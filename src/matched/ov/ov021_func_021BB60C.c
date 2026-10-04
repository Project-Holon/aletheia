/*
 * function: func_021BB60C
 * address:  0x021BB60C
 * packet:   pkt_ov021_021BB60C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021BB808  0x021BB808  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V3;
typedef struct { u32 f0, f4, f8, fC; u16 f10[10]; u32 f24; } X;
extern int func_0216E1C4(int a0, int a1);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *v);
extern void func_021BB808(X *x, V3 *v);
extern void func_021AC1CC(u32 a, V3 *v);
void func_021BB60C(u32 a, X *x)
{
    V3 v;
    if (func_0216E1C4(x->fC, (int)x->f10) == 0) {
        x->f24 = 1;
        return;
    }
    func_0216D88C((const struct Actor *)x->fC, (struct VecFx32 *)&v);
    func_021BB808(x, &v);
    func_021AC1CC(a, &v);
}
