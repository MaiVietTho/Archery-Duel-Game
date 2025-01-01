#include "game_border.h"

#include "game_archery.h"

game_border_t border;
uint32_t game_score = 10;
bool person_left_win;

#define GAME_BORDER_SETUP() \
do { \
    border.x = AXIS_X_BORDER; \
    border.visible = WHITE; \
    border.action_image = 0; \
}  while(0);

#define GAME_CHECK_GAME_OVER() \
do { \
    for (uint8_t i = 0; i < MAX_NUM_ARROW_2; i++){ \
        if(arrow_2[i].x <= (border.x-3)) { \
            person_left_win = false; \
            task_post_pure_msg(GAME_SCREEN_ID, GAME_RESET); \
        } \
    } \
} while(0);

#define GAME_BORDER_RESET() \
do { \
    border.x = AXIS_X_BORDER; \
    border.visible = BLACK; \
} while(0)

void game_border_handle(ak_msg_t* msg){
    switch (msg->sig)
    {
    case GAME_BORDER_SETUP: {
        APP_DBG_SIG("GAME_BORDER_SETUP\n");
        GAME_BORDER_SETUP();
    }
        break;
    
    case GAME_CHECK_GAME_OVER: {
        APP_DBG_SIG("GAME_CHECK_GAME_OVER\n");
        GAME_CHECK_GAME_OVER();
    }
        break;

    case GAME_BORDER_RESET: {
        APP_DBG_SIG("GAME_BORDER_RESET\n");
        GAME_BORDER_RESET();
    }
        break;
        
    default:
        break;
    }
}