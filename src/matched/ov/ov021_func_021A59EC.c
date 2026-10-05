/*
 * function: func_021A59EC
 * address:  0x021A59EC
 * packet:   pkt_ov021_021A59EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A66F8  0x021A66F8  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;

extern u32 func_021A66F8(u32 p, u32 f);

u32 func_021A59EC(u32 p)
{
    u32 r = 1;
    if (func_021A66F8(p, 1) == 0) {
        r = 0;
    }
    return r;
}
