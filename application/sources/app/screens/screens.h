#ifndef __SCREENS_H__
#define __SCREENS_H__

#include "view_item.h"

/* screens */
#include "scr_startup.h"
#include "scr_menu.h"
#include "scr_inform.h"
#include "scr_check_connect.h"
#include "scr_setting.h"

// scr_archery_game
extern view_dynamic_t dyn_view_item_archery_game;
extern view_screen_t scr_archery_game;
extern void scr_archery_game_handle(ak_msg_t* msg);

// scr_charts_game
extern view_dynamic_t dyn_view_item_charts_game;
extern view_screen_t scr_charts_game;
extern void scr_charts_game_handle(ak_msg_t* msg);

// scr_game_over
extern view_dynamic_t dyn_view_item_game_over;
extern view_screen_t scr_game_over;
extern void scr_game_over_handle(ak_msg_t* msg);

// scr_game_setting
extern view_dynamic_t dyn_view_item_game_setting;
extern view_screen_t scr_game_setting;
extern void scr_game_setting_handle(ak_msg_t* msg);

// scr_menu_game
extern view_dynamic_t dyn_view_item_menu_game;
extern view_screen_t scr_menu_game;
extern void scr_menu_game_handle(ak_msg_t* msg);

extern view_dynamic_t dyn_view_item_waiting_opponent;
extern view_screen_t scr_waiting_opponent;
extern void scr_waiting_opponent_handle(ak_msg_t* msg); 

/********************************************************** */

// screen startup
extern view_dynamic_t dyn_view_startup;
extern view_screen_t scr_startup;
extern void scr_startup_handle(ak_msg_t* msg);

// screen menu
extern view_dynamic_t dyn_view_menu;
extern view_screen_t scr_menu;
extern void scr_menu_handle(ak_msg_t* msg);

// screen inform
extern view_dynamic_t dyn_view_inform;
extern view_screen_t scr_inform;
extern void scr_inform_handle(ak_msg_t* msg);

// screen test connect
extern view_dynamic_t dyn_view_check_connect;
extern view_screen_t scr_check_connect;
extern void scr_check_connect_handle(ak_msg_t* msg);

// screen setting
extern view_dynamic_t dyn_view_setting;
extern view_screen_t scr_setting;
extern void scr_setting_handle(ak_msg_t* msg);

// screen idle
extern view_dynamic_t dyn_view_idle;
extern view_screen_t scr_idle;
extern void scr_idle_handle(ak_msg_t* msg);

#endif //__SCREENS_H__