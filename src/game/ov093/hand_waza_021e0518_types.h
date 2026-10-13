#ifndef HAND_WAZA_021E0518_TYPES_H
#define HAND_WAZA_021E0518_TYPES_H
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
#include "btl_event_types.h"
#include "btl_action_word_types.h"
#include "hand_tokusei_021d9adc_types.h"

/* Event variable keys that these handlers read or write (more are in btl_action_word_types.h). */
#define BTL_EVAR_TARGET_ID 6          /* target of the move being used */
#define BTL_EVAR_MOVE_TARGET_KIND 0x1b
#define BTL_EVAR_MOVE_FAIL_FLAG 0x40  /* set to 1 to make the move fail */
#define BTL_EVAR_ACCURACY_CHECK_FLAG 0x51 /* result of event 0x3d, default 0 (same key as the speed penalty flag) */

/* Command kinds that these handlers queue (pushed with BTL_SERVER_FLOW_AllocCmdRecord, kinds without record with BTL_SERVER_FLOW_PushCmdRecord). */
#define BTL_CMD_KIND_MESSAGE 4
#define BTL_CMD_KIND_DAMAGE 7
#define BTL_CMD_KIND_HP_DELTA 8
#define BTL_CMD_KIND_CURE_SICK 0xb
#define BTL_CMD_KIND_ADD_SICK 0xc
#define BTL_CMD_KIND_RANK_EFFECT 0xe
#define BTL_CMD_KIND_RESET_RANKS 0x10
#define BTL_CMD_KIND_CHANGE_TYPE 0x14
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
#define BTL_SIDE_EFFECT_REFLECT 0
#define BTL_SIDE_EFFECT_LIGHT_SCREEN 1
#define BTL_SIDE_EFFECT_SAFEGUARD 2
#define BTL_SIDE_EFFECT_MIST 3
#define BTL_SIDE_EFFECT_SPIKES 6
#define BTL_SIDE_EFFECT_TOXIC_SPIKES 7
#define BTL_SIDE_EFFECT_STEALTH_ROCK 8

/* Rule ids of the battle (single, double, triple, rotation). */
#define BTL_RULE_SINGLE 0
#define BTL_RULE_ROTATION 3

/* Move ids that the handlers compare against. */
#define BTL_MOVE_STRUGGLE 165
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
#define BTL_RANK_DEFENSE 2
#define BTL_RANK_SPEED 5
#define BTL_RANK_EVASION 7

/* Pokemon type ids (a dense list; some are in btl_action_word_types.h). */
#define POKETYPE_NORMAL 0
#define POKETYPE_GROUND 4
#define POKETYPE_ROCK 5
#define POKETYPE_GHOST 7

/* Value ids of the Pokemon value getter that these handlers read. */
#define BPP_VALUE_ABILITY_ID 0x11
#define BPP_VALUE_HP 0xd /* current hit points (guess) */

/* Ability ids that Worry Seed checks. */
#define BTL_ABILITY_TRUANT 0x36
#define BTL_ABILITY_INSOMNIA 0xf

/* Kind 0x14: replace the type pair of a Pokemon (both bytes equal means a single type). */
typedef struct {
    u32 header;
    u16 typePair;
    u8 pokeId;
} BtlChangeTypeCmd;

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
    struct HandExMessage message;
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
    struct HandExMessage message;
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

/* Services of the battle flow and the Pokemon that these handlers use. */
extern void BTL_SERVER_FLOW_PushCmdRecord(struct BtlSvFlow *flow, int kind, int pokeId);
extern int BTL_SERVER_FLOW_GetFieldSituationType(struct BtlSvFlow *flow);
extern int BTL_SERVER_FLOW_GetRule(struct BtlSvFlow *flow);
extern int BTL_FIELD_GetStaticSlotObject(int fieldEffectId);
extern int BTLV_CORE_MakeSlotKind2Index(u32 turns);
extern union SickCont BTLV_CORE_MakeSlotKind3(int pokeId);
extern union SickCont BTLV_CORE_MakeSlotKind1Empty(void);
extern u16 BTLV_CORE_PackByteTwice(int type);
extern u16 BTL_POKEPARAM_GetTypePair(struct BtlPokeParam *bpp);
extern u32 BTL_POKEPARAM_HasSubstitute(struct BtlPokeParam *bpp);
extern int BTL_POKEPARAM_IsTransformed(struct BtlPokeParam *bpp);
extern int BTL_POKEPARAM_HasMove(struct BtlPokeParam *bpp, int moveId);
extern int BTL_POKEPARAM_HasType(struct BtlPokeParam *bpp, int type);
extern u16 BTL_POKEPARAM_GetLastUsedMoveId(struct BtlPokeParam *bpp);
extern u16 BTL_POKEPARAM_GetLastSelectedMoveId(struct BtlPokeParam *bpp);
extern u8 BTL_POKEPARAM_FindMoveSlot(struct BtlPokeParam *bpp, int moveId);
extern int BTL_CALC_DivideMaxHpMin1(struct BtlPokeParam *bpp, u32 divisor);
extern int BTL_CALC_GetCurseTargetKind(struct BtlPokeParam *bpp);
extern u32 BTL_CALC_MakeSickContPoke(int pokeId);
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern void BTL_EVENT_SetFactorSkipCheck(struct BtlEventFactor *factor, BtlEventSkipCheck check);
extern void BTL_EVENT_ClearFactorSkipCheck(struct BtlEventFactor *factor);
extern unsigned char BTL_MAIN_IsPokeIdInSecondPair(unsigned int pokeId);
extern int BTL_MAIN_IsPokeSamePair(unsigned int pokeIdA, unsigned int pokeIdB);
extern int BTL_SERVER_FLOW_GetFrontPosOfPoke(struct BtlSvFlow *flow, int pokeId);
extern u8 BTL_SERVER_FLOW_CollectAlivePokeIds(struct BtlSvFlow *flow, int filter, u8 *outPokeIds);
extern unsigned int BTL_SERVER_FLOW_TestStateFlagBit0(struct BtlSvFlow *flow);
extern int BTL_SERVER_FLOW_CheckAllyMoveAutoHitById(struct BtlSvFlow *flow, int attackerId, int pokeId, int moveId);
extern void BTL_SERVER_FLOW_SetCurTurnStateFlag(struct BtlSvFlow *flow, int flag);
extern int func_06898CF4(int sideId, int sideEffectId);
extern int func_0689CA7C(int moveId);
extern void HAND_WAZA_RemoveMoveHandlerById(int pokeId, int moveId);

#endif
