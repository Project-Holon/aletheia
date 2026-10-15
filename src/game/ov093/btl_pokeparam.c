/*
 * file:     btl_pokeparam.c
 * unit:     yes
 * function: BTL_POKEPARAM_Create, BTL_POKEPARAM_ReloadFromMon, BTL_POKEPARAM_LoadMoves, BTL_POKEPARAM_SaveMovesToMon, BTL_POKEPARAM_SyncMovesFromMon, BTL_POKEPARAM_ResetBattleMoves, BTL_POKEPARAM_ClearMoveUsedFlags, BTL_POKEPARAM_ReplaceMoveSlot, BTL_POKEPARAM_SetMoveInfo, BTL_POKEPARAM_LoadMoveInfo, BTL_POKEPARAM_LoadStats, BTL_POKEPARAM_RestoreIfNeeded, BTL_POKEPARAM_ResetMoveHistory, BTL_POKEPARAM_ClearMoveFlags, BTL_POKEPARAM_Delete, BTL_POKEPARAM_InitStatStages, BTL_POKEPARAM_SetNeutralStatStages, BTL_POKEPARAM_RaiseLowStatStagesInArray, BTL_POKEPARAM_GetPokeId, BTL_POKEPARAM_GetSpecies, BTL_POKEPARAM_GetMoveCount, func_021D5450, func_021D5478, BTL_POKEPARAM_GetUsedMoveTotal, BTL_POKEPARAM_GetMoveId, BTL_POKEPARAM_GetRealMoveId, BTL_POKEPARAM_GetMoveUsedFlag, func_021D54F4, func_021D5528, BTL_POKEPARAM_GetMovePPLost, BTL_POKEPARAM_GetRealMovePPLost, BTL_POKEPARAM_GetMovePPChecked, BTL_POKEPARAM_GetMovePPById, BTL_POKEPARAM_IsMovePPFull, BTL_POKEPARAM_DecrementMovePP, BTL_POKEPARAM_DecrementRealMovePP, BTL_POKEPARAM_RestoreMovePP, BTL_POKEPARAM_RestoreRealMovePP, BTL_POKEPARAM_MarkMoveUsed, BTL_POKEPARAM_ReplaceMove, BTL_POKEPARAM_HasMove, BTL_POKEPARAM_FindMoveSlot, BTL_POKEPARAM_GetTypes, BTL_POKEPARAM_GetTypePair, BTL_POKEPARAM_HasType, BTL_POKEPARAM_GetMon, BTL_POKEPARAM_SetFakeMon, BTL_POKEPARAM_ClearFakeMon, BTL_POKEPARAM_GetDisplayMon, BTL_POKEPARAM_RemapStatId, func_021D58A8, BTL_POKEPARAM_ReadStatsFromMon, BTL_POKEPARAM_SetStat, func_021D59B4, BTL_POKEPARAM_GetStatForCrit, BTL_POKEPARAM_GetItem, BTL_POKEPARAM_SetItem, BTL_POKEPARAM_IsHpFull, BTL_POKEPARAM_IsFainted, BTL_POKEPARAM_IsAbleToBattle, BTL_POKEPARAM_GetTurnCount, BTL_POKEPARAM_TestTurnFlag, BTL_POKEPARAM_TestContFlag, BTL_POKEPARAM_GetSemiInvulnerableFlag, BTL_POKEPARAM_IsSemiInvulnerable, BTL_POKEPARAM_GetHpRatioFixed, func_021D5CB4, func_021D5D14, func_021D5D50, BTL_POKEPARAM_HasLoweredStatStage, BTL_POKEPARAM_RaiseStatStage, BTL_POKEPARAM_LowerStatStage, BTL_POKEPARAM_SetStatStage, BTL_POKEPARAM_RaiseLoweredStatStages, BTL_POKEPARAM_ResetStatStages, BTL_POKEPARAM_GetCritStage, BTL_POKEPARAM_AddCritStage, BTL_POKEPARAM_SubHp, BTL_POKEPARAM_AddHp, BTL_POKEPARAM_ZeroHp, BTL_POKEPARAM_SetTurnFlag, BTL_POKEPARAM_SetContFlag, BTL_POKEPARAM_ClearContFlag, BTL_POKEPARAM_SetSickCont, BTL_POKEPARAM_TickSickCont, BTL_POKEPARAM_TickSleepTurn, BTL_POKEPARAM_TickSlot6Turn, BTL_POKEPARAM_ClearMajorStatus, BTL_POKEPARAM_ClearDependentSick, BTL_POKEPARAM_CureSick, BTL_POKEPARAM_CureSickBySource, BTL_POKEPARAM_GetMajorStatusIndex, BTL_POKEPARAM_HasSick, BTL_POKEPARAM_GetSickParam, BTL_POKEPARAM_GetSickContRaw, BTL_POKEPARAM_GetSickTurn, BTL_POKEPARAM_CalcSickDamage, BTL_POKEPARAM_ClearSickConts, BTL_POKEPARAM_StartTurnThreshold, BTL_POKEPARAM_AdvanceTurn, BTL_POKEPARAM_ClearTurnFlag, BTL_POKEPARAM_ResetAllEffects, BTL_POKEPARAM_ResetEffectsOnSwitchOut, BTL_POKEPARAM_ReloadAndResetEffects, BTL_POKEPARAM_PassEffects, BTL_POKEPARAM_SetTypes, BTL_POKEPARAM_SetAbility, BTL_POKEPARAM_ChangeForm, BTL_POKEPARAM_ConsumeHeldItem, BTL_POKEPARAM_ClearConsumedItem, BTL_POKEPARAM_GetConsumedItem, BTL_POKEPARAM_RecordMoveUse, BTL_POKEPARAM_GetMoveStreak, BTL_POKEPARAM_GetLastUsedMoveId, BTL_POKEPARAM_GetLastTargetPos, BTL_POKEPARAM_GetLastSelectedMoveId, BTL_POKEPARAM_GetLastMoveSlot, BTL_POKEPARAM_IsLevelUpPending, BTL_POKEPARAM_SetWeight, BTL_POKEPARAM_GetWeight, BTL_POKEPARAM_ClearHitHistory, BTL_POKEPARAM_AdvanceHitTurn, BTL_POKEPARAM_AddHitRecord, BTL_POKEPARAM_GetHitCount, BTL_POKEPARAM_GetHitRecord, BTL_POKEPARAM_SetCounter, func_021D69AC, BTL_POKEPARAM_AddExp, BTL_POKEPARAM_GetMaxLevelExp, BTL_POKEPARAM_WriteBackToParam, BTL_POKEPARAM_ReloadFromParam, BTL_POKEPARAM_IsIllusionActive, BTL_POKEPARAM_ClearIllusion, BTL_POKEPARAM_SetPokeParam, BTL_POKEPARAM_Transform, BTL_POKEPARAM_IsTransformed, BTL_POKEPARAM_SetSubstituteHp, BTL_POKEPARAM_ClearSubstitute, BTL_POKEPARAM_HasSubstitute, BTL_POKEPARAM_GetSubstituteHp, BTL_POKEPARAM_DamageSubstitute, func_021D6DC4, BTL_EVENT_GetClientPartyCount, BTL_EVENT_GetClientPartySlotId, BTL_EVENT_StartClientPalAnm, BTL_EVENT_SetClientReservedChoice, BTL_EVENT_GetClientReservedChoice, BTL_EVENT_HasClientReservedChoice, BTL_EVENT_ClearClientReservedChoice, BTL_EVENT_ReleaseClientHandle
 * address:  0x021D4D84
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
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_ConsumeHeldItem 0x021D6730 thumb ov093
 *   BTL_POKEPARAM_RecordMoveUse 0x021D6744 thumb ov093
 *   BTL_POKEPARAM_SetContFlag 0x021D5FE4 thumb ov093
 *   BTL_POKEPARAM_ClearContFlag 0x021D6008 thumb ov093
 *   BTL_POKEPARAM_SetTurnFlag 0x021D5FC0 thumb ov093
 *   BTL_POKEPARAM_ClearTurnFlag 0x021D6440 thumb ov093
 *   BTL_POKEPARAM_SetAbility 0x021D66D0 thumb ov093
 *   BTL_POKEPARAM_ResetEffectsOnSwitchOut   0x021D64F0  thumb
 *   BTL_FIELD_RegisterSlot 0x021EF9F4 thumb ov093
 *   BTL_FIELD_AddSlotHolder 0x021EFAD8 thumb ov093
 *   BTL_FIELD_RemoveHolderFromSlots 0x021EFB34 thumb ov093
 *   BTL_FIELD_RemoveSlot 0x021EFA94 thumb ov093
 *   BTL_POKEPARAM_SetCounter 0x021D69A0 thumb ov093
 *   BTL_POKEPARAM_PassEffects 0x021D65C8 thumb ov093
 *   BTL_POKEPARAM_SetSubstituteHp 0x021D6D5C thumb ov093
 *   BTL_POKEPARAM_ClearSubstitute   0x021D6D70  thumb
 *   BTL_CLIENT_AddPoints 0x021CD9F4 thumb ov093
 *   BTL_MAIN_AddClientPoints 0x021B9B10 thumb ov093
 *   BTL_SIDE_GetSlotOfClient 0x021B9AEC thumb ov093
 *   BTL_SLOT_UpdateIllusion 0x021B9D10 thumb ov093
 *   BTL_POKEPARAM_ClearConsumedItem   0x021D6738  thumb
 *   BTL_POKEPARAM_CureSickBySource 0x021D6264 thumb ov093
 *   BTL_POKEPARAM_AddHitRecord 0x021D6848 thumb ov093
 *   BTL_POKEPARAM_AdvanceTurn 0x021D6408 thumb ov093
 *   BTL_EVENT_ClearClientReservedChoice 0x021D6E88 thumb ov093
 *   BTL_FIELD_TickSlots   0x021EFC78  thumb
 *   BTL_POKEPARAM_SetWeight 0x021D67D8 thumb ov093
 *   BTL_FIELD_GetCountdownByte 0x021EF9A8 thumb ov093
 *   BTL_MAIN_GetTrainerItem 0x021B9F84 thumb ov093
 *   gBtlClientItemSlotLimits  0x021EFF74  data  a1
 *   BTL_SLOT_GetCount  0x021B9B94  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_CALC_GetItemParam  0x021D805C  thumb  ov093
 *   BTL_CALC_DivideMaxHp  0x021D7B60  thumb  ov093
 *   gBtlClientItemStatChecks  0x021EFF94  data  ov093  a1
 *   BTL_POKEPARAM_GetCritStage  0x021D5F14  thumb  ov093
 *   gBtlClientItemSickChecks 0x021EFFA0 data a1
 *   BTLV_CORE_SetCounterDisplay 0x021EAE74 thumb ov093
 *   BTLV_CORE_PollCounterInput 0x021EAE64 thumb ov093
 *   BTLV_CORE_StartFadeIn 0x021EAE04 thumb ov093
 *   BTLV_CORE_SetCounterValueMode 0x021EAECC thumb ov093
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_SetPlayersAudible 0x02005CA4 thumb
 *   PM_VOICE_SetMasterVolume 0x02006734 thumb
 *   BTLV_EFFECT_SuspendVmWait 0x021F8B10 thumb ov094
 *   BTL_MAIN_SetKeepBgm 0x021B92A0 thumb ov093
 *   BTLV_CORE_PollFadeInDone 0x021EAE14 thumb ov093
 *   gBtlNet 0x021F3B88 data ov093 a4
 *   gBtlNetSourceName 0x021F3A98 data ov093 a4
 *   func_02030734 0x02030734 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GFL_NET_GetNegotiationNum 0x0203D1B4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *   GFL_NET_SendData  0x0203D3F8  arm
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   func_02007B50  0x02007B50  thumb
 *   func_02007B00  0x02007B00  thumb
 *   MI_CpuCopy8    0x02082D44  arm
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   MYSTATUS_GetSize 0x02008468 thumb
 *   gBtlNetSourceName   0x021F3A98  data
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   MIi_CpuClear16 0x02082A48  arm
 *   STRBUF_GetLength   0x020458F8  arm
 *   STRBUF_GetChars   0x02045A90  arm
 *   sub_0201F41C   0x0201F41C  thumb
 *   GFL_NET_HANDLE_SetUserInfo 0x0203A424 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02017E1C  0x02017E1C  thumb
 *   POKE_TOOL_GetPersonalParam  0x02019C90  thumb
 *   POKE_TOOL_GetStatusCondition  0x02017F90  thumb
 *   BTL_POKEPARAM_ClearSickConts  0x021D63B8  thumb  ov093
 *   BTL_CALC_MakeDefaultSickCont  0x021D7D18  thumb  ov093
 *   BTL_POKEPARAM_ClearHitHistory  0x021D67F4  thumb  ov093
 *   func_021D6DC4  0x021D6DC4  thumb  ov093
 *   gBtlPokeparamFileName     0x021F3AA4  data  a1
 *   POKE_TOOL_DecodePartyParam 0x02017D30 thumb
 *   POKE_TOOL_EncodePartyParam 0x02017D70 thumb
 *   func_020181F4  0x020181F4  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   WAZA_TOOL_GetMaxPP 0x0201C158 thumb
 *   POKE_TOOL_GetGender  0x02017F00  thumb
 *   BTLV_CORE_PackBytes  0x021E8CE0  thumb  ov093
 *   BTL_FIELD_GetStaticSlotObject 0x021EF948 thumb ov093
 *   BTL_CALC_ApplyStatStage  0x021D78E4  thumb  ov093
 *   gSemiInvulnerableContFlags  0x021F040C  data  ov093
 *   _dflt   0x0209B750  arm
 *   _dfltu  0x0209B790  arm
 *   _ddiv   0x0209D1E0  arm
 *   _dgr    0x0209B864  arm
 *   _dmul   0x0209B2E8  arm
 *   _dadd   0x0209AC04  arm
 *   _dsub   0x0209AF34  arm
 *   _dfix   0x0209C508  arm
 *   BTL_ID_IsBatonPassSick  0x0689C868  thumb
 *   BTL_POKEPARAM_RaiseLowStatStagesInArray  0x021D53DC  thumb  ov093
 *   BTL_POKEPARAM_SetNeutralStatStages  0x021D53C8  thumb  ov093
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTL_CALC_HasDefaultSickCont  0x021D7D6C  thumb  ov093
 *   BTLV_CORE_GetSlotLow  0x021E8AFC  thumb  ov093
 *   BTLV_CORE_GetSlotValue  0x021E8B80  thumb  ov093
 *   BTLV_CORE_GetZeroMasked  0x021E8918  thumb  ov093
 *   BTL_POKEPARAM_HasMove  0x021D5750  thumb  ov093
 *   BTLV_CORE_IsSlotKindNone  0x021E8928  thumb  ov093
 *   BTLV_CORE_GetSlotPosition  0x021E8A98  thumb  ov093
 *   BTLV_CORE_IsSlotKind1Index15  0x021E8A78  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   MI_CpuFill8  0x02082BCC  arm
 *   BTL_POKEPARAM_AdvanceHitTurn  0x021D6824  thumb  ov093
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 *   BTL_POKEPARAM_RestoreIfNeeded  0x021D533C  thumb  ov093
 *   BTL_POKEPARAM_ResetBattleMoves  0x021D5150  thumb  ov093
 *   BTL_POKEPARAM_ResetMoveHistory  0x021D5364  thumb  ov093
 *   BTL_POKEPARAM_ClearMoveFlags  0x021D539C  thumb  ov093
 *   BTL_POKEPARAM_ClearIllusion  0x021D6C2C  thumb  ov093
 *   BTL_POKEPARAM_InitStatStages  0x021D53C0  thumb  ov093
 *   BTL_POKEPARAM_ReloadFromMon  0x021D4EFC  thumb  ov093
 *   func_021D58A8  0x021D58A8  thumb  ov093
 *   BTL_POKEPARAM_SetStat  0x021D5970  thumb  ov093
 *   BTLV_CORE_GetHighByte 0x021E8CFC thumb ov093
 *   BTLV_CORE_GetLowByte 0x021E8D04 thumb ov093
 *   POKE_TOOL_ChangeForm  0x02017988  thumb
 *   BTL_POKEPARAM_LoadStats  0x021D52B4  thumb  ov093
 *   func_02018584 0x02018584 thumb
 *   BTL_POKEPARAM_SaveMovesToMon 0x021D505C thumb ov093
 *   POKE_TOOL_SetStatusCondition  0x02017F9C  thumb
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_POKEPARAM_LoadMoves 0x021D4F84 thumb ov093
 *   BTL_POKEPARAM_SyncMovesFromMon 0x021D50B4 thumb ov093
 *   BTL_POKEPARAM_ReplaceMoveSlot  0x021D51DC  thumb  ov093
 *   gBtlPokeParamTransformMoves     0x021F3B8C  data  a4
 *   gBtlPokeParamTransformKept     0x021F3BC4  data  a4
 *   BTL_POKEPARAM_CureSick 0x021D6238 thumb ov093
 *   PALANM_GetPairedCodeForFirst 0x0202142C thumb
 *   gBtlEventFactorStorage  0x021F4470  data  a4
 *   gBtlEventFactorFreePool  0x021F3CBC  data  a4
 *   gBtlEventFactorList  0x021F3CB0  data  a4
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_TestTurnFlag 0x021D5BB0 thumb ov093
 *   HAND_WAZA_IsKeptOnSuspend  0x021E03E8  thumb  ov093
 *   gBtlEventVarStack 0x021F3ECC data a4
 *   gBtlEventEmptyString  0x021F3AB4  data
 *   func_02034714  0x02034714  arm
 *   _ll_mul        0x0209C054  arm
 *   d_021F6360 0x021F6360 data a4
 *   gBtlCalcFileName 0x021F3AB8 data a1
 *   gBtlCalcWork  0x021F6360  data  ov093
 *   _ull_mul       0x0209C054  arm
 *   gBtlStatStageRatios 0x021F0448 data a1
 *   _u32_div_f 0x0209C2B0 arm
 */
