# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
KEY_OVERRIDE_ENABLE = no   # Override key
TAP_DANCE_ENABLE = yes
# CONSOLE_ENABLE = yes

RGB_MATRIX_ENABLE = yes         # Use RGB matrix
RGB_MATRIX_DRIVER = is31fl3741

LTO_ENABLE = yes

LAYOUTS = tkl_iso

SRC +=							features/custom_keys.c
