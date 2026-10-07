/*
 * file:     weather_task_p67.c
 * unit:     yes
 * function: func_021A596C, func_021A59DC, func_021A59EC, func_021A5A00, func_021A5A0C, func_021A5A18, func_021A5A24
 * address:  0x021A596C
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
 *   func_021A3AB8  0x021A3AB8  thumb  ov021
 *   func_021A3CC0  0x021A3CC0  thumb  ov021
 *   func_021A6BB4  0x021A6BB4  thumb  ov021
 *   func_021A682C  0x021A682C  thumb  ov021
 *   func_021A5A68  0x021A5A68  thumb  ov021
 *   func_021A5B4C  0x021A5B4C  thumb  ov021
 *   func_021A5AD4  0x021A5AD4  thumb  ov021
 *   func_021A5B7C  0x021A5B7C  thumb  ov021
 *   func_021A6C30  0x021A6C30  thumb  ov021
 *   func_021A66F8  0x021A66F8  thumb  ov021
 *   func_0219E2C0  0x0219E2C0  thumb  ov021
 *   func_0219E2F4  0x0219E2F4  thumb  ov021
 *   func_0219E664  0x0219E664  thumb  ov021
 *   func_021B8028  0x021B8028  thumb  ov021
 */
#include "../../matched/include/Obj09572.h"
#include "../../matched/include/Obj18054.h"
#include "../../matched/include/Obj18055.h"
#include "../../matched/include/Obj18056.h"
#include "../../matched/include/Obj18057.h"
#include "../../matched/include/Obj18058.h"

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

extern u16 func_021A3AB8(u32 a, u32 v);
extern void func_021A3CC0(u32 a);
extern void func_021A6BB4(u8 *p, u32 a1, u32 a2);
extern u32  func_021A682C(u8 *p, u32 a1, u32 a2);
extern int func_021A5A68(u8 *p, u32 a, u32 b, u32 c, u32 d);
extern void func_021A5B4C(u32 *p, u32 a, int mode);
extern void func_021A5AD4(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_021A5B7C(u8 *p);
extern void func_021A6C30(u8 *p);
extern u32 func_021A66F8(u32 p, u32 f);
extern void func_0219E2C0(void *a, void *r);
extern void func_0219E2F4(void *o, void *out);
extern int func_0219E664(void *o, u32 k, void *buf);
extern void func_021B8028(u32 v);
void func_021A596C(u8 *p, u32 b, u32 c);
int func_021A59DC(u32 a);
u32 func_021A59EC(u32 p);
void func_021A5A00(u8 *p, void *r);
void func_021A5A0C(u8 *p, void *a1);
int func_021A5A18(u8 *p, u32 k, void *buf);
void func_021A5A24(u8 *p);


/*
 * Addresses are Black-image addresses.
 */
void func_021A596C(u8 *p, u32 b, u32 c)
{
    u32 t;
    u32 x;
    u32 y;

    t = func_021A3AB8(((struct Obj09572 *)p)->f14, c);
    func_021A3CC0(((struct Obj09572 *)p)->f14);
    func_021A6BB4(p + 0xc, t, ((struct Obj09572 *)p)->f1C);
    x = func_021A682C(p, t, 0);
    y = func_021A5A68(p, x, b, c, 0);
    func_021A5B4C((u32 *)p, c, y);
    func_021A5AD4(p, y, x, b, c, 0);
    func_021A5B7C(p);
    func_021A6C30(p + 0xc);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A59DC(u32 a)
{
if (((struct Obj18054 *)((u8 *)(a)))->f0 == 3) {
    return 1;
}
return 0;
}


u32 func_021A59EC(u32 p)
{
    u32 r = 1;
    if (func_021A66F8(p, 1) == 0) {
        r = 0;
    }
    return r;
}


/*
 * Tail-call thunk: forwards the object's word at +0x1c to func_0219E2C0.
 *
 * Addresses are Black-image addresses.
 */
void func_021A5A00(u8 *p, void *r)
{
    func_0219E2C0(((struct Obj18055 *)p)->f1C, r);
}


/*
 * Tail-call thunk: forwards the object's word at +0x1c to func_0219E2F4.
 *
 * Addresses are Black-image addresses.
 */
void func_021A5A0C(u8 *p, void *a1)
{
    func_0219E2F4((void *)(((struct Obj18056 *)p)->f1C), a1);
}


/*
 * Tail-call thunk: forwards the object's word at +0x1c to func_0219E664.
 *
 * Addresses are Black-image addresses.
 */
int func_021A5A18(u8 *p, u32 k, void *buf)
{
    return func_0219E664(((struct Obj18057 *)p)->f1C, k, buf);
}


/*
 * Tail-call thunk: forwards the object's word at +0x20 to func_021B8028.
 *
 * Addresses are Black-image addresses.
 */
void func_021A5A24(u8 *p)
{
    func_021B8028(((struct Obj18058 *)p)->f20);
}
