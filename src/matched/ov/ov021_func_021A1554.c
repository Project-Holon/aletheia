/*
 * function: func_021A1554
 * address:  0x021A1554
 * packet:   pkt_ov021_021A1554
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F009C  0x021F009C  thumb  ov034
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern unsigned func_021F009C(char *p);

int func_021A1554(u32 *p)
{
    return func_021F009C((char *)p[8]);
}
