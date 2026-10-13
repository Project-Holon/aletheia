/*
 * file:     hand_tokusei_021dcae8.c
 * unit:     yes
 * function: HAND_TOKUSEI_MagicBounceReflectMoveWithWindow, HAND_TOKUSEI_AddMagicBounce, HAND_TOKUSEI_HarvestRestoreBerry, HAND_TOKUSEI_AddHarvest, HAND_TOKUSEI_AddHeavyMetal, HAND_TOKUSEI_HeavyMetalDoubleWeight, HAND_TOKUSEI_AddLightMetal, HAND_TOKUSEI_LightMetalHalveWeight, HAND_TOKUSEI_ContraryInvertStatChange, HAND_TOKUSEI_UnnerveOnOwnerEnter, HAND_TOKUSEI_UnnerveAnnounce, HAND_TOKUSEI_UnnerveSkipBerry, HAND_TOKUSEI_ImposterTransform, HAND_TOKUSEI_AddImposter, HAND_TOKUSEI_AddIllusion, HAND_TOKUSEI_IllusionBreakOnHit, HAND_TOKUSEI_IllusionBreakOnOwnerEvent, HAND_TOKUSEI_IllusionBreakOnAbilityChange, HAND_TOKUSEI_IllusionBreak, HAND_TOKUSEI_AddVictoryStar, HAND_TOKUSEI_VictoryStarBoostAccuracy, HAND_ITEM_AddFactor, HAND_ITEM_RemoveUnforcedFactors, HAND_ITEM_AddHeldItemFactor, HAND_ITEM_AddForcedFactor, HAND_ITEM_RemoveFactor, HAND_ITEM_DisablePokeFactors, HAND_ITEM_EnablePokeFactors, HAND_ITEM_RollChance, HAND_ITEM_GetParam, HAND_ITEM_GetBoostRatio, HAND_ITEM_PushUseItem, HAND_ITEM_CheriBerryOnTrigger, HAND_ITEM_CheriBerryOnEaten, HAND_ITEM_ChestoBerryOnTrigger, HAND_ITEM_ChestoBerryOnEaten, HAND_ITEM_RawstBerryOnTrigger, HAND_ITEM_RawstBerryOnEaten, HAND_ITEM_AspearBerryOnTrigger, HAND_ITEM_AspearBerryOnEaten, HAND_ITEM_PersimBerryOnTrigger, HAND_ITEM_PersimBerryOnEaten, HAND_ITEM_PechaBerryOnTrigger, HAND_ITEM_PechaBerryOnEaten, HAND_ITEM_LumBerryOnTrigger, HAND_ITEM_LumBerryOnEaten, HAND_ITEM_CureSickOnTrigger, HAND_ITEM_CureSickOnEaten, HAND_ITEM_CheckHasSick, HAND_ITEM_AddLeppaBerry, HAND_ITEM_LeppaBerryOnLastMoveEmpty, HAND_ITEM_LeppaBerryOnAnyMoveEmptyChecked, HAND_ITEM_LeppaBerryOnAnyMoveEmpty, HAND_ITEM_LeppaBerryClaimTrigger, HAND_ITEM_LeppaBerryOnEaten, HAND_ITEM_LeppaBerryOnForcedUse, HAND_ITEM_FindLastMoveEmptySlot, HAND_ITEM_FindEmptyMoveSlot, HAND_ITEM_PushRecoverPp, HAND_ITEM_RecoverHpOnTrigger, HAND_ITEM_RecoverHpOnCheck, HAND_ITEM_RecoverHpOnLowHp, HAND_ITEM_RecoverFixedHpOnEaten, HAND_ITEM_AddBerryJuice, HAND_ITEM_AddSitrusBerry
 * address:  0x021DCAE8
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
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 *   BTLV_CORE_EventQueueMoveNotice  0x021E8804  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetConsumedItem  0x021D6740  thumb  ov093
 *   ITEM_IsBerry  0x020213C0  thumb
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk  0x021C8288  thumb  ov093
 *   HAND_TOKUSEI_RollChanceOrFlag  0x021D85C0  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gMagicBounceHandlers     0x021F0AD0  data   ov093  a4
 *   gLightMetalHandlers 0x021F05E0 data a4
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   gContraryHandlers 0x021F0708 data a4
 *   BTL_MAIN_IsPokeIdInSecondPair  0x021B9A40  thumb  ov093
 *   BTL_MAIN_IsZero  0x021B9A5C  thumb  ov093
 *   BTL_EVENT_SetFactorSkipCheck  0x021D7320  thumb  ov093
 *   BTL_EVENT_GetFactorPokeId 0x021D70AC thumb ov093
 *   BTL_MAIN_IsPokeSamePair 0x021B9A24 thumb ov093
 *   gUnnerveHandlers 0x021F0AE8 data a4
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb  ov093
 *   BTL_SERVER_FLOW_GetRule  0x021C815C  thumb  ov093
 *   BTL_MAIN_GetFacingPos  0x021B8C5C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeIdAtFieldIndex  0x021C8020  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   gHarvestHandlers     0x021F0728  data   ov093  a4
 *   gHeavyMetalHandlers     0x021F0680  data   ov093  a4
 *   BTL_EVENT_GetFactorKey 0x021D70A8 thumb ov093
 *   BTL_POKEPARAM_IsIllusionActive  0x021D6C24  thumb  ov093
 *   gImposterHandlers     0x021F0750  data   ov093  a4
 *   gIllusionHandlers     0x021F0B60  data   ov093  a4
 *   func_021D58A8  0x021D58A8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_AddFactor  0x021D6F0C  thumb  ov093
 *   gItemHandlerRegistry     0x021F1EA4  data  ov093
 *   BTL_EVENT_FindFactor  0x021D732C  thumb  ov093
 *   BTL_EVENT_FindNextFactor  0x021D7360  thumb  ov093
 *   BTL_EVENT_GetFactorWork  0x021D70B4  thumb  ov093
 *   BTL_EVENT_RemoveFactor  0x021D7040  thumb  ov093
 *   BTL_EVENT_EnableFactorSpecialEvent 0x021D70BC thumb ov093
 *   BTL_EVENT_SetFactorWork 0x021D70DC thumb ov093
 *   BTL_EVENT_DisablePokeFactors 0x021D7404 thumb ov093
 *   BTL_EVENT_EnablePokeFactors 0x021D7438 thumb ov093
 *   BTL_CALC_RollPercent 0x021D7AF0 thumb ov093
 *   BTL_SERVER_FLOW_QueryMainFlag 0x021C82B8 thumb ov093
 *   BTL_CALC_GetMonParamWithHeap   0x021D805C  thumb
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   BTL_EVENT_KeepFactorRunning 0x021D70C8 thumb ov093
 *   gCheriBerryHandlers 0x021F1AC4 data a4
 *   gChestoBerryHandlers 0x021F1AEC data a4
 *   gRawstBerryHandlers 0x021F1DE4 data a4
 *   gAspearBerryHandlers 0x021F1B14 data a4
 *   gPersimBerryHandlers 0x021F1B3C data a4
 *   gPechaBerryHandlers 0x021F1B64 data a4
 *   gLumBerryHandlers 0x021F1B8C data a4
 *   BTL_EVENT_TryGetVar  0x021D778C  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_CALC_FindMajorSick  0x021D7E10  thumb  ov093
 *   gVictoryStarHandlers     0x021F0760  data   ov093  a4
 *   BTL_POKEPARAM_GetLastSelectedMoveId 0x021D67B8 thumb ov093
 *   BTL_POKEPARAM_FindMoveSlot 0x021D5778 thumb ov093
 *   BTL_POKEPARAM_GetMovePPChecked 0x021D5584 thumb ov093
 *   BTL_POKEPARAM_GetMoveCount 0x021D5448 thumb ov093
 *   BTL_POKEPARAM_GetMovePPLost 0x021D554C thumb ov093
 *   BTL_POKEPARAM_GetMoveId 0x021D54C0 thumb ov093
 *   gOranBerryHandlers 0x021F1BB4 data a4
 *   HAND_ITEM_HpBerryCheckAndUse 0x021DDE30 thumb ov093
 *   HAND_ITEM_IsHpAtOrBelowFraction 0x021DDEA4 thumb ov093
 *   gLeppaBerryHandlers     0x021F1E6C  data   ov093  a4
 *   gBerryJuiceHandlers     0x021F1AA4  data   ov093  a4
 *   gSitrusBerryHandlers     0x021F1BDC  data   ov093  a4
 */
