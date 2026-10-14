/*
 * function: BTLV_SCU_TaskMonFormChange
 * address:  0x021ED5E8
 * packet:   pkt_ov093_021ED5E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SIDE_GetPokeAtPos  0x021B98AC  thumb  ov093
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   BTLV_EFFECT_StartHitTask  0x021F7D80  thumb  ov094
 *   BTLV_EFFECT_ResetPokeSprite  0x021F7E38  thumb  ov094
 *   BTLV_EFFECT_GaugeDeleteSlot  0x021F80E4  thumb  ov094
 *   BTLV_EFFECT_IsBusy  0x021F7EB4  thumb  ov094
 *   BTLV_EFFECT_GaugeInitSlotFromBattlePoke  0x021F803C  thumb  ov094
 *   TCBL_DeleteTask  0x02031194  arm
 */
#include "../include/Obj21597.h"
#include "../include/Obj21598.h"
#include "../include/Obj21599.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct S { char *w; u8 k; u8 pad[3]; u32 v; u32 c; u32 a; u8 *cnt; };

extern u8 *BTL_SIDE_GetPokeAtPos(char *const *q, u8 b);
extern void *BTL_POKEPARAM_GetMon(void *m);
extern void BTLV_EFFECT_StartHitTask(void *a, int b);
extern void BTLV_EFFECT_ResetPokeSprite(void *a, int b);
extern void BTLV_EFFECT_GaugeDeleteSlot(u32 a);
extern int BTLV_EFFECT_IsBusy(void);
extern void BTLV_EFFECT_GaugeInitSlotFromBattlePoke(u32 a, void *m, u32 c);
struct TcblNode;
extern void TCBL_DeleteTask(struct TcblNode *n);

void BTLV_SCU_TaskMonFormChange(u32 x, struct S *t)
{
    void *r;

    switch (t->c) {
    case 0:
        r = BTL_POKEPARAM_GetMon(BTL_SIDE_GetPokeAtPos(*(char *const * *)&((struct Obj21597 *)(t->w))->f138, t->k));
        if (t->a == 0)
            BTLV_EFFECT_StartHitTask(r, t->v);
        else
            BTLV_EFFECT_ResetPokeSprite(r, t->v);
        BTLV_EFFECT_GaugeDeleteSlot(t->v);
        t->c++;
        break;
    case 1:
        if (BTLV_EFFECT_IsBusy() == 0) {
            BTLV_EFFECT_GaugeInitSlotFromBattlePoke(((struct Obj21598 *)(t->w))->f134,
                          BTL_SIDE_GetPokeAtPos(*(char *const * *)&((struct Obj21599 *)(t->w))->f138, t->k), t->v);
            (*t->cnt)--;
            TCBL_DeleteTask((struct TcblNode *)x);
        }
        break;
    }
}
