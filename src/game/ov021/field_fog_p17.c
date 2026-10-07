/*
 * file:     field_fog_p17.c
 * unit:     yes
 * function: func_021A0860, func_021A08CC, func_021A0918, func_021A0974, func_021A0980, func_021A0A50, func_021A0B14, func_021A0B34
 * address:  0x021A0860
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
 *   _s32_div_f  0x0209C0A4  arm
 *   func_0207CB68  0x0207CB68  arm
 *   func_0207CAA4  0x0207CAA4  arm
 *   func_0207D184  0x0207D184  arm
 *   func_0207B65C  0x0207B65C  arm
 *   func_0207BC08  0x0207BC08  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   d_020A1B38  0x020A1B38  data  a2
 *   func_021A0818  0x021A0818  thumb  ov021
 */
#include "../../matched/include/Obj19697.h"
#include "../../matched/include/Obj19698.h"
#include "../../matched/include/Obj01498.h"
#include "../../matched/include/Obj02080.h"
#include "../../matched/include/Obj03124.h"

#define GX_RGB(r, g, b) ((u16)(((r) << 0) | ((g) << 5) | ((b) << 10)))
typedef signed short   s16;

typedef unsigned short u16;

typedef struct {
    s16 base;
    s16 delta;
} Lerp021A0860;

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct { s32 x, y, z; } V32;

typedef int BOOL;

typedef struct {
    u8 pad[0xF0];
    u16 cur;
    u16 max;
} Counter;

typedef signed char    s8;

extern void func_0207CB68(const s16 *a, u32 b, s16 *c);
extern s32 func_0207CAA4(const s16 *a, u32 b);
extern u16 func_0207D184(s32 x);
extern void func_0207B65C(void *o, void *m, s32 a, s32 b);
extern void func_0207BC08(void *m, void *n, void *o);
extern void func_0207CCA4(void *a, void *b);
extern void func_021A0818(s16 *o, s32 a, u32 b);
u16 func_021A0860(Lerp021A0860 *c, int t, int n);
void func_021A08CC(s32 *o, const s16 *in, u32 c);
void func_021A0918(u8 *a, s32 x, s32 y, s16 *out);
void func_021A0974(u32 a1, u32 a2, u32 a3);
void func_021A0980(u8 *a, u8 *b, u8 *c, u32 d);
void func_021A0A50(u8 *a, u8 *b, u32 c, u32 d);
void func_021A0B14(Counter *p);
int func_021A0B34(u32 a);
extern s16 d_020A1B38[];


/*
 * Colour interpolation: three {base, delta} s16 pairs, each channel
 * base + delta * t / n, packed GX_RGB. Each channel is an s16 local set
 * from the quotient and then `+=` its base; a single-expression
 * initialiser lets the compiler hoist all three divisions and evaluate
 * them right to left.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021A0860(Lerp021A0860 *c, int t, int n)
{
    s16 r = (s16)(c[0].delta * t / n);
    s16 g, b;

    r += c[0].base;
    g = (s16)(c[1].delta * t / n);
    g += c[1].base;
    b = (s16)(c[2].delta * t / n);
    b += c[2].base;
    return GX_RGB(r, g, b);
}


static inline void set(V32 *o, s32 x, s32 y, s32 z)
{
    o->x = x;
    o->y = y;
    o->z = z;
}


/*
 * Addresses are Black-image addresses.
 * The `const` on `in` is what puts its three loads ahead of the stores in
 * the original's order (in[2], in[1], in[0]; stores o[1], o[2], o[0]).
 */
void func_021A08CC(s32 *o, const s16 *in, u32 c)
{
    s16 v[3];

    set((V32 *)o, in[0], in[1], in[2]);
    func_0207CB68(in, c, v);
    set((V32 *)(o + 3), v[0], v[1], v[2]);
    ((struct Obj19697 *)o)->f18 = func_0207D184(func_0207CAA4(in, c));
}


/*
 * Addresses are Black-image addresses.
 */
void func_021A0918(u8 *a, s32 x, s32 y, s16 *out)
{
    s32 m[12];
    s32 v[3];
    s32 vx, vy, vz;
    u32 i;

    i = (u16)(((struct Obj19698 *)a)->f18 * x / y) >> 4;
    func_0207B65C(m, a + 0xc, d_020A1B38[i * 2], d_020A1B38[i * 2 + 1]);
    func_0207BC08(a, m, v);
    func_0207CCA4(v, v);
    vz = v[2];
    vy = v[1];
    vx = v[0];
    out[0] = vx;
    out[1] = vy;
    out[2] = vz;
}


