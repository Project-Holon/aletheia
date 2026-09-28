/*
 * function: func_0215D198
 * address:  0x0215D198
 * packet:   pkt_ov010_0215D198
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 */

extern int func_02017E1C(void *, int, int);

int func_0215D198(void *x)
{
    int a = func_02017E1C(x, 5, 0);
    int b = func_02017E1C(x, 0x6e, 0);
    if (a == 0x20 || a == 0x1d) {
        a = 0;
        if (func_02017E1C(x, 0x75, 0) == 0)
            return a;
    }
    switch (b) {
    case 2:
    default: return 0;
    case 0: return 1;
    case 1: return 2;
    }
}
