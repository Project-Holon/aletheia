/*
 * file:     unit_021F8480.c
 * unit:     yes
 * function: func_021F8480, func_021F8518, func_021F8590, func_021F8604, func_021F8658, func_021F86A4, func_021F86E4, func_021F8790, func_021F88B0, func_021F8950, func_021F8A0C, func_021F8AA8, func_021F8B5C, func_021F8C30, func_021F8D18, func_021F8D5C, func_021F8D98, func_021F8E60, func_021F8E90, func_021F8EE8, func_021F8EFC, func_021F8F58, func_021F8F88, func_021F8FB0, func_021F8FC8, func_021F9008, func_021F9048
 * address:  0x021F8480
 * region:   ov185
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
 *   MI_CpuFill8 0x02082BCC arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_021FC4DC 0x021FC4DC thumb ov186
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_02040588 0x02040588 arm
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021FD714 0x021FD714 thumb ov186
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   func_021FD820 0x021FD820 thumb ov186
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021FF88C 0x021FF88C thumb ov186
 *   func_021F9C6C 0x021F9C6C thumb ov186
 *   func_021FD71C 0x021FD71C thumb ov186
 *   func_021FD72C 0x021FD72C thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_021FC830 0x021FC830 thumb ov186
 *   func_021FD6B0 0x021FD6B0 thumb ov186
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   func_021F3C50 0x021F3C50 thumb ov112
 *   func_021FFE34 0x021FFE34 thumb ov186
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021FD744 0x021FD744 thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_021FFC9C   0x021FFC9C  thumb
 *   func_021FFE90   0x021FFE90  thumb
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021F9048 0x021F9048 thumb ov185
 *   func_021FF54C 0x021FF54C thumb ov186
 *   func_021FF648 0x021FF648 thumb ov186
 *   func_021FF72C 0x021FF72C thumb ov186
 *   func_021FF660 0x021FF660 thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   func_021FEEC0   0x021FEEC0  thumb
 *   func_021FBDA4   0x021FBDA4  thumb
 *   func_021FC1F8   0x021FC1F8  thumb
 *   func_021FC610   0x021FC610  thumb  ov135
 *   func_021F3AF0   0x021F3AF0  thumb
 *   func_021F3BF0 0x021F3BF0 thumb ov112
 *   func_021FC640 0x021FC640 thumb ov186
 *   func_021FC148 0x021FC148 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_02034714 0x02034714 arm
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FD1C4 0x021FD1C4 thumb ov186
 *   func_021FD640  0x021FD640  thumb  ov186
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_021FFBD4 0x021FFBD4 thumb ov186
 *   func_021FFE5C 0x021FFE5C thumb ov186
 *   func_021FFE70 0x021FFE70 thumb ov186
 *   func_021FFC6C 0x021FFC6C thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   func_021FD15C 0x021FD15C thumb ov186
 */
#include "../../matched/include/Obj00278.h"
#include "../../matched/include/Obj02526.h"
#include "../../matched/include/Obj03337.h"
#include "../../matched/include/Obj04583.h"
#include "../../matched/include/Obj01966.h"
#include "../../matched/include/Obj24716.h"
#include "../../matched/include/Obj24717.h"
#include "../../matched/include/Obj10769.h"
#include "../../matched/include/Obj08320.h"
#include "../../matched/include/Obj24722.h"
#include "../../matched/include/Obj10771.h"
#include "../../matched/include/Obj02525.h"
#include "../../matched/include/Obj01276.h"
#include "../../matched/include/Obj24723.h"
#include "../../matched/include/Obj24724.h"
#include "../../matched/include/Obj24725.h"
#include "../../matched/include/Obj24726.h"
#include "../../matched/include/Obj24727.h"
#include "../../matched/include/Obj24728.h"
#include "../../matched/include/Obj03886.h"
#include "../../matched/include/Obj04582.h"
#include "../../matched/include/Obj01568.h"
#include "../../matched/include/Obj01769.h"
#include "../../matched/include/Obj24755.h"
#include "../../matched/include/Obj24756.h"
#include "../../matched/include/Obj06622.h"
#include "../../matched/include/Obj03337.h"
#include "../../matched/include/Obj04583.h"
#include "../../matched/include/Obj03338.h"
#include "../../matched/include/Obj05490.h"
#include "../../matched/include/Obj06623.h"
#include "../../matched/include/Obj10772.h"
#include "../../matched/include/Obj04584.h"
#include "../../matched/include/Obj24759.h"
#include "../../matched/include/Obj06624.h"
#include "../../matched/include/Obj14448.h"
#include "../../matched/include/Obj10773.h"
#include "../../matched/include/Obj24760.h"
#include "../../matched/include/Obj24761.h"
#include "../../matched/include/Obj24762.h"

