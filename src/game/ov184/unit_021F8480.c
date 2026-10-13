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
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201C440 0x0201C440 thumb
 *   func_021FC4DC 0x021FC4DC thumb ov186
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   func_021FD760 0x021FD760 thumb ov186
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_0200A5F8 0x0200A5F8 thumb
 *   func_0200A640 0x0200A640 thumb
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021FD714 0x021FD714 thumb ov186
 *   func_021F89D0 0x021F89D0 thumb ov184
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021FF88C 0x021FF88C thumb ov186
 *   func_021F9C6C 0x021F9C6C thumb ov186
 *   func_021FD71C 0x021FD71C thumb ov186
 *   func_021FD72C 0x021FD72C thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   func_021F3C50 0x021F3C50 thumb ov112
 *   func_021FE784   0x021FE784  thumb
 *   func_021FE7B0   0x021FE7B0  thumb
 *   func_021FD73C   0x021FD73C  thumb
 *   func_021FD744   0x021FD744  thumb
 *   func_021F9BA0   0x021F9BA0  thumb
 *   func_02035D20 0x02035D20 arm
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FF54C 0x021FF54C thumb ov186
 *   func_021FF648 0x021FF648 thumb ov186
 *   func_021FF72C 0x021FF72C thumb ov186
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021FEEC0  0x021FEEC0  thumb  ov186
 *   func_021FBDA4  0x021FBDA4  thumb  ov186
 *   func_021FC1F8  0x021FC1F8  thumb  ov186
 *   func_021FC610  0x021FC610  thumb  ov186
 *   func_021F3AF0  0x021F3AF0  thumb  ov112
 *   func_021F3BF0  0x021F3BF0  thumb  ov112
 *   func_021FC640  0x021FC640  thumb  ov186
 *   func_021FC148  0x021FC148  thumb  ov186
 *   func_021FB964  0x021FB964  thumb  ov186
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
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
extern unsigned func_021F9B9C(struct Obj24810 *p);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,unsigned);
extern u32 func_0201C440(void *);
extern u32 func_021FC4DC(u8 *p);
extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200A5F8(void *sys);
extern int func_0200A640(int);
extern int *func_021FD6D8(int payload, int callback, u32 heap);
extern void func_021FD714(void *p);
extern void func_021F89D0(int *,char *);
extern void func_021FD820(char *);
extern void func_021FD15C(void *,int);
extern void BMP_OAM_DeleteSys(void *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_020315D4(struct S020315D4 *);
extern void func_02034A5C(int);
extern int func_021FF88C(char *);
extern void func_021F9C6C(char *);
extern void func_021FD71C(u8 *p);
extern int func_021FD72C(int *);
extern void func_021FD854(char *);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void func_021FD1BC(void *p);
extern void func_021F3C50(u8 *p);
extern int func_021FE784(int, int, int, int);
extern int func_021FE7B0(int);
extern int * func_021FD73C(int, void *);
extern int func_021FD744(int);
extern void func_021F9BA0(int);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021FB4B4(unsigned int *obj, int x, int y);
extern void func_021FD860(int,int,int *);
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void func_021FD170(char *p, char *q, void *text);
extern void func_021FF54C(char *p, int kind, const int *values);
extern int func_021FF648(char *);
extern int func_021FF72C(char *,int *);
extern int TOUCHPANEL_GetTrg(void);
extern void func_020061E4(u32 a);
extern void func_021FEEC0(char *p, int mode, u32 value);
extern void func_021FBDA4(int a, unsigned mode);
extern void func_021FC1F8(int *p, int i);
extern void func_021FC610(u32 a, u16 b);
extern u8 *func_021F3AF0(u8 *src, u16 heap);
extern void func_021F3BF0(u8 *p);
extern void func_021FC640(u32 a, u16 b);
extern void func_021FC148(char *p, unsigned i, unsigned heap);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern void func_021FBE54(char *, u32, u32);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern int func_021FC124(char *, unsigned, void *);
extern int func_021FB378(Config *, u16, int, int, void *, int, int, int, void *, u16);
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
    p=PROCSYS_AllocProcWork(obj,0x34,func_021F9B9C(((struct Obj06617 *)q)->f10));
    func_02082BCC(p,0,0x34);
    ((struct Obj02898 *)p)->f24=func_021F9B9C(((struct Obj06617 *)q)->f10);
    *(char * *)&((struct Obj02898 *)p)->f30=q;
    ((struct Obj02898 *)p)->f20=func_0201C440((void *)(unsigned int)((struct Obj02898 *)p)->f24);
    v=(void *)func_021FC4DC(((struct Obj06617 *)q)->f8);
    ((struct Obj02898 *)p)->f1C=BMP_OAM_CreateSys(((struct Obj02898 *)p)->f24,v);
    for (i=0;i<2;i++) *(void **)(p+i*4+0x14)=func_021FD760((unsigned int)v,(char *)(((struct Obj06617 *)q)->fC),i,((struct Obj02898 *)p)->f24);
    ((struct Obj02898 *)p)->f28=func_0200A640((int)func_0200A5F8((void *)GAME_DATA_GetSaveControl((struct Big *)(((struct Obj06617 *)q)->f18))));
    func_021F88A4(p,q);
    func_021F891C(p,q);
    ((struct Obj02898 *)p)->fC=func_021FD6D8((int)p,(int)func_021F85DC,((struct Obj02898 *)p)->f24);
    return 1;
}




