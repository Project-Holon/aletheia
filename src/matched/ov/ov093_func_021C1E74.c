/*
 * function: BTL_SERVER_FLOW_CalcMoveDamage
 * address: 0x021C1E74
 * packet: pkt_ov093_021C1E74
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: 0x0201C1E8, unlabelled ARM9 tail-call wrapper owned by the integrator.
 *   Call +0x10 has no witness outside 021C1E74..021C2048; all concrete
 *   bytes match, and the other 39 relocation sites resolve.
 *   Verified one --thumb, no --region, dsi/1.1p1 -O4,p: EXACT, 12 bytes.
 *   typedef unsigned short u16; typedef unsigned int u32;
 *   extern u32 WAZA_TOOL_GetParam(u16, u32);
 *   symbols: WAZA_TOOL_GetParam 0x0201BD28 thumb
 *   u32 WAZA_TOOL_GetDamageType(u16 id) { return WAZA_TOOL_GetParam(id, 2); }
 * lever: a separately narrowed u8 level local avoids the extra r0-to-r2
 *   copy from narrowing an inline call argument. value * scale selects
 *   the original multiplication destination; scale * value adds a copy.
 * symbols:
 *   WAZA_TOOL_GetDamageType 0x0201C1E8 thumb
 *   BTL_EVENT_PushVarFrame 0x021D74F8 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_EVENT_SetVarReadOnly 0x021D75EC thumb ov093
 *   BTL_EVENT_SetVar 0x021D75A8 thumb ov093
 *   BTL_EVENT_SetVarRanged 0x021D7674 thumb ov093
 *   BTL_EVENT_DispatchEventChecked 0x021D70F0 thumb ov093
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_PopVarFrame 0x021D7540 thumb ov093
 *   BTL_SERVER_FLOW_CalcMovePower 0x021C728C thumb ov093
 *   BTL_SERVER_FLOW_CalcAttackStat 0x021C7374 thumb ov093
 *   BTL_SERVER_FLOW_CalcDefenseStat 0x021C7474 thumb ov093
 *   BTL_POKEPARAM_GetValue 0x021D59B4 thumb ov093
 *   BTL_CALC_CalcBaseDamage 0x021D7A44 thumb ov093
 *   BTL_CALC_MulRatio 0x021D7B10 thumb ov093
 *   BTL_SERVER_FLOW_GetEffectiveWeather 0x021C2AB0 thumb ov093
 *   BTL_CALC_GetWeatherMoveRatio 0x021D7C38 thumb ov093
 *   BTL_MAIN_ReturnZero 0x021B911C thumb ov093
 *   BTL_CALC_Random 0x021D78AC thumb ov093
 *   _u32_div_f 0x0209C2B0 arm
 *   BTL_SERVER_FLOW_CalcTypeMatchMultiplier 0x021C75EC thumb ov093
 *   BTL_CALC_ApplyTypeAffinity 0x021D7A6C thumb ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex 0x021D62A8 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int WAZA_TOOL_GetDamageType(int a);
extern void BTL_EVENT_PushVarFrame(int);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *);
extern void BTL_EVENT_SetVarReadOnly(int, u32);
extern void BTL_EVENT_SetVar(int, u32);
extern void BTL_EVENT_SetVarRanged(int, u32, u32, u32);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern u32 BTL_EVENT_GetVar(int);
extern void BTL_EVENT_PopVarFrame(int);
extern u16 BTL_SERVER_FLOW_CalcMovePower(u8 *, u8 *, u8 *, u8 *);
extern u16 BTL_SERVER_FLOW_CalcAttackStat(u8 *p, u8 *a, u8 *b, u8 *c, int flag);
extern u16 BTL_SERVER_FLOW_CalcDefenseStat(u8 *p, u8 *a, u8 *b, u8 *c, u32 flag);
extern int BTL_POKEPARAM_GetValue(u8 *, int);
extern u32 BTL_CALC_CalcBaseDamage(u32 a, u32 b, u32 c, u32 d);
extern u32 BTL_CALC_MulRatio(u32, u32);
extern int BTL_SERVER_FLOW_GetEffectiveWeather(u8 *);
extern u32 BTL_CALC_GetWeatherMoveRatio(int a, int b);
extern int BTL_MAIN_ReturnZero(void *, int);
extern u32 BTL_CALC_Random(u32);
extern int BTL_SERVER_FLOW_CalcTypeMatchMultiplier(u8 *, u8 *, int);
extern u32 BTL_CALC_ApplyTypeAffinity(u32, u32);
struct Unk021D62A8;
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
int BTL_SERVER_FLOW_CalcMoveDamage(u8 *p, u8 *a, u8 *b, u8 *c, u32 d, u32 e, u32 f, int g, u16 *out)
{
    int category = WAZA_TOOL_GetDamageType(*(u16 *)c);
    int flag = 0;
    u32 result;
    u32 x;
    u32 y;
    u32 value;
    u32 factor;
    u16 scale;
    u8 level;
    BTL_EVENT_PushVarFrame(0x1c21);
    BTL_EVENT_SetVarReadOnly(0x38, d);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(0x45, f);
    BTL_EVENT_SetVarReadOnly(0x16, c[6]);
    BTL_EVENT_SetVarReadOnly(0x12, *(u16 *)c);
    BTL_EVENT_SetVarReadOnly(0x1a, category);
    BTL_EVENT_SetVar(0x37, 0);
    BTL_EVENT_DispatchEventChecked(p, 0x46);
    result = BTL_EVENT_GetVar(0x37);
    if (result) {
        flag = 1;
    } else {
        x = BTL_SERVER_FLOW_CalcMovePower(p, a, b, c);
        y = BTL_SERVER_FLOW_CalcAttackStat(p, a, b, c, f);
        value = BTL_SERVER_FLOW_CalcDefenseStat(p, a, b, c, f);
        level = BTL_POKEPARAM_GetValue(a, 15);
        value = BTL_CALC_CalcBaseDamage(x, y, level, value);
        if (e != 0x1000) value = BTL_CALC_MulRatio(value, e);
        factor = BTL_CALC_GetWeatherMoveRatio(BTL_SERVER_FLOW_GetEffectiveWeather(p), c[6]);
        if (factor != 0x1000) value = BTL_CALC_MulRatio(value, factor);
        if (f) value *= 2;
        if (!BTL_MAIN_ReturnZero(*(void **)(p + 4), 7)) {
            if (g) scale = 85;
            else scale = 100 - BTL_CALC_Random(16);
            value = (u32)(value * scale) / 100u;
        }
        if (c[6] != 17) value = BTL_CALC_MulRatio(value, BTL_SERVER_FLOW_CalcTypeMatchMultiplier(p, a, c[6]));
        value = BTL_CALC_ApplyTypeAffinity(value, d);
        if (category == 1 && BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)a) == 4 && BTL_POKEPARAM_GetValue(a, 17) != 62) {
            value = (u32)(50u * value) / 100u;
        }
        if (!value) value = 1;
        BTL_EVENT_SetVarRanged(0x35, 0x1000, 0x29, 0x20000);
        BTL_EVENT_SetVar(0x32, value);
        BTL_EVENT_DispatchEventChecked(p, 0x47);
        factor = BTL_EVENT_GetVar(0x35);
        result = BTL_CALC_MulRatio(BTL_EVENT_GetVar(0x32), factor);
    }
    BTL_EVENT_DispatchEventChecked(p, 0x48);
    BTL_EVENT_PopVarFrame(0x1c8d);
    *out = result;
    return flag;
}
