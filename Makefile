PREFIX ?= arm-none-eabi-
CC     := $(PREFIX)gcc
OBJCOPY:= $(PREFIX)objcopy
SIZE   := $(PREFIX)size

CFLAGS ?= -W -Wall -Wextra -Werror -Wundef -Wshadow -Wdouble-promotion \
	-Wformat-truncation -fno-common -Wconversion \
	-g3 -O0 -ffunction-sections -fdata-sections -Iinclude -Ibsp -I. \
	-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 $(EXTRA_CFLAGS)

LDFLAGS ?= -Tf411.ld -nostartfiles -nostdlib -Wl,--gc-sections -Wl,-Map=firmware.map -lgcc

SOURCES := \
	src/startup.c \
	src/main.c \
	src/rcc.c \
	src/gpio.c \
	src/systick.c \
	bsp/bsp_led.c

all: firmware.bin

firmware.elf: $(SOURCES) f411.ld
	$(CC) $(CFLAGS) $(SOURCES) $(LDFLAGS) -o $@
	$(SIZE) $@

firmware.bin: firmware.elf
	$(OBJCOPY) -O binary $< $@

flash: firmware.bin
	st-flash --reset write $< 0x08000000

clean:
	rm -f firmware.elf firmware.bin firmware.map

.PHONY: all clean flash
