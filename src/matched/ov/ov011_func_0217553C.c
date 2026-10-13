/*
 * function: INTRUDE_COMM_ClearRequestResult
 * address:  0x0217553C
 * packet:   pkt_ov011_0217553C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save): clears the byte at +0x157.
 */

typedef unsigned char u8;

void INTRUDE_COMM_ClearRequestResult(u8 *p)
{
    p[0x157] = 0;
}
