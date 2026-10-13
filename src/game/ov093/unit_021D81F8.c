/*
 * file:     unit_021D81F8.c
 * unit:     yes
 * function: func_021D81F8, func_021D8230, func_021D8244, func_021D826C, func_021D8270, func_021D82D0, func_021D82FC
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
 *   func_021D80BC 0x021D80BC thumb ov093
 *   func_021B902C  0x021B902C  thumb
 */
#include "btl_calc_types.h"
#include "unit_021D794C_types.h"
#include "btl_main_types.h"

struct BtlPokeParam;

extern int func_021D80BC(void *main, void *posTable, struct BtlPokeParam *attacker, u16 moveId);
extern int func_021B902C(int clientId, int otherClientId);
extern struct BtlCalcWork data_021F6360;
int func_021D81F8(void *main, void *posTable, struct BtlPokeParam *attacker, u16 moveId, BtlRngState *savedRng);
void func_021D8230(struct BtlClientSet *set);
void func_021D8244(struct BtlClientSet *set, int clientId);
u32 func_021D826C(struct BtlClientSet *set);
int func_021D8270(struct BtlClientSet *set, u8 localClientId, u32 rule);
void func_021D82D0(union BtlAction *action, u32 moveId, u32 targetPos);
void func_021D82FC(union BtlAction *action, int targetPos);
void func_021D8318(union BtlAction *action);
u32 func_021D832C(union BtlAction *action);


/*
 * Picks a move's target like func_021D80BC, then puts the random number
 * state back, so the pick does not advance the battle's random numbers.
 * savedRng receives the state before the pick and is copied back afterwards.
 */
int func_021D81F8(void *main, void *posTable, struct BtlPokeParam *attacker, u16 moveId, BtlRngState *savedRng)
{
    int targetPos;

    *savedRng = data_021F6360.rng;
    targetPos = func_021D80BC(main, posTable, attacker, moveId);
    data_021F6360.rng = *savedRng;
    return targetPos;
}



/* Empties a set of client ids. */
void func_021D8230(struct BtlClientSet *set) { u32 index; for(index=0;index<4;index++) set->ids[index]=BTL_CLIENT_ID_NONE; set->count=0; }



/* Adds a client id to the set unless it is already there. */
void func_021D8244(struct BtlClientSet *set, int clientId) { u32 index; for(index=0;index<4;index++) { if(set->ids[index]==clientId) return; if(set->ids[index]==BTL_CLIENT_ID_NONE) { set->ids[index]=clientId; ++set->count; return; } } }




/* 021D826C  ldr r0,[r0] */
/*
 * Number of clients in the set (the u32 field at offset 0).
 */
u32 func_021D826C(struct BtlClientSet *set) { return set->count; }



/*
 * Result code from the set of defeated clients, as seen by the local client:
 * 3 when only its own team is in the set, 4 when only the other team is,
 * and for a mix 3 in single and double battles, else 2.
 */
int func_021D8270(struct BtlClientSet *set, u8 localClientId, u32 rule)
{
    int foeDefeated = 0;
    int friendDefeated = 0;
    u32 index;
    for (index = 0; index < set->count; index++) {
        if (func_021B902C(set->ids[index], localClientId))
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
void func_021D82D0(union BtlAction *action, u32 moveId, u32 targetPos)
{
    union BtlAction built = {0};
    built.fight.kind = 1;
    built.fight.targetPos = targetPos;
    built.fight.moveId = moveId;
    *action = built;
}




/*
 * Three accessors on the fight action of func_021D82D0: set the target
 * position (unless 6, no target), set the slot flag, read the slot flag.
 */
void func_021D82FC(union BtlAction *action, int targetPos)
{
    if (action->head.kind == 1) {
        if (targetPos != 6)
            action->fight.targetPos = targetPos;
    }
}




void func_021D8318(union BtlAction *action)
{
    if (action->head.kind == 1)
        action->fight.slotFlag = 1;
}




u32 func_021D832C(union BtlAction *action)
{
    if (action->head.kind == 1)
        return action->fight.slotFlag;
    return 0;
}
