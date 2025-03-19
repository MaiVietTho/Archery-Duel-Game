#ifndef __SCR_ARCHERY_GAME_H__
#define __SCR_ARCHERY_GAME_H__

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

#include "game_archery.h"
#include "game_archery_person_2.h"
#include "game_arrow.h"
#include "game_arrow_person_2.h"
#include "game_bang.h"
#include "game_border.h"
#include "game_border_person_2.h"
#include "scr_check_connect.h"
#include "scr_waiting_opponent.h"

enum game_state {
    GAME_OFF,
    GAME_PLAY,
    GAME_OVER,
};

extern enum game_state GAME_STATE; 
extern game_setting_t settingsetup;

extern view_dynamic_t dyn_view_item_archery_game;
extern view_screen_t scr_archery_game;
extern void scr_archery_game_handle(ak_msg_t* msg);

#endif // __SCR_ARCHERY_GAME_H_