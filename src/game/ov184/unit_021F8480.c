/*
 * file:     unit_021F8480.c
 * unit:     yes
 * function: func_021F8480, func_021F851C, func_021F857C, func_021F85DC, func_021F8624, func_021F8670, func_021F86EC, func_021F88A4, func_021F88E0, func_021F891C
 * address:  0x021F8480
 * region:   ov184
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
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
 *   func_0200A5F8 0x0200A5F8 thumb
 *   func_0200A640 0x0200A640 thumb
 *   BR_UTIL_CreateTask 0x021FD6D8 thumb ov186
 *   BR_UTIL_DeleteTask 0x021FD714 thumb ov186
 *   func_021F89D0 0x021F89D0 thumb ov184
 *   BR_UTIL_DeleteHandles 0x021FD820 thumb ov186
 *   BR_UTIL_DeleteTextWin 0x021FD15C thumb ov186
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_02034A5C 0x02034A5C arm
 *   BR_NET_HandleNetError 0x021FF88C thumb ov186
 *   BR_PROC_SYS_FlushWindows 0x021F9C6C thumb ov186
 *   BR_UTIL_RunTask 0x021FD71C thumb ov186
 *   BR_UTIL_IsTaskIdle 0x021FD72C thumb ov186
 *   BR_UTIL_RunHandles 0x021FD854 thumb ov186
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BR_UTIL_FlushWindow 0x021FD1BC thumb ov186
 *   func_021F3C50 0x021F3C50 thumb ov112
 *   BR_FADE_Start   0x021FE784  thumb
 *   BR_FADE_GetResult   0x021FE7B0  thumb
 *   BR_UTIL_SetTaskStep   0x021FD73C  thumb
 *   func_021FD744   0x021FD744  thumb
 *   BR_PROC_SYS_PopEntry   0x021F9BA0  thumb
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   BR_BTN_HitTestWithSound 0x021FB4B4 thumb ov186
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   BR_UTIL_CreateTextWin 0x021FD12C thumb ov186
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 *   BR_NET_StartRequest 0x021FF54C thumb ov186
 *   BR_NET_IsIdle 0x021FF648 thumb ov186
 *   BR_NET_PollErrorMessage 0x021FF72C thumb ov186
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BR_SIDEBAR_SetVisibleBySpace  0x021FEEC0  thumb  ov186
 *   BR_RES_ApplyBgSet  0x021FBDA4  thumb  ov186
 *   BR_RES_ReleaseUiPalette  0x021FC1F8  thumb  ov186
 *   BR_GRAPHIC_Begin3d  0x021FC610  thumb  ov186
 *   func_021F3AF0  0x021F3AF0  thumb  ov112
 *   func_021F3BF0  0x021F3BF0  thumb  ov112
 *   BR_GRAPHIC_End3d  0x021FC640  thumb  ov186
 *   BR_RES_LoadUiPalette  0x021FC148  thumb  ov186
 *   BR_RES_LoadBgGraphics  0x021FB964  thumb  ov186
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   BR_BTN_CreateFromMessage 0x021FB378 thumb ov186
 */
#include "../../matched/include/Obj02898.h"
#include "../../matched/include/Obj06617.h"
#include "../../matched/include/Obj02233.h"
#include "../../matched/include/Obj04581.h"
#include "../../matched/include/Obj03336.h"
#include "../../matched/include/Obj24698.h"
#include "../../matched/include/Obj24699.h"
#include "../../matched/include/Obj14447.h"
#include "../../matched/include/Obj08318.h"
#include "../../matched/include/Obj05483.h"
#include "../../matched/include/Obj24700.h"
#include "../../matched/include/Obj24701.h"
#include "../../matched/include/Obj00548.h"
#include "../../matched/include/Obj24704.h"
#include "../../matched/include/Obj24705.h"
#include "../../matched/include/Obj24708.h"
#include "../../matched/include/Obj24709.h"
#include "../../matched/include/Obj24710.h"
#include "../../matched/include/Obj24711.h"
#include "../../matched/include/Obj24714.h"
#include "../../matched/include/Obj06618.h"
#include "../../matched/include/Obj08319.h"

