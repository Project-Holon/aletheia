/*
 * function: BTLV_EFFECT_GetPokeSlot
 * address:  0x021F84D0
 * packet:   pkt_ov094_021F84D0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns slot a-8 of the table at 0x1f8 of the global work block.
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 */
extern char *gBtlvEff;

int BTLV_EFFECT_GetPokeSlot(int a)
{
    return ((int *)(gBtlvEff + 0x1f8))[a - 8];
}
