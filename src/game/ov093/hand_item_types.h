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
#include "hand_tokusei_021d93d8_types.h"
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
#define HANDEX_KIND_MESSAGE 4

#define HANDEX_KIND_RECOVER_HP 5

#define HANDEX_KIND_ADD_SICK 0xc

#define HANDEX_KIND_RANK_EFFECT 0xe

#define HANDEX_KIND_SET_CONT_FLAG 0x17

/* Event variables the item handlers read with the event variable getter. */

/* Type affinity values above this are super effective. */
#define BTL_AFFINITY_SUPER_EFFECTIVE_ABOVE 3

/* Value ids of the poke parameter getter. */
#define BTL_VALUE_MAX_HP 0xe

/* Status ids. */
#define BTL_SICK_CONFUSION 6

#define BTL_SICK_ITEM_BLOCK 15 /* the status that stops a held item from acting (guess: Embargo) */

/* Stat ids of the rank (stat stage) records; also the numbers the stat berries use. */
#define BTL_RANK_ATTACK 1

#define BTL_RANK_DEFENSE 2

#define BTL_RANK_SP_ATTACK 3

#define BTL_RANK_SP_DEFENSE 4

#define BTL_RANK_SPEED 5

#define BTL_RANK_KIND_COUNT 5

/* Pokemon type ids (a dense list: there is no unused slot between steel and fire). */
enum {
    POKETYPE_NORMAL = 0,
    POKETYPE_FIGHTING = 1,
    POKETYPE_FLYING = 2,
    POKETYPE_POISON = 3,
    POKETYPE_GROUND = 4,
    POKETYPE_ROCK = 5,
    POKETYPE_GHOST = 7,
    POKETYPE_STEEL = 8,
    POKETYPE_ELECTRIC = 12,
    POKETYPE_PSYCHIC = 13,
    POKETYPE_DRAGON = 15,
    POKETYPE_DARK = 16
};

/* Condition flag that the critical-rate berry sets. */
#define BTL_CONT_FLAG_CRITICAL_UP 9

/* Slots of the per-item work words the handlers share. */
#define ITEM_WORK_USED 0       /* nonzero once the item has acted */

#define ITEM_WORK_FORCED_USE 6 /* set when the item was used from outside (same slot as hand_tokusei_021dcae8_types.h) */

/* A message with up to eight word arguments, embedded in some records. */
typedef struct {
    u16 strId;
    u8 strType;
    u8 argCount : 7;
    u8 extraSet : 1;
    u32 args[8];
} HandExStr;

#define HANDEX_STR_SET 2 /* message type: show a message by id with a Pokemon name */

/* Kind 4: show a message. */
typedef struct {
    u32 header;
    HandExStr str;
} HandExMessage;

/* Kind 5: heal a Pokemon; the message is at +8. */
typedef struct {
    u32 header;
    u16 amount;
    u8 pokeId;
    u8 pad07;
    HandExStr str;
} HandExRecoverHp;

/* Kind 0xc: add a status condition. */
typedef struct {
    u32 header;
    u32 sickKind;
    union SickCont sickCont;
    u8 suppressMessage;
    u8 pad0D[2];
    u8 pokeId;
} HandExAddSick;

/* Kind 0xe: change a stat stage (volume is the number of stages). */
typedef struct {
    u32 header;
    u32 rankKind;
    u8 pad08[4];
    s8 volume;
    u8 flagA;
    u8 flagB;
    u8 pokeCount;
    u8 pokeId;
} HandExRankEffect;

/* Kind 0x17: set a condition flag on a Pokemon. */
typedef struct {
    u32 header;
    u32 flagId;
    u8 pokeId;
} HandExSetContFlag;

/* Deprecated names of event variable keys, kept for files not yet cleaned. */
#define BTL_EVAR_HIT_SUBSTITUTE BTL_EVAR_HIT_SUBSTITUTE_FLAG

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

/* More event variable keys (see hand_item_types.h for the first ones). */
#ifndef BTL_EVAR_ATTACKER_ID

#endif

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

/* Deprecated names of event variable keys, kept for files not yet cleaned. */
#define BTL_EVAR_MOVE_CATEGORY BTL_EVAR_DAMAGE_TYPE

