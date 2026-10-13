/*
 * function: BTL_SERVER_FLOW_CheckMoveExecuteFail
 * address: 0x021C001C
 * packet: pkt_ov093_021C001C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Naming the one-word union result before passing it restores the original frame.
 * Symbol hints retain the Thumb ISA of the two already-matched ARM9 callees.
 * symbols:
 *   WAZA_TOOL_GetFlag 0x0201BEB8 thumb
 *   WAZA_TOOL_IsDamaging 0x0201C314 thumb
 *   BTL_SERVER_FLOW_TickSleepTurn 0x021C03D8 thumb ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex 0x021D62A8 thumb ov093
 *   BTL_SERVER_FLOW_QueryStatusSkipEvent 0x021C0274 thumb ov093
 *   BTL_SERVER_FLOW_CheckFreezeThaw 0x021C0404 thumb ov093
 *   BTL_POKEPARAM_FindMoveSlot 0x021D5778 thumb ov093
 *   BTL_POKEPARAM_GetMovePPChecked 0x021D5584 thumb ov093
 *   BTL_SERVER_FLOW_QueryMoveFailReasonEvent 0x021C02CC thumb ov093
 *   BTL_POKEPARAM_TestTurnFlag 0x021D5BB0 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_POKEPARAM_GetSickContRaw 0x021D6314 thumb ov093
 *   BTLV_CORE_GetSlotValue 0x021E8B80 thumb ov093
 *   BTL_FIELD_GetStaticSlotObject 0x021EF948 thumb ov093
 *   BTL_POKEPARAM_GetLastSelectedMoveId 0x021D67B8 thumb ov093
 *   BTL_POKEPARAM_GetLastUsedMoveId 0x021D67A8 thumb ov093
 *   func_021EF91C 0x021EF91C thumb ov093
 *   BTL_SERVER_FLOW_CheckParalysisFail 0x021C031C thumb ov093
 *   BTL_CALC_RollPercent 0x021D7AF0 thumb ov093
 *   BTL_SERVER_FLOW_CheckConfusionSelfHit 0x021C03AC thumb ov093
 *   BTL_SERVER_FLOW_ProcMoveExecuteFail 0x021C0450 thumb ov093
 *   BTL_SERVER_FLOW_PushMoveFailMessage 0x021C0520 thumb ov093
 *   BTL_SERVER_FLOW_PushPokeEffectAnim 0x021C5480 thumb ov093
 *   BTL_SERVER_FLOW_CureMajorStatusWithMessage 0x021C557C thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_CMD_PushVariable 0x021CD64C thumb ov093
 */
