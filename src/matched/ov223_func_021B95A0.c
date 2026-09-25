/*
 * function: func_021B95A0
 * address:  0x021B95A0
 * packet:   pkt_ov223_021B95A0
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * This address is also matched as func_021B95A0 in ov217; the ov223 copy is a
 * distinct function and gets its own shard.
 *
 * symbols:
 *   func_020115EC  0x020115EC  thumb
 *
 * Addresses are Black-image addresses.
 */

extern int func_020115EC(int, int);

int func_021B95A0(int a0, int a1)
{
    return func_020115EC(a0, a1 / 2);
}