struct Obj24810;
struct Obj0203159C;
struct PrintSys;
struct S020315D4;
struct Pair;
typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef unsigned char  u8;

typedef struct Cfg {u16 heap;unsigned char rest[6];} Cfg;

typedef struct Pair {int x,y;} Pair;

typedef struct Config {u16 x,y,z; unsigned char a,b;} Config;

typedef struct Triple {int a,b,c;} Triple;

extern int func_02034AC4(s32 handle);
extern unsigned func_021F9B9C(struct Obj24810 *p);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,unsigned);
extern u32 PRINTSYS_QUE_Create(void *);
extern u32 func_021FC4DC(u8 *p);
extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern void func_021FBE54(char *base, u32 idx, u32 area);
extern void func_02040588(unsigned char which, unsigned char enable);
extern int *func_021FD6D8(int payload, int callback, u32 heap);
extern void func_021FD714(void *p);
extern void func_021FC0C8(char *p, unsigned i);
extern void func_021FD820(char *);
extern void BMP_OAM_DeleteSys(void *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_02034A5C(int);
extern int func_021FF88C(char *);
extern void func_021F9C6C(char *);
extern void func_021FD71C(u8 *p);
extern int func_021FD72C(int *);
extern void func_021FD854(char *);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern int func_021FC830(u8 *p);
extern int func_021FD6B0(u8 *p);
extern void func_021FD1BC(void *p);
extern void func_021F3C50(u8 *p);
extern unsigned func_021FFE34(char *p);
extern void func_021FE784(int a, int b, int c, int d);
extern int func_021FE7B0(int *p);
extern int *func_021FD73C(int *p, int v);
extern int func_021FD744(int *a);
extern void func_021F9BA0(unsigned *ctx);
extern void func_021FFC9C(int);
extern int func_021FFE90(int, unsigned short *);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int func_021FB4B4(unsigned int *obj, int x, int y);
extern void func_021FD860(int,int,int *);
extern int func_021F9048(char *p, unsigned x, unsigned y);
extern void func_021FF54C(char *p, int kind, const int *values);
extern int func_021FF648(char *),func_021FF72C(char *,int *),func_021FF660(char *,int,int,int *);
extern void func_021FD170(char *p, char *q, void *text);
extern int TOUCHPANEL_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern void func_021FC754(char *,void *,void *,void *,unsigned short);
extern void func_021FEEC0(int, int, int);
extern void func_021FBDA4(int, int);
extern void func_021FC1F8(int, int);
extern int func_021FC610(u8 *p, int a1);
extern int func_021F3AF0(int, int);
extern void func_021F3BF0(u8 *);
extern void func_021FC640(void *,unsigned);
extern void func_021FC148(char *,unsigned,unsigned);
extern void func_021FB964(void *,unsigned,u16);
extern int func_021FC124(void *,unsigned,void *);
extern void func_02034714(const char *,unsigned,const char *);
extern void *func_021FB378(void *,int,int,int,int,int,int,int,void *,u16);
extern void *func_021FC6A4(u16,unsigned,u16,u16,unsigned char,unsigned char,void *,u16);
extern void func_021FB494(char *p);
extern void func_021FC734(u8 *p);
extern char *func_021FD1C4(void *prof, char *q, void *a2, void *a3, int mode, u16 heap);
extern void func_021FD640(int *p);
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void *func_0200CA1C(void *a);
extern char *func_021FFBD4(void *owner, void *table, int a, int b, int c, int d, int e, unsigned short heap);
extern void func_021FFE5C(char *);
extern void func_021FFE70(char *p);
extern void func_021FFC6C(char *p);
extern void func_020409B4(unsigned);
extern void func_021FD15C(void *,int);
int func_021F8480(void *obj,int b,char *q);
int func_021F8518(int obj,int b,char *q,char *p);
int func_021F8590(int a,int b,int c,char *p);
void func_021F8604(int a,int *state,char *p);
void func_021F8658(int a,int *state,char *p);
void func_021F86A4(int a, int b, char *p);
void func_021F86E4(int a,int b,char *p);
void func_021F8790(int *task,unsigned *state,char *p);
void func_021F88B0(int a,int *state,char *p);
void func_021F8950(int *sys,int *state,char *p);
void func_021F8A0C(int *sys,int *state,char *p);
void func_021F8AA8(int *sys,int *state,char *p);
void func_021F8B5C(int *task,int *state,char *p);
void func_021F8C30(int *task,int *state,char *p);
void func_021F8D18(char *a, int *r4);
void func_021F8D5C(char *p,char *q);
void func_021F8D98(char *p,char *q);
void func_021F8E60(char *p,char *q);
void func_021F8E90(char *p,int *source);
void func_021F8EE8(char *p, int *a1);
void func_021F8EFC(char *p,int *source);
void func_021F8F58(char *p,char *q);
void func_021F8F88(char *p, int *q);
void func_021F8FB0(char *p, char *a1);
int func_021F8FC8(int a, int b, int c);
int func_021F9008(int a, int b, int c);
extern char ov112_id[];











int func_021F8480(void *obj,int b,char *q)
{
    char *p;
    void *v;
    int i;
    func_02034AC4((int)ov112_id);
    p=PROCSYS_AllocProcWork(obj,88,func_021F9B9C(((struct Obj02526 *)q)->f10));
    MI_CpuFill8(p,0,88);
    *(char * *)&((struct Obj00278 *)p)->f34=q;
    ((struct Obj00278 *)p)->f30=func_021F9B9C(((struct Obj02526 *)q)->f10);
    ((struct Obj00278 *)p)->f2C=PRINTSYS_QUE_Create((void *)(unsigned int)((struct Obj00278 *)p)->f30);
    v=(void *)func_021FC4DC(((struct Obj02526 *)q)->f8);
    ((struct Obj00278 *)p)->f28=BMP_OAM_CreateSys(((struct Obj00278 *)p)->f30,v);
    for (i=0;i<2;i++) *(void **)(p+i*4+56)=func_021FD760((unsigned int)v,(char *)(((struct Obj02526 *)q)->fC),i,((struct Obj00278 *)p)->f30);
    func_021FBE54((char *)(((struct Obj02526 *)q)->fC),6,((struct Obj00278 *)p)->f30);
    func_02040588(0,1);
    func_021F8EFC(p,(int *)q);
    ((struct Obj00278 *)p)->f24=func_021FD6D8((int)p,(int)func_021F8604,((struct Obj00278 *)p)->f30);
    return 1;
}











int func_021F8518(int obj,int b,char *q,char *p)
{
    int i;
    func_021F8D5C(p,q);
    func_021F8E60(p,q);
    func_021F8EE8(p,(int *)q);
    func_021F8F58(p,q);
    func_021F8FB0(p,q);
    func_021FD714((void *)(((struct Obj03337 *)p)->f24));
    func_021F8F58(p,q);
    func_021FC0C8((char *)(*(int *)&((struct Obj04583 *)q)->fC),6);
    for (i=0;i<2;i++) func_021FD820(*(char **)(p+i*4+56));
    BMP_OAM_DeleteSys((void *)(((struct Obj03337 *)p)->f28));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj03337 *)p)->f2C));
    func_020315D4((struct S020315D4 *)obj);
    func_02034A5C((int)ov112_id);
    return 1;
}











