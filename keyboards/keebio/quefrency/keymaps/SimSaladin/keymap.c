// Copyright 2022 Danny Nguyen (@nooges)
// Copyright 2023 Samuli Thomasson (@SimSaladin)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "SimSaladin.h"

// RGB-related keycodes: see features/rgblight.md
// UG_TOGG - toggle underglow LEDs on/off
// UG_NEXT / UG_PREV  - cycle modes  (was: RGB_MOD)
// UG_HUEU / UG_HUED  - Hue up/down    (was: RGB_VAI)
// UG_SATU / UG_SATD  - saturation inc/dec    (RGB_HUI)
// UG_VALU / UG_VALD  - Increase/decrease brightness
// UG_SPDU / UG_SPDD  - Speed up/down
//

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65(
// ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
    KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_6    ,         KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,KC_EQL  ,KC_NO   ,KC_BSPC ,KC_MUTE ,
// ├────────┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┘    ┌───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────────┼────────┤
    KC_TAB       ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,         KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_LBRC ,KC_RBRC ,KC_BSLS     ,KC_END  ,
// ├─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐      └─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────┼────────┤
    TT(_MS)        ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,         KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,KC_ENT             ,KC_PGUP ,
// ├───────────────┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┐  └─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴───────────────────┼────────┤
    KC_LSFT              ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,         KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT, KC_NO        ,KC_PGDN ,
// ├──────────┬──────────┴┬───────┴──┬─────┴─────┬──┴────────┴────────┤        ├────────┼────────┴────┬───┴────┬───┴────┬───┴────┬────────┬────────┼────────┤
    KC_LCTL   ,KC_LGUI    ,KC_LALT   ,TT(_KPAD)  ,LT(_FN1, KC_SPC)    ,         KC_SPC  ,MO(_FN1)     ,KC_RALT ,KC_RGUI ,KC_NO   ,KC_RCTL ,CK_CYCLS,KC_HOME
// └──────────┴───────────┴──────────┴───────────┴────────────────────┘        └────────┴─────────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_FN1] = LAYOUT_65(
// ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
    KC_ESC  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6   ,         KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,KC_NO   ,KC_DEL  ,QK_BOOT ,
// ├────────┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┘    ┌───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────────┼────────┤
    _______      ,_______ ,XX_DWB  ,QK_REP  ,XX_DWF  ,_______ ,         KC_PGUP ,KC_HOME ,KC_UP   ,KC_END  ,KC_DEL  ,_______ ,QK_LOCK ,_______     ,UG_TOGG ,
// ├─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐      └─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────┼────────┤
    _______        ,KC_CAPS ,XX_MWB  ,_______ ,XX_MWF  ,_______ ,         KC_PGDN ,KC_LEFT ,KC_DOWN ,KC_RIGHT,KC_INS  ,_______ ,_______            ,UG_NEXT ,
// ├───────────────┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┐  └─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴───────────────────┼────────┤
    _______              ,_______ ,  XX_DLB,_______ ,  XX_DLF,_______ ,         _______ ,PB_1    ,PB_2    ,PB_3    ,PB_4    ,_______ ,KC_NO        ,UG_SATU ,
// ├──────────┬──────────┴┬───────┴──┬─────┴─────┬──┴────────┴────────┤        ├────────┼────────┴────┬───┴────┬───┴────┬───┴────┬────────┬────────┼────────┤
    _______   ,_______    ,_______   ,_______    ,_______             ,         QK_LEAD ,_______      ,_______ ,_______ ,KC_NO   ,_______ ,_______ ,UG_HUEU
// └──────────┴───────────┴──────────┴───────────┴────────────────────┘        └────────┴─────────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_MS] = LAYOUT_65(
// ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
    _______ ,PB_1    ,PB_2    ,PB_3    ,PB_4    ,PB_5    ,PB_6    ,         PB_7    ,PB_8    ,PB_9    ,PB_10   ,PB_11   ,PB_12   ,KC_NO   ,_______ ,_______ ,
// ├────────┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┘    ┌───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────────┼────────┤
    _______      ,_______ ,MS_WHLL ,_______ ,MS_WHLR ,_______ ,         MS_WHLU ,MS_WHLL ,MS_UP   ,MS_WHLR ,_______ ,_______ ,_______ ,_______     ,QK_BOOT ,
// ├─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐      └─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴────────────┼────────┤
    _______        ,_______ ,MS_BTN4 ,MS_BTN3 ,MS_BTN5 ,_______ ,         MS_WHLD ,MS_LEFT ,MS_DOWN ,MS_RGHT ,_______ ,_______ ,_______            ,_______ ,
// ├───────────────┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┐  └─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴───────────────────┼────────┤
    _______              ,_______ ,_______ ,MS_WHLD ,MS_WHLU ,_______ ,         _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_NO        ,_______ ,
// ├──────────┬──────────┴┬───────┴──┬─────┴─────┬──┴────────┴────────┤        ├────────┼────────┴────┬───┴────┬───┴────┬───┴────┬────────┬────────┼────────┤
    _______   ,_______    ,_______   ,MS_ACL0    ,MS_ACL2             ,         MS_BTN1 ,MS_BTN2      ,_______ ,_______ ,KC_NO   ,_______ ,_______ ,_______
// └──────────┴───────────┴──────────┴───────────┴────────────────────┘        └────────┴─────────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_KPAD] = LAYOUT_65(
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

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FN1]    = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT) },
    [_MS]     = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [_KPAD]   = { ENCODER_CCW_CW(UG_VALU, UG_SPDU) },
};
#endif

// RGBLIGHT LAYERS

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

/**
 * Encoder push repeats too eagerly, so add and emit press only after it's
 * been pressed for a bit.
 */
void my_process_encoder_pressed(uint16_t keycode, keyrecord_t *record) {
    static uint16_t timer   = 0;
    static bool     pressed = false;
    if (record->event.pressed) {
        pressed = true;
        timer   = timer_read();
    } else if (pressed && timer_elapsed(timer) >= TAP_CODE_DELAY) {
        pressed = false;
        tap_code16(keycode);
    }
}

void my_handle_cycle_layers(void) {
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


// HOOKS

void eeconfig_init_user(void) { }

void matrix_init_user(void) { };

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    // Encoder push repeats too eagerly, so add delay.
    if (record->event.key.col == 8 && record->event.key.row == 5 && keycode <= QK_BASIC_MAX) {
	my_process_encoder_pressed(keycode, record);
	return false;
    }
    switch (keycode) {
	    case CK_CYCLS:
		if (record->event.pressed)
			my_handle_cycle_layers();
		return false;
    }
    return true;
}


// HOOKS :: Layer Change

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(2, layer_state_cmp(state, _FN1));
	rgblight_set_layer_state(3, layer_state_cmp(state, _MS));
	rgblight_set_layer_state(4, layer_state_cmp(state, _KPAD));
	return state;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(1, layer_state_cmp(state, _BASE));
	return state;
}

// POSTPROCESSING HOOKS

void keyboard_post_init_user(void) {
	// Enable LED layers
	rgblight_layers = my_rgb_layers;

	// Enable underglow (not saving settings)
	rgblight_enable_noeeprom();
	// sets the color to teal/cyan without saving
	rgblight_sethsv_noeeprom(180, 100, 50);
	// sets mode to Fast breathing without saving
	//rgblight_mode_noeeprom(RGBLIGHT_MODE_ST + 3);
}

bool led_update_user(led_t led_state) {
	// set capslock layer state
	rgblight_set_layer_state(0, led_state.caps_lock);
	return true;
}
