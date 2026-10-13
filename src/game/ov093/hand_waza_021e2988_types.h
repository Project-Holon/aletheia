#ifndef HAND_WAZA_021E2988_TYPES_H
#define HAND_WAZA_021E2988_TYPES_H
/*
 * ov093 move handlers (HAND_WAZA_*): the factors that a move adds to the
 * event list when it is used. Each move has an Add function that returns a
 * table of {event, handler} pairs; the handlers read event variables and
 * either overwrite them (power, type, hit checks) or ask the battle server
 * flow for an effect record (HANDEX_KIND_*).
 *
 * The move id is the key of the factor (BTL_EVENT_GetFactorKey).
 */

#include "btl_event_types.h"
#include "hand_item_021dd588_types.h"

struct BtlSvFlow;

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
#ifndef BTL_EVAR_ATTACKER_ID
#define BTL_EVAR_ATTACKER_ID 3
#endif
#define BTL_EVAR_DAMAGED_ID 6           /* the target whose damage was just applied (guess) */
#define BTL_EVAR_MOVE_ID 0x12
#define BTL_EVAR_MOVE_TYPE 0x16
#define BTL_EVAR_HIDE_KIND 0x21         /* how the target is hidden (BTL_CONT_FLAG_*) */
#define BTL_EVAR_FAIL_REASON 0x22
#define BTL_EVAR_ACCURACY 0x2b
#define BTL_EVAR_WAZA_POWER 0x30
#define BTL_EVAR_POWER_RATIO 0x31
#define BTL_EVAR_DAMAGE_RATIO 0x35
#define BTL_EVAR_AVOID_FLAG 0x42        /* nonzero: the hidden target is not hit (guess) */
#define BTL_EVAR_HANDLED_FLAG 0x51      /* set by an event handler to say it acted */

/* Value ids of the poke parameter getter. */
#define BTL_VALUE_HP 0xd

/* Status condition and flag ids. */
#define BTL_SICK_PARALYSIS 1
#define BTL_SICK_SLEEP 2
#define BTL_SICK_SNATCH_BLOCK 0x21     /* the user already holds this condition (guess) */
#define BTL_CONT_FLAG_FLYING 3
#define BTL_CONT_FLAG_DIGGING 5
#define BTL_TURN_FLAG_DAMAGED 2        /* the Pokemon took damage this turn */

/* Flag of a move (WAZA_TOOL_GetFlag). */
#define WAZA_FLAG_SNATCH 5

/* Message type: a plain message by id. */
#define HANDEX_STR_STANDARD 1

/* Weather ids. */
#define BTL_WEATHER_SUN 1
#define BTL_WEATHER_RAIN 2
#define BTL_WEATHER_HAIL 3
#define BTL_WEATHER_SAND 4

/* Move failure reason: the move fails with the standard message. */
#define BTL_FAIL_REASON_MOVE_FAILED 0x1a

/* A move slot index of this value means no slot. */
#define BTL_MOVE_SLOT_NONE 4

/* Slot of the factor work words that the Magic Coat and Snatch handlers share: set once the move announced itself. */
#define WAZA_WORK_ANNOUNCED 6

/* Fixed point ratio (0x1000 is 1.0). */
#define BTL_RATIO_DOUBLE 0x2000

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
#define HANDEX_KIND_CURE_SICK 0xb
#define HANDEX_KIND_SET_ITEM 0x20
#define HANDEX_KIND_ITEM_MESSAGE 0x23
#define HANDEX_KIND_SWAP_ITEM 0x24
#define HANDEX_KIND_FLAG_RECORD 0x3a

/* Header flag of a record (guess: the record is shown as an item event). */
#define HANDEX_FLAG_ITEM_EVENT (1u << 24)

/* HANDEX_KIND_CURE_SICK: cure a status condition of up to 12 listed Pokemon. */
typedef struct {
    u32 header;
    u32 sickKind;
    u8 pokeIds[12];
    u8 pokeCount;
    u8 suppressMessage;
} HandExCureSick;

/* HANDEX_KIND_SET_ITEM: give a Pokemon a held item, then show a string. */
typedef struct {
    u32 header;
    u16 itemId;
    u8 pokeId;
    u8 announce;
    u32 pad08;
    HandExStr str;
} HandExSetItem;

/* HANDEX_KIND_ITEM_MESSAGE: consume the item flag, then show a string (the string is not used by Natural Gift). */
typedef struct {
    u32 header;
    u32 consumeItem;
    HandExStr str;
} HandExItemMessage;

/* HANDEX_KIND_SWAP_ITEM: three messages for an item change between two Pokemon. */
typedef struct {
    u32 header;
    u8 targetId;
    u8 pad05[3];
    HandExStr swapMessage;       /* the user acts on the target's item */
    HandExStr targetGetsMessage; /* the target received the user's item */
    HandExStr userGetsMessage;   /* the user received the target's item */
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

#endif
