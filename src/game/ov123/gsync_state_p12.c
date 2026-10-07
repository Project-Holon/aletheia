/*
 * file:     gsync_state_p12.c
 * unit:     yes
 * function: func_021D6D5C, func_021D6E08, func_021D6E70, func_021D6EA4, func_021D6EBC, func_021D6EE0, func_021D6EE8, func_021D6F04, func_021D6F44, func_021D6F70, func_021D6FF0, func_021D706C, func_021D7088, func_021D70BC, func_021D7130, func_021D7180, func_021D7204
 * address:  0x021D6D5C
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0203CD98 0x0203CD98 arm
 *   func_020221A4  0x020221A4  thumb
 *   func_021D580C 0x021D580C thumb ov123
 *   func_021D5C0C 0x021D5C0C thumb ov123
 *   func_021D5B70 0x021D5B70 thumb ov123
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_02012E08  0x02012E08  thumb
 *   func_021D8F58  0x021D8F58  thumb  ov123
 *   func_021D5D58  0x021D5D58  thumb  ov123
 *   func_021B9774 0x021B9774 thumb ov114
 *   func_021D584C 0x021D584C thumb ov123
 *   func_021D5950 0x021D5950 thumb ov123
 *   func_021D5960 0x021D5960 thumb ov123
 *   d_021DA844 0x021DA844 data a4
 *   func_02005E9C 0x02005E9C thumb
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005DF8 0x02005DF8 thumb
 *   func_021D5A60  0x021D5A60  thumb  ov123
 *   func_021D57D0  0x021D57D0  thumb  ov123
 *   func_021D56FC  0x021D56FC  thumb  ov123
 *   func_02005E64  0x02005E64  thumb
 *   func_02005D90  0x02005D90  thumb
 *   func_021D62BC 0x021D62BC thumb ov123
 *   func_021D62B4 0x021D62B4 thumb ov123
 *   func_021D63D4 0x021D63D4 thumb ov123
 */
#include "../../matched/include/Obj01544.h"
#include "../../matched/include/Obj00063.h"
#include "../../matched/include/Obj10442.h"
#include "../../matched/include/Obj22952.h"
#include "../../matched/include/Obj13982.h"
#include "../../matched/include/Obj22953.h"
#include "../../matched/include/Obj13983.h"
#include "../../matched/include/Obj22954.h"
#include "../../matched/include/Obj22955.h"
#include "../../matched/include/Obj13984.h"
#include "../../matched/include/Obj10443.h"
#include "../../matched/include/Obj05363.h"
#include "../../matched/include/Obj02182.h"
#include "../../matched/include/Obj22956.h"
#include "../../matched/include/Obj22957.h"
#include "../../matched/include/Obj22958.h"
#include "../../matched/include/Obj06463.h"
#include "../../matched/include/Obj03792.h"
#include "../../matched/include/Obj10444.h"

struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

struct Point { s16 x,y; u16 f4; u8 f6,f7; };

typedef signed int     s32;

typedef signed char s8;

typedef struct { int x[8]; } Table;

extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02020E60(u32 item, u32 which);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern int func_0203CD98(void);
extern u32 func_020221A4(void);
extern int func_021D580C(char *);
extern void func_0202208C(void *, u32, u32, u32, u32, u32, u32);
extern int func_021D5C0C(char *p);
extern void func_021D5B70(char *p);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_02012E08(char *p);
extern void func_021D8F58(char *p);
extern int func_021D5D58(char *p);
extern void func_021B9774(u8 *p);
extern void func_021D584C(char *);
extern int func_021D5950(u8 *p, int x);
extern void func_021D5960(char *,int,int);
extern int func_02005E9C(void);
extern void func_02005DE4(void *p);
extern void func_02005DF8(u32 v);
extern void func_021D5A60(char *p);
extern void func_021D57D0(void *p, int msg, int n, void *mon);
extern void func_021D56FC(char *p, int mode);
extern int func_02005E64(void);
extern void func_02005D90(int, int);
extern void func_021D62BC(u8 *,int,u32);
extern void func_021D62B4(u8 *p, unsigned int i);
extern void func_021D63D4(u8 *);
void func_021D6D5C(u8 *p);
int func_021D6E08(char *p,int x);
int func_021D6E70(u8 *p);
int func_021D6EA4(char *p);
int func_021D6EBC(u8 *p);
void func_021D6EDC(u8 *p,u32 v,int unused);
void func_021D6EE0(u8 *p,u32 v,int unused);
void func_021D6EE8(char *p);
void func_021D6F04(char *p);
void func_021D6F44(u8 *p);
void func_021D6F70(unsigned char *a);
void func_021D6FF0(char *p);
void func_021D706C(char *p);
void func_021D7088(char *p);
void func_021D70BC(char *p);
void func_021D7130(char *p);
void func_021D7180(int a);
void func_021D7204(u8 *p);
extern const Table d_021DA844;

