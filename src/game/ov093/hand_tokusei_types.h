#ifndef UNIT_021D93D8_TYPES_H
#define UNIT_021D93D8_TYPES_H
#include "hand_common_types.h"
#include "btl_pokeparam_types.h"
#include "hand_common_protos.h"
/*
 * ov093 ability handlers (second part): Frisk, Sturdy, Unaware, Heatproof,
 * Dry Skin, Water Absorb, Volt Absorb, Motor Drive, Scrappy, Soundproof,
 * Levitate, Wonder Guard, Truant, Damp, Flash Fire, Bad Dreams. Every handler
 * takes the factor that owns it, the server flow and the id of the Pokemon
 * that owns the factor, and the four-argument form adds the factor's work words.
 */
#include "btl_event_types.h"
/*
 * ov093 ability handlers (Run Away, Mold Breaker, Forecast, Storm Drain,
 * Lightning Rod, Suction Cups, Liquid Ooze, Klutz, Sticky Hold, Pressure,
 * Magic Guard, Stench, Shadow Tag, Arena Trap): the command records that the
 * handlers push to the battle server flow, and the event variable keys they use.
 */
#include "btl_action_word_types.h"

/*
 * ov093 battle ability handlers (status guards, weather abilities, weather
 * recovery, stat guards). Each ability is a handler table (event id plus
 * function) that its getter returns; the handlers answer battle events and
 * queue commands on the battle flow.
 */

#include "../types.h"

/* Event variable keys read and rewritten by the handlers. */

/* Status condition slots of BtlPokeParam.sickCont (1..5 are the major statuses). */
#define TKS_SICK_PARALYSIS 1

#define TKS_SICK_SLEEP 2

#define TKS_SICK_FREEZE 3

#define TKS_SICK_BURN 4

#define TKS_SICK_POISON 5

#define TKS_SICK_CONFUSION 6

#define TKS_SICK_INFATUATION 7

/* Weather ids returned by the flow and stored in weather commands. */
#define TKS_WEATHER_SUN 1

#define TKS_WEATHER_RAIN 2

#define TKS_WEATHER_HAIL 3

#define TKS_WEATHER_SAND 4

/* Command kind 4: a message shown on the battle screen (strParam at +4). */
typedef struct {
    u32 flags;
    BtlStrParam strParam;
} TokuseiMessageCmd;

/* Command kind 0xb: cure one status slot of a Pokemon (0x24 = every major status). */
typedef struct {
    u32 flags;
    u32 sickIndex;
    u8 pokeId;
    u8 pad9[11];
    u8 showMessage;
} TokuseiCureSickCmd;

/* Command kind 0x1d: change the weather (turns 0xff = no limit); strParam at +8. */
typedef struct {
    u32 flags;
    u8 weather;
    u8 turns;
    u8 announce;
    u8 pad7;
    BtlStrParam strParam;
} TokuseiWeatherCmd;

/* Command kinds 5 and 7: restore (5) or remove (7) hit points of a Pokemon. */
typedef struct {
    u32 flags;
    u16 amount;
    u8 pokeId;
} TokuseiHpCmd;

/* Deprecated names of event variable keys, kept for files not yet cleaned. */
#define TKS_EVAR_POKE_ID BTL_EVAR_POKE_ID

#define TKS_EVAR_ATTACKER_ID BTL_EVAR_ATTACKER_ID

#define TKS_EVAR_DEFENDER_ID BTL_EVAR_DEFENDER_ID

#define TKS_EVAR_MOVE_ID BTL_EVAR_MOVE_ID

#define TKS_EVAR_CONDITION BTL_EVAR_SICK_ID

#define TKS_EVAR_CHANGE_AMOUNT BTL_EVAR_EFFECT_PERCENT

#define TKS_EVAR_POWER_RATIO BTL_EVAR_RATIO

#define TKS_EVAR_WEATHER BTL_EVAR_WEATHER

