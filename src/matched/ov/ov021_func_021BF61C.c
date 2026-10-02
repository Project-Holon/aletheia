/*
 * function: func_021BF61C
 * address:  0x021BF61C
 * packet:   pkt_ov021_021BF61C
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
 *   func_021BFA6C  0x021BFA6C  thumb  ov021
 */

typedef struct {
    int f0;
    int f4;
} Work;

extern void *func_020122C0(int a, int b, void (*cb)(void), int size);
extern Work *func_020124E8(void *task);
extern void func_021BFA6C(void);

void *func_021BF61C(int a, int b, int c)
{
    void *t = func_020122C0(b, a, func_021BFA6C, 0x68);
    Work *w = func_020124E8(t);
    w->f4 = c;
    w->f0 = b;
    return t;
}