struct Obj24810;
struct Obj0203159C;
struct Big;
struct PrintSys;
struct S020315D4;
typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef unsigned char  u8;

typedef struct Cfg {int a,b;} Cfg;

typedef struct Pair {int x,y;} Pair;

typedef struct
{
  u16 x;
  u16 y;
  u16 index;
  unsigned char flag;
  unsigned char pad;
} Config;

extern int func_02034AC4(s32 handle);
extern unsigned BR_PROC_SYS_GetSlotId(struct Obj24810 *p);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,unsigned);
extern u32 PRINTSYS_QUE_Create(void *);
extern u32 BR_GRAPHIC_GetActorUnit(u8 *p);
extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);
extern char *BR_UTIL_CreateHandles(unsigned owner, char *resources, int index, int heap);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200A5F8(void *sys);
extern int func_0200A640(int);
extern int *BR_UTIL_CreateTask(int payload, int callback, u32 heap);
extern void BR_UTIL_DeleteTask(void *p);
extern void func_021F89D0(int *,char *);
extern void BR_UTIL_DeleteHandles(char *);
extern void BR_UTIL_DeleteTextWin(void *,int);
extern void BMP_OAM_DeleteSys(void *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void func_020315D4(struct S020315D4 *);
extern void func_02034A5C(int);
extern int BR_NET_HandleNetError(char *);
extern void BR_PROC_SYS_FlushWindows(char *);
extern void BR_UTIL_RunTask(u8 *p);
extern int BR_UTIL_IsTaskIdle(int *);
extern void BR_UTIL_RunHandles(char *);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void BR_UTIL_FlushWindow(void *p);
extern void func_021F3C50(u8 *p);
extern int BR_FADE_Start(int, int, int, int);
extern int BR_FADE_GetResult(int);
extern int * BR_UTIL_SetTaskStep(int, void *);
extern int func_021FD744(int);
extern void BR_PROC_SYS_PopEntry(int);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int BR_BTN_HitTestWithSound(unsigned int *obj, int x, int y);
extern void BR_UTIL_StartEffect(int,int,int *);
extern void *BR_UTIL_CreateTextWin(int a, void *owner, u16 heap);
extern void BR_UTIL_SetWindowText(char *p, char *q, void *text);
extern void BR_NET_StartRequest(char *p, int kind, const int *values);
extern int BR_NET_IsIdle(char *);
extern int BR_NET_PollErrorMessage(char *,int *);
extern int TOUCHPANEL_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void BR_SIDEBAR_SetVisibleBySpace(char *p, int mode, u32 value);
extern void BR_RES_ApplyBgSet(int a, unsigned mode);
extern void BR_RES_ReleaseUiPalette(int *p, int i);
extern void BR_GRAPHIC_Begin3d(u32 a, u16 b);
extern u8 *func_021F3AF0(u8 *src, u16 heap);
extern void func_021F3BF0(u8 *p);
extern void BR_GRAPHIC_End3d(u32 a, u16 b);
extern void BR_RES_LoadUiPalette(char *p, unsigned i, unsigned heap);
extern void BR_RES_LoadBgGraphics(void *ctx, unsigned kind, unsigned short heap);
extern void BR_RES_LoadSprite(char *, u32, u32);
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern int BR_RES_GetSprite(char *, unsigned, void *);
extern int BR_BTN_CreateFromMessage(Config *, u16, int, int, void *, int, int, int, void *, u16);
int func_021F8480(void *obj,int b,char *q);
int func_021F851C(int obj,int b,char *q,char *p);
int func_021F857C(int a,int b,int c,char *p);
void func_021F85DC(int a, int *state, char *p);
void func_021F8624(int a, int *state, char *p);
void func_021F8670(int a,int b,char *p);
void func_021F86EC(int *task,unsigned *state,char *p);
void func_021F88A4(char *p, char *q);
void func_021F88E0(char *p, char *q);
void func_021F891C(char *p, const char *q);
extern char ov112_id[];




int func_021F8480(void *obj,int b,char *q)
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
    ((struct Obj02898 *)p)->f28=func_0200A640((int)func_0200A5F8((void *)GAME_DATA_GetSaveControl((struct Big *)(((struct Obj06617 *)q)->f18))));
    func_021F88A4(p,q);
    func_021F891C(p,q);
    ((struct Obj02898 *)p)->fC=BR_UTIL_CreateTask((int)p,(int)func_021F85DC,((struct Obj02898 *)p)->f24);
    return 1;
}




