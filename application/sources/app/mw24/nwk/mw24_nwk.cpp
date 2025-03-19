#include "mw24_nwk.h"
#include "mw24_eeprom.h"

#include "button.h"

#include "sys_dbg.h"

#include "app.h"
#include "app_bsp.h"
#include "app_dbg.h"
#include "app_if.h"

#include "task_list.h"
#include "task_list_if.h"

#include "fsm.h"
#include "port.h"
#include "message.h"
#include "timer.h"

#include "sys_ctrl.h"

/* Game */
#include "scr_waiting_opponent.h"
#include "control_game.h"
#include "scr_archery_game.h"

/*************************************************************************************/
/* Variable and Struct Declaration */
/*************************************************************************************/
#define MW24_NRF_MAX_RETRANMIT		  ((1 << HAL_NRF_MAX_RT))
#define MW24_NRF_SEND_DONE			  ((1 << HAL_NRF_TX_DS))
#define MW24_NRF_PACKET_RECEIVED	  ((1 << HAL_NRF_RX_DR))
#define MW24_NRF_ACK_PAYLOAD_RECIEVED ((1 << HAL_NRF_RX_DR) | (1 << HAL_NRF_TX_DS))

/*Game*/
volatile uint8_t opponent_address;
data_transmit DATA_TRANSMIT;

/* Mode check wireless */
uint16_t mw24_check_wireless_msg_couter = 0;
bool mw24_i_enable_check_wireless = false;
bool mw24_i_am_master = false;

/* nrf state handware */
static uint8_t mw24_nrf_handware_state = MW24_NRF_HANDWARE_STATE_NONE;
static uint8_t mw24_get_nrf_handware_state();
static void mw24_set_nrf_handware_state(uint8_t state);

/* nrf state send */
static uint8_t mw24_nrf_send_state = MW24_NRF_SEND_STATE_IDLE;
static uint8_t mw24_get_nrf_send_state();
static void mw24_set_nrf_send_state(uint8_t state);

/* nrf state receive*/
static uint8_t mw24_nrf_recv_state = MW24_NRF_RECV_STATE_IDLE;
static uint8_t mw24_get_nrf_recv_state();
static void mw24_set_nrf_recv_state(uint8_t state);

/*************************************************************************************/
/* Action timer:
	1) mw24_end_sending: Update status and mode switch Rx*/
/*************************************************************************************/
void mw24_end_sending() {
	if (mw24_get_nrf_send_state() == MW24_NRF_SEND_STATE_SENDING) {
		mw24_set_nrf_send_state(MW24_NRF_SEND_STATE_IDLE);
		mw24_rx_nrf_mode_switch();
	}
	
	if (mw24_get_nrf_recv_state() == MW24_NRF_RECV_STATE_RECEIVING) {
		mw24_set_nrf_recv_state(MW24_NRF_SEND_STATE_IDLE);
		mw24_io_rs485_dir_low();
	}
}

/*************************************************************************************/
/* Action nRF24l01:
	1) mw24_tx_nrf_mode_switch: Switches the device to transmit (Tx) mode in nRF24l01.
	2) mw24_rx_nrf_mode_switch: Switches the device to receive (Rx) mode in nRF24l01.
	3) mw24_nrf_send_data_byte: Writes data to the transmit (Tx) register in nRF24l01.
	4) mw24_send_data_uart_to_nrf: Transfers data directly from UART to in nRF24l01.
	5) mw24_send_data_check_wireless: Sends data to check the wireless connectivity.
*/
/*************************************************************************************/
void mw24_tx_nrf_mode_switch() {
	CE_LOW();
	hal_nrf_set_operation_mode(HAL_NRF_PTX);
	sys_ctrl_delay_us(150);
	CE_HIGH();
}

void mw24_rx_nrf_mode_switch() {
	CE_LOW();
	hal_nrf_set_address(HAL_NRF_PIPE0, (uint8_t*)mw24_get_address_nrf()); /* Sets recieving address on pipe0 */
	hal_nrf_set_operation_mode(HAL_NRF_PRX);
	sys_ctrl_delay_us(150);
	CE_HIGH();
}

