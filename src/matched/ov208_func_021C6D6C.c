/*
 * function: ov208_func_021C6D6C
 * address:  0x021C6D6C
 * packet:   pkt_ov208_021C6D6C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 */

typedef unsigned char u8;

void ov208_func_021C6D6C(int n, int i, u8 *lo, u8 *mid, u8 *hi)
{
    u8 a = i * 65 / n + 0x9c;
    u8 b = (i + 1) * 65 / n + 0x9c;
    u8 m;

    if (i == 0)
        m = a;
    else if (i == n - 1)
        m = b - 1;
    else if (a >= b)
        m = a;
    else
        m = (a + b - 1) / 2;
    if (lo != 0)
        *lo = a;
    if (hi != 0)
        *hi = b;
    if (mid != 0)
        *mid = m;
}