#define TKS_EVAR_FAIL_FLAG BTL_EVAR_FORCE_GROUNDED_FLAG

/*
 * ov093 ability handlers (the second half of the ability handler file): the
 * effect records a handler pushes to the battle flow, and the event variable
 * numbers the handlers read.
 *
 * A handler asks the flow for a record of one kind (HANDEX_KIND_*), fills the
 * fields that kind uses and hands it back. The record buffer is reused, so
 * each kind has its own struct; all of them start with the 32-bit header.
 */

struct BtlServerFlow;

/* Record kinds. The two window kinds carry no record: they open and close the ability window. */

#define HANDEX_KIND_CHANGE_FORM 0x14

#define HANDEX_KIND_CHANGE_ABILITY 0x1f

#define HANDEX_ABILITY_WINDOW_IN 2

#define HANDEX_ABILITY_WINDOW_OUT 3

/* Header flags (guessed from the abilities that set them). */
#define HANDEX_FLAG_SHOW_ABILITY (1 << 23)

#define HANDEX_FLAG_SHOW_CURE_MESSAGE (1 << 25)

/* Event variables a handler reads with the event-variable getter. */

/* Status ids as the handlers use them. */

/* Value ids for the Pokemon value getter. */
#define BPP_VALUE_DEFENSE 9

#define BPP_VALUE_SP_DEFENSE 0xb

#define BPP_VALUE_GENDER 0x12

#define BPP_VALUE_ABILITY 16

#define BTL_GENDER_NONE 2

/* "No Pokemon" id and "no slot" value. */
#define BTL_POKEID_NONE 0x1f

#define BTL_SLOT_NONE 6

/* Rank (stat stage) kinds used by Download. */

#define HANDEX_MESSAGE_SET 2 /* message kind: show a message by id */

/* Kind 0x1f: replace the ability of a Pokemon. */
struct HandExChangeAbility {
    u32 header;
    u16 abilityId;
    u8 pokeId;
    u8 pad7;
    u8 announce;
    u8 pad9[3];
    BtlStrParam message;
};

/* Deprecated names of event variable keys, kept for files not yet cleaned. */
#define HANDVAR_POKE_ID BTL_EVAR_POKE_ID

#define HANDVAR_ATTACKER_ID BTL_EVAR_ATTACKER_ID

#define HANDVAR_DEFENDER_ID BTL_EVAR_DEFENDER_ID

#define HANDVAR_MOVE_ID BTL_EVAR_MOVE_ID

#define HANDVAR_WEATHER BTL_EVAR_MOVE_TYPE

#define HANDVAR_SICK_ID BTL_EVAR_SICK_ID

#define HANDVAR_SICK_CONT BTL_EVAR_SICK_CONT

#define HANDVAR_CRITICAL_RANK BTL_EVAR_CRITICAL_RANK

#define HANDVAR_SICK_DAMAGE BTL_EVAR_DAMAGE

#define HANDVAR_GENERAL_FLAG BTL_EVAR_FORCE_GROUNDED_FLAG

#define HANDVAR_CRITICAL_HIT BTL_EVAR_CRITICAL_FLAG

#define HANDVAR_HIT_SUBSTITUTE BTL_EVAR_HIT_SUBSTITUTE_FLAG

/* Weather ids of BTL_EVAR_WEATHER. */

/* Type affinity classes: 3 is neutral, higher is super effective. */
#define BTL_AFFINITY_NEUTRAL 3

/* Type ids. */

/* Stat ids of the rank commands. */

/* Value of BTL_EVAR_ENDURE_REASON that marks an endure by Sturdy. */
#define BTL_ENDURE_REASON_STURDY 4

/* Stat stage 6 is the neutral stage (no boost). */
#define BTL_STAT_STAGE_NEUTRAL 6

/* Major status ids. */
enum {
    BTL_SICK_SLEEP = 2,
    BTL_SICK_BURN = 4
};

