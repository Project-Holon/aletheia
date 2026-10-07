/*
 * file:     fldmmdl_p11.c
 * unit:     yes
 * function: func_0216CF6C, func_0216CFC4, func_0216D02C, func_0216D040, func_0216D0E8, func_0216D0F8, func_0216D1C8, func_0216D208
 * address:  0x0216CF6C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D948  0x0216D948  thumb  ov010
 *   func_0216D76C  0x0216D76C  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D508  0x0216D508  thumb  ov010
 *   func_0216E180  0x0216E180  thumb  ov010
 *   func_0216D584  0x0216D584  thumb  ov010
 *   func_0216D59C  0x0216D59C  thumb  ov010
 *   func_0216D5A4  0x0216D5A4  thumb  ov010
 *   func_0216D5AC  0x0216D5AC  thumb  ov010
 *   func_0216D5B4  0x0216D5B4  thumb  ov010
 *   func_0216D620  0x0216D620  thumb  ov010
 *   func_0216D65C  0x0216D65C  thumb  ov010
 *   func_0216D668  0x0216D668  thumb  ov010
 *   func_021642F8 0x021642F8 thumb ov010
 *   func_0216E3D8  0x0216E3D8  thumb  ov010
 *   func_0216D594  0x0216D594  thumb  ov010
 *   func_0216E39C  0x0216E39C  thumb  ov010
 *   func_02164304 0x02164304 thumb ov010
 *   func_0216E51C  0x0216E51C  thumb  ov010
 *   func_0216E544  0x0216E544  thumb  ov010
 *   func_0216D7F0  0x0216D7F0  thumb  ov010
 *   func_0216D7F4  0x0216D7F4  thumb  ov010
 *   func_0216D800  0x0216D800  thumb  ov010
 *   func_0216D80C  0x0216D80C  thumb  ov010
 *   func_0216D818  0x0216D818  thumb  ov010
 *   func_0216D824  0x0216D824  thumb  ov010
 *   func_0216D844  0x0216D844  thumb  ov010
 *   func_0216D85C  0x0216D85C  thumb  ov010
 *   func_0216D874  0x0216D874  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216D58C  0x0216D58C  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D5BC  0x0216D5BC  thumb  ov010
 *   func_0216DB98  0x0216DB98  thumb  ov010
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_0216D5D4 0x0216D5D4 thumb ov010
 *   func_0216D5D8 0x0216D5D8 thumb ov010
 *   func_0216D600 0x0216D600 thumb ov010
 */
#include "../../matched/include/Obj00113.h"
#include "../../matched/include/Obj02051.h"
#include "../../matched/include/Obj19118.h"
#include "../../matched/include/Obj09310.h"
#include "../../matched/include/Obj19119.h"

struct Ctx;
struct Rec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short   s16;

typedef int            s32;

typedef s32            fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Src {
    u16  x;
    u16  y;
    fx32 z;
} Src;

extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern int func_0216D948(int a0);
extern void func_0216D76C(void *a0);
extern int func_0216D55C(int a0, int a1);
extern int func_0216D508(int a0);
extern void func_0216E180(void *a0);
extern int func_0216D584();
extern int func_0216D59C();
extern int func_0216D5A4();
extern int func_0216D5AC();
extern int func_0216D5B4();
extern int func_0216D620(int a0, int a1, int a2);
extern int func_0216D65C();
extern int func_0216D668();
extern void func_021642F8(void *a0);
extern u32 func_0216E3D8(u32 a, u32 b);
extern void func_0216D594(void *p, u32 v);
extern void func_0216E39C(int a0, int a1, int a2);
extern void func_02164304(int, u8 *);
extern int func_0216E51C(void *a, int a1);
extern void func_0216E544(void *obj, VecFx32 *out);
extern void func_0216D7F0(void *obj, s16 v);
extern void func_0216D7F4(void *obj, s16 v);
extern void func_0216D800(void *obj, s16 v);
extern void func_0216D80C(void *obj, s16 v);
extern void func_0216D818(void *obj, s16 v);
extern void func_0216D824(void *obj, s16 v);
extern void func_0216D844(void *obj, s16 v);
extern void func_0216D85C(void *p, int v);
extern void func_0216D874(int a0, int a1);
extern void func_0216D89C(void *obj, const VecFx32 *v);
extern void func_0216D58C(void *p, u16 v);
extern u32 *func_0216D548(u32 *p, u32 v);
extern void *func_0216D568(void *p, u32 v);
extern int func_0216D5BC(void *p);
extern int func_0216DB98(void *a0, int a1);
extern void *func_0216D4B4(char *p);
extern int func_0216D5D4(void *p);
extern int func_0216D5D8(int a0, int a1);
extern int func_0216D600(int a0, u16 a1);
void func_0216CF6C(u32 x);
int func_0216CFC4(int a0, int a1);
void func_0216D02C(int a, u8 *p);
void func_0216D040(u8 *o, u16 *r, u32 b, u32 c);
void func_0216D0E8(int a, u8 *p);
void func_0216D0F8(void *obj, const u8 *a1);
void func_0216D1C8(u8 *p, u32 a, u32 b);
void func_0216D208(void *p);


void func_0216CF6C(u32 x)
{
    int n;
    u8 *o;
    u32 k = 2;

    n = 0;
    while (func_0216DD1C((struct Ctx *)x, (struct Rec **)(&o), (u32 *)(&n))) {
        if (func_0216D948(x) == 1)
            func_0216D76C(o);
        func_0216D55C((int)o, k);
        func_0216D508(*(u32 *)&((struct Obj00113 *)o)->f88);
        func_0216E180(o);
    }
}


