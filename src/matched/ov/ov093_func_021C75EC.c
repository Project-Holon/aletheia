/*
 * function: BTL_SERVER_FLOW_CalcTypeMatchMultiplier
 * address:  0x021C75EC
 * packet:   pkt_ov093_021C75EC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb  ov093
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   BTL_EVENT_SetVar  0x021D75A8  thumb  ov093
 *   BTL_EVENT_SetVarOnce  0x021D7630  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_POKEPARAM_HasType(void *p, int k);
extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVar(int key, u32 val);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);

int BTL_SERVER_FLOW_CalcTypeMatchMultiplier(u8 *p, u8 *a, int k)
{
    int f = BTL_POKEPARAM_HasType(a, k);
    u32 v = 0x1000;
    int x;
    int r;

    BTL_EVENT_PushVarFrame(12664);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarOnce(0x51, f);
    BTL_EVENT_DispatchEventChecked(p, 0x40);
    x = BTL_EVENT_GetVar(0x51);
    if (x != 0)
        v = 0x1800;
    BTL_EVENT_SetVarReadOnly(0x44, x);
    BTL_EVENT_SetVar(0x35, v);
    BTL_EVENT_DispatchEventChecked(p, 0x41);
    r = BTL_EVENT_GetVar(0x35);
    BTL_EVENT_PopVarFrame(12681);
    return r;
}
