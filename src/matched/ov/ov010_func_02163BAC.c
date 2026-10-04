/*
 * function: func_02163BAC
 * address:  0x02163BAC
 * packet:   pkt_ov010_02163BAC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb
 *   func_0216DD1C  0x0216DD1C  thumb
 *   func_02163AF0  0x02163AF0  thumb
 */

extern void *func_0216D67C(void *a0);
extern int func_0216DD1C(int it, int *cur, int *v);
extern int func_02163AF0(int a, int b, int c, int d, int e, int f);

int func_02163BAC(int a, int b, int c, int d)
{
    int v;
    int cur;
    int it;

    v = 0;
    it = (int)func_0216D67C((void *)a);
    while (func_0216DD1C(it, &cur, &v) == 1) {
        if (a != cur) {
            if (func_02163AF0(a, cur, b, c, d, 1) == 1)
                return 1;
        }
    }
    return 0;
}
