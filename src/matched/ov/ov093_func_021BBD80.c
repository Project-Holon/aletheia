/*
 * function: BTL_SERVER_FLOW_ResetInitStateAfterChange
 * address:  0x021BBD80
 * packet:   pkt_ov093_021BBD80
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;

void BTL_SERVER_FLOW_ResetInitStateAfterChange(u8 *p)
{
    p[0x77c] = 0;
}
