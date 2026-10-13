#ifndef UNIT_021DC6EC_TYPES_H
#define UNIT_021DC6EC_TYPES_H
/*
 * ov093 ability handlers, middle part: Sand Force, Zen Mode, Infiltrator,
 * Moxie, Justified, Rattled, Mummy, Sap Sipper, Prankster and the Magic
 * Bounce wrappers. Each ability has a handler table (event id, handler) and a
 * function that returns it with its length; the registry in
 * unit_021D8434.c maps an ability id to that function.
 */
#include "unit_021D8434_types.h"

/* Event variable keys that these handlers read or write (more keys: unit_021D8434_types.h). */
enum {
    BTL_EVAR_DEFENDER_COUNT = 5,    /* number of defenders the move hit */
    BTL_EVAR_DEFENDER_FIRST = 6,    /* defender poke ids start here, one key each */
    BTL_EVAR_MOVE_PRIORITY = 0x18,
    BTL_EVAR_POWER_RATIO = 0x31,    /* multiplier of the move power */
    BTL_EVAR_HIT_SUBSTITUTE = 0x46 /* nonzero when the hit landed on a substitute */
};

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
extern u16 func_021D5444(struct BtlPokeParam *bpp);
extern int func_021D5B68(struct BtlPokeParam *bpp);
extern u8 func_021D70AC(struct BtlEventFactor *factor);
extern void func_021D7320(struct BtlEventFactor *factor, BtlEventSkipCheck skipCheck);
extern void func_021D7324(struct BtlEventFactor *factor);
extern u8 func_021B9A40(u32 pokeId);
extern int func_021B9A24(u32 pokeIdA, u32 pokeIdB);
extern int func_021C83D4(struct BtlSvFlow *flow);
extern u32 WAZA_TOOL_GetFlag(u16 moveId, u32 flagBit);
extern int func_021DA8A8(struct BtlSvFlow *flow, int pokeId, int moveType);
extern void func_021DA96C(struct BtlSvFlow *flow, int pokeId, u32 statId, int amount);
extern void func_021E8744(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
extern void func_021E8798(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);

#endif
