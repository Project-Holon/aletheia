/*
 * function: BTLV_CORE_WaitViewEffectEx
 * address:  0x021EA3F8
 * packet:   pkt_ov093_021EA3F8
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

int BTLV_CORE_WaitViewEffectEx(int a)
{
    if (BTLV_EFFECT_IsBusy() == 0) {
        return 1;
    }
    return 0;
}
