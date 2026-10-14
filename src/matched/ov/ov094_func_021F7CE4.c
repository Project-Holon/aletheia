/*
 * function: BTLV_EFFECT_StartPokeAppearEffect
 * address:  0x021F7CE4
 * packet:   pkt_ov094_021F7CE4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Runs BTLV_EFFECT_StartEffectOnPoke with code 0x23b, then BTLV_EFFECT_SetPokeEffectValue with 0.
 *
 * symbols:
 *   BTLV_EFFECT_StartEffectOnPoke 0x021F7A28 thumb ov094
 *   BTLV_EFFECT_SetPokeEffectValue 0x021F8AE8 thumb ov094
 */
typedef unsigned int   u32;
extern void BTLV_EFFECT_StartEffectOnPoke(int a, u32 b);
extern void BTLV_EFFECT_SetPokeEffectValue(int i, u32 v);

void BTLV_EFFECT_StartPokeAppearEffect(int a)
{
    BTLV_EFFECT_StartEffectOnPoke(a, 0x23b);
    BTLV_EFFECT_SetPokeEffectValue(a, 0);
}
