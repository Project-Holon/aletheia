/*
 * function: BTL_SERVER_FLOW_CheckAccuracyCheckRequired
 * address:  0x021BF168
 * packet:   pkt_ov093_021BF168
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_SetVar  0x021D75A8  thumb  ov093
 *   BTL_EVENT_SetVarOnce  0x021D7630  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVar(int key, u32 val);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);

int BTL_SERVER_FLOW_CheckAccuracyCheckRequired(u8 *p, u16 *a, u8 *b)
{
    int r;
    BTL_EVENT_PushVarFrame(4500);
    BTL_EVENT_SetVar(3, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVar(0x12, *a);
    BTL_EVENT_SetVarOnce(0x51, 0);
    BTL_EVENT_DispatchEventChecked(p, 0x3d);
    r = BTL_EVENT_GetVar(0x51);
    BTL_EVENT_PopVarFrame(4506);
    return r;
}
