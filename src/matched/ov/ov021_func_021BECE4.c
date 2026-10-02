/*
 * function: func_021BECE4
 * address:  0x021BECE4
 * packet:   pkt_ov021_021BECE4
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
 *   func_021BF3BC  0x021BF3BC  thumb  ov021
 *   func_021BEA6C  0x021BEA6C  thumb  ov021
 */

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
} Work;

extern void *func_020122C0(int a, int b, void (*cb)(void), int size);
extern Work *func_020124E8(void *task);
extern void func_021BF3BC(void);
extern int func_021BEA6C(int a);

void *func_021BECE4(int a, int b)
{
    void *t = func_020122C0(a, 0, func_021BF3BC, 0x2c);
    Work *w = func_020124E8(t);
    w->f0 = a;
    w->f4 = b;
    w->f8 = 6;
    w->fC = func_021BEA6C(6);
    return t;
}
