/*
 * file:     pmsiv_category_p05.c
 * unit:     yes
 * function: func_021BB82C, func_021BB838, func_021BB854, func_021BB870, func_021BB8AC, func_021BB8B8, func_021BB8D8, func_021BB954, func_021BB958, func_021BB9C0, func_021BB9E8, func_021BBA10, func_021BBB0C, func_021BBB84, func_021BBC10, func_021BBC5C, func_021BBCF0, func_021BBD60
 * address:  0x021BB82C
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BC93C 0x021BC93C thumb ov110
 *   func_021BC868 0x021BC868 thumb ov110
 *   func_021BC898 0x021BC898 thumb ov110
 *   func_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   func_02041EE4 0x02041EE4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_020499D4 0x020499D4 arm
 *   func_02045374 0x02045374 arm
 *   func_02049238 0x02049238 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021BAC44 0x021BAC44 thumb ov110
 *   func_021BF7D4 0x021BF7D4 thumb ov110
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045334 0x02045334 arm
 *   func_021BF7FC 0x021BF7FC thumb ov110
 *   func_02040804 0x02040804 arm
 *   func_021BC78C 0x021BC78C thumb ov110
 *   func_021BAC4C 0x021BAC4C thumb ov110
 *   func_021BF814 0x021BF814 thumb ov110
 *   func_0201C724 0x0201C724 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_021BC7DC 0x021BC7DC thumb ov110
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021BB224 0x021BB224 thumb ov110
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B98C 0x0204B98C arm
 *   func_02030734 0x02030734 arm
 *   d_021C3C58 0x021C3C58 data a1
 *   func_021BF6D4 0x021BF6D4 thumb ov110
 *   func_02045B38 0x02045B38 arm
 *   func_02020D18 0x02020D18 thumb
 *   func_0202C9B4 0x0202C9B4 thumb
 *   func_0202CA0C 0x0202CA0C thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_02020D3C 0x02020D3C thumb
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021BC068 0x021BC068 thumb ov110
 *   func_021BC120 0x021BC120 thumb ov110
 *   func_021BC160 0x021BC160 thumb ov110
 *   func_021BC23C 0x021BC23C thumb ov110
 *   func_021BC1B8 0x021BC1B8 thumb ov110
 *   func_020498F4 0x020498F4 arm
 *   func_02040618 0x02040618 arm
 *   func_02049658 0x02049658 arm
 *   func_020450F0 0x020450F0 arm
 *   func_0202CA3C 0x0202CA3C thumb
 *   func_0202CB18 0x0202CB18 thumb
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_0202CEBC 0x0202CEBC thumb
 *   func_0202CC58 0x0202CC58 thumb
 */
#include "../../matched/include/Obj22368.h"
#include "../../matched/include/Obj10275.h"
#include "../../matched/include/Obj02460.h"
#include "../../matched/include/Obj05289.h"
#include "../../matched/include/Obj05290.h"
#include "../../matched/include/Obj04446.h"
#include "../../matched/include/Obj01392.h"
#include "../../matched/include/Obj01248.h"
#include "../../matched/include/Obj01922.h"

struct Cfg;
struct CharBuf;
struct Descriptor;
struct U16Vec;
struct PrintSys;
struct Obj;
struct Vec2;
struct Actor;
struct WinMgr;
struct MsgBank;
struct D;
struct Node;
struct Rec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16_021BB838;

typedef unsigned int u32_021BB838;

typedef short s16_021BB854;

typedef unsigned int u32_021BB854;

typedef unsigned int   u32_021BB870;

typedef short s16_021BB8B8;

typedef unsigned int u32_021BB8B8;

typedef unsigned int   u32_021BB8D8;

typedef short s16_021BB954;

typedef signed char s8;

typedef unsigned int u32_021BB954;

typedef int s32;

typedef unsigned int u32_021BB958;

typedef signed short   s16_021BB958;

typedef short s16_021BB9C0;

typedef unsigned int u32_021BB9C0;

typedef short s16_021BB9E8;

typedef unsigned int u32_021BB9E8;

typedef short s16_021BBA10;

typedef unsigned u32_021BBA10;

typedef unsigned int   u32_021BBB0C;

typedef signed short s16_021BBB84;

typedef struct { s16_021BBB84 x, y; } Vec2;

