/*
 * function: func_021BFC54
 * address:  0x021BFC54
 * packet:   pkt_021BFC54
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

int func_021BFC54(int a, int *out, char *buf, int n)
{
    if (a == 0)
        return 0;
    if (out == 0)
        return 0;
    if (buf == 0)
        return 0;
    if (n <= 0)
        return 0;
    out[0] = a;
    out[1] = (int)buf;
    out[2] = n;
    out[3] = 0;
    out[4] = 0;
    out[5] = 0;
    out[6] = 1;
    out[7] = 1;
    out[8] = 0;
    *buf = 0;
    return 1;
}