#include "btl_pokeparam_types.h"

typedef struct BtlPokeParam BtlPokeParam;
typedef struct PokemonParam PokemonParam;

int BTL_POKEPARAM_HasSick(BtlPokeParam *pp, int condition);
extern u32 func_020307B0(void *p);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern u32 func_02017E1C(PokemonParam *mon, u32 paramId, u32 arg);
extern u32 POKE_TOOL_GetPersonalParam(u16 species, u16 form, u32 paramId);
extern u32 POKE_TOOL_GetStatusCondition(PokemonParam *mon);
void BTL_POKEPARAM_ClearSickConts(BtlPokeParam *pp, int all);
extern union SickCont BTL_CALC_MakeDefaultSickCont(int condition);
void BTL_POKEPARAM_ClearHitHistory(BtlPokeParam *pp);
void func_021D6DC4(BtlPokeParam *pp);
extern u32 POKE_TOOL_DecodePartyParam(PokemonParam *mon);
extern u32 POKE_TOOL_EncodePartyParam(PokemonParam *mon, u32 wasDecoded);
extern void func_020181F4(PokemonParam *mon, u16 moveId, u32 slot);
extern void POKE_TOOL_SetPartyValue(PokemonParam *mon, u32 paramId, u32 value);
extern u32 WAZA_TOOL_GetMaxPP(u32 moveId, u32 ppUps);
extern u8 POKE_TOOL_GetGender(PokemonParam *mon);
extern u16 BTLV_CORE_PackBytes(u32 type1, u32 type2);
extern int BTL_FIELD_GetStaticSlotObject(int);
extern unsigned short BTL_CALC_ApplyStatStage(unsigned short stat, int stage);
extern const char gBtlPokeparamFileName[];
extern const u32 gSemiInvulnerableContFlags[4];
BtlPokeParam *BTL_POKEPARAM_Create(PokemonParam *mon, u8 pokeId, u32 heapId);
void BTL_POKEPARAM_ReloadFromMon(BtlPokeParam *pp, PokemonParam *mon, u32 withHp, u32 withAbility);
int BTL_POKEPARAM_LoadMoves(BtlPokeParam *pp, PokemonParam *mon, int reset);
void BTL_POKEPARAM_SaveMovesToMon(BtlPokeParam *pp);
void BTL_POKEPARAM_SyncMovesFromMon(BtlPokeParam *pp);
void BTL_POKEPARAM_ResetBattleMoves(BtlPokeParam *pp);
void BTL_POKEPARAM_ClearMoveUsedFlags(struct BattleMoveSlot *slot);
void BTL_POKEPARAM_ReplaceMoveSlot(struct BattleMoveSlot *slot, u32 moveId, u32 ppCap, u32 toReal);
void BTL_POKEPARAM_SetMoveInfo(struct MoveInfo *info, u32 moveId, u32 ppCap);
int BTL_POKEPARAM_LoadMoveInfo(struct MoveInfo *info, PokemonParam *mon, u8 slotIndex);
void BTL_POKEPARAM_LoadStats(BtlPokeParam *pp, PokemonParam *mon, u32 withTypes);
void BTL_POKEPARAM_RestoreIfNeeded(BtlPokeParam *pp);
void BTL_POKEPARAM_ResetMoveHistory(BtlPokeParam *pp);
void BTL_POKEPARAM_ClearMoveFlags(BtlPokeParam *pp);
void BTL_POKEPARAM_Delete(BtlPokeParam *pp);
void BTL_POKEPARAM_InitStatStages(unsigned char *stages);
void BTL_POKEPARAM_SetNeutralStatStages(unsigned char *stages);
int BTL_POKEPARAM_RaiseLowStatStagesInArray(signed char *stages);
u8 BTL_POKEPARAM_GetPokeId(BtlPokeParam *pp);
u16 BTL_POKEPARAM_GetSpecies(BtlPokeParam *pp);
u8 BTL_POKEPARAM_GetMoveCount(BtlPokeParam *pp);
u8 func_021D5450(BtlPokeParam *pp);
u8 func_021D5478(BtlPokeParam *pp);
u8 BTL_POKEPARAM_GetUsedMoveTotal(BtlPokeParam *pp);
u16 BTL_POKEPARAM_GetMoveId(BtlPokeParam *pp, int slot);
u32 BTL_POKEPARAM_GetRealMoveId(BtlPokeParam *pp, u8 slot);
u32 BTL_POKEPARAM_GetMoveUsedFlag(BtlPokeParam *pp, u32 slot);
void func_021D54F4(BtlPokeParam *src, BtlPokeParam *dst);
u16 func_021D5528(BtlPokeParam *pp, u8 slot, u8 *pp_, u8 *ppMax);
u8 BTL_POKEPARAM_GetMovePPLost(BtlPokeParam *pp, u8 slot);
u8 BTL_POKEPARAM_GetRealMovePPLost(BtlPokeParam *pp, u32 slot);
u8 BTL_POKEPARAM_GetMovePPChecked(BtlPokeParam *pp, u32 slot);
int BTL_POKEPARAM_GetMovePPById(BtlPokeParam *pp, int moveId);
int BTL_POKEPARAM_IsMovePPFull(BtlPokeParam *pp, int slot, int useReal);
void BTL_POKEPARAM_DecrementMovePP(BtlPokeParam *pp, int slot, u8 amount);
void BTL_POKEPARAM_DecrementRealMovePP(BtlPokeParam *pp, u32 slot, u32 amount);
u16 BTL_POKEPARAM_RestoreMovePP(BtlPokeParam *pp, u32 slot, u8 amount);
u16 BTL_POKEPARAM_RestoreRealMovePP(BtlPokeParam *pp, u32 slot, u8 amount);
void BTL_POKEPARAM_MarkMoveUsed(BtlPokeParam *pp, int slot);
void BTL_POKEPARAM_ReplaceMove(BtlPokeParam *pp, u8 slot, u16 moveId, u8 ppCap, u32 toReal);
int BTL_POKEPARAM_HasMove(BtlPokeParam *pp, u16 moveId);
u8 BTL_POKEPARAM_FindMoveSlot(BtlPokeParam *pp, u16 moveId);
void BTL_POKEPARAM_GetTypes(BtlPokeParam *pp, u8 *type1, u8 *type2);
u16 BTL_POKEPARAM_GetTypePair(BtlPokeParam *pp);
int BTL_POKEPARAM_HasType(BtlPokeParam *pp, int type);
PokemonParam *BTL_POKEPARAM_GetMon(BtlPokeParam *pp);
void BTL_POKEPARAM_SetFakeMon(BtlPokeParam *pp, PokemonParam *fakeMon);
void BTL_POKEPARAM_ClearFakeMon(BtlPokeParam *pp);
PokemonParam *BTL_POKEPARAM_GetDisplayMon(BtlPokeParam *pp);
int BTL_POKEPARAM_RemapStatId(BtlPokeParam *pp, int valueId);
int func_021D58A8(BtlPokeParam *pp, int valueId);
void BTL_POKEPARAM_ReadStatsFromMon(PokemonParam **monPtr, u16 *stats);
void BTL_POKEPARAM_SetStat(BtlPokeParam *pp, int valueId, u16 value);
int func_021D59B4(BtlPokeParam *pp, int valueId);
int BTL_POKEPARAM_GetStatForCrit(BtlPokeParam *pp, int valueId);
u16 BTL_POKEPARAM_GetItem(BtlPokeParam *pp);
void BTL_POKEPARAM_SetItem(BtlPokeParam *pp, u16 item);
int BTL_POKEPARAM_IsHpFull(BtlPokeParam *pp);
int BTL_POKEPARAM_IsFainted(BtlPokeParam *pp);
int BTL_POKEPARAM_IsAbleToBattle(BtlPokeParam *pp);
unsigned short BTL_POKEPARAM_GetTurnCount(BtlPokeParam *pp);
int BTL_POKEPARAM_TestTurnFlag(BtlPokeParam *pp, u32 flag);
int BTL_POKEPARAM_TestContFlag(BtlPokeParam *pp, u32 flag);
u32 BTL_POKEPARAM_GetSemiInvulnerableFlag(BtlPokeParam *pp);
int BTL_POKEPARAM_IsSemiInvulnerable(BtlPokeParam *pp);
int BTL_POKEPARAM_GetHpRatioFixed(BtlPokeParam *pp);
s8 *func_021D5CB4(BtlPokeParam *pp, int stageId, u8 *minStage, u8 *maxStage);
int func_021D5D14(BtlPokeParam *pp, int stageId, int direction);
int func_021D5D50(BtlPokeParam *pp, int stageId);
int BTL_POKEPARAM_HasLoweredStatStage(BtlPokeParam *pp);
u8 BTL_POKEPARAM_RaiseStatStage(BtlPokeParam *pp, int stageId, u8 amount);
typedef enum { SICK_SLOT_FIRST, SICK_SLOT_COUNT = 36, SICK_SLOT_FORCE_UNSIGNED = 0xFFFFFFFF } SickSlotIndex;
extern int BTL_CALC_HasDefaultSickCont(int sickIndex);
extern u8 BTLV_CORE_GetSlotLow(union SickCont cont);
extern u16 BTLV_CORE_GetSlotValue(union SickCont cont);
extern union SickCont BTLV_CORE_GetZeroMasked(void);
extern int BTLV_CORE_IsSlotKindNone(union SickCont cont);
extern int BTLV_CORE_GetSlotPosition(union SickCont cont);
extern int BTLV_CORE_IsSlotKind1Index15(union SickCont cont);
extern int BTL_CALC_DivideMaxHpMin1(struct BtlPokeParam *bpp, u32 divisor);
void BTL_POKEPARAM_AdvanceHitTurn(struct BtlPokeParam *bpp);
extern void POKE_TOOL_RecalcParam(void *mon);
void BTL_EVENT_ClearClientReservedChoice(struct BtlPokeParam *bpp);
void BTL_POKEPARAM_ClearIllusion(struct BtlPokeParam *bpp);
void BTL_POKEPARAM_ClearSubstitute(struct BtlPokeParam *bpp);
extern int BTL_ID_IsBatonPassSick(u32 sickIndex);
void BTL_POKEPARAM_SetStatStage(struct BtlPokeParam *bpp, int statIndex, u8 stage);
int BTL_POKEPARAM_RaiseLoweredStatStages(struct BtlPokeParam *bpp);
void BTL_POKEPARAM_ResetStatStages(struct BtlPokeParam *bpp);
u8 BTL_POKEPARAM_GetCritStage(struct BtlPokeParam *bpp);
int BTL_POKEPARAM_AddCritStage(struct BtlPokeParam *bpp, int delta);
void BTL_POKEPARAM_SubHp(struct BtlPokeParam *bpp, u16 damage);
void BTL_POKEPARAM_AddHp(struct BtlPokeParam *bpp, u16 amount);
void BTL_POKEPARAM_ZeroHp(struct BtlPokeParam *bpp);
void BTL_POKEPARAM_SetTurnFlag(struct BtlPokeParam *bpp, u32 flagIndex);
void BTL_POKEPARAM_SetContFlag(struct BtlPokeParam *bpp, unsigned int flagIndex);
void BTL_POKEPARAM_ClearContFlag(struct BtlPokeParam *bpp, unsigned int flagIndex);
void BTL_POKEPARAM_SetSickCont(struct BtlPokeParam *bpp, int sickIndex, union SickCont cont);
int BTL_POKEPARAM_TickSickCont(struct BtlPokeParam *bpp, u32 sickIndex, union SickCont *outCont, int *outCured);
int BTL_POKEPARAM_TickSleepTurn(struct BtlPokeParam *bpp);
int BTL_POKEPARAM_TickSlot6Turn(struct BtlPokeParam *bpp);
void BTL_POKEPARAM_ClearMajorStatus(struct BtlPokeParam *bpp);
void BTL_POKEPARAM_ClearDependentSick(struct BtlPokeParam *bpp, int sickIndex);
void BTL_POKEPARAM_CureSick(struct BtlPokeParam *bpp, int sickIndex);
void BTL_POKEPARAM_CureSickBySource(struct BtlPokeParam *bpp, int sourceId);
int BTL_POKEPARAM_GetMajorStatusIndex(struct BtlPokeParam *bpp);
u16 BTL_POKEPARAM_GetSickParam(struct BtlPokeParam *bpp, int sickIndex);
u32 BTL_POKEPARAM_GetSickContRaw(struct BtlPokeParam *bpp, int sickIndex);
u8 BTL_POKEPARAM_GetSickTurn(struct BtlPokeParam *bpp, int sickIndex);
int BTL_POKEPARAM_CalcSickDamage(struct BtlPokeParam *bpp, int sickIndex);
void BTL_POKEPARAM_StartTurnThreshold(struct BtlPokeParam *bpp, u16 threshold);
void BTL_POKEPARAM_AdvanceTurn(struct BtlPokeParam *bpp);
void BTL_POKEPARAM_ClearTurnFlag(struct BtlPokeParam *bpp, u32 flagIndex);
void BTL_POKEPARAM_ResetAllEffects(struct BtlPokeParam *bpp);
void BTL_POKEPARAM_ResetEffectsOnSwitchOut(struct BtlPokeParam *bpp);
void BTL_POKEPARAM_ReloadAndResetEffects(struct BtlPokeParam *bpp);
void BTL_POKEPARAM_PassEffects(struct BtlPokeParam *dst, struct BtlPokeParam *src);
extern u8 BTLV_CORE_GetHighByte(int typePair);
extern int BTLV_CORE_GetLowByte(int typePair);
extern u32 POKE_TOOL_ChangeForm(void *pokeParam, u32 form);
extern u32 func_02018584(u16 species, u16 form, u16 level);
extern void POKE_TOOL_SetStatusCondition(void *pokeParam, u32 condition);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u8 gBtlPokeParamTransformMoves[0x38];
extern BtlPokeParamKept gBtlPokeParamTransformKept;
extern unsigned short PALANM_GetPairedCodeForFirst(int a0);
unsigned char BTL_EVENT_GetClientPartyCount(BtlPokeParam *pp);
u8 BTL_EVENT_GetClientPartySlotId(BtlPokeParam *pp, u32 slot);
void BTL_EVENT_StartClientPalAnm(BtlPokeParam *pp, int value);
void BTL_EVENT_SetClientReservedChoice(BtlPokeParam *pp, u8 pokeId, u16 key);
int BTL_EVENT_GetClientReservedChoice(BtlPokeParam *pp, u8 *pokeId, u16 *key);
u32 BTL_EVENT_HasClientReservedChoice(BtlPokeParam *pp);
void BTL_EVENT_ReleaseClientHandle(BtlPokeParam *pp);