#include "hand_tokusei_021dcae8_types.h"

/* Handler tables defined in the overlay data, one per ability or item. */
extern const BtlEventHandlerEntry gMagicBounceHandlers[];
extern const BtlEventHandlerEntry gLightMetalHandlers[];
extern const BtlEventHandlerEntry gContraryHandlers[];
extern const BtlEventHandlerEntry gUnnerveHandlers[];
extern const BtlEventHandlerEntry gHarvestHandlers[];
extern const BtlEventHandlerEntry gHeavyMetalHandlers[];
extern const BtlEventHandlerEntry gImposterHandlers[];
extern const BtlEventHandlerEntry gIllusionHandlers[];
extern const BtlEventHandlerEntry gVictoryStarHandlers[];
extern const BtlEventHandlerEntry gCheriBerryHandlers[];
extern const BtlEventHandlerEntry gChestoBerryHandlers[];
extern const BtlEventHandlerEntry gRawstBerryHandlers[];
extern const BtlEventHandlerEntry gAspearBerryHandlers[];
extern const BtlEventHandlerEntry gPersimBerryHandlers[];
extern const BtlEventHandlerEntry gPechaBerryHandlers[];
extern const BtlEventHandlerEntry gLumBerryHandlers[];
extern const BtlEventHandlerEntry gLeppaBerryHandlers[];
extern const BtlEventHandlerEntry gOranBerryHandlers[];
extern const BtlEventHandlerEntry gBerryJuiceHandlers[];
extern const BtlEventHandlerEntry gSitrusBerryHandlers[];
extern ItemHandlerEntry gItemHandlerRegistry[ITEM_HANDLER_COUNT];

