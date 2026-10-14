#include QMK_KEYBOARD_H

#include "SimSaladin.h"

// keebio/sinc/rev2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_80_with_macro( /* DEFAULT */
    KC_MUTE ,           KC_ESC ,   KC_F1 ,   KC_F2 ,    KC_F3 ,   KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,            KC_DEL ,  KC_INS ,
    KC_NUM  , KC_PSCR,  KC_GRV ,    KC_1 ,    KC_2 ,     KC_3 ,    KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,   KC_MINS,  KC_EQL,   XXXXXXX, KC_BSPC,  KC_HOME,
    CK_CYCLS, KC_INS ,  KC_TAB ,    KC_Q ,    KC_W ,     KC_E ,    KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,   KC_LBRC,  KC_RBRC,  KC_BSLS,           KC_END ,
    KC_BRIU , UG_TOGG,  TT(_MS),    KC_A ,    KC_S ,     KC_D ,    KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,  KC_SCLN,  KC_QUOT,              KC_ENT,           KC_PGUP,
    KC_BRID , KC_UP  ,  KC_LSFT,              KC_Z ,     KC_X ,    KC_C,     KC_V,     KC_B,     KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_RSFT,   XXXXXXX,           KC_PGDN,
    KC_LEFT , KC_DOWN,  KC_LCTL,  KC_LGUI,  KC_LALT,  MO(_FN1), XXXXXXX,LT(_FN1,KC_SPC),       KC_SPC, MO(_FN1),  KC_RALT,  KC_RGUI,  XXXXXXX,  KC_RCTL,  MO(_FN1),           KC_RGHT
  ),
  [_FN1] = LAYOUT_80_with_macro( /* FUNCTION */
    _______,            QK_BOOT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    UG_HUED,  UG_HUEU,  QK_GESC,    KC_F1,    KC_F2,    KC_F3,   KC_F4 ,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,  KC_F12,   XXXXXXX,  _______,  _______,
    UG_SATD,  UG_SATU,  UG_TOGG,  UG_NEXT,   XX_DWB,    KC_UP,   XX_DWF,  _______,  KC_PGUP,  KC_HOME,    KC_UP,   KC_END,  KC_DEL ,  _______, _______,   _______,            _______,
    UG_VALD,  UG_VALU,  UG_SPDD,  KC_CAPS,   XX_MWB,  KC_DOWN,   XX_MWF,  _______,  KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_INS ,  _______,            _______,            _______,
    _______,  _______,  UG_SPDU,            _______,  XX_DLB,   _______,   XX_DLF,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  XXXXXXX,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  XXXXXXX,  _______,            _______,  _______,  _______,  _______,  XXXXXXX,  _______,  _______,  _______
  ),
  [_MS] = LAYOUT_80_with_macro( /* MOUSE KEYS */
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  XXXXXXX,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  MS_WHLU,  _______,  MS_UP  ,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  MS_WHLD,  MS_LEFT,  MS_DOWN,  MS_RGHT,  _______,  _______,            _______,            _______,
    _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  XXXXXXX,            _______,
    _______,  _______,  _______,  _______,  _______,  MS_ACL0,  XXXXXXX,  MS_ACL1,            MS_BTN1,  MS_BTN2,  _______,  _______,  _______,  _______,  _______,  _______
  ),
  [_KPAD] = LAYOUT_80_with_macro( /* KEYPAD / 2. FUNCTION LAYER */
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  XXXXXXX,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
    _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  XXXXXXX,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  XXXXXXX,  _______,            _______,  _______,  _______,  _______,  XXXXXXX,  _______,  _______,  _______
  ),
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP)},
    [_FN1]  = {ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_PGDN, KC_PGUP)},
    [_MS]   = {ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(MS_WHLU, MS_WHLD)},
    [_KPAD] = {ENCODER_CCW_CW(UG_VALU, UG_SPDU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD)},
};

// Overwrite magic functions placeholders to save firmware space
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}
uint8_t mod_config(uint8_t mod) {
    return mod;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    my_handle_custom_keycodes(keycode, record);
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
