#include "fortysix_console.h"
//#include "action_layer.h"
//#include "quantum.h"
//#include "action.h"
//#include "process_keycode/process_tap_dance.h"

//Keymaps are at the end.

//Give layers a name for readability.

enum fortysix_layers {
  _QWERTY,
  _FUNCTN
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

	[_QWERTY] = LAYOUT_fortysix_console(
    KC_ESC, KC_PSCR, KC_PAUS, KC_DEL, KC_RGUI,
    		MO(1), KC_7, KC_8, KC_9, KC_SLSH,
    		KC_LCTL, KC_4, KC_5, KC_6, KC_ASTR,
    		KC_LALT, KC_1, KC_2, KC_3, KC_MINS,
    		KC_TAB, KC_GRV, KC_0, KC_DOT, KC_PLUS,
    		KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS, KC_MINS,
    		KC_HOME, KC_END, KC_UP, KC_PGUP, KC_PGDN,
    		KC_LEFT, KC_DOWN, KC_RGHT),

/* FUNCTN
 * ------------------------------------
 * |  ESC |  F10 |  F11 |  F12 | LOCK |
 * |------+------+------+------+------|
 * |  FN  |  F7  |  F8  |  F9  |      |
 * |------+------+------+------+------|
 * | CTRL |  F4  |  F5  |  F6  |      |
 * |------+------+------+------+------|
 * |  ALT |  F1  |  F2  |  F3  |      |
 * |------+------+------+------+------|
 * |  TAB |      |      |      |      |
 * |------+------+------+------+------|
 * |  HUD |  HUI | MUTE |  SAD |  SAI |
 * |------+------+------+------+------|
 * |  VAD |  VAI | PLAY |  TOG |  MOD |
 * |------+------+------+------+------|
 * |      |  |<< | STOP |  >>| |      |
 * ------------------------------------
 * Thumb cluster is displayed as a signle row running clockwise from top left.
 * Cluster can, of course, be physically rotated so check your keyboard.
 */

	[_FUNCTN] = LAYOUT_fortysix_console(
    RESET, KC_F10, KC_F11, KC_F12, LGUI(KC_L),
		KC_TRNS, KC_F7, KC_F8, KC_F9, KC_NO,
		KC_LCTL, KC_F4, KC_F5, KC_F6, KC_NO,
		KC_LALT, KC_F1, KC_F2, KC_F3, KC_NO,
		KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO,
		RGB_HUD, RGB_HUI, KC_MUTE, RGB_SAD, RGB_SAI,
		RGB_VAD, RGB_VAI, KC_MPLY, RGB_TOG, RGB_MOD,
		KC_MPRV, KC_MSTP, KC_MNXT),

};

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case _QWERTY:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    case _FUNCTN:
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    }
  return state;
}
/*
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	keyevent_t event = record->event;

	switch (id) {

	}
	return MACRO_NONE;
}
*/
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
