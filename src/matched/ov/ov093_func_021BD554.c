/*
 * function: BTL_SERVER_FLOW_DispatchShiftInEvent
 * address: 0x021BD554
 * packet: pkt_ov093_021BD554
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
extern void BTL_EVENT_PushVarFrame(int);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVar(int, unsigned int);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern void BTL_EVENT_PopVarFrame(int);
void BTL_SERVER_FLOW_DispatchShiftInEvent(u8 *p, u8 *m)
{
    BTL_EVENT_PushVarFrame(2712);
    BTL_EVENT_SetVar(2, BTL_POKEPARAM_GetPokeId(m));
    BTL_EVENT_DispatchEventChecked(p, 164);
    BTL_EVENT_PopVarFrame(2715);
}
