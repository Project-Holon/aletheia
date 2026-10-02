/*
 * function: ov021_func_021A13E4
 * address:  0x021A13E4
 * packet:   pkt_ov021_021A13E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0217CFE4  0x0217CFE4  thumb  ov018
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern u32 func_02188C80(u32);
extern u32 func_0217CFE4(u32);

void ov021_func_021A13E4(u32 *p)
{
    p[8] = func_0217CFE4(func_02188C80(p[5]));
}
