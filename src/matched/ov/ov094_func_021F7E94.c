/*
 * function: BTLV_EFFECT_StartPokeEffectId26E
 * address:  0x021F7E94
 * packet:   pkt_ov094_021F7E94
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Thumb tail call through r3 with a constant second argument. Labelled in wave D8.
 *
 * symbols:
 *   BTLV_EFFECT_StartEffectOnPoke  0x021F7A28  thumb ov094
 */

typedef unsigned int u32;
extern void BTLV_EFFECT_StartEffectOnPoke(int a, u32 b);

void BTLV_EFFECT_StartPokeEffectId26E(int a)
{
    BTLV_EFFECT_StartEffectOnPoke(a, 0x26E);
}
