/*
 * function: func_021990D4
 * address:  0x021990D4
 * packet:   pkt_ov021_021990D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D4C1C     0x021D4C1C  data   a4
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;
typedef struct { int w[10]; } T40;
extern T40 d_021D4C1C;
extern void *func_0216D6D4(void *p);
extern void func_0216D8C0(u32, Vec *);
extern u32 func_0216D7CC(u32);

int func_021990D4(u32 a)
{
    Vec v = { 0, 0, 0 };
    T40 t;
    int *p;
    int i;

    t = d_021D4C1C;
    p = func_0216D6D4((void *)a);
    i = p[0];
    if (i >= 10) {
        i = 9;
    }
    v.y = t.w[i];
    func_0216D8C0(a, &v);
    p[0] = p[0] + 1;
    if (p[0] >= 20) {
        func_0216D7CC(a);
    }
    return 0;
}
