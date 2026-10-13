/*
 * function: BTL_SERVER_FLOW_RunMoveSickSelectedEvent
 * address:  0x021C26A8
 * packet:   pkt_ov093_021C26A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern void BTL_EVENT_PopVarFrame(int line);

void BTL_SERVER_FLOW_RunMoveSickSelectedEvent(u8 *p, u32 a, u8 *b, u8 *c, u32 d)
{
    BTL_EVENT_PushVarFrame(7704);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(c));
    BTL_EVENT_SetVarReadOnly(0x3f, d);
    BTL_EVENT_SetVarReadOnly(0x1d, a);
    BTL_EVENT_DispatchEventChecked(p, 0x61);
    BTL_EVENT_PopVarFrame(7710);
}
