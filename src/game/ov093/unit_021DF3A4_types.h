#ifndef UNIT_021DF3A4_TYPES_H
#define UNIT_021DF3A4_TYPES_H
/*
 * ov093 held item handlers (second part): the item version of Run Away,
 * the prize money items, the type boost items, the weather rocks and the
 * Fling-able status items. Each item has a getter that returns its handler
 * table (event id plus function) and writes the number of entries.
 */
#include "unit_021D8434_types.h"
#include "unit_021D93D8_types.h"
#include "unit_021D794C_types.h"

struct BtlEventFactor;
struct BtlSvFlow;
struct BtlPokeParam;

/* Pokemon types that the type boost items name (the battle type list, 0 = normal). */
#define BTL_TYPE_NORMAL 0
#define BTL_TYPE_FIGHTING 1
#define BTL_TYPE_FLYING 2
#define BTL_TYPE_POISON 3
#define BTL_TYPE_BUG 6
#define BTL_TYPE_ELECTRIC 12
#define BTL_TYPE_GRASS 11
#define BTL_TYPE_PSYCHIC 13
#define BTL_TYPE_DRAGON 15
#define BTL_TYPE_DARK 16

/* Species that hold-item effects check. */
#define BTL_SPECIES_PIKACHU 0x19
#define BTL_SPECIES_GIRATINA 0x1E7

/* Event ids that the handlers of these items answer (names from the handler use; guesses). */
enum {
    BTL_ITEM_EVENT_ESCAPE_MESSAGE = 0xD,
    BTL_ITEM_EVENT_MOVE_POWER = 0x38,
    BTL_ITEM_EVENT_ATTACK_RATIO = 0x3B,
    BTL_ITEM_EVENT_MEMBER_ENTER = 0x55,
    BTL_ITEM_EVENT_MEMBER_ENTER_DONE = 0x58,
    BTL_ITEM_EVENT_FLING_EFFECT = 0x73,
    BTL_ITEM_EVENT_TURN_END = 0x77,
    BTL_ITEM_EVENT_WEATHER_TURNS = 0x7C
};

/* Event variable keys that these handlers use, besides those of the included headers. */
enum {
    BTL_EVAR_WEATHER_TURNS = 0x24,
    BTL_EVAR_MOVE_POWER_RATIO = 0x31
};

/* Command kinds that these handlers queue on the battle flow. */
#define BTL_CMD_KIND_MESSAGE 4
#define BTL_CMD_KIND_ADD_SICK 12

/* String table id used by the standard battle messages. */
#define BTL_STR_TYPE_STANDARD 2

/* Item parameter ids read through the item parameter getter. */
#define BTL_ITEM_PARAM_BOOST_PERCENT 2 /* percent bonus; for weather rocks, extra turns */

/*
 * Command kind 12: put a status condition on a Pokemon, with an optional
 * message. The message part is only filled by the turn end handlers.
 */
typedef struct {
    u32 header;
    u32 sickKind;
    union BtlSickCont sickCont;
    u8 hideMessage;
    u8 pad0D[2];
    u8 pokeId;
    u8 pad10[4];
    BtlStrParam strParam;
} BtlAddSickCmd;


/* Services of the event factor and the item parameters. */
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern int BTL_HANDLER_ITEM_GetParam(struct BtlEventFactor *factor, int paramId);
extern int BTL_HANDLER_ITEM_GetBoostRatio(struct BtlEventFactor *factor);
extern u16 BTL_POKEPARAM_GetSpecies(struct BtlPokeParam *bpp);
extern void func_021C888C(BtlStrParam *strParam, u32 extraArg);
extern void func_021C8408(struct BtlSvFlow *flow, int pokeId);
extern int BTLV_CORE_EventTrySetFlagIfAttacker(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
extern union BtlSickCont BTLV_CORE_MakeSlotKind1Index15(void);
extern union BtlSickCont BTL_CALC_MakeDefaultSickCont(int sickKind);

/* The move power handler shared by all type boost items. */
void BTL_HANDLER_ITEM_BoostMovePowerOfType(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int moveType);

#endif
