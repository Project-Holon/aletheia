/*
 * function: BTLV_SCU_IsMonDamageAnimDone
 * address:  0x021ED250
 * packet:   pkt_ov093_021ED250
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_EFFECT_IsBusy  0x021F7EB4  thumb  ov094
 *   BTLV_EFFECT_GaugeIsAnimating  0x021F8180  thumb  ov094
 */
extern int BTLV_EFFECT_IsBusy(void);
extern int BTLV_EFFECT_GaugeIsAnimating(void);
int BTLV_SCU_IsMonDamageAnimDone(void)
{
    int a = BTLV_EFFECT_IsBusy();
    if ((BTLV_EFFECT_GaugeIsAnimating() | a) == 0)
        return 1;
    return 0;
}
