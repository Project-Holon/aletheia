/*
 * file:     field_fog_p15.c
 * unit:     yes
 * function: func_021A07B0, func_021A07B4
 * address:  0x021A07B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A07F8  0x021A07F8  thumb  ov021
 */
#include "../../matched/include/Obj12700.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

extern int func_021A07F8(u32 a, void *t);
void func_021A07B0(void);
u32 func_021A07B4(u8 *p, int t);


/*
 * An empty function.
 */
void func_021A07B0(void)
{
}


/*
 * Addresses are Black-image addresses.
 */
u32 func_021A07B4(u8 *p, int t)
{
    int prev = 0;
    u32 i;
    int v;
    for (i = 0; i < ((struct Obj12700 *)p)->fC; i++) {
        v = func_021A07F8(((struct Obj12700 *)p)->f2, p + 0x10 + i * 0x34);
        if (prev <= t && v > t)
            return i;
        prev = v;
    }
    return 0;
}
