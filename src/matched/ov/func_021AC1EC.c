/*
 * function: func_021AC1EC
 * address:  0x021AC1EC
 * packet:   pkt_021AC1EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Setter: stores the second argument at +0x24.  Unlabelled in the listing;
 * called from func_021881D8.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

void func_021AC1EC(u32 *p, u32 v)
{
    p[9] = v;
}
