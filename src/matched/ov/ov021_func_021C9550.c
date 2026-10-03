/*
 * function: func_021C9550
 * address:  0x021C9550
 * packet:   pkt_ov021_021C9550
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021DAC80     0x021DAC80  data  a4
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef struct V3 { int v[3]; } V3;
typedef struct Rec { u32 h; V3 pos; } Rec;

extern void func_0216D88C(u32, V3 *);
extern u32 func_0216D5F8(u32);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(u32, void *, u32, u32, Rec *, u32);
extern u32 d_021DAC80[];

void func_021C9550(u32 a, u32 b)
{
    V3 v;
    Rec r;

    func_0216D88C(a, &v);
    switch (func_0216D5F8(a)) {
    case 0:
        v.v[2] -= 0x10000;
        break;
    case 1:
        v.v[2] += 0x10000;
        break;
    case 2:
        v.v[0] -= 0x10000;
        break;
    case 3:
        v.v[0] += 0x10000;
        break;
    }
    r.h = func_021ABEA0(b, 0xc);
    r.pos = v;
    func_021ABFA8(b, d_021DAC80, 0, 0, &r, 0);
}
