/*
 * function: BTL_CLIENT_StepChangeBgm
 * address:  0x021D2990
 * packet:   pkt_ov093_021D2990
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_EFFECT_StopLowHpBgm  0x021F878C  thumb  ov094
 */

typedef unsigned int   u32;
void BTLV_EFFECT_StopLowHpBgm(u32 a);

int BTL_CLIENT_StepChangeBgm(int a, int b, int *c)
{
    BTLV_EFFECT_StopLowHpBgm(*c);
    return 1;
}
