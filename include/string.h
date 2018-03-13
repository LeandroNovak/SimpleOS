#ifndef STRING_H
#define STRING_H

#include <stddef.h>
#include "memory.h"

size_t strlen(const char* str);

size_t strcmp(const char* str1, const char* str2);

size_t strcpy(char *dst,const char *src);

char * strncpy(char *dst, const char *src, size_t num);

size_t strncmp(const char* str1, const char* str2, size_t num);

void   strcat(void *dest,const void *src);

#endif //STRING_H