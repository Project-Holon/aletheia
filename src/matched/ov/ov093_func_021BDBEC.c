/*
 * function: BTL_SERVER_FLOW_DispatchMemberInBeginEvent
 * address: 0x021BDBEC
 * packet: pkt_ov093_021BDBEC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_PushVarFrame 0x021D74F8 thumb ov093
 *   BTL_EVENT_DispatchEventChecked 0x021D70F0 thumb ov093
 *   BTL_EVENT_PopVarFrame 0x021D7540 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void BTL_EVENT_PushVarFrame(int);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern void BTL_EVENT_PopVarFrame(int);
void BTL_SERVER_FLOW_DispatchMemberInBeginEvent(u8 *p)
{
    BTL_EVENT_PushVarFrame(3173);
    BTL_EVENT_DispatchEventChecked(p, 86);
    BTL_EVENT_PopVarFrame(3175);
}
