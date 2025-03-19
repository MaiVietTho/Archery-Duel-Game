#ifndef __TASK_LIST_H__
#define __TASK_LIST_H__

#include "ak.h"
#include "task.h"

extern const task_t app_task_table[];
extern const task_polling_t app_task_polling_table[];

/*****************************************************************************/
/*  DECLARE: Internal Task ID
 *  Note: Task id MUST be increasing order.
 */
/*****************************************************************************/
enum {
	/* SYSTEM TASKS */
	TASK_TIMER_TICK_ID,

	/* APP TASKS */
	AC_TASK_SYSTEM_ID,
	AC_TASK_FW_ID,
	AC_TASK_SHELL_ID,
	AC_TASK_LIFE_ID,
	AC_TASK_IF_ID,
	AC_TASK_UART_IF_ID,
	AC_TASK_DBG_ID,
	AC_TASK_DISPLAY_ID,

	/* ARCHERY GAME */
	GAME_ARCHERY_ID,
	GAME_ARCHERY_2_ID,
	GAME_ARROW_ID,
	GAME_ARROW_2_ID,
	GAME_BORDER_ID,
	GAME_BORDER_2_ID,

	GAME_BANG_ID,
	GAME_SCREEN_ID,
	CONTROL_GAME_ID,
	WAITING_OPPONENT_ID,

	/* LINK */
#if defined (IF_LINK_UART_EN)
	AC_LINK_PHY_ID,
	AC_LINK_MAC_ID,
	AC_LINK_ID,
#endif

	/* EOT task ID */
	AK_TASK_EOT_ID,
};

/*****************************************************************************/
/*  DECLARE: Internal Polling Task ID
 *  Note: Task id MUST be increasing order.
 */
/*****************************************************************************/
enum {
	/* APP TASKS */
	AC_TASK_POLLING_CONSOLE_ID,
	/* EOT polling task ID */
	AK_TASK_POLLING_EOT_ID,
};

/*****************************************************************************/
/*  DECLARE: Task entry point
 */
/*****************************************************************************/
/* APP TASKS */
extern void task_system(ak_msg_t*);
extern void task_fw(ak_msg_t*);
extern void task_shell(ak_msg_t*);
extern void task_life(ak_msg_t*);
extern void task_if(ak_msg_t*);
extern void task_uart_if(ak_msg_t*);
extern void task_dbg(ak_msg_t*);
extern void task_display(ak_msg_t*);

/* LINK TASK */
extern void task_link_phy(ak_msg_t*);
extern void task_link_mac(ak_msg_t*);
extern void task_link(ak_msg_t*);

/* ARCHERY GAME HANDLE */
extern void scr_archery_game_handle(ak_msg_t* msg);
extern void game_archery_handle(ak_msg_t* msg);
extern void game_archery_2_handle(ak_msg_t* msg);
extern void game_arrow_handle(ak_msg_t* msg);
extern void game_arrow_2_handle(ak_msg_t* msg);
extern void game_meteoroid_handle(ak_msg_t* msg);
extern void game_border_handle(ak_msg_t* msg);
extern void game_border_2_handle(ak_msg_t* msg);
extern void game_bang_handle(ak_msg_t* msg);
extern void control_game_handle(ak_msg_t* msg);  
extern void scr_waiting_opponent_handle(ak_msg_t* msg); 

/*****************************************************************************/
/*  DECLARE: Task polling
 */
/*****************************************************************************/
extern void task_polling_console();

#endif //__TASK_LIST_H__
