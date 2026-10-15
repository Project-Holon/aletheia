/*
 * function: BR_CODEIN_StatCreate
 * address: 0x021DE9A0
 * packet: pkt_ov183_021DE9A0
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
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BR_UTIL_CreateHandles 0x021FD760 thumb ov186
 *   BR_UTIL_CreateTask 0x021FD6D8 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_CODEIN_SearchStepText 0x021DF0DC thumb ov183
 *   BR_CODEIN_StatSetup 0x021DEB4C thumb ov183
 */
#include "../include/Obj02229.h"
#include "../include/Obj06605.h"
#include "../include/Obj24581.h"
typedef unsigned short u16;
struct Obj24810;
extern unsigned BR_PROC_SYS_GetSlotId(struct Obj24810 *p);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, unsigned int size, unsigned int heap);
extern void MI_CpuFill8(void *, int, unsigned int);
extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);
typedef unsigned int   u32;
extern u32 PRINTSYS_QUE_Create(void *p);
extern char *BR_UTIL_CreateHandles(unsigned owner, char *resources, int index, int heap);
extern int *BR_UTIL_CreateTask(int payload, int callback, u32 heap);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_CODEIN_SearchStepText(int *p, int *state, char *q);
extern void BR_CODEIN_StatSetup(int *task, int *state, char *p);
int BR_CODEIN_StatCreate(void *a, int b, char *q)
{
    char *p = PROCSYS_AllocProcWork(a, 0x10C, BR_PROC_SYS_GetSlotId(((struct Obj06605 *)q)->f14));
    int i;
    MI_CpuFill8(p, 0, 0x10C);
    *(char * *)&((struct Obj02229 *)p)->f108 = q;
    ((struct Obj02229 *)p)->f18 = BR_PROC_SYS_GetSlotId(((struct Obj06605 *)q)->f14);
    ((struct Obj02229 *)p)->f0 = BMP_OAM_CreateSys(((struct Obj02229 *)p)->f18, ((struct Obj06605 *)q)->fC);
    ((struct Obj02229 *)p)->f14 = (void *)PRINTSYS_QUE_Create((void *)(((struct Obj02229 *)p)->f18));
    for (i = 0; i < 2; i++)
        *(void **)(p + i * 4 + 0x1C) = BR_UTIL_CreateHandles((unsigned int)(((struct Obj06605 *)q)->fC), (char *)(((struct Obj06605 *)q)->f10), i, ((struct Obj02229 *)p)->f18);
    ((struct Obj02229 *)p)->f10 = BR_UTIL_CreateTask((int)p, (int)BR_CODEIN_SearchStepText, ((struct Obj02229 *)p)->f18);
    if (((struct Obj24581 *)(*(char * *)&((struct Obj02229 *)p)->f108))->f4 != 0)
        BR_UTIL_SetTaskStep(((struct Obj02229 *)p)->f10, (int)BR_CODEIN_StatSetup);
    else
        BR_UTIL_SetTaskStep(((struct Obj02229 *)p)->f10, (int)BR_CODEIN_SearchStepText);
    return 1;
}