/*
 * BTL_POKEPARAM_Create: BTL_CALC_MakeDefaultSickCont (the initial volatile-condition entry)
 * returns a one-word union by value, as in its own definition. That return
 * reserves the frame word (push r4-r6 + sub sp,#8) and stops mwcc from
 * deriving 0x272 from the hoisted 0x1f8 and 0x143 from the argument 0x9e.
 * With a u32 return every spelling of the body keeps the constant chain.
 */
BtlPokeParam *BTL_POKEPARAM_Create(PokemonParam *mon, u8 pokeId, u32 heapId)
{
    BtlPokeParam *pp;
    u32 statusCondition;

    pp = GFL_HEAP_Alloc(heapId, 0x1f8, 1, gBtlPokeparamFileName, 0xe3);
    pp->partyIndex = pokeId;
    pp->species = func_02017E1C(mon, 5, 0);
    pp->mon = mon;
    pp->hp = func_02017E1C(mon, 0xa0, 0);
    pp->maxHp = func_02017E1C(mon, 0xa1, 0);
    pp->heldItem = func_02017E1C(mon, 6, 0);
    if (pp->heldItem > 0x272) pp->heldItem = 0;
    pp->consumedItem = 0;
    pp->isTransformed = 0;
    pp->illusionMon = 0;
    pp->illusionActive = 0;
    pp->thresholdArmed = 0;
    pp->baseForm = func_02017E1C(mon, 0x6f, 0);
    pp->baseAbility = func_02017E1C(mon, 0xa, 0);
    pp->level = func_02017E1C(mon, 0x9e, 0);
    pp->genderRatio = POKE_TOOL_GetPersonalParam(pp->species, pp->baseForm, 1);
    BTL_POKEPARAM_ReloadFromMon(pp, mon, 1, 1);
    pp->moveCount = BTL_POKEPARAM_LoadMoves(pp, mon, 1);
    pp->usedMoveCount = 0;
    BTL_POKEPARAM_InitStatStages(pp->stages.stage);
    BTL_POKEPARAM_ClearSickConts(pp, 1);
    statusCondition = POKE_TOOL_GetStatusCondition(mon);
    if (statusCondition != 0) {
        pp->sickCont[statusCondition] = BTL_CALC_MakeDefaultSickCont(statusCondition);
        pp->sickTurn[statusCondition] = 0;
    }
    pp->turnThreshold = 10000;
    pp->turnsOnField = 0;
    pp->substituteHp = 0;
    pp->lastSelectedMoveId = 0;
    pp->lastUsedMoveId = 0;
    pp->lastTargetPos = 0x11;
    pp->moveStreak = 0;
    pp->storedMoveId = 0;
    pp->storedPokeId = 0x1f;
    pp->critStage = 0;
    MI_CpuFill8(pp->turnFlags, 0, sizeof(pp->turnFlags));
    MI_CpuFill8(pp->contFlags, 0, sizeof(pp->contFlags));
    BTL_POKEPARAM_ClearHitHistory(pp);
    func_021D6DC4(pp);
    return pp;
}

/* BTL_POKEPARAM_ReloadFromMon: withHp also reloads hp and maxHp, withAbility reloads the stats, ability and form. */
void BTL_POKEPARAM_ReloadFromMon(BtlPokeParam *pp, PokemonParam *mon, u32 withHp, u32 withAbility)
{
    if (withHp != 0) {
        pp->hp = func_02017E1C(mon, 0xa0, 0);
        pp->maxHp = func_02017E1C(mon, 0xa1, 0);
    }
    pp->exp = func_02017E1C(mon, 8, 0);
    BTL_POKEPARAM_LoadStats(pp, mon, withAbility);
    if (withAbility != 0) {
        pp->ability = func_02017E1C(mon, 0xa, 0);
    }
    pp->form = func_02017E1C(mon, 0x6f, 0);
    pp->weight = POKE_TOOL_GetPersonalParam(pp->species, pp->form, 0x26);
    if (pp->weight < 1) {
        pp->weight = 1;
    }
}

