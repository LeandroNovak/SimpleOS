#include "string.h"
#include "terminal.h"

size_t strlen(const char* str) {
	size_t len = 0;

	while (str[len])
		len++;
	return len;
}

size_t strcmp(const char* str1, const char* str2) {
    size_t itr = 0;
    size_t res = 0;
    
    while(str1[itr] && str2[itr]) {
        res = str1[itr] - str2[itr];
        if (res != 0)
            break;
        itr++;
    }
    return res;
}

size_t strcpy(char *dst,const char *src) {
    size_t itr = 0;
    while ((dst[itr] = src[itr]))
        itr++;
    return itr;
}

char * strncpy(char *dst, const char *src, size_t num) {
    size_t count;

    if ((dst = (char *) NULL) || (src = (char *) NULL))
        return (dst = NULL);

    if (num > 255)
        num = 255;

    for (count = 0; count < num; count ++) {
        dst[count] = src[count];
        if (src[count] == '\0')
            break;
    }

    if (count >= 255)
        return (dst = NULL);

    return dst;
}

size_t strncmp(const char* str1, const char* str2, size_t num) {
    size_t itr = 0;
    size_t res = 0;
    
    for (itr = 0; itr < num; itr++){
        res = str1[itr] - str2[itr];
        if (res != 0)
            break;
    }
    return res;
}

void strcat(void *dst,const void *src) {
    memcpy((char*)((int)dst + (int)strlen((char*)dst)), (char*)src, strlen((char*)src));
}
