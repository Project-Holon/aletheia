/*
 * file:     unit_021DA624.c
 * unit:     yes
 * function: func_021DA624, func_021DA6EC, func_021DA748, func_021DA780, func_021DA7DC, func_021DA808, func_021DA820, func_021DA838, func_021DA844, func_021DA868, func_021DA89C, func_021DA8A8, func_021DA8DC, func_021DA96C, func_021DA9E0, func_021DAA70, func_021DAA94, func_021DAAC0, func_021DAAEC, func_021DAB24, func_021DAB48, func_021DAB78, func_021DABE8, func_021DABF4, func_021DAC1C, func_021DAC6C, func_021DAC90, func_021DAD20, func_021DAD2C, func_021DAD58, func_021DAD84, func_021DADD8, func_021DAE04, func_021DAE38, func_021DAE94, func_021DAEA4, func_021DAEAC, func_021DAEC4, func_021DAED8, func_021DAEE4, func_021DAF1C, func_021DAF58, func_021DB000, func_021DB00C, func_021DB0D0, func_021DB0DC
 * address:  0x021DA624
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
 *   func_021D7320  0x021D7320  thumb  ov093
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7D54 0x021C7D54 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021C88B4 0x021C88B4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F09B0 0x021F09B0 data a4
 *   d_021F0B00 0x021F0B00 data a4
 *   func_021D76BC   0x021D76BC  thumb ov093
 *   func_021D5B48 0x021D5B48 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021D7B08   0x021D7B08  thumb ov093
 *   d_021F0B18     0x021F0B18  data   ov093  a4
 *   func_021D7B74   0x021D7B74  thumb ov093
 *   func_021D5D14  0x021D5D14  thumb  ov093
 *   d_021F0B30 0x021F0B30 data a4
 *   d_021F0730 0x021F0730 data a4
 *   d_021F0798 0x021F0798 data a4
 *   d_021F0790 0x021F0790 data a4
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   d_021F09D0     0x021F09D0  data   ov093  a4
 *   d_021F0A10 0x021F0A10 data a4
 *   WAZA_TOOL_IsDamaging   0x0201C314  thumb
 *   d_021F0788     0x021F0788  data   ov093  a4
 *   func_021D5BB0 0x021D5BB0 thumb ov093
 *   d_021F0B94 0x021F0B94 data a4
 *   d_021F0660     0x021F0660  data   ov093  a4
 *   func_021D7324  0x021D7324  thumb  ov093
 *   func_021E8878  0x021E8878  thumb  ov093
 *   func_021D5BDC 0x021D5BDC thumb ov093
 *   d_021F0BD4     0x021F0BD4  data   ov093  a4
 *   func_021C7D00 0x021C7D00 thumb ov093
 *   func_021C7F68 0x021C7F68 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   d_021F07E8 0x021F07E8 data a4
 *   d_021F0A28     0x021F0A28  data   ov093  a4
 */
#include "unit_021DA624_types.h"

