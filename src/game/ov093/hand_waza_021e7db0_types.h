#ifndef HAND_WAZA_021E7DB0_TYPES_H
#define HAND_WAZA_021E7DB0_TYPES_H
/*
 * ov093 move handlers (HAND_WAZA_), tail of the move block: Round, Quick Guard,
 * Ally Switch, Telekinesis, Sky Drop, Relic Song, Foresight, Odor Sleuth,
 * Miracle Eye, Growth, Freeze Shock, Ice Burn, Fusion Flare, Fusion Bolt and the
 * three Pledge moves, plus three helpers that the ability, item and move
 * handlers all call (HAND_COMMON_).
 *
 * The move registry rows ({move id, getter}) at 0x021F366C..0x021F383C name the
 * owner of every getter. A getter stores the row count of its handler table
 * ({event id, handler} rows) and returns the table.
 */
#include "btl_event_types.h"
#include "hand_common_types.h"
#include "btl_pokeparam_types.h"

struct BtlServerFlow;
struct BtlTurnRecord;


/* Moves (ids of the move registry). */
#define BTL_MOVE_ROUND 496
#define BTL_MOVE_QUICK_GUARD 501
#define BTL_MOVE_ALLY_SWITCH 502
#define BTL_MOVE_WATER_PLEDGE 518
#define BTL_MOVE_FIRE_PLEDGE 519
#define BTL_MOVE_GRASS_PLEDGE 520
#define BTL_MOVE_FREEZE_SHOCK 553
#define BTL_MOVE_ICE_BURN 554
#define BTL_MOVE_FUSION_FLARE 558
#define BTL_MOVE_FUSION_BOLT 559

/* Species, items and types that these handlers test. */
#define BTL_SPECIES_DIGLETT 50
#define BTL_SPECIES_DUGTRIO 51
#define BTL_SPECIES_MELOETTA 648
#define BTL_TYPE_FLYING 2
#define BTL_TYPE_GHOST 7
#define BTL_TYPE_FIRE 9
#define BTL_TYPE_WATER 10
#define BTL_TYPE_GRASS 11
#define BTL_TYPE_DARK 16

/* Event variable keys of these handlers beyond hand_common_types.h. */
#define BTL_EVAR_EFFECTIVE_MOVE_ID 0x13      /* move id the flow shows and animates (a Pledge combination replaces it) */
#define BTL_EVAR_WAZA_POWER 0x30
#define BTL_EVAR_MESSAGE 0x3F                /* pointer to the message the event is about to show */
#define BTL_EVAR_REFLECTED_FLAG 0x4F         /* guess: the move was reflected or absorbed on the way */
#define BTL_EVAR_PREVENT_FLAG BTL_EVAR_FORCE_GROUNDED_FLAG
#define BTL_EVAR_GENERIC_FLAG BTL_EVAR_FORCE_FLOATING_FLAG
#define BTL_EVAR_SKIP_CHARGE_FLAG BTL_EVAR_FORCE_FLOATING_FLAG

/* Battle rules (BTL_SERVER_FLOW_GetRule), the client id that marks "no client", message string types. */
#ifndef BTL_RULE_SINGLE
#define BTL_RULE_SINGLE 0
#endif
#ifndef BTL_RULE_DOUBLE
#define BTL_RULE_DOUBLE 1
#endif
#ifndef BTL_RULE_TRIPLE
#define BTL_RULE_TRIPLE 2
#endif
#ifndef BTL_RULE_ROTATION
#define BTL_RULE_ROTATION 3
#endif
#ifndef BTL_CLIENT_ID_NONE
#define BTL_CLIENT_ID_NONE 4
#endif
#define BTL_STRTYPE_STD 1
#define BTL_STRTYPE_SET 2

/* Value ids of the Pokemon value getter (func_021D59B4) and weather values. */
#define BTL_BPP_VALUE_FORM 19
#define BTL_WEATHER_SUN 1
#define BTL_RATIO_DOUBLE 0x2000                    /* fixed point ratio, 0x1000 is 1.0 */

/* Values of the calls above. */
#define BTL_POS_NONE 6                             /* "no position" */
#define BTL_COUNTER_BOUND_TARGET 4                 /* counter slot: id + 1 of the Pokemon that Sky Drop holds */
#define BTL_BOUND_TARGET_LIMIT 0x18                /* counter values from here on mean no Pokemon */
#define BTL_SICK_INGRAIN 0x15
#define BTL_SICK_FLOATING_BLOCK 0x1f               /* guess: Smack Down */
#define BTL_SICK_TELEKINESIS 0x20

/* Record kinds (HANDEX_KIND_*) beyond the ones of hand_waza_021e4754_types.h. */
#define HANDEX_KIND_SWAP_POSITIONS 0x32
#define HANDEX_KIND_PLAY_EFFECT 0x37
#define HANDEX_KIND_CHANGE_MON_FORM 0x39

/* Strings these handlers show. */
#define HAND_WAZA_STR_QUICK_GUARD 0xa2
#define HAND_WAZA_STR_PLEDGE_WAITING 0xbb
#define HAND_WAZA_STR_FORM_CHANGE 0xde
#define HAND_WAZA_STR_SKY_DROP 1118
#define HAND_WAZA_STR_ALLY_SWITCH 1137
#define HAND_WAZA_STR_TELEKINESIS 1140
#define HAND_WAZA_STR_FREEZE_SHOCK_CHARGE 0x35f
#define HAND_WAZA_STR_ICE_BURN_CHARGE 0x362
#define HAND_WAZA_STR_RAINBOW 0xa4
#define HAND_WAZA_STR_SEA_OF_FIRE 0xa8
#define HAND_WAZA_STR_SWAMP 0xac

