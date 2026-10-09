/*
 * file:     pdw_postman_p13.c
 * unit:     yes
 * function: func_021B810C, func_021B821C, func_021B8220, func_021B8224, func_021B8230, func_021B823C, func_021B8248, func_021B824C, func_021B8250, func_021B82F0, func_021B82F4, func_021B82F8, func_021B82FC, func_021B8300, func_021B8304, func_021B8308
 * address:  0x021B810C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B91AC  0x021B91AC  thumb  ov021
 *   func_021B88DC  0x021B88DC  thumb  ov021
 *   func_021B977C  0x021B977C  thumb  ov021
 *   func_021B91F8  0x021B91F8  thumb  ov021
 *   func_021B9238  0x021B9238  thumb  ov021
 *   d_021DE298     0x021DE298  data
 *   func_021B87D8  0x021B87D8  thumb
 *   func_021B87FC  0x021B87FC  thumb
 *   func_021B8848  0x021B8848  thumb
 *   func_021B9278  0x021B9278  thumb  ov021
 *   func_021B9280  0x021B9280  thumb  ov021
 */
#include "../../matched/include/Obj18106.h"
#include "../../matched/include/Obj18107.h"
#include "../../matched/include/Obj18108.h"
#include "../../matched/include/Obj18109.h"
#include "../../matched/include/Obj18111.h"
#include "../../matched/include/Obj18112.h"
#include "../../matched/include/Obj18113.h"
#include "../../matched/include/Obj18114.h"
#include "../../matched/include/Obj18115.h"
#include "../../matched/include/Obj18116.h"
#include "../../matched/include/Obj18117.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

typedef struct { s32 x, y, z; } V3;

typedef struct { u16 a; u8 t; u8 c; s16 e; u16 d; } Out;

typedef struct { u16 f0; u16 f2; } Owner;

typedef struct Sub {
    u16 f0;
    u16 pad2;
    void *f4;
    u16 f8;
    u16 padA;
    s32 fC;
    u8 pad10[0x1C];
    u8 f2C;
    s8 f2D;
    u16 f2E;
    u16 f30;
    u8 f32;
    u8 f33;
    u8 f34;
    u8 pad35[3];
    V3 f38;
    V3 f44;
    u8 pad50[0xc];
    Out f5C;
    Out f64;
    u8 pad6C[8];
    u8 f74;
    u8 pad75[3];
    Owner *f78;
} Sub;

typedef struct { u16 h0; u8 b2; u8 pad3; s16 h4; u16 h6; } Arg;

typedef struct Tbl { u16 f0; u16 f2; u8 pad4[0x10]; u8 *f14; } Tbl;

typedef struct Mgr {
    u8 pad00[0x20];
    Tbl tbl;
    u8 pad38[0x14];
    u32 f4C;
} Mgr;

extern int func_021B91AC(u32 a);
extern int func_021B88DC(Sub *p, int dir, int d);
extern void func_021B977C(u8 *p);
extern void func_021B91F8(Sub *p, V3 *out);
extern void func_021B9238(Sub *p, Out *out);
extern u8 *func_021B87D8(u8 *p, u32 idx);
extern u8 *func_021B87FC(u8 *p, u32 idx);
extern void func_021B8848();
extern int func_021B9278(u8 *a, u32 b, const Tbl *t);
extern int func_021B9280(u8 *a, u32 arg2, u32 arg3, u8 *tbl);
void func_021B810C(Sub *o);
u32 func_021B821C(u8 *p);
u32 func_021B8220(u8 *p);
void func_021B8224(u8 *p, u32 a1);
void func_021B8230(u8 *p, u32 a1);
void func_021B823C(u8 *p, int k);
u32 func_021B8248(u8 *p);
u32 func_021B824C(u8 *p);
void func_021B8250(const Mgr *m, const Arg *src, Arg *out);
u16 func_021B82F0(u8 *p);
u32 func_021B82F4(u8 *p);
u32 func_021B82F8(u8 *p);
u32 func_021B82FC(u8 *p);
u32 func_021B8300(u8 *p);
u32 func_021B8304(u8 *p);
u32 func_021B8308(u8 *p);
extern const u8 d_021DE298[];



/*
 * The table byte is also func_021B88DC's third argument: the callee's
 * matched prototype is (p, dir, d), and the image leaves the ldrb value in
 * r2 untouched up to the call. That extra use keeps the byte live across
 * the f2D update, so its sign extension lands in a fresh register (r3).
 * See docs/idioms/a-byte-kept-live-into-a-call-argument-register-pushes-its-sign-extension-to-a-fresh-register.md.
 */
