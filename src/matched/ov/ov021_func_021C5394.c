/*
 * function: func_021C5394
 * address:  0x021C5394
 * packet:   pkt_ov021_021C5394
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the result word and optionally its argument.
 */

typedef unsigned char u8;
typedef unsigned int u32;

u32 func_021C5394(u8 *p, u32 *out)
{
    if (out != 0)
        *out = *(u32 *)(p + 0x78);
    return *(u32 *)(p + 0x74);
}
