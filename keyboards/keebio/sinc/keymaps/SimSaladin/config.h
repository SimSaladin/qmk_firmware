#pragma once

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


// // Mouse Keys (kinetic mode)
// #define MK_KINETIC_SPEED
// #define MOUSEKEY_DELAY         0
// #define MOUSEKEY_INTERVAL      1
// #define MOUSEKEY_MOVE_DELTA    10
// #define MOUSEKEY_INITIAL_SPEED 350

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

// Support up to 8 layers
#define LAYER_STATE_8BIT

// rgblight
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYER_BLINK
