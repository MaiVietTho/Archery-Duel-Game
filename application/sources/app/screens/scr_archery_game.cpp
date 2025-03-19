#include "scr_archery_game.h"

#include "screens.h"


enum game_state GAME_STATE;
game_setting_t settingsetup;

int pos_border[5] = {2, 12, 22, 32 ,42};

void game_frame_display() {
    view_render.setTextSize(1);
    view_render.setTextColor(WHITE);
    view_render.setCursor(2,55);
    view_render.print("Arrow 1:");
    view_render.print(settingsetup.num_arrow);
    view_render.setCursor(73,55);
    view_render.print("Arrow 2:");
    view_render.print(settingsetup.num_arrow_2);
    view_render.drawLine(0, LCD_HEIGHT-10, LCD_WIDTH, LCD_HEIGHT-10, WHITE);
    view_render.drawRect(0, 0, 128, 64, WHITE);
}

void game_archery_display() {
    if (archery.visible == WHITE && settingsetup.num_arrow != 0) {
        view_render.drawBitmap( archery.x, \
                                archery.y - 10, \
                                bitmap_archery_I, \
                                SIZE_BITMAP_ARCHERY_X, \
                                SIZE_BITMAP_ARCHERY_Y, \
                                WHITE);
    }
    else if (archery.visible == WHITE && settingsetup.num_arrow == 0) {
        view_render.drawBitmap( archery.x, \
                                archery.y - 10, \
                                bitmap_archery_II, \
                                SIZE_BITMAP_ARCHERY_X, \
                                SIZE_BITMAP_ARCHERY_Y, \
                                WHITE);
    }
}

void game_archery_2_display() {
    if (archery_2.visible == WHITE && settingsetup.num_arrow_2 != 0) {
        view_render.drawBitmap( archery_2.x, \
                                archery_2.y - 10, \
                                bitmap_archery_2_I, \
                                SIZE_BITMAP_ARCHERY_X_2, \
                                SIZE_BITMAP_ARCHERY_Y_2, \
                                WHITE);
    }
    else if (archery_2.visible == WHITE && settingsetup.num_arrow_2 == 0) {
        view_render.drawBitmap( archery_2.x, \
                                archery_2.y - 10, \
                                bitmap_archery_2_II, \
                                SIZE_BITMAP_ARCHERY_X_2, \
                                SIZE_BITMAP_ARCHERY_Y_2, \
                                WHITE);
    }   
}

void game_arrow_display() {
    for (uint8_t i = 0; i < MAX_NUM_ARROW; i++) {
        if (arrow[i].visible == WHITE) {
            view_render.drawBitmap( arrow[i].x, \
                                    arrow[i].y, \
                                    bitmap_arrow, \
                                    SIZE_BITMAP_ARROW_X, \
                                    SIZE_BITMAP_ARROW_Y, \
                                    WHITE);
        }
    }
}

void game_arrow_2_display() {
    for (uint8_t i = 0; i < MAX_NUM_ARROW_2; i++) {
        if (arrow_2[i].visible == WHITE) {
            view_render.drawBitmap( arrow_2[i].x, \
                                    arrow_2[i].y, \
                                    bitmap_arrow_2, \
                                    SIZE_BITMAP_ARROW_X_2, \
                                    SIZE_BITMAP_ARROW_Y_2, \
                                    WHITE);
        }
    }
}

void game_bang_display() {
    for (uint8_t i= 0; i < NUM_BANG; i++) {
        if (bang[i].visible == WHITE) {
            if(bang[i].action_image == 1) {
                view_render.drawBitmap( bang[i].x, \
                                        bang[i].y, \
                                        bitmap_bang_I, \
                                        SIZE_BITMAP_BANG_I_X, \
                                        SIZE_BITMAP_BANG_I_Y, \
                                        WHITE); 
            }
            else if(bang[i].action_image == 2) {
                view_render.drawBitmap( bang[i].x, \
                                        bang[i].y, \
                                        bitmap_bang_II, \
                                        SIZE_BITMAP_BANG_I_X, \
                                        SIZE_BITMAP_BANG_I_Y, \
                                        WHITE); 
            }
            else if(bang[i].action_image == 3) {
                view_render.drawBitmap( bang[i].x + 2, \
                                        bang[i].y - 1, \
                                        bitmap_bang_III, \
                                        SIZE_BITMAP_BANG_II_X, \
                                        SIZE_BITMAP_BANG_II_Y, \
                                        WHITE); 
            }
        }
    }
}

void game_border_display() {
    if(border.visible == WHITE) {
        view_render.drawFastVLine( border.x, \
                                    AXIS_Y_BORDER_ON, \
                                    AXIS_Y_BORDER_UNDER, \
                                    WHITE); 
        for (uint8_t i = 0; i < 5; i++) {
            view_render.fillCircle( border.x, \
                                    pos_border[i] + 5, \
                                    1, \
                                    WHITE);
        }
    }
}

void game_border_2_display() {
    if(border_2.visible == WHITE) {
        view_render.drawFastVLine( border_2.x, \
                                    AXIS_Y_BORDER_ON_2, \
                                    AXIS_Y_BORDER_UNDER_2, \
                                    WHITE); 
        for (uint8_t i = 0; i < 5; i++) {
            view_render.fillCircle( border_2.x, \
                                    pos_border[i] + 5, \
                                    1, \
                                    WHITE);
        }
    }
}


static void view_scr_archery_game();

