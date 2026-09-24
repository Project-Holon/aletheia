/*
 * function: func_021C60AC
 * address:  0x021C60AC
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Row stride: rounds `n` up into 3-byte triples and scales by 4.
 */

typedef unsigned char u8;
typedef unsigned int u32;
int func_021C60AC(int n)
{
    return ((n + 2) / 3) * 4;
}
