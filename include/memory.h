#ifndef MEMORY_H
#define MEMORY_H

#include <stddef.h>

size_t memcmp(const void* ptr1, const void* ptr2, size_t num);

void * memset(char *dst,char src, size_t num);

void * memcpy(char *dst, char *src, size_t num);

#endif //MEMORY_H