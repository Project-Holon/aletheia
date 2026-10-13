/*
 * function: INTRUDE_FIELD_GetStartKind
 * address:  0x0217BF28
 * packet:   pkt_ov018_0217BF28
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;

u8 INTRUDE_FIELD_GetStartKind(u8 *p)
{
    return p[0xE];
}
