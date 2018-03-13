#ifndef ASM_H
#define ASM_H

#include "types.h"

/* output byte */
void outb(u32 ad, u8 v);

/* output word */
void outw(u32 ad, u16 v);

/* output word */
void outl(u32 ad, u32 v);

/* input byte */
u8 inb(u32 ad);

/* input word */
u16 inw(u32 ad);

/* input word */
u32 inl(u32 ad);

#endif //ASM_H