typedef unsigned int   u32_021BBB84;

typedef unsigned int   u32_021BBC10;

typedef unsigned int u32_021BBC5C;

typedef unsigned int   u32_021BBCF0;

typedef unsigned u32_021BBD60;

typedef short s16_021BBD60;

extern int func_021BC93C(u8 *);
extern void func_021BC868(u8 *p, int a, int b, int start, int end, int frames);
extern int func_021BC898(u8 *p);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(void *, int, int, int, int);
extern u8 func_021BF6DC(u8 *);
extern void func_02041EE4(u32_021BB8B8,u32_021BB8B8,u32_021BB8B8);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32_021BB8D8 func_020499D4(void *a0, u32_021BB8D8 a1, u32_021BB8D8 a2, u32_021BB8D8 a3, u32_021BB8D8 a4, u32_021BB8D8 a5, u32_021BB8D8 a6, u16 a7);
extern void func_02045374(struct Cfg *cfg);
extern void func_02049238(void *);
extern void func_02041B6C(unsigned);
extern u32_021BB958 func_021BAC44(u8 *p);
extern void func_021BF7D4(u8 *p, void *q);
extern struct U16Vec *func_020457B0(u32_021BB958 capacity, u32_021BB958 heapId);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32_021BB958 r, u32_021BB958 g, u32_021BB958 b);
extern void func_0201C7A4(void *x, s16_021BB958 y, s16_021BB958 z, void *s, void *w);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045334(struct Descriptor *d);
extern u8 func_021BF7FC(u8 *p);
extern u32_021BB9E8 func_02040804(unsigned);
extern void func_021BC78C(u8 *,int,int,int,int);
extern u32_021BBA10 func_021BAC4C(u8 *);
extern void func_021BF814(u8 *p, u32_021BBA10 a, int b);
extern void func_0201C724(void *,u32_021BBA10,u32_021BBA10,u32_021BBA10,u32_021BBA10,u32_021BBA10,u16);
extern u32_021BBB0C func_0201C6C4(struct PrintSys *p, void *v);
extern int func_021BC7DC(u8 *p);
extern u32_021BBB84 func_0204B3F4(struct Obj *p);
extern void func_0204B3DC(struct Obj *p, u32_021BBB84 v);
extern void func_021BB224(unsigned, int *, int *);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32_021BBB84 which);
extern void func_0204B878(struct Obj *p, u16 value);
extern u16 func_0204B898(struct Obj *p);
extern u32_021BBC10 func_0204B98C(struct Actor *a);
extern void *func_02030734(unsigned, unsigned, int, const char *, u16);
extern u8 *func_021BF6D4(u8 *);
extern struct MsgBank *func_02045B38(u32_021BBC5C resident, u32_021BBC5C arcId, u32_021BBC5C fileId, u32_021BBC5C heapId);
extern void *func_02020D18(unsigned);
extern struct WinMgr *func_0202C9B4(u32_021BBC5C a0, u32_021BBC5C a1, u32_021BBC5C heap);
extern void func_0202CA0C(struct WinMgr *mgr);
extern void func_02030EAC(struct Node *n);
extern void func_02020D3C(struct D *p);
extern void func_0204B3B4(struct Obj *p);
extern unsigned int func_02045C04(struct Rec *rec);
extern unsigned int func_020452E8(struct Descriptor *d);
extern u32_021BBCF0 func_020307B0(void *p);
extern void func_021BC068(u8 *,void *);
extern void func_020498F4(void *a, u32_021BBD60 b, u32_021BBD60 c, u32_021BBD60 d, u32_021BBD60 e, u32_021BBD60 f, u16 g);
extern void func_02040618(u32_021BBD60,u32_021BBD60,u32_021BBD60);
extern u32_021BBD60 func_02049658(void *a, u32_021BBD60 b, u32_021BBD60 c, u32_021BBD60 d, u32_021BBD60 e, u32_021BBD60 f, u16 g);
extern u32_021BBD60 func_020450F0(u32_021BBD60,u32_021BBD60,u32_021BBD60,u32_021BBD60,u8,u8,u8);
extern void func_021BC120(u8 *);
extern void func_021BC160(void *);
extern void func_021BC23C(void *);
extern void func_021BC1B8(u8 *);
extern void func_0202CA3C(struct WinMgr *mgr, u32_021BBD60 idx, u32_021BBD60 bg, u32_021BBD60 w, u32_021BBD60 h);
extern void func_0202CB18(struct WinMgr *mgr, u32_021BBD60 idx, void *arc, u32_021BBD60 member, u32_021BBD60 alloc);
extern void func_0202CB4C(struct WinMgr *mgr, u32_021BBD60 idx, s8 x, s8 y);
extern void func_0202CEBC(struct WinMgr *mgr, u32_021BBD60 idx, void *a);
extern void func_0202CC58(struct WinMgr *mgr, u32_021BBD60 idx);
int func_021BB82C(u8 *p);
void func_021BB838(u8 *p);
int func_021BB854(u8 *p);
void func_021BB870(u8 *p);
int func_021BB8AC(u8 *p);
void func_021BB8B8(u8 *p);
void func_021BB8D8(u8 *p);
int func_021BB954(u8 *a0);
void func_021BB958(char *p);
void func_021BB9C0(u8 *p,int flag);
void func_021BB9E8(u8 *p,u32_021BB9E8 unused);
void func_021BBA10(u8 *p,unsigned n);
int func_021BBB0C(u8 *p, int a);
void func_021BBB84(u8 *p, unsigned index);
int func_021BBC10(u8 *p);
u8 *func_021BBC5C(void *a, u8 *b, void *c);
void func_021BBCF0(u8 *p);
void func_021BBD60(u8 *p,u32_021BBD60 a);
extern const char d_021C3C58[];

