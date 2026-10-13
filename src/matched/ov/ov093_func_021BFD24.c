/*
 * function: BTL_SERVER_FLOW_ProcMoveUseDecide
 * address: 0x021BFD24
 * packet: pkt_ov093_021BFD24
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: u16 c and u8 n recover spill scheduling; fifth e and C676C fourth argument are u16.
 * symbols:
 *   BTL_SERVER_FLOW_BeginHandExScope 0x021CC8D8 thumb ov093
 *   BTL_SERVER_FLOW_EndHandExScope 0x021CC95C thumb ov093
 *   BTL_SERVER_FLOW_QueryMoveRedirectEvent 0x021C676C thumb ov093
 *   func_021BFE30 0x021BFE30 thumb ov093
 *   func_021BFE40 0x021BFE40 thumb ov093
 *   func_021BFE50 0x021BFE50 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   BTL_SERVER_FLOW_NotifyMoveBeginEvent 0x021C6848 thumb ov093
 *   BTL_POKEPARAM_IsSemiInvulnerable 0x021D5C30 thumb ov093
 *   BTL_SERVER_FLOW_PushMsgStdFailed 0x021C5718 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *, int);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);
extern int BTL_SERVER_FLOW_QueryMoveRedirectEvent(u8 *, u8 *, u8 *, u16, u8 *, u32 *);
extern int func_021BFE30(u8 *);
extern u8 *func_021BFE40(u8 *, int);
extern u8 func_021BFE50(void *, u8);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SERVER_FLOW_NotifyMoveBeginEvent(u8 *, u8 *);
struct UtilWork;
extern int BTL_POKEPARAM_IsSemiInvulnerable(struct UtilWork *p);
extern void BTL_SERVER_FLOW_PushMsgStdFailed(u8 *, u8 *, u32);
int BTL_SERVER_FLOW_ProcMoveUseDecide(u8 *p, u8 *q, u16 c, u8 *d, u16 e)
{
    u32 out;
    u8 id;
    u32 lock;
    int r;
    u8 n;
    out = 0;
    id = 31;
    lock = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 5160);
    r = BTL_SERVER_FLOW_QueryMoveRedirectEvent(p, q, d, e, &id, &out);
    if (r) {
        n = p[0x77f];
        if (func_021BFE30(d))
            n = func_021BFE50(p + 0x1ab8, BTL_POKEPARAM_GetPokeId(func_021BFE40(d, 0)));
        BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 48, c, n, e, 0);
    }
    BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), lock, 5173);
    if (r) {
        lock = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 5177);
        BTL_SERVER_FLOW_NotifyMoveBeginEvent(p, q);
        BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), lock, 5179);
        if (BTL_POKEPARAM_IsSemiInvulnerable((struct UtilWork *)q))
            BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 49, BTL_POKEPARAM_GetPokeId(q), 1);
        if (id != 31)
            BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 49, id, 1);
    } else if (out == 0) {
        BTL_SERVER_FLOW_PushMsgStdFailed(p, q, e);
    }
    return r;
}
