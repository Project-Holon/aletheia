#ifndef HAND_WAZA_021E0518_TYPES_H
#define HAND_WAZA_021E0518_TYPES_H
#include "../ov093/hand_common_types.h"
#include "../ov093/hand_common_protos.h"
/*
 * ov093 move effect handlers (HAND_WAZA_), first part: the handlers of
 * Camouflage, Trick Room, Gravity, Water Sport, Mud Sport, Defog, Brick
 * Break, Jump Kick, Mimic, Sketch, Follow Me, Refresh, the trapping moves,
 * Haze, Splash, Curse, Thunder Wave, Worry Seed, Dream Eater and Captivate.
 *
 * Each move has a getter that returns its handler table (event id plus
 * function) and writes the number of entries. The move registry
 * (0x021F3030, 0x102 rows of {move id, getter}) is searched by move id when a
 * Pokemon uses the move; the handlers then answer battle events and queue
 * command records on the battle flow.
 */
#include "../ov093/btl_event_types.h"
#include "../ov093/btl_action_word_types.h"
#include "../ov093/hand_tokusei_types.h"
#include "../ov093/btl_pokeparam_types.h"
#include "../ov093/hand_item_021dd588_types.h"
#include "../ov093/btl_calc_types.h"

/* Event variable keys that these handlers read or write (more are in btl_action_word_types.h). */

/* Command kinds that these handlers queue (pushed with BTL_SERVER_FLOW_AllocCmdRecord, kinds without record with BTL_SERVER_FLOW_PushCmdRecord). */

#define BTL_CMD_KIND_DAMAGE 7

#define BTL_CMD_KIND_HP_DELTA 8




#define BTL_CMD_KIND_RESET_RANKS 0x10


#define BTL_CMD_KIND_REMOVE_SIDE_EFFECTS 0x1a

#define BTL_CMD_KIND_ADD_FIELD_EFFECT 0x1b

#define BTL_CMD_KIND_REMOVE_FIELD_EFFECT 0x1c

#define BTL_CMD_KIND_CHANGE_ABILITY 0x1f

#define BTL_CMD_KIND_REPLACE_MOVE 0x25

#define BTL_CMD_KIND_APPLY_GRAVITY 0x35 /* guess: grounds the Pokemon that were in the air */

#define BTL_CMD_KIND_SIDE_EFFECTS_REMOVED 0x3a

/* Slot of the factor work words that move handlers share. */
#define HAND_WORK_ACTIVATED 6 /* set once the move took effect; unset factors are cleaned up by the event module */

/* Header flag of the HP delta command (guess: the loss is not a hit). */
#define BTL_CMD_FLAG_SELF_INFLICTED (1u << 24)

/* Message string types. */
#define BTL_STR_TYPE_PLAIN 1

#define BTL_STR_TYPE_POKE_NAME 2 /* arguments are Pokemon or move ids */

/* Field effect ids (what the add and remove commands and the active check use). */
#define BTL_FIELD_EFFECT_TRICK_ROOM 1

#define BTL_FIELD_EFFECT_GRAVITY 2

#define BTL_FIELD_EFFECT_WATER_SPORT 4

#define BTL_FIELD_EFFECT_MUD_SPORT 5

/* Factor types of the event factor list (the registry of a move adds type 0). */
#define BTL_EVENT_TYPE_MOVE 0

#define BTL_EVENT_TYPE_SIDE_EFFECT 2

/* Side effect ids (bit numbers of the side effect set). */







/* Rule ids of the battle (single, double, triple, rotation). */


/* Move ids that the handlers compare against. */

#define BTL_MOVE_SKETCH 166

#define BTL_MOVE_CHATTER 448

#define BTL_MOVE_SKY_DROP 0x1fb

/* Failure reason shown when Follow Me is used outside a multi battle (guess). */
#define BTL_FAIL_REASON_NEEDS_MULTI_BATTLE 26

/* Status ids. */
#define BTL_SICK_NO_ESCAPE 0x16 /* set by the trapping moves */

#define BTL_SICK_CURSE 10

#define BTL_SICK_BLOCKS_REDIRECT 0x21 /* guess: a holder with this status is not redirected to */

/* Stat ids of the rank commands. */


#define BTL_RANK_EVASION 7

/* Pokemon type ids (a dense list; some are in btl_action_word_types.h). */




/* Value ids of the Pokemon value getter that these handlers read. */
#define BPP_VALUE_ABILITY_ID 0x11

#define BPP_VALUE_HP 0xd /* current hit points (guess) */

/* Ability ids that Worry Seed checks. */
#define BTL_ABILITY_TRUANT 0x36

#define BTL_ABILITY_INSOMNIA 0xf

/* Kind 0xe: change a stat stage; volume is signed (the stage count, negative lowers). */
typedef struct {
    u32 header;
    u32 rankKind;
    u8 pad08[4];
    s8 volume;
    u8 flagA;
    u8 flagB;
    u8 pokeCount;
    u8 pokeId;
} BtlRankEffectCmd;

/* Kind 8: change the hit points of a Pokemon by a signed amount (negative loses). */
typedef struct {
    u32 header;
    u8 mode;
    u8 pad05[2];
    u8 pokeId;
    u8 pad08[8];
    s32 delta;
} BtlHpDeltaCmd;

/* Kind 0xc with a message at +0x14: add a status condition and tell the player. */
typedef struct {
    u32 header;
    u32 sickKind;
    union SickCont cont;
    u8 suppressMessage;
    u8 pad0D[2];
    u8 pokeId;
    u8 pad10[4];
    BtlStrParam message;
} BtlAddSickMessageCmd;

/* Kind 0x10: reset the stat stages of the listed Pokemon. */
typedef struct {
    u32 header;
    u8 pokeCount;
    u8 pokeIds[6];
} BtlResetRanksCmd;

