/*
 * file:     btl_action_word.c
 * unit:     yes
 * function: BTL_ACTION_SetFight, BTL_ACTION_SetFightTarget, BTL_ACTION_SetFightSlotFlag, BTL_ACTION_GetFightSlotFlag, BTL_ACTION_GetFightMove, BTL_ACTION_SetItem, BTL_ACTION_SetChange, BTL_ACTION_SetChangeDepleted, BTL_ACTION_IsChangeDepleted, BTL_ACTION_SetRotate, BTL_ACTION_SetEscape, BTL_ACTION_SetSkip, BTL_ACTION_SetNone, BTL_ACTION_SetForcedSkip, BTL_ACTION_GetKind, BTL_ACTION_SetRecordReset, BTL_ACTION_SetRecordError
 * address:  0x021D82D0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from btl_calc.c, btl_action_word.c, hand_tokusei.c by tools/splitfile.py.
 *
 * symbols:
 */
#include "btl_calc_types.h"

/*
 * stand-in: the three bit-built actions below (item, forced change, rotate)
 * keep the original's and/or sequence on a local of enum type. A bitfield
 * local, a zeroed union and a u32 local all compile differently (mwcc folds
 * the zero start into constants). Only the enum local gives the original bytes.
 */
typedef enum { ACTION_BITS_ZERO = 0 } ActionBits;

void BTL_ACTION_SetFight(union BtlAction *action, u32 moveId, u32 targetPos);

void BTL_ACTION_SetFightTarget(union BtlAction *action, int targetPos);

void BTL_ACTION_SetFightSlotFlag(union BtlAction *action);

u32 BTL_ACTION_GetFightSlotFlag(union BtlAction *action);

u32 BTL_ACTION_GetFightMove(union BtlAction *action);

void BTL_ACTION_SetItem(union BtlAction *action,u32 itemId,u32 targetIndex,u32 itemParam);

void BTL_ACTION_SetChange(union BtlAction *action,u32 posIndex,u32 memberIndex);

void BTL_ACTION_SetChangeDepleted(union BtlAction *action);

int BTL_ACTION_IsChangeDepleted(union BtlAction *action);

void BTL_ACTION_SetRotate(union BtlAction *action,u32 direction);

void BTL_ACTION_SetEscape(union BtlAction *action);

void BTL_ACTION_SetSkip(union BtlAction *action);

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

/* The move id of a fight action, else 0. */
u32 BTL_ACTION_GetFightMove(union BtlAction *action) { if(action->head.kind==1) return (u16)action->fight.moveId; return 0; }

/* Makes an item action: the item, the target index and one parameter byte. */
void BTL_ACTION_SetItem(union BtlAction *action,u32 itemId,u32 targetIndex,u32 itemParam)
{
    ActionBits bits=ACTION_BITS_ZERO;
    bits &=~15;
    bits |=2;
    bits &=~0x7fff80;
    bits |=(u16)itemId<<7;
    bits &=~0x70;
    bits |=(targetIndex&7)<<4;
    bits &=~0x7f800000;
    bits |=(itemParam&255)<<23;
    action->raw=bits;
}

/* Makes a change action: the position and the party member to send in. */
void BTL_ACTION_SetChange(union BtlAction *action,u32 posIndex,u32 memberIndex) { union BtlAction built={0}; built.change.kind=3; built.change.posIndex=posIndex; built.change.memberIndex=memberIndex; built.change.depleted=0; *action=built; }

/* Makes a change action with no member chosen yet, flagged as forced by a fainted Pokemon. */
void BTL_ACTION_SetChangeDepleted(union BtlAction *action)
{
    ActionBits bits=ACTION_BITS_ZERO;
    bits &=~15;
    bits |=3;
    bits &=~0x380;
    bits |=0x400;
    action->raw=bits;
}

/* True for a change action that a fainted Pokemon forced. */
int BTL_ACTION_IsChangeDepleted(union BtlAction *action) { if(action->head.kind==3 && action->change.depleted==1) return 1; return 0; }

/*
 * Makes a rotate action with the given direction.
 * follower: Existing pkt_ov093_021D8414 covers 021D8414 and 021D8424.
 */
void BTL_ACTION_SetRotate(union BtlAction *action,u32 direction)
{
    ActionBits bits=ACTION_BITS_ZERO;
    bits &=~15;
    bits |=6;
    bits &=~0x70;
    bits |=(direction&7)<<4;
    action->raw=bits;
}

/*
 * Sets the kind of an action to escape, keeping the other bits.
 * follower: 0x021D8424 is a 14-byte read-modify-write and return leaf with two padding bytes.
 */
void BTL_ACTION_SetEscape(union BtlAction *action)
{
    action->raw = (action->raw & ~15) | 4;
}

/* Sets the kind of an action to skip, keeping the other bits. */
void BTL_ACTION_SetSkip(union BtlAction *action)
{
    action->raw = (action->raw & ~15) | 5;
}

typedef enum { MASK=15 } Mask;

void BTL_ACTION_SetNone(u32 *action);

void BTL_ACTION_SetForcedSkip(u32 *action);

unsigned int BTL_ACTION_GetKind(union BtlAction *action);

void BTL_ACTION_SetRecordReset(u32 *action);

void BTL_ACTION_SetRecordError(u32 *action);

/*
 * The setters below write only the kind nibble of an action word.
 * stand-in: ActionSetNone clears the nibble and then masks with an enum
 * constant (a clear and a mask that contradict each other); the mask-first
 * order in the last AND selects the original register.
 */
void BTL_ACTION_SetNone(u32 *action) { Mask mask=MASK; *action=mask & (*action & ~15); }

void BTL_ACTION_SetForcedSkip(u32 *action) { *action = (*action & ~15) | BTL_ACTION_KIND_FORCED_SKIP; }

unsigned int BTL_ACTION_GetKind(union BtlAction *action)
{
    return action->head.kind;
}

void BTL_ACTION_SetRecordReset(u32 *action) { *action = ((*action & ~15) | BTL_ACTION_KIND_RECORD_RESET) & 15; }

void BTL_ACTION_SetRecordError(u32 *action) { *action = ((*action & ~15) | BTL_ACTION_KIND_RECORD_ERROR) & 15; }
