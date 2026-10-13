/*
 * function: BTL_CLIENT_StepPlayMonEffect262
 * address:  0x021D23B8
 * packet:   pkt_ov093_021D23B8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_GetTrainerSlotOfPoke  0x021B8D8C  thumb  ov093
 *   BTL_MAIN_GetViewPosOfSlot  0x021B8E70  thumb  ov093
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   BTL_MAIN_CheckSceneOff  0x021B8590  thumb  ov093
 *   BTLV_CORE_StartViewEffect262  0x021EA7C8  thumb  ov093
 *   BTLV_CORE_WaitViewEffectDone  0x021EA7E8  thumb  ov093
 */
#include "../include/Obj05206.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_MAIN_GetTrainerSlotOfPoke(void *p, void *a, u32 b);
extern u8 BTL_MAIN_GetViewPosOfSlot(u8 *p, u32 k);
extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern unsigned int BTL_MAIN_CheckSceneOff(unsigned char *p);
extern void BTLV_CORE_StartViewEffect262(void *ctx, int a);
extern int BTLV_CORE_WaitViewEffectDone(void *w, int v);

int BTL_CLIENT_StepPlayMonEffect262(u8 *p, int *st, u32 *c)
{
    u32 t = BTL_MAIN_GetViewPosOfSlot(((struct Obj05206 *)p)->f0, BTL_MAIN_GetTrainerSlotOfPoke(((struct Obj05206 *)p)->f0, ((struct Obj05206 *)p)->f4, (u8)(*c)));

    switch (*st) {
    case 0:
        if (BTL_CLIENT_IsMainStepActive(p))
            return 1;
        if (!BTL_MAIN_CheckSceneOff(((struct Obj05206 *)p)->f0))
            return 1;
        BTLV_CORE_StartViewEffect262(((struct Obj05206 *)p)->f54, t);
        (*st)++;
        break;
    case 1:
        if (BTLV_CORE_WaitViewEffectDone(((struct Obj05206 *)p)->f54, t))
            return 1;
        break;
    }
    return 0;
}
