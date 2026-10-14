/*
 * function: BTLV_CORE_StartViewEffect
 * address:  0x021EA3B8
 * packet:   pkt_ov093_021EA3B8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   BTLV_EFFECT_StartEffectOnPoke  0x021F7A28  thumb  ov094
 */
#include "../include/Obj21561.h"
typedef unsigned char u8;
typedef unsigned int u32;

extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern void BTLV_EFFECT_StartEffectOnPoke(int a, u32 b);

void BTLV_CORE_StartViewEffect(char *ctx, int a, int b)
{
    if (BTL_CLIENT_IsMainStepActive(*(u8 * *)&((struct Obj21561 *)ctx)->f4) == 0) {
        BTLV_EFFECT_StartEffectOnPoke(a, b);
    }
}