void func_021DA624(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *func_021DA6D4(int *handlerCount);
BtlEventHandler *func_021DA6E0(int *handlerCount);
void func_021DA6EC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DA748(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void func_021DA780(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void func_021DA7DC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DA808(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DA820(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *func_021DA838(int *handlerCount);
void func_021DA844(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DA868(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *func_021DA89C(int *handlerCount);
int func_021DA8A8(struct BtlSvFlow *flow, int pokeId, int moveType);
void func_021DA8DC(struct BtlSvFlow *flow, int pokeId, int divisor);
void func_021DA96C(struct BtlSvFlow *flow, int pokeId, u32 statId, int amount);
void func_021DA9E0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DAA70(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DAA94(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *func_021DAAB4(int *handlerCount);
void func_021DAAC0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *func_021DAAE0(int *handlerCount);
void func_021DAAEC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *func_021DAB0C(int *handlerCount);
BtlEventHandler *func_021DAB18(int *handlerCount);
void func_021DAB24(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DAB48(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *func_021DAB6C(int *handlerCount);
void func_021DAB78(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *func_021DABE8(int *handlerCount);
void func_021DABF4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void func_021DAC1C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void func_021DAC6C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *func_021DAC84(int *handlerCount);
void func_021DAC90(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *func_021DAD20(int *handlerCount);
void func_021DAD2C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void func_021DAD58(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void func_021DAD84(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void func_021DADD8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *func_021DADF8(int *handlerCount);
void func_021DAE04(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void func_021DAE38(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void func_021DAE94(struct BtlEventFactor *factor);
void func_021DAEA4(struct BtlEventFactor *factor);
void func_021DAEAC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int func_021DAEC4(struct BtlEventFactor *other, void *context, int factorType, int eventId, u16 key, u8 ownerId);
BtlEventHandler *func_021DAED8(int *handlerCount);
void func_021DAEE4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DAF1C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DAF58(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *func_021DB000(int *handlerCount);
void func_021DB00C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *func_021DB0D0(int *handlerCount);
void func_021DB0DC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int unusedArg);
extern void func_021E8878(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int unusedArg);

/* Handler tables: pairs of an event id and the function that answers it. */
extern BtlEventHandler d_021F09B0[], d_021F0B00[];
extern BtlEventHandler d_021F0B18[];
extern BtlEventHandler d_021F0B30[];
extern BtlEventHandler d_021F0730[];
extern BtlEventHandler d_021F0798[];
extern BtlEventHandler d_021F0790[];
extern BtlEventHandler d_021F09D0[];
extern BtlEventHandler d_021F0A10[];
extern BtlEventHandler d_021F0788[];
extern BtlEventHandler d_021F0B94[];
extern BtlEventHandler d_021F0660[];
extern BtlEventHandler d_021F0BD4[];
extern BtlEventHandler d_021F0A28[];
extern BtlEventHandler d_021F07E8[];

/* Frisk: on entry, shows the held item of one opposing Pokemon chosen at random. */
void func_021DA624(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u16 itemIds[4];
    u8 targetIds[4];
    u8 targetCount;
    u8 itemCount;
    u8 i;
    u8 choice;
    BtlMessageCmd *cmd;
    struct BtlPokeParam *target;
    if (pokeId != func_021D775C(BTL_EVAR_POKE_ID)) return;
    targetCount = func_021C7D54(flow, pokeId, targetIds);
    itemCount = 0;
    for (i = 0; i < targetCount; i++) {
        target = func_021C7CF4(flow, targetIds[i]);
        itemIds[itemCount] = func_021D5B40(target);
        if (itemIds[itemCount] != 0) itemCount++;
    }
    if (itemCount == 0) return;
    choice = func_021D78AC(itemCount);
    func_021C88B4(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
    cmd = func_021C88A4(flow, BTL_CMD_MESSAGE, pokeId);
    func_021C8838(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_FRISK_ITEM);
    func_021C8860(&cmd->strParam, pokeId);
    func_021C8860(&cmd->strParam, itemIds[choice]);
    func_021C88C8(flow, cmd);
    func_021C88B4(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
}

BtlEventHandler *func_021DA6D4(int *handlerCount) { *handlerCount = 2; return d_021F09B0; }

BtlEventHandler *func_021DA6E0(int *handlerCount) { *handlerCount = 3; return d_021F0B00; }

/* Sturdy: a one-hit knockout move against the owner has no effect. */
void func_021DA6EC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlMessageCmd *cmd;

    if (pokeId != func_021D775C(BTL_EVAR_DEFENDER_ID))
        return;
    if (func_021D76BC(BTL_EVAR_PREVENT_FLAG, 1) == 0)
        return;
    func_021C88B4(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
    cmd = func_021C88A4(flow, BTL_CMD_MESSAGE, pokeId);
    func_021C8838(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
    func_021C8860(&cmd->strParam, pokeId);
    func_021C88C8(flow, cmd);
    func_021C88B4(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
}

/* Sturdy: at full HP the owner survives a knockout blow; work[0] tells the message handler. */
void func_021DA748(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID)) {
        if (func_021D5B48(func_021C7CF4(flow, pokeId)) != 0) {
            *work = func_021D76BC(BTL_EVAR_ENDURE_REASON, BTL_ENDURE_REASON_STURDY);
            return;
        }
        *work = 0;
    }
}

/* Sturdy: shows the message after the owner has endured a blow. */
void func_021DA780(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    BtlMessageCmd *cmd;

    if (pokeId != func_021D775C(BTL_EVAR_POKE_ID))
        return;
    if (*work == 0)
        return;
    func_021C88B4(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
    cmd = func_021C88A4(flow, BTL_CMD_MESSAGE, pokeId);
    func_021C8838(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_STURDY_ENDURE);
    func_021C8860(&cmd->strParam, pokeId);
    func_021C88C8(flow, cmd);
    func_021C88B4(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
    *work = 0;
}

/* Unaware: the attacker ignores the defender's defense boosts, the defender ignores the attacker's attack boosts. */
void func_021DA7DC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID)) {
        func_021D76BC(BTL_EVAR_DEFENSE_STAGE, BTL_STAT_STAGE_NEUTRAL);
        return;
    }
    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID))
        func_021D76BC(BTL_EVAR_ATTACK_STAGE, BTL_STAT_STAGE_NEUTRAL);
}

/* Unaware: when the owner defends, sets the generic flag (ignores the attacker's accuracy boosts). */
void func_021DA808(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID))
        func_021D76BC(BTL_EVAR_GENERIC_FLAG, 1);
}

/* Unaware: when the owner attacks, sets the generic flag (ignores the defender's evasion boosts). */
void func_021DA820(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID))
        func_021D76BC(BTL_EVAR_GENERIC_FLAG, 1);
}

BtlEventHandler *func_021DA838(int *handlerCount)
{
    *handlerCount = 3;
    return d_021F0B18;
}

/* Heatproof: fire moves against the owner lose half their power. */
void func_021DA844(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID) && func_021D775C(BTL_EVAR_MOVE_TYPE) == POKETYPE_FIRE)
        func_021D7704(BTL_EVAR_POWER_RATIO, BTL_RATIO_0_5);
}

/* Heatproof: burn damage to the owner is halved (at least 1). */
void func_021DA868(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    int damage;

    if (pokeId != func_021D775C(BTL_EVAR_POKE_ID))
        return;
    if (func_021D775C(BTL_EVAR_SICK_ID) != BTL_SICK_BURN)
        return;
    damage = func_021D775C(BTL_EVAR_DAMAGE);
    func_021D76BC(BTL_EVAR_DAMAGE, func_021D7B08(damage / 2, 1));
}

BtlEventHandler *func_021DA89C(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F09D0;
}

/* Absorb abilities: nonzero when a move of moveType from another Pokemon hits the owner and is nullified. */
int func_021DA8A8(struct BtlSvFlow *flow, int pokeId, int moveType)
{
    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID) && pokeId != func_021D775C(BTL_EVAR_ATTACKER_ID) && moveType == func_021D775C(BTL_EVAR_MOVE_TYPE))
        return func_021D76BC(BTL_EVAR_NO_EFFECT_FLAG, 1);
    return 0;
}

/* Absorb abilities: restore 1/divisor of the owner's HP, or show "no effect" at full HP. */
void func_021DA8DC(struct BtlSvFlow *flow, int pokeId, int divisor)
{
    struct BtlPokeParam *owner;
    BtlRecoverHpCmd *recoverCmd;
    BtlMessageCmd *messageCmd;

    owner = func_021C7CF4(flow, pokeId);
    if (func_021D5B48(owner) == 0) {
        recoverCmd = func_021C88A4(flow, BTL_CMD_RECOVER_HP, pokeId);
        recoverCmd->pokeId = pokeId;
        recoverCmd->amount = func_021D7B74(owner, divisor);
        recoverCmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        func_021C8838(&recoverCmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABSORB_RECOVER_HP);
        func_021C8860(&recoverCmd->strParam, pokeId);
        func_021C88C8(flow, recoverCmd);
    } else {
        messageCmd = func_021C88A4(flow, BTL_CMD_MESSAGE, pokeId);
        func_021C8838(&messageCmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
        func_021C8860(&messageCmd->strParam, pokeId);
        messageCmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        func_021C88C8(flow, messageCmd);
    }
    func_021D76BC(BTL_EVAR_GENERIC_FLAG, 1);
}

/* Absorb abilities: raise a stat of the owner, or show "no effect" when it cannot rise. */
void func_021DA96C(struct BtlSvFlow *flow, int pokeId, u32 statId, int amount)
{
    BtlRankCmd *rankCmd;
    BtlMessageCmd *messageCmd;

    if (func_021D5D14(func_021C7CF4(flow, pokeId), statId, amount) != 0) {
        rankCmd = func_021C88A4(flow, BTL_CMD_RANK, pokeId);
        rankCmd->targetCount = 1;
        rankCmd->targets[0] = pokeId;
        rankCmd->showMessage = 1;
        rankCmd->statId = statId;
        rankCmd->amount = amount;
        rankCmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        func_021C88C8(flow, rankCmd);
    } else {
        messageCmd = func_021C88A4(flow, BTL_CMD_MESSAGE, pokeId);
        func_021C8838(&messageCmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
        func_021C8860(&messageCmd->strParam, pokeId);
        messageCmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        func_021C88C8(flow, messageCmd);
    }
}

/* Dry Skin: sun hurts the owner by 1/8, rain restores 1/8. */
void func_021DA9E0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlDamageCmd *damageCmd;
    BtlRecoverHpCmd *recoverCmd;
    struct BtlPokeParam *owner;
    u8 weather;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        owner = func_021C7CF4(flow, pokeId);
        weather = func_021D775C(BTL_EVAR_WEATHER);
        if (weather == BTL_WEATHER_SUN) {
            func_021C88B4(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
            damageCmd = func_021C88A4(flow, BTL_CMD_DAMAGE, pokeId);
            damageCmd->pokeId = pokeId;
            damageCmd->amount = func_021D7B74(owner, 8);
            func_021C88C8(flow, damageCmd);
            func_021C88B4(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
        } else if (weather == BTL_WEATHER_RAIN) {
            recoverCmd = func_021C88A4(flow, BTL_CMD_RECOVER_HP, pokeId);
            recoverCmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            recoverCmd->pokeId = pokeId;
            recoverCmd->amount = func_021D7B74(owner, 8);
            func_021C88C8(flow, recoverCmd);
        }
    }
}

/* Dry Skin: fire moves against the owner gain 1.25 times power. */
void func_021DAA70(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID) && func_021D775C(BTL_EVAR_MOVE_TYPE) == POKETYPE_FIRE)
        func_021D7704(BTL_EVAR_POWER_RATIO, BTL_RATIO_1_25);
}

/* Dry Skin: absorbs water moves and restores 1/4 of the HP. */
void func_021DAA94(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (func_021DA8A8(flow, pokeId, POKETYPE_WATER))
        func_021DA8DC(flow, pokeId, 4);
}

BtlEventHandler *func_021DAAB4(int *handlerCount)
{
    *handlerCount = 3;
    return d_021F0B30;
}

/* Water Absorb: absorbs water moves and restores 1/4 of the HP. */
void func_021DAAC0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (func_021DA8A8(flow, pokeId, POKETYPE_WATER))
        func_021DA8DC(flow, pokeId, 4);
}

BtlEventHandler *func_021DAAE0(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0730;
}

/* Volt Absorb: absorbs electric moves and restores 1/4 of the HP. */
void func_021DAAEC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (func_021DA8A8(flow, pokeId, POKETYPE_ELECTRIC))
        func_021DA8DC(flow, pokeId, 4);
}

/* Volt Absorb's table is the second row after the start of Motor Drive's table object. */
BtlEventHandler *func_021DAB0C(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0798 + 1;
}

BtlEventHandler *func_021DAB18(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0798;
}

/* Motor Drive: absorbs electric moves and raises Speed by one stage. */
void func_021DAB24(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (func_021DA8A8(flow, pokeId, POKETYPE_ELECTRIC))
        func_021DA96C(flow, pokeId, BTL_STAT_SPEED, 1);
}

/* Scrappy: the owner's attacks ignore the immunity of Ghost types. */
void func_021DAB48(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID) && func_021D775C(BTL_EVAR_DEFENDER_TYPE) == POKETYPE_GHOST)
        func_021D76BC(BTL_EVAR_IGNORE_IMMUNITY_FLAG, 1);
}

BtlEventHandler *func_021DAB6C(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0790;
}

/* Soundproof: sound moves against the owner have no effect. */
void func_021DAB78(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlMessageCmd *cmd;

    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID)) {
        if (WAZA_TOOL_GetFlag(func_021D775C(BTL_EVAR_MOVE_ID), BTL_WAZA_FLAG_SOUND) != 0 && func_021D76BC(BTL_EVAR_NO_EFFECT_FLAG, 1) != 0) {
            func_021C88B4(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
            cmd = func_021C88A4(flow, BTL_CMD_MESSAGE, pokeId);
            func_021C8838(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
            func_021C8860(&cmd->strParam, pokeId);
            func_021C88C8(flow, cmd);
            func_021C88B4(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
        }
    }
}

BtlEventHandler *func_021DABE8(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0788;
}

/* Levitate: sets the generic flag once for the owner; work[0] gets the result. */
void func_021DABF4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        if (func_021D775C(BTL_EVAR_GENERIC_FLAG) == 0)
            *work = func_021D76BC(BTL_EVAR_GENERIC_FLAG, 1);
    }
}

/* Levitate: shows "no effect" once when the flag was set. */
void func_021DAC1C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    BtlMessageCmd *cmd;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID) && *work != 0) {
        cmd = func_021C88A4(flow, BTL_CMD_MESSAGE, pokeId);
        cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        func_021C8838(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
        func_021C8860(&cmd->strParam, pokeId);
        func_021C88C8(flow, cmd);
        *work = 0;
    }
}

/* Levitate: clears the flag when the owner's event ends. */
void func_021DAC6C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID))
        *work = 0;
}

