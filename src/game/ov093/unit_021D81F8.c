/*
 * file:     unit_021D81F8.c
 * unit:     yes
 * function: BTL_CALC_PeekMoveTarget, BTL_CLIENT_SET_Clear, BTL_CLIENT_SET_Add, BTL_CLIENT_SET_GetCount, BTL_CLIENT_SET_JudgeResult, BTL_ACTION_SetFight, BTL_ACTION_SetFightTarget
 * address:  0x021D81F8
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
 *   d_021F6368 0x021F6368 data a4
 *   BTL_CALC_DecideMoveTarget 0x021D80BC thumb ov093
 *   BTL_MAIN_IsSameTeamClient  0x021B902C  thumb
 *   gBtlCalcWork  0x021F6360  data
 */
#include "btl_calc_types.h"
#include "unit_021D794C_types.h"
#include "btl_main_types.h"

struct BtlPokeParam;

extern int BTL_CALC_DecideMoveTarget(void *main, void *posTable, struct BtlPokeParam *attacker, u16 moveId);
extern int BTL_MAIN_IsSameTeamClient(int clientId, int otherClientId);
extern struct BtlCalcWork gBtlCalcWork;
int BTL_CALC_PeekMoveTarget(void *main, void *posTable, struct BtlPokeParam *attacker, u16 moveId, BtlRngState *savedRng);
void BTL_CLIENT_SET_Clear(struct BtlClientSet *set);
void BTL_CLIENT_SET_Add(struct BtlClientSet *set, int clientId);
u32 BTL_CLIENT_SET_GetCount(struct BtlClientSet *set);
int BTL_CLIENT_SET_JudgeResult(struct BtlClientSet *set, u8 localClientId, u32 rule);
void BTL_ACTION_SetFight(union BtlAction *action, u32 moveId, u32 targetPos);
void BTL_ACTION_SetFightTarget(union BtlAction *action, int targetPos);
void BTL_ACTION_SetFightSlotFlag(union BtlAction *action);
u32 BTL_ACTION_GetFightSlotFlag(union BtlAction *action);


/*
 * Picks a move's target like BTL_CALC_DecideMoveTarget, then puts the random number
 * state back, so the pick does not advance the battle's random numbers.
 * savedRng receives the state before the pick and is copied back afterwards.
 */
int BTL_CALC_PeekMoveTarget(void *main, void *posTable, struct BtlPokeParam *attacker, u16 moveId, BtlRngState *savedRng)
{
    int targetPos;

    *savedRng = gBtlCalcWork.rng;
    targetPos = BTL_CALC_DecideMoveTarget(main, posTable, attacker, moveId);
    gBtlCalcWork.rng = *savedRng;
    return targetPos;
}



/* Empties a set of client ids. */
void BTL_CLIENT_SET_Clear(struct BtlClientSet *set) { u32 index; for(index=0;index<4;index++) set->ids[index]=BTL_CLIENT_ID_NONE; set->count=0; }



/* Adds a client id to the set unless it is already there. */
void BTL_CLIENT_SET_Add(struct BtlClientSet *set, int clientId) { u32 index; for(index=0;index<4;index++) { if(set->ids[index]==clientId) return; if(set->ids[index]==BTL_CLIENT_ID_NONE) { set->ids[index]=clientId; ++set->count; return; } } }




/* 021D826C  ldr r0,[r0] */
/*
 * Number of clients in the set (the u32 field at offset 0).
 */
u32 BTL_CLIENT_SET_GetCount(struct BtlClientSet *set) { return set->count; }



/*
 * Result code from the set of defeated clients, as seen by the local client:
 * 3 when only its own team is in the set, 4 when only the other team is,
 * and for a mix 3 in single and double battles, else 2.
 */
int BTL_CLIENT_SET_JudgeResult(struct BtlClientSet *set, u8 localClientId, u32 rule)
{
    int foeDefeated = 0;
    int friendDefeated = 0;
    u32 index;
    for (index = 0; index < set->count; index++) {
        if (BTL_MAIN_IsSameTeamClient(set->ids[index], localClientId))
            friendDefeated = 1;
        else
            foeDefeated = 1;
    }
    if (friendDefeated && foeDefeated) {
        if (rule <= 1)
            return 3;
        return 2;
    }
    return friendDefeated ? 3 : 4;
}




/* Makes a fight action: the move and the target position. */
void BTL_ACTION_SetFight(union BtlAction *action, u32 moveId, u32 targetPos)
{
    union BtlAction built = {0};
    built.fight.kind = 1;
    built.fight.targetPos = targetPos;
    built.fight.moveId = moveId;
    *action = built;
}




/*
 * Three accessors on the fight action of BTL_ACTION_SetFight: set the target
 * position (unless 6, no target), set the slot flag, read the slot flag.
 */
void BTL_ACTION_SetFightTarget(union BtlAction *action, int targetPos)
{
    if (action->head.kind == 1) {
        if (targetPos != 6)
            action->fight.targetPos = targetPos;
    }
}




void BTL_ACTION_SetFightSlotFlag(union BtlAction *action)
{
    if (action->head.kind == 1)
        action->fight.slotFlag = 1;
}




u32 BTL_ACTION_GetFightSlotFlag(union BtlAction *action)
{
    if (action->head.kind == 1)
        return action->fight.slotFlag;
    return 0;
}
