/*
 * function: BEACON_DETAIL_GRA_AddTimerTaskEx
 * address: 0x021BD6FC
 * packet: pkt_ov216_021BD6FC
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * region evidence: ov067 labels 021B64A8; its filed/full body reads the supplied object in r0 and enable in r1.
 * symbols:
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BEACON_DETAIL_GRA_TimerCallback 0x021BD768 thumb ov216
 *   TOUCHBAR_SetAllButtonsEnabled 0x021B64A8 thumb ov067
 */
#include "../include/Obj10949.h"
#include "../include/Obj14720.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Tcbl;
struct TcblNode;
struct S02030FB4;
extern struct TcblNode *TCBL_AddTask(struct Tcbl *, void (*)(struct TcblNode *, void *), u32, u32);
extern void *TCBL_GetWork(struct S02030FB4 *);
extern void MI_CpuFill8(void *, int, int);
extern void BEACON_DETAIL_GRA_TimerCallback(struct TcblNode *, void *);
extern void TOUCHBAR_SetAllButtonsEnabled(u8 *, u32);
void BEACON_DETAIL_GRA_AddTimerTaskEx(char *owner, int *counter)
{
    char *work;
    work = TCBL_GetWork((struct S02030FB4 *)TCBL_AddTask(*(struct Tcbl * *)&((struct Obj14720 *)owner)->f18, BEACON_DETAIL_GRA_TimerCallback, 16, 0));
    MI_CpuFill8(work, 0, 16);
    *(char * *)&((struct Obj10949 *)work)->f8 = owner;
    ((struct Obj10949 *)work)->f1 = 150;
    TOUCHBAR_SetAllButtonsEnabled(*(u8 * *)&((struct Obj14720 *)owner)->f124, 0);
    *(int * *)&((struct Obj10949 *)work)->fC = counter;
    ++*counter;
}
