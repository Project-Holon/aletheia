/*
 * function: func_021BD56C
 * address:  0x021BD56C
 * packet:   pkt_ov217_021BD56C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * This address is also matched as func_021BD56C in ov208; the ov217 copy is a
 * distinct function and gets its own shard.
 *
 * symbols:
 *   func_021C2A08  0x021C2A08  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

extern void func_021C2A08(int);

void func_021BD56C(int *p)
{
    int i;
    for (i = 0; i < 6; i++)
        func_021C2A08(p[i + 0x27]);
}
