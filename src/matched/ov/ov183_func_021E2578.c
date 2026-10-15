/*
 * function: BR_CODEIN_SoclCreate
 * address: 0x021E2578
 * packet: pkt_ov183_021E2578
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_PROC_SYS_GetSlotId 0x021F9B9C thumb ov186
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   BR_UTIL_CreateTask 0x021FD6D8 thumb ov186
 *   BR_CODEIN_SoclStep 0x021E26B8 thumb ov183
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BR_UTIL_CreateHandles 0x021FD760 thumb ov186
 */
#include "../include/Obj03332.h"
#include "../include/Obj06614.h"
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj24810;
extern unsigned BR_PROC_SYS_GetSlotId(struct Obj24810 *p);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,unsigned);
extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);
extern int *BR_UTIL_CreateTask(int payload, int callback, u32 heap);
extern void BR_CODEIN_SoclStep(int *task, int *state, char *p);
extern u32 PRINTSYS_QUE_Create(void *);
extern char *BR_UTIL_CreateHandles(unsigned owner, char *resources, int index, int heap);
int BR_CODEIN_SoclCreate(void *obj,int b,char *q)
{
    char *p;
    int i;
    p=PROCSYS_AllocProcWork(obj,0x54,BR_PROC_SYS_GetSlotId(((struct Obj06614 *)q)->f10));
    MI_CpuFill8(p,0,0x54);
    *(char * *)&((struct Obj03332 *)p)->f3C=q;
    ((struct Obj03332 *)p)->f38=BR_PROC_SYS_GetSlotId(((struct Obj06614 *)q)->f10);
    ((struct Obj03332 *)p)->f0=BMP_OAM_CreateSys(((struct Obj03332 *)p)->f38,((struct Obj06614 *)q)->f4);
    ((struct Obj03332 *)p)->fC=BR_UTIL_CreateTask((int)p,(int)BR_CODEIN_SoclStep,((struct Obj03332 *)p)->f38);
    ((struct Obj03332 *)p)->f4=PRINTSYS_QUE_Create((void *)(unsigned int)((struct Obj03332 *)p)->f38);
    for (i=0;i<2;i++) *(void **)(p+i*4+0x30)=BR_UTIL_CreateHandles((unsigned int)(((struct Obj06614 *)q)->f4),(char *)(((struct Obj06614 *)q)->f8),i,((struct Obj03332 *)p)->f38);
    return 1;
}
