/*
 * file:     hand_waza_021e324c.c
 * unit:     yes
 * function: HAND_WAZA_TechnoBlastOnWazaTypeCheck, HAND_WAZA_HiddenPowerOnWazaTypeCheck, HAND_WAZA_HiddenPowerOnWazaPower, HAND_WAZA_AddNaturalGift, HAND_WAZA_NaturalGiftOnExecuteCheck, HAND_WAZA_NaturalGiftOnWazaTypeCheck, HAND_WAZA_NaturalGiftOnWazaPower, HAND_WAZA_NaturalGiftOnWazaFinish, HAND_WAZA_AddKnockOff
 * address:  0x021E324C
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
 *   gKnockOffHandlers     0x021F2844  data   ov093  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_CanUseHeldItem  0x021C824C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_SetCurTurnStateFlag  0x021C83DC  thumb  ov093
 *   gHiddenPowerHandlers  0x021F2A78  data   a4
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   POKE_TOOL_GetHiddenPowerType  0x02018790  thumb
 *   POKE_TOOL_GetHiddenPowerPower  0x02018820  thumb
 *   gNaturalGiftHandlers 0x021F2E18 data a4
 *   BTL_CALC_GetMonParamWithHeap  0x021D805C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "hand_waza_021e2988_types.h"

extern int BTL_EVENT_GetVar(int varId);
extern int BTL_SERVER_FLOW_CanUseHeldItem(struct BtlSvFlow *flow, int pokeId);
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlSvFlow *flow, int pokeId);
extern u16 BTL_POKEPARAM_GetItem(struct BtlPokeParam *poke);
extern int BTL_EVENT_OverwriteVar(int varId, u32 value);
extern void BTL_SERVER_FLOW_SetCurTurnStateFlag(struct BtlSvFlow *flow, int variant);
extern void *BTL_POKEPARAM_GetMon(struct BtlPokeParam *poke);
extern u32 POKE_TOOL_GetHiddenPowerType(void *mon);
extern u32 POKE_TOOL_GetHiddenPowerPower(void *mon);
extern u32 BTL_CALC_GetMonParamWithHeap(void *itemId, u32 paramId);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(struct BtlSvFlow *flow, int cmdKind, int pokeId);
extern void BTL_SERVER_FLOW_CommitCmdRecord(struct BtlSvFlow *flow, void *cmd);

void HAND_WAZA_TechnoBlastOnWazaTypeCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddHiddenPower(int *handlerCount);
void HAND_WAZA_HiddenPowerOnWazaTypeCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_HiddenPowerOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddNaturalGift(int *handlerCount);
void HAND_WAZA_NaturalGiftOnExecuteCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_NaturalGiftOnWazaTypeCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_NaturalGiftOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_NaturalGiftOnWazaFinish(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddKnockOff(int *handlerCount);

extern BtlEventHandler gHiddenPowerHandlers[];
extern BtlEventHandler gNaturalGiftHandlers[];
extern BtlEventHandler gKnockOffHandlers[];

/* Techno Blast: the type and the animation variant follow the drive that the user holds. */
void HAND_WAZA_TechnoBlastOnWazaTypeCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_SERVER_FLOW_CanUseHeldItem(flow, pokeId) != 0) {
            u16 itemId = (u16)(int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId));
            int type = POKETYPE_NORMAL;
            int variant = 0;
            switch (itemId) {
            case ITEM_DOUSE_DRIVE: type = POKETYPE_WATER; variant = 1; break;
            case ITEM_SHOCK_DRIVE: type = POKETYPE_ELECTRIC; variant = 2; break;
            case ITEM_BURN_DRIVE: type = POKETYPE_FIRE; variant = 3; break;
            case ITEM_CHILL_DRIVE: type = POKETYPE_ICE; variant = 4; break;
            }
            BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_TYPE, type);
            BTL_SERVER_FLOW_SetCurTurnStateFlag(flow, variant);
        }
    }
}

/* Hidden Power. */
BtlEventHandler *HAND_WAZA_AddHiddenPower(int *handlerCount)
{
    *handlerCount = 2;
    return gHiddenPowerHandlers;
}

/* Hidden Power: the type comes from the user's individual values. */
void HAND_WAZA_HiddenPowerOnWazaTypeCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_TYPE, POKE_TOOL_GetHiddenPowerType(BTL_POKEPARAM_GetMon(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId))));
}

/* Hidden Power: the power comes from the user's individual values. */
void HAND_WAZA_HiddenPowerOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, POKE_TOOL_GetHiddenPowerPower(BTL_POKEPARAM_GetMon(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId))));
}

/* Natural Gift. */
BtlEventHandler *HAND_WAZA_AddNaturalGift(int *handlerCount)
{
    *handlerCount = 4;
    return gNaturalGiftHandlers;
}

/* Natural Gift: it fails when the user cannot use its item or the item has no Natural Gift power. */
void HAND_WAZA_NaturalGiftOnExecuteCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    u16 itemId;
    int paramId;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_SERVER_FLOW_CanUseHeldItem(flow, pokeId) == 0) {
            BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_MOVE_FAILED);
            return;
        }
        itemId = (u16)(int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId));
        paramId = ITEM_PARAM_NATURAL_GIFT_POWER;
        BTL_CALC_GetMonParamWithHeap((void *)itemId, paramId);
        if (itemId == 0 || BTL_CALC_GetMonParamWithHeap((void *)itemId, paramId) == 0)
            BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_MOVE_FAILED);
    }
}

/* Natural Gift: the type comes from the item. */
void HAND_WAZA_NaturalGiftOnWazaTypeCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_TYPE, BTL_CALC_GetMonParamWithHeap((void *)((u16)(int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId))), ITEM_PARAM_NATURAL_GIFT_TYPE));
}

/* Natural Gift: the power comes from the item. */
void HAND_WAZA_NaturalGiftOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, BTL_CALC_GetMonParamWithHeap((void *)((u16)(int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId))), ITEM_PARAM_NATURAL_GIFT_POWER));
}

/* Natural Gift: the item is used up after the move. */
void HAND_WAZA_NaturalGiftOnWazaFinish(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    HandExItemMessage *consume;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        consume = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ITEM_MESSAGE, pokeId);
        consume->consumeItem = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, consume);
    }
}

/* Knock Off. */
BtlEventHandler *HAND_WAZA_AddKnockOff(int *handlerCount)
{
    *handlerCount = 1;
    return gKnockOffHandlers;
}
