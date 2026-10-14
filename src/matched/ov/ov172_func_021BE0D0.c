/*
 * function: COMM_TVT_SYS_GetEndRequested
 * address:  0x021BE0D0
 * packet:   pkt_ov172_021BE0D0
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Field getter, u32 at +0x2c.
 */
#include "../include/Obj24134.h"

typedef unsigned long u32;

u32 COMM_TVT_SYS_GetEndRequested(void *p)
{
    return ((struct Obj24134 *)p)->f2C;
}
