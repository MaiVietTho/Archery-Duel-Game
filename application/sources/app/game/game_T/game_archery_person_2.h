#ifndef __GAME_ARCHERY_PERSON_2_H__
#define __GAME_ARCHERY_PERSON_2_H__

#include <stdio.h>

#include "fsm.h"
#include "port.h"
#include "message.h"
#include "timer.h"

#include "app.h"
#include "app_dbg.h"
#include "task_list.h"
#include "task_display.h"
#include "view_render.h"

#include "scr_archery_game.h"

#define STEP_ARCHERY_AXIS_Y_2     (10)
#define SIZE_BITMAP_ARCHERY_X_2   (15)
#define SIZE_BITMAP_ARCHERY_Y_2   (15)
#define AXIS_X_ARCHERY_2          (114)
#define AXIS_Y_ARCHERY_2          (30)

typedef struct {
    bool visible;
    uint32_t x,y;
    uint8_t action_image;
} game_archery_2_t;

extern game_archery_2_t archery_2;

#endif // __GAME_ARCHERY_PERSON_2_H__