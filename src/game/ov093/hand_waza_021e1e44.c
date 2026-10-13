/*
 * file:     hand_waza_021e1e44.c
 * unit:     yes
 * function: HAND_WAZA_FocusEnergyApplyEffect, HAND_WAZA_ChargeGetHandlers, HAND_WAZA_ChargeStoreOnUse, HAND_WAZA_ChargeBoostElectricPower, HAND_WAZA_ChargeArmOnNextMove, HAND_WAZA_ChargeExpireOnMoveEnd, HAND_WAZA_PerishSongGetHandlers, HAND_WAZA_PerishSongShowMessage, HAND_WAZA_PerishSongClearNoEffect, HAND_WAZA_LeechSeedGetHandlers, HAND_WAZA_LeechSeedSetSickCont, HAND_WAZA_PayDayGetHandlers
 * address:  0x021E1E44
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
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   BTL_EVENT_RemoveFactor  0x021D7040  thumb  ov093
 *   gChargeHandlers     0x021F2DD8  data   ov093  a4
 *   gPerishSongHandlers     0x021F2988  data   ov093  a4
 *   BTL_SERVER_FLOW_GetFrontPosOfPoke  0x021C7D00  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1Value  0x021E89D4  thumb  ov093
 *   gLeechSeedHandlers     0x021F250C  data   ov093  a4
 *   gPayDayHandlers     0x021F247C  data   ov093  a4
 */
#include "hand_waza_021e1c8c_types.h"

extern int BTL_POKEPARAM_TestContFlag(struct BtlPokeParam *poke, u32 flagId);
extern int BTL_SERVER_FLOW_GetFrontPosOfPoke(struct BtlSvFlow *flow, int pokeId);
extern union SickCont BTLV_CORE_MakeSlotKind1Value(int position);

void HAND_WAZA_FocusEnergyApplyEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_ChargeGetHandlers(int *handlerCount);
void HAND_WAZA_ChargeStoreOnUse(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaChargeWork *work);
void HAND_WAZA_ChargeBoostElectricPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaChargeWork *work);
void HAND_WAZA_ChargeArmOnNextMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaChargeWork *work);
void HAND_WAZA_ChargeExpireOnMoveEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaChargeWork *work);
BtlEventHandler *HAND_WAZA_PerishSongGetHandlers(int *handlerCount);
void HAND_WAZA_PerishSongShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_WAZA_PerishSongClearNoEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_LeechSeedGetHandlers(int *handlerCount);
void HAND_WAZA_LeechSeedSetSickCont(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_PayDayGetHandlers(int *handlerCount);
extern BtlEventHandler gChargeHandlers[]; /* Charge handler table */
extern BtlEventHandler gPerishSongHandlers[]; /* Perish Song handler table */
extern BtlEventHandler gLeechSeedHandlers[]; /* Leech Seed handler table */
extern BtlEventHandler gPayDayHandlers[]; /* Pay Day handler table */




/*
 * Focus Energy, status move effect: raise the critical-hit rate of the user
 * unless it is already raised, then show the message.
 * The tail after the pop (movs r1,#4; str r1,[r0]; ldr r0,[pc]; bx lr) is an
 * unlabelled follower stub.
 */
void HAND_WAZA_FocusEnergyApplyEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExSetContFlag *setFlag;
    HandExMessage *message;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_CONT_FLAG_CRITICAL_UP) == 0) {
            setFlag = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_CONT_FLAG, pokeId);
            setFlag->pokeId = pokeId;
            setFlag->flagId = BTL_CONT_FLAG_CRITICAL_UP;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, setFlag);
            message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&message->str, HANDEX_STR_SET, 0x411);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&message->str, pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
        }
    }
}




/* Charge handler table getter: four handlers. */
BtlEventHandler *HAND_WAZA_ChargeGetHandlers(int *handlerCount)
{
    *handlerCount = 4;
    return gChargeHandlers;
}




/*
 * Charge, move execute query: when the user executes Charge itself, show the
 * message and remember that the charge is stored.
 */
void HAND_WAZA_ChargeStoreOnUse(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaChargeWork *work)
{
    HandExMessage *message;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID) == BTL_EVENT_GetFactorKey(factor)) {
            message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&message->str, HANDEX_STR_SET, 0x298);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&message->str, pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
            BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_HANDLED_FLAG, 1);
            work->charged = 1;
            work->phase = 1;
        }
    }
}







/* Charge, power ratio event: an Electric move used with the charge doubles its power. */
void HAND_WAZA_ChargeBoostElectricPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaChargeWork *work)
{
    if (work->phase == 2) {
        if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
            if (BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE) == POKETYPE_ELECTRIC)
                BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_RATIO_2_0);
        }
    }
}







/* Charge, move start event: the next move other than Charge takes the stored charge. */
void HAND_WAZA_ChargeArmOnNextMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaChargeWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID) != BTL_EVENT_GetFactorKey(factor))
            work->phase = 2;
    }
}





/* Charge, move end event: the charge is used up, remove the factor. */
void HAND_WAZA_ChargeExpireOnMoveEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, HandWazaChargeWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (work->phase == 2)
            BTL_EVENT_RemoveFactor(factor);
    }
}



/* Perish Song handler table getter: two handlers. */
BtlEventHandler *HAND_WAZA_PerishSongGetHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gPerishSongHandlers;
}



/* Perish Song, move succeeded event: show the standard message. */
void HAND_WAZA_PerishSongShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExMessage *message;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&message->str, HANDEX_STR_STD, 0x77);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
    }
}




/* Perish Song, no-effect check: the move itself never fails. */
void HAND_WAZA_PerishSongClearNoEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID) == BTL_EVENT_GetFactorKey(factor))
            BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 0);
    }
}


/* Leech Seed handler table getter: one handler. */
BtlEventHandler *HAND_WAZA_LeechSeedGetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gLeechSeedHandlers;
}


/* Leech Seed, sick cont event: store the position of the seeder in the condition. */
void HAND_WAZA_LeechSeedSetSickCont(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        union SickCont seederCont = BTLV_CORE_MakeSlotKind1Value(BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, pokeId));
        BTL_EVENT_OverwriteVar(BTL_EVAR_SICK_CONT, seederCont.raw);
    }
}


/* Pay Day handler table getter: one handler. */
BtlEventHandler *HAND_WAZA_PayDayGetHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gPayDayHandlers;
}
