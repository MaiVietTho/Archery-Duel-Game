#ifndef __SCR_CHECK_CONNECT_H__
#define __SCR_CHECK_CONNECT_H__

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

#include "app_eeprom.h"
#include "eeprom.h"
#include "mw24_eeprom.h"

#include "mw24_nwk.h"
#include "ring_buffer.h"
#include "hal_nrf.h"
typedef enum {
    BUTTON_DOWN_MASTER,
    BUTTON_UP_MASTER,
    BUTTON_MODE_MASTER,
    BUTTON_DOWN_SLAVE,
    BUTTON_UP_SLAVE,
    BUTTON_MODE_SLAVE,
} button_transmit;

extern button_transmit BUTTON_TRANSMIT; 
extern view_dynamic_t dyn_view_check_connect;

extern view_screen_t scr_check_connect;
extern void scr_check_connect_handle(ak_msg_t* msg);

#endif // __SCR_CHECK_CONNECT_H__