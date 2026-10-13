#ifndef HAND_WAZA_021E396C_TYPES_H
#define HAND_WAZA_021E396C_TYPES_H
/*
 * ov093 move handlers (hand_waza), part 3: Surf, Stomp, False Swipe, the
 * Protect family, Bide, Recycle, Psycho Shift, Pain Split, Belly Drum, Feint,
 * Acupressure, Rest, Attract, Conversion 2, Encore and the Taunt getter.
 *
 * Every move owns a getter that returns its handler table (rows of event id
 * and handler) and stores the row count. The move registry holds rows of move
 * id and getter. A handler asks the flow for a record of one kind
 * (HANDEX_KIND_*), fills the fields that kind uses and commits it; the record
 * buffer is reused, so each kind has its own struct. Every record starts with
 * the 32-bit header.
 */
#include "btl_event_types.h"

struct BtlSvFlow;
struct BtlPokeParam;

/* A callee that returns a one-word struct: the compiler then reserves a frame word. */
typedef struct OneWordResult {
    u32 value;
} OneWordResult;

/* Event variable keys (same values and names as the other handler headers). */
#ifndef BTL_EVAR_POKE_ID
#define BTL_EVAR_POKE_ID 2
#define BTL_EVAR_ATTACKER_ID 3
#define BTL_EVAR_DEFENDER_ID 4
#define BTL_EVAR_DEFENDER_FIRST 6
#define BTL_EVAR_TARGET_SEMI_INVULNERABLE 0x21 /* contFlag of the target's semi-invulnerable state, 0x10 when none */
#define BTL_EVAR_FAIL_REASON 0x22
#define BTL_EVAR_MAGNITUDE 0x30                /* guess: magnitude level the message shows */
#define BTL_EVAR_DAMAGE 0x32
#define BTL_EVAR_RATIO 0x35                    /* fixed point ratio, 0x1000 is 1.0 */
#define BTL_EVAR_FIXED_DAMAGE 0x37             /* damage that replaces the calculation (Bide) */
#define BTL_EVAR_SURVIVE_RESULT 0x3A           /* 1 Endure, 2 False Swipe (4 Sturdy): the hit leaves 1 HP */
#define BTL_EVAR_MOVE_PHASE 0x3E               /* guess: 2 makes the flow skip the normal move execution */
#define BTL_EVAR_MESSAGE 0x3F                  /* pointer to the message the event is about to show */
#define BTL_EVAR_NO_EFFECT_FLAG 0x40
#define BTL_EVAR_AVOID_BY_SEMI_INVULNERABLE 0x42 /* nonzero: the target dodges because it is semi-invulnerable */
#define BTL_EVAR_HIT_SUBSTITUTE 0x46
#define BTL_EVAR_GENERIC_FLAG 0x51             /* result slot several events share */
#endif

/* contFlag numbers (BTL_POKEPARAM_TestContFlag). */
#define BTL_CONT_FLAG_DIVING 4                 /* semi-invulnerable underwater (Dive) */
#define BTL_CONT_FLAG_MINIMIZED 8
#define BTL_SEMI_INVULNERABLE_DIVING 4
/* Turn flags. */
#define BTL_TURN_FLAG_ACTED 1                  /* guess: the Pokemon already acted this turn */
#define BTL_TURN_FLAG_PROTECTED 7              /* the Pokemon protects itself this turn */
/* Counter slot of the consecutive-use streak of Protect, Detect, Endure and the guard moves. */
#define BTL_COUNTER_PROTECT_STREAK 3
#define BTL_PROTECT_STREAK_MAX 9

#define BTL_FAIL_REASON_SLEEP_BLOCKED 0x0D     /* guess */
#define BTL_FAIL_REASON_HP_FULL 0x0E
#define BTL_FAIL_REASON_ABILITY_BLOCKS_SLEEP 0x0F
#define BTL_FAIL_REASON_GENERIC 0x1A           /* "But it failed" */

/* Value ids of the Pokemon value getter. */
#define BPP_VALUE_HP 13
#define BPP_VALUE_MAX_HP 14
#define BPP_VALUE_CURRENT_ABILITY 0x11
#define BPP_VALUE_GENDER 0x12
#define BTL_GENDER_NONE 2
#define ABILITY_INSOMNIA 15
#define ABILITY_VITAL_SPIRIT 72

/* Status conditions ("sick" kinds). */
#define BTL_SICK_SLEEP 2
#define BTL_SICK_POISON 5
#define BTL_SICK_SLEEP_BLOCK 0x0F              /* guess: a condition that stops the user from falling asleep */
#define BTL_SICK_ENCORE 0x17
#define BTL_SICK_BIDE 0x19                     /* Bide is storing energy */

/* Stat stage ids. */
#define BTL_RANK_ATTACK 1
#define BTL_RANK_DEFENSE 2
#define BTL_RANK_SP_ATTACK 3
#define BTL_RANK_SP_DEFENSE 4
#define BTL_RANK_SPEED 5
#define BTL_RANK_ACCURACY 6
#define BTL_RANK_EVASION 7
#define BTL_RANK_STAT_COUNT 7
#define BTL_RANK_DIRECTION_RAISE 2             /* third argument of the stage check */

