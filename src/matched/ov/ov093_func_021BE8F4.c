/*
 * function: BTL_SERVER_FLOW_DispatchMoveExecuteFailEvent
 * address: 0x021BE8F4
 * packet: pkt_ov093_021BE8F4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_EVENT_PushVarFrame 0x021D74F8 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_EVENT_SetVarReadOnly 0x021D75EC thumb ov093
 *   BTL_EVENT_DispatchEventChecked 0x021D70F0 thumb ov093
 *   BTL_EVENT_PopVarFrame 0x021D7540 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void BTL_EVENT_PushVarFrame(int);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int,u32);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern void BTL_EVENT_PopVarFrame(int);
void BTL_SERVER_FLOW_DispatchMoveExecuteFailEvent(u8 *p,u8 *a)
{
    BTL_EVENT_PushVarFrame(3968);
    BTL_EVENT_SetVarReadOnly(3,BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_DispatchEventChecked(p,7);
    BTL_EVENT_PopVarFrame(3971);
}
