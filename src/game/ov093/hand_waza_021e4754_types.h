#ifndef HAND_WAZA_021E4754_TYPES_H
#define HAND_WAZA_021E4754_TYPES_H
/*
 * ov093 move effect handlers (HAND_WAZA_): status moves that the move registry
 * (id, getter) lists. A getter returns the handler table of one move
 * ({event id, handler} rows) and stores the row count. A handler answers one
 * battle event and queues effect records on the battle flow.
 *
 * Records: the handler asks the flow for a record of one kind
 * (BTL_SERVER_FLOW_AllocCmdRecord(flow, kind, pokeId)), fills the fields of that kind and hands
 * it back (BTL_SERVER_FLOW_CommitCmdRecord). Every record starts with a 32-bit header.
 */
#include "btl_event_types.h"
#include "unit_021D794C_types.h"

struct BtlSvFlow;
struct BtlPokeParam;
struct BtlParty;

/*
 * A message with up to eight word arguments, embedded in the records. The type
 * and the argument count share the halfword at +2 (the image reads and writes
 * it as a halfword, so BtlStrParam of hand_tokusei_021d93d8_types.h, which has bytes there,
 * does not fit these handlers).
 */
typedef struct BtlMessageParam {
    u16 strId;
    u16 strType : 8;
    u16 argCount : 7;
    u16 argFlag : 1;
    u32 args[8];
} BtlMessageParam;

/* Move handler: BtlEventFactor, battle flow, id of the Pokemon that owns the handler, handler work. */
typedef void (*BtlWazaHandlerFunc)(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);

/* Event ids of the handler table rows used by these moves (guessed from which moves register them). */
#define BTL_EVENT_UNCATEGORIZED_MOVE 0xa0            /* effect of a move that has a target */
#define BTL_EVENT_UNCATEGORIZED_MOVE_NO_TARGET 0xa1  /* effect of a move that has no target (screens, hazards, party moves) */

/* Event variable keys. */
#ifndef BTL_EVAR_ATTACKER_ID
#define BTL_EVAR_ATTACKER_ID 3
#endif
#define BTL_EVAR_TARGET_ID 6

/* Record kinds. */
#define HANDEX_KIND_MESSAGE 4
#define HANDEX_KIND_REDUCE_PP 0xa
#define HANDEX_KIND_CURE_SICK 0xb
#define HANDEX_KIND_ADD_SICK 0xc
#define HANDEX_KIND_RANK_CHANGE 0xe
#define HANDEX_KIND_SET_RANKS 0xf
#define HANDEX_KIND_SET_STATS 0x11
#define HANDEX_KIND_KILL_POKE 0x13
#define HANDEX_KIND_SET_CONT_FLAG 0x17
#define HANDEX_KIND_ADD_SIDE_EFFECT 0x19
#define HANDEX_KIND_ADD_FIELD_EFFECT 0x1b
#define HANDEX_KIND_TRANSFORM 0x33

/* Status ids (sick kinds) these moves add or cure. */
#define BTL_SICK_TAUNT 0xb
#define BTL_SICK_TORMENT 0xc
#define BTL_SICK_DISABLE 0xd
#define BTL_SICK_LOCK_ON 0x1d
#define BTL_SICK_ALL_MAJOR 0x24     /* cure kind: every major status */

#define BTL_MOVE_STRUGGLE 0xa5

/* Turn flag index tested on the Pokemon ("has already acted this turn"; guess). */
#define BTL_TURN_FLAG_ACTED 1

/* Condition flag index set by Power Trick. */
#define BTL_CONT_FLAG_POWER_TRICK 0xa

/* Message string types for the string parameter setter. */
#define BTL_STRTYPE_STD 1
#define BTL_STRTYPE_SET 2