int func_0216CFC4(int a0, int a1)
{
    int a2;
    int t4;
    int t5;

t4 = a1 + 0;
a1 = ((struct Obj02051 *)((char *)t4))->f0;
t5 = a0 + 0;
    a0 = func_0216D584(a0, a1);
loc_0216CFD0:
a1 = ((struct Obj02051 *)t4)->f4;
a0 = t5 + 0;
    a0 = func_0216D59C(a0, a1);
loc_0216CFD8:
a1 = ((struct Obj02051 *)t4)->f6;
a0 = t5 + 0;
    a0 = func_0216D5A4(a0, a1);
loc_0216CFE0:
a1 = ((struct Obj02051 *)t4)->f8;
a0 = t5 + 0;
    a0 = func_0216D5AC(a0, a1);
loc_0216CFE8:
a1 = ((struct Obj02051 *)t4)->fA;
a0 = t5 + 0;
    a0 = func_0216D5B4(a0, a1);
loc_0216CFF0:
a0 = ((struct Obj02051 *)t4)->fC;
a1 = ((struct Obj02051 *)t4)->fE;
a2 = 0;
*(u16 *)((char *)t5 + 0x16) = a0;
((struct Obj00113 *)t5)->f1A = a0;
a0 = t5 + 0;
    a0 = func_0216D620(a0, a1, a2);
loc_0216D000:
a1 = ((struct Obj02051 *)t4)->f10;
a0 = t5 + 0;
a2 = 1;
    a0 = func_0216D620(a0, a1, a2);
loc_0216D00A:
a1 = ((struct Obj02051 *)t4)->f12;
a0 = t5 + 0;
a2 = 2;
    a0 = func_0216D620(a0, a1, a2);
loc_0216D014:
a1 = 0x14;
a1 = *(short *)((char *)t4 + a1);
a0 = t5 + 0;
    a0 = func_0216D65C(a0, a1);
loc_0216D01E:
a1 = 0x16;
a1 = *(short *)((char *)t4 + a1);
a0 = t5 + 0;
    a0 = func_0216D668(a0, a1);
loc_0216D028:
    return a0;}

void func_0216D02C(int a, u8 *p) {
    if (((struct Obj19118 *)p)->f18 == 0) func_0216D0F8((void *)a, p);
    else func_021642F8((void *)a);
}


void func_0216D040(u8 *o, u16 *r, u32 b, u32 c)
{
    u32 id;
    s8 *p;

    func_0216CFC4((int)o, (int)r);
    id = func_0216E3D8(b, r[1]);
    func_0216D594(o, id);
    func_0216E39C(c, id, (int)o);
    p = (s8 *)(o + 0xe4);
    if (id == 0xb9) {
        o[0x7c] = r[7];
        o[0x7d] = r[8];
        if (o[0x7c] == 0)
            o[0x7c] += 1;
        if (o[0x7d] == 0)
            o[0x7d] += 1;
    } else {
        o[0x7c] = ((u8 *)p)[0xb];
        o[0x7d] = ((u8 *)p)[0xc];
    }
    o[0x7e] = p[0xd];
    o[0x7f] = p[0xe];
    o[0x80] = p[0xf];
    func_0216D02C((int)o, (u8 *)r);
}

/*
 * extent: zero alignment halfword at 0x0216D0F6, then labelled 0x0216D0F8.
 */
void func_0216D0E8(int a, u8 *p) {
    if (((struct Obj09310 *)p)->f18 == 1) func_02164304(a, p);
}


#pragma opt_propagation off

/*
 * final push 2026-10-05 G4L4: EXACT in c99 and c. The last argument of func_0216D7F4 is
 * a named int local (t) set from the field just before the call, with
 * #pragma opt_propagation off around the function. With propagation on the local is folded
 * into the call and the object copy is born before the argument chain (chain in r1, 13 B);
 * with it off the chain is born first and takes r0, as in the image. s16 local with the
 * pragma gave 9 B; int local without the pragma gave 13 B.
 */
void func_0216D0F8(void *obj, const u8 *a1)
{
    const Src *p = (const Src *)(a1 + 0x1c);
    VecFx32 v;
    s32 x;
    s32 y;
    fx32 z;

    if (func_0216E51C(obj, (int)a1) == 0) {
        x = p->x;
        y = p->y;
        z = p->z;
    } else {
        func_0216E544(obj, &v);
        x = (v.x >> 4) / 4096;
        y = (v.z >> 4) / 4096;
        z = v.y;
    }
    v.x = (x << 16) + 0x8000;
    func_0216D7F0(obj, p->x);
    func_0216D80C(obj, x);
    func_0216D844(obj, x);
    {
        int t = (p->z >> 4) / 4096;
        func_0216D7F4(obj, t);
    }
    v.y = z;
    x = (z >> 4) / 4096;
    func_0216D818(obj, x);
    func_0216D85C(obj, (s16)x);
    v.z = (y << 16) + 0x8000;
    func_0216D800(obj, p->y);
    func_0216D824(obj, y);
    func_0216D874((int)obj, (s16)y);
    func_0216D89C(obj, &v);
}

#pragma opt_propagation reset


void func_0216D1C8(u8 *p, u32 a, u32 b)
{
    ((struct Obj19119 *)p)->f88 = a;
    func_0216D58C(p, (u16)b);
    func_0216D548((u32 *)p, 1);
    func_0216D568(p, 0x1800);
    if (func_0216D5BC(p) == 1)
        func_0216DB98(p, 1);
    func_0216D4B4((char *)p);
}

void func_0216D208(void *p)
{
    func_0216D5D8((int)p, (u16)func_0216D5D4(p));
    func_0216D600((int)p, (u16)func_0216D5D4(p));
}
