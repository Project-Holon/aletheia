/*
 * function: BTL_SERVER_FLOW_CalcAccuracyRatio
 * address:  0x021C6A04
 * packet:   pkt_ov093_021C6A04
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0201BD28  0x0201BD28  thumb
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   BTL_EVENT_SetVarOnce  0x021D7630  thumb  ov093
 *   BTL_EVENT_SetVarRanged  0x021D7674  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 *   BTL_CALC_MulRatio  0x021D7B10  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Q { u16 h0; u8 pad[6]; u32 w8; };

extern u32 sub_0201BD28(u16 id, u32 field);
extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern void BTL_EVENT_SetVarRanged(int key, u32 a, u32 b, u32 c);
extern void func_021D70F0(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);
extern u32 BTL_CALC_MulRatio(u32 a, u32 b);

int BTL_SERVER_FLOW_CalcAccuracyRatio(u8 *p, u8 *a, u8 *b, struct Q *q)
{
    int x, y;
    u32 t = sub_0201BD28(q->h0, 4);
    BTL_EVENT_PushVarFrame(0x2E2F);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(0x12, q->h0);
    BTL_EVENT_SetVarReadOnly(0x1a, q->w8);
    BTL_EVENT_SetVarOnce(0x2b, t);
    BTL_EVENT_SetVarRanged(0x35, 4 << 10, 0x19A, 4 << 15);
    func_021D70F0(p, 0x34);
    x = BTL_EVENT_GetVar(0x2b);
    y = BTL_EVENT_GetVar(0x35);
    BTL_EVENT_PopVarFrame(0x2E39);
    return BTL_CALC_MulRatio(x, y);
}
