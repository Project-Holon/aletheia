/*
 * file:     unit_021DE980.c
 * unit:     yes
 * function: BTL_HANDLER_ITEM_ChoiceSpecs_BoostSpAttack, BTL_HANDLER_ITEM_ChoiceScarf_BoostSpeed, BTL_HANDLER_ITEM_Choice_LockMove, BTL_HANDLER_ITEM_Choice_ReleaseMoveLock, BTL_HANDLER_ITEM_FocusSash_CheckSurvive, BTL_HANDLER_ITEM_FocusSash_ConsumeAndAnnounce, BTL_HANDLER_ITEM_GetFocusBandHandlers, BTL_HANDLER_ITEM_FocusBand_CheckSurvive, BTL_HANDLER_ITEM_FocusBand_UseItem, BTL_HANDLER_ITEM_FocusBand_ShowMessage, BTL_HANDLER_ITEM_GetExpertBeltHandlers
 * address:  0x021DE980
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
 *   d_021F150C     0x021F150C  data   ov093  a4
 *   d_021F1904 0x021F1904 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   WAZA_TOOL_GetDamageType 0x0201C1E8 thumb
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1Value  0x021E89D4  thumb  ov093
 *   d_021F16BC 0x021F16BC data a4
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_IsHpFull 0x021D5B48 thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   d_021F191C 0x021F191C data a4
 *   BTL_HANDLER_ITEM_GetParam 0x021DCFF8 thumb ov093
 *   BTL_HANDLER_ITEM_RollChance 0x021DCFD0 thumb ov093
 *   BTL_HANDLER_ITEM_PushUseItem 0x021DD044 thumb ov093
 */
#include "unit_021DE7E4_types.h"

struct BtlEventFactor;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 value);
extern void BTL_EVENT_MultiplyVar(int key, int multiplier);
extern int WAZA_TOOL_GetDamageType(int moveId);
extern void *func_021C88A4(void *flow, int cmdKind, int pokeId);
extern void func_021C88C8(void *flow, void *cmd);
extern int BTLV_CORE_MakeSlotKind1Value(u32 moveId);
extern void *func_021C7CF4(void *flow, int pokeId);
extern int BTL_POKEPARAM_IsHpFull(void *pokeParam);
extern void func_021C8838(HandExStr *str, int strType, int strId);
extern void func_021C8860(HandExStr *str, u32 arg);
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern int BTL_HANDLER_ITEM_GetParam(struct BtlEventFactor *factor, int index);
extern int BTL_HANDLER_ITEM_RollChance(void *flow, u32 chance);
extern void BTL_HANDLER_ITEM_PushUseItem(struct BtlEventFactor *factor, void *flow, int pokeId);
extern int d_021F1904;
extern int d_021F16BC;
extern int d_021F191C;
extern int d_021F150C[];

/* Choice Specs: 1.5 times power for special moves. */
void BTL_HANDLER_ITEM_ChoiceSpecs_BoostSpAttack(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == 2)
            BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, 6144);
    }
}

int *BTL_HANDLER_ITEM_GetChoiceScarfHandlers(int *count)
{
    *count = 3;
    return &d_021F1904;
}

/* Choice Scarf: 1.5 times speed. */
void BTL_HANDLER_ITEM_ChoiceScarf_BoostSpeed(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, 6144);
}

/* Choice items: lock the holder into the move it just used (anything but Struggle, 0xa5). */
void BTL_HANDLER_ITEM_Choice_LockMove(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    u16 moveId;
    HandExAddSickFull *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
        if (moveId != 0xa5) {
            cmd = (HandExAddSickFull *)func_021C88A4(flow, HANDEX_KIND_ADD_SICK, pokeId);
            cmd->pokeId = pokeId;
            cmd->sickKind = BTL_SICK_MOVE_LOCK;
            cmd->sickCont = BTLV_CORE_MakeSlotKind1Value(moveId);
            cmd->mode = 2;
            func_021C88C8(flow, cmd);
        }
    }
}

/* Choice items: release the move lock when the holder leaves the field. */
void BTL_HANDLER_ITEM_Choice_ReleaseMoveLock(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    HandExCureSickSlot *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        cmd = (HandExCureSickSlot *)func_021C88A4(flow, 11, pokeId);
        cmd->sickIndex = BTL_SICK_MOVE_LOCK;
        cmd->pokeId = pokeId;
        cmd->flagA = 1;
        cmd->flagB = 1;
        func_021C88C8(flow, cmd);
    }
}

int *BTL_HANDLER_ITEM_GetFocusSashHandlers(int *count)
{
    *count = 2;
    return &d_021F16BC;
}

/* Focus Sash: a hit at full HP leaves the holder at 1 HP. */
void BTL_HANDLER_ITEM_FocusSash_CheckSurvive(struct BtlEventFactor *factor, void *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        if (BTL_POKEPARAM_IsHpFull(func_021C7CF4(flow, pokeId)))
            *work = BTL_EVENT_OverwriteVar(BTL_EVAR_SURVIVE_RESULT, 3);
        else
            *work = 0;
    }
}

/* Focus Sash: consume the item and show its message after it saved the holder. */
void BTL_HANDLER_ITEM_FocusSash_ConsumeAndAnnounce(struct BtlEventFactor *factor, void *flow, int pokeId, int *work)
{
    HandExConsumeItem *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && *work != 0) {
        cmd = (HandExConsumeItem *)func_021C88A4(flow, 0x23, pokeId);
        func_021C8838(&cmd->str, HANDEX_STR_SET, 0x3ef);
        func_021C8860(&cmd->str, pokeId);
        func_021C8860(&cmd->str, BTL_EVENT_GetFactorKey(factor));
        func_021C88C8(flow, cmd);
        *work = 0;
    }
}

int *BTL_HANDLER_ITEM_GetFocusBandHandlers(int *count)
{
    *count = 3;
    return &d_021F191C;
}

/* Focus Band: a random chance (item parameter) to survive a hit with 1 HP. */
void BTL_HANDLER_ITEM_FocusBand_CheckSurvive(struct BtlEventFactor *factor, void *flow, int pokeId, int *work)
{
    int chance;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        chance = (unsigned char)BTL_HANDLER_ITEM_GetParam(factor, 2);
        if (BTL_HANDLER_ITEM_RollChance(flow, chance))
            *work = BTL_EVENT_OverwriteVar(BTL_EVAR_SURVIVE_RESULT, 3);
        else
            *work = 0;
    }
}

/* Focus Band: use the item when it saved the holder. */
void BTL_HANDLER_ITEM_FocusBand_UseItem(struct BtlEventFactor *factor, void *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (*work) {
            BTL_HANDLER_ITEM_PushUseItem(factor, flow, pokeId);
            *work = 0;
        }
    }
}

/* Focus Band: show the message that the holder hung on. */
void BTL_HANDLER_ITEM_FocusBand_ShowMessage(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    HandExMessage *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        cmd = (HandExMessage *)func_021C88A4(flow, HANDEX_KIND_MESSAGE, pokeId);
        func_021C8838(&cmd->str, HANDEX_STR_SET, 0x3ef);
        func_021C8860(&cmd->str, pokeId);
        func_021C8860(&cmd->str, BTL_EVENT_GetFactorKey(factor));
        func_021C88C8(flow, cmd);
    }
}

int *BTL_HANDLER_ITEM_GetExpertBeltHandlers(int *count)
{
    *count = 1;
    return d_021F150C;
}
