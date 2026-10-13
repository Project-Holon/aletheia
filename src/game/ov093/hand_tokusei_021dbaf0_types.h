#ifndef UNIT_021DBAF0_TYPES_H
#define UNIT_021DBAF0_TYPES_H
#include "hand_common_types.h"
/*
 * ov093 battle ability handlers (third part): Magnet Pull, Unburden, Pickup,
 * Pickpocket, Cursed Body, Weak Armor, Sheer Force, Defiant, Defeatist,
 * Multiscale, Friend Guard, Healer, Toxic Boost, Flare Boost, Telepathy,
 * Moody, Overcoat, Poison Touch, Regenerator, Wonder Skin, Sand Rush and
 * Analytic. Every handler takes the factor that owns it, the server flow and
 * the id of the Pokemon that owns the factor; the four-argument form adds the
 * work words of the factor. A getter stores the handler count and returns the
 * handler table (event id plus function pairs) of one ability.
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

struct BtlEventFactor;
struct BtlServerFlow;
struct BtlPokeParam;

#define BTL_DAMAGE_TYPE_STATUS 0
#define BTL_DAMAGE_TYPE_PHYSICAL 1
#define BTL_DAMAGE_TYPE_SPECIAL 2

/* Stat ids of the rank commands, in the order of the stat stage table. */
enum {
    BTL_STAT_ATTACK = 1,
    BTL_STAT_DEFENSE = 2,
    BTL_STAT_SPEED = 5,
    BTL_STAT_COUNT_RANKED = 7     /* attack, defense, special attack, special defense, speed, accuracy, evasion */
};

/* Value ids of the poke parameter getter. */
#define BTL_POKEPARAM_VALUE_HP 0xD
#define BTL_POKEPARAM_VALUE_MAX_HP 0xE

/* Turn flag ids of the poke parameter. */
#define BTL_TURN_FLAG_ACTED 1
#define BTL_TURN_FLAG_ITEM_USED 8       /* guess */

/* Status condition slots of a Pokemon. */
#define BTL_SICK_BURN 4
#define BTL_SICK_POISON 5
#define BTL_SICK_DISABLE 0xD

#define BTL_WEATHER_SAND 4

#define POKETYPE_STEEL 8

#define BTL_MOVE_STRUGGLE 165
#define BTL_MOVE_SECRET_POWER 290
#define BTL_WAZA_FLAG_CONTACT 0

/* Fields of the move parameter getter that the Sheer Force test reads. */
#define BTL_WAZA_PARAM_ADDED_EFFECT_RATE 10   /* guess */
#define BTL_WAZA_PARAM_ADDED_EFFECT_KIND 11   /* guess */

/* Damage classes of the move data (WAZA_TOOL_GetCategory). */
enum {
    BTL_WAZA_CATEGORY_DAMAGE_PLUS_EFFECT = 4,
    BTL_WAZA_CATEGORY_DAMAGE_PLUS_SICK = 6,
    BTL_WAZA_CATEGORY_DAMAGE_PLUS_RANK = 7
};

/* Ratios in 20.12 fixed point (0x1000 is 1.0). */
enum {
    BTL_RATIO_0_5 = 0x800,
    BTL_RATIO_0_75 = 0xC00,
    BTL_RATIO_1_3 = 0x14CD,
    BTL_RATIO_1_5 = 0x1800,
    BTL_RATIO_2_0 = 0x2000
};

/* Header flags of the commands that the handlers queue. */
#define BTL_CMD_FLAG_FROM_ABILITY (1u << 23)
#define BTL_CMD_FLAG_ABILITY_ON_ALLY (1u << 25)   /* guess: Healer sets it with the ability flag */

/* Command kinds that BTL_SERVER_FLOW_AllocCmdRecord reserves. */
enum {
    BTL_CMD_KIND_MESSAGE = 4,
    BTL_CMD_KIND_REGENERATE_HP = 8,
    BTL_CMD_KIND_CURE_SICK = 0xB,
    BTL_CMD_KIND_ADD_SICK = 0xC,
    BTL_CMD_KIND_RANK_EFFECT = 0xE,
    BTL_CMD_KIND_SET_ITEM = 0x20,
    BTL_CMD_KIND_STEAL_ITEM = 0x24
};

