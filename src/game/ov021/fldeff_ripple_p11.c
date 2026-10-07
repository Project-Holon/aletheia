/*
 * file:     fldeff_ripple_p11.c
 * unit:     yes
 * function: func_021C47E8, func_021C47FC, func_021C483C, func_021C484C
 * address:  0x021C47E8
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
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_021AC1F0  0x021AC1F0  thumb  ov021
 *   func_020500F0  0x020500F0  arm
 *   func_02050278  0x02050278  arm
 *   func_02164280  0x02164280  thumb  ov010
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021DA9F0     0x021DA9F0  data  a4
 */
#include "../../matched/include/Obj12131.h"

struct BbActRec;
struct BbActSys;
struct X;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32_021C47E8;

typedef struct S { u32 w0; u8 b4, b5, b6, b7; u32 w8; } S;

typedef struct P { u32 f0; u32 f4; u16 f8; } P;

typedef int            s32_021C484C;

typedef struct Vec3 { s32_021C484C x, y, z; } Vec3;

typedef struct Arg { u32 a; Vec3 v; } Arg;

extern u32 func_020307B0(void *p);
extern u32 func_021ABE24(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern void func_021AC1F0(struct X *x, void *b);
extern u16 func_020500F0(struct BbActSys *o, const struct BbActRec *recs, u32 n);
extern void func_02050278(struct BbActSys *o, u32 first, u32 count);
extern void func_02164280(int x, int y, int *p);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(u32 a, u8 *b, u32 c, u32 d, Arg *e, u32 f);
void func_021C47E8(u32 a, u8 *p);
void func_021C47FC(P *p);
void func_021C483C(u8 *p);
void func_021C484C(u32 a, int b, int c, s32_021C484C d);
extern u8 d_021DA9F0[];


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021C47E8(u32 a, u8 *p)
{
    func_021C483C(p);
    func_020307B0(p);
}


void func_021C47FC(P *p)
{
    S s;
    u32 x = func_021ABE24((u8 *)p->f0);

    s.b4 = 2;
    s.b5 = 0x13;
    s.b6 = 0x10;
    s.b7 = 0x10;
    s.w8 = 1;
    s.w0 = (u32)func_02046E24(x, 0x2e);
    func_021AC1F0((struct X *)p->f0, (void *)s.w0);
    p->f8 = func_020500F0((struct BbActSys *)p->f4, (const struct BbActRec *)(&s), 1);
}


void func_021C483C(u8 *p)
{
    func_02050278((struct BbActSys *)(((struct Obj12131 *)p)->f4), ((struct Obj12131 *)p)->f8, 1);
}


void func_021C484C(u32 a, int b, int c, s32_021C484C d)
{
    Vec3 v;
    Arg s;

    func_02164280(b, c, (int *)(&v));
    v.y = d - 0x8000;
    v.z -= 0x5000;
    s.a = func_021ABEA0(a, 7);
    s.v = v;
    func_021ABFA8(a, d_021DA9F0, 0, 0, &s, 0);
}
