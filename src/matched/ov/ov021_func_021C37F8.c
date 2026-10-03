/*
 * function: func_021C37F8
 * address:  0x021C37F8
 * packet:   pkt_ov021_021C37F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 func_02017E1C(void *, u32, u32);

int func_021C37F8(u32 a, u32 b)
{
    u32 x[2];
    u32 y[2];
    u32 m[2];
    int i;

    m[0] = a;
    m[1] = b;
    for (i = 0; i < 2; i++) {
        x[i] = func_02017E1C((void *)m[i], 5, 0);
        y[i] = func_02017E1C((void *)m[i], 7, 0);
    }
    if (x[0] != x[1]) {
        if (y[0] == y[1])
            return 0x14;
        return 0x32;
    }
    if (y[0] == y[1])
        return 0x32;
    return 0x46;
}
