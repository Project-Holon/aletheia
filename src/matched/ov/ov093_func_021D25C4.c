/*
 * function: BTL_CLIENT_StepPlayMonAnim
 * address:  0x021D25C4
 * packet:   pkt_ov093_021D25C4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_GetTrainerSlotOfPoke  0x021B8D8C  thumb  ov093
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   BTL_MAIN_CheckSceneOff  0x021B8590  thumb  ov093
 *   func_021EA838  0x021EA838  thumb  ov093
 *   func_021EA850  0x021EA850  thumb  ov093
 */
#include "../include/Obj06241.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_MAIN_GetTrainerSlotOfPoke(void *p, void *a, u32 b);
extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern unsigned int BTL_MAIN_CheckSceneOff(unsigned char *p);
extern void func_021EA838(u32 *p, u32 k);
extern int func_021EA850(u32 *p, u32 k);

int BTL_CLIENT_StepPlayMonAnim(u8 *p, int *st, u32 *c)
{
    int t = BTL_MAIN_GetTrainerSlotOfPoke(((struct Obj06241 *)p)->f0, ((struct Obj06241 *)p)->f4, (u8)(*c));

    switch (*st) {
    case 0:
        if (BTL_CLIENT_IsMainStepActive(p))
            return 1;
        if (!BTL_MAIN_CheckSceneOff(((struct Obj06241 *)p)->f0))
            return 1;
        func_021EA838(((struct Obj06241 *)p)->f54, t);
        (*st)++;
        break;
    case 1:
        if (func_021EA850(((struct Obj06241 *)p)->f54, t))
            return 1;
        break;
    }
    return 0;
}
