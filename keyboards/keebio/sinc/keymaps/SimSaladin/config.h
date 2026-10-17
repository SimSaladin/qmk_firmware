#pragma once

// For Sinc Rev. 2

// Use I2C instead of serial
#define USE_I2C

// Default is 10ms
#define USB_POLLING_INTERVAL_MS 4

// The default for split decreases this to 100 kHz. (Normal default is 400 kHz)
#define F_SCL 200000UL

// Master is the side that detects active USB connection
#define SPLIT_USB_DETECT

// fallback for SPLIT_USB_DETECT: reboot if both halves end up as slaves.
#define SPLIT_WATCHDOG_ENABLE

// mirror the master side matrix to slave
#define SPLIT_TRANSPORT_MIRROR

// sync layer state between both halves
#define SPLIT_LAYER_STATE_ENABLE

// sync host led status between both halves
#define SPLIT_LED_STATE_ENABLE

// sync modifier state between both halves
#define SPLIT_MODS_ENABLE

// XXX
#undef DEBOUNCE
#define DEBOUNCE 2

// underglow sync for split keyboard
#define RGBLIGHT_SPLIT

#define RGBLIGHT_LAYERS
#define RGBLIGHT_MAX_LAYERS 4
#define RGBLIGHT_LAYER_BLINK
