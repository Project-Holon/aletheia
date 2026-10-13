/*
 * function: BTL_SERVER_FLOW_ProcMemberOutCore
 * address:  0x021BDD7C
 * packet:   pkt_ov093_021BDD7C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_MAIN_GetTrainerSlotOfPoke  0x021B8D8C  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BTL_SERVER_FLOW_MarkActionDone  0x021BD1D0  thumb  ov093
 *   BTL_SERVER_FLOW_BeginHandExScope  0x021CC8D8  thumb  ov093
 *   BTL_SERVER_FLOW_DispatchMemberOutEvent  0x021BDE18  thumb  ov093
 *   BTL_SERVER_FLOW_EndHandExScope  0x021CC95C  thumb  ov093
 *   BTL_SERVER_FLOW_ProcPokeLeaveField  0x021C5108  thumb  ov093
 *   BTL_POKEPARAM_ResetEffectsOnSwitchOut  0x021D64F0  thumb  ov093
 *   func_021BDE08  0x021BDE08  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_MAIN_GetTrainerSlotOfPoke(void *p, void *a, u32 b);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SERVER_FLOW_MarkActionDone(u8 *p, u32 n);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *lock, int line);
extern void BTL_SERVER_FLOW_DispatchMemberOutEvent(u8 *p, u8 *a);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);
extern void BTL_SERVER_FLOW_ProcPokeLeaveField(u8 *p, u8 *a, int z);
extern void BTL_POKEPARAM_ResetEffectsOnSwitchOut(u8 *a);
extern void func_021BDE08(u8 *p, u32 n);

void BTL_SERVER_FLOW_ProcMemberOutCore(u8 *p, u8 *a, u32 c)
{
    u32 n = BTL_POKEPARAM_GetPokeId(a);
    u32 s;
    int r = BTL_MAIN_GetTrainerSlotOfPoke(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, n);
    if (r != 6) BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x3C, r, c);
    BTL_SERVER_FLOW_MarkActionDone(p, n);
    s = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1D74, 3327);
    BTL_SERVER_FLOW_DispatchMemberOutEvent(p, a);
    BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1D74), s, 3329);
    BTL_SERVER_FLOW_ProcPokeLeaveField(p, a, 0);
    BTL_POKEPARAM_ResetEffectsOnSwitchOut(a);
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x20, BTL_POKEPARAM_GetPokeId(a));
    func_021BDE08(p + 0x1AB8, n);
}
