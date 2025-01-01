#include "screens_bitmap.h"

/*****************************************************************************/
/* scr_setting - Bitmap*/
/*****************************************************************************/
// 'chosse_icon', 20x20px
const unsigned char PROGMEM choose_icon [] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xf8, 0x00, 0xff, 0xfc, 0x00, 0x7f, 
	0xfe, 0x00, 0x3f, 0xff, 0x00, 0x1f, 0xff, 0x80, 0x0f, 0xff, 0xc0, 0x07, 0xff, 0xe0, 0x04, 0x00, 
	0x20, 0x08, 0x00, 0x40, 0x10, 0x00, 0x80, 0x20, 0x01, 0x00, 0x40, 0x02, 0x00, 0x80, 0x04, 0x00, 
	0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'speaker_1', 7x7px
const unsigned char PROGMEM speaker_1 [] = { 
	0x20, 0x62, 0xea, 0xea, 0xea, 0x62, 0x20
};
// 'speaker_2', 7x7px
const unsigned char PROGMEM speaker_2 [] = {
	0x20, 0x60, 0xea, 0xe4, 0xea, 0x60, 0x20
};

/*****************************************************************************/
/* scr_menu - Bitmap*/
/*****************************************************************************/
// 'archery_icon', 15x15px
const unsigned char PROGMEM archery_icon [] = {
	0x04, 0x00, 0x02, 0x00, 0x01, 0x00, 0x04, 0xc0, 0x00, 0x40, 0x08, 0x40, 0x00, 0x00, 0x1f, 0xf0, 
	0x00, 0x00, 0x08, 0x40, 0x00, 0x40, 0x04, 0xc0, 0x01, 0x00, 0x02, 0x00, 0x04, 0x00
};
// 'dot_icon', 1x64px
const unsigned char PROGMEM dot_icon [] = {
	0x80, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 
	0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 
	0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 
	0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00
};
// 'chart_icon', 16x16px
const unsigned char PROGMEM chart_icon [] = {
	0x10, 0x00, 0x10, 0x00, 0x6c, 0x00, 0x28, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x00, 
	0x44, 0x00, 0x57, 0xe0, 0x54, 0x20, 0x54, 0x20, 0x54, 0x3e, 0x44, 0x22, 0x44, 0x22, 0x7f, 0xfe
};
// 'setting_icon', 16x16px
const unsigned char PROGMEM setting_icon [] = {
	0x03, 0xc0, 0x12, 0x48, 0x3e, 0x7c, 0x60, 0x06, 0x20, 0x04, 0x23, 0xc4, 0xe4, 0x27, 0x84, 0x21, 
	0x84, 0x21, 0xe4, 0x27, 0x23, 0xc4, 0x20, 0x04, 0x60, 0x06, 0x3e, 0x7c, 0x12, 0x48, 0x03, 0xc0
};
// 'exit_icon', 16x16px
const unsigned char PROGMEM exit_icon [] = {
	0x00, 0x00, 0x7f, 0x80, 0xff, 0xc0, 0xff, 0xc0, 0xff, 0xd8, 0xff, 0xcc, 0xff, 0xc6, 0xfc, 0x3f, 
	0xfc, 0x3f, 0xff, 0xc6, 0xff, 0xcc, 0xff, 0xd8, 0xff, 0xc0, 0xff, 0xc0, 0x7f, 0x80, 0x00, 0x00
};


