#include "memory.h"

size_t memcmp(const void* ptr1, const void* ptr2, size_t num) {
    const unsigned char* tmp1 = ptr1;
    const unsigned char* tmp2 = ptr2;
    size_t itr = 0;
    size_t res = 0;
    
    for (itr = 0; itr < num; itr++){
        res = (*(tmp1 + (itr * sizeof(char))) - *(tmp2 + (itr * sizeof(char))));
        if (res != 0)
            break;
    }
    return res;
}

void * memset(char *dst,char src, size_t num) {
    char *p = dst;

    while (num--)
        *dst++ = src;
    return p;
}

void * memcpy(char *dst, char *src, size_t num) {
    char *p = dst;
    
    while (num--)
        *dst++ = *src++;
    return p;
}