/*
 * Kind 0x1a: remove side effects. The handlers fill it as a small byte array
 * (a plain struct would let the compiler keep the first byte in a register).
 */
typedef struct {
    u32 header;
    u8 bytes[3]; /* [0] removal depth, [1] and [2] one bit per side effect */
    u8 sideId;
} BtlRemoveSideEffectsCmd;

/* Kind 0x1b: start a field effect (Trick Room, Gravity, the sports). */
typedef struct {
    u32 header;
    u32 effectId;
    union SickCont duration;
    u32 pad0C;
    BtlStrParam message;
} BtlFieldEffectAddCmd;

/* Kind 0x1c: end a field effect. */
typedef struct {
    u32 header;
    u32 effectId;
} BtlFieldEffectRemoveCmd;

/* Kind 0x25: put a move into a move slot of a Pokemon (Mimic and Sketch). */
typedef struct {
    u32 header;
    u8 pokeId;
    u8 slot;
    u8 fullPp;
    u8 permanent;
    u16 moveId;
} BtlReplaceMoveCmd;

/* Kind 0x3a: a one byte record. */
typedef struct {
    u32 header;
    u8 value;
} BtlByteCmd;

#include "../ov093/btl_server_flow.h"

#include "../ov093/btl_field.h"


#include "../ov093/btl_pokeparam.h"




#include "../ov093/btl_calc.h"


#include "../ov093/btl_event.h"



#include "../ov095/hand_side.h"

#include "../ov095/btl_id_sets.h"

/* Services of the battle flow and the Pokemon that these handlers use. */

struct BtlServerFlow;

/* Events that the handlers of these moves answer. */
#define HANDEVENT_ACTION_CHECK 0x1d       /* a status stops the Pokemon from acting (fail reason in 0x22) */

#define HANDEVENT_MOVE_FAIL_CHECK 0x1f    /* the move may fail (fail reason in 0x22) */

#define HANDEVENT_PREPARE_MOVE 0x24       /* the move is about to run */

#define HANDEVENT_MOVE_END 0x27           /* the move has finished */

#define HANDEVENT_DECIDE_TARGET 0x29      /* the target of the move is chosen */

#define HANDEVENT_NO_EFFECT_CHECK 0x2c    /* the move may have no effect on the target */

#define HANDEVENT_GET_MOVE_POWER 0x37     /* base power of the move */

#define HANDEVENT_CALC_FIXED_DAMAGE 0x46  /* the move may deal a fixed amount */

#define HANDEVENT_CALC_DAMAGE_RATIO 0x47  /* ratio applied to the damage */

#define HANDEVENT_ADD_SICK_MESSAGE 0x61   /* message that a status was added */

#define HANDEVENT_DECIDE_ADD_SICK 0x64    /* status, status data and chance of the extra effect */

#define HANDEVENT_ADD_EFFECT 0x83         /* extra effect after the damage */

#define HANDEVENT_CALC_HEAL_RATIO 0x8f    /* part of the maximum HP that a heal restores */

#define HANDEVENT_INVULNERABLE_CHECK 0x99 /* a move may hit a Pokemon that avoids it */

#define HANDEVENT_MOVE_EFFECT 0xa0        /* effect of a move that deals no damage */

/* More event variables. */
#define HANDVAR_EFFECT_TARGET_ID 6        /* Pokemon that an extra effect applies to */

#define HANDVAR_SEMI_INVULNERABLE 0x21    /* kind of semi-invulnerable state of the target */

#define HANDVAR_FAIL_REASON 0x22

#define HANDVAR_ADD_SICK_PERCENT 0x26     /* chance in percent of the extra status */

#define HANDVAR_BASE_POWER 0x30

#define HANDVAR_RATIO 0x35                /* 20.12 fixed point */

#define HANDVAR_FIXED_DAMAGE 0x37

#define HANDVAR_MESSAGE 0x3f              /* message record that the event fills */

#define HANDVAR_NO_EFFECT_FLAG 0x40

#define HANDVAR_AVOID_FLAG 0x42           /* the target avoids the move */

#define HANDVAR_EFFECT_BLOCKED 0x47       /* an ability blocks the extra effect */

#define BTL_FAIL_REASON_ASLEEP 2

#define BTL_FAIL_REASON_MOVE_FAILED 0x1a

#define BTL_SEMI_INVULNERABLE_UNDERWATER 4

#define BTL_POS_NONE 6

/* Status ids. */


#define BTL_SICK_TRAP 8                   /* Wrap, Bind, Fire Spin, ... */

/* Stat stage ids of a rank effect record. */


#define BTL_RANK_ACCURACY 6

/* Value ids of the Pokemon value getter. */

#define BPP_VALUE_LEVEL 15

/* Per-Pokemon counters (BtlPokeParam.counters). */
#define BPP_COUNTER_STOCKPILE 0

#define BPP_COUNTER_STOCKPILE_DEFENSE 1

#define BPP_COUNTER_STOCKPILE_SP_DEFENSE 2

/* Damage categories that Counter, Mirror Coat and Metal Burst react to; 0 is any. */
#define BTL_DAMAGE_TYPE_ANY 0



/* Record kinds. */
#define HANDEX_KIND_SET_COUNTER 0x26


/* The record applies only if the previous record had an effect (guess). */
#define HANDEX_FLAG_AFTER_SUCCESS (1u << 24)

/* Kind 0x2b: make a Pokemon flinch with a chance in percent. */
/* Services of the event variable stack. */

/* Services of the calculation code. */



/* Services of the battle server flow. */


#include "../arm9/waza_tool.h"





/* Services of the Pokemon parameter code. */

