#ifndef __SCR_GAME_SETTING_H__
#define __SCR_GAME_SETTING_H__

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

#include "eeprom.h"
#include "app_eeprom.h"

#include "screens.h"
#include "screens_bitmap.h"

#define STEP_SETTING_CHOOSE                         (15)
//ITEM
#define SETTING_ITEM_ARRDESS_0                      (0)
#define SETTING_ITEM_ARRDESS_1                      (STEP_SETTING_CHOOSE)
#define SETTING_ITEM_ARRDESS_2                      (STEP_SETTING_CHOOSE*2)
#define SETTING_ITEM_ARRDESS_3                      (STEP_SETTING_CHOOSE*3)
#define SETTING_ITEM_ARRDESS_4                      (STEP_SETTING_CHOOSE*4)
// Text anf number
#define GAME_SETTING_TEXT_AXIS_X                    (20)
#define GAME_SETTING_NUMBER_AXIS_X                  (110)
// Choose icon
#define GAME_SETTING_CHOOSE_ICON_AXIS_Y             (17)
#define GAME_SETTING_CHOOSE_ICON_SIZE_W		        (20)
#define GAME_SETTING_CHOOSE_ICON_SIZE_H		        (20)
// Frames	
#define GAME_SETTING_FRAMES_AXIS_X		        	(20)
#define GAME_SETTING_FRAMES_AXIS_Y_1		    	(2)
#define GAME_SETTING_FRAMES_STEP 		          	(15)
#define GAME_SETTING_FRAMES_SIZE_W		        	(103)
#define GAME_SETTING_FRAMES_SIZE_H		        	(13)
#define GAME_SETTING_FRAMES_SIZE_R		        	(3)
// SPEAKER
#define GAME_SETTING_SPEAKER_AXIS_X                 (109)
#define GAME_SETTING_SPEAKER_SIZE_W                 (7)
#define GAME_SETTING_SPEAKER_SIZE_H                 (7)

extern game_setting_t setting_data;
extern view_dynamic_t dyn_view_item_game_setting;
extern view_screen_t scr_game_setting;
extern void scr_game_setting_handle(ak_msg_t* msg);

#endif // __SCR_GAME_SETTING_H__