int func_021F8590(int a,int b,int c,char *p)
{
    int i;
    if (func_021FF88C(*(char * *)&((struct Obj24716 *)(*(char * *)&((struct Obj01966 *)p)->f34))->f14)==2) {
        func_021F9C6C(*(char * *)&((struct Obj24717 *)(*(char * *)&((struct Obj01966 *)p)->f34))->f10);
        return 1;
    }
    func_021FD71C((u8 *)(*(char * *)&((struct Obj01966 *)p)->f24));
    if (func_021FD72C(*(int * *)&((struct Obj01966 *)p)->f24)) return 1;
    for (i=0;i<2;i++) func_021FD854(*(char **)(p+i*4+56));
    PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj01966 *)p)->f2C));
    if (*(char * *)&((struct Obj01966 *)p)->f1C) func_021FC830((u8 *)(*(char * *)&((struct Obj01966 *)p)->f1C));
    if (*(char * *)&((struct Obj01966 *)p)->f10) func_021FD6B0((u8 *)(*(char * *)&((struct Obj01966 *)p)->f10));
    if (*(char * *)&((struct Obj01966 *)p)->f4) func_021FD1BC(*(char * *)&((struct Obj01966 *)p)->f4);
    if (*(char * *)&((struct Obj01966 *)p)->f14) func_021F3C50((u8 *)(*(char * *)&((struct Obj01966 *)p)->f14));
    return 0;
}