/* Event variable keys the move handlers read or write. */

/* Condition (sick) ids as the move handlers use them. */

#define BTL_SICK_MOVE_LOCK 0x19 /* locked into the move: Thrash, Uproar, Rollout */

#define BTL_SICK_AQUA_RING 0x23

/* Condition flag ids of the poke parameter (SetContFlag/TestContFlag). */
#define BTL_CONT_FLAG_DEFENSE_CURL 7


/* Turn flag ids of the poke parameter (TestTurnFlag). */
#define BTL_TURN_FLAG_MOVED 1           /* guess: the Pokemon has used its move this turn */

#define BTL_TURN_FLAG_ACTION_FINISHED 3 /* guess: its action is already over this turn */

/* Value ids of the poke parameter value getter. */
#define BTL_VALUE_SPEED 0xC



#define BTL_VALUE_LEVEL 0xF

/* Major status ids returned by BTL_POKEPARAM_GetMajorStatusIndex. */
#define BTL_MAJOR_STATUS_PARALYSIS 1

#define BTL_MAJOR_STATUS_BURN 4

#define BTL_MAJOR_STATUS_POISON 5

/* Pokemon type id that the move handlers test. */

/* Ratio in 20.12 fixed point: 0x1000 is 1.0. */

/* Message string types of BtlStrParam. */
#define HANDEX_STR_STD 1 /* standard message by id */


/* Record kinds that these handlers push. */




#define HANDEX_KIND_FAINT 0x13


/* Stat id of the rank record: attack. */

/*
 * Factor work areas of the moves that keep state (BtlEventFactor.work, seven
 * words). Slot 6 is the "active" word of every move that uses one.
 */
typedef struct HandWazaWork { /* Thrash family, Rollout family, Rage, Uproar, Triple Kick */
    s32 count;                /* Thrash: turns left; Rollout: hits so far; Triple Kick: hits so far */
    s32 limit;                /* Rollout: hit limit */
    s32 unused08[4];
    s32 active;               /* the lock or rage was set */
} HandWazaWork;

typedef struct HandWazaChargeWork {
    s32 phase;                    /* 1: charged, 2: the next move uses the charge */
    s32 unused04[5];
    s32 charged;
} HandWazaChargeWork;

/* Row of the Flail/Reversal power table: the largest HP ratio (in 48ths) and the power for it. */
typedef struct HandFlailRow {
    u16 maxRatio;
    u16 power;
} HandFlailRow;

/* Scratch list of Pokemon ids that the flow fills (count first). */
typedef struct HandPokeList {
    u8 count;
    u8 pokeIds[6];
} HandPokeList;

/* Target code that selects every Pokemon on the field when combined with a position (guess). */
#define BTL_TARGET_CODE_ALL_POKES 0x800

/* Services of the event variable stack and the event factors. */

/* Services of the battle flow. */

/* Events that the move handlers answer (the first word of a table pair). */
enum {
    BTL_EVENT_WAZA_TURN_END = 8,         /* the move factor's turn check (Snatch: effect used up) */
    BTL_EVENT_WAZA_NOTICE = 9,           /* Magic Coat: decide whether the bounce is announced */
    BTL_EVENT_WAZA_SNATCH_CHECK = 26,    /* Snatch: a move may be stolen */
    BTL_EVENT_WAZA_EXECUTE_CHECK = 31,   /* may the move be used (fail reason) */
    BTL_EVENT_WAZA_START = 36,           /* Magnitude: the roll before the hit */
    BTL_EVENT_WAZA_FINISH = 39,          /* after the move ended (Natural Gift: eat the berry) */
    BTL_EVENT_WAZA_TYPE_CHECK = 40,      /* move type decision */
    BTL_EVENT_WAZA_COUNTER = 45,         /* Magic Coat: bounce the move */
    BTL_EVENT_WAZA_VARIANT = 48,         /* Present: choose damage or heal */
    BTL_EVENT_WAZA_HEAL_EFFECT = 49,     /* Present: the heal branch */
    BTL_EVENT_HIT_CHECK = 50,            /* force the move to hit */
    BTL_EVENT_ACCURACY_CHECK = 52,       /* change the move accuracy */
    BTL_EVENT_WAZA_POWER = 55,           /* base power of the move */
    BTL_EVENT_POWER_RATIO = 56,          /* power multiplier */
    BTL_EVENT_DAMAGE_RATIO = 71,         /* damage multiplier */
    BTL_EVENT_TURN_END = 118,            /* end of turn check */
    BTL_EVENT_WAZA_PREPARE = 129,        /* Thief: remember the user's item before the hit */
    BTL_EVENT_WAZA_DAMAGE_END = 131,     /* after the hit on one target */
    BTL_EVENT_INVULNERABLE_CHECK = 153,  /* may the move hit a hidden target */
    BTL_EVENT_WAZA_EXECUTE = 160         /* the user is executing the move */
};

/* Event variables (BTL_EVENT_GetVar keys). */

/* Value ids of the poke parameter getter. */

/* Status condition and flag ids. */


#define BTL_SICK_SNATCH_BLOCK 0x21     /* the user already holds this condition (guess) */

#define BTL_CONT_FLAG_FLYING 3

#define BTL_CONT_FLAG_DIGGING 5

#define BTL_TURN_FLAG_DAMAGED 2        /* the Pokemon took damage this turn */

/* Flag of a move (WAZA_TOOL_GetFlag). */
#define WAZA_FLAG_SNATCH 5

/* Message type: a plain message by id. */

/* Weather ids. */




/* Move failure reason: the move fails with the standard message. */

/* A move slot index of this value means no slot. */

/* Slot of the factor work words that the Magic Coat and Snatch handlers share: set once the move announced itself. */
#define WAZA_WORK_ANNOUNCED 6

