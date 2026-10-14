/*
 * function: BTLV_SCU_IsMonExitDone
 * address:  0x021ED2BC
 * packet:   pkt_ov093_021ED2BC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_EFFECT_IsBusy  0x021F7EB4  thumb  ov094
 */
extern int BTLV_EFFECT_IsBusy(void);
int BTLV_SCU_IsMonExitDone(void)
{
    if (BTLV_EFFECT_IsBusy() == 0)
        return 1;
    return 0;
}
