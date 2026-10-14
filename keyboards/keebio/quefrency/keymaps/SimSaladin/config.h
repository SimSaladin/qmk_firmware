#pragma once

// Use I2C instead of serial
#define USE_I2C

// The default for split decreases this to 100 kHz.
#define F_SCL 400000UL

// default 500 (mW)
#define USB_MAX_POWER_CONSUMPTION 400

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
// #define ENCODERS_PAD_A { }
// #define ENCODERS_PAD_B { }

#define ENCODER_MAP_KEY_DELAY 15

// disabled matrix pins
#undef MATRIX_COL_PINS
#define MATRIX_COL_PINS { NO_PIN, NO_PIN, F0, B7, B3, D2, D3, D5, D4 }

// Limit to lower than 255
#define RGBLIGHT_LIMIT_VAL 200
