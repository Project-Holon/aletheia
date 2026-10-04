/*
 * function: func_0215A660
 * address:  0x0215A660
 * packet:   pkt_ov010_0215A660
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Setter: byte at +0x104 of the object whose pointer sits at +0x20.
 * Unlabelled leaf (leaf of func_021B03E4).
 *
 * symbols:
 *   (none)
 */
#include "../include/Obj18793.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

void func_0215A660(u8 *p, u32 v)
{
    *((u8 *)((struct Obj18793 *)p)->f20 + 0x104) = v;
}
