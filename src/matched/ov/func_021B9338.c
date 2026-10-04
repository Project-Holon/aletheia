/*
 * function: func_021B9338
 * address:  0x021B9338
 * packet:   pkt_021B9338
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
  * status:   EXACT*
 *
 * symbols:
 *   func_021B9280  0x021B9280  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04891.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int func_021B9280(u8 *a, u32 arg2, u32 arg3, u8 *tbl);

int func_021B9338(u8 *p, u8 *base, u32 arg3, int arg4)
{
    int r = func_021B9280(base, ((struct Obj04891 *)p)->fC, arg3, *(u8 * *)&((struct Obj04891 *)p)->f24);
    int f = ((struct Obj04891 *)p)->f14;

    ((struct Obj04891 *)p)->f18 = r;
    if ((f < 0 ? -f : f) >= r) {
        if (f > 0)
            ((struct Obj04891 *)p)->f14 = r;
        else
            ((struct Obj04891 *)p)->f14 = -r;
    }
    return arg4;
}

