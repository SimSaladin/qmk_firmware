// Copyright 2022 Danny Nguyen (@nooges)
// Copyright 2023 Samuli Thomasson (@SimSaladin)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "keymap_dvorak_programmer.h"

enum my_layers {
  _BASE, // 0
  _FN1, // 1
  _MOUSE, // 2
  _KEYPAD, // 3
  LAYER_COUNT
};

enum my_keycodes {
  CK_QWERTY = QK_USER,
  CK_CYCLS,
};

#define X_A_B  LALT(DP_B)    // backward word
#define X_A_F  LALT(DP_F)    // forward word
#define X_A_D  LALT(DP_D)    // delete forward word
#define X_A_BS LALT(KC_BSPC) // delete backward word

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65(
// ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
    KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_6    ,         KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,KC_EQL  ,KC_NO   ,KC_BSPC ,KC_MUTE ,
// ├────────┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┘    ┌───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────────┼────────┤
    KC_TAB       ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,         KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_LBRC ,KC_RBRC ,KC_BSLS     ,KC_END  ,
// ├─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐      └─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────┼────────┤
    TT(_MOUSE)     ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,         KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,KC_ENT             ,KC_PGUP ,
// ├───────────────┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┐  └─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴───────────────────┼────────┤
    KC_LSFT              ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,         KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT, KC_NO        ,KC_PGDN ,
// ├──────────┬──────────┴┬───────┴──┬─────┴─────┬──┴────────┴────────┤        ├────────┼────────┴────┬───┴────┬───┴────┬───┴────┬────────┬────────┼────────┤
    KC_LCTL   ,KC_LGUI    ,KC_LALT   ,TT(_KEYPAD),LT(_FN1, KC_SPC)    ,         KC_SPC  ,MO(_FN1)     ,KC_RALT ,KC_RGUI ,KC_NO   ,KC_RCTL ,CK_CYCLS,KC_HOME
// └──────────┴───────────┴──────────┴───────────┴────────────────────┘        └────────┴─────────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_FN1] = LAYOUT_65(
// ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
    KC_ESC  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6   ,         KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,KC_NO   ,KC_DEL  ,QK_BOOT ,
// ├────────┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┘    ┌───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────────┼────────┤
    _______      ,_______ ,X_A_BS  ,QK_REP  ,X_A_D   ,_______ ,         KC_PGUP ,KC_HOME ,KC_UP   ,KC_END  ,KC_DEL  ,_______ ,QK_LOCK ,_______     ,RGB_TOG ,
// ├─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐      └─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────┼────────┤
    _______        ,KC_CAPS ,X_A_B   ,_______ ,X_A_F   ,_______ ,         KC_PGDN ,KC_LEFT ,KC_DOWN ,KC_RIGHT,KC_INS  ,_______ ,_______            ,RGB_MOD ,
// ├───────────────┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┐  └─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴───────────────────┼────────┤
    _______              ,_______ ,_______ ,_______ ,_______ ,_______ ,         _______ ,PB_1    ,PB_2    ,PB_3    ,PB_4    ,_______ ,KC_NO        ,RGB_VAI ,
// ├──────────┬──────────┴┬───────┴──┬─────┴─────┬──┴────────┴────────┤        ├────────┼────────┴────┬───┴────┬───┴────┬───┴────┬────────┬────────┼────────┤
    _______   ,_______    ,_______   ,_______    ,_______             ,         QK_LEAD ,_______      ,_______ ,_______ ,KC_NO   ,_______ ,_______ ,RGB_HUI
// └──────────┴───────────┴──────────┴───────────┴────────────────────┘        └────────┴─────────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_MOUSE] = LAYOUT_65(
// ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
    _______ ,PB_1    ,PB_2    ,PB_3    ,PB_4    ,PB_5    ,PB_6    ,         PB_7    ,PB_8    ,PB_9    ,PB_10   ,PB_11   ,PB_12   ,KC_NO   ,_______ ,_______ ,
// ├────────┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┘    ┌───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────────┼────────┤
    _______      ,_______ ,KC_WH_L ,_______ ,KC_WH_R ,_______ ,         KC_WH_U ,KC_WH_L ,KC_MS_U ,KC_WH_R ,_______ ,_______ ,_______ ,_______     ,QK_BOOT ,
// ├─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐      └─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────┼────────┤
    _______        ,_______ ,KC_BTN4 ,KC_BTN3 ,KC_BTN5 ,_______ ,         KC_WH_D ,KC_MS_L ,KC_MS_D ,KC_MS_R ,_______ ,_______ ,_______            ,_______ ,
// ├───────────────┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┐  └─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴───────────────────┼────────┤
    _______              ,_______ ,_______ ,KC_WH_D ,KC_WH_U ,_______ ,         _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_NO        ,_______ ,
// ├──────────┬──────────┴┬───────┴──┬─────┴─────┬──┴────────┴────────┤        ├────────┼────────┴────┬───┴────┬───┴────┬───┴────┬────────┬────────┼────────┤
    _______   ,_______    ,_______   ,KC_ACL0    ,KC_ACL2             ,         KC_BTN1 ,KC_BTN2      ,_______ ,_______ ,KC_NO   ,_______ ,_______ ,_______
// └──────────┴───────────┴──────────┴───────────┴────────────────────┘        └────────┴─────────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_KEYPAD] = LAYOUT_65(
// ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
    _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,         KC_ESC  ,KC_PSLS ,KC_PAST ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
// ├────────┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┘    ┌───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────────┼────────┤
    _______      ,KC_SYRQ ,KC_PSCR ,KC_SCRL ,KC_NUM ,KC_BRK  ,         KC_PMNS ,KC_KP_7 ,KC_KP_8 ,KC_KP_9 ,KC_PCMM , _______,_______ ,_______     ,_______ ,
// ├─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐      └─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────┼────────┤
    _______        ,_______ ,_______ ,_______ ,_______ ,KC_INS  ,         KC_PPLS ,KC_KP_4 ,KC_KP_5 ,KC_KP_6 ,KC_NUM  ,_______ ,_______            ,_______ ,
// ├───────────────┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┐  └─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴───────────────────┼────────┤
    _______              ,_______ ,_______ ,_______ ,_______ ,_______ ,        KC_PDOT  ,KC_KP_1 ,KC_KP_2 ,KC_KP_3 ,KC_PEQL ,_______ ,_______      ,_______ ,
// ├──────────┬──────────┴┬───────┴──┬─────┴─────┬──┴────────┴────────┤        ├────────┼────────┴────┬───┴────┬───┴────┬───┴────┬────────┬────────┼────────┤
    _______   ,_______    ,_______   ,_______    ,_______             ,         KC_KP_0 ,KC_PENT      ,_______ ,_______ ,_______ ,_______ ,_______ ,_______
// └──────────┴───────────┴──────────┴───────────┴────────────────────┘        └────────┴─────────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE]   = { ENCODER_CCW_CW(KC_VOLD,     KC_VOLU)       },
    [_FN1]    = { ENCODER_CCW_CW(KC_LEFT,     KC_RIGHT)      },
    [_MOUSE]  = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_KEYPAD] = { ENCODER_CCW_CW(RGB_SAD,     RGB_SAI)       },
};

