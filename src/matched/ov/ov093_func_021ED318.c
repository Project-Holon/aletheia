/*
 * unit:     yes
 * function: BTLV_SCU_StartMonWithdraw, BTLV_SCU_IsMonWithdrawDone
 * address:  0x021ED318
 * packet:   pkt_ov093_021ED318
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_EFFECT_GaugeDeleteSlot  0x021F80E4  thumb  ov094
 *   BTLV_EFFECT_DeletePokeSprite  0x021F7F04  thumb  ov094
 *   TCBL_AddTask  0x020311B8  arm
 *   TCBL_GetWork  0x02031290  arm
 *   BTLV_SCU_TaskMonWithdraw  0x021ED384  thumb  ov093
 */
#include "../include/Obj05231.h"
#include "../include/Obj12172.h"
#include "../include/Obj21591.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void BTLV_EFFECT_GaugeDeleteSlot(u32 a);
struct S02030FB4;
extern void BTLV_EFFECT_DeletePokeSprite(int a);
extern void *TCBL_AddTask(u32 a, void *fn, u32 sz, u32 a3);
extern void *TCBL_GetWork(struct S02030FB4 *p);
extern void BTLV_SCU_TaskMonWithdraw(u32 a, u8 *t);

void BTLV_SCU_StartMonWithdraw(char *p, u16 k, u16 a, int flag)
{
    u8 *t;

    if (flag != 0 || a == 0) {
        BTLV_EFFECT_GaugeDeleteSlot(k);
        BTLV_EFFECT_DeletePokeSprite(k);
        return;
    }
    t = TCBL_GetWork(TCBL_AddTask(((struct Obj21591 *)p)->f2C, (void *)BTLV_SCU_TaskMonWithdraw, 0x10, 1));
    ((struct Obj05231 *)t)->f6 = k;
    *(char * *)&((struct Obj05231 *)t)->f0 = p + 0x48 + k * 0xc;
    *(char * *)&((struct Obj05231 *)t)->fC = p + 0x42;
    if (a == 0)
        a = 0x26c;
    ((struct Obj05231 *)t)->f8 = a;
    ((struct Obj05231 *)t)->f4 = 0;
    (**(u8 * *)&((struct Obj05231 *)t)->fC)++;
}

int BTLV_SCU_IsMonWithdrawDone(char *p)
{
    if (((struct Obj12172 *)p)->f42 == 0)
        return 1;
    return 0;
}
