/*
 * file:     weather_task_p41.c
 * unit:     yes
 * function: func_021A3C94, func_021A3CB0
 * address:  0x021A3C94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj05862.h"

typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

int func_021A3C94(u32 x);
int func_021A3CB0(u32 a, u32 b);


int func_021A3C94(u32 x)
{
    int i = 10;

    if (x != 0) {
        for (i = 0; i < 10; i++) {
            if (x & 1)
                break;
            x >>= 1;
        }
    }
    return i;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A3CB0(u32 a, u32 b)
{
((struct Obj05862 *)((u8 *)(a)))->f24 = b;
((struct Obj05862 *)((u8 *)(a)))->f30 = 0;
((struct Obj05862 *)((u8 *)(a)))->f32 = 0;
((struct Obj05862 *)((u8 *)(a)))->f2C = 0;
((struct Obj05862 *)((u8 *)(a)))->f2E = 0;
return a;
}
