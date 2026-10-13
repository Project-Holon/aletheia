/*
 * function: BTL_SERVER_FLOW_CalcSingleTypeAffinity
 * address:  0x021C7038
 * packet:   pkt_ov093_021C7038
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
 *   func_021C70D4  0x021C70D4  thumb  ov093
 *   BTL_CALC_GetTypeAffinity  0x021D794C  thumb  ov093
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
extern void func_021C70D4(u8 *p, u8 *b);
extern int BTL_CALC_GetTypeAffinity(int a, int b);

int BTL_SERVER_FLOW_CalcSingleTypeAffinity(u8 *p, u8 *a, u8 *b, u32 q, u8 s)
{
    int x, y, r;
    BTL_EVENT_PushVarFrame(12290);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(0x15, s);
    BTL_EVENT_SetVarReadOnly(0x16, q);
    BTL_EVENT_SetVarOnce(0x4b, 0);
    BTL_EVENT_SetVarOnce(0x4c, 0);
    func_021C70D4(p, b);
    BTL_EVENT_DispatchEventChecked(p, 0x3e);
    x = BTL_EVENT_GetVar(0x4b);
    y = BTL_EVENT_GetVar(0x4c);
    BTL_EVENT_PopVarFrame(12303);
    if (y) return 3;
    r = BTL_CALC_GetTypeAffinity(q, s);
    if (r == 0 && x) r = 3;
    return r;
}