BtlEventHandler *func_021DAC84(int *handlerCount)
{
    *handlerCount = 3;
    return d_021F0A10;
}

/* Wonder Guard: damaging moves from another Pokemon that are not super effective have no effect. */
void func_021DAC90(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlMessageCmd *cmd;
    struct BtlPokeParam *defender;
    u16 moveId;

    if (pokeId != func_021D775C(BTL_EVAR_DEFENDER_ID))
        return;
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID))
        return;
    defender = func_021C7CF4(flow, pokeId);
    moveId = func_021D775C(BTL_EVAR_MOVE_ID);
    if (WAZA_TOOL_IsDamaging(moveId) == 0)
        return;
    if (moveId == BTL_MOVE_STRUGGLE)
        return;
    if (func_021D775C(BTL_EVAR_TYPE_AFFINITY) > BTL_AFFINITY_NEUTRAL)
        return;
    if (func_021D76BC(BTL_EVAR_NO_EFFECT_FLAG, 1) == 0)
        return;
    func_021C88B4(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
    cmd = func_021C88A4(flow, BTL_CMD_MESSAGE, pokeId);
    func_021C8838(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
    func_021C8860(&cmd->strParam, pokeId);
    func_021C88C8(flow, cmd);
    func_021C88B4(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
}

BtlEventHandler *func_021DAD20(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0660;
}

/* Truant: every other turn the owner loafs; work[0] is the loafing flag, work[1] the fail result. */
void func_021DAD2C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        if (*work != 0) {
            work[1] = func_021D76BC(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_ABILITY);
            *work = 0;
        } else
            *work = 1;
    }
}

