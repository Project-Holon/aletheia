/*
 * function: BTL_SERVER_FLOW_DispatchTurnCheckEvent
 * address: 0x021C4910
 * packet: pkt_ov093_021C4910
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_PushVarFrame 0x021D74F8 thumb ov093
 *   BTL_EVENT_SetVarReadOnly 0x021D75EC thumb ov093
 *   BTL_EVENT_DispatchEventChecked 0x021D70F0 thumb ov093
 *   BTL_EVENT_PopVarFrame 0x021D7540 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void BTL_EVENT_PushVarFrame(int);
extern void BTL_EVENT_SetVarReadOnly(int, u32);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern void BTL_EVENT_PopVarFrame(int);
void BTL_SERVER_FLOW_DispatchTurnCheckEvent(u8 *p, u32 a, int k)
{
    BTL_EVENT_PushVarFrame(9667);
    BTL_EVENT_SetVarReadOnly(2, a);
    BTL_EVENT_DispatchEventChecked(p, k);
    BTL_EVENT_PopVarFrame(9670);
}
