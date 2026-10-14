/*
 * function: BTLV_CORE_StartViewEffect262
 * address:  0x021EA7C8
 * packet:   pkt_ov093_021EA7C8
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

void BTLV_CORE_StartViewEffect262(void *ctx, int a)
{
    BTLV_EFFECT_StartEffectOnPoke(a, 0x262);
}
