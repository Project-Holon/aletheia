#ifndef HAND_WAZA_021E700C_TYPES_H
#define HAND_WAZA_021E700C_TYPES_H
/*
 * ov093 move effect handlers, second part (Hex to Round): moves whose power
 * depends on weight, speed, stat stages or history, the type and ability
 * changers, forced switches, Wonder Room, Magic Room, Autotomize and the
 * turn order moves.
 *
 * A getter returns the handler table of one move ({event id, handler} rows)
 * and stores the row count. A handler answers one battle event. To act on the
 * battle, it asks the flow for a record of one kind, fills the fields of that
 * kind and commits it. Every record starts with a 32-bit header.
 */
#include "hand_common_types.h"

struct BtlServerFlow;
struct BtlPokeParam;

/* Message string types of BTL_SERVER_FLOW_InitMsgRecord. */
#define HAND_WAZA_STR_STANDARD 1
#define HAND_WAZA_STR_SET 2

/* Record kinds written by these handlers. */
#define HAND_WAZA_KIND_MESSAGE 4
#define HAND_WAZA_KIND_DAMAGE 7
#define HAND_WAZA_KIND_CURE_SICK 0xb
#define HAND_WAZA_KIND_ADD_SICK 0xc
#define HAND_WAZA_KIND_RANK_CHANGE 0xe
#define HAND_WAZA_KIND_RESET_RANKS 0x10
#define HAND_WAZA_KIND_CHANGE_TYPE 0x14
#define HAND_WAZA_KIND_ADD_FIELD_EFFECT 0x1b
#define HAND_WAZA_KIND_REMOVE_FIELD_EFFECT 0x1c
#define HAND_WAZA_KIND_SET_ABILITY 0x1f
#define HAND_WAZA_KIND_SET_ITEM 0x20
#define HAND_WAZA_KIND_LOSE_WEIGHT 0x2d
#define HAND_WAZA_KIND_FORCE_SWITCH 0x2e
#define HAND_WAZA_KIND_MOVE_NEXT 0x2f
#define HAND_WAZA_KIND_ROUND_USED 0x30
#define HAND_WAZA_KIND_MOVE_LAST 0x31
#define HAND_WAZA_KIND_DROP_FROM_SKY 0x36

/* Event ids of the handler table rows. */
#define HAND_WAZA_EVENT_PREPARE_MOVE 0x24
#define HAND_WAZA_EVENT_NO_EFFECT_CHECK 0x2c
#define HAND_WAZA_EVENT_EVASION_STAGE 0x33
#define HAND_WAZA_EVENT_GET_MOVE_POWER 0x37
#define HAND_WAZA_EVENT_REVENGE_POWER 0x38
#define HAND_WAZA_EVENT_ATTACK_STAT_SOURCE 0x39
#define HAND_WAZA_EVENT_DEFENSE_STAT 0x3a
#define HAND_WAZA_EVENT_CALC_FIXED_DAMAGE 0x46
#define HAND_WAZA_EVENT_AFTER_DAMAGE 0x4b
#define HAND_WAZA_EVENT_AUTOTOMIZE 0x5e
#define HAND_WAZA_EVENT_ADD_EFFECT 0x83
#define HAND_WAZA_EVENT_FIELD_EFFECT_MOVE 0x9e
#define HAND_WAZA_EVENT_MOVE_EFFECT 0xa0

/* Event variable keys that BTL_EVAR_* in hand_common_types.h does not name. */
#define HAND_WAZA_EVAR_BASE_POWER 0x30
#define HAND_WAZA_EVAR_FIXED_DAMAGE 0x37
#define HAND_WAZA_EVAR_ATTACK_STAT_SOURCE_ID 0x3b /* Pokemon whose Attack the damage formula reads */
#define HAND_WAZA_EVAR_DEFENSE_STAT_KIND 0x3c     /* 0xb when the formula reads the special defense stat (guess) */
#define HAND_WAZA_EVAR_DEFENSE_STAT_STEP 0x3d     /* index step toward the other defense stat (guess) */
#define HAND_WAZA_EVAR_IGNORE_EVASION_FLAG 0x4b   /* same slot as the immunity override flag */
#define HAND_WAZA_EVAR_IGNORE_STAGES_FLAG 0x51    /* same slot as the force floating flag */
#define HAND_WAZA_EVAR_TARGET_ID 6                /* first target of the move */

