/*
 * function: func_021BFB0C
 * address:  0x021BFB0C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clear the u32 at +0x1c.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25948.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BFB0C(void *p)
{
    ((struct Obj25948 *)p)->f1C = 0;
}
