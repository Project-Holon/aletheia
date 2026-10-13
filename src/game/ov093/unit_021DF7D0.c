/*
 * file:     unit_021DF7D0.c
 * unit:     yes
 * function: func_021DF7D0, func_021DF7DC, func_021DF7E8, func_021DF7F4, func_021DF834
 * address:  0x021DF7D0
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
 *   func_021DF93C  0x021DF93C  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D7D18  0x021D7D18  thumb  ov093
 *   d_021F170C     0x021F170C  data   ov093  a4
 *   d_021F15AC     0x021F15AC  data    a4
 */
#include "unit_021DF3A4_types.h"

extern const BtlEventHandler d_021F170C[];
extern const BtlEventHandler d_021F15AC[];

void func_021DF7D0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF7DC(int *handlerCount);
void func_021DF7E8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DF7F4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF834(int *handlerCount);

/* Sharp Beak. */
void func_021DF7D0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF93C(factor, flow, pokeId, BTL_TYPE_FLYING);
}

/* Poison Barb: two entries. */
const BtlEventHandler *func_021DF7DC(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F170C;
}

/* Poison Barb. */
void func_021DF7E8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021DF93C(factor, flow, pokeId, BTL_TYPE_POISON);
}

/*
 * Poison Barb, Fling: poison the target. Same shape as the Light Ball
 * version, with the poison condition.
 */
void func_021DF7F4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlAddSickCmd *cmd;
    unsigned char flingerId;

    if (pokeId != func_021D775C(BTL_EVAR_POKE_ID))
        return;
    flingerId = func_021D775C(BTL_EVAR_ATTACKER_ID);
    cmd = (BtlAddSickCmd *)func_021C88A4(flow, BTL_CMD_KIND_ADD_SICK, flingerId);
    cmd->pokeId = pokeId;
    cmd->sickKind = TKS_SICK_POISON;
    cmd->sickCont = func_021D7D18(TKS_SICK_POISON);
    func_021C88C8(flow, cmd);
}

/* Never-Melt Ice. */
const BtlEventHandler *func_021DF834(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F15AC;
}
