/*
 * function: func_021B985C
 * address:  0x021B985C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reset the object: marker u16 at +0, value at +4, six u32 fields zeroed.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01438.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021B985C(void *p, u32 value)
{
    ((struct Obj01438 *)p)->f0 = 1;
    ((struct Obj01438 *)p)->f4 = value;
    ((struct Obj01438 *)p)->f8 = 0;
    ((struct Obj01438 *)p)->fC = 0;
    ((struct Obj01438 *)p)->f10 = 0;
    ((struct Obj01438 *)p)->f14 = 0;
    ((struct Obj01438 *)p)->f18 = 0;
    ((struct Obj01438 *)p)->f1C = 0;
}