/* Ratios in 20.12 fixed point (0x1000 is 1.0). */
enum {
    BTL_RATIO_1_25 = 0x1400
};

#define BTL_MOVE_SELF_DESTRUCT 120

#define BTL_MOVE_EXPLOSION 153

#define BTL_MOVE_STRUGGLE 165

#define BTL_WAZA_FLAG_SOUND 8

/* Ability ids that a handler tests. */
#define ABILITY_AFTERMATH 106

/* Event type of ability factors (the factorType argument of a skip check). */

/* Cont flag index that Flash Fire sets on its owner. */
#define BTL_CONT_FLAG_FLASH_FIRE 13

/* Fail reason that Truant and Damp write to BTL_EVAR_FAIL_REASON. */
#define BTL_FAIL_REASON_ABILITY 19

/* Header flag that ability commands set. */

/* Command kinds that BTL_SERVER_FLOW_AllocCmdRecord reserves. */
enum {
    BTL_CMD_MESSAGE = 4,
    BTL_CMD_RECOVER_HP = 5,
    BTL_CMD_DAMAGE = 7,
    BTL_CMD_RANK = 14,
    BTL_CMD_SET_CONT_FLAG = 0x17,
    BTL_CMD_CLEAR_CONT_FLAG = 0x18
};

/* States of the ability pop-up window (BTL_SERVER_FLOW_PushCmdRecord). */
enum {
    BTL_ABILITY_POPUP_OPEN = 2,
    BTL_ABILITY_POPUP_CLOSE = 3
};

/* String type of BTL_SERVER_FLOW_InitMsgRecord: a standard battle message. */
#define BTL_STR_TYPE_STD 2

/* Message ids. */
enum {
    BTL_MSG_ABILITY_NO_EFFECT = 0xD2,
    BTL_MSG_ABSORB_RECOVER_HP = 0x183,
    BTL_MSG_FLASH_FIRE_ABSORB = 0x1AB,
    BTL_MSG_FRISK_ITEM = 0x1B7,
    BTL_MSG_TRUANT_LOAFING = 0x1BD,
    BTL_MSG_BAD_DREAMS_HURT = 0x1E4,
    BTL_MSG_STURDY_ENDURE = 0x202,
    BTL_MSG_DAMP_BLOCK = 0x389
};

/* Kind 5: restore HP of one Pokemon. */
typedef struct {
    u32 header;
    u16 amount;
    u8 pokeId;
    u8 pad07;
    BtlStrParam strParam;
} BtlRecoverHpCmd;

/* Kind 7: hurt one Pokemon. */
typedef struct {
    u32 header;
    u16 amount;
    u8 pokeId;
    u8 pad07[5];
    BtlStrParam strParam;
} BtlDamageCmd;

/* Kinds 0x17 and 0x18: set or clear one cont flag of a Pokemon. */
typedef struct {
    u32 header;
    u32 flagIndex;
    u8 pokeId;
} BtlContFlagCmd;

/* Services of the event variable stack. */
extern void BTL_EVENT_ClearFactorSkipCheck(struct BtlEventFactor *factor);

/* Services of the battle server flow. */

/* Services of the calculation and of the poke parameter. */
extern u32 BTL_CALC_Random(u32 range);

extern int BTL_CALC_Max(int value, int floor);

extern int BTL_POKEPARAM_IsHpFull(struct BtlPokeParam *bpp);

extern int BTL_POKEPARAM_CanChangeStatStage(struct BtlPokeParam *bpp, int statId, int amount);

/* Deprecated names of event variable keys, kept for files not yet cleaned. */

struct BtlEventFactor;

/* Poke parameter values read through BTL_POKEPARAM_GetValue. */
enum {
    BPP_VALUE_CURRENT_ABILITY = 0x11,
    BPP_VALUE_FORM = 0x13
};

#define SPECIES_CASTFORM 0x15F

#define BTL_STAT_SP_ATTACK 3

