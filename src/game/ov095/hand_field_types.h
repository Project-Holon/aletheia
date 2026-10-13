#ifndef HAND_FIELD_TYPES_H
#define HAND_FIELD_TYPES_H
/*
 * ov095 battle effect factors that are not abilities: field effects (factor type 3),
 * position effects (type 1) and side effects (type 2). Each effect registers one
 * event factor through BTL_EVENT_AddFactor; the handler tables below say which battle
 * events the factor answers.
 */
#include "../ov093/hand_common_types.h"

struct BtlSvFlow;
struct BtlPokeParam;

/* Factor types (first argument of BTL_EVENT_AddFactor). 4 is the ability type, 7 means "any". */
#ifndef BTL_EVENT_TYPE_POS_EFFECT
#define BTL_EVENT_TYPE_POS_EFFECT 1
#define BTL_EVENT_TYPE_SIDE_EFFECT 2
#define BTL_EVENT_TYPE_FIELD_EFFECT 3

/* Battle server flow and poke parameter services used by the position effect handlers. */
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlSvFlow *flow, int pokeId);
extern int BTL_SERVER_FLOW_GetPokeIdAtFieldIndex(struct BtlSvFlow *flow, int position);
extern u32 BTL_SERVER_FLOW_GetTurnCount(struct BtlSvFlow *flow);
extern int BTL_SERVER_FLOW_CheckShowdownThunk(struct BtlSvFlow *flow);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(struct BtlSvFlow *flow, int kind, int pokeId);
extern void BTL_SERVER_FLOW_CommitCmdRecord(struct BtlSvFlow *flow, void *cmd);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *message, int kind, int messageId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(void *message, u32 arg);
extern int BTL_POKEPARAM_IsHpFull(struct BtlPokeParam *bpp);
extern u16 BTL_CALC_DivideMaxHpMin1(struct BtlPokeParam *bpp, int divisor);

#endif

/* Event variable keys used here that the shared enum does not name yet. */
#define BTL_EVAR_REVERSE_SPEED_ORDER_FLAG 0x4A /* Trick Room: sort by slowest first */
#define BTL_EVAR_USE_COUNTER 0x3D              /* counter that the field effect at slot 6 increments */

/* Event ids that the handler tables of these effects answer (names from the handler bodies; guesses). */
enum {
    HAND_EVENT_SPEED = 0x13,                 /* speed comparison for the action order */
    HAND_EVENT_ACCURACY = 0x34,              /* hit chance calculation */
    HAND_EVENT_MOVE_POWER = 0x38,            /* move power calculation */
    HAND_EVENT_USE_COUNTER_STEP = 0x3A,      /* guess: once per action, the use counter advances */
    HAND_EVENT_GROUND_IMMUNITY = 0x3E,       /* may the move hit through a ground immunity */
    HAND_EVENT_DAMAGE_RATIO = 0x47,          /* final damage ratio (screens, resist berries) */
    HAND_EVENT_MEMBER_ENTER = 0x55,          /* a Pokemon enters the field */
    HAND_EVENT_TURN_CHECK = 0x76,            /* guess: end-of-turn processing */
    HAND_EVENT_MEMBER_ENTER_AFTER_FAINT = 0xA4 /* guess: a replacement enters after a faint */
};

/* Type ids that the handlers compare the move type with (identical to the POKETYPE values of the shared headers). */
enum {
    HAND_POKETYPE_GROUND = 4,
    HAND_POKETYPE_FIRE = 9,
    HAND_POKETYPE_ELECTRIC = 12
};

/* Damage categories (event variable BTL_EVAR_DAMAGE_TYPE) and battle rules. */
#define BTL_DAMAGE_TYPE_PHYSICAL 1
#define BTL_DAMAGE_TYPE_SPECIAL 2
#define BTL_RULE_SINGLE 0
#define BTL_RULE_ROTATION 3

/* Damage and accuracy ratios in 1/4096 units. */
#define HAND_RATIO_GRAVITY_ACCURACY 0x1ab8 /* about 1.67 */
#define HAND_RATIO_SPORT_POWER 0x548       /* about 0.33 */
#define HAND_RATIO_SCREEN_SINGLES 0x800    /* 0.5 */
#define HAND_RATIO_SCREEN_DOUBLES 0xa8f    /* about 0.66 */

/* Field effect ids: index into the table that BTL_EVENT_AddFactor callers pass (8 entries). */
enum BtlFieldEffect {
    BTL_FLDEFF_WEATHER = 0,    /* guess: presence marker only, the handler list is empty */
    BTL_FLDEFF_TRICK_ROOM = 1,
    BTL_FLDEFF_GRAVITY = 2,
    BTL_FLDEFF_WONDER_ROOM = 3, /* guess: presence marker only */
    BTL_FLDEFF_WATER_SPORT = 4,
    BTL_FLDEFF_MUD_SPORT = 5,
    BTL_FLDEFF_USE_COUNTER = 6, /* guess: counts uses with event variable 0x3D */
    BTL_FLDEFF_MAGIC_ROOM = 7,  /* guess: presence marker only */
    BTL_FLDEFF_COUNT = 8
};