#define BTL_POKEID_NONE 0x1F
#define BTL_SLOT_NONE 6
#define BTL_SIDE_EFFECT_QUICK_GUARD 9          /* guess */
#define BTL_SIDE_EFFECT_WIDE_GUARD 10          /* guess */

/* Record kinds. */
#define HANDEX_KIND_MESSAGE 4
#define HANDEX_KIND_RECOVER_HP 5
#define HANDEX_KIND_CHANGE_HP 8
#define HANDEX_KIND_CURE_SICK 0xB
#define HANDEX_KIND_ADD_SICK 0xC
#define HANDEX_KIND_RANK_EFFECT 0xE
#define HANDEX_KIND_CHANGE_TYPE 0x14
#define HANDEX_KIND_SET_TURN_FLAG 0x15
#define HANDEX_KIND_CLEAR_TURN_FLAG 0x16
#define HANDEX_KIND_REMOVE_SIDE_EFFECT 0x1A
#define HANDEX_KIND_SET_ITEM 0x20
#define HANDEX_KIND_REFRESH_HP_GAUGE 0x21
#define HANDEX_KIND_SET_COUNTER 0x26

/* Header flag (guess): the record plays no animation. */
#define HANDEX_FLAG_SILENT (1u << 24)

/* A message under construction: kind 1 is a standard string, kind 2 a string set; up to 8 arguments. */
#define BTL_MSG_KIND_STD 1
#define BTL_MSG_KIND_SET 2
struct HandExMessage {
    u16 messageId;
    u16 kind : 8;
    u16 argCount : 7;
    u16 flag : 1;
    u32 args[8];
};

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

/* Kind 4: show a message. */
struct HandExMessageRecord {
    u32 header;
    struct HandExMessage message;
};

/* Kind 5: heal a Pokemon. */
struct HandExRecoverHp {
    u32 header;
    u16 amount;
    u8 pokeId;
};

/* Kind 8: change the HP of up to nine Pokemon by a signed amount each. */
struct HandExChangeHp {
    u32 header;
    u8 pokeCount;
    u8 pad5;
    u8 updateGauge;          /* guess */
    u8 pokeIds[9];           /* 0x07 */
    s32 amounts[2];          /* 0x10 */
};

/* Kind 0xb: cure a status condition of up to 12 listed Pokemon. */
struct HandExCureSick {
    u32 header;
    u32 sickKind;
    u8 pokeIds[12];
    u8 pokeCount;
    u8 suppressMessage;
};

/* Kind 0xc: add a status condition with its packed duration, then optionally a message. */
struct HandExAddSick {
    u32 header;
    u32 sickKind;
    OneWordResult sickCont;  /* packed duration and parameters */
    u8 replaceExisting;      /* guess: 1 overwrites a condition already present */
    u8 pad0D;
    u8 ignoreImmunity;       /* guess */
    u8 pokeId;
    u8 useOwnMessage;        /* guess: the record shows its own message instead of the default one */
    u8 pad11[3];
    struct HandExMessage message;
};

/* Kind 0xe: change a stat stage. */
struct HandExRankEffect {
    u32 header;
    u32 rankKind;
    u8 pad8[4];
    u8 volume;
    u8 bypassBlockers;       /* guess */
    u8 suppressMessage;
    u8 pokeCount;
    u8 pokeId;
};

/* Kind 0x14: set the type pair of a Pokemon (packed as two bytes). */
struct HandExChangeType {
    u32 header;
    u16 typePair;
    u8 pokeId;
};

/* Kinds 0x15 and 0x16: set or clear a turn flag. */
struct HandExTurnFlag {
    u32 header;
    s32 flag;
    u8 pokeId;
};

/* Kind 0x1a: remove a side effect (layout guessed from the one writer). */
struct HandExRemoveSideEffect {
    u32 header;
    u8 mode;                 /* 0x04: 3 */
    u8 pad5;
    u8 flags;                /* 0x06: bits 1 and 2 set when mode is above 2 */
    u8 side;                 /* 0x07 */
};

/* Kind 0x20: give a Pokemon a held item, then show a message. */
struct HandExSetItem {
    u32 header;
    u16 itemId;
    s8 pokeId;
    s8 announce;
    u8 pad8[4];
    struct HandExMessage message;
};

/* Kind 0x21: refresh the HP gauge of a Pokemon (mode 1 after a loss or exchange, 3 after a recovery). */
struct HandExRefreshHpGauge {
    u32 header;
    u8 pokeId;
    u8 pad5[3];
    u32 mode;
};

