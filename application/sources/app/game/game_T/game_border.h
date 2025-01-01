#ifndef __GAME_BORDER_H__
#define __GAME_BORDER_H__

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
#include "game_arrow_person_2.h"

#define AXIS_X_BORDER           (15)
#define AXIS_Y_BORDER_ON        (2)
#define AXIS_Y_BORDER_UNDER     (52)

typedef struct {
    bool visible;
    uint32_t x,y;
    uint8_t action_image;
} game_border_t;

extern game_border_t border;
extern uint32_t game_score;
extern bool person_left_win;

#endif // _GAME_BORDER_H__