/* Truant: starts loafing for the next turn after the owner acted. */
void func_021DAD58(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        if (func_021D5BB0(func_021C7CF4(flow, pokeId), 0))
            *work = 1;
    }
}

/* Truant: shows the loafing message when the fail result is set. */
void func_021DAD84(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    BtlMessageCmd *cmd;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID) && work[1] != 0) {
        cmd = func_021C88A4(flow, BTL_CMD_MESSAGE, pokeId);
        cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        func_021C8838(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_TRUANT_LOAFING);
        func_021C8860(&cmd->strParam, pokeId);
        func_021C88C8(flow, cmd);
        work[1] = 0;
    }
}

/* Truant: clears the loafing flag when the event variable 12 is 7. */
void func_021DADD8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID) && func_021D775C(12) == 7)
        *work = 0;
}

BtlEventHandler *func_021DADF8(int *handlerCount)
{
    *handlerCount = 4;
    return d_021F0B94;
}

/* Damp: Explosion and Self-Destruct fail; work[0] is the fail result, work[1] the move. */
void func_021DAE04(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    u16 moveId;
    moveId = func_021D775C(BTL_EVAR_MOVE_ID);
    *work = 0;
    if (moveId == BTL_MOVE_EXPLOSION || moveId == BTL_MOVE_SELF_DESTRUCT) {
        if (func_021D775C(BTL_EVAR_FAIL_REASON) == 0) {
            *work = func_021D76BC(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_ABILITY);
            work[1] = moveId;
        }
    }
}