#ifndef BTL_EVAR_ATTACKER_ID

#endif

#define BTL_ITEM_DITTO_SPECIES 0x84

#define BTL_SICK_MOVE_LOCK 0x1b     /* choice item lock */

#define BTL_SICK_INFATUATION 7

#define BTL_SICK_BIND 8

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
    HandExStr str;
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
    HandExStr str;
} HandExAddSickFull;

/* Kind 0x23: consume the item and show a message at +8. */
typedef struct {
    u32 header;
    u8 pad04[4];
    HandExStr str;
} HandExConsumeItem;

/* Kind 0x24: move the held item of the attacker to the holder. */
typedef struct {
    u32 header;
    u8 pokeId;
} HandExStealItem;

/* Deprecated names of event variable keys, kept for files not yet cleaned. */

#define BTL_EVAR_AFFINITY_SCALED BTL_EVAR_TYPE_AFFINITY

#define BTL_EVAR_SURVIVE_RESULT BTL_EVAR_ENDURE_REASON

#define BTL_EVAR_NO_EFFECT_FLAG BTL_EVAR_SHEER_FORCE_FLAG

#define BTL_EVAR_SKIP_CHARGE_FLAG BTL_EVAR_FORCE_FLOATING_FLAG

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

#define BTL_SPECIES_GIRATINA 0x1E7

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
#define BTL_CMD_KIND_MESSAGE 4

#define BTL_CMD_KIND_ADD_SICK 12

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
    union BtlSickCont sickCont;
    u8 hideMessage;
    u8 pad0D[2];
    u8 pokeId;
    u8 pad10[4];
    BtlStrParam strParam;
} BtlAddSickCmd;

/* Services of the event factor and the item parameters. */
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);

extern int HAND_ITEM_GetParam(struct BtlEventFactor *factor, int index);

extern int HAND_ITEM_GetBoostRatio(struct BtlEventFactor *factor);

extern u16 BTL_POKEPARAM_GetSpecies(struct BtlPokeParam *poke);

extern void BTL_SERVER_FLOW_SetMsgRecordSe(BtlStrParam *strParam, u32 extraArg);

extern void BTL_SERVER_FLOW_TryFinishMainCounter(struct BtlSvFlow *flow, int pokeId);

extern int BTLV_CORE_EventTrySetFlagIfAttacker(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);

extern union BtlSickCont BTLV_CORE_MakeSlotKind1Index15(void);

extern union BtlSickCont BTL_CALC_MakeDefaultSickCont(int sickKind);

/* The move power handler shared by all type boost items. */
void HAND_ITEM_BoostMovePowerOfType(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int moveType);

/* Deprecated names of event variable keys, kept for files not yet cleaned. */
#define BTL_EVAR_MOVE_POWER_RATIO BTL_EVAR_POWER_RATIO

/* Event variable keys that only these items use. */

/* Record kinds that these handlers push to the flow. */
#define BTL_CMD_KIND_MESSAGE 4

#define BTL_CMD_KIND_LOSE_HP 7

#define BTL_CMD_KIND_SET_ITEM 0x20

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
} BtlSetItemCmd;

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

extern int BTL_SERVER_FLOW_IsPokeEvolvable(struct BtlSvFlow *flow, int pokeId);    /* guess: the Pokemon can still evolve */

extern int BTL_FIELD_GetStaticSlotObject(int query);

extern int func_021E85F8(int pokeId);

extern int BTL_SERVER_FLOW_GetFrontPosOfPoke(struct BtlSvFlow *flow, int pokeId);

extern int BTL_SERVER_FLOW_CheckClientHasBackupPoke(struct BtlSvFlow *flow, int pokeId);

extern int BTL_SERVER_FLOW_CheckShowdownThunk(struct BtlSvFlow *flow);

extern u32 BTL_SERVER_FLOW_IsActionCounterSet(struct BtlSvFlow *flow);

extern u32 WAZA_TOOL_GetFlag(u16 moveId, u32 flagBit);

#ifndef BTL_EVAR_SICK_CONT

#define BTL_EVAR_SICK_CONT 0x1E      /* packed duration and parameters of the status being applied */

#endif

#ifndef BTL_RANK_ATTACK

