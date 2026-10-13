/*
 * function: BTL_SERVER_FLOW_DispatchPokeEntryEventToType4
 * address: 0x021BDBB8
 * packet: pkt_ov093_021BDBB8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_PushVarFrame 0x021D74F8 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_EVENT_SetVarReadOnly 0x021D75EC thumb ov093
 *   BTL_EVENT_DispatchEventToType 0x021D70FC thumb ov093
 *   BTL_EVENT_PopVarFrame 0x021D7540 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void BTL_EVENT_PushVarFrame(int);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int, u32);
extern void BTL_EVENT_DispatchEventToType(int a, int b, int c);
extern void BTL_EVENT_PopVarFrame(int);
void BTL_SERVER_FLOW_DispatchPokeEntryEventToType4(u8 *p, u8 *a)
{
    BTL_EVENT_PushVarFrame(0xc55);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_DispatchEventToType((int)p, 0x55, 4);
    BTL_EVENT_PopVarFrame(0xc58);
}
