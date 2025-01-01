#include "scr_game_setting.h"

game_setting_t setting_data;

static uint8_t setting_location_choose;

static void view_scr_game_setting();

view_dynamic_t dyn_view_item_game_setting = {
    {
        .item_type = ITEM_TYPE_DYNAMIC,
    },
    view_scr_game_setting
};

view_screen_t scr_game_setting = {
    &dyn_view_item_game_setting,
    ITEM_NULL,
    ITEM_NULL,

    .focus_item = 0,
};

void view_scr_game_setting() {
    view_render.setTextSize(1);
    view_render.setTextColor(WHITE);

    //Icon
    view_render.drawBitmap( 0,
                            setting_location_choose - GAME_SETTING_CHOOSE_ICON_AXIS_Y,
                            choose_icon,
                            GAME_SETTING_CHOOSE_ICON_SIZE_W,
                            GAME_SETTING_CHOOSE_ICON_SIZE_H,
                            WHITE);

    if (setting_data.silent == 0) {
        view_render.drawBitmap( GAME_SETTING_SPEAKER_AXIS_X,
                                GAME_SETTING_FRAMES_AXIS_Y_1 + GAME_SETTING_FRAMES_STEP*3-12,
                                speaker_2,
                                GAME_SETTING_SPEAKER_SIZE_W,
                                GAME_SETTING_SPEAKER_SIZE_H,
                                WHITE);
    }
    else {
        view_render.drawBitmap( GAME_SETTING_SPEAKER_AXIS_X,
                                GAME_SETTING_FRAMES_AXIS_Y_1 + GAME_SETTING_FRAMES_STEP*3-12,
                                speaker_1,
                                GAME_SETTING_SPEAKER_SIZE_W,
                                GAME_SETTING_SPEAKER_SIZE_H,
                                WHITE);         
    }

    // Frames
    view_render.drawRoundRect(  GAME_SETTING_FRAMES_AXIS_X,
                                GAME_SETTING_FRAMES_AXIS_Y_1,
                                GAME_SETTING_FRAMES_SIZE_W,
                                GAME_SETTING_FRAMES_SIZE_H,
                                GAME_SETTING_FRAMES_SIZE_R,
                                WHITE);

    view_render.drawRoundRect(  GAME_SETTING_FRAMES_AXIS_X,
                                GAME_SETTING_FRAMES_AXIS_Y_1 + GAME_SETTING_FRAMES_STEP,
                                GAME_SETTING_FRAMES_SIZE_W,
                                GAME_SETTING_FRAMES_SIZE_H,
                                GAME_SETTING_FRAMES_SIZE_R,
                                WHITE);

    view_render.drawRoundRect(  GAME_SETTING_FRAMES_AXIS_X,
                                GAME_SETTING_FRAMES_AXIS_Y_1 + GAME_SETTING_FRAMES_STEP*2,
                                GAME_SETTING_FRAMES_SIZE_W,
                                GAME_SETTING_FRAMES_SIZE_H,
                                GAME_SETTING_FRAMES_SIZE_R,
                                WHITE);

    view_render.drawRoundRect(  GAME_SETTING_FRAMES_AXIS_X,
                                GAME_SETTING_FRAMES_AXIS_Y_1 + GAME_SETTING_FRAMES_STEP*3,
                                GAME_SETTING_FRAMES_SIZE_W,
                                GAME_SETTING_FRAMES_SIZE_H,
                                GAME_SETTING_FRAMES_SIZE_R,
                                WHITE); 

	// Count Arrow 1
	view_render.setCursor(GAME_SETTING_TEXT_AXIS_X, 5);
	view_render.print(" Arrows 1     ( ) ");
	view_render.setCursor(GAME_SETTING_NUMBER_AXIS_X, 5);
	view_render.print(setting_data.num_arrow);    
	// Count Arrow 2
	view_render.setCursor(GAME_SETTING_TEXT_AXIS_X, 20);
	view_render.print(" Arrows 2     ( ) ");	
	view_render.setCursor(GAME_SETTING_NUMBER_AXIS_X, 20);
	view_render.print(setting_data.num_arrow_2);
	// Silent
	view_render.setCursor(GAME_SETTING_TEXT_AXIS_X, 35);
	view_render.print(" Silent           ");
	// EXIT
	view_render.setCursor(GAME_SETTING_TEXT_AXIS_X + 32, 50);
	view_render.print(" EXIT ") ;
	view_render.update();                                 
}

void scr_game_setting_handle(ak_msg_t* msg){
    switch (msg->sig)
    {
    case SCREEN_ENTRY: {
        APP_DBG_SIG("SCREEN_ENTRY\n");
        view_render.clear();

        setting_location_choose = SETTING_ITEM_ARRDESS_1;

        eeprom_read( EEPROM_SETTING_START_ADDR,
                     (uint8_t*)&setting_data,
                     sizeof(setting_data));
    }
        break;
    
    case AC_DISPLAY_BUTTON_MODE_RELEASED: {
        APP_DBG_SIG("AC_DISPLAY_BUTON_MODE_RELEASED\n");
        switch (setting_location_choose)
        {
        case SETTING_ITEM_ARRDESS_1: {
            setting_data.num_arrow++;
            if(setting_data.num_arrow > 5){
                setting_data.num_arrow = 1;
            }
        }
            break;

        // case SETTING_ITEM_ARRDESS_2: {
        //     setting_data.meteoroid_speed++;
        //     if(setting_data.meteoroid_speed > 5) {
        //         setting_data.meteoroid_speed = 1;
        //     }
        // }
        //     break;

        case SETTING_ITEM_ARRDESS_2: {
            setting_data.num_arrow_2++;
            if(setting_data.num_arrow_2 > 5) {
                setting_data.num_arrow_2 = 1;
            }
        }
            break;

        case SETTING_ITEM_ARRDESS_3: {
            setting_data.silent = !setting_data.silent;
            xprintf("%d\n",setting_data.silent);
            BUZZER_Sleep(setting_data.silent);
        }
            break;

        case SETTING_ITEM_ARRDESS_4: {
            setting_data.arrow_speed = 5;

            eeprom_write( EEPROM_SETTING_START_ADDR,
                          (uint8_t*)&setting_data,
                          sizeof(setting_data));
            SCREEN_TRAN(scr_menu_game_handle, &scr_menu_game);
            BUZZER_PlayTones(tones_startup);
        }
            break;

        default:
            break;
        }
    }
        BUZZER_PlayTones(tones_cc);
        break;

    case AC_DISPLAY_BUTTON_DOWN_RELEASED: {
        APP_DBG_SIG("AC_DISPLAY_BUTON_DOWN_RELEASED\n");
        setting_location_choose += STEP_SETTING_CHOOSE;
        if(setting_location_choose > SETTING_ITEM_ARRDESS_4) {
            setting_location_choose = SETTING_ITEM_ARRDESS_1;
        }   
    }
        BUZZER_PlayTones(tones_cc);
        break;

    case AC_DISPLAY_BUTTON_UP_RELEASED: {
        APP_DBG_SIG("AC_DISPLAY_BUTON_UP_RELEASED\n");
        setting_location_choose -= STEP_SETTING_CHOOSE;
        if(setting_location_choose == SETTING_ITEM_ARRDESS_0) {
            setting_location_choose = SETTING_ITEM_ARRDESS_4;
        }
    }
        BUZZER_PlayTones(tones_cc);
        break;
        
    default:
        break;
    }
}