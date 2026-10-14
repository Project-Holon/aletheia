/*
 * function: BTLV_EFFECT_StartPokeEffectId26F
 * address:  0x021F7EA4
 * packet:   pkt_ov094_021F7EA4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub, filed for the caller ov093 BTL_CLIENT_StepPlayEffectOnMonFast (lane S16).
 *
 * symbols:
 *   BTLV_EFFECT_StartEffectOnPoke  0x021F7A28  thumb  ov094
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void BTLV_EFFECT_StartEffectOnPoke(int a, u32 b);

void BTLV_EFFECT_StartPokeEffectId26F(u32 a)
{
    BTLV_EFFECT_StartEffectOnPoke(a, 0x26F);
}
