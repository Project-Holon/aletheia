#ifndef UNIT_021DA624_TYPES_H
#define UNIT_021DA624_TYPES_H
/*
 * ov093 ability handlers (second part): Frisk, Sturdy, Unaware, Heatproof,
 * Dry Skin, Water Absorb, Volt Absorb, Motor Drive, Scrappy, Soundproof,
 * Levitate, Wonder Guard, Truant, Damp, Flash Fire, Bad Dreams. Every handler
 * takes the factor that owns it, the server flow and the id of the Pokemon
 * that owns the factor, and the four-argument form adds the factor's work words.
 */
#include "btl_event_types.h"
#include "btl_pokeparam_types.h"

struct BtlSvFlow;

/* Event variable keys that the handlers of this unit read or write. */
enum {
    BTL_EVAR_POKE_ID = 2,
    BTL_EVAR_ATTACKER_ID = 3,
    BTL_EVAR_DEFENDER_ID = 4,
    BTL_EVAR_MOVE_ID = 0x12,
    BTL_EVAR_DEFENDER_TYPE = 0x15,
    BTL_EVAR_MOVE_TYPE = 0x16,
    BTL_EVAR_SICK_ID = 0x1D,
    BTL_EVAR_FAIL_REASON = 0x22,
    BTL_EVAR_ATTACK_STAGE = 0x27,
    BTL_EVAR_DEFENSE_STAGE = 0x28,
    BTL_EVAR_POWER_RATIO = 0x31,
    BTL_EVAR_DAMAGE = 0x32,
    BTL_EVAR_RATIO = 0x35,
    BTL_EVAR_ENDURE_REASON = 0x3A,
    BTL_EVAR_TYPE_AFFINITY = 0x38,
    BTL_EVAR_WEATHER = 0x39,
    BTL_EVAR_NO_EFFECT_FLAG = 0x40,
    BTL_EVAR_PREVENT_FLAG = 0x41,
    BTL_EVAR_IGNORE_IMMUNITY_FLAG = 0x4B,
    BTL_EVAR_GENERIC_FLAG = 0x51
};

/* Weather ids of BTL_EVAR_WEATHER. */
enum {
    BTL_WEATHER_SUN = 1,
    BTL_WEATHER_RAIN = 2
};

/* Type affinity classes: 3 is neutral, higher is super effective. */
#define BTL_AFFINITY_NEUTRAL 3

/* Type ids. */
enum {
    POKETYPE_GHOST = 7,
    POKETYPE_FIRE = 9,
    POKETYPE_WATER = 10,
    POKETYPE_ELECTRIC = 12
};

/* Stat ids of the rank commands. */
#define BTL_STAT_SPEED 5

/* Value of BTL_EVAR_ENDURE_REASON that marks an endure by Sturdy. */
#define BTL_ENDURE_REASON_STURDY 4

/* Stat stage 6 is the neutral stage (no boost). */
#define BTL_STAT_STAGE_NEUTRAL 6

/* Major status ids. */
enum {
    BTL_SICK_SLEEP = 2,
    BTL_SICK_BURN = 4
};

/* Ratios in 20.12 fixed point (0x1000 is 1.0). */
enum {
    BTL_RATIO_0_5 = 0x800,
    BTL_RATIO_1_25 = 0x1400,
    BTL_RATIO_1_5 = 0x1800
};

#define BTL_MOVE_SELF_DESTRUCT 120
#define BTL_MOVE_EXPLOSION 153
#define BTL_MOVE_STRUGGLE 165
#define BTL_WAZA_FLAG_SOUND 8

/* Ability ids that a handler tests. */
#define ABILITY_AFTERMATH 106

/* Event type of ability factors (the factorType argument of a skip check). */
#define BTL_EVENT_TYPE_ABILITY 4

/* Cont flag index that Flash Fire sets on its owner. */
#define BTL_CONT_FLAG_FLASH_FIRE 13

/* Fail reason that Truant and Damp write to BTL_EVAR_FAIL_REASON. */
#define BTL_FAIL_REASON_ABILITY 19

/* Header flag that ability commands set. */
#define BTL_CMD_FLAG_FROM_ABILITY (1u << 23)

/* Command kinds that func_021C88A4 reserves. */
enum {
    BTL_CMD_MESSAGE = 4,
    BTL_CMD_RECOVER_HP = 5,
    BTL_CMD_DAMAGE = 7,
    BTL_CMD_RANK = 14,
    BTL_CMD_SET_CONT_FLAG = 0x17,
    BTL_CMD_CLEAR_CONT_FLAG = 0x18
};

