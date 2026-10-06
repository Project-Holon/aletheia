/*
 * function: func_021A030C
 * address:  0x021A030C
 * packet:   pkt_ov021_021A030C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204A380  0x0204A380  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04228.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed char    s8;
typedef signed short   s16;
typedef unsigned int   u32;

extern void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3);

void func_021A030C(u8 *p, u32 a)
{
    if (p[0] == 1) {
        ((s8 *)p)[1]--;
        if (((s8 *)p)[1] <= 0) {
            ((struct Obj04228 *)p)->f4 = (unsigned int)func_0204A380((void *)(((struct Obj04228 *)p)->fC), ((struct Obj04228 *)p)->f2, 0, a);
            p[0] = 0;
        }
    }
}
