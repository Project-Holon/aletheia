/*
 * function: BTL_SERVER_FLOW_ProcFight
 * address: 0x021BDE98
 * packet: pkt_ov093_021BDE98
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note (2026-10-05, final push G4L2): EXACT in c99 and c. The zero flag is a u8 local: a narrow local
 *   keeps its spill store below the select store and lets the id copy schedule right after the act load
 *   (u32 and int flags sink the copy to the last slot before the first BTL_POKEPARAM_HasSick call, 12 bytes off).
 *   Callee check: no declaration problems (021BE338..021BE398 are veneers, 021BE620 and 021BFE60 are void).
 * symbols:
 *   BTL_POKEPARAM_GetSemiInvulnerableFlag 0x021D5C08 thumb ov093
 *   BTL_SERVER_FLOW_InitTurnState 0x021BD1E0 thumb ov093
 *   BTL_SERVER_FLOW_InitMoveQueue 0x021BE518 thumb ov093
 *   BTL_SERVER_FLOW_GetEncoredMove 0x021BDE48 thumb ov093
 *   BTL_CALC_DecideMoveTarget 0x021D80BC thumb ov093
 *   BTL_ACTION_SetFight 0x021D82D0 thumb ov093
 *   BTL_POKEPARAM_FindMoveSlot 0x021D5778 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   HAND_WAZA_AddMoveHandler 0x021E02DC thumb ov093
 *   BTL_SERVER_FLOW_NotifyMoveStart 0x021BE924 thumb ov093
 *   BTL_SERVER_FLOW_CheckMoveExecuteFail 0x021C001C thumb ov093
 *   BTL_SERVER_FLOW_QueryForcedMoveEvent 0x021C62D8 thumb ov093
 *   BTL_SERVER_FLOW_PushPokeCmd59 0x021C5604 thumb ov093
 *   BTL_SERVER_FLOW_GetMoveParam 0x021C64B4 thumb ov093
 *   BTL_SERVER_FLOW_DecideMoveTargets 0x021CA7F4 thumb ov093
 *   BTL_SERVER_FLOW_ReducePPByEvent 0x021C07AC thumb ov093
 *   BTL_SERVER_FLOW_ProcMoveExecuteFail 0x021C0450 thumb ov093
 *   BTL_SERVER_FLOW_PushMoveExecCmd 0x021BEBD8 thumb ov093
 *   BTL_SERVER_FLOW_CheckMoveRestricted 0x021BE3A8 thumb ov093
 *   func_021BE338 0x021BE338 thumb ov093
 *   func_021BE348 0x021BE348 thumb ov093
 *   func_021BE358 0x021BE358 thumb ov093
 *   func_021BE368 0x021BE368 thumb ov093
 *   func_021BE378 0x021BE378 thumb ov093
 *   func_021BE388 0x021BE388 thumb ov093
 *   func_021BE398 0x021BE398 thumb ov093
 *   BTL_SERVER_FLOW_DispatchMoveParamEventLocked 0x021BE66C thumb ov093
 *   BTL_SERVER_FLOW_DispatchMoveTypeEvent 0x021BE620 thumb ov093
 *   BTL_SERVER_FLOW_QueryActionMessageEvent 0x021C6458 thumb ov093
 *   BTL_SERVER_FLOW_PushMsgRecord 0x021C99A0 thumb ov093
 *   BTL_SERVER_FLOW_ClearMsgRecord 0x021C8810 thumb ov093
 *   BTL_SERVER_FLOW_CureSick 0x021C5620 thumb ov093
 *   BTL_POKEPARAM_SetTurnFlag 0x021D5FC0 thumb ov093
 *   BTL_SERVER_FLOW_CheckMoveExecuteFailByEvent 0x021C024C thumb ov093
 *   BTL_SERVER_FLOW_TryMoveExecuteCheckEvent 0x021BE7E4 thumb ov093
 *   BTL_SERVER_FLOW_ProcPledgeCombo 0x021BE6EC thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_FLOW_CheckMoveInterrupt 0x021BEAB4 thumb ov093
 *   BTL_SERVER_FLOW_ProcInterruptMove 0x021BE550 thumb ov093
 *   BTL_SERVER_FLOW_ProcMoveExecute 0x021BEC58 thumb ov093
 *   BTL_POKEPARAM_RecordMoveUse 0x021D6744 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   BTL_POKEPARAM_GetCounter 0x021D69AC thumb ov093
 *   BTL_SERVER_FLOW_SetPokeCounter 0x021C0780 thumb ov093
 *   BTL_SERVER_FLOW_ClearMoveLockSicks 0x021BFE60 thumb ov093
 *   BTL_POKEPARAM_TestTurnFlag 0x021D5BB0 thumb ov093
 *   BTL_SERVER_FLOW_ReleaseBindingTarget 0x021BFF60 thumb ov093
 *   BTL_SERVER_FLOW_NotifyMoveEnd 0x021BE994 thumb ov093
 *   HAND_WAZA_RemoveMoveHandlerUnlessKept 0x021E0394 thumb ov093
 *   BTL_SERVER_FLOW_ProcDeferredMoves 0x021BE400 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef union {
    struct { u32 type:4, select:3, move:16, arg:8, rest:1; } full;
    u32 w;
} Action;
struct Out { u8 c0; u8 pad; u16 c2; u8 c4; };
struct Cell { u32 w[5]; };
struct Msg;
struct O;
struct Out64B4;
struct Slot;
struct Unk021BD1E0;
struct Unk021BDE48;
struct Unk021BE518;
struct Unk021D62A8;
struct Unk021D82D0;
struct UtilWork;
extern u32 BTL_POKEPARAM_GetSemiInvulnerableFlag(struct UtilWork *p);
extern void BTL_SERVER_FLOW_InitTurnState(struct Unk021BD1E0 *p);
extern void BTL_SERVER_FLOW_InitMoveQueue(struct Unk021BE518 *p);
extern u16 BTL_SERVER_FLOW_GetEncoredMove(void *p, struct Unk021BDE48 *m);
extern int BTL_CALC_DecideMoveTarget(void *p, int a, int m, u16 move);
extern void BTL_ACTION_SetFight(struct Unk021D82D0 *out, u32 id, u32 sub);
extern u8 BTL_POKEPARAM_FindMoveSlot(struct UtilWork *p, u16 id);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern int HAND_WAZA_AddMoveHandler(u8 *, u16, u32);
extern void BTL_SERVER_FLOW_NotifyMoveStart(u8 *, u8 *, u32);
extern int BTL_SERVER_FLOW_CheckMoveExecuteFail(u8 *, u8 *, u16, u16);
extern int BTL_SERVER_FLOW_QueryForcedMoveEvent(u8 *p, u8 *a, u32 unused, u32 c, struct O *out);
extern void BTL_SERVER_FLOW_PushPokeCmd59(u8 *, u8 *, int);
extern void BTL_SERVER_FLOW_GetMoveParam(u8 *p, u16 q, u8 *a, struct Out64B4 *out);
extern int BTL_SERVER_FLOW_DecideMoveTargets(u8 *, u8 *, u16, const u8 *, void *);
extern int BTL_SERVER_FLOW_ReducePPByEvent(u8 *, u8 *, u32, u32, int);
extern void BTL_SERVER_FLOW_ProcMoveExecuteFail(u8 *, u8 *, u16, int);
extern void BTL_SERVER_FLOW_PushMoveExecCmd(u8 *, u8 *, int, int);
extern int BTL_SERVER_FLOW_CheckMoveRestricted(u8 *, u8 *, u16 *);
extern void func_021BE338(void *);
extern void func_021BE348(void *);
extern u32 func_021BE358(void *);
extern void func_021BE368(void *);
extern void func_021BE378(void *, void *);
extern void func_021BE388(void *, u32);
extern void func_021BE398(void *, u16, u32, u32);
extern void BTL_SERVER_FLOW_DispatchMoveParamEventLocked(u8 *p, u8 *a, u8 *c, int k);
extern void BTL_SERVER_FLOW_DispatchMoveTypeEvent(u8 *p, u8 *a, u8 *c);
extern int BTL_SERVER_FLOW_QueryActionMessageEvent(u8 *, u8 *, u32, u32, u8 *);
extern int BTL_SERVER_FLOW_PushMsgRecord(void *w, const struct Msg *m);
extern void BTL_SERVER_FLOW_ClearMsgRecord(u8 *);
extern void BTL_SERVER_FLOW_CureSick(u8 *p, u8 *a, int k, struct Slot *out);
extern void BTL_POKEPARAM_SetTurnFlag(struct UtilWork *p, u32 n);
extern int BTL_SERVER_FLOW_CheckMoveExecuteFailByEvent(u8 *, u8 *, u32);
extern int BTL_SERVER_FLOW_TryMoveExecuteCheckEvent(u8 *, u8 *, u32, u32, u8 *);
extern int BTL_SERVER_FLOW_ProcPledgeCombo(u8 *, u8 *, u16, u32);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_SERVER_FLOW_CheckMoveInterrupt(u8 *, u8 *, int, int, u8 *);
extern void BTL_SERVER_FLOW_ProcInterruptMove(u8 *, u8 *, u16, void *);
extern int BTL_SERVER_FLOW_ProcMoveExecute(u8 *p, u8 *a, u16 key, u8 *d);
extern void BTL_POKEPARAM_RecordMoveUse(u8 *, u8, int, u8, u16, u16);
extern void BTL_SERVER_CMD_Push(void *, volatile u32, ...);
extern u8 BTL_POKEPARAM_GetCounter(u8 *, int);
extern void BTL_SERVER_FLOW_SetPokeCounter(u8 *, u8 *, int, u8);
extern void BTL_SERVER_FLOW_ClearMoveLockSicks(u8 *, u8 *);
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
extern void BTL_SERVER_FLOW_ReleaseBindingTarget(u8 *, u8 *, int);
extern void BTL_SERVER_FLOW_NotifyMoveEnd(u8 *, u8 *, u32, u32);
extern void HAND_WAZA_RemoveMoveHandlerUnlessKept(u8 *, int);
extern void BTL_SERVER_FLOW_ProcDeferredMoves(u8 *, u16);

static inline void ev18(void *w, u32 x, u32 s, u32 c, u32 b, u32 i2, u32 i1)
{
    BTL_SERVER_CMD_Push(w, 0x18, x, s, c, b, i2, i1);
}

#define F(o) (*(u8 **)(p + (o)))

void BTL_SERVER_FLOW_ProcFight(u8 *p, u8 *a, Action *act, u32 key)
{
    int k;
    u8 sel;
    u32 prev;
    int chk1, chk2;
    int found;
    u8 flag;
    u8 pr;
    u16 m;
    u16 id;
    u16 id2;
    struct Out o;

    prev = BTL_POKEPARAM_GetSemiInvulnerableFlag((struct UtilWork *)a);
    BTL_SERVER_FLOW_InitTurnState((struct Unk021BD1E0 *)F(0x4a8));
    BTL_SERVER_FLOW_InitMoveQueue((struct Unk021BE518 *)F(0x4b0));
    o.c2 = 0;
    o.c4 = 6;
    m = BTL_SERVER_FLOW_GetEncoredMove(a, (struct Unk021BDE48 *)act);
    if (m != 0) {
        BTL_ACTION_SetFight((struct Unk021D82D0 *)act, m, BTL_CALC_DecideMoveTarget(*(void **)(p + 4), *(int *)(p + 8), (int)a, m));
    }
    id = act->full.move;
    pr = BTL_POKEPARAM_FindMoveSlot((struct UtilWork *)a, id);
    id2 = id;
    sel = (u8)act->full.select;
    flag = 0;
    o.c0 = 0;
    chk1 = (u8)BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 0x19);
    chk2 = (u8)BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 0x1a);
    HAND_WAZA_AddMoveHandler(a, id, key);
    BTL_SERVER_FLOW_NotifyMoveStart(p, a, id);
    if (BTL_SERVER_FLOW_CheckMoveExecuteFail(p, a, id, (u8)((chk1 != 0 || chk2 != 0) ? 1 : flag)) != 0) goto end;
    if (BTL_SERVER_FLOW_QueryForcedMoveEvent(p, a, id, sel, (struct O *)(&o.c2)) == 0) {
        BTL_SERVER_FLOW_PushPokeCmd59(p, a, id);
        BTL_SERVER_FLOW_GetMoveParam(p, id, a, (struct Out64B4 *)F(0x1ab4));
        BTL_SERVER_FLOW_DecideMoveTargets(p, a, sel, F(0x1ab4), F(0x850));
        BTL_SERVER_FLOW_ReducePPByEvent(p, a, id, pr, (int)F(0x850));
        flag = 1;
        BTL_SERVER_FLOW_ProcMoveExecuteFail(p, a, id, 0x1a);
        goto end;
    }
    found = (u8)((o.c2 != 0) ? 1 : 0);
    if (found) {
        BTL_SERVER_FLOW_PushPokeCmd59(p, a, id);
        BTL_SERVER_FLOW_PushMoveExecCmd(p, a, id, sel);
        HAND_WAZA_AddMoveHandler(a, o.c2, key);
        id2 = o.c2;
        sel = o.c4;
    } else {
        id2 = id;
    }
    BTL_SERVER_FLOW_GetMoveParam(p, id, a, (struct Out64B4 *)F(0x1ab4));
    if (found) {
        BTL_SERVER_FLOW_GetMoveParam(p, id2, a, (struct Out64B4 *)F(0x1ab0));
        ((u32 *)F(0x1ab0))[4] |= 4;
        ((u16 *)F(0x1ab0))[1] = id;
        if (BTL_SERVER_FLOW_CheckMoveRestricted(p, a, (u16 *)F(0x1ab0)) != 0) {
            BTL_SERVER_FLOW_ReducePPByEvent(p, a, id, pr, (int)F(0x850));
            flag = 1;
            goto end;
        }
    } else {
        *(struct Cell *)F(0x1ab0) = *(struct Cell *)F(0x1ab4);
    }
    func_021BE338(F(0x850));
    func_021BE348(F(0x854));
    BTL_SERVER_FLOW_DecideMoveTargets(p, a, sel, F(0x1ab0), F(0x850));
    {
        u32 v = (u8)func_021BE358(F(0x850));
        func_021BE368(F(0x850));
        func_021BE378(F(0x850), F(0x854));
        func_021BE388(F(0x854), v);
    }
    if (chk1 == 0 && chk2 == 0 && pr != 4) {
        BTL_SERVER_FLOW_ReducePPByEvent(p, a, id, pr, (int)F(0x850));
        flag = 1;
    }
    {
        k = 0x1ab4;
        BTL_SERVER_FLOW_DispatchMoveParamEventLocked(p, a, *(void **)(p + k), 0x22);
        BTL_SERVER_FLOW_DispatchMoveTypeEvent(p, a, *(void **)(p + k - 4));
        if (BTL_SERVER_FLOW_QueryActionMessageEvent(p, a, id, id2, p + k + 0x30) != 0) {
            BTL_SERVER_FLOW_PushMsgRecord(p, (const struct Msg *)(p + k + 0x30));
            k += 0x30;
            BTL_SERVER_FLOW_ClearMsgRecord(p + k);
        } else {
            BTL_SERVER_FLOW_PushPokeCmd59(p, a, id2);
        }
    }
    *(u16 *)(p + 0x1f74) = id2;
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 0x22) != 0) {
        BTL_SERVER_FLOW_CureSick(p, a, 0x22, 0);
        BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)a, 0xe);
    }
    if (BTL_SERVER_FLOW_CheckMoveExecuteFailByEvent(p, a, id2) == 0
        && BTL_SERVER_FLOW_TryMoveExecuteCheckEvent(p, a, id2, sel, (u8 *)&o) == 0
        && BTL_SERVER_FLOW_ProcPledgeCombo(p, a, id2, sel) == 0) {
        func_021BE398(p + 0x1c, id2, *(u32 *)(p + 0x10), BTL_POKEPARAM_GetPokeId(a));
        BTL_SERVER_FLOW_DispatchMoveParamEventLocked(p, a, F(0x1ab0), 0x23);
        if (BTL_SERVER_FLOW_CheckMoveInterrupt(p, a, id2, *(int *)(p + 0x854), F(0x4ac)) != 0) {
            BTL_SERVER_FLOW_ProcInterruptMove(p, a, id2, F(0x854));
        } else {
            o.c0 = BTL_SERVER_FLOW_ProcMoveExecute(p, a, id2, F(0x854));
        }
    }
end:
    BTL_POKEPARAM_SetTurnFlag((struct UtilWork *)a, 3);
    if (flag != 0 || chk1 != 0 || id2 == 0xa5) {
        BTL_POKEPARAM_RecordMoveUse(a, sel, o.c0, F(0x1ab0)[6], id2, id);
        ev18(*(void **)(p + 0xc), BTL_POKEPARAM_GetPokeId(a), sel, o.c0, F(0x1ab0)[6], id2, id);
    } else if (BTL_POKEPARAM_GetCounter(a, 3) != 0) {
        BTL_SERVER_FLOW_SetPokeCounter(p, a, 3, 0);
    }
    if (prev != 0x10 && BTL_POKEPARAM_GetSemiInvulnerableFlag((struct UtilWork *)a) != 0x10) BTL_SERVER_FLOW_ClearMoveLockSicks(p, a);
    if (BTL_POKEPARAM_TestTurnFlag((struct UtilWork *)a, 0xb) != 0) {
        BTL_SERVER_CMD_Push(*(void **)(p + 0xc), 0x31, BTL_POKEPARAM_GetPokeId(a), 0);
        BTL_SERVER_FLOW_ReleaseBindingTarget(p, a, 0);
    }
    BTL_SERVER_FLOW_NotifyMoveEnd(p, a, id2, o.c0);
    if (o.c2 != 0) HAND_WAZA_RemoveMoveHandlerUnlessKept(a, o.c2);
    HAND_WAZA_RemoveMoveHandlerUnlessKept(a, id);
    BTL_SERVER_FLOW_ProcDeferredMoves(p, id2);
}
