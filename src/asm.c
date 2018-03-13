#include "asm.h"

void outb(u32 ad, u8 v){
    asm("outb %%al, %%dx" 
        :
        : "d" (ad), "a" (v));;
}

void outw(u32 ad, u16 v){
    asm("outw %%ax, %%dx" 
        :
        : "d" (ad), "a" (v));
}

void outl(u32 ad, u32 v){
    asm("outl %%eax, %%dx" 
        :
        : "d" (ad), "a" (v));
}

u8 inb(u32 ad){
    u8 _v;
    asm("inb %%dx, %%al" 
        : "=a" (_v) 
        : "d" (ad));
    return _v;
}

u16 inw(u32 ad){
    u16 _v;
    asm("inw %%dx, %%ax"
        : "=a" (_v)
        : "d" (ad));
    return _v;
}

u32 inl(u32 ad){
    u32 _v;
    asm("inl %%dx, %%eax" 
        : "=a" (_v)
        : "d" (ad));
    return _v;
}