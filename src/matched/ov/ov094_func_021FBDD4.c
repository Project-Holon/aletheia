/*
 * function: func_021FBDD4
 * address:  0x021FBDD4
 * packet:   pkt_ov094_021FBDD4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020113B0  0x020113B0  thumb
 */
extern void func_020113B0(int, int);

void func_021FBDD4(int a, int b, int c, int op, int e)
{
    int t = 0;

    switch (op) {
    case 0:
        if (b == c)
            t = 1;
        break;
    case 1:
        if (b != c)
            t = 1;
        break;
    case 2:
        if (b < c)
            t = 1;
        break;
    case 3:
        if (b > c)
            t = 1;
        break;
    case 4:
        if (b <= c)
            t = 1;
        break;
    case 5:
        if (b >= c)
            t = 1;
        break;
    }
    if (t == 1)
        func_020113B0(a, *(int *)(a + 0x14) + e);
}
