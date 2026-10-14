/*
 * function: BTLV_SCU_IsHpGaugeIdle
 * address:  0x021ED4D0
 * packet:   pkt_ov093_021ED4D0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_EFFECT_GaugeIsAnimating  0x021F8180  thumb  ov094
 */
extern int BTLV_EFFECT_GaugeIsAnimating(void);
int BTLV_SCU_IsHpGaugeIdle(void)
{
    if (BTLV_EFFECT_GaugeIsAnimating() == 0)
        return 1;
    return 0;
}
