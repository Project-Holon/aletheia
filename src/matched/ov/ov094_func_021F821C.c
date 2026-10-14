/*
 * function: BTLV_EFFECT_GaugeGetSlotHealthInfo
 * address:  0x021F821C
 * packet:   pkt_ov094_021F821C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Forwards three arguments to BTLV_GAUGE_GetSlotHealthInfo with the handle at 0x1a4 of the global work block.
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 *   BTLV_GAUGE_GetSlotHealthInfo 0x02208958 thumb ov094
 */
extern char *gBtlvEff;
extern void BTLV_GAUGE_GetSlotHealthInfo(void *, int, int, int);

void BTLV_EFFECT_GaugeGetSlotHealthInfo(int a, int b, int c)
{
    BTLV_GAUGE_GetSlotHealthInfo(*(void **)(gBtlvEff + 0x1a4), a, b, c);
}
