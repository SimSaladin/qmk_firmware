#include QMK_KEYBOARD_H

#include "keymap_dvorak_programmer.h"

#define X_A_B  LALT(DP_B)    // backward word
#define X_A_F  LALT(DP_F)    // forward word
#define X_A_D  LALT(DP_D)    // delete forward word
#define X_A_BS LALT(KC_BSPC) // delete backward word

// Layer shorthand
enum my_layers {
  _BASE,      // Base layer / _BASE,     // 0
  _FN1,       // 1. function layer       // 1
  _MS,        // mouse keys layer        // 2
  _KPAD,      // 3 keymap
  LAYER_COUNT
};

enum my_keycodes {
  CK_QWERTY = QK_USER,
  CK_CYCLS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_80_with_macro( /* DEFAULT */
    KC_MUTE ,           KC_ESC ,  KC_F1  ,    KC_F2,    KC_F3 ,   KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,             KC_DEL , KC_INS ,
    KC_NUM  , KC_PSCR,  KC_GRV ,  KC_1   ,     KC_2,     KC_3 ,    KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,   KC_MINS,  KC_EQL,   _______,  KC_BSPC, KC_HOME,
    CK_CYCLS, KC_INS ,  KC_TAB ,  KC_Q   ,     KC_W,     KC_E ,    KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,   KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_END  ,
    KC_BRIU , UG_TOGG,  MO(_MS),  KC_A   ,     KC_S,     KC_D ,    KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,  KC_SCLN,  KC_QUOT,              KC_ENT,          KC_PGUP ,
    KC_BRID , KC_UP  ,  KC_LSFT,             KC_Z  ,     KC_X ,    KC_C,     KC_V,     KC_B,     KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_RSFT,   _______,          KC_PGDN ,
    KC_LEFT , KC_DOWN,  KC_LCTL,  KC_LGUI,  KC_LALT,  MO(_FN1), _______,   KC_SPC,             KC_SPC, MO(_FN1),  KC_RALT,  KC_RGUI,  _______,  KC_RCTL,  MO(_FN1),          KC_RGHT
  ),
  [_FN1] = LAYOUT_80_with_macro( /* FUNCTION */
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    UG_HUED,  UG_HUEU,  QK_GESC,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,  KC_F12,  _______,  _______,  _______,
    UG_SATD,  UG_SATU,  UG_TOGG,  UG_NEXT,  _______,    KC_UP,  _______,  _______,  KC_PGUP,  KC_HOME,    KC_UP,   KC_END ,  KC_DEL ,  _______, _______,  _______,            _______,
    UG_VALD,  UG_VALU,  UG_SPDD,  UG_SPDU,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_INS ,  _______,            _______,            _______,
    _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),
  [_MS] = LAYOUT_80_with_macro( /* MOUSE KEYS */
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  X_A_BS ,  _______,  X_A_D  ,  _______,  MS_WHLU,  _______,  MS_UP  ,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  _______,  X_A_B  ,  _______,  X_A_F  ,  _______,  MS_WHLD,  MS_LEFT,  MS_DOWN,  MS_RGHT,  _______,  _______,            _______,            _______,
    _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  _______,  MS_ACL0,  MS_ACL1,  _______,  _______,            MS_BTN1,  MS_BTN2,  _______,  _______,  _______,  _______,  _______,  _______
  ),
  [_KPAD] = LAYOUT_80_with_macro( /* KEYPAD / 2. FUNCTION LAYER */
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
    _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FN1]    = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT) },
    [_MS]     = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [_KPAD]   = { ENCODER_CCW_CW(UG_VALU, UG_SPDU) },
};

void eeconfig_init_user(void) {
}

void matrix_init_user(void) {
// set_unicode_input_mode(UNICODE_MODE_LINUX);
};

void __my_process_encoder_pressed(uint16_t keycode, keyrecord_t *record) {
	static uint16_t timer = 0;
	static bool pressed = false;
	if (record->event.pressed) {
		pressed = true;
		timer = timer_read();
	} else if (pressed && timer_elapsed(timer) >= TAP_CODE_DELAY) {
		pressed = false;
		tap_code16(keycode);
	}
}

//bool encoder_update_user(uint8_t index, bool clockwise) {
//    if (index == 0) {
//        if (clockwise) {
//            tap_code(KC_PGDN);
//        } else {
//            tap_code(KC_PGUP);
//        }
//    } else if (index == 1) {
//        if (clockwise) {
//            tap_code(KC_VOLU);
//        } else {
//            tap_code(KC_VOLD);
//        }
//    }
//    return true;
//}

void __handle_cycle_layers(void) {
	uint8_t lr = get_highest_layer(layer_state);
	// Check if we are within the range, if not quit
	if (lr >= LAYER_COUNT || lr < _BASE) {
		return;
	}
	lr++;
	if (lr >= LAYER_COUNT) {
		lr = _BASE;
	}
	layer_move(lr);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Encoder push repeats too eagerly, so add delay.
    if (record->event.key.col == 8 && record->event.key.row == 5 && keycode <= QK_BASIC_MAX) {
	__my_process_encoder_pressed(keycode, record);
	return false;
    }
    switch (keycode) {
	    case CK_CYCLS:
		if (record->event.pressed)
			__handle_cycle_layers();
		return false;
    }
    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
	// blink leds on certain keys
	switch (keycode) {
		case QK_BOOT:
			rgblight_blink_layer_repeat(1, 250, 4);
			break;
	}
}

// overwrite magic functions placeholders to save firmware space
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}
uint8_t mod_config(uint8_t mod) {
    return mod;
}
