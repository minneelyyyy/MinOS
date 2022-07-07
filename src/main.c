
#include "include/inttypes.h"

/* colors are 1 byte and can be created in
 * the format of 'bg_color << 4 | fg_color' */

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

/* cursor always points to next empty space */
uint32_t cursor = 0;

/* pointer to video memory
 * every byte thats at an even address is a character.
 * every byte thats at an odd address is a color.
 * 
 * for example: ['A'][0x0F] is an A with a
 *  black background and white foreground.
 * 
 * NOTE: if you want to use uint16_t to store both a color and a character
 *  you need to reverse the byte order on little-endian machines. */
char *const vmem = (char*) 0xb8000;

/* print a string to the terminal */
void print(const char *str) {
    while (*str != 0) {
        switch (*str) {
            case '\n':
                cursor += (COLUMNS - (cursor % COLUMNS)) - 1;
                break;

            case '\t': {
                while (cursor % TAB != 0) {
                    vmem[cursor * 2] = ' ';
                    cursor++;
                }

                break;
            }

            default:
                vmem[cursor * 2] = *str;
                break;
        }

        cursor++;
        str++;

        /* TODO: add a line to the bottom if reached. */
        if (cursor > VMEM_SIZE)
            cursor = 0;
    }
}

/* move cursor to 0 */
void reset() {
    cursor = 0;
}

/* fill vram with null bytes and a plain background color */
void clear() {
    register int i;

    for (i = 0; i < VMEM_SIZE; i += 2) {
        /* sets characters */
        vmem[i] = 0;

        /* sets colors */
        vmem[i + 1] = (COLOR_CYAN << 4) | COLOR_BLACK;
    }

    reset();
}

void kmain() {
    clear();

    print("Hello, World!\n");
    print("Kernel-land is cool!\n");
}
