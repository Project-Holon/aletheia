/*
 * function: func_021A0170
 * address:  0x021A0170
 * packet:   pkt_ov021_021A0170
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207DC44  0x0207DC44  arm
 *   func_0207DD10  0x0207DD10  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03581.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void func_0207DC44(int enable, int fogMode, int fogSlope, int fogOffset);
extern void func_0207DD10(u8 *);

static inline void SetFogColor(u16 color, int alpha)
{
    *(volatile u32 *)0x04000358 = (u32)(color | (alpha << 16));
}

void func_021A0170(u8 *p, u32 a1, u32 a2, u32 a3)
{
    if (((struct Obj03581 *)p)->f40) {
        func_0207DC44(p[0], p[1], p[2], ((struct Obj03581 *)p)->f4);
        SetFogColor(((struct Obj03581 *)p)->f8, p[3]);
        func_0207DD10(p + 0xc);
        ((struct Obj03581 *)p)->f40 = 0;
    }
}
