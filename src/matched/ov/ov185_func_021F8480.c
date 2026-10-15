/*
 * function: BR_POKESEARCH_CreateWork
 * address: 0x021F8480
 * packet: pkt_ov185_021F8480
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ov112_id 0x00000070 data
 *   func_02034AC4 0x02034AC4 arm
 *   BR_PROC_SYS_GetSlotId 0x021F9B9C thumb ov186
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BR_GRAPHIC_GetActorUnit 0x021FC4DC thumb ov186
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   BR_UTIL_CreateHandles 0x021FD760 thumb ov186
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   func_02040588 0x02040588 arm
 *   BR_POKESEARCH_CreateSearch 0x021F8EFC thumb ov185
 *   BR_UTIL_CreateTask 0x021FD6D8 thumb ov186
 *   BR_POKESEARCH_OpenTask 0x021F8604 thumb ov185
 */
#include "../include/Obj00278.h"
#include "../include/Obj02526.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern char ov112_id[];
typedef signed int     s32;
extern int func_02034AC4(s32 handle);
struct Obj24810;
extern unsigned BR_PROC_SYS_GetSlotId(struct Obj24810 *p);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,unsigned);
extern u32 PRINTSYS_QUE_Create(void *);
typedef unsigned char  u8;
extern u32 BR_GRAPHIC_GetActorUnit(u8 *p);
extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);
extern char *BR_UTIL_CreateHandles(unsigned owner, char *resources, int index, int heap);
extern void BR_RES_LoadSprite(char *base, u32 idx, u32 area);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BR_POKESEARCH_CreateSearch(char *p, int *source);
extern int *BR_UTIL_CreateTask(int payload, int callback, u32 heap);
extern void BR_POKESEARCH_OpenTask(int,int *,char *);
int BR_POKESEARCH_CreateWork(void *obj,int b,char *q)
{
    char *p;
    void *v;
    int i;
    func_02034AC4((int)ov112_id);
    p=PROCSYS_AllocProcWork(obj,88,BR_PROC_SYS_GetSlotId(((struct Obj02526 *)q)->f10));
    MI_CpuFill8(p,0,88);
    *(char * *)&((struct Obj00278 *)p)->f34=q;
    ((struct Obj00278 *)p)->f30=BR_PROC_SYS_GetSlotId(((struct Obj02526 *)q)->f10);
    ((struct Obj00278 *)p)->f2C=PRINTSYS_QUE_Create((void *)(unsigned int)((struct Obj00278 *)p)->f30);
    v=(void *)BR_GRAPHIC_GetActorUnit(((struct Obj02526 *)q)->f8);
    ((struct Obj00278 *)p)->f28=BMP_OAM_CreateSys(((struct Obj00278 *)p)->f30,v);
    for (i=0;i<2;i++) *(void **)(p+i*4+56)=BR_UTIL_CreateHandles((unsigned int)v,(char *)(((struct Obj02526 *)q)->fC),i,((struct Obj00278 *)p)->f30);
    BR_RES_LoadSprite((char *)(((struct Obj02526 *)q)->fC),6,((struct Obj00278 *)p)->f30);
    func_02040588(0,1);
    BR_POKESEARCH_CreateSearch(p,(int *)q);
    ((struct Obj00278 *)p)->f24=BR_UTIL_CreateTask((int)p,(int)BR_POKESEARCH_OpenTask,((struct Obj00278 *)p)->f30);
    return 1;
}
