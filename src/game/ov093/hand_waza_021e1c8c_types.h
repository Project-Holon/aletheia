#ifndef HAND_WAZA_021E1C8C_TYPES_H
#define HAND_WAZA_021E1C8C_TYPES_H
/*
 * ov093 move handlers (second part of the move handler run): the effect
 * records a move handler pushes to the battle flow, the event variables and
 * condition ids these handlers use, and the services they call.
 *
 * Every move in the registry (gWazaHandlerRegistry, 258 rows) owns a getter that
 * returns its handler table (event id, handler function). The handler table
 * is registered as event factor handlers; each handler gets the factor, the
 * battle flow, the id of the Pokemon the factor belongs to and the factor
 * work area (BtlEventFactor.work).
 *
 * Event ids seen in these tables (name: id, what the flow does there):
 *   action start 1, action end 2, move start 3, move end 4 (var 0x51 holds
 *   the move-succeeded flag), obedience override 0xE, move done 0x21, move
 *   execute query 0x24, move succeeded 0x25, move failed 0x26, move finished
 *   0x27, always-hit query 0x32, multi-hit count 0x35, base power 0x37, power
 *   ratio 0x38, no-effect check 0x2C, move hit 0x45, damage end 0x4B, pursuit
 *   before switch 0x53, sick cont 0x62, sick blocked query 0x65, turn end 0x77,
 *   status move effect 0xA0.
 */
#include "btl_event_types.h"
#include "btl_pokeparam_types.h"

struct BtlSvFlow;

/* Event variable keys the move handlers read or write. */
enum {
    BTL_EVAR_POKE_ID = 2,           /* the Pokemon the event is about */
    BTL_EVAR_ATTACKER_ID = 3,
    BTL_EVAR_DEFENDER_ID = 4,
    BTL_EVAR_SWITCHING_POKE_ID = 6, /* pursuit-before-switch event: the Pokemon that leaves */
    BTL_EVAR_MOVE_ID = 0x12,
    BTL_EVAR_MOVE_TYPE = 0x16,
    BTL_EVAR_SICK_ID = 0x1D,
    BTL_EVAR_SICK_CONT = 0x1E,
    BTL_EVAR_BASE_POWER = 0x30,
    BTL_EVAR_POWER_RATIO = 0x31,
    BTL_EVAR_MOVE_HANDLED_FLAG = 0x3E, /* move execute query: the handler took over the move (guess) */
    BTL_EVAR_NO_EFFECT_STRING = 0x3F,  /* no-effect check: string record to fill when the move fails */
    BTL_EVAR_NO_EFFECT_FLAG = 0x40,    /* no-effect check: nonzero makes the move fail */
    BTL_EVAR_PREVENT_FLAG = 0x41,
    BTL_EVAR_CHECK_EACH_HIT_FLAG = 0x42, /* multi-hit count: check accuracy for every hit */
    BTL_EVAR_HIT_SUBSTITUTE = 0x46,
    BTL_EVAR_RESULT_FLAG = 0x51 /* boolean answer of many query events; move end passes the succeeded flag here */
};

/* Condition (sick) ids as the move handlers use them. */
#define BTL_SICK_SLEEP 2
#define BTL_SICK_CONFUSION 6
#define BTL_SICK_MOVE_LOCK 0x19 /* locked into the move: Thrash, Uproar, Rollout */
#define BTL_SICK_AQUA_RING 0x23

/* Condition flag ids of the poke parameter (SetContFlag/TestContFlag). */
#define BTL_CONT_FLAG_DEFENSE_CURL 7
#define BTL_CONT_FLAG_CRITICAL_UP 9

/* Turn flag ids of the poke parameter (TestTurnFlag). */
#define BTL_TURN_FLAG_MOVED 1           /* guess: the Pokemon has used its move this turn */
#define BTL_TURN_FLAG_ACTION_FINISHED 3 /* guess: its action is already over this turn */

/* Value ids of the poke parameter value getter. */
#define BTL_VALUE_SPEED 0xC
#define BTL_VALUE_HP 0xD
#define BTL_VALUE_MAX_HP 0xE
#define BTL_VALUE_LEVEL 0xF