/* Value ids of the Pokemon value getter: stat stages 1..7, then raw stats. */
#define BPP_VALUE_ATTACK_RANK 1
#define BPP_VALUE_DEFENSE_RANK 2
#define BPP_VALUE_SP_ATTACK_RANK 3
#define BPP_VALUE_SP_DEFENSE_RANK 4
#define BPP_VALUE_SPEED_RANK 5
#define BPP_VALUE_ACCURACY_RANK 6
#define BPP_VALUE_EVASION_RANK 7
#define BPP_RANK_COUNT 7
#define BPP_VALUE_ATTACK 8
#define BPP_VALUE_DEFENSE 9
#define BPP_VALUE_SP_ATTACK 10
#define BPP_VALUE_SP_DEFENSE 11
#define BPP_VALUE_HP 13

/* Side effect kinds of the AddSideEffect record. */
enum {
    BTL_SIDE_EFFECT_REFLECT,
    BTL_SIDE_EFFECT_LIGHT_SCREEN,
    BTL_SIDE_EFFECT_SAFEGUARD,
    BTL_SIDE_EFFECT_MIST,
    BTL_SIDE_EFFECT_TAILWIND,
    BTL_SIDE_EFFECT_LUCKY_CHANT,
    BTL_SIDE_EFFECT_SPIKES,
    BTL_SIDE_EFFECT_TOXIC_SPIKES,
    BTL_SIDE_EFFECT_STEALTH_ROCK,
    BTL_SIDE_EFFECT_WIDE_GUARD
};

/* Kind 4: show a message. */
struct HandExMessage {
    u32 header;
    BtlMessageParam message;
};

/* Kind 0xa: lower the PP of one move slot, then show a message. */
struct HandExReducePp {
    u32 header;
    u8 amount;
    u8 pokeId;
    u8 moveSlot;
    u8 pad07;
    BtlMessageParam message;
};

/* Kind 0xb: cure a status of up to 12 listed Pokemon. */
struct HandExCureSick {
    u32 header;
    u32 sickKind;
    u8 pokeIds[12];
    u8 pokeCount;
    u8 suppressMessage;
};

/* Kind 0xc: add a status; Lock-On also shows a message (tail). */
struct HandExAddSick {
    u32 header;
    u32 sickKind;
    union BtlSickCont sickCont;
    u8 suppressMessage;
    u8 pad0D[2];
    u8 pokeId;
    u32 pad10;
    BtlMessageParam message;
};

/* Kind 0xe: change a stat stage; serialNumber comes from the serial counter of the flow. */
struct HandExRankChange {
    u32 header;
    u32 rankKind;
    u32 serialNumber;
    s8 volume;
    u8 pad0D;
    u8 showMessage;
    u8 pokeCount;
    u8 pokeId;
};

/* Kind 0xf: set all seven stat stages of a Pokemon (attack .. evasion). */
struct HandExSetRanks {
    u32 header;
    u8 pokeId;
    u8 ranks[BPP_RANK_COUNT];
};

/* Kind 0x11: set raw stats of a Pokemon; the set flags choose which values apply. */
struct HandExSetStats {
    u32 header;
    u16 attack;
    u16 defense;
    u16 spAttack;
    u16 spDefense;
    u16 pad0C;
    u8 pokeId;
    u8 setAttack : 1;
    u8 setDefense : 1;
    u8 setSpAttack : 1;
    u8 setSpDefense : 1;
    u8 flagsRest : 4;
    BtlMessageParam message;
};

/* Kind 0x13: make a Pokemon faint. */
struct HandExKillPoke {
    u32 header;
    u8 pokeId;
};

/* Kind 0x17: set a condition flag on a Pokemon. */
struct HandExSetContFlag {
    u32 header;
    u32 flagId;
    u8 pokeId;
};

/* Kind 0x19: put an effect on a side of the field (screen, hazard, Tailwind ...). */
struct HandExAddSideEffect {
    u32 header;
    u32 effectKind;
    union BtlSickCont cont;
    u8 side;
    u8 pad0D[3];
    BtlMessageParam message;
};

