/*
 * function: func_021DB2E0
 * address: 0x021DB2E0
 * packet: pkt_ov183_021DB2E0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_PROC_SYS_GetSlotId 0x021F9B9C thumb ov186
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BR_UTIL_CreateHandles 0x021FD760 thumb ov186
 *   BR_UTIL_SetHandlesAnimSeq 0x021FD940 thumb ov186
 *   BR_UTIL_CreateTask 0x021FD6D8 thumb ov186
 *   func_021DB3C4 0x021DB3C4 thumb ov183
 *   func_021DB594 0x021DB594 thumb ov183
 *   func_021DB61C 0x021DB61C thumb ov183
 */
#include "../include/Obj02228.h"
#include "../include/Obj03879.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj24810;
extern unsigned BR_PROC_SYS_GetSlotId(struct Obj24810 *p);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,unsigned);
extern u32 PRINTSYS_QUE_Create(void *p);
extern char *BR_UTIL_CreateHandles(unsigned owner, char *resources, int index, int heap);
extern void BR_UTIL_SetHandlesAnimSeq(u8 *p, u32 value);
extern int *BR_UTIL_CreateTask(int payload, int callback, u32 heap);
extern void func_021DB3C4(int *task, int *state, char *p);
extern void func_021DB594(int *task, int *state, char *p);
extern void func_021DB61C(int *task, int *state, char *p);
int func_021DB2E0(int *task, int unused, char *p)
{
    char *s;
    void *callback;
    s=PROCSYS_AllocProcWork((struct Obj0203159C *)task,0x20,BR_PROC_SYS_GetSlotId(((struct Obj03879 *)p)->f10));
    MI_CpuFill8(s,0,0x20);
    *(char * *)&((struct Obj02228 *)s)->f1C=p;
    ((struct Obj02228 *)s)->f4=BR_PROC_SYS_GetSlotId(((struct Obj03879 *)p)->f10);
    ((struct Obj02228 *)s)->fC=(void *)PRINTSYS_QUE_Create((void *)(((struct Obj02228 *)s)->f4));
    ((struct Obj02228 *)s)->f14=BR_UTIL_CreateHandles(((struct Obj03879 *)p)->f4,(char *)(((struct Obj03879 *)p)->fC),0,((struct Obj02228 *)s)->f4);
    ((struct Obj02228 *)s)->f18=BR_UTIL_CreateHandles(((struct Obj03879 *)p)->f4,(char *)(((struct Obj03879 *)p)->fC),1,((struct Obj02228 *)s)->f4);
    BR_UTIL_SetHandlesAnimSeq(((struct Obj02228 *)s)->f14,1);
    BR_UTIL_SetHandlesAnimSeq(((struct Obj02228 *)s)->f18,1);
    if(((struct Obj03879 *)p)->f0==0) callback=func_021DB3C4;
    else if(((struct Obj03879 *)p)->f0==1) callback=func_021DB594;
    else callback=func_021DB61C;
    ((struct Obj02228 *)s)->f0=BR_UTIL_CreateTask((int)s,(int)callback,((struct Obj02228 *)s)->f4);
    return 1;
}
