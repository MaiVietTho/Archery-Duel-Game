#ifndef __GAME_BORDER_PERSON_2_H__
#define __GAME_BORDER_PERSON_2_H__

#include "fsm.h"
#include "port.h"
#include "message.h"
#include "timer.h"

#include "app.h"
#include "app_dbg.h"
#include "task_list.h"
#include "task_display.h"

#include "buzzer.h"
#include "scr_archery_game.h"
#include "game_arrow.h"

#define AXIS_X_BORDER_2           (113)
#define AXIS_Y_BORDER_ON_2        (2)
#define AXIS_Y_BORDER_UNDER_2     (52)

typedef struct {
    bool visible;
    uint32_t x,y;
    uint8_t action_image;
} game_border_2_t;

extern game_border_2_t border_2;
// extern uint32_t game_score;

#endif // __GAME_BORDER_PERSON_2_H__
