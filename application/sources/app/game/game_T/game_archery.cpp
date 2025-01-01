#include "game_archery.h"

game_archery_t archery;
static uint32_t archery_y = AXIS_Y_ARCHERY;

#define GAME_ARCHERY_SETUP()    \
do {                            \
    archery.x = AXIS_X_ARCHERY; \
    archery.y = AXIS_Y_ARCHERY; \
    archery.visible = WHITE;    \
    archery.action_image = 1;   \
} while (0);

#define GAME_ARCHERY_UP() \
do { \
    archery_y -= STEP_ARCHERY_AXIS_Y; \
    if (archery_y == 0) \
    { \
        archery_y = 10; \
    } \
} while (0);

#define GAME_ARCHERY_DOWN() \
do { \
    archery_y += STEP_ARCHERY_AXIS_Y; \
    if (archery_y > 50) \
    { \
        archery_y = 50; \
    } \
} while (0);

#define GAME_ARCHERY_RESET() \
do { \
    archery.x = AXIS_X_ARCHERY; \
    archery.y = AXIS_Y_ARCHERY; \
    archery.visible = BLACK; \
    archery_y = AXIS_Y_ARCHERY; \
} while (0);

void game_archery_handle(ak_msg_t *msg)
{
    switch (msg->sig)
    {
    case GAME_ARCHERY_SETUP:
    {
        APP_DBG_SIG("GAME_ARCHERY_SETUP\n");
        GAME_ARCHERY_SETUP();
    }
    break;

    case GAME_ARCHERY_UPDATE:
    {
        APP_DBG_SIG("GAME_ARCHERY_UPDATE\n");
        archery.y = archery_y;
    }
    break;

    case GAME_ARCHERY_UP:
    {
        APP_DBG_SIG("GAME_ARCHERY_UP\n");
        GAME_ARCHERY_UP();
    }
    break;

    case GAME_ARCHERY_DOWN:
    {
        APP_DBG_SIG("GAME_ARCHERY_DOWN\n");
        GAME_ARCHERY_DOWN();
    }
    break;

    case GAME_ARCHERY_RESET:
    {
        APP_DBG_SIG("GAME_ARCHERY_RESET\n");
        GAME_ARCHERY_RESET();
    }
    break;

    default:
        break;
    }
}
