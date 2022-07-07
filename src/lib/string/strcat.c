#include <string.h>

char *strcat(char *dest, const char *src) {
    char *tmpd = dest;

    while ((*tmpd != 0)) {
        tmpd++;
    }

    while ((*tmpd++ = *src++));

    return dest;
}
