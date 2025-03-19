#include "scr_menu_game.h"

#define MENU_ITEMS_ICON_COLOR_GAME() \
do { \
    menu_items_icon_color_game[0] = !menu_choose_game.items.is_item_1; \
    menu_items_icon_color_game[1] = !menu_choose_game.items.is_item_2; \
    menu_items_icon_color_game[2] = !menu_choose_game.items.is_item_3; \
} while(0);

struct menu_items {
    unsigned int is_item_1 : 1;
    unsigned int is_item_2 : 1;
    unsigned int is_item_3 : 1;
};

// Screen and item location on the Menu
typedef struct {
    int screen;
    int location;
} screen_t;

// Menu items ID
union scr_menu_t
{
    uint32_t id = 1;
    menu_items items;
};

// Scroll bar
typedef struct {
    uint8_t axis_x = 126;
    uint8_t axis_y = 0; 
    uint8_t size_W = 3;
    uint8_t size_H = SCREEN_MENU_H_GAME / NUMBER_MENU_ITEMS_GAME;
} scr_menu_scroll_bar_t;

// Frame
typedef struct {
    uint8_t axis_x = 0;
    uint8_t axis_y = 0;
    uint8_t size_W = 123;
    uint8_t size_H = 20;
    uint8_t size_r = 3;
} scr_menu_frames_t;

screen_t screen_menu_game;
scr_menu_t menu_choose_game;
scr_menu_scroll_bar_t scroll_bar_game;
scr_menu_frames_t frame_White_game;
scr_menu_frames_t frame_game[3];

//Name
static char menu_items_name_game[NUMBER_MENU_ITEMS_GAME][20] = {
    "   Archery Game   ",		// item 1
	"   Setting        ",		// item 2
	"   Exit           ",		// item 3
};

// Menu items icon
static const uint8_t *menu_items_icon_game[NUMBER_MENU_ITEMS_GAME] = {
    archery_icon,				// item 1
	setting_icon,				// item 2
	exit_icon,					// item 3
};

uint8_t menu_items_icon_size_W_game[NUMBER_MENU_ITEMS_GAME] = {
    15,                         // item 1
    16,                         // item 2
    15,                         // item 3
};

uint8_t menu_items_icon_size_H_game[NUMBER_MENU_ITEMS_GAME] = {
    15,                         // item 1
    16,                         // item 2
    15,                         // item 3
};

// Menu items icon
uint8_t menu_items_icon_color_game[NUMBER_MENU_ITEMS_GAME];

uint8_t menu_items_icon_axis_y_game[3] = {
    2,							// icon frame 1
	24,							// icon frame 2
	46,							// icon frame 3
};

static void view_scr_menu_game();

view_dynamic_t dyn_view_item_menu_game = {
    {
        .item_type = ITEM_TYPE_DYNAMIC,
    },
    view_scr_menu_game
};

view_screen_t scr_menu_game = {
    &dyn_view_item_menu_game,
    ITEM_NULL,
    ITEM_NULL,

    .focus_item = 0,
};

void view_scr_menu_game() {
    // Scroll bar and dot
    view_render.fillRect(  scroll_bar_game.axis_x - 1,
                           scroll_bar_game.axis_y,
                           scroll_bar_game.size_W,
                           scroll_bar_game.size_H,
                           WHITE);
    view_render.drawBitmap( scroll_bar_game.axis_x,
                            0,
                            dot_icon,
                            1,
                            SCREEN_MENU_H_GAME,
                            WHITE);

    // Frame White
    view_render.fillRoundRect(  frame_White_game.axis_x,
                                frame_White_game.axis_y,
                                frame_White_game.size_W,
                                frame_White_game.size_H,
                                frame_White_game.size_r,
                                WHITE);

    for(uint8_t i = 0; i < 3; i++) {
         // Frames
        view_render.drawRoundRect(  frame_game[i].axis_x,
                                    frame_game[i].axis_y,
                                    frame_game[i].size_W,
                                    frame_game[i].size_H,
                                    frame_game[i].size_r,
                                    WHITE);

        // Icon 
        view_render.drawBitmap( GAME_MENU_ICON_AXIS_X,
                                menu_items_icon_axis_y_game[i],
                                menu_items_icon_game[screen_menu_game.screen + i],
                                menu_items_icon_size_W_game[screen_menu_game.screen + i],
                                menu_items_icon_size_H_game[screen_menu_game.screen + i],
                                menu_items_icon_color_game[screen_menu_game.screen + i]);
    }

    view_render.setTextSize(1);
    for (uint8_t i = 0; i < 3; i++) {
        view_render.setTextColor(menu_items_icon_color_game[screen_menu_game.screen + i]);
        view_render.setCursor(GAME_MENU_TEXT_AXIS_X,menu_items_icon_axis_y_game[i] + 5);
        view_render.print(menu_items_name_game[screen_menu_game.screen + i]);
    }
}

