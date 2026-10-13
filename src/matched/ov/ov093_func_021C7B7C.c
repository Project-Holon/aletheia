/*
 * function: BTL_SERVER_FLOW_NotifyAbilityChangedEvent
 * address: 0x021C7B7C
 * packet: pkt_ov093_021C7B7C
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
extern void BTL_EVENT_PushVarFrame(int);
extern void BTL_EVENT_SetVarReadOnly(int, unsigned int);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern void BTL_EVENT_PopVarFrame(int);
void BTL_SERVER_FLOW_NotifyAbilityChangedEvent(u8 *p, unsigned int i) { BTL_EVENT_PushVarFrame(13085); BTL_EVENT_SetVarReadOnly(2,i); BTL_EVENT_DispatchEventChecked(p,138); BTL_EVENT_PopVarFrame(13088); }
