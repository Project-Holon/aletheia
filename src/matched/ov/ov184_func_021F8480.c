/*
 * function: BR_DOWNLOAD_Create
 * address: 0x021F8480
 * packet: pkt_ov184_021F8480
 * region: ov184
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
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   MUSICAL_SAVE_GetFromSave 0x0200A5F8 thumb
 *   MUSICAL_SAVE_NoOp 0x0200A640 thumb
 *   BR_DOWNLOAD_Begin3d 0x021F88A4 thumb ov184
 *   BR_DOWNLOAD_CreateButtons 0x021F891C thumb ov184
 *   BR_UTIL_CreateTask 0x021FD6D8 thumb ov186
 *   BR_DOWNLOAD_StepFadeIn 0x021F85DC thumb ov184
 */
#include "../include/Obj02898.h"
#include "../include/Obj06617.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int     s32;
extern int func_02034AC4(s32 handle);
extern char ov112_id[];
struct Obj24810;
extern unsigned BR_PROC_SYS_GetSlotId(struct Obj24810 *p);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,unsigned);
extern u32 PRINTSYS_QUE_Create(void *);
typedef unsigned char  u8;
struct Big;
extern u32 BR_GRAPHIC_GetActorUnit(u8 *p);
extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);
extern char *BR_UTIL_CreateHandles(unsigned owner, char *resources, int index, int heap);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MUSICAL_SAVE_GetFromSave(void *sys);
extern int MUSICAL_SAVE_NoOp(int);
extern void BR_DOWNLOAD_Begin3d(char *,char *);
extern void BR_DOWNLOAD_CreateButtons(char *p, const char *q);
extern int *BR_UTIL_CreateTask(int payload, int callback, u32 heap);
extern void BR_DOWNLOAD_StepFadeIn(int,int *,char *);
int BR_DOWNLOAD_Create(void *obj,int b,char *q)
{
    char *p;
    void *v;
    int i;
    func_02034AC4((int)ov112_id);
    p=PROCSYS_AllocProcWork(obj,0x34,BR_PROC_SYS_GetSlotId(((struct Obj06617 *)q)->f10));
    MI_CpuFill8(p,0,0x34);
    ((struct Obj02898 *)p)->f24=BR_PROC_SYS_GetSlotId(((struct Obj06617 *)q)->f10);
    *(char * *)&((struct Obj02898 *)p)->f30=q;
    ((struct Obj02898 *)p)->f20=PRINTSYS_QUE_Create((void *)(unsigned int)((struct Obj02898 *)p)->f24);
    v=(void *)BR_GRAPHIC_GetActorUnit(((struct Obj06617 *)q)->f8);
    ((struct Obj02898 *)p)->f1C=BMP_OAM_CreateSys(((struct Obj02898 *)p)->f24,v);
    for (i=0;i<2;i++) *(void **)(p+i*4+0x14)=BR_UTIL_CreateHandles((unsigned int)v,(char *)(((struct Obj06617 *)q)->fC),i,((struct Obj02898 *)p)->f24);
    ((struct Obj02898 *)p)->f28=MUSICAL_SAVE_NoOp((int)MUSICAL_SAVE_GetFromSave((void *)GAME_DATA_GetSaveControl((struct Big *)(((struct Obj06617 *)q)->f18))));
    BR_DOWNLOAD_Begin3d(p,q);
    BR_DOWNLOAD_CreateButtons(p,q);
    ((struct Obj02898 *)p)->fC=BR_UTIL_CreateTask((int)p,(int)BR_DOWNLOAD_StepFadeIn,((struct Obj02898 *)p)->f24);
    return 1;
}
