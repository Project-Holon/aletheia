/*
 * function: func_021D0FE8
 * address:  0x021D0FE8
 * packet:   pkt_ov021_021D0FE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_021D10A8  0x021D10A8  thumb  ov021
 *   func_021D1164  0x021D1164  thumb  ov021
 *   func_021D11B0  0x021D11B0  thumb  ov021
 */

typedef struct Work {
    void *f00;
    int f04;
    int f08;
    int f0C;
} Work;

extern void *func_020122C0(void *a, int b, void *cb, int size);
extern Work *func_020124E8(void *task);
extern void *func_0201210C(void *p);
extern void func_021D10A8(void);
extern int func_021D1164(int a, void *b);
extern void func_021D11B0(void);

void *func_021D0FE8(void *a, int unused, int c)
{
    void *task;
    Work *w;

    task = func_020122C0(a, 0, func_021D10A8, 0x10);
    w = func_020124E8(task);
    w->f00 = a;
    w->f04 = 0;
    w->f08 = c;
    w->f0C = func_021D1164(0x8015, func_0201210C(a));
    func_021D11B0();
    return task;
}