void func_021D6D5C(u8 *p)
{
    struct Point pt;
    void *h;
    h=func_020490F4(25,((struct Obj01544 *)p)->f43C4);
    ((struct Obj01544 *)p)->f34=(void *)func_0204AC18(h,func_02020E60(1,2),0,256,0,1,((struct Obj01544 *)p)->f43C4);
    ((struct Obj01544 *)p)->f50=(void *)func_0204A6C8(h,func_02020E60(1,1),0,0,((struct Obj01544 *)p)->f43C4);
    ((struct Obj01544 *)p)->f6C=(void *)func_0204AF28(h,1,0,((struct Obj01544 *)p)->f43C4);
    func_02049238(h);
    pt.x=156; pt.y=28; pt.f4=0; pt.f6=0; pt.f7=2;
    ((struct Obj01544 *)p)->fB8=func_0204B294((void *)((struct Obj01544 *)p)->fC,(unsigned int)((struct Obj01544 *)p)->f50,*(u32 *)&((struct Obj01544 *)p)->f34,*(u32 *)&((struct Obj01544 *)p)->f6C,&pt,0,((struct Obj01544 *)p)->f43C4);
    func_0204B92C(((struct Obj01544 *)p)->fB8,0);
    func_0204B3DC(((struct Obj01544 *)p)->fB8,0);
}

int func_021D6E08(char *p,int x)
{
    switch (x) {
    case 503:
        ((struct Obj00063 *)p)->f80=0xfff1;
        func_021D6EE0((u8 *)p,(int)func_021D6FF0,0xd3);
        return 1;
    case 502:
        ((struct Obj00063 *)p)->f80=0xfff2;
        func_021D6EE0((u8 *)p,(int)func_021D6FF0,0xd7);
        return 1;
    }
    if (x>=400) {
        ((struct Obj00063 *)p)->f80=0xfff3;
        func_021D6EE0((u8 *)p,(int)func_021D6FF0,0xdd);
        return 1;
    }
    return 0;
}

int func_021D6E70(u8 *p){u8 *q=*(u8 * *)&((struct Obj22952 *)p)->f20;if(((struct Obj10442 *)q)->f1C8==2)return 0;if(((struct Obj10442 *)q)->f50 && ((struct Obj10442 *)q)->fC==4)return 0;if(func_0203CD98())return 1;return 0;}


int func_021D6EA4(char *p)
{
    char *q = *(char * *)&((struct Obj22953 *)p)->f20;

    return ((struct Obj13982 *)q)->f50 != 0 && ((struct Obj13982 *)q)->fC == 0;
}

int func_021D6EBC(u8 *p){u8 *q=*(u8 * *)&((struct Obj22954 *)p)->f20;if(((struct Obj13983 *)q)->f50){unsigned int x=((struct Obj13983 *)q)->fC;if(x==0)return 1;if(x==4)return 1;}return 0;}

void func_021D6EDC(u8 *p,u32 v,int unused){((struct Obj22955 *)p)->f50=v;}

void func_021D6EE0(u8 *p,u32 v,int unused){func_021D6EDC(p,v,unused);}


void func_021D6EE8(char *p)
{
    if (func_020221A4() != 0)
        func_021D6EE0((u8 *)p, 0, 0x157);
}

void func_021D6F04(char *p)
{
    if (func_021D580C(*(char * *)&((struct Obj13984 *)p)->f18)) {
        func_0202208C(0,0,0,0,6,1,((struct Obj13984 *)p)->f0);
        func_021D6EE0((u8 *)p,(int)func_021D6EE8,0x16b);
    }
}

void func_021D6F44(u8 *p){if(func_021D5C0C((char *)(((struct Obj10443 *)p)->f8))){func_021D5B70((char *)(((struct Obj10443 *)p)->f8));((struct Obj10443 *)p)->f8=0;func_021D6EE0(p,(u32)func_021D706C,0x17c);}}


