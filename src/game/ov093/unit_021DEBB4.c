/*
 * file:     unit_021DEBB4.c
 * unit:     yes
 * function: BTL_HANDLER_ITEM_ExpertBelt_BoostSuperEffective, BTL_HANDLER_ITEM_LifeOrb_RecoilDamage, BTL_HANDLER_ITEM_LifeOrb_BoostDamage, BTL_HANDLER_ITEM_Metronome_BoostConsecutiveUse
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
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   BTL_HANDLER_ITEM_GetBoostRatio 0x021DD008 thumb ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   d_021F13BC 0x021F13BC data a4
 *   BTL_POKEPARAM_GetMoveStreak  0x021D679C  thumb  ov093
 *   BTL_POKEPARAM_GetLastUsedMoveId  0x021D67A8  thumb  ov093
 *   BTL_HANDLER_ITEM_GetParam  0x021DCFF8  thumb  ov093
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb
 */
#include "unit_021DE7E4_types.h"

struct BtlEventFactor;

extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_MultiplyVar(int key, int multiplier);
extern int BTL_HANDLER_ITEM_GetBoostRatio(struct BtlEventFactor *factor);
extern void *func_021C88A4(void *flow, int cmdKind, int pokeId);
extern void func_021C88C8(void *flow, void *cmd);
extern void func_021C8838(HandExStr *str, int strType, int strId);
extern void func_021C8860(HandExStr *str, u32 arg);
extern void *func_021C7CF4(void *flow, int pokeId);
extern int BTL_CALC_DivideMaxHpMin1(void *pokeParam, u32 divisor);
extern int func_0689C8CC(u16 moveId);
extern u16 BTL_POKEPARAM_GetMoveStreak(void *pokeParam);
extern u16 BTL_POKEPARAM_GetLastUsedMoveId(void *pokeParam);
extern int BTL_HANDLER_ITEM_GetParam(struct BtlEventFactor *factor, int index);
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern int d_021F16DC;
extern int d_021F13BC;

/* Expert Belt: a super effective hit (affinity above 3) is boosted by the item's ratio. */
void BTL_HANDLER_ITEM_ExpertBelt_BoostSuperEffective(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_AFFINITY_SCALED) > BTL_AFFINITY_SUPER_EFFECTIVE_ABOVE)
            BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_HANDLER_ITEM_GetBoostRatio(factor));
    }
}

int *BTL_HANDLER_ITEM_GetLifeOrbHandlers(int *count)
{
    *count = 2;
    return &d_021F16DC;
}

/* Life Orb: the attacker loses a tenth of its maximum HP after dealing damage. */
void BTL_HANDLER_ITEM_LifeOrb_RecoilDamage(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    void *attacker;
    HandExLoseHp *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        attacker = func_021C7CF4(flow, pokeId);
        cmd = (HandExLoseHp *)func_021C88A4(flow, 7, pokeId);
        cmd->pokeId = pokeId;
        cmd->amount = BTL_CALC_DivideMaxHpMin1(attacker, 10);
        func_021C8838(&cmd->str, HANDEX_STR_SET, 0x3f5);
        func_021C8860(&cmd->str, pokeId);
        func_021C88C8(flow, cmd);
    }
}

/* Life Orb: the attacker's damage is boosted by the item's ratio. */
void BTL_HANDLER_ITEM_LifeOrb_BoostDamage(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_HANDLER_ITEM_GetBoostRatio(factor));
}

int *BTL_HANDLER_ITEM_GetMetronomeHandlers(int *count)
{
    *count = 1;
    return &d_021F13BC;
}

/* Metronome: each consecutive use of the same move adds the item's step to the power, up to 200 percent. */
void BTL_HANDLER_ITEM_Metronome_BoostConsecutiveUse(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    void *attacker;
    u16 streak;
    u16 percent;
    u16 moveId;
    int ratio;
    float scaled;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (func_0689C8CC(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == 0) {
            attacker = func_021C7CF4(flow, pokeId);
            streak = (int)BTL_POKEPARAM_GetMoveStreak(attacker);
            if (streak >= 1) {
                moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
                if (moveId == BTL_POKEPARAM_GetLastUsedMoveId(attacker)) {
                    percent = streak * BTL_HANDLER_ITEM_GetParam(factor, 2) + 100;
                    if (percent > 200)
                        percent = 200;
                    if (percent != 0)
                        scaled = 0.5f + (float)(percent << 12);
                    else
                        scaled = (float)(percent << 12) - 0.5f;
                    ratio = (int)scaled;
                    BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, ratio / 100);
                }
            }
        }
    }
}
