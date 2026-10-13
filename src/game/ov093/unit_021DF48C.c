/*
 * file:     unit_021DF48C.c
 * unit:     yes
 * function: func_021DF48C, func_021DF498, func_021DF4A4, func_021DF4B0, func_021DF4BC, func_021DF4C8, func_021DF4D4, func_021DF4E0, func_021DF510, func_021DF51C, func_021DF548, func_021DF588, func_021DF594, func_021DF5F4, func_021DF634, func_021DF640, func_021DF6AC, func_021DF6EC, func_021DF6F8, func_021DF704, func_021DF710, func_021DF71C, func_021DF728, func_021DF734
 * address:  0x021DF48C
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
 *   d_021F1464     0x021F1464  data   ov093  a4
 *   d_021F151C     0x021F151C  data   a4
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F1514     0x021F1514  data   ov093  a4
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D7D18  0x021D7D18  thumb  ov093
 *   d_021F167C     0x021F167C  data   ov093  a4
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021E8A58  0x021E8A58  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   d_021F168C     0x021F168C  data   ov093  a4
 *   d_021F169C     0x021F169C  data   ov093  a4
 *   func_021DF93C  0x021DF93C  thumb  ov093
 *   d_021F14F4     0x021F14F4  data   ov093  a4
 *   d_021F13FC     0x021F13FC  data   ov093  a4
 *   d_021F13AC     0x021F13AC  data   ov093  a4
 *   d_021F137C     0x021F137C  data   ov093  a4
 */
#include "unit_021DF3A4_types.h"

extern const BtlEventHandler d_021F1464[];
extern const BtlEventHandler d_021F151C[];
extern const BtlEventHandler d_021F1514[];
extern const BtlEventHandler d_021F167C[];
extern const BtlEventHandler d_021F168C[];
extern const BtlEventHandler d_021F169C[];
extern const BtlEventHandler d_021F14F4[];
extern const BtlEventHandler d_021F13FC[];
extern const BtlEventHandler d_021F13AC[];
extern const BtlEventHandler d_021F137C[];

void func_021DF48C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF498(int *handlerCount);
void func_021DF4A4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF4B0(int *handlerCount);
void func_021DF4BC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF4C8(int *handlerCount);
void func_021DF4D4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DF4E0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int weather);
const BtlEventHandler *func_021DF510(int *handlerCount);
void func_021DF51C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DF548(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF588(int *handlerCount);
void func_021DF594(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DF5F4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF634(int *handlerCount);
void func_021DF640(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DF6AC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF6EC(int *handlerCount);
void func_021DF6F8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF704(int *handlerCount);
void func_021DF710(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF71C(int *handlerCount);
void func_021DF728(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF734(int *handlerCount);

/* Icy Rock: hail lasts longer. */
void func_021DF48C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF4E0(factor, flow, pokeId, BTL_WEATHER_HAIL);
}

const BtlEventHandler *func_021DF498(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F1464;
}

/* Smooth Rock: sandstorm lasts longer. */
void func_021DF4A4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF4E0(factor, flow, pokeId, BTL_WEATHER_SAND);
}

const BtlEventHandler *func_021DF4B0(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F151C;
}

/* Heat Rock: sunshine lasts longer. */
void func_021DF4BC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF4E0(factor, flow, pokeId, BTL_WEATHER_SUN);
}

const BtlEventHandler *func_021DF4C8(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F1514;
}

/* Damp Rock: rain lasts longer. */
void func_021DF4D4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF4E0(factor, flow, pokeId, BTL_WEATHER_RAIN);
}

/* Weather rocks: when the holder sets the given weather, replace its turn count with the item parameter. */
void func_021DF4E0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int weather)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID) && weather == func_021D775C(BTL_EVAR_WEATHER))
        func_021D76BC(BTL_EVAR_WEATHER_TURNS, func_021DCFF8(factor, BTL_ITEM_PARAM_BOOST_PERCENT));
}

/* Light Ball: two entries. */
const BtlEventHandler *func_021DF510(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F167C;
}

/* Light Ball: doubles the attack ratio of a Pikachu. */
void func_021DF51C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID) && func_021D5444(func_021C7CF4(flow, pokeId)) == BTL_SPECIES_PIKACHU)
        func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_2_0);
}

