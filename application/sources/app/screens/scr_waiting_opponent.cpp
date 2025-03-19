#include "scr_waiting_opponent.h"

#include "screens.h"

bool master_joined_game = false;
bool slave_joined_game = false;

static void view_scr_waiting_opponent();

view_dynamic_t dyn_view_item_waiting_opponent = {
    {
            .item_type = ITEM_TYPE_DYNAMIC,
    },
    view_scr_waiting_opponent
};

view_screen_t scr_waiting_opponent = {
    &dyn_view_item_waiting_opponent,
    ITEM_NULL,
    ITEM_NULL,

    .focus_item = 0,
};

void view_scr_waiting_opponent() {
        view_render.clear();
        view_render.setTextSize(1);
        view_render.setTextColor(WHITE);
        view_render.setCursor(5, 25);
        view_render.print("Waiting for opponent");  
        view_render.drawBitmap(100,	48,	icon_go_home,	16,	16,	WHITE);      
}

void scr_waiting_opponent_handle(ak_msg_t* msg) {
    uint8_t device_address = mw24_get_number_address_nrf();
    switch (msg->sig)
    {
    case SCREEN_ENTRY: {
        APP_DBG_SIG("SCREEN_ENTRY\n");\
        APP_DBG("Opponrnt address: %d\n", opponent_address);
        // View render
        view_render.clear();
		view_render.initialize();
		view_render_display_on();

        send_address_to_opponent();
        if (mw24_i_am_master) {
            master_joined_game = true;
            DATA_TRANSMIT = MASTER_JOINED_GAME;
            mw24_send_data_to_rf24_tx((uint8_t)DATA_TRANSMIT);
        } else if (!mw24_i_am_master) {
                slave_joined_game = true;
                DATA_TRANSMIT = SLAVE_JOINED_GAME;
                mw24_send_data_to_rf24_tx((uint8_t)DATA_TRANSMIT); 
        }
        timer_set(WAITING_OPPONENT_ID, WAITING_OPPONENT_TIME_OUT, 10000, TIMER_ONE_SHOT);
        timer_set(WAITING_OPPONENT_ID, WAITING_OPPONENT_CHECK, 200, TIMER_PERIODIC);
    }
        break;

    case WAITING_OPPONENT_CHECK: {
        APP_DBG_SIG("WAITING_OPPONENT_CHECK\n");
        if (master_joined_game && slave_joined_game && device_address == opponent_address) {
            timer_remove_attr(WAITING_OPPONENT_ID, WAITING_OPPONENT_TIME_OUT);
            timer_remove_attr(WAITING_OPPONENT_ID, WAITING_OPPONENT_CHECK);
            SCREEN_TRAN(scr_archery_game_handle, &scr_archery_game);
        }
    }
        break;

    case WAITING_OPPONENT_TIME_OUT: {
        APP_DBG_SIG("WAITING_OPPONENT_TIME_OUT\n");
        timer_remove_attr(WAITING_OPPONENT_ID, WAITING_OPPONENT_CHECK);
        opponent_address = 0;

        if (mw24_i_am_master) {
            DATA_TRANSMIT = RESET_ADDRESS_OPPONENT;
            mw24_send_data_to_rf24_tx((uint8_t)DATA_TRANSMIT);
        } 
        else {
            DATA_TRANSMIT = RESET_ADDRESS_OPPONENT;
            mw24_send_data_to_rf24_tx((uint8_t)DATA_TRANSMIT); 
        }   
        timer_set(WAITING_OPPONENT_ID, WAITING_OPPONENT_EXIT, 200, TIMER_ONE_SHOT);  
    }
        break;

    case WAITING_OPPONENT_EXIT: {
        APP_DBG_SIG("WAITING_OPPONENT_EXIT\n");
        opponent_address = 0;

        if (mw24_i_am_master) {
            master_joined_game = false;
            DATA_TRANSMIT = MASTER_OUT_GAME;
            mw24_send_data_to_rf24_tx((uint8_t)DATA_TRANSMIT);
        } 
        else {
            slave_joined_game = false;
            DATA_TRANSMIT = SLAVE_OUT_GAME;
            mw24_send_data_to_rf24_tx((uint8_t)DATA_TRANSMIT);
        }
        SCREEN_TRAN(scr_menu_game_handle, &scr_menu_game); 

    }
        BUZZER_PlayTones(tones_cc);
        break;

    case AC_DISPLAY_BUTTON_MODE_RELEASED: {
        APP_DBG_SIG("AC_DISPLAY_BUTTON_MODE_RELEASED\n");
        timer_remove_attr(WAITING_OPPONENT_ID, WAITING_OPPONENT_TIME_OUT);
        timer_remove_attr(WAITING_OPPONENT_ID, WAITING_OPPONENT_CHECK);
        opponent_address = 0;

        if (mw24_i_am_master) {
            DATA_TRANSMIT = RESET_ADDRESS_OPPONENT;
            mw24_send_data_to_rf24_tx((uint8_t)DATA_TRANSMIT);
        } 
        else {
            DATA_TRANSMIT = RESET_ADDRESS_OPPONENT;
            mw24_send_data_to_rf24_tx((uint8_t)DATA_TRANSMIT);
        }
        task_post_pure_msg(WAITING_OPPONENT_ID, WAITING_OPPONENT_EXIT); 
    }
        break;
        
    default:
        break;
    }
}
