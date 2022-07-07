#ifndef __VGA_H
#define __VGA_H

#define COLOR_BLACK             0x00
#define COLOR_BLUE              0x01
#define COLOR_GREEN             0x02
#define COLOR_CYAN              0x03
#define COLOR_RED               0x04
#define COLOR_MAGENTA           0x05
#define COLOR_YELLOW            0x06
#define COLOR_LIGHT_GREY        0x07

#define COLOR_DARK_GREY         0x08
#define COLOR_BRIGHT_BLUE       0x09
#define COLOR_BRIGHT_GREEN      0x0A
#define COLOR_BRIGHT_CYAN       0x0B
#define COLOR_BRIGHT_RED        0x0C
#define COLOR_BRIGHT_MAGENTA    0x0D
#define COLOR_BRIGHT_YELLOW     0x0E
#define COLOR_WHITE             0x0F

#define COLUMNS 80
#define ROWS 25
#define TAB 8

#define VMEM_SIZE (COLUMNS * ROWS * 2)

void vga_print(const char *str);
void vga_reset();
void vga_clear();

#endif /* __VGA_H */