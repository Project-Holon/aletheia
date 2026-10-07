/*
 * function: func_02198A10
 * address:  0x02198A10
 * packet:   pkt_ov021_02198A10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
typedef struct { int x, y, z; } Vec;
extern void *func_0216D6D4(void *p);
extern void func_0216D8C0(u32, Vec *);
extern u32 func_0216D7CC(u32);

int func_02198A10(u32 a)
{
    int *p;

    p = func_0216D6D4((void *)a);
    p[0] = p[0] + p[1];
    {
        Vec v = { 0, 0, 0 };
        v.y = p[0];
        func_0216D8C0(a, &v);
    }
    if (p[0] / 0x8000 < 0x28) {
        return 0;
    }
    func_0216D7CC(a);
    return 1;
}
