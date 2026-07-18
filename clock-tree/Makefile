CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
SIZE  = arm-none-eabi-size
OPENOCD = openocd

CPUFLAGS = -mcpu=cortex-m3 -mthumb

CFLAGS = $(CPUFLAGS) -Wall -Wextra \
         -ffreestanding \
         -fno-common \
         -O0 -g3 \
         -ffunction-sections \
         -fdata-sections

LDFLAGS = $(CPUFLAGS) -T linker/stm32f103c8.ld \
		 -nostdlib \
		 -Wl,--gc-sections \
		 -Wl,-Map=build/firmware.map

OPENOCD_FLAGS = -f interface/stlink.cfg -f target/stm32f1x.cfg

SOURCES = startup/startup_stm32f103c8.c src/main.c
OBJECTS = build/startup.o build/main.o

TARGET = build/firmware

all: $(TARGET).elf $(TARGET).bin

build:
	mkdir -p build

build/startup.o: startup/startup_stm32f103c8.c | build
	$(CC) $(CFLAGS) -c $< -o $@

build/main.o: src/main.c | build
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET).elf: $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SIZE) $@

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

inspect: $(TARGET).elf
	$(OBJDUMP) -h -t $(TARGET).elf

flash: $(TARGET).elf
	$(OPENOCD) $(OPENOCD_FLAGS) -c "program $< verify reset exit"

clean:
	rm -rf build

.PHONY: all inspect clean