/* BTL_POKEPARAM_LoadMoves: reads the four moves from the Pokemon, returns how many exist. */
int BTL_POKEPARAM_LoadMoves(BtlPokeParam *pp, PokemonParam *mon, int reset)
{
    u8 wasDecoded = POKE_TOOL_DecodePartyParam(mon);
    u32 moveCount = 0;
    u32 i;
    if (reset) {
        for (i = 0; i < 4; i++) {
            pp->moves[i].cur.counterLow = 0;
            pp->moves[i].cur.counterHigh = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        if (BTL_POKEPARAM_LoadMoveInfo(&pp->moves[i].cur, mon, i)) moveCount++;
    }
    if (reset) {
        for (i = 0; i < 4; i++) {
            pp->moves[i].halves[3] = pp->moves[i].halves[0];
            pp->moves[i].halves[4] = pp->moves[i].halves[1];
            pp->moves[i].halves[5] = pp->moves[i].halves[2];
            pp->moves[i].savedActive = 1;
        }
    }
    POKE_TOOL_EncodePartyParam(mon, wasDecoded);
    return moveCount;
}

/* BTL_POKEPARAM_SaveMovesToMon */
void BTL_POKEPARAM_SaveMovesToMon(BtlPokeParam *pp)
{
    PokemonParam *mon = pp->mon;
    u32 i;

    for (i = 0; i < 4; i++) {
        func_020181F4(mon, pp->moves[i].cur.id, (u8)i);
        POKE_TOOL_SetPartyValue(mon, 0x3a + i, pp->moves[i].cur.pp);
        POKE_TOOL_SetPartyValue(mon, 0x3e + i, pp->moves[i].cur.ppUp);
    }
}

/* BTL_POKEPARAM_SyncMovesFromMon */
void BTL_POKEPARAM_SyncMovesFromMon(BtlPokeParam *pp)
{
    PokemonParam *mon = pp->mon;
    u32 i;
    pp->moveCount = 0;
    for (i = 0; i < 4; i++) {
        if (BTL_POKEPARAM_LoadMoveInfo(&pp->moves[i].cur, mon, i)) pp->moveCount++;
        if (pp->moves[i].savedActive != 0) {
            pp->moves[i].halves[3] = pp->moves[i].halves[0];
            pp->moves[i].halves[4] = pp->moves[i].halves[1];
            pp->moves[i].halves[5] = pp->moves[i].halves[2];
        }
    }
}

/* BTL_POKEPARAM_ResetBattleMoves: copies the real moves over the battle moves and relinks them. */
void BTL_POKEPARAM_ResetBattleMoves(BtlPokeParam *pp)
{
    u32 i;
    pp->moveCount = 0;
    for (i = 0; i < 4; i++) {
        pp->moves[i].halves[3] = pp->moves[i].halves[0];
        pp->moves[i].halves[4] = pp->moves[i].halves[1];
        pp->moves[i].halves[5] = pp->moves[i].halves[2];
        if (pp->moves[i].halves[3] != 0) pp->moveCount++;
        pp->moves[i].savedActive = 1;
    }
}

/*
 * BTL_POKEPARAM_ClearMoveUsedFlags: `info &= ~0xf` on a u8 narrowed the mask
 * to 0xf0 and used ands; the image keeps a 32-bit intermediate and bics with
 * 0xf. Leaf of 8 instructions: the battle view first, then the real view.
 */
void BTL_POKEPARAM_ClearMoveUsedFlags(struct BattleMoveSlot *slot)
{
    u32 flags;
    flags = slot->saved.counters;
    flags &= ~0xf;
    slot->saved.counters = flags;
    flags = slot->cur.counters;
    flags &= ~0xf;
    slot->cur.counters = flags;
}

/* BTL_POKEPARAM_ReplaceMoveSlot: toReal sets the real move (and the battle copy while linked), else only the battle move. */
void BTL_POKEPARAM_ReplaceMoveSlot(struct BattleMoveSlot *slot, u32 moveId, u32 ppCap, u32 toReal)
{
    if (toReal != 0) {
        BTL_POKEPARAM_SetMoveInfo(&slot->cur, moveId, ppCap);
        if (slot->savedActive != 0) {
            slot->halves[3] = slot->halves[0];
            slot->halves[4] = slot->halves[1];
            slot->halves[5] = slot->halves[2];
        }
    } else {
        BTL_POKEPARAM_SetMoveInfo(&slot->saved, moveId, ppCap);
        slot->savedActive = 0;
    }
}

/* BTL_POKEPARAM_SetMoveInfo: full PP from the move table, limited to ppCap when ppCap is nonzero. */
void BTL_POKEPARAM_SetMoveInfo(struct MoveInfo *info, u32 moveId, u32 ppCap)
{
    info->id = moveId;
    info->counterLow = 0;
    info->counterHigh = 0;
    if (moveId != 0) info->ppMax = WAZA_TOOL_GetMaxPP(moveId, 0);
    else info->ppMax = 0;
    if (ppCap != 0 && info->ppMax > ppCap) info->ppMax = ppCap;
    info->pp = info->ppMax;
}

/* BTL_POKEPARAM_LoadMoveInfo: reads one move slot from the Pokemon, returns 1 when the slot holds a move. */
int BTL_POKEPARAM_LoadMoveInfo(struct MoveInfo *info, PokemonParam *mon, u8 slotIndex)
{
    int hasMove = 1;
    u16 moveId = func_02017E1C(mon, slotIndex + 0x36, 0);
    if (info->id != moveId) {
        info->counterLow = 0;
        info->counterHigh = 0;
    }
    info->id = moveId;
    if (info->id != 0) {
        info->pp = func_02017E1C(mon, slotIndex + 0x3a, 0);
        info->ppMax = func_02017E1C(mon, slotIndex + 0x42, 0);
        info->ppUp = func_02017E1C(mon, slotIndex + 0x3e, 0);
    } else {
        hasMove = 0;
        info->pp = 0;
        info->ppMax = 0;
        info->ppUp = 0;
    }
    return hasMove;
}

/* BTL_POKEPARAM_LoadStats: withTypes also reloads both types. */
void BTL_POKEPARAM_LoadStats(BtlPokeParam *pp, PokemonParam *mon, u32 withTypes)
{
    if (withTypes) {
        pp->type1 = func_02017E1C(mon, 0xae, 0);
        pp->type2 = func_02017E1C(mon, 0xaf, 0);
    }
    pp->gender = POKE_TOOL_GetGender(mon);
    pp->attack = func_02017E1C(mon, 0xa2, 0);
    pp->defense = func_02017E1C(mon, 0xa3, 0);
    pp->spAttack = func_02017E1C(mon, 0xa5, 0);
    pp->spDefense = func_02017E1C(mon, 0xa6, 0);
    pp->speed = func_02017E1C(mon, 0xa4, 0);
}

/* BTL_POKEPARAM_RestoreIfNeeded */
void BTL_POKEPARAM_RestoreIfNeeded(BtlPokeParam *pp)
{
    if (pp->isTransformed != 0) {
        BTL_POKEPARAM_ReloadFromMon(pp, pp->mon, 0, 1);
        BTL_POKEPARAM_ResetBattleMoves(pp);
        pp->isTransformed = 0;
    }
}

/* BTL_POKEPARAM_ResetMoveHistory */
void BTL_POKEPARAM_ResetMoveHistory(BtlPokeParam *pp)
{
    u32 i;
    for (i = 0; i < 4; i++) BTL_POKEPARAM_ClearMoveUsedFlags(&pp->moves[i]);
    pp->lastSelectedMoveId = 0;
    pp->lastUsedMoveId = 0;
    pp->lastTargetPos = 0x11;
    pp->moveStreak = 0;
}

/* BTL_POKEPARAM_ClearMoveFlags */
void BTL_POKEPARAM_ClearMoveFlags(BtlPokeParam *pp)
{
    u32 i;
    for (i = 0; i < 5; i++) pp->counters[i] = 0;
}

/* BTL_POKEPARAM_Delete: tail-call thunk to the heap release function. */
void BTL_POKEPARAM_Delete(BtlPokeParam *pp)
{
    func_020307B0(pp);
}

/* BTL_POKEPARAM_InitStatStages: tail-call thunk to BTL_POKEPARAM_SetNeutralStatStages. */
void BTL_POKEPARAM_InitStatStages(unsigned char *stages)
{
    BTL_POKEPARAM_SetNeutralStatStages(stages);
}

/* BTL_POKEPARAM_SetNeutralStatStages: writes 6 into the seven stage bytes. */
void BTL_POKEPARAM_SetNeutralStatStages(unsigned char *stages)
{
    stages[0] = 6;
    stages[1] = 6;
    stages[2] = 6;
    stages[3] = 6;
    stages[4] = 6;
    stages[5] = 6;
    stages[6] = 6;
}

/* BTL_POKEPARAM_RaiseLowStatStagesInArray: returns 1 when any stage changed. */
int BTL_POKEPARAM_RaiseLowStatStagesInArray(signed char *stages)
{
    int changed = 0;
    int i = 0;
    if (stages[i] < 6) { stages[i] = 6; changed = 1; }
    i = 1;
    if (stages[i] < 6) { stages[i] = 6; changed = 1; }
    i = 2;
    if (stages[i] < 6) { stages[i] = 6; changed = 1; }
    i = 3;
    if (stages[i] < 6) { stages[i] = 6; changed = 1; }
    i = 4;
    if (stages[i] < 6) { stages[i] = 6; changed = 1; }
    i = 5;
    if (stages[i] < 6) { stages[i] = 6; changed = 1; }
    i = 6;
    if (stages[i] < 6) { stages[i] = 6; changed = 1; }
    return changed;
}

/* BTL_POKEPARAM_GetPokeId */
u8 BTL_POKEPARAM_GetPokeId(BtlPokeParam *pp) { return pp->partyIndex; }

/* BTL_POKEPARAM_GetSpecies */
u16 BTL_POKEPARAM_GetSpecies(BtlPokeParam *pp) { return pp->species; }

/* BTL_POKEPARAM_GetMoveCount: leaf of 4 instructions (the offset 0x140 is built with movs/lsls). */
u8 BTL_POKEPARAM_GetMoveCount(BtlPokeParam *pp) { return pp->moveCount; }

/* BTL_POKEPARAM_CountRealMoves: counts the leading real moves that exist. */
u8 func_021D5450(BtlPokeParam *pp)
{
    u32 count;
    u32 i;
    i = 0;
    count = 0;
    for (; i < 4; i++) {
        if (pp->moves[i].cur.id == 0) break;
        count++;
    }
    return count;
}

/*
 * BTL_POKEPARAM_CountUsedMoves: counts the battle moves marked as used since
 * switch-in. stand-in: volatile, because the image re-reads moveCount as the
 * loop bound (at 021D54A6); the plain field read, in for, while and u32-index
 * forms, compiles 4 bytes short.
 */
u8 func_021D5478(BtlPokeParam *pp)
{
    u8 count;
    u8 i;
    i = 0;
    count = 0;
    for (; i < *(volatile u8 *)&pp->moveCount; i++) {
        if (pp->moves[i].saved.counterLow != 0) count++;
    }
    return count;
}

/* BTL_POKEPARAM_GetUsedMoveTotal: reads a byte at +0x143 (offset in the literal pool). */
u8 BTL_POKEPARAM_GetUsedMoveTotal(BtlPokeParam *pp)
{
    return pp->usedMoveCount;
}

/*
 * BTL_POKEPARAM_GetMoveId: the halfword is the first member of a 14-byte
 * record in the array at +0x10a; the image folds the constant 0x10a with the
 * stride (adds r2,#0xfc), it is not a +0xa field.
 */
u16 BTL_POKEPARAM_GetMoveId(BtlPokeParam *pp, int slot)
{
    return pp->moves[slot].saved.id;
}

/* BTL_POKEPARAM_GetRealMoveId */
u32 BTL_POKEPARAM_GetRealMoveId(BtlPokeParam *pp, u8 slot) { return pp->moves[slot].cur.id; }

/*
 * BTL_POKEPARAM_GetMoveUsedFlag: the image extracts with lsls #0x1c / lsrs
 * #0x1c, a 4-bit unsigned bitfield read; neither `& 0xf` nor the shift pair
 * in C reproduces it (both narrow to a mask).
 */
u32 BTL_POKEPARAM_GetMoveUsedFlag(BtlPokeParam *pp, u32 slot)
{
    return pp->moves[slot].saved.counterLow;
}

/* BTL_POKEPARAM_CopyMoves */
void func_021D54F4(BtlPokeParam *src, BtlPokeParam *dst)
{
    u32 i;
    for (i = 0; i < 4; i++) dst->moves[i] = src->moves[i];
    dst->moveCount = src->moveCount;
}

/* BTL_POKEPARAM_GetMovePP: returns the battle move id and writes its PP and PP maximum. */
u16 func_021D5528(BtlPokeParam *pp, u8 slot, u8 *ppOut, u8 *ppMaxOut)
{
    *ppOut = pp->moves[slot].saved.pp;
    *ppMaxOut = pp->moves[slot].saved.ppMax;
    return pp->moves[slot].saved.id;
}

/* BTL_POKEPARAM_GetMovePPLost */
u8 BTL_POKEPARAM_GetMovePPLost(BtlPokeParam *pp, u8 slot) { return pp->moves[slot].saved.ppMax - pp->moves[slot].saved.pp; }

/* BTL_POKEPARAM_GetRealMovePPLost */
u8 BTL_POKEPARAM_GetRealMovePPLost(BtlPokeParam *pp, u32 slot) { return pp->moves[slot].cur.ppMax - pp->moves[slot].cur.pp; }

/* BTL_POKEPARAM_GetMovePPChecked: 0 for a slot past the move count. */
u8 BTL_POKEPARAM_GetMovePPChecked(BtlPokeParam *pp, u32 slot)
{
    if (slot < pp->moveCount) return pp->moves[slot].saved.pp;
    return 0;
}

/* BTL_POKEPARAM_GetMovePPById: PP of the battle move with this id, 0 when absent. stand-in: volatile re-read of moveCount as in BTL_POKEPARAM_CountUsedMoves (plain read is 4 bytes short). */
int BTL_POKEPARAM_GetMovePPById(BtlPokeParam *pp, int moveId)
{
    u32 i;
    for (i = 0; i < *(volatile u8 *)&pp->moveCount; i++) {
        if (moveId == pp->moves[i].saved.id) return pp->moves[i].saved.pp;
    }
    return 0;
}

/*
 * BTL_POKEPARAM_IsMovePPFull: the index is added in each arm of the view
 * select, so the sum is formed once and shared by the halfword and byte loads.
 */
int BTL_POKEPARAM_IsMovePPFull(BtlPokeParam *pp, int slot, int useReal)
{
    struct MoveInfo *info;
    if (useReal) info = &pp->moves[slot].cur; else info = &pp->moves[slot].saved;
    if (info->id != 0 && info->pp == info->ppMax) return 1;
    return 0;
}

/* BTL_POKEPARAM_DecrementMovePP: subtracts down to 0; a linked slot also updates the real move and the Pokemon. */
void BTL_POKEPARAM_DecrementMovePP(BtlPokeParam *pp, int slot, u8 amount)
{
    if (pp->moves[slot].saved.pp >= amount) pp->moves[slot].saved.pp -= amount;
    else pp->moves[slot].saved.pp = 0;
    if (pp->moves[slot].savedActive != 0) {
        pp->moves[slot].cur.pp = pp->moves[slot].saved.pp;
        POKE_TOOL_SetPartyValue(pp->mon, slot + 0x3A, pp->moves[slot].cur.pp);
    }
}

/* BTL_POKEPARAM_DecrementRealMovePP: only for an unlinked slot (a linked slot went through the battle move). */
void BTL_POKEPARAM_DecrementRealMovePP(BtlPokeParam *pp, u32 slot, u32 amount)
{
    int newPp;
    if (pp->moves[slot].savedActive == 0) {
        newPp = (int)((u32)pp->moves[slot].cur.pp - amount);
        if (newPp < 0) newPp = 0;
        pp->moves[slot].cur.pp = newPp;
        POKE_TOOL_SetPartyValue(pp->mon, slot + 0x3a, pp->moves[slot].cur.pp);
    }
}

/* BTL_POKEPARAM_RestoreMovePP: adds up to ppMax, returns the battle move id. */
u16 BTL_POKEPARAM_RestoreMovePP(BtlPokeParam *pp, u32 slot, u8 amount)
{
    struct BattleMoveSlot *moveSlot = &pp->moves[slot];
    moveSlot->saved.pp += amount;
    if (moveSlot->saved.pp > moveSlot->saved.ppMax) moveSlot->saved.pp = moveSlot->saved.ppMax;
    if (moveSlot->savedActive) moveSlot->cur.pp = moveSlot->saved.pp;
    return moveSlot->saved.id;
}

/* BTL_POKEPARAM_RestoreRealMovePP */
u16 BTL_POKEPARAM_RestoreRealMovePP(BtlPokeParam *pp, u32 slot, u8 amount)
{
    struct BattleMoveSlot *moveSlot = &pp->moves[slot];
    moveSlot->cur.pp += amount;
    if (moveSlot->cur.pp > moveSlot->cur.ppMax) moveSlot->cur.pp = moveSlot->cur.ppMax;
    if (moveSlot->savedActive) moveSlot->saved.pp = moveSlot->cur.pp;
    return moveSlot->cur.id;
}

/* BTL_POKEPARAM_MarkMoveUsed */
void BTL_POKEPARAM_MarkMoveUsed(BtlPokeParam *pp, int slot)
{
    struct BattleMoveSlot *moveSlot = &pp->moves[slot];
    if (moveSlot->saved.counterHigh == 0) {
        moveSlot->saved.counterHigh = 1;
        pp->usedMoveCount++;
    }
    moveSlot->saved.counterLow = 1;
    if (moveSlot->savedActive != 0) {
        moveSlot->cur.counterLow = moveSlot->saved.counterLow;
        moveSlot->cur.counterHigh = moveSlot->saved.counterHigh;
    }
}

/* BTL_POKEPARAM_ReplaceMove */
void BTL_POKEPARAM_ReplaceMove(BtlPokeParam *pp, u8 slot, u16 moveId, u8 ppCap, u32 toReal)
{ BTL_POKEPARAM_ReplaceMoveSlot(&pp->moves[slot], moveId, ppCap, toReal); }

/* BTL_POKEPARAM_HasMove */
int BTL_POKEPARAM_HasMove(BtlPokeParam *pp, u16 moveId)
{ u32 i; for(i=0;i<4;i++) if(moveId == pp->moves[i].saved.id) return 1; return 0; }

/* BTL_POKEPARAM_FindMoveSlot: 4 when the move is absent or the id is 0. */
u8 BTL_POKEPARAM_FindMoveSlot(BtlPokeParam *pp, u16 moveId)
{
    u32 i;
    if (moveId != 0) {
        for (i = 0; i < 4; i++) {
            if (moveId == pp->moves[i].saved.id) return (u8)i;
        }
    }
    return 4;
}

/* BTL_POKEPARAM_GetTypes: both types; a flying type is hidden while condition 0x18 holds, and a hidden type takes the other one. */
void BTL_POKEPARAM_GetTypes(BtlPokeParam *pp, u8 *type1, u8 *type2)
{
    int typeHidden = BTL_POKEPARAM_HasSick(pp, 0x18);
    u8 type;
    type = pp->type1;
    if (type == 2 && typeHidden) *type1 = 0x11;
    else *type1 = type;
    type = pp->type2;
    if (type == 2 && typeHidden) *type2 = 0x11;
    else *type2 = type;
    if (*type1 == 0x11) {
        if (*type2 == 0x11) *type2 = 0;
        *type1 = *type2;
    } else if (*type2 == 0x11) {
        *type2 = *type1;
    }
}

/* BTL_POKEPARAM_GetTypePair */
u16 BTL_POKEPARAM_GetTypePair(BtlPokeParam *pp)
{
    u8 type1;
    u8 type2;
    BTL_POKEPARAM_GetTypes(pp, &type1, &type2);
    return BTLV_CORE_PackBytes(type1, type2);
}

/* BTL_POKEPARAM_HasType */
int BTL_POKEPARAM_HasType(BtlPokeParam *pp, int type)
{
    u8 type1;
    u8 type2;
    if (type != 0x11) {
        BTL_POKEPARAM_GetTypes(pp, &type1, &type2);
        if (type1 == type || type2 == type) return 1;
    }
    return 0;
}

/* BTL_POKEPARAM_GetMon */
PokemonParam *BTL_POKEPARAM_GetMon(BtlPokeParam *pp) { return pp->mon; }

/* BTL_POKEPARAM_SetFakeMon: leaf of 6 instructions. */
void BTL_POKEPARAM_SetFakeMon(BtlPokeParam *pp, PokemonParam *fakeMon)
{
    pp->illusionMon = fakeMon;
    pp->illusionActive = 1;
}

/* BTL_POKEPARAM_ClearFakeMon */
void BTL_POKEPARAM_ClearFakeMon(BtlPokeParam *pp) { pp->illusionMon = 0; pp->illusionActive = 0; }

/* BTL_POKEPARAM_GetDisplayMon */
PokemonParam *BTL_POKEPARAM_GetDisplayMon(BtlPokeParam *pp) { if (pp->illusionMon && pp->illusionActive) return pp->illusionMon; return pp->mon; }

/* BTL_POKEPARAM_RemapStatId: with the swap condition 6 active, defense (9) and spDefense (11) trade places. */
int BTL_POKEPARAM_RemapStatId(BtlPokeParam *pp, int valueId)
{
    switch(valueId) {
    case 9: if (BTL_FIELD_GetStaticSlotObject(6)) valueId = 11; break;
    case 11: if (BTL_FIELD_GetStaticSlotObject(6)) valueId = 9; break;
    }
    return valueId;
}

/* BTL_POKEPARAM_GetStatRaw: a stat without its stage (ids 8 to 12), 6 for ids 6 and 7, else GetValue. */
int func_021D58A8(BtlPokeParam *pp, int valueId)
{
    int id = BTL_POKEPARAM_RemapStatId(pp, valueId);
    switch (id) {
    case 8:
        return pp->attack;
    case 9:
        return pp->defense;
    case 10:
        return pp->spAttack;
    case 11:
        return pp->spDefense;
    case 12:
        return pp->speed;
    case 6:
        return 6;
    case 7:
        return 6;
    }
    return func_021D59B4(pp, id);
}

/* BTL_POKEPARAM_ReadStatsFromMon: writes maxHp, attack, defense, spAttack, spDefense, speed to stats[1..6]. */
void BTL_POKEPARAM_ReadStatsFromMon(PokemonParam **monPtr, u16 *stats)
{
    u8 wasDecoded = POKE_TOOL_DecodePartyParam(*monPtr);
    stats[1] = func_02017E1C(*monPtr, 0xa1, 0);
    stats[2] = func_02017E1C(*monPtr, 0xa2, 0);
    stats[3] = func_02017E1C(*monPtr, 0xa3, 0);
    stats[4] = func_02017E1C(*monPtr, 0xa5, 0);
    stats[5] = func_02017E1C(*monPtr, 0xa6, 0);
    stats[6] = func_02017E1C(*monPtr, 0xa4, 0);
    POKE_TOOL_EncodePartyParam(*monPtr, wasDecoded);
}

/* BTL_POKEPARAM_SetStat */
void BTL_POKEPARAM_SetStat(BtlPokeParam *pp, int valueId, u16 value)
{
    switch (BTL_POKEPARAM_RemapStatId(pp, valueId)) {
    case 8:
        pp->attack = value;
        break;
    case 9:
        pp->defense = value;
        break;
    case 10:
        pp->spAttack = value;
        break;
    case 11:
        pp->spDefense = value;
        break;
    case 12:
        pp->speed = value;
        break;
    }
}

/*
 * BTL_POKEPARAM_GetValue: the generic accessor. Ids 1 to 7 are the stat
 * stages, 8 to 12 the stats with their stage applied, 13 hp, 14 maxHp,
 * 15 level, 16 base-ability slot, 17 ability (0 while condition 0x10 holds),
 * 18 gender, 19 base form, 20 exp, 21 the base attack stat.
 * lever: the switch value stays in r1 and is the hidden second argument of
 * BTL_POKEPARAM_GetStatRaw; case 17 falls through into case 16.
 */
int func_021D59B4(BtlPokeParam *pp, int valueId)
{
    int id = BTL_POKEPARAM_RemapStatId(pp, valueId);

    switch (id) {
    case 8:
        return BTL_CALC_ApplyStatStage(func_021D58A8(pp, id), *(u8 *)&pp->stages.attack);
    case 9:
        return BTL_CALC_ApplyStatStage(func_021D58A8(pp, id), *(u8 *)&pp->stages.defense);
    case 10:
        return BTL_CALC_ApplyStatStage(func_021D58A8(pp, id), *(u8 *)&pp->stages.spAttack);
    case 11:
        return BTL_CALC_ApplyStatStage(func_021D58A8(pp, id), *(u8 *)&pp->stages.spDefense);
    case 12:
        return BTL_CALC_ApplyStatStage(func_021D58A8(pp, id), pp->stages.speed);
    case 1:
        return pp->stages.attack;
    case 2:
        return pp->stages.defense;
    case 3:
        return pp->stages.spAttack;
    case 4:
        return pp->stages.spDefense;
    case 5:
        return *(s8 *)&pp->stages.speed;
    case 6:
        return pp->stages.accuracy;
    case 7:
        return pp->stages.evasion;
    case 15:
        return pp->level;
    case 18:
        return pp->gender;
    case 13:
        return pp->hp;
    case 14:
        return pp->maxHp;
    case 21:
        return pp->genderRatio;
    case 17:
        if (BTL_POKEPARAM_HasSick(pp, 0x10) != 0)
            return 0;
    case 16:
        return pp->ability;
    case 19:
        return pp->form;
    case 20:
        return pp->exp;
    case 0:
        break;
    }
    return 0;
}

/* BTL_POKEPARAM_GetStatForCrit: the raw stat when the stage works against the attacker, else the staged stat. */
int BTL_POKEPARAM_GetStatForCrit(BtlPokeParam *pp, int valueId)
{
    int useRaw = 0;
    switch (BTL_POKEPARAM_RemapStatId(pp, valueId)) {
    case 8:
        if (pp->stages.attack < 6) useRaw = 1;
        break;
    case 10:
        if (pp->stages.spAttack < 6) useRaw = 1;
        break;
    case 9:
        if (pp->stages.defense > 6) useRaw = 1;
        break;
    case 11:
        if (pp->stages.spDefense > 6) useRaw = 1;
        break;
    }
    if (useRaw) return func_021D58A8(pp, valueId);
    return func_021D59B4(pp, valueId);
}

/* BTL_POKEPARAM_GetItem */
u16 BTL_POKEPARAM_GetItem(BtlPokeParam *pp) { return pp->heldItem; }

/* BTL_POKEPARAM_SetItem */
void BTL_POKEPARAM_SetItem(BtlPokeParam *pp, u16 item) { pp->heldItem = item; }

/* BTL_POKEPARAM_IsHpFull */
int BTL_POKEPARAM_IsHpFull(BtlPokeParam *pp)
{
    if (func_021D59B4(pp, 0xd) == func_021D59B4(pp, 0xe)) return 1;
    return 0;
}

/* BTL_POKEPARAM_IsFainted */
int BTL_POKEPARAM_IsFainted(BtlPokeParam *pp)
{
    if (func_021D59B4(pp, 13) == 0) return 1;
    return 0;
}

/* BTL_POKEPARAM_IsAbleToBattle: 0 for an egg or a fainted Pokemon. */
int BTL_POKEPARAM_IsAbleToBattle(BtlPokeParam *pp)
{
    int ok;
    ok = 0;
    if (func_02017E1C(pp->mon, 0x4c, 0)) return ok;
    if (BTL_POKEPARAM_IsFainted(pp) == 0) ok = 1;
    return ok;
}

/* BTL_POKEPARAM_GetTurnCount: unlabelled leaf hidden in a .word run. */
unsigned short BTL_POKEPARAM_GetTurnCount(BtlPokeParam *pp)
{
    return pp->turnsOnField;
}

/* BTL_POKEPARAM_TestTurnFlag */
int BTL_POKEPARAM_TestTurnFlag(BtlPokeParam *pp, u32 flag)
{
    return (pp->turnFlags[(u8)(flag >> 3)] & (u8)(1 << (flag & 7))) ? 1 : 0;
}

/* BTL_POKEPARAM_TestContFlag */
int BTL_POKEPARAM_TestContFlag(BtlPokeParam *pp, u32 flag)
{
    return (pp->contFlags[(u8)(flag >> 3)] & (u8)(1 << (flag & 7))) ? 1 : 0;
}

/* BTL_POKEPARAM_GetSemiInvulnerableFlag: the first of four table flags that is set, 0x10 when none. */
u32 BTL_POKEPARAM_GetSemiInvulnerableFlag(BtlPokeParam *pp)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        if (BTL_POKEPARAM_TestContFlag(pp, gSemiInvulnerableContFlags[i])) return gSemiInvulnerableContFlags[i];
    }
    return 0x10;
}

