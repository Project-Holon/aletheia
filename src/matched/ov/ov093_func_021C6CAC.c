/*
 * function: BTL_SERVER_FLOW_CalcMoveDrainRecoil
 * address:  0x021C6CAC
 * packet:   pkt_ov093_021C6CAC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note 2026-10-05 (wave P8): earlier DIFF (288 vs 292 B) closed by local declaration
 *   order (line, n, v, t, y, z, x, then kind); spill slots follow it. Plain literals
 *   12019 and 12032 are EXACT, so no line local. Also EXACT with --lang c.
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   WAZA_TOOL_GetParam 0x0201BD28 thumb
 *   WAZA_TOOL_GetCategory 0x0201C1BC thumb
 *   BTL_EVENT_PushVarFrame 0x021D74F8 thumb ov093
 *   BTL_EVENT_SetVarReadOnly 0x021D75EC thumb ov093
 *   BTL_EVENT_SetVar 0x021D75A8 thumb ov093
 *   BTL_EVENT_SetVarOnce 0x021D7630 thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_PopVarFrame 0x021D7540 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   BTL_CALC_MulPercent 0x021D7B3C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { KIND_NONE, KIND_FIRST, KIND_SECOND } Kind;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *);
extern u32 WAZA_TOOL_GetParam(u16, u32);
extern u32 WAZA_TOOL_GetCategory(u16);
extern void BTL_EVENT_PushVarFrame(int);
extern void BTL_EVENT_SetVarReadOnly(int, u32);
extern void BTL_EVENT_SetVar(int, u32);
extern void BTL_EVENT_SetVarOnce(int, u32);
extern void func_021D70F0(void *a, int id);
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_PopVarFrame(int);
extern int func_021D59B4(u8 *, int);
extern u32 BTL_CALC_MulPercent(u32, u32);
int BTL_SERVER_FLOW_CalcMoveDrainRecoil(u8 *p, u8 *a, u16 b, int amount, int *out)
{
    u8 n, v;
    u8 t, y, z, x;
    int kind;
    n = BTL_POKEPARAM_GetPokeId(a);
    v = WAZA_TOOL_GetParam(b, 30);
    kind = 0;
    *out = kind;
    if (v) kind = KIND_FIRST;
    else {
        v = WAZA_TOOL_GetParam(b, 31);
        if (v) kind = KIND_SECOND;
    }
    if (WAZA_TOOL_GetCategory(b) == 8) return 0;
    BTL_EVENT_PushVarFrame(12019);
    BTL_EVENT_SetVarReadOnly(3, n);
    BTL_EVENT_SetVar(0x35, v);
    BTL_EVENT_SetVar(0x36, 0);
    BTL_EVENT_SetVarOnce(0x41, 0);
    BTL_EVENT_SetVarOnce(0x51, 0);
    func_021D70F0(p, 0x50);
    x = BTL_EVENT_GetVar(0x35);
    y = BTL_EVENT_GetVar(0x41);
    z = BTL_EVENT_GetVar(0x51);
    t = BTL_EVENT_GetVar(0x36);
    BTL_EVENT_PopVarFrame(12032);
    if (z == 0 && y == 1) return 0;
    x += t;
    if (x) {
        if (kind == KIND_SECOND) {
            amount = BTL_CALC_MulPercent(func_021D59B4(a, 14), x);
            if (amount < 1) amount = 1;
        } else if (amount != 0) {
            amount = BTL_CALC_MulPercent(amount, x);
            if (amount < 1) amount = 1;
        }
        *out = z;
        return amount;
    }
    return 0;
}
