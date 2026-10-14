#pragma once

// Prefer that the board reset more frequently to work with OS detection
#define OS_DETECTION_KEYBOARD_RESET

// Default debounce time is 5ms
#define DEBOUNCE 3

// Support up to 8 layers
#define LAYER_STATE_8BIT

// Enables support for extended reports (-32767 to 32767, instead of -127 to 127),
#define MOUSE_EXTENDED_REPORT

// Mouse Keys (kinetic mode)
#define MK_KINETIC_SPEED
#define MOUSEKEY_DELAY             0
#define MOUSEKEY_INTERVAL          2
#define MOUSEKEY_MOVE_DELTA        10
#define MOUSEKEY_INITIAL_SPEED     500
#define MOUSEKEY_BASE_SPEED        5000 // Max cursor speed
#define MOUSEKEY_DECELERATED_SPEED 300
#define MOUSEKEY_ACCELERATED_SPEED 5000

// Disable useless features to save space
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE

// RGBLIGHT
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYER_BLINK
#define RGBLIGHT_LAYERS_RETAIN_VAL
#define RGBLIGHT_SLEEP // Switch off rgblight when host goes to sleep
#define RGBLIGHT_TIMEOUT 180000 // ms, Custom RGB light timeout
// Defaults when EEPROM is cleared
#define RGBLIGHT_DEFAULT_ON true
#define RGBLIGHT_DEFAULT_VAL 200
#undef RGBLIGHT_DEFAULT_MODE
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT

// Disable various animations in order to save ROM space.
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

// ... and enable some custom ones as defaults
#define RGBLIGHT_EFFECT_BREATHE_CENTER 2
#define RGBLIGHT_EFFECT_BREATHE_MAX 64 // 255
#define RGBLIGHT_BREATHE_TABLE_SIZE 64

// Disable debugging stuff to decrease firmware size
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT
