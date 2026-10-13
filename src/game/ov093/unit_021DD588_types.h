#ifndef UNIT_021DD588_TYPES_H
#define UNIT_021DD588_TYPES_H
/*
 * ov093 held item handlers (berries): the effect records a handler pushes to
 * the battle flow and the event variable numbers the handlers read.
 *
 * A handler asks the flow for a record of one kind (HANDEX_KIND_*), fills the
 * fields that kind uses and hands it back. Every record starts with the
 * 32-bit header the flow writes.
 */

#include "btl_pokeparam_types.h"

struct BtlEventFactor;

/* Record kinds that the item handlers push. */
#define HANDEX_KIND_MESSAGE 4
#define HANDEX_KIND_RECOVER_HP 5
#define HANDEX_KIND_ADD_SICK 0xc
#define HANDEX_KIND_RANK_EFFECT 0xe
#define HANDEX_KIND_SET_CONT_FLAG 0x17

/* Event variables the item handlers read with the event variable getter. */
#define BTL_EVAR_POKE_ID 2
#define BTL_EVAR_DEFENDER_ID 4
#define BTL_EVAR_TYPE_AFFINITY 0x38
#define BTL_EVAR_HIT_SUBSTITUTE 0x46 /* set when the hit went into a substitute */

/* Type affinity values above this are super effective. */
#define BTL_AFFINITY_SUPER_EFFECTIVE_ABOVE 3

/* Value ids of the poke parameter getter. */
#define BTL_VALUE_MAX_HP 0xe

/* Status ids. */
#define BTL_SICK_CONFUSION 6
#define BTL_SICK_ITEM_BLOCK 15 /* the status that stops a held item from acting (guess: Embargo) */

/* Stat ids of the rank (stat stage) records; also the numbers the stat berries use. */
#define BTL_RANK_ATTACK 1
#define BTL_RANK_DEFENSE 2
#define BTL_RANK_SP_ATTACK 3
#define BTL_RANK_SP_DEFENSE 4
#define BTL_RANK_SPEED 5
#define BTL_RANK_KIND_COUNT 5

/* Pokemon type ids (a dense list: there is no unused slot between steel and fire). */
enum {
    POKETYPE_NORMAL = 0,
    POKETYPE_FIGHTING = 1,
    POKETYPE_FLYING = 2,
    POKETYPE_POISON = 3,
    POKETYPE_GROUND = 4,
    POKETYPE_ROCK = 5,
    POKETYPE_BUG = 6,
    POKETYPE_GHOST = 7,
    POKETYPE_STEEL = 8,
    POKETYPE_FIRE = 9,
    POKETYPE_WATER = 10,
    POKETYPE_GRASS = 11,
    POKETYPE_ELECTRIC = 12,
    POKETYPE_PSYCHIC = 13,
    POKETYPE_ICE = 14,
    POKETYPE_DRAGON = 15,
    POKETYPE_DARK = 16
};

/* Condition flag that the critical-rate berry sets. */
#define BTL_CONT_FLAG_CRITICAL_UP 9

/* Slots of the per-item work words the handlers share. */
#define ITEM_WORK_USED 0       /* nonzero once the item has acted */
#define ITEM_WORK_FORCED_USE 6 /* set when the item was used from outside (same slot as unit_021DCAE8_types.h) */

/* A message with up to eight word arguments, embedded in some records. */
typedef struct {
    u16 strId;
    u8 strType;
    u8 argCount : 7;
    u8 extraSet : 1;
    u32 args[8];
} HandExStr;

#define HANDEX_STR_SET 2 /* message type: show a message by id with a Pokemon name */

/* Kind 4: show a message. */
typedef struct {
    u32 header;
    HandExStr str;
} HandExMessage;

/* Kind 5: heal a Pokemon; the message is at +8. */
typedef struct {
    u32 header;
    u16 amount;
    u8 pokeId;
    u8 pad07;
    HandExStr str;
} HandExRecoverHp;

/* Kind 0xc: add a status condition. */
typedef struct {
    u32 header;
    u32 sickKind;
    union SickCont sickCont;
    u8 suppressMessage;
    u8 pad0D[2];
    u8 pokeId;
} HandExAddSick;

/* Kind 0xe: change a stat stage (volume is the number of stages). */
typedef struct {
    u32 header;
    u32 rankKind;
    u8 pad08[4];
    s8 volume;
    u8 flagA;
    u8 flagB;
    u8 pokeCount;
    u8 pokeId;
} HandExRankEffect;

/* Kind 0x17: set a condition flag on a Pokemon. */
typedef struct {
    u32 header;
    u32 flagId;
    u8 pokeId;
} HandExSetContFlag;

#endif
