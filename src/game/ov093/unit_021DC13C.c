/*
 * file:     unit_021DC13C.c
 * unit:     yes
 * function: func_021DC13C, func_021DC170, func_021DC20C, func_021DC218, func_021DC250, func_021DC25C, func_021DC294, func_021DC2A0, func_021DC320
 * address:  0x021DC13C
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
 *   d_021F0780 0x021F0780 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021B9A24 0x021B9A24 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C7F68  0x021C7F68  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D85C0  0x021D85C0  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   d_021F0778     0x021F0778  data   ov093  a4
 *   d_021F0768     0x021F0768  data   ov093  a4
 *   WAZA_TOOL_IsDamaging  0x0201C314  thumb
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F0620     0x021F0620  data   ov093  a4
 *   d_021F05E8     0x021F05E8  data   ov093  a4
 */
#include "unit_021DBAF0_types.h"

extern int func_021D775C(int key);
extern int func_021B9A24(unsigned int pokeIdA, unsigned int pokeIdB);
extern void func_021D7704(int key, int ratio);
extern int func_021C8010(struct BtlServerFlow *flow, unsigned int mask);
extern u8 func_021C7F68(struct BtlServerFlow *flow, int posKey, u8 *out);
extern struct BtlPokeParam *func_021C7CF4(struct BtlServerFlow *flow, int pokeId);
extern int func_021D62A8(struct BtlPokeParam *bpp);
extern int func_021D85C0(struct BtlServerFlow *flow, u32 percent);
extern void *func_021C88A4(struct BtlServerFlow *flow, int cmdKind, int pokeId);
extern void func_021C88C8(struct BtlServerFlow *flow, void *cmd);
extern int func_021D62C4(struct BtlPokeParam *bpp, int sickId);
extern u32 WAZA_TOOL_IsDamaging(u16 moveId);
extern int func_021D76BC(int key, u32 value);
extern void func_021C8838(BtlStrParam *strParam, int strType, int strId);
extern void func_021C8860(BtlStrParam *strParam, u32 arg);
void func_021DC13C(struct BtlEventFactor *factor, struct BtlServerFlow *flow, unsigned int ownerId);
int *func_021DC164(int *handlerCount);
void func_021DC170(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
int *func_021DC20C(int *handlerCount);
void func_021DC218(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
int *func_021DC250(int *handlerCount);
void func_021DC25C(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
int *func_021DC294(int *handlerCount);
void func_021DC2A0(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u32 ownerId);
int *func_021DC320(int *handlerCount);
extern int d_021F0780;
extern int d_021F0778[];
extern int d_021F0768[];
extern int d_021F0620[];
extern int d_021F05E8[];

/* Friend Guard: damage to an ally of the owner is reduced to three quarters. */
void func_021DC13C(struct BtlEventFactor *factor, struct BtlServerFlow *flow, unsigned int ownerId)
{
    unsigned char defenderId;
    defenderId = func_021D775C(BTL_EVAR_DEFENDER_ID);
    if (defenderId != ownerId && func_021B9A24(ownerId, defenderId))
        func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_0_75);
}

int *func_021DC164(int *handlerCount) { *handlerCount = 1; return &d_021F0780; }

/* Healer: sometimes cures the major status condition of an ally. */
void func_021DC170(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    u8 allyIds[4];
    u8 allyCount;
    u8 i;
    BtlCureSickCmd *cmd;

    if (ownerId == func_021D775C(BTL_EVAR_POKE_ID)) {
        allyCount = func_021C7F68(flow, (u16)(0x400 | func_021C8010(flow, ownerId)), allyIds);
        for (i = 0; i < allyCount; i++) {
            if (allyIds[i] != ownerId) {
                if (func_021D62A8(func_021C7CF4(flow, allyIds[i])) && func_021D85C0(flow, 30)) {
                    cmd = func_021C88A4(flow, BTL_CMD_KIND_CURE_SICK, ownerId);
                    cmd->flags |= BTL_CMD_FLAG_FROM_ABILITY;
                    cmd->flags |= BTL_CMD_FLAG_ABILITY_ON_ALLY;
                    cmd->showMessage = 1;
                    cmd->pokeId = allyIds[i];
                    cmd->sickIndex = BTL_CURE_ALL_MAJOR;
                    func_021C88C8(flow, cmd);
                }
            }
        }
    }
}

int *func_021DC20C(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0778;
}

/* Toxic Boost: while poisoned, the physical power of the owner is 1.5 times. */
void func_021DC218(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == func_021D775C(BTL_EVAR_ATTACKER_ID)
        && func_021D62C4(func_021C7CF4(flow, ownerId), BTL_SICK_POISON) != 0
        && func_021D775C(BTL_EVAR_DAMAGE_TYPE) == BTL_DAMAGE_TYPE_PHYSICAL) {
        func_021D7704(BTL_EVAR_POWER_RATIO, BTL_RATIO_1_5);
    }
}

int *func_021DC250(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0768;
}

/* Flare Boost: while burned, the special power of the owner is 1.5 times. */
void func_021DC25C(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == func_021D775C(BTL_EVAR_ATTACKER_ID)
        && func_021D62C4(func_021C7CF4(flow, ownerId), BTL_SICK_BURN) != 0
        && func_021D775C(BTL_EVAR_DAMAGE_TYPE) == BTL_DAMAGE_TYPE_SPECIAL) {
        func_021D7704(BTL_EVAR_POWER_RATIO, BTL_RATIO_1_5);
    }
}

int *func_021DC294(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F0620;
}

/* Telepathy: damaging moves of an ally do not hit the owner. */
void func_021DC2A0(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u32 ownerId)
{
    BtlMessageCmd *cmd;
    u8 attackerId;
    if (ownerId == func_021D775C(BTL_EVAR_DEFENDER_ID)) {
        attackerId = func_021D775C(BTL_EVAR_ATTACKER_ID);
        if (func_021B9A24(ownerId, attackerId) != 0
            && ownerId != attackerId
            && WAZA_TOOL_IsDamaging(func_021D775C(BTL_EVAR_MOVE_ID)) != 0
            && func_021D76BC(BTL_EVAR_NO_EFFECT_FLAG, 1) != 0) {
            cmd = func_021C88A4(flow, BTL_CMD_KIND_MESSAGE, ownerId);
            cmd->flags |= BTL_CMD_FLAG_FROM_ABILITY;
            func_021C8838(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_TELEPATHY_AVOID);
            func_021C8860(&cmd->strParam, ownerId);
            func_021C88C8(flow, cmd);
        }
    }
}

int *func_021DC320(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F05E8;
}
