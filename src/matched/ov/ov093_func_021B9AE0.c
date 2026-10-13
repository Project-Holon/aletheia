/*
 * function: BTL_MAIN_GetPosParity
 * address:  0x021B9AE0
 * packet:   pkt_021B9AE0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent 12, compiled 10, trailing padding)
 */

unsigned char BTL_MAIN_GetPosParity(unsigned int x)
{
    return x & 1;
}