/* BTL_POKEPARAM_IsSemiInvulnerable */
int BTL_POKEPARAM_IsSemiInvulnerable(BtlPokeParam *pp)
{
    if (BTL_POKEPARAM_GetSemiInvulnerableFlag(pp) != 16) return 1;
    return 0;
}

/* BTL_POKEPARAM_GetHpRatioFixed: hp * 100 / maxHp as a 20.12 fixed-point value, rounded half away from zero. */
int BTL_POKEPARAM_GetHpRatioFixed(BtlPokeParam *pp)
{
    double ratio = (double)(100 * pp->hp) / (double)pp->maxHp;
    double scaled;
    if (ratio > 0)
        scaled = 4096.0 * ratio + 0.5;
    else
        scaled = 4096.0 * ratio - 0.5;
    return (int)scaled;
}

/* BTL_POKEPARAM_GetStatStagePtr: the stage byte for stageId 1 to 7 (NULL otherwise); the range is 0 to 12. */
s8 *func_021D5CB4(BtlPokeParam *pp, int stageId, u8 *minStage, u8 *maxStage)
{
    *minStage = 0;
    *maxStage = 12;
    switch (stageId) {
    case 1: return &pp->stages.attack;
    case 2: return &pp->stages.defense;
    case 3: return &pp->stages.spAttack;
    case 4: return &pp->stages.spDefense;
    case 5: return (s8 *)&pp->stages.speed;
    case 6: return &pp->stages.accuracy;
    case 7: return &pp->stages.evasion;
    default: return 0;
    }
}

/*
 * BTL_POKEPARAM_CanChangeStatStage: direction above 0 asks for a rise.
 * extent: final two bytes are zero alignment padding.
 * evidence: BTL_POKEPARAM_GetStatStagePtr unconditionally writes both outputs
 * before its switch.
 */
int func_021D5D14(BtlPokeParam *pp, int stageId, int direction)
{
    s8 minStage;
    s8 maxStage;
    s8 *stage;
    stage = func_021D5CB4(pp, stageId, (u8 *)&minStage, (u8 *)&maxStage);
    if (direction > 0) return *stage < maxStage;
    else return *stage > minStage;
}

/*
 * BTL_POKEPARAM_GetStatStageRoom: how far the stage can still rise.
 * lever: minStage declared before maxStage places maxStage at stack offset zero.
 * evidence: BTL_POKEPARAM_GetStatStagePtr unconditionally writes both outputs
 * before its switch.
 */
int func_021D5D50(BtlPokeParam *pp, int stageId)
{
    s8 minStage;
    s8 maxStage;
    s8 *stage;
    stage = func_021D5CB4(pp, stageId, (u8 *)&minStage, (u8 *)&maxStage);
    return maxStage - *stage;
}