void func_021D6F70(unsigned char *a)
{
    if (((struct Obj05363 *)a)->fAB != 0)
        return;
    if (func_020362DC() == 0 && func_02035C60() == 0)
        return;
    if (((struct Obj05363 *)a)->fAD != 0) {
        func_02012E08((char *)(((struct Obj05363 *)a)->f2C));
        ((struct Obj05363 *)a)->fAD = 0;
    }
    func_021D8F58((char *)a);
    if (((struct Obj05363 *)a)->f8 != 0) {
        if (func_021D5D58((char *)(((struct Obj05363 *)a)->f8)) != 0)
            func_021D6EE0(a, (int)func_021D6F44, 0x191);
        func_021D6EE0(a, 0x021D706D, 0x193);
    } else {
        func_021D6EE0(a, 0x021D706D, 0x196);
    }
}

/*
 * extent: unit includes the 28-byte store-and-tail stub at 021D706C.
 */
void func_021D6FF0(char *p)
{
    int n=((struct Obj02182 *)p)->f80+29;
    if (((struct Obj02182 *)p)->f10) func_021B9774(((struct Obj02182 *)p)->f10);
    if (((struct Obj02182 *)p)->f80==0xfff0) n=39;
    else if (((struct Obj02182 *)p)->f80==0xfff1) n=40;
    else if (((struct Obj02182 *)p)->f80==0xfff2) n=41;
    else if (((struct Obj02182 *)p)->f80==0xfff3) n=38;
    else if (((struct Obj02182 *)p)->f80<=0 || ((struct Obj02182 *)p)->f80>=10) n=38;
    func_021D584C(*(char * *)&((struct Obj02182 *)p)->f18);
    func_021D5950((u8 *)(*(char * *)&((struct Obj02182 *)p)->f18),n);
    func_021D5960(*(char * *)&((struct Obj02182 *)p)->f18,1,16);
    func_021D6EE0((u8 *)p,(int)func_021D6F70,0x1b9);
}

void func_021D706C(char *p)
{
    ((struct Obj22957 *)(*(char * *)&((struct Obj22956 *)p)->f20))->f1C8=6;
    func_021D6EE0((u8 *)p,(int)func_021D6F04,0x1c9);
}

void func_021D7088(char *p) { if(func_021D580C(*(char * *)&((struct Obj22958 *)p)->f18) && (func_020362DC() || func_02035C60())) func_021D6EE0((u8 *)p,(int)func_021D706C,0x1d9); }

void func_021D70BC(char *p)
{
    Table t=d_021DA844;
    if (((struct Obj06463 *)p)->fA8) {
        func_021D584C(*(char * *)&((struct Obj06463 *)p)->f18);
        func_021D5950((u8 *)(*(char * *)&((struct Obj06463 *)p)->f18),t.x[((struct Obj06463 *)p)->fA8]);
        func_021D5960(*(char * *)&((struct Obj06463 *)p)->f18,1,8);
        func_021D6EE0((u8 *)p,(int)func_021D7088,0x1f0);
    } else {
        func_021D6EE0((u8 *)p,(int)func_021D706C,0x1f3);
    }
}

void func_021D7130(char *p)
{
    if (func_021D580C(*(char **)(p + 0x18)) != 0) {
        int n = *(int *)(p + 0x78) - 1;
        *(int *)(p + 0x78) = n;
        if (n <= 0) {
            if (n == 0) {
                func_02005E9C();
                func_02005DE4(0);
                func_02005DF8(6);
            }
            if (func_020362DC() != 0 || func_02035C60() != 0) {
                func_021D6EE0((u8 *)p, (int)func_021D70BC, 0x20B);
            }
        }
    }
}


void func_021D7180(int a)
{
    if (func_021D580C((char *)(((struct Obj03792 *)a)->f18)) == 0)
        return;
    if (func_020362DC() == 0 && func_02035C60() == 0)
        return;
    if (((struct Obj03792 *)a)->f6C == 0) {
        func_021D6EE0((u8 *)a, (int)func_021D70BC, 0x217);
        return;
    }
    func_021D5A60((char *)(((struct Obj03792 *)a)->f18));
    func_021D57D0((void *)(((struct Obj03792 *)a)->f18), 0x16, ((struct Obj03792 *)a)->f6C,
                 (void *)(((struct Obj03792 *)a)->fC));
    func_021D56FC((char *)(((struct Obj03792 *)a)->f18), 0);
    func_02005DE4((void *)1);
    func_02005E64();
    func_02005D90(0x515, 0xffff);
    ((struct Obj03792 *)a)->f78 = 0xb4;
    func_021D6EE0((u8 *)a, (int)func_021D7130, 0x222);
}

void func_021D7204(u8 *p) { func_021D62BC(*(u8 * *)&((struct Obj10444 *)p)->f14,0,0); func_021D62B4((u8 *)(*(char * *)&((struct Obj10444 *)p)->f14),12); func_021D63D4(*(u8 * *)&((struct Obj10444 *)p)->f14); }