void func_021F8604(int a,int *state,char *p)
{
    switch (*state) {
    case 0: if (func_021FFE34((char *)(((struct Obj10769 *)p)->f0))) { func_021FE784(**(int * *)&((struct Obj10769 *)p)->f34,2,3,0); *state=1; } break;
    case 1: if (func_021FE7B0((int *)(**(int * *)&((struct Obj10769 *)p)->f34))) *state=2; break;
    case 2: func_021FD73C((int *)a,(int)func_021F86A4); break;
    }
}










void func_021F8658(int a,int *state,char *p)
{
    switch (*state) {
    case 0: func_021FE784(**(int * *)&((struct Obj08320 *)p)->f34,2,3,1); *state=1; break;
    case 1: if (func_021FE7B0((int *)(**(int * *)&((struct Obj08320 *)p)->f34))) *state=2; break;
    case 2: func_021FD744((int *)(((struct Obj08320 *)p)->f24)); func_021F9BA0((unsigned int *)(((struct Obj24722 *)(*(char * *)&((struct Obj08320 *)p)->f34))->f10)); break;
    }
}











void func_021F86A4(int a, int b, char *p)
{
    unsigned short buf;
    int r;
    func_021FFC9C(((struct Obj10771 *)p)->f0);
    r = func_021FFE90(((struct Obj10771 *)p)->f0, &buf);
    if (r == 0)
        return;
    if (r == 2) {
        ((struct Obj10771 *)p)->f8 = buf;
        func_021FD73C((int *)a, (int)func_021F8AA8);
    } else {
        func_021FD73C((int *)a, (int)func_021F8658);
    }
}








void func_021F86E4(int a,int b,char *p)
{
    int x,y;
    if (TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))) {
        if (func_021FB4B4((unsigned int *)(((struct Obj02525 *)p)->f18),x,y)) {
            int pair[2];
            pair[0]=x; pair[1]=y;
            func_021FD860(((struct Obj02525 *)p)->f3C,1,pair);
            func_021FD73C((int *)a,(int)func_021F8950);
        }
        if (func_021F8FC8((int)p,x,y)) func_021FD73C((int *)a,(int)func_021F8C30);
        if (func_021F9008((int)p,x,y)) {
            int index=((struct Obj02525 *)p)->fC-1;
            if (index<0) ((struct Obj02525 *)p)->fC=((struct Obj02525 *)p)->f54-1;
            else ((struct Obj02525 *)p)->fC=index;
            func_021FD73C((int *)a,(int)func_021F8B5C);
        }
        if (func_021F9048((char *)((int)p),x,y)) {
            ((struct Obj02525 *)p)->fC=((struct Obj02525 *)p)->fC+1;
            ((struct Obj02525 *)p)->fC=(int)((struct Obj02525 *)p)->fC % ((struct Obj02525 *)p)->f54;
            func_021FD73C((int *)a,(int)func_021F8B5C);
        }
    }
}








void func_021F8790(int *task,unsigned *state,char *p)
{
    Cfg cfg;
    int out,x,y;
    Pair pair;
    switch(*state) {
    case 0:
        MI_CpuFill8(&cfg,0,8);
        cfg.heap=((struct Obj01276 *)p)->f8;
        ((struct Obj01276 *)p)->fA=0;
        func_021FF54C(*(char * *)&((struct Obj24723 *)(*(char * *)&((struct Obj01276 *)p)->f34))->f14,1,(const int *)(&cfg));
        *state=1; break;
    case 1:
        ((struct Obj01276 *)p)->fA=((struct Obj01276 *)p)->fA+1;
        if(func_021FF648(*(char * *)&((struct Obj24724 *)(*(char * *)&((struct Obj01276 *)p)->f34))->f14) && ((struct Obj01276 *)p)->fA>0x60) {
            func_021FD860(((struct Obj01276 *)p)->f38, 0, (int *)0);
            *state=2;
        }
        break;
    case 2:
        if(!func_021FF72C(*(char * *)&((struct Obj24725 *)(*(char * *)&((struct Obj01276 *)p)->f34))->f14,&out)) {
            if(func_021FF660(*(char * *)&((struct Obj24726 *)(*(char * *)&((struct Obj01276 *)p)->f34))->f14,(int)(p+0x40),5,(int *)(p+0x54)) && ((struct Obj01276 *)p)->f54) {
                ((struct Obj01276 *)p)->fC=0;
                func_021FD73C(task,(int)func_021F88B0);
                break;
            }
            *state=3;
            func_021FD170(((struct Obj01276 *)p)->f4,((struct Obj24727 *)(*(char * *)&((struct Obj01276 *)p)->f34))->fC,(void *)0x14d);
        }else{
            *state=3;
            func_021FD170(((struct Obj01276 *)p)->f4,((struct Obj24728 *)(*(char * *)&((struct Obj01276 *)p)->f34))->fC,(void *)out);
        }
        break;
    case 3:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y));
            pair.x=x;pair.y=y;
            func_021FD860(((struct Obj01276 *)p)->f3C, 1, (int *)&pair);
            GFL_USE_PlaySeDefaultVolume(0x703);
            func_021FD73C(task,(int)func_021F8A0C);
        }
        break;
    }
}








