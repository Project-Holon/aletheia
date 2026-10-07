/*
 * file:     box2_seq_p21.c
 * unit:     yes
 * function: func_021E8E24, func_021E8F20, func_021E8F50, func_021E8F60, func_021E8F90, func_021E8FC0, func_021E8FD0, func_021E8FE0, func_021E8FE8, func_021E9010, func_021E90D4, func_021E912C, func_021E91A0, func_021E9284, func_021E92A8, func_021E93F4, func_021E941C, func_021E946C, func_021E949C, func_021E94AC
 * address:  0x021E8E24
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_020216D4 0x020216D4 thumb
 *   func_020056BC 0x020056BC thumb
 *   func_0202173C 0x0202173C thumb
 *   func_021DED58 0x021DED58 thumb ov170
 *   func_02007838 0x02007838 thumb
 *   func_021EDAB0 0x021EDAB0 thumb ov170
 *   func_021E95CC 0x021E95CC thumb ov170
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021ED508 0x021ED508 thumb ov170
 *   func_021EBADC 0x021EBADC thumb ov170
 *   func_021EA984 0x021EA984 thumb ov170
 *   func_021DC9A0  0x021DC9A0  thumb  ov170
 *   func_021DC9B8  0x021DC9B8  thumb  ov170
 *   func_021DCF58 0x021DCF58 thumb
 *   func_02036270 0x02036270 arm
 *   func_021DD25C 0x021DD25C thumb ov170
 *   func_02007E50 0x02007E50 thumb
 *   func_021DD2D0 0x021DD2D0 thumb ov170
 *   func_021EBB34 0x021EBB34 thumb ov170
 *   func_021DD2B4 0x021DD2B4 thumb ov170
 *   func_021DD718 0x021DD718 thumb ov170
 *   func_021DD8A8 0x021DD8A8 thumb ov170
 *   func_021EC48C 0x021EC48C thumb ov170
 *   func_021DEFF8 0x021DEFF8 thumb ov170
 *   func_020061E4 0x020061E4 thumb
 *   func_021EBB58 0x021EBB58 thumb ov170
 *   func_020355C4 0x020355C4 arm
 *   func_020260F4 0x020260F4 thumb
 *   func_021ED6E4 0x021ED6E4 thumb ov170
 *   func_021EBA5C 0x021EBA5C thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_021DE728 0x021DE728 thumb ov170
 *   func_021EC94C 0x021EC94C thumb ov170
 *   func_021EBA70 0x021EBA70 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021E0190 0x021E0190 thumb ov170
 *   func_021DEFEC 0x021DEFEC thumb ov170
 *   func_021EF670 0x021EF670 thumb ov170
 *   func_021ED108 0x021ED108 thumb ov170
 *   func_021EBFA8 0x021EBFA8 thumb ov170
 *   func_021EBCB4 0x021EBCB4 thumb ov170
 *   func_021DE898  0x021DE898  thumb  ov170
 *   func_021EF480 0x021EF480 thumb
 *   func_021EF68C 0x021EF68C thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021E2334 0x021E2334 thumb ov170
 *   func_021DD090  0x021DD090  thumb  ov170
 *   func_0202CF8C 0x0202CF8C thumb
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj23940.h"
#include "../../matched/include/Obj23941.h"
#include "../../matched/include/Obj18468.h"
#include "../../matched/include/Obj18469.h"
#include "../../matched/include/Obj18470.h"
#include "../../matched/include/Obj18471.h"
#include "../../matched/include/Obj23942.h"
#include "../../matched/include/Obj23943.h"
#include "../../matched/include/Obj18472.h"
#include "../../matched/include/Obj23944.h"
#include "../../matched/include/Obj05869.h"
#include "../../matched/include/Obj23945.h"
#include "../../matched/include/Obj23946.h"
#include "../../matched/include/Obj23947.h"

#define W (*(char **)(p + 0x2c))
#define S (*(int *)(W + 0xA194))
struct PalAnmSlot;
struct Struct_02025CD0;
struct WinMgr;
struct Sound;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef struct {
 unsigned char pad[0x1A6];
 unsigned char flag:1;
 unsigned char rest:7;
 unsigned char lo:4;
 unsigned char hi:4;
 unsigned char a,b,d,c,f,g;
} Work;

typedef struct {
 unsigned char pad[0x28];
 int value;
 Work *work;
} Obj;

extern void func_021ED55C(char **p, int flag);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern u32 func_020056BC(void);
extern int func_0202173C(void *, u16, u16, s16, u8, u8, u16, void *);
extern void func_021DED58(char *, int);
extern void func_02007838(void *save, u32 box, u8 v);
extern void func_021EDAB0(char *, int);
extern int func_021E95CC(unsigned char *, unsigned char);
extern void func_021EC000(char *,int,int);
extern void func_021ED508(u8 *,int,int);
extern void func_021EBADC(char *,int);
extern void func_021EA984(u8 *);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021DC9A0(char *, int);
extern void func_021DC9B8(char *);
extern void func_021DCF58(unsigned char *p, int sel);
extern int func_02036270(int a0, int a1);
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);
extern int func_021DD2D0(void ***p, int a, unsigned b);
extern void func_021EBB34(char *p, int a, int b);
extern void func_021DD2B4(int a, int b, int c, int d, int e);
extern int func_021DD718(void **pp, void *mon);
extern void func_021DD8A8(void **pp, u32 idx);
extern void func_021EC48C(unsigned char *p, int box, int pos, int win);
extern void func_021DEFF8(char *p, unsigned b);
extern void func_020061E4(unsigned se);
extern void func_021EBB58(char *p, int b);
extern u8 func_020355C4(void);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern void func_021ED6E4(char **p, int v);
extern void func_021EBA5C(char *w, int v);
extern void func_021DD14C(char *p);
extern void func_021DE728(unsigned char *p);
extern void func_021EC94C(char *p);
extern void func_021EBA70(char *,int);
extern void func_021ED888(char *,int);
extern void func_021ECB20(char *p, int f, int c);
extern int func_021E0190(char *p);
extern void func_021DEFEC(char *p, int b);
extern void func_021EF670(char *);
extern void func_021ED108(char *,int);
extern void func_021EBFA8(char *,int,int);
extern void func_021EBCB4(unsigned char *,int,int);
extern void func_021DE898(int *q);
extern int func_021EF480(struct WinMgr *mgr);
extern void func_021EF68C(char *);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern int func_021E2334(unsigned char *);
extern void func_021DD090(char *, int);
extern u8 func_0202CF8C(struct WinMgr *mgr, u32 idx);
int func_021E8E24(char *p);
int func_021E8F14(unsigned char *p);
void func_021E8F20(u8 *p);
int func_021E8F50(char *p, int v);
int func_021E8F60(void *p, int a);
int func_021E8F90(void *p, int a);
int func_021E8FC0(char *p, int a, int b);
int func_021E8FD0(char *p, int a);
int func_021E8FE0(char *p, int v);
int func_021E8FE8(unsigned char *p, int sel);
int func_021E9010(unsigned char *p);
int func_021E90D4(unsigned char *p);
int func_021E912C(unsigned char *p);
int func_021E91A0(unsigned char *p);
int func_021E9284(char *p);
int func_021E92A8(unsigned char *p);
void func_021E93F4(char *p);
int func_021E941C(unsigned char *p);
void func_021E946C(unsigned char *p);
int func_021E949C(char *p, int a, int b);
int func_021E94AC(Obj *p,int a,int b);

int func_021E8E24(char *p)
{
    switch (S) {
    case 0:
        func_021ED55C((char **)p, 0);
        func_020216D4(*(void **)(W + 0x6c), 0, 0, 0x200);
        func_0202173C(*(void **)(W + 0x6c), 1, 0xc000, 0, 0, 16, 0x7fff, (void *)func_020056BC());
        ((struct Obj00000 *)p)->f28 = 0x66;
        S++;
        return 3;
    case 1:
        func_021DED58(p, *(u8 *)(W + 0xA17B));
        func_02007838(((struct Obj23940 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f4, ((struct Obj00000 *)p)->f14, *(u8 *)(W + 0xA17B));
        func_021EDAB0(p, ((struct Obj00000 *)p)->f14);
        S++;
        break;
    case 2:
        func_0202173C(*(void **)(W + 0x6c), 1, 0xc000, 0, 16, 0, 0x7fff, (void *)func_020056BC());
        ((struct Obj00000 *)p)->f28 = 0x66;
        S++;
        return 3;
    case 3:
        func_021ED55C((char **)p, 1);
        S = 0;
        return 0x65;
    }
    return 0x66;
}

int func_021E8F14(unsigned char *p)
{
    return func_021E95CC(p, 2);
}

void func_021E8F20(u8 *p){func_021EC000(*(char * *)&((struct Obj23941 *)p)->f2C,4,0);func_021ED508(p,14,0);func_021EBADC((char *)p,24);func_021EA984(p);func_021E8FE8(p,4);}



/*
 * Clear the pooled-offset word and return the argument.
 */