/* Cure kind that removes every major status condition. */
#define BTL_CURE_ALL_MAJOR 0x24

/* States of the ability pop-up window (BTL_SERVER_FLOW_PushCmdRecord). */
enum {
    BTL_ABILITY_POPUP_OPEN = 2,
    BTL_ABILITY_POPUP_CLOSE = 3
};

/* String type of BTL_SERVER_FLOW_InitMsgRecord: a standard battle message. */
#define BTL_STR_TYPE_STD 2

/* Message ids. */
enum {
    BTL_MSG_TELEPATHY_AVOID = 0x1D5,
    BTL_MSG_POISON_TOUCH = 0x1D8,
    BTL_MSG_PICKPOCKET = 0x1CC,
    BTL_MSG_PICKUP = 0x1EA
};

/* A message with up to eight word arguments, embedded in the commands. */
typedef struct {
    u16 strId;
    u8 strType;
    u8 argCount : 7;
    u8 argFlag : 1;
    u32 args[8];
} BtlStrParam;

/* A packed volatile condition record (kind, parameters), as the poke parameter stores it. */
union BtlSickCont {
    u32 raw;
    struct { u32 kind : 3; u32 paramLow : 6; u32 paramHigh : 6; u32 flags : 17; } byPart;
};

/* Kind 4: a message shown on the battle screen (strParam at +4). */
typedef struct {
    u32 flags;
    BtlStrParam strParam;
} BtlMessageCmd;

/* Kind 8: restore hit points of one Pokemon without a message (Regenerator). */
typedef struct {
    u32 flags;
    u8 mode;
    u8 showBar;
    u8 pad06;
    u8 pokeId;
    u8 pad08[8];
    u32 amount;
} BtlRegenerateHpCmd;

/* Kind 0xB: cure one status slot of a Pokemon (0x24 = every major status). */
typedef struct {
    u32 flags;
    u32 sickIndex;
    u8 pokeId;
    u8 pad09[11];
    u8 showMessage;
} BtlCureSickCmd;

/* Kind 0xC: give a status condition to a Pokemon; strParam at +0x14. */
typedef struct {
    u32 flags;
    u32 sickId;
    union BtlSickCont sickCont;
    u8 pad0C[3];
    u8 targetId;
    u8 pad10[4];
    BtlStrParam strParam;
} BtlAddSickCmd;

/* Kind 0xE: a stat rank change of one or more Pokemon. */
typedef struct {
    u32 flags;
    u32 statId;
    u32 pad08;
    s8 amount;
    u8 pad0D;
    u8 showMessage;
    u8 targetCount;
    u8 targets[1];
} BtlRankCmd;

/* Kind 0x20: set the held item of a Pokemon (Pickup); strParam at +0xC. */
typedef struct {
    u32 flags;
    u16 itemId;
    u8 pokeId;
    u8 pad07;
    u8 clearConsumed;
    u8 sourcePokeId;
    u8 pad0A[2];
    BtlStrParam strParam;
} BtlSetItemCmd;

/* Kind 0x24: take the held item of another Pokemon (Pickpocket); strParam at +8. */
typedef struct {
    u32 flags;
    u8 victimId;
    u8 pad05[3];
    BtlStrParam strParam;
} BtlStealItemCmd;

/*
 * Scratch block of Pickup (14 bytes, reserved by BTL_SERVER_FLOW_GetScratchBuffer): the Pokemon
 * found around the owner, the ones that used an item, and the count.
 */
typedef struct {
    u8 candidateIds[6];
    u8 holderIds[6];
    u8 candidateCount;
    u8 spare;
} TokuseiPickupScratch;

/*
 * Scratch block of Moody (0xB6 bytes): the pairs (stat to raise, stat to
 * lower) that can be drawn, then the lists of stats that can still rise and
 * fall.
 */
typedef struct {
    u16 pairs[0x54];
    u8 raisableStats[7];
    u8 lowerableStats[7];
} TokuseiMoodyScratch;

/* Deprecated names of event variable keys, kept for files not yet cleaned. */
#define BTL_EVAR_PREVENT_FLAG BTL_EVAR_FORCE_GROUNDED_FLAG
#define BTL_EVAR_SUBSTITUTE_FLAG BTL_EVAR_HIT_SUBSTITUTE_FLAG

#endif
