/*
 * function: BTLV_EFFECT_GetTrainerType
 * address:  0x021F8740
 * packet:   pkt_ov094_021F8740
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns halfword a of the table at 0x1d4 of the global work block.
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 */
extern char *gBtlvEff;

unsigned short BTLV_EFFECT_GetTrainerType(int a)
{
    return ((unsigned short *)(gBtlvEff + 0x1d4))[a];
}
