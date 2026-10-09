/*
 * file:     union_comm_p06.c
 * unit:     yes
 * function: func_0217325C, func_021733C4, func_021733C8, func_02173400, func_02173404, func_02173408, func_02173420, func_021734A8, func_021734E0
 * address:  0x0217325C
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_0203D378  0x0203D378  arm
 *   func_02087C6C  0x02087C6C  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_020084F8  0x020084F8  thumb
 *   func_02008554  0x02008554  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008530  0x02008530  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_02008570  0x02008570  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_02009CB0  0x02009CB0  thumb
 *   func_021840C8  0x021840C8  thumb  ov022
 *   func_020307B0  0x020307B0  arm
 *   func_02183BE0  0x02183BE0  thumb  ov022
 *   func_0217505C  0x0217505C  thumb  ov012
 *   func_020056EC 0x020056EC thumb
 *   func_02173524 0x02173524 thumb ov012
 */
#include "../../matched/include/Obj02671.h"
#include "../../matched/include/Obj05917.h"
#include "../../matched/include/Obj09357.h"

struct Sub0200852CObj;
struct BigObj;
struct Ctx;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct Blob28 {
    u8 b[0x28];
} Blob28;

typedef struct Rec {
    u8  mac[6];
    u8  b6lo : 3;
    u8  b6bit : 1;
    u8  b6hi : 4;
    u8  b7lo : 3;
    u8  b7bit : 1;
    u8  used : 1;
    u8  b7hi : 3;
    u8  f8;
    u8  f9;
    u8  fA;
    u8  fB;
    u8  fC[0x10];
    u16 f1C;
    u16 f1E;
    u16 f20;
    u16 f22;
    u16 f24;
    u8  f26;
    u8  f27;
    Blob28 f28;
    u8  f50[0xc];
    u32 f5C;
    u32 f60;
} Rec;

typedef struct Local {
    u8  f0;
    u8  f1;
    u8  f2;
    u8  f3;
    u16 f4;
    u16 f6;
    u16 f8;
    u16 fA;
    u16 fC;
    u8  fE;
    u8  fF;
    u8  pad10[8];
    u8 *f18;
    u8  pad1C[4];
    u8 *f20;
    u8  pad24[0xc];
    Blob28 f30;
} Local;

typedef struct Save {
    void *f0;
    u8    pad4[8];
    u32   fC;
} Save;

typedef struct { u8 pad[0x288a]; u8 f : 1; } W;

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

typedef struct Work_021734E0 { struct { void *f0; } *head; } Work_021734E0;

extern void func_02082BCC(void *dst, int val, int size);
extern u32 func_0203D378(void);
extern void func_02087C6C(void *p);
extern void MI_CpuCopy8(const void *src, void *dst, int n);
extern int  func_0203D1B4(void);
extern u32 func_020084F8(void *dst, u32 value, u32 size);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201283C(const struct BigObj *p);
extern int func_02009CB0(int a0, int a1);
extern int func_021840C8(u8 *p);
extern u32 func_020307B0(void *p);
extern void func_02183BE0(void *p);
extern void func_0217505C(int *p, int x);
extern u32 func_020056EC(u32 range);
extern void func_02173524(Work_021734E0 *w,u8 *p);
void func_0217325C(u8 *self, Rec *out);
int func_021733C4(void);
int func_021733C8(u32 a, u32 b, W *p);
void func_02173400(void);
void func_02173404(void);
void func_02173408(u8 *w);
void func_02173420(Work_02173420 *w);
void func_021734A8(u8 *self, u32 id, u32 v);
void func_021734E0(Work_021734E0 *w);


/*
 * Fills the 0x64-byte record that func_021730F8 files into its table
 * (same bitfield at byte 7 bit 4, MAC at +0x64 of a table entry).
 */
void func_0217325C(u8 *self, Rec *out)
{
    Local *l = (Local *)(self + 0x2830);

    func_02082BCC(out, 0, 0x64);
    if (l->f20 != 0) {
        if (func_0203D378() == 1)
            func_02087C6C(out);
        else
            MI_CpuCopy8(l->f20 + 0x64, out, 6);
    } else if (l->f18 != 0) {
        MI_CpuCopy8(l->f18 + 0x64, out, 6);
    }
    out->b6lo = func_0203D1B4();
    out->f8 = 0x15;
    out->f9 = 2;
    out->fA = l->f1;
    out->b7hi = l->f2;
    out->fB = l->f0;
    func_020084F8((*(Save * *)&((struct Obj02671 *)self)->f0)->f0, (u32)out->fC, 8);
    out->b6hi = func_02008554((*(Save * *)&((struct Obj02671 *)self)->f0)->f0);
    out->b7bit = (u32)func_02008550((*(Save * *)&((struct Obj02671 *)self)->f0)->f0);
    out->f5C = func_02008530((*(Save * *)&((struct Obj02671 *)self)->f0)->f0);
    out->b7lo = l->fF;
    out->f1C = l->f4;
    out->f1E = l->f6;
    out->f20 = l->f8;
    out->f22 = l->fA;
    out->f24 = l->fC;
    out->f26 = func_0200856C((*(Save * *)&((struct Obj02671 *)self)->f0)->f0);
    out->f27 = func_02008570((*(Save * *)&((struct Obj02671 *)self)->f0)->f0);
    out->f28 = l->f30;
    func_02009CB0(func_0201283C(func_020120F4((const struct Ctx *)((*(Save * *)&((struct Obj02671 *)self)->f0)->fC))), (int)out->f50);
    if (((struct Obj02671 *)self)->f3528 != 0)
        out->b6bit = func_021840C8(((struct Obj02671 *)self)->f3528);
    else
        out->b6bit = 0;
    out->used = 1;
    self[0x2829] = 1;
}


int func_021733C4(void) { return 100; }


int func_021733C8(u32 a, u32 b, W *p)
{
    if (p->f == 1) {
        if (a == 0x14 || b == 0x14)
            return 0;
        if (a == b)
            return 1;
        return 0;
    }
    if (b >= 0x14 && b <= 0x1b)
        return 1;
    return 0;
}


void func_02173400(void) {}


void func_02173404(void) {}



/*
 * note:     unlabelled leaf (prints as .word in ov012.s); called from
 *           ov019 func_0217E904.
 */
void func_02173408(u8 *w)
{
    func_02082BCC(w + 0x2910, 0, 0x578);
}




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
