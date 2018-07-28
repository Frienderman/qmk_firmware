#ifndef FORTYSIX_H
#define FORTYSIX_H

#include "quantum.h"

#define KEYMAP LAYOUT_fortysix_half

#define LAYOUT_fortysix_half( \
	K00, K01, K02, K03, K04,                \
	K10, K11, K12, K13, K14,                \
	K20, K21, K22, K23, K24,                \
	K30, K31, K32, K33, K34,                \
	                         K45, K46, K47  \
) { \
	{ K00,   K01,   K02,   K03,   K04,   KC_NO, KC_NO, KC_NO }, \
	{ K10,   K11,   K12,   K13,   K14,   KC_NO, KC_NO, KC_NO }, \
	{ K20,   K21,   K22,   K23,   K24,   KC_NO, KC_NO, KC_NO }, \
	{ K30,   K31,   K32,   K33,   K34,   KC_NO, KC_NO, KC_NO }, \
	{ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K45,   K46,   K47 }  \
}

#endif
