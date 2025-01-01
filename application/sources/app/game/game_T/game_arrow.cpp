#include "game_arrow.h"

#include "game_archery.h"
#include "game_bang.h"
#include "game_arrow_person_2.h"
#include "game_border.h"
#include "scr_archery_game.h"

game_arrow_t arrow[MAX_NUM_ARROW];

#define GAME_ARROW_SETUP() \
do {  \
    for(uint8_t i = 0; i < MAX_NUM_ARROW; i++) { \
        arrow[i].x = 0; \
        arrow[i].y = 0; \
        arrow[i].visible = BLACK; \
        arrow[i].action_image = 1; \
     } \
} while(0);

#define GAME_ARROW_RUN() \
do { \
    for(uint8_t i = 0; i < MAX_NUM_ARROW; i++) { \
        if (arrow[i].visible == WHITE) { \
            arrow[i].x += settingsetup.arrow_speed; \
        } \
    } \
} while(0);

#define GAME_ARROW_SHOOT() \
do { \
    for (uint8_t i = 0; i < MAX_NUM_ARROW; i++){ \
        if (arrow[i].visible == BLACK && settingsetup.num_arrow != 0) { \
            settingsetup.num_arrow--; \
            arrow[i].visible = WHITE; \
            arrow[i].y = archery.y - 5; \
            BUZZER_PlayTones(tones_cc); \
            break; \
        } \
        else if (settingsetup.num_arrow == 0) { \
            BUZZER_PlayTones(tones_3beep); \
            break; \
        } \
    } \
} while(0);

#define GAME_ARROW_DETONATOR() \
do { \
    for (uint8_t i = 0; i < NUM_BANG; i++) { \
        if (arrow[i].visible == WHITE) { \
            for (uint8_t j = 0; j < MAX_NUM_ARROW_2; j++) { \
                if (arrow_2[j].visible == WHITE) { \
                    if(arrow_2[j].x < (arrow[i].x + SIZE_BITMAP_ARROW_X - 3)) { \
                        if (arrow_2[j].y == arrow[i].y) { \
                            arrow[i].visible = BLACK; \
                            arrow_2[j].visible = BLACK; \
                            bang[i].visible = WHITE; \
                            bang[i].x = arrow_2[j].x - 3; \
                            bang[i].y = arrow_2[j].y - 2; \
                            arrow[i].x = 0; \
                            arrow_2[j].x = 112; \
                            settingsetup.num_arrow++; \
                            settingsetup.num_arrow_2++; \
                            BUZZER_PlayTones(tones_BUM); \
                        } \
                    } \
                } \
            } \
        } \
    } \
} while(0);

#define GAME_ARROW_RESET() \
do { \
    for (uint8_t i = 0; i < MAX_NUM_ARROW; i++){ \
        arrow[i].x = 0; \
        arrow[i].y = 0; \
        arrow[i].visible = BLACK; \
        arrow[i].action_image = 1; \
    } \
} while(0);

void game_arrow_handle(ak_msg_t* msg){
    switch (msg->sig)
    {
    case GAME_ARROW_SETUP: {
        APP_DBG_SIG("GAME_ARROW_SETUP\n");
        GAME_ARROW_SETUP();  
    }
        break;

    case GAME_ARROW_RUN: {
        APP_DBG_SIG("GAME_ARROW_RUN\n");
        GAME_ARROW_RUN();
    }
        break;
    
    case GAME_ARROW_SHOOT: {
        APP_DBG_SIG("GAME_ARROW_SHOOT\n");
        GAME_ARROW_SHOOT();
    }
        break;

    case GAME_ARROW_DETONATOR: {
        APP_DBG_SIG("GAME_ARROW_DETONATOR\n");
        GAME_ARROW_DETONATOR();
    }
        break;

    case GAME_ARROW_RESET: {
        APP_DBG_SIG("GAME_ARROW_RESET\n");
        GAME_ARROW_RESET();
    }
        break;
    
    default:
        break;
    }
}