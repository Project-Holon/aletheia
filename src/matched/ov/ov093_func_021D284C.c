/*
 * function: BTL_CLIENT_StepPlayEffectOnMonFast
 * address:  0x021D284C
 * packet:   pkt_ov093_021D284C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_GetViewPosOfSlot  0x021B8E70  thumb  ov093
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   BTLV_EFFECT_SetSeSuppressed  0x021F88BC  thumb  ov094
 *   BTLV_EFFECT_StartPokeEffectId26F  0x021F7EA4  thumb  ov094
 *   BTLV_EFFECT_IsBusy  0x021F7EB4  thumb  ov094
 */
#include "../include/Obj21158.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u8 BTL_MAIN_GetViewPosOfSlot(u8 *p, u32 k);
extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern void BTLV_EFFECT_SetSeSuppressed(int v);
extern void BTLV_EFFECT_StartPokeEffectId26F(u32 v);
extern int BTLV_EFFECT_IsBusy(void);

int BTL_CLIENT_StepPlayEffectOnMonFast(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0: {
        u32 t = BTL_MAIN_GetViewPosOfSlot(((struct Obj21158 *)p)->f0, (u8)(*c));
        if (BTL_CLIENT_IsMainStepActive(p))
            BTLV_EFFECT_SetSeSuppressed(1);
        BTLV_EFFECT_StartPokeEffectId26F(t);
        (*st)++;
        break;
    }
    case 1:
        if (!BTLV_EFFECT_IsBusy()) {
            if (BTL_CLIENT_IsMainStepActive(p))
                BTLV_EFFECT_SetSeSuppressed(0);
            return 1;
        }
        break;
    }
    return 0;
}