int func_021E8F50(char *p, int v)
{
    ((struct Obj18468 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA194 = 0;
    return v;
}



/*
 * Sibling of func_021E8F90: the seven-argument setup call then
 * the state word at +0xA188 of the sub-object, return 2.
 */
int func_021E8F60(void *p, int a)
{
    func_0202208C(0, 1, 1, 0, 6, 1, 0x4c);
    *(int *)(((struct Obj18469 *)p)->f2C + 0xA188) = a;
    return 2;
}



/*
 * Same body as func_021E8F60 with the first four arguments zero;
 * the state word goes to +0xA188, return 2.
 */
int func_021E8F90(void *p, int a)
{
    func_0202208C(0, 0, 0, 0, 6, 1, 0x4c);
    *(int *)(((struct Obj18470 *)p)->f2C + 0xA188) = a;
    return 2;
}

/*
 * Store the third argument, then reset the sub-object.
 */
int func_021E8FC0(char *p, int a, int b)
{
    *(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x68) = b;
    func_021DC9A0(*(char * *)&((struct Obj00000 *)p)->f2C, a);
    return 5;
}

/*
 * Store the second argument, then re-seat the sub-object.
 */
int func_021E8FD0(char *p, int a)
{
    *(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x68) = a;
    func_021DC9B8(*(char * *)&((struct Obj00000 *)p)->f2C);
    return 5;
}



/*
 * Store v at +0x28, return 13.
 */
int func_021E8FE0(char *p, int v)
{
    ((struct Obj18471 *)p)->f28 = v;
    return 0xd;
}


#define WORK(p) (*(char **)((p) + 0x2C))


/*
 * Opens the yes/no menu with the cursor on sel and enters state 7.
 */
int func_021E8FE8(unsigned char *p, int sel)
{
    *(unsigned short *)(WORK(p) + 0x1A4) = sel;
    if (sel == 1)
        func_021DCF58(p, 1);
    else
        func_021DCF58(p, 0);
    func_02036270(*(unsigned *)(WORK(p) + 0x4C), *(unsigned *)(WORK(p) + 0x50));
    return 7;
}

#undef WORK
#define WORK(p) (*(char **)((p) + 0x2C))

int func_021E9010(unsigned char *p)
{
    unsigned item;
    void *mon;
    item = func_021DD25C((void ***)p, p[0x16], p[0x14], 6, 0);
    if (func_02007E50(((struct Obj23942 *)(*(char * *)&((struct Obj00000 *)p)->f0))->fC, item, 1, 0x4C) == 1) {
        mon = (void *)func_021DD2D0((void ***)p, p[0x14], p[0x16]);
        func_021EBB34((char *)p, item, 0x18);
        func_021DD2B4((int)p, p[0x16], p[0x14], 6, 0);
        if (func_021DD718((void **)p, mon) == 1) {
            func_021DD8A8((void **)p, p[0x16]);
            func_021EC48C(p, p[0x14], p[0x16], *(unsigned char *)(WORK(p) + p[0x16] + 0x3DD2));
        }
        func_021DEFF8((char *)p, p[0x16]);
    } else {
        func_020061E4(0x557);
        func_021EBB58((char *)p, 0x18);
    }
    if (func_020355C4() == 1) {
        func_020260F4(*(void **)(WORK(p) + 0x70), 0);
    } else {
        func_020260F4(*(void **)(WORK(p) + 0x70), 1);
        func_021ED55C((char **)p, 0);
    }
    ((struct Obj00000 *)p)->f28 = 0xE;
    return func_021E8F50((char *)p, 6);
}

#undef WORK
#define WORK(p) (*(char **)((p) + 0x2C))

int func_021E90D4(unsigned char *p)
{
    func_021ED6E4((char **)p, 0);
    func_021EBA5C(WORK(p), 0x18);
    func_021DD14C((char *)p);
    func_021DE728(p);
    func_021EC94C(*(char **)(WORK(p) + 0xA190));
    if (func_020355C4() == 1) {
        func_020260F4(*(void **)(WORK(p) + 0x70), 0);
    } else {
        func_020260F4(*(void **)(WORK(p) + 0x70), 1);
        func_021ED55C((char **)p, 0);
    }
    return 0x5A;
}

#undef WORK
#define WORK(p) (*(char **)((p)+0x2C))

int func_021E912C(unsigned char *p) {
 func_021ED6E4((char **)p,1); func_021EBA70(WORK(p),0x18); func_021DD14C((char *)p);
 if(p[0x16]<0x1E) { func_021ED888(WORK(p),1); func_021ECB20((char *)p,1,0); }
 else func_021ECB20((char *)p,2,0);
 if(func_020355C4()==1) func_020260F4(*(void **)(WORK(p)+0x70),0);
 else { func_020260F4(*(void **)(WORK(p)+0x70),1); func_021ED55C((char **)p,0); }
 return func_021E8FC0((char *)p,(int)func_021E0190,func_021E8F50((char *)p,0xE));
}

#undef WORK
#define WORK(p) (*(char **)((p) + 0x2C))

int func_021E91A0(unsigned char *p)
{
    void *mon;
    if(func_020355C4()==1) func_020260F4(*(void **)(WORK(p)+0x70),0);
    else { func_020260F4(*(void **)(WORK(p)+0x70),1); func_021ED55C((char **)p,0); }
    if(func_02007E50(((struct Obj23943 *)(*(char * *)&((struct Obj00000 *)p)->f0))->fC,*(unsigned short *)(WORK(p)+0xa16c),1,0x4c)==1) {
        mon=(void *)func_021DD2D0((void ***)p,p[0x14],p[0x16]);
        func_021DD2B4((int)p,p[0x16],p[0x14],6,0);
        if(func_021DD718((void **)p,mon)==1) {
            func_021DD8A8((void **)p,p[0x16]);
            func_021EC48C(p,p[0x14],p[0x16],*(unsigned char *)(WORK(p)+p[0x16]+0x3dd2));
        }
        func_021DEFEC((char *)p,p[0x16]); func_021ED6E4((char **)p,0);
        func_021EBA5C(WORK(p),0x18); func_021DD14C((char *)p); func_021EF670(WORK(p));
        func_021ED108(WORK(p),1); func_021EBFA8(WORK(p),0xa,2);
        return 0x3b;
    }
    func_020061E4(0x557); func_021EBCB4(p,6,0x18);
    ((struct Obj00000 *)p)->f28=0xe;
    return func_021E8F50((char *)p,6);
}

/*
 * Set the id, re-key the queue, store 0x69 as the frame, then
 *   arm the flag.
 */
int func_021E9284(char *p)
{
    func_020061E4(0x55D);
    func_021DE898((int *)p);
    ((struct Obj18472 *)p)->f28 = 0x69;
    return func_021E8F90(p, 1);
}

#undef WORK
#define WORK (*(char **)(p+0x2c))

/*
 * trailing extent: two-byte zero alignment at 021E93F2.
 */
int func_021E92A8(unsigned char *p)
{
    func_021EBA5C(WORK,0x18);
    func_021DD14C((char *)p);
    if(func_020355C4()==1) func_020260F4(*(void **)(WORK+0x70),0);
    else func_020260F4(*(void **)(WORK+0x70),1);
    func_021ED508(p,0xe,1);
    switch(((struct Obj23944 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24) {
    case 0: func_021ECB20((char *)p,2,0); return 0x31;
    case 1: func_021ED888(WORK,1); func_021ECB20((char *)p,1,0); return 0x2c;
    case 2:
        if(func_021EF480(*(struct WinMgr **)(WORK+0x74))==1) {
            func_021ECB20((char *)p,2,0); func_021EF68C(WORK); return 0x1b;
        }
        func_021ED888(WORK,1); func_021ECB20((char *)p,1,0); func_021EF670(WORK); return 0x11;
    case 3:
        if(func_021EF480(*(struct WinMgr **)(WORK+0x74))==1) {
            func_021ECB20((char *)p,0x82,0); func_021EF68C(WORK); return 0x46;
        }
        func_021ED888(WORK,1); func_021ECB20((char *)p,0x81,0); func_021EF670(WORK); return 0x39;
    case 4:
        if(func_021EF480(*(struct WinMgr **)(WORK+0x74))==1) {
            func_021ECB20((char *)p,2,0); func_021EF68C(WORK); return 0x27;
        }
        func_021ED888(WORK,1); func_021ECB20((char *)p,1,0); func_021EF670(WORK); return 0x23;
    case 5: func_021ED888(WORK,1); func_021ECB20((char *)p,0x81,1); return 0x4b;
    }
    return 0x11;
}

/*
 * candidate func_021E93F4: copy two bytes into a sub object
 */
void func_021E93F4(char *p)
{
    func_021DE898((int *)((int)p));
    *(unsigned char *)(((struct Obj05869 *)p)->f0 + 0x2a) = ((struct Obj05869 *)p)->f14;
    *(unsigned char *)(((struct Obj05869 *)p)->f0 + 0x2b) = ((struct Obj05869 *)p)->f16;
    ((struct Obj05869 *)p)->f28 = 0x69;
    func_021E8F90((void *)((int)p), 1);
}

#undef WORK
#define WORK(p) (*(char **)((p)+0x2C))

int func_021E941C(unsigned char *p) {
 func_021EBA5C(WORK(p),0x1B); func_021DD14C((char *)p);
 func_020260E4(*(void **)(WORK(p)+0x70),p[0x16]);
 func_021ECB20((char *)p,0x81,1); func_021ED6E4((char **)p,0);
 if(func_020355C4()==1) func_020260F4(*(void **)(WORK(p)+0x70),0);
 else func_020260F4(*(void **)(WORK(p)+0x70),1);
 return 0x4B;
}

void func_021E946C(unsigned char *p){if(func_020355C4()==1)func_020260F4(((struct Obj23945 *)(*(unsigned char * *)&((struct Obj00000 *)p)->f2C))->f70,0);else {func_020260F4(((struct Obj23946 *)(*(unsigned char * *)&((struct Obj00000 *)p)->f2C))->f70,1);func_021ED55C((char **)p,0);}func_021E2334(p);}

/*
 * Forward, then store the third argument at 0x28.
 */
int func_021E949C(char *p, int a, int b)
{
    func_021DD090(p, a);
    ((struct Obj00000 *)p)->f28 = b;
    return 8;
}

int func_021E94AC(Obj *p,int a,int b) {
 p->work->flag=1;
 p->work->rest=func_0202CF8C(*(struct WinMgr * *)&((struct Obj23947 *)((char *)p->work))->f74,7);
 p->work->lo=13;
 p->work->hi=12;
 p->work->a=0;
 p->work->b=0;
 if(a==0) p->work->c=14;
 else p->work->c=17;
 p->work->d=21;
 p->work->f=11;
 p->work->g=3;
 p->value=b;
 return 8;
}