void func_021B810C(Sub *o)
{
    int res;
    u16 prev;
    u16 k;
    u8 d;
    s32 rem;

    if (o->f78->f2 == 0)
        return;
    if (o->f8 == 0)
        return;
    if (func_021B91AC((u32)o) == 0)
        return;
    res = 0;
    o->f34 = 0;
    if (o->f2C == 0)
        return;
    prev = o->f0;
    k = o->f2E;
    d = d_021DE298[o->f30];
    o->f2D += (s8)d;
    if (prev == 1)
        res = func_021B88DC(o, k, d);
    if (res != 0) {
        o->f32 = res;
        o->f33 = o->f30;
        o->f34 = 1;
        func_021B91F8(o, &o->f38);
    }
    if (prev != o->f0)
        func_021B977C((u8 *)o);
    if (o->f2D < 0x10 && res != 0)
        return;
    o->f2C = 0;
    o->f74 = 0;
    o->f64 = o->f5C;
    func_021B9238(o, &o->f5C);
    o->f44 = o->f38;
    rem = o->fC % 16;
    if (rem == 0)
        return;
    if (rem > 8)
        o->fC = o->fC + (16 - rem);
    else
        o->fC = o->fC - rem;
}



/*
 * Loads the 32-bit word at byte +0x10 of the object.
 */
u32 func_021B821C(u8 *p)
{
    return ((struct Obj18106 *)p)->f10;
}



u32 func_021B8220(u8 *p)
{
    return ((struct Obj18107 *)p)->f14;
}



/*
 * Tail-call thunk on the object 0x20 bytes in.
 *
 * Addresses are Black-image addresses.
 */
void func_021B8224(u8 *p, u32 a1)
{
    func_021B87D8(p + 0x20, a1);
}



void func_021B8230(u8 *p, u32 a1)
{
    func_021B87FC(p + 0x20, a1);
}



void func_021B823C(u8 *p, int k)
{
    func_021B8848(p + 0x20);
}



/*
 * Loads the 32-bit word at byte +0x4c of the object.
 */
u32 func_021B8248(u8 *p)
{
    return ((struct Obj18108 *)p)->f4C;
}



u32 func_021B824C(u8 *p)
{
    return ((struct Obj18109 *)p)->f1C;
}



/*
 * Twin of func_021B7DE0. The first call adds a zero-valued local to off,
 * which gives the early multiply, the spilled offset and the
 * `adds r0,r3,#0` copy. `const Mgr *m` lets the base load schedule into the
 * struct copy (`ldr r7,[r6,#0x34]` between the stores to a).
 */
void func_021B8250(const Mgr *m, const Arg *src, Arg *out)
{
    Arg a;
    u8 *base;
    s32 off;
    s32 x;
    s32 y;
    s32 v;
    s32 w;
    s32 pad;

    a = *src;
    base = m->tbl.f14;
    *out = a;
    off = a.h0 * 0x48;
    pad = 0;
    y = a.h6 << 4;
    x = a.h4 << 4;
    v = func_021B9278(base + (off + pad), m->f4C, &m->tbl);
    w = func_021B9280(base + off, y, v, (u8 *)(&m->tbl));
    if (y >= v)
        out->h6 = (v - 1) / 16;
    if ((x < 0 ? -x : x) > w) {
        if (x > 0)
            out->h4 = w / 16;
        else
            out->h4 = -w / 16;
    }
}



u16 func_021B82F0(u8 *p)
{
    return ((struct Obj18111 *)p)->f0;
}



/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
u32 func_021B82F4(u8 *p)
{
    return ((struct Obj18112 *)p)->f4;
}



/*
 * Loads the 32-bit word at byte +0xc of the object.
 */
u32 func_021B82F8(u8 *p)
{
    return ((struct Obj18113 *)p)->fC;
}



u32 func_021B82FC(u8 *p)
{
    return ((struct Obj18114 *)p)->f10;
}



/*
 * Loads the 32-bit word at byte +0x14 of the object.
 */
u32 func_021B8300(u8 *p)
{
    return ((struct Obj18115 *)p)->f14;
}



u32 func_021B8304(u8 *p)
{
    return ((struct Obj18116 *)p)->f18;
}



u32 func_021B8308(u8 *p)
{
    return ((struct Obj18117 *)p)->f1C;
}
