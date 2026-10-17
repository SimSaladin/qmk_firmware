# rules.mk for keymaps: SimSaladin

# Common features to always enable:
LTO_ENABLE = yes
MOUSEKEY_ENABLE = yes
NKRO_ENABLE = yes
PROGRAMMABLE_BUTTON_ENABLE = yes
ENCODER_MAP_ENABLE = yes
SRC += SimSaladin.c

# Hack for bad power saving practicces Do not put the microcontroller into power saving mode
# when we get USB suspend event.
#OPT_DEFS += -DNO_SUSPEND_POWER_DOWN

# Certain options nodisale
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MUSIC_ENABLE = no

# Use a shared USB endpoint for keyboard and mouse for efficiency.
KEYBOARD_SHARED_EP = yes
MOUSE_SHARED_EP = yes
