#ifndef STRING_H
#define STRING_H

#include <stddef.h>

size_t strlen(const char* str);

size_t strcmp(const char* str1, const char* str2);

size_t memcmp(const void* ptr1, const void* ptr2, size_t num);

size_t strncmp(const char* str1, const char* str2, size_t num);

#endif //STRING_H