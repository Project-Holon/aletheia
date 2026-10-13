/*
 * unit:     yes
 * function: BTLV_SCU_StartMonFormChange, BTLV_SCU_IsMonFormChangeDone
 * address:  0x021ED590
 * packet:   pkt_ov093_021ED590
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetViewPosOfSlot  0x021B8E70  thumb  ov093
 *   TCBL_AddTask  0x020311B8  arm
 *   TCBL_GetWork  0x02031290  arm
 *   BTLV_SCU_TaskMonFormChange  0x021ED5E8  thumb  ov093
 */
#include "../include/Obj12173.h"
#include "../include/Obj13568.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct S { char *p; u8 k; u8 pad[3]; u32 v; u32 c; u32 a; u8 *cnt; };

extern u8 BTL_MAIN_GetViewPosOfSlot(u8 *p, u32 k);
extern void *TCBL_AddTask(u32 a, void *fn, u32 sz, u32 a3);
struct S02030FB4;
extern void *TCBL_GetWork(struct S02030FB4 *p);
extern void BTLV_SCU_TaskMonFormChange(u32 x, struct S *t);

void BTLV_SCU_StartMonFormChange(char *p, u8 k, u32 a)
{
    struct S *t;

    if (k != 6) {
        t = (struct S *)TCBL_GetWork(TCBL_AddTask(((struct Obj13568 *)p)->f2C, (void *)BTLV_SCU_TaskMonFormChange, 0x18, 1));
        t->p = p;
        t->k = k;
        t->a = a;
        t->v = BTL_MAIN_GetViewPosOfSlot(*(u8 * *)&((struct Obj13568 *)p)->f134, k);
        t->cnt = (u8 *)p + 0x40;
        t->c = 0;
        (*t->cnt)++;
    }
}

int BTLV_SCU_IsMonFormChangeDone(char *p)
{
    if (((struct Obj12173 *)p)->f40 == 0)
        return 1;
    return 0;
}
