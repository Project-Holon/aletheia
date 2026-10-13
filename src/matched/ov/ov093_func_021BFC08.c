/*
 * function: func_021BFC08
 * address: 0x021BFC08
 * packet: pkt_ov093_021BFC08
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Wide n/callee parameter avoids truncation; named one-word Word result supplies the frame word.
 * symbols:
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   BTL_SERVER_FLOW_QueryFirstTargetBlockEvent 0x021C66AC thumb ov093
 *   BTL_SERVER_FLOW_PushMsgStdFailed 0x021C5718 thumb ov093
 *   BTL_SERVER_FLOW_QueryMoveBlockedEvent 0x021C6720 thumb ov093
 *   BTL_SERVER_FLOW_ProcMoveUseDecide 0x021BFD24 thumb ov093
 *   BTLV_CORE_MakeSlotKind2 0x021E896C thumb ov093
 *   BTL_SERVER_FLOW_SetSickCont 0x021C5C1C thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   BTL_SERVER_FLOW_NotifyMoveFinishEvent 0x021C6878 thumb ov093
 *   BTL_SERVER_FLOW_QueryMoveTargetsAllowedEvent 0x021C68A8 thumb ov093
 *   BTL_POKEPARAM_SetTurnFlag 0x021D5FC0 thumb ov093
 *   BTL_SERVER_FLOW_ClearMoveLockSicks 0x021BFE60 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 raw; } Word;
struct Unk021D62A8;
struct UtilWork;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int func_021B8D8C(void *, void *, u32);
extern int BTL_SERVER_FLOW_QueryFirstTargetBlockEvent(u8 *, u8 *, u32);
extern void BTL_SERVER_FLOW_PushMsgStdFailed(u8 *, u8 *, u32);
extern int BTL_SERVER_FLOW_QueryMoveBlockedEvent(u8 *, u8 *, u32);
extern int BTL_SERVER_FLOW_ProcMoveUseDecide(u8 *, u8 *, int, u8 *, u16);
extern Word BTLV_CORE_MakeSlotKind2(int, int);
extern void BTL_SERVER_FLOW_SetSickCont(u8 *, u8 *, int, Word);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void BTL_SERVER_FLOW_NotifyMoveFinishEvent(u8 *p, u8 *a, int a2);
extern int BTL_SERVER_FLOW_QueryMoveTargetsAllowedEvent(u8 *, u8 *, u8 *, u16);
extern void BTL_POKEPARAM_SetTurnFlag(struct UtilWork *p, u32 n);
extern void BTL_SERVER_FLOW_ClearMoveLockSicks(u8 *, u8 *);
int func_021BFC08(u8 *p, u8 *q, u8 *d, u16 c)
{
    int result;
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)q, 26) == 0) {
        int n = func_021B8D8C(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, BTL_POKEPARAM_GetPokeId(q));
        if (BTL_SERVER_FLOW_QueryFirstTargetBlockEvent(p, q, (u32)d)) {
            BTL_SERVER_FLOW_PushMsgStdFailed(p, q, c);
            return 1;
        }
        if (BTL_SERVER_FLOW_QueryMoveBlockedEvent(p, q, c) == 0) {
            if (BTL_SERVER_FLOW_ProcMoveUseDecide(p, q, n, d, c)) {
                Word s = BTLV_CORE_MakeSlotKind2(2, c);
                BTL_SERVER_FLOW_SetSickCont(p, q, 26, s);
            }
            return 2;
        }
        if (BTL_SERVER_FLOW_ProcMoveUseDecide(p, q, n, d, c) == 0) return 1;
        {
            u32 lock = func_021CC8D8(p + 0x1d74, 5124);
            BTL_SERVER_FLOW_NotifyMoveFinishEvent(p, q, c);
            func_021CC95C((u32 *)(p + 0x1d74), lock, 5126);
        }
    }
    (*(u8 **)(p + 0x4a8))[4] = 1;
    {
        u32 lock = func_021CC8D8(p + 0x1d74, 5134);
        result = BTL_SERVER_FLOW_QueryMoveTargetsAllowedEvent(p, q, d, c);
        func_021CC95C((u32 *)(p + 0x1d74), lock, 5136);
    }
    BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)q, 11);
    BTL_SERVER_FLOW_ClearMoveLockSicks(p, q);
    return result ? 4 : 3;
}
