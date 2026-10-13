/*
 * file:     unit_021DEDF8.c
 * unit:     yes
 * function: func_021DEDF8, func_021DEE3C, func_021DEE48, func_021DEE7C, func_021DEEA4, func_021DEEF0, func_021DEEFC, func_021DEF48, func_021DEFB8
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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   func_021E8C50  0x021E8C50  thumb  ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021DD044  0x021DD044  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   d_021F197C     0x021F197C  data   ov093  a4
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5B48  0x021D5B48  thumb  ov093
 *   func_021D70C8  0x021D70C8  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   d_021F16EC     0x021F16EC  data   ov093  a4
 *   d_021F14B4     0x021F14B4  data   ov093  a4
 */
#include "unit_021DE7E4_types.h"

struct BtlEventFactor;

#define BTL_MOVE_SKY_DROP 507 /* (guess) the two-turn move that Power Herb cannot skip */

extern int func_021D775C(int key);
extern int func_021D76BC(int key, u32 value);
extern int func_021DCFF8(struct BtlEventFactor *factor, int index);
extern void func_021E8C50(u32 *sickCont, u32 turns);
extern void func_021D7704(int key, int multiplier);
extern void func_021DD044(struct BtlEventFactor *factor, void *flow, int pokeId);
extern void *func_021C88A4(void *flow, int cmdKind, int pokeId);
extern void func_021C88C8(void *flow, void *cmd);
extern void func_021C8838(HandExStr *str, int strType, int strId);
extern void func_021C8860(HandExStr *str, u32 arg);
extern u16 func_021D70A8(struct BtlEventFactor *factor);
extern void *func_021C7CF4(void *flow, int pokeId);
extern int func_021D5B48(void *pokeParam);
extern void func_021D70C8(struct BtlEventFactor *factor);
extern int func_021D7B74(void *pokeParam, u32 divisor);
extern int d_021F197C[];
extern int d_021F16EC[];
extern int d_021F14B4[];

/* Light Clay: a screen set up by the holder lasts the item's parameter in extra turns. */
void func_021DEDF8(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    int sickCont;
    u8 extraTurns;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID) && (u32)func_021D775C(BTL_EVAR_SCREEN_KIND) <= 1) {
        sickCont = func_021D775C(BTL_EVAR_SICK_CONT);
        extraTurns = func_021DCFF8(factor, 2);
        func_021E8C50((u32 *)&sickCont, extraTurns);
        func_021D76BC(BTL_EVAR_SICK_CONT, sickCont);
    }
}

int *func_021DEE3C(int *count)
{
    *count = 3;
    return d_021F197C;
}

/* Power Herb: a two-turn move (except Sky Drop) skips its charge turn. */
void func_021DEE48(struct BtlEventFactor *factor, void *flow, int pokeId, int *work)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID)) {
        if (func_021D775C(BTL_EVAR_MOVE_ID) != BTL_MOVE_SKY_DROP) {
            if (func_021D76BC(BTL_EVAR_SKIP_CHARGE_FLAG, 1))
                *work = 1;
        }
    }
}

/* Power Herb: use up the item when the charge turn was skipped. */
void func_021DEE7C(struct BtlEventFactor *factor, void *flow, int pokeId, int *work)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID) && *work != 0)
        func_021DD044(factor, flow, pokeId);
}

/* Power Herb: show the message that the holder became fully charged. */
void func_021DEEA4(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    HandExMessage *cmd;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        cmd = (HandExMessage *)func_021C88A4(flow, HANDEX_KIND_MESSAGE, pokeId);
        func_021C8838(&cmd->str, HANDEX_STR_SET, 0x3fe);
        func_021C8860(&cmd->str, pokeId);
        func_021C8860(&cmd->str, func_021D70A8(factor));
        func_021C88C8(flow, cmd);
    }
}

int *func_021DEEF0(int *count)
{
    *count = 2;
    return d_021F16EC;
}

/* Leftovers: at the end of the turn, if the holder is hurt, start the item effect. */
void func_021DEEFC(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    HandExItemUse *cmd;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        if (func_021D5B48(func_021C7CF4(flow, pokeId)) == 0) {
            cmd = (HandExItemUse *)func_021C88A4(flow, 0, pokeId);
            cmd->flags = (cmd->flags & ~1) | 1;
            func_021D70C8(factor);
            func_021C88C8(flow, cmd);
        }
    }
}

/* Leftovers: recover a sixteenth of the maximum HP. */
void func_021DEF48(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    void *holder;
    HandExRecoverHp *cmd;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        holder = func_021C7CF4(flow, pokeId);
        if (func_021D5B48(holder) == 0) {
            cmd = (HandExRecoverHp *)func_021C88A4(flow, HANDEX_KIND_RECOVER_HP, pokeId);
            cmd->pokeId = pokeId;
            cmd->amount = func_021D7B74(holder, 16);
            func_021C8838(&cmd->str, HANDEX_STR_SET, 0x392);
            func_021C8860(&cmd->str, pokeId);
            func_021C8860(&cmd->str, func_021D70A8(factor));
            func_021C88C8(flow, cmd);
        }
    }
}

int *func_021DEFB8(int *count)
{
    *count = 1;
    return d_021F14B4;
}
