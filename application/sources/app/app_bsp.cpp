#include "button.h"

#include "sys_dbg.h"

#include "app.h"
#include "app_bsp.h"
#include "app_dbg.h"
#include "app_if.h"

#include "task_list.h"
#include "task_list_if.h"

#include "scr_archery_game.h"
#include "mw24_nwk.h"

button_t btn_mode;
button_t btn_up;
button_t btn_down;

void btn_mode_callback(void* b) {
	button_t* me_b = (button_t*)b;
	switch (me_b->state) {
	case BUTTON_SW_STATE_PRESSED: {
		APP_DBG("[btn_mode_callback] BUTTON_SW_STATE_PRESSED\n");
	}
		break;

	case BUTTON_SW_STATE_LONG_PRESSED: {
		APP_DBG("[btn_mode_callback] BUTTON_SW_STATE_LONG_PRESSED\n");
		task_post_pure_msg(AC_TASK_DISPLAY_ID, AC_DISPLAY_BUTTON_MODE_LONG_PRESSED);
	}
		break;

	case BUTTON_SW_STATE_RELEASED: {
		APP_DBG("[btn_mode_callback] BUTTON_SW_STATE_RELEASED\n");
		if (GAME_STATE != GAME_OFF) {
			if (mw24_i_am_master == false) {
				task_post_pure_msg(CONTROL_GAME_ID, AC_DISPLAY_BUTTON_MODE_RELEASED);
				task_post_pure_msg(GAME_ARROW_ID, GAME_ARROW_SHOOT);
			}
			else {
				task_post_pure_msg(CONTROL_GAME_ID, AC_DISPLAY_BUTTON_MODE_RELEASED);
				task_post_pure_msg(GAME_ARROW_2_ID, GAME_ARROW_2_SHOOT);
			}
		}
		else {
			task_post_pure_msg(AC_TASK_DISPLAY_ID, AC_DISPLAY_BUTTON_MODE_RELEASED);	
		}
	}
		break;

	default:
		break;
	}
}

void btn_up_callback(void* b) {
	button_t* me_b = (button_t*)b;
	switch (me_b->state) {
	case BUTTON_SW_STATE_PRESSED: {
		APP_DBG("[btn_up_callback] BUTTON_SW_STATE_PRESSED\n");
	}
		break;

	case BUTTON_SW_STATE_LONG_PRESSED: {
		APP_DBG("[btn_up_callback] BUTTON_SW_STATE_LONG_PRESSED\n");
		task_post_pure_msg(AC_TASK_DISPLAY_ID, AC_DISPLAY_BUTTON_UP_LONG_PRESSED);
	}
		break;

	case BUTTON_SW_STATE_RELEASED: {
		APP_DBG("[btn_up_callback] BUTTON_SW_STATE_RELEASED\n");
		if (GAME_STATE != GAME_OFF) {
			if (mw24_i_am_master == false) {
				task_post_pure_msg(CONTROL_GAME_ID, AC_DISPLAY_BUTTON_UP_RELEASED);
				task_post_pure_msg(GAME_ARCHERY_ID, GAME_ARCHERY_UP);
			}
			else {
				task_post_pure_msg(CONTROL_GAME_ID, AC_DISPLAY_BUTTON_UP_RELEASED);
				task_post_pure_msg(GAME_ARCHERY_2_ID, GAME_ARCHERY_2_UP);
			}
		}
		else {
			task_post_pure_msg(AC_TASK_DISPLAY_ID, AC_DISPLAY_BUTTON_UP_RELEASED);
		}
	}
		break;

	default:
		break;
	}
}

void btn_down_callback(void* b) {
	button_t* me_b = (button_t*)b;
	switch (me_b->state) {
	case BUTTON_SW_STATE_PRESSED: {
		APP_DBG("[btn_down_callback] BUTTON_SW_STATE_PRESSED\n");
	}
		break;

	case BUTTON_SW_STATE_LONG_PRESSED: {
		APP_DBG("[btn_down_callback] BUTTON_SW_STATE_LONG_PRESSED\n");
		task_post_pure_msg(AC_TASK_DISPLAY_ID, AC_DISPLAY_BUTTON_DOWN_LONG_RELEASED);
	}
		break;

	case BUTTON_SW_STATE_RELEASED: {
		APP_DBG("[btn_down_callback] BUTTON_SW_STATE_RELEASED\n");
		if (GAME_STATE != GAME_OFF) {
			if (mw24_i_am_master == false) {
				task_post_pure_msg(CONTROL_GAME_ID, AC_DISPLAY_BUTTON_DOWN_RELEASED);
				task_post_pure_msg(GAME_ARCHERY_ID, GAME_ARCHERY_DOWN);
			}
			else {
				task_post_pure_msg(CONTROL_GAME_ID, AC_DISPLAY_BUTTON_DOWN_RELEASED);
				task_post_pure_msg(GAME_ARCHERY_2_ID, GAME_ARCHERY_2_DOWN);
			}
		}
		else {
			task_post_pure_msg(AC_TASK_DISPLAY_ID, AC_DISPLAY_BUTTON_DOWN_RELEASED);
		}
	}
		break;

	default:
		break;
	}
}
