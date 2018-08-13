#include "fortysix.h"
#include "action_layer.h"
#include "quantum.h"
#include "action.h"
#include "process_keycode/process_tap_dance.h"

//Keymaps are at the end.

//Give layers a name for readability.

enum fortysix_layers {
  _QWERTY,
  _GAMING,
  _LAYRGB
};

//Tap dance enums
enum {
 CT_LCTL = 0,
 //CT_RALT,
 CT_UNUSED
};

void dance_ctl_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) {
		  //register_code(TO(0));
		  layer_off(1);
		  layer_off(2);
		  layer_on(0);
		  //rgblight_setrgb(128,0,0);
      //rgblight_sethsv(0,255,255);
      //register_code (KC_RSFT);
      //register_code (KC_SCLN);
    } else {
      register_code(KC_LCTRL);
    }
  } else if (state->count == 2) {
		//register_code(TO(1));
		layer_off(0);
		layer_off(2);
		layer_on(1);
		//rgblight_setrgb(0,128,0);
    //rgblight_sethsv(0,128,128);
    //register_code (KC_RSFT);
    //register_code (KC_SCLN);
  } else if (state->count == 3) {
		//register_code(TO(2));
		layer_off(1);
		layer_off(0);
		layer_on(2);
		//rgblight_setrgb(0,0,128);
    //rgblight_sethsv(120,128,128);
    //register_code (KC_RSFT);
    //register_code (KC_SCLN);
  } else {
		//If not anything else, jump back to default layer.
		//register_code(TO(0));
		layer_off(1);
		layer_off(2);
		layer_on(0);
		//rgblight_setrgb(128,0,0);
    //rgblight_sethsv(0,255,255);
  }
}

void dance_ctl_reset (qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 1) {
		unregister_code(KC_LCTL);
		//rgblight_setrgb(128,0,0);
    //register_code (KC_RSFT);
    //register_code (KC_SCLN);
  } else if (state->count == 2) {
		//unregister_code(TG(1));
		//rgblight_setrgb(0,128,0);
		//register_code (KC_RSFT);
    //register_code (KC_SCLN);
  } else if (state->count == 3) {
		//unregister_code(TG(2));
		//rgblight_setrgb(0,0,128);
		//register_code (KC_RSFT);
    //register_code (KC_SCLN);
  } else {
    //unregister_code (KC_NO);
  }
}

//All tap dance functions would go here. Only showing this one.
qk_tap_dance_action_t tap_dance_actions[] = {
 [CT_LCTL] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_ctl_finished, dance_ctl_reset)
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
 * ------------------------------------
 *            ---------------
 *            |  BS  |  CTL |
 *            |------+------|
 *            |    SHIFT    |
 *            ---------------
 * Thumb cluster is displayed as a signle row running clockwise from top left.
 * Cluster can, of course, be physically rotated so check your keyboard.
 */

	[_QWERTY] = LAYOUT_fortysix_half(
		KC_1, KC_2, KC_3, KC_4, KC_5,
		KC_Q, KC_W, KC_E, KC_R, KC_T,
		KC_A, KC_S, KC_D, KC_F, KC_G,
		KC_Z, KC_X, KC_C, KC_V, KC_B,
		KC_BSPC, TD(CT_LCTL), KC_LSFT),

/* Gaming
 * ------------------------------------
 * |  ~   |  1   |  2   |  3   |  4   |
 * |------+------+------+------+------|
 * |  TAB |  Q   |  W   |  E   |  R   |
 * |------+------+------+------+------|
 * |  SFT |  A   |  S   |  D   |  F   |
 * |------+------+------+------+------|
 * |  CTL |  Z   |  X   |  C   |  V   |
 * ------------------------------------
 *            ---------------
 *            | ALT  |  CTL |
 *            |------+------|
 *            |    SPACE    |
 *            ---------------
 * Thumb cluster is displayed as a signle row running clockwise from top left.
 * Cluster can, of course, be physically rotated so check your keyboard.
 */

	[_GAMING] = LAYOUT_fortysix_half(
		KC_GRV, KC_1, KC_2, KC_3, KC_4,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R,
		KC_LSHIFT, KC_A, KC_S, KC_D, KC_F,
		KC_LCTRL, KC_Z, KC_X, KC_C, KC_V,
		KC_LALT, TD(CT_LCTL), KC_SPACE),

/* LAYRGB
 * ------------------------------------
 * |      | MODE-|RGBTOG|MODE+ |      |
 * |------+------+------+------+------|
 * |      | HUE- |      | HUE+ |      |
 * |------+------+------+------+------|
 * |      | SAT- |STATIC| SAT+ |      |
 * |------+------+------+------+------|
 * |  RST | BRI- | TEST | BRI+ |      |
 * ------------------------------------
 *            ---------------
 *            |      |  CTL |
 *            |------+------|
 *            |             |
 *            ---------------
 * Thumb cluster is displayed as a signle row running clockwise from top left.
 * Cluster can, of course, be physically rotated so check your keyboard.
 */

	[_LAYRGB] = LAYOUT_fortysix_half(
    KC_NO, RGB_RMOD, RGB_TOG, RGB_MOD, KC_NO,
		KC_NO, RGB_HUD, KC_NO, RGB_HUI, KC_NO,
		KC_NO, RGB_SAD, RGB_M_P, RGB_SAI, KC_NO,
		RESET, RGB_VAD, RGB_M_T, RGB_VAI, KC_NO,
		KC_NO, TD(CT_LCTL), KC_NO),

};

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case _QWERTY:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    case _GAMING:
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    case _LAYRGB:
        rgblight_setrgb (0x0F,  0x0F, 0x0F);
        break;
    //case _ADJUST:
    //    rgblight_setrgb (0x7A,  0x00, 0xFF);
    //    break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    }
  return state;
}

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
