/*
 * function: BTL_SERVER_FLOW_CalcMultiHitCount
 * address:  0x021C71E0
 * packet:   pkt_ov093_021C71E0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201BD28  0x0201BD28  thumb
 *   BTL_CALC_RollHitCount  0x021D7BA4  thumb  ov093
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   BTL_EVENT_SetVar  0x021D75A8  thumb  ov093
 *   BTL_EVENT_SetVarOnce  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 func_0201BD28(u32 v, u32 n);
extern int BTL_CALC_RollHitCount(int a);
extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVar(int key, u32 val);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);

int BTL_SERVER_FLOW_CalcMultiHitCount(u8 *p, u8 *a, u32 x, u8 *out)
{
    u8 id = func_0201BD28(x, 8);
    u32 r;

    out[1] = 0;
    out[5] = 3;
    if (id > 1) {
        r = BTL_CALC_RollHitCount(id);
        BTL_EVENT_PushVarFrame(12432);
        BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
        BTL_EVENT_SetVarReadOnly(0x29, id);
        BTL_EVENT_SetVar(0x2a, r);
        BTL_EVENT_SetVarOnce(0x51, 0);
        BTL_EVENT_SetVarOnce(0x42, 0);
        func_021D70F0(p, 0x35);
        if (id <= 5 && BTL_EVENT_GetVar(0x51) != 0) {
            out[0] = id;
            out[2] = 0;
        } else {
            out[0] = BTL_EVENT_GetVar(0x2a);
            out[2] = BTL_EVENT_GetVar(0x42);
        }
        out[3] = 1;
        BTL_EVENT_PopVarFrame(12455);
        return 1;
    }
    out[0] = 1;
    out[2] = 0;
    out[3] = 0;
    return 0;
}
