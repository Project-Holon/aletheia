/*
 * function: func_021B8658
 * address:  0x021B8658
 * packet:   pkt_021B8658
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04134.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_021B8658(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f)
{
    ((struct Obj04134 *)p)->f0 = 1;
    ((struct Obj04134 *)p)->f4 = a;
    ((struct Obj04134 *)p)->f14 = d;
    ((struct Obj04134 *)p)->f10 = e;
    ((struct Obj04134 *)p)->f20 = b;
    ((struct Obj04134 *)p)->fC = c;
    ((struct Obj04134 *)p)->f18 = f;
}
