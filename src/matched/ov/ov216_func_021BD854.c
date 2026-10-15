/*
 * function: BEACON_DETAIL_GRA_SlideCallback
 * address: 0x021BD854
 * packet: pkt_ov216_021BD854
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BEACON_DETAIL_GRA_MoveActor 0x021BD13C thumb ov216
 *   BEACON_DETAIL_GRA_SetSlotVisible 0x021BD0E4 thumb ov216
 *   TCBL_DeleteTask 0x02031194 arm
 */
#include "../include/Obj02927.h"
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int   u32;
extern void BEACON_DETAIL_GRA_MoveActor(u8 *p, int a);
extern void BEACON_DETAIL_GRA_SetSlotVisible(char *p, u8 index, u32 enable);
struct TcblNode;
extern void TCBL_DeleteTask(struct TcblNode *);
void BEACON_DETAIL_GRA_SlideCallback(struct TcblNode *task, char *p)
{
    u8 count;
    count = ((struct Obj02927 *)p)->f1;
    ((struct Obj02927 *)p)->f1 = count - 1;
    if (count != 0) {
        ((struct Obj02927 *)p)->f4 += ((struct Obj02927 *)p)->f6;
        BEACON_DETAIL_GRA_MoveActor(((struct Obj02927 *)p)->fC, ((struct Obj02927 *)p)->f4);
        return;
    }
    if (((struct Obj02927 *)p)->f4 != 0)
        BEACON_DETAIL_GRA_SetSlotVisible(((struct Obj02927 *)p)->f10, ((struct Obj02927 *)p)->f0, 0);
    --**(int * *)&((struct Obj02927 *)p)->f14;
    TCBL_DeleteTask(task);
}