/* Abilities */
void HAND_TOKUSEI_MagicBounceReflectMoveWithWindow(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int work);
const BtlEventHandlerEntry *HAND_TOKUSEI_AddMagicBounce(int *count);
void HAND_TOKUSEI_HarvestRestoreBerry(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandlerEntry *HAND_TOKUSEI_AddHarvest(int *count);
const BtlEventHandlerEntry *HAND_TOKUSEI_AddHeavyMetal(int *count);
void HAND_TOKUSEI_HeavyMetalDoubleWeight(int factor, int flow, int pokeId);
const BtlEventHandlerEntry *HAND_TOKUSEI_AddLightMetal(int *count);
void HAND_TOKUSEI_LightMetalHalveWeight(int factor, int flow, int pokeId);
void HAND_TOKUSEI_ContraryInvertStatChange(int factor, int flow, int pokeId, int *work);
const BtlEventHandlerEntry *HAND_TOKUSEI_AddContrary(int *count);
void HAND_TOKUSEI_UnnerveOnOwnerEnter(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, UnnerveWork *work);
void HAND_TOKUSEI_UnnerveAnnounce(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, UnnerveWork *work);
int HAND_TOKUSEI_UnnerveSkipBerry(struct BtlEventFactor *factor, void *context, int targetFactorType, int eventId, u16 targetKey, u8 targetOwnerId);
const BtlEventHandlerEntry *HAND_TOKUSEI_AddUnnerve(int *count);
void HAND_TOKUSEI_ImposterTransform(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandlerEntry *HAND_TOKUSEI_AddImposter(int *count);
const BtlEventHandlerEntry *HAND_TOKUSEI_AddIllusion(int *count);
void HAND_TOKUSEI_IllusionBreakOnHit(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_TOKUSEI_IllusionBreakOnOwnerEvent(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_TOKUSEI_IllusionBreakOnAbilityChange(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_TOKUSEI_IllusionBreak(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandlerEntry *HAND_TOKUSEI_AddVictoryStar(int *count);
void HAND_TOKUSEI_VictoryStarBoostAccuracy(int factor, int flow, unsigned int pokeId);

/* Held items */
struct BtlEventFactor *HAND_ITEM_AddFactor(struct BtlPokeParam *poke, u32 itemId);
void HAND_ITEM_RemoveUnforcedFactors(struct BtlPokeParam *poke);
struct BtlEventFactor *HAND_ITEM_AddHeldItemFactor(struct BtlPokeParam *poke);
struct BtlEventFactor *HAND_ITEM_AddForcedFactor(struct BtlPokeParam *poke, unsigned int itemId);
void HAND_ITEM_RemoveFactor(struct BtlEventFactor *factor);
void HAND_ITEM_DisablePokeFactors(struct BtlPokeParam *poke);
void HAND_ITEM_EnablePokeFactors(struct BtlPokeParam *poke);
int HAND_ITEM_RollChance(struct BtlSvFlow *flow, unsigned int percent);
int HAND_ITEM_GetParam(struct BtlEventFactor *factor, int paramIndex);
int HAND_ITEM_GetBoostRatio(struct BtlEventFactor *factor);
void HAND_ITEM_PushUseItem(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_ITEM_CheriBerryOnTrigger(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_ITEM_CheriBerryOnEaten(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandlerEntry *HAND_ITEM_AddCheriBerry(int *count);
void HAND_ITEM_ChestoBerryOnTrigger(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_ITEM_ChestoBerryOnEaten(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandlerEntry *HAND_ITEM_AddChestoBerry(int *count);
void HAND_ITEM_RawstBerryOnTrigger(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_ITEM_RawstBerryOnEaten(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandlerEntry *HAND_ITEM_AddRawstBerry(int *count);
void HAND_ITEM_AspearBerryOnTrigger(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_ITEM_AspearBerryOnEaten(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandlerEntry *HAND_ITEM_AddAspearBerry(int *count);
void HAND_ITEM_PersimBerryOnTrigger(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_ITEM_PersimBerryOnEaten(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandlerEntry *HAND_ITEM_AddPersimBerry(int *count);
void HAND_ITEM_PechaBerryOnTrigger(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_ITEM_PechaBerryOnEaten(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandlerEntry *HAND_ITEM_AddPechaBerry(int *count);
void HAND_ITEM_LumBerryOnTrigger(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_ITEM_LumBerryOnEaten(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandlerEntry *HAND_ITEM_AddLumBerry(int *count);
void HAND_ITEM_CureSickOnTrigger(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int sickKind);
void HAND_ITEM_CureSickOnEaten(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int sickKind);
int HAND_ITEM_CheckHasSick(struct BtlSvFlow *flow, int pokeId, int sickKind);
const BtlEventHandlerEntry *HAND_ITEM_AddLeppaBerry(int *count);
void HAND_ITEM_LeppaBerryOnLastMoveEmpty(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_ITEM_LeppaBerryOnAnyMoveEmptyChecked(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_ITEM_LeppaBerryOnAnyMoveEmpty(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_ITEM_LeppaBerryClaimTrigger(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_ITEM_LeppaBerryOnEaten(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 pokeId, int *work);
void HAND_ITEM_LeppaBerryOnForcedUse(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 pokeId, int *work);
u8 HAND_ITEM_FindLastMoveEmptySlot(struct BtlSvFlow *flow, int pokeId);
u8 HAND_ITEM_FindEmptyMoveSlot(struct BtlSvFlow *flow, int pokeId);
int HAND_ITEM_PushRecoverPp(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 pokeId, int *work, int allowAnyLostSlot);
const BtlEventHandlerEntry *HAND_ITEM_AddOranBerry(int *count);
void HAND_ITEM_RecoverHpOnTrigger(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_ITEM_RecoverHpOnCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_ITEM_RecoverHpOnLowHp(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_ITEM_RecoverFixedHpOnEaten(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandlerEntry *HAND_ITEM_AddBerryJuice(int *count);
const BtlEventHandlerEntry *HAND_ITEM_AddSitrusBerry(int *count);

/* Magic Bounce: reflect the incoming move and show the ability window. */
void HAND_TOKUSEI_MagicBounceReflectMoveWithWindow(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_FLOATING_FLAG, 1) != 0) {
        BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_KIND_ABILITY_WINDOW_IN, pokeId);
        BTLV_CORE_EventQueueMoveNotice(factor, flow, pokeId, work);
        BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_KIND_ABILITY_WINDOW_OUT, pokeId);
    }
}

const BtlEventHandlerEntry *HAND_TOKUSEI_AddMagicBounce(int *count)
{
    *count = 3;
    return gMagicBounceHandlers;
}

/* Harvest: give back the consumed Berry when the Pokemon holds nothing (always in sun, else 50%). */
void HAND_TOKUSEI_HarvestRestoreBerry(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExSetItem *rec;
    struct BtlPokeParam *poke;
    u32 itemId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        itemId = BTL_POKEPARAM_GetConsumedItem(poke);
        if (itemId != 0 && ITEM_IsBerry(itemId) != 0 && BTL_POKEPARAM_GetItem(poke) == 0
            && (BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == BTL_WEATHER_SUN || HAND_TOKUSEI_RollChanceOrFlag(flow, 50) != 0)) {
            rec = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_ITEM, pokeId);
            rec->header |= HANDEX_FLAG_SHOW_ABILITY;
            rec->itemId = itemId;
            rec->pokeId = pokeId;
            rec->announce = 1;
            BTL_SERVER_FLOW_InitMsgRecord(&rec->str, HANDEX_STR_SET, 0x1db);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&rec->str, pokeId);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&rec->str, itemId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, rec);
        }
    }
}

const BtlEventHandlerEntry *HAND_TOKUSEI_AddHarvest(int *count)
{
    *count = 1;
    return gHarvestHandlers;
}

const BtlEventHandlerEntry *HAND_TOKUSEI_AddHeavyMetal(int *count)
{
    *count = 1;
    return gHeavyMetalHandlers;
}

/* Heavy Metal: double the weight. */
void HAND_TOKUSEI_HeavyMetalDoubleWeight(int factor, int flow, int pokeId) { if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_DOUBLE); }

const BtlEventHandlerEntry *HAND_TOKUSEI_AddLightMetal(int *count) { *count = 1; return gLightMetalHandlers; }

/*
 * Light Metal: halve the weight.
 * extent: trailing two-byte zero alignment at 021DCC2A.
 */
void HAND_TOKUSEI_LightMetalHalveWeight(int factor, int flow, int pokeId) { if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_HALF); }

/* Contrary: invert the stat change. */
void HAND_TOKUSEI_ContraryInvertStatChange(int factor, int flow, int pokeId, int *work) { if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) *work = BTL_EVENT_OverwriteVar(BTL_EVAR_VOLUME,-BTL_EVENT_GetVar(BTL_EVAR_VOLUME)); }

const BtlEventHandlerEntry *HAND_TOKUSEI_AddContrary(int *count) { *count = 1; return gContraryHandlers; }

/* Unnerve, when its owner enters. */
void HAND_TOKUSEI_UnnerveOnOwnerEnter(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, UnnerveWork *work) { if(pokeId==BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) HAND_TOKUSEI_UnnerveAnnounce(factor,flow,pokeId,work); }

/* Unnerve: show the ability window once and install the Berry skip check. */
void HAND_TOKUSEI_UnnerveAnnounce(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, UnnerveWork *work)
{
    HandExMessage *rec;
    u32 side;

    if (work->announced == 0) {
        side = BTL_MAIN_IsZero(BTL_MAIN_IsPokeIdInSecondPair(pokeId));
        BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_KIND_ABILITY_WINDOW_IN, pokeId);
        rec = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&rec->str, HANDEX_STR_STANDARD, 0xb0);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&rec->str, side);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rec);
        BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_KIND_ABILITY_WINDOW_OUT, pokeId);
        BTL_EVENT_SetFactorSkipCheck(factor, HAND_TOKUSEI_UnnerveSkipBerry);
        work->announced = 1;
    }
}

/*
 * Unnerve skip check: a Berry held by a Pokemon of the other side is skipped.
 * extent: callback followed by store-and-return leaf at 021DCD14.
 * stack: the last two arguments sit in stack slots; the body reads the
 * halfword at +0 and the byte at +4 using a common stack base.
 */
int HAND_TOKUSEI_UnnerveSkipBerry(struct BtlEventFactor *factor, void *context, int targetFactorType, int eventId, u16 targetKey, u8 targetOwnerId)
{
    if(targetFactorType==BTL_EVENT_TYPE_ITEM) {
        if(!BTL_MAIN_IsPokeSamePair(BTL_EVENT_GetFactorPokeId(factor),targetOwnerId)) {
            if(ITEM_IsBerry(targetKey)) return 1;
        }
    }
    return 0;
}

const BtlEventHandlerEntry *HAND_TOKUSEI_AddUnnerve(int *count) { *count=3; return gUnnerveHandlers; }

/* Imposter: transform into the Pokemon facing the owner, unless one of the two has fainted. */
void HAND_TOKUSEI_ImposterTransform(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExTransform *rec;
    struct BtlPokeParam *targetPoke;
    int targetId;
    int position;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        position = BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
        targetId = BTL_SERVER_FLOW_GetPokeIdAtFieldIndex(flow, BTL_MAIN_GetFacingPos(BTL_SERVER_FLOW_GetRule(flow), position));
        targetPoke = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        if (BTL_POKEPARAM_IsFainted(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) == 0 && BTL_POKEPARAM_IsFainted(targetPoke) == 0) {
            rec = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_TRANSFORM, pokeId);
            rec->header |= HANDEX_FLAG_SHOW_ABILITY;
            rec->targetPokeId = targetId;
            BTL_SERVER_FLOW_InitMsgRecord(&rec->str, HANDEX_STR_SET, 0x284);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&rec->str, pokeId);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&rec->str, rec->targetPokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, rec);
        }
    }
}

const BtlEventHandlerEntry *HAND_TOKUSEI_AddImposter(int *count)
{
    *count = 1;
    return gImposterHandlers;
}

const BtlEventHandlerEntry *HAND_TOKUSEI_AddIllusion(int *count)
{
    *count = 3;
    return gIllusionHandlers;
}

/* Illusion: the disguise ends when the owner is hit (not through a substitute). */
void HAND_TOKUSEI_IllusionBreakOnHit(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId) { if(pokeId==BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG)==0) HAND_TOKUSEI_IllusionBreak(factor,flow,pokeId); }

/* Illusion: the disguise ends on another event about the owner. */
void HAND_TOKUSEI_IllusionBreakOnOwnerEvent(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId) { if(pokeId==BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) HAND_TOKUSEI_IllusionBreak(factor,flow,pokeId); }

/* Illusion: the disguise ends when the owner's ability changes to another ability. */
void HAND_TOKUSEI_IllusionBreakOnAbilityChange(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId) { int newAbilityId; newAbilityId=BTL_EVENT_GetVar(BTL_EVAR_NEW_ABILITY_ID); if(newAbilityId!=BTL_EVENT_GetFactorKey(factor) && pokeId==BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) HAND_TOKUSEI_IllusionBreak(factor,flow,pokeId); }

/* Illusion: drop the disguise when it is active. */
void HAND_TOKUSEI_IllusionBreak(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExEndIllusion *rec;
    if (BTL_POKEPARAM_IsIllusionActive(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId))) {
        rec = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_END_ILLUSION, pokeId);
        rec->pokeId = pokeId;
        BTL_SERVER_FLOW_InitMsgRecord(&rec->str, HANDEX_STR_SET, 478);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&rec->str, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rec);
    }
}

const BtlEventHandlerEntry *HAND_TOKUSEI_AddVictoryStar(int *count)
{
    *count = 1;
    return gVictoryStarHandlers;
}

/*
 * Victory Star: raise the accuracy of the owner's side by 10%.
 * lever: u8 result local reproduces 021DCEA6/021DCEA8 truncation in r0,
 * then shift-copy to r1; inline narrowing produced an extra register copy.
 */
void HAND_TOKUSEI_VictoryStarBoostAccuracy(int factor, int flow, unsigned int pokeId) { unsigned char attackerId; attackerId=BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID); if(BTL_MAIN_IsPokeSamePair(pokeId,attackerId)) BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO,BTL_RATIO_ACCURACY_BOOST); }

/* Add the event factor of an item to the factor list; 0 if the item has no handler. */
struct BtlEventFactor *HAND_ITEM_AddFactor(struct BtlPokeParam *poke, u32 itemId)
{
    u32 i;
    u16 speed;
    u8 ownerId;
    u32 handlerTable;
    u32 handlerCount;

    for (i = 0; i < ITEM_HANDLER_COUNT; i++) {
        if (itemId == gItemHandlerRegistry[i].itemId) {
            speed = func_021D58A8(poke, 0xc);
            ownerId = BTL_POKEPARAM_GetPokeId(poke);
            handlerTable = gItemHandlerRegistry[i].getHandlers(&handlerCount);
            return BTL_EVENT_AddFactor(BTL_EVENT_TYPE_ITEM, itemId, 6, speed, ownerId, handlerTable, handlerCount);
        }
    }
    return 0;
}

/* Remove the item factors of a Pokemon, except those that were added from outside. */
void HAND_ITEM_RemoveUnforcedFactors(struct BtlPokeParam *poke)
{
    struct BtlEventFactor *factor = BTL_EVENT_FindFactor(BTL_EVENT_TYPE_ITEM, BTL_POKEPARAM_GetPokeId(poke));
    while (factor != 0) {
        struct BtlEventFactor *next = BTL_EVENT_FindNextFactor(factor);
        if (BTL_EVENT_GetFactorWork(factor, ITEM_WORK_FORCED_USE) == 0)
            BTL_EVENT_RemoveFactor(factor);
        factor = next;
    }
}

/*
 * Add the factor of the held item.
 * interface: 021D5B40's u16 field result is kept as a full register value
 * until the explicit halfword truncation at 021DCF68/021DCF6C; the caller
 * therefore uses a wide result and a u16 021DCEC4 argument, as the listing shows.
 */
struct BtlEventFactor *HAND_ITEM_AddHeldItemFactor(struct BtlPokeParam *poke) { int heldItem; heldItem=BTL_POKEPARAM_GetItem(poke); if(heldItem) return HAND_ITEM_AddFactor(poke,(unsigned short)heldItem); return 0; }

/* Add the factor of an item from outside (not held) and mark it as forced. */
struct BtlEventFactor *HAND_ITEM_AddForcedFactor(struct BtlPokeParam *poke, unsigned int itemId) { struct BtlEventFactor *factor; if(itemId) { factor=HAND_ITEM_AddFactor(poke,itemId); if(factor) { BTL_EVENT_EnableFactorSpecialEvent(factor); BTL_EVENT_SetFactorWork(factor,ITEM_WORK_FORCED_USE,1); return factor; } } return 0; }

/*
 * Remove one item factor.
 * tail-call thunk to BTL_EVENT_RemoveFactor
 */
void HAND_ITEM_RemoveFactor(struct BtlEventFactor *factor)
{
    BTL_EVENT_RemoveFactor(factor);
}

/* Switch off the item factors of a Pokemon. */
void HAND_ITEM_DisablePokeFactors(struct BtlPokeParam *poke) { BTL_EVENT_DisablePokeFactors(BTL_POKEPARAM_GetPokeId(poke),BTL_EVENT_TYPE_ITEM); }

/* Switch the item factors of a Pokemon on again; add the held item's factor when there is none. */
void HAND_ITEM_EnablePokeFactors(struct BtlPokeParam *poke) { if(!BTL_EVENT_EnablePokeFactors(BTL_POKEPARAM_GetPokeId(poke),BTL_EVENT_TYPE_ITEM)) HAND_ITEM_AddHeldItemFactor(poke); }

/*
 * An item chance succeeds when the percent roll passes or the battle rule says so.
 * interface: 021C82B8 forwards r1=2 unchanged to 021B911C; r0 is consumed
 * after the call at 021DCFEA, requiring a result despite its legacy void extern.
 */
int HAND_ITEM_RollChance(struct BtlSvFlow *flow, unsigned int percent) { if(BTL_CALC_RollPercent(percent)) return 1; if(BTL_SERVER_FLOW_QueryMainFlag(flow,2)) return 1; return 0; }

/*
 * Parameter of the item behind an event factor.
 * 021DCFF8  pass-through: second callee takes the first one's result
 * Leaf with no calls and no pool; 6 instructions, 16 bytes: push {r4, lr}; adds r4, r1, #0; bl BTL_EVENT_GetFactorKey; adds r1, r4, #0; bl BTL_CALC_GetMonParamWithHeap; pop {r4, pc}.
 */
int HAND_ITEM_GetParam(struct BtlEventFactor *factor, int paramIndex)
{
    return BTL_CALC_GetMonParamWithHeap(BTL_EVENT_GetFactorKey(factor), paramIndex);
}

/* Boost ratio (4096 = 1.0) of an item whose parameter 2 is a percent bonus. */
int HAND_ITEM_GetBoostRatio(struct BtlEventFactor *factor) { int percent; float ratio; percent=HAND_ITEM_GetParam(factor,2)+100; if(percent>0) ratio=0.5f+(float)(percent<<12); else ratio=(float)(percent<<12)-0.5f; return (int)ratio/100; }

/* Mark the item as used and ask the flow to show it. */
void HAND_ITEM_PushUseItem(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BTL_EVENT_KeepFactorRunning(factor);
    BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_KIND_USE_ITEM, pokeId);
}

/* Cheri Berry (cures paralysis). */
void HAND_ITEM_CheriBerryOnTrigger(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnTrigger(factor, flow, pokeId, BTL_SICK_PARALYSIS);
}

void HAND_ITEM_CheriBerryOnEaten(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnEaten(factor, flow, pokeId, BTL_SICK_PARALYSIS);
}

const BtlEventHandlerEntry *HAND_ITEM_AddCheriBerry(int *count)
{
    *count = 5;
    return gCheriBerryHandlers;
}

/* Chesto Berry (cures sleep). */
void HAND_ITEM_ChestoBerryOnTrigger(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnTrigger(factor, flow, pokeId, BTL_SICK_SLEEP);
}

void HAND_ITEM_ChestoBerryOnEaten(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnEaten(factor, flow, pokeId, BTL_SICK_SLEEP);
}

const BtlEventHandlerEntry *HAND_ITEM_AddChestoBerry(int *count)
{
    *count = 5;
    return gChestoBerryHandlers;
}

/* Rawst Berry (cures burn). */
void HAND_ITEM_RawstBerryOnTrigger(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnTrigger(factor, flow, pokeId, BTL_SICK_BURN);
}

void HAND_ITEM_RawstBerryOnEaten(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnEaten(factor, flow, pokeId, BTL_SICK_BURN);
}

const BtlEventHandlerEntry *HAND_ITEM_AddRawstBerry(int *count)
{
    *count = 5;
    return gRawstBerryHandlers;
}

/* Aspear Berry (cures freeze). */
void HAND_ITEM_AspearBerryOnTrigger(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnTrigger(factor, flow, pokeId, BTL_SICK_FREEZE);
}

void HAND_ITEM_AspearBerryOnEaten(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnEaten(factor, flow, pokeId, BTL_SICK_FREEZE);
}

const BtlEventHandlerEntry *HAND_ITEM_AddAspearBerry(int *count)
{
    *count = 5;
    return gAspearBerryHandlers;
}

/* Persim Berry (cures confusion). */
void HAND_ITEM_PersimBerryOnTrigger(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnTrigger(factor, flow, pokeId, BTL_SICK_CONFUSION);
}

void HAND_ITEM_PersimBerryOnEaten(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnEaten(factor, flow, pokeId, BTL_SICK_CONFUSION);
}

const BtlEventHandlerEntry *HAND_ITEM_AddPersimBerry(int *count)
{
    *count = 5;
    return gPersimBerryHandlers;
}

/* Pecha Berry (cures poison). */
void HAND_ITEM_PechaBerryOnTrigger(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnTrigger(factor, flow, pokeId, BTL_SICK_POISON);
}

void HAND_ITEM_PechaBerryOnEaten(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnEaten(factor, flow, pokeId, BTL_SICK_POISON);
}

const BtlEventHandlerEntry *HAND_ITEM_AddPechaBerry(int *count)
{
    *count = 5;
    return gPechaBerryHandlers;
}

/* Lum Berry (cures any status). */
void HAND_ITEM_LumBerryOnTrigger(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnTrigger(factor, flow, pokeId, BTL_SICK_ANY);
}

void HAND_ITEM_LumBerryOnEaten(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HAND_ITEM_CureSickOnEaten(factor, flow, pokeId, BTL_SICK_ANY);
}

const BtlEventHandlerEntry *HAND_ITEM_AddLumBerry(int *count)
{
    *count = 5;
    return gLumBerryHandlers;
}

/* Status berry used on its own: cure the status when the trigger kind allows it. */
void HAND_ITEM_CureSickOnTrigger(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int sickKind)
{
    int triggerKind;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_EVENT_TryGetVar(BTL_EVAR_TRIGGER_KIND, &triggerKind) == 0 || triggerKind == 3 || triggerKind == 0) {
            if (HAND_ITEM_CheckHasSick(flow, pokeId, sickKind) != 0)
                HAND_ITEM_PushUseItem(factor, flow, pokeId);
        }
    }
}

