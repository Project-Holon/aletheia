/*
 * file:     unit_021DED28.c
 * unit:     yes
 * function: func_021DED28, func_021DED60, func_021DED6C, func_021DEDEC
 * address:  0x021DED28
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
 *   func_021E8C9C  0x021E8C9C  thumb  ov093
 *   func_021DCFF8   0x021DCFF8  thumb ov093
 *   func_021D70A8   0x021D70A8  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *   func_0209C2B0   0x0209C2B0  arm
 *   d_021F152C     0x021F152C  data   ov093  a4
 *   d_021F143C     0x021F143C  data   ov093  a4
 */
#include "unit_021DE7E4_types.h"

struct BtlEventFactor;

extern int func_021D775C(int key);
extern int func_021D76BC(int key, u32 value);
extern void func_021E8C9C(u32 *sickCont, int value);
extern int func_021DCFF8(struct BtlEventFactor *factor, int index);
extern int func_0209C2B0(int dividend, int divisor);
extern u16 func_021D70A8(struct BtlEventFactor *factor);
extern void *func_021C88A4(void *flow, int cmdKind, int pokeId);
extern void func_021C8838(HandExStr *str, int strType, int strId);
extern void func_021C8860(HandExStr *str, u32 arg);
extern void func_021C88C8(void *flow, void *cmd);
extern int d_021F152C[];
extern int d_021F143C[];

/* Grip Claw: a binding status applied by the holder is stretched to the longer duration. */
void func_021DED28(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    int sickCont;

    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID) && func_021D775C(BTL_EVAR_SICK_ID) == BTL_SICK_BIND) {
        sickCont = func_021D775C(BTL_EVAR_SICK_CONT);
        func_021E8C9C((u32 *)&sickCont, 8);
        func_021D76BC(BTL_EVAR_SICK_CONT, sickCont);
    }
}

int *func_021DED60(int *count)
{
    *count = 1;
    return d_021F152C;
}

/*
 * Shell Bell: after the holder dealt damage (and no other effect blocks it),
 * it recovers the damage divided by the item's parameter, at least 1 HP.
 */
void func_021DED6C(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    int damage, amount;
    HandExRecoverHp *cmd;

    if (pokeId != func_021D775C(BTL_EVAR_ATTACKER_ID))
        return;
    if (func_021D775C(BTL_EVAR_NO_EFFECT_FLAG) != 0)
        return;
    damage = func_021D775C(BTL_EVAR_DAMAGE);
    if (damage == 0)
        return;
    amount = func_0209C2B0(damage, func_021DCFF8(factor, 2));
    if (amount == 0)
        amount = 1;
    cmd = (HandExRecoverHp *)func_021C88A4(flow, HANDEX_KIND_RECOVER_HP, pokeId);
    cmd->pokeId = pokeId;
    cmd->amount = amount;
    func_021C8838(&cmd->str, HANDEX_STR_SET, 0x392);
    func_021C8860(&cmd->str, pokeId);
    func_021C8860(&cmd->str, func_021D70A8(factor));
    func_021C88C8(flow, cmd);
}

int *func_021DEDEC(int *count)
{
    *count = 1;
    return d_021F143C;
}
