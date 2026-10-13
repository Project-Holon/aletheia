#ifndef HAND_ITEM_TYPES_H
#define HAND_ITEM_TYPES_H
#include "hand_common_types.h"
/*
 * ov093 held item handlers (berries): the effect records a handler pushes to
 * the battle flow and the event variable numbers the handlers read.
 *
 * A handler asks the flow for a record of one kind (HANDEX_KIND_*), fills the
 * fields that kind uses and hands it back. Every record starts with the
 * 32-bit header the flow writes.
 */

#include "btl_pokeparam_types.h"
/*
 * ov093 held item handlers, middle part: the type-resist berries (Kasib to
 * Chilan), the HP-threshold berries (Custap, Micle), Jaboca and Rowap Berry,
 * White Herb, Mental Herb, Bright Powder, Macho Brace, Quick Claw, Lagging
 * Tail, King's Rock, the critical-rate items, the accuracy items and the
 * power items (Muscle Band, Wise Glasses, Deep Sea Tooth and Scale).
 *
 * An item has a getter that returns its handler table (event id and handler)
 * and the table length. The item registry (hand_tokusei_021dcae8.c) maps an item id to
 * that getter. Several items can share one table (King's Rock and Razor Fang,
 * Scope Lens and Razor Claw), and the berries of one family share handlers.
 * A handler is called as (factor, flow, pokeId, work); work is the factor work
 * array.
 */
#include "hand_item_types.h"
/*
 * ov093 held item handlers (second part): the item version of Run Away,
 * the prize money items, the type boost items, the weather rocks and the
 * Fling-able status items. Each item has a getter that returns its handler
 * table (event id plus function) and writes the number of entries.
 */
#include "btl_action_word_types.h"
#include "hand_tokusei_types.h"
#include "unit_021D794C_types.h"
/*
 * ov093 held item handlers, last part: Binding Band (power part), Absorb
 * Bulb, Cell Battery, Eject Button and the 17 type gems; and the start of the
 * move handler code (registry lookup and removal of move handlers).
 *
 * Handler tables hold (event id, handler) pairs. Events used here:
 *   0x38 move power, 0x4B damage reaction, 0x62 move sick content,
 *   0x72 use item, 0x81 move used, 0x83 after the damage of a move,
 *   0x88 end of the damage of a move, 0xA0 move effect.
 * Item ids: 545 Absorb Bulb, 546 Cell Battery, 547 Eject Button,
 * 548..564 Fire, Water, Electric, Grass, Ice, Fighting, Poison, Ground,
 * Flying, Psychic, Bug, Rock, Ghost, Dragon, Dark, Steel and Normal Gem.
 */
#include "hand_item_types.h"

struct BtlEventFactor;

/* Record kinds that the item handlers push. */





/* Event variables the item handlers read with the event variable getter. */

/* Type affinity values above this are super effective. */

/* Value ids of the poke parameter getter. */

/* Status ids. */


/* Stat ids of the rank (stat stage) records; also the numbers the stat berries use. */






/* Pokemon type ids (a dense list: there is no unused slot between steel and fire). */

/* Condition flag that the critical-rate berry sets. */

/* Slots of the per-item work words the handlers share. */









/* Deprecated names of event variable keys, kept for files not yet cleaned. */

struct BtlServerFlow;

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

/* More event variable keys (see hand_item_types.h for the first ones). */

#define BTL_RATIO_ONE 4096



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


/* Condition ids. */
#define BTL_SICK_MICLE_ACCURACY 0x22


/* More record kinds. */


#define HANDEX_KIND_RESTORE_RANKS 0x12



/* Work slot 0 of a held item is cleared when the item has shown its message (ITEM_WORK_USED). */

/* Kind 0: the held item acts. */
typedef struct HandExUseItem {
    u32 header;
    u32 useFlags;
} HandExUseItem;

/* useFlags: the record keeps the item (the berry only remembers the attacker). */
#define HANDEX_USE_ITEM_KEEP_ITEM 2


/* Kind 0xc with a message: add a status condition, then show a string. */
typedef struct HandExAddSickMessage {
    u32 header;
    u32 sickKind;
    union SickCont sickCont;
    u8 suppressMessage;
    u8 pad0D[2];
    u8 pokeId;
    u32 pad10;
    BtlStrParam message;
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
    BtlStrParam message;
} HandExItemMessage;

/* Kind 0x2b: make a Pokemon flinch with a chance in percent. */
typedef struct HandExFlinch {
    u32 header;
    u8 pokeId;
    u8 percent;
} HandExFlinch;

/* Deprecated names of event variable keys, kept for files not yet cleaned. */


#define BTL_ITEM_DITTO_SPECIES 0x84

#define BTL_SICK_MOVE_LOCK 0x1b     /* choice item lock */



/* Kind 0: use the held item (flags bit 0 marks it as consumed by the handler). */
typedef struct {
    u32 header;
    u32 flags;
} HandExItemUse;

