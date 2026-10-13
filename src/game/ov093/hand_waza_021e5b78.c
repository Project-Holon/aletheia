/*
 * file:     hand_waza_021e5b78.c
 * unit:     yes
 * function: HAND_WAZA_GetBatonPassHandlers, HAND_WAZA_BatonPassSwitchOut, HAND_WAZA_TeleportCheckFail, HAND_WAZA_TeleportEscape, HAND_WAZA_TeleportShowFailMessage, HAND_WAZA_GetFlingHandlers, HAND_WAZA_FlingCheckFail, HAND_WAZA_FlingSetBasePower, HAND_WAZA_FlingShowMessage, HAND_WAZA_FlingUseItemOnTarget, HAND_WAZA_FlingRemoveItemAfterMove, HAND_WAZA_GetMagnetRiseHandlers, HAND_WAZA_MagnetRiseCheckFail, HAND_WAZA_MagnetRiseAddFloating, HAND_WAZA_GetHelpingHandHandlers, HAND_WAZA_HelpingHandSetGenericFlag, HAND_WAZA_HelpingHandClearProtectBypass, HAND_WAZA_HelpingHandAssistAlly, HAND_WAZA_HelpingHandBoostPower, HAND_WAZA_HelpingHandRemoveAtTurnEnd, HAND_WAZA_GetBeatUpHandlers, HAND_WAZA_BeatUpSetHitCount, HAND_WAZA_BeatUpSetBasePower, HAND_WAZA_FindBeatUpMember, HAND_WAZA_GetFakeOutHandlers, HAND_WAZA_FakeOutCheckFail, HAND_WAZA_GetWeatherHealHandlers
 * address:  0x021E5B6C
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
 *   gBatonPassHandlers     0x021F2454  data   ov093  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_CheckClientHasBackupPoke  0x021C7F24  thumb  ov093
 *   BTL_SERVER_FLOW_TrySetOnceFlag  0x021C7F4C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gTeleportHandlers     0x021F2CD8  data   ov093  a4
 *   BTL_SERVER_FLOW_GetCompetitor  0x021C8168  thumb  ov093
 *   BTL_SERVER_FLOW_GetRule  0x021C815C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_EVENT_KeepFactorRunning  0x021D70C8  thumb  ov093
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_CALC_GetMonParamWithHeap  0x021D805C  thumb  ov093
 *   BTL_SERVER_FLOW_CanUseHeldItem  0x021C824C  thumb  ov093
 *   BTLV_CORE_CheckPartySlotPair  0x021E869C  thumb  ov093
 *   gFlingHandlers     0x021F2EC8  data   ov093  a4
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   gMagnetRiseHandlers     0x021F2A38  data   ov093  a4
 *   BTL_SERVER_FLOW_GetActivePosPerSide   0x021C8180  thumb ov093
 *   BTL_POKEPARAM_IsFainted   0x021D5B68  thumb ov093
 *   BTL_POKEPARAM_TestTurnFlag   0x021D5BB0  thumb ov093
 *   BTL_EVENT_MarkFactorDead   0x021D7090  thumb ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   BTL_EVENT_RemoveFactor   0x021D7040  thumb
 *   gHelpingHandHandlers     0x021F2EF0  data   ov093  a4
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   _u32_div_f     0x0209C2B0  arm
 *   BTL_SERVER_FLOW_GetPartyOfPoke  0x021C7FCC  thumb  ov093
 *   BTL_SLOT_GetCount  0x021B9B94  thumb  ov093
 *   BTL_SLOT_GetPokeParam  0x021B9C00  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_POKEPARAM_IsAbleToBattle  0x021D5B7C  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   gBeatUpHandlers     0x021F2A68  data   ov093  a4
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   gFakeOutHandlers     0x021F242C  data   ov093  a4
 *   gWeatherHealHandlers     0x021F240C  data   ov093  a4
 */
#include "hand_waza_021e5620_types.h"

struct BtlParty;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_SERVER_FLOW_CheckClientHasBackupPoke(struct BtlServerFlow *flow, int pokeId);
extern int BTL_SERVER_FLOW_TrySetOnceFlag(struct BtlServerFlow *flow);
extern int BTL_SERVER_FLOW_GetPokeViewPos(struct BtlServerFlow *flow, unsigned int pokeId);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(struct BtlServerFlow *flow, int kind, int pokeId);
extern void BTL_SERVER_FLOW_CommitCmdRecord(struct BtlServerFlow *flow, void *record);
extern int BTL_SERVER_FLOW_GetCompetitor(struct BtlServerFlow *flow);
extern int BTL_SERVER_FLOW_GetRule(struct BtlServerFlow *flow);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlServerFlow *flow, int pokeId);
extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *pokeParam, int sickKind);
extern void BTL_EVENT_KeepFactorRunning(struct BtlEventFactor *factor);
extern void BTL_SERVER_FLOW_PushCmdRecord(struct BtlServerFlow *flow, int kind, int pokeId);
extern void BTL_SERVER_FLOW_InitMsgRecord(struct HandExMessage *message, int kind, int messageId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct HandExMessage *message, u32 arg);
extern u16 BTL_POKEPARAM_GetItem(struct BtlPokeParam *pokeParam);
extern u32 BTL_CALC_GetMonParamWithHeap(u32 itemId, u32 paramId);
extern int BTL_SERVER_FLOW_CanUseHeldItem(struct BtlServerFlow *flow, int pokeId);
extern int BTLV_CORE_CheckPartySlotPair(struct BtlServerFlow *flow, int pokeId);
extern union SickCont BTLV_CORE_MakeSlotKind2Index(u8 turns);
int BTL_SERVER_FLOW_GetActivePosPerSide(struct BtlServerFlow *flow);
int BTL_POKEPARAM_IsFainted(struct BtlPokeParam *pokeParam);
int BTL_POKEPARAM_TestTurnFlag(struct BtlPokeParam *pokeParam, u32 turnFlag);
void BTL_EVENT_MarkFactorDead(struct BtlEventFactor *factor);
extern void BTL_EVENT_MultiplyVar(int key, int factor);
extern int func_021D59B4(struct BtlPokeParam *pokeParam, int valueId);
extern u32 _u32_div_f(u32, u32);
extern struct BtlParty *BTL_SERVER_FLOW_GetPartyOfPoke(struct BtlServerFlow *flow, int pokeId);
extern u8 BTL_SLOT_GetCount(struct BtlParty *party);
extern struct BtlPokeParam *BTL_SLOT_GetPokeParam(struct BtlParty *party, u32 index);
extern u8 BTL_POKEPARAM_GetPokeId(struct BtlPokeParam *pokeParam);
extern int BTL_POKEPARAM_IsAbleToBattle(struct BtlPokeParam *pokeParam);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct BtlPokeParam *pokeParam);
extern int BTL_POKEPARAM_TestContFlag(struct BtlPokeParam *pokeParam, u32 contFlag);
extern void BTL_EVENT_RemoveFactor(struct BtlEventFactor *factor);
extern int gBatonPassHandlers[];
extern int gTeleportHandlers[];
extern int gFlingHandlers[];
extern int gMagnetRiseHandlers[];
extern int gHelpingHandHandlers[];
extern int gBeatUpHandlers[];
extern int gFakeOutHandlers[];
extern int gWeatherHealHandlers[];

/* Item parameters read by Fling. */
#define ITEM_PARAM_FLING_EFFECT 9
#define ITEM_PARAM_FLING_POWER 10

/* Value id of the base Attack stat of a species, used by Beat Up. */
#define BPP_VALUE_BASE_ATTACK 0x15

/* Number of party slots Beat Up walks through. */
#define BEAT_UP_PARTY_SLOTS 6

#define MAGNET_RISE_TURNS 5

int *HAND_WAZA_GetBatonPassHandlers(int *handlerCount);
void HAND_WAZA_BatonPassSwitchOut(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetTeleportHandlers(int *handlerCount);
void HAND_WAZA_TeleportCheckFail(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_TeleportEscape(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_TeleportShowFailMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetFlingHandlers(int *handlerCount);
void HAND_WAZA_FlingCheckFail(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_FlingSetBasePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_FlingShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_FlingUseItemOnTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_FlingRemoveItemAfterMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
int *HAND_WAZA_GetMagnetRiseHandlers(int *handlerCount);
void HAND_WAZA_MagnetRiseCheckFail(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_MagnetRiseAddFloating(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetHelpingHandHandlers(int *handlerCount);
void HAND_WAZA_HelpingHandSetGenericFlag(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_HelpingHandClearProtectBypass(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_HelpingHandAssistAlly(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_HelpingHandBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_HelpingHandRemoveAtTurnEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetBeatUpHandlers(int *handlerCount);
void HAND_WAZA_BeatUpSetHitCount(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
void HAND_WAZA_BeatUpSetBasePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);
struct BtlPokeParam *HAND_WAZA_FindBeatUpMember(struct BtlServerFlow *flow, u32 pokeId, u8 index);
int *HAND_WAZA_GetFakeOutHandlers(int *handlerCount);
void HAND_WAZA_FakeOutCheckFail(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetWeatherHealHandlers(int *handlerCount);


/* Baton Pass getter: one handler row. */
int *HAND_WAZA_GetBatonPassHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gBatonPassHandlers;
}


/* Baton Pass: arm the pass-on position effect, flag the user as passing, show the switch animation. */
void HAND_WAZA_BatonPassSwitchOut(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExSetPosEffect *posEffect;
    struct HandExSetContFlag *setContFlag;
    struct HandExMessageAnim *messageAnim;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID) && BTL_SERVER_FLOW_CheckClientHasBackupPoke(flow, pokeId) != 0 && BTL_SERVER_FLOW_TrySetOnceFlag(flow) != 0) {
        posEffect = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_SET_POS_EFFECT, pokeId);
        posEffect->effectKind = BTL_POS_EFFECT_BATON_PASS;
        posEffect->position = BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
        posEffect->param = pokeId;
        posEffect->mode = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, posEffect);
        setContFlag = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_SET_CONT_FLAG, pokeId);
        setContFlag->pokeId = pokeId;
        setContFlag->contFlag = BTL_CONT_FLAG_BATON_PASS;
        setContFlag->header |= HANDEX_FLAG_NO_WAIT;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, setContFlag);
        messageAnim = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_MESSAGE_ANIM, pokeId);
        messageAnim->pokeId = pokeId;
        messageAnim->animMode = 1;
        messageAnim->header |= HANDEX_FLAG_NO_WAIT;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageAnim);
    }
}


/* Teleport getter: three handler rows. */
int *HAND_WAZA_GetTeleportHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gTeleportHandlers;
}


/* Teleport: fails in a trainer battle or when the user is bound and trapped. */
void HAND_WAZA_TeleportCheckFail(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *pokeParam;

    if (BTL_SERVER_FLOW_GetCompetitor(flow) != 0 || BTL_SERVER_FLOW_GetRule(flow) != 0)
        BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_MOVE_FAILED);
    pokeParam = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    if (BTL_POKEPARAM_HasSick(pokeParam, BTL_SICK_BIND) != 0 && BTL_POKEPARAM_HasSick(pokeParam, BTL_SICK_TRAPPED) != 0)
        BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_MOVE_FAILED);
}


/* Teleport: keep the factor running and push the escape command. */
void HAND_WAZA_TeleportEscape(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        BTL_EVENT_KeepFactorRunning(factor);
        BTL_SERVER_FLOW_PushCmdRecord(flow, HAND_WAZA_KIND_ESCAPE, pokeId);
    }
}


/* Teleport: show the "but it failed" message. */
void HAND_WAZA_TeleportShowFailMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExMessageRecord *messageRecord;

    if (BTL_EVENT_OverwriteVar(BTL_EVAR_GENERIC_FLAG, 1) != 0) {
        messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, HANDEX_MESSAGE_SET, 0x2ff);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&messageRecord->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
    }
}


/* Fling getter: five handler rows. */
int *HAND_WAZA_GetFlingHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gFlingHandlers;
}


/* Fling: fails without a held item, without a Fling power, or in the listed battle situations. */
void HAND_WAZA_FlingCheckFail(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId != BTL_EVENT_GetVar(HANDVAR_POKE_ID))
        return;
    {
        struct BtlPokeParam *pokeParam = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        u16 heldItem = (u32)BTL_POKEPARAM_GetItem(pokeParam);
        if (heldItem == 0 || BTL_CALC_GetMonParamWithHeap(heldItem, ITEM_PARAM_FLING_POWER) == 0 || BTL_SERVER_FLOW_CanUseHeldItem(flow, pokeId) == 0
            || BTLV_CORE_CheckPartySlotPair(flow, pokeId) != 0)
            BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_MOVE_FAILED);
    }
}