/* Fixed point ratio (0x1000 is 1.0). */

/* Maximum value of the power tables of Fury Cutter and Punishment. */
#define FURY_CUTTER_MAX_POWER 160

#define PUNISHMENT_MAX_POWER 200

/* Held items that change the type of a move. */
enum {
    ITEM_DOUSE_DRIVE = 0x74,
    ITEM_SHOCK_DRIVE = 0x75,
    ITEM_BURN_DRIVE = 0x76,
    ITEM_CHILL_DRIVE = 0x77,
    ITEM_FLAME_PLATE = 0x12a,
    ITEM_SPLASH_PLATE = 0x12b,
    ITEM_ZAP_PLATE = 0x12c,
    ITEM_MEADOW_PLATE = 0x12d,
    ITEM_ICICLE_PLATE = 0x12e,
    ITEM_FIST_PLATE = 0x12f,
    ITEM_TOXIC_PLATE = 0x130,
    ITEM_EARTH_PLATE = 0x131,
    ITEM_SKY_PLATE = 0x132,
    ITEM_MIND_PLATE = 0x133,
    ITEM_INSECT_PLATE = 0x134,
    ITEM_STONE_PLATE = 0x135,
    ITEM_SPOOKY_PLATE = 0x136,
    ITEM_DRACO_PLATE = 0x137,
    ITEM_DREAD_PLATE = 0x138,
    ITEM_IRON_PLATE = 0x139
};

/* Item data parameters that Natural Gift reads. */
#define ITEM_PARAM_NATURAL_GIFT_POWER 11

#define ITEM_PARAM_NATURAL_GIFT_TYPE 12

/* Record kinds that the move handlers push (HANDEX_KIND_MESSAGE and RECOVER_HP are in hand_item_021dd588_types.h). */



#define HANDEX_KIND_SWAP_ITEM 0x24

#define HANDEX_KIND_FLAG_RECORD 0x3a

/* Header flag of a record (guess: the record is shown as an item event). */
#define HANDEX_FLAG_ITEM_EVENT (1u << 24)

/* HANDEX_KIND_SWAP_ITEM: three messages for an item change between two Pokemon. */
typedef struct {
    u32 header;
    u8 targetId;
    u8 pad05[3];
    BtlStrParam swapMessage;       /* the user acts on the target's item */
    BtlStrParam targetGetsMessage; /* the target received the user's item */
    BtlStrParam userGetsMessage;   /* the user received the target's item */
} HandExSwapItem;

/* HANDEX_KIND_FLAG_RECORD: a small flag record that Thief pushes after it stole an item. */
typedef struct {
    u32 header;
    u8 flag;
} HandExFlagRecord;

/* Magnitude: the power thresholds (percent roll below which the row applies) and powers. */
typedef struct {
    u8 rollLimit;
    u8 power;
} MagnitudeRow;

#define MAGNITUDE_ROW_COUNT 7

struct BtlPokeParam;

/* A callee that returns a one-word struct: the compiler then reserves a frame word. */
typedef struct OneWordResult {
    u32 value;
} OneWordResult;

/* Event variable keys (same values and names as the other handler headers). */

/* contFlag numbers (BTL_POKEPARAM_TestContFlag). */
#define BTL_CONT_FLAG_DIVING 4                 /* semi-invulnerable underwater (Dive) */

#define BTL_CONT_FLAG_MINIMIZED 8

#define BTL_SEMI_INVULNERABLE_DIVING 4

/* Turn flags. */

#define BTL_TURN_FLAG_PROTECTED 7              /* the Pokemon protects itself this turn */

/* Counter slot of the consecutive-use streak of Protect, Detect, Endure and the guard moves. */
#define BTL_COUNTER_PROTECT_STREAK 3

#define BTL_PROTECT_STREAK_MAX 9

#define BTL_FAIL_REASON_SLEEP_BLOCKED 0x0D     /* guess */

#define BTL_FAIL_REASON_HP_FULL 0x0E

#define BTL_FAIL_REASON_ABILITY_BLOCKS_SLEEP 0x0F

#define BTL_FAIL_REASON_GENERIC 0x1A           /* "But it failed" */

#define BPP_VALUE_MAX_HP 14




#define ABILITY_INSOMNIA 15

#define ABILITY_VITAL_SPIRIT 72

/* Status conditions ("sick" kinds). */


#define BTL_SICK_SLEEP_BLOCK 0x0F              /* guess: a condition that stops the user from falling asleep */

#define BTL_SICK_ENCORE 0x17

#define BTL_SICK_BIDE 0x19                     /* Bide is storing energy */

/* Stat stage ids. */



#define BTL_RANK_STAT_COUNT 7

#define BTL_RANK_DIRECTION_RAISE 2             /* third argument of the stage check */



#define BTL_SIDE_EFFECT_QUICK_GUARD 10


/* Record kinds. */


#define HANDEX_KIND_CHANGE_HP 8

#define HANDEX_KIND_CHANGE_TYPE 0x14

#define HANDEX_KIND_SET_TURN_FLAG 0x15

#define HANDEX_KIND_CLEAR_TURN_FLAG 0x16

#define HANDEX_KIND_REMOVE_SIDE_EFFECT 0x1A

#define HANDEX_KIND_REFRESH_HP_GAUGE 0x21


/* Header flag (guess): the record plays no animation. */
#define HANDEX_FLAG_SILENT (1u << 24)

/* A message under construction: kind 1 is a standard string, kind 2 a string set; up to 8 arguments. */
#define BTL_MSG_KIND_STD 1

#define BTL_MSG_KIND_SET 2

/* String ids the move handlers show. */
#define HAND_WAZA_STR_ENDURE_BRACED 0x1FF

