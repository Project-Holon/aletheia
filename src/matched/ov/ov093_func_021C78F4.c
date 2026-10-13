/*
 * function: BTL_SERVER_FLOW_CalcDrainHealAmount
 * address:  0x021C78F4
 * packet:   pkt_ov093_021C78F4
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
 *   BTL_EVENT_SetVar  0x021D75A8  thumb  ov093
 *   BTL_EVENT_SetVarRanged  0x021D7674  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 *   BTL_CALC_MulRatioMin1  0x021D7B2C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVar(int key, u32 val);
extern void BTL_EVENT_SetVarRanged(int key, u32 a, u32 b, u32 c);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);
extern u32 BTL_CALC_MulRatioMin1(u32 a, u32 b);

u16 BTL_SERVER_FLOW_CalcDrainHealAmount(u8 *p, u8 *a, u8 *b, u32 s)
{
    int k;
    u32 y;
    u16 r;

    if (b != 0)
        k = BTL_POKEPARAM_GetPokeId(b);
    else
        k = 0x1f;
    BTL_EVENT_PushVarFrame(12894);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, (u8)k);
    BTL_EVENT_SetVarRanged(0x35, 0x1000, 410, 0x20000);
    BTL_EVENT_SetVar(0x20, s);
    BTL_EVENT_DispatchEventChecked(p, 0x8c);
    s = (u16)BTL_EVENT_GetVar(0x20);
    y = BTL_EVENT_GetVar(0x35);
    if (s != 0)
        s = (u16)BTL_CALC_MulRatioMin1(s, y);
    BTL_EVENT_OverwriteVar(0x20, s);
    BTL_EVENT_DispatchEventChecked(p, 0x8d);
    r = BTL_EVENT_GetVar(0x20);
    BTL_EVENT_PopVarFrame(12911);
    return r;
}
