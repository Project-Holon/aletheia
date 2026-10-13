/*
 * function: BTL_NET_ResetAfterParty
 * address:  0x021D4500
 * packet:   pkt_ov093_021D4500
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_NET_ResetReplySlots  0x021D4CEC  thumb  ov093
 *   BTL_NET_FreeRecvBuffers  0x021D4A6C  thumb  ov093
 */

void BTL_NET_ResetReplySlots(void);
void BTL_NET_FreeRecvBuffers(void);

void BTL_NET_ResetAfterParty(void)
{
    BTL_NET_ResetReplySlots();
    BTL_NET_FreeRecvBuffers();
}
