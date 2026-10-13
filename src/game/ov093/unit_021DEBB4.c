/*
 * file:     unit_021DEBB4.c
 * unit:     yes
 * function: func_021DEBB4, func_021DEBEC, func_021DEC44, func_021DEC70
 * address:  0x021DEBB4
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
 *   func_0689C8CC  0x0689C8CC  thumb
 *   d_021F16DC 0x021F16DC data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021DD008 0x021DD008 thumb ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   d_021F13BC 0x021F13BC data a4
 *   func_021D679C  0x021D679C  thumb  ov093
 *   func_021D67A8  0x021D67A8  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   _s32_div_f     0x0209C0A4  arm
 */
#include "unit_021DE7E4_types.h"

struct BtlEventFactor;

extern int func_021D775C(int key);
extern void func_021D7704(int key, int multiplier);
extern int func_021DD008(struct BtlEventFactor *factor);
extern void *func_021C88A4(void *flow, int cmdKind, int pokeId);
extern void func_021C88C8(void *flow, void *cmd);
extern void func_021C8838(HandExStr *str, int strType, int strId);
extern void func_021C8860(HandExStr *str, u32 arg);
extern void *func_021C7CF4(void *flow, int pokeId);
extern int func_021D7B74(void *pokeParam, u32 divisor);
extern int func_0689C8CC(u16 moveId);
extern u16 func_021D679C(void *pokeParam);
extern u16 func_021D67A8(void *pokeParam);
extern int func_021DCFF8(struct BtlEventFactor *factor, int index);
extern u16 func_021D70A8(struct BtlEventFactor *factor);
extern int d_021F16DC;
extern int d_021F13BC;

/* Expert Belt: a super effective hit (affinity above 3) is boosted by the item's ratio. */
void func_021DEBB4(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID)) {
        if (func_021D775C(BTL_EVAR_AFFINITY_SCALED) > BTL_AFFINITY_SUPER_EFFECTIVE_ABOVE)
            func_021D7704(BTL_EVAR_POWER_RATIO, func_021DD008(factor));
    }
}

int *func_021DEBE0(int *count)
{
    *count = 2;
    return &d_021F16DC;
}

/* Life Orb: the attacker loses a tenth of its maximum HP after dealing damage. */
void func_021DEBEC(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    void *attacker;
    HandExLoseHp *cmd;

    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID)) {
        attacker = func_021C7CF4(flow, pokeId);
        cmd = (HandExLoseHp *)func_021C88A4(flow, 7, pokeId);
        cmd->pokeId = pokeId;
        cmd->amount = func_021D7B74(attacker, 10);
        func_021C8838(&cmd->str, HANDEX_STR_SET, 0x3f5);
        func_021C8860(&cmd->str, pokeId);
        func_021C88C8(flow, cmd);
    }
}

/* Life Orb: the attacker's damage is boosted by the item's ratio. */
void func_021DEC44(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID))
        func_021D7704(BTL_EVAR_POWER_RATIO, func_021DD008(factor));
}

int *func_021DEC64(int *count)
{
    *count = 1;
    return &d_021F13BC;
}

/* Metronome: each consecutive use of the same move adds the item's step to the power, up to 200 percent. */
void func_021DEC70(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    void *attacker;
    u16 streak;
    u16 percent;
    u16 moveId;
    int ratio;
    float scaled;

    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID)) {
        if (func_0689C8CC(func_021D775C(BTL_EVAR_MOVE_ID)) == 0) {
            attacker = func_021C7CF4(flow, pokeId);
            streak = (int)func_021D679C(attacker);
            if (streak >= 1) {
                moveId = func_021D775C(BTL_EVAR_MOVE_ID);
                if (moveId == func_021D67A8(attacker)) {
                    percent = streak * func_021DCFF8(factor, 2) + 100;
                    if (percent > 200)
                        percent = 200;
                    if (percent != 0)
                        scaled = 0.5f + (float)(percent << 12);
                    else
                        scaled = (float)(percent << 12) - 0.5f;
                    ratio = (int)scaled;
                    func_021D7704(BTL_EVAR_POWER_RATIO, ratio / 100);
                }
            }
        }
    }
}