/* Light Ball, Fling: paralyze the target. */
void func_021DF548(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlAddSickCmd *cmd;
    unsigned char flingerId;

    if (pokeId != func_021D775C(BTL_EVAR_POKE_ID))
        return;
    flingerId = func_021D775C(BTL_EVAR_ATTACKER_ID);
    cmd = (BtlAddSickCmd *)func_021C88A4(flow, BTL_CMD_KIND_ADD_SICK, flingerId);
    cmd->pokeId = pokeId;
    cmd->sickKind = TKS_SICK_PARALYSIS;
    cmd->sickCont = func_021D7D18(TKS_SICK_PARALYSIS);
    func_021C88C8(flow, cmd);
}

/* Toxic Orb: two entries. */
const BtlEventHandler *func_021DF588(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F168C;
}

/* Toxic Orb: at turn end badly poison the holder and show the message. */
void func_021DF594(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlAddSickCmd *cmd;

    if (pokeId != func_021D775C(BTL_EVAR_POKE_ID))
        return;
    cmd = (BtlAddSickCmd *)func_021C88A4(flow, BTL_CMD_KIND_ADD_SICK, pokeId);
    cmd->sickKind = TKS_SICK_POISON;
    cmd->sickCont = func_021E8A58();
    cmd->hideMessage = 0;
    cmd->pokeId = pokeId;
    func_021C8838(&cmd->strParam, BTL_STR_TYPE_STANDARD, 0xf0);
    func_021C8860(&cmd->strParam, pokeId);
    func_021C8860(&cmd->strParam, func_021D70A8(factor));
    func_021C88C8(flow, cmd);
}

/*
 * Toxic Orb, Fling: badly poison the target.
 *
 * func_021E8A58 returns the condition record by value; that is what reserves
 * the empty frame word (push r3 / sub sp, #4). An int return drops it.
 */
void func_021DF5F4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlAddSickCmd *cmd;
    unsigned char flingerId;

    if (pokeId != func_021D775C(BTL_EVAR_POKE_ID))
        return;
    flingerId = func_021D775C(BTL_EVAR_ATTACKER_ID);
    cmd = (BtlAddSickCmd *)func_021C88A4(flow, BTL_CMD_KIND_ADD_SICK, flingerId);
    cmd->pokeId = pokeId;
    cmd->sickKind = TKS_SICK_POISON;
    cmd->sickCont = func_021E8A58();
    func_021C88C8(flow, cmd);
}

/* Flame Orb: two entries. */
const BtlEventHandler *func_021DF634(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F169C;
}

/* Flame Orb: at turn end burn the holder and show the message. */
void func_021DF640(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlAddSickCmd *cmd;

    if (pokeId != func_021D775C(BTL_EVAR_POKE_ID))
        return;
    cmd = (BtlAddSickCmd *)func_021C88A4(flow, BTL_CMD_KIND_ADD_SICK, pokeId);
    cmd->sickKind = TKS_SICK_BURN;
    cmd->sickCont = func_021D7D18(TKS_SICK_BURN);
    cmd->hideMessage = 0;
    cmd->pokeId = pokeId;
    /* The message argument is written here and again by the second append below. */
    cmd->strParam.args[1] = func_021D70A8(factor);
    func_021C8838(&cmd->strParam, BTL_STR_TYPE_STANDARD, 0x102);
    func_021C8860(&cmd->strParam, pokeId);
    func_021C8860(&cmd->strParam, func_021D70A8(factor));
    func_021C88C8(flow, cmd);
}

/* Flame Orb, Fling: burn the target. */
void func_021DF6AC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlAddSickCmd *cmd;
    unsigned char flingerId;

    if (pokeId != func_021D775C(BTL_EVAR_POKE_ID))
        return;
    flingerId = func_021D775C(BTL_EVAR_ATTACKER_ID);
    cmd = (BtlAddSickCmd *)func_021C88A4(flow, BTL_CMD_KIND_ADD_SICK, flingerId);
    cmd->pokeId = pokeId;
    cmd->sickKind = TKS_SICK_BURN;
    cmd->sickCont = func_021D7D18(TKS_SICK_BURN);
    func_021C88C8(flow, cmd);
}

/* Silver Powder. */
const BtlEventHandler *func_021DF6EC(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F14F4;
}

void func_021DF6F8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF93C(factor, flow, pokeId, BTL_TYPE_BUG);
}

/* Soft Sand. */
const BtlEventHandler *func_021DF704(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F13FC;
}

void func_021DF710(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF93C(factor, flow, pokeId, BTL_TYPE_GROUND);
}

/* Hard Stone. */
const BtlEventHandler *func_021DF71C(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F13AC;
}

void func_021DF728(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF93C(factor, flow, pokeId, BTL_TYPE_ROCK);
}

/* Miracle Seed. */
const BtlEventHandler *func_021DF734(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F137C;
}