/* BTL_POKEPARAM_HasLoweredStatStage */
int BTL_POKEPARAM_HasLoweredStatStage(BtlPokeParam *pp)
{
    if (pp->stages.attack < 6) return 1;
    if (pp->stages.defense < 6) return 1;
    if (pp->stages.spAttack < 6) return 1;
    if (pp->stages.spDefense < 6) return 1;
    if (*(s8 *)&pp->stages.speed < 6) return 1;
    if (pp->stages.accuracy < 6) return 1;
    if (pp->stages.evasion < 6) return 1;
    return 0;
}

/* BTL_POKEPARAM_RaiseStatStage: raises up to 12, returns the amount applied. */
u8 BTL_POKEPARAM_RaiseStatStage(BtlPokeParam *pp, int stageId, u8 amount)
{
    s8 *stage;
    int current;
    switch (stageId) {
    case 1: stage = &pp->stages.attack; break;
    case 2: stage = &pp->stages.defense; break;
    case 3: stage = &pp->stages.spAttack; break;
    case 4: stage = &pp->stages.spDefense; break;
    case 5: stage = (s8 *)&pp->stages.speed; break;
    case 6: stage = &pp->stages.accuracy; break;
    case 7: stage = &pp->stages.evasion; break;
    default: return 0;
    }
    current = stage[0];
    if (current < 12) {
        if (current + amount > 12) amount = 12 - current;
        stage[0] += amount;
        return amount;
    }
    return 0;
}

/*
 * Lower one stat stage of a battle Pokemon (1 attack, 2 defense, 3 special
 * attack, 4 special defense, 5 speed, 6 accuracy, 7 evasion). Stages run
 * 0..12 with 6 as neutral. Returns the number of steps actually applied.
 * Counterpart of BTL_POKEPARAM_RaiseStatStage (raise), which this function follows in
 * the original file.
 */
u8 BTL_POKEPARAM_LowerStatStage(struct BtlPokeParam *pokeParam, int statIndex, u8 steps)
{
    s8 *stage;
    int current;

    switch (statIndex) {
    case 1: stage = &pokeParam->stages.attack; break;
    case 2: stage = &pokeParam->stages.defense; break;
    case 3: stage = &pokeParam->stages.spAttack; break;
    case 4: stage = &pokeParam->stages.spDefense; break;
    case 5: stage = (s8 *)&pokeParam->stages.speed; break;
    case 6: stage = &pokeParam->stages.accuracy; break;
    case 7: stage = &pokeParam->stages.evasion; break;
    default: return 0;
    }
    current = stage[0];
    if (current > 0) {
        if (current - steps < 0) steps = current;
        stage[0] -= steps;
        return steps;
    }
    return 0;
}

/* Set one stat stage (index 1..7), only when the new stage is at most 12. */
void BTL_POKEPARAM_SetStatStage(struct BtlPokeParam *bpp, int statIndex, u8 stage)
{
    u8 *slot;
    switch (statIndex) {
    case 1: slot = &bpp->stages.stage[0]; break;
    case 2: slot = &bpp->stages.stage[1]; break;
    case 3: slot = &bpp->stages.stage[2]; break;
    case 4: slot = &bpp->stages.stage[3]; break;
    case 5: slot = &bpp->stages.stage[4]; break;
    case 6: slot = &bpp->stages.stage[5]; break;
    case 7: slot = &bpp->stages.stage[6]; break;
    default: return;
    }
    if (stage <= 12) slot[0] = stage;
}

/* Raise every lowered stat stage back to neutral; nonzero if any changed. */
int BTL_POKEPARAM_RaiseLoweredStatStages(struct BtlPokeParam *bpp)
{
    return BTL_POKEPARAM_RaiseLowStatStagesInArray((signed char *)bpp->stages.stage);
}

/* Reset all seven stat stages to neutral. */
void BTL_POKEPARAM_ResetStatStages(struct BtlPokeParam *bpp)
{
    BTL_POKEPARAM_SetNeutralStatStages((unsigned char *)bpp->stages.stage);
}

/* Critical hit stage, 0 to 4; the condition with flag index 9 adds 2. */
u8 BTL_POKEPARAM_GetCritStage(struct BtlPokeParam *bpp)
{
    u8 stage;
    stage = bpp->critStage;
    if (BTL_POKEPARAM_TestContFlag(bpp, 9)) {
        stage += 2;
        if (stage > 4) stage = 4;
    }
    return stage;
}

/*
 * Change the critical hit stage by delta, clamped to 0..4. Returns 1 when the
 * stage could move.
 * Lever: the clamp at the bottom stores the field in each arm
 * (`if (p->f > k) p->f = p->f - (u8)k; else p->f = 0;`). A local assigned in the arms
 * and stored once, or a ternary, keeps k out of r4 (no push {r3,r4}; 8 bytes short).
 * `n * 0xffffffff` keeps the mvns/muls (a-multiply-by-minus-one-is-strength-reduced-but-by-0xffffffff-is-not.md).
 */
int BTL_POKEPARAM_AddCritStage(struct BtlPokeParam *bpp, int delta)
{
    int decrement;

    if (delta > 0) {
        if (bpp->critStage < 4) {
            bpp->critStage = bpp->critStage + (u8)delta;
            if (bpp->critStage > 4) bpp->critStage = 4;
            return 1;
        }
    } else {
        decrement = delta * 0xffffffff;
        if (bpp->critStage != 0) {
            if (bpp->critStage > decrement) bpp->critStage = bpp->critStage - (u8)decrement; else bpp->critStage = 0;
            return 1;
        }
    }
    return 0;
}

/*
 * Subtract damage from the current HP, stopping at 0.
 * lever: plain subtraction avoids compound-assignment operand narrowing.
 */
void BTL_POKEPARAM_SubHp(struct BtlPokeParam *bpp, u16 damage)
{
    if (bpp->hp > damage) {
        bpp->hp = bpp->hp - damage;
        return;
    }
    bpp->hp = 0;
}

/* Add recovered HP, stopping at the maximum. */
void BTL_POKEPARAM_AddHp(struct BtlPokeParam *bpp, u16 amount)
{
    bpp->hp += amount;
    if (bpp->hp > bpp->maxHp) bpp->hp = bpp->maxHp;
}

/* Set the current HP to 0. */
void BTL_POKEPARAM_ZeroHp(struct BtlPokeParam *bpp)
{
    bpp->hp = 0x0;
}

/* Set one per-turn flag (cleared at the start of the next turn). */
void BTL_POKEPARAM_SetTurnFlag(struct BtlPokeParam *bpp, u32 flagIndex)
{
    bpp->turnFlags[(u8)(flagIndex >> 3)] |= (u8)(1 << (flagIndex & 7));
}

/*
 * Set one continuous flag (kept until the Pokemon leaves the battle).
 * lever: index the offset base (p + 0x155), preserving its separate add.
 */
void BTL_POKEPARAM_SetContFlag(struct BtlPokeParam *bpp, unsigned int flagIndex)
{
    bpp->contFlags[(u8)(flagIndex >> 3)] |= (u8)(1 << (flagIndex & 7));
}

/* Clear one continuous flag. */
void BTL_POKEPARAM_ClearContFlag(struct BtlPokeParam *bpp, unsigned int flagIndex)
{
    bpp->contFlags[(u8)(flagIndex >> 3)] &= (u8)~(u8)(1 << (flagIndex & 7));
}

/* Store a condition in slot sickIndex with a fresh turn counter; a major status replaces all other major ones. */
void BTL_POKEPARAM_SetSickCont(struct BtlPokeParam *bpp, int sickIndex, union SickCont cont)
{
    if (BTL_CALC_HasDefaultSickCont(sickIndex)) BTL_POKEPARAM_ClearMajorStatus(bpp);
    bpp->sickCont[(u32)sickIndex] = cont;
    bpp->sickTurn[(u32)sickIndex] = 0;
}

/*
 * Advance the turn counter of one condition. Returns 1 when the slot is
 * active (and copies it to *outCont); *outCured is set to 1 when the
 * condition ran out and the slot was cleared. Slots 2 and 6 are ticked by
 * their own functions and return 0 here.
 */
int BTL_POKEPARAM_TickSickCont(struct BtlPokeParam *bpp, u32 sickIndex, union SickCont *outCont, int *outCured)
{
    u8 turnLimit;
    union SickCont cont;
    u32 index;
    if (sickIndex == 2 || sickIndex == 6) return 0;
    if (bpp->sickCont[sickIndex].byPart.kind != 0) {
        turnLimit = BTLV_CORE_GetSlotLow(bpp->sickCont[sickIndex]);
        cont = bpp->sickCont[sickIndex];
        if (outCont != 0) *outCont = cont;
        if (outCured != 0) *outCured = 0;
        if (sickIndex == 27 && BTL_POKEPARAM_HasMove(bpp, BTLV_CORE_GetSlotValue(cont)) == 0) {
            bpp->sickCont[sickIndex] = BTLV_CORE_GetZeroMasked();
            bpp->sickTurn[sickIndex] = 0;
            if (outCured != 0) *outCured = 1;
        }
        if (turnLimit != 0) {
            bpp->sickTurn[sickIndex]++;
            if (bpp->sickTurn[sickIndex] >= turnLimit) {
                bpp->sickCont[sickIndex] = BTLV_CORE_GetZeroMasked();
                bpp->sickTurn[sickIndex] = 0;
                if (outCured != 0) *outCured = 1;
            }
        } else if (bpp->sickCont[sickIndex].byPart.kind == 1 && bpp->sickCont[sickIndex].byPart.paramLow != 0) {
            index = sickIndex;
            if (bpp->sickTurn[sickIndex] < bpp->sickCont[index].byPart.paramLow) bpp->sickTurn[sickIndex]++;
        }
        return 1;
    }
    return 0;
}

/* Tick the sleep counter (slot 2); it runs twice as fast with the ability 0x30 (Early Bird). Returns 1 when the Pokemon wakes up. */
int BTL_POKEPARAM_TickSleepTurn(struct BtlPokeParam *bpp)
{
    union SickCont *sleep = &bpp->sickCont[2];
    u8 turnLimit;
    int earlyBird;
    int step;
    if (sleep->byPart.kind != 0) {
        turnLimit = BTLV_CORE_GetSlotLow(*sleep);
        if (turnLimit != 0) {
            earlyBird = BTL_POKEPARAM_HasSick(bpp, 0x10) ? 0 : (bpp->ability == 0x30);
            step = 2;
            if (earlyBird == 0) step = 1;
            bpp->sickTurn[2] += (u8)step;
            if (bpp->sickTurn[2] >= turnLimit) {
                *sleep = BTLV_CORE_GetZeroMasked();
                BTL_POKEPARAM_CureSick(bpp, 2);
                return 1;
            }
        }
    }
    return 0;
}

/* Tick the counter of the condition in slot 6. Returns 1 when it ran out. */
int BTL_POKEPARAM_TickSlot6Turn(struct BtlPokeParam *bpp)
{
    union SickCont *cont = &bpp->sickCont[6];
    u8 turnLimit;
    if (cont->byPart.kind != 0) {
        turnLimit = BTLV_CORE_GetSlotLow(*cont);
        if (turnLimit != 0) {
            bpp->sickTurn[6]++;
            if (bpp->sickTurn[6] >= turnLimit) {
                *cont = BTLV_CORE_GetZeroMasked();
                BTL_POKEPARAM_CureSick(bpp, 6);
                return 1;
            }
        }
    }
    return 0;
}

/* Clear the five major status slots (1..5). */
void BTL_POKEPARAM_ClearMajorStatus(struct BtlPokeParam *bpp)
{
    u32 i;
    for (i = 1; i < 6; i++) {
        bpp->sickCont[i] = BTLV_CORE_GetZeroMasked();
        bpp->sickTurn[i] = 0;
        BTL_POKEPARAM_ClearDependentSick(bpp, i);
    }
}

/* Clearing slot 2 (sleep) also clears the condition in slot 9 that depends on it. */
void BTL_POKEPARAM_ClearDependentSick(struct BtlPokeParam *bpp, int sickIndex)
{
    if (sickIndex == 2) {
        bpp->sickCont[9] = BTLV_CORE_GetZeroMasked();
        bpp->sickTurn[9] = 0;
    }
}

/* Clear one condition; clearing a major status clears all major ones. */
void BTL_POKEPARAM_CureSick(struct BtlPokeParam *bpp, int sickIndex)
{
    if (BTL_CALC_HasDefaultSickCont(sickIndex) != 0) {
        BTL_POKEPARAM_ClearMajorStatus(bpp);
        return;
    }
    bpp->sickCont[sickIndex] = BTLV_CORE_GetZeroMasked();
    bpp->sickTurn[sickIndex] = 0;
}

/* Clear every condition that was caused by the source sourceId (0x1f means none). */
void BTL_POKEPARAM_CureSickBySource(struct BtlPokeParam *bpp, int sourceId)
{
    u32 i;
    if (sourceId != 0x1f) {
        for (i = 0; i < 0x24; i++) {
            if (BTLV_CORE_IsSlotKindNone(bpp->sickCont[i]) == 0 && sourceId == BTLV_CORE_GetSlotPosition(bpp->sickCont[i])) {
                bpp->sickCont[i] = BTLV_CORE_GetZeroMasked();
                BTL_POKEPARAM_ClearDependentSick(bpp, i);
            }
        }
    }
}

/* Index of the first active major status (1..5), or 0 when there is none. */
int BTL_POKEPARAM_GetMajorStatusIndex(struct BtlPokeParam *bpp)
{
    u32 i;
    for (i = 1; i < 6; i++) {
        if (bpp->sickCont[i].byPart.kind) return i;
    }
    return 0;
}