#define HAND_WAZA_STR_PROTECT 0x205

#define HAND_WAZA_STR_BIDE_STORING 0x2E9

#define HAND_WAZA_STR_BIDE_STORING_MORE 0x2EC

#define HAND_WAZA_STR_RECYCLE 0x2DD

#define HAND_WAZA_STR_BELLY_DRUM 613

#define HAND_WAZA_STR_FEINT 526

#define HAND_WAZA_STR_REST 638

#define HAND_WAZA_STR_ENCORE 559

#define HAND_WAZA_STR_PAIN_SPLIT 113

/* Kind 8: change the HP of up to nine Pokemon by a signed amount each. */
struct HandExChangeHp {
    u32 header;
    u8 pokeCount;
    u8 pad5;
    u8 updateGauge;          /* guess */
    u8 pokeIds[9];           /* 0x07 */
    s32 amounts[2];          /* 0x10 */
};


/* Kinds 0x15 and 0x16: set or clear a turn flag. */
struct HandExTurnFlag {
    u32 header;
    s32 flag;
    u8 pokeId;
};

/* Kind 0x21: refresh the HP gauge of a Pokemon (mode 1 after a loss or exchange, 3 after a recovery). */
struct HandExRefreshHpGauge {
    u32 header;
    u8 pokeId;
    u8 pad5[3];
    u32 mode;
};

/* Work areas of the factors (the handler's fourth argument). */
struct EndureWork {
    s32 pad[6];
    s32 braced;              /* 0x18: set when Endure was used this turn */
};

struct BideWork {
    s32 phase;               /* 0 first turn, 1 second turn, 2 and 3 release */
    s32 storedDamage;        /* damage taken while storing */
    s32 targetId;            /* poke id of the Pokemon that hit last, 0x1F when none */
    s32 pad[3];
    s32 storing;             /* 0x18: the Bide status is on */
};

struct FeintWork {
    s32 guardBroken;         /* a Quick Guard or Wide Guard was removed by this move */
};


#include "../ov093/hand_common.h"

#include "../ov093/btl_main.h"










#include "../ov093/btl_sickcont.h"



                                             /* nonzero: the move cannot be Encored */

#include "../arm9/mi_memory.h"
                            /* byte move */

/* Raises the Protect streak counter of a Pokemon by one (defined with the Protect handlers). */



struct BtlParty;

/* Move handler: BtlEventFactor, battle flow, id of the Pokemon that owns the handler, handler work. */
typedef void (*BtlWazaHandlerFunc)(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work);

/* Event ids of the handler table rows used by these moves (guessed from which moves register them). */
#define BTL_EVENT_UNCATEGORIZED_MOVE 0xa0            /* effect of a move that has a target */

#define BTL_EVENT_UNCATEGORIZED_MOVE_NO_TARGET 0xa1  /* effect of a move that has no target (screens, hazards, party moves) */

/* Event variable keys. */

/* Record kinds. */

#define HANDEX_KIND_REDUCE_PP 0xa



#define HANDEX_KIND_RANK_CHANGE 0xe

#define HANDEX_KIND_SET_RANKS 0xf

#define HANDEX_KIND_SET_STATS 0x11

#define HANDEX_KIND_KILL_POKE 0x13

#define HANDEX_KIND_ADD_SIDE_EFFECT 0x19

#define HANDEX_KIND_ADD_FIELD_EFFECT 0x1b


/* Status ids (sick kinds) these moves add or cure. */
#define BTL_SICK_TAUNT 0xb

#define BTL_SICK_TORMENT 0xc


#define BTL_SICK_LOCK_ON 0x1d

#define BTL_SICK_ALL_MAJOR 0x24     /* cure kind: every major status */


/* Turn flag index tested on the Pokemon ("has already acted this turn"; guess). */

/* Condition flag index set by Power Trick. */
#define BTL_CONT_FLAG_POWER_TRICK 0xa

/* Message string types for the string parameter setter. */
#define BTL_STRTYPE_STD 1

#define BTL_STRTYPE_SET 2

/* Value ids of the Pokemon value getter: stat stages 1..7, then raw stats. */
#define BPP_VALUE_ATTACK_RANK 1

#define BPP_VALUE_DEFENSE_RANK 2

#define BPP_VALUE_SP_ATTACK_RANK 3

#define BPP_VALUE_SP_DEFENSE_RANK 4

#define BPP_VALUE_SPEED_RANK 5

#define BPP_VALUE_ACCURACY_RANK 6

#define BPP_VALUE_EVASION_RANK 7

#define BPP_RANK_COUNT 7

#define BPP_VALUE_ATTACK 8


#define BPP_VALUE_SP_ATTACK 10



/* Side effect kinds of the AddSideEffect record. */
enum {
    BTL_SIDE_EFFECT_REFLECT,
    BTL_SIDE_EFFECT_LIGHT_SCREEN,
    BTL_SIDE_EFFECT_SAFEGUARD,
    BTL_SIDE_EFFECT_MIST,
    BTL_SIDE_EFFECT_TAILWIND,
    BTL_SIDE_EFFECT_LUCKY_CHANT,
    BTL_SIDE_EFFECT_SPIKES,
    BTL_SIDE_EFFECT_TOXIC_SPIKES,
    BTL_SIDE_EFFECT_STEALTH_ROCK,
    BTL_SIDE_EFFECT_WIDE_GUARD
};

/* Kind 0xa: lower the PP of one move slot, then show a message. */
struct HandExReducePp {
    u32 header;
    u8 amount;
    u8 pokeId;
    u8 moveSlot;
    u8 pad07;
    BtlStrParam message;
};