/* Kind 0x1b: put a field effect bound to a Pokemon (Imprison) and show a message. */
struct HandExAddFieldEffect {
    u32 header;
    u32 effectKind;
    union BtlSickCont cont;
    u8 showMessage;
    u8 pad0D[3];
    BtlMessageParam message;
};

/* Kind 0x33: transform into the target (message names both). */
struct HandExTransform {
    u32 header;
    u8 targetId;
    u8 pad05[3];
    BtlMessageParam message;
};

/* Services of the event variable stack and the battle flow. */
extern int BTL_EVENT_GetVar(int key);
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlSvFlow *flow, int pokeId);
extern struct BtlParty *BTL_SERVER_FLOW_GetPartyOfPoke(struct BtlSvFlow *flow, int pokeId);
extern struct BtlParty *BTL_SERVER_FLOW_GetPartyOfPokeIfClientUsed(struct BtlSvFlow *flow, int pokeId);
extern u8 *BTL_SERVER_FLOW_GetScratchBuffer(struct BtlSvFlow *flow, int bufferId);
extern u32 BTL_SERVER_FLOW_NextSerialNumberThunk(struct BtlSvFlow *flow);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(struct BtlSvFlow *flow, int kind, int pokeId);
extern void BTL_SERVER_FLOW_CommitCmdRecord(struct BtlSvFlow *flow, void *record);
extern void BTL_SERVER_FLOW_InitMsgRecord(BtlMessageParam *param, int strType, int strId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(BtlMessageParam *param, u32 arg);

/* Services of the Pokemon parameter and party. */
extern int func_021D59B4(struct BtlPokeParam *bpp, int valueId);
extern int func_021D58A8(struct BtlPokeParam *bpp, int valueId);
extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *bpp, int sickId);
extern int BTL_POKEPARAM_TestTurnFlag(struct BtlPokeParam *bpp, u32 flagIndex);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct BtlPokeParam *bpp);
extern u8 BTL_POKEPARAM_GetPokeId(struct BtlPokeParam *bpp);
extern u16 BTL_POKEPARAM_GetLastSelectedMoveId(struct BtlPokeParam *bpp);
extern int BTL_POKEPARAM_HasMove(struct BtlPokeParam *bpp, int moveId);
extern int BTL_POKEPARAM_FindMoveSlot(struct BtlPokeParam *bpp, int moveId);
extern int BTL_POKEPARAM_GetMovePPChecked(struct BtlPokeParam *bpp, u32 slot);
extern u8 BTL_SLOT_GetCount(struct BtlParty *party);
extern struct BtlPokeParam *BTL_SLOT_GetPokeParam(struct BtlParty *party, u32 index);

/* Status condition records (see unit_021D794C_types.h). */
extern union BtlSickCont BTL_CALC_MakeSickContTurns(int turns);
extern union BtlSickCont BTLV_CORE_MakeSlotKind1Empty(void);
extern union BtlSickCont BTLV_CORE_MakeSlotKind2Index(int turns);
extern union BtlSickCont BTLV_CORE_MakeSlotKind2(int turns, int moveId);
extern union BtlSickCont BTLV_CORE_MakeSlotKind3(u32 pokeId);
extern union BtlSickCont BTLV_CORE_MakeSlotKind4(u32 pokeId, u32 turns);

#ifndef HAND_WAZA_DEFINES_ADD_SIDE_EFFECT
/* Queues an AddSideEffect record: side, effect kind, duration record and message id (defined with the Wide Guard handler). */
extern void HAND_WAZA_AddSideEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work,
                          int side, int effectKind, union BtlSickCont cont, u16 messageId);
#endif

/* Side of the field of a Pokemon id, and the opposite side. */
extern u8 BTL_MAIN_IsPokeIdInSecondPair(u32 pokeId);
extern u8 BTL_MAIN_IsPokeIdInFirstPair(u32 pokeId);

#endif
