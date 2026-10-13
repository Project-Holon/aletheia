/*
 * file:     hand_tokusei_021db650.c
 * unit:     yes
 * function: HAND_TOKUSEI_Klutz_SkipCheck, HAND_TOKUSEI_Klutz_InstallSkipCheck, HAND_TOKUSEI_Klutz_InstallSkipCheckOnEntry, HAND_TOKUSEI_Klutz_RemoveSkipCheck, HAND_TOKUSEI_Klutz_NoticeHeldItem, HAND_TOKUSEI_Klutz_BlockNaturalGift, HAND_TOKUSEI_Klutz_ShowBlockedMoveMessage, HAND_TOKUSEI_GetKlutzHandlers, HAND_TOKUSEI_StickyHold_BlockTrick, HAND_TOKUSEI_StickyHold_BlockItemRemoval, HAND_TOKUSEI_StickyHold_ShowMessage, HAND_TOKUSEI_GetStickyHoldHandlers, HAND_TOKUSEI_GetPressureHandlers, HAND_TOKUSEI_Pressure_ShowAbilityMessage, HAND_TOKUSEI_Pressure_AddPPCost
 * address:  0x021DB650
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
 *   func_0689C8DC  0x0689C8DC  thumb
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_EVENT_GetFactorPokeId  0x021D70AC  thumb  ov093
 *   gKlutzExemptItemIds     0x021F0B78  data   a2
 *   BTL_EVENT_SetFactorSkipCheck 0x021D7320 thumb ov093
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_ClearFactorSkipCheck   0x021D7324  thumb
 *   BTL_POKEPARAM_GetItem 0x021D5B40 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   gKlutzHandlers     0x021F0D9C  data   ov093  a4
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   WAZA_TOOL_GetCategory   0x0201C1BC  thumb
 *   gStickyHoldHandlers     0x021F0AA0  data   ov093  a4
 *   gPressureHandlers     0x021F0AB8  data   ov093  a4
 */
#include "hand_tokusei_021db0e4_types.h"

/* Ability handlers: Klutz, Sticky Hold, Pressure. */

#define KLUTZ_EXEMPT_ITEM_COUNT 13
#define MOVE_NATURAL_GIFT 0x16B
#define MOVE_TRICK 0x10F
#define MOVE_SWITCHEROO 0x19F
#define BTL_FAIL_REASON_ITEM_UNUSABLE 0x13

/* The work area of a Klutz factor. */
typedef struct KlutzWork {
    int skipCheckSet;
    int pad04;
    int moveBlocked;
} KlutzWork;

extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *bpp, int sickId);
extern u16 BTL_POKEPARAM_GetItem(struct BtlPokeParam *bpp);
extern u32 WAZA_TOOL_GetCategory(u16 moveId);
extern int func_0689C8DC(int moveId);

int HAND_TOKUSEI_Klutz_SkipCheck(struct BtlEventFactor *other, struct BtlSvFlow *flow, int factorType, int eventId, unsigned short key, u8 ownerId);
void HAND_TOKUSEI_Klutz_InstallSkipCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, KlutzWork *work);
void HAND_TOKUSEI_Klutz_InstallSkipCheckOnEntry(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, KlutzWork *work);
void HAND_TOKUSEI_Klutz_RemoveSkipCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_TOKUSEI_Klutz_NoticeHeldItem(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_TOKUSEI_Klutz_BlockNaturalGift(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, KlutzWork *work);
void HAND_TOKUSEI_Klutz_ShowBlockedMoveMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, KlutzWork *work);
const BtlEventHandler *HAND_TOKUSEI_GetKlutzHandlers(int *handlerCount);
void HAND_TOKUSEI_StickyHold_BlockTrick(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_TOKUSEI_StickyHold_BlockItemRemoval(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *messagePending);
void HAND_TOKUSEI_StickyHold_ShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *messagePending);
const BtlEventHandler *HAND_TOKUSEI_GetStickyHoldHandlers(int *handlerCount);
const BtlEventHandler *HAND_TOKUSEI_GetPressureHandlers(int *handlerCount);
void HAND_TOKUSEI_Pressure_ShowAbilityMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_TOKUSEI_Pressure_AddPPCost(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
extern const u16 gKlutzExemptItemIds[];
extern const BtlEventHandler gKlutzHandlers[];
extern const BtlEventHandler gStickyHoldHandlers[];
extern const BtlEventHandler gPressureHandlers[];


/* Klutz skip check: item factors of the holder are skipped, except the items in the exempt list. */
int HAND_TOKUSEI_Klutz_SkipCheck(struct BtlEventFactor *other, struct BtlSvFlow *flow, int factorType, int eventId, unsigned short key, u8 ownerId)
{
    u32 i;

    if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, ownerId), 0x10) != 0)
        return 0;
    if (factorType == 5 && ownerId == BTL_EVENT_GetFactorPokeId(other)) {
        for (i = 0; i < KLUTZ_EXEMPT_ITEM_COUNT; i++) {
            if (key == gKlutzExemptItemIds[i])
                return 0;
        }
        return 1;
    }
    return 0;
}


