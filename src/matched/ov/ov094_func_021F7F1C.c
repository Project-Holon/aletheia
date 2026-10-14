/*
 * function: BTLV_EFFECT_IsPokeSpriteLoaded
 * address:  0x021F7F1C
 * packet:   pkt_021FD1CC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvEff     0x0220AF20  data
 *   BTLV_MCSS_IsSpriteLoaded  0x021FFD9C  thumb  ov094
 */

#include "../include/G_0220AF20.h"

extern struct G_0220AF20 *gBtlvEff;
extern int BTLV_MCSS_IsSpriteLoaded(char *p, int key);

int BTLV_EFFECT_IsPokeSpriteLoaded(int i)
{
    if (i < 8)
        return BTLV_MCSS_IsSpriteLoaded(*(char **)(((char *)gBtlvEff) + 0x190), i);
    if (*(int *)(((char *)gBtlvEff) + (i - 8) * 4 + 0x1f8) != -1)
        return 1;
    return 0;
}
