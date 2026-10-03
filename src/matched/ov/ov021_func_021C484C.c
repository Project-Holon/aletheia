/*
 * function: func_021C484C
 * address:  0x021C484C
 * packet:   pkt_ov021_021C484C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02164280  0x02164280  thumb  ov010
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021DA9F0     0x021DA9F0  data  a4
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef int            s32;

typedef struct Vec3 { s32 x, y, z; } Vec3;
typedef struct Arg { u32 a; Vec3 v; } Arg;

extern void func_02164280(int x, int y, Vec3 *p);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(u32 a, u8 *b, u32 c, u32 d, Arg *e, u32 f);
extern u8 d_021DA9F0[];

void func_021C484C(u32 a, int b, int c, s32 d)
{
    Vec3 v;
    Arg s;

    func_02164280(b, c, &v);
    v.y = d - 0x8000;
    v.z -= 0x5000;
    s.a = func_021ABEA0(a, 7);
    s.v = v;
    func_021ABFA8(a, d_021DA9F0, 0, 0, &s, 0);
}
