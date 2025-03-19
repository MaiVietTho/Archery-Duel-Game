#include "control_game.h"

// data_transmit DATA_TRANSMIT;

void control_game_handle(ak_msg_t* msg) {
	switch (msg->sig)
	{
	case AC_DISPLAY_BUTTON_MODE_RELEASED: {
		APP_DBG_SIG("AC_DISPLAY_BUTTON_MODE_RELEASED\n");
		if (mw24_i_am_master) {
			DATA_TRANSMIT = BUTTON_MODE_MASTER;
			mw24_send_data_to_rf24_tx((uint8_t)DATA_TRANSMIT);
			APP_DBG("Master tranmit button mode\n");
		}
		else { 
				DATA_TRANSMIT = BUTTON_MODE_SLAVE;
				mw24_send_data_to_rf24_tx((uint8_t)DATA_TRANSMIT);
				APP_DBG("Slave tranmit button mode\n");
		}
	}
		break;

	case AC_DISPLAY_BUTTON_UP_RELEASED: {
		APP_DBG_SIG("AC_DISPLAY_BUTTON_UP_RELEASED\n");
		if (mw24_i_am_master) {
			DATA_TRANSMIT = BUTTON_UP_MASTER;
			mw24_send_data_to_rf24_tx((uint8_t)DATA_TRANSMIT);
			APP_DBG("Master tranmit button up\n");
		}
		else {
			DATA_TRANSMIT = BUTTON_UP_SLAVE;
			mw24_send_data_to_rf24_tx((uint8_t)DATA_TRANSMIT);
			APP_DBG("Slave tranmit button up\n");
		}
	}
		break;

	case AC_DISPLAY_BUTTON_DOWN_RELEASED: {
		APP_DBG_SIG("AC_DISPLAY_BUTTON_DOWN_RELEASED\n");
		if (mw24_i_am_master) {
			DATA_TRANSMIT = BUTTON_DOWN_MASTER;
			mw24_send_data_to_rf24_tx((uint8_t)DATA_TRANSMIT);
			APP_DBG("Master tranmit button down\n");
		}
		else {
				DATA_TRANSMIT = BUTTON_DOWN_SLAVE;
				mw24_send_data_to_rf24_tx((uint8_t)DATA_TRANSMIT);
				APP_DBG("Slave tranmit button down\n");		
		}
	}	
		break;
	
	default:
		break;
	}
}