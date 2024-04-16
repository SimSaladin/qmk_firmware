/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2018 Danny Nguyen <danny@keeb.io>
Copyright 2023 Samuli Thomasson (@SimSaladin)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define OS_DETECTION_KEYBOARD_RESET

// Use I2C instead of serial
#define USE_I2C

// The default for split decreases this to 100 kHz.
#define F_SCL 400000UL

#define NO_MUSIC_MODE

// default 500 (mW)
#define USB_MAX_POWER_CONSUMPTION 400

// Always enable NKRO
#define FORCE_NKRO

// Default is 5 ms
#define DEBOUNCE 5

#define TAP_CODE_DELAY 50 // default 0
#define TAPPING_TERM 150 // default 200
#define QUICK_TAP_TERM 50 // default TAPPING_TERM
//#define QUICK_TAP_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS // TODO maybe only for mouse layer?

// Mouse Keys (kinetic mode)
#define MK_KINETIC_SPEED
#define MOUSEKEY_DELAY             0
#define MOUSEKEY_INTERVAL          2
#define MOUSEKEY_MOVE_DELTA        10
#define MOUSEKEY_INITIAL_SPEED     500
#define MOUSEKEY_BASE_SPEED        5000 // Max cursor speed
#define MOUSEKEY_DECELERATED_SPEED 300
#define MOUSEKEY_ACCELERATED_SPEED 5000

#define MOUSE_EXTENDED_REPORT // Enables support for extended reports (-32767 to 32767, instead of -127 to 127),
#define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE

#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_ACTIVITY_ENABLE
#define SPLIT_POINTING_ENABLE
#define SPLIT_CONNECTION_CHECK_TIMEOUT 50 // default 500
#define SPLIT_USB_DETECT // Master is the side that detects active USB connection
#define SPLIT_WATCHDOG_ENABLE // fallback for SPLIT_USB_DETECT: reboot if both halves end up as slaves.
//#define FORCED_SYNC_THROTTLE_MS 20

#define RPC_M2S_BUFFER_SIZE 48 // Master to slave (32 bytes)
#define RPC_S2M_BUFFER_SIZE 48 // Slave to master (32 bytes)

#define RGBLIGHT_DEFAULT_ON true // Do not enable rgblight by default
#define RGBLIGHT_SLEEP // Switch off rgblight when host goes to sleep
#define RGBLIGHT_TIMEOUT 180000 // ms, Custom RGB light timeout
#define RGBLIGHT_LIMIT_VAL 200
#define RGBLIGHT_VAL_STEP 25
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 15

// Without the macro pad there are fewer leds on the left side

#undef RGBLED_NUM
#undef RGBLIGHT_LED_COUNT
#define RGBLIGHT_LED_COUNT 14

#undef RGBLED_SPLIT
#define RGBLED_SPLIT { 6, 8 }

#undef RGBLIGHT_LED_MAP
#define RGBLIGHT_LED_MAP { 1, 2, 3, 12, 13, 0, 7, 6, 5, 4, 11, 10, 9, 8 }

// disable left side encoder (does not exist)
#undef ENCODERS_PAD_A
#undef ENCODERS_PAD_B
#define ENCODERS_PAD_A { }
#define ENCODERS_PAD_B { }

#define ENCODER_MAP_KEY_DELAY 15

// disabled matrix pins
#undef MATRIX_COL_PINS
#define MATRIX_COL_PINS { NO_PIN, NO_PIN, F0, B7, B3, D2, D3, D5, D4 }

// Disable rgblight animations to save space
#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_BREATHING
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_TWINKLE

#define RGBLIGHT_EFFECT_BREATHE_CENTER 2
#define RGBLIGHT_EFFECT_BREATHE_MAX 64 // 255
#define RGBLIGHT_BREATHE_TABLE_SIZE 64

#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYER_BLINK
//#define RGBLIGHT_LAYERS_RETAIN_VAL

// Decreases the firmware size for some reason.
// https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/
#define NO_ACTION_ONESHOT
//#define NO_ACTION_TAPPING
//#define IGNORE_MOD_TAP_INTERRUPT
//#define TAPPING_FORCE_HOLD

// Support up to 8 layers
#define LAYER_STATE_8BIT

// disable debugging stuff to decrease firmware size
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT
