#include QMK_KEYBOARD_H

// Layer shorthand
#define L_DF 0
#define L_FN 1
#define L_MK 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_DF] = LAYOUT_80_with_macro( /* DEFAULT */
    KC_MUTE,            KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_INS,
    KC_NUM,   KC_PSCR,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   _______,  KC_BSPC, KC_HOME,
    KC_SCRL,  KC_INS,   KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_END,
    KC_BRIU,  RGB_TOG,  MO(L_MK), KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_PGUP,
    KC_BRID,  KC_UP,    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  _______,  KC_PGDN,
    KC_LEFT,  KC_DOWN,  KC_LCTL,  KC_LGUI,  KC_LALT,  MO(L_FN), _______,  KC_SPC,             KC_SPC,   MO(L_FN), KC_RALT,  KC_RGUI,  _______,  KC_RCTL,  MO(L_FN), KC_RGHT
  ),
  [L_FN] = LAYOUT_80_with_macro( /* FUNCTION */
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    RGB_HUI,  RGB_HUD,  QK_GESC,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  _______,
    RGB_SAI,  RGB_SAD,  RGB_TOG,  RGB_MOD,  _______,  KC_UP,    _______,  _______,  _______,  _______,  KC_UP,    _______,  _______,  _______,  _______,  _______,  _______,
    RGB_VAI,  RGB_VAD,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT, _______,  _______,            _______,  _______,
    _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),
  [L_MK] = LAYOUT_80_with_macro( /* MOUSE KEYS */
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_WH_U,  _______,  KC_MS_U,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_WH_D,  KC_MS_L,  KC_MS_D,  KC_MS_R,  _______,  _______,            _______,  _______,
    _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_BTN1,  KC_BTN2,  _______,  _______,  _______,  _______,  _______,  _______
  ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}
