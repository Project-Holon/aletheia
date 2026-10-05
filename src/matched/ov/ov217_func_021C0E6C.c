/*
 * function: func_021C0E6C
 * address:  0x021C0E6C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Clear the u32 fields at +0, +8 and +0xc.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06714.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021C0E6C(void *p)
{
    ((struct Obj06714 *)p)->f0 = 0;
    ((struct Obj06714 *)p)->f8 = 0;
    ((struct Obj06714 *)p)->fC = 0;
}
