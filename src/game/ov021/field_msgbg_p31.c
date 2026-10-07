/*
 * file:     field_msgbg_p31.c
 * unit:     yes
 * function: func_0218D9B8, func_0218D9C8
 * address:  0x0218D9B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj05857.h"
#include "../../matched/include/Obj19551.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;

int func_0218D9B8(u32 a);
void func_0218D9C8(u8 *p);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0218D9B8(u32 a)
{
((struct Obj05857 *)((u8 *)(a)))->f0 = 0;
((struct Obj05857 *)((u8 *)(a)))->f2 = 0;
((struct Obj05857 *)((u8 *)(a)))->f4 = 0;
((struct Obj05857 *)((u8 *)(a)))->f8 = 0;
((struct Obj05857 *)((u8 *)(a)))->fC = 0;
return a;
}


void func_0218D9C8(u8 *p)
{
    int i;
    for (i = 0; i < 16; i++)
        func_0218D9B8((u32)(p + i * 16));
    ((struct Obj19551 *)p)->f100 = 0;
}