/* Status berry eaten through another move: cure the status. */
void HAND_ITEM_CureSickOnEaten(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int sickKind)
{
    HandExCureSick *rec;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && HAND_ITEM_CheckHasSick(flow, pokeId, sickKind)) {
        rec = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
        rec->sickKind = sickKind;
        rec->pokeCount = 1;
        rec->pokeIds[0] = pokeId;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rec);
    }
}

/* Does the Pokemon have the status condition that the berry cures? */
int HAND_ITEM_CheckHasSick(struct BtlSvFlow *flow, int pokeId, int sickKind)
{
    struct BtlPokeParam *poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    switch (sickKind) {
    case BTL_SICK_ANY:
        if (BTL_POKEPARAM_GetMajorStatusIndex(poke) == 0 && BTL_POKEPARAM_HasSick(poke, BTL_SICK_CONFUSION) == 0)
            break;
        return 1;
    case BTL_SICK_ANY_MAJOR:
        if (BTL_POKEPARAM_GetMajorStatusIndex(poke) != 0)
            return 1;
        return 0;
    case BTL_SICK_ANY_VOLATILE:
        if (BTL_CALC_FindMajorSick(poke) != 0)
            return 1;
        return 0;
    default:
        return BTL_POKEPARAM_HasSick(poke, sickKind);
    }
    return 0;
}

