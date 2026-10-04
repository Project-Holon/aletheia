/*
 * function: func_021C0B8C
 * address:  0x021C0B8C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clear the u32 at +0x20.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25985.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021C0B8C(void *p)
{
    ((struct Obj25985 *)p)->f20 = 0;
}