/* 1 when slot sickIndex holds a condition. */
int BTL_POKEPARAM_HasSick(struct BtlPokeParam *bpp, int sickIndex)
{
    if (bpp->sickCont[sickIndex].byPart.kind) return 1;
    return 0;
}

/* The parameter of the condition, chosen by its kind (value, low part or high part). */
u16 BTL_POKEPARAM_GetSickParam(struct BtlPokeParam *bpp, int sickIndex)
{
    switch (bpp->sickCont[sickIndex].byPart.kind) {
    case 2: return bpp->sickCont[sickIndex].byValue.value;
    case 3: return bpp->sickCont[sickIndex].byPart.paramLow;
    case 4: return bpp->sickCont[sickIndex].byPart.paramHigh;
    }
    return 0;
}

u32 BTL_POKEPARAM_GetSickContRaw(struct BtlPokeParam *bpp, int sickIndex) { return bpp->sickCont[sickIndex].raw; }

u8 BTL_POKEPARAM_GetSickTurn(struct BtlPokeParam *bpp, int sickIndex) { return bpp->sickTurn[sickIndex]; }

/* Damage taken per turn from the condition in slot sickIndex (a fraction of the maximum HP). */
int BTL_POKEPARAM_CalcSickDamage(struct BtlPokeParam *bpp, int sickIndex)
{
    if (BTL_POKEPARAM_HasSick(bpp, sickIndex) != 0) {
        switch (sickIndex) {
        case 5:
            if (BTLV_CORE_IsSlotKind1Index15(bpp->sickCont[sickIndex]) != 0)
                return BTL_CALC_DivideMaxHpMin1(bpp, 0x10) * bpp->sickTurn[sickIndex];
            return BTL_CALC_DivideMaxHpMin1(bpp, 8);
        case 4:
            return BTL_CALC_DivideMaxHpMin1(bpp, 8);
        case 9:
            if (BTL_POKEPARAM_HasSick(bpp, 2) != 0)
                return BTL_CALC_DivideMaxHpMin1(bpp, 4);
            break;
        case 10:
            return BTL_CALC_DivideMaxHpMin1(bpp, 4);
        default:
            return 0;
        }
    }
    return 0;
}

/*
 * Clear the conditions and their counters: all of them, or only the
 * non-major ones (from slot 6) when clearMajor is 0.
 * lever: enum loop counter with unsigned bound retains the entry guard;
 *   word-array indexing settles zero/offset scratch register allocation.
 */
void BTL_POKEPARAM_ClearSickConts(struct BtlPokeParam *bpp, int clearMajor)
{
    SickSlotIndex i;
    i = 0;
    if (clearMajor == 0) i = 6;
    for (; i < 36U; i++) {
        bpp->sickCont[i].raw = 0;
        bpp->sickCont[i].byPart.kind = 0;
    }
    MI_CpuFill8(bpp->sickTurn, 0, 36);
}

/* Start counting turns: restart the turn counter and arm the threshold. */
void BTL_POKEPARAM_StartTurnThreshold(struct BtlPokeParam *bpp, u16 threshold)
{
    bpp->turnThreshold = threshold;
    bpp->turnsOnField = 0;
    bpp->thresholdArmed = 1;
    BTL_POKEPARAM_ClearHitHistory(bpp);
}

/*
 * Start of a new turn: clear the per-turn flags and count the turn (at most 9999).
 */
void BTL_POKEPARAM_AdvanceTurn(struct BtlPokeParam *bpp)
{
    MI_CpuFill8(bpp->turnFlags, 0, 2);
    if (bpp->turnsOnField < 9999)
        bpp->turnsOnField += 1;
    BTL_POKEPARAM_AdvanceHitTurn(bpp);
}

/* Clear one per-turn flag. */
void BTL_POKEPARAM_ClearTurnFlag(struct BtlPokeParam *bpp, u32 flagIndex)
{
    u8 *flags;
    u8 byteIndex;
    u8 mask;
    flags = bpp->turnFlags;
    byteIndex = flagIndex >> 3;
    mask = 1 << (flagIndex & 7);
    flags[byteIndex] &= (u8)~mask;
}

/* Reset all battle effects (flags, history, conditions, stages) and reload the form and ability. */
void BTL_POKEPARAM_ResetAllEffects(struct BtlPokeParam *bpp)
{
    MI_CpuFill8(bpp->turnFlags, 0, 2);
    MI_CpuFill8(bpp->contFlags, 0, 2);
    BTL_POKEPARAM_RestoreIfNeeded(bpp);
    BTL_POKEPARAM_ResetBattleMoves(bpp);
    BTL_POKEPARAM_ResetMoveHistory(bpp);
    BTL_POKEPARAM_ClearMoveFlags(bpp);
    BTL_EVENT_ClearClientReservedChoice(bpp);
    BTL_POKEPARAM_ClearIllusion(bpp);
    BTL_POKEPARAM_ClearSubstitute(bpp);
    BTL_POKEPARAM_ClearSickConts(bpp, 1);
    BTL_POKEPARAM_InitStatStages(bpp->stages.stage);
    bpp->form = bpp->baseForm;
    bpp->ability = bpp->baseAbility;
    POKE_TOOL_SetPartyValue(bpp->mon, 0x6f, bpp->form);
    POKE_TOOL_RecalcParam(bpp->mon);
}

/* Switch-out reset: like the full reset, but keeps conditions, stages and continuous flags when flag 0xe is set. */
void BTL_POKEPARAM_ResetEffectsOnSwitchOut(struct BtlPokeParam *bpp)
{
    MI_CpuFill8(bpp->turnFlags, 0, 2);
    BTL_POKEPARAM_RestoreIfNeeded(bpp);
    BTL_POKEPARAM_ResetBattleMoves(bpp);
    BTL_POKEPARAM_ResetMoveHistory(bpp);
    BTL_POKEPARAM_ClearMoveFlags(bpp);
    BTL_EVENT_ClearClientReservedChoice(bpp);
    BTL_POKEPARAM_ClearIllusion(bpp);
    if (BTL_POKEPARAM_TestContFlag(bpp, 0xe) == 0) {
        BTL_POKEPARAM_ClearSubstitute(bpp);
        BTL_POKEPARAM_ClearSickConts(bpp, 0);
        BTL_POKEPARAM_InitStatStages(bpp->stages.stage);
        MI_CpuFill8(bpp->contFlags, 0, 2);
    }
    bpp->form = bpp->baseForm;
    bpp->ability = bpp->baseAbility;
    POKE_TOOL_SetPartyValue(bpp->mon, 0x6f, bpp->form);
    POKE_TOOL_RecalcParam(bpp->mon);
}

/* Reload the Pokemon from its party data and reset its effects, keeping the major status. */
void BTL_POKEPARAM_ReloadAndResetEffects(struct BtlPokeParam *bpp)
{
    BTL_POKEPARAM_ReloadFromMon(bpp, bpp->mon, 0, 1);
    MI_CpuFill8(bpp->contFlags, 0, 2);
    MI_CpuFill8(bpp->turnFlags, 0, 2);
    BTL_POKEPARAM_ClearSubstitute(bpp);
    BTL_POKEPARAM_ResetMoveHistory(bpp);
    BTL_POKEPARAM_ClearSickConts(bpp, 0);
    BTL_POKEPARAM_InitStatStages(bpp->stages.stage);
}

/* Pass the transferable effects (stages, conditions, some flags) from src to dst, then clear them on src. */
void BTL_POKEPARAM_PassEffects(struct BtlPokeParam *dst, struct BtlPokeParam *src)
{
    unsigned long i;
    u16 first;
    u16 second;
    dst->stages = src->stages;
    dst->substituteHp = src->substituteHp;
    for (i = 0; i < 36; i++) {
        if (src->sickCont[i].byPart.kind != 0 && BTL_ID_IsBatonPassSick(i)) {
            dst->sickCont[i] = src->sickCont[i];
            dst->sickTurn[i] = src->sickTurn[i];
        }
    }
    if (BTL_POKEPARAM_TestContFlag(src, 10)) {
        BTL_POKEPARAM_SetContFlag(dst, 10);
        first = func_021D58A8(dst, 8);
        second = func_021D58A8(dst, 9);
        BTL_POKEPARAM_SetStat(dst, 8, second);
        BTL_POKEPARAM_SetStat(dst, 9, first);
    }
    if (BTL_POKEPARAM_TestContFlag(src, 9)) BTL_POKEPARAM_SetContFlag(dst, 9);
    BTL_POKEPARAM_ClearSubstitute(src);
    BTL_POKEPARAM_ClearSickConts(src, 0);
    BTL_POKEPARAM_InitStatStages(src->stages.stage);
    MI_CpuFill8(src->contFlags, 0, 2);
}

void BTL_POKEPARAM_SetTypes(struct BtlPokeParam *poke, int typePair)
{
    poke->type1 = BTLV_CORE_GetHighByte(typePair);
    poke->type2 = BTLV_CORE_GetLowByte(typePair);
}

void BTL_POKEPARAM_SetAbility(struct BtlPokeParam *poke, u32 ability)
{
    poke->ability = ability;
}

void BTL_POKEPARAM_ChangeForm(struct BtlPokeParam *poke, u32 form)
{
    u32 savedState;
    poke->form = form;
    savedState = POKE_TOOL_DecodePartyParam(poke->mon);
    POKE_TOOL_ChangeForm(poke->mon, form);
    BTL_POKEPARAM_LoadStats(poke, poke->mon, 1);
    if (poke->species == 0x1ec && form == 0) {
        poke->baseForm = 0;
        poke->ability = func_02017E1C(poke->mon, 10, 0);
    }
    POKE_TOOL_EncodePartyParam(poke->mon, savedState);
}

/* Uses up the held item: it is remembered as consumed and the hand is empty. */
void BTL_POKEPARAM_ConsumeHeldItem(struct BtlPokeParam *poke, u16 itemId)
{
    poke->consumedItem = itemId;
    poke->heldItem = 0;
}

void BTL_POKEPARAM_ClearConsumedItem(struct BtlPokeParam *poke)
{
    poke->consumedItem = 0;
}

u16 BTL_POKEPARAM_GetConsumedItem(struct BtlPokeParam *poke)
{
    return poke->consumedItem;
}

/* Remembers the last move used; moveStreak counts uses of the same move in a row. */
void BTL_POKEPARAM_RecordMoveUse(struct BtlPokeParam *poke, u8 moveSlot, int keepStreak, u8 targetPos, u16 usedMoveId, u16 selectedMoveId)
{
    u16 previousMoveId = poke->lastUsedMoveId;
    poke->lastSelectedMoveId = selectedMoveId;
    poke->lastUsedMoveId = usedMoveId;
    poke->lastMoveSlot = moveSlot;
    poke->lastTargetPos = targetPos;
    if (previousMoveId == usedMoveId) {
        if (keepStreak) poke->moveStreak += 1;
        else poke->moveStreak = 0;
    } else {
        poke->moveStreak = keepStreak ? 1 : 0;
    }
}

u16 BTL_POKEPARAM_GetMoveStreak(struct BtlPokeParam *poke)
{
    return poke->moveStreak;
}

u16 BTL_POKEPARAM_GetLastUsedMoveId(struct BtlPokeParam *poke)
{
    return poke->lastUsedMoveId;
}

u8 BTL_POKEPARAM_GetLastTargetPos(struct BtlPokeParam *poke)
{
    return poke->lastTargetPos;
}

u16 BTL_POKEPARAM_GetLastSelectedMoveId(struct BtlPokeParam *poke)
{
    return poke->lastSelectedMoveId;
}

u8 BTL_POKEPARAM_GetLastMoveSlot(struct BtlPokeParam *poke)
{
    return poke->lastMoveSlot;
}

int BTL_POKEPARAM_IsLevelUpPending(struct BtlPokeParam *poke)
{
    return poke->thresholdArmed;
}

/* The weight is never below 1. */
void BTL_POKEPARAM_SetWeight(struct BtlPokeParam *poke, u32 weight)
{
    if (weight < 1) weight = 1;
    poke->weight = weight;
}

u16 BTL_POKEPARAM_GetWeight(struct BtlPokeParam *poke)
{
    return poke->weight;
}

void BTL_POKEPARAM_ClearHitHistory(struct BtlPokeParam *poke)
{
    MI_CpuFill8(poke->hitHistory, 0, sizeof(poke->hitHistory));
    MI_CpuFill8(poke->hitCount, 0, sizeof(poke->hitCount));
    poke->hitTurnIndex = 0;
    poke->hitHistorySpare = 0;
}

/* Starts the next turn of the three turn history and empties it. */
void BTL_POKEPARAM_AdvanceHitTurn(struct BtlPokeParam *poke)
{
    poke->hitTurnIndex++;
    if (poke->hitTurnIndex >= BTL_POKEPARAM_HIT_TURNS) poke->hitTurnIndex = 0;
    poke->hitCount[poke->hitTurnIndex] = 0;
}

/*
 * Adds a hit to the current turn; when the turn holds 6 hits the oldest is dropped.
 * stand-in: the new hit is written through a BtlPokeParam view at its address, the
 * direct array form changes the bytes (the original adds the field offset last).
 */
