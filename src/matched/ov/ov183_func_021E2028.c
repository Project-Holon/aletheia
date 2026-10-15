/*
 * function: func_021E2028
 * address: 0x021E2028
 * packet: pkt_ov183_021E2028
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E39B4 0x021E39B4 data a4
 *   func_02034714 0x02034714 arm
 *   BR_PROC_SYS_GetSlotId 0x021F9B9C thumb ov186
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_UTIL_CreateTask 0x021FD6D8 thumb ov186
 *   func_021E214C 0x021E214C thumb ov183
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_021E23C8 0x021E23C8 thumb ov183
 *   BR_UTIL_CreateHandles 0x021FD760 thumb ov186
 */
#include "../include/Obj01567.h"
#include "../include/Obj04580.h"
typedef unsigned short u16;
extern char d_021E39B4[];
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
struct Obj24810;
extern unsigned BR_PROC_SYS_GetSlotId(struct Obj24810 *p);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,int);
extern int *BR_UTIL_CreateTask(int payload, int callback, u32 heap);
extern void func_021E214C(int *task, int *state, char *p);
extern u32 PRINTSYS_QUE_Create(void *p);
extern void func_021E23C8(char *,char *);
extern char *BR_UTIL_CreateHandles(unsigned owner, char *resources, int index, int heap);
int func_021E2028(struct Obj0203159C *obj,int unused,char *arg)
{
    char *p;
    int i;
    if (*(int *)&((struct Obj01567 *)arg)->f0>=4) func_02034714(d_021E39B4,0,d_021E39B4);
    p=PROCSYS_AllocProcWork(obj,40,BR_PROC_SYS_GetSlotId((struct Obj24810 *)(((struct Obj01567 *)arg)->f10)));
    MI_CpuFill8(p,0,40);
    *(char * *)&((struct Obj04580 *)p)->f20=arg;
    ((struct Obj04580 *)p)->f1C=BR_PROC_SYS_GetSlotId((struct Obj24810 *)(((struct Obj01567 *)arg)->f10));
    ((struct Obj04580 *)p)->f8=(int)BR_UTIL_CreateTask((int)p,(int)func_021E214C,((struct Obj04580 *)p)->f1C);
    ((struct Obj04580 *)p)->f0=PRINTSYS_QUE_Create((void *)(((struct Obj04580 *)p)->f1C));
    func_021E23C8(p,arg);
    for (i=0;i<2;i++) *(int *)(p+i*4+0x14)=(int)BR_UTIL_CreateHandles(((struct Obj01567 *)arg)->f8,(char *)(*(int *)&((struct Obj01567 *)arg)->fC),i,((struct Obj04580 *)p)->f1C);
    return 1;
}
