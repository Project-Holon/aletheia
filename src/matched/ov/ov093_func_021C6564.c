/*
 * function: BTL_SERVER_FLOW_DispatchMoveDoneEvent
 * address:  0x021C6564
 * packet:   pkt_ov093_021C6564
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
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern void BTL_EVENT_PopVarFrame(int line);

void BTL_SERVER_FLOW_DispatchMoveDoneEvent(u8 *p, u8 *a, u32 c, u32 d)
{
    BTL_EVENT_PushVarFrame(11508);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x12, c);
    BTL_EVENT_SetVarReadOnly(0x22, d);
    BTL_EVENT_DispatchEventChecked(p, 0x21);
    BTL_EVENT_PopVarFrame(11513);
}
