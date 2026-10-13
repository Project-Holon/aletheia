/*
 * function: BTL_NET_IsRelayedPartyReceived
 * address: 0x021D4784
 * packet: pkt_ov093_021D4784
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gBtlNet 0x021F3B88 data ov093 a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct S { u8 pad[0x3b04]; void *tblC[4]; };
extern struct S *gBtlNet;
int BTL_NET_IsRelayedPartyReceived(u32 a)
{
    if (gBtlNet->tblC[a]) return 1;
    return 0;
}