void update_menu_screen_choose_game() {
    // Frames location
    frame_White_game.axis_y = frame_game[screen_menu_game.location - screen_menu_game.screen].axis_y;
    frame_game[0].axis_y = 0;
    frame_game[1].axis_y = 22;
    frame_game[2].axis_y = 44;

    //update color menu
    menu_choose_game.id = 1 << screen_menu_game.location;
    MENU_ITEMS_ICON_COLOR_GAME();

    // update scroll bar
    scroll_bar_game.axis_y = (SCREEN_MENU_H_GAME * screen_menu_game.location / NUMBER_MENU_ITEMS_GAME);
}

void screen_tran_menu_game() {
    switch (screen_menu_game.location)
    {
    case 0:  // item 1
        SCREEN_TRAN(scr_waiting_opponent_handle, &scr_waiting_opponent);
        break;

    case 1: // item 2
        SCREEN_TRAN(scr_game_setting_handle, &scr_game_setting);
        break;

    case 2: // item 3
        SCREEN_TRAN(scr_menu_handle, &scr_menu);
        break;

    default:
        break;
    }
}

void scr_menu_game_handle(ak_msg_t* msg) {
    switch (msg->sig)
    {
    case SCREEN_ENTRY: {
        APP_DBG_SIG("SCREEN_ENTRY\n");
        view_render.initialize();
        view_render_display_on();
        update_menu_screen_choose_game();
    }
        break;
    
    case AC_DISPLAY_BUTTON_MODE_RELEASED: {
        APP_DBG_SIG("AC_DISPLAY_BUTTON_MODE_RELEASED\n");
        send_address_to_opponent();
        screen_tran_menu_game();
    }
        break;

    case AC_DISPLAY_BUTTON_UP_RELEASED: {
        APP_DBG_SIG("AC_DISPLAY_BUTTON_UP_RELEASED\n");
        if (screen_menu_game.location > 0) {
            screen_menu_game.location--;
        }
        if(frame_White_game.axis_y == frame_game[0].axis_y) {
            if (screen_menu_game.screen > 0) {
                screen_menu_game.screen--;
            }
        }
        else if (frame_White_game.axis_y == frame_game[1].axis_y) {
            frame_White_game.axis_y = frame_game[0].axis_y;
        }
        else if (frame_White_game.axis_y == frame_game[2].axis_y) {
            frame_White_game.axis_y = frame_game[1].axis_y;
        } 
        update_menu_screen_choose_game();
    }
        BUZZER_PlayTones(tones_cc);
        break;

    case AC_DISPLAY_BUTTON_DOWN_RELEASED: {
        APP_DBG_SIG("AC_DISPLAY_BUTTON_DOWN_RELEASED\n");
        if (screen_menu_game.location < NUMBER_MENU_ITEMS_GAME - 1) {
            screen_menu_game.location++;
        }
        if (frame_White_game.axis_y == frame_game[0].axis_y) {
            frame_White_game.axis_y = frame_game[1].axis_y;
        }
        else if (frame_White_game.axis_y == frame_game[1].axis_y) {
            frame_White_game.axis_y = frame_game[2].axis_y;
        }
        else if (frame_White_game.axis_y == frame_game[2].axis_y) {
            if (screen_menu_game.screen < NUMBER_MENU_ITEMS_GAME - 3) {
                screen_menu_game.screen++;
            }
        }
        update_menu_screen_choose_game();
    }
        BUZZER_PlayTones(tones_cc);
        break;
        
    default:
        break;
    }
}