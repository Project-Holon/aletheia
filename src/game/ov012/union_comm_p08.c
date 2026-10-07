/*
 * file:     union_comm_p08.c
 * unit:     yes
 * function: func_02173420, func_021734A8, func_021734E0
 * address:  0x02173420
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02183BE0  0x02183BE0  thumb  ov022
 *   func_0217505C  0x0217505C  thumb  ov012
 *   func_02082BCC 0x02082BCC arm
 *   func_020056EC 0x020056EC thumb
 *   func_02173524 0x02173524 thumb ov012
 */
#include "../../matched/include/Obj05917.h"
#include "../../matched/include/Obj09357.h"

typedef unsigned char u8;

typedef struct {
    struct { int pad[3]; int f0c; } *head;
    u8 pad[0x3528 - 4];
    void *f3528;
    u8 pad2[0x3534 - 0x352C];
    void *f3534;
    void *f3538;
    void *f353C;
    void *f3540;
    void *f3544;
    u8 pad3[0x355C - 0x3548];
    void *f355C;
} Work_02173420;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct Work_021734E0 { struct { void *f0; } *head; } Work_021734E0;

extern u32 func_020307B0(void *p);
extern void func_02183BE0(void *p);
extern void func_0217505C(int *p, int x);
extern void func_02082BCC(void *p,u32 v,u32 n);
extern u32 func_020056EC(u32 range);
extern void func_02173524(Work_021734E0 *w,u8 *p);
void func_02173420(Work_02173420 *w);
void func_021734A8(u8 *self, u32 id, u32 v);
void func_021734E0(Work_021734E0 *w);


void func_02173420(Work_02173420 *w)
{
    w->f353C = 0;
    if (w->f3540 != 0) {
        func_020307B0(w->f3540);
        w->f3540 = 0;
    }
    if (w->f3544 != 0) {
        func_020307B0(w->f3544);
        w->f3544 = 0;
    }
    if (w->f3538 != 0) {
        func_020307B0(w->f3538);
        w->f3538 = 0;
    }
    if (w->f3534 != 0) {
        func_020307B0(w->f3534);
        w->f3534 = 0;
    }
    if (w->f3528 != 0) {
        func_02183BE0(w->f3528);
        w->f3528 = 0;
    }
    if (w->f355C != 0) {
        func_0217505C(w->f355C, w->head->f0c);
        w->f355C = 0;
    }
}

void func_021734A8(u8 *self, u32 id, u32 v) { u8 *p; p=self+0x2830; switch(id) { case 0: ((struct Obj05917 *)p)->f14=v; return; case 1: ((struct Obj05917 *)p)->f18=v; return; case 2: ((struct Obj05917 *)p)->f1C=v; return; case 3: ((struct Obj05917 *)p)->f20=v; return; case 4: *p=v; } }

void func_021734E0(Work_021734E0 *w) { u8 *p; p=(u8 *)w+0x2830; func_02082BCC(p,0,0x7c); ((struct Obj09357 *)p)->fC=func_020056EC(0xffff); p[0xf]=1; p[1]=2; func_02173524(w,p+0x14); }
