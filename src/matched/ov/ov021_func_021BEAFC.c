/*
 * function: func_021BEAFC
 * address:  0x021BEAFC
 * packet:   pkt_ov021_021BEAFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021BEE74  0x021BEE74  thumb  ov021
 *   func_021BEA6C  0x021BEA6C  thumb  ov021
 */

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
} Work;

extern void *func_020122C0(int a, int b, void (*cb)(void), int size);
extern Work *func_020124E8(void *task);
extern void func_021BEE74(void);
extern int func_021BEA6C(int a);

void *func_021BEAFC(int a, int b, int c, int d)
{
    void *t = func_020122C0(a, 0, func_021BEE74, 0x2c);
    Work *w = func_020124E8(t);
    w->f0 = a;
    w->f4 = b;
    w->f8 = c;
    w->f14 = d;
    w->fC = func_021BEA6C(c);
    return t;
}
