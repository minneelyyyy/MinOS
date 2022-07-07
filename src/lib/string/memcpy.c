#include <string.h>

void *memcpy(void *dest, const void *src, u32 n) {
    int i;

    for (i = 0; i < n; i++) {
        ((char*)dest)[i] = ((char*)src)[i];
    }

    return dest;
}
