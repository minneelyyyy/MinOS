#include <string.h>

u32 strlen(const char *str) {
    register u32 len = 0;

    while (*str++) {
        len++;
    }

    return len;
}
