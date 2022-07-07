/* colors are 1 byte and can be created in
 * the format of 'bg_color << 4 | fg_color' */

#include "../include/vga.h"
#include "../include/inttypes.h"

/* cursor always points to next empty space */
u32 cursor = 0;

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
void vga_print(const char *str) {
    if (str == NULL) {
        return;
    }

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
        if (cursor > VMEM_SIZE) {
            cursor = 0;
        }
    }
}

/* move cursor to 0 */
void vga_reset() {
    cursor = 0;
}

/* fill vram with null bytes and a plain background color */
void vga_clear() {
    register int i;

    for (i = 0; i < VMEM_SIZE; i += 2) {
        /* sets characters */
        vmem[i] = 0;

        /* sets colors */
        vmem[i + 1] = (COLOR_CYAN << 4) | COLOR_BLACK;
    }

    vga_reset();
}