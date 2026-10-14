/*
 * function: BTLV_EFFECT_SetPokeSpriteVisible
 * address:  0x021F84B4
 * packet:   pkt_ov094_021F84B4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, filed as the blocker of ov093 callers (lane S15).
 *
 * symbols:
 *   gBtlvEff     0x0220AF20  data   ov094
 *   BTLV_MCSS_SwapSprites  0x021FF7B0  thumb  ov094
 */

typedef unsigned int u32;

extern char *gBtlvEff;
extern void BTLV_MCSS_SwapSprites(u32 obj, u32 a, u32 b);

void BTLV_EFFECT_SetPokeSpriteVisible(u32 a, u32 b)
{
    BTLV_MCSS_SwapSprites(*(u32 *)(gBtlvEff + 0x190), a, b);
}
