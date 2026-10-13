/*
 * file:     hand_waza_021e4340.c
 * unit:     yes
 * function: HAND_WAZA_AcupressureRaiseRandomStat, HAND_WAZA_GetRestHandlers, HAND_WAZA_RestCheckFail, HAND_WAZA_RestSleepAndHeal, HAND_WAZA_GetAttractHandlers, HAND_WAZA_AttractCheckGender, HAND_WAZA_GetConversion2Handlers, HAND_WAZA_Conversion2ChangeType, HAND_WAZA_GetEncoreHandlers, HAND_WAZA_EncoreAddSick, HAND_WAZA_GetTauntHandlers
 * address:  0x021E4340
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
 *   func_0689C8AC  0x0689C8AC  thumb
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   func_021D5D14 0x021D5D14 thumb ov093
 *   BTL_CALC_Random 0x021D78AC thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   gAcupressureStats 0x021F2D20 data a4
 *   gRestHandlers 0x021F2888 data a4
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb ov093
 *   BTL_POKEPARAM_HasSick   0x021D62C4  thumb ov093
 *   BTL_POKEPARAM_IsHpFull   0x021D5B48  thumb ov093
 *   func_021D59B4   0x021D59B4  thumb ov093
 *   BTL_CALC_MakeSickContTurns 0x021D7D78 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   gAttractHandlers 0x021F278C data a4
 *   BTL_POKEPARAM_GetLastTargetPos  0x021D67B0  thumb  ov093
 *   BTL_SERVER_FLOW_GetScratchBuffer  0x021C8120  thumb  ov093
 *   BTL_CALC_ListResistingTypes  0x021D7A9C  thumb  ov093
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb  ov093
 *   func_02082D44  0x02082D44  arm
 *   BTLV_CORE_PackByteTwice  0x021E8CF0  thumb  ov093
 *   gConversion2Handlers     0x021F2784  data   ov093  a4
 *   BTL_POKEPARAM_GetLastSelectedMoveId  0x021D67B8  thumb  ov093
 *   BTL_POKEPARAM_GetMovePPById  0x021D55A0  thumb  ov093
 *   BTL_POKEPARAM_TestTurnFlag  0x021D5BB0  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2  0x021E896C  thumb  ov093
 *   gEncoreHandlers     0x021F25E4  data   ov093  a4
 *   gTauntHandlers     0x021F2774  data   ov093  a4
 *   HAND_WAZA_GetTauntHandlers  0x021E4748  thumb  ov093
 */
#include "hand_waza_021e396c_types.h"

/* Encore lasts 3 turns, 4 when the target already acted this turn; the enum type keeps the byte arithmetic of the original. */
typedef enum { ENCORE_TURNS_BASE } EncoreTurns;

void HAND_WAZA_AcupressureRaiseRandomStat(int unused, struct BtlSvFlow *flow, int pokeId);
int *HAND_WAZA_GetRestHandlers(int *handlerCount);
void HAND_WAZA_RestCheckFail(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_WAZA_RestSleepAndHeal(int unused, struct BtlSvFlow *flow, int pokeId);
int *HAND_WAZA_GetAttractHandlers(int *handlerCount);
void HAND_WAZA_AttractCheckGender(int unused, struct BtlSvFlow *flow, int pokeId);
int *HAND_WAZA_GetConversion2Handlers(int *handlerCount);
void HAND_WAZA_Conversion2ChangeType(int unused, struct BtlSvFlow *flow, int pokeId);
int *HAND_WAZA_GetEncoreHandlers(int *handlerCount);
void HAND_WAZA_EncoreAddSick(int unused, struct BtlSvFlow *flow, int pokeId);
int *HAND_WAZA_GetTauntHandlers(int *handlerCount);
extern const u32 gAcupressureStats[];
extern int gRestHandlers[];
extern int gAttractHandlers[];
extern int gConversion2Handlers[];
extern int gEncoreHandlers[];
extern int gTauntHandlers[];

/*
 * Acupressure, event 0xa0: raises a random stat of the target by 2 stages, among the stats that can still rise.
 * Lever: chained candidateCount = i = 0 initializes the index first; a fresh byte
 * pick for the random selection keeps the second loop's count in r4.
 * Reusing candidateCount for that selection swaps the second loop's r4/r5 allocation.
 */
void HAND_WAZA_AcupressureRaiseRandomStat(int unused, struct BtlSvFlow *flow, int pokeId)
{
    u8 targetId;
    struct BtlPokeParam *bpp;
    u8 candidateCount;
    u8 i;
    struct HandExRankEffect *record;
    u8 pick;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_FIRST);
        bpp = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        candidateCount = i = 0;
        for (; i < BTL_RANK_STAT_COUNT; i++) {
            if (func_021D5D14(bpp, gAcupressureStats[i], BTL_RANK_DIRECTION_RAISE) != 0)
                candidateCount++;
        }
        if (candidateCount != 0) {
            pick = BTL_CALC_Random(candidateCount);
            for (i = 0; i < BTL_RANK_STAT_COUNT; i++) {
                if (func_021D5D14(bpp, gAcupressureStats[i], BTL_RANK_DIRECTION_RAISE) != 0) {
                    if (pick == 0) {
                        record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RANK_EFFECT, pokeId);
                        record->pokeId = targetId;
                        record->pokeCount = 1;
                        record->rankKind = gAcupressureStats[i];
                        record->volume = 2;
                        record->suppressMessage = 0;
                        BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
                        return;
                    }
                    pick--;
                }
            }
        }
    }
}