const BtlEventHandlerEntry *HAND_ITEM_AddLeppaBerry(int *count)
{
    *count = 7;
    return gLeppaBerryHandlers;
}

/* Leppa Berry: use it when the last used move is out of PP. */
void HAND_ITEM_LeppaBerryOnLastMoveEmpty(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (HAND_ITEM_FindLastMoveEmptySlot(flow, pokeId) != BTL_MOVE_SLOT_NONE)
            HAND_ITEM_PushUseItem(factor, flow, pokeId);
    }
}

/* Leppa Berry: use it when any move is out of PP (checked for the trigger kinds 0 and 2). */
void HAND_ITEM_LeppaBerryOnAnyMoveEmptyChecked(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    int triggerKind;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        triggerKind = BTL_EVENT_GetVar(BTL_EVAR_TRIGGER_KIND);
        if (triggerKind != 2 && triggerKind != 0) return;
        if (HAND_ITEM_FindEmptyMoveSlot(flow, pokeId) != BTL_MOVE_SLOT_NONE)
            HAND_ITEM_PushUseItem(factor, flow, pokeId);
    }
}

/* Leppa Berry: use it when any move is out of PP. */
void HAND_ITEM_LeppaBerryOnAnyMoveEmpty(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (HAND_ITEM_FindEmptyMoveSlot(flow, pokeId) != BTL_MOVE_SLOT_NONE)
            HAND_ITEM_PushUseItem(factor, flow, pokeId);
    }
}

