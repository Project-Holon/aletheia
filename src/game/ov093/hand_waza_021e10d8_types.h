#ifndef HAND_WAZA_021E10D8_TYPES_H
#define HAND_WAZA_021E10D8_TYPES_H
/*
 * ov093 move handlers, part 1 (Tri Attack, Secret Power, Chatter, the trap
 * moves, Whirlpool, fixed-damage moves, Stockpile, Spit Up, Swallow, Counter,
 * Mirror Coat, Metal Burst, Last Resort, Snore, Nightmare).
 *
 * Each move owns a group in the original source: a function that stores the
 * handler count and returns the handler table (the "Add" function), then the
 * handler functions. A handler table row is a BtlEventHandler: event id and
 * function. A move registry row (id, Add function) lives in the move registry.
 *
 * Handlers get (factor, flow, pokeId, work). Most of them compare pokeId with
 * the event variable that names the Pokemon the event is about and do nothing
 * for other Pokemon.
 */
#include "btl_event_types.h"
#include "btl_pokeparam_types.h"
#include "hand_tokusei_021d9adc_types.h"

struct BtlSvFlow;

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
#define BTL_SICK_FREEZE 3
#define BTL_SICK_CONFUSION 6
#define BTL_SICK_TRAP 8                   /* Wrap, Bind, Fire Spin, ... */

/* Stat stage ids of a rank effect record. */
#define BTL_RANK_DEFENSE 2
#define BTL_RANK_SP_DEFENSE 4
#define BTL_RANK_SPEED 5
#define BTL_RANK_ACCURACY 6

/* Value ids of the Pokemon value getter. */
#define BPP_VALUE_HP 13
#define BPP_VALUE_LEVEL 15

/* Per-Pokemon counters (BtlPokeParam.counters). */
#define BPP_COUNTER_STOCKPILE 0
#define BPP_COUNTER_STOCKPILE_DEFENSE 1
#define BPP_COUNTER_STOCKPILE_SP_DEFENSE 2

/* Damage categories that Counter, Mirror Coat and Metal Burst react to; 0 is any. */
#define BTL_DAMAGE_TYPE_ANY 0
#define BTL_DAMAGE_TYPE_PHYSICAL 1
#define BTL_DAMAGE_TYPE_SPECIAL 2

/* Record kinds. */
#define HANDEX_KIND_SET_COUNTER 0x26
#define HANDEX_KIND_FLINCH 0x2B

/* The record applies only if the previous record had an effect (guess). */
#define HANDEX_FLAG_AFTER_SUCCESS (1u << 24)

/*
 * Kind 0xe: change a stat stage, with a signed volume. Same layout as
 * struct HandExRankEffect in hand_tokusei_021d9adc_types.h, whose volume is unsigned;
 * the code stores -1 through a signed field (the byte is built from another
 * register, not loaded as 0xff).
 */
struct HandExRankChange {
    u32 header;
    u32 rankKind;
    u8 pad08[4];
    s8 volume;
    u8 flagA;
    u8 flagB;
    u8 pokeCount;
    u8 pokeId;
};

/* Kind 0x26: set a per-Pokemon counter. */
struct HandExSetCounter {
    u32 header;
    u8 pokeId;
    u8 counterIndex;
    u8 value;
};

/* Kind 0x2b: make a Pokemon flinch with a chance in percent. */
struct HandExFlinch {
    u32 header;
    u8 pokeId;
    u8 percent;
};

/*
 * One hit that a Pokemon took, as BTL_POKEPARAM_GetHitRecord returns it. The
 * bytes at 4 to 7 are read as bytes here (attacker id and the slot the
 * attacker had); struct BtlHitRecord in btl_pokeparam_types.h calls them two
 * u16 fields.
 */
struct BtlHitInfo {
    u16 moveId;
    u16 damage;
    u8 flags;
    u8 attackerId;
    u8 attackerPos;
    u8 reserved7;
};

/* Services of the event variable stack. */
extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 value);
extern void BTL_EVENT_MultiplyVar(int key, s32 ratio);
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);

/* Services of the calculation code. */
extern u32 BTL_CALC_Random(u32 range);
extern union SickCont BTL_CALC_MakeDefaultSickCont(int sickId);
extern void BTL_CALC_MakeSickContFromKind(int sickId, struct BtlPokeParam *poke, union SickCont *out);
extern u32 BTL_CALC_MulRatio(u32 value, u32 ratio);
extern void BTLV_CORE_SetSlotValue(union SickCont *cont, u16 value);

/* Services of the battle server flow. */
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlSvFlow *flow, int pokeId);
extern int BTL_SERVER_FLOW_QueryPokeClientFlag(struct BtlSvFlow *flow, int pokeId);
extern int BTL_SERVER_FLOW_GetFrontPosOfPoke(struct BtlSvFlow *flow, int pokeId);
extern int BTL_SERVER_FLOW_GetPosTableEntryForPoke(struct BtlSvFlow *flow, int pos);
extern int BTL_SERVER_FLOW_DecideMoveTarget(struct BtlSvFlow *flow, int pokeId, u16 moveId);
extern int BTL_SERVER_FLOW_GetFieldSituationType(struct BtlSvFlow *flow);
extern void BTL_SERVER_FLOW_SetCurTurnStateFlag(struct BtlSvFlow *flow, int value);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(struct BtlSvFlow *flow, int kind, int pokeId);
extern void BTL_SERVER_FLOW_CommitCmdRecord(struct BtlSvFlow *flow, void *record);
extern void BTL_SERVER_FLOW_InitMsgRecord(struct HandExMessage *message, int kind, int messageId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct HandExMessage *message, u32 arg);
extern int BTL_MAIN_IsPokeSamePair(u32 pokeIdA, u32 pokeIdB);
extern int WAZA_TOOL_GetDamageType(int moveId);

/* Services of the Pokemon parameter code. */
extern int func_021D59B4(struct BtlPokeParam *poke, int valueId);
extern u8 BTL_POKEPARAM_GetCounter(struct BtlPokeParam *poke, int index);
extern u16 BTL_POKEPARAM_GetSpecies(struct BtlPokeParam *poke);
extern void *BTL_POKEPARAM_GetMon(struct BtlPokeParam *poke);
extern u8 BTL_POKEPARAM_GetPokeId(struct BtlPokeParam *poke);
extern u8 BTL_POKEPARAM_GetMoveCount(struct BtlPokeParam *poke);
extern u16 BTL_POKEPARAM_GetMoveId(struct BtlPokeParam *poke, int index);
extern u32 BTL_POKEPARAM_GetMoveUsedFlag(struct BtlPokeParam *poke, u32 index);
extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *poke, int sickId);
extern int BTL_POKEPARAM_TestContFlag(struct BtlPokeParam *poke, u32 flag);
extern int BTL_POKEPARAM_GetHitRecord(struct BtlPokeParam *poke, int turnsAgo, u32 hitsAgo, struct BtlHitInfo *out);

#endif
