/*
 * function: BTL_SERVER_FLOW_TryMoveExecuteCheckEvent
 * address:  0x021BE7E4
 * packet:   pkt_ov093_021BE7E4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_BeginHandExScope  0x021CC8D8  thumb  ov093
 *   BTL_SERVER_FLOW_DispatchMoveExecuteCheckEvent  0x021BE878  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_MAIN_GetTrainerSlotOfPoke  0x021B8D8C  thumb  ov093
 *   BTL_SERVER_FLOW_GetLockState  0x021C88E4  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BTL_SERVER_FLOW_NotifyMoveExecuteFail  0x021BE8C4  thumb  ov093
 *   BTL_SERVER_FLOW_PushMsgStdFailed  0x021C5718  thumb  ov093
 *   BTL_SERVER_FLOW_EndHandExScope  0x021CC95C  thumb  ov093
 */
#include "../include/Obj09962.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *lock, int line);
extern int BTL_SERVER_FLOW_DispatchMoveExecuteCheckEvent(u8 *p, u8 *a, u32 c);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_MAIN_GetTrainerSlotOfPoke(void *p, void *a, u32 b);
extern int BTL_SERVER_FLOW_GetLockState(u8 *p);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SERVER_FLOW_NotifyMoveExecuteFail(u8 *p, u8 *a);
extern void BTL_SERVER_FLOW_PushMsgStdFailed(u8 *p, u8 *a, u32 b);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);

int BTL_SERVER_FLOW_TryMoveExecuteCheckEvent(u8 *p, u8 *a, u32 b, u32 c, u8 *q)
{
    u32 lk = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1D74, 3894);
    int r = BTL_SERVER_FLOW_DispatchMoveExecuteCheckEvent(p, a, c);
    int s;
    *q = 0;
    if (r) {
        s = BTL_MAIN_GetTrainerSlotOfPoke(((struct Obj09962 *)p)->f4, ((struct Obj09962 *)p)->f8, BTL_POKEPARAM_GetPokeId(a));
        if (BTL_SERVER_FLOW_GetLockState(p) == 2) {
            BTL_SERVER_CMD_Push(((struct Obj09962 *)p)->fC, 0x30, s, c, b, 0);
            BTL_SERVER_FLOW_NotifyMoveExecuteFail(p, a);
            *q = 1;
        } else {
            BTL_SERVER_FLOW_PushMsgStdFailed(p, a, b);
        }
    }
    BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1D74), lk, 3913);
    return r;
}
