#include "fortysix.h"
#include "action_layer.h"
#include "quantum.h"
#include "action.h"
#include "process_keycode/process_tap_dance.h"

//Keymaps are at the end.

//Give layers a name for readability.

enum fortysix_layers {
  _QWERTY,
  _LAYRGB,
  _LRESET
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//Note the last 3 keys are the key cluster. If a cluster is sitting with bar key at the bottom
//the first is the top left, second is the top right and third is the bottom bar key.
//This will be important when the trying to make sense of left and right sections
//as they use an identical keymap but will want the keys swapped based on use case.

/* Qwerty
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
 * |   Z  |   X  |   C  |   V  |   B  |
 * ------------------------------------
 * Thumb cluster is displayed as a signle row running clockwise from top left.
 * Cluster can, of course, be physically rotated so check your keyboard.
 */

	[_QWERTY] = LAYOUT_fortysix_half(
		KC_1, KC_2, KC_3, KC_4, KC_5,
		KC_Q, KC_W, KC_E, KC_R, KC_T,
		KC_A, KC_S, KC_D, KC_F, KC_G,
		KC_Z, KC_X, KC_C, KC_V, KC_B,
		KC_1, KC_2, KC_3, KC_4, KC_5,
		KC_Q, KC_W, KC_E, KC_R, KC_T,
		KC_A, KC_S, KC_D, KC_F, KC_G,
		KC_Z, KC_X, KC_C, KC_V, KC_B),

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
 * |   Z  |   X  |   C  |   V  |   B  |
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
		KC_Z, KC_X, KC_C, KC_V, KC_B),

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
 * |   Z  |   X  |   C  |   V  |   B  |
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
		KC_Z, KC_X, KC_C, KC_V, KC_B),


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
