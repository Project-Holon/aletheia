#ifndef BTL_ACTION_WORD_TYPES_H
#define BTL_ACTION_WORD_TYPES_H
#include "hand_common_types.h"
#include "hand_common_protos.h"
/*
 * ov093 ability handlers: the action word setters, the ability handler
 * registry, and the handler functions of the abilities that gate on the
 * event variable stack.
 */
#include "btl_event_types.h"

struct BtlServerFlow;
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

/* Weather ids that BTL_SERVER_FLOW_GetEffectiveWeatherThunk returns. */

/* Type affinity classes that BTL_CALC_SummarizeTypeAffinity returns. */
enum {
    BTL_AFFINITY_SUPER_EFFECTIVE = 2,
    BTL_AFFINITY_RESISTED = 3
};

/* Type ids. */

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



/* Services of the event variable stack and the battle server flow. */
extern u32 BTL_CALC_MulRatio(u32 value, u32 ratio);
extern u32 BTL_CALC_DivideMaxHp(struct BtlPokeParam *bpp, u32 divisor);
extern int BTL_CALC_SummarizeTypeAffinity(int affinity);
extern int BTL_CALC_RollPercent(u32 percent);
extern int WAZA_TOOL_GetDamageType(int moveId);

/* Services of the poke parameter. */
extern int func_021D58A8(struct BtlPokeParam *bpp, int valueId);

/* Deprecated names of event variable keys, kept for files not yet cleaned. */

#endif
