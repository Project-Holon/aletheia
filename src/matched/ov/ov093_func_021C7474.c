/*
 * function: BTL_SERVER_FLOW_CalcDefenseStat
 * address: 0x021C7474
 * packet: pkt_ov093_021C7474
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: 0x0201C1E8, unlabelled ARM9 tail-call wrapper owned by the integrator;
 *   no witness outside this caller (7474-r1.log). Verified blocker C copied
 *   from ov093_func_021C1E74.c, whose header records its EXACT compile:
 *   typedef unsigned short u16; typedef unsigned int u32;
 *   extern u32 WAZA_TOOL_GetParam(u16, u32);
 *   symbols: WAZA_TOOL_GetParam 0x0201BD28 thumb
 *   u32 WAZA_TOOL_GetDamageType(u16 id) { return WAZA_TOOL_GetParam(id, 2); }
 * symbols:
 *   WAZA_TOOL_GetDamageType 0x0201C1E8 thumb
 *   BTL_EVENT_PushVarFrame 0x021D74F8 thumb ov093
 *   BTL_EVENT_PopVarFrame 0x021D7540 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_EVENT_SetVarReadOnly 0x021D75EC thumb ov093
 *   BTL_EVENT_SetVar 0x021D75A8 thumb ov093
 *   BTL_EVENT_SetVarOnce 0x021D7630 thumb ov093
 *   BTL_EVENT_DispatchEventChecked 0x021D70F0 thumb ov093
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_POKEPARAM_GetStatRaw 0x021D58A8 thumb ov093
 *   BTL_POKEPARAM_GetStatForCrit 0x021D5AD8 thumb ov093
 *   BTL_POKEPARAM_GetValue 0x021D59B4 thumb ov093
 *   BTL_SERVER_FLOW_GetEffectiveWeather 0x021C2AB0 thumb ov093
 *   BTL_POKEPARAM_HasType 0x021D5814 thumb ov093
 *   BTL_EVENT_SetVarRanged 0x021D7674 thumb ov093
 *   BTL_CALC_MulRatio 0x021D7B10 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int WAZA_TOOL_GetDamageType(int a);
extern void BTL_EVENT_PushVarFrame(int);
extern void BTL_EVENT_PopVarFrame(int);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *);
extern void BTL_EVENT_SetVarReadOnly(int, u32);
extern void BTL_EVENT_SetVar(int, u32);
extern void BTL_EVENT_SetVarOnce(int, u32);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int);
extern int BTL_POKEPARAM_GetStatRaw(u8 *, int);
extern int BTL_POKEPARAM_GetStatForCrit(u8 *, int);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern int BTL_SERVER_FLOW_GetEffectiveWeather(u8 *);
extern int BTL_POKEPARAM_HasType(void *, int);
extern void BTL_EVENT_SetVarRanged(int, u32, u32, u32);
extern u32 BTL_CALC_MulRatio(u32 a, u32 b);

u16 BTL_SERVER_FLOW_CalcDefenseStat(u8 *p, u8 *a, u8 *b, u8 *c, u32 flag)
{
    int k;
    u32 field;
    u16 value;
    u8 other;
    int scale;
    int mode = WAZA_TOOL_GetDamageType(*(u16 *)c);
    k = 11;
    if (mode != 2) k = 9;
    field = *(u32 *)(c + 8);
    BTL_EVENT_PushVarFrame(12595);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(0x3c, k);
    BTL_EVENT_SetVar(0x3d, 0);
    BTL_EVENT_SetVarOnce(0x51, 0);
    BTL_EVENT_DispatchEventChecked(p, 0x3a);
    if (BTL_EVENT_GetVar(0x3d) & 1) {
        if (k == 9) k = 11;
        else k = 9;
        if (k == 9) field = 1;
        else field = 2;
    }
    other = BTL_EVENT_GetVar(0x51);
    BTL_EVENT_PopVarFrame(12610);
    if (other) value = BTL_POKEPARAM_GetStatRaw(b, k);
    else if (flag) value = BTL_POKEPARAM_GetStatForCrit(b, k);
    else value = BTL_POKEPARAM_GetValue(b, k);
    if (BTL_SERVER_FLOW_GetEffectiveWeather(p) == 4 && BTL_POKEPARAM_HasType(b, 5) && k == 11)
        value = BTL_CALC_MulRatio(value, 6 << 10);
    BTL_EVENT_PushVarFrame(12631);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(0x12, *(u16 *)c);
    BTL_EVENT_SetVarReadOnly(0x16, c[6]);
    BTL_EVENT_SetVarReadOnly(0x1a, field);
    BTL_EVENT_SetVar(0x34, value);
    BTL_EVENT_SetVarRanged(0x35, 4 << 10, 410, 4 << 15);
    BTL_EVENT_DispatchEventChecked(p, 0x3c);
    value = BTL_EVENT_GetVar(0x34);
    scale = BTL_EVENT_GetVar(0x35);
    BTL_EVENT_PopVarFrame(12642);
    return BTL_CALC_MulRatio(value, scale);
}
