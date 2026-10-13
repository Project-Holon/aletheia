/*
 * function: BTL_SERVER_FLOW_ResetInitState
 * address:  0x021BBC34
 * packet:   pkt_ov093_021BBC34
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;

void BTL_SERVER_FLOW_ResetInitState(u8 *p)
{
    p[0x77c] = 0;
    p[0x783] = 0;
}