/* Command kinds that the handlers pass to BTL_SERVER_FLOW_AllocCmdRecord and BTL_SERVER_FLOW_PushCmdRecord. */
enum {
    HANDEX_TOKWIN_IN = 2,
    HANDEX_TOKWIN_OUT = 3,
    HANDEX_MESSAGE = 4,
    HANDEX_DAMAGE = 7,
    HANDEX_POKE_NOTICE = 0x21,
    HANDEX_CHANGE_FORM = 0x39
};

/* HANDEX_CHANGE_FORM: set the form of a poke, then show a string. */
typedef struct HandExChangeForm {
    u32 header;
    u8 pokeId;
    u8 form;
    u8 pad06[2];
    BtlStrParam message;
} HandExChangeForm;

/* HANDEX_POKE_NOTICE: names one poke and nothing else. */
typedef struct HandExPokeNotice {
    u32 header;
    u8 pokeId;
} HandExPokeNotice;

extern u8 BTL_EVENT_GetFactorPokeId(struct BtlEventFactor *factor);

extern void BTL_SERVER_FLOW_SetMsgRecordSe(void *str, u32 extra);

extern int BTL_SERVER_FLOW_IsPokeGroundedById(struct BtlServerFlow *flow, int pokeId);

extern int HAND_COMMON_IsMoveTarget(int pokeId);

/* Deprecated names of event variable keys, kept for files not yet cleaned. */

/* Services of the battle server flow and the event factor list used by several of these files. */

/*
 * ov093 battle ability handlers (third part): Magnet Pull, Unburden, Pickup,
 * Pickpocket, Cursed Body, Weak Armor, Sheer Force, Defiant, Defeatist,
 * Multiscale, Friend Guard, Healer, Toxic Boost, Flare Boost, Telepathy,
 * Moody, Overcoat, Poison Touch, Regenerator, Wonder Skin, Sand Rush and
 * Analytic. Every handler takes the factor that owns it, the server flow and
 * the id of the Pokemon that owns the factor; the four-argument form adds the
 * work words of the factor. A getter stores the handler count and returns the
 * handler table (event id plus function pairs) of one ability.
 */

struct BtlPokeParam;

#define BTL_DAMAGE_TYPE_STATUS 0

#define BTL_DAMAGE_TYPE_PHYSICAL 1

#define BTL_DAMAGE_TYPE_SPECIAL 2

/* Stat ids of the rank commands, in the order of the stat stage table. */
enum {
    BTL_STAT_ATTACK = 1,
    BTL_STAT_DEFENSE = 2,
    BTL_STAT_SPEED = 5,
    BTL_STAT_COUNT_RANKED = 7     /* attack, defense, special attack, special defense, speed, accuracy, evasion */
};

/* Value ids of the poke parameter getter. */
#define BTL_POKEPARAM_VALUE_HP 0xD

#define BTL_POKEPARAM_VALUE_MAX_HP 0xE

/* Turn flag ids of the poke parameter. */
#define BTL_TURN_FLAG_ACTED 1

#define BTL_TURN_FLAG_ITEM_USED 8       /* guess */

/* Status condition slots of a Pokemon. */

#define BTL_SICK_DISABLE 0xD

#define BTL_MOVE_SECRET_POWER 290

#define BTL_WAZA_FLAG_CONTACT 0

/* Fields of the move parameter getter that the Sheer Force test reads. */
#define BTL_WAZA_PARAM_ADDED_EFFECT_RATE 10   /* guess */

#define BTL_WAZA_PARAM_ADDED_EFFECT_KIND 11   /* guess */

/* Damage classes of the move data (WAZA_TOOL_GetCategory). */
enum {
    BTL_WAZA_CATEGORY_DAMAGE_PLUS_EFFECT = 4,
    BTL_WAZA_CATEGORY_DAMAGE_PLUS_SICK = 6,
    BTL_WAZA_CATEGORY_DAMAGE_PLUS_RANK = 7
};

