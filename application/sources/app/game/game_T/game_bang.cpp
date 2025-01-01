#include "game_bang.h"

#include "game_meteoroid.h"

game_bang_t bang[NUM_BANG];

#define GAME_BANG_SETUP() \
do { \
    for (uint8_t i = 0; i < NUM_BANG; i++) { \
        bang[i].x = 0; \
        bang[i].y = 0; \
        bang[i].visible = BLACK; \
        bang[i].action_image = 1; \
    } \
} while(0);

#define GAME_BANG_UPDATE() \
do { \
    for (uint8_t i = 0; i < NUM_BANG; i++) { \
        if (bang[i].visible == WHITE) { \
            bang[i].action_image++; \
        } \
        if (bang[i].action_image == 4) { \
            bang[i].action_image = 1; \
            bang[i].visible = BLACK; \
        } \
    } \
} while(0); 

#define GAME_BANG_RESET() \
do { \
    for (uint8_t i = 0; i< NUM_BANG; i++) { \
        bang[i].visible = BLACK; \
        bang[i].action_image = 1; \
    } \
} while(0);

void game_bang_handle(ak_msg_t* msg) {
    switch (msg->sig)
    {
    case GAME_BANG_SETUP: {
        APP_DBG_SIG("GAME_BANG_SETUP\n");
        GAME_BANG_SETUP();
    }
        break;
    
    case GAME_BANG_UPDATE: {
        APP_DBG_SIG("GAME_BANG_UPDATE\n");
        GAME_BANG_UPDATE();
    }
        break;

    case GAME_BANG_RESET: {
        APP_DBG_SIG("GAME_BANG_RESET\n");
        GAME_BANG_RESET();
    }
        break;
        
    default:
        break;
    }
}