/* Kind 7: lose hit points (amount, message at +12). */
typedef struct {
    u32 header;
    u16 amount;
    u8 pokeId;
    u8 flags;       /* bit 1 set by the item damage handlers */
    u16 effectId;
    u8 effectParam;
    u8 effectKind;
    BtlStrParam message;
} HandExLoseHp;

/* Kind 0xb: cure a status slot of a Pokemon. */
typedef struct {
    u32 header;
    s32 sickIndex;
    u8 pokeId;
    u8 pad09[11];
    u8 flagA;
    u8 flagB;
} HandExCureSickSlot;

/* Kind 0xc: add a status condition with a packed duration and a message at +0x14. */
typedef struct {
    u32 header;
    u32 sickKind;
    u32 sickCont;
    u8 pad0C;
    u8 flagD;
    u8 pad0E;
    u8 pokeId;
    u8 mode;
    u8 pad11[3];
    BtlStrParam message;
} HandExAddSickFull;

/* Kind 0x23: consume the item and show a message at +8. */
typedef struct {
    u32 header;
    u8 pad04[4];
    BtlStrParam message;
} HandExConsumeItem;

/* Kind 0x24: move the held item of the attacker to the holder. */
typedef struct {
    u32 header;
    u8 pokeId;
} HandExStealItem;

/* Deprecated names of event variable keys, kept for files not yet cleaned. */





struct BtlPokeParam;

/* Pokemon types that the type boost items name (the battle type list, 0 = normal). */
#define BTL_TYPE_NORMAL 0

#define BTL_TYPE_FIGHTING 1

#define BTL_TYPE_FLYING 2

#define BTL_TYPE_POISON 3

#define BTL_TYPE_BUG 6

#define BTL_TYPE_ELECTRIC 12

#define BTL_TYPE_GRASS 11

#define BTL_TYPE_PSYCHIC 13

#define BTL_TYPE_DRAGON 15

#define BTL_TYPE_DARK 16

/* Species that hold-item effects check. */
#define BTL_SPECIES_PIKACHU 0x19


/* Event ids that the handlers of these items answer (names from the handler use; guesses). */
enum {
    BTL_ITEM_EVENT_ESCAPE_MESSAGE = 0xD,
    BTL_ITEM_EVENT_MEMBER_ENTER = 0x55,
    BTL_ITEM_EVENT_MEMBER_ENTER_DONE = 0x58,
    BTL_ITEM_EVENT_FLING_EFFECT = 0x73,
    BTL_ITEM_EVENT_TURN_END = 0x77,
    BTL_ITEM_EVENT_WEATHER_TURNS = 0x7C
};

/* Command kinds that these handlers queue on the battle flow. */


/* String table id used by the standard battle messages. */
#define BTL_STR_TYPE_STANDARD 2

/* Item parameter ids read through the item parameter getter. */
#define BTL_ITEM_PARAM_BOOST_PERCENT 2 /* percent bonus; for weather rocks, extra turns */

/*
 * Command kind 12: put a status condition on a Pokemon, with an optional
 * message. The message part is only filled by the turn end handlers.
 */
typedef struct {
    u32 header;
    u32 sickKind;
    union SickCont sickCont;
    u8 hideMessage;
    u8 pad0D[2];
    u8 pokeId;
    u8 pad10[4];
    BtlStrParam strParam;
} BtlItemAddSickCmd;

/* Services of the event factor and the item parameters. */
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);

extern int HAND_ITEM_GetParam(struct BtlEventFactor *factor, int index);

extern int HAND_ITEM_GetBoostRatio(struct BtlEventFactor *factor);

extern u16 BTL_POKEPARAM_GetSpecies(struct BtlPokeParam *poke);


extern void BTL_SERVER_FLOW_TryFinishMainCounter(struct BtlServerFlow *flow, int pokeId);