#define BTL_RANK_ATTACK 1

#endif

#ifndef BTL_RANK_SP_ATTACK

#endif

#ifndef BTL_CMD_KIND_RANK_CHANGE

#define BTL_CMD_KIND_RANK_CHANGE 0xE

#endif

#define BTL_CMD_KIND_SWITCH_OUT 0x29

#define BTL_STR_TYPE_SET 1           /* message of a set (item or ability line) */

#define BTL_STR_ID_EJECT_BUTTON 0x19E  /* message of the Eject Button switch out */

#define BTL_STR_ID_GEM_BOOST 0xB6    /* "the gem strengthened the move" */

#define BTL_GEM_STATE_IDLE 0

#define BTL_GEM_STATE_CONSUMED 1     /* the gem was used for this move; the power boost applies */

#define BTL_GEM_STATE_DONE 2         /* the damage of the move is finished */

#define BTL_GEM_RATIO 0x1800         /* 1.5 in 20.12 fixed point */

/* Types of the gems (type ids of the moves). */
#ifndef POKETYPE_NORMAL

#endif

/* Kind 0x29: switch the Pokemon out after a message at +4. */
typedef struct {
    u32 header;
    BtlStrParam strParam;
    u8 pad28[0x24];
    u8 pokeId;
} BtlSwitchOutCmd;

#define BTL_CMD_KIND_CHANGE_TYPE 0x14

/* Kind 0x14: change the type of a Pokemon to a packed type pair (the same type twice). */
typedef struct {
    u32 header;
    u16 typePair;
    u8 pokeId;
} BtlChangeTypeCmd;

/* One row of the move handler registry: move id and the function that returns its handler table. */
typedef struct {
    u16 moveId;
    BtlEventHandler *(*getHandlers)(int *handlerCount);
} WazaHandlerEntry;

#define WAZA_HANDLER_REGISTRY_COUNT 0x102

#define BTL_EVENT_TYPE_WAZA 0

#define WAZA_HANDLER_FACTOR_LIMIT 8       /* at most 9 factors are scanned; a longer list refuses a new handler */

#define BTL_FACTOR_WORK_KEEP 6            /* work slot: nonzero for a handler that stays active */

/* Services used by the handlers of this part. */
extern void BTLV_CORE_SetSlotFlag(u32 *packedCont, int slot);

extern int func_021D5D14(struct BtlPokeParam *pokeParam, int statId, int amount);

extern void HAND_ITEM_PushUseItem(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);

extern int BTL_SERVER_FLOW_IsPokeAfflictedByStatus(struct BtlSvFlow *flow, int pokeId);

extern u32 BTL_SERVER_FLOW_TestStateFlagBit0(struct BtlSvFlow *flow);

extern int BTL_SERVER_FLOW_TrySetOnceFlag(struct BtlSvFlow *flow);

extern int WAZA_TOOL_IsDamaging(u16 moveId);

extern int func_0689C8EC(u16 moveId);

extern int BTL_EVENT_IsFactorDead(struct BtlEventFactor *factor);

extern void BTL_EVENT_MarkFactorDead(struct BtlEventFactor *factor);

extern struct BtlEventFactor *BTL_EVENT_AddFactor(int factorType, u32 key, int priority, u32 subPriority, u8 ownerId, BtlEventHandler *handlers, u16 handlerCount);

extern struct BtlEventFactor *BTL_EVENT_FindFactor(int factorType, int ownerId);

extern struct BtlEventFactor *BTL_EVENT_FindNextFactor(struct BtlEventFactor *factor);

extern u32 BTL_EVENT_GetFactorWork(struct BtlEventFactor *factor, int index);

extern void BTL_EVENT_RemoveFactor(struct BtlEventFactor *factor);

extern u8 BTL_POKEPARAM_GetMoveCount(struct BtlPokeParam *bpp);

extern u16 BTL_POKEPARAM_GetMoveId(struct BtlPokeParam *bpp, int slot);

extern u8 WAZA_TOOL_GetType(u32 moveId);

extern int BTL_POKEPARAM_HasType(struct BtlPokeParam *bpp, int type);

extern u32 BTL_CALC_Random(u32 range);

extern int BTLV_CORE_PackByteTwice(int value);

#endif