int func_021BB82C(u8 *p) { return func_021BC93C(p+0x18); }

void func_021BB838(u8 *p) { func_021BC868(p+24,2,63,124,0,12); }

int func_021BB854(u8 *p) { if (func_021BC898(p+24)!=0) { func_02040588(1,0); return 1; } return 0; }

/*
 * extent: includes the unlabelled forwarding stub at 0x021BB8AC.
 */
void func_021BB870(u8 *p)
{
    func_0207D63C((void *)0x04000050, 2, 63, 0, 16);
    func_02040588(1, 1);
    func_021BC868(p + 0x18, 2, 63, 0, 124, 12);
}

int func_021BB8AC(u8 *p)
{
    return func_021BC898(p + 0x18);
}

/*
 * extent: two bytes of zero alignment padding after return.
 */
void func_021BB8B8(u8 *p) { int v; if (func_021BF6DC(*(u8 * *)&((struct Obj22368 *)p)->f4)==0) v=-4; else v=0; func_02041EE4(1,0,v); }

/*
 * extent: two bytes of zero alignment padding after the return.
 */
void func_021BB8D8(u8 *p)
{
    void *handle;
    int i;
    handle = func_020490F4(43, 42);
    if (func_021BF6DC(*(u8 * *)&((struct Obj10275 *)p)->f4) == 0) {
        func_020499D4(handle, 27, 1, 0, 0, 0, 0, 42);
        for (i = 0; i < 12; i++) func_02045374(*(void **)(p + 0x60 + i * 4));
    } else {
        func_020499D4(handle, 26, 1, 0, 0, 0, 0, 42);
        func_02045374(((struct Obj10275 *)p)->f90);
        func_02045374(((struct Obj10275 *)p)->f94);
    }
    func_02049238(handle);
    func_02041B6C(1);
}


int func_021BB954(u8 *a0) { return 1; }

void func_021BB958(char *p)
{
    u32_021BB958 r7 = func_021BAC44((u8 *)(*(u32_021BB958 *)p));
    void *r4 = *(void **)(p + 0x94);
    void *r6 = func_020457B0(14, 42);
    func_021BF7D4((u8 *)(*(u32_021BB958 *)(p + 4)), r6);
    func_02043B5C(func_02045770(r4), 1);
    func_0201DD78(15, 14, 1);
    func_0201C7A4(func_02045770(r4), 0, 0, r6, (void *)r7);
    func_02045808(r6);
    func_02045374(r4);
    func_02045334(r4);
    func_02041B6C(1);
}

/*
 * prototype-evidence: BF7FC's legacy source says void; this caller uses r0
 * at 0x021BB9CC/0x021BB9CE, so its observed unsigned result is retained.
 */
