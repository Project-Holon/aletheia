/*
 * function: func_021B9850
 * address:  0x021B9850
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, offset 0x08 of the object.  Leaf, no relocations.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25803.h"
typedef unsigned int u32;

u32 func_021B9850(const void *p)
{
    return *(const u32 *)&((struct Obj25803 *)p)->f8;
}