void func_021F88B0(int a,int *state,char *p)
{
    switch (*state) {
    case 0: func_021FE784(**(int * *)&((struct Obj03886 *)p)->f34,4,3,1); *state=1; break;
    case 1: if (func_021FE7B0((int *)(**(int * *)&((struct Obj03886 *)p)->f34))) *state=2; break;
    case 2: func_021F8FB0(p,*(char * *)&((struct Obj03886 *)p)->f34); func_021F8D18(p,*(int * *)&((struct Obj03886 *)p)->f34); func_021F8D98(p,*(char * *)&((struct Obj03886 *)p)->f34); *state=3; break;
    case 3: func_021FE784(**(int * *)&((struct Obj03886 *)p)->f34,4,3,0); *state=4; break;
    case 4: if (func_021FE7B0((int *)(**(int * *)&((struct Obj03886 *)p)->f34))) *state=5; break;
    case 5: ((struct Obj03886 *)p)->f20=1; func_021FD73C((int *)a,(int)func_021F86E4); break;
    }
}







void func_021F8950(int *sys,int *state,char *p)
{
    switch(*state) {
    case 0:
        if(((struct Obj00278 *)p)->f20) func_021FE784(**(int * *)&((struct Obj00278 *)p)->f34,4,3,1);
        else func_021FE784(**(int * *)&((struct Obj00278 *)p)->f34,2,3,1);
        *state=1; break;
    case 1: if(func_021FE7B0(*(int **)*(int * *)&((struct Obj00278 *)p)->f34)) *state=2; break;
    case 2:
        func_021F8EE8(p,*(int * *)&((struct Obj00278 *)p)->f34);
        func_021F8D5C(p,(char *)(*(int * *)&((struct Obj00278 *)p)->f34));
        func_021F8E60(p,(char *)(*(int * *)&((struct Obj00278 *)p)->f34));
        func_021F8EFC(p,*(int * *)&((struct Obj00278 *)p)->f34);
        *state=3; break;
    case 3:
        if(((struct Obj00278 *)p)->f20) func_021FE784(**(int * *)&((struct Obj00278 *)p)->f34,4,3,0);
        else func_021FE784(**(int * *)&((struct Obj00278 *)p)->f34,2,3,0);
        *state=4; break;
    case 4: if(func_021FE7B0(*(int **)*(int * *)&((struct Obj00278 *)p)->f34)) *state=5; break;
    case 5: func_021FD73C(sys,(int)func_021F86A4); break;
    }
}







void func_021F8A0C(int *sys,int *state,char *p)
{
    switch(*state) {
    case 0: func_021FE784(**(int * *)&((struct Obj00278 *)p)->f34,2,3,1); *state=1; break;
    case 1: if(func_021FE7B0(*(int **)*(int * *)&((struct Obj00278 *)p)->f34)) *state=2; break;
    case 2: func_021F8FB0(p,(char *)(*(int * *)&((struct Obj00278 *)p)->f34)); func_021F8EFC(p,*(int * *)&((struct Obj00278 *)p)->f34); *state=3; break;
    case 3: if(func_021FFE34((char *)(*(int *)&((struct Obj00278 *)p)->f0))) {func_021FE784(**(int * *)&((struct Obj00278 *)p)->f34,2,3,0); *state=4;} break;
    case 4: if(func_021FE7B0(*(int **)*(int * *)&((struct Obj00278 *)p)->f34)) *state=5; break;
    case 5: func_021FD73C(sys,(int)func_021F86A4); break;
    }
}







