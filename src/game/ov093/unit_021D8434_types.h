#ifndef UNIT_021D8434_TYPES_H
#define UNIT_021D8434_TYPES_H
/*
 * ov093 ability handlers: the action word setters, the ability handler
 * registry, and the handler functions of the abilities that gate on the
 * event variable stack.
 */
#include "btl_event_types.h"

struct BtlSvFlow;
struct BtlPokeParam;

/* The low four bits of an action word hold its kind. */
typedef struct {
    u32 kind : 4;
} BtlActionWord;

/* Action kinds that these files write. */
#define BTL_ACTION_NONE 0
#define BTL_ACTION_FORCED_SKIP 7
#define BTL_ACTION_RECORD_RESET 8
#define BTL_ACTION_RECORD_ERROR 9
#define BTL_ACTION_CHANGE 3

/* One row of the ability registry: ability id and the function that returns its handler table. */
typedef struct {
    u32 abilityId;
    u32 (*getHandlers)(u32 *packedInfo);
} AbilityHandlerEntry;

#define ABILITY_REGISTRY_COUNT 0x9E
#define BTL_EVENT_TYPE_ABILITY 4
#define ABILITY_DEFAULT_PRIORITY 5

/* Event variable keys that the ability handlers read or write. */
enum {
    BTL_EVAR_POKE_ID = 2,
    BTL_EVAR_ATTACKER_ID = 3,
    BTL_EVAR_DEFENDER_ID = 4,
    BTL_EVAR_ACTION_ORDER = 0x11,
    BTL_EVAR_MOVE_ID = 0x12,
    BTL_EVAR_MOVE_TYPE = 0x16,
    BTL_EVAR_FAIL_REASON = 0x22,
    BTL_EVAR_DAMAGE = 0x32,
    BTL_EVAR_POWER = 0x33,
    BTL_EVAR_RATIO = 0x35,
    BTL_EVAR_TYPE_AFFINITY = 0x38,
    BTL_EVAR_WEATHER = 0x39,
    BTL_EVAR_PREVENT_FLAG = 0x41,
    BTL_EVAR_SPEED_PENALTY_FLAG = 0x51,
    BTL_EVAR_SAME_TYPE_FLAG = 0x44,
    BTL_EVAR_CRITICAL_FLAG = 0x45
};

#define BTL_FAIL_REASON_FLINCH 6
#define BTL_SICK_CONFUSION 6

/* Weather ids that func_021C8288 returns. */
enum {
    BTL_WEATHER_SUN = 1,
    BTL_WEATHER_RAIN = 2,
    BTL_WEATHER_HAIL = 3,
    BTL_WEATHER_SAND = 4
};

/* Type affinity classes that func_021D7AD4 returns. */
enum {
    BTL_AFFINITY_SUPER_EFFECTIVE = 2,
    BTL_AFFINITY_RESISTED = 3
};

/* Type ids. */
enum {
    POKETYPE_BUG = 6,
    POKETYPE_FIRE = 9,
    POKETYPE_WATER = 10,
    POKETYPE_GRASS = 11,
    POKETYPE_ICE = 14
};

#define WAZA_DAMAGE_PHYSICAL 1

/* Ratios in 20.12 fixed point (0x1000 is 1.0). */
enum {
    BTL_RATIO_0_5 = 0x800,
    BTL_RATIO_0_75 = 0xC00,
    BTL_RATIO_0_8 = 0xCCD,
    BTL_RATIO_1_3 = 0x14CD,
    BTL_RATIO_1_5 = 0x1800,
    BTL_RATIO_2_0 = 0x2000
};

/* Header flag that the ability message and rank commands set. */
#define BTL_CMD_FLAG_FROM_ABILITY (1u << 23)

/* A stat rank change command: stat id, amount, and the poke ids it applies to. */
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

/* A message command: the header, then the string parameter. */
typedef struct {
    u32 header;
    u32 strParam[1];
} BtlMessageCmd;

/* Services of the event variable stack and the battle server flow. */
extern int func_021D775C(int key);
extern int func_021D76BC(int key, u32 value);
extern void func_021D7704(int key, s32 ratio);
extern u32 func_021D7B10(u32 value, u32 ratio);
extern u32 func_021D7B60(struct BtlPokeParam *bpp, u32 divisor);
extern int func_021D7AD4(int affinity);
extern int func_021D7AF0(u32 percent);
extern struct BtlPokeParam *func_021C7CF4(struct BtlSvFlow *flow, int pokeId);
extern int func_021C8288(struct BtlSvFlow *flow);
extern void *func_021C88A4(struct BtlSvFlow *flow, int size, int pokeId);
extern void func_021C88C8(struct BtlSvFlow *flow, void *cmd);
extern void func_021C8838(void *strParam, int strType, int strId);
extern void func_021C8860(void *strParam, u32 arg);
extern int WAZA_TOOL_GetDamageType(int moveId);

/* Services of the poke parameter. */
extern int func_021D59B4(struct BtlPokeParam *bpp, int valueId);
extern u8 func_021D5440(struct BtlPokeParam *bpp);
extern int func_021D58A8(struct BtlPokeParam *bpp, int valueId);
extern int func_021D5BDC(struct BtlPokeParam *bpp, u32 flagIndex);
extern int func_021D62A8(struct BtlPokeParam *bpp);
extern int func_021D62C4(struct BtlPokeParam *bpp, int sickId);

#endif
