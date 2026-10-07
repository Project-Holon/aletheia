/*
 * file:     br_codein_p01.c
 * unit:     yes
 * function: func_021DB2E0, func_021DB36C, func_021DB394, func_021DB3C4, func_021DB594, func_021DB61C, func_021DB690, func_021DB698, func_021DB740, func_021DB770, func_021DB924, func_021DB940
 * address:  0x021DB2E0
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201C440 0x0201C440 thumb
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021FD940 0x021FD940 thumb ov186
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_021FD714 0x021FD714 thumb ov186
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_021FD71C 0x021FD71C thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   func_021FD72C 0x021FD72C thumb ov186
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FD938 0x021FD938 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   func_021FE794 0x021FE794 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FEE24 0x021FEE24 thumb ov186
 *   func_021F9BF4 0x021F9BF4 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021FC830 0x021FC830 thumb ov186
 *   func_020061E4 0x020061E4 thumb
 *   func_02035C60 0x02035C60 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021FEE74 0x021FEE74 thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_021FEE9C 0x021FEE9C thumb ov186
 *   func_021FEE4C 0x021FEE4C thumb ov186
 *   func_021FD744 0x021FD744 thumb ov186
 *   func_021FC1F8 0x021FC1F8 thumb ov186
 *   func_021FC148 0x021FC148 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021F9CB8 0x021F9CB8 thumb ov186
 *   func_021FE840 0x021FE840 thumb ov186
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_021F9F48 0x021F9F48 thumb ov186
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FA018 0x021FA018 thumb ov186
 *   func_021F9FE8 0x021F9FE8 thumb ov186
 *   func_021FA004 0x021FA004 thumb ov186
 *   func_021FA01C 0x021FA01C thumb ov186
 *   func_021FC238 0x021FC238 thumb ov186
 *   func_021FC230 0x021FC230 thumb ov186
 *   func_021FC224 0x021FC224 thumb ov186
 *   func_021FE7F4 0x021FE7F4 thumb ov186
 *   func_02035D20 0x02035D20 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021E3280 0x021E3280 data a4
 *   func_021FC240  0x021FC240  thumb  ov186
 *   func_021DBFB0 0x021DBFB0 thumb ov183
 *   func_021DC4FC 0x021DC4FC thumb ov183
 *   func_021DBC68 0x021DBC68 thumb ov183
 *   func_02025538 0x02025538 thumb
 *   func_0200B928 0x0200B928 thumb
 *   func_0200B910 0x0200B910 thumb
 *   func_0200B98C 0x0200B98C thumb
 */
#include "../../matched/include/Obj02228.h"
#include "../../matched/include/Obj03879.h"
#include "../../matched/include/Obj08308.h"
#include "../../matched/include/Obj06595.h"
#include "../../matched/include/Obj00630.h"
#include "../../matched/include/Obj24519.h"
#include "../../matched/include/Obj24520.h"
#include "../../matched/include/Obj24521.h"
#include "../../matched/include/Obj24522.h"
#include "../../matched/include/Obj24523.h"
#include "../../matched/include/Obj24524.h"
#include "../../matched/include/Obj24525.h"
#include "../../matched/include/Obj24526.h"
#include "../../matched/include/Obj24527.h"
#include "../../matched/include/Obj24528.h"
#include "../../matched/include/Obj24529.h"
#include "../../matched/include/Obj24530.h"
#include "../../matched/include/Obj05470.h"
#include "../../matched/include/Obj24531.h"
#include "../../matched/include/Obj24532.h"
#include "../../matched/include/Obj24533.h"
#include "../../matched/include/Obj24534.h"
#include "../../matched/include/Obj06597.h"
#include "../../matched/include/Obj24535.h"
#include "../../matched/include/Obj24536.h"
#include "../../matched/include/Obj24537.h"
#include "../../matched/include/Obj24538.h"
#include "../../matched/include/Obj24539.h"
#include "../../matched/include/Obj01072.h"
#include "../../matched/include/Obj02517.h"
#include "../../matched/include/Obj10727.h"
#include "../../matched/include/Obj14419.h"
#include "../../matched/include/Obj01004.h"
#include "../../matched/include/Obj02891.h"
#include "../../matched/include/Obj08309.h"
#include "../../matched/include/Obj14420.h"

struct Obj24810;
struct Obj0203159C;
struct S020315D4;
struct PrintSys;
struct Obj;
struct Node;
struct ObjC4;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long long u64;

