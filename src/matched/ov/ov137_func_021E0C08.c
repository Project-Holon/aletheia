/*
 * function: GURU2_MAIN_StartDropEffect
 * address: 0x021E0C08
 * packet: pkt_ov137_021E0C08
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02030DA8 0x02030DA8 arm
 *   GURU2_MAIN_DropEffectTask 0x021E0C70 thumb ov137
 *   gGuru2MainAllocFileName 0x021E22B8 data
 */
#include "../include/Obj06537.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *,int,unsigned);
extern void func_02030DA8(void *,void (*)(void *,void *),void *,int);
struct Node;
extern void GURU2_MAIN_DropEffectTask(struct Node *task, char *p);
extern const char gGuru2MainAllocFileName[];
void GURU2_MAIN_StartDropEffect(char *p,int a,int b,int c,int d,int e,int *q)
{
    int *r;
    q[3]=a;
    q[4]=b;
    q[5]=c;
    q[6]=b;
    q[7]=d<<12;
    q[8]=e<<12;
    q[0]=1;
    q[2]=0;
    r=func_02030734(0x8072,24,0,gGuru2MainAllocFileName,0x130e);
    MI_CpuFill8(r,0,24);
    r[5]=(int)p;
    r[4]=(int)q;
    func_02030DA8(((struct Obj06537 *)p)->fD98,(void (*)(void *, void *))GURU2_MAIN_DropEffectTask,r,0);
}