int func_021F851C(int obj,int b,char *q,char *p)
{
    int i;
    func_021FD714((void *)(((struct Obj02233 *)p)->fC));
    func_021F89D0((int *)p,q);
    func_021F88E0(p,q);
    for (i=0;i<2;i++) func_021FD820(*(char **)(p+i*4+0x14));
    if (((struct Obj02233 *)p)->f10) {
        func_021FD15C(((struct Obj02233 *)p)->f10,((struct Obj04581 *)q)->fC);
        *(int *)&((struct Obj02233 *)p)->f10=0;
    }
    BMP_OAM_DeleteSys((void *)(((struct Obj02233 *)p)->f1C));
    func_0201C4C0((struct PrintSys *)(((struct Obj02233 *)p)->f20));
    func_020315D4((struct S020315D4 *)obj);
    func_02034A5C((int)ov112_id);
    return 1;
}




int func_021F857C(int a,int b,int c,char *p)
{
    int i;
    if (func_021FF88C(*(char * *)&((struct Obj24698 *)(*(char * *)&((struct Obj03336 *)p)->f30))->f14)==2) {
        func_021F9C6C(*(char * *)&((struct Obj24699 *)(*(char * *)&((struct Obj03336 *)p)->f30))->f10);
        return 1;
    }
    func_021FD71C((u8 *)(*(char * *)&((struct Obj03336 *)p)->fC));
    if (func_021FD72C(*(int * *)&((struct Obj03336 *)p)->fC)) return 1;
    for (i=0;i<2;i++) func_021FD854(*(char **)(p+i*4+20));
    PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj03336 *)p)->f20));
    if (*(char * *)&((struct Obj03336 *)p)->f10) func_021FD1BC(*(char * *)&((struct Obj03336 *)p)->f10);
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
        func_021FE784(*(int *)(((struct Obj14447 *)p)->f30), 4, 3, 0);
        *state = 1;
        break;
    case 1:
        if (func_021FE7B0(*(int *)(((struct Obj14447 *)p)->f30)))
            *state = 2;
        break;
    case 2:
        func_021FD73C(a, func_021F8670);
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
        func_021FE784(*(int *)(((struct Obj08318 *)p)->f30), 4, 3, 1);
        *state = 1;
        break;
    case 1:
        if (func_021FE7B0(*(int *)(((struct Obj08318 *)p)->f30)))
            *state = 2;
        break;
    case 2:
        func_021FD744(((struct Obj08318 *)p)->fC);
        func_021F9BA0(*(int *)(((struct Obj08318 *)p)->f30 + 0x10));
        break;
    }
}



