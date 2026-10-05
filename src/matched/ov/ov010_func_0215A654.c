/*
 * function: func_0215A654
 * address:  0x0215A654
 * packet:   pkt_ov010_0215A654
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Getter: byte at +0x104 of the object whose pointer sits at +0x20.
 * Unlabelled leaf (leaf of func_021B03E4).
 *
 * symbols:
 *   (none)
 */
#include "../include/Obj18792.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

u32 func_0215A654(u8 *p)
{
    return *((u8 *)((struct Obj18792 *)p)->f20 + 0x104);
}
