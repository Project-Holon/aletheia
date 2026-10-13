#ifndef UNIT_021DF974_TYPES_H
#define UNIT_021DF974_TYPES_H
/*
 * ov093 held item handlers: the Orbs, Iron Ball, Float Stone, Eviolite,
 * Rocky Helmet, Air Balloon, Red Card and Ring Target. Each item has a getter
 * that stores the handler count and returns a table of (event id, handler)
 * pairs; the handlers answer one event each. The tables are registered by
 * item id (0x87 Adamant Orb, 0x116 Iron Ball, 0x21A..0x220 Eviolite to
 * Binding Band).
 *
 * Event ids in the tables of these items:
 *   0x38 move power, 0x13 speed ratio, 0x12 ground check, 0x7B weight ratio,
 *   0x3C defense ratio, 0x4B damage reaction, 0x55 enter field,
 *   0x83 damage reaction at the end of the move, 0x3E type immunity check.
 */
#include "unit_021D8434_types.h"
#include "unit_021D93D8_types.h"

/* Event variable keys that only these items use. */
#define BTL_EVAR_MOVE_POWER_RATIO 0x31   /* multiplied by the item's power ratio */
#define BTL_EVAR_HIT_SUBSTITUTE_FLAG 0x46 /* set when the hit went into a substitute */
#define BTL_EVAR_IMMUNITY_OVERRIDE_FLAG 0x4B /* set to ignore the target's type immunity */
#define BTL_EVAR_SHEER_FORCE_FLAG 0x4D   /* guess: the move is boosted by Sheer Force, no secondary item effect */
#define BTL_EVAR_FORCE_GROUNDED_FLAG 0x41 /* set by Iron Ball: the holder counts as grounded */
#define BTL_EVAR_FORCE_FLOATING_FLAG 0x51 /* set by Air Balloon: the holder counts as floating */

/* Record kinds that these handlers push to the flow. */
#define BTL_CMD_KIND_MESSAGE 4
#define BTL_CMD_KIND_LOSE_HP 7
#define BTL_CMD_KIND_SET_ITEM 0x20
#define BTL_CMD_KIND_ITEM_MESSAGE 0x23   /* guess: message with the user and a second Pokemon as arguments */
#define BTL_CMD_KIND_FORCE_SWITCH 0x2E   /* guess */

/* Species and move class constants that the Orbs test. */
#define SPECIES_DIALGA 483
#define SPECIES_PALKIA 484
#define POKETYPE_STEEL 8
#define POKETYPE_DRAGON 15

/* Indexes of the item parameter reader. */
#define BTL_ITEM_PARAM_DAMAGE_DIVISOR 2  /* Rocky Helmet: fraction of the attacker's max HP is 1/this */

#define BTL_FIELD_EFFECT_GRAVITY_QUERY 2 /* guess: argument of the field effect check Air Balloon makes */
#define BTL_STR_TYPE_STANDARD 2

/* Kind 7: remove hit points of a Pokemon, then show a message at +0xC. */
typedef struct {
    u32 header;
    u16 amount;
    u8 pokeId;
    u8 pad07[5];
    BtlStrParam strParam;
} BtlLoseHpCmd;

/* Kind 0x20: change the held item of a Pokemon (itemId 0 removes it), then show a message at +0xC. */
typedef struct {
    u32 header;
    u16 itemId;
    u8 pokeId;
    u8 announce;
    u32 pad08;
    BtlStrParam strParam;
} BtlSetItemCmd;

/* Kind 0x23: a message at +8 whose arguments are poke ids. */
typedef struct {
    u32 header;
    u32 pad04;
    BtlStrParam strParam;
} BtlItemMessageCmd;

/* Kind 0x2E: force a Pokemon out of the field; mode is the high nibble of byte 7. */
typedef struct {
    u32 header;
    u16 strId;       /* guess: 0x28C */
    u8 pokeId;
    u8 modeLow : 4;
    u8 mode : 4;
} BtlForceSwitchCmd;

#define BTL_FORCE_SWITCH_MODE_ITEM 1
#define BTL_FORCE_SWITCH_STR_ID 0x28C

extern u16 BTL_POKEPARAM_GetSpecies(struct BtlPokeParam *bpp);          /* species */
extern int BTL_HANDLER_ITEM_GetBoostRatio(struct BtlEventFactor *factor);     /* power ratio of the held item */
extern int BTL_HANDLER_ITEM_GetParam(struct BtlEventFactor *factor, int index); /* item parameter */
extern int BTL_CALC_DivideMaxHpMin1(struct BtlPokeParam *bpp, u32 divisor); /* max HP / divisor, at least 1 */
extern int func_021C818C(struct BtlSvFlow *flow, int pokeId);    /* guess: the Pokemon can still evolve */
extern int BTL_FIELD_GetStaticSlotObject(int query);
extern int func_021E85F8(int pokeId);
extern int func_021C7D00(struct BtlSvFlow *flow, int pokeId);
extern int func_021C7F24(struct BtlSvFlow *flow, int pokeId);
extern int func_021C83D4(struct BtlSvFlow *flow);
extern u32 func_021C7EC4(struct BtlSvFlow *flow);
extern u32 WAZA_TOOL_GetFlag(u16 moveId, u32 bit);

#endif
