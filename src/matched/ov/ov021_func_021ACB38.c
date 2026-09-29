/*
 * function: func_021ACB38
 * address:  0x021ACB38
 * packet:   pkt_ov021_021ACB38
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D915C     0x021D915C  data  a4
 *   d_021D9184     0x021D9184  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

typedef struct Vec3 { s32 x, y, z; } Vec3;
typedef struct Arg { u32 a; u32 b; u16 c, d, e; } Arg;

extern u32 func_021ABEA0(u32 a, u32 b);
extern u16 func_0216D588(u32 a);
extern u16 func_0216D590(u32 a);
extern int func_0216D55C(u32 a, u32 b);
extern void func_021ABFA8(u32 a, u8 *b, Vec3 *c, u32 d, Arg *e, u32 f);
extern u8 d_021D915C[];
extern u8 d_021D9184[];

void func_021ACB38(u32 a, u32 b, Vec3 *c, u32 d, u32 e)
{
    Vec3 v;
    Arg s;
    s.a = func_021ABEA0(a, 3);
    s.b = d;
    s.c = func_0216D588(d);
    s.d = func_0216D590(d);
    s.e = b;
    v = *c;
    if (func_0216D55C(d, 0x2000) != 0)
        func_021ABFA8(a, d_021D915C, &v, e, &s, 0);
    else
        func_021ABFA8(a, d_021D9184, &v, e, &s, 0);
}