/* Status ids (sick kinds) these moves look at or add. */
#define HAND_WAZA_SICK_MAGNET_RISE 0x1e
#define HAND_WAZA_SICK_SMACKED_DOWN 0x1f
#define HAND_WAZA_SICK_TELEKINESIS 0x20
#define HAND_WAZA_SICK_GROUND_GUARD 0x21 /* guess */

/* Stat stage kinds of the rank change record (same numbering as the stat stage value ids of the Pokemon getter). */
#define HAND_WAZA_RANK_ATTACK 1
#define HAND_WAZA_RANK_DEFENSE 2
#define HAND_WAZA_RANK_SP_ATTACK 3
#define HAND_WAZA_RANK_SP_DEFENSE 4
#define HAND_WAZA_RANK_SPEED 5

/* Condition flag of a Pokemon that is up in the air (Fly, Bounce). */
#define HAND_WAZA_CONT_FLAG_FLYING 3

/* Field effect ids of the Wonder Room and Magic Room records. */
#define HAND_WAZA_FIELD_WONDER_ROOM 6
#define HAND_WAZA_FIELD_MAGIC_ROOM 7

/* Handler signature: factor, battle flow, id of the Pokemon that owns the handler, handler work. */
typedef void (*HandWazaHandlerFunc)(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);

/* Kind 7: damage a Pokemon (a fraction of its maximum HP) and show a message. */
struct HandWazaCmdDamage {
    u32 header;
    u16 amount;
    u8 pokeId;
    u8 noMoveHitEffect : 1; /* guess: the damage is shown without the hit effect of a move */
    u8 flagsRest : 7;
    u32 pad08;
    BtlStrParam message;
};

/* Kind 0xe: change a stat stage of one Pokemon. */
struct HandWazaCmdRankChange {
    u32 header;
    u32 rankKind;
    u32 serialNumber;
    s8 volume;
    u8 pad0D;
    u8 showMessage;
    u8 pokeCount;
    u8 pokeId;
};

/* Kind 0x10: reset all stat stages of a Pokemon. */
struct HandWazaCmdResetRanks {
    u32 header;
    u8 resetKind;
    u8 pokeId;
};

/* Kind 0x14: set the type pair of a Pokemon (both types packed in a halfword). */
struct HandWazaCmdChangeType {
    u32 header;
    u16 typePair;
    u8 pokeId;
    u8 showMessage;
};

/* Kind 0x1b: start a field effect (duration, then a message). */
struct HandWazaCmdAddFieldEffect {
    u32 header;
    u32 effectId;
    union SickCont cont;
    u32 pad0C;
    BtlStrParam message;
};

/* Kind 0x1c: end a field effect. */
struct HandWazaCmdRemoveFieldEffect {
    u32 header;
    u32 effectId;
};

/* Kind 0x1f: set the ability of a Pokemon and show a message. */
struct HandWazaCmdSetAbility {
    u32 header;
    u16 abilityId;
    u8 pokeId;
    u8 pad07;
    u32 pad08;
    BtlStrParam message;
};

/* Kind 0x20: set (or with item 0 remove) the held item of a Pokemon and show a message. */
struct HandWazaCmdSetItem {
    u32 header;
    u16 itemId;
    u8 pokeId;
    u8 pad07;
    u32 pad08;
    BtlStrParam message;
};

/* Kind 0x2d: set the weight of a Pokemon (in tenths of a kilogram) after it lost weight, and show a message. */
struct HandWazaCmdLoseWeight {
    u32 header;
    u8 pokeId;
    u8 pad05;
    u16 newWeight;
    BtlStrParam message;
};

/* Kind 0x2e: force a Pokemon out of the battle (the next Pokemon of its party comes in). */
struct HandWazaCmdForceSwitch {
    u32 header;
    u16 strId;
    u8 pokeId;
};

/* Kinds 0x2f and 0x31: change the turn order for a Pokemon and show a message. */
struct HandWazaCmdTurnOrder {
    u32 header;
    u8 pokeId;
    u8 pad05[3];
    BtlStrParam message;
};

/* Kind 0x30: tell the flow that a move of this factor was used (Round). */
struct HandWazaCmdRoundUsed {
    u32 header;
    u16 factorKey;
};

/* Kind 0x36: bring a Pokemon down from the sky (clears the flying state), optionally with a message. */
struct HandWazaCmdDropFromSky {
    u32 header;
    u8 pokeId;
    u8 pad05[3];
    u32 flyingFlag;
    BtlStrParam message;
};

#endif
