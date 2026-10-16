/*
 * function: BTL_SERVER_FLOW_CheckOneHitKoHit
 * address:  0x021C6A9C
 * packet:   pkt_ov093_021C6A9C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   BTL_SERVER_FLOW_CheckNoGuardHit  0x021BF324  thumb  ov093
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   BTL_EVENT_SetVarOnce  0x021D7630  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern int BTL_SERVER_FLOW_CheckNoGuardHit(u8 *p, u8 *a, u8 *b);
extern u32 WAZA_TOOL_GetParam(u16 id, u32 field);
extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);
extern u32 BTL_CALC_Random(u32 range);

int BTL_SERVER_FLOW_CheckOneHitKoHit(u8 *p, u8 *a, u8 *b, u16 id)
{
    u8 x, y, c;
    int r, t;
    x = BTL_POKEPARAM_GetValue(a, 15);
    y = BTL_POKEPARAM_GetValue(b, 15);
    if (x < y) return 0;
    BTL_EVENT_PushVarFrame(0x2E5A);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    r = 0;
    BTL_EVENT_SetVarOnce(0x41, 0);
    BTL_EVENT_DispatchEventChecked(p, 0x70);
    t = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(0x2E60);
    if (t) return r;
    if (BTL_SERVER_FLOW_CheckNoGuardHit(p, a, b)) {
        r = 1;
    } else {
        c = WAZA_TOOL_GetParam(id, 4);
        c += (u8)(x - y);
        if (BTL_CALC_Random(100) < c) r = 1;
    }
    return r;
}
