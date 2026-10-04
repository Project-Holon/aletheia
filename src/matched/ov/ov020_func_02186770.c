/*
 * function: func_02186770
 * address:  0x02186770
 * packet:   pkt_02186770
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Test: is bit 0 of the byte at +3 set.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19460.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
int func_02186770(u8 *p)
{
return (((struct Obj19460 *)p)->f3 & 1) != 0;
}
