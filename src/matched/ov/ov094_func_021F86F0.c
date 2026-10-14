/*
 * function: BTLV_EFFECT_GetClact
 * address:  0x021F86F0
 * packet:   pkt_ov094_021F86F0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the word at 0x1a0 of the global work block.
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 */
extern char *gBtlvEff;

int BTLV_EFFECT_GetClact(void)
{
    return *(int *)(gBtlvEff + 0x1a0);
}
