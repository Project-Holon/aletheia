/*
 * function: func_021ADD7C
 * address:  0x021ADD7C
 * packet:   pkt_ov021_021ADD7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021ABE8C  0x021ABE8C  thumb  ov021
 *   func_021ABE30  0x021ABE30  thumb  ov021
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021D9290     0x021D9290  data  a4
 */

typedef unsigned char u8;
typedef int s32;

typedef struct Vec3 { s32 x, y, z; } Vec3;
typedef struct Arg { unsigned a; Vec3 v; } Arg;

extern u8 d_021D9290[];

struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *v);
extern int func_021ABE8C(int a, int b);
extern void func_021ABE30(int a, int *b, int c);
typedef unsigned int   u32;
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(int a, u8 *b, int c, int d, Arg *e, int f);

void func_021ADD7C(int a, int b)
{
    Vec3 v;
    Arg s;
    int n;

    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&v);
    v.y += 0x1000;
    v.z += 0xc000;
    if (func_021ABE8C(b, 10) == 0) {
        n = 10;
        func_021ABE30(b, &n, 1);
    }
    s.a = func_021ABEA0(b, 10);
    s.v = v;
    func_021ABFA8(b, d_021D9290, 0, 0, &s, 0);
}