/* Ratios in 20.12 fixed point (0x1000 is 1.0). */

/* Header flags of the commands that the handlers queue. */

#define BTL_CMD_FLAG_ABILITY_ON_ALLY (1u << 25)   /* guess: Healer sets it with the ability flag */

/* Command kinds that BTL_SERVER_FLOW_AllocCmdRecord reserves. */
enum {
    BTL_CMD_KIND_REGENERATE_HP = 8,
    BTL_CMD_KIND_CURE_SICK = 0xB,
    BTL_CMD_KIND_RANK_EFFECT = 0xE,
    BTL_CMD_KIND_STEAL_ITEM = 0x24
};

/* Cure kind that removes every major status condition. */
#define BTL_CURE_ALL_MAJOR 0x24

/* Message ids. */
enum {
    BTL_MSG_TELEPATHY_AVOID = 0x1D5,
    BTL_MSG_POISON_TOUCH = 0x1D8,
    BTL_MSG_PICKPOCKET = 0x1CC,
    BTL_MSG_PICKUP = 0x1EA
};

/* Kind 8: restore hit points of one Pokemon without a message (Regenerator). */
typedef struct {
    u32 flags;
    u8 mode;
    u8 showBar;
    u8 pad06;
    u8 pokeId;
    u8 pad08[8];
    u32 amount;
} BtlRegenerateHpCmd;

/* Kind 0xB: cure one status slot of a Pokemon (0x24 = every major status). */
typedef struct {
    u32 flags;
    u32 sickIndex;
    u8 pokeId;
    u8 pad09[11];
    u8 showMessage;
} BtlCureSickCmd;

/* Kind 0xC: give a status condition to a Pokemon; strParam at +0x14. */
typedef struct {
    u32 flags;
    u32 sickId;
    union SickCont sickCont;
    u8 pad0C[3];
    u8 targetId;
    u8 pad10[4];
    BtlStrParam strParam;
} BtlAddSickCmd;

/* Kind 0x20: set the held item of a Pokemon (Pickup); strParam at +0xC. */
typedef struct {
    u32 flags;
    u16 itemId;
    u8 pokeId;
    u8 pad07;
    u8 clearConsumed;
    u8 sourcePokeId;
    u8 pad0A[2];
    BtlStrParam strParam;
} BtlSetItemCmd;

/* Kind 0x24: take the held item of another Pokemon (Pickpocket); strParam at +8. */
typedef struct {
    u32 flags;
    u8 victimId;
    u8 pad05[3];
    BtlStrParam strParam;
} BtlStealItemCmd;

/*
 * Scratch block of Pickup (14 bytes, reserved by BTL_SERVER_FLOW_GetScratchBuffer): the Pokemon
 * found around the owner, the ones that used an item, and the count.
 */
typedef struct {
    u8 candidateIds[6];
    u8 holderIds[6];
    u8 candidateCount;
    u8 spare;
} TokuseiPickupScratch;

/*
 * Scratch block of Moody (0xB6 bytes): the pairs (stat to raise, stat to
 * lower) that can be drawn, then the lists of stats that can still rise and
 * fall.
 */
typedef struct {
    u16 pairs[0x54];
    u8 raisableStats[7];
    u8 lowerableStats[7];
} TokuseiMoodyScratch;

/* Value ids for the battle Pokemon value getter. */

#define BTL_BPP_VALUE_ABILITY 0x10

/* Types that these handlers test (the battle type list, 0 = normal). */

#define WAZA_DAMAGE_STATUS 0

#define WAZA_FLAG_CONTACT 0

/* Event factor type of side conditions such as Reflect and Light Screen (guess). */
#define BTL_EVENT_TYPE_SIDE_CONDITION 2

/* Side condition keys 0 to 3 are the ones that Infiltrator ignores (guess: screens, Safeguard, Mist). */
#define BTL_SIDE_CONDITION_SCREEN_KEY_MAX 3

