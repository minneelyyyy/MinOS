#include <string.h>

void *memmove(void *dest, const void *src, u32 n) {
    /* TODO: implement an overlap safe move */
    return memcpy(dest, src, n);
}
