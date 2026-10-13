/*
 * function: BTL_SERVER_FLOW_DispatchDamageEndEvents
 * address:  0x021C4268
 * packet:   pkt_ov093_021C4268
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   BTL_EVENT_SetVarOnce  0x021D7630  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 */
#include "../include/Obj07754.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_PushVarFrame(int line);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern void BTL_EVENT_PopVarFrame(int line);

void BTL_SERVER_FLOW_DispatchDamageEndEvents(u8 *p, u8 *a, u8 *b, u8 *c, u32 s0, u32 s1, u32 s2, u32 s3)
{
    u8 x = BTL_POKEPARAM_GetPokeId(b);
    BTL_EVENT_PushVarFrame(9335);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, x);
    BTL_EVENT_SetVarReadOnly(0x14, ((struct Obj07754 *)c)->f2);
    BTL_EVENT_SetVarReadOnly(0x12, ((struct Obj07754 *)c)->f0);
    BTL_EVENT_SetVarReadOnly(0x38, s0);
    BTL_EVENT_SetVarReadOnly(0x16, c[6]);
    BTL_EVENT_SetVarReadOnly(0x1a, ((struct Obj07754 *)c)->f8);
    BTL_EVENT_SetVarReadOnly(0x32, s1);
    BTL_EVENT_SetVarReadOnly(0x45, s2);
    BTL_EVENT_SetVarReadOnly(0x46, s3);
    BTL_EVENT_SetVarOnce(0x47, 0);
    BTL_EVENT_DispatchEventChecked(p, 0x4a);
    BTL_EVENT_DispatchEventChecked(p, 0x4b);
    BTL_EVENT_DispatchEventChecked(p, 0x4c);
    BTL_EVENT_PopVarFrame(9352);
}