void HAND_TOKUSEI_Klutz_InstallSkipCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, KlutzWork *work)
{
    if (work->skipCheckSet == 0) {
        BTL_EVENT_SetFactorSkipCheck(factor, (u32)HAND_TOKUSEI_Klutz_SkipCheck);
        work->skipCheckSet = 1;
    }
}


void HAND_TOKUSEI_Klutz_InstallSkipCheckOnEntry(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, KlutzWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        HAND_TOKUSEI_Klutz_InstallSkipCheck(factor, flow, pokeId, work);
}


void HAND_TOKUSEI_Klutz_RemoveSkipCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_ClearFactorSkipCheck(factor);
}


/* Klutz: tell the server flow that the held item of the holder changed its effect. */
void HAND_TOKUSEI_Klutz_NoticeHeldItem(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExPokeNotice *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId))) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_POKE_NOTICE, pokeId);
        cmd->pokeId = pokeId;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}


/* Klutz: Natural Gift fails when the holder uses it. */
void HAND_TOKUSEI_Klutz_BlockNaturalGift(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, KlutzWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        unsigned short moveId = (unsigned short)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
        work->moveBlocked = 0;
        if (moveId == MOVE_NATURAL_GIFT && pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
            work->moveBlocked = BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_ITEM_UNUSABLE);
    }
}


/* Klutz: show the message for the blocked move. */
void HAND_TOKUSEI_Klutz_ShowBlockedMoveMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, KlutzWork *work)
{
    HandExMessage *msg;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && work->moveBlocked != 0) {
        BTL_EVENT_GetVar(BTL_EVAR_POKE_ID);
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_MESSAGE, pokeId);
        msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
        BTL_SERVER_FLOW_InitMsgRecord(&msg->str, 2, 0x389);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->str, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->str, BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID));
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
        work->moveBlocked = 0;
    }
}


const BtlEventHandler *HAND_TOKUSEI_GetKlutzHandlers(int *handlerCount)
{
    *handlerCount = 7;
    return gKlutzHandlers;
}


/* Sticky Hold: Trick and Switcheroo against the holder have no effect. */
void HAND_TOKUSEI_StickyHold_BlockTrick(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u16 moveId;
    HandExMessage *msg;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
        if (moveId == MOVE_TRICK || moveId == MOVE_SWITCHEROO) {
            if (BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 1) != 0) {
                msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_MESSAGE, pokeId);
                msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
                BTL_SERVER_FLOW_InitMsgRecord(&msg->str, 2, 0xd2);
                BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->str, pokeId);
                BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
            }
        }
    }
}


/* Sticky Hold: block the removal of the item of the holder when another poke causes it. */
void HAND_TOKUSEI_StickyHold_BlockItemRemoval(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *messagePending)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_EVENT_GetVar(BTL_EVAR_SELF_CAUSED_FLAG) == 0)
        *messagePending = BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}


void HAND_TOKUSEI_StickyHold_ShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *messagePending)
{
    HandExMessage *msg;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && *messagePending != 0) {
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_MESSAGE, pokeId);
        msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
        BTL_SERVER_FLOW_InitMsgRecord(&msg->str, 2, 0x1ed);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->str, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
        *messagePending = 0;
    }
}


const BtlEventHandler *HAND_TOKUSEI_GetStickyHoldHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gStickyHoldHandlers;
}


const BtlEventHandler *HAND_TOKUSEI_GetPressureHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gPressureHandlers;
}


/* Pressure: when the poke enters, show the ability window and the message. */
void HAND_TOKUSEI_Pressure_ShowAbilityMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExMessage *msg;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_TOKWIN_IN, pokeId);
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->str, 2, 0x1e7);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->str, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
        BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_TOKWIN_OUT, pokeId);
    }
}


static inline void overwriteVarU8(int key, u8 value)
{
    BTL_EVENT_OverwriteVar(key, value);
}


/* Pressure: a move of an opposing poke costs one more PP. */
void HAND_TOKUSEI_Pressure_AddPPCost(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    int extraCost;
    u16 moveId;

    if (BTL_MAIN_IsPokeSamePair((u8)BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID), pokeId) == 0) {
        extraCost = 0;
        if (func_021E85F8(pokeId) != 0) {
            extraCost = 1;
        } else {
            moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
            if (WAZA_TOOL_GetCategory(moveId) == 10)
                extraCost = 1;
            else if (func_0689C8DC(moveId) != 0)
                extraCost = 1;
        }
        if (extraCost != 0)
            overwriteVarU8(BTL_EVAR_VOLUME, BTL_EVENT_GetVar(BTL_EVAR_VOLUME) + 1);
    }
}
