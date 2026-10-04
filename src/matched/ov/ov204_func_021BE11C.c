/*
 * function: func_021BE11C
 * address:  0x021BE11C
 * packet:   pkt_021BE11C
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE10C  0x021BE10C  thumb  ov204
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10870.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_021BE10C(u8 *, u32, u32 *);

u32 func_021BE11C(u8 *p)
{
    u32 t = *(u32 *)(((struct Obj10870 *)p)->f4 + 8);

    if (t == 0) {
        t = t + 1;
    }
    func_021BE10C(p, 0, &t);
    return 1;
}