void eeconfig_init_user(void) {
}

void matrix_init_user(void) {
// set_unicode_input_mode(UNICODE_MODE_LINUX);
};

void my_process_encoder_pressed(uint16_t keycode, keyrecord_t *record) {
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

void handle_cycle_layers(void) {
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
	my_process_encoder_pressed(keycode, record);
	return false;
    }
    switch (keycode) {
	    case CK_CYCLS:
		if (record->event.pressed)
			handle_cycle_layers();
		return false;
    }
    return true;
}

#ifdef RGBLIGHT_TIMEOUT
// timer for last keyboard activity, use 32bit value and function to make longer idle time possible
static uint32_t key_timer = 0;
// store if RGB has timed out or not in a boolean
static bool is_rgblight_timeout = false;

// Wakeup rgblight from suspend on activity.
void my_rgblight_refresh(void) {
	key_timer = timer_read32(); // store last refresh
	if (is_rgblight_timeout) {
		is_rgblight_timeout = false;
		rgblight_wakeup();
	}
}

// check if RGBLIGHT_TIMEOUT passed and suspend rgblight.
void my_rgblight_check_timeout(void) {
	if (!is_rgblight_timeout && timer_elapsed32(key_timer) > RGBLIGHT_TIMEOUT) {
		rgblight_suspend();
		is_rgblight_timeout = true;
	}
}
#endif

void housekeeping_task_user(void) {
#ifdef RGBLIGHT_TIMEOUT
	my_rgblight_check_timeout();
#endif
}

// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_rgb_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 4, HSV_RED},       // Light 4 LEDs, starting with LED 6
    {12, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12
);
const rgblight_segment_t PROGMEM my_rgb_layer1[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_rgb_layer2[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 4, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_rgb_layer3[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 4, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_rgb_layer4[] = RGBLIGHT_LAYER_SEGMENTS(
    {8, 4, HSV_MAGENTA}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  my_rgb_capslock_layer,
  my_rgb_layer1,
  my_rgb_layer2,
  my_rgb_layer3,
  my_rgb_layer4
);

void keyboard_post_init_user(void) {
	// Enable LED layers
	rgblight_layers = my_rgb_layers;

  rgblight_enable_noeeprom(); // enables Rgb, without saving settings
  rgblight_sethsv_noeeprom(180, 100, 50); // sets the color to teal/cyan without saving
  //rgblight_mode_noeeprom(RGBLIGHT_MODE_ST + 3); // sets mode to Fast breathing without saving
}

bool led_update_user(led_t led_state) {
	// set capslock layer state
	rgblight_set_layer_state(0, led_state.caps_lock);
	return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(1, layer_state_cmp(state, _BASE));
	return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(2, layer_state_cmp(state, _FN1));
	rgblight_set_layer_state(3, layer_state_cmp(state, _MOUSE));
	rgblight_set_layer_state(4, layer_state_cmp(state, _KEYPAD));
	return state;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
	// blink leds on certain keys
	switch (keycode) {
		case QK_BOOT:
			rgblight_blink_layer_repeat(1, 250, 4);
			break;
	}

#ifdef RGBLIGHT_TIMEOUT
	if (record->event.pressed)
		my_rgblight_refresh();
#endif
}

// overwrite magic functions placeholders to save firmware space
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}
uint8_t mod_config(uint8_t mod) {
    return mod;
}
