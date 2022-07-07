#include <string.h>

int memcmp(const void *str1, const void *str2, u32 n) {
    const char *s1 = str1, *s2 = str2;
    unsigned char c1, c2;
    int i;

    for (i = 0; i < n; i++) {
        c1 = (unsigned char) *s1++;
        c2 = (unsigned char) *s2++;

        if (c1 != c2) {
            return c1 - c2;
        }
    }

    return 0;
}