#define SPECIES_DARMANITAN 555

#define ABILITY_MUMMY 152

/* Rank change stat ids that these handlers use. */
enum {
    BTL_RANK_STAT_ATTACK = 1,
    BTL_RANK_STAT_SPEED = 5
};

/* Server command kinds that these handlers queue. */
enum {
    BTL_CMD_KIND_ABILITY_CHANGE = 0x1f,
    BTL_CMD_KIND_FORM_CHANGE = 0x39
};

/* Message string types and ids (the type values are a guess). */
enum {
    BTL_STR_TYPE_ABILITY_LINE = 1,
    BTL_STR_TYPE_WITH_POKE_NAME = 2
};

enum {
    BTL_STR_ZEN_MODE_ON = 0xb9,
    BTL_STR_ZEN_MODE_OFF = 0xba,
    BTL_STR_MUMMY_SPREAD = 0x1cf
};

/* Command kind 0x39: change the form of a Pokemon (0 = base form, 1 = Zen Mode). */
typedef struct {
    u32 header;
    u8 pokeId;
    u8 form;
    u8 pad06[2];
    BtlStrParam strParam;
} BtlFormChangeCmd;

/* Command kind 0x1f: give a Pokemon a new ability. */
typedef struct {
    u32 header;
    u16 abilityId;
    u8 pokeId;
    u8 pad07[5];
    BtlStrParam strParam;
} BtlAbilityChangeCmd;

extern int BTL_SERVER_FLOW_CheckShowdownThunk(struct BtlServerFlow *flow);

extern void HAND_COMMON_EventRedirectMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, void *work);

extern void HAND_COMMON_EventCounterMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, void *work);

/*
 * ov093 battle event handlers: the last ability handlers (Magic Bounce,
 * Harvest, Heavy Metal, Light Metal, Contrary, Unnerve, Imposter, Illusion,
 * Victory Star) and the first held-item handlers (the item registry, the
 * status-curing berries, Leppa Berry, the HP-restoring berries).
 *
 * An event handler is called as (factor, flow, pokeId, work). It reads event
 * variables and asks the battle server flow for an effect record of one kind
 * (HANDEX_KIND_*). It fills the record and hands it back to the flow.
 */

/* Effect record kinds that the handlers of this file request. */
enum {
    HANDEX_KIND_ABILITY_WINDOW_IN = 2,
    HANDEX_KIND_ABILITY_WINDOW_OUT = 3,
    HANDEX_KIND_RECOVER_PP = 9,
    HANDEX_KIND_CURE_SICK = 0xb,
    HANDEX_KIND_SET_ITEM = 0x20,
    HANDEX_KIND_TRANSFORM = 0x33,
    HANDEX_KIND_END_ILLUSION = 0x34
};

/* Header flag: show the ability window around the effect. */

/* Ratios are fixed point with 4096 = 1.0. */

#define BTL_RATIO_ACCURACY_BOOST 4506

/* Status condition kinds used by the curing berries. */
enum {
    BTL_SICK_PARALYSIS = 1,
    BTL_SICK_FREEZE = 3,
    BTL_SICK_POISON = 5,
    BTL_SICK_ANY = 0x25,
    BTL_SICK_ANY_MAJOR = 0x24
};

/* String record kinds. */
#define HANDEX_STR_STANDARD 1

/* Held-item factor work: slot 6 is set when the item was used from outside. */

/* A move slot index of this value means "none". */
#define BTL_MOVE_SLOT_NONE 4

/* Event factor type of held items. */
#define BTL_EVENT_TYPE_ITEM 5

/* HANDEX_KIND_RECOVER_PP: restore PP of one move slot, then show a string. */
typedef struct HandExRecoverPp {
    u32 header;
    u8 volume;
    u8 pokeId;
    u8 moveSlot;
    u8 showItem : 1;
    u8 pad07 : 7;
    BtlStrParam message;
} HandExRecoverPp;

