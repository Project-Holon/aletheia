/*
 * file:     worldtrade_adapter_p30.c
 * unit:     yes
 * function: func_022008F0, func_0220090C, func_0220093C, func_022009A4, func_02200A10, func_02200A7C, func_02200AB4, func_02200B34, func_02200BAC
 * address:  0x022008F0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02202840  0x02202840  thumb  ov135
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   d_022038FC 0x022038FC data a4
 *   func_02045CAC 0x02045CAC arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02202858 0x02202858 thumb ov135
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_022028C8 0x022028C8 thumb ov135
 *   func_020490F4 0x020490F4 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02049658 0x02049658 arm
 *   func_020499D4 0x020499D4 arm
 *   func_02049238 0x02049238 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02049B68  0x02049B68  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_020450F0  0x020450F0  arm
 *   func_021F9218  0x021F9218  thumb
 *   func_02041B6C  0x02041B6C  arm
 */
#include "../../matched/include/Obj12230.h"
#include "../../matched/include/Obj07254.h"
#include "../../matched/include/Obj02863.h"
#include "../../matched/include/Obj04139.h"
#include "../../matched/include/Obj00137.h"
#include "../../matched/include/Obj00345.h"

struct Descriptor;
struct CharBuf;
struct Cfg;
struct MsgBank;
struct U16Vec;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef struct {
    u8 pad0[0x32];
    u16 index;
    u8 pad34[0xb6c - 0x34];
    u32 bank;
    u8 padb70[0xd50 - 0xb70];
    u32 win[3];
    u8 padd5c[0xfa0 - 0xd5c];
    u8 queue[1];
} Work;

typedef signed char s8;

typedef signed short s16;

extern u32 func_02202840(u8 *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern u32 func_02202858(void *p, u8 b, void *s, u32 x, u32 y, void *out);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_022028C8(void *,u8,void *,u32,u32,u32,u16,void *);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_020499D4(void *, u32, u32, u32, u32, u32, u32, u16);
extern void func_02049238(void *);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_021F9218(void *win, void *bank, int idx, void *g);
extern void func_02041B6C(u32 v);
int func_022008F0(u8 *p);
int func_0220090C(u8 *p);
void func_0220093C(Work *p);
void func_022009A4(u8 *p, u32 n, int a2, int a3, int a4);
void func_02200A10(u8 *p, int k, int a2, int a3, int a4);
void func_02200A7C(void *p,void *bank,u32 b,u32 id,u32 fifth,void *out,u16 se);
void func_02200AB4(u8 *p);
void func_02200B34(u8 *p);
void func_02200BAC(u8 *p, u32 k);
extern const u32 d_022038FC[][3];


/*
 * When the sub-object at +0xfa0 is idle, re-arm the state word from +0x2c.
 */
int func_022008F0(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        ((struct Obj12230 *)p)->f28 = ((struct Obj12230 *)p)->f2C;
    }
    return 2;
}


/*
 * When the build query answers 0, bump the countdown at +0xdfc and roll state when it passes 0x2d.
 */
int func_0220090C(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        if (++((struct Obj07254 *)p)->fDFC > 0x2d) {
            ((struct Obj07254 *)p)->fDFC = 0;
            ((struct Obj07254 *)p)->f28 = ((struct Obj07254 *)p)->f2C;
        }
    }
    return 2;
}

/*
 * lever: struct window array avoids hoisting its base; initialize i before q.
 */
void func_0220093C(Work *p)
{
    void *q;
    const u32 *t;
    int i;
    t = d_022038FC[p->index];
    i = 0;
    q = p->queue;
    for (; i < 3; i++) {
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[i])), 1);
        func_02200A7C((void *)p->win[i], (void *)p->bank, 0, t[i], 0, q, 0x3dc1);
    }
}

