/*
 * function: func_02188D40
 * address:  0x02188D40
 * packet:   pkt_02188D40
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Field setter at +0xf0 through a displaced pointer.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17880.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_02188D40(u8 *p, u32 v)
{
    ((struct Obj17880 *)p)->fF0 = v;
}
