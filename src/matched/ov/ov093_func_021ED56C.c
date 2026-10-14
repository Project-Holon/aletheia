/*
 * function: BTLV_SCU_StartPosCueEffect
 * address:  0x021ED56C
 * packet:   pkt_ov093_021ED56C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_EFFECT_StartEffectOnPoke  0x021F7A28  thumb  ov094
 */
typedef unsigned int   u32;
extern void BTLV_EFFECT_StartEffectOnPoke(int a, u32 b);
void BTLV_SCU_StartPosCueEffect(int a, int b)
{
    BTLV_EFFECT_StartEffectOnPoke(b, 0x25f);
}