void BTL_POKEPARAM_AddHitRecord(struct BtlPokeParam *poke, struct BtlHitRecord *record)
{
    u8 count;
    u8 turn = poke->hitTurnIndex;
    u32 i;
    struct BtlPokeParam *slot;
    count = poke->hitCount[turn];
    if (count == BTL_POKEPARAM_HIT_MAX) {
        for (i = 0; i < BTL_POKEPARAM_HIT_MAX - 1; i++) {
            poke->hitHistory[turn][i].moveId = poke->hitHistory[turn][i + 1].moveId;
            poke->hitHistory[turn][i].damage = poke->hitHistory[turn][i + 1].damage;
            poke->hitHistory[turn][i].typeAndAttacker = poke->hitHistory[turn][i + 1].typeAndAttacker;
            poke->hitHistory[turn][i].hitFlags = poke->hitHistory[turn][i + 1].hitFlags;
        }
        count--;
    }
    slot = (struct BtlPokeParam *)((u8 *)poke + turn * sizeof(poke->hitHistory[0]) + count * sizeof(struct BtlHitRecord));
    slot->hitHistory[0][0].moveId = record->moveId;
    slot->hitHistory[0][0].damage = record->damage;
    slot->hitHistory[0][0].typeAndAttacker = record->typeAndAttacker;
    slot->hitHistory[0][0].hitFlags = record->hitFlags;
    if (poke->hitCount[turn] < BTL_POKEPARAM_HIT_MAX) poke->hitCount[turn]++;
}

/* Number of hits taken turnsAgo turns ago (0 to 2); 0 when out of range. */
int BTL_POKEPARAM_GetHitCount(struct BtlPokeParam *poke, u32 turnsAgo)
{
    if (turnsAgo < BTL_POKEPARAM_HIT_TURNS) {
        turnsAgo = poke->hitTurnIndex - turnsAgo;
        if ((int)turnsAgo < 0) turnsAgo += BTL_POKEPARAM_HIT_TURNS;
        return poke->hitCount[turnsAgo];
    }
    return 0;
}

/*
 * Reads the hit that is hitsAgo hits back in the turn turnsAgo turns ago; 0 if there is none.
 * stand-in: read through a BtlPokeParam view at the hit's address (same reason as BTL_POKEPARAM_AddHitRecord).
 */
int BTL_POKEPARAM_GetHitRecord(const struct BtlPokeParam *poke, int turnsAgo, u32 hitsAgo, struct BtlHitRecord *out)
{
    int turn;
    u32 count;
    const struct BtlPokeParam *slot;

    if ((u32)turnsAgo < BTL_POKEPARAM_HIT_TURNS) {
        turn = poke->hitTurnIndex - turnsAgo;
        if (turn < 0) turn += BTL_POKEPARAM_HIT_TURNS;
        count = poke->hitCount[turn];
        if (hitsAgo < count) {
            slot = (const struct BtlPokeParam *)((const u8 *)poke + turn * sizeof(poke->hitHistory[0]) + (u8)(count - hitsAgo - 1) * sizeof(struct BtlHitRecord));
            out->moveId = slot->hitHistory[0][0].moveId;
            out->damage = slot->hitHistory[0][0].damage;
            out->typeAndAttacker = slot->hitHistory[0][0].typeAndAttacker;
            out->hitFlags = slot->hitHistory[0][0].hitFlags;
            return 1;
        }
    }
    return 0;
}

void BTL_POKEPARAM_SetCounter(struct BtlPokeParam *poke, int index, u8 value)
{
    poke->counters[index] = value;
}

u8 func_021D69AC(struct BtlPokeParam *poke, int index)
{
    return poke->counters[index];
}

/*
 * Gives up to *remaining exp: stops at the next level. Returns 1 and fills
 * result when a level was gained (the used exp is taken from *remaining).
 */
int BTL_POKEPARAM_AddExp(struct BtlPokeParam *poke, u32 *remaining, struct BtlLevelUpResult *result)
{
    u32 oldExp, newExp, used, nextLevelExp;
    u16 oldMaxHp, oldAttack, oldDefense, oldSpAttack, oldSpDefense, oldSpeed;
    u8 savedState;
    if (poke->level < 100) {
        oldExp = poke->exp;
        newExp = oldExp + *remaining;
        nextLevelExp = func_02018584(poke->species, poke->form, poke->level + 1);
        if (newExp >= nextLevelExp) {
            used = nextLevelExp - oldExp;
            oldMaxHp = poke->maxHp;
            savedState = POKE_TOOL_DecodePartyParam(poke->mon);
            oldAttack = func_02017E1C(poke->mon, 0xa2, 0);
            oldDefense = func_02017E1C(poke->mon, 0xa3, 0);
            oldSpeed = func_02017E1C(poke->mon, 0xa4, 0);
            oldSpAttack = func_02017E1C(poke->mon, 0xa5, 0);
            oldSpDefense = func_02017E1C(poke->mon, 0xa6, 0);
            poke->exp = oldExp + used;
            POKE_TOOL_SetPartyValue(poke->mon, 8, poke->exp);
            POKE_TOOL_RecalcParam(poke->mon);
            poke->maxHp = func_02017E1C(poke->mon, 0xa1, 0);
            poke->level = func_02017E1C(poke->mon, 0x9e, 0);
            oldMaxHp = poke->maxHp - oldMaxHp;
            result->attackGain = func_02017E1C(poke->mon, 0xa2, 0);
            result->defenseGain = func_02017E1C(poke->mon, 0xa3, 0);
            result->spAttackGain = func_02017E1C(poke->mon, 0xa5, 0);
            result->spDefenseGain = func_02017E1C(poke->mon, 0xa6, 0);
            result->speedGain = func_02017E1C(poke->mon, 0xa4, 0);
            if (poke->isTransformed == 0) {
                poke->attack = result->attackGain;
                poke->defense = result->defenseGain;
                poke->spAttack = result->spAttackGain;
                poke->spDefense = result->spDefenseGain;
                poke->speed = result->speedGain;
            }
            result->level = poke->level;
            result->maxHpGain = oldMaxHp;
            result->attackGain -= oldAttack;
            result->defenseGain -= oldDefense;
            result->spAttackGain -= oldSpAttack;
            result->spDefenseGain -= oldSpDefense;
            result->speedGain -= oldSpeed;
            poke->hp += oldMaxHp;
            POKE_TOOL_SetPartyValue(poke->mon, 0xa0, poke->hp);
            BTL_POKEPARAM_SaveMovesToMon(poke);
            POKE_TOOL_EncodePartyParam(poke->mon, savedState);
            *remaining -= used;
            return 1;
        } else {
            poke->exp = newExp;
            POKE_TOOL_SetPartyValue(poke->mon, 8, newExp);
        }
    }
    if (result != 0) MI_CpuFill8(result, 0, sizeof(struct BtlLevelUpResult));
    return 0;
}

/* Exp needed to reach level 100. */
u32 BTL_POKEPARAM_GetMaxLevelExp(struct BtlPokeParam *poke)
{
    return func_02018584(poke->species, poke->form, 100);
}

/* Writes exp, HP, status, held item and form back into the party Pokemon. */
void BTL_POKEPARAM_WriteBackToParam(struct BtlPokeParam *poke, int useOriginalForm)
{
    void *pokeParam = poke->mon;
    u32 form;

    POKE_TOOL_SetPartyValue(pokeParam, 8, poke->exp);
    POKE_TOOL_SetPartyValue(pokeParam, 0xa0, poke->hp);
    if (poke->hp != 0)
        POKE_TOOL_SetStatusCondition(pokeParam, BTL_POKEPARAM_GetMajorStatusIndex(poke));
    else
        POKE_TOOL_SetStatusCondition(pokeParam, 0);
    BTL_POKEPARAM_SaveMovesToMon(poke);
    if (poke->isTransformed || useOriginalForm != 0)
        form = poke->baseForm;
    else
        form = poke->form;
    POKE_TOOL_SetPartyValue(pokeParam, 0x6f, (u8)form);
    POKE_TOOL_RecalcParam(pokeParam);
    POKE_TOOL_SetPartyValue(pokeParam, 6, poke->heldItem);
}

void BTL_POKEPARAM_ReloadFromParam(struct BtlPokeParam *poke)
{
    if (!poke->isTransformed) {
        BTL_POKEPARAM_ReloadFromMon(poke, poke->mon, 1, 0);
        BTL_POKEPARAM_SyncMovesFromMon(poke);
    } else {
        BTL_POKEPARAM_LoadMoves(poke, poke->mon, 0);
    }
}

int BTL_POKEPARAM_IsIllusionActive(struct BtlPokeParam *poke)
{
    return poke->illusionActive;
}

void BTL_POKEPARAM_ClearIllusion(struct BtlPokeParam *poke)
{
    poke->illusionActive = 0;
    poke->illusionMon = 0;
}

void BTL_POKEPARAM_SetPokeParam(void **pokeParamSlot, void *pokeParam)
{
    func_02017E1C(pokeParam, 5, 0);
    *pokeParamSlot = pokeParam;
}

/*
 * Transform: poke becomes a copy of target (its stats and moves) but keeps
 * its identity part; the copied moves get 5 PP. Fails (returns 0) when either
 * is already transformed or the target has a substitute.
 */
int BTL_POKEPARAM_Transform(struct BtlPokeParam *poke, struct BtlPokeParam *target)
{
    u16 savedSubstituteHp;
    int i;
    if (poke->isTransformed == 0 && target->isTransformed == 0 && target->substituteHp == 0) {
        MI_CpuCopy8(poke->moves, gBtlPokeParamTransformMoves, sizeof(poke->moves));
        gBtlPokeParamTransformKept = *(BtlPokeParamKept *)poke;
        savedSubstituteHp = poke->substituteHp;
        *poke = *target;
        *(BtlPokeParamKept *)poke = gBtlPokeParamTransformKept;
        poke->substituteHp = savedSubstituteHp;
        MI_CpuCopy8(gBtlPokeParamTransformMoves, poke->moves, sizeof(poke->moves));
        for (i = 0; i < BTL_POKEPARAM_MOVE_COUNT; i++)
            BTL_POKEPARAM_ReplaceMoveSlot(&poke->moves[i], target->moves[i].saved.id, 5, 0);
        MI_CpuFill8(poke->turnFlags, 0, sizeof(poke->turnFlags));
        MI_CpuFill8(poke->contFlags, 0, sizeof(poke->contFlags));
        poke->turnThreshold = 10000;
        poke->turnsOnField = 0;
        poke->lastSelectedMoveId = 0;
        poke->lastUsedMoveId = 0;
        poke->lastTargetPos = 0x11;
        poke->moveStreak = 0;
        poke->isTransformed = 1;
        return 1;
    }
    return 0;
}

int BTL_POKEPARAM_IsTransformed(struct BtlPokeParam *poke)
{
    return poke->isTransformed;
}

void BTL_POKEPARAM_SetSubstituteHp(struct BtlPokeParam *poke, u16 hp)
{
    poke->substituteHp = hp;
    BTL_POKEPARAM_CureSick(poke, 8);
}

void BTL_POKEPARAM_ClearSubstitute(struct BtlPokeParam *poke)
{
    poke->substituteHp = 0;
}

u32 BTL_POKEPARAM_HasSubstitute(struct BtlPokeParam *poke)
{
    return (poke->substituteHp != 0);
}

int BTL_POKEPARAM_GetSubstituteHp(struct BtlPokeParam *poke)
{
    return poke->substituteHp;
}

/*
 * Lets the substitute take *damage: returns 1 and lowers *damage to what the
 * substitute still had when it breaks, else lowers the substitute and returns 0.
 */
int BTL_POKEPARAM_DamageSubstitute(struct BtlPokeParam *poke, u16 *damage)
{
    u16 requested;
    requested = *damage;
    if (poke->substituteHp <= requested) {
        *damage = poke->substituteHp;
        poke->substituteHp = 0;
        return 1;
    }
    poke->substituteHp -= requested;
    return 0;
}

void func_021D6DC4(struct BtlPokeParam *poke)
{
    poke->foughtCount = 0;
}

/* Adds an opponent to the fought list unless it is already there. */
void func_021D6DCC(struct BtlPokeParam *poke, u32 pokeId)
{
    u32 i;
    u8 count = poke->foughtCount;

    for (i = 0; i < count; i++) {
        if (pokeId == poke->foughtIds[i]) return;
    }
    if (i < BTL_POKEPARAM_FOUGHT_MAX) {
        poke->foughtIds[i] = pokeId;
        poke->foughtCount++;
    }
}

unsigned char BTL_EVENT_GetClientPartyCount(BtlPokeParam *pp)
{
    return pp->foughtCount;
}


u8 BTL_EVENT_GetClientPartySlotId(BtlPokeParam *pp, u32 slot)
{
    if (slot < pp->foughtCount) return pp->foughtIds[slot];
    return BTL_POKEPARAM_NO_POKE;
}


void BTL_EVENT_StartClientPalAnm(BtlPokeParam *pp, int value)
{
    u32 code;
    code = PALANM_GetPairedCodeForFirst(value);
    if (code == 0) code = 4;
    POKE_TOOL_SetPartyValue(pp->mon, 0x98, code);
}


void BTL_EVENT_SetClientReservedChoice(BtlPokeParam *pp, u8 pokeId, u16 key)
{
    pp->storedPokeId = pokeId;
    pp->storedMoveId = key;
}


int BTL_EVENT_GetClientReservedChoice(BtlPokeParam *pp, u8 *pokeId, u16 *key)
{
    if (pp->storedPokeId != BTL_POKEPARAM_NO_POKE) {
        *pokeId = pp->storedPokeId;
        *key = pp->storedMoveId;
        return 1;
    }
    return 0;
}


u32 BTL_EVENT_HasClientReservedChoice(BtlPokeParam *pp)
{
    return (pp->storedPokeId != BTL_POKEPARAM_NO_POKE);
}


void BTL_EVENT_ClearClientReservedChoice(BtlPokeParam *pp)
{
    if (pp->storedPokeId != BTL_POKEPARAM_NO_POKE) {
        pp->storedPokeId = BTL_POKEPARAM_NO_POKE;
        pp->storedMoveId = 0;
    }
}

void BTL_EVENT_ReleaseClientHandle(BtlPokeParam *pp)
{
    POKE_TOOL_RecalcParam(pp->mon);
}
