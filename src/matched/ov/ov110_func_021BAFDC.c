/*
 * function: PMSI_SEARCH_GetInputCount
 * address:  0x021BAFDC
 * packet:   pkt_ov110_021BAFDC
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte accessor: p[0xaf0].
 */

typedef unsigned char u8;

u8 PMSI_SEARCH_GetInputCount(u8 *p)
{
    return p[0xaf0];
}