extern unsigned func_021F9B9C(struct Obj24810 *p);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,unsigned);
extern u32 func_0201C440(void *p);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern void func_021FD940(u8 *p, u32 value);
extern int *func_021FD6D8(int payload, int callback, u32 heap);
extern void func_021FD820(char *);
extern void func_021FD714(void *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_020315D4(struct S020315D4 *);
extern void func_021FD71C(u8 *p);
extern void func_021FD854(char *);
extern int func_021FD72C(int *);
extern u32 func_0201C4E4(struct PrintSys *);
extern void func_021FD860(int,int,int *);
extern int func_021FD938(char *);
extern void *func_021FC6A4(unsigned short,unsigned,unsigned short,unsigned short,unsigned char,unsigned char,void *,unsigned short);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern void func_021FC754(char *,void *,void *,void *,unsigned short);
extern void func_021FE794(char *p, u32 index, u32 a, u32 b, u32 c);
extern int func_021FE7B0(int *);
extern void func_021FC734(u8 *p);
extern void func_021FEE24(char *p);
extern int func_021FC830(u8 *p);
extern void func_021F9BF4(unsigned *,unsigned);
extern int *func_021FD73C(int *p, int v);
extern void func_020061E4(u32 a);
extern void func_020409B4(u32 index);
extern int func_02035C60(void);
extern void func_021FEE74(char *p);
extern void func_021F9BA0(unsigned *ctx);
extern void func_021FEE9C(char *p);
extern void func_021FEE4C(char *p);
extern int func_021FD744(int *a);
extern void func_021FC1F8(int *,int);
extern void func_021FC148(char *p, unsigned i, unsigned heap);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern struct Obj *func_021F9CB8(int a, int b, int c, int d, int e, int f, u32 heap);
extern void func_021FE840(int,int,int);
extern void func_021FE784(int,int,int,int);
extern int func_021FA018(char *),func_021FA01C(char *);
extern void func_021F9FE8(char *);
extern int func_021FA004(char *,int *,int *);
extern int func_021FC238(char *),func_021FC224(char *);
extern void func_021FC230(char *,int),func_021FE7F4(int *,int);
extern u32 func_02035D20(u32 *,u32 *);
extern void *func_020056A0(void (*)(void),void *,int);
extern void func_02030EAC(struct Node *n);
extern void func_021FC240(char *p, void *owner, unsigned short heap);
extern void * func_02025538(unsigned,void *);
extern void func_021DBFB0(int *a, int *state, char *p);
extern void func_021DC4FC(int *a, int *state, char *p);
extern void func_021DBC68(int a, int b, char *p);
extern char * func_0200B928(void);
extern struct ObjC4 *func_0200B910(void);
extern unsigned long long func_0200B98C(u8 *p, int selector, int index);
int func_021DB2E0(int *task, int unused, char *p);
int func_021DB36C(struct S020315D4 *task,int b,int c,char *p);
int func_021DB394(int a,int b,int c,char *p);
void func_021DB3C4(int *task,int *state,char *p);
void func_021DB594(int *task, int *state, char *p);
void func_021DB61C(int *task, int *state, char *p);
void func_021DB690(int *task);
int func_021DB698(int *task,int b,char *p);
int func_021DB740(struct S020315D4 *task,int b,char *q,char *p);
int func_021DB770(int *task,int *state,char *p,char *q);
void func_021DB924(int a0, char *p);
int func_021DB940(int *task,int *state,char *q);
extern int d_021E3280[];

int func_021DB2E0(int *task, int unused, char *p)
{
    char *s;
    void *callback;
    s=func_0203159C((struct Obj0203159C *)task,0x20,func_021F9B9C(((struct Obj03879 *)p)->f10));
    func_02082BCC(s,0,0x20);
    *(char * *)&((struct Obj02228 *)s)->f1C=p;
    ((struct Obj02228 *)s)->f4=func_021F9B9C(((struct Obj03879 *)p)->f10);
    ((struct Obj02228 *)s)->fC=(void *)func_0201C440((void *)(((struct Obj02228 *)s)->f4));
    ((struct Obj02228 *)s)->f14=func_021FD760(((struct Obj03879 *)p)->f4,(char *)(((struct Obj03879 *)p)->fC),0,((struct Obj02228 *)s)->f4);
    ((struct Obj02228 *)s)->f18=func_021FD760(((struct Obj03879 *)p)->f4,(char *)(((struct Obj03879 *)p)->fC),1,((struct Obj02228 *)s)->f4);
    func_021FD940(((struct Obj02228 *)s)->f14,1);
    func_021FD940(((struct Obj02228 *)s)->f18,1);
    if(((struct Obj03879 *)p)->f0==0) callback=func_021DB3C4;
    else if(((struct Obj03879 *)p)->f0==1) callback=func_021DB594;
    else callback=func_021DB61C;
    ((struct Obj02228 *)s)->f0=func_021FD6D8((int)s,(int)callback,((struct Obj02228 *)s)->f4);
    return 1;
}

int func_021DB36C(struct S020315D4 *task,int b,int c,char *p) { func_021FD820(*(char * *)&((struct Obj08308 *)p)->f14); func_021FD820(*(char * *)&((struct Obj08308 *)p)->f18); func_0201C4C0(((struct Obj08308 *)p)->fC); func_021FD714((void *)(((struct Obj08308 *)p)->f0)); func_020315D4(task); return 1; }

int func_021DB394(int a,int b,int c,char *p) { func_021FD71C((u8 *)(*(int *)&((struct Obj06595 *)p)->f0)); func_0201C4E4(*(struct PrintSys * *)&((struct Obj06595 *)p)->fC); func_021FD854(*(char * *)&((struct Obj06595 *)p)->f14); func_021FD854(*(char * *)&((struct Obj06595 *)p)->f18); if(func_021FD72C(*(int * *)&((struct Obj06595 *)p)->f0)) return 1; return 0; }

/*
 * lever: enum-valued one-bit mask preserves the original call/mask scheduling, as in sibling 021DB594.
 * abi: 02035C60 returns a full word consumed by the original caller's comparison.
 */
void func_021DB3C4(int *task,int *state,char *p)
{
    int a,b;
    switch(*state) {
    case 0: {int args[2];args[0]=128;args[1]=96;func_021FD860(*(int *)&((struct Obj00630 *)p)->f14,2,args);func_020061E4(0x700);*state=1;break;}
    case 1: if(func_021FD938(*(char * *)&((struct Obj00630 *)p)->f14))*state=2;break;
    case 2: {int args[2];args[0]=128;args[1]=-8;func_021FD860(*(int *)&((struct Obj00630 *)p)->f18,3,args);*state=3;break;}
    case 3: if(func_021FD938(*(char * *)&((struct Obj00630 *)p)->f18))*state=4;break;
    case 4:
        ((struct Obj00630 *)p)->f8=func_021FC6A4(4,8,16,16,2,14,((struct Obj00630 *)p)->fC,((struct Obj00630 *)p)->f4);
        a=func_021FC20C(*(char * *)&((struct Obj24519 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->fC);
        b=func_021FC214(*(char * *)&((struct Obj24520 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->fC);
        func_021FC754(*(char * *)&((struct Obj00630 *)p)->f8,(void *)b,(void *)228,(void *)a,0x440);
        func_021FE794((char *)(((struct Obj24521 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f8),3,15,1,4);*state=5;break;
    case 5: if(func_021FE7B0(*(int * *)&((struct Obj24522 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f8))*state=6;break;
    case 6: func_021FE794((char *)(((struct Obj24523 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f8),3,15,0,4);*state=7;break;
    case 7: if(func_021FE7B0(*(int * *)&((struct Obj24524 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f8))*state=8;break;
    case 8: if(func_02035C60()) {func_020061E4(0x6ff);func_021FC734(((struct Obj00630 *)p)->f8);*(int *)&((struct Obj00630 *)p)->f8=0;func_020409B4(4);*state=9;}break;
    case 9: func_021FE794((char *)(((struct Obj24525 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f8),3,3,0,48);func_021FEE24((char *)(((struct Obj24526 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f14));*state=10;break;
    case 10: {enum {ONE=1} mask=ONE;if(func_021FE7B0(*(int * *)&((struct Obj24527 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f8)&mask) {func_021FD860(*(int *)&((struct Obj00630 *)p)->f18,8,0);*state=11;}break;}
    case 11: func_021FE794((char *)(((struct Obj24528 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f8),2,3,1,1);*state=12;break;
    case 12: if(func_021FE7B0(*(int * *)&((struct Obj24529 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f8))*state=13;break;
    case 13: if(func_021FD938(*(char * *)&((struct Obj00630 *)p)->f18)) {func_021F9BF4(*(unsigned * *)&((struct Obj24530 *)(*(char * *)&((struct Obj00630 *)p)->f1C))->f10,1);func_021FD73C(task,(int)func_021DB690);}break;
    }
    if(((struct Obj00630 *)p)->f8)func_021FC830(((struct Obj00630 *)p)->f8);
}

/*
 * lever: enum mask local materializes one before the call; int mask left nine bytes different
 */
void func_021DB594(int *task, int *state, char *p)
{
    switch(*state) {
    case 0: *state=1; break;
    case 1:
        func_021FEE74((char *)(((struct Obj24531 *)(*(char * *)&((struct Obj05470 *)p)->f1C))->f14));
        *state=2;
        break;
    case 2:
        if((((struct Obj05470 *)p)->f10)++ !=0) {
            ((struct Obj05470 *)p)->f10=0;
            func_021FE794((char *)(((struct Obj24532 *)(*(char * *)&((struct Obj05470 *)p)->f1C))->f8),3,3,1,26);
            *state=3;
        }
        break;
    case 3:
    {
        enum { MASK=1 } mask=MASK;
        if(func_021FE7B0(*(int * *)&((struct Obj24533 *)(*(char * *)&((struct Obj05470 *)p)->f1C))->f8)&mask) *state=4;
        break;
    }
    case 4:
        func_021F9BA0(((struct Obj24534 *)(*(char * *)&((struct Obj05470 *)p)->f1C))->f10);
        func_021FD73C(task,(int)func_021DB690);
        break;
    }
}

void func_021DB61C(int *task, int *state, char *p)
{
    switch(*state) {
    case 0:
        func_021FE794((char *)(((struct Obj24535 *)(*(char * *)&((struct Obj06597 *)p)->f1C))->f8),2,3,1,1);
        *state=1;
        break;
    case 1:
        if(func_021FE7B0(*(int * *)&((struct Obj24536 *)(*(char * *)&((struct Obj06597 *)p)->f1C))->f8)) *state=2;
        break;
    case 2:
        func_021FEE9C((char *)(((struct Obj24537 *)(*(char * *)&((struct Obj06597 *)p)->f1C))->f14));
        func_021FEE4C((char *)(((struct Obj24538 *)(*(char * *)&((struct Obj06597 *)p)->f1C))->f14));
        func_021F9BF4((unsigned int *)(((struct Obj24539 *)(*(char * *)&((struct Obj06597 *)p)->f1C))->f10),1);
        func_021FD73C(task,(int)func_021DB690);
        break;
    }
}

void func_021DB690(int *task)
{
    func_021FD744((int *)task);
}

/*
 * extent: two bytes of zero alignment padding at 0x021DB73E
 */
int func_021DB698(int *task,int b,char *p)
{
    char *s;
    s=func_0203159C((struct Obj0203159C *)task,24,func_021F9B9C((struct Obj24810 *)(*(char * *)&((struct Obj01072 *)p)->f1C)));
    func_02082BCC(s,0,24);
    *(char * *)&((struct Obj02517 *)s)->fC=p;
    ((struct Obj02517 *)s)->f14=func_021F9B9C((struct Obj24810 *)(*(char * *)&((struct Obj01072 *)p)->f1C));
    func_021FC1F8(*(int * *)&((struct Obj01072 *)p)->f18,0);
    func_021FC1F8(*(int * *)&((struct Obj01072 *)p)->f18,1);
    func_021FC148((char *)(*(int * *)&((struct Obj01072 *)p)->f18),0,((struct Obj02517 *)s)->f14);
    func_021FC148((char *)(*(int * *)&((struct Obj01072 *)p)->f18),1,((struct Obj02517 *)s)->f14);
    if(((struct Obj01072 *)p)->f0<5) func_021FB964(*(int * *)&((struct Obj01072 *)p)->f18,3,((struct Obj02517 *)s)->f14);
    else func_021FB964(*(int * *)&((struct Obj01072 *)p)->f18,4,((struct Obj02517 *)s)->f14);
    ((struct Obj02517 *)s)->f4=(int)func_021FD760(((struct Obj01072 *)p)->f14,(char *)(*(int *)&((struct Obj01072 *)p)->f18),1,((struct Obj02517 *)s)->f14);
    ((struct Obj02517 *)s)->f0=(int)func_021F9CB8(((struct Obj01072 *)p)->f0,((struct Obj01072 *)p)->f14,*(int *)&((struct Obj01072 *)p)->f18,((struct Obj01072 *)p)->f20,((struct Obj01072 *)p)->f24,((struct Obj02517 *)s)->f4,((struct Obj02517 *)s)->f14);
    if(((struct Obj01072 *)p)->fC==4) func_021FE840(((struct Obj01072 *)p)->f10,2,0);
    else func_021FE840(((struct Obj01072 *)p)->f10,3,0);
    return 1;
}

/*
 * lever: Explicit call arms preserve the original conditional argument branch.
 */
int func_021DB740(struct S020315D4 *task,int b,char *q,char *p) { if(((struct Obj10727 *)q)->f0<5) func_021FBDA4(((struct Obj10727 *)q)->f18,3); else func_021FBDA4(((struct Obj10727 *)q)->f18,4); func_021F9F48(*(u8 * *)&((struct Obj14419 *)p)->f0); func_021FD820(*(char * *)&((struct Obj14419 *)p)->f4); func_020315D4(task); return 1; }

/*
 * lever: explicit case-3 call arms preserve the original block shape; ARM9 division helper uses the proven _u32_div_f ABI.
 */
int func_021DB770(int *task,int *state,char *p,char *q)
{
    u32 x,y;
    switch(*state) {
    case 0: func_021FE784(*(int *)&((struct Obj01004 *)p)->f10,((struct Obj01004 *)p)->fC,3,0);*state=1;break;
    case 1: if(func_021FE7B0(*(int * *)&((struct Obj01004 *)p)->f10))*state=2;break;
    case 2:
        if(((struct Obj01004 *)p)->f0<=4 && !func_021FA018(*(char * *)&((struct Obj02891 *)q)->f0) && func_02035D20(&x,&y)) {
            if(x<8 || x>248) {func_020061E4(0x703);*state=6;break;}
        }
        func_021F9FE8(*(char * *)&((struct Obj02891 *)q)->f0);
        if(func_021FA004(*(char * *)&((struct Obj02891 *)q)->f0,(int *)(p+4),(int *)(p+8))) *state=3;
        break;
    case 3:
        if(((struct Obj01004 *)p)->f4==12)func_021FE784(*(int *)&((struct Obj01004 *)p)->f10,4,3,1);
        else func_021FE784(*(int *)&((struct Obj01004 *)p)->f10,2,3,1);
        *state=4;break;
    case 4: if(func_021FE7B0(*(int * *)&((struct Obj01004 *)p)->f10))*state=5;break;
    case 5:
        switch(func_021FA004(*(char * *)&((struct Obj02891 *)q)->f0,(int *)(p+4),(int *)(p+8))) {
        case 1: func_021F9BF4(*(unsigned * *)&((struct Obj01004 *)p)->f1C,(unsigned short)((struct Obj01004 *)p)->f4);return 1;
        case 2: func_021F9BA0(((struct Obj01004 *)p)->f1C);**(int * *)&((struct Obj01004 *)p)->f28=func_021FA01C(*(char * *)&((struct Obj02891 *)q)->f0);return 1;
        }
        break;
    case 6: {
        int v=func_021FC238(*(char * *)&((struct Obj01004 *)p)->f18);u32 i;
        for(i=0;i<7;i++) {if(v==d_021E3280[i]) {v=d_021E3280[(i+1)%7];break;}}
        func_021FC230(*(char * *)&((struct Obj01004 *)p)->f18,v);
        func_021FE7F4(*(int * *)&((struct Obj01004 *)p)->f10,func_021FC224(*(char * *)&((struct Obj01004 *)p)->f18));
        func_021FE784(*(int *)&((struct Obj01004 *)p)->f10,3,3,1);*state=7;break;
    }
    case 7: if(func_021FE7B0(*(int * *)&((struct Obj01004 *)p)->f10))*state=8;break;
    case 8: ((struct Obj02891 *)q)->f8=func_020056A0((void (*)(void))func_021DB924,q,0);((struct Obj02891 *)q)->f10=0;*state=9;break;
    case 9: if(((struct Obj02891 *)q)->f10) {func_02030EAC(((struct Obj02891 *)q)->f8);*state=10;}break;
    case 10: func_021FE784(*(int *)&((struct Obj01004 *)p)->f10,3,3,0);*state=11;break;
    case 11: if(func_021FE7B0(*(int * *)&((struct Obj01004 *)p)->f10))*state=2;break;
    }
    func_021FD854(*(char * *)&((struct Obj02891 *)q)->f4);return 0;
}


void func_021DB924(int a0, char *p)
{
    int v = ((struct Obj08309 *)p)->f10;
    char *q = *(char * *)&((struct Obj08309 *)p)->fC;

    if (v == 0) {
        func_021FC240((char *)(((struct Obj14420 *)q)->f18), (void *)(((struct Obj14420 *)q)->f10),
                      ((struct Obj08309 *)p)->f14);
    }
    ((struct Obj08309 *)p)->f10 = 1;
}

/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * lever: shared state-flag store and distinct case-5 null path preserve the original switch layout.
 * blocker-C: copied prior verified Thumb EXACT from ov183_func_021DF838.c header, blocker-r2.log; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 func_0200B98C_Table[];
 * u64 func_0200B98C(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==func_0200B98C_Table[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 */
int func_021DB940(int *task,int *state,char *q)
{
    char *p,*s;
    int i;
    p=func_0203159C((struct Obj0203159C *)task,0xe8,func_021F9B9C((struct Obj24810 *)(*(char **)(q+0x14))));
    func_02082BCC(p,0,0xe8);
    *(unsigned short *)(p+0xb4)=func_021F9B9C((struct Obj24810 *)(*(char **)(q+0x14)));
    *(int *)(p+0xb0)=0;
    *(char **)(p+0xd0)=q;
    *(void **)p=func_02025538(*(unsigned short *)(p+0xb4),*(void **)(q+0x18));
    *(void **)(p+4)=(void *)func_0201C440((void *)(*(unsigned short *)(p+0xb4)));
    *(void **)(p+8)=func_021FD6D8((int)p,0,*(unsigned short *)(p+0xb4));
    for(i=0;i<2;i++) *(char **)(p+i*4+0xc)=func_021FD760(*(unsigned *)(q+0x18),*(char **)(q+0x10),i,*(unsigned short *)(p+0xb4));
    switch(*(int *)(*(char **)(p+0xd0)+8)) {
    case 4:
        s=*(char **)(*(char **)(p+0xd0)+0x30);
        *(char **)(p+0xc4)=s+*(int *)(s+0x171c)*0xc4+0x80;
        s=*(char **)(*(char **)(p+0xd0)+0x30);
        *(char **)(p+0xc0)=s+*(int *)(s+0x171c)*0xc4;
        *(int *)(p+0xcc)=1;
        if(**(int **)(*(char **)(p+0xd0)+0x3c) && *(int *)(*(char **)(p+0xd0)+0x34)) {
            s=*(char **)(*(char **)(p+0xd0)+0x30);
            *(s+*(int *)(s+0x171c)+0x16f8)=1;
        }
        s=*(char **)(*(char **)(p+0xd0)+0x30);
        *(int *)(p+0xc8)=*(unsigned char *)(s+*(int *)(s+0x171c)+0x16f8);
        break;
    case 0:
        *(char **)(p+0xc4)=func_0200B928();*(char **)(p+0xc0)=(char *)func_0200B910();
        *(int *)(p+0xc8)=1;i=0;goto set_cc;
    case 1: case 2: case 3:
        *(char **)(p+0xc4)=func_0200B928();*(char **)(p+0xc0)=(char *)func_0200B910();
        *(int *)(p+0xc8)=func_0200B98C(*(void **)(p+0xc4),5,0);*(int *)(p+0xcc)=0;break;
    case 5:
        if(*(int *)(*(char **)(p+0xd0)+0x34)==0) {
            *(int *)(p+0xc4)=0;*(int *)(p+0xc0)=0;
        }else {
            *(char **)(p+0xc4)=func_0200B928();*(char **)(p+0xc0)=(char *)func_0200B910();
            *(int *)(p+0xc8)=**(int **)(*(char **)(p+0xd0)+0x3c);
        }
        i=1;
    set_cc:
        *(int *)(p+0xcc)=i;
        break;
    }
    if(*(int *)(*(char **)(p+0xd0)+8)==5) {
        if(*(int *)(*(char **)(p+0xd0)+0x34)==0)func_021FD73C(*(int **)(p+8),(int)func_021DBFB0);
        else func_021FD73C(*(int **)(p+8),(int)func_021DBC68);
    }else if((u32)(*(int *)(*(char **)(p+0xd0)+8)-1)<=2 && *(int *)(*(char **)(p+0xd0)+0x34) && **(int **)(*(char **)(p+0xd0)+0x3c) && *(int *)(p+0xc8)==0) {
        func_021FD73C(*(int **)(p+8),(int)func_021DC4FC);
    }else func_021FD73C(*(int **)(p+8),(int)func_021DBC68);
    return 1;
}
