/*
 * function: func_0215A63C
 * address:  0x0215A63C
 * packet:   pkt_ov010_0215A63C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Address of the block at +0xD4 inside the object at +0x20.
 *
 * symbols:
 *   (none)
 */
#include "../include/Obj00005.h"

typedef unsigned char u8;

u8 *func_0215A63C(u8 *p)
{
    return *(u8 * *)&((struct Obj00005 *)p)->f20 + 0xd4;
}
