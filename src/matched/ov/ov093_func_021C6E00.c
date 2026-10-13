/*
 * function: BTL_SERVER_FLOW_DispatchPostMoveKindEvent
 * address: 0x021C6E00
 * packet: pkt_ov093_021C6E00
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_PushVarFrame 0x021D74F8 thumb ov093
 *   BTL_EVENT_PopVarFrame 0x021D7540 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_EVENT_SetVar 0x021D75A8 thumb ov093
 *   BTL_EVENT_DispatchEvent 0x021D70E4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void BTL_EVENT_PushVarFrame(int);
extern void BTL_EVENT_PopVarFrame(int);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVar(int, u32);
extern void BTL_EVENT_DispatchEvent(void *a, int id);
void BTL_SERVER_FLOW_DispatchPostMoveKindEvent(u8 *p, u8 *a, u8 k)
{
    int line = 12093;
    BTL_EVENT_PushVarFrame(line);
    BTL_EVENT_SetVar(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVar(3, k);
    BTL_EVENT_DispatchEvent(p, 115);
    BTL_EVENT_PopVarFrame(line + 4);
}