int func_021F851C(int obj,int b,char *q,char *p)
{
    int i;
    BR_UTIL_DeleteTask((void *)(((struct Obj02233 *)p)->fC));
    func_021F89D0((int *)p,q);
    func_021F88E0(p,q);
    for (i=0;i<2;i++) BR_UTIL_DeleteHandles(*(char **)(p+i*4+0x14));
    if (((struct Obj02233 *)p)->f10) {
        BR_UTIL_DeleteTextWin(((struct Obj02233 *)p)->f10,((struct Obj04581 *)q)->fC);
        *(int *)&((struct Obj02233 *)p)->f10=0;
    }
    BMP_OAM_DeleteSys((void *)(((struct Obj02233 *)p)->f1C));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj02233 *)p)->f20));
    func_020315D4((struct S020315D4 *)obj);
    func_02034A5C((int)ov112_id);
    return 1;
}




int func_021F857C(int a,int b,int c,char *p)
{
    int i;
    if (BR_NET_HandleNetError(*(char * *)&((struct Obj24698 *)(*(char * *)&((struct Obj03336 *)p)->f30))->f14)==2) {
        BR_PROC_SYS_FlushWindows(*(char * *)&((struct Obj24699 *)(*(char * *)&((struct Obj03336 *)p)->f30))->f10);
        return 1;
    }
    BR_UTIL_RunTask((u8 *)(*(char * *)&((struct Obj03336 *)p)->fC));
    if (BR_UTIL_IsTaskIdle(*(int * *)&((struct Obj03336 *)p)->fC)) return 1;
    for (i=0;i<2;i++) BR_UTIL_RunHandles(*(char **)(p+i*4+20));
    PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj03336 *)p)->f20));
    if (*(char * *)&((struct Obj03336 *)p)->f10) BR_UTIL_FlushWindow(*(char * *)&((struct Obj03336 *)p)->f10);
    if (*(char * *)&((struct Obj03336 *)p)->f0) func_021F3C50((u8 *)(*(char * *)&((struct Obj03336 *)p)->f0));
    return 0;
}





/*
 *   wildcarded because that address lies outside ov184's own 0x5A0-byte
 *   region and no listing labels it -- the only branch image-wide is the
 *   one inside this range.
 *
 * Three-state step over the object at *(p+0x30): submit on 0, poll on 1,
 *   finish through 0x21FD73C on 2.
 */
void func_021F85DC(int a, int *state, char *p)
{
    switch (*state) {
    case 0:
        BR_FADE_Start(*(int *)(((struct Obj14447 *)p)->f30), 4, 3, 0);
        *state = 1;
        break;
    case 1:
        if (BR_FADE_GetResult(*(int *)(((struct Obj14447 *)p)->f30)))
            *state = 2;
        break;
    case 2:
        BR_UTIL_SetTaskStep(a, func_021F8670);
        break;
    }
}





/*
 *   outside ov184's 0x5A0-byte region and no listing labels them, so the
 *   two calls stay wildcarded.
 *
 * Three-state step over the object at *(p+0x30): submit on 0, poll on 1,
 *   release the two child handles on 2.
 */
void func_021F8624(int a, int *state, char *p)
{
    switch (*state) {
    case 0:
        BR_FADE_Start(*(int *)(((struct Obj08318 *)p)->f30), 4, 3, 1);
        *state = 1;
        break;
    case 1:
        if (BR_FADE_GetResult(*(int *)(((struct Obj08318 *)p)->f30)))
            *state = 2;
        break;
    case 2:
        func_021FD744(((struct Obj08318 *)p)->fC);
        BR_PROC_SYS_PopEntry(*(int *)(((struct Obj08318 *)p)->f30 + 0x10));
        break;
    }
}



