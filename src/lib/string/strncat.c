#include <string.h>

char *strncat(char *dest, const char *src, u32 n) {
    char *tmpd = dest;
    int i;

    while ((*tmpd != 0)) {
        tmpd++;
    }

    for (i = 0; i < n; i++) {
        tmpd[i] = src[i];

        if (src[i] == 0) {
            break;
        }
    }

    tmpd[i] = 0;

    return dest;
}
