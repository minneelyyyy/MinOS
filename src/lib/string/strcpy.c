#include <string.h>

char *strcpy(char *dest, const char *src) {
    char *save = dest;

    while ((*dest++ = *src++));

    return save;
}
