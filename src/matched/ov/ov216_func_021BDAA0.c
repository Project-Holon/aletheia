/*
 * function: func_021BDAA0
 * address: 0x021BDAA0
 * packet: pkt_ov216_021BDAA0
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BEACON_DETAIL_GRA_PrintWaitTask 0x021BDAD8 thumb ov216
 */
#include "../include/Obj25797.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Tcbl; struct TcblNode; struct S02030FB4;
typedef void (*TcblFunc)(struct TcblNode *,void *);
typedef struct Work{int arg;u8 *owner;int *counter;} Work;
extern struct TcblNode *TCBL_AddTask(struct Tcbl *,TcblFunc,u32,u32);
extern void *TCBL_GetWork(struct S02030FB4 *);
extern void MI_CpuFill8(void *,u32,u32);
extern void BEACON_DETAIL_GRA_PrintWaitTask(int,int **);
void func_021BDAA0(u8 *p,int arg,int *counter)
{
    Work *work;
    work=TCBL_GetWork((struct S02030FB4 *)TCBL_AddTask(*(struct Tcbl * *)&((struct Obj25797 *)p)->f18,(TcblFunc)BEACON_DETAIL_GRA_PrintWaitTask,12,0));
    MI_CpuFill8(work,0,12);
    work->owner=p;
    work->arg=arg;
    if(counter!=0){work->counter=counter;++*counter;}
}
