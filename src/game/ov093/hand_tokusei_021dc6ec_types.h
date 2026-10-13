#ifndef UNIT_021DC6EC_TYPES_H
#define UNIT_021DC6EC_TYPES_H
#include "hand_common_types.h"
/*
 * ov093 ability handlers, middle part: Sand Force, Zen Mode, Infiltrator,
 * Moxie, Justified, Rattled, Mummy, Sap Sipper, Prankster and the Magic
 * Bounce wrappers. Each ability has a handler table (event id, handler) and a
 * function that returns it with its length; the registry in
 * btl_action_word.c maps an ability id to that function.
 */
#include "btl_action_word_types.h"

/* Value ids for the battle Pokemon value getter. */
#define BTL_BPP_VALUE_HP 13
#define BTL_BPP_VALUE_FORM 0x13
#define BTL_BPP_VALUE_ABILITY 0x10

/* Types that these handlers test (the battle type list, 0 = normal). */
enum {
    POKETYPE_GROUND = 4,
    POKETYPE_ROCK = 5,
    POKETYPE_GHOST = 7,
    POKETYPE_STEEL = 8,
    POKETYPE_DARK = 0x10
};

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
    BTL_CMD_KIND_RANK_CHANGE = 0xe,
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

/* A message with up to eight word arguments, embedded in some commands (same layout as the other ability files). */
typedef struct {
    u16 strId;
    u8 strType;
    u8 argCount : 7;
    u8 argFlag : 1;
    u32 args[8];
} BtlStrParam;

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

/* Services of the poke parameter, event factors and server flow that these handlers use. */
extern u16 BTL_POKEPARAM_GetSpecies(struct BtlPokeParam *bpp);
extern int BTL_POKEPARAM_IsFainted(struct BtlPokeParam *bpp);
extern u8 BTL_EVENT_GetFactorPokeId(struct BtlEventFactor *factor);
extern void BTL_EVENT_SetFactorSkipCheck(struct BtlEventFactor *factor, BtlEventSkipCheck skipCheck);
extern void BTL_EVENT_ClearFactorSkipCheck(struct BtlEventFactor *factor);
extern u8 BTL_MAIN_IsPokeIdInSecondPair(u32 pokeId);
extern int BTL_MAIN_IsPokeSamePair(u32 pokeIdA, u32 pokeIdB);
extern int BTL_SERVER_FLOW_CheckShowdownThunk(struct BtlSvFlow *flow);
extern u32 WAZA_TOOL_GetFlag(u16 moveId, u32 flagBit);
extern int HAND_TOKUSEI_AbsorbCheckMoveType(struct BtlSvFlow *flow, int pokeId, int moveType);
extern void HAND_TOKUSEI_AbsorbRaiseStat(struct BtlSvFlow *flow, int pokeId, u32 statId, int amount);
extern void BTLV_CORE_EventRedirectMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
extern void BTLV_CORE_EventCounterMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);

/* Deprecated names of event variable keys, kept for files not yet cleaned. */
#define BTL_EVAR_HIT_SUBSTITUTE BTL_EVAR_HIT_SUBSTITUTE_FLAG

#endif
