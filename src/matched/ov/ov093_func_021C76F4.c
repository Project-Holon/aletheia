/*
 * function: BTL_SERVER_FLOW_RollFlinchChance
 * address:  0x021C76F4
 * packet:   pkt_ov093_021C76F4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_QueryMainFlag  0x021C82B8  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
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

extern int BTL_SERVER_FLOW_QueryMainFlag(void *p, int z);
extern u32 BTL_CALC_Random(u32 range);
extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVar(int key, u32 val);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);

int BTL_SERVER_FLOW_RollFlinchChance(u8 *p, u8 *a, u32 k)
{
    int res;
    int c26;
    int c41;

    BTL_EVENT_PushVarFrame(12745);
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVar(0x26, k);
    BTL_EVENT_SetVarOnce(0x41, 0);
    res = 0;
    BTL_EVENT_DispatchEventChecked(p, 0x6d);
    c26 = BTL_EVENT_GetVar(0x26);
    c41 = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(12753);
    if (c41 != 0)
        return 0;
    if (c26 != 0) {
        if (BTL_SERVER_FLOW_QueryMainFlag(p, res) != 0)
            return 1;
        if (BTL_CALC_Random(100) < (u8)c26)
            res = 1;
        return res;
    }
    return res;
}
