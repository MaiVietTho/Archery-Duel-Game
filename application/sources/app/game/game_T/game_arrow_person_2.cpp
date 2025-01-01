#include "game_arrow_person_2.h"

#include "game_archery_person_2.h"
#include "scr_archery_game.h"

game_arrow_2_t arrow_2[MAX_NUM_ARROW_2];

#define GAME_ARROW_2_SETUP() \
do {  \
    for(uint8_t i = 0; i < MAX_NUM_ARROW_2; i++) { \
        arrow_2[i].x = 113; \
        arrow_2[i].y = 0; \
        arrow_2[i].visible = BLACK; \
        arrow_2[i].action_image = 1; \
     } \
} while(0);

#define GAME_ARROW_2_RUN() \
do { \
    for(uint8_t i = 0; i < MAX_NUM_ARROW_2; i++) { \
        if (arrow_2[i].visible == WHITE) { \
            arrow_2[i].x -= settingsetup.arrow_speed; \
        } \
    } \
} while(0);

#define GAME_ARROW_2_SHOOT() \
do { \
    for (uint8_t i = 0; i < MAX_NUM_ARROW_2; i++){ \
        if (arrow_2[i].visible == BLACK && settingsetup.num_arrow_2 != 0) { \
            settingsetup.num_arrow_2--; \
            arrow_2[i].visible = WHITE; \
            arrow_2[i].y = archery_2.y - 5; \
            BUZZER_PlayTones(tones_cc); \
            break; \
        } \
        else if (settingsetup.num_arrow_2 == 0) { \
            BUZZER_PlayTones(tones_3beep); \
            break; \
        } \
    } \
} while(0);

#define GAME_ARROW_2_RESET() \
do { \
    for (uint8_t i = 0; i < MAX_NUM_ARROW_2; i++){ \
        arrow_2[i].x = 113; \
        arrow_2[i].y = 0; \
        arrow_2[i].visible = BLACK; \
        arrow_2[i].action_image = 1; \
    } \
} while(0);

void game_arrow_2_handle(ak_msg_t* msg){
    switch (msg->sig)
    {
    case GAME_ARROW_2_SETUP: {
        APP_DBG_SIG("GAME_ARROW_2_SETUP\n");
        GAME_ARROW_2_SETUP();  
    }
        break;

    case GAME_ARROW_2_RUN: {
        APP_DBG_SIG("GMAE_ARROW_2_RUN\n");
        GAME_ARROW_2_RUN();
    }
        break;
    
    case GAME_ARROW_2_SHOOT: {
        APP_DBG_SIG("GAME_ARROW_2_SHOOT\n");
        GAME_ARROW_2_SHOOT();
    }
        break;

    case GAME_ARROW_2_RESET: {
        APP_DBG_SIG("GAME_ARROW_2_RESET\n");
        GAME_ARROW_2_RESET();
    }
        break;
    
    default:
        break;
    }
}