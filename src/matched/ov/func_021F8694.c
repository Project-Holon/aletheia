/*
 * function: BTLV_EFFECT_GetMcss
 * address:  0x021F8694
 * packet:   pkt_021FD1CC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data
 */

#include "../include/G_0220AF20.h"

extern struct G_0220AF20 *gBtlvEff;

int BTLV_EFFECT_GetMcss(void)
{
    return *(int *)((char *)((void *)gBtlvEff) + 0x190);
}
