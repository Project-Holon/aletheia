/*
 * function: BTL_SERVER_FLOW_QueryActionMessageEvent
 * address:  0x021C6458
 * packet:   pkt_ov093_021C6458
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_ClearMsgRecord  0x021C8810  thumb  ov093
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   BTL_EVENT_SetVarOnce  0x021D7630  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTL_SERVER_FLOW_ClearMsgRecord(u8 *p);
extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);

int BTL_SERVER_FLOW_QueryActionMessageEvent(u8 *p, u8 *a, u32 c, u32 d, u8 *e)
{
    int r;
    int line = 11440;
    BTL_SERVER_FLOW_ClearMsgRecord(e);
    BTL_EVENT_PushVarFrame(line);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x12, d);
    BTL_EVENT_SetVarReadOnly(0x3F, (u32)e);
    BTL_EVENT_SetVarOnce(0x51, 0);
    BTL_EVENT_DispatchEventChecked(p, 0x19);
    r = BTL_EVENT_GetVar(0x51);
    BTL_EVENT_PopVarFrame(line + 7);
    return r;
}
