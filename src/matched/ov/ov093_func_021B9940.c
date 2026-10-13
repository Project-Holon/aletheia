/*
 * function: BTL_SIDE_GetPokeById
 * address:  0x021B9940
 * packet:   pkt_021B9940
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent 12, compiled 10, trailing padding)
 */

typedef unsigned char u8;

u8 *BTL_SIDE_GetPokeById(char *p, u8 i)
{
    return *(u8 **)(p + i * 4 + 0x84);
}
