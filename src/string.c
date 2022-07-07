#include "include/inttypes.h"

void memset(char *str, char c, uint32_t sz) {
    int i;

    for (i = 0; i < sz; i++) {
        str[i] = c;
    }
}