/* Kind 0x26: write a counter slot of a Pokemon. */
struct HandExSetCounter {
    u32 header;
    u8 pokeId;
    u8 counterId;
    u8 value;
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

/* Services of the event variable stack and the battle flow. */
extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 value);
extern void BTL_EVENT_MultiplyVar(int key, s32 ratio);
extern void BTL_EVENT_RemoveFactor(struct BtlEventFactor *factor);
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern u32 BTL_CALC_Random(u32 range);

extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlSvFlow *flow, int pokeId);   /* poke container lookup */
extern void *BTL_SERVER_FLOW_AllocCmdRecord(struct BtlSvFlow *flow, int kind, int pokeId);        /* allocate a HandEx record */
extern void BTL_SERVER_FLOW_CommitCmdRecord(struct BtlSvFlow *flow, void *record);                 /* commit a record */
extern void BTL_SERVER_FLOW_InitMsgRecord(struct HandExMessage *msg, int kind, int messageId);   /* start a message */
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct HandExMessage *msg, u32 arg);                   /* append a message argument */
extern void BTL_SERVER_FLOW_SetCurTurnStateFlag(struct BtlSvFlow *flow, int value);
extern int BTL_SERVER_FLOW_GetFrontPosOfPoke(struct BtlSvFlow *flow, int pokeId);
extern int BTL_SERVER_FLOW_GetPokeViewPos(struct BtlSvFlow *flow, int pokeId);
extern u8 BTL_SERVER_FLOW_CollectAlivePokeIds(struct BtlSvFlow *flow, int selector, u8 *outIds);
extern u8 *BTL_SERVER_FLOW_GetScratchBuffer(struct BtlSvFlow *flow, int index);
extern int BTL_SERVER_FLOW_CheckSideEffectActive(struct BtlSvFlow *flow, int side, int sideEffect);
extern int func_021E8624(struct BtlSvFlow *flow, int pokeId);
extern u8 BTL_MAIN_IsPokeIdInSecondPair(unsigned int pokeId);
extern u8 BTL_MAIN_IsZero(u32 value);
extern int func_021D59B4(struct BtlPokeParam *bpp, int valueId);
extern int func_021D5D14(struct BtlPokeParam *bpp, int stageId, int direction);
extern int func_021D5D50(struct BtlPokeParam *bpp, int stageId);

extern u8 BTL_POKEPARAM_GetCounter(struct BtlPokeParam *bpp, int counterId);
extern int BTL_POKEPARAM_TestContFlag(struct BtlPokeParam *bpp, u32 flag);
extern int BTL_POKEPARAM_TestTurnFlag(struct BtlPokeParam *bpp, u32 flag);
extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *bpp, int sickKind);
extern int BTL_POKEPARAM_IsHpFull(struct BtlPokeParam *bpp);
extern int BTL_POKEPARAM_HasType(struct BtlPokeParam *bpp, int type);
extern int BTL_POKEPARAM_GetHitCount(struct BtlPokeParam *bpp, u32 turnAgo);
extern int BTL_POKEPARAM_GetHitRecord(const struct BtlPokeParam *bpp, int turnAgo, u32 index, u16 *out);
extern u16 BTL_POKEPARAM_GetItem(struct BtlPokeParam *bpp);
extern u16 BTL_POKEPARAM_GetConsumedItem(struct BtlPokeParam *bpp);
extern u16 BTL_POKEPARAM_GetLastUsedMoveId(struct BtlPokeParam *bpp);
extern u16 BTL_POKEPARAM_GetLastSelectedMoveId(struct BtlPokeParam *bpp);
extern u8 BTL_POKEPARAM_GetLastTargetPos(struct BtlPokeParam *bpp);
extern int BTL_POKEPARAM_GetMovePPById(struct BtlPokeParam *bpp, int moveId);
extern OneWordResult BTL_POKEPARAM_GetMajorStatusIndex(struct BtlPokeParam *bpp);
extern u32 BTL_POKEPARAM_GetSickContRaw(struct BtlPokeParam *bpp, int sickKind);
extern int BTL_CALC_DivideMaxHpMin1(struct BtlPokeParam *bpp, u32 divisor);
extern int BTL_CALC_MakeDefaultSickCont(int sickKind);
extern OneWordResult BTL_CALC_MakeSickContTurns(int turns);
extern u8 BTL_CALC_ListResistingTypes(int attackType, u8 *out);
extern OneWordResult BTLV_CORE_MakeSlotKind1Value(unsigned int value);
extern OneWordResult BTLV_CORE_MakeSlotKind1Index15(void);
extern OneWordResult BTLV_CORE_MakeSlotKind2(int turns, int moveId);
extern int BTLV_CORE_IsSlotKind1Index15(int sickCont);
extern int BTLV_CORE_PackByteTwice(int value);
extern int func_0689C8AC(int moveId);                                             /* nonzero: the move cannot be Encored */
extern void func_02082D44(u8 *src, u8 *dst, u32 size);                            /* byte move */

/* Raises the Protect streak counter of a Pokemon by one (defined with the Protect handlers). */
extern void HAND_WAZA_ProtectIncrementStreak(struct BtlSvFlow *flow, int pokeId, int silent);

#endif
