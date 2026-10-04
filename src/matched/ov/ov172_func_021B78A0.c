/*
 * function: func_021B78A0
 * address:  0x021B78A0
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Store the four u16 arguments at +0x14..+0x1a and the word 1 at +0.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06555.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021B78A0(void *p, u16 a, u16 b, u16 c, u16 d)
{
    ((struct Obj06555 *)p)->f0 = 1;
    ((struct Obj06555 *)p)->f14 = a;
    ((struct Obj06555 *)p)->f16 = b;
    ((struct Obj06555 *)p)->f18 = c;
    ((struct Obj06555 *)p)->f1A = d;
}