void func_021F8670(int a,int b,char *p)
{
    int x,y;
    if (TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))) {
        if (BR_BTN_HitTestWithSound((unsigned int *)(((struct Obj05483 *)p)->f4),x,y)) {
            int pair[2];
            pair[0]=x; pair[1]=y;
            BR_UTIL_StartEffect(((struct Obj05483 *)p)->f18,1,pair);
            ((struct Obj24700 *)(*(char * *)&((struct Obj05483 *)p)->f30))->f1C=0;
            BR_UTIL_SetTaskStep((int)((int *)a), (void *)((int)func_021F8624));
        }
        if (BR_BTN_HitTestWithSound((unsigned int *)(((struct Obj05483 *)p)->f8),x,y)) {
            int pair[2];
            pair[0]=x; pair[1]=y;
            BR_UTIL_StartEffect(((struct Obj05483 *)p)->f18,1,pair);
            ((struct Obj24701 *)(*(char * *)&((struct Obj05483 *)p)->f30))->f1C=1;
            BR_UTIL_SetTaskStep((int)((int *)a), (void *)((int)func_021F86EC));
        }
    }
}


void func_021F86EC(int *task,unsigned *state,char *p)
{
    Pair initial;
    Cfg cfg;
    int out,x,y;
    Pair pair;
    switch(*state) {
    case 0:BR_FADE_Start(**(int * *)&((struct Obj00548 *)p)->f30,4,3,1);*state=1;break;
    case 1:if(BR_FADE_GetResult((int)(**(int ** *)&((struct Obj00548 *)p)->f30))) *state=2;break;
    case 2:
        func_021F89D0((int *)p,*(char * *)&((struct Obj00548 *)p)->f30);
        func_021F88E0(p,*(char * *)&((struct Obj00548 *)p)->f30);
        ((struct Obj00548 *)p)->f10=BR_UTIL_CreateTextWin(((struct Obj24704 *)(*(char * *)&((struct Obj00548 *)p)->f30))->fC,(void *)(((struct Obj00548 *)p)->f20),((struct Obj00548 *)p)->f24);
        BR_UTIL_SetWindowText(((struct Obj00548 *)p)->f10,(char *)(((struct Obj24705 *)(*(char * *)&((struct Obj00548 *)p)->f30))->fC),(void *)0x145);
        initial.x=0x80;initial.y=0x60;
        BR_UTIL_StartEffect(((struct Obj00548 *)p)->f14, 4, (int *)&initial);
        *state=3;break;
    case 3:BR_FADE_Start(**(int * *)&((struct Obj00548 *)p)->f30,4,3,0);*state=4;break;
    case 4:if(BR_FADE_GetResult((int)(**(int ** *)&((struct Obj00548 *)p)->f30))) *state=5;break;
    case 5:
        MI_CpuFill8(&cfg,0,8);
        cfg.a=((struct Obj00548 *)p)->f28;
        BR_NET_StartRequest(*(char * *)&((struct Obj24708 *)(*(char * *)&((struct Obj00548 *)p)->f30))->f14,0,(const int *)(&cfg));
        *(int *)&((struct Obj00548 *)p)->f2C=0;
        *state=6;break;
    case 6:
        ((struct Obj00548 *)p)->f2C=((struct Obj00548 *)p)->f2C+1;
        if(BR_NET_IsIdle(*(char * *)&((struct Obj24709 *)(*(char * *)&((struct Obj00548 *)p)->f30))->f14) && ((struct Obj00548 *)p)->f2C>0x60) {
            BR_UTIL_StartEffect(((struct Obj00548 *)p)->f14, 0, (int *)0);*state=7;
        }break;
    case 7:
        if(!BR_NET_PollErrorMessage(*(char * *)&((struct Obj24710 *)(*(char * *)&((struct Obj00548 *)p)->f30))->f14,&out)) *state=9;
        else {BR_UTIL_SetWindowText(((struct Obj00548 *)p)->f10,(char *)(((struct Obj24711 *)(*(char * *)&((struct Obj00548 *)p)->f30))->fC),(void *)out);*state=8;}
        break;
    case 8:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y));pair.x=x;pair.y=y;
            BR_UTIL_StartEffect(((struct Obj00548 *)p)->f18, 1, (int *)&pair);
            GFL_USE_PlaySeDefaultVolume(0x703);*state=9;
        }break;
    case 9:BR_FADE_Start(**(int * *)&((struct Obj00548 *)p)->f30,2,3,1);*state=10;break;
    case 10:if(BR_FADE_GetResult((int)(**(int ** *)&((struct Obj00548 *)p)->f30))) *state=11;break;
    case 11:func_021FD744((int)task);BR_PROC_SYS_PopEntry((int)((unsigned int *)(((struct Obj24714 *)(*(char * *)&((struct Obj00548 *)p)->f30))->f10)));break;
    }
}



