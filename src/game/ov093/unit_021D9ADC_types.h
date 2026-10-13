#ifndef UNIT_021D9ADC_TYPES_H
#define UNIT_021D9ADC_TYPES_H
/*
 * ov093 ability handlers (the second half of the ability handler file): the
 * effect records a handler pushes to the battle flow, and the event variable
 * numbers the handlers read.
 *
 * A handler asks the flow for a record of one kind (HANDEX_KIND_*), fills the
 * fields that kind uses and hands it back. The record buffer is reused, so
 * each kind has its own struct; all of them start with the 32-bit header.
 */

#ifndef OV093_BASIC_TYPES
#define OV093_BASIC_TYPES
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
#endif

#include "btl_pokeparam_types.h"

struct BtlServerFlow;

/* Record kinds. The two window kinds carry no record: they open and close the ability window. */
#define HANDEX_KIND_MESSAGE 4
#define HANDEX_KIND_RECOVER_HP 5
#define HANDEX_KIND_DAMAGE 7
#define HANDEX_KIND_CURE_SICK 0xb
#define HANDEX_KIND_ADD_SICK 0xc
#define HANDEX_KIND_RANK_EFFECT 0xe
#define HANDEX_KIND_CHANGE_FORM 0x14
#define HANDEX_KIND_CHANGE_ABILITY 0x1f
#define HANDEX_ABILITY_WINDOW_IN 2
#define HANDEX_ABILITY_WINDOW_OUT 3

/* Header flags (guessed from the abilities that set them). */
#define HANDEX_FLAG_SHOW_ABILITY (1 << 23)
#define HANDEX_FLAG_SHOW_CURE_MESSAGE (1 << 25)

/* Event variables a handler reads with the event-variable getter. */
#define HANDVAR_POKE_ID 2        /* the Pokemon the event is about */
#define HANDVAR_ATTACKER_ID 3
#define HANDVAR_DEFENDER_ID 4
#define HANDVAR_MOVE_ID 0x12
#define HANDVAR_WEATHER 0x16
#define HANDVAR_SICK_ID 0x1d
#define HANDVAR_SICK_CONT 0x1e
#define HANDVAR_CRITICAL_RANK 0x2c
#define HANDVAR_SICK_DAMAGE 0x32
#define HANDVAR_GENERAL_FLAG 0x41 /* result slot several events share */
#define HANDVAR_CRITICAL_HIT 0x45
#define HANDVAR_HIT_SUBSTITUTE 0x46

/* Status ids as the handlers use them. */
#define BTL_SICK_PARALYSIS 1
#define BTL_SICK_SLEEP 2
#define BTL_SICK_BURN 4
#define BTL_SICK_POISON 5
#define BTL_SICK_INFATUATION 7

/* Value ids for the Pokemon value getter. */
#define BPP_VALUE_DEFENSE 9
#define BPP_VALUE_SP_DEFENSE 0xb
#define BPP_VALUE_GENDER 0x12
#define BPP_VALUE_ABILITY 16
#define BTL_GENDER_NONE 2

/* "No Pokemon" id and "no slot" value. */
#define BTL_POKEID_NONE 0x1f
#define BTL_SLOT_NONE 6

/* Rank (stat stage) kinds used by Download. */
#define BTL_RANK_ATTACK 1
#define BTL_RANK_SP_ATTACK 3

/* A message argument list: message id, kind, argument count and up to 8 arguments. */
struct HandExMessage {
    u16 messageId;
    u16 kind : 8;
    u16 argCount : 7;
    u16 flag : 1;
    u32 args[8];
};

#define HANDEX_MESSAGE_SET 2 /* message kind: show a message by id */

/* Kind 4: show a message. */
struct HandExMessageRecord {
    u32 header;
    struct HandExMessage message;
};

/* Kind 5: heal a Pokemon. */
struct HandExRecoverHp {
    u32 header;
    u16 amount;
    u8 pokeId;
};

/* Kind 7: damage a Pokemon. */
struct HandExDamage {
    u32 header;
    u16 amount;
    u8 pokeId;
    u8 unblockable : 1; /* damage cannot be blocked (guess) */
    u8 flagsRest : 7;
    u8 pad8[4];
    struct HandExMessage message;
};

/* Kind 0xb: cure a status condition of up to 12 listed Pokemon. */
struct HandExCureSick {
    u32 header;
    u32 sickKind;
    u8 pokeIds[12];
    u8 pokeCount;
    u8 suppressMessage;
};

/* Kind 0xc: add a status condition. */
struct HandExAddSick {
    u32 header;
    u32 sickKind;
    union SickCont sickCont;
    u8 suppressMessage;
    u8 pad0D[2];
    u8 pokeId;
};

/* Kind 0xe: change a stat stage. */
struct HandExRankEffect {
    u32 header;
    u32 rankKind;
    u8 pad8[4];
    u8 volume;
    u8 flagA;
    u8 flagB;
    u8 pokeCount;
    u8 pokeId;
    u8 pad11[7];
    struct HandExMessage message; /* at 0x18 */
};

/* Kind 0x14: switch the form of a Pokemon. */
struct HandExChangeForm {
    u32 header;
    u16 form;
    u8 pokeId;
};

/* Kind 0x1f: replace the ability of a Pokemon. */
struct HandExChangeAbility {
    u32 header;
    u16 abilityId;
    u8 pokeId;
    u8 pad7;
    u8 announce;
    u8 pad9[3];
    struct HandExMessage message;
};

#endif
