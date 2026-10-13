/*
 * function: BTL_SERVER_FLOW_ResetInitStateAfterSelect
 * address:  0x021BBD20
 * packet:   pkt_ov093_021BBD20
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;

void BTL_SERVER_FLOW_ResetInitStateAfterSelect(u8 *p)
{
    p[0x77c] = 0;
}
