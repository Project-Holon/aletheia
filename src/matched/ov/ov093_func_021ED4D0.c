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
 *   func_021F8180  0x021F8180  thumb  ov094
 */
extern int func_021F8180(void);
int BTLV_SCU_IsHpGaugeIdle(void)
{
    if (func_021F8180() == 0)
        return 1;
    return 0;
}
