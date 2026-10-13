/*
 * file:     unit_021DC57C.c
 * unit:     yes
 * function: func_021DC57C, func_021DC5EC, func_021DC5F8, func_021DC604, func_021DC614, func_021DC624, func_021DC630, func_021DC664, func_021DC6A0
 * address:  0x021DC57C
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
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   BTL_POKEPARAM_IsFainted   0x021D5B68  thumb ov093
 *   BTL_POKEPARAM_IsHpFull   0x021D5B48  thumb ov093
 *   BTL_CALC_DivideMaxHpMin1   0x021D7B74  thumb ov093
 *   func_021D59B4   0x021D59B4  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *   BTL_ABILITY_BlockIndirectDamage   0x021D928C  thumb
 *   BTL_ABILITY_ShowIndirectGuardMessage   0x021D92CC  thumb
 *   gRegeneratorHandlers     0x021F0700  data   ov093  a4
 *   gIndirectGuardCause2Handlers     0x021F0940  data   ov093  a4
 *   gWonderSkinHandlers 0x021F06D0 data a4
 *   func_021C8288 0x021C8288 thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   gAnalyticHandlers 0x021F0628 data a4
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 *   func_021E8624 0x021E8624 thumb ov093
 *   gSandRushHandlers     0x021F0950  data   ov093  a4
 */
#include "unit_021DBAF0_types.h"

extern int BTL_EVENT_GetVar(int key);
extern struct BtlPokeParam *func_021C7CF4(struct BtlServerFlow *flow, int pokeId);
extern int BTL_POKEPARAM_IsFainted(struct BtlPokeParam *bpp);
extern int BTL_POKEPARAM_IsHpFull(struct BtlPokeParam *bpp);
extern int BTL_CALC_DivideMaxHpMin1(struct BtlPokeParam *bpp, u32 divisor);
extern int func_021D59B4(struct BtlPokeParam *bpp, int valueId);
extern void *func_021C88A4(struct BtlServerFlow *flow, int cmdKind, int pokeId);
extern void func_021C88C8(struct BtlServerFlow *flow, void *cmd);
extern int func_021C8288(struct BtlServerFlow *flow);
extern void BTL_EVENT_MultiplyVar(int key, int ratio);
extern int BTL_EVENT_OverwriteVar(int key, unsigned int value);
extern int func_0689C8CC(u16 moveId);
extern int func_021E8624(struct BtlServerFlow *flow, int pokeId);
/* The indirect damage guard pair shared with the other guards (cause, then message). */
extern void BTL_ABILITY_BlockIndirectDamage(struct BtlServerFlow *flow, int pokeId, int *work, int blockedCause);
extern void BTL_ABILITY_ShowIndirectGuardMessage(struct BtlServerFlow *flow, int pokeId, int *work, int stringId);
void func_021DC57C(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
int *func_021DC5EC(int *handlerCount);
int *func_021DC5F8(int *handlerCount);
void func_021DC604(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, int *work);
void func_021DC614(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, int *work);
int *func_021DC624(int *handlerCount);
void func_021DC630(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
void *func_021DC658(int *handlerCount);
void func_021DC664(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
void *func_021DC694(int *handlerCount);
void func_021DC6A0(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
extern int gRegeneratorHandlers[];
extern int gIndirectGuardCause2Handlers[];
extern unsigned char gWonderSkinHandlers[];
extern unsigned char gAnalyticHandlers[];
extern int gSandRushHandlers[];

/*
 * Regenerator: when the owner leaves the field, it recovers a third of its
 * hit points (at most what it lacks). Two live calls with no free saved
 * register put the first result on the stack.
 */
void func_021DC57C(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    struct BtlPokeParam *owner;
    u32 recoverAmount, missingHp;
    BtlRegenerateHpCmd *cmd;

    if (ownerId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    owner = func_021C7CF4(flow, ownerId);
    if (BTL_POKEPARAM_IsFainted(owner) != 0)
        return;
    if (BTL_POKEPARAM_IsHpFull(owner) != 0)
        return;
    recoverAmount = BTL_CALC_DivideMaxHpMin1(owner, 3);
    missingHp = func_021D59B4(owner, BTL_POKEPARAM_VALUE_MAX_HP) - func_021D59B4(owner, BTL_POKEPARAM_VALUE_HP);
    if (recoverAmount > missingHp)
        recoverAmount = missingHp;
    cmd = func_021C88A4(flow, BTL_CMD_KIND_REGENERATE_HP, ownerId);
    cmd->pokeId = ownerId;
    cmd->amount = recoverAmount;
    cmd->mode = 1;
    cmd->showBar = 1;
    func_021C88C8(flow, cmd);
}

int *func_021DC5EC(int *handlerCount)
{
    *handlerCount = 1;
    return gRegeneratorHandlers;
}

int *func_021DC5F8(int *handlerCount)
{
    *handlerCount = 2;
    return gIndirectGuardCause2Handlers;
}

/* Indirect damage guard of cause 2: blocks the damage (same family as cause 1, 6 and 8). */
void func_021DC604(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, int *work)
{
    BTL_ABILITY_BlockIndirectDamage(flow, ownerId, work, 0x2);
}

/* Indirect damage guard of cause 2: shows its message. */
void func_021DC614(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, int *work)
{
    BTL_ABILITY_ShowIndirectGuardMessage(flow, ownerId, work, 0xcc);
}

int *func_021DC624(int *handlerCount)
{
    *handlerCount = 2;
    return gSandRushHandlers;
}

/* Sand Rush: in a sandstorm the speed of the owner doubles. */
void func_021DC630(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && func_021C8288(flow) == BTL_WEATHER_SAND)
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_2_0);
}

void *func_021DC658(int *handlerCount) { *handlerCount = 1; return gWonderSkinHandlers; }

/* Wonder Skin: the accuracy of a status move against the owner is at most 50. */
void func_021DC664(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)
        && BTL_EVENT_GetVar(BTL_EVAR_DAMAGE_TYPE) == BTL_DAMAGE_TYPE_STATUS
        && (unsigned int)BTL_EVENT_GetVar(BTL_EVAR_ACCURACY) > 50)
        BTL_EVENT_OverwriteVar(BTL_EVAR_ACCURACY, 50);
}

void *func_021DC694(int *handlerCount) { *handlerCount = 1; return gAnalyticHandlers; }

/* Analytic: when every other Pokemon has already moved, the power of the owner is 1.3 times. */
void func_021DC6A0(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)
        && func_0689C8CC(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == 0
        && func_021E8624(flow, ownerId) != 0)
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_RATIO_1_3);
}
