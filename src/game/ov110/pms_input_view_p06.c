/*
 * file:     pms_input_view_p06.c
 * unit:     yes
 * function: func_021B9A50, func_021B9B20, func_021B9BA4, func_021B9BAC, func_021B9BD0, func_021B9BEC
 * address:  0x021B9A50
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
 *   d_021C3C20 0x021C3C20 data a4
 *   d_020A1448 0x020A1448 data a4
 *   d_021C3714 0x021C3714 data a4
 *   func_02030734 0x02030734 arm
 *   func_021BF6D4 0x021BF6D4 thumb ov110
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0207D534 0x0207D534 arm
 *   func_021BF7D0 0x021BF7D0 thumb ov110
 *   func_02030DA8 0x02030DA8 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049238 0x02049238 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_021BCA30 0x021BCA30 thumb ov110
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0204A600 0x0204A600 arm
 *   func_021BCA84 0x021BCA84 thumb ov110
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021BADE8 0x021BADE8 thumb ov110
 *   func_020419E4 0x020419E4 arm
 *   func_0204A648 0x0204A648 arm
 *   d_021C3B94 0x021C3B94 data a4
 */
#include "../../matched/include/Obj01920.h"
#include "../../matched/include/Obj05284.h"
#include "../../matched/include/Obj06380.h"
#include "../../matched/include/Obj03239.h"
#include "../../matched/include/Obj13768.h"
#include "../../matched/include/Obj10264.h"

struct Cfg;
struct Bank;
struct Node;
struct PrintSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef signed char s8;

typedef int s32;

typedef struct { u32 entries[35]; } CallbackTable;

typedef struct { u8 *owner; u32 field4, field8; int id, slot, state; } Context;

extern void *func_02030734(u32,u32,int,const char *,u16);
extern u8 *func_021BF6D4(u8 *);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern u32 func_021BF7D0(u8 *);
extern void *func_02030DA8(u32,u32,void *,int);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049238(void *);
extern void func_02030EAC(struct Node *n);
extern void func_021BCA30(u8 *p);
extern unsigned int func_0204B1CC(struct Bank *bank);
extern void func_0204ADA4(unsigned int);
extern void func_0204A8D4(unsigned int);
extern void func_0204AFD8(unsigned int);
extern void func_0204A5AC(void);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern u32 func_020307B0(void *p);
extern void *func_020056A0(void (*fn)(void *, u8 *), u8 *p, int n);
extern void func_0204A600(void);
extern void func_021BCA84(unsigned char *);
extern unsigned int func_0201C4E4(struct PrintSys *);
extern void func_021BADE8(unsigned char *);
extern void func_020419E4(void);
extern void func_0204A648(void);
void *func_021B9A50(u8 *context,void *arg);
void func_021B9B20(u8 *p);
void *func_021B9BA4(void (*fn)(void *, u8 *), u8 *p, int n);
void func_021B9BAC(int a,unsigned char *b);
void func_021B9BD0(int a,unsigned char *b);
void func_021B9BEC(u8 *p, int id);
extern const char d_021C3C20[];
extern const u8 d_020A1448[];
extern const u8 d_021C3714[];
extern const CallbackTable d_021C3B94;

void *func_021B9A50(u8 *context,void *arg) {
    u8 *p;
    int i;
    p=func_02030734(42,0x90,0,d_021C3C20,0xdf);
    if(p!=0) {
        ((struct Obj01920 *)p)->f64=0;
        ((struct Obj01920 *)p)->f7C=0;
        *(u8 * *)&((struct Obj01920 *)p)->f18=context;
        ((struct Obj01920 *)p)->f1C=arg;
        *(u8 * *)&((struct Obj01920 *)p)->f78=func_021BF6D4(context);
        func_0204A48C((const struct Cfg *)d_020A1448,(u32)d_021C3714,42);
        ((struct Obj01920 *)p)->f20=func_0204B100(128,0,42);
        func_0203F8F4(42);
        func_02045088(42);
        func_0207D534((void *)0x0400006c,-16);
        func_0207D534((void *)0x0400106c,-16);
        ((struct Obj01920 *)p)->f0=func_02030DA8(func_021BF7D0(context),(u32)func_021B9BAC,p,2);
        ((struct Obj01920 *)p)->f4=func_021B9BA4((void (*)(void *, u8 *))func_021B9BD0,p,1);
        for(i=0;i<4;++i) *(void **)(p+8+i*4)=0;
        ((struct Obj01920 *)p)->f70=0;
        p[0x74]=0;
        ((struct Obj01920 *)p)->f84=0;
        ((struct Obj01920 *)p)->f88=0;
        ((struct Obj01920 *)p)->f8C=func_020490F4(43,42);
    }
    return p;
}

void func_021B9B20(u8 *p) {
    int i, j;
    if (p) {
        func_02049238(((struct Obj06380 *)p)->f8C);
        for (i=0; i<4; ++i) {
            void *r = *(void **)(p+8+i*4);
            if (r) func_02030EAC(r);
        }
        func_02030EAC(((struct Obj06380 *)p)->f0);
        func_02030EAC(((struct Obj06380 *)p)->f4);
        func_021BCA30(((struct Obj06380 *)p)->f64);
        func_0204B1CC(((struct Obj06380 *)p)->f20);
        for (j=0; j<2; ++j) {
            u8 *r = p+j*12;
            func_0204ADA4(((struct Obj05284 *)r)->f24);
            func_0204A8D4(((struct Obj05284 *)r)->f28);
            func_0204AFD8(((struct Obj05284 *)r)->f2C);
            func_0204ADA4(((struct Obj05284 *)r)->f3C);
            func_0204A8D4(((struct Obj05284 *)r)->f40);
            func_0204AFD8(((struct Obj05284 *)r)->f44);
        }
        func_0204A5AC();
        func_020450C8();
        func_0203F9B4();
        func_020307B0(p);
    }
}

void *func_021B9BA4(void (*fn)(void *, u8 *), u8 *p, int n) { return func_020056A0(fn, p, n); }

void func_021B9BAC(int a,unsigned char *b) { func_0204A600(); if(((struct Obj03239 *)b)->f64) func_021BCA84(((struct Obj03239 *)b)->f64); if(((struct Obj03239 *)b)->f7C) { func_0201C4E4(*(struct PrintSys * *)&((struct Obj03239 *)b)->f7C); func_021BADE8(b); } }

void func_021B9BD0(int a,unsigned char *b) { if(((struct Obj13768 *)b)->f84) ((struct Obj13768 *)b)->f84=0; func_020419E4(); func_0204A648(); }

void func_021B9BEC(u8 *p, int id) {
    CallbackTable table;
    int i;
    Context *q;
    table = d_021C3B94;
    if (id >= 35) return;
    q = func_02030734(42, 24, 0, d_021C3C20, 493);
    if (!q) return;
    q->state = 0;
    q->id = id;
    q->owner = (u8 *)p;
    q->field4 = *(u32 *)&((struct Obj10264 *)p)->f18;
    q->field8 = ((struct Obj10264 *)p)->f1C;
    for (i=0; i<4; ++i) {
        if (!*(void **)(p+i*4+8)) {
            q->slot = i;
            *(void **)((u32)p+i*4+8) = func_02030DA8(func_021BF7D0(*(u8 * *)&((struct Obj10264 *)p)->f18), table.entries[id], q, 1);
            return;
        }
    }
}
