/*
 * function: BTL_SERVER_FLOW_CalcMovePower
 * address:  0x021C728C
 * packet:   pkt_ov093_021C728C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WAZA_TOOL_GetPower  0x0201C1D8  thumb
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   BTL_EVENT_SetVarOnce  0x021D7630  thumb  ov093
 *   BTL_EVENT_SetVarRanged  0x021D7674  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 *   BTL_CALC_MulRatio  0x021D7B10  thumb  ov093
 */
#include "../include/Obj07759.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u16 WAZA_TOOL_GetPower(void *p);
extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern void BTL_EVENT_SetVarRanged(int key, u32 a, u32 b, u32 c);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);
extern u32 BTL_CALC_MulRatio(u32 a, u32 b);

u16 BTL_SERVER_FLOW_CalcMovePower(u8 *p, u8 *a, u8 *b, u8 *s)
{
    u32 t = WAZA_TOOL_GetPower((void *)(((struct Obj07759 *)s)->f0));
    u16 x;
    u32 y;

    BTL_EVENT_PushVarFrame(12487);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(0x12, ((struct Obj07759 *)s)->f0);
    BTL_EVENT_SetVarReadOnly(0x16, s[6]);
    BTL_EVENT_SetVarReadOnly(0x1a, ((struct Obj07759 *)s)->f8);
    BTL_EVENT_SetVarOnce(0x30, t);
    BTL_EVENT_DispatchEventChecked(p, 0x37);
    BTL_EVENT_SetVarRanged(0x31, 0x1000, 0x29, 0x200000);
    BTL_EVENT_DispatchEventChecked(p, 0x38);
    x = BTL_EVENT_GetVar(0x30);
    y = BTL_EVENT_GetVar(0x31);
    BTL_EVENT_PopVarFrame(12500);
    return BTL_CALC_MulRatio(x, y);
}