/* Leppa Berry: claim the trigger when the last used move is out of PP. */
void HAND_ITEM_LeppaBerryClaimTrigger(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && HAND_ITEM_FindLastMoveEmptySlot(flow, pokeId) != BTL_MOVE_SLOT_NONE)
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_FLOATING_FLAG, 1);
}

/*
 * Leppa Berry eaten through another move: restore the PP of an empty move.
 * extent: trailing two-byte alignment padding.
 * prototype: third DD39C input widened to full register width; no truncation at call.
 */
void HAND_ITEM_LeppaBerryOnEaten(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) HAND_ITEM_PushRecoverPp(factor, flow, pokeId, work, 0);
}

/*
 * Leppa Berry used from outside: restore the PP of an empty move, or of a move that lost PP.
 * extent: trailing two-byte alignment padding.
 */
void HAND_ITEM_LeppaBerryOnForcedUse(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 pokeId, int *work)
{
    if (work[ITEM_WORK_FORCED_USE] != 0) HAND_ITEM_PushRecoverPp(factor, flow, pokeId, work, 1);
}

/*
 * Slot of the last used move when it is out of PP, else the none value.
 * extent: trailing two-byte alignment padding.
 * prototype: C7CF4 result used and r1 supplied; 5584 index is the u8 return of 5778.
 */
