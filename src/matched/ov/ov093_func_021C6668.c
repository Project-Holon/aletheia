/*
 * function: BTL_SERVER_FLOW_QueryActionCancelEvent
 * address:  0x021C6668
 * packet:   pkt_ov093_021C6668
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
 *   BTL_EVENT_SetVar  0x021D75A8  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVar(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);

int BTL_SERVER_FLOW_QueryActionCancelEvent(u8 *p, u8 *a, u8 *a2, u16 a3)
{
    int r;
    BTL_EVENT_PushVarFrame(11574);
    BTL_EVENT_SetVar(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVar(0x51, 0);
    BTL_EVENT_DispatchEventChecked(p, 0x2E);
    r = BTL_EVENT_GetVar(0x51);
    BTL_EVENT_PopVarFrame(11579);
    return r;
}
