/*
 * file:     hand_waza_021e4154.c
 * unit:     yes
 * function: HAND_WAZA_BellyDrumMaximizeAttack, HAND_WAZA_GetFeintHandlers, HAND_WAZA_FeintSetBypassFlag, HAND_WAZA_FeintBreakProtect, HAND_WAZA_FeintBreakSideGuard, HAND_WAZA_GetAcupressureHandlers
 * address:  0x021E4154
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gAcupressureHandlers     0x021F27A4  data   ov093  a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_CALC_DivideMaxHpMin1 0x021D7B74 thumb ov093
 *   func_021D5D50 0x021D5D50 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   gFeintHandlers 0x021F2B10 data a4
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb
 *   BTL_POKEPARAM_TestTurnFlag  0x021D5BB0  thumb  ov093
 *   BTL_MAIN_IsPokeIdInSecondPair  0x021B9A40  thumb  ov093
 *   BTL_MAIN_IsZero  0x021B9A5C  thumb  ov093
 *   BTL_SERVER_FLOW_CheckSideEffectActive  0x021C82C4  thumb  ov093
 */
#include "hand_waza_021e396c_types.h"

/* Kind 0x1a record as Feint fills it: byte 0 selects the effect group, bytes 1 and 2 are flags. */
struct FeintRemoveRecord {
    u32 header;
    u8 filter[3];
    u8 side;
};

void HAND_WAZA_BellyDrumMaximizeAttack(int unused, struct BtlSvFlow *flow, int pokeId);
int *HAND_WAZA_GetFeintHandlers(int *handlerCount);
void HAND_WAZA_FeintSetBypassFlag(int unused, int unused2, int pokeId);
void HAND_WAZA_FeintBreakProtect(int unused, struct BtlSvFlow *flow, int pokeId, struct FeintWork *work);
void HAND_WAZA_FeintBreakSideGuard(int unused, struct BtlSvFlow *flow, int pokeId, struct FeintWork *work);
int *HAND_WAZA_GetAcupressureHandlers(int *handlerCount);
extern int gFeintHandlers[];
extern int gAcupressureHandlers[];

/* Belly Drum, event 0xa0: when the user has more than half HP and Attack can still rise, pays half the max HP
   and raises Attack to the maximum; shows its own message. */
void HAND_WAZA_BellyDrumMaximizeAttack(int unused, struct BtlSvFlow *flow, int pokeId)
{
    struct BtlPokeParam *bpp;
    int halfMaxHp;
    int attackRoom;
    struct HandExChangeHp *changeHp;
    struct HandExRankEffect *rankEffect;
    struct HandExMessageRecord *message;
    struct HandExRefreshHpGauge *gauge;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        halfMaxHp = BTL_CALC_DivideMaxHpMin1(bpp, 2);
        attackRoom = func_021D5D50(bpp, BTL_RANK_ATTACK);
        if (func_021D59B4(bpp, BPP_VALUE_HP) > (u32)halfMaxHp && attackRoom != 0) {
            changeHp = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CHANGE_HP, pokeId);
            changeHp->pokeCount = 1;
            changeHp->updateGauge = 1;
            changeHp->pokeIds[0] = pokeId;
            changeHp->amounts[0] = -halfMaxHp;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, changeHp);
            rankEffect = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RANK_EFFECT, pokeId);
            rankEffect->rankKind = BTL_RANK_ATTACK;
            rankEffect->volume = attackRoom;
            rankEffect->pokeCount = 1;
            rankEffect->pokeId = pokeId;
            rankEffect->bypassBlockers = 1;
            rankEffect->suppressMessage = 1;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, rankEffect);
            message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&message->message, BTL_MSG_KIND_SET, HAND_WAZA_STR_BELLY_DRUM);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&message->message, pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
            gauge = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_REFRESH_HP_GAUGE, pokeId);
            gauge->pokeId = pokeId;
            gauge->mode = 1;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, gauge);
        }
    }
}

/* Feint (move 364): handler table, 3 rows. */
int *HAND_WAZA_GetFeintHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gFeintHandlers;
}

/*
 * Feint, event 0x2e: the move ignores protection (sets the shared flag).
 * Leaf with no calls and no pool; 10 instructions, 24 bytes.
 */
void HAND_WAZA_FeintSetBypassFlag(int unused, int unused2, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_GENERIC_FLAG, 1);
}

/* Feint, event 0x45: when the target was protecting itself (or a guard was just removed), clears its protected turn
   flag and shows the message. */
void HAND_WAZA_FeintBreakProtect(int unused, struct BtlSvFlow *flow, int pokeId, struct FeintWork *work)
{
    u8 targetId;
    struct HandExTurnFlag *turnFlag;
    struct HandExMessageRecord *message;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
        if (BTL_POKEPARAM_TestTurnFlag(BTL_SERVER_FLOW_GetPokeParam(flow, targetId), BTL_TURN_FLAG_PROTECTED) != 0 || work->guardBroken != 0) {
            turnFlag = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CLEAR_TURN_FLAG, pokeId);
            turnFlag->pokeId = targetId;
            turnFlag->flag = BTL_TURN_FLAG_PROTECTED;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, turnFlag);
            message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&message->message, BTL_MSG_KIND_SET, HAND_WAZA_STR_FEINT);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&message->message, targetId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
        }
    }
}

/* Feint, event 0x23: removes Quick Guard or Wide Guard from the side of the target. */
void HAND_WAZA_FeintBreakSideGuard(int unused, struct BtlSvFlow *flow, int pokeId, struct FeintWork *work)
{
    int side;
    u32 i;
    struct FeintRemoveRecord *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        side = BTL_MAIN_IsZero(BTL_MAIN_IsPokeIdInSecondPair(pokeId));
        if (BTL_SERVER_FLOW_CheckSideEffectActive(flow, side, BTL_SIDE_EFFECT_QUICK_GUARD) != 0 || BTL_SERVER_FLOW_CheckSideEffectActive(flow, side, BTL_SIDE_EFFECT_WIDE_GUARD) != 0) {
            record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_REMOVE_SIDE_EFFECT, pokeId);
            record->side = side;
            record->filter[0] = 3;
            for (i = 1; i < 3; i++)
                record->filter[i] = 0;
            if (record->filter[0] > 2)
                record->filter[2] |= 2;
            if (record->filter[0] > 2)
                record->filter[2] |= 4;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
            work->guardBroken = 1;
        }
    }
}

/* Acupressure (move 367): handler table, 1 row (its handler is the first function of the next unit). */
int *HAND_WAZA_GetAcupressureHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gAcupressureHandlers;
}
