#ifndef UNIT_021DCAE8_TYPES_H
#define UNIT_021DCAE8_TYPES_H
#include "hand_common_types.h"
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

#ifndef OV093_BASIC_TYPES
#define OV093_BASIC_TYPES
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
#endif

struct BtlSvFlow;
struct BtlEventFactor;
struct BtlPokeParam;

/* Effect record kinds that the handlers of this file request. */
enum {
    HANDEX_KIND_USE_ITEM = 0,
    HANDEX_KIND_ABILITY_WINDOW_IN = 2,
    HANDEX_KIND_ABILITY_WINDOW_OUT = 3,
    HANDEX_KIND_MESSAGE = 4,
    HANDEX_KIND_RECOVER_HP = 5,
    HANDEX_KIND_RECOVER_PP = 9,
    HANDEX_KIND_CURE_SICK = 0xb,
    HANDEX_KIND_SET_ITEM = 0x20,
    HANDEX_KIND_TRANSFORM = 0x33,
    HANDEX_KIND_END_ILLUSION = 0x34
};

/* Header flag: show the ability window around the effect. */
#define HANDEX_FLAG_SHOW_ABILITY (1 << 23)

/* Ratios are fixed point with 4096 = 1.0. */
#define BTL_RATIO_HALF 2048
#define BTL_RATIO_DOUBLE 8192
#define BTL_RATIO_ACCURACY_BOOST 4506

/* Status condition kinds used by the curing berries. */
enum {
    BTL_SICK_PARALYSIS = 1,
    BTL_SICK_SLEEP = 2,
    BTL_SICK_FREEZE = 3,
    BTL_SICK_BURN = 4,
    BTL_SICK_POISON = 5,
    BTL_SICK_CONFUSION = 6,
    BTL_SICK_ANY = 0x25,
    BTL_SICK_ANY_MAJOR = 0x24,
    BTL_SICK_ANY_VOLATILE = 0x26
};

#define BTL_WEATHER_SUN 1

/* String record kinds. */
#define HANDEX_STR_STANDARD 1
#define HANDEX_STR_SET 2

/* Held-item factor work: slot 6 is set when the item was used from outside. */
#define ITEM_WORK_FORCED_USE 6

/* A move slot index of this value means "none". */
#define BTL_MOVE_SLOT_NONE 4

/* Event factor type of held items. */
#define BTL_EVENT_TYPE_ITEM 5

/* A message record inside an effect record: string id, kind, up to 8 arguments. */
typedef struct HandExStr {
    u16 strId;
    u8 strType;
    u8 argCount : 7;
    u8 extraSet : 1;
    u32 args[8];
} HandExStr;

/* HANDEX_KIND_MESSAGE */
typedef struct HandExMessage {
    u32 header;
    HandExStr str;
} HandExMessage;

/* HANDEX_KIND_RECOVER_HP: heal a Pokemon, then show a string. */
typedef struct HandExRecoverHp {
    u32 header;
    u16 amount;
    u8 pokeId;
    u8 pad07;
    HandExStr str;
} HandExRecoverHp;

/* HANDEX_KIND_RECOVER_PP: restore PP of one move slot, then show a string. */
typedef struct HandExRecoverPp {
    u32 header;
    u8 volume;
    u8 pokeId;
    u8 moveSlot;
    u8 showItem : 1;
    u8 pad07 : 7;
    HandExStr str;
} HandExRecoverPp;

/* HANDEX_KIND_CURE_SICK: cure a status condition of up to 12 listed Pokemon. */
typedef struct HandExCureSick {
    u32 header;
    u32 sickKind;
    u8 pokeIds[12];
    u8 pokeCount;
    u8 suppressMessage;
} HandExCureSick;

/* HANDEX_KIND_SET_ITEM: give a Pokemon a held item, then show a string. */
typedef struct HandExSetItem {
    u32 header;
    u16 itemId;
    u8 pokeId;
    u8 announce;
    u32 pad08;
    HandExStr str;
} HandExSetItem;

/* HANDEX_KIND_TRANSFORM: transform into the target Pokemon, then show a string. */
typedef struct HandExTransform {
    u32 header;
    u8 targetPokeId;
    u8 pad05[3];
    HandExStr str;
} HandExTransform;

