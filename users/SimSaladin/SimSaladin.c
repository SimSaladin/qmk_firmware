#include QMK_KEYBOARD_H

#include "SimSaladin.h"

// For macro keycode mapping
#include "sendstring_dvorak_programmer.h"

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

__attribute__ ((weak))
void post_process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return;
}

__attribute__ ((weak))
void housekeeping_task_keymap(void) {
    return;
}

#ifdef RGBLIGHT_TIMEOUT
// timer for last keyboard activity, use 32bit value and function to make longer idle time possible
static uint32_t key_timer = 0;
// store if RGB has timed out or not in a boolean
static bool is_rgblight_timeout = false;
#endif

/**
 * Handles custom keycodes i.e. trigger macros etc.
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case XX_DLB:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("x") SS_TAP(X_BSPC));
            }
            break;
//        case CK_CYCLS:
//            if (record->event.pressed) my_handle_cycle_layers();
//            return false;
    }
    return process_record_keymap(keycode, record);
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef RGBLIGHT_TIMEOUT
    if (record->event.pressed) {
	key_timer = timer_read32(); // store last refresh
        // Wakeup rgblight from suspend on activity.
	if (is_rgblight_timeout && !rgblight_is_enabled()) {
		is_rgblight_timeout = false;
		rgblight_wakeup();
	}
    }
#endif

#ifdef RGBLIGHT_LAYERS
    switch (keycode) {
            // blink leds on certain keys
            case QK_BOOT:
            case KC_MUTE:
            case KC_CAPS:
                    rgblight_blink_layer_repeat(0, 250, 4);
                    break;
    }
#endif
    return post_process_record_keymap(keycode, record);
}

void housekeeping_task_user(void) {
#ifdef RGBLIGHT_TIMEOUT
    if (is_keyboard_master()) {
        // check if RGBLIGHT_TIMEOUT passed and suspend rgblight.
        if (rgblight_is_enabled() && !is_rgblight_timeout && timer_elapsed32(key_timer) > RGBLIGHT_TIMEOUT) {
            rgblight_suspend();
            is_rgblight_timeout = true;
        }
    }
#endif // RGBLIGHT_TIMEOUT
    return housekeeping_task_keymap();
}