/* States of the ability pop-up window (func_021C88B4). */
enum {
    BTL_ABILITY_POPUP_OPEN = 2,
    BTL_ABILITY_POPUP_CLOSE = 3
};

/* String type of func_021C8838: a standard battle message. */
#define BTL_STR_TYPE_STD 2

/* Message ids. */
enum {
    BTL_MSG_ABILITY_NO_EFFECT = 0xD2,
    BTL_MSG_ABSORB_RECOVER_HP = 0x183,
    BTL_MSG_FLASH_FIRE_ABSORB = 0x1AB,
    BTL_MSG_FRISK_ITEM = 0x1B7,
    BTL_MSG_TRUANT_LOAFING = 0x1BD,
    BTL_MSG_BAD_DREAMS_HURT = 0x1E4,
    BTL_MSG_STURDY_ENDURE = 0x202,
    BTL_MSG_DAMP_BLOCK = 0x389
};

/* A string parameter block; its size depends on the command that holds it. */
typedef struct {
    u32 words[1];
} BtlStrParam;

/* Kind 4: show a message. */
typedef struct {
    u32 header;
    BtlStrParam strParam;
} BtlMessageCmd;

/* Kind 5: restore HP of one Pokemon. */
typedef struct {
    u32 header;
    u16 amount;
    u8 pokeId;
    u8 pad07;
    BtlStrParam strParam;
} BtlRecoverHpCmd;

/* Kind 7: hurt one Pokemon. */
typedef struct {
    u32 header;
    u16 amount;
    u8 pokeId;
    u8 pad07[5];
    BtlStrParam strParam;
} BtlDamageCmd;

/* Kind 14: change a stat rank of the listed Pokemon. */
typedef struct {
    u32 header;
    u32 statId;
    u32 pad08;
    s8 amount;
    u8 pad0D;
    u8 showMessage;
    u8 targetCount;
    u8 targets[1];
} BtlRankCmd;

/* Kinds 0x17 and 0x18: set or clear one cont flag of a Pokemon. */
typedef struct {
    u32 header;
    u32 flagIndex;
    u8 pokeId;
} BtlContFlagCmd;

/* Services of the event variable stack. */
extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 value);
extern void BTL_EVENT_MultiplyVar(int key, s32 ratio);
extern void BTL_EVENT_SetFactorSkipCheck(struct BtlEventFactor *factor, BtlEventSkipCheck skipCheck);
extern void BTL_EVENT_ClearFactorSkipCheck(struct BtlEventFactor *factor);

/* Services of the battle server flow. */
extern u8 func_021C7D54(struct BtlSvFlow *flow, int pokeId, u8 *outIds);
extern struct BtlPokeParam *func_021C7CF4(struct BtlSvFlow *flow, int pokeId);
extern int func_021C7D00(struct BtlSvFlow *flow, int pokeId);
extern u8 func_021C7F68(struct BtlSvFlow *flow, u16 sideSpec, u8 *outIds);
extern void func_021C88B4(struct BtlSvFlow *flow, int state, int pokeId);
extern void *func_021C88A4(struct BtlSvFlow *flow, int kind, int pokeId);
extern void func_021C8838(BtlStrParam *str, int strType, int strId);
extern void func_021C8860(BtlStrParam *str, u32 arg);
extern void func_021C88C8(struct BtlSvFlow *flow, void *cmd);

/* Services of the calculation and of the poke parameter. */
extern u32 BTL_CALC_Random(u32 range);
extern int BTL_CALC_Max(int value, int floor);
extern int BTL_CALC_DivideMaxHpMin1(struct BtlPokeParam *bpp, u32 divisor);
extern u16 BTL_POKEPARAM_GetItem(struct BtlPokeParam *bpp);
extern int BTL_POKEPARAM_IsHpFull(struct BtlPokeParam *bpp);
extern int func_021D5D14(struct BtlPokeParam *bpp, int statId, int amount);
extern int BTL_POKEPARAM_TestTurnFlag(struct BtlPokeParam *bpp, u32 flagIndex);
extern int BTL_POKEPARAM_TestContFlag(struct BtlPokeParam *bpp, u32 flagIndex);
extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *bpp, int sickId);
extern u32 WAZA_TOOL_GetFlag(u16 move, u32 flag);
extern u32 WAZA_TOOL_IsDamaging(u16 move);

#endif
