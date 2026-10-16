/*
 * function: BTL_SERVER_FLOW_CheckCriticalHit
 * address:  0x021C6BF8
 * packet:   pkt_ov093_021C6BF8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note 2026-10-05 (wave P13 B10): the older DIFF (12 B, p and h/r in each other's
 *   r4/r5) closed with #pragma opt_lifetimes off around the function, see
 *   docs/idioms/a-colour-swap-no-source-form-fixes-can-be-opt-lifetimes-off.md.
 *   Source is unchanged from the old draft. Plain literals already (11952, 0x2c).
 *   Callees: BTL_POKEPARAM_GetCritStage returns u8, BTL_CALC_RollCriticalHit takes u8 (both matched);
 *   WAZA_TOOL_GetParam and WAZA_TOOL_IsAlwaysCritical return u32 (matched arm9 units).
 * symbols:
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb
 *   WAZA_TOOL_IsAlwaysCritical  0x0201C284  thumb
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   BTL_EVENT_SetVarOnce  0x021D7630  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 *   BTL_EVENT_SetVar  0x021D75A8  thumb  ov093
 *   BTL_POKEPARAM_GetCritStage  0x021D5F14  thumb  ov093
 *   BTL_CALC_RollCriticalHit  0x021D7930  thumb  ov093
 *   BTL_MAIN_ReturnZero  0x021B911C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
struct UtilWork;
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);
extern void BTL_EVENT_SetVar(int key, u32 val);
extern u8 BTL_POKEPARAM_GetCritStage(struct UtilWork *p);
extern int BTL_CALC_RollCriticalHit(int i);
extern int BTL_MAIN_ReturnZero(int a, int b);
extern u32 WAZA_TOOL_GetParam(u16 id, u32 field);
extern u32 WAZA_TOOL_IsAlwaysCritical(u16 id);

#pragma opt_lifetimes off
int BTL_SERVER_FLOW_CheckCriticalHit(u8 *p, u8 *a, u8 *b, u16 q)
{
    int r, n;
    u16 h;
    h = WAZA_TOOL_GetParam(q, 7);
    h = h + BTL_POKEPARAM_GetCritStage((struct UtilWork *)a);
    BTL_EVENT_PushVarFrame(11952);
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVar(0x2c, h);
    r = 0;
    BTL_EVENT_SetVarOnce(0x41, 0);
    BTL_EVENT_DispatchEventChecked(p, 0x36);
    if (BTL_EVENT_GetVar(0x41) == 0) {
        if (WAZA_TOOL_IsAlwaysCritical(q)) {
            r = 1;
        } else {
            n = BTL_EVENT_GetVar(0x2c);
            if (n > 4) n = 4;
            r = BTL_CALC_RollCriticalHit((u8)((u16)n));
        }
        if (BTL_MAIN_ReturnZero(*(int *)(p + 4), 3)) r = 1;
    }
    BTL_EVENT_PopVarFrame(11975);
    return r;
}

#pragma opt_lifetimes reset
