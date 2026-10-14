/*
 * function: BTLV_CORE_ProcRotation
 * address:  0x021EA990
 * packet:   pkt_ov093_021EA990
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_GetTaskWork  0x021E9100  thumb  ov093
 *   BTLV_EFFECT_SetPokeSpriteVisible  0x021F84B4  thumb  ov094
 *   func_021EAF00  0x021EAF00  thumb  ov093
 *   BTLV_EFFECT_IsBusy  0x021F7EB4  thumb  ov094
 *   BTLV_SCU_HideMonPair  0x021ED4E4  thumb  ov093
 *   BTLV_SCU_ShowMonPair  0x021ED510  thumb  ov093
 */
#include "../include/Obj13564.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *BTLV_CORE_GetTaskWork(u8 *p, int n);
extern void BTLV_EFFECT_SetPokeSpriteVisible(u32 a, u32 b);
extern void func_021EAF00(u8 *p, int a);
extern int BTLV_EFFECT_IsBusy(void);
extern void BTLV_SCU_HideMonPair(u8 *p, int a, int b);
extern int BTLV_SCU_ShowMonPair(u8 *p, int a, int b);

int BTLV_CORE_ProcRotation(int *st, u8 *b)
{
    u8 *t = BTLV_CORE_GetTaskWork(b, 7);

    switch (*st) {
    case 0:
        BTLV_EFFECT_SetPokeSpriteVisible(t[1], t[2]);
        func_021EAF00(b, 0x57b);
        *st = *st + 1;
        break;
    case 1:
        if (BTLV_EFFECT_IsBusy() == 0) {
            BTLV_SCU_HideMonPair((u8 *)(((struct Obj13564 *)b)->f17C), t[5], t[6]);
            *st = *st + 1;
        }
        break;
    case 2:
        if (BTLV_SCU_ShowMonPair((u8 *)(((struct Obj13564 *)b)->f17C), t[5], t[6]) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}
