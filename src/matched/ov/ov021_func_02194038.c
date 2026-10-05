/*
 * function: func_02194038
 * address:  0x02194038
 * packet:   pkt_02194038
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned int u32;

u32 func_02194038(char *a, int b, int c)
{
    return *(u32 *)(a + c * 0x20 + b * 4);
}
