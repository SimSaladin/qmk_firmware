#ifndef USERSPACE
#define USERSPACE

#include QMK_KEYBOARD_H
#include "keymap_dvorak_programmer.h"

// My default set of layers
enum my_layers {
    _BASE, // Base layer / _BASE,     // 0
    _FN1,  // 1. function layer       // 1
    _MS,   // mouse keys layer        // 2
    _KPAD, // 3 keymap
    LAYER_COUNT
};

enum my_keycodes {
    CK_QWERTY = QK_USER_0,
    XX_DLF = LCTL(DP_K),    // <C-k>          [D]elete [l]line    [f]forward
    XX_MWB = LALT(DP_B),    // <A-b>          [m]ove   [b]ackward [w]ord
    XX_MWF = LALT(DP_F),    // <A-f>          [m]ove   [f]orward  [w]ord
    XX_DWF = LALT(DP_D),    // <A-d>          [D]elete [w]ord     [f]orwards
    XX_DWB = LALT(KC_BSPC), // <A-Bspc>       [D]elete [w]ord     [b]ackwards
    XX_DLB = QK_USER_1,     // <C-x> <Rubout> aka delete-line-backwards
    CK_CYCLS = QK_USER_1,
};

/**
 * Implements the handling of custom keycodes in my_keycodes.
 *
 * This should go in process_record_user!
 */
void my_handle_custom_keycodes(uint16_t, keyrecord_t*);

void my_process_encoder_pressed(uint16_t, keyrecord_t *);
void my_handle_cycle_layers(void);

#endif
