/*
 * function: BTL_SERVER_FLOW_CalcPokeSpeed
 * address:  0x021BC948
 * packet:   pkt_ov093_021BC948
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   BTL_EVENT_SetVar  0x021D75A8  thumb  ov093
 *   BTL_EVENT_SetVarRanged  0x021D7674  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_CALC_MulRatio  0x021D7B10  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   _u32_div_f     0x0209C2B0  arm
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D59B4(u8 *p, int k);
extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVar(int key, u32 val);
extern void BTL_EVENT_SetVarRanged(int key, u32 a, u32 b, u32 c);
struct Unk021D62A8;
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern u32 BTL_CALC_MulRatio(u32 a, u32 b);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern void BTL_EVENT_PopVarFrame(int line);

u16 BTL_SERVER_FLOW_CalcPokeSpeed(u8 *p, u8 *x, int flag)
{
    u32 r;
    int k = func_021D59B4(x, 0xc);
    int one;
    BTL_EVENT_PushVarFrame(1760);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(x));
    BTL_EVENT_SetVarReadOnly(0x2f, k);
    one = 1;
    BTL_EVENT_SetVar(0x51, 1);
    BTL_EVENT_SetVar(0x4a, 0);
    BTL_EVENT_SetVarRanged(0x35, one << 12, 410, one << 17);
    BTL_EVENT_DispatchEventChecked(p, 0x13);
    r = BTL_CALC_MulRatio(BTL_EVENT_GetVar(0x2f), BTL_EVENT_GetVar(0x35));
    if (BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)x) == 1 && BTL_EVENT_GetVar(0x51) != 0)
        r = r * 25 / 100;
    if (r > 10000)
        r = 10000;
    if (flag != 0 && BTL_EVENT_GetVar(0x4a) != 0)
        r = 10000 - r;
    BTL_EVENT_PopVarFrame(1792);
    return r;
}