void mw24_nrf_send_data_byte(uint8_t* data, uint8_t len) {

	MW24_DEBUG_DATA("Data_send: [%d]\n", *data);

	/* off rf24 */
	CSN_LOW();
	/* Write command */
	hal_nrf_rw(WR_TX_PLOAD);
	/* Write tx_payload*/
	while (len--)
	{
		hal_nrf_rw(*data++);
	}
	/* On rf24 */
	CSN_HIGH();
}

void mw24_send_data_to_rf24_tx(uint8_t data) {
	if (mw24_get_nrf_handware_state() == MW24_NRF_HANDWARE_STATE_NONE) {
		return;
	}

	MW24_DEBUG_TX_ON();

	if (mw24_get_nrf_send_state() == MW24_NRF_SEND_STATE_IDLE) {
		mw24_tx_nrf_mode_switch();

		/* Enable timer change mode */
		mw24_timer_reset();
		mw24_timer_enable();
	}

	// /* Clear data Tx */
	hal_nrf_flush_tx();

	/* Send data rf24*/
	mw24_nrf_send_data_byte((uint8_t*)&data, sizeof(data));

	/* update status rf24 */
	mw24_set_nrf_send_state(MW24_NRF_SEND_STATE_SENDING);


	MW24_DEBUG_TX_OFF();
}

void mw24_send_data_check_wireless() {
	uint8_t data = 7;
	if (mw24_get_nrf_handware_state() == MW24_NRF_HANDWARE_STATE_NONE) {
		return;
	}
	
	if (mw24_get_nrf_send_state() == MW24_NRF_SEND_STATE_IDLE) {
		mw24_tx_nrf_mode_switch();

		/* Enable timer change mode */
		mw24_timer_reset();
		mw24_timer_enable();
	}

	/* Clear data Tx */
	hal_nrf_flush_tx();

	/* Send data rf24*/
	mw24_nrf_send_data_byte((uint8_t*)&data, sizeof(data));

	/* update status rf24 */
	mw24_set_nrf_send_state(MW24_NRF_SEND_STATE_SENDING);
}

