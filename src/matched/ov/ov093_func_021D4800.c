/*
 * function: BTL_NET_FreeAfterPartyUse
 * address: 0x021D4800
 * packet: pkt_ov093_021D4800
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_NET_FreeRecvBuffers 0x021D4A6C thumb ov093
 */
extern void BTL_NET_FreeRecvBuffers(void);
void BTL_NET_FreeAfterPartyUse(void)
{
    BTL_NET_FreeRecvBuffers();
}
