/*
 * function: BTL_SERVER_FLOW_QueryPokeGroundedEvent
 * address:  0x021C6F34
 * packet:   pkt_ov093_021C6F34
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
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   BTL_EVENT_SetVarOnce  0x021D7630  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb  ov093
 *   func_021C6FB0  0x021C6FB0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);
extern int BTL_POKEPARAM_HasType(void *p, int k);
extern void func_021C6FB0(u8 *p, u8 *a);

int BTL_SERVER_FLOW_QueryPokeGroundedEvent(u8 *p, u8 *a, int f)
{
    int t;
    u8 x, y;
    if (f) {
        t = BTL_POKEPARAM_HasType(a, 2);
    } else {
        t = 0;
    }
    BTL_EVENT_PushVarFrame(12220);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarOnce(0x51, (u8)t);
    BTL_EVENT_SetVarOnce(0x41, (u8)0);
    BTL_EVENT_DispatchEventChecked(p, 0x12);
    func_021C6FB0(p, a);
    x = BTL_EVENT_GetVar(0x51);
    y = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(12228);
    if (y) return 0;
    return x;
}
