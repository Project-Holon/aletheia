/*
 * function: func_021C79E0
 * address:  0x021C79E0
 * packet:   pkt_ov093_021C79E0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201BD28  0x0201BD28  thumb
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   BTL_EVENT_SetVar  0x021D75A8  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 *   BTL_CALC_MulRatio  0x021D7B10  thumb  ov093
 *   BTL_CALC_MulPercent  0x021D7B3C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 func_0201BD28(u32 v, u32 n);
extern int func_021D59B4(u8 *p, int k);
extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVar(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);
extern u32 BTL_CALC_MulRatio(u32 a, u32 b);
extern u32 BTL_CALC_MulPercent(u32 a, u32 b);

u32 func_021C79E0(u8 *p, u32 x, u8 *a)
{
    u32 s = func_0201BD28(x, 0x1a);
    int c;
    u32 m;
    u32 r;

    BTL_EVENT_PushVarFrame(12956);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVar(0x35, 0);
    func_021D70F0(p, 0x8f);
    c = BTL_EVENT_GetVar(0x35);
    BTL_EVENT_PopVarFrame(12961);
    m = func_021D59B4(a, 0xe);
    if (c != 0)
        r = BTL_CALC_MulRatio(m, c);
    else
        r = BTL_CALC_MulPercent(m, s);
    if (r == 0)
        return 1;
    if (r > m)
        r = m;
    return r;
}