/* Rest (move 156): handler table, 2 rows. */
int *HAND_WAZA_GetRestHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gRestHandlers;
}

/*
 * Rest, event 0x1f: sets the fail reason of the move. Two-key gate: only when this is the user and no reason was set yet.
 * Then, in order: already asleep (generic), a sleep-blocking condition, full HP, and an ability
 * (Insomnia or Vital Spirit) that stops sleep. The ability check is the only one that reads the 16-bit value.
 */
void HAND_WAZA_RestCheckFail(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u16 abilityId;
    struct BtlPokeParam *bpp;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_FAIL_REASON) != 0)
        return;
    bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    if (BTL_POKEPARAM_HasSick(bpp, BTL_SICK_SLEEP) != 0) {
        BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_GENERIC);
        return;
    }
    if (BTL_POKEPARAM_HasSick(bpp, BTL_SICK_SLEEP_BLOCK) != 0) {
        BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_SLEEP_BLOCKED);
        return;
    }
    if (BTL_POKEPARAM_IsHpFull(bpp) != 0) {
        BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_HP_FULL);
        return;
    }
    abilityId = func_021D59B4(bpp, BPP_VALUE_CURRENT_ABILITY);
    if (abilityId == ABILITY_INSOMNIA || abilityId == ABILITY_VITAL_SPIRIT)
        BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_ABILITY_BLOCKS_SLEEP);
}

/* Rest, event 0xa0: the user falls asleep for 3 turns and recovers all HP. */
void HAND_WAZA_RestSleepAndHeal(int unused, struct BtlSvFlow *flow, int pokeId)
{
    struct BtlPokeParam *bpp;
    struct HandExAddSick *addSick;
    struct HandExRecoverHp *recover;
    struct HandExRefreshHpGauge *gauge;
    u32 maxHp;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_IsHpFull(bpp) == 0) {
            addSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
            addSick->pokeId = pokeId;
            addSick->sickKind = BTL_SICK_SLEEP;
            addSick->sickCont = BTL_CALC_MakeSickContTurns(3);
            addSick->replaceExisting = 1;
            addSick->useOwnMessage = 1;
            addSick->ignoreImmunity = 1;
            BTL_SERVER_FLOW_InitMsgRecord(&addSick->message, BTL_MSG_KIND_SET, HAND_WAZA_STR_REST);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&addSick->message, pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, addSick);
            recover = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RECOVER_HP, pokeId);
            recover->pokeId = pokeId;
            maxHp = func_021D59B4(bpp, BPP_VALUE_MAX_HP);
            recover->amount = maxHp - func_021D59B4(bpp, BPP_VALUE_HP);
            recover->header |= HANDEX_FLAG_SILENT;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, recover);
            gauge = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_REFRESH_HP_GAUGE, pokeId);
            gauge->pokeId = pokeId;
            gauge->mode = 3;
            gauge->header |= HANDEX_FLAG_SILENT;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, gauge);
            BTL_EVENT_OverwriteVar(BTL_EVAR_GENERIC_FLAG, 0);
        }
    }
}

