#pragma once

// Use I2C instead of serial
#define USE_I2C

// The default for split decreases this to 100 kHz.
#define F_SCL 400000UL

// Master is the side that detects active USB connection
#define SPLIT_USB_DETECT

// fallback for SPLIT_USB_DETECT: reboot if both halves end up as slaves.
#define SPLIT_WATCHDOG_ENABLE
