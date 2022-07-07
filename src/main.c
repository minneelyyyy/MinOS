
#include <inttypes.h>
#include <vga.h>

void kmain() {
    vga_clear();

    vga_print("Hello, World!\n");
    vga_print("Kernel-land is cool!\n");
}
