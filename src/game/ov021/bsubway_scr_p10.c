/*
 * file:     bsubway_scr_p10.c
 * unit:     yes
 * function: func_021C8F7C, func_021C8FB8
 * address:  0x021C8F7C
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
 *   d_021DABA4  0x021DABA4  data  a4
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 */
struct Actor;
struct VecFx32;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 x, y, z; } V;

typedef struct { u32 a; V v; } T;

extern void func_0216D88C(const struct Actor *a, struct VecFx32 *v);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(u32 a, void *tbl, u32 c, u32 d, void *t, u32 f);
extern int func_021AC1AC(u32 a);
extern void func_021AC1CC(u32 a, u32 *p);
extern void func_020061E4(u32 id);
void func_021C8F7C(u32 a, u32 b);
void func_021C8FB8(u32 a, u32 *out);
extern u8 d_021DABA4[];

void func_021C8F7C(u32 a, u32 b)
{
    V pos;
    T t;
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&pos);
    t.a = func_021ABEA0(b, 0xb);
    t.v = pos;
    func_021ABFA8(b, d_021DABA4, 0, 0, &t, 0);
}

void func_021C8FB8(u32 a, u32 *out)
{
    u32 *r = (u32 *)func_021AC1AC(a);
    *out = r[0];
    func_021AC1CC(a, &r[1]);
    func_020061E4(0x6a2);
}
