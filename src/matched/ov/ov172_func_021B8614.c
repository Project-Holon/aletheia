/*
 * function: func_021B8614
 * address:  0x021B8614
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clear the block behind the third argument, limit byte 0xff.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04551.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021B8614(int unused, int unused2, void *p)
{
    ((struct Obj04551 *)p)->fC = 0;
    ((struct Obj04551 *)p)->f0 = 0;
    ((struct Obj04551 *)p)->f4 = 0;
    ((struct Obj04551 *)p)->f8 = 0;
    ((struct Obj04551 *)p)->f10 = 0;
    ((struct Obj04551 *)p)->f14 = 0xff;
    ((struct Obj04551 *)p)->f18 = 0;
}