/* Kind 0xf: set all seven stat stages of a Pokemon (attack .. evasion). */
struct HandExSetRanks {
    u32 header;
    u8 pokeId;
    u8 ranks[BPP_RANK_COUNT];
};

/* Kind 0x11: set raw stats of a Pokemon; the set flags choose which values apply. */
struct HandExSetStats {
    u32 header;
    u16 attack;
    u16 defense;
    u16 spAttack;
    u16 spDefense;
    u16 pad0C;
    u8 pokeId;
    u8 setAttack : 1;
    u8 setDefense : 1;
    u8 setSpAttack : 1;
    u8 setSpDefense : 1;
    u8 flagsRest : 4;
    BtlStrParam message;
};

/* Kind 0x13: make a Pokemon faint. */
struct HandExKillPoke {
    u32 header;
    u8 pokeId;
};

/* Kind 0x19: put an effect on a side of the field (screen, hazard, Tailwind ...). */
struct HandExAddSideEffect {
    u32 header;
    u32 effectKind;
    union SickCont cont;
    u8 side;
    u8 pad0D[3];
    BtlStrParam message;
};

/* Kind 0x1b: put a field effect bound to a Pokemon (Imprison) and show a message. */
struct HandExAddFieldEffect {
    u32 header;
    u32 effectKind;
    union SickCont cont;
    u8 showMessage;
    u8 pad0D[3];
    BtlStrParam message;
};

/* Services of the event variable stack and the battle flow. */




#ifndef HAND_WAZA_DEFINES_ADD_SIDE_EFFECT

/* Queues an AddSideEffect record: side, effect kind, duration record and message id (defined with the Wide Guard handler). */
#include "../ov093/hand_waza.h"

#endif


/* Side of the field of a Pokemon id, and the opposite side. */

/* Record kinds that only these handlers use (the shared ones are HANDEX_KIND_* in hand_tokusei_021d9adc_types.h). */
#define HAND_WAZA_KIND_CLEAR_TURN_FLAG 0x16

#define HAND_WAZA_KIND_SET_CONT_FLAG 0x17

#define HAND_WAZA_KIND_FAINT 0x13

#define HAND_WAZA_KIND_CLEAR_HAZARDS 0x1a

#define HAND_WAZA_KIND_SET_POS_EFFECT 0x1e

#define HAND_WAZA_KIND_USE_ITEM 0x22

#define HAND_WAZA_KIND_REMOVE_ITEM 0x23

#define HAND_WAZA_KIND_ESCAPE 0x28

#define HAND_WAZA_KIND_MESSAGE_ANIM 0x29

#define HAND_WAZA_KIND_SWITCH_OUT 0x37

/* Event variables (guesses are listed in the lane review notes). */

/* Move events these handlers answer. */
#define BTL_EVENT_MOVE_DELAYED_START 6   /* Future Sight and Doom Desire: the delayed attack is armed */

#define BTL_EVENT_MOVE_DELAYED_MESSAGE 7

#define BTL_EVENT_MOVE_NO_EFFECT 0xd

#define BTL_EVENT_MOVE_CHECK_FAIL 0x1f

#define BTL_EVENT_MOVE_EFFECT 0xa0       /* the effect of a status move */

/* Record header flag set by U-turn, Volt Switch and Baton Pass (meaning guessed: no wait after the message). */
#define HANDEX_FLAG_NO_WAIT (1 << 24)

/* Position effects (kind 0x1e, field effectKind). */
#define BTL_POS_EFFECT_WISH 0

#define BTL_POS_EFFECT_LUNAR_DANCE 1

#define BTL_POS_EFFECT_HEALING_WISH 2

#define BTL_POS_EFFECT_DELAYED_ATTACK 3   /* Future Sight, Doom Desire */

#define BTL_POS_EFFECT_BATON_PASS 4

/* Continuing flags set by kind 0x17. */

#define BTL_CONT_FLAG_SHADOW_FORCE 6

#define BTL_CONT_FLAG_BATON_PASS 0xe

/* Turn flag that Protect style moves set; cleared by kind 0x16. */


/* Status ids (guesses) used by Rapid Spin, Teleport and Magnet Rise. */

#define BTL_SICK_LEECH_SEED 0x12

#define BTL_SICK_INGRAIN 0x15

#define BTL_SICK_MAGNET_RISE 0x1e

#define BTL_SICK_FLOATING_BLOCK 0x1f

#define BTL_SICK_TRAPPED 0x16

#define BTL_SICK_ABILITY_SUPPRESSED 0x10

/* Kind 0x16: clear a turn flag of a Pokemon. */
struct HandExClearTurnFlag {
    u32 header;
    s32 turnFlag;
    u8 pokeId;
};

/* Kind 0x1a: remove the entry hazards from a side. maskBytes[0] holds 3 and the other two bytes are the bit mask. */
struct HandExClearHazards {
    u32 header;
    u8 maskBytes[3];
    u8 side;
};

/* Kind 0x1e: arm a position effect (Wish, Lunar Dance, Healing Wish, delayed attack, Baton Pass). */
struct HandExSetPosEffect {
    u32 header;
    s32 effectKind;
    u8 position;
    u8 pad9[3];
    s32 param;       /* delayed attack: trigger turn; Baton Pass: the Pokemon that passes */
    s32 factorKey;   /* key of the event factor that owns the effect */
    u8 pad14[8];
    u8 mode;         /* 1 plain, 2 delayed attack */
};

/* Kind 0x22: use the held item of a Pokemon on another one. */
struct HandExUseItem {
    u32 header;
    u8 targetId;
    u8 pad5;
    u16 itemId;
};

/* Kind 0x23: remove the held item. */
struct HandExRemoveItem {
    u32 header;
    s32 consumeKind;
};