void func_021F8AA8(int *sys,int *state,char *p)
{
    int pair[2];
    switch(*state) {
    case 0: func_021FE784(**(int * *)&((struct Obj04582 *)p)->f34,2,3,1); *state=1; break;
    case 1: if(func_021FE7B0(*(int **)*(int * *)&((struct Obj04582 *)p)->f34)) *state=2; break;
    case 2:
        func_021F8F58(p,(char *)(*(int * *)&((struct Obj04582 *)p)->f34));
        func_021F8F88(p,*(int * *)&((struct Obj04582 *)p)->f34);
        pair[0]=0x80;pair[1]=0x60;
        func_021FD860((int)(((struct Obj04582 *)p)->f38), 4, pair); *state=3; break;
    case 3: func_021FE784(**(int * *)&((struct Obj04582 *)p)->f34,2,3,0); *state=4; break;
    case 4: if(func_021FE7B0(*(int **)*(int * *)&((struct Obj04582 *)p)->f34)) *state=5; break;
    case 5: func_021FD73C(sys,(int)func_021F8790); break;
    }
}







/*
 * abi: 021F8BBC/021F8BD6 load r1 for func_021F8EE8, retained despite unused callee input.
 */
void func_021F8B5C(int *task,int *state,char *p)
{
    switch (*state) {
    case 0:
        if (((struct Obj01568 *)p)->f20) func_021FE784(**(int * *)&((struct Obj01568 *)p)->f34,1,1,1);
        else func_021FE784(**(int * *)&((struct Obj01568 *)p)->f34,2,1,1);
        *state=1;break;
    case 1: if (func_021FE7B0(*(int **)*(int * *)&((struct Obj01568 *)p)->f34)) *state=2;break;
    case 2:
        if (((struct Obj01568 *)p)->f20) {
            func_021F8EE8(p,*(int * *)&((struct Obj01568 *)p)->f34);
            func_021F8D5C(p,(char *)(*(int * *)&((struct Obj01568 *)p)->f34));
            func_021F8D18(p,*(int * *)&((struct Obj01568 *)p)->f34);
        } else {
            func_021F8EE8(p,*(int * *)&((struct Obj01568 *)p)->f34);
            func_021F8D5C(p,(char *)(*(int * *)&((struct Obj01568 *)p)->f34));
            func_021F8E90(p,*(int * *)&((struct Obj01568 *)p)->f34);
        }
        *state=3;break;
    case 3:
        if (((struct Obj01568 *)p)->f20) func_021FE784(**(int * *)&((struct Obj01568 *)p)->f34,1,1,0);
        else func_021FE784(**(int * *)&((struct Obj01568 *)p)->f34,2,1,0);
        *state=4;break;
    case 4: if (func_021FE7B0(*(int **)*(int * *)&((struct Obj01568 *)p)->f34)) *state=5;break;
    case 5: func_021FD73C(task,(int)func_021F86E4);break;
    }
}





/*
 * abi: 021F8C9E passes r1 to func_021F8EE8 despite its unused second input.
 */
void func_021F8C30(int *task,int *state,char *p)
{
    int flag,a,b,c;
    switch (*state) {
    case 0: func_021FE784(**(int * *)&((struct Obj01769 *)p)->f34,1,1,1);*state=1;break;
    case 1: if(func_021FE7B0(*(int **)*(int * *)&((struct Obj01769 *)p)->f34)) *state=2;break;
    case 2:
        flag=1;
        if(!((struct Obj01769 *)p)->f14) flag=0;
        if(flag) {
            func_021F8D5C(p,(char *)(*(int * *)&((struct Obj01769 *)p)->f34));
            func_021F8E90(p,*(int * *)&((struct Obj01769 *)p)->f34);
        } else {
            func_021F8EE8(p,*(int * *)&((struct Obj01769 *)p)->f34);
            func_021F8D18(p,*(int * *)&((struct Obj01769 *)p)->f34);
        }
        a=func_021FC20C(*(char * *)&((struct Obj24755 *)(*(char * *)&((struct Obj01769 *)p)->f34))->fC);
        b=func_021FC214(*(char * *)&((struct Obj24756 *)(*(char * *)&((struct Obj01769 *)p)->f34))->fC);
        if(flag) {((struct Obj01769 *)p)->f20=0;c=0x72;}
        else {((struct Obj01769 *)p)->f20=1;c=0x71;}
        func_021FC754(*(char * *)&((struct Obj01769 *)p)->f1C,(void *)b,(void *)c,(void *)a,0x3da0);
        *state=3;break;
    case 3: func_021FE784(**(int * *)&((struct Obj01769 *)p)->f34,1,1,0);*state=4;break;
    case 4: if(func_021FE7B0(*(int **)*(int * *)&((struct Obj01769 *)p)->f34)) *state=5;break;
    case 5: func_021FD73C(task,(int)func_021F86E4);break;
    }
}





