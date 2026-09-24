/*
 * function: func_021BAA14
 * address:  0x021BAA14
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Word getter at +0x14.
 */

typedef unsigned char u8;
typedef unsigned int u32;
u32 func_021BAA14(u8 *p)
{
    return *(u32 *)(p + 0x14);
}