/* HANDEX_KIND_END_ILLUSION: drop the Illusion disguise, then show a string. */
typedef struct HandExEndIllusion {
    u32 header;
    u8 pokeId;
    u8 pad05[3];
    BtlStrParam message;
} HandExEndIllusion;

/* Work area of Unnerve: set once the ability window has been shown. */
typedef struct UnnerveWork {
    int announced;
} UnnerveWork;

/* Skip check callback of an event factor: may the factor of the given type, key and owner be skipped? */
typedef int (*BtlSkipCheckFn)(struct BtlEventFactor *factor, void *context, int targetFactorType, int eventId, u16 targetKey, u8 targetOwnerId);

/* One entry of a handler table: event id and handler function. */
typedef struct BtlEventHandlerEntry {
    u32 eventId;
    void *handler;
} BtlEventHandlerEntry;

/* Registry entry of held items: item id and the function that returns the item's handler table. */
typedef struct ItemHandlerEntry {
    u32 itemId;
    u32 (*getHandlers)(u32 *count);
} ItemHandlerEntry;

#define ITEM_HANDLER_COUNT 0xac

/* Battle server flow services. */
extern u8 BTL_SERVER_FLOW_GetPokeIdAtFieldIndex(struct BtlServerFlow *flow, int position);

extern int BTL_SERVER_FLOW_QueryMainFlag(struct BtlServerFlow *flow, int rule);

extern int BTL_CALC_RollChanceOrFlag(struct BtlServerFlow *flow, u32 percent);

extern void HAND_COMMON_EventQueueMoveNotice(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int work);

extern int HAND_ITEM_IsHpAtOrBelowFraction(struct BtlServerFlow *flow, int pokeId, u32 param);

extern void HAND_ITEM_HpBerryCheckAndUse(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int param, int forced);

extern u8 BTL_MAIN_GetFacingPos(int kind, u32 flags);

extern u8 BTL_MAIN_IsZero(u32 side);

/* Event variables and factors. */
extern int BTL_EVENT_TryGetVar(int key, int *out);

extern void BTL_EVENT_EnableFactorSpecialEvent(struct BtlEventFactor *factor);

extern void BTL_EVENT_KeepFactorRunning(struct BtlEventFactor *factor);

extern u32 BTL_EVENT_GetFactorWork(struct BtlEventFactor *factor, int index);

extern void BTL_EVENT_SetFactorWork(struct BtlEventFactor *factor, int index, u32 value);

extern struct BtlEventFactor *BTL_EVENT_FindFactor(int factorType, int ownerId);

extern struct BtlEventFactor *BTL_EVENT_FindNextFactor(struct BtlEventFactor *factor);

extern void BTL_EVENT_DisablePokeFactors(unsigned int ownerId, int factorType);

extern int BTL_EVENT_EnablePokeFactors(int ownerId, int factorType);

extern int BTL_CALC_RollPercent(unsigned int percent);

/* Poke parameters. */
extern u16 BTL_POKEPARAM_GetConsumedItem(struct BtlPokeParam *poke);

extern int BTL_POKEPARAM_IsIllusionActive(struct BtlPokeParam *poke);

extern int BTL_POKEPARAM_GetStatRaw(struct BtlPokeParam *poke, int paramId);

extern int BTL_CALC_FindMajorSick(struct BtlPokeParam *poke);

extern u16 BTL_POKEPARAM_GetLastSelectedMoveId(struct BtlPokeParam *poke);

extern u8 BTL_POKEPARAM_GetMoveCount(struct BtlPokeParam *poke);

extern u8 BTL_POKEPARAM_GetMovePPLost(struct BtlPokeParam *poke, u8 slot);

extern u16 BTL_POKEPARAM_GetMoveId(struct BtlPokeParam *poke, int slot);

extern int PALANM_IsColorCodeKnown(u32 itemId);

#endif