void func_021BB9C0(u8 *p,int flag) { u32_021BB9C0 n=func_021BF7FC(*(u8 * *)&((struct Obj02460 *)p)->f4); if(n>22)n=22; if(flag)func_021BBA10(p,n);else func_021BB9E8(p,n); }

/*
 * extent: two bytes of zero alignment padding after return.
 * lever: bind the step arithmetic to a local before the outer call; the
 * inline argument form adds a saved register and changes scheduling.
 */
void func_021BB9E8(u8 *p,u32_021BB9E8 unused) { int step=-192-func_02040804(6); func_021BC78C(p+56,6,1,step,8); }

void func_021BBA10(u8 *p,unsigned n)
{
    u32_021BBA10 owner,font;
    void *str;
    int i,x,height,base;
    owner=func_021BAC4C(*(u8 * *)&((struct Obj02460 *)p)->f0);
    font=func_021BAC44(*(u8 * *)&((struct Obj02460 *)p)->f0);
    str=func_020457B0(15,42);
    func_02043B5C(func_02045770(((struct Obj02460 *)p)->f98),15);
    ((struct Obj02460 *)p)->f9C=((struct Obj02460 *)p)->f98;
    p[0xa0]=0;
    for(i=0;i<n;i++) {
        if(i%2==0) x=8; else x=128;
        func_021BF814(*(u8 * *)&((struct Obj02460 *)p)->f4,i,(int)str);
        func_0201C724((void *)owner,(u32_021BBA10)func_02045770(((struct Obj02460 *)p)->f9C),(s16_021BBA10)x,(s16_021BBA10)((i/2)*16),(u32_021BBA10)str,font,1103);
        p[0xa0]=1;
    }
    func_02045808(str);
    base=func_02040804(6)+192;
    height=((n+1)/2)*16+8;
    if(height>192) height=192;
    else if(height<48) height=48;
    func_021BC78C(p+0x38,6,1,height-base,8);
    func_02045374(((struct Obj02460 *)p)->f98);
    func_02041B6C(6);
    func_02040588(6,1);
}

int func_021BBB0C(u8 *p, int a)
{
    unsigned owner;
    int ready;
    int result;
    owner = func_021BAC4C(*(u8 * *)&((struct Obj05289 *)p)->f0);
    ready = 1;
    if (a) {
        if (p[0xa0]) {
            if (func_0201C6C4((struct PrintSys *)owner, (void *)((unsigned)func_02045770(((struct Obj05289 *)p)->f9C))) == 0) {
                func_02045334(((struct Obj05289 *)p)->f9C);
                p[0xa0] = 0;
            }
        }
        ready = p[0xa0] == 0 ? 1 : 0;
    }
    result = func_021BC7DC(p + 0x38);
    if (ready && result) {
        if (a == 0) func_02040588(6, 0);
        return 1;
    }
    return 0;
}

void func_021BBB84(u8 *p, unsigned index)
{
    Vec2 pos;
    int x, y;
    int state;
    ((struct Obj05290 *)p)->f58 = func_0204B3F4(((struct Obj05290 *)p)->f54);
    func_0204B3DC(((struct Obj05290 *)p)->f54, 1);
    if (func_021BF6DC(*(u8 * *)&((struct Obj05290 *)p)->f4) == 0 && index != 254) {
        pos.x = 48 + 80 * (index % 3U);
        pos.y = 64 + 24 * (index / 3U);
        state = 31;
    } else {
        state = 16;
        switch (index) {
        case 252: case 253: case 254: break;
        default:
            func_021BB224(index, &x, &y);
            pos.x = x + 18;
            pos.y = y + 56;
            state = 30;
            break;
        }
    }
    func_0204B404(((struct Obj05290 *)p)->f54, (const struct Vec2 *)(&pos), 0);
    func_0204B878(((struct Obj05290 *)p)->f54, state);
}

int func_021BBC10(u8 *p)
{
    u16 state = func_0204B898(((struct Obj04446 *)p)->f54);
    if (state != 31 && state != 30) return 1;
    if (func_0204B98C(((struct Obj04446 *)p)->f54) == 0) {
        func_0204B3DC(((struct Obj04446 *)p)->f54, ((struct Obj04446 *)p)->f58);
        func_0204B878(((struct Obj04446 *)p)->f54, func_021BF6DC(*(u8 * *)&((struct Obj04446 *)p)->f4) == 0 ? 4 : 6);
        *(int *)&((struct Obj04446 *)p)->f58 = 0;
        return 1;
    }
    return 0;
}