view_dynamic_t dyn_view_item_archery_game = {
    {
        .item_type = ITEM_TYPE_DYNAMIC,
    },
    view_scr_archery_game
};

view_screen_t scr_archery_game = {
    &dyn_view_item_archery_game,
    ITEM_NULL,
    ITEM_NULL,

    .focus_item = 0,
};

void view_scr_archery_game(){
    if(GAME_STATE == GAME_PLAY){
        game_frame_display();
        game_archery_display();
        game_archery_2_display();
        game_arrow_display();
        game_arrow_2_display();
        game_bang_display();
        game_border_display();
        game_border_2_display();
    }
    else if (GAME_STATE == GAME_OVER){
        if (mw24_i_am_master) {
            if (person_left_win) {
                view_render.clear();
                view_render.setTextSize(2);
                view_render.setTextColor(WHITE);
                view_render.setCursor(45, 24);
                view_render.print("LOSE");
            } else {
                view_render.clear();
                view_render.setTextSize(2);
                view_render.setTextColor(WHITE);
                view_render.setCursor(40, 24);
                view_render.print("WINER");
            }
        }
        else {
            if (person_left_win) {
                view_render.clear();
                view_render.setTextSize(2);
                view_render.setTextColor(WHITE);
                view_render.setCursor(40, 24);
                view_render.print("WINER");
            } else {
                view_render.clear();
                view_render.setTextSize(2);
                view_render.setTextColor(WHITE);
                view_render.setCursor(45, 24);
                view_render.print("LOSE");
            }
        }
    }
}

void game_level_setup() {
    eeprom_read ( EEPROM_SETTING_START_ADDR,
                    (uint8_t*) &settingsetup,
                    sizeof(settingsetup));
}

void scr_archery_game_handle(ak_msg_t* msg) {
    switch (msg->sig)
    {
    case SCREEN_ENTRY: {  
        APP_DBG_SIG("SCREEN_ENTRY\n");
        game_level_setup();

        task_post_pure_msg(GAME_ARCHERY_ID,       GAME_ARCHERY_SETUP);
        task_post_pure_msg(GAME_ARCHERY_2_ID,     GAME_ARCHERY_2_SETUP);
        task_post_pure_msg(GAME_ARROW_ID,         GAME_ARROW_SETUP);
        task_post_pure_msg(GAME_ARROW_2_ID,       GAME_ARROW_2_SETUP);

        task_post_pure_msg(GAME_BANG_ID,          GAME_BANG_SETUP);
        task_post_pure_msg(GAME_BORDER_ID,        GAME_BORDER_SETUP);
        task_post_pure_msg(GAME_BORDER_2_ID,      GAME_BORDER_2_SETUP);

        timer_set( AC_TASK_DISPLAY_ID, 
                    GAME_TIME_TICK,
                    GAME_TIME_TICK_INTERVAL,
                    TIMER_PERIODIC);
        GAME_STATE = GAME_PLAY;
    }
        break;

    case GAME_TIME_TICK: {
        APP_DBG_SIG("GAME_TIME_TICK\n");
        task_post_pure_msg(GAME_ARCHERY_ID,        GAME_ARCHERY_UPDATE);
        task_post_pure_msg(GAME_ARCHERY_2_ID,      GAME_ARCHERY_2_UPDATE);
        task_post_pure_msg(GAME_ARROW_ID,          GAME_ARROW_RUN);
        task_post_pure_msg(GAME_ARROW_2_ID,        GAME_ARROW_2_RUN);
        task_post_pure_msg(GAME_ARROW_ID,          GAME_ARROW_DETONATOR);
        task_post_pure_msg(GAME_BANG_ID,           GAME_BANG_UPDATE);
        task_post_pure_msg(GAME_BORDER_ID,         GAME_CHECK_GAME_OVER);
        task_post_pure_msg(GAME_BORDER_2_ID,       GAME_CHECK_GAME_OVER_2);
    }
        break;

    case GAME_RESET: {
        APP_DBG_SIG("GAME_RESET\n");
        task_post_pure_msg(GAME_ARCHERY_ID,        GAME_ARCHERY_RESET);
        task_post_pure_msg(GAME_ARCHERY_2_ID,      GAME_ARCHERY_2_RESET);
        task_post_pure_msg(GAME_ARROW_ID,          GAME_ARROW_RESET);
        task_post_pure_msg(GAME_ARROW_2_ID,        GAME_ARROW_2_RESET);
        task_post_pure_msg(GAME_BANG_ID,           GAME_BANG_RESET);
        task_post_pure_msg(GAME_BORDER_ID,         GAME_BORDER_RESET);
        task_post_pure_msg(GAME_BORDER_2_ID,       GAME_BORDER_2_RESET);

        timer_set( AC_TASK_DISPLAY_ID, 
                    GAME_EXIT_GAME,
                    GAME_TIME_EXIT_INTERVAL,
                    TIMER_ONE_SHOT);

        GAME_STATE = GAME_OVER;
    }
        BUZZER_PlayTones(tones_3beep);
        break;

    case GAME_EXIT_GAME: {
        APP_DBG_SIG("GAME_EXIT_GAME\n");
        master_joined_game = false;
        slave_joined_game = false;   
        opponent_address = 0;     
        GAME_STATE = GAME_OFF;

        SCREEN_TRAN(scr_game_over_handle, &scr_game_over);
    }
        break;
    
    default:
        break;
    }
}