/* Kind 0x29: show a message and play the matching animation for pokeId. */
struct HandExMessageAnim {
    u32 header;
    BtlStrParam message;
    u8 pad28[0x24];
    u8 pokeId;
    u8 animMode;
};

/* Kind 0x37: send a Pokemon back to its ball after a move (U-turn, Volt Switch). */
struct HandExSwitchOut {
    u32 header;
    u16 messageId;
    u8 position;
    u8 replacementSlot;
};

/* Kind 0xc with an announcement text: add a status condition and show a message. */
struct HandExAddSickAnnounce {
    u32 header;
    u32 sickKind;
    union SickCont sickCont;
    u8 suppressMessage;
    u8 pad0D[2];
    u8 pokeId;
    u8 pad10[4];
    BtlStrParam message;
};

/* Record kinds written by these handlers. */
#define HANDEX_WAZA_KIND_MESSAGE 4

#define HANDEX_WAZA_KIND_PP_CHANGE 10

#define HANDEX_WAZA_KIND_ADD_SICK 12

#define HANDEX_WAZA_KIND_RANK_EFFECT 0xe

#define HANDEX_WAZA_KIND_KILL 0x13

#define HANDEX_WAZA_KIND_VISIBILITY 0x15

#define HANDEX_WAZA_KIND_SET_STATE 0x17

#define HANDEX_WAZA_KIND_CONSUME_ITEM 0x20

#define HANDEX_WAZA_KIND_ITEM_EFFECT 0x22

#define HANDEX_WAZA_KIND_ANIMATION 0x37

/* Event variables the move handlers read or write. */
#define WAZAVAR_POKE_ID 2

#define WAZAVAR_ATTACKER_ID 3

#define WAZAVAR_DEFENDER_ID 4

#define WAZAVAR_MOVE_ID 0x12

#define WAZAVAR_MOVE_SLOT 0xd

#define WAZAVAR_TARGET_SLOT 0xe

#define WAZAVAR_ITEM_SLOT 6

#define WAZAVAR_SECONDARY_RATE 0x1f

#define WAZAVAR_POWER_RATIO 0x31

#define WAZAVAR_FAIL_MESSAGE 0x3f

#define WAZAVAR_FAIL_FLAG 0x41

#define WAZAVAR_SKIP_FLAG 0x51

/* Kind 4: show a message. */
struct HandWazaMessageRecord {
    u32 header;
    BtlStrParam message;
};

/* Kinds 0x17 and 0x15: set a per-Pokemon state value (charge-turn flag, visibility). */
struct HandWazaStateRecord {
    u32 header;
    u32 state;
    u8 pokeId;
};

/* Kind 0xe: change a stat stage. */
struct HandWazaRankRecord {
    u32 header;
    u32 rankKind;
    u8 pad08[4];
    u8 volume;
    u8 pad0D;
    u8 flagB;
    u8 pokeCount;
    u8 pokeId;
};

/* Kind 0x20: use up a held item with a message. */
struct HandWazaConsumeItemRecord {
    u32 header;
    u16 flags;
    u8 pokeId;
    u8 pad07;
    u8 pad08[4];
    BtlStrParam message;
};

/* Kind 0x22: apply the effect of a held item. */
struct HandWazaItemEffectRecord {
    u32 header;
    u8 pokeId;
    u8 pad05;
    u16 itemId;
};

/* Kind 0x13: kill a Pokemon, or print a message about it. */
struct HandWazaKillRecord {
    u32 header;
    u8 pokeId;
    u8 flag;
    u8 pad06[2];
    BtlStrParam message;
};

/* Kind 10: change the PP of a move slot. */
struct HandWazaPpRecord {
    u32 header;
    s8 amount;
    u8 pokeId;
    u8 slot;
    u8 flags;
    BtlStrParam message;
};

/* Kind 0x37: play a move animation. */
struct HandWazaAnimRecord {
    u32 header;
    u16 animId;
    u8 target;
    u8 mode;
    u8 pad08[3];
    u8 flag;
};

/* Kind 12: add a status condition. */
struct HandWazaSickRecord {
    u32 header;
    u32 sickKind;
    u32 sickCont;
    u8 pad0C;
    u8 flag;
    u8 pad0E;
    u8 pokeId;
};


/* Move handler records and constants, second part (Hex to Round). */
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

