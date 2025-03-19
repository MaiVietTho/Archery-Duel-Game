#ifndef __CONTROL_GAME_H__
#define __CONTROL_GAME_H__

#include <stdio.h>

#include "fsm.h"
#include "port.h"
#include "message.h"
#include "timer.h"

#include "app.h"
#include "app_dbg.h"
#include "task_list.h"
#include "task_display.h"

#include "mw24_nwk.h"

typedef enum {
	RESET_ADDRESS_OPPONENT,

    OPPONENT_ADDRESS_1,
    OPPONENT_ADDRESS_2,
    OPPONENT_ADDRESS_3,
    OPPONENT_ADDRESS_4,
    OPPONENT_ADDRESS_5,

    BUTTON_DOWN_MASTER, //Slave receive Master
    BUTTON_UP_MASTER,
    BUTTON_MODE_MASTER,
    
    BUTTON_DOWN_SLAVE, // Master receive Slave
    BUTTON_UP_SLAVE,
    BUTTON_MODE_SLAVE,

    MASTER_JOINED_GAME, 
	MASTER_OUT_GAME,
    SLAVE_JOINED_GAME,
	SLAVE_OUT_GAME,
} data_transmit;

extern data_transmit DATA_TRANSMIT;

#endif //__CONTROL_GAME_H__