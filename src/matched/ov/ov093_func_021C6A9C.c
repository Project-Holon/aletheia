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
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021BF324  0x021BF324  thumb  ov093
 *   sub_0201BD28  0x0201BD28  thumb
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   BTL_EVENT_SetVarOnce  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D59B4(u8 *p, int k);
extern int func_021BF324(u8 *p, u8 *a, u8 *b);
extern u32 sub_0201BD28(u16 id, u32 field);
extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);
extern u32 BTL_CALC_Random(u32 range);

int BTL_SERVER_FLOW_CheckOneHitKoHit(u8 *p, u8 *a, u8 *b, u16 id)
{
    u8 x, y, c;
    int r, t;
    x = func_021D59B4(a, 15);
    y = func_021D59B4(b, 15);
    if (x < y) return 0;
    BTL_EVENT_PushVarFrame(0x2E5A);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    r = 0;
    BTL_EVENT_SetVarOnce(0x41, 0);
    func_021D70F0(p, 0x70);
    t = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(0x2E60);
    if (t) return r;
    if (func_021BF324(p, a, b)) {
        r = 1;
    } else {
        c = sub_0201BD28(id, 4);
        c += (u8)(x - y);
        if (BTL_CALC_Random(100) < c) r = 1;
    }
    return r;
}
