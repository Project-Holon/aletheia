/*
 * file:     fldeff_namipoke_p03.c
 * unit:     yes
 * function: func_021ACA5C, func_021ACA70, func_021ACB0C, func_021ACB38, func_021ACBB8, func_021ACBC8
 * address:  0x021ACA5C
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
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 *   func_021C6590  0x021C6590  thumb  ov021
 *   func_021C67D8  0x021C67D8  thumb  ov021
 *   func_021C6580  0x021C6580  thumb  ov021
 *   func_021C6628  0x021C6628  thumb  ov021
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D915C     0x021D915C  data  a4
 *   d_021D9184     0x021D9184  data  a4
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 */
struct X;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32_021ACA5C;

typedef signed short   s16;

typedef signed char    s8;

typedef struct X { u32 f0; u16 h4; u16 h6; u16 h8; u16 ha; } X;

typedef int            s32_021ACB38;

typedef struct Vec3 { s32_021ACB38 x, y, z; } Vec3;

typedef struct Arg { u32 a; u32 b; u16 c, d, e; } Arg;

extern u32 func_020307B0(void *p);
extern u32 func_021ABE18(u8 *p);
extern u32 func_021ABE24(u8 *p);
extern void func_021C6AE0(u32 a);
extern int func_021C6AF0(u32 a, u32 b, u32 c);
extern void func_021C6AF8(u32 *p, u32 v);
extern void func_021C6AFC(u32 *a, u32 b);
extern int func_021C6574(u32 a, u32 b, u32 c);
extern u32 func_021C6590(u32 a, u32 b, u32 c, u32 d);
extern void func_021C67D8(u32 a, u32 b, u32 c);
extern void func_021C6628(u32 a, u32 b);
extern void func_021C6580(u8 *p, int i);
extern int func_021ABEA0(u32 a, u32 b);
extern u16 func_0216D588(void *p);
extern u16 func_0216D590(void *p);
extern int func_0216D55C(int a0, int a1);
extern void func_021ABFA8(u32 a, u8 *b, Vec3 *c, u32 d, Arg *e, u32 f);
extern int func_021AC1E0(u32 a);
void func_021ACA5C(u32 a, u8 *p);
void func_021ACA70(u32 *a);
void func_021ACB0C(X *x);
void func_021ACB38(u32 a, u32 b, Vec3 *c, u32 d, u32 e);
void func_021ACBB8(u32 a, u8 v);
void func_021ACBC8(u32 a, int v);
extern u8 d_021D915C[];
extern u8 d_021D9184[];


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021ACA5C(u32 a, u8 *p)
{
    func_021ACB0C((struct X *)p);
    func_020307B0(p);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021ACA70(u32 *a)
{
    u32 buf[9];
    u16 *h = (u16 *)a;
    u32 r4 = func_021ABE18((u8 *)a[0]);
    u32 r6 = func_021ABE24((u8 *)a[0]);
    func_021C6AE0((u32)buf);
    func_021C6AF0((u32)buf, r6, 0x31);
    h[2] = func_021C6574(r4, (u32)buf, 0);
    h[4] = func_021C6590(r4, h[2], 0, 0);
    func_021C67D8(r4, h[4], 1);
    func_021C6AE0((u32)buf);
    func_021C6AF0((u32)buf, r6, 0x36);
    func_021C6AF8((u32 *)buf, r6);
    func_021C6AFC(buf, 0x6b);
    func_021C6AFC(buf, 0x85);
    h[3] = func_021C6574(r4, (u32)buf, 0);
    h[5] = func_021C6590(r4, h[3], 0, 0);
    func_021C67D8(r4, h[5], 1);
}


void func_021ACB0C(X *x)
{
    u32 h = func_021ABE18((u8 *)x->f0);

    func_021C6628(h, x->h8);
    func_021C6628(h, x->ha);
    func_021C6580((u8 *)h, x->h4);
    func_021C6580((u8 *)h, x->h6);
}


void func_021ACB38(u32 a, u32 b, Vec3 *c, u32 d, u32 e)
{
    Vec3 v;
    Arg s;
    s.a = func_021ABEA0(a, 3);
    s.b = d;
    s.c = func_0216D588((void *)d);
    s.d = func_0216D590((void *)d);
    s.e = b;
    v = *c;
    if (func_0216D55C(d, 0x2000) != 0)
        func_021ABFA8(a, d_021D915C, &v, e, &s, 0);
    else
        func_021ABFA8(a, d_021D9184, &v, e, &s, 0);
}


void func_021ACBB8(u32 a, u8 v)
{
    if (a != 0)
        ((u8 *)func_021AC1E0(a))[9] = v;
}


void func_021ACBC8(u32 a, int v)
{
    u8 *p;

    if (a != 0) {
        p = (u8 *)func_021AC1E0(a);
        if (v == 1)
            p[10] = 0;
        else
            p[10] = 1;
    }
}