void func_021F88A4(char *p, char *q)
{
    if (((struct Obj06618 *)p)->f0 != 0)
        return;
    BR_SIDEBAR_SetVisibleBySpace((char *)(((struct Obj08319 *)q)->f4), 0, 0);
    BR_RES_ApplyBgSet(((struct Obj08319 *)q)->fC, 0);
    BR_RES_ReleaseUiPalette((int *)(((struct Obj08319 *)q)->fC), 0);
    BR_GRAPHIC_Begin3d(((struct Obj08319 *)q)->f8, ((struct Obj06618 *)p)->f24);
    ((struct Obj06618 *)p)->f0 = (unsigned int)func_021F3AF0((u8 *)(((struct Obj06618 *)p)->f28), ((struct Obj06618 *)p)->f24);
}



void func_021F88E0(char *p, char *q)
{
    if (*(u32 *)&((struct Obj02233 *)p)->f0 == 0)
        return;
    func_021F3BF0(((struct Obj02233 *)p)->f0);
    *(u32 *)&((struct Obj02233 *)p)->f0 = 0;
    BR_GRAPHIC_End3d(((struct Obj04581 *)q)->f8, ((struct Obj02233 *)p)->f24);
    BR_RES_LoadUiPalette((char *)(*(u32 *)&((struct Obj04581 *)q)->fC), 0, ((struct Obj02233 *)p)->f24);
    BR_RES_LoadBgGraphics((void *)(*(u32 *)&((struct Obj04581 *)q)->fC), 0, ((struct Obj02233 *)p)->f24);
    BR_SIDEBAR_SetVisibleBySpace((char *)(((struct Obj04581 *)q)->f4), 0, 1);
}


/*
 * tail: 021F89CE..021F89D0 is two zero alignment bytes before matched021F89D0.
 * lever: first types search extracted full-word temporaries and took kind's address;
 * its volatile parameter was removed, and the clean spelling independently matched.
 */
void func_021F891C(char *p, const char *q)
{
  Config cfg;
  int resources[3];
  void *v;
  int v0;
  int v1;
  int i;
  int kind;
  int tmp;
  char **tmp1;
  (void) (&kind);
  if (*((int *) (p + 4)))
    return;
  tmp1 = (char **) (q + 12);
  BR_RES_LoadBgGraphics((void *)(*((u32 *) (q + 12))), 23, *((u16 *) (p + 36)));
  BR_RES_LoadSprite(*tmp1, 6, *((u16 *) (p + 36)));
  v0 = BR_RES_GetFont(*((char **) (q + 12)));
  v1 = BR_RES_GetMsgData(*((char **) (q + 12)));
  MI_CpuFill8(&cfg, 0, 8);
  cfg.y = 168;
  cfg.flag = 1;
  v = (void *)BR_GRAPHIC_GetActorUnit(*((void **) (q + 8)));
  BR_RES_GetSprite(*((char **) (q + 12)), 6, resources);
  for (i = 0; i < 2; i++)
  {
    if (i == 0)
    {
      kind = 4;
      cfg.x = 32;
      cfg.index = 0;
    }
    else
    {
      kind = 43;
      cfg.x = 128;
      cfg.index = 4;
    }
    tmp = *((int *) (p + 28));
    *((int *) ((p + (i * 4)) + 4)) = BR_BTN_CreateFromMessage(&cfg, kind, 96, 1, v, tmp, v0, v1, resources, *((u16 *) (p + 36)));
  }
}
