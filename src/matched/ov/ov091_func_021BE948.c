/*
 * function: func_021BE948
 * address:  0x021BE948
 * packet:   pkt_ov091_021BE948
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

int func_021BE948(int a0, int a1, int a2, int a3)
{
    if (a0 == 0 && a2 < 0)
        return -1;
    if (a0 == 0xff && a2 > 0)
        return -1;
    if (a0 >= 100 && a3 == 0 && a2 > 0)
        return -1;
    if (a0 + a1 >= 0x1FE && a2 > 0)
        return -1;
    a0 += a2;
    if (a2 > 0 && a0 > 100 && a3 == 0)
        a0 = 100;
    else if (a0 < 0)
        a0 = 0;
    if (a0 + a1 > 0x1FE)
        a0 = 0x1FE - a1;
    return a0;
}
