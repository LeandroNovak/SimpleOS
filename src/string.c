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