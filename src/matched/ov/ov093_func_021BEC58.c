/*
 * function: BTL_SERVER_FLOW_ProcMoveExecute
 * address: 0x021BEC58
 * packet: pkt_ov093_021BEC58
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * budget: 2 iteration one; scheduling variant1/2 consumed; no checks/permuter.
 * symbols:
 *   WAZA_TOOL_GetCategory 0x0201C1BC thumb
 *   WAZA_TOOL_GetFlag 0x0201BEB8 thumb
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_SERVER_FLOW_RecordSpecialMoveUse 0x021BEC2C thumb ov093
 *   BTL_SERVER_FLOW_ProcMoveExecuteChecks 0x021BFC08 thumb ov093
 *   func_021BEFEC 0x021BEFEC thumb ov093
 *   func_021BEFFC 0x021BEFFC thumb ov093
 *   func_021BF00C 0x021BF00C thumb ov093
 *   func_021BF01C 0x021BF01C thumb ov093
 *   func_021BF02C 0x021BF02C thumb ov093
 *   func_021BF03C 0x021BF03C thumb ov093
 *   BTL_SERVER_CMD_Reserve 0x021CD4FC thumb ov093
 *   BTL_SERVER_FLOW_SetupTurnState 0x021BD200 thumb ov093
 *   BTL_SERVER_FLOW_BeginHandExScope 0x021CC8D8 thumb ov093
 *   BTL_SERVER_FLOW_EndHandExScope 0x021CC95C thumb ov093
 *   BTL_SERVER_FLOW_QueryMoveExecuteEvent 0x021C65A8 thumb ov093
 *   BTL_SERVER_FLOW_PushPendingHpRecovery 0x021BFBD0 thumb ov093
 *   BTL_SERVER_FLOW_RemoveOutOfRangeTargets 0x021BF04C thumb ov093
 *   BTL_SERVER_FLOW_RemoveSelfTarget 0x021BF0E4 thumb ov093
 *   BTL_SERVER_FLOW_PushMsgStdFailed 0x021C5718 thumb ov093
 *   BTL_SERVER_FLOW_RemoveImmuneTargets 0x021BF83C thumb ov093
 *   BTL_SERVER_FLOW_ResetSlotTable 0x021CC8A0 thumb ov093
 *   BTL_SERVER_FLOW_CheckAccuracyCheckRequired 0x021BF168 thumb ov093
 *   BTL_SERVER_FLOW_ProcAccuracyCheck 0x021BF3D8 thumb ov093
 *   BTL_SERVER_FLOW_ProcNoEffectChecks 0x021BF4AC thumb ov093
 *   BTL_SERVER_FLOW_RemoveMissedTargets 0x021BF8D4 thumb ov093
 *   BTL_SERVER_FLOW_RemoveSubstituteTargets 0x021BF1B4 thumb ov093
 *   BTL_SERVER_FLOW_NotifyMoveFailed 0x021BF27C thumb ov093
 *   BTL_SERVER_FLOW_ProcMoveHitTargets 0x021C091C thumb ov093
 *   BTL_SERVER_FLOW_ProcMoveRankEffectAllTargets 0x021C2DC4 thumb ov093
 *   BTL_SERVER_FLOW_ProcMoveSickAllTargets 0x021C2488 thumb ov093
 *   BTL_SERVER_FLOW_ProcMoveRankAndSickAllTargets 0x021C3184 thumb ov093
 *   BTL_SERVER_FLOW_ProcMoveOhko 0x021C3438 thumb ov093
 *   BTL_SERVER_FLOW_ProcMoveForceSwitchAllTargets 0x021C376C thumb ov093
 *   BTL_SERVER_FLOW_ProcMoveRecoverHpAllTargets 0x021C3274 thumb ov093
 *   BTL_SERVER_FLOW_ProcMoveWeather 0x021C3AA8 thumb ov093
 *   BTL_SERVER_FLOW_ProcMoveSpecialEffect 0x021C3D08 thumb ov093
 *   BTL_SERVER_FLOW_SetContFlag 0x021C60EC thumb ov093
 *   BTL_SERVER_FLOW_NotifyMoveSucceeded 0x021BF244 thumb ov093
 *   BTL_SERVER_FLOW_NotifyMoveFinished 0x021BF2B4 thumb ov093
 *   BTL_SERVER_FLOW_ProcFaintedPoke 0x021C4F64 thumb ov093
 *
 * Single action/filter pipeline, with flags initialized at EC74..EC7E.
 * All exit paths and switch table mappings retain their original results.
 * CC8D8 returns the full pre-mutation 32-bit Lock (10+9+9+1+1+1+1).
 * ECFA saves all r0 and ED0E/ED14 forwards all r1 to own CC95C's u32
 * store; preserve line inputs 10A8/10AA under original return-use rule.
 * C5718's own one-input body does not erase the original loaded r1/r2.
 * Veneers EFEC/FFC/00C/01C/02C/03C forward respectively to ov095
 * CB3C/CEE4/CD50/CD50/CD50/D050; own matched records fix their widths.
 * Original ED78 branches onto ED7A: duplicated forced=1 arms retain the
 * cross-jumped break. Original EDB0..EDB4 extracts byte bit4, represented
 * by Bits78A. EE44 branches directly to EE6C, skipping C5718 at EE68;
 * only BF02C's true path performs that call before BF27C.
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct State { u16 f0; u8 f2, f3, f4; u8 a:1, b:1, rest:6; };
struct Bits78A { u8 low:4, skip:1, rest:3; };
struct Buf { u32 wpos, rpos; };
struct S { u32 id[6]; u16 a[6], b[6]; u8 c[6]; u16 d[6]; u8 n, max, f44, f45; };
struct Rec { u32 value; u16 kind; u8 data, flag; };
struct O { u32 pos; struct Rec r[120]; };
extern u32 WAZA_TOOL_GetCategory(u16);
extern u32 WAZA_TOOL_GetFlag(u16, u32);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_POKEPARAM_IsFainted(void *);
extern void BTL_SERVER_FLOW_RecordSpecialMoveUse(u8 *p, u8 *a, int c);
extern int BTL_SERVER_FLOW_ProcMoveExecuteChecks(u8 *, u8 *, u8 *, u16);
extern void func_021BEFEC(void *);
extern void func_021BEFFC(struct S *);
extern int func_021BF00C(struct S *);
extern int func_021BF01C(struct S *);
extern int func_021BF02C(struct S *);
extern void func_021BF03C(struct O *);
extern u32 BTL_SERVER_CMD_Reserve(struct Buf *, u32);
struct Unk021BD200;
extern void BTL_SERVER_FLOW_SetupTurnState(struct Unk021BD200 *p, u8 *q, u8 *a, int t);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *, int);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *, u32, int);
extern int BTL_SERVER_FLOW_QueryMoveExecuteEvent(u8 *, u8 *, u32, u8 *);
extern void BTL_SERVER_FLOW_PushPendingHpRecovery(u8 *, u32, u8 *, u32);
extern void BTL_SERVER_FLOW_RemoveOutOfRangeTargets(u8 *, u16 *, int, int);
extern void BTL_SERVER_FLOW_RemoveSelfTarget(int, u8 *, int, u8 *, int);
extern void BTL_SERVER_FLOW_PushMsgStdFailed(u8 *, u8 *, u32);
extern void BTL_SERVER_FLOW_RemoveImmuneTargets(u8 *, u16 *, u8 *, int);
extern void BTL_SERVER_FLOW_ResetSlotTable(u32 *p);
extern int BTL_SERVER_FLOW_CheckAccuracyCheckRequired(u8 *, u16 *, u8 *);
extern void BTL_SERVER_FLOW_ProcAccuracyCheck(u8 *, int, u8 *, int, void *);
extern void BTL_SERVER_FLOW_ProcNoEffectChecks(u8 *, u8 *, u8 *, void *, void *);
extern void BTL_SERVER_FLOW_RemoveMissedTargets(u8 *, u16 *, u8 *, int);
extern void BTL_SERVER_FLOW_RemoveSubstituteTargets(int, u16 *, int, int, int);
extern void BTL_SERVER_FLOW_NotifyMoveFailed(u8 *, u32, u32);
extern void BTL_SERVER_FLOW_ProcMoveHitTargets(u8 *, u8 *, u8 *, u8 *, u32, u32);
extern void BTL_SERVER_FLOW_ProcMoveRankEffectAllTargets(u8 *, u32, u32, u32);
extern void BTL_SERVER_FLOW_ProcMoveSickAllTargets(u8 *, u16, u8 *, u32);
extern void BTL_SERVER_FLOW_ProcMoveRankAndSickAllTargets(u8 *, const u16 *, u32, u32);
extern void BTL_SERVER_FLOW_ProcMoveOhko(u8 *, u16 *, u8 *, u8 *);
extern void BTL_SERVER_FLOW_ProcMoveForceSwitchAllTargets(u8 *, u16, int, int);
extern void BTL_SERVER_FLOW_ProcMoveRecoverHpAllTargets(u8 *, u32, u32, u32);
extern void BTL_SERVER_FLOW_ProcMoveWeather(u8 *, u16 *, u8 *);
extern void BTL_SERVER_FLOW_ProcMoveSpecialEffect(u8 *, u16 *, u8 *, u8 *);
extern void BTL_SERVER_FLOW_SetContFlag(u8 *p, u8 *a, u32 n);
extern void BTL_SERVER_FLOW_NotifyMoveSucceeded(u8 *, u32, u32);
extern void BTL_SERVER_FLOW_NotifyMoveFinished(u8 *, u32, u32);
extern int BTL_SERVER_FLOW_ProcFaintedPoke(u8 *, u8 *);

int BTL_SERVER_FLOW_ProcMoveExecute(u8 *p, u8 *a, u16 key, u8 *d)
{
    u32 lock;
    u32 action = WAZA_TOOL_GetCategory(key);
    u8 id = BTL_POKEPARAM_GetPokeId(a);
    int active = 1;
    int execute = 0;
    int forced = 0;
    u32 pos;
    int result;
    struct State *s;
    BTL_SERVER_FLOW_RecordSpecialMoveUse(p, a, key);
    if (WAZA_TOOL_GetFlag(key, 1)) {
        switch (BTL_SERVER_FLOW_ProcMoveExecuteChecks(p, a, d, key)) {
        case 0: break;
        case 1: return execute;
        case 2: return active;
        case 3: return execute;
        case 4: break;
        }
    }
    func_021BEFEC(((struct Obj00003 *)p)->f860);
    pos = BTL_SERVER_CMD_Reserve(*(struct Buf * *)&((struct Obj00003 *)p)->fC, 0x30);
    BTL_SERVER_FLOW_SetupTurnState((struct Unk021BD200 *)(*(struct State * *)&((struct Obj00003 *)p)->f4A8), p, a, (int)d);
    lock = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 0x10a8);
    result = BTL_SERVER_FLOW_QueryMoveExecuteEvent(p, a, key, d);
    BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), lock, 0x10aa);
    if (result != 0) {
        s = *(struct State * *)&((struct Obj00003 *)p)->f4A8;
        if (s->a == 0) s->a = 1;
        if (result == 2) {
            BTL_SERVER_FLOW_PushPendingHpRecovery(p, key, *(u8 * *)&((struct Obj00003 *)p)->f4A8, pos);
            return 1;
        }
    }
    switch (action) {
    case 0: case 4: case 6: case 7: case 8:
        execute = 1;
        forced = 1;
        break;
    case 9:
        forced = 1;
        break;
    }
    func_021BEFFC((struct S *)d);
    BTL_SERVER_FLOW_RemoveOutOfRangeTargets(p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, (int)a, (int)d);
    BTL_SERVER_FLOW_RemoveSelfTarget((int)p, a, (int)d, *(u8 * *)&((struct Obj00003 *)p)->f1AB0, execute);
    if (func_021BF00C((struct S *)d)) {
        if (((struct Bits78A *)(p + 0x78a))->skip == 0) BTL_SERVER_FLOW_PushMsgStdFailed(p, a, key);
        active = 0;
    }
    if (active != 0) {
        if (action != 9) BTL_SERVER_FLOW_RemoveImmuneTargets(p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, a, (int)d);
        BTL_SERVER_FLOW_ResetSlotTable((u32 *)(p + 0x1f88));
        if (forced != 0 || BTL_SERVER_FLOW_CheckAccuracyCheckRequired(p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, a))
            BTL_SERVER_FLOW_ProcAccuracyCheck(p, *(int *)&((struct Obj00003 *)p)->f1AB0, a, (int)d, p + 0x1f88);
        BTL_SERVER_FLOW_ProcNoEffectChecks(p, *(u8 * *)&((struct Obj00003 *)p)->f1AB0, a, d, p + 0x1f88);
        if (action != 9) BTL_SERVER_FLOW_RemoveMissedTargets(p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, a, (int)d);
        if (func_021BF01C((struct S *)d)) {
            BTL_SERVER_FLOW_NotifyMoveFailed(p, id, key);
            active = 0;
        } else {
            BTL_SERVER_FLOW_RemoveSubstituteTargets((int)p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, (int)a, (int)d, forced);
            if (func_021BF02C((struct S *)d)) {
                BTL_SERVER_FLOW_PushMsgStdFailed(p, a, key);
                BTL_SERVER_FLOW_NotifyMoveFailed(p, id, key);
                active = 0;
            }
        }
    }
    if (active != 0) {
        if (execute != 0) {
            BTL_SERVER_FLOW_ProcMoveHitTargets(p, *(u8 * *)&((struct Obj00003 *)p)->f1AB0, a, d, (u32)(p + 0x1f88), 0);
        } else {
            switch (action) {
            case 2: BTL_SERVER_FLOW_ProcMoveRankEffectAllTargets(p, *(u32 *)&((struct Obj00003 *)p)->f1AB0, (u32)a, (u32)d); break;
            case 1: BTL_SERVER_FLOW_ProcMoveSickAllTargets(p, key, a, (u32)d); break;
            case 5: BTL_SERVER_FLOW_ProcMoveRankAndSickAllTargets(p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, (u32)a, (u32)d); break;
            case 9: BTL_SERVER_FLOW_ProcMoveOhko(p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, a, d); break;
            case 12: BTL_SERVER_FLOW_ProcMoveForceSwitchAllTargets(p, key, (int)a, (int)d); break;
            case 3: BTL_SERVER_FLOW_ProcMoveRecoverHpAllTargets(p, key, (u32)a, (u32)d); break;
            case 10: BTL_SERVER_FLOW_ProcMoveWeather(p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, a); break;
            case 11: case 13: BTL_SERVER_FLOW_ProcMoveSpecialEffect(p, *(u16 * *)&((struct Obj00003 *)p)->f1AB0, a, d); break;
            }
        }
        s = *(struct State * *)&((struct Obj00003 *)p)->f4A8;
        if (s->a != 0) {
            if (s->b == 0) BTL_SERVER_FLOW_PushPendingHpRecovery(p, key, *(u8 * *)&((struct Obj00003 *)p)->f4A8, pos);
            func_021BF03C((struct O *)(p + 0x1c));
            if (!BTL_POKEPARAM_IsFainted(a) && WAZA_TOOL_GetFlag(key, 2)) BTL_SERVER_FLOW_SetContFlag(p, a, 12);
            BTL_SERVER_FLOW_NotifyMoveSucceeded(p, id, key);
        } else {
            BTL_SERVER_FLOW_NotifyMoveFailed(p, id, key);
            active = 0;
        }
    } else {
        s = *(struct State * *)&((struct Obj00003 *)p)->f4A8;
        if (s->a != 0) BTL_SERVER_FLOW_PushPendingHpRecovery(p, key, *(u8 * *)&((struct Obj00003 *)p)->f4A8, pos);
    }
    BTL_SERVER_FLOW_NotifyMoveFinished(p, id, key);
    BTL_SERVER_FLOW_ProcFaintedPoke(p, a);
    return active;
}
