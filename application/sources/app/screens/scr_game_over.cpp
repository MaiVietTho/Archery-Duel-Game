#include "scr_game_over.h"
#include "game_border.h"

static game_score_t game_score_eeprom;

static void view_scr_game_over();

view_dynamic_t dyn_view_item_game_over = {
    {
        .item_type = ITEM_TYPE_DYNAMIC,
    },
    view_scr_game_over
};

view_screen_t scr_game_over = {
    &dyn_view_item_game_over,
    ITEM_NULL,
    ITEM_NULL,

    .focus_item = 0,
};

void view_scr_game_over() {
    view_render.clear();
    view_render.setTextSize(2);
    view_render.setTextColor(WHITE);
    view_render.setCursor(30, 10);
    view_render.print("1 VS 1");
    view_render.setTextSize(1);
    view_render.setTextColor(WHITE);
    view_render.setCursor(10, 32);
    view_render.print("Winner:");
    view_render.setCursor(55, 32);
    if (person_left_win == true) {
        view_render.print("Person left");
    }
    else {
        view_render.print("Person right");
    }

    // Icon
	view_render.drawBitmap(10, 	48,	icon_restart,	15,	15,	WHITE);
	// view_render.drawBitmap(55, 	50,	icon_charts,	17,	15,	WHITE);
	view_render.drawBitmap(100,	48,	icon_go_home,	16,	16,	WHITE);
}

void rank_ranking() {
    if (game_score_eeprom.score_now > game_score_eeprom.score_1st) {
        game_score_eeprom.score_3rd = game_score_eeprom.score_2nd;
        game_score_eeprom.score_2nd = game_score_eeprom.score_1st;
        game_score_eeprom.score_1st = game_score_eeprom.score_now;
    }
    else if (game_score_eeprom.score_now > game_score_eeprom.score_2nd) {
        game_score_eeprom.score_3rd = game_score_eeprom.score_2nd;
        game_score_eeprom.score_2nd = game_score_eeprom.score_now;
    }
    else if (game_score_eeprom.score_now > game_score_eeprom.score_3rd) {
        game_score_eeprom.score_3rd = game_score_eeprom.score_now;
    }
}

void scr_game_over_handle(ak_msg_t* msg) {
    switch (msg->sig)
    {
    case SCREEN_ENTRY: {
        APP_DBG_SIG("SCREEN_ENTRY\n");
        // View render
		view_render.initialize();
		view_render_display_on();

        eeprom_read(  EEPROM_SCORE_START_ADDR, 
                      (uint8_t*)&game_score_eeprom,
                      sizeof(game_score_eeprom));

        eeprom_read(  EEPROM_SCORE_PLAY_ADDR,
                      (uint8_t*)&game_score_eeprom.score_now,
                      sizeof(game_score_eeprom.score_now));

        rank_ranking();
    }
        break;
    
    case AC_DISPLAY_BUTTON_MODE_RELEASED: {
        APP_DBG_SIG("AC_DISPLAY_BUTTON_MODE_RELEASED\n");
        eeprom_write(  EEPROM_SCORE_START_ADDR,
                       (uint8_t*)&game_score_eeprom,
                       sizeof(game_score_eeprom));

        SCREEN_TRAN(scr_menu_game_handle, &scr_menu_game);
    }
        BUZZER_PlayTones(tones_cc);
        break;

    // case AC_DISPLAY_BUTTON_UP_RELEASED: {
    //     APP_DBG_SIG("AC_DISPLAY_BUTON_UP_RELEASED\n");
    //     eeprom_write(  EEPROM_SCORE_START_ADDR,
    //                    (uint8_t*)&game_score_eeprom,
    //                    sizeof(game_score_eeprom));
    //     SCREEN_TRAN(scr_charts_game_handle, &scr_charts_game);
    // }
    //     BUZZER_PlayTones(tones_cc);
    //     break;
        
    case AC_DISPLAY_BUTTON_DOWN_RELEASED: {
        APP_DBG_SIG("AC_DISPLAY_BUTON_DOWN_RELEASED\n");
        eeprom_write(  EEPROM_SCORE_START_ADDR,
                       (uint8_t*)&game_score_eeprom,
                       sizeof(game_score_eeprom));
        SCREEN_TRAN(scr_archery_game_handle, &scr_archery_game);
    }
        BUZZER_PlayTones(tones_cc);
        break;

    default:
        break;
    }
}