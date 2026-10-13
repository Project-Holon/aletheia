/*
 * function: INTRUDE_COMM_IsLinked
 * address:  0x021736D8
 * packet:   pkt_021736D8
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   INTRUDE_COMM_HasConnectedPeers  0x02175628  thumb
 */

int INTRUDE_COMM_HasConnectedPeers(void);

int INTRUDE_COMM_IsLinked(void)
{
    return INTRUDE_COMM_HasConnectedPeers();
}
