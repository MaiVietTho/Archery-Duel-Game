#include "task_list.h"
#include "timer.h"

const task_t app_task_table[] = {
	/*************************************************************************/
	/* SYSTEM TASK */
	/*************************************************************************/
	{TASK_TIMER_TICK_ID,		TASK_PRI_LEVEL_7,		task_timer_tick			},

	/*************************************************************************/
	/* APP TASK */
	/*************************************************************************/
	{AC_TASK_SYSTEM_ID			,	TASK_PRI_LEVEL_2	,	task_system			},
	{AC_TASK_FW_ID				,	TASK_PRI_LEVEL_2	,	task_fw				},
	{AC_TASK_SHELL_ID			,	TASK_PRI_LEVEL_2	,	task_shell			},
	{AC_TASK_LIFE_ID			,	TASK_PRI_LEVEL_6	,	task_life			},
	{AC_TASK_IF_ID				,	TASK_PRI_LEVEL_4	,	task_if				},
	{AC_TASK_UART_IF_ID			,	TASK_PRI_LEVEL_4	,	task_uart_if		},
	{AC_TASK_DBG_ID				,	TASK_PRI_LEVEL_4	,	task_dbg			},
	{AC_TASK_DISPLAY_ID			,	TASK_PRI_LEVEL_4	,	task_display		},

	/* ARCHERY GAME */
	/*************************************************************************/
	{GAME_ARCHERY_ID			,	TASK_PRI_LEVEL_4	,	game_archery_handle			},
	{GAME_ARCHERY_2_ID			,	TASK_PRI_LEVEL_4	,	game_archery_2_handle		},
	{GAME_ARROW_ID				,	TASK_PRI_LEVEL_4	,	game_arrow_handle			},
	{GAME_ARROW_2_ID			,	TASK_PRI_LEVEL_4	,	game_arrow_2_handle			},
	{GAME_BORDER_ID				,	TASK_PRI_LEVEL_4	, 	game_border_handle			},
	{GAME_BORDER_2_ID			,	TASK_PRI_LEVEL_4	, 	game_border_2_handle		},
	{GAME_BANG_ID				,	TASK_PRI_LEVEL_4	,	game_bang_handle			},
	{GAME_SCREEN_ID				,	TASK_PRI_LEVEL_4	,	scr_archery_game_handle		},
	{CONTROL_GAME_ID			,	TASK_PRI_LEVEL_4	, 	control_game_handle			},
	{WAITING_OPPONENT_ID		,	TASK_PRI_LEVEL_4	,	scr_waiting_opponent_handle	},

	/*************************************************************************/
	/* LINK TASK */
	/*************************************************************************/
	#if defined (IF_LINK_UART_EN)
	{AC_LINK_PHY_ID				,	TASK_PRI_LEVEL_3	,	task_link_phy		},
	{AC_LINK_MAC_ID				,	TASK_PRI_LEVEL_4	,	task_link_mac		},
	{AC_LINK_ID					,	TASK_PRI_LEVEL_5	,	task_link			},
	#endif

	/*************************************************************************/
	/* END OF TABLE */
	/*************************************************************************/
	{AK_TASK_EOT_ID				,	TASK_PRI_LEVEL_0	,	(pf_task)0			}
};

const task_polling_t app_task_polling_table[] = {
	{AC_TASK_POLLING_CONSOLE_ID	,	AK_ENABLE	,	task_polling_console		},
	{AK_TASK_POLLING_EOT_ID		,	AK_DISABLE	,	(pf_task_polling)0			},
};
