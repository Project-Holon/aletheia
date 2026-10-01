/*
 * function: func_021AC760
 * address:  0x021AC760
 * packet:   pkt_ov021_021AC760
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: semantics and statement order match; residue is allocation.
 * The original keeps the literal 2 live in r6 (used as the func_021ABEA0
 * argument and shifted to 0x2000 for func_0216D55C and the v.z adjust),
 * which pushes c onto the stack (str r2, [sp, #8]) and adds r3 to the push;
 * this C folds the 2 (a local int k = 2 is propagated too). Stack order
 * tmp@0xc, s@0x10, v@0x34 now matches.
 *
 * symbols:
 *   d_021D90EC  0x021D90EC  data
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   func_02163E58  0x02163E58  thumb  ov010
 *   func_02164280  0x02164280  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D8AC  0x0216D8AC  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct V3 { int x, y, z; } V3;
typedef struct Arg {
    u32 f0;
    u32 f4;
    int f8;
    int fc;
    u16 h10;
    u16 h12;
    V3 pos;
    int f20;
} Arg;

extern u32 func_021ABEA0(u32 a, u32 b);
extern u16 func_0216D588(u32 a);
extern u16 func_0216D590(u32 a);
extern int func_0216D83C(u32 a);
extern int func_0216D86C(u32 a);
extern void func_02164280(s16 a, s16 b, V3 *out);
extern int func_0216D8AC(u32 a);
extern int func_0216D55C(u32 a, int b);
extern void func_02163E58(u32 a, V3 *v, int *out);
extern void func_021ABFA8(u32 a, u8 *b, u32 c, u32 d, Arg *e, u32 f);
extern u8 d_021D90EC[];

void func_021AC760(u32 a, u32 b, u32 c, int d)
{
    V3 v;
    Arg s;
    int tmp;
    int k = 2;

    if (d >= 8)
        return;
    s.f0 = func_021ABEA0(a, k);
    s.f4 = b;
    s.f20 = d;
    s.h10 = func_0216D588(b);
    s.h12 = func_0216D590(b);
    s.f8 = func_0216D83C(b);
    s.fc = func_0216D86C(b);
    func_02164280(s.f8, s.fc, &v);
    v.y = func_0216D8AC(b);
    if (func_0216D55C(b, k << 12) != 0) {
        v.y += 7 * 0x1000;
    } else {
        func_02163E58(b, &v, &tmp);
        v.y = tmp + 9 * 0x1000;
    }
    v.z -= k << 12;
    s.pos = v;
    func_021ABFA8(a, d_021D90EC, 0, c, &s, 0);
}