u8 HAND_ITEM_FindLastMoveEmptySlot(struct BtlSvFlow *flow, int pokeId)
{
    struct BtlPokeParam *poke;
    u8 slot;
    poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    slot = BTL_POKEPARAM_FindMoveSlot(poke, BTL_POKEPARAM_GetLastSelectedMoveId(poke));
    if (slot != BTL_MOVE_SLOT_NONE && BTL_POKEPARAM_GetMovePPChecked(poke, slot) == 0) return slot;
    return BTL_MOVE_SLOT_NONE;
}

/* First move slot that is out of PP, else the none value. */
u8 HAND_ITEM_FindEmptyMoveSlot(struct BtlSvFlow *flow, int pokeId)
{
    struct BtlPokeParam *poke;
    u32 moveCount, i;
    poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    moveCount = BTL_POKEPARAM_GetMoveCount(poke);
    for (i = 0; i < moveCount; i++) {
        if (BTL_POKEPARAM_GetMovePPChecked(poke, (u8)i) == 0) return (u8)i;
    }
    return BTL_MOVE_SLOT_NONE;
}

/* Restore 10 PP of an empty move slot (with allowAnyLostSlot, of any move that lost PP). */
int HAND_ITEM_PushRecoverPp(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 pokeId, int *work, int allowAnyLostSlot)
{
    struct BtlPokeParam *poke;
    u32 i;
    u32 moveCount;
    u8 slot;
    HandExRecoverPp *rec;
    poke = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    slot = HAND_ITEM_FindLastMoveEmptySlot(flow, pokeId);
    if (slot == BTL_MOVE_SLOT_NONE) {
        slot = HAND_ITEM_FindEmptyMoveSlot(flow, pokeId);
        if (slot == BTL_MOVE_SLOT_NONE && allowAnyLostSlot) {
            moveCount = BTL_POKEPARAM_GetMoveCount(poke);
            for (i = 0; i < moveCount; i++) {
                if (BTL_POKEPARAM_GetMovePPLost(poke, i)) {
                    slot = i;
                    break;
                }
            }
        }
    }
    if (slot != BTL_MOVE_SLOT_NONE) {
        rec = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RECOVER_PP, pokeId);
        rec->volume = 10;
        rec->pokeId = pokeId;
        rec->moveSlot = slot;
        rec->showItem = 1;
        BTL_SERVER_FLOW_InitMsgRecord(&rec->str, HANDEX_STR_SET, 0x38f);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&rec->str, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&rec->str, BTL_EVENT_GetFactorKey(factor));
        BTL_SERVER_FLOW_AppendMsgRecordArg(&rec->str, BTL_POKEPARAM_GetMoveId(poke, slot));
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rec);
        return 1;
    }
    return 0;
}

