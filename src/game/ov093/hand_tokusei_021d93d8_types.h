#ifndef UNIT_021D93D8_TYPES_H
#define UNIT_021D93D8_TYPES_H
#include "hand_common_types.h"
/*
 * ov093 battle ability handlers (status guards, weather abilities, weather
 * recovery, stat guards). Each ability is a handler table (event id plus
 * function) that its getter returns; the handlers answer battle events and
 * queue commands on the battle flow.
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

/* Event variable keys read and rewritten by the handlers. */

/* Status condition slots of BtlPokeParam.sickCont (1..5 are the major statuses). */
#define TKS_SICK_PARALYSIS 1
#define TKS_SICK_SLEEP 2
#define TKS_SICK_FREEZE 3
#define TKS_SICK_BURN 4
#define TKS_SICK_POISON 5
#define TKS_SICK_CONFUSION 6
#define TKS_SICK_INFATUATION 7

/* Weather ids returned by the flow and stored in weather commands. */
#define TKS_WEATHER_SUN 1
#define TKS_WEATHER_RAIN 2
#define TKS_WEATHER_HAIL 3
#define TKS_WEATHER_SAND 4

/* A message with up to eight word arguments, embedded in some commands. */
typedef struct {
    u16 strId;
    u8 strType;
    u8 argCount : 7;
    u8 argFlag : 1;
    u32 args[8];
} BtlStrParam;

/* Command kind 4: a message shown on the battle screen (strParam at +4). */
typedef struct {
    u32 flags;
    BtlStrParam strParam;
} TokuseiMessageCmd;

/* Command kind 0xb: cure one status slot of a Pokemon (0x24 = every major status). */
typedef struct {
    u32 flags;
    u32 sickIndex;
    u8 pokeId;
    u8 pad9[11];
    u8 showMessage;
} TokuseiCureSickCmd;

/* Command kind 0x1d: change the weather (turns 0xff = no limit); strParam at +8. */
typedef struct {
    u32 flags;
    u8 weather;
    u8 turns;
    u8 announce;
    u8 pad7;
    BtlStrParam strParam;
} TokuseiWeatherCmd;

/* Command kinds 5 and 7: restore (5) or remove (7) hit points of a Pokemon. */
typedef struct {
    u32 flags;
    u16 amount;
    u8 pokeId;
} TokuseiHpCmd;

/* Deprecated names of event variable keys, kept for files not yet cleaned. */
#define TKS_EVAR_POKE_ID BTL_EVAR_POKE_ID
#define TKS_EVAR_ATTACKER_ID BTL_EVAR_ATTACKER_ID
#define TKS_EVAR_DEFENDER_ID BTL_EVAR_DEFENDER_ID
#define TKS_EVAR_MOVE_ID BTL_EVAR_MOVE_ID
#define TKS_EVAR_CONDITION BTL_EVAR_SICK_ID
#define TKS_EVAR_CHANGE_AMOUNT BTL_EVAR_EFFECT_PERCENT
#define TKS_EVAR_POWER_RATIO BTL_EVAR_RATIO
#define TKS_EVAR_WEATHER BTL_EVAR_WEATHER
#define TKS_EVAR_FAIL_FLAG BTL_EVAR_FORCE_GROUNDED_FLAG

#endif
