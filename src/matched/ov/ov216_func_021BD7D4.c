/*
 * function: BEACON_DETAIL_GRA_AddSlideTask
 * address: 0x021BD7D4
 * packet: pkt_ov216_021BD7D4
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: u8 direction puts the r3 home first; caller 021BD948 supplies ldrb direction in r3.
 * symbols:
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BEACON_DETAIL_GRA_SlideCallback 0x021BD854 thumb ov216
 *   BEACON_DETAIL_GRA_MoveActor 0x021BD13C thumb ov216
 *   BEACON_DETAIL_GRA_SetSlotVisible 0x021BD0E4 thumb ov216
 */
#include "../include/Obj00051.h"
#include "../include/Obj02553.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
struct Tcbl;
struct TcblNode;
struct S02030FB4;
extern struct TcblNode *TCBL_AddTask(struct Tcbl *, void (*)(struct TcblNode *, void *), u32, u32);
extern void *TCBL_GetWork(struct S02030FB4 *);
extern void MI_CpuFill8(void *, int, int);
extern void BEACON_DETAIL_GRA_SlideCallback(struct TcblNode *, char *);
extern void BEACON_DETAIL_GRA_MoveActor(u8 *p, int a);
extern void BEACON_DETAIL_GRA_SetSlotVisible(char *p, u8 index, u32 enable);
void BEACON_DETAIL_GRA_AddSlideTask(char *owner, u8 index, int position, u8 direction, int *counter)
{
    char *work;
    work = TCBL_GetWork((struct S02030FB4 *)TCBL_AddTask(*(struct Tcbl * *)&((struct Obj00051 *)owner)->f18, (void (*)(struct TcblNode *, void *))BEACON_DETAIL_GRA_SlideCallback, 24, 0));
    MI_CpuFill8(work, 0, 24);
    *(char * *)&((struct Obj02553 *)work)->fC = owner + 0x15c + index * 128;
    ((struct Obj02553 *)work)->f0 = index;
    ((struct Obj02553 *)work)->f4 = (1 - position) * -192;
    if (direction == 0)
        ((struct Obj02553 *)work)->f6 -= 8;
    else
        ((struct Obj02553 *)work)->f6 += 8;
    ((struct Obj02553 *)work)->f1 = 24;
    BEACON_DETAIL_GRA_MoveActor(((struct Obj02553 *)work)->fC, ((struct Obj02553 *)work)->f4);
    if (position != 1)
        BEACON_DETAIL_GRA_SetSlotVisible(owner, ((struct Obj02553 *)work)->f0, 1);
    *(char * *)&((struct Obj02553 *)work)->f10 = owner;
    *(int * *)&((struct Obj02553 *)work)->f14 = counter;
    ++*counter;
}
