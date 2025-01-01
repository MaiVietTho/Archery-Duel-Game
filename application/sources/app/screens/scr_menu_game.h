#ifndef __SCR_MENU_GAME_H__
#define __SCR_MENU_GAME_H__

#include "fsm.h"
#include "port.h"
#include "message.h"
#include "timer.h"

#include "sys_ctrl.h"
#include "sys_dbg.h"

#include "app.h"
#include "app_dbg.h"
#include "task_list.h"
#include "task_display.h"
#include "view_render.h"

#include "buzzer.h"

#include "screens.h"
#include "screens_bitmap.h"

#define STEP_MENU_CHOOSE_GAME            (22)
#define NUMBER_MENU_ITEMS_GAME           (3)
#define SCREEN_MENU_H_GAME               (64)

#define GAME_MENU_ICON_AXIS_X			(7)
#define GAME_MENU_TEXT_AXIS_X			(20)

extern view_dynamic_t dyn_view_item_menu_game;
extern view_screen_t scr_menu_game;
extern void scr_menu_game_handle(ak_msg_t* msg);

#endif // __SCR_MENU_GAME_H__