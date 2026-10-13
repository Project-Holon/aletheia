/*
 * file:     btl_action_word.c
 * unit:     yes
 * function: BTL_CALC_ActionSetNone, BTL_CALC_ActionSetForcedSkip, BTL_CALC_ActionGetKind, BTL_CALC_ActionSetRecordReset, BTL_CALC_ActionSetRecordError, HAND_TOKUSEI_AddAbilityHandlers, HAND_TOKUSEI_PackAbilityHandlerInfo, HAND_TOKUSEI_UnpackAbilityPriority, HAND_TOKUSEI_RemoveAbilityHandlers, HAND_TOKUSEI_DisableAbilityHandlers, HAND_TOKUSEI_EnableAbilityHandlers, HAND_TOKUSEI_SwapAbilityHandlers, HAND_TOKUSEI_GetPokeSpeed, HAND_TOKUSEI_RollChanceOrFlag, HAND_TOKUSEI_IntimidateOnEnter, HAND_TOKUSEI_GetInnerFocusHandlers
 * address:  0x021D8434
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gInnerFocusHandlers     0x021F0710  data   ov093  a4
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_AddFactor  0x021D6F0C  thumb  ov093
 *   gAbilityHandlerRegistry     0x021F0E74  data  ov093
 *   BTL_EVENT_FindFactor 0x021D732C thumb ov093
 *   BTL_EVENT_RemoveFactor 0x021D7040 thumb ov093
 *   BTL_EVENT_DisablePokeFactors 0x021D7404 thumb ov093
 *   BTL_EVENT_EnablePokeFactors 0x021D7438 thumb ov093
 *   func_021D58A8 0x021D58A8 thumb ov093
 *   gIntimidateHandlers 0x021F08C0 data ov093 a4
 *   BTL_CALC_RollPercent 0x021D7AF0 thumb ov093
 *   BTL_SERVER_FLOW_QueryMainFlag 0x021C82B8 thumb ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetFrontPosOfPoke  0x021C7D00  thumb  ov093
 *   BTL_SERVER_FLOW_GetScratchBuffer  0x021C8120  thumb  ov093
 *   BTL_SERVER_FLOW_CollectAlivePokeIds  0x021C7F68  thumb  ov093
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "btl_action_word_types.h"

typedef enum { MASK=15 } Mask;

extern struct BtlEventFactor *BTL_EVENT_FindFactor(int factorType, int pokeId);
extern void BTL_EVENT_DisablePokeFactors(u32 pokeId, int factorType);
extern int BTL_EVENT_EnablePokeFactors(int pokeId, int factorType);
int BTL_SERVER_FLOW_QueryMainFlag(struct BtlServerFlow *flow, int flagId);
u8 *BTL_SERVER_FLOW_GetScratchBuffer(struct BtlServerFlow *flow, int bufferId);
u8 BTL_SERVER_FLOW_CollectAlivePokeIds(struct BtlServerFlow *flow, int posKey, u8 *out);
void BTL_SERVER_FLOW_PushCmdRecord(struct BtlServerFlow *flow, int kind, int pokeId);

void BTL_CALC_ActionSetNone(u32 *action);
void BTL_CALC_ActionSetForcedSkip(u32 *action);
unsigned int BTL_CALC_ActionGetKind(BtlActionWord *action);
void BTL_CALC_ActionSetRecordReset(u32 *action);
void BTL_CALC_ActionSetRecordError(u32 *action);
struct BtlEventFactor *HAND_TOKUSEI_AddAbilityHandlers(struct BtlPokeParam *bpp);
unsigned int HAND_TOKUSEI_PackAbilityHandlerInfo(unsigned int priority, unsigned int handlerCount);
int HAND_TOKUSEI_UnpackAbilityPriority(u32 *packedInfo);
void HAND_TOKUSEI_RemoveAbilityHandlers(struct BtlPokeParam *bpp);
void HAND_TOKUSEI_DisableAbilityHandlers(struct BtlPokeParam *bpp);
void HAND_TOKUSEI_EnableAbilityHandlers(struct BtlPokeParam *bpp);
void HAND_TOKUSEI_SwapAbilityHandlers(struct BtlPokeParam *bppA, struct BtlPokeParam *bppB);
u16 HAND_TOKUSEI_GetPokeSpeed(struct BtlPokeParam *bpp);
int HAND_TOKUSEI_RollChanceOrFlag(struct BtlServerFlow *flow, u32 percent);
u8 *HAND_TOKUSEI_GetIntimidateHandlers(u32 *packedInfo);
void HAND_TOKUSEI_IntimidateOnEnter(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_TOKUSEI_GetInnerFocusHandlers(int *packedInfo);
extern AbilityHandlerEntry gAbilityHandlerRegistry[ABILITY_REGISTRY_COUNT];
extern u8 gIntimidateHandlers[];
extern int gInnerFocusHandlers[];

/*
 * The setters below write only the kind nibble of an action word.
 * stand-in: ActionSetNone clears the nibble and then masks with an enum
 * constant (a clear and a mask that contradict each other); the mask-first
 * order in the last AND selects the original register.
 */
void BTL_CALC_ActionSetNone(u32 *action) { Mask mask=MASK; *action=mask & (*action & ~15); }

void BTL_CALC_ActionSetForcedSkip(u32 *action) { *action = (*action & ~15) | BTL_ACTION_FORCED_SKIP; }


unsigned int BTL_CALC_ActionGetKind(BtlActionWord *action)
{
    return action->kind;
}

void BTL_CALC_ActionSetRecordReset(u32 *action) { *action = ((*action & ~15) | BTL_ACTION_RECORD_RESET) & 15; }