/* Fling: the base power is the Fling power of the held item. */
void HAND_WAZA_FlingSetBasePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        u16 heldItem = (int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId));
        BTL_EVENT_OverwriteVar(BTL_EVAR_BASE_POWER, BTL_CALC_GetMonParamWithHeap(heldItem, ITEM_PARAM_FLING_POWER));
    }
}


/* Fling: message that the user flung its item. */
void HAND_WAZA_FlingShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *pokeParam;
    u16 heldItem;
    struct HandExMessageRecord *messageRecord;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        return;
    pokeParam = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    heldItem = (u32)BTL_POKEPARAM_GetItem(pokeParam);
    if (heldItem == 0)
        return;
    messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, HANDEX_MESSAGE_SET, 0x30b);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&messageRecord->message, pokeId);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&messageRecord->message, heldItem);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
}


/* Fling: remove the held item and, when the target is hit, use its effect on the target. */
void HAND_WAZA_FlingUseItemOnTarget(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    struct BtlPokeParam *pokeParam;
    u16 heldItem;
    struct HandExRemoveItem *removeItem;
    struct HandExUseItem *useItem;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        return;
    pokeParam = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    heldItem = (u32)BTL_POKEPARAM_GetItem(pokeParam);
    if (heldItem == 0)
        return;
    removeItem = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_REMOVE_ITEM, pokeId);
    removeItem->consumeKind = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, removeItem);
    *work = 1;
    if (BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE) == 0 && BTL_EVENT_GetVar(BTL_EVAR_MOVE_BLOCKED) == 0
        && BTL_CALC_GetMonParamWithHeap(heldItem, ITEM_PARAM_FLING_EFFECT) != 0) {
        useItem = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_USE_ITEM, pokeId);
        useItem->targetId = BTL_EVENT_GetVar(HANDVAR_DEFENDER_ID);
        useItem->itemId = heldItem;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, useItem);
    }
}


/* Fling: when the effect did not remove the item yet (work still 0), remove it after the move. */
void HAND_WAZA_FlingRemoveItemAfterMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    struct BtlPokeParam *pokeParam;
    struct HandExRemoveItem *removeItem;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_POKE_ID))
        return;
    if (*work != 0)
        return;
    pokeParam = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    if ((u16)(u32)BTL_POKEPARAM_GetItem(pokeParam) != 0) {
        removeItem = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_REMOVE_ITEM, pokeId);
        removeItem->consumeKind = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, removeItem);
    }
}


/* Magnet Rise getter: two handler rows. */
int *HAND_WAZA_GetMagnetRiseHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gMagnetRiseHandlers;
}


/* Magnet Rise: fails while the user is rooted or already floating. */
void HAND_WAZA_MagnetRiseCheckFail(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *pokeParam;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID)) {
        pokeParam = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_HasSick(pokeParam, BTL_SICK_INGRAIN) != 0 || BTL_POKEPARAM_HasSick(pokeParam, BTL_SICK_FLOATING_BLOCK) != 0)
            BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_MOVE_FAILED);
    }
}


/* Magnet Rise: float the user for five turns and announce it. */
void HAND_WAZA_MagnetRiseAddFloating(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExAddSickAnnounce *addSick;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        return;
    addSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
    addSick->pokeId = pokeId;
    addSick->sickKind = BTL_SICK_MAGNET_RISE;
    addSick->sickCont = BTLV_CORE_MakeSlotKind2Index(MAGNET_RISE_TURNS);
    BTL_SERVER_FLOW_InitMsgRecord(&addSick->message, HANDEX_MESSAGE_SET, 0x292);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&addSick->message, pokeId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, addSick);
}


/* Helping Hand getter: five handler rows. */
int *HAND_WAZA_GetHelpingHandHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gHelpingHandHandlers;
}


/* Helping Hand: set the generic result flag for the user (event 0x1c). */
void HAND_WAZA_HelpingHandSetGenericFlag(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_GENERIC_FLAG, 1);
}


/* Helping Hand: clear the protect bypass variable for the user (event 0x99). */
void HAND_WAZA_HelpingHandClearProtectBypass(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_PROTECT_BYPASS, 0);
}


/*
 * Helping Hand: needs a second Pokemon on the field; when the target ally is
 * still able and has not acted, announce the help, remember the ally in the
 * work slot and mark this factor dead. The factor is used last because the
 * factor and the work pointer both live on the stack here.
 */