/* Major status ids returned by BTL_POKEPARAM_GetMajorStatusIndex. */
#define BTL_MAJOR_STATUS_PARALYSIS 1
#define BTL_MAJOR_STATUS_BURN 4
#define BTL_MAJOR_STATUS_POISON 5

/* Pokemon type id that the move handlers test. */
#define POKETYPE_ELECTRIC 12

/* Ratio in 20.12 fixed point: 0x1000 is 1.0. */
#define BTL_RATIO_2_0 0x2000

/* Message string types of HandExStr. */
#define HANDEX_STR_STD 1 /* standard message by id */
#define HANDEX_STR_SET 2 /* message by id that names a Pokemon */

/* Record kinds that these handlers push. */
#define HANDEX_KIND_MESSAGE 4
#define HANDEX_KIND_CURE_SICK 0xB
#define HANDEX_KIND_ADD_SICK 0xC
#define HANDEX_KIND_RANK_EFFECT 0xE
#define HANDEX_KIND_FAINT 0x13
#define HANDEX_KIND_SET_CONT_FLAG 0x17

/* Stat id of the rank record: attack. */
#define BTL_RANK_ATTACK 1

/* A message with up to eight word arguments, embedded in some records. */
typedef struct HandExStr {
    u16 strId;
    u8 strType;
    u8 argCount : 7;
    u8 extraSet : 1;
    u32 args[8];
} HandExStr;

/* Kind 4: show a message. */
typedef struct HandExMessage {
    u32 header;
    HandExStr str;
} HandExMessage;

/* Kind 0xB: cure a status condition of up to 12 listed Pokemon. */
typedef struct HandExCureSick {
    u32 header;
    u32 sickKind;
    u8 pokeIds[12];
    u8 pokeCount;
    u8 suppressMessage;
    u8 pad16[2];
    HandExStr str;
} HandExCureSick;

/* Kind 0xC: add a status condition, then show a string at +0x14. */
typedef struct HandExAddSick {
    u32 header;
    u32 sickKind;
    union SickCont sickCont;
    u8 suppressMessage;
    u8 fromMove;
    u8 pad0E;
    u8 pokeId;
    u32 pad10;
    HandExStr str;
} HandExAddSick;

/* Kind 0xE: change a stat stage, then show a string at +0x18. */
typedef struct HandExRankEffect {
    u32 header;
    u32 statId;
    u32 pad08;
    s8 amount;
    u8 fromMove;
    u8 showMessage;
    u8 targetCount;
    u8 targets[8];
    HandExStr str;
} HandExRankEffect;

/* Kind 0x13: make a Pokemon faint. */
typedef struct HandExFaint {
    u32 header;
    u8 pokeId;
} HandExFaint;

/* Kind 0x17: set a condition flag on a Pokemon. */
typedef struct HandExSetContFlag {
    u32 header;
    u32 flagId;
    u8 pokeId;
} HandExSetContFlag;

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

/* One hit taken, as BTL_POKEPARAM_GetHitRecord returns it for these handlers (byte +5 is the attacker). */
typedef struct HandHitRecord {
    u16 moveId;
    u16 damage;
    u8 moveType;
    u8 attackerId;
    u16 hitFlags;
} HandHitRecord;

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
extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 value);
extern void BTL_EVENT_MultiplyVar(int key, int ratio);
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern void BTL_EVENT_RemoveFactor(struct BtlEventFactor *factor);

/* Services of the battle flow. */
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlSvFlow *flow, int pokeId);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(struct BtlSvFlow *flow, int kind, int pokeId);
extern void BTL_SERVER_FLOW_CommitCmdRecord(struct BtlSvFlow *flow, void *record);
extern void BTL_SERVER_FLOW_InitMsgRecord(HandExStr *str, int strType, int strId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(HandExStr *str, u32 arg);
extern union SickCont BTLV_CORE_MakeSlotKind2(int turnCount, int moveKey);

#endif