u8 *func_021BBC5C(void *a, u8 *b, void *c)
{
    u8 *p;
    p = func_02030734(42, 444, 1, d_021C3C58, 211);
    ((struct Obj01392 *)p)->f0 = a;
    *(u8 * *)&((struct Obj01392 *)p)->f4 = b;
    ((struct Obj01392 *)p)->f8 = c;
    *(u8 * *)&((struct Obj01392 *)p)->f1A0 = func_021BF6D4(b);
    ((struct Obj01392 *)p)->f14 = 0;
    ((struct Obj01392 *)p)->f18 = 0;
    ((struct Obj01392 *)p)->f1A4 = 0;
    ((struct Obj01392 *)p)->f30 = func_020457B0(128, 42);
    ((struct Obj01392 *)p)->f2C = func_02045B38(0, 2, 146, 42);
    ((struct Obj01392 *)p)->f34 = func_02020D18(42);
    ((struct Obj01392 *)p)->f198 = 0;
    ((struct Obj01392 *)p)->f19A = 0;
    ((struct Obj01392 *)p)->f1A8 = 0;
    ((struct Obj01392 *)p)->f1AC = 0;
    ((struct Obj01392 *)p)->f1B0 = 0;
    ((struct Obj01392 *)p)->f1B4 = func_0202C9B4(1, 1, 42);
    return p;
}

void func_021BBCF0(u8 *p)
{
    func_0202CA0C(((struct Obj01248 *)p)->f1B4);
    if (((struct Obj01248 *)p)->f1B0) func_02030EAC(((struct Obj01248 *)p)->f1B0);
    if (((struct Obj01248 *)p)->f1A4) func_02030EAC(((struct Obj01248 *)p)->f1A4);
    if (((struct Obj01248 *)p)->f34) func_02020D3C(((struct Obj01248 *)p)->f34);
    if (((struct Obj01248 *)p)->f14) func_0204B3B4(((struct Obj01248 *)p)->f14);
    if (((struct Obj01248 *)p)->f18) func_0204B3B4(((struct Obj01248 *)p)->f18);
    if (((struct Obj01248 *)p)->f2C) func_02045C04(((struct Obj01248 *)p)->f2C);
    if (((struct Obj01248 *)p)->f30) func_02045808(((struct Obj01248 *)p)->f30);
    func_020452E8(((struct Obj01248 *)p)->fC);
    func_020452E8(((struct Obj01248 *)p)->f10);
    func_020307B0(p);
}

/*
 * prototype: legacy 02040618 fourth input is unused by its full 02042360 target; caller sets only r0-r2.
 */
void func_021BBD60(u8 *p,u32_021BBD60 a)
{
    func_021BC068(p,(void *)a);
    func_020498F4((void *)a,25,0,0,0,0,42);
    func_020498F4((void *)a,25,4,0,0,0,42);
    ((struct Obj01922 *)p)->f19A=-192;
    func_02040618(4,3,((struct Obj01922 *)p)->f19A);
    func_02049658((void *)a,14,0,0,0,0,42);
    func_02049658((void *)a,14,4,0,0,0,42);
    *(u32_021BBD60 *)&((struct Obj01922 *)p)->fC=func_020450F0(0,3,1,28,4,0,1);
    *(u32_021BBD60 *)&((struct Obj01922 *)p)->f10=func_020450F0(4,3,1,28,4,0,1);
    func_02045374(((struct Obj01922 *)p)->fC);
    func_02045374(((struct Obj01922 *)p)->f10);
    func_021BC120(p);
    func_021BC160(p);
    func_021BC23C(p);
    func_021BC1B8(p);
    func_0202CA3C(((struct Obj01922 *)p)->f1B4,0,0,32,6);
    func_0202CB18(((struct Obj01922 *)p)->f1B4,0,(void *)a,25,0);
    func_0202CB4C(((struct Obj01922 *)p)->f1B4,0,0,0);
    func_0202CEBC(((struct Obj01922 *)p)->f1B4,0,((struct Obj01922 *)p)->fC);
    func_0202CC58(((struct Obj01922 *)p)->f1B4,0);
    ((struct Obj01922 *)p)->f1B8=0;
}
