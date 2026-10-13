/*
 * file:     unit_021DC6EC.c
 * unit:     yes
 * function: func_021DC6EC, func_021DC6F8, func_021DC738, func_021DC7BC, func_021DC814, func_021DC820, func_021DC844, func_021DC864, func_021DC87C, func_021DC888, func_021DC894, func_021DC8FC, func_021DC908, func_021DC954
 * address:  0x021DC6EC
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
 *   d_021F0990 0x021F0990 data a4
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D7B60  0x021D7B60  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D70AC 0x021D70AC thumb ov093
 *   func_021B9A40 0x021B9A40 thumb ov093
 *   func_021D7320 0x021D7320 thumb ov093
 *   func_021D7324   0x021D7324  thumb
 *   d_021F0B48     0x021F0B48  data   ov093  a4
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   d_021F0A00     0x021F0A00  data   ov093  a4
 *   d_021F0770     0x021F0770  data   ov093  a4
 *   d_021F05D0     0x021F05D0  data   ov093  a4
 *   d_021F05B0     0x021F05B0  data   ov093  a4
 */
#include "unit_021DC6EC_types.h"

extern BtlEventHandler d_021F0990[];
extern BtlEventHandler d_021F0B48[];
extern BtlEventHandler d_021F0A00[];
extern BtlEventHandler d_021F0770[];
extern BtlEventHandler d_021F05D0[];
extern BtlEventHandler d_021F05B0[];