const BtlEventHandlerEntry *HAND_ITEM_AddOranBerry(int *count) { *count = 5; return gOranBerryHandlers; }

/* HP-restoring berries (Oran, Berry Juice, Sitrus): use the item when HP is low, unless Heal Block applies. */
void HAND_ITEM_RecoverHpOnTrigger(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), 15) == 0)
        HAND_ITEM_HpBerryCheckAndUse(factor, flow, pokeId, 2, 1);
}

void HAND_ITEM_RecoverHpOnCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), 15) == 0)
        HAND_ITEM_HpBerryCheckAndUse(factor, flow, pokeId, 2, 0);
}

void HAND_ITEM_RecoverHpOnLowHp(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), 15) == 0 && HAND_ITEM_IsHpAtOrBelowFraction(flow, pokeId, 2) != 0)
        HAND_ITEM_PushUseItem(factor, flow, pokeId);
}

/* Fixed-amount HP berry eaten through another move: restore the amount from the item parameter. */
void HAND_ITEM_RecoverFixedHpOnEaten(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExRecoverHp *rec;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        rec = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RECOVER_HP, pokeId);
        rec->pokeId = pokeId;
        rec->amount = HAND_ITEM_GetParam(factor, 2);
        BTL_SERVER_FLOW_InitMsgRecord(&rec->str, HANDEX_STR_SET, 908);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&rec->str, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&rec->str, BTL_EVENT_GetFactorKey(factor));
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rec);
    }
}

const BtlEventHandlerEntry *HAND_ITEM_AddBerryJuice(int *count)
{
    *count = 4;
    return gBerryJuiceHandlers;
}

const BtlEventHandlerEntry *HAND_ITEM_AddSitrusBerry(int *count)
{
    *count = 5;
    return gSitrusBerryHandlers;
}