/* Side effect kinds that continue the side effect numbering of the Wide Guard handler (Wide Guard is 9). */
#define BTL_SIDE_EFFECT_QUICK_GUARD_KIND 10
#define BTL_SIDE_EFFECT_RAINBOW 11
#define BTL_SIDE_EFFECT_SEA_OF_FIRE 12
#define BTL_SIDE_EFFECT_SWAMP 13

/* Battle effect ids played when a Pledge combination starts. */
#define BTL_EFFECT_RAINBOW 0x28d
#define BTL_EFFECT_SEA_OF_FIRE 0x28e
#define BTL_EFFECT_SWAMP 0x28f

/* Combination kinds of two Pledge moves; 0 is no combination. */
#define PLEDGE_COMBO_NONE 0
#define PLEDGE_COMBO_RAINBOW 1       /* Water + Fire: Water type, helps the user's side */
#define PLEDGE_COMBO_SEA_OF_FIRE 2   /* Grass + Fire: Fire type, hurts the foe side */
#define PLEDGE_COMBO_SWAMP 3         /* Water + Grass: Grass type, slows the foe side */
#define PLEDGE_COMBINED_POWER 150

/* Kind 4: show a message. */
/* Name of the message parameter in these handlers. */
typedef BtlStrParam BtlMessageParam;


#define HANDEX_KIND_MESSAGE 4

#define HANDEX_KIND_ADD_SIDE_EFFECT 0x19

/* Kind 0x32: two Pokemon swap places, then a message names both. */
struct HandExSwapPositions {
    u32 header;
    u8 pokeId;
    u8 partnerId;
    u8 pad06[2];
    BtlMessageParam message;
};

/* Kind 0x37: play a battle effect between two positions. */
struct HandExPlayEffect {
    u32 header;
    u16 effectId;
    u8 fromPos;
    u8 toPos;
};

/* One row of the Pledge combination table: two moves and the combination they make. */
struct PledgeCombo {
    u16 firstMove;
    u16 secondMove;
    int combo;
};

/* Work words of a Pledge factor. */
struct PledgeWork {
    int combined;     /* nonzero once a partner Pledge is paired with this one */
    int combo;        /* PLEDGE_COMBO_* */
    int partnerId;    /* id of the partner Pokemon that chose the other Pledge */
};

/* Services used by the handlers of these files. */
extern int BTL_EVENT_GetVar(int key);
extern int func_021D59B4(struct BtlPokeParam *bpp, int valueId);
extern void BTL_EVENT_MultiplyVar(int key, int ratio);
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern void BTL_SERVER_FLOW_CommitCmdRecord(struct BtlServerFlow *flow, void *record);
extern void BTL_SERVER_FLOW_SetCurTurnStateFlag(struct BtlServerFlow *flow, int flag);
extern u8 BTL_MAIN_IsPokeIdInSecondPair(u32 pokeId);
extern int BTL_MAIN_IsPokeSamePair(unsigned int pokeIdA, unsigned int pokeIdB);
extern unsigned char BTL_POKEPARAM_GetCounter(struct BtlPokeParam *bpp, int counterId);
extern union SickCont BTLV_CORE_MakeSlotKind2Index(int turns);
extern void HAND_WAZA_AddSideEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int *work,
                                    u8 side, int effectKind, union SickCont cont, u16 messageId);
extern void HAND_WAZA_ProtectIncrementStreak(struct BtlServerFlow *flow, int pokeId, int silent);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(struct BtlServerFlow *flow, int kind, int pokeId);
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlServerFlow *flow, int pokeId);
extern int BTL_EVENT_OverwriteVar(int key, u32 value);
extern int BTL_EVENT_GetClientReservedChoice(struct BtlPokeParam *bpp, u8 *pokeId, u16 *moveId);
extern struct BtlTurnRecord *BTL_SERVER_FLOW_GetTurnRecord(struct BtlServerFlow *flow);
extern u16 BTL_SERVER_FLOW_GetTurnCount(struct BtlServerFlow *flow);
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(struct BtlServerFlow *flow);
extern int BTL_SERVER_FLOW_GetRule(struct BtlServerFlow *flow);
extern u32 BTL_SERVER_FLOW_GetClientIdBySide(struct BtlServerFlow *flow, u8 clientId);
extern int BTL_SERVER_FLOW_GetPokeIdAtPos(struct BtlServerFlow *flow, int pos);
extern int BTL_SERVER_FLOW_IsPokeInPosTable(struct BtlServerFlow *flow, u8 pokeId);
extern int BTL_SERVER_FLOW_ProcMoveReflectOrAbsorbById(struct BtlServerFlow *flow, int attackerId, int targetId, int *reflected);
extern void BTL_SERVER_FLOW_ReleaseBindingTargetById(struct BtlServerFlow *flow, int pokeId);
extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 pokeId);
extern u8 BTL_MAIN_GetOwnLanePos(u32 viewPos, u32 lane);
extern u32 BTL_MAIN_IsBackRowPos(u32 viewPos);
extern int BTL_POKEPARAM_HasType(struct BtlPokeParam *bpp, int type);
extern u16 BTL_POKEPARAM_GetSpecies(struct BtlPokeParam *bpp);
extern void BTLV_CORE_EventScaleDamage(int ratio);
extern void BTLV_CORE_SetSlotValue(union SickCont *slot, u16 value);
extern u32 func_0689D098(struct BtlTurnRecord *record, int moveId, int turnCount);
extern int func_0689D0C8(struct BtlTurnRecord *record, int turnCount);



#endif