BtlEventHandler *func_021DC6EC(u32 *handlerCount);
void func_021DC6F8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
void func_021DC738(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
void func_021DC7BC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
BtlEventHandler *func_021DC814(u32 *handlerCount);
int func_021DC820(struct BtlEventFactor *factor, void *context, int targetFactorType, int eventId, u16 targetKey, u8 targetOwnerId);
void func_021DC844(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
void func_021DC864(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
BtlEventHandler *func_021DC87C(u32 *handlerCount);
BtlEventHandler *func_021DC888(u32 *handlerCount);
void func_021DC894(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
BtlEventHandler *func_021DC8FC(u32 *handlerCount);
void func_021DC908(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
BtlEventHandler *func_021DC954(u32 *handlerCount);

BtlEventHandler *func_021DC6EC(u32 *handlerCount) { *handlerCount = 2; return d_021F0990; }

/* Sand Force: while the owner attacks in a sandstorm, Ground, Rock and Steel moves get 1.3 times power. */
void func_021DC6F8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    u8 moveType;

    if (ownerId == func_021D775C(BTL_EVAR_ATTACKER_ID) && func_021C8288(flow) == BTL_WEATHER_SAND) {
        moveType = func_021D775C(BTL_EVAR_MOVE_TYPE);
        if (moveType == POKETYPE_GROUND || moveType == POKETYPE_ROCK || moveType == POKETYPE_STEEL)
            func_021D7704(BTL_EVAR_POWER_RATIO, BTL_RATIO_1_3);
    }
}

/* Zen Mode: a Darmanitan at half HP or less takes the Zen form; above half it takes the base form. */
void func_021DC738(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    struct BtlPokeParam *bpp;
    u8 wantZenForm;
    BtlFormChangeCmd *cmd;

    bpp = func_021C7CF4(flow, ownerId);
    if (func_021D5444(bpp) == SPECIES_DARMANITAN) {
        wantZenForm = (func_021D59B4(bpp, BTL_BPP_VALUE_HP) <= func_021D7B60(bpp, 2));
        if (wantZenForm != func_021D59B4(bpp, BTL_BPP_VALUE_FORM)) {
            cmd = func_021C88A4(flow, BTL_CMD_KIND_FORM_CHANGE, ownerId);
            cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            cmd->pokeId = ownerId;
            cmd->form = wantZenForm;
            func_021C8838(&cmd->strParam, BTL_STR_TYPE_ABILITY_LINE, (u16)(wantZenForm == 1 ? BTL_STR_ZEN_MODE_ON : BTL_STR_ZEN_MODE_OFF));
            func_021C88C8(flow, cmd);
        }
    }
}

/* Zen Mode: when the Darmanitan leaves or loses the ability, it returns to the base form. */
void func_021DC7BC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    BtlFormChangeCmd *cmd;

    if (ownerId == func_021D775C(BTL_EVAR_POKE_ID)) {
        if (func_021D5444(func_021C7CF4(flow, ownerId)) == SPECIES_DARMANITAN) {
            cmd = func_021C88A4(flow, BTL_CMD_KIND_FORM_CHANGE, ownerId);
            cmd->pokeId = ownerId;
            cmd->form = 0;
            func_021C8838(&cmd->strParam, BTL_STR_TYPE_ABILITY_LINE, BTL_STR_ZEN_MODE_OFF);
            func_021C8860(&cmd->strParam, ownerId);
            func_021C88C8(flow, cmd);
        }
    }
}

BtlEventHandler *func_021DC814(u32 *handlerCount)
{
    *handlerCount = 3;
    return d_021F0B48;
}

/*
 * Infiltrator skip check: skips the screen-type side conditions that belong to
 * the other side than the Infiltrator's owner.
 */
int func_021DC820(struct BtlEventFactor *factor, void *context, int targetFactorType, int eventId, u16 targetKey, u8 targetOwnerId)
{
    u8 ownSide;

    if (targetFactorType == BTL_EVENT_TYPE_SIDE_CONDITION) {
        ownSide = func_021B9A40(func_021D70AC(factor));
        if (ownSide != targetOwnerId && targetKey <= BTL_SIDE_CONDITION_SCREEN_KEY_MAX)
            return 1;
    }
    return 0;
}

/* Infiltrator: while the owner attacks, install the skip check on its factor. */
void func_021DC844(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    if (ownerId == func_021D775C(BTL_EVAR_ATTACKER_ID))
        func_021D7320(factor, func_021DC820);
}

/* Infiltrator: when the owner's attack ends, remove the skip check again. */
void func_021DC864(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    if (ownerId == func_021D775C(BTL_EVAR_POKE_ID))
        func_021D7324(factor);
}

BtlEventHandler *func_021DC87C(u32 *handlerCount)
{
    *handlerCount = 2;
    return d_021F0A00;
}

BtlEventHandler *func_021DC888(u32 *handlerCount)
{
    *handlerCount = 1;
    return d_021F0770;
}

/* Moxie: the owner raises its Attack by one rank for each defender it knocked out. */
void func_021DC894(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    u32 defenderCount;
    u32 i;
    BtlRankCmd *cmd;

    if (ownerId == func_021D775C(BTL_EVAR_ATTACKER_ID)) {
        defenderCount = func_021D775C(BTL_EVAR_DEFENDER_COUNT);
        for (i = 0; i < defenderCount; i++) {
            if (func_021D5B68(func_021C7CF4(flow, (u8)func_021D775C(i + BTL_EVAR_DEFENDER_FIRST))) != 0) {
                cmd = func_021C88A4(flow, BTL_CMD_KIND_RANK_CHANGE, ownerId);
                cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
                cmd->targetCount = 1;
                cmd->targets[0] = ownerId;
                cmd->statId = BTL_RANK_STAT_ATTACK;
                cmd->amount = 1;
                func_021C88C8(flow, cmd);
            }
        }
    }
}

BtlEventHandler *func_021DC8FC(u32 *handlerCount)
{
    *handlerCount = 1;
    return d_021F05D0;
}

/* Justified: when a Dark move hits the owner, it raises its Attack by one rank. */
void func_021DC908(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    BtlRankCmd *cmd;

    if (ownerId == func_021D775C(BTL_EVAR_DEFENDER_ID) && func_021D775C(BTL_EVAR_HIT_SUBSTITUTE) == 0 && func_021D775C(BTL_EVAR_MOVE_TYPE) == POKETYPE_DARK) {
        cmd = func_021C88A4(flow, BTL_CMD_KIND_RANK_CHANGE, ownerId);
        cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        cmd->targetCount = 1;
        cmd->targets[0] = ownerId;
        cmd->statId = BTL_RANK_STAT_ATTACK;
        cmd->amount = 1;
        func_021C88C8(flow, cmd);
    }
}

BtlEventHandler *func_021DC954(u32 *handlerCount)
{
    *handlerCount = 1;
    return d_021F05B0;
}
