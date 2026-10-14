/*
 * function: COMM_TVT_SYS_SetEndRequested
 * address:  0x021BE0D4
 * packet:   pkt_ov172_021BE0D4
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
 * Field setter, u32 at +0x2c (unlabelled; follows the getter COMM_TVT_SYS_GetEndRequested).
 */
#include "../include/Obj24135.h"

typedef unsigned long u32;

void COMM_TVT_SYS_SetEndRequested(void *p, u32 v)
{
    ((struct Obj24135 *)p)->f2C = v;
}
