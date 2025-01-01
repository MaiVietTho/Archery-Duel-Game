#include "game_border_person_2.h"

#include "game_archery_person_2.h"
// #include "game_meteoroid.h"

game_border_2_t border_2;
// uint32_t game_score = 10;

#define GAME_BORDER_2_SETUP() \
do { \
    border_2.x = AXIS_X_BORDER_2; \
    border_2.visible = WHITE; \
    border_2.action_image = 0; \
}  while(0);

#define GAME_CHECK_GAME_OVER_2() \
do { \
    for (uint8_t i = 0; i < MAX_NUM_ARROW; i++){ \
        if(arrow[i].x >= (border_2.x+3)) { \
            person_left_win = true; \
            task_post_pure_msg(GAME_SCREEN_ID, GAME_RESET); \
        } \
    } \
} while(0);

#define GAME_BORDER_2_RESET() \
do { \
    border_2.x = AXIS_X_BORDER_2; \
    border_2.visible = BLACK; \
} while(0)

void game_border_2_handle(ak_msg_t* msg){
    switch (msg->sig)
    {
    case GAME_BORDER_2_SETUP: {
        APP_DBG_SIG("GAME_BORDER_2_SETUP\n");
        GAME_BORDER_2_SETUP();
    }
        break;
    
    case GAME_CHECK_GAME_OVER_2: {
        APP_DBG_SIG("GAME_CHECK_GAME_OVER_2\n");
        GAME_CHECK_GAME_OVER_2();
    }
        break;

    case GAME_BORDER_2_RESET: {
        APP_DBG_SIG("GAME_BORDER_2_RESET\n");
        GAME_BORDER_2_RESET();
    }
        break;
        
    default:
        break;
    }
}