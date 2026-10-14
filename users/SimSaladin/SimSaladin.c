#include QMK_KEYBOARD_H

#include "SimSaladin.h"

#include "sendstring_dvorak_programmer.h"

void my_handle_custom_keycodes(uint16_t kc, keyrecord_t *rec) {
    switch (kc) {
        case XX_DLB:
            if (rec->event.pressed) {
                SEND_STRING(SS_LCTL("x") SS_TAP(X_BSPC));
            }
            break;
    }
}

// if (record->event.key.col == 8 && record->event.key.row == 5 && keycode <= QK_BASIC_MAX) {
//     my_process_encoder_pressed(keycode, record);
//     return false;
// }
// return true;

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

//@bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//@    switch (keycode) {
//@        case CK_CYCLS:
//@            if (record->event.pressed) __handle_cycle_layers();
//@            return false;
//@    }
//@    return true;
//@}

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

// #ifdef RGBLIGHT_TIMEOUT

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

void my_post_process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed)
		my_rgblight_refresh();
}

// END RGBALIGHT_TIMEOUT