/*
 * Calls func_021A0980(its own argument 1, its own argument 2, its own argument 3, 0x3c) and returns nothing.
 */
void func_021A0974(u32 a1, u32 a2, u32 a3)
{
    func_021A0980((u8 *)a1, (u8 *)a2, (u8 *)a3, 0x3c);
}


void func_021A0980(u8 *a, u8 *b, u8 *c, u32 d)
{
    u8 *p0;
    u8 *p1;
    u8 *p2;
    u8 *p3;
    int i;

    i = 0;
    ((struct Obj02080 *)a)->fF0 = i;
    ((struct Obj02080 *)a)->fF2 = d;
    ((struct Obj02080 *)a)->f0 = ((struct Obj03124 *)c)->f0;
    ((struct Obj02080 *)a)->f2 = ((struct Obj03124 *)c)->f2;
    p0 = a;
    p0 += 8;
    p1 = a;
    p1 += 0x38;
    p2 = b;
    p2 += 0x10;
    p3 = c;
    p3 += 0x10;
    for (; i < 4; i++) {
        func_021A0818((s16 *)(p0 + i * 12), *(u16 *)(b + 8 + i * 2), *(u16 *)(c + 8 + i * 2));
        func_021A08CC((s32 *)(p1 + i * 0x1c), (const s16 *)(p2 + i * 6), (u32)(p3 + i * 6));
        a[4 + i] = c[4 + i];
    }
    func_021A0818((s16 *)(a + 0xa8), ((struct Obj01498 *)b)->f28, ((struct Obj03124 *)c)->f28);
    func_021A0818((s16 *)(a + 0xb4), ((struct Obj01498 *)b)->f2A, ((struct Obj03124 *)c)->f2A);
    func_021A0818((s16 *)(a + 0xc0), ((struct Obj01498 *)b)->f2C, ((struct Obj03124 *)c)->f2C);
    func_021A0818((s16 *)(a + 0xcc), ((struct Obj01498 *)b)->f2E, ((struct Obj03124 *)c)->f2E);
    func_021A0818((s16 *)(a + 0xd8), ((struct Obj01498 *)b)->f30, ((struct Obj03124 *)c)->f30);
    func_021A0818((s16 *)(a + 0xe4), ((struct Obj01498 *)b)->f32, ((struct Obj03124 *)c)->f32);
}


void func_021A0A50(u8 *a, u8 *b, u32 c, u32 d)
{
    s32 i;

    ((struct Obj02080 *)a)->fF0 = 0;
    ((struct Obj02080 *)a)->fF2 = d;
    ((struct Obj02080 *)a)->f0 = ((struct Obj01498 *)b)->f0;
    ((struct Obj02080 *)a)->f2 = ((struct Obj01498 *)b)->f2;
    for (i = 0; i < 4; i++) {
        func_021A0818((s16 *)(a + 8 + i * 12), *(u16 *)(b + 8 + i * 2), c);
        func_021A08CC((s32 *)(a + 0x38 + i * 0x1c), (const s16 *)(b + 0x10 + i * 6), (u32)(b + 0x10 + i * 6));
        a[4 + i] = b[4 + i];
    }
    func_021A0818((s16 *)(a + 0xa8), ((struct Obj01498 *)b)->f28, c);
    func_021A0818((s16 *)(a + 0xb4), ((struct Obj01498 *)b)->f2A, c);
    func_021A0818((s16 *)(a + 0xc0), ((struct Obj01498 *)b)->f2C, c);
    func_021A0818((s16 *)(a + 0xcc), ((struct Obj01498 *)b)->f2E, c);
    func_021A0818((s16 *)(a + 0xd8), ((struct Obj01498 *)b)->f30, c);
    func_021A0818((s16 *)(a + 0xe4), ((struct Obj01498 *)b)->f32, c);
}


void func_021A0B14(Counter *p)
{
    if (p->cur < p->max)
        p->cur++;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A0B34(u32 a)
{
if (*(u16 *)((u8 *)((a + 240))) < *(u16 *)((u8 *)((a + 242)))) {
    return 1;
}
return 0;
}