void func_021F8670(int a,int b,char *p)
{
    int x,y;
    if (func_02035D20((u32 *)(&x),(u32 *)(&y))) {
        if (func_021FB4B4((unsigned int *)(((struct Obj05483 *)p)->f4),x,y)) {
            int pair[2];
            pair[0]=x; pair[1]=y;
            func_021FD860(((struct Obj05483 *)p)->f18,1,pair);
            ((struct Obj24700 *)(*(char * *)&((struct Obj05483 *)p)->f30))->f1C=0;
            func_021FD73C((int)((int *)a), (void *)((int)func_021F8624));
        }
        if (func_021FB4B4((unsigned int *)(((struct Obj05483 *)p)->f8),x,y)) {
            int pair[2];
            pair[0]=x; pair[1]=y;
            func_021FD860(((struct Obj05483 *)p)->f18,1,pair);
            ((struct Obj24701 *)(*(char * *)&((struct Obj05483 *)p)->f30))->f1C=1;
            func_021FD73C((int)((int *)a), (void *)((int)func_021F86EC));
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
    case 0:func_021FE784(**(int * *)&((struct Obj00548 *)p)->f30,4,3,1);*state=1;break;
    case 1:if(func_021FE7B0((int)(**(int ** *)&((struct Obj00548 *)p)->f30))) *state=2;break;
    case 2:
        func_021F89D0((int *)p,*(char * *)&((struct Obj00548 *)p)->f30);
        func_021F88E0(p,*(char * *)&((struct Obj00548 *)p)->f30);
        ((struct Obj00548 *)p)->f10=func_021FD12C(((struct Obj24704 *)(*(char * *)&((struct Obj00548 *)p)->f30))->fC,(void *)(((struct Obj00548 *)p)->f20),((struct Obj00548 *)p)->f24);
        func_021FD170(((struct Obj00548 *)p)->f10,(char *)(((struct Obj24705 *)(*(char * *)&((struct Obj00548 *)p)->f30))->fC),(void *)0x145);
        initial.x=0x80;initial.y=0x60;
        func_021FD860(((struct Obj00548 *)p)->f14, 4, (int *)&initial);
        *state=3;break;
    case 3:func_021FE784(**(int * *)&((struct Obj00548 *)p)->f30,4,3,0);*state=4;break;
    case 4:if(func_021FE7B0((int)(**(int ** *)&((struct Obj00548 *)p)->f30))) *state=5;break;
    case 5:
        func_02082BCC(&cfg,0,8);
        cfg.a=((struct Obj00548 *)p)->f28;
        func_021FF54C(*(char * *)&((struct Obj24708 *)(*(char * *)&((struct Obj00548 *)p)->f30))->f14,0,(const int *)(&cfg));
        *(int *)&((struct Obj00548 *)p)->f2C=0;
        *state=6;break;
    case 6:
        ((struct Obj00548 *)p)->f2C=((struct Obj00548 *)p)->f2C+1;
        if(func_021FF648(*(char * *)&((struct Obj24709 *)(*(char * *)&((struct Obj00548 *)p)->f30))->f14) && ((struct Obj00548 *)p)->f2C>0x60) {
            func_021FD860(((struct Obj00548 *)p)->f14, 0, (int *)0);*state=7;
        }break;
    case 7:
        if(!func_021FF72C(*(char * *)&((struct Obj24710 *)(*(char * *)&((struct Obj00548 *)p)->f30))->f14,&out)) *state=9;
        else {func_021FD170(((struct Obj00548 *)p)->f10,(char *)(((struct Obj24711 *)(*(char * *)&((struct Obj00548 *)p)->f30))->fC),(void *)out);*state=8;}
        break;
    case 8:
        if(TOUCHPANEL_GetTrg()) {
            func_02035D20((u32 *)(&x),(u32 *)(&y));pair.x=x;pair.y=y;
            func_021FD860(((struct Obj00548 *)p)->f18, 1, (int *)&pair);
            func_020061E4(0x703);*state=9;
        }break;
    case 9:func_021FE784(**(int * *)&((struct Obj00548 *)p)->f30,2,3,1);*state=10;break;
    case 10:if(func_021FE7B0((int)(**(int ** *)&((struct Obj00548 *)p)->f30))) *state=11;break;
    case 11:func_021FD744((int)task);func_021F9BA0((int)((unsigned int *)(((struct Obj24714 *)(*(char * *)&((struct Obj00548 *)p)->f30))->f10)));break;
    }
}



void func_021F88A4(char *p, char *q)
{
    if (((struct Obj06618 *)p)->f0 != 0)
        return;
    func_021FEEC0((char *)(((struct Obj08319 *)q)->f4), 0, 0);
    func_021FBDA4(((struct Obj08319 *)q)->fC, 0);
    func_021FC1F8((int *)(((struct Obj08319 *)q)->fC), 0);
    func_021FC610(((struct Obj08319 *)q)->f8, ((struct Obj06618 *)p)->f24);
    ((struct Obj06618 *)p)->f0 = (unsigned int)func_021F3AF0((u8 *)(((struct Obj06618 *)p)->f28), ((struct Obj06618 *)p)->f24);
}



void func_021F88E0(char *p, char *q)
{
    if (*(u32 *)&((struct Obj02233 *)p)->f0 == 0)
        return;
    func_021F3BF0(((struct Obj02233 *)p)->f0);
    *(u32 *)&((struct Obj02233 *)p)->f0 = 0;
    func_021FC640(((struct Obj04581 *)q)->f8, ((struct Obj02233 *)p)->f24);
    func_021FC148((char *)(*(u32 *)&((struct Obj04581 *)q)->fC), 0, ((struct Obj02233 *)p)->f24);
    func_021FB964((void *)(*(u32 *)&((struct Obj04581 *)q)->fC), 0, ((struct Obj02233 *)p)->f24);
    func_021FEEC0((char *)(((struct Obj04581 *)q)->f4), 0, 1);
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
  func_021FB964((void *)(*((u32 *) (q + 12))), 23, *((u16 *) (p + 36)));
  func_021FBE54(*tmp1, 6, *((u16 *) (p + 36)));
  v0 = func_021FC20C(*((char **) (q + 12)));
  v1 = func_021FC214(*((char **) (q + 12)));
  func_02082BCC(&cfg, 0, 8);
  cfg.y = 168;
  cfg.flag = 1;
  v = (void *)func_021FC4DC(*((void **) (q + 8)));
  func_021FC124(*((char **) (q + 12)), 6, resources);
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
    *((int *) ((p + (i * 4)) + 4)) = func_021FB378(&cfg, kind, 96, 1, v, tmp, v0, v1, resources, *((u16 *) (p + 36)));
  }
}