/* Damp: shows the message that names the owner and the blocked move. */
void func_021DAE38(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    BtlMessageCmd *cmd;
    u32 ownerId;

    if (*work != 0) {
        ownerId = (u8)func_021D775C(BTL_EVAR_POKE_ID);
        cmd = func_021C88A4(flow, BTL_CMD_MESSAGE, pokeId);
        cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        func_021C8838(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_DAMP_BLOCK);
        func_021C8860(&cmd->strParam, ownerId);
        func_021C8860(&cmd->strParam, work[1]);
        func_021C88C8(flow, cmd);
        *work = 0;
    }
}

/* Damp: while the owner is on the field, Aftermath is blocked. */
void func_021DAE94(struct BtlEventFactor *factor)
{
    func_021D7320(factor, func_021DAEC4);
}

/* Damp: removes the skip check. */
void func_021DAEA4(struct BtlEventFactor *factor)
{
    func_021D7324(factor);
}

/* Damp: removes the skip check when the owner's event comes. */
void func_021DAEAC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID))
        func_021D7324(factor);
}

/* Damp: skip check that blocks the factors of the Aftermath ability. */
int func_021DAEC4(struct BtlEventFactor *other, void *context, int factorType, int eventId, u16 key, u8 ownerId)
{
    if (factorType == BTL_EVENT_TYPE_ABILITY && key == ABILITY_AFTERMATH) {
        return 1;
    }
    return 0;
}

