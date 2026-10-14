/*
 * function: CircleGraph_GetPointRange
 * address:  0x021C1B28
 * packet:   pkt_ov217_021C1B28
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _ffltu  0x0209BE04  arm
 *   _ffixu  0x0209C494  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

void CircleGraph_GetPointRange(u8 *p, u8 *a, u8 *b)
{
    u8 x = (u8)(float)p[9];
    u8 y = (u8)(float)p[10];
    *a = x;
    *b = y;
}
