#ifndef __SCREENS_BITMAP_H__
#define __SCREENS_BITMAP_H__

#include "view_render.h"

// scr_archery_game
extern const unsigned char PROGMEM bitmap_archery_I []; 
extern const unsigned char PROGMEM bitmap_archery_II [];
extern const unsigned char PROGMEM bitmap_meteoroid_I [];
extern const unsigned char PROGMEM bitmap_meteoroid_II [];
extern const unsigned char PROGMEM bitmap_meteoroid_III [];
extern const unsigned char PROGMEM bitmap_arrow [];
extern const unsigned char PROGMEM bitmap_bang_I [];
extern const unsigned char PROGMEM bitmap_bang_II [];
extern const unsigned char PROGMEM bitmap_bang_III [];

extern const unsigned char PROGMEM bitmap_archery_2_I [];
extern const unsigned char PROGMEM bitmap_archery_2_II [];
extern const unsigned char PROGMEM bitmap_arrow_2 [];

// scr_charts_game
extern const unsigned char PROGMEM bitmap_icon_charts [];

// scr_game_over
extern const unsigned char PROGMEM icon_restart [];
extern const unsigned char PROGMEM icon_charts [];
extern const unsigned char PROGMEM icon_go_home [];

/***********************************************************/

/* scr_setting */
extern const unsigned char PROGMEM choose_icon [];
extern const unsigned char PROGMEM speaker_1 [];
extern const unsigned char PROGMEM speaker_2 [];

/* scr_menu */
extern const unsigned char PROGMEM archery_icon [];
extern const unsigned char PROGMEM dot_icon [];
extern const unsigned char PROGMEM chart_icon [];
extern const unsigned char PROGMEM setting_icon [];
extern const unsigned char PROGMEM exit_icon [];

/* Epcb logo */
extern const unsigned char PROGMEM EPCB_Logo [];
extern const unsigned char PROGMEM inform_icon [];
extern const unsigned char PROGMEM check_connect_icon [];
extern const unsigned char PROGMEM read_sensor_icon [];

extern const unsigned char PROGMEM next_1_icon [];
extern const unsigned char PROGMEM next_2_icon [];
extern const unsigned char PROGMEM next_3_icon [];

/* AK icon */
// 'AK', 15x15px
extern const unsigned char PROGMEM ak_1_icon [];
// 'AK SLave', 15x15px
extern const unsigned char PROGMEM ak_slave_icon [];
// 'AK Master', 15x15px
extern const unsigned char PROGMEM ak_master_icon [];
// 'ak', 11x11px
extern const unsigned char PROGMEM ak_2_icon [];

/* Sensor - es35*/
extern const unsigned char PROGMEM icon_temp_12x13[];
extern const unsigned char PROGMEM icon_hum_13x13[];
extern const unsigned char PROGMEM icon_es35_sensor_28x55[];

/* pin */
extern const unsigned char PROGMEM pin_1_icon [];

/* chosse */
extern const unsigned char PROGMEM chosse_1_icon [];

/* message */
extern const unsigned char PROGMEM message_1_icon [];
extern const unsigned char PROGMEM message_2_icon [];

#endif //__SCREENS_BITMAP_H__