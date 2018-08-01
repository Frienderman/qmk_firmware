#include "fortysix_console.h"
#include "action_layer.h"
#include "quantum.h"
#include "action.h"
#include "process_keycode/process_tap_dance.h"

//Keymaps are at the end.

//Give layers a name for readability.

enum fortysix_layers {
  _QWERTY,
  _FUNCTION,
  _LAYRGB
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//Note the last 3 keys are the key cluster. If a cluster is sitting with bar key at the bottom
//the first is the top left, second is the top right and third is the bottom bar key.
//This will be important when the trying to make sense of left and right sections
//as they use an identical keymap but will want the keys swapped based on use case.

/* Qwerty
 * ------------------------------------
 * |  ESC | PTSC | PAUS |  DEL |  WIN |
 * |------+------+------+------+------|
 * |  FN  |   7  |   8  |   9  |   /  |
 * |------+------+------+------+------|
 * | CTRL |   4  |   5  |   6  |   *  |
 * |------+------+------+------+------|
 * |  ALT |   1  |   2  |   3  |   -  |
 * |------+------+------+------+------|
 * |  TAB |   `  |   0  |   .  |   +  |
 * |------+------+------+------+------|
 * |   ;  |   [  |   ]  |   \  |  -_  |
 * |------+------+------+------+------|
 * | HOME |  END |  UP  | PGUP | PGDN |
 * |------+------+------+------+------|
 * |      | LEFT | DOWN | RGHT |      |
 * ------------------------------------
 * Thumb cluster is displayed as a signle row running clockwise from top left.
 * Cluster can, of course, be physically rotated so check your keyboard.
 */

	[_QWERTY] = LAYOUT_fortysix_half(
		KC_ESC, KC_PSCR, KC_PAUS, KC_DEL, KC_APP,
		KC_, KC_P7, KC_P8, KC_P9, KC_PSLS,
		KC_RCTRL, KC_P4, KC_P5, KC_P6, KC_PAST,
		KC_RALT, KC_P1, KC_P2, KC_P3, KC_PMNS,
		KC_TAB, KC_GRAVE, KC_P0, KC_PDOT, KC_PPLS,
		KC_SCOLON, KC_LBRACKET, KC_RBRACKET, KC_BSLASH, KC_MINUS,
		KC_HOME, KC_END, KC_UP, KC_PGUP, KC_PGDN,
		KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO),

/* FUNCTION
 * ------------------------------------
 * |  ESC |  F10 |  F11 |  F12 |  WIN |
 * |------+------+------+------+------|
 * |  FN  |  F7  |  F8  |  F9  |      |
 * |------+------+------+------+------|
 * | CTRL |  F4  |  F5  |  F6  |      |
 * |------+------+------+------+------|
 * |  ALT |  F1  |  F2  |  F3  |      |
 * |------+------+------+------+------|
 * |  TAB |      |      |      |      |
 * |------+------+------+------+------|
 * |      |      |      |      |      |
 * |------+------+------+------+------|
 * |      |      | PLAY |      |      |
 * |------+------+------+------+------|
 * |      |  |<< | STOP |  >>| |      |
 * ------------------------------------
 * Thumb cluster is displayed as a signle row running clockwise from top left.
 * Cluster can, of course, be physically rotated so check your keyboard.
 */

	[_FUNCTION] = LAYOUT_fortysix_half(
    KC_ESC, KC_F10, KC_F11, KC_F12, KC_APP,
		KC_TRNS, KC_F7, KC_F8, KC_F9, KC_NO,
		KC_RCTRL, KC_F4, KC_F5, KC_F6, KC_NO,
		KC_RALT, KC_F1, KC_F2, KC_F3, KC_NO,
		KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_MPLY, KC_NO, KC_NO,
		KC_NO, KC_MPRV, KC_MSTP, KC_MNXT, KC_NO),

/* LAYRGB
 * ------------------------------------
 * |   1  |   2  |   3  |   4  |   5  |
 * |------+------+------+------+------|
 * |   Q  |   W  |   E  |   R  |   T  |
 * |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |
 * |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |
 * |------+------+------+------+------|
 * |   1  |   2  |   3  |   4  |   5  |
 * |------+------+------+------+------|
 * |   Q  |   W  |   E  |   R  |   T  |
 * |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |
 * |------+------+------+------+------|
 * |   Z  |   X  | RSET |   V  |   B  |
 * ------------------------------------
 * Thumb cluster is displayed as a signle row running clockwise from top left.
 * Cluster can, of course, be physically rotated so check your keyboard.
 */

	[_LAYRGB] = LAYOUT_fortysix_half(
    KC_NO, RGB_RMOD, RGB_TOG, RGB_MOD, KC_NO,
		KC_NO, RGB_HUD, KC_NO, RGB_HUI, KC_NO,
		KC_NO, RGB_SAD, RGB_M_P, RGB_SAI, KC_NO,
		KC_NO, RGB_VAD, RGB_M_T, RGB_VAI, KC_NO,
		KC_1, KC_2, KC_3, KC_4, KC_5,
		KC_Q, KC_W, KC_E, KC_R, KC_T,
		KC_A, KC_S, KC_D, KC_F, KC_G,
		KC_Z, KC_X, RESET, KC_V, KC_B),


};



const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	//keyevent_t event = record->event;

	switch (id) {

	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_KANA)) {

	} else {

	}

}
