RGBLIGHT_ENABLE = no
BACKLIGHT_ENABLE = no

MOUSEKEY_ENABLE = yes

TAP_DANCE_ENABLE=yes
SRC += 7k2mpa.c

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
