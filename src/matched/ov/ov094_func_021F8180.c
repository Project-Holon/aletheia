/*
 * function: BTLV_EFFECT_GaugeIsAnimating
 * address:  0x021F8180
 * packet:   pkt_ov094_021F8180
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to BTLV_GAUGE_IsAnimating with the handle at 0x1a4 of the global work block.
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 *   BTLV_GAUGE_IsAnimating 0x02207C94 thumb ov094
 */
extern char *gBtlvEff;
typedef unsigned char  u8;
extern int BTLV_GAUGE_IsAnimating(u8 *p);

int BTLV_EFFECT_GaugeIsAnimating(void)
{
    return BTLV_GAUGE_IsAnimating(*(void **)(gBtlvEff + 0x1a4));
}
