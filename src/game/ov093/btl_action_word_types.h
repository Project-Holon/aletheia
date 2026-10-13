#ifndef BTL_ACTION_WORD_TYPES_H
#define BTL_ACTION_WORD_TYPES_H
#include "hand_common_types.h"
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

#define BTL_FAIL_REASON_FLINCH 6
#define BTL_SICK_CONFUSION 6

/* Weather ids that BTL_SERVER_FLOW_GetEffectiveWeatherThunk returns. */
enum {
    BTL_WEATHER_SUN = 1,
    BTL_WEATHER_RAIN = 2,
    BTL_WEATHER_HAIL = 3,
    BTL_WEATHER_SAND = 4
};

/* Type affinity classes that BTL_CALC_SummarizeTypeAffinity returns. */
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
extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 value);
extern void BTL_EVENT_MultiplyVar(int key, s32 ratio);
extern u32 BTL_CALC_MulRatio(u32 value, u32 ratio);
extern u32 BTL_CALC_DivideMaxHp(struct BtlPokeParam *bpp, u32 divisor);
extern int BTL_CALC_SummarizeTypeAffinity(int affinity);
extern int BTL_CALC_RollPercent(u32 percent);
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlSvFlow *flow, int pokeId);
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(struct BtlSvFlow *flow);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(struct BtlSvFlow *flow, int size, int pokeId);
extern void BTL_SERVER_FLOW_CommitCmdRecord(struct BtlSvFlow *flow, void *cmd);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *strParam, int strType, int strId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(void *strParam, u32 arg);
extern int WAZA_TOOL_GetDamageType(int moveId);

/* Services of the poke parameter. */
extern int func_021D59B4(struct BtlPokeParam *bpp, int valueId);
extern u8 BTL_POKEPARAM_GetPokeId(struct BtlPokeParam *bpp);
extern int func_021D58A8(struct BtlPokeParam *bpp, int valueId);
extern int BTL_POKEPARAM_TestContFlag(struct BtlPokeParam *bpp, u32 flagIndex);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct BtlPokeParam *bpp);
extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *bpp, int sickId);

/* Deprecated names of event variable keys, kept for files not yet cleaned. */
#define BTL_EVAR_PREVENT_FLAG BTL_EVAR_FORCE_GROUNDED_FLAG
#define BTL_EVAR_SPEED_PENALTY_FLAG BTL_EVAR_FORCE_FLOATING_FLAG

#endif
