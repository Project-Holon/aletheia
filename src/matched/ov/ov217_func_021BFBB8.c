/*
 * function: func_021BFBB8
 * address:  0x021BFBB8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clear the u32 at +0x18.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25953.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BFBB8(void *p)
{
    ((struct Obj25953 *)p)->f18 = 0;
}
