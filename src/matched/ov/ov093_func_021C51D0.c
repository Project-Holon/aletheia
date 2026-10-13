/*
 * function: BTL_SERVER_FLOW_DispatchPokeLeaveEvent
 * address: 0x021C51D0
 * packet: pkt_ov093_021C51D0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_PushVarFrame 0x021D74F8 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_EVENT_SetVar 0x021D75A8 thumb ov093
 *   BTL_EVENT_DispatchEventChecked 0x021D70F0 thumb ov093
 *   BTL_EVENT_PopVarFrame 0x021D7540 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void BTL_EVENT_PushVarFrame(int);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVar(int, u32);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern void BTL_EVENT_PopVarFrame(int);
void BTL_SERVER_FLOW_DispatchPokeLeaveEvent(u8 *p, u8 *a)
{
    int line = 0x27DF;
    BTL_EVENT_PushVarFrame(line);
    BTL_EVENT_SetVar(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_DispatchEventChecked(p, 0xA3);
    BTL_EVENT_PopVarFrame(line + 3);
}
