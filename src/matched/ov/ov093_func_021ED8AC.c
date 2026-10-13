/*
 * function: BTLV_SCU_StartMsgWinFadeOutTask
 * address:  0x021ED8AC
 * packet:   pkt_ov093_021ED8AC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TCBL_AddTask  0x020311B8  arm  arm9
 *   TCBL_GetWork  0x02031290  arm  arm9
 *   BTLV_SCU_TaskMsgWinFadeOut  0x021ED8E8  thumb  ov093
 */
#include "../include/Obj21604.h"
typedef unsigned char u8;
struct Q { u8 *a; int b; u8 *c; };
extern void *TCBL_AddTask(void *, void *, int, int);
struct S02030FB4;
extern void *TCBL_GetWork(struct S02030FB4 *p);
extern void BTLV_SCU_TaskMsgWinFadeOut(int, struct Q *);
void BTLV_SCU_StartMsgWinFadeOutTask(u8 *p)
{
    struct Q *q;
    q = TCBL_GetWork(TCBL_AddTask(((struct Obj21604 *)p)->f2C, (void *)BTLV_SCU_TaskMsgWinFadeOut, 0xc, 1));
    q->a = p;
    q->c = p + 0x40;
    q->b = 0;
    (*q->c)++;
}