/* Position effect ids (5 entries). */
enum BtlPosEffect {
    BTL_POSEFF_WISH = 0,
    BTL_POSEFF_LUNAR_DANCE = 1,
    BTL_POSEFF_HEALING_WISH = 2,
    BTL_POSEFF_FUTURE_SIGHT = 3,
    BTL_POSEFF_PENDING_ENTRY = 4,
    BTL_POSEFF_COUNT = 5
};

/* Side effect ids (14 entries). Spikes stack to 3 layers, Toxic Spikes to 2, the rest to 1. */
enum BtlSideEffect {
    BTL_SIDEEFF_REFLECT = 0,
    BTL_SIDEEFF_LIGHT_SCREEN = 1,
    BTL_SIDEEFF_SAFEGUARD = 2,
    BTL_SIDEEFF_MIST = 3,
    BTL_SIDEEFF_TAILWIND = 4,
    BTL_SIDEEFF_LUCKY_CHANT = 5,
    BTL_SIDEEFF_SPIKES = 6,
    BTL_SIDEEFF_TOXIC_SPIKES = 7,
    BTL_SIDEEFF_STEALTH_ROCK = 8,
    BTL_SIDEEFF_WIDE_GUARD = 9,
    BTL_SIDEEFF_QUICK_GUARD = 10,
    BTL_SIDEEFF_RAINBOW = 11,
    BTL_SIDEEFF_SEA_OF_FIRE = 12,
    BTL_SIDEEFF_SWAMP = 13,
    BTL_SIDEEFF_COUNT = 14
};

#define BTL_SIDE_COUNT 2

/* Duration word of an effect: how it ends and after how many turns. */
enum {
    BTL_EFFECT_CONT_TIMED = 2 /* ends after turnLimit turns */
};
typedef union {
    u32 raw;
    struct {
        u32 kind : 3;
        u32 turnLimit : 6;
        u32 rest : 23;
    } bits;
} BtlEffectCont;

/* One row of a factor table: effect id and the function that returns its handler list. */
typedef struct {
    int effectId;
    const BtlEventHandler *(*getHandlers)(u32 *handlerCount);
} HandEffectEntry;

/* Side effect table row: also the maximum number of stacked layers. */
typedef struct {
    int effectId;
    const BtlEventHandler *(*getHandlers)(u32 *handlerCount);
    u32 maxLayers;
} HandSideEffectEntry;

/* State of one side effect on one side. */
typedef struct {
    struct BtlEventFactor *factor; /* 0 when the effect is not active */
    BtlEffectCont cont;
    u32 turnsElapsed;
    u32 layers;                    /* stack count, 0 when inactive */
} BtlSideEffectSlot;

typedef struct {
    BtlSideEffectSlot effects[BTL_SIDEEFF_COUNT];
} BtlSideEffectRow;

/* Work area of a position effect factor (BtlEventFactor.work, 7 words). */
typedef struct {
    u32 armed;       /* 0 until the first turn check has run */
    u32 startTurn;   /* turn on which the effect was set */
    u32 reserved[4];
    u32 userPokeId;  /* work[6]: Pokemon that created the effect */
} HandWishWork;

typedef struct {
    int triggerTurn; /* the attack lands when the turn count reaches this */
    u32 moveId;      /* Future Sight or Doom Desire */
    u32 reserved[4];
    u32 userPokeId;
} HandFutureSightWork;

/* Command records that the handlers push to the battle server flow. */
#define HANDEX_KIND_MESSAGE 4
#define HANDEX_KIND_RECOVER_HP 5
#define HANDEX_KIND_RESTORE_PP 9
#define HANDEX_KIND_CURE_SICK 0xb
#define HANDEX_KIND_FUTURE_SIGHT_HIT 0x27
#define HANDEX_KIND_PENDING_ENTRY 0x2a
#define HANDEX_KIND_POS_HEAL_NOTICE 0x37
#define HANDEX_MESSAGE_SET 2 /* message kind: show a message by id */

struct HandExRestorePp {
    u32 header;
    u8 amount;
    u8 pokeId;
    u8 moveIndex;
};

struct HandExFutureSightHit {
    u32 header;
    u8 attackerId;
    u8 targetId;
    u16 moveId;
};

struct HandExPendingEntry {
    u32 header;
    u8 value;
    u8 pokeId;
};

/* Position healing notice: shows the aura message at the position the effect fills. */
struct HandExPosHealNotice {
    u32 header;
    u16 animId;
    u8 position;
    u8 targetKind;
    u8 pad8[3];
    u8 restorePp;
    BtlStrParam message; /* at 0xC */
};

/* Services used by several files. */
extern struct BtlEventFactor *BTL_EVENT_AddFactor(int factorType, u16 key, int priority, u32 subPriority, u32 ownerId, u32 handlers, u16 handlerCount);
extern void BTL_EVENT_RemoveFactor(struct BtlEventFactor *factor);
extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 value);
extern void BTL_EVENT_MultiplyVar(int key, s32 ratio);

#endif