BtlEventHandler *func_021DAED8(int *handlerCount)
{
    *handlerCount = 5;
    return d_021F0BD4;
}

/* Flash Fire: after absorbing fire, the owner's fire moves gain 1.5 times power. */
void func_021DAEE4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID) && func_021D5BDC(func_021C7CF4(flow, pokeId), BTL_CONT_FLAG_FLASH_FIRE) && func_021D775C(BTL_EVAR_MOVE_TYPE) == POKETYPE_FIRE)
        func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_1_5);
}

/* Flash Fire: clears the absorbed-fire flag of the owner. */
void func_021DAF1C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlContFlagCmd *cmd;
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID) && func_021D5BDC(func_021C7CF4(flow, pokeId), BTL_CONT_FLAG_FLASH_FIRE)) {
        cmd = func_021C88A4(flow, BTL_CMD_CLEAR_CONT_FLAG, pokeId);
        cmd->pokeId = pokeId;
        cmd->flagIndex = BTL_CONT_FLAG_FLASH_FIRE;
        func_021C88C8(flow, cmd);
    }
}

/* Flash Fire: absorbs fire moves; the first time it also sets the absorbed-fire flag. */
void func_021DAF58(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlMessageCmd *messageCmd;
    BtlContFlagCmd *flagCmd;

    if (func_021DA8A8(flow, pokeId, POKETYPE_FIRE) != 0) {
        func_021C88B4(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
        if (func_021D5BDC(func_021C7CF4(flow, pokeId), BTL_CONT_FLAG_FLASH_FIRE) == 0) {
            messageCmd = func_021C88A4(flow, BTL_CMD_MESSAGE, pokeId);
            func_021C8838(&messageCmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_FLASH_FIRE_ABSORB);
            func_021C8860(&messageCmd->strParam, pokeId);
            func_021C88C8(flow, messageCmd);
            flagCmd = func_021C88A4(flow, BTL_CMD_SET_CONT_FLAG, pokeId);
            flagCmd->pokeId = pokeId;
            flagCmd->flagIndex = BTL_CONT_FLAG_FLASH_FIRE;
            func_021C88C8(flow, flagCmd);
        } else {
            messageCmd = func_021C88A4(flow, BTL_CMD_MESSAGE, pokeId);
            func_021C8838(&messageCmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
            func_021C8860(&messageCmd->strParam, pokeId);
            func_021C88C8(flow, messageCmd);
        }
        func_021C88B4(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
    }
}

BtlEventHandler *func_021DB000(int *handlerCount)
{
    *handlerCount = 3;
    return d_021F0A28;
}

/* Bad Dreams: hurts every sleeping opposing Pokemon by 1/8 of its HP. */
void func_021DB00C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 victimIds[4];
    struct BtlPokeParam *victim;
    u8 victimCount;
    int popupOpen;
    BtlDamageCmd *cmd;
    u8 i;
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        popupOpen = 0;
        victimCount = func_021C7F68(flow, func_021C7D00(flow, pokeId) | 0x100, victimIds);
        for (i = 0; i < victimCount; i++) {
            victim = func_021C7CF4(flow, victimIds[i]);
            if (func_021D62C4(victim, BTL_SICK_SLEEP)) {
                if (!popupOpen) {
                    popupOpen = 1;
                    func_021C88B4(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
                }
                cmd = func_021C88A4(flow, BTL_CMD_DAMAGE, pokeId);
                cmd->pokeId = victimIds[i];
                cmd->amount = func_021D7B74(victim, 8);
                func_021C8838(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_BAD_DREAMS_HURT);
                func_021C8860(&cmd->strParam, victimIds[i]);
                func_021C88C8(flow, cmd);
            }
        }
        if (popupOpen) func_021C88B4(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
    }
}

BtlEventHandler *func_021DB0D0(int *handlerCount) { *handlerCount = 1; return d_021F07E8; }

/* Run Away: the first handler of its table; belongs to unit_021DB0E4.c. */
void func_021DB0DC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int unusedArg)
{
    func_021E8878(factor, flow, pokeId, unusedArg);
}
