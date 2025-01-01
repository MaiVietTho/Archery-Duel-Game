#ifndef __APP_EEPROM_H__
#define __APP_EEPROM_H__

#include <stdint.h>
#include "app.h"

/**
  *****************************************************************************
  * EEPROM define address.
  *
  *****************************************************************************
  */
#define EEPROM_START_ADDR								(0X0000)
#define EEPROM_END_ADDR									(0X1000)

#define EEPROM_SCORE_START_ADDR     (0X0010)
#define EEPROM_SCORE_PLAY_ADDR      (0X0104)

#define EEPROM_SETTING_START_ADDR   (0X010E)

typedef struct {
  uint32_t score_now;
  uint32_t score_1st;
  uint32_t score_2nd;
  uint32_t score_3rd;
} game_score_t;

typedef struct {
  bool silent;
  uint8_t num_arrow;
  uint8_t num_arrow_2;
  uint8_t arrow_speed;
  uint8_t meteoroid_speed;
} game_setting_t;

#endif //__APP_EEPROM_H__
