/*
 * function: func_021C4224
 * address:  0x021C4224
 * packet:   pkt_ov127_021C4224
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf of ov099 func_021B989C's callee func_021C5858 (a forwarder to here).
 *
 * symbols:
 *   CLACT_GetActorDrawPriority  0x0204B838  arm
 */
#include "../include/Obj23015.h"

typedef unsigned char u8;

extern int CLACT_GetActorDrawPriority(int a0);

int func_021C4224(u8 *p)
{
    return CLACT_GetActorDrawPriority((int)(((struct Obj23015 *)p)->f4));
}