/* HANDEX_KIND_END_ILLUSION: drop the Illusion disguise, then show a string. */
typedef struct HandExEndIllusion {
    u32 header;
    u8 pokeId;
    u8 pad05[3];
    HandExStr str;
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
extern void *BTL_SERVER_FLOW_AllocCmdRecord(struct BtlSvFlow *flow, int kind, int pokeId);
extern void BTL_SERVER_FLOW_PushCmdRecord(struct BtlSvFlow *flow, int kind, int pokeId);
extern void BTL_SERVER_FLOW_CommitCmdRecord(struct BtlSvFlow *flow, void *record);
extern void BTL_SERVER_FLOW_InitMsgRecord(HandExStr *str, int strType, int strId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(HandExStr *str, u32 arg);
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlSvFlow *flow, int pokeId);
extern int BTL_SERVER_FLOW_GetPokeViewPos(struct BtlSvFlow *flow, int pokeId);
extern int BTL_SERVER_FLOW_GetRule(struct BtlSvFlow *flow);
extern u8 BTL_SERVER_FLOW_GetPokeIdAtFieldIndex(struct BtlSvFlow *flow, int position);
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(struct BtlSvFlow *flow);
extern int BTL_SERVER_FLOW_QueryMainFlag(struct BtlSvFlow *flow, int rule);
extern int BTL_CALC_RollChanceOrFlag(struct BtlSvFlow *flow, u32 percent);
extern void BTLV_CORE_EventQueueMoveNotice(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int work);
extern int HAND_ITEM_IsHpAtOrBelowFraction(struct BtlSvFlow *flow, int pokeId, u32 param);
extern void HAND_ITEM_HpBerryCheckAndUse(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int param, int forced);
extern u8 BTL_MAIN_GetFacingPos(int kind, u32 flags);
extern unsigned char BTL_MAIN_IsPokeIdInSecondPair(unsigned int pokeId);
extern u8 BTL_MAIN_IsZero(u32 side);
extern int BTL_MAIN_IsPokeSamePair(unsigned int pokeIdA, unsigned int pokeIdB);

/* Event variables and factors. */
extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 value);
extern int BTL_EVENT_TryGetVar(int key, int *out);
extern void BTL_EVENT_MultiplyVar(int key, int ratio);
extern void BTL_EVENT_SetFactorSkipCheck(struct BtlEventFactor *factor, BtlSkipCheckFn skipCheck);
extern u8 BTL_EVENT_GetFactorPokeId(struct BtlEventFactor *factor);
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern void BTL_EVENT_EnableFactorSpecialEvent(struct BtlEventFactor *factor);
extern void BTL_EVENT_KeepFactorRunning(struct BtlEventFactor *factor);
extern u32 BTL_EVENT_GetFactorWork(struct BtlEventFactor *factor, int index);
extern void BTL_EVENT_SetFactorWork(struct BtlEventFactor *factor, int index, u32 value);
extern void BTL_EVENT_RemoveFactor(struct BtlEventFactor *factor);
extern struct BtlEventFactor *BTL_EVENT_AddFactor(int factorType, u32 key, int priority, u32 subPriority, u8 ownerId, u32 handlerTable, u16 handlerCount);
extern struct BtlEventFactor *BTL_EVENT_FindFactor(int factorType, int ownerId);
extern struct BtlEventFactor *BTL_EVENT_FindNextFactor(struct BtlEventFactor *factor);
extern void BTL_EVENT_DisablePokeFactors(unsigned int ownerId, int factorType);
extern int BTL_EVENT_EnablePokeFactors(int ownerId, int factorType);
extern int BTL_CALC_RollPercent(unsigned int percent);
extern u32 BTL_CALC_GetMonParamWithHeap(u16 itemId, u32 paramIndex);

/* Poke parameters. */
extern u16 BTL_POKEPARAM_GetConsumedItem(struct BtlPokeParam *poke);
extern u16 BTL_POKEPARAM_GetItem(struct BtlPokeParam *poke);
extern int BTL_POKEPARAM_IsFainted(struct BtlPokeParam *poke);
extern int BTL_POKEPARAM_IsIllusionActive(struct BtlPokeParam *poke);
extern int func_021D58A8(struct BtlPokeParam *poke, int paramId);
extern u8 BTL_POKEPARAM_GetPokeId(struct BtlPokeParam *poke);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct BtlPokeParam *poke);
extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *poke, int sickKind);
extern int BTL_CALC_FindMajorSick(struct BtlPokeParam *poke);
extern u16 BTL_POKEPARAM_GetLastSelectedMoveId(struct BtlPokeParam *poke);
extern u8 BTL_POKEPARAM_FindMoveSlot(struct BtlPokeParam *poke, u16 moveId);
extern u8 BTL_POKEPARAM_GetMovePPChecked(struct BtlPokeParam *poke, u32 slot);
extern u8 BTL_POKEPARAM_GetMoveCount(struct BtlPokeParam *poke);
extern u8 BTL_POKEPARAM_GetMovePPLost(struct BtlPokeParam *poke, u8 slot);
extern u16 BTL_POKEPARAM_GetMoveId(struct BtlPokeParam *poke, int slot);
extern int PALANM_IsColorCodeKnown(u32 itemId);

/* Deprecated names of event variable keys, kept for files not yet cleaned. */
#define BTL_EVAR_HIT_SUBSTITUTE BTL_EVAR_HIT_SUBSTITUTE_FLAG
#define BTL_EVAR_HANDLED_FLAG BTL_EVAR_FORCE_FLOATING_FLAG

#endif