/* Kind 0x10: reset all stat stages of a Pokemon. */
struct HandWazaCmdResetRanks {
    u32 header;
    u8 resetKind;
    u8 pokeId;
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

/* Move handler constants and services, tail of the move block (Round to Pledge). */
struct BtlTurnRecord;


/* Moves (ids of the move registry). */
#define BTL_MOVE_ROUND 496
#define BTL_MOVE_QUICK_GUARD 501
#define BTL_MOVE_ALLY_SWITCH 502
#define BTL_MOVE_WATER_PLEDGE 518
#define BTL_MOVE_FIRE_PLEDGE 519
#define BTL_MOVE_GRASS_PLEDGE 520
#define BTL_MOVE_FREEZE_SHOCK 553
#define BTL_MOVE_ICE_BURN 554
#define BTL_MOVE_FUSION_FLARE 558
#define BTL_MOVE_FUSION_BOLT 559

/* Species, items and types that these handlers test. */
#define BTL_SPECIES_DIGLETT 50
#define BTL_SPECIES_DUGTRIO 51
#define BTL_SPECIES_MELOETTA 648
#define BTL_TYPE_FLYING 2
#define BTL_TYPE_GHOST 7
#define BTL_TYPE_FIRE 9
#define BTL_TYPE_WATER 10
#define BTL_TYPE_GRASS 11
#define BTL_TYPE_DARK 16

/* Event variable keys of these handlers beyond hand_common_types.h. */
#define BTL_EVAR_EFFECTIVE_MOVE_ID 0x13      /* move id the flow shows and animates (a Pledge combination replaces it) */
#define BTL_EVAR_WAZA_POWER 0x30
#define BTL_EVAR_MESSAGE 0x3F                /* pointer to the message the event is about to show */
#define BTL_EVAR_REFLECTED_FLAG 0x4F         /* guess: the move was reflected or absorbed on the way */
#define BTL_EVAR_PREVENT_FLAG BTL_EVAR_FORCE_GROUNDED_FLAG
#define BTL_EVAR_GENERIC_FLAG BTL_EVAR_FORCE_FLOATING_FLAG
#define BTL_EVAR_SKIP_CHARGE_FLAG BTL_EVAR_FORCE_FLOATING_FLAG

/* Battle rules (BTL_SERVER_FLOW_GetRule), the client id that marks "no client", message string types. */
#ifndef BTL_RULE_SINGLE
#define BTL_RULE_SINGLE 0
#endif
#ifndef BTL_RULE_DOUBLE
#define BTL_RULE_DOUBLE 1
#endif
#ifndef BTL_RULE_TRIPLE
#define BTL_RULE_TRIPLE 2
#endif
#ifndef BTL_RULE_ROTATION
#define BTL_RULE_ROTATION 3
#endif
#ifndef BTL_CLIENT_ID_NONE
#define BTL_CLIENT_ID_NONE 4
#endif
#define BTL_STRTYPE_STD 1
#define BTL_STRTYPE_SET 2

/* Value ids of the Pokemon value getter (BTL_POKEPARAM_GetValue) and weather values. */
#define BTL_BPP_VALUE_FORM 19
#define BTL_WEATHER_SUN 1
#define BTL_RATIO_DOUBLE 0x2000                    /* fixed point ratio, 0x1000 is 1.0 */

/* Values of the calls above. */
#define BTL_POS_NONE 6                             /* "no position" */
#define BTL_COUNTER_BOUND_TARGET 4                 /* counter slot: id + 1 of the Pokemon that Sky Drop holds */
#define BTL_BOUND_TARGET_LIMIT 0x18                /* counter values from here on mean no Pokemon */
#define BTL_SICK_INGRAIN 0x15
#define BTL_SICK_FLOATING_BLOCK 0x1f               /* guess: Smack Down */
#define BTL_SICK_TELEKINESIS 0x20

/* Record kinds (HANDEX_KIND_*) beyond the ones of hand_waza_021e4754_types.h. */
#define HANDEX_KIND_SWAP_POSITIONS 0x32
#define HANDEX_KIND_PLAY_EFFECT 0x37
#define HANDEX_KIND_CHANGE_MON_FORM 0x39

/* Strings these handlers show. */
#define HAND_WAZA_STR_QUICK_GUARD 0xa2
#define HAND_WAZA_STR_PLEDGE_WAITING 0xbb
#define HAND_WAZA_STR_FORM_CHANGE 0xde
#define HAND_WAZA_STR_SKY_DROP 1118
#define HAND_WAZA_STR_ALLY_SWITCH 1137
#define HAND_WAZA_STR_TELEKINESIS 1140
#define HAND_WAZA_STR_FREEZE_SHOCK_CHARGE 0x35f
#define HAND_WAZA_STR_ICE_BURN_CHARGE 0x362
#define HAND_WAZA_STR_RAINBOW 0xa4
#define HAND_WAZA_STR_SEA_OF_FIRE 0xa8
#define HAND_WAZA_STR_SWAMP 0xac

/* Side effect kinds that continue the side effect numbering of the Wide Guard handler (Wide Guard is 9). */
#define BTL_SIDE_EFFECT_QUICK_GUARD_KIND 10
#define BTL_SIDE_EFFECT_RAINBOW 11
#define BTL_SIDE_EFFECT_SEA_OF_FIRE 12
#define BTL_SIDE_EFFECT_SWAMP 13

/* Battle effect ids played when a Pledge combination starts. */
#define BTL_EFFECT_RAINBOW 0x28d
#define BTL_EFFECT_SEA_OF_FIRE 0x28e
#define BTL_EFFECT_SWAMP 0x28f

/* Combination kinds of two Pledge moves; 0 is no combination. */
#define PLEDGE_COMBO_NONE 0
#define PLEDGE_COMBO_RAINBOW 1       /* Water + Fire: Water type, helps the user's side */
#define PLEDGE_COMBO_SEA_OF_FIRE 2   /* Grass + Fire: Fire type, hurts the foe side */
#define PLEDGE_COMBO_SWAMP 3         /* Water + Grass: Grass type, slows the foe side */
#define PLEDGE_COMBINED_POWER 150

/* Kind 4: show a message. */
/* Name of the message parameter in these handlers. */
typedef BtlStrParam BtlMessageParam;


#define HANDEX_KIND_MESSAGE 4

#define HANDEX_KIND_ADD_SIDE_EFFECT 0x19

/* Kind 0x32: two Pokemon swap places, then a message names both. */
struct HandExSwapPositions {
    u32 header;
    u8 pokeId;
    u8 partnerId;
    u8 pad06[2];
    BtlMessageParam message;
};

/* One row of the Pledge combination table: two moves and the combination they make. */
struct PledgeCombo {
    u16 firstMove;
    u16 secondMove;
    int combo;
};

/* Work words of a Pledge factor. */
struct PledgeWork {
    int combined;     /* nonzero once a partner Pledge is paired with this one */
    int combo;        /* PLEDGE_COMBO_* */
    int partnerId;    /* id of the partner Pokemon that chose the other Pledge */
};

/* Services used by the handlers of these files. */
#include "../ov095/btl_wazarec.h"

#endif