/*
 * Build the p+0x14 handle once: flush the three sub-resources and start
 *   0x21F3AF0 on the indexed table entry.
 */
void func_021F8D18(char *a, int *r4)
{
    if (((struct Obj06622 *)a)->f14 == 0) {
        func_021FEEC0(r4[1], 0, 0);
        func_021FBDA4(r4[3], 0);
        func_021FC1F8(r4[3], 0);
        func_021FC610((u8 *)r4[2], ((struct Obj06622 *)a)->f30);
        ((struct Obj06622 *)a)->f14 = func_021F3AF0(
            *(int *)(a + 0x40 + ((struct Obj06622 *)a)->fC * 4) + 0x80,
            ((struct Obj06622 *)a)->f30);
    }
}



void func_021F8D5C(char *p,char *q) { if(((struct Obj03337 *)p)->f14){func_021F3BF0(((struct Obj03337 *)p)->f14);((struct Obj03337 *)p)->f14=0;func_021FC640(((struct Obj04583 *)q)->f8,((struct Obj03337 *)p)->f30);func_021FC148(*(char * *)&((struct Obj04583 *)q)->fC,0,((struct Obj03337 *)p)->f30);func_021FB964(((struct Obj04583 *)q)->fC,0,((struct Obj03337 *)p)->f30);func_021FEEC0((int)((char *)(((struct Obj04583 *)q)->f4)), 0, 1);} }



void func_021F8D98(char *p,char *q)
{
    int a,b;
    void *v;
    Config cfg;
    Triple triple;
    if (!*(int *)&((struct Obj03338 *)p)->f1C) {
        a=func_021FC20C(*(char * *)&((struct Obj05490 *)q)->fC);
        b=func_021FC214(*(char * *)&((struct Obj05490 *)q)->fC);
        func_021FC4DC(((struct Obj05490 *)q)->f8);
        MI_CpuFill8(&cfg,0,8);
        cfg.x=0x50;cfg.y=0xa8;cfg.z=0;cfg.a=1;
        v=(void *)func_021FC4DC(((struct Obj05490 *)q)->f8);
        if (!func_021FC124(((struct Obj05490 *)q)->fC,6,&triple)) func_02034714("",0,"");
        ((struct Obj03338 *)p)->f18=func_021FB378(&cfg,4,0x60,1,(int)v,((struct Obj03338 *)p)->f28,a,b,&triple,((struct Obj03338 *)p)->f30);
        ((struct Obj03338 *)p)->f1C=func_021FC6A4(4,8,3,0x10,2,0xe,((struct Obj03338 *)p)->f2C,((struct Obj03338 *)p)->f30);
        func_021FC754(*(char * *)&((struct Obj03338 *)p)->f1C,(void *)b,(void *)0x71,(void *)a,0x3da0);
        func_021FB964((void *)(*(int *)&((struct Obj05490 *)q)->fC),0x16,((struct Obj03338 *)p)->f30);
    }
}



void func_021F8E60(char *p,char *q) { if(((struct Obj06623 *)p)->f1C){func_021FBDA4(*(int *)&((struct Obj04583 *)q)->fC,22);func_021FB494(((struct Obj06623 *)p)->f18);((struct Obj06623 *)p)->f18=0;func_021FC734(((struct Obj06623 *)p)->f1C);((struct Obj06623 *)p)->f1C=0;func_021FBDA4(*(int *)&((struct Obj04583 *)q)->fC,22);} }



/*
 * note: 2026-10-04 (D2-13): body is byte-correct. Callee func_021FD1C4 (ov186, 0x021FD1C4) is a 1148-byte function in pengy's ov186 split with no witness (its listing extent shows 64 bytes, a wrong label gap); the relocation cannot resolve until it is filed. No change possible here.
 * has a seven-case resource loop, nested branches, stack aggregates and
 * many calls; no mechanical whole-body lever. W29 S24 evidence agrees.
 * tu --suggest-split confirms no viable partition; no speculative leaf C.
 * note 2026-10-05 (D4-14): re-run, still MATCH, only func_021FD1C4 (ov186, pengy split) unresolved. No change.
 * note 2026-10-05 (D8-02): re-run, still MATCH. show --region ov186 at 0x021FD1C4 starts with push {r3-r7,lr},
 *   a real 1148-byte function in pengy's ov186 split; outside this lane's write set. No change.
 */
