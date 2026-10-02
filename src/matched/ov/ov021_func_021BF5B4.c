/*
 * function: func_021BF5B4
 * address:  0x021BF5B4
 * packet:   pkt_ov021_021BF5B4
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
 *   func_021BF76C  0x021BF76C  thumb  ov021
 */

typedef struct {
    int f0;
    int f4;
    unsigned char pad8[0x54];
    int f5C;
    int f60;
    int f64;
} Work;

extern void *func_020122C0(int a, int b, void (*cb)(void), int size);
extern Work *func_020124E8(void *task);
extern void func_021BF76C(void);

void *func_021BF5B4(int a, int b, int c, int d, int e, int f)
{
    void *t = func_020122C0(b, a, func_021BF76C, 0x68);
    Work *w = func_020124E8(t);
    w->f4 = c;
    w->f0 = b;
    w->f5C = d;
    w->f60 = e;
    w->f64 = f;
    return t;
}