void BTL_CALC_ActionSetRecordError(u32 *action) { *action = ((*action & ~15) | BTL_ACTION_RECORD_ERROR) & 15; }


/* Adds the handler table of the ability that the poke holds to the event factor list. */
struct BtlEventFactor *HAND_TOKUSEI_AddAbilityHandlers(struct BtlPokeParam *bpp)
{
    u16 abilityId = func_021D59B4(bpp, 0x10);
    u32 i;
    u32 speed;
    u8 pokeId;
    int priority;
    u32 handlerCount;
    u32 handlers;

    for (i = 0; i < ABILITY_REGISTRY_COUNT; i++) {
        if (abilityId == gAbilityHandlerRegistry[i].abilityId) {
            speed = HAND_TOKUSEI_GetPokeSpeed(bpp);
            pokeId = BTL_POKEPARAM_GetPokeId(bpp);
            handlers = gAbilityHandlerRegistry[i].getHandlers(&handlerCount);
            priority = HAND_TOKUSEI_UnpackAbilityPriority(&handlerCount);
            return BTL_EVENT_AddFactor(BTL_EVENT_TYPE_ABILITY, abilityId, priority, speed, pokeId, (BtlEventHandler *)handlers, handlerCount);
        }
    }
    return 0;
}

/* Packs the factor priority into the high half and the handler count into the low half. */
unsigned int HAND_TOKUSEI_PackAbilityHandlerInfo(unsigned int priority, unsigned int handlerCount)
{
    return (priority << 16) | handlerCount;
}

/* Splits the packed info: leaves the handler count in place and returns the priority (5 when none is packed). */
int HAND_TOKUSEI_UnpackAbilityPriority(u32 *packedInfo) { u16 priority = *packedInfo >> 16; if (priority == 0) priority = ABILITY_DEFAULT_PRIORITY; *packedInfo &= 65535; return priority; }

void HAND_TOKUSEI_RemoveAbilityHandlers(struct BtlPokeParam *bpp) { int pokeId = BTL_POKEPARAM_GetPokeId(bpp); struct BtlEventFactor *factor; while ((factor=BTL_EVENT_FindFactor(BTL_EVENT_TYPE_ABILITY,pokeId)) != 0) { BTL_EVENT_RemoveFactor(factor); } }

void HAND_TOKUSEI_DisableAbilityHandlers(struct BtlPokeParam *bpp) { BTL_EVENT_DisablePokeFactors(BTL_POKEPARAM_GetPokeId(bpp),BTL_EVENT_TYPE_ABILITY); }

void HAND_TOKUSEI_EnableAbilityHandlers(struct BtlPokeParam *bpp) { if (!BTL_EVENT_EnablePokeFactors(BTL_POKEPARAM_GetPokeId(bpp),BTL_EVENT_TYPE_ABILITY)) HAND_TOKUSEI_AddAbilityHandlers(bpp); }


/* Swaps the abilities of two pokes: removes both handler sets, then adds both again. */
void HAND_TOKUSEI_SwapAbilityHandlers(struct BtlPokeParam *bppA, struct BtlPokeParam *bppB)
{
    int pokeIdA = BTL_POKEPARAM_GetPokeId(bppA);
    int pokeIdB = BTL_POKEPARAM_GetPokeId(bppB);
    struct BtlEventFactor *factorA = BTL_EVENT_FindFactor(BTL_EVENT_TYPE_ABILITY, pokeIdA);
    struct BtlEventFactor *factorB = BTL_EVENT_FindFactor(BTL_EVENT_TYPE_ABILITY, pokeIdB);

    if (factorA != 0)
        BTL_EVENT_RemoveFactor(factorA);
    if (factorB != 0)
        BTL_EVENT_RemoveFactor(factorB);
    HAND_TOKUSEI_AddAbilityHandlers(bppA);
    HAND_TOKUSEI_AddAbilityHandlers(bppB);
}

u16 HAND_TOKUSEI_GetPokeSpeed(struct BtlPokeParam *bpp) { return func_021D58A8(bpp,12); }

/* True after a percent roll succeeds, or when the flow flag 1 is set. */
int HAND_TOKUSEI_RollChanceOrFlag(struct BtlServerFlow *flow, u32 percent) { int result; if (BTL_CALC_RollPercent(percent)) return 1; result=BTL_SERVER_FLOW_QueryMainFlag(flow,1)!=0; return result; }

u8 *HAND_TOKUSEI_GetIntimidateHandlers(u32 *packedInfo) { *packedInfo=2; return gIntimidateHandlers; }


/* Intimidate: lowers the attack of every opposing poke when the owner enters. */
void HAND_TOKUSEI_IntimidateOnEnter(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    int pos;
    u8 *targets;
    int targetCount;
    u32 i;
    BtlRankCmd *cmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    pos = BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, pokeId);
    targets = BTL_SERVER_FLOW_GetScratchBuffer(flow, 6);
    targetCount = BTL_SERVER_FLOW_CollectAlivePokeIds(flow, (u16)(pos | 0x100), targets);
    if (targetCount == 0)
        return;
    BTL_SERVER_FLOW_PushCmdRecord(flow, 2, pokeId);
    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, 0xe, pokeId);
    cmd->statId = 1;
    cmd->amount = -1;
    cmd->showMessage = 1;
    cmd->targetCount = targetCount;
    for (i = 0; i < (u32)targetCount; i++)
        cmd->targets[i] = targets[i];
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    BTL_SERVER_FLOW_PushCmdRecord(flow, 3, pokeId);
}

/* Inner Focus: handler table. */
int *HAND_TOKUSEI_GetInnerFocusHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gInnerFocusHandlers;
}
