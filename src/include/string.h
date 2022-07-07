#ifndef __STRING_H
#define __STRING_H

#include "inttypes.h"

const void *memchr(const void *str, int c, u32 n);
int memcmp(const void *str1, const void *str2, u32 n);
void *memcpy(void *dest, const void *src, u32 n);
void *memmove(void *dest, const void *src, u32 n);
void *memset(void *str, int c, u32 n);
char *strcat(char *dest, const char *src);
const char *strchr(const char *str, int c);
int strcmp(const char *str1, const char *str2);
char *strcpy(char *dest, const char *src);
u32 strlen(const char *str);
char *strncat(char *dest, const char *src, u32 n);
char *strncpy(char *dest, const char *src, u32 n);

#endif /* __STRING_H */