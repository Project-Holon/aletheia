/*
 * function: BTLV_EFFECT_GaugeRequestStop
 * address:  0x021F8168
 * packet:   pkt_ov094_021F8168
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to BTLV_GAUGE_RequestStop with the handle at 0x1a4 of the global work block.
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 *   BTLV_GAUGE_RequestStop 0x022089AC thumb ov094
 */
extern char *gBtlvEff;
extern void BTLV_GAUGE_RequestStop(void *);

void BTLV_EFFECT_GaugeRequestStop(void)
{
    BTLV_GAUGE_RequestStop(*(void **)(gBtlvEff + 0x1a4));
}
