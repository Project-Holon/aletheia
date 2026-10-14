/*
 * function: BTLV_SCU_TaskMonWithdraw
 * address:  0x021ED384
 * packet:   pkt_ov093_021ED384
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_EFFECT_StartEffectOnPoke  0x021F7A28  thumb  ov094
 *   BTLV_EFFECT_IsBusy  0x021F7EB4  thumb  ov094
 *   BTLV_EFFECT_GaugeDeleteSlot  0x021F80E4  thumb  ov094
 *   BTLV_EFFECT_DeletePokeSprite  0x021F7F04  thumb  ov094
 *   TCBL_DeleteTask  0x02031194  arm
 */
#include "../include/Obj03709.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void BTLV_EFFECT_StartEffectOnPoke(int a, u32 b);
extern int BTLV_EFFECT_IsBusy(void);
extern void BTLV_EFFECT_GaugeDeleteSlot(u32 a);
extern void BTLV_EFFECT_DeletePokeSprite(int a);
struct TcblNode;
extern void TCBL_DeleteTask(struct TcblNode *n);

void BTLV_SCU_TaskMonWithdraw(u32 a, u8 *t)
{
    switch (((struct Obj03709 *)t)->f4) {
    case 0:
        BTLV_EFFECT_StartEffectOnPoke(((struct Obj03709 *)t)->f6, ((struct Obj03709 *)t)->f8);
        (((struct Obj03709 *)t)->f4)++;
        break;
    case 1:
        if (BTLV_EFFECT_IsBusy() == 0) {
            BTLV_EFFECT_GaugeDeleteSlot(((struct Obj03709 *)t)->f6);
            BTLV_EFFECT_DeletePokeSprite(((struct Obj03709 *)t)->f6);
            (((struct Obj03709 *)t)->f4)++;
        }
        break;
    case 2:
        (**(u8 * *)&((struct Obj03709 *)t)->fC)--;
        TCBL_DeleteTask((struct TcblNode *)a);
        break;
    }
}
