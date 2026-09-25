/*
 * function: func_021BC5D4
 * address:  0x021BC5D4
 * packet:   pkt_ov217_021BC5D4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * This address is also matched as func_021BC5D4 in ov021; the ov217 copy is a
 * distinct function and gets its own shard.
 *
 * symbols:
 *   func_021C29F0  0x021C29F0  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

extern void func_021C29F0(int);

void func_021BC5D4(int *p)
{
    int i;
    for (i = 0; i < 6; i++)
        func_021C29F0(p[i + 0x27]);
}
