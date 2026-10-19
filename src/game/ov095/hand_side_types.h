#ifndef UNIT_06898F04_TYPES_H
#define UNIT_06898F04_TYPES_H
/*
 * ov095 side effect handlers (factor type 2): Safeguard, Mist, Tailwind, Lucky
 * Chant, Stealth Rock, Wide Guard, Quick Guard, Spikes, Toxic Spikes and the
 * three Pledge combinations (Rainbow, Swamp, Sea of Fire). Each effect has a getter that
 * stores the handler count and returns its handler table (event id plus
 * function). The owner id of a side effect factor is the side it protects, so
 * the third handler argument is a side, not a Pokemon id.
 */
#include "hand_field_types.h"

/* Event ids that the side effect handler tables answer (names from the handler bodies). */
enum {
    BTL_SIDE_EVENT_NO_EFFECT_CHECK = 0x2C,   /* Wide Guard, Quick Guard: a move may be blocked */
    BTL_SIDE_EVENT_CRITICAL_CHECK = 0x36,    /* Lucky Chant: a critical hit may be blocked */
    BTL_SIDE_EVENT_STAT_DROP_CHECK = 0x5B,   /* Mist: a stat drop may be blocked */
    BTL_SIDE_EVENT_STAT_DROP_NOTICE = 0x5C,  /* Mist: show that a stat drop was blocked */
    BTL_SIDE_EVENT_SICK_BLOCK_CHECK = 0x65,  /* Safeguard: a status condition may be blocked */
    BTL_SIDE_EVENT_SICK_BLOCK_NOTICE = 0x67  /* Safeguard: show that a status condition was blocked */
};

/* Event variable keys that the shared enum does not name yet. */
enum {
    HAND_SIDE_EVAR_STAT_ID = 0x19,       /* Mist: the stat that the drop is about */
    HAND_SIDE_EVAR_MESSAGE_PARAM = 0x3F  /* no-effect check: address of the message the flow shows */
};

/* Result flag of a check event (hand_common_types.h names the same slot for Iron Ball). */
#define HAND_SIDE_EVAR_PREVENT_FLAG BTL_EVAR_FORCE_GROUNDED_FLAG

/* Status condition ids that Safeguard blocks besides the major statuses (guess for the second). */
#define BTL_SICK_CONFUSION 6
#define BTL_SICK_YAWN 0xE

/* Message ids of the side effect notices. */
enum {
    BTL_MSG_SAFEGUARD_BLOCKED = 0x347,
    BTL_MSG_MIST_BLOCKED = 0x34A,
    BTL_MSG_WIDE_GUARD_BLOCKED = 0x31D,
    BTL_MSG_QUICK_GUARD_BLOCKED = 0x320,
    BTL_MSG_STEALTH_ROCK_HURT = 0x356,
    BTL_MSG_SPIKES_HURT = 0x353,
    BTL_MSG_SEA_OF_FIRE_HURT = 0x484
};

/* Move data fields (WAZA_TOOL_GetParam). */
#define WAZA_PARAM_PRIORITY 6
#define WAZA_PARAM_TARGET_RANGE 0x1B

/* Target ranges that Wide Guard blocks (guess for the names). */
#define WAZA_RANGE_ALL_ENEMIES 4
#define WAZA_RANGE_ALL_OTHERS 5

/* Type affinity classes that BTL_CALC_GetTypeAffinityVsPair returns (higher is more effective). */
enum {
    BTL_AFFINITY_CLASS_HALF = 2,
    BTL_AFFINITY_CLASS_NEUTRAL = 3,
    BTL_AFFINITY_CLASS_DOUBLE = 4,
    BTL_AFFINITY_CLASS_QUADRUPLE = 5
};

#define BTL_TYPE_ROCK 5

/* The ratio that doubles a value (1/4096 units). */
#define HAND_RATIO_DOUBLE 0x2000

/* Record kind 7: hurt one Pokemon, then show a message. */
#define HANDEX_KIND_DAMAGE 7

/* Record kind 12 (HandExAddSick) and 0x1a (remove a side effect), kind 0x37 (play an effect). */
#define HANDEX_KIND_REMOVE_SIDE_EFFECT 0x1A
#define HANDEX_KIND_PLAY_EFFECT 0x37
#define HAND_SIDE_EFFECT_ID_TOXIC_SPIKES 3
#define HAND_RATIO_QUARTER 0x400
#define BTL_SICK_POISON 5

/* HANDEX_KIND_REMOVE_SIDE_EFFECT: end a side effect (the layers byte is rebuilt by an inline helper). */
typedef struct HandExRemoveSideEffect {
    u32 header;
    u8 effectCont[3];
    u8 side;
} HandExRemoveSideEffect;

/* HANDEX_KIND_PLAY_EFFECT: play a battle animation on a Pokemon, then show a message. */
typedef struct HandExPlayEffect {
    u32 header;
    u16 effectId;
    u8 viewPos;
    u8 mode;
} HandExPlayEffect;

extern int BTL_SERVER_FLOW_IsPokeGroundedById(struct BtlServerFlow *flow, int pokeId);
extern int BTL_SERVER_FLOW_IsPokeInPosTable(struct BtlServerFlow *flow, u8 pokeId);
extern int BTL_SERVER_FLOW_GetPokeViewPos(struct BtlServerFlow *flow, int pokeId);
extern int BTL_POKEPARAM_HasType(struct BtlPokeParam *bpp, int typeId);
extern u32 BTL_SICKCONT_MakeKind1Empty(void);
extern u32 BTL_SICKCONT_MakeKind1Index15(void);
extern int HAND_SIDE_GetStackCountByFactor(struct BtlEventFactor *factor, u32 side);

extern u8 BTL_MAIN_IsPokeIdInSecondPair(u32 pokeId);
extern int BTL_CALC_HasDefaultSickCont(int sickIndex);
extern u16 BTL_POKEPARAM_GetTypePair(struct BtlPokeParam *bpp);
extern int BTL_CALC_GetTypeAffinityVsPair(int type, u16 typePair);
extern u32 WAZA_TOOL_GetParam(u16 moveId, u32 paramId);
extern u32 WAZA_TOOL_IsDamaging(u16 moveId);

#endif
