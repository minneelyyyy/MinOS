#include <string.h>

int strcmp(const char *str1, const char *str2) {
    unsigned char c1, c2;

    do {
        c1 = (unsigned char) *str1++;
        c2 = (unsigned char) *str2++;

        if (c1 == '\0') {
            return c1 - c2;
        }
    } while (c1 == c2);

    return c1 - c2;
}
