/*
 * file:     unit_021DEDF8.c
 * unit:     yes
 * function: BTL_HANDLER_ITEM_LightClay_ExtendScreen, BTL_HANDLER_ITEM_GetPowerHerbHandlers, BTL_HANDLER_ITEM_PowerHerb_CheckSkipCharge, BTL_HANDLER_ITEM_PowerHerb_UseItem, BTL_HANDLER_ITEM_PowerHerb_ShowMessage, BTL_HANDLER_ITEM_GetLeftoversHandlers, BTL_HANDLER_ITEM_Leftovers_TriggerOnTurnEnd, BTL_HANDLER_ITEM_Leftovers_Heal, BTL_HANDLER_ITEM_GetBlackSludgeHandlers
 * address:  0x021DEDF8
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
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_HANDLER_ITEM_GetParam  0x021DCFF8  thumb  ov093
 *   BTLV_CORE_AddSlotIndex  0x021E8C50  thumb  ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   BTL_HANDLER_ITEM_PushUseItem  0x021DD044  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   d_021F197C     0x021F197C  data   ov093  a4
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_IsHpFull  0x021D5B48  thumb  ov093
 *   BTL_EVENT_KeepFactorRunning  0x021D70C8  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   d_021F16EC     0x021F16EC  data   ov093  a4
 *   d_021F14B4     0x021F14B4  data   ov093  a4
 */
#include "unit_021DE7E4_types.h"

struct BtlEventFactor;

#define BTL_MOVE_SKY_DROP 507 /* (guess) the two-turn move that Power Herb cannot skip */

extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 value);
extern int BTL_HANDLER_ITEM_GetParam(struct BtlEventFactor *factor, int index);
extern void BTLV_CORE_AddSlotIndex(u32 *sickCont, u32 turns);
extern void BTL_EVENT_MultiplyVar(int key, int multiplier);
extern void BTL_HANDLER_ITEM_PushUseItem(struct BtlEventFactor *factor, void *flow, int pokeId);
extern void *func_021C88A4(void *flow, int cmdKind, int pokeId);
extern void func_021C88C8(void *flow, void *cmd);
extern void func_021C8838(HandExStr *str, int strType, int strId);
extern void func_021C8860(HandExStr *str, u32 arg);
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern void *func_021C7CF4(void *flow, int pokeId);
extern int BTL_POKEPARAM_IsHpFull(void *pokeParam);
extern void BTL_EVENT_KeepFactorRunning(struct BtlEventFactor *factor);
extern int BTL_CALC_DivideMaxHpMin1(void *pokeParam, u32 divisor);
extern int d_021F197C[];
extern int d_021F16EC[];
extern int d_021F14B4[];

/* Light Clay: a screen set up by the holder lasts the item's parameter in extra turns. */
void BTL_HANDLER_ITEM_LightClay_ExtendScreen(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    int sickCont;
    u8 extraTurns;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && (u32)BTL_EVENT_GetVar(BTL_EVAR_SCREEN_KIND) <= 1) {
        sickCont = BTL_EVENT_GetVar(BTL_EVAR_SICK_CONT);
        extraTurns = BTL_HANDLER_ITEM_GetParam(factor, 2);
        BTLV_CORE_AddSlotIndex((u32 *)&sickCont, extraTurns);
        BTL_EVENT_OverwriteVar(BTL_EVAR_SICK_CONT, sickCont);
    }
}

int *BTL_HANDLER_ITEM_GetPowerHerbHandlers(int *count)
{
    *count = 3;
    return d_021F197C;
}

/* Power Herb: a two-turn move (except Sky Drop) skips its charge turn. */
void BTL_HANDLER_ITEM_PowerHerb_CheckSkipCharge(struct BtlEventFactor *factor, void *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID) != BTL_MOVE_SKY_DROP) {
            if (BTL_EVENT_OverwriteVar(BTL_EVAR_SKIP_CHARGE_FLAG, 1))
                *work = 1;
        }
    }
}

/* Power Herb: use up the item when the charge turn was skipped. */
void BTL_HANDLER_ITEM_PowerHerb_UseItem(struct BtlEventFactor *factor, void *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && *work != 0)
        BTL_HANDLER_ITEM_PushUseItem(factor, flow, pokeId);
}

/* Power Herb: show the message that the holder became fully charged. */
void BTL_HANDLER_ITEM_PowerHerb_ShowMessage(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    HandExMessage *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        cmd = (HandExMessage *)func_021C88A4(flow, HANDEX_KIND_MESSAGE, pokeId);
        func_021C8838(&cmd->str, HANDEX_STR_SET, 0x3fe);
        func_021C8860(&cmd->str, pokeId);
        func_021C8860(&cmd->str, BTL_EVENT_GetFactorKey(factor));
        func_021C88C8(flow, cmd);
    }
}

int *BTL_HANDLER_ITEM_GetLeftoversHandlers(int *count)
{
    *count = 2;
    return d_021F16EC;
}

/* Leftovers: at the end of the turn, if the holder is hurt, start the item effect. */
void BTL_HANDLER_ITEM_Leftovers_TriggerOnTurnEnd(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    HandExItemUse *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_POKEPARAM_IsHpFull(func_021C7CF4(flow, pokeId)) == 0) {
            cmd = (HandExItemUse *)func_021C88A4(flow, 0, pokeId);
            cmd->flags = (cmd->flags & ~1) | 1;
            BTL_EVENT_KeepFactorRunning(factor);
            func_021C88C8(flow, cmd);
        }
    }
}

/* Leftovers: recover a sixteenth of the maximum HP. */
void BTL_HANDLER_ITEM_Leftovers_Heal(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    void *holder;
    HandExRecoverHp *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        holder = func_021C7CF4(flow, pokeId);
        if (BTL_POKEPARAM_IsHpFull(holder) == 0) {
            cmd = (HandExRecoverHp *)func_021C88A4(flow, HANDEX_KIND_RECOVER_HP, pokeId);
            cmd->pokeId = pokeId;
            cmd->amount = BTL_CALC_DivideMaxHpMin1(holder, 16);
            func_021C8838(&cmd->str, HANDEX_STR_SET, 0x392);
            func_021C8860(&cmd->str, pokeId);
            func_021C8860(&cmd->str, BTL_EVENT_GetFactorKey(factor));
            func_021C88C8(flow, cmd);
        }
    }
}

int *BTL_HANDLER_ITEM_GetBlackSludgeHandlers(int *count)
{
    *count = 1;
    return d_021F14B4;
}