#include "../include/Obj04359.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
union Slot {
    struct { u32 kind:3; u32 pad:6; u32 id:16; u32 rest:7; } a;
    struct { u32 kind:3; u32 pad:12; u32 id:16; u32 rest:1; } b;
};
extern void BTL_SERVER_FLOW_TickSleepTurn(u8 *, u8 *, u16);
struct QL;
struct Unk021D62A8;
struct UtilWork;
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern int BTL_SERVER_FLOW_QueryStatusSkipEvent(u8 *, u8 *, u32, u32);
extern int BTL_SERVER_FLOW_CheckFreezeThaw(u8 *, u8 *, void *);
struct UtilWork;
extern u8 BTL_POKEPARAM_FindMoveSlot(struct UtilWork *p, u16 id);
extern u8 BTL_POKEPARAM_GetMovePPChecked(struct UtilWork *p, u32 i);
extern int BTL_SERVER_FLOW_QueryMoveFailReasonEvent(u8 *, u8 *, u32, int);
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern union Slot BTL_POKEPARAM_GetSickContRaw(void *, int);
extern u16 BTLV_CORE_GetSlotValue(union Slot);
extern u32 WAZA_TOOL_GetFlag(u16, u32);
extern int BTL_FIELD_GetStaticSlotObject(int);
extern u16 BTL_POKEPARAM_GetLastSelectedMoveId(u8 *);
extern u16 BTL_POKEPARAM_GetLastUsedMoveId(struct QL *p);
extern u32 WAZA_TOOL_IsDamaging(void *p);
extern int func_021EF91C(void *, u8 *, u16);
extern int BTL_SERVER_FLOW_CheckParalysisFail(u8 *, u8 *);
extern int BTL_CALC_RollPercent(u32);
extern int BTL_SERVER_FLOW_CheckConfusionSelfHit(u8 *, u8 *);
extern void BTL_SERVER_FLOW_ProcMoveExecuteFail(u8 *, u8 *, u16, int);
extern void BTL_SERVER_FLOW_PushMoveFailMessage(u8 *, u8 *, u16, u32);
extern void BTL_SERVER_FLOW_PushPokeEffectAnim(u8 *, u8 *, int);
extern void BTL_SERVER_FLOW_CureMajorStatusWithMessage(u8 *, u8 *, int, int);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *);
extern void BTL_SERVER_CMD_PushVariable(void *, u8, ...);
int BTL_SERVER_FLOW_CheckMoveExecuteFail(u8 *p, u8 *a, u16 c, u16 d)
{
    int mode;
    int changed = 0;
    int reason;
    union Slot move;
    BTL_SERVER_FLOW_TickSleepTurn(p, a, c);
    mode = BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)a);
    if (mode == 2) {
        reason = 2;
        if (BTL_SERVER_FLOW_QueryStatusSkipEvent(p, a, c, 2) == 0) goto done;
    }
    changed = BTL_SERVER_FLOW_CheckFreezeThaw(p, a, (void *)c);
    mode = BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)a);
    if (mode == 3 && changed == 0) { reason = 4; goto done; }
    if (((struct Obj04359 *)p)->f1F78 == 4) { reason = 22; goto done; }
    if (((struct Obj04359 *)p)->f1F78 == 2) { reason = 23; goto done; }
    if (d == 0) {
        int index = BTL_POKEPARAM_FindMoveSlot((struct UtilWork *)a, c);
        if (index != 4 && BTL_POKEPARAM_GetMovePPChecked((struct UtilWork *)a, index) == 0) { reason = 1; goto done; }
    }
    reason = BTL_SERVER_FLOW_QueryMoveFailReasonEvent(p, a, c, 30);
    if (reason) goto done;
    if (BTL_POKEPARAM_TestTurnFlag((struct UtilWork *)a, 6)) { reason = 7; goto done; }
    if (BTL_POKEPARAM_TestTurnFlag((struct UtilWork *)a, 4)) { reason = 6; goto done; }
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 13) && c != 165) {
        move = BTL_POKEPARAM_GetSickContRaw(a, 13);
        if (c == BTLV_CORE_GetSlotValue(move)) { reason = 9; goto done; }
    }
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 15) && WAZA_TOOL_GetFlag(c, 12)) { reason = 13; goto done; }
    if (BTL_FIELD_GetStaticSlotObject(2) && WAZA_TOOL_GetFlag(c, 9)) { reason = 20; goto done; }
    if (c != 165) {
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 23)) {
            u16 id = BTL_POKEPARAM_GetLastSelectedMoveId(a);
            if (id != 165 && id != c) { reason = 17; goto done; }
        }
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 25) && c != BTL_POKEPARAM_GetLastUsedMoveId((struct QL *)a)) { reason = 17; goto done; }
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 11) && WAZA_TOOL_IsDamaging((void *)c) == 0) { reason = 10; goto done; }
        if (BTL_FIELD_GetStaticSlotObject(3) && func_021EF91C(((struct Obj04359 *)p)->f8, a, c)) { reason = 12; goto done; }
    }
    if (BTL_SERVER_FLOW_CheckParalysisFail(p, a)) { reason = 5; goto done; }
    if (mode == 1 && BTL_CALC_RollPercent(25)) { reason = 3; goto done; }
    if (BTL_SERVER_FLOW_CheckConfusionSelfHit(p, a)) reason = 8;
done:
    if (reason) {
        BTL_SERVER_FLOW_ProcMoveExecuteFail(p, a, c, reason);
        return 1;
    }
    if (mode == 2) {
        BTL_SERVER_FLOW_PushMoveFailMessage(p, a, c, 2);
        BTL_SERVER_FLOW_PushPokeEffectAnim(p, a, 598);
    } else if (changed && mode == 3) {
        BTL_SERVER_FLOW_CureMajorStatusWithMessage(p, a, mode, 0);
        BTL_SERVER_CMD_PushVariable(((struct Obj04359 *)p)->fC, 91, 303, BTL_POKEPARAM_GetPokeId(a), c, 0xffff0000);
    }
    return 0;
}
