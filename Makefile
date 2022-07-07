
CC=i386-elf-gcc
CFLAGS=-c -nostdlib -nostdinc -fno-builtin -fno-stack-protector -ffreestanding
LD=i386-elf-ld
ASM=nasm

BUILD=build

c_sources := $(shell find src/ -name "*.c")
c_objects := $(patsubst src/%.c, $(BUILD)/%.o, $(c_sources))
assembly_sources := $(shell find src/ -name "*.asm")
assembly_objects := $(patsubst src/%.asm, $(BUILD)/%.o, $(assembly_sources))

include_dir := src/include

.PHONY: all clean

all: build/minos.iso


$(c_objects): $(BUILD)/%.o : src/%.c
	@echo " CC      $(patsubst $(BUILD)/%.o,src/%.c,$@)"
	@mkdir -p $(dir $@) > /dev/null
	@$(CC) $(CFLAGS) -I$(include_dir) $(patsubst $(BUILD)/%.o, src/%.c, $@) -o $@ > /dev/null

$(assembly_objects): $(BUILD)/%.o : src/%.asm
	@echo " AS      $(patsubst $(BUILD)/%.o,src/%.asm,$@)"
	@mkdir -p $(dir $@) > /dev/null
	@$(ASM) -felf $(patsubst $(BUILD)/%.o, src/%.asm, $@) -o $@ > /dev/null


build/minos.bin: $(assembly_objects) $(c_objects)
	@echo " LD      $@"
	@$(LD) -n -o build/minos.bin -Tlinker.ld $(assembly_objects) $(c_objects) > /dev/null

geniso/boot/minos.bin: build/minos.bin
	@echo " CP      $^ -> $@"
	@cp build/minos.bin geniso/boot/minos.bin > /dev/null

build/minos.iso: geniso/boot/minos.bin
	@echo " MKRCUE  $@"
	@grub-mkrescue /usr/lib/grub/i386-pc -o build/minos.iso geniso/ > /dev/null 2>&1


clean:
	@rm -rf build/ geniso/boot/minos.bin