void HAND_WAZA_HelpingHandAssistAlly(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    u8 targetId;
    struct BtlPokeParam *targetParam;
    struct HandExMessageRecord *messageRecord;

    if ((u32)BTL_SERVER_FLOW_GetActivePosPerSide(flow) <= 1)
        return;
    if (pokeId != BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        return;
    targetId = (u8)BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
    targetParam = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
    if (BTL_POKEPARAM_IsFainted(targetParam) != 0)
        return;
    if (BTL_POKEPARAM_TestTurnFlag(targetParam, BTL_TURN_FLAG_ACTED) != 0)
        return;
    messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, HANDEX_MESSAGE_SET, 0x414);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&messageRecord->message, pokeId);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&messageRecord->message, targetId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
    *work = targetId;
    BTL_EVENT_MarkFactorDead(factor);
}


/* Helping Hand: the helped Pokemon (kept in the work slot) hits 1.5 times harder. */
void HAND_WAZA_HelpingHandBoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    if (*work == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, 3 << 11);
}


/* Helping Hand: remove the factor at the end of the turn. */
void HAND_WAZA_HelpingHandRemoveAtTurnEnd(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID))
        BTL_EVENT_RemoveFactor(factor);
}


/* Beat Up getter: two handler rows. */
int *HAND_WAZA_GetBeatUpHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBeatUpHandlers;
}


/* Beat Up: one hit for each able party member (at least one), and restart the member cursor. */
void HAND_WAZA_BeatUpSetHitCount(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    int hitCount;
    u32 partyIndex;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        return;
    hitCount = 0;
    for (partyIndex = 0; partyIndex < BEAT_UP_PARTY_SLOTS; partyIndex++) {
        if (HAND_WAZA_FindBeatUpMember(flow, pokeId, partyIndex) != 0)
            hitCount++;
    }
    if (hitCount == 0)
        hitCount = 1;
    BTL_EVENT_OverwriteVar(BTL_EVAR_HIT_COUNT, hitCount);
    *work = 0;
}


/* Beat Up: the power of each hit comes from the base Attack of the next able member. */
void HAND_WAZA_BeatUpSetBasePower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work)
{
    struct BtlPokeParam *attackerParam;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        return;
    attackerParam = HAND_WAZA_FindBeatUpMember(flow, pokeId, *work);
    if (attackerParam == 0)
        attackerParam = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    *work = *work + 1;
    if (*work >= BEAT_UP_PARTY_SLOTS)
        *work = 0;
    BTL_EVENT_OverwriteVar(BTL_EVAR_BASE_POWER, _u32_div_f(func_021D59B4(attackerParam, BPP_VALUE_BASE_ATTACK), 10) + 5);
}


/* Beat Up: the index-th party member that takes part (the user itself, or an able member without a status). */
struct BtlPokeParam *HAND_WAZA_FindBeatUpMember(struct BtlServerFlow *flow, u32 pokeId, u8 index)
{
    struct BtlParty *party;
    u32 partySize;
    u32 partyIndex;
    struct BtlPokeParam *member;
    int takesPart;

    party = BTL_SERVER_FLOW_GetPartyOfPoke(flow, pokeId);
    partySize = BTL_SLOT_GetCount(party);
    if (index >= partySize)
        return 0;
    for (partyIndex = 0; partyIndex < partySize; partyIndex++) {
        takesPart = 0;
        member = BTL_SLOT_GetPokeParam(party, (u8)partyIndex);
        if (pokeId == BTL_POKEPARAM_GetPokeId(member))
            takesPart = 1;
        else if (BTL_POKEPARAM_IsAbleToBattle(member) != 0 && BTL_POKEPARAM_GetMajorStatusIndex(member) == 0)
            takesPart = 1;
        if (takesPart != 0) {
            if (index == 0)
                return member;
            index = index - 1;
        }
    }
    return 0;
}


/* Fake Out getter: one handler row. */
int *HAND_WAZA_GetFakeOutHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gFakeOutHandlers;
}


/* Fake Out: fails unless it is the first turn since the user came in. */
void HAND_WAZA_FakeOutCheckFail(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID)) {
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), 0) != 0)
            BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_MOVE_FAILED);
    }
}


/* Morning Sun, Synthesis and Moonlight getter: one handler row. */
int *HAND_WAZA_GetWeatherHealHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gWeatherHealHandlers;
}