void func_021F8E90(char *p,int *source)
{
    if(*(int *)(p+0x10)==0) {
        int a=func_021FC20C((char *)source[3]);
        int b=func_021FC214((char *)source[3]);
        int c=func_021FC4DC((u8 *)source[2]);
        *(void **)(p+0x10)=func_021FD1C4(((void **)(p+0x40))[*(unsigned short *)(p+0xc)],(char *)source[3],(void *)c,(void *)(*(int *)(p+0x2c)),1,*(unsigned short *)(p+0x30));
        func_021FC754(*(char **)(p+0x1c),(void *)b,(void *)0x72,(void *)a,0x3da0);
    }
}



void func_021F8EE8(char *p, int *a1)
{
    if (((struct Obj10772 *)p)->f10 != 0) {
        func_021FD640((int *)(((struct Obj10772 *)p)->f10));
        ((struct Obj10772 *)p)->f10 = 0;
    }
}


void func_021F8EFC(char *p,int *source)
{
    if(*(int *)&((struct Obj00278 *)p)->f0==0) {
        int c=func_021FC4DC((u8 *)source[2]);
        char *result;
        if(*(int *)&((struct Obj00278 *)p)->f4==0)
            ((struct Obj00278 *)p)->f4=func_021FD12C((int)((void *)source[3]),(void *)(*(int *)&((struct Obj00278 *)p)->f2C),((struct Obj00278 *)p)->f30);
        func_021FD170(((struct Obj00278 *)p)->f4,(void *)source[3],(void *)0x2c);
        result=func_021FFBD4(func_0200CA1C((void *)source[6]),(void *)source[3],c,*(int *)&((struct Obj00278 *)p)->f28,source[0],((struct Obj00278 *)p)->f38,((struct Obj00278 *)p)->f3C,((struct Obj00278 *)p)->f30);
        *(char * *)&((struct Obj00278 *)p)->f0=result;
        func_021FFE5C(result);
    }
}


void func_021F8F58(char *p,char *q) { if(((struct Obj04584 *)p)->f0){func_021FFE70(((struct Obj04584 *)p)->f0);func_021FFC6C(((struct Obj04584 *)p)->f0);((struct Obj04584 *)p)->f0=0;func_020409B4(4);if(((struct Obj04584 *)p)->f4){func_021FD15C(((struct Obj04584 *)p)->f4,((struct Obj24759 *)q)->fC);((struct Obj04584 *)p)->f4=0;}} }


void func_021F8F88(char *p, int *q) { if(!((struct Obj06624 *)p)->f4)((struct Obj06624 *)p)->f4=func_021FD12C((int)(((struct Obj14448 *)q)->fC),(void *)(((struct Obj06624 *)p)->f2C),((struct Obj06624 *)p)->f30);func_021FD170(((struct Obj06624 *)p)->f4,((struct Obj14448 *)q)->fC,(void *)0x146); }



void func_021F8FB0(char *p, char *a1)
{
    if (((struct Obj10773 *)p)->f4 != 0) {
        func_021FD15C((void *)(((struct Obj10773 *)p)->f4), ((struct Obj24760 *)a1)->fC);
        ((struct Obj10773 *)p)->f4 = 0;
    }
}



/*
 * Range-gate the pair then hand them to 0x21FD860 as a two-word record.
 */
int func_021F8FC8(int a, int b, int c)
{
    int ok = ((unsigned)(b - 0x40) <= 0x78) & ((unsigned)(c - 0x10) <= 0x20);
    if (ok) {
        int buf[2];
        buf[0] = b;
        buf[1] = c;
        func_021FD860(((struct Obj24761 *)a)->f3C, 1, buf);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}



int func_021F9008(int a, int b, int c)
{
    int ok = ((unsigned)(b - 0x18) <= 0x28) & ((unsigned)(c - 0x40) <= 0x28);
    if (ok) {
        int buf[2];
        buf[0] = b;
        buf[1] = c;
        func_021FD860(((struct Obj24762 *)a)->f3C, 1, buf);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}

#include "../../matched/include/Obj24763.h"

int func_021F9048(char *p,unsigned x,unsigned y)
{
    int inside=((unsigned)(x-0xb8)<=0x28)&((unsigned)(y-0x40)<=0x28);
    if(inside) {
        int pair[2];
        pair[0]=x;
        pair[1]=y;
        func_021FD860((int)((struct Obj24763 *)p)->f3C,1,pair);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return inside;
}

