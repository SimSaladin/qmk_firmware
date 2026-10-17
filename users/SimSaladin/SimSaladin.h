#ifndef USERSPACE
#define USERSPACE

#include QMK_KEYBOARD_H

// We use DP_* to define keycodes below.
#include "keymap_dvorak_programmer.h"

// My default set of layers
enum my_layers {
    _BASE,         // [0] base layer.
    _FN1,          // [1] function keys etc.
    _MS,           // [2] mouse keys
    _KPAD,         // [3] numpad etc.
    LAYER_COUNT
};

#define XX_DLF LCTL(DP_K)    // <C-k>          [D]elete [l]line    [f]forward
#define XX_MWB LALT(DP_B)    // <A-b>          [m]ove   [b]ackward [w]ord
#define XX_MWF LALT(DP_F)    // <A-f>          [m]ove   [f]orward  [w]ord
#define XX_DWF LALT(DP_D)    // <A-d>          [D]elete [w]ord     [f]orwards
#define XX_DWB LALT(KC_BSPC) // <A-Bspc>       [D]elete [w]ord     [b]ackwards

enum custom_keycodes {
    XX_DLB = SAFE_RANGE,     // <C-x> <Rubout> aka delete-line-backwards
    CK_CYCLS,
    CK_QWERTY,
};

#endif
