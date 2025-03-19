#ifndef __SCR_WAITING_OPPONENT__
#define __SCR_WAITING_OPPONENT__

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

#include "eeprom.h"
#include "app_eeprom.h"

#include "buzzer.h"

#include "screens.h"
#include "screens_bitmap.h"

#include "mw24_nwk.h"
#include "mw24_eeprom.h"

#include "scr_archery_game.h"
#include "control_game.h"


extern bool master_joined_game;
extern bool slave_joined_game;

extern view_dynamic_t dyn_view_item_waiting_opponent;
extern view_screen_t scr_waiting_opponent;
extern void scr_waiting_opponent_handle(ak_msg_t* msg); 

#endif //__SCR_WAITING_OPPONENT__