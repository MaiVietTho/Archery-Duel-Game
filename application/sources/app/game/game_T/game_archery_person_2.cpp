#include "game_archery_person_2.h"

game_archery_2_t archery_2;
static uint32_t archery_y_2 = AXIS_Y_ARCHERY_2;

#define GAME_ARCHERY_2_SETUP()    \
do {                            \
    archery_2.x = AXIS_X_ARCHERY_2; \
    archery_2.y = AXIS_Y_ARCHERY_2; \
    archery_2.visible = WHITE;    \
    archery_2.action_image = 1;   \
} while (0);

#define GAME_ARCHERY_2_UP() \
do { \
    archery_y_2 -= STEP_ARCHERY_AXIS_Y_2; \
    if (archery_y_2 == 0) \
    { \
        archery_y_2 = 10; \
    } \
} while (0);

#define GAME_ARCHERY_2_DOWN() \
do { \
    archery_y_2 += STEP_ARCHERY_AXIS_Y_2; \
    if (archery_y_2 > 50) \
    { \
        archery_y_2 = 50; \
    } \
} while (0);

#define GAME_ARCHERY_2_RESET() \
do { \
    archery_2.x = AXIS_X_ARCHERY_2; \
    archery_2.y = AXIS_Y_ARCHERY_2; \
    archery_2.visible = BLACK; \
    archery_y_2 = AXIS_Y_ARCHERY_2; \
} while (0);

void game_archery_2_handle(ak_msg_t *msg)
{
    switch (msg->sig)
    {
    case GAME_ARCHERY_2_SETUP:
    {
        APP_DBG_SIG("GAME_ARCHERY_2_SETUP\n");
        GAME_ARCHERY_2_SETUP();
    }
    break;

    case GAME_ARCHERY_2_UPDATE:
    {
        APP_DBG_SIG("GAME_ARCHERY_2_UPDATE\n");
        archery_2.y = archery_y_2;
    }
    break;

    case GAME_ARCHERY_2_UP:
    {
        APP_DBG_SIG("GAME_ARCHERY_2_UP\n");
        GAME_ARCHERY_2_UP();
    }
    break;

    case GAME_ARCHERY_2_DOWN:
    {
        APP_DBG_SIG("GAME_ARCHERY_2_DOWN\n");
        GAME_ARCHERY_2_DOWN();
    }
    break;

    case GAME_ARCHERY_2_RESET:
    {
        APP_DBG_SIG("GAME_ARCHERY_2_RESET\n");
        GAME_ARCHERY_2_RESET();
    }
    break;

    default:
        break;
    }
}
