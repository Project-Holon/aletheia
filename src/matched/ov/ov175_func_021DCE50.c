/*
 * function: WIFIBATTLEMATCH_NET_SetResultC
 * address:  0x021DCE50
 * packet:   pkt_021DCE50
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Two-word setter: stores the caller's word at +0xc and hard-codes 2 at +0x1c.
 */
#include "../include/Obj14353.h"

typedef unsigned long u32;

void WIFIBATTLEMATCH_NET_SetResultC(char *ctx, u32 v, int line)
{
    ((struct Obj14353 *)ctx)->fC = v;
    ((struct Obj14353 *)ctx)->f1C = 2;
}
