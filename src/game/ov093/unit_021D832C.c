/*
 * file:     unit_021D832C.c
 * unit:     yes
 * function: func_021D8340, func_021D8358, func_021D8394, func_021D83C4, func_021D83E0, func_021D83FC, func_021D8414
 * address:  0x021D8340
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "unit_021D794C_types.h"

/*
 * stand-in: the three bit-built actions below (item, forced change, rotate)
 * keep the original's and/or sequence on a local of enum type. A bitfield
 * local, a zeroed union and a u32 local all compile differently (mwcc folds
 * the zero start into constants). Only the enum local gives the original bytes.
 */
typedef enum { ACTION_BITS_ZERO = 0 } ActionBits;

u32 func_021D8340(union BtlAction *action);
void func_021D8358(union BtlAction *action, u32 itemId, u32 targetIndex, u32 itemParam);
void func_021D8394(union BtlAction *action, u32 posIndex, u32 memberIndex);
void func_021D83C4(union BtlAction *action);
int func_021D83E0(union BtlAction *action);
void func_021D83FC(union BtlAction *action, u32 direction);
void func_021D8414(union BtlAction *action);
void func_021D8424(union BtlAction *action);


/* The move id of a fight action, else 0. */
u32 func_021D8340(union BtlAction *action) { if(action->head.kind==1) return (u16)action->fight.moveId; return 0; }



/* Makes an item action: the item, the target index and one parameter byte. */
void func_021D8358(union BtlAction *action,u32 itemId,u32 targetIndex,u32 itemParam)
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
void func_021D8394(union BtlAction *action,u32 posIndex,u32 memberIndex) { union BtlAction built={0}; built.change.kind=3; built.change.posIndex=posIndex; built.change.memberIndex=memberIndex; built.change.depleted=0; *action=built; }


/* Makes a change action with no member chosen yet, flagged as forced by a fainted Pokemon. */
void func_021D83C4(union BtlAction *action)
{
    ActionBits bits=ACTION_BITS_ZERO;
    bits &=~15;
    bits |=3;
    bits &=~0x380;
    bits |=0x400;
    action->raw=bits;
}


/* True for a change action that a fainted Pokemon forced. */
int func_021D83E0(union BtlAction *action) { if(action->head.kind==3 && action->change.depleted==1) return 1; return 0; }


/*
 * Makes a rotate action with the given direction.
 * follower: Existing pkt_ov093_021D8414 covers 021D8414 and 021D8424.
 */
void func_021D83FC(union BtlAction *action,u32 direction)
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
void func_021D8414(union BtlAction *action)
{
    action->raw = (action->raw & ~15) | 4;
}


/* Sets the kind of an action to skip, keeping the other bits. */
void func_021D8424(union BtlAction *action)
{
    action->raw = (action->raw & ~15) | 5;
}