void func_022009A4(u8 *p, u32 n, int a2, int a3, int a4)
{
    u32 w;
    func_02045CAC((struct MsgBank *)(((struct Obj02863 *)p)->fB6C), n, ((struct Obj02863 *)p)->fB88);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj02863 *)p)->fD40)), 0xf);
    w = ((struct Obj02863 *)p)->fD40;
    func_02045334((struct Descriptor *)w);
    func_02045374((struct Cfg *)w);
    func_020409B4(func_02045730((struct Descriptor *)w));
    func_0201F73C((void *)(((struct Obj02863 *)p)->fD40), 0, 1, 0xe);
    func_02202858((void *)(((struct Obj02863 *)p)->fD40), 0, ((struct Obj02863 *)p)->fB88, 0, 0, p + 0xfa0);
}


/*
 * Tear the object down: unhook the two sub-objects, release the +0xdd0 resource, wire the 0/1/e quad, then drain the four engine hooks.
 */
void func_02200A10(u8 *p, int k, int a2, int a3, int a4)
{
    u32 v;

    func_02045CAC((struct MsgBank *)(((struct Obj04139 *)p)->fB6C), k, (void *)(*(u32 *)(p + 0xb6c + 0x1c)));
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj04139 *)p)->fDD0)), 0xf);
    func_0201F73C((void *)(((struct Obj04139 *)p)->fDD0), 0, 1, 0xe);
    func_02202858((void *)(((struct Obj04139 *)p)->fDD0), 0, (void *)(*(u32 *)(p + 0xb6c + 0x1c)), 0, 0, p + 0xfa0);
    v = ((struct Obj04139 *)p)->fDD0;
    func_02045334((struct Descriptor *)v);
    func_02045374((struct Cfg *)v);
    func_020409B4(func_02045730((struct Descriptor *)v));
}

void func_02200A7C(void *p,void *bank,u32 b,u32 id,u32 fifth,void *out,u16 se) { void *s=func_02045EC0(bank,id); func_022028C8(p,b,s,0,0,0,se,out); func_02045808(s); }

void func_02200AB4(u8 *p)
{
    void *h;
    if (((struct Obj00137 *)p)->f12E0 == 1 && ((struct Obj00137 *)p)->f12E4 == 0) {
        h = func_020490F4(0x60, 0x48);
        func_02049BDC(h, 4, 4, 0x160, 0x160, 0xa0, 0x48);
        func_02049658(h, 0xe, 5, 0, 0x1c00, 0, 0x48);
        func_020499D4(h, 0x21, 5, 0, 0, 0, 0, 0x48);
        func_02049238(h);
        func_02049B40(0x17, 5, 4, 0x20, 0x20, 0x48);
    }
}


void func_02200B34(u8 *p)
{
    void *h;

    if (((struct Obj00137 *)p)->f12E0 == 1 && ((struct Obj00137 *)p)->f12E4 == 0) {
        h = func_020490F4(0x60, 0x48);
        func_02049B68(h, 5, 4, 0, 0x20, 0x48);
        func_02049658(h, 0xf, 6, 0, 0, 0, 0x48);
        func_020499D4(h, 0x22, 6, 0, 0, 0, 0, 0x48);
        func_02049238(h);
    }
    func_0204B3DC((struct Obj *)((struct Obj00137 *)p)->fD38, 1);
}


void func_02200BAC(u8 *p, u32 k)
{
    u32 v;

    ((struct Obj00345 *)p)->fDE0 = func_020450F0(4, 0xc, 0x13, 0x12, 4, 1, 1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj00345 *)p)->fDE0)), 0);
    func_021F9218((void *)(((struct Obj00345 *)p)->fDE0), (void *)(((struct Obj00345 *)p)->fB6C), k, p + 0xfa0);
    v = ((struct Obj00345 *)p)->fDE0;
    func_02045334((struct Descriptor *)v);
    func_02045374((struct Cfg *)v);
    func_02041B6C(func_02045730((struct Descriptor *)v));
}
