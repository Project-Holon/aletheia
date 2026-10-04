/*
 * function: func_0215A6AC
 * address:  0x0215A6AC
 * packet:   pkt_0215A6AC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Getter: word at +0x108 of the object whose pointer sits at +0x20.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17664.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
u32 func_0215A6AC(u8 *p)
{
return *(u32 *)((u8 *)((struct Obj17664 *)p)->f20 + 0x108);
}
