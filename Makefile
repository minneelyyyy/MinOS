
CC=i386-elf-gcc
LD=i386-elf-ld
ASM=nasm

BUILD=build

c_sources := src/main.c src/string.c
c_objects := $(patsubst src/%.c, $(BUILD)/%.o, $(c_sources))
assembly_sources := src/header.asm src/entry.asm
assembly_objects := $(patsubst src/%.asm, $(BUILD)/%.o, $(assembly_sources))

.PHONY: all clean

all: $(BUILD) geniso/boot/minos.bin build/minos.iso

$(BUILD):
	mkdir $@


$(c_objects): $(BUILD)/%.o : src/%.c
	$(CC) -c -nostdlib -nostdinc -fno-builtin -fno-stack-protector -ffreestanding $(patsubst $(BUILD)/%.o, src/%.c, $@) -o $@

$(assembly_objects): $(BUILD)/%.o : src/%.asm
	$(ASM) -felf32 $(patsubst $(BUILD)/%.o, src/%.asm, $@) -o $@


build/minos.bin: $(assembly_objects) $(c_objects)
	$(LD) -n -o build/minos.bin -Tlinker.ld $(assembly_objects) $(c_objects)

geniso/boot/minos.bin: build/minos.bin
	cp build/minos.bin geniso/boot/minos.bin

build/minos.iso: build/minos.iso
	grub-mkrescue /usr/lib/grub/i386-pc -o build/minos.iso geniso/


clean:
	rm -rf build/ geniso/boot/minos.bin
