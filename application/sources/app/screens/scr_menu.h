#ifndef __SCR_MENU_H__
#define __SCR_MENU_H__

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

extern view_dynamic_t dyn_view_menu;
extern view_screen_t scr_menu;
extern void scr_menu_handle(ak_msg_t* msg);

#endif // __SCR_MENU_H__