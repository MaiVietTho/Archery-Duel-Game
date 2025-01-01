#ifndef __GAME_ARROW_PERSON_2_H__
#define __GAME_ARROW_PERSON_2_H__

#include <stdio.h>

#include "fsm.h"
#include "port.h"
#include "message.h"

#include "app.h"
#include "app_dbg.h"
#include "task_list.h"
#include "task_display.h"

#include "buzzer.h"
#include "scr_archery_game.h"

#define MAX_NUM_ARROW_2         (5)
#define MIN_AXIS_X_ARROW_2      (8)
#define SIZE_BITMAP_ARROW_X_2   (10)
#define SIZE_BITMAP_ARROW_Y_2   (5)

typedef struct {
    bool visible;
    uint32_t x, y;
    uint8_t action_image;
} game_arrow_2_t;

extern game_arrow_2_t arrow_2[MAX_NUM_ARROW_2];

#endif // __GAME_ARROW_PERSON_2_H__