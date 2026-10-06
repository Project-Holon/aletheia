/*
 * function: func_0219A54C
 * address:  0x0219A54C
 * packet:   pkt_ov021_0219A54C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 */

typedef unsigned int u32;
typedef struct { u32 v; int n; } St;
extern void *func_0216D69C(void *p);
extern void func_0216D5E0(int a0, int a1);

void func_0219A54C(u32 a)
{
    St *p = func_0216D69C((void *)a);
    switch (p->n) {
    case 0:
        func_0216D5E0(a, (unsigned short)p->v);
        p->n = p->n + 1;
        break;
    case 1:
        break;
    }
}
