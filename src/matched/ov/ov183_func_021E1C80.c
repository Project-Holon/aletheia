/*
 * function: BR_CODEIN_UploadCreate
 * address: 0x021E1C80
 * packet: pkt_ov183_021E1C80
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_PROC_SYS_GetSlotId 0x021F9B9C thumb ov186
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_UTIL_CreateTask 0x021FD6D8 thumb ov186
 *   BR_CODEIN_UploadStepFadeIn 0x021E1DA8 thumb ov183
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BR_UTIL_CreateTextWin 0x021FD12C thumb ov186
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 *   BR_UTIL_CreateHandles 0x021FD760 thumb ov186
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   d_021E38E0 0x021E38E0 data a4
 */
#include "../include/Obj02232.h"
#include "../include/Obj05482.h"
typedef unsigned short u16;
typedef struct {int a,b;} Pair;
extern const Pair d_021E38E0;
typedef unsigned int   u32;
struct Obj24810;
extern unsigned BR_PROC_SYS_GetSlotId(struct Obj24810 *p);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,int);
extern int *BR_UTIL_CreateTask(int payload, int callback, u32 heap);
extern void BR_CODEIN_UploadStepFadeIn(int,int *,char *);
extern u32 PRINTSYS_QUE_Create(void *p);
extern void *BR_UTIL_CreateTextWin(int a, void *owner, u16 heap);
extern void BR_UTIL_SetWindowText(char *p, char *q, void *text);
extern char *BR_UTIL_CreateHandles(unsigned owner, char *resources, int index, int heap);
extern void BR_UTIL_StartEffect(int,int,Pair *);
int BR_CODEIN_UploadCreate(struct Proc *obj,int unused,char *arg)
{
    char *p;
    int i;
    Pair pair;
    p=PROCSYS_AllocProcWork(obj,32,BR_PROC_SYS_GetSlotId((struct Obj24810 *)(((struct Obj05482 *)arg)->fC)));
    MI_CpuFill8(p,0,32);
    *(char * *)&((struct Obj02232 *)p)->f18=arg;
    ((struct Obj02232 *)p)->f8=BR_PROC_SYS_GetSlotId((struct Obj24810 *)(((struct Obj05482 *)arg)->fC));
    ((struct Obj02232 *)p)->f4=(int)BR_UTIL_CreateTask((int)p,(int)BR_CODEIN_UploadStepFadeIn,((struct Obj02232 *)p)->f8);
    ((struct Obj02232 *)p)->f0=PRINTSYS_QUE_Create((void *)(((struct Obj02232 *)p)->f8));
    ((struct Obj02232 *)p)->fC=(int)BR_UTIL_CreateTextWin(((struct Obj05482 *)arg)->f8,(void *)(((struct Obj02232 *)p)->f0),((struct Obj02232 *)p)->f8);
    BR_UTIL_SetWindowText((char *)(((struct Obj02232 *)p)->fC),(char *)(((struct Obj05482 *)arg)->f8),(void *)111);
    for (i=0;i<2;i++) *(int *)(p+i*4+0x10)=(int)BR_UTIL_CreateHandles(((struct Obj05482 *)arg)->f4,(char *)(((struct Obj05482 *)arg)->f8),i,((struct Obj02232 *)p)->f8);
    pair=d_021E38E0;
    BR_UTIL_StartEffect(((struct Obj02232 *)p)->f10,4,&pair);
    return 1;
}