/*************************************************************************************/
/* Interrup nRF24l01 */
/*************************************************************************************/
void mw24_irq_nrf() {
	if (mw24_get_nrf_handware_state() == MW24_NRF_HANDWARE_STATE_NONE) {
		return;
	}

	uint8_t nrf24_irq_mask = hal_nrf_get_clear_irq_flags();

	MW24_DEBUG_FLAGS("RF24_flags: [%d]", nrf24_irq_mask);

	// uint8_t slave_address = mw24_get_number_address_nrf();
	switch (nrf24_irq_mask) {
	case MW24_NRF_MAX_RETRANMIT: {
		MW24_DEBUG_STATUS("RF24_state_send: max retranmit\n");
		hal_nrf_flush_tx(); // clear tx
		mw24_rx_nrf_mode_switch(); // chuyen che do
	}
		break;

	case MW24_NRF_SEND_DONE: { /* send done */
		MW24_DEBUG_STATUS("RF24_state_send: send done\n");
		MW24_DEBUG_TX_ON();
		mw24_timer_reset(); /* reset timer change mode rf24 */
		MW24_DEBUG_TX_OFF();
	}
		break;

	case MW24_NRF_PACKET_RECEIVED: /* Packet received */
		MW24_DEBUG_STATUS("RF24_state_received: data_rf24\n");
		MW24_DEBUG_RX_ON();
		/* test connect */
		if (mw24_i_enable_check_wireless) {
			if (mw24_i_am_master == false) {
				mw24_check_wireless_msg_couter++;
			}
		}
		
		if (!hal_nrf_rx_fifo_empty()) {
			/* Receive data */
			uint8_t pl_len;
			volatile uint8_t data;
			pl_len = hal_nrf_read_rx_pload((uint8_t*)&data);
			// xprintf("%d\n", k);

			if (pl_len != MW24_FRAME_DATA_RF24_PAYLOAD_LEN) {
				FATAL("RF24", 0x05);
			}

			switch (data)
			{
			case RESET_ADDRESS_OPPONENT: {
				APP_DBG("RESET ADRESS OPPONENT\n");
				opponent_address = 0;
			}
				break;		

			case OPPONENT_ADDRESS_1: {
				APP_DBG("RECEIVED OPPONENT ADDRESS 1\n");
				opponent_address = 1;
			}
				break;

			case OPPONENT_ADDRESS_2: {
				APP_DBG("RECEIVED OPPONENT ADDRESS 2\n");
				opponent_address = 2;
			}
				break;

			case OPPONENT_ADDRESS_3: {
				APP_DBG("RECEIVED OPPONENT ADDRESS 3\n");
				opponent_address = 3;
			}
				break;

			case OPPONENT_ADDRESS_4: {
				APP_DBG("RECEIVED OPPONENT ADDRESS 4\n");
				opponent_address = 4;
			}
				break;

			case OPPONENT_ADDRESS_5: {
				APP_DBG("RECEIVED OPPONENT ADDRESS 5\n");
				opponent_address = 5;
			}
				break;
				
			case BUTTON_DOWN_MASTER: {
				if(GAME_STATE != GAME_OFF) {
					APP_DBG("SLAVE RECEIVED BUTTON DOWN MASTER\n");
					task_post_pure_msg(GAME_ARCHERY_2_ID, GAME_ARCHERY_2_DOWN);
				}
			}
				break;

			case BUTTON_UP_MASTER: {
				if (GAME_STATE != GAME_OFF) {
					APP_DBG("SLAVE RECEIVED BUTTON UP MASTER\n");
					task_post_pure_msg(GAME_ARCHERY_2_ID, GAME_ARCHERY_2_UP);
				}
			}
				break;

			case BUTTON_MODE_MASTER: {
				if (GAME_STATE != GAME_OFF) {
					APP_DBG("SLAVE RECEIVED BUTTON MODE MASTER\n");
					task_post_pure_msg(GAME_ARROW_2_ID, GAME_ARROW_2_SHOOT);
				}
			}
				break;

			case BUTTON_DOWN_SLAVE: {
				if(GAME_STATE != GAME_OFF) {
					APP_DBG("MASTER RECEIVED BUTTON DOWN SLAVE\n");
					task_post_pure_msg(GAME_ARCHERY_ID, GAME_ARCHERY_DOWN);
				}			
			}
				break;

			case BUTTON_UP_SLAVE: {
				if (GAME_STATE != GAME_OFF) {
					APP_DBG("MASTER RECEIVED BUTTON UP SLAVE\n");
					task_post_pure_msg(GAME_ARCHERY_ID, GAME_ARCHERY_UP);
				}			
			}
				break;

			case BUTTON_MODE_SLAVE: {
				if (GAME_STATE != GAME_OFF) {
					APP_DBG("MASTER RECEIVED BUTTON MODE SLAVE\n");
					task_post_pure_msg(GAME_ARROW_ID, GAME_ARROW_SHOOT);
				}			
			}
				break;

			case MASTER_JOINED_GAME: {
				APP_DBG("MASTER JOINED GAME\n");
				master_joined_game = true;
			}
				break;

			case MASTER_OUT_GAME: {
				APP_DBG("MASTER OUT GAME\n");
				master_joined_game = false;
			}
				break;

			case SLAVE_JOINED_GAME: {
				APP_DBG("SLAVE JOINED GAME\n");
				slave_joined_game = true; 
			}
				break;

			case SLAVE_OUT_GAME: {
				APP_DBG("SLAVE OUT GAME\n");
				slave_joined_game = false;
			}
				break;

			default:
				break;
			}
			MW24_DEBUG_RX_OFF();

			/* Clear data rx*/
			hal_nrf_flush_rx();

			// MW24_DEBUG_RX_ON();

			/* Transformation mode rs485 -> Tx */
			// mw24_tx_rs485_uart2_enable();
			// if (mw24_get_nrf_recv_state() == MW24_NRF_RECV_STATE_IDLE) {
			// 	mw24_timer_reset();
			// 	mw24_io_rs485_dir_high();
			// 	mw24_timer_enable();
			// 	mw24_set_nrf_recv_state(MW24_NRF_RECV_STATE_RECEIVING);
			// }
			
			// mw24_timer_reset();
			// USART_SendData(USART2, k);

			// MW24_DEBUG_RX_OFF();
		}
		break;

	case MW24_NRF_ACK_PAYLOAD_RECIEVED: { /* Ack payload recieved */
	}
		break;

	default: {
		hal_nrf_get_clear_irq_flags();
	}
		break;
	}
}

