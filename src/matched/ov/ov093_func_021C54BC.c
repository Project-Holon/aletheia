/*
 * function: BTL_SERVER_FLOW_PushActionBlockedMessage
 * address: 0x021C54BC
 * packet: pkt_ov093_021C54BC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: Sole blocker of BTL_SERVER_FLOW_ProcAction; ordinary default-argument tail call.
 * extent: Next function 021C54C8 is already separately matched; 12-byte leaf.
 * semantics: Forwards both pointer inputs unchanged; literal argument 0x350.
 * symbols:
 *   BTL_SERVER_FLOW_PushMsgSetPoke 0x021C5D88 thumb ov093
 */
typedef unsigned char u8;
extern void BTL_SERVER_FLOW_PushMsgSetPoke(u8 *, u8 *, int);
void BTL_SERVER_FLOW_PushActionBlockedMessage(u8 *p, u8 *a)
{
    BTL_SERVER_FLOW_PushMsgSetPoke(p, a, 0x350);
}