/* Attract (move 213): handler table, 1 row. */
int *HAND_WAZA_GetAttractHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gAttractHandlers;
}

/* Attract, event 0x2c: no effect when either Pokemon is genderless or both have the same gender. */
void HAND_WAZA_AttractCheckGender(int unused, struct BtlSvFlow *flow, int pokeId)
{
    struct BtlPokeParam *userBpp;
    struct BtlPokeParam *targetBpp;
    u8 userGender;
    u8 targetGender;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        userBpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        targetBpp = BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID));
        userGender = func_021D59B4(userBpp, BPP_VALUE_GENDER);
        targetGender = func_021D59B4(targetBpp, BPP_VALUE_GENDER);
        if (userGender == BTL_GENDER_NONE || targetGender == BTL_GENDER_NONE || userGender == targetGender)
            BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 1);
    }
}

/* Conversion 2 (move 176): handler table, 1 row. */
int *HAND_WAZA_GetConversion2Handlers(int *handlerCount)
{
    *handlerCount = 1;
    return gConversion2Handlers;
}

/* Conversion 2, event 0xa0: the user takes a random type that resists the type of the last move the target used.
   Types the user already has are removed from the candidate list first. */
void HAND_WAZA_Conversion2ChangeType(int unused, struct BtlSvFlow *flow, int pokeId)
{
    int lastMoveType;
    u8 *types;
    u32 typeCount;
    struct BtlPokeParam *userBpp;
    u32 i;
    int newType;
    struct HandExChangeType *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        lastMoveType = BTL_POKEPARAM_GetLastTargetPos(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_FIRST)));
        if (lastMoveType != 0x11) {
            types = BTL_SERVER_FLOW_GetScratchBuffer(flow, 0x11);
            typeCount = BTL_CALC_ListResistingTypes(lastMoveType, types);
            if (typeCount != 0) {
                userBpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
                i = 0;
                while (i < typeCount) {
                    if (BTL_POKEPARAM_HasType(userBpp, types[i]) != 0) {
                        if ((int)(typeCount - 1 - i) > 0)
                            func_02082D44(types + (i + 1), types + i, typeCount - 1 - i);
                        typeCount--;
                    } else {
                        i++;
                    }
                }
                if (typeCount != 0) {
                    newType = types[BTL_CALC_Random(typeCount)];
                    record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CHANGE_TYPE, pokeId);
                    record->typePair = BTLV_CORE_PackByteTwice(newType);
                    record->pokeId = pokeId;
                    BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
                }
            }
        }
    }
}

/* Encore (move 227): handler table, 1 row. */
int *HAND_WAZA_GetEncoreHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gEncoreHandlers;
}

/* Encore, event 0xa0: forces the target to repeat its last move when that move can be encored and has PP left. */
void HAND_WAZA_EncoreAddSick(int unused, struct BtlSvFlow *flow, int pokeId)
{
    EncoreTurns turns = 3;
    u8 targetId;
    struct BtlPokeParam *targetBpp;
    int lastMoveId;
    struct HandExAddSick *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_FIRST);
        targetBpp = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        lastMoveId = BTL_POKEPARAM_GetLastSelectedMoveId(targetBpp);
        if (BTL_POKEPARAM_HasSick(targetBpp, BTL_SICK_ENCORE) == 0 && func_0689C8AC(lastMoveId) == 0 && BTL_POKEPARAM_GetMovePPById(targetBpp, lastMoveId) != 0) {
            if (BTL_POKEPARAM_TestTurnFlag(targetBpp, BTL_TURN_FLAG_ACTED) != 0)
                turns = (u8)(turns + 1);
            record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
            record->sickKind = BTL_SICK_ENCORE;
            record->sickCont = BTLV_CORE_MakeSlotKind2(turns, lastMoveId);
            record->pokeId = targetId;
            record->replaceExisting = 0;
            BTL_SERVER_FLOW_InitMsgRecord(&record->message, BTL_MSG_KIND_SET, HAND_WAZA_STR_ENCORE);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&record->message, targetId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
        }
    }
}

/* Taunt (move 269): handler table, 1 row (its handler is the first function of the next unit). */
int *HAND_WAZA_GetTauntHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gTauntHandlers;
}
