/*
 * function: func_02208D38
 * address:  0x02208D38
 * packet:   pkt_ov094_02208D38
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0209C2B0  0x0209C2B0  arm
 */

extern int func_0209C2B0(int a, int b);

int func_02208D38(int a, int b, int c)
{
    int r = func_0209C2B0(a * c, b);
    if (r == 0 && a != 0)
        r = 1;
    return r;
}