extern int BTLV_CORE_EventTrySetFlagIfAttacker(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

extern union SickCont BTLV_CORE_MakeSlotKind1Index15(void);

extern union SickCont BTL_CALC_MakeDefaultSickCont(int sickKind);

/* The move power handler shared by all type boost items. */
void HAND_ITEM_BoostMovePowerOfType(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int moveType);

/* Deprecated names of event variable keys, kept for files not yet cleaned. */

/* Event variable keys that only these items use. */

/* Record kinds that these handlers push to the flow. */

#define BTL_CMD_KIND_LOSE_HP 7


#define BTL_CMD_KIND_ITEM_MESSAGE 0x23   /* guess: message with the user and a second Pokemon as arguments */

#define BTL_CMD_KIND_FORCE_SWITCH 0x2E   /* guess */

/* Species and move class constants that the Orbs test. */
#define SPECIES_DIALGA 483

#define SPECIES_PALKIA 484

/* Indexes of the item parameter reader. */
#define BTL_ITEM_PARAM_DAMAGE_DIVISOR 2  /* Rocky Helmet: fraction of the attacker's max HP is 1/this */

#define BTL_FIELD_EFFECT_GRAVITY_QUERY 2 /* guess: argument of the field effect check Air Balloon makes */

#define BTL_STR_TYPE_STANDARD 2

/* Kind 7: remove hit points of a Pokemon, then show a message at +0xC. */
typedef struct {
    u32 header;
    u16 amount;
    u8 pokeId;
    u8 pad07[5];
    BtlStrParam strParam;
} BtlLoseHpCmd;

/* Kind 0x20: change the held item of a Pokemon (itemId 0 removes it), then show a message at +0xC. */
typedef struct {
    u32 header;
    u16 itemId;
    u8 pokeId;
    u8 announce;
    u32 pad08;
    BtlStrParam strParam;
} BtlItemSetItemCmd;

/* Kind 0x23: a message at +8 whose arguments are poke ids. */
typedef struct {
    u32 header;
    u32 pad04;
    BtlStrParam strParam;
} BtlItemMessageCmd;

/* Kind 0x2E: force a Pokemon out of the field; mode is the high nibble of byte 7. */
typedef struct {
    u32 header;
    u16 strId;       /* guess: 0x28C */
    u8 pokeId;
    u8 modeLow : 4;
    u8 mode : 4;
} BtlForceSwitchCmd;

#define BTL_FORCE_SWITCH_MODE_ITEM 1

#define BTL_FORCE_SWITCH_STR_ID 0x28C

extern int BTL_CALC_DivideMaxHpMin1(struct BtlPokeParam *pokeParam, u32 divisor);

extern int BTL_SERVER_FLOW_IsPokeEvolvable(struct BtlServerFlow *flow, int pokeId);    /* guess: the Pokemon can still evolve */

extern int BTL_FIELD_GetStaticSlotObject(int query);

extern int HAND_COMMON_IsMoveTarget(int pokeId);


extern int BTL_SERVER_FLOW_CheckClientHasBackupPoke(struct BtlServerFlow *flow, int pokeId);

extern int BTL_SERVER_FLOW_CheckShowdownThunk(struct BtlServerFlow *flow);

extern u32 BTL_SERVER_FLOW_IsActionCounterSet(struct BtlServerFlow *flow);

extern u32 WAZA_TOOL_GetFlag(u16 moveId, u32 flagBit);





#define BTL_CMD_KIND_SWITCH_OUT 0x29

#define BTL_STR_TYPE_SET 1           /* message of a set (item or ability line) */

#define BTL_STR_ID_EJECT_BUTTON 0x19E  /* message of the Eject Button switch out */

#define BTL_STR_ID_GEM_BOOST 0xB6    /* "the gem strengthened the move" */





/* Types of the gems (type ids of the moves). */

/* Kind 0x29: switch the Pokemon out after a message at +4. */
typedef struct {
    u32 header;
    BtlStrParam strParam;
    u8 pad28[0x24];
    u8 pokeId;
} BtlSwitchOutCmd;


/* Kind 0x14: change the type of a Pokemon to a packed type pair (the same type twice). */
typedef struct {
    u32 header;
    u16 typePair;
    u8 pokeId;
} BtlChangeTypeCmd;

/* Services used by the handlers of this part. */
extern void BTLV_CORE_SetSlotFlag(u32 *packedCont, int slot);

extern int func_021D5D14(struct BtlPokeParam *pokeParam, int statId, int amount);

extern void HAND_ITEM_PushUseItem(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

extern int BTL_SERVER_FLOW_IsPokeAfflictedByStatus(struct BtlServerFlow *flow, int pokeId);

extern u32 BTL_SERVER_FLOW_TestStateFlagBit0(struct BtlServerFlow *flow);

extern int BTL_SERVER_FLOW_TrySetOnceFlag(struct BtlServerFlow *flow);


extern int func_0689C8EC(u16 moveId);

extern int BTL_EVENT_IsFactorDead(struct BtlEventFactor *factor);

extern void BTL_EVENT_MarkFactorDead(struct BtlEventFactor *factor);


extern struct BtlEventFactor *BTL_EVENT_FindFactor(int factorType, int ownerId);

extern struct BtlEventFactor *BTL_EVENT_FindNextFactor(struct BtlEventFactor *factor);

extern u32 BTL_EVENT_GetFactorWork(struct BtlEventFactor *factor, int index);

extern void BTL_EVENT_RemoveFactor(struct BtlEventFactor *factor);

extern u8 BTL_POKEPARAM_GetMoveCount(struct BtlPokeParam *bpp);

extern u16 BTL_POKEPARAM_GetMoveId(struct BtlPokeParam *bpp, int slot);

extern u8 WAZA_TOOL_GetType(u32 moveId);

extern int BTL_POKEPARAM_HasType(struct BtlPokeParam *bpp, int type);

extern u32 BTL_CALC_Random(u32 range);

extern u16 BTLV_CORE_PackByteTwice(int value);

#endif