/*****************************************************************************/
/* Bitmap */
/*****************************************************************************/
// 'EPCB Logo', 128x64px
const unsigned char PROGMEM EPCB_Logo [] ={
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xe0, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0xfe, 0x00, 0x3f, 0xff, 
	0xff, 0xc0, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x00, 0xe0, 0x01, 0xfe, 0x00, 0x3e, 0x00, 0x0f, 0xff, 
	0xff, 0xcf, 0xff, 0xff, 0xff, 0xf3, 0xe0, 0x00, 0xe0, 0x00, 0xfc, 0x00, 0x1e, 0x00, 0x07, 0xff, 
	0xff, 0xcf, 0xff, 0xff, 0xff, 0xf3, 0xe0, 0x00, 0xe3, 0xf8, 0x78, 0x7f, 0x1e, 0x3f, 0xc3, 0xff, 
	0xff, 0xcf, 0xff, 0xff, 0xff, 0xf3, 0xe3, 0xff, 0xe3, 0xfc, 0x38, 0xff, 0x8e, 0x3f, 0xe3, 0xff, 
	0xff, 0xcf, 0xff, 0xff, 0xff, 0xf3, 0xe3, 0xff, 0xe3, 0xfe, 0x31, 0xff, 0x8e, 0x3f, 0xe3, 0xff, 
	0xff, 0xcf, 0xff, 0xff, 0xff, 0xf3, 0xe3, 0xff, 0xe3, 0xfe, 0x31, 0xff, 0xfe, 0x3f, 0xe3, 0xff, 
	0xff, 0xcf, 0xff, 0xff, 0xff, 0xf3, 0xe3, 0xff, 0xe3, 0xfe, 0x31, 0xff, 0xfe, 0x3f, 0xe3, 0xff, 
	0xff, 0xcf, 0xff, 0x0f, 0xff, 0xf3, 0xe3, 0xff, 0xe3, 0xfe, 0x31, 0xff, 0xfe, 0x3f, 0xc7, 0xff, 
	0xff, 0xcf, 0xfe, 0x07, 0xff, 0xf3, 0xe0, 0x03, 0xe3, 0xfc, 0x31, 0xff, 0xfe, 0x00, 0x0f, 0xff, 
	0xff, 0xcf, 0xfe, 0x07, 0xff, 0xf3, 0xe0, 0x03, 0xe3, 0xf8, 0x71, 0xff, 0xfe, 0x00, 0x0f, 0xff, 
	0xff, 0xcf, 0xfe, 0x67, 0xff, 0xf3, 0xe0, 0x03, 0xe0, 0x00, 0xf1, 0xff, 0xfe, 0x00, 0x07, 0xff, 
	0xff, 0xcf, 0xfe, 0x67, 0x07, 0xf3, 0xe3, 0xff, 0xe0, 0x01, 0xf1, 0xff, 0xfe, 0x3f, 0xc3, 0xff, 
	0xff, 0xcf, 0xfe, 0x66, 0x03, 0xf3, 0xe3, 0xff, 0xe3, 0xff, 0xf1, 0xff, 0xfe, 0x3f, 0xe3, 0xff, 
	0xff, 0xcf, 0xfe, 0x66, 0x03, 0xf3, 0xe3, 0xff, 0xe3, 0xff, 0xf1, 0xff, 0xfe, 0x3f, 0xe3, 0xff, 
	0xff, 0xff, 0xfe, 0x66, 0x73, 0xf3, 0xe3, 0xff, 0xe3, 0xff, 0xf1, 0xff, 0x8e, 0x3f, 0xe3, 0xff, 
	0xff, 0xff, 0xfe, 0x66, 0x71, 0xf3, 0xe3, 0xff, 0xe3, 0xff, 0xf8, 0xff, 0x8e, 0x3f, 0xe3, 0xff, 
	0xff, 0xc0, 0x3e, 0x66, 0x78, 0x03, 0xe3, 0xff, 0xe3, 0xff, 0xf8, 0x7f, 0x1e, 0x3f, 0xc3, 0xff, 
	0xff, 0xc0, 0x1e, 0x66, 0x7c, 0x03, 0xe0, 0x00, 0xe3, 0xff, 0xfc, 0x00, 0x1e, 0x00, 0x07, 0xff, 
	0xff, 0xcf, 0x8e, 0x66, 0x7f, 0xff, 0xe0, 0x00, 0xe3, 0xff, 0xfe, 0x00, 0x3e, 0x00, 0x0f, 0xff, 
	0xff, 0xcf, 0xce, 0x66, 0x7f, 0xff, 0xe0, 0x00, 0xe3, 0xff, 0xff, 0x80, 0xfe, 0x00, 0x3f, 0xff, 
	0xff, 0xcf, 0xce, 0x66, 0x7f, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xcf, 0xc0, 0x66, 0x7f, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xcf, 0xc0, 0x66, 0x7f, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xcf, 0xe0, 0xe6, 0x7f, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xcf, 0xff, 0xe0, 0x7f, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xcf, 0xff, 0xe0, 0x7f, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xcf, 0xff, 0xf0, 0xff, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xcf, 0xff, 0xff, 0xff, 0xf3, 0xee, 0x38, 0x3c, 0x60, 0xc3, 0x7d, 0x71, 0x83, 0x1f, 0xff, 
	0xff, 0xcf, 0xff, 0xff, 0xff, 0xf3, 0xed, 0xde, 0xfb, 0xaf, 0xdd, 0x7d, 0x6e, 0xbe, 0xef, 0xff, 
	0xff, 0xcf, 0xff, 0xff, 0xff, 0xf3, 0xeb, 0xee, 0xfb, 0xef, 0xdd, 0xbb, 0x5f, 0xbe, 0xff, 0xff, 
	0xff, 0xcf, 0xff, 0xff, 0xff, 0xf3, 0xeb, 0xee, 0xfc, 0x61, 0xc3, 0xbb, 0x5f, 0x87, 0x1f, 0xff, 
	0xff, 0xcf, 0xff, 0xff, 0xff, 0xf3, 0xeb, 0xee, 0xff, 0xaf, 0xcf, 0xbb, 0x5f, 0xbf, 0xef, 0xff, 
	0xff, 0xcf, 0xff, 0xff, 0xff, 0xf3, 0xeb, 0xee, 0xff, 0xaf, 0xd7, 0xd7, 0x5f, 0xbf, 0xef, 0xff, 
	0xff, 0xc0, 0x00, 0x00, 0x00, 0x03, 0xed, 0xde, 0xfb, 0xaf, 0xdb, 0xd7, 0x6e, 0xbe, 0xef, 0xff, 
	0xff, 0xe0, 0x00, 0x00, 0x00, 0x07, 0xee, 0x3e, 0xfc, 0x60, 0xdd, 0xef, 0x71, 0x83, 0x1f, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

/*****************************************************************************/
/* Icon menu 15*15 */
/*****************************************************************************/
const unsigned char PROGMEM inform_icon [] = {
	0x7f, 0xfc, 0xc0, 0x06, 0x80, 0x02, 0x81, 0x02, 0x80, 0x02, 0x81, 0x02, 0x81, 0x02, 0x81, 0x02, 
	0x81, 0x02, 0x81, 0x02, 0x80, 0x02, 0x80, 0x06, 0xff, 0xfc, 0xc0, 0x00, 0x80, 0x00
};

const unsigned char PROGMEM check_connect_icon [] = {
	0x00, 0x00, 0x03, 0x80, 0x0f, 0xe0, 0x3c, 0x78, 0x70, 0x1c, 0xe7, 0xce, 0x8f, 0xe2, 0x38, 0x38, 
	0x33, 0x98, 0x06, 0xc0, 0x0c, 0x60, 0x01, 0x00, 0x03, 0x80, 0x03, 0x80, 0x00, 0x00
};

const unsigned char PROGMEM read_sensor_icon [] = {
	0x07, 0xc0, 0x18, 0x30, 0x20, 0x08, 0x41, 0xc4, 0x41, 0x44, 0x9d, 0x42, 0x95, 0x5e, 0x95, 0x52, 
	0xf5, 0x52, 0x85, 0x52, 0x45, 0x74, 0x47, 0x04, 0x20, 0x08, 0x18, 0x30, 0x07, 0xc0
};

/*****************************************************************************/
/* Icon AK */
/*****************************************************************************/
// 'AK', 15x15px
const unsigned char PROGMEM ak_1_icon [] = {
	0x7f, 0xfc, 0x80, 0x02, 0x80, 0x02, 0xbf, 0xfa, 0xa0, 0x0a, 0xa4, 0xaa, 0xaa, 0xca, 0xae, 0xaa, 
	0xaa, 0xaa, 0xa0, 0x0a, 0xbf, 0xfa, 0x80, 0x02, 0x91, 0x12, 0x80, 0x02, 0x7f, 0xfc
};

// 'AK Slave', 15x15px
const unsigned char PROGMEM ak_slave_icon [] = {
	0x7f, 0xfc, 0x80, 0x02, 0xbf, 0xfa, 0xa0, 0x0a, 0xa3, 0x8a, 0xa2, 0x0a, 0xa1, 0x0a, 0xa0, 0x8a, 
	0xa3, 0x8a, 0xa0, 0x0a, 0xbf, 0xfa, 0x80, 0x02, 0x91, 0x12, 0x80, 0x02, 0x7f, 0xfc
};

// 'AK Master', 15x15px
const unsigned char PROGMEM ak_master_icon [] = {
	0x7f, 0xfc, 0x80, 0x02, 0xbf, 0xfa, 0xa0, 0x0a, 0xac, 0x6a, 0xaa, 0xaa, 0xa9, 0x2a, 0xa8, 0x2a, 
	0xa8, 0x2a, 0xa0, 0x0a, 0xbf, 0xfa, 0x80, 0x02, 0x91, 0x12, 0x80, 0x02, 0x7f, 0xfc
};

// 'ak', 11x11px
const unsigned char PROGMEM ak_2_icon [] = {
	0xff, 0xe0, 0x80, 0x20, 0x92, 0xa0, 0xab, 0x20, 0xba, 0xa0, 0xaa, 0xa0, 0x80, 0x20, 0x80, 0x20, 
	0xa4, 0xa0, 0x80, 0x20, 0xff, 0xe0
};

/*****************************************************************************/
/* Bitmap icon */
/*****************************************************************************/
/* status pin */
// 'pin_1', 14x7px
const unsigned char PROGMEM pin_1_icon [] = {
	0x3f, 0xfc, 0x20, 0x04, 0xed, 0xb4, 0xad, 0xb4, 0xed, 0xb4, 0x20, 0x04, 0x3f, 0xfc
};

// 'message 1', 14x7px
const unsigned char PROGMEM message_1_icon [] = {
	0x7f, 0xf8, 0xbf, 0xf4, 0xdf, 0xec, 0xe0, 0x1c, 0xdf, 0xec, 0xbf, 0xf4, 0x7f, 0xf8
};

// 'message 2', 8x5px
const unsigned char PROGMEM message_2_icon [] = {
	0x7e, 0xbd, 0xc3, 0xbd, 0x7e
};

// 'chosse 1', 5x7px
const unsigned char PROGMEM choose_1_icon [] = {
	0xc0, 0xe0, 0xb0, 0x98, 0xb0, 0xe0, 0xc0
};

/* sensor */
const unsigned char PROGMEM icon_temp_12x13[] = {
	0x00, 0x00, 0x18, 0x00, 0x3c, 0x00, 0x34, 0x00, 0x34, 0x00, 0x34, 0x00,
	0x34, 0x02, 0x66, 0x03, 0x42, 0x02, 0x66, 0x02, 0x3c, 0x02, 0x00, 0x07,
	0x00, 0x00
};

const unsigned char PROGMEM icon_hum_13x13[] = {
	0x00, 0x00, 0x08, 0x00, 0x1c, 0x00, 0x36, 0x00, 0x36, 0x00, 0x3e, 0x00, 0x1c, 0x80, 0x01, 0xc0,
	0x03, 0x60, 0x03, 0x60, 0x03, 0xe0, 0x01, 0xc0, 0x00, 0x00
};

const unsigned char PROGMEM icon_es35_sensor_28x55[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x01, 0x58, 0x00, 0x00, 0x01, 0x58, 0x00,
	0x00, 0x01, 0x58, 0x00, 0x00, 0x01, 0x58, 0x00, 0x00, 0x01, 0x58, 0x00, 0x00, 0x01, 0x58, 0x00,
	0x00, 0x01, 0x58, 0x00, 0x00, 0x01, 0x58, 0x00, 0x00, 0x01, 0x58, 0x00, 0x00, 0x01, 0x78, 0x00,
	0x00, 0x01, 0x78, 0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x01, 0x08, 0x00, 0x00, 0x3f, 0xf8, 0x00,
	0x00, 0x61, 0xf8, 0x00, 0x00, 0x61, 0xf8, 0x00, 0x00, 0x61, 0xf8, 0x00, 0x00, 0x61, 0xf8, 0x00,
	0x00, 0x63, 0xf8, 0x00, 0x00, 0x63, 0xf8, 0x00, 0x00, 0x63, 0xf8, 0x00, 0x00, 0x7f, 0xf8, 0x00,
	0x00, 0x3f, 0xf8, 0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x01, 0xf8, 0x00,
	0x00, 0x01, 0xf8, 0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x01, 0xf8, 0x00,
	0x00, 0x01, 0x08, 0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x60, 0x00,
	0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x60, 0x00, 0x01, 0xc0, 0x60, 0x00, 0x03, 0xe0, 0xe0, 0x00,
	0x07, 0x7f, 0xc0, 0x00, 0x06, 0x3f, 0x80, 0x00, 0x0c, 0x03, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
	0x0c, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
	0x0c, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};



/*****************************************************************************/
/* scr_archery_game - Bitmap*/
/*****************************************************************************/
// 'bitmap_archery_I', 15x15px
const unsigned char PROGMEM bitmap_archery_I [] = {
	0x04, 0x00, 0x02, 0x00, 0x01, 0x00, 0x04, 0xc0, 0x00, 0x40, 0x08, 0x40, 0x00, 0x00, 0x1f, 0xf0, 
	0x00, 0x00, 0x08, 0x40, 0x00, 0x40, 0x04, 0xc0, 0x01, 0x00, 0x02, 0x00, 0x04, 0x00
};
// 'bitmap_archery_II', 15x15px
const unsigned char PROGMEM bitmap_archery_II [] = {
	0x04, 0x00, 0x02, 0x00, 0x01, 0x00, 0x04, 0xc0, 0x00, 0x40, 0x08, 0x40, 0x00, 0x20, 0x08, 0x40, 
	0x00, 0x20, 0x08, 0x40, 0x00, 0x40, 0x04, 0xc0, 0x01, 0x00, 0x02, 0x00, 0x04, 0x00
};
// 'bitmap_meteoroid_I', 20x10px
const unsigned char PROGMEM bitmap_meteoroid_I [] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x78, 0x00, 0xa8, 0x00, 0x00, 0xfe, 0x3e, 0x00, 0xa8, 
	0x00, 0x00, 0xfc, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'bitmap_meteoroid_II', 20x10px
const unsigned char PROGMEM bitmap_meteoroid_II [] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xe3, 0xc0, 0xa8, 0x00, 0x00, 0xfd, 0xf1, 0xf0, 0xa8, 
	0x00, 0x00, 0xfc, 0xe3, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'bitmap_meteoroid_III', 20x10px
const unsigned char PROGMEM bitmap_meteoroid_III [] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x80, 0x40, 0xa8, 0x00, 0x00, 0xfb, 0xe0, 0x10, 0xa8, 
	0x00, 0x00, 0xff, 0x80, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'bitmap_arrow', 10x5px
const unsigned char PROGMEM bitmap_arrow [] = {
	0x00, 0x00, 0x80, 0x00, 0x7f, 0xc0, 0x80, 0x00, 0x00, 0x00
};
// 'bitmap_bang_I', 15x15px
const unsigned char PROGMEM bitmap_bang_I [] = {
	0x00, 0x00, 0x02, 0x20, 0x02, 0x60, 0x23, 0xe0, 0x1f, 0xe0, 0x1f, 0x7c, 0x0c, 0x30, 0x78, 0x70, 
	0x1c, 0x78, 0x0e, 0xfe, 0x1f, 0xe0, 0x13, 0x60, 0x03, 0x20, 0x02, 0x10, 0x00, 0x00
};
// 'bitmap_bang_II', 15x15px
const unsigned char PROGMEM bitmap_bang_II [] = {
	0x00, 0x00, 0x10, 0x80, 0x09, 0x80, 0x0d, 0x90, 0x0f, 0xf0, 0xfe, 0xe0, 0x3c, 0x70, 0x1c, 0x3c, 
	0x18, 0x60, 0x7d, 0xf0, 0x0f, 0xf0, 0x0f, 0x88, 0x0c, 0x80, 0x08, 0x80, 0x00, 0x00
};
// 'bitmap_bang_III', 10x10px
const unsigned char PROGMEM bitmap_bang_III [] = {
	0x04, 0x00, 0x24, 0x00, 0x1d, 0x00, 0x1f, 0x00, 0x63, 0x80, 0x23, 0x00, 0x7f, 0x00, 0x1d, 0x80, 
	0x14, 0x00, 0x00, 0x00
};

/*****************************************************************************/
/* scr_charts_game - Bitmap*/
/*****************************************************************************/
// 'bitmap_icon_charts', 60x20px
const unsigned char PROGMEM bitmap_icon_charts [] = {
	0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0xc0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x30, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x80, 0x00, 0x00, 0x00, 
	0x7e, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x07, 0xe0, 0xe7, 0x00, 0x00, 0x1f, 0x80, 0x00, 0x0e, 0x70, 
	0xe7, 0x00, 0x00, 0x39, 0xc0, 0x00, 0x0e, 0x70, 0x7f, 0x00, 0x60, 0x70, 0xe0, 0x60, 0x0f, 0xe0, 
	0x03, 0xc0, 0xfe, 0xe0, 0x77, 0xf0, 0x3c, 0x00, 0x01, 0xf9, 0xc7, 0x80, 0x1e, 0x39, 0xf8, 0x00, 
	0x00, 0xff, 0x87, 0x00, 0x0e, 0x1f, 0x70, 0x00, 0x00, 0x73, 0xce, 0x00, 0x07, 0x7c, 0xe0, 0x00, 
	0x00, 0x38, 0x7c, 0x00, 0x03, 0xe1, 0xc0, 0x00, 0x00, 0x1c, 0x18, 0x00, 0x00, 0x03, 0x80, 0x00, 
	0x00, 0x0e, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 
	0x00, 0x03, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00
};

/*****************************************************************************/
/* scr_game_over - Bitmap*/
/*****************************************************************************/
// 'icon_restart', 15x15px
const unsigned char PROGMEM icon_restart [] = {
	0x01, 0x00, 0x07, 0x00, 0x0f, 0xc0, 0x0f, 0xf0, 0x07, 0x78, 0x63, 0x9c, 0x61, 0x0c, 0x60, 0x0c, 
	0x60, 0x0c, 0x60, 0x0c, 0x60, 0x0c, 0x70, 0x1c, 0x38, 0x38, 0x1f, 0xf0, 0x07, 0xc0
};
// 'icon_xep_hang', 17x15px
const unsigned char PROGMEM icon_charts [] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x28, 0x00, 0x00, 
	0xa8, 0x00, 0x00, 0xa8, 0x00, 0x02, 0xa8, 0x00, 0x02, 0xa8, 0x00, 0x0a, 0xa8, 0x00, 0x0a, 0xa8, 
	0x00, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'icon_go_home', 16x16px
const unsigned char PROGMEM icon_go_home [] = {
	0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x02, 0x40, 0x05, 0xa0, 0x0b, 0xd0, 0x17, 0xe8, 0x2f, 0xf4, 
	0x5f, 0xfb, 0xbc, 0x3d, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x1c, 0x38, 0x00, 0x00
};

/*****************************************************************************/

// 'bitmap_arrow_2', 10x5px
const unsigned char PROGMEM bitmap_arrow_2 [] = {
	0x00, 0x00, 0x00, 0x40, 0xff, 0x80, 0x00, 0x40, 0x00, 0x00
};

// 'bitmap_archery_2_I', 15x15px
const unsigned char PROGMEM bitmap_archery_2_I [] = {
	0x00, 0x80, 0x01, 0x00, 0x02, 0x00, 0x0c, 0x80, 0x08, 0x00, 0x08, 0x40, 0x00, 0x08, 0x3f, 0xf0, 
	0x00, 0x08, 0x08, 0x40, 0x08, 0x00, 0x0c, 0x80, 0x02, 0x00, 0x01, 0x00, 0x00, 0x80
};

// 'bitmap_archery_2_II', 15x15px
const unsigned char PROGMEM bitmap_archery_2_II [] = {
	0x00, 0x80, 0x01, 0x00, 0x02, 0x00, 0x0c, 0x80, 0x08, 0x00, 0x08, 0x40, 0x10, 0x00, 0x08, 0x40, 
	0x10, 0x00, 0x08, 0x40, 0x08, 0x00, 0x0c, 0x80, 0x02, 0x00, 0x01, 0x00, 0x00, 0x80
};