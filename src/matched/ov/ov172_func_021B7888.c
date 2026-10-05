/*
 * function: func_021B7888
 * address:  0x021B7888
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Store the four u16 arguments at +0xc..+0x12 and the word 1 at +0.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06554.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021B7888(void *p, u16 a, u16 b, u16 c, u16 d)
{
    ((struct Obj06554 *)p)->f0 = 1;
    ((struct Obj06554 *)p)->fC = a;
    ((struct Obj06554 *)p)->fE = b;
    ((struct Obj06554 *)p)->f10 = c;
    ((struct Obj06554 *)p)->f12 = d;
}
