/*
 * file:     pdw_postman_p11.c
 * unit:     yes
 * function: func_021B823C, func_021B8248, func_021B824C, func_021B8250, func_021B82F0, func_021B82F4, func_021B82F8, func_021B82FC, func_021B8300, func_021B8304, func_021B8308
 * address:  0x021B823C
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
 *   func_021B8848  0x021B8848  thumb
 *   func_021B9278  0x021B9278  thumb  ov021
 *   func_021B9280  0x021B9280  thumb  ov021
 */
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

typedef signed short   s16;

typedef signed int     s32;

typedef struct { u16 h0; u8 b2; u8 pad3; s16 h4; u16 h6; } Arg;

typedef struct Tbl { u16 f0; u16 f2; u8 pad4[0x10]; u8 *f14; } Tbl;

typedef struct Mgr {
    u8 pad00[0x20];
    Tbl tbl;
    u8 pad38[0x14];
    u32 f4C;
} Mgr;

extern void func_021B8848();
extern int func_021B9278(u8 *a, u32 b, const Tbl *t);
extern int func_021B9280(u8 *a, u32 arg2, u32 arg3, u8 *tbl);
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


/*
 * Tail-call thunk on the object 0x20 bytes in.
 *
 * Addresses are Black-image addresses.
 */
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
