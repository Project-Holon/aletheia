/*
 * function: BTL_SERVER_FLOW_RollMoveAddedEffectChance
 * address:  0x021C2D10
 * packet:   pkt_ov093_021C2D10
 * region:   ov093
 * compiler: 1.1p1
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
 *   BTL_EVENT_SetVar  0x021D75A8  thumb  ov093
 *   BTL_EVENT_SetVarOnce  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   func_021B911C  0x021B911C  thumb  ov093
 */
#include "../include/Obj21084.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 sub_0201BD28(u16 id, u32 field);
extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVar(int key, u32 val);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);
extern u32 BTL_CALC_Random(u32 range);
extern int func_021B911C(u32 a, u32 b);

int BTL_SERVER_FLOW_RollMoveAddedEffectChance(u8 *p, u16 *q, u8 *b, u8 *c)
{
    u8 s, x, y;
    u32 t;
    s = sub_0201BD28(*q, 0x12);
    BTL_EVENT_PushVarFrame(8142);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(c));
    BTL_EVENT_SetVarReadOnly(0x12, *q);
    t = 0;
    BTL_EVENT_SetVarOnce(0x41, 0);
    BTL_EVENT_SetVar(0x26, s);
    func_021D70F0(p, 0x51);
    x = BTL_EVENT_GetVar(0x41);
    y = BTL_EVENT_GetVar(0x26);
    BTL_EVENT_PopVarFrame(8152);
    if (x == 0) {
        if (BTL_CALC_Random(100) < y)
            t = 1;
        if (t)
            return 1;
        if (func_021B911C(((struct Obj21084 *)p)->f4, 0) != 0)
            return 1;
    }
    return 0;
}
