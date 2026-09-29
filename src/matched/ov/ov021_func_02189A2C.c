/*
 * function: func_02189A2C
 * address:  0x02189A2C
 * packet:   pkt_ov021_02189A2C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: tail-calls func_020120D8 with the word at offset 4 of its argument.
 *
 * symbols:
 *   func_020120D8  0x020120D8  thumb
 * Addresses are Black-image addresses.
 */

extern int func_020120D8(int a);

int func_02189A2C(int *a)
{
    return func_020120D8(a[1]);
}
