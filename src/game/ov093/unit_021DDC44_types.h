#ifndef UNIT_021DDC44_TYPES_H
#define UNIT_021DDC44_TYPES_H
/*
 * ov093 held item handlers, middle part: the type-resist berries (Kasib to
 * Chilan), the HP-threshold berries (Custap, Micle), Jaboca and Rowap Berry,
 * White Herb, Mental Herb, Bright Powder, Macho Brace, Quick Claw, Lagging
 * Tail, King's Rock, the critical-rate items, the accuracy items and the
 * power items (Muscle Band, Wise Glasses, Deep Sea Tooth and Scale).
 *
 * An item has a getter that returns its handler table (event id and handler)
 * and the table length. The item registry (unit_021DCAE8.c) maps an item id to
 * that getter. Several items can share one table (King's Rock and Razor Fang,
 * Scope Lens and Razor Claw), and the berries of one family share handlers.
 * A handler is called as (factor, flow, pokeId, work); work is the factor work
 * array.
 */
#include "unit_021DD588_types.h"

struct BtlSvFlow;

/* Event ids that the item handler tables of these files use (guesses from the handler bodies). */
enum {
    BTL_ITEM_EVENT_AFTER_ACTION_CHECK = 0x02,  /* guess: end of an action; HP and status berries test their trigger */
    BTL_ITEM_EVENT_ACTION_ORDER = 0x0F,        /* may rewrite the action order key */
    BTL_ITEM_EVENT_SPEED = 0x13,
    BTL_ITEM_EVENT_ACCURACY = 0x34,
    BTL_ITEM_EVENT_CRITICAL_RANK = 0x36,
    BTL_ITEM_EVENT_MOVE_POWER = 0x38,
    BTL_ITEM_EVENT_ATTACK_RATIO = 0x3B,
    BTL_ITEM_EVENT_DEFENSE_RATIO = 0x3C,
    BTL_ITEM_EVENT_RESIST_NOTICE = 0x44,       /* resist berry: show that it was eaten */
    BTL_ITEM_EVENT_RESIST_DAMAGE = 0x47,       /* resist berry: halve the damage */
    BTL_ITEM_EVENT_HIT_REACTION = 0x4B,        /* the holder was hit */
    BTL_ITEM_EVENT_DAMAGE_CHECK = 0x55,        /* guess: after damage was dealt */
    BTL_ITEM_EVENT_STAT_DROP_CHECK = 0x57,
    BTL_ITEM_EVENT_TURN_END_CHECK = 0x58,
    BTL_ITEM_EVENT_ADD_EFFECT_CHANCE = 0x6C,
    BTL_ITEM_EVENT_USE_ITEM = 0x72,            /* the item acts */
    BTL_ITEM_EVENT_USE_ITEM_FORCED = 0x73,     /* the item acts although it was used from outside (Fling) */
    BTL_ITEM_EVENT_STAT_CHANGE_CHECK = 0x77,
    BTL_ITEM_EVENT_SWITCH_IN_CHECK = 0x91
};

/* More event variable keys (see unit_021DD588_types.h for the first ones). */
#ifndef BTL_EVAR_ATTACKER_ID
#define BTL_EVAR_ATTACKER_ID 3
#endif
#define BTL_EVAR_TURN_PHASE 0xC            /* guess: phase of the turn check; 6 is skipped by the berries */
#define BTL_EVAR_ACTION_ORDER 0x11         /* priority key of the action order; 0 is last, 2 is first */
#define BTL_EVAR_MOVE_ID 0x12
#define BTL_EVAR_MOVE_TYPE 0x16
#define BTL_EVAR_MOVE_CATEGORY 0x1A        /* 1 physical, 2 special */
#define BTL_EVAR_EFFECT_PERCENT_LOCKED 0x25 /* guess: nonzero when the extra effect chance is fixed already */
#define BTL_EVAR_EFFECT_PERCENT 0x26       /* chance of the extra effect (flinch) */
#define BTL_EVAR_CRITICAL_RANK 0x2C
#define BTL_EVAR_TRIGGER_KIND 0x2E
#define BTL_EVAR_POWER_RATIO 0x31
#define BTL_EVAR_RATIO 0x35                /* fixed point ratio, 4096 is 1.0 */

#define BTL_RATIO_ONE 4096
#define BTL_RATIO_HALF 2048
#define BTL_RATIO_DOUBLE 8192
#define BTL_RATIO_MICLE_ACCURACY 0x78      /* percent, stored in the Micle status */

/* Move categories of BTL_EVAR_MOVE_CATEGORY. */
#define BTL_MOVE_CATEGORY_PHYSICAL 1
#define BTL_MOVE_CATEGORY_SPECIAL 2

/* Action order values written to BTL_EVAR_ACTION_ORDER. */
#define BTL_ACTION_ORDER_LAST 0
#define BTL_ACTION_ORDER_FIRST 2

/* Ability and species ids tested by the handlers. */
#define BTL_ABILITY_GLUTTONY 0x52
#define BTL_SPECIES_CLAMPERL 0x16E
#define BTL_SPECIES_CHANSEY 0x71
#define BTL_SPECIES_FARFETCHD 0x53
#define BTL_SPECIES_DITTO 0x86

/* Index of the item data value that the handlers read with the item param getter (HP divisor, percent, ...). */
#define BTL_ITEM_PARAM_VALUE 2

/* Poke parameter value ids used by the HP test. */
#define BTL_VALUE_ABILITY 0x11
#define BTL_VALUE_HP 0xD

/* Condition ids. */
#define BTL_SICK_MICLE_ACCURACY 0x22
#define BTL_SICK_ANY_VOLATILE 0x26

/* More record kinds. */
#define HANDEX_KIND_USE_ITEM 0
#define HANDEX_KIND_DAMAGE 7
#define HANDEX_KIND_RESTORE_RANKS 0x12
#define HANDEX_KIND_ITEM_MESSAGE 0x23
#define HANDEX_KIND_FLINCH 0x2B

/* Work slot 0 of a held item is cleared when the item has shown its message (ITEM_WORK_USED). */

/* Kind 0: the held item acts. */
typedef struct HandExUseItem {
    u32 header;
    u32 useFlags;
} HandExUseItem;

/* useFlags: the record keeps the item (the berry only remembers the attacker). */
#define HANDEX_USE_ITEM_KEEP_ITEM 2

/* Kind 7: damage a Pokemon, then show a string. */
typedef struct HandExDamage {
    u32 header;
    u16 amount;
    u8 pokeId;
    u8 pad07;
    u32 pad08;
    HandExStr str;
} HandExDamage;

/* Kind 0xc with a message: add a status condition, then show a string. */
typedef struct HandExAddSickMessage {
    u32 header;
    u32 sickKind;
    union SickCont sickCont;
    u8 suppressMessage;
    u8 pad0D[2];
    u8 pokeId;
    u32 pad10;
    HandExStr str;
} HandExAddSickMessage;

/* Kind 0x12: restore the lowered stat stages of a Pokemon. */
typedef struct HandExRestoreRanks {
    u32 header;
    u8 pokeId;
} HandExRestoreRanks;

/* Kind 0x23: show a message that names the item (the string is at +8). */
typedef struct HandExItemMessage {
    u32 header;
    u32 pad04;
    HandExStr str;
} HandExItemMessage;

/* Kind 0x2b: make a Pokemon flinch with a chance in percent. */
typedef struct HandExFlinch {
    u32 header;
    u8 pokeId;
    u8 percent;
} HandExFlinch;

#endif