/*************************************************************************************/
/* Init nRF24l01 */
/*************************************************************************************/
void mw24_nrf_init() {
	/* init io control of nrf24 (CE, NCS, IRQ) */
	mw24_io_nrf_ctrl_init();
	/* init SPI1 */
	mw24_spi_nrf_ctrl_init();

	CE_LOW();
	sys_ctrl_delay_ms(100);

	hal_nrf_set_power_mode(HAL_NRF_PWR_DOWN);
	hal_nrf_get_clear_irq_flags();

	hal_nrf_close_pipe(HAL_NRF_ALL); /* First close all radio pipes, Pipe 0 and 1 open by default */
	hal_nrf_open_pipe(HAL_NRF_PIPE0, false); /* Open pipe0, without/autoack (autoack) */

	hal_nrf_set_crc_mode(HAL_NRF_CRC_8BIT); /* Operates in 16bits CRC mode */
	// hal_nrf_set_auto_retr(2, 750); /* Enable auto retransmit */

	hal_nrf_set_address_width(HAL_NRF_AW_5BYTES); /* 5 bytes address width */
	hal_nrf_set_address(HAL_NRF_TX, (uint8_t*)mw24_get_address_nrf()); /* Set device's addresses */
	hal_nrf_set_address(HAL_NRF_PIPE0, (uint8_t*)mw24_get_address_nrf()); /* Sets recieving address on pipe0 */

	hal_nrf_set_operation_mode(HAL_NRF_PRX);
	hal_nrf_set_rx_pload_width((uint8_t)HAL_NRF_PIPE0, MW24_FRAME_DATA_RF24_PAYLOAD_LEN);

	hal_nrf_set_rf_channel(mw24_get_channel_nrf());
	hal_nrf_set_output_power(HAL_NRF_0DBM);
	hal_nrf_set_lna_gain(HAL_NRF_LNA_HCURR);
	hal_nrf_set_datarate(HAL_NRF_2MBPS);

	hal_nrf_set_power_mode(HAL_NRF_PWR_UP); /* Power up device */

	hal_nrf_set_irq_mode(HAL_NRF_MAX_RT, true);
	hal_nrf_set_irq_mode(HAL_NRF_TX_DS, true);
	hal_nrf_set_irq_mode(HAL_NRF_RX_DR, true);

	hal_nrf_flush_rx();
	hal_nrf_flush_tx();

	sys_ctrl_delay_ms(2);
	CE_HIGH();

	ENTRY_CRITICAL();
	mw24_set_nrf_handware_state(MW24_NRF_HANDWARE_STATE_STARTED);
	mw24_set_nrf_send_state(MW24_NRF_SEND_STATE_IDLE);
	EXIT_CRITICAL();
}

/*************************************************************************************/
/* Status nRF24l01 */
/*************************************************************************************/
/* Status RF24 */
uint8_t mw24_get_nrf_handware_state() {
	return mw24_nrf_handware_state;
}

uint8_t mw24_get_nrf_send_state() {
	return mw24_nrf_send_state;
}

uint8_t mw24_get_nrf_recv_state() {
	return mw24_nrf_recv_state;
}

void mw24_set_nrf_handware_state(uint8_t state) {
	mw24_nrf_handware_state = state;
	MW24_DEBUG_STATUS("RF24_state_handware: [%d]\n", state);
}

void mw24_set_nrf_send_state(uint8_t state) {
	mw24_nrf_send_state = state;
	MW24_DEBUG_STATUS("RF24_state_send: [%d]\n", state);
}

void mw24_set_nrf_recv_state(uint8_t state) {
	mw24_nrf_recv_state = state;
	MW24_DEBUG_STATUS("RF24_state_recv: [%d]\n", state);
}

void send_address_to_opponent() {
	uint8_t device_address = mw24_get_number_address_nrf();
	mw24_send_data_to_rf24_tx(device_address);
}

