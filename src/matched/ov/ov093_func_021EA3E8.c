/*
 * function: BTLV_CORE_StartViewEffectEx
 * address:  0x021EA3E8
 * packet:   pkt_ov093_021EA3E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_EFFECT_StartEffectBetweenPokes  0x021F7AAC  thumb  ov094
 */
typedef unsigned int u32;

extern void BTLV_EFFECT_StartEffectBetweenPokes(int a, int b, u32 c);

void BTLV_CORE_StartViewEffectEx(void *ctx, int a, int b, u32 c)
{
    BTLV_EFFECT_StartEffectBetweenPokes(a, b, c);
}
