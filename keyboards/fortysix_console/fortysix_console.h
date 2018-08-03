#ifndef FORTYSIX_CONSOLE_H
#define FORTYSIX_CONSOLE_H

#include "quantum.h"

#define KEYMAP LAYOUT_fortysix_console

#define LAYOUT_fortysix_console( \
	K00, K01, K02, K03, K04, \
	K10, K11, K12, K13, K14, \
	K20, K21, K22, K23, K24, \
	K30, K31, K32, K33, K34, \
	K40, K41, K42, K43, K44, \
	K50, K51, K52, K53, K54, \
	K60, K61, K62, K63, K64, \
	K70, K71, K72, K73, K74 \
) { \
	{ K00,   K01,   K02,   K03,   K04 }, \
	{ K10,   K11,   K12,   K13,   K14 }, \
	{ K20,   K21,   K22,   K23,   K24 }, \
	{ K30,   K31,   K32,   K33,   K34 }, \
	{ K40,   K41,   K42,   K43,   K44 }, \
	{ K50,   K51,   K52,   K53,   K54 }, \
	{ K60,   K61,   K62,   K63,   K64 }, \
	{ K70,   K71,   K72,   K73,   K74 } \
}

#endif
