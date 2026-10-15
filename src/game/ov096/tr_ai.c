/*
 * file:     tr_ai.c
 * unit:     yes
 * function: TR_AI_Create, TR_AI_Think, TR_AI_Delete, TR_AI_Start, TR_AI_GetChosenMove, TR_AI_GetChosenTarget, TR_AI_ThinkSingle, TR_AI_ThinkMulti, TR_AI_RunScripts, TR_AI_CmdIfRandomLess, TR_AI_CmdIfRandomGreater, TR_AI_CmdIfRandomEqual, TR_AI_CmdIfRandomNotEqual, TR_AI_CompareRandom, TR_AI_CmdAddScore, TR_AI_CmdIfHpLess, TR_AI_CmdIfHpGreater, TR_AI_CmdIfHpEqual, TR_AI_CmdIfHpNotEqual, TR_AI_CompareHpRatio, TR_AI_CmdIfHasMajorStatus, TR_AI_CmdIfNoMajorStatus, TR_AI_CompareMajorStatus, TR_AI_CmdIfSick, TR_AI_CmdIfNotSick, TR_AI_CompareSick, TR_AI_CmdIfSickContKind, TR_AI_CmdIfNotSickContKind, TR_AI_CompareSickContKind, TR_AI_CmdIfContFlag, TR_AI_CmdIfNotContFlag, TR_AI_CompareContFlag, TR_AI_CmdIfSideEffect, TR_AI_CmdIfNotSideEffect, TR_AI_CompareSideEffect, TR_AI_CmdIfValueLess, TR_AI_CmdIfValueGreater, TR_AI_CmdIfValueEqual, TR_AI_CmdIfValueNotEqual, TR_AI_CmdIfValueAllBits, TR_AI_CmdIfValueNoBits, TR_AI_CompareValue, TR_AI_CmdIfMoveEqual, TR_AI_CmdIfMoveNotEqual, TR_AI_CompareMove, TR_AI_CmdIfValueInList, TR_AI_CmdIfValueNotInList, TR_AI_CmdIfHasMoveWithParam3, TR_AI_CmdIfNoMoveWithParam3, TR_AI_CmdLoadTurnCount, TR_AI_CmdLoadType, TR_AI_CmdLoadMovePower, TR_AI_CmdLoadMoveDamageRank, TR_AI_CmdLoadLastUsedMove, TR_AI_CmdCompareSpeed, TR_AI_CmdLoadAbleBackupCount, TR_AI_CmdLoadMoveParam28, TR_AI_CmdLoadAbility, TR_AI_CmdCompareMoveEffectiveness, TR_AI_CmdIfAnyPartyMajorStatus, TR_AI_CmdIfNoPartyMajorStatus, TR_AI_ComparePartyMajorStatus, TR_AI_CmdLoadFieldCountdown, TR_AI_CmdIfMoveParam28Equal, TR_AI_CmdIfMoveParam28NotEqual, TR_AI_CompareMoveParam28, TR_AI_CmdIfPokeValueLess, TR_AI_CmdIfPokeValueGreater, TR_AI_CmdIfPokeValueEqual, TR_AI_CmdIfPokeValueNotEqual, TR_AI_ComparePokeValue, TR_AI_CmdIfDamageAbove, TR_AI_CmdIfDamageBelow, TR_AI_CompareDamage, TR_AI_CmdIfKnowsMove, TR_AI_CmdIfNotKnowsMove, TR_AI_CompareKnowsMove, TR_AI_CmdIfKnowsMoveParam28, TR_AI_CmdIfNotKnowsMoveParam28, TR_AI_CompareKnowsMoveParam28,TR_AI_CmdNop2,TR_AI_CmdSetNoMoveFlag,TR_AI_CmdNop3,TR_AI_CmdNop4, TR_AI_CmdLoadItem, TR_AI_CmdLoadItemEffect, TR_AI_CmdLoadPokeValue12, TR_AI_CmdLoadNoSubstitute, TR_AI_CmdLoadPokeValueByte, TR_AI_CmdLoadConsumedItem, TR_AI_CmdNop5, TR_AI_CmdMapMoveParam3, TR_AI_CmdMapMoveParam28, TR_AI_CmdLoadMoveStreak, TR_AI_CmdJump, TR_AI_CmdEnd, TR_AI_CmdCompareStat15, TR_AI_CmdIfTargetSick11, TR_AI_CmdIfTargetNotSick11, TR_AI_CompareTargetSick11, TR_AI_CmdIfSameSide, TR_AI_CmdLoadHasType, TR_AI_CmdLoadAbilityEquals, TR_AI_CmdJumpIfContFlag13, TR_AI_CmdJumpIfItemEquals, TR_AI_CmdCompareStaticSlot, TR_AI_CmdLoadSideEffect, TR_AI_CmdIfAnyPartyHpRatio, TR_AI_CmdIfAnyPartyMovePpLost, TR_AI_CmdLoadItemFieldNoSick19, TR_AI_GetMovePpChecked, TR_AI_CmdJumpIfNoMoveValue, TR_AI_GetMoveParam2, TR_AI_GetLastMoveParam2, TR_AI_CmdLoadFasterCount, TR_AI_CmdLoadTurnCountOfPoke, TR_AI_CmdJumpIfPartyDamage, TR_AI_CmdJumpIfSuperEffective, TR_AI_CmdJumpIfPredictedDamage, TR_AI_CmdLoadPokeValueSimple, TR_AI_CmdLoadPokeValueTwoArgs, TR_AI_CmdLoadBestDamagePoke, TR_AI_CmdIfFainted, TR_AI_CmdIfNotFainted, TR_AI_CompareFainted, TR_AI_CmdLoadPokeValue17, TR_AI_CmdJumpIfSubstitute, TR_AI_CmdLoadSpecies, TR_AI_CmdIfLess, TR_AI_CmdIfGreater, TR_AI_CmdIfEqual, TR_AI_CmdIfNotEqual, TR_AI_CompareGeneric, TR_AI_CmdJumpIfMoveParam28, TR_AI_CmdJumpIfFieldEffect, TR_AI_CmdCompareStat0, TR_AI_CmdCompareStat1, TR_AI_CmdCompareStat2, TR_AI_CompareStat, TR_AI_Compare, TR_AI_GetPosition, TR_AI_GetAbility, TR_AI_GetPoke, TR_AI_GetSlotPoke, TR_AI_ResetScores, TR_AI_RememberLastMove, TR_AI_GetMoveParam, TR_AI_GetMoveFlag, TR_AI_GetBestDamage, TR_AI_GetItemField, TR_AI_InitScriptCache, TR_AI_FreeScriptCache, TR_AI_LoadScript, TR_AI_ReleaseScript
 * address:  0x02187F00
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020490F4 0x020490F4 arm
 *   FILE_UTIL_Create_0F14 0x02020F14 thumb
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   VM_Create 0x0201121C thumb
 *   VM_Init 0x0201126C thumb
 *   WAZA_TOOL_IsCacheCreated 0x0201C408 thumb
 *   WAZA_TOOL_CreateCache 0x0201C328 thumb
 *   gTrAiAllocSite 0x0218A7A0 data
 *   gTrAiVmParams 0x0218A574 data
 *   VM_GetUserData 0x02011324 thumb
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
 *   VM_Delete 0x02011264 thumb
 *   WAZA_TOOL_DeleteCache 0x0201C3C0 thumb
 *   BTL_POKEPARAM_GetMoveCount 0x021D5448 thumb ov093
 *   func_020870D0 0x020870D0 arm
 *   BTL_POKEPARAM_GetMoveId 0x021D54C0 thumb ov093
 *   BTL_MAIN_IsPosInTable 0x021B9A6C thumb ov093
 *   BTL_MAIN_GetSlotClientIdThunk 0x021B8DE4 thumb ov093
 *   BTL_MAIN_IsOpposingPos 0x021B8CE8 thumb ov093
 *   BTL_POKEPARAM_GetMovePPChecked 0x021D5584 thumb ov093
 *   TR_AI_ReleaseScript 0x0218A528 thumb ov096
 *   VM_Start 0x0201127C thumb
 *   func_02011290 0x02011290 thumb
 *   VM_Control 0x02011298 thumb
 *   VM_GetU32  0x0201134C  thumb
 *   BTL_POKEPARAM_GetHpRatioFixed  0x021D5C44  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_POKEPARAM_GetSickContRaw  0x021D6314  thumb  ov093
 *   BTLV_CORE_IsSlotKind1Index15  0x021E8A78  thumb  ov093
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTL_SERVER_FLOW_GetSideEffectEntry  0x021C82D0  thumb  ov093
 *   VM_Jump  0x020113B0  thumb
 *   BTL_SERVER_FLOW_GetTurnCount 0x021C8138 thumb ov093
 *   BTL_POKEPARAM_GetTypePair  0x021D57FC  thumb  ov093
 *   BTLV_CORE_GetHighByte  0x021E8CFC  thumb  ov093
 *   BTLV_CORE_GetLowByte  0x021E8D04  thumb  ov093
 *   WAZA_TOOL_GetPower 0x0201C1D8 thumb
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_FLOW_CalcPredictedMoveDamage 0x021C7E14 thumb ov093
 *   BTL_POKEPARAM_GetLastUsedMoveId  0x021D67A8  thumb  ov093
 *   BTL_SERVER_FLOW_CalcPokeSpeedWrapper  0x021C81C8  thumb  ov093
 *   BTL_SIDE_GetSlotOfClientThunk  0x021B9AF8  thumb  ov093
 *   BTL_MAIN_GetPositionsPerClientThunk  0x021B99B8  thumb  ov093
 *   BTL_SLOT_GetCount  0x021B9B94  thumb  ov093
 *   BTL_POKEPARAM_IsAbleToBattle  0x021D5B7C  thumb  ov093
 *   BTL_SERVER_FLOW_CalcMoveTypeEffectiveness  0x021C7DAC  thumb  ov093
 *   BTL_FIELD_GetCountdownValue 0x021EF884 thumb ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   func_021D69AC  0x021D69AC  thumb  ov093
 *   BTL_POKEPARAM_GetConsumedItem  0x021D6740  thumb  ov093
 *   BTL_POKEPARAM_GetMoveStreak 0x021D679C thumb ov093
 *   BTL_FIELD_GetStaticSlotObject  0x021EF948  thumb  ov093
 *   BTL_POKEPARAM_GetMovePPLost 0x021D554C thumb ov093
 *   func_021D5478  0x021D5478  thumb  ov093
 *   BTL_SERVER_FLOW_CountFasterPokes  0x021C81D0  thumb  ov093
 *   BTL_POKEPARAM_GetTurnCount  0x021D5BA4  thumb  ov093
 *   BTL_SLOT_FindPoke 0x021B9C98 thumb ov093
 *   BTL_POKEPARAM_HasSubstitute 0x021D6D7C thumb ov093
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 *   BTL_SERVER_FLOW_CheckFieldEffectActive  0x021C82F4  thumb  ov093
 *   BTL_MAIN_GetOwnLanePos  0x021B8C38  thumb  ov093
 *   BTLV_EFFECT_GetPokeEffectValue 0x021F8AFC thumb ov094
 *   func_02019C90 0x02019C90 thumb
 *   BTL_SIDE_GetPokeAtPos  0x021B98AC  thumb  ov093
 *   BTL_SLOT_GetPokeParam  0x021B9C00  thumb  ov093
 *   func_02020F20  0x02020F20  thumb
 *   FILE_UTIL_Get_1014  0x02021014  thumb
 *   gTrAiScriptCache 0x0218A7C0 data a4
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb  arm9
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb  arm9
 */
#include "tr_ai_types.h"

typedef enum { COUNT_ONE = 1 } Count;
typedef enum { Z0 } E;
typedef struct SickCont { u32 a : 3; u32 rest : 29; } SickCont;
extern SickCont BTL_POKEPARAM_GetSickContRaw(struct BtlPokeParam *p, int i);

typedef struct { u8 id[4]; u8 ref[4]; void *obj[4]; } TrAiScriptCache;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(u32 id, u16 heap);
extern void *FILE_UTIL_Create_0F14(u16 heap);
extern u32 BTL_MAIN_GetRule(void **p);
extern void *BTL_MAIN_GetCompetitor(void ***p);
extern ScriptVm *VM_Create(u32 heapId, const struct ScriptVmParams *params);
extern void VM_Init(ScriptVm *vm, void *user);
extern u32 WAZA_TOOL_IsCacheCreated(void);
extern void WAZA_TOOL_CreateCache(int n, u32 heap);
extern TrAiWork *VM_GetUserData(ScriptVm *vm);
extern int BTL_POKEPARAM_IsFainted(struct BtlPokeParam *m);
extern u32 func_0203F0A8(void);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 func_020307B0(void *p);
extern void VM_Delete(void *);
extern void WAZA_TOOL_DeleteCache(void);
extern u8 BTL_POKEPARAM_GetMoveCount(struct BtlPokeParam *p);
extern u64 func_020870D0(void);
extern u16 BTL_POKEPARAM_GetMoveId(struct BtlPokeParam *p, int i);
extern int BTL_MAIN_IsPosInTable(int, u32);
extern u8 BTL_MAIN_GetSlotClientIdThunk(void *p, int i);
extern int BTL_MAIN_IsOpposingPos(void *, int, int);
extern u8 BTL_POKEPARAM_GetMovePPChecked(struct BtlPokeParam *p, u32 i);
extern void TR_AI_ReleaseScript(TrAiWork *);
extern void VM_Start(ScriptVm *vm, u8 *pc);
extern ScriptVm *func_02011290(ScriptVm *vm);
extern int VM_Control(ScriptVm *vm);
extern u32 VM_GetU32(ScriptVm *p);
extern int BTL_POKEPARAM_GetHpRatioFixed(struct BtlPokeParam *p);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct BtlPokeParam *p);
extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *p, int i);
extern int BTLV_CORE_IsSlotKind1Index15(SickCont);
extern int BTL_POKEPARAM_TestContFlag(struct BtlPokeParam *p, u32 n);
extern int BTL_SERVER_FLOW_GetSideEffectEntry(void *unused, unsigned int v, int k);
extern void VM_Jump(ScriptVm *c, u32 v);
extern unsigned short BTL_SERVER_FLOW_GetTurnCount(void *);
extern u16 BTL_POKEPARAM_GetTypePair(struct BtlPokeParam *p);
extern u8 BTLV_CORE_GetHighByte(int v);
extern int BTLV_CORE_GetLowByte(int x);
extern u16 WAZA_TOOL_GetPower(void *p);
extern u8 BTL_POKEPARAM_GetPokeId(struct BtlPokeParam *);
extern u16 BTL_SERVER_FLOW_CalcPredictedMoveDamage(u8 *p, u8 a, u8 b, u32 c, int e0, int e1);
extern u16 BTL_POKEPARAM_GetLastUsedMoveId(struct BtlPokeParam *p);
extern u16 BTL_SERVER_FLOW_CalcPokeSpeedWrapper(void *, struct BtlPokeParam *, int);
extern char *BTL_SIDE_GetSlotOfClientThunk(void *p, int i);
extern int BTL_MAIN_GetPositionsPerClientThunk(void *pp, unsigned int b);
extern u8 BTL_SLOT_GetCount(void *p);
extern int BTL_POKEPARAM_IsAbleToBattle(struct BtlPokeParam *);
extern int BTL_SERVER_FLOW_CalcMoveTypeEffectiveness(u8 *p, int a, int b, int c);
extern int BTL_FIELD_GetCountdownValue(void);
extern int func_021D59B4(struct BtlPokeParam *p, int k);
extern u16 BTL_POKEPARAM_GetItem(struct BtlPokeParam *p);
extern unsigned char func_021D69AC(struct BtlPokeParam *base, int idx);
extern u16 BTL_POKEPARAM_GetConsumedItem(struct BtlPokeParam *p);
extern u16 BTL_POKEPARAM_GetMoveStreak(struct BtlPokeParam *p);
extern int BTL_FIELD_GetStaticSlotObject(int);
extern u8 BTL_POKEPARAM_GetMovePPLost(struct BtlPokeParam *p, u8 i);
extern u8 func_021D5478(struct BtlPokeParam *p);
extern u16 BTL_SERVER_FLOW_CountFasterPokes(void *p, struct BtlPokeParam *a, u32 y);
extern unsigned short BTL_POKEPARAM_GetTurnCount(struct BtlPokeParam *p);
extern int BTL_SLOT_FindPoke(u8 *p, u32 v);
extern u32 BTL_POKEPARAM_HasSubstitute(struct BtlPokeParam *p);
extern u16 BTL_POKEPARAM_GetSpecies(struct BtlPokeParam *p);
extern int BTL_SERVER_FLOW_CheckFieldEffectActive(void *, int, int);
extern u8 BTL_MAIN_GetOwnLanePos(u32 flags, u32 v);
extern int BTLV_EFFECT_GetPokeEffectValue(int);
extern u32 func_02019C90(u16, u16, u32);
extern struct BtlPokeParam *BTL_SIDE_GetPokeAtPos(void *q, u8 b);
extern struct BtlPokeParam *BTL_SLOT_GetPokeParam(void *p, u32 i);
extern int WAZA_TOOL_GetParam(int, int);
extern int WAZA_TOOL_GetFlag(int, int);
extern void *func_02020F20(void *, int, u16);
extern u32 FILE_UTIL_Get_1014(void *p, u32 sel);
extern void *ARC_TOOL_LoadHandleMember(void *arc, u32 member, u32 heap);
ScriptVm *TR_AI_Create(void **battleMain, u32 serverFlow, u32 sideTable, u32 scriptMask, u16 heapId);
int TR_AI_Think(ScriptVm *vm);
void TR_AI_Delete(ScriptVm *vm);
void TR_AI_Start(ScriptVm *vm, u8 *movePp, int selfPos);
u8 TR_AI_GetChosenMove(ScriptVm *vm);
u8 TR_AI_GetChosenTarget(ScriptVm *vm);
int TR_AI_ThinkSingle(ScriptVm *vm, TrAiWork *ai);
int TR_AI_ThinkMulti(ScriptVm *vm, TrAiWork *ai);
void TR_AI_RunScripts(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfRandomLess(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfRandomGreater(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfRandomEqual(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfRandomNotEqual(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CompareRandom(ScriptVm *vm, TrAiWork *ai, int op);
int TR_AI_CmdAddScore(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfHpLess(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfHpGreater(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfHpEqual(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfHpNotEqual(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CompareHpRatio(ScriptVm *vm, TrAiWork *ai, int op);
int TR_AI_CmdIfHasMajorStatus(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfNoMajorStatus(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CompareMajorStatus(ScriptVm *vm, TrAiWork *ai, int op);
int TR_AI_CmdIfSick(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfNotSick(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CompareSick(ScriptVm *vm, TrAiWork *ai, int op);
int TR_AI_CmdIfSickContKind(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfNotSickContKind(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CompareSickContKind(ScriptVm *vm, TrAiWork *ai, int op);
int TR_AI_CmdIfContFlag(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfNotContFlag(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CompareContFlag(ScriptVm *vm, TrAiWork *ai, int op);
int TR_AI_CmdIfSideEffect(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfNotSideEffect(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CompareSideEffect(ScriptVm *vm, TrAiWork *ai, int op);
int TR_AI_CmdIfValueLess(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfValueGreater(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfValueEqual(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfValueNotEqual(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfValueAllBits(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfValueNoBits(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CompareValue(ScriptVm *vm, TrAiWork *ai, int op);
int TR_AI_CmdIfMoveEqual(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfMoveNotEqual(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CompareMove(ScriptVm *vm, TrAiWork *ai, int op);
int TR_AI_CmdIfValueInList(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfValueNotInList(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfHasMoveWithParam3(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfNoMoveWithParam3(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadTurnCount(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadType(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadMovePower(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadMoveDamageRank(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadLastUsedMove(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdCompareSpeed(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadAbleBackupCount(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadCurrentMove(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadMoveParam28(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadAbility(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdNop(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdCompareMoveEffectiveness(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfAnyPartyMajorStatus(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfNoPartyMajorStatus(ScriptVm *vm, TrAiWork *ai);
void TR_AI_ComparePartyMajorStatus(ScriptVm *vm, TrAiWork *ai, int op);
int TR_AI_CmdLoadFieldCountdown(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfMoveParam28Equal(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfMoveParam28NotEqual(ScriptVm *vm, TrAiWork *ai);
void TR_AI_CompareMoveParam28(ScriptVm *vm, TrAiWork *ai, int op);
int TR_AI_CmdIfPokeValueLess(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfPokeValueGreater(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfPokeValueEqual(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfPokeValueNotEqual(ScriptVm *vm, TrAiWork *ai);
int TR_AI_ComparePokeValue(ScriptVm *vm, TrAiWork *ai, int op);
int TR_AI_CmdIfDamageAbove(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfDamageBelow(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CompareDamage(ScriptVm *vm, TrAiWork *ai, int op);
int TR_AI_CmdIfKnowsMove(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfNotKnowsMove(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CompareKnowsMove(ScriptVm *vm, TrAiWork *ai, int op);
int TR_AI_CmdIfKnowsMoveParam28(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfNotKnowsMoveParam28(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CompareKnowsMoveParam28(ScriptVm *vm, TrAiWork *ai, int op);
int TR_AI_CmdNop2(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdSetNoMoveFlag(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdNop3(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdNop4(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadItem(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadItemEffect(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadPokeValue12(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadNoSubstitute(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadPokeValueByte(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadRule(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadCompetitor(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadConsumedItem(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdNop5(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdMapMoveParam3(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdMapMoveParam28(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadMoveStreak(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdJump(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdEnd(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdCompareStat15(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfTargetSick11(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfTargetNotSick11(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CompareTargetSick11(ScriptVm *vm, TrAiWork *ai, int op);
int TR_AI_CmdIfSameSide(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadHasType(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadAbilityEquals(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdJumpIfContFlag13(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdJumpIfItemEquals(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdCompareStaticSlot(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadSideEffect(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfAnyPartyHpRatio(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfAnyPartyMovePpLost(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadItemFieldNoSick19(ScriptVm *vm, TrAiWork *ai);
int TR_AI_GetMovePpChecked(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdJumpIfNoMoveValue(ScriptVm *vm, TrAiWork *ai);
int TR_AI_GetMoveParam2(ScriptVm *vm, TrAiWork *ai);
int TR_AI_GetLastMoveParam2(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadFasterCount(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadTurnCountOfPoke(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdJumpIfPartyDamage(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdJumpIfSuperEffective(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdJumpIfPredictedDamage(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadPokeValueSimple(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadPokeValueTwoArgs(ScriptVm *vm, TrAiWork *ai);
int TR_AI_NopA(ScriptVm *vm, TrAiWork *ai);
int TR_AI_NopB(ScriptVm *vm, TrAiWork *ai);
int TR_AI_NopC(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadBestDamagePoke(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfFainted(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfNotFainted(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CompareFainted(ScriptVm *vm, TrAiWork *ai, int op);
int TR_AI_CmdLoadPokeValue17(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdJumpIfSubstitute(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdLoadSpecies(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfLess(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfGreater(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfEqual(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdIfNotEqual(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CompareGeneric(ScriptVm *vm, TrAiWork *ai, int op);
int TR_AI_CmdJumpIfMoveParam28(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdJumpIfFieldEffect(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdCompareStat0(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdCompareStat1(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CmdCompareStat2(ScriptVm *vm, TrAiWork *ai);
int TR_AI_CompareStat(ScriptVm *vm, TrAiWork *ai, int op);
int TR_AI_Compare(ScriptVm *vm, int op, int x, int y, int jumpOffset);
u8 TR_AI_GetPosition(TrAiWork *ai, int kind);
int TR_AI_GetAbility(TrAiWork *ai, int kind, u8 pos);
struct BtlPokeParam *TR_AI_GetPoke(TrAiWork *ai, u8 pos);
struct BtlPokeParam *TR_AI_GetSlotPoke(void *p, u32 i);
void TR_AI_ResetScores(TrAiWork *ai);
void TR_AI_RememberLastMove(TrAiWork *ai);
int TR_AI_GetMoveParam(TrAiWork *ai, int b, int c);
int TR_AI_GetMoveFlag(void *a, int b, int c);
u32 TR_AI_GetBestDamage(TrAiWork *ai, struct BtlPokeParam *attacker, struct BtlPokeParam *defender, int flags);
int TR_AI_GetItemField(TrAiWork *ai, int itemId, int field);
void TR_AI_InitScriptCache(u32 heapId);
void TR_AI_FreeScriptCache(void);
void *TR_AI_LoadScript(TrAiWork *ai);
extern const char gTrAiAllocSite[];
extern const ScriptVmParams gTrAiVmParams;
extern TrAiScriptCache *gTrAiScriptCache;


ScriptVm *TR_AI_Create(void **battleMain, u32 serverFlow, u32 sideTable, u32 scriptMask, u16 heapId)
{
    TrAiWork *ai;
    ScriptVm *vm;
    ai = func_02030734(heapId, 0xD8, 1, gTrAiAllocSite, 0x1D9);
    ai->heapId = heapId;
    ai->cmdReturn = 1;
    ai->fullMask = scriptMask;
    ai->scriptArchive = func_020490F4(0xAB, heapId);
    ai->itemArchive = FILE_UTIL_Create_0F14(heapId);
    ai->battleMain = battleMain;
    ai->serverFlow = (void *)serverFlow;
    ai->sideTable = (void *)sideTable;
    ai->rule = BTL_MAIN_GetRule(battleMain);
    ai->competitor = BTL_MAIN_GetCompetitor((void ***)battleMain);
    vm = VM_Create(heapId, &gTrAiVmParams);
    VM_Init(vm, ai);
    if (WAZA_TOOL_IsCacheCreated() == 0)
        WAZA_TOOL_CreateCache(0x30, heapId);
    TR_AI_InitScriptCache(ai->heapId);
    return vm;
}

/*
 * lever: unsigned count/u64 draw reproduce the guarded high multiply;
 *   the callee result is returned through the final flag clear, keeping r0 live.
 */
int TR_AI_Think(ScriptVm *vm) {
    TrAiWork *ai;
    u32 n;
    int candidates[3];
    u64 r;
    int result;
    ai = VM_GetUserData(vm);
    if (ai->rule == 0) {
        ai->targetPos = ai->selfPos ^ 1;
        return TR_AI_ThinkSingle(vm, ai);
    }
    if (ai->rule == 1 || ai->rule == 2) {
        return TR_AI_ThinkMulti(vm, ai);
    }
    n = 0;
    for (ai->targetPos = 0; ai->targetPos < 6; ai->targetPos++) {
        if (ai->targetPos != ai->selfPos && (ai->targetPos & 1) != (ai->selfPos & 1)) {
            if (BTL_POKEPARAM_IsFainted(TR_AI_GetPoke(ai, ai->targetPos)) != 1)
                candidates[n++] = ai->targetPos;
        }
    }
    r = func_0203F0A8();
    if (n != 0)
        r = (r * n) >> 32;
    ai->targetPos = candidates[r];
    result = TR_AI_ThinkSingle(vm, ai);
    if (result == 0)
        ai->chosenTarget = 0;
    return result;
}

/*
 * note: Extent ends with two-byte zero alignment padding.
 */
void TR_AI_Delete(ScriptVm *vm) {
    TrAiWork *ai;
    ai = VM_GetUserData(vm);
    ARC_TOOL_DeleteHandle(ai->scriptArchive);
    ARC_TOOL_DeleteHandle(ai->itemArchive);
    func_020307B0(ai);
    VM_Delete(vm);
    if (WAZA_TOOL_IsCacheCreated() == 1) WAZA_TOOL_DeleteCache();
    TR_AI_FreeScriptCache();
}

void TR_AI_Start(ScriptVm *vm, u8 *movePp, int selfPos)
{
    TrAiWork *ai;
    int i;
    int zero;

    ai = VM_GetUserData(vm);
    ai->phase = 0;
    ai->moveId = 0;
    ai->moveIndex = 0;
    ai->workValue = 0;
    ai->flags = 0;
    ai->scriptId = 0;
    ai->selfPos = selfPos;
    ai->pendingMask = ai->fullMask;
    ai->moveCount = 4;
    zero = 0;
    for (i = 0; i < 4; i++) {
        if (movePp[i] == 0)
            ai->baseScores[i] = zero;
        else
            ai->baseScores[i] = 100;
        ai->moveRoll[i] = 100 - (u32)(((u64)func_0203F0A8() * 0x10) >> 32);
    }
    ai->randomByte = (u32)(((u64)func_0203F0A8() * 0x100) >> 32);
}

u8 TR_AI_GetChosenMove(ScriptVm *vm) { return VM_GetUserData(vm)->chosenMove; }

u8 TR_AI_GetChosenTarget(ScriptVm *vm) { return VM_GetUserData(vm)->chosenTarget; }

inline static u32 draw_below(u32 n) {
    u32 r = func_0203F0A8();
    u64 random = r;
    if (n != 0)
        r = (random * n) >> 32;
    return r;
}

/*
 * Lever: guarded named field pointers retain the 0x18 frame; entry/mask
 * declaration order fixes r7/r6; u64 draw puts its high-word zero before
 * the count guard. All 9 relocation sites resolve.
 */
int TR_AI_ThinkSingle(ScriptVm *vm, TrAiWork *ai) {
    int tiedScores[4];
    u8 tiedMoves[4];
    long moveSlot;
    int score;
    Count tieCount;

    u32 mask;
    int nextScript;
    u8 *entryPtr;
    u32 *maskPtr;
    u8 *flagsPtr;
    ai->selfPoke = TR_AI_GetPoke(ai, ai->selfPos);
    ai->targetPoke = TR_AI_GetPoke(ai, ai->targetPos);
    if (!(ai->flags & 16)) {
        TR_AI_ResetScores(ai);
        TR_AI_RememberLastMove(ai);
    }
    if ((mask = ai->pendingMask) != 0) {
    flagsPtr = &ai->flags;
    maskPtr = &ai->pendingMask;
    entryPtr = &ai->scriptId;
    do {
        if (mask & 1) {
            if (!(ai->flags & 16)) ai->phase = 0;
            *flagsPtr &= ~16;
            ai->startTick = func_020870D0();
            TR_AI_RunScripts(vm, ai);
            if (ai->flags & 16) return 1;
        }
        nextScript = *entryPtr + 1;
        mask = *maskPtr >> 1;
        *entryPtr = nextScript;
        *maskPtr = mask;
        ai->moveIndex = 0;
    } while ((mask = *maskPtr) != 0);
    }
    if (ai->flags & 2) {
        ai->chosenMove = 4;
    } else {
        tieCount = COUNT_ONE;
        tiedScores[0] = ai->moveScores[0];
        tiedMoves[0] = 0;
        for (moveSlot = 1; moveSlot < 4; moveSlot++) {
            if (moveSlot < BTL_POKEPARAM_GetMoveCount(ai->selfPoke)) {
                score = ai->moveScores[moveSlot];
                if (tiedScores[0] == score) {
                    tiedScores[tieCount] = score;
                    tiedMoves[tieCount] = moveSlot;
                    tieCount++;
                }
                if (tiedScores[0] < score) {
                    tiedScores[0] = score;
                    tieCount = COUNT_ONE;
                    tiedMoves[0] = moveSlot;
                }
            }
        }
        ai->chosenMove = tiedMoves[draw_below(tieCount)];
    }
    ai->chosenTarget = ai->targetPos;
    return 0;
}

/*
 * note (2026-10-05, wD5 lane16): EXACT. The draw helper holds the random value in a u32 and
 *   widens a copy to u64 before the test (`u32 r = f(); u64 random = r; if (n) r = (random * n) >> 32;`).
 *   That makes the hi zero before the n test and keeps the result in r0, as at both original sites.
 */
int TR_AI_ThinkMulti(ScriptVm *vm, TrAiWork *ai) {
    int targetLimit;
    int tiedScores[4];
    u8 tiedMoves[4];
    u8 tiedTargets[6];
    u32 mask;
    int nextScript;
    u8 *entryPtr;
    u32 *maskPtr;
    u8 *flagsPtr;
    Count tieCount;
    int moveSlot;
    int score;
    u8 targetSlot;
    int bestScore;

    targetLimit = (ai->rule == 1) ? 4 : 6;
    if (!(ai->flags & 16))
        ai->targetPos = 0;
    while (ai->targetPos < targetLimit) {
        ai->selfPoke = TR_AI_GetPoke(ai, ai->selfPos);
        ai->targetPoke = TR_AI_GetPoke(ai, ai->targetPos);
        if (!(ai->flags & 16)) {
            if (ai->targetPoke == 0) {
                ai->targetMove[ai->targetPos] = -1;
                ai->targetScores[ai->targetPos] = -1;
                goto nextTarget;
            }
            if (ai->targetPos == ai->selfPos || BTL_POKEPARAM_IsFainted(ai->targetPoke) == 1) {
                ai->targetMove[ai->targetPos] = -1;
                ai->targetScores[ai->targetPos] = -1;
                goto nextTarget;
            }
            TR_AI_ResetScores(ai);
            TR_AI_RememberLastMove(ai);
            ai->scriptId = 0;
            mask = ai->fullMask;
            ai->moveIndex = 0;
            ai->pendingMask = mask;
        }
        if ((mask = ai->pendingMask) != 0) {
            flagsPtr = &ai->flags;
            maskPtr = &ai->pendingMask;
            entryPtr = &ai->scriptId;
            do {
                if (mask & 1) {
                    if (!(ai->flags & 16)) ai->phase = 0;
                    *flagsPtr &= ~16;
                    ai->startTick = func_020870D0();
                    TR_AI_RunScripts(vm, ai);
                    if (ai->flags & 16) return 1;
                }
                nextScript = *entryPtr + 1;
                mask = *maskPtr >> 1;
                *entryPtr = nextScript;
                *maskPtr = mask;
                ai->moveIndex = 0;
            } while ((mask = *maskPtr) != 0);
        }
        if (ai->flags & 2) {
            ai->chosenMove = 4;
            goto nextTarget;
        }
        tieCount = COUNT_ONE;
        tiedScores[0] = ai->moveScores[0];
        tiedMoves[0] = 0;
        for (moveSlot = 1; moveSlot < 4; moveSlot++) {
            if (moveSlot < BTL_POKEPARAM_GetMoveCount(ai->selfPoke)) {
                score = ai->moveScores[moveSlot];
                if (tiedScores[0] == score) {
                    tiedScores[tieCount] = score;
                    tiedMoves[tieCount] = moveSlot;
                    tieCount++;
                }
                if (tiedScores[0] < score) {
                    tiedScores[0] = score;
                    tieCount = COUNT_ONE;
                    tiedMoves[0] = moveSlot;
                }
            }
        }
        ai->targetMove[ai->targetPos] = tiedMoves[draw_below(tieCount)];
        ai->targetScores[ai->targetPos] = tiedScores[0];
        if (BTL_MAIN_IsOpposingPos(ai->battleMain, BTL_MAIN_GetSlotClientIdThunk(ai->battleMain, ai->selfPos), BTL_MAIN_GetSlotClientIdThunk(ai->battleMain, ai->targetPos)) == 0) {
            if (ai->targetScores[ai->targetPos] < 100)
                ai->targetScores[ai->targetPos] = -1;
        }
    nextTarget:
        ai->targetPos = ai->targetPos + 1;
    }
    bestScore = ai->targetScores[0];
    tieCount = COUNT_ONE;
    tiedTargets[0] = 0;
    for (targetSlot = 1; targetSlot < targetLimit; targetSlot++) {
        score = ai->targetScores[targetSlot];
        if (bestScore == score) {
            tiedTargets[tieCount] = targetSlot;
            tieCount++;
        }
        if (bestScore < score) {
            bestScore = score;
            tiedTargets[0] = targetSlot;
            tieCount = COUNT_ONE;
        }
    }
    ai->chosenTarget = tiedTargets[draw_below(tieCount)];
    ai->chosenMove = ai->targetMove[ai->chosenTarget];
    if (TR_AI_GetMoveParam(ai, BTL_POKEPARAM_GetMoveId(ai->selfPoke, ai->chosenMove), 27) == 1 && !(ai->chosenTarget & 1))
        ai->chosenTarget = ai->selfPos;
    score = BTL_POKEPARAM_GetMoveId(ai->selfPoke, ai->chosenMove);
    if (ai->rule == 2 && BTL_MAIN_IsPosInTable(ai->selfPos, ai->chosenTarget) == 0 && TR_AI_GetMoveFlag(ai, score, 11) == 0)
        ai->chosenTarget = (ai->chosenTarget & 1) + 2;
    return 0;
}

/*
 * Lever: case 2 falls into default; an empty case 2 break adds four bytes.
 * Caller-visible return overrides tail-forwarders; 0201127C keeps visible r1.
 */
void TR_AI_RunScripts(ScriptVm *vm, TrAiWork *ai) {
    while (ai->phase != 2 && !(ai->flags & 16)) {
        switch (ai->phase) {
        case 0:
            if (BTL_POKEPARAM_GetMovePPChecked(ai->selfPoke, ai->moveIndex) == 0) {
                ai->moveId = 0;
            } else {
                ai->moveId = BTL_POKEPARAM_GetMoveId(ai->selfPoke, ai->moveIndex);
                ai->script = TR_AI_LoadScript(ai);
                VM_Start(vm, ai->script);
            }
            ai->phase++;
        case 1:
            if (ai->rule == 2 && ai->moveId != 0 && BTL_MAIN_IsPosInTable(ai->selfPos, ai->targetPos) == 0 && TR_AI_GetMoveFlag(ai, ai->moveId, 11) == 0) {
                ai->moveId = 0;
                func_02011290(vm);
                TR_AI_ReleaseScript(ai);
                ai->script = 0;
            }
            if (ai->moveId != 0) {
                VM_Control(vm);
                if (ai->flags & 1) {
                    ai->flags &= ~16;
                    TR_AI_ReleaseScript(ai);
                    ai->script = 0;
                } else if (func_020870D0() - ai->startTick > 500) {
                    ai->flags |= 16;
                    break;
                }
            } else {
                ai->moveScores[ai->moveIndex] = 0;
                ai->flags |= 1;
            }
            if (ai->flags & 1) {
                ai->moveIndex++;
                if (ai->moveIndex < BTL_POKEPARAM_GetMoveCount(ai->selfPoke) && !(ai->flags & 8))
                    ai->phase = 0;
                else
                    ai->phase++;
                ai->flags &= ~1;
            }
            break;
        case 2:
        default:
            ai->phase = 2;
            break;
        }
    }
}

int TR_AI_CmdIfRandomLess(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareRandom(vm, ai, 0);
    return ai->cmdReturn;
}

int TR_AI_CmdIfRandomGreater(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareRandom(vm, ai, 1);
    return ai->cmdReturn;
}

int TR_AI_CmdIfRandomEqual(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareRandom(vm, ai, 2);
    return ai->cmdReturn;
}

int TR_AI_CmdIfRandomNotEqual(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareRandom(vm, ai, 3);
    return ai->cmdReturn;
}

/*
 * Two levers closed this: (1) the third argument's zero is an enum-typed
 *   value (`typedef enum { Z0 } E; z = Z0;`) so mwcc does not fold
 *   `(v >> 24) | (z << 8)`; the operand order must put the shift second so
 *   its register is the accumulator (`lsls r2` + `orrs r2,r4`).  (2) the
 *   twice-called helper is 0x0201134C, not the 0x02011324 the old name
 *   implied.
 */
int TR_AI_CompareRandom(ScriptVm *vm, TrAiWork *ai, int op) {
    u8 *threshold;
    u32 random;
    int jumpOffset;
    E zero;
    threshold = (u8 *)VM_GetU32(vm);
    jumpOffset = (int)VM_GetU32(vm);
    random = func_0203F0A8();
    zero = Z0;
    return TR_AI_Compare(vm, op, ((random >> 24) | (zero << 8)), (int)threshold, jumpOffset);
}

int TR_AI_CmdAddScore(ScriptVm *vm, TrAiWork *ai) {
    u32 value;
    value = VM_GetU32(vm);
    ai->moveScores[ai->moveIndex] += value;
    if (ai->moveScores[ai->moveIndex] < 0)
        ai->moveScores[ai->moveIndex] = 0;
    return ai->cmdReturn;
}

int TR_AI_CmdIfHpLess(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareHpRatio(vm, ai, 0);
    return ai->cmdReturn;
}

int TR_AI_CmdIfHpGreater(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareHpRatio(vm, ai, 1);
    return ai->cmdReturn;
}

int TR_AI_CmdIfHpEqual(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareHpRatio(vm, ai, 2);
    return ai->cmdReturn;
}

int TR_AI_CmdIfHpNotEqual(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareHpRatio(vm, ai, 3);
    return ai->cmdReturn;
}

int TR_AI_CompareHpRatio(ScriptVm *vm, TrAiWork *ai, int op) {
    int side;
    int threshold;
    int jumpOffset;
    int hpRatio;
    u8 pos;

    side = VM_GetU32(vm);
    threshold = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, side);
    hpRatio = BTL_POKEPARAM_GetHpRatioFixed(TR_AI_GetPoke(ai, pos));
    return TR_AI_Compare(vm, op, hpRatio >> 12, threshold, jumpOffset);
}

int TR_AI_CmdIfHasMajorStatus(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareMajorStatus(vm, ai, 3);
    return ai->cmdReturn;
}

int TR_AI_CmdIfNoMajorStatus(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareMajorStatus(vm, ai, 2);
    return ai->cmdReturn;
}

int TR_AI_CompareMajorStatus(ScriptVm *vm, TrAiWork *ai, int op) {
    int side;
    int jumpOffset;
    int status;
    u8 pos;

    side = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, side);
    status = BTL_POKEPARAM_GetMajorStatusIndex(TR_AI_GetPoke(ai, pos));
    return TR_AI_Compare(vm, op, status, 0, jumpOffset);
}

int TR_AI_CmdIfSick(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareSick(vm, ai, 2);
    return ai->cmdReturn;
}

int TR_AI_CmdIfNotSick(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareSick(vm, ai, 3);
    return ai->cmdReturn;
}

int TR_AI_CompareSick(ScriptVm *vm, TrAiWork *ai, int op) {
    int side;
    int sickId;
    int jumpOffset;
    int hasSick;
    u8 pos;

    side = VM_GetU32(vm);
    sickId = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, side);
    hasSick = BTL_POKEPARAM_HasSick(TR_AI_GetPoke(ai, pos), sickId);
    return TR_AI_Compare(vm, op, hasSick, 1, jumpOffset);
}

int TR_AI_CmdIfSickContKind(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareSickContKind(vm, ai, 2);
    return ai->cmdReturn;
}

int TR_AI_CmdIfNotSickContKind(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareSickContKind(vm, ai, 3);
    return ai->cmdReturn;
}

int TR_AI_CompareSickContKind(ScriptVm *vm, TrAiWork *ai, int op) {
    int side;
    int jumpOffset;
    struct BtlPokeParam *poke;
    u8 pos;
    int matches;
    SickCont cont;

    side = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, side);
    poke = TR_AI_GetPoke(ai, pos);
    matches = 0;
    if (BTL_POKEPARAM_HasSick(poke, 5) != 0) {
        cont = BTL_POKEPARAM_GetSickContRaw(poke, 5);
        if (BTLV_CORE_IsSlotKind1Index15(cont) != 0)
            matches = 1;
    }
    return TR_AI_Compare(vm, op, matches, 1, jumpOffset);
}

int TR_AI_CmdIfContFlag(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareContFlag(vm, ai, 2);
    return ai->cmdReturn;
}

int TR_AI_CmdIfNotContFlag(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareContFlag(vm, ai, 3);
    return ai->cmdReturn;
}

int TR_AI_CompareContFlag(ScriptVm *vm, TrAiWork *ai, int op) {
    int side;
    int flag;
    int jumpOffset;
    int hasFlag;
    u8 pos;

    side = VM_GetU32(vm);
    flag = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, side);
    hasFlag = BTL_POKEPARAM_TestContFlag(TR_AI_GetPoke(ai, pos), flag);
    return TR_AI_Compare(vm, op, hasFlag, 1, jumpOffset);
}

int TR_AI_CmdIfSideEffect(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareSideEffect(vm, ai, 2);
    return ai->cmdReturn;
}

int TR_AI_CmdIfNotSideEffect(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareSideEffect(vm, ai, 3);
    return ai->cmdReturn;
}

int TR_AI_CompareSideEffect(ScriptVm *vm, TrAiWork *ai, int op) {
    int side;
    int effect;
    int jumpOffset;
    int lookup;

    side = VM_GetU32(vm);
    effect = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    lookup = TR_AI_GetPosition(ai, side);
    lookup = BTL_SERVER_FLOW_GetSideEffectEntry(ai->serverFlow, lookup, effect);
    return TR_AI_Compare(vm, op, lookup != 0, 1, jumpOffset);
}

int TR_AI_CmdIfValueLess(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareValue(vm, ai, 0);
    return ai->cmdReturn;
}

int TR_AI_CmdIfValueGreater(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareValue(vm, ai, 1);
    return ai->cmdReturn;
}

int TR_AI_CmdIfValueEqual(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareValue(vm, ai, 2);
    return ai->cmdReturn;
}

int TR_AI_CmdIfValueNotEqual(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareValue(vm, ai, 3);
    return ai->cmdReturn;
}

int TR_AI_CmdIfValueAllBits(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareValue(vm, ai, 4);
    return ai->cmdReturn;
}

int TR_AI_CmdIfValueNoBits(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareValue(vm, ai, 5);
    return ai->cmdReturn;
}

int TR_AI_CompareValue(ScriptVm *vm, TrAiWork *ai, int op) { int compareValue,jumpOffset; compareValue=VM_GetU32(vm); jumpOffset=VM_GetU32(vm); return TR_AI_Compare(vm,op,ai->workValue,compareValue,jumpOffset); }

int TR_AI_CmdIfMoveEqual(ScriptVm *vm, TrAiWork *ai) { TR_AI_CompareMove(vm,ai,2); return ai->cmdReturn; }

int TR_AI_CmdIfMoveNotEqual(ScriptVm *vm, TrAiWork *ai) { TR_AI_CompareMove(vm,ai,3); return ai->cmdReturn; }

int TR_AI_CompareMove(ScriptVm *vm, TrAiWork *ai, int op) { int compareMove,jumpOffset; compareMove=VM_GetU32(vm); jumpOffset=VM_GetU32(vm); return TR_AI_Compare(vm,op,ai->moveId,compareMove,jumpOffset); }

int TR_AI_CmdIfValueInList(ScriptVm *vm, TrAiWork *ai) {
    u16 *list;
    int jumpOffset;
    int index;
    int entry;

    list = (u16 *)((int)vm->pc + VM_GetU32(vm));
    jumpOffset = VM_GetU32(vm);
    index = 0;
    do {
        entry = list[index] | (list[index + 1] << 16);
        if (ai->workValue == entry) {
            VM_Jump(vm, (int)vm->pc + jumpOffset);
            break;
        }
        index += 2;
    } while (entry != -1);
    return ai->cmdReturn;
}

int TR_AI_CmdIfValueNotInList(ScriptVm *vm, TrAiWork *ai) {
    u16 *list;
    int jumpOffset;
    int index;
    int entry;

    list = (u16 *)((int)vm->pc + VM_GetU32(vm));
    jumpOffset = VM_GetU32(vm);
    index = 0;
    do {
        entry = list[index] | (list[index + 1] << 16);
        if (ai->workValue == entry)
            return ai->cmdReturn;
        index += 2;
    } while (entry != -1);
    VM_Jump(vm, (int)vm->pc + jumpOffset);
    return ai->cmdReturn;
}

/*
 * Lever: b is a pointer to a Conn_02188284 struct (fields fbc, fc4) so the b+0xbc
 *   address is not CSE'd across the calls (the original re-adds it each time);
 *   TR_AI_GetMoveParam's second parameter is int (no truncation before the bl).
 */
/*
 * Lever: b is a pointer to a Conn struct (fields fbc, fc4) so the b+0xbc
 *   address is not CSE'd across the calls (the original re-adds it each time);
 *   TR_AI_GetMoveParam's second parameter is int (no truncation before the bl).
 */
int TR_AI_CmdIfHasMoveWithParam3(ScriptVm *vm, TrAiWork *ai) {
    int jumpOffset;
    int moveSlot;

    jumpOffset = VM_GetU32(vm);
    for (moveSlot = 0; moveSlot < BTL_POKEPARAM_GetMoveCount(ai->selfPoke); moveSlot++) {
        if (TR_AI_GetMoveParam(ai, BTL_POKEPARAM_GetMoveId(ai->selfPoke, (u8)moveSlot), 3) != 0)
            break;
    }
    if (moveSlot < BTL_POKEPARAM_GetMoveCount(ai->selfPoke))
        VM_Jump(vm, (int)vm->pc + jumpOffset);
    return ai->cmdReturn;
}

/*
 * Lever: as TR_AI_CmdIfHasMoveWithParam3 (Conn_02188284 struct pointer, (Conn_02188284 *)(int second parameter)).
 */
/*
 * Lever: as TR_AI_CmdIfHasMoveWithParam3 (Conn struct pointer, int second parameter).
 */
int TR_AI_CmdIfNoMoveWithParam3(ScriptVm *vm, TrAiWork *ai) {
    int jumpOffset;
    int moveSlot;

    jumpOffset = VM_GetU32(vm);
    for (moveSlot = 0; moveSlot < BTL_POKEPARAM_GetMoveCount(ai->selfPoke); moveSlot++) {
        if (TR_AI_GetMoveParam(ai, BTL_POKEPARAM_GetMoveId(ai->selfPoke, (u8)moveSlot), 3) != 0)
            break;
    }
    if (moveSlot == BTL_POKEPARAM_GetMoveCount(ai->selfPoke))
        VM_Jump(vm, (int)vm->pc + jumpOffset);
    return ai->cmdReturn;
}

int TR_AI_CmdLoadTurnCount(ScriptVm *vm, TrAiWork *ai) { ai->workValue=BTL_SERVER_FLOW_GetTurnCount(ai->serverFlow); return ai->cmdReturn; }

/*
 * Lever: the source order of the switch arms decides which arm holds the
 *   shared tail and which becomes a stub jump; the original order is
 *   1,0,3,2,4,6,5,8,7 (not ascending).
 */
int TR_AI_CmdLoadType(ScriptVm *vm, TrAiWork *ai) {
    u32 kind;
    int selfTypes;
    int targetTypes;

    kind = VM_GetU32(vm);
    selfTypes = BTL_POKEPARAM_GetTypePair(ai->selfPoke);
    targetTypes = BTL_POKEPARAM_GetTypePair(ai->targetPoke);
    switch (kind) {
    case 1:
        ai->workValue = BTLV_CORE_GetHighByte(selfTypes);
        break;
    case 0:
        ai->workValue = BTLV_CORE_GetHighByte(targetTypes);
        break;
    case 3:
        ai->workValue = BTLV_CORE_GetLowByte(selfTypes);
        break;
    case 2:
        ai->workValue = BTLV_CORE_GetLowByte(targetTypes);
        break;
    case 4:
        ai->workValue = TR_AI_GetMoveParam(ai, ai->moveId, 0);
        break;
    case 6:
        ai->workValue = BTLV_CORE_GetHighByte(BTL_POKEPARAM_GetTypePair(TR_AI_GetPoke(ai, TR_AI_GetPosition(ai, 3))));
        break;
    case 5:
        ai->workValue = BTLV_CORE_GetHighByte(BTL_POKEPARAM_GetTypePair(TR_AI_GetPoke(ai, TR_AI_GetPosition(ai, 2))));
        break;
    case 8:
        ai->workValue = BTLV_CORE_GetLowByte(BTL_POKEPARAM_GetTypePair(TR_AI_GetPoke(ai, TR_AI_GetPosition(ai, 3))));
        break;
    case 7:
        ai->workValue = BTLV_CORE_GetLowByte(BTL_POKEPARAM_GetTypePair(TR_AI_GetPoke(ai, TR_AI_GetPosition(ai, 2))));
        break;
    }
    return ai->cmdReturn;
}

int TR_AI_CmdLoadMovePower(ScriptVm *vm, TrAiWork *ai) { ai->workValue=WAZA_TOOL_GetPower((void *)(ai->moveId)); return ai->cmdReturn; }

int TR_AI_CmdLoadMoveDamageRank(ScriptVm *vm, TrAiWork *ai) {
    int calcFlags = VM_GetU32(vm);
    u8 attackerId = BTL_POKEPARAM_GetPokeId(ai->selfPoke);
    u8 defenderId = BTL_POKEPARAM_GetPokeId(ai->targetPoke);
    u32 best = BTL_SERVER_FLOW_CalcPredictedMoveDamage(ai->serverFlow, attackerId, defenderId, ai->moveId, 1, calcFlags);
    int moveSlot;
    if (best == 0) {
        ai->workValue = 0;
    } else {
        ai->workValue = 2;
        for (moveSlot = 0; moveSlot < BTL_POKEPARAM_GetMoveCount((ai->selfPoke)); moveSlot++) {
            u16 otherMoveId = BTL_POKEPARAM_GetMoveId(ai->selfPoke, (u8)moveSlot);
            if (moveSlot != ai->moveIndex) {
                u32 otherDamage = BTL_SERVER_FLOW_CalcPredictedMoveDamage(ai->serverFlow, attackerId, defenderId, otherMoveId, 1, calcFlags);
                if (otherDamage > best) {
                    ai->workValue = 1;
                    break;
                }
            }
        }
    }
    return ai->cmdReturn;
}

int TR_AI_CmdLoadLastUsedMove(ScriptVm *vm, TrAiWork *ai) {
    int selector;
    u8 pos;
    selector = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, selector);
    selector = BTL_POKEPARAM_GetLastUsedMoveId(TR_AI_GetPoke(ai, pos));
    ai->workValue = selector;
    return ai->cmdReturn;
}

/*
 * Lever: x is a u16 local from the evidenced u16 callee return. Its word
 * spill reload stays after the outgoing fifth-argument store. All 5
 * relocation sites resolve; trailing two-byte padding is EXACT*.
 */
int TR_AI_CmdCompareSpeed(ScriptVm *vm, TrAiWork *ai) {
    int compareOp;
    int jumpOffset;
    u16 selfSpeed;
    int targetSpeed;

    compareOp = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    selfSpeed = BTL_SERVER_FLOW_CalcPokeSpeedWrapper(ai->serverFlow, ai->selfPoke, 1);
    targetSpeed = BTL_SERVER_FLOW_CalcPokeSpeedWrapper(ai->serverFlow, ai->targetPoke, 1);
    switch (compareOp) {
    case 0:
        compareOp = 1;
        break;
    case 1:
        compareOp = 0;
        break;
    case 2:
        compareOp = 2;
        break;
    }
    TR_AI_Compare(vm, compareOp, selfSpeed, targetSpeed, jumpOffset);
    return ai->cmdReturn;
}

/*
 * TR_AI_CmdLoadCurrentMove is the unlabelled store-and-return stub at 0x02188F08
 * (function_starts seed).
 */
int TR_AI_CmdLoadAbleBackupCount(ScriptVm *vm, TrAiWork *ai) {
    int clientId;
    char *slots;
    int slotIndex;

    clientId = BTL_MAIN_GetSlotClientIdThunk(ai->battleMain, TR_AI_GetPosition(ai, VM_GetU32(vm)));
    slots = BTL_SIDE_GetSlotOfClientThunk(ai->sideTable, clientId);
    slotIndex = BTL_MAIN_GetPositionsPerClientThunk(ai->battleMain, clientId);
    ai->workValue = 0;
    for (; slotIndex < BTL_SLOT_GetCount(slots); slotIndex++) {
        if (BTL_POKEPARAM_IsAbleToBattle(TR_AI_GetSlotPoke(slots, (u8)slotIndex)) != 0)
            ai->workValue++;
    }
    return ai->cmdReturn;
}

int TR_AI_CmdLoadCurrentMove(ScriptVm *vm, TrAiWork *ai) {
    ai->workValue = ai->moveId;
    return ai->cmdReturn;
}

int TR_AI_CmdLoadMoveParam28(ScriptVm *vm, TrAiWork *ai) { ai->workValue=TR_AI_GetMoveParam((void *)(ai),ai->moveId,28); return ai->cmdReturn; }

int TR_AI_CmdLoadAbility(ScriptVm *vm, TrAiWork *ai) { int selector; selector=VM_GetU32(vm); ai->workValue=TR_AI_GetAbility(ai,selector,TR_AI_GetPosition(ai,selector)); return ai->cmdReturn; }

int TR_AI_CmdNop(ScriptVm *vm, TrAiWork *ai) { return ai->cmdReturn; }

int TR_AI_CmdCompareMoveEffectiveness(ScriptVm *vm, TrAiWork *ai) {
    int compareValue;
    int jumpOffset;
    int attackerId;
    int defenderId;
    int effectiveness;

    compareValue = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    attackerId = BTL_POKEPARAM_GetPokeId(ai->selfPoke);
    defenderId = BTL_POKEPARAM_GetPokeId(ai->targetPoke);
    effectiveness = BTL_SERVER_FLOW_CalcMoveTypeEffectiveness(ai->serverFlow, attackerId, defenderId, ai->moveId);
    TR_AI_Compare(vm, 2, effectiveness, compareValue, jumpOffset);
    return ai->cmdReturn;
}

int TR_AI_CmdIfAnyPartyMajorStatus(ScriptVm *vm, TrAiWork *ai) { TR_AI_ComparePartyMajorStatus(vm,ai,2); return ai->cmdReturn; }

int TR_AI_CmdIfNoPartyMajorStatus(ScriptVm *vm, TrAiWork *ai) { TR_AI_ComparePartyMajorStatus(vm,ai,3); return ai->cmdReturn; }

void TR_AI_ComparePartyMajorStatus(ScriptVm *vm, TrAiWork *ai, int op) {
    int side;
    int jumpOffset;
    int clientId;
    char *slots;
    int slotIndex;

    side = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    clientId = BTL_MAIN_GetSlotClientIdThunk((char *)(ai->battleMain), TR_AI_GetPosition(ai, side));
    slots = BTL_SIDE_GetSlotOfClientThunk(ai->sideTable, clientId);
    for (slotIndex = BTL_MAIN_GetPositionsPerClientThunk((void *)(ai->battleMain), clientId);
         slotIndex < BTL_SLOT_GetCount(slots); slotIndex++) {
        struct BtlPokeParam *poke = TR_AI_GetSlotPoke(slots, (unsigned char)slotIndex);

        if (BTL_POKEPARAM_IsFainted(poke) == 0) {
            if (TR_AI_Compare(vm, op, BTL_POKEPARAM_GetMajorStatusIndex(poke), 0, jumpOffset) != 0)
                break;
        }
    }
}

int TR_AI_CmdLoadFieldCountdown(ScriptVm *vm, TrAiWork *ai) { ai->workValue=BTL_FIELD_GetCountdownValue(); return ai->cmdReturn; }

int TR_AI_CmdIfMoveParam28Equal(ScriptVm *vm, TrAiWork *ai) { TR_AI_CompareMoveParam28(vm,ai,2); return ai->cmdReturn; }

int TR_AI_CmdIfMoveParam28NotEqual(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareMoveParam28(vm, ai, 3);
    return ai->cmdReturn;
}

/*
 * return: TR_AI_GetMoveParam's r0 is consumed by original caller, overriding its void forwarder declaration.
 */
void TR_AI_CompareMoveParam28(ScriptVm *vm, TrAiWork *ai, int op) {
    int compareValue, jumpOffset;
    compareValue = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    TR_AI_Compare(vm, op, TR_AI_GetMoveParam(ai, ai->moveId, 28), compareValue, jumpOffset);
}

int TR_AI_CmdIfPokeValueLess(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_ComparePokeValue(vm, ai, 0);
    return ai->cmdReturn;
}

int TR_AI_CmdIfPokeValueGreater(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_ComparePokeValue(vm, ai, 1);
    return ai->cmdReturn;
}

int TR_AI_CmdIfPokeValueEqual(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_ComparePokeValue(vm, ai, 2);
    return ai->cmdReturn;
}

int TR_AI_CmdIfPokeValueNotEqual(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_ComparePokeValue(vm, ai, 3);
    return ai->cmdReturn;
}

int TR_AI_ComparePokeValue(ScriptVm *vm, TrAiWork *ai, int op) {
    int side;
    int valueKind;
    int compareValue;
    int jumpOffset;
    int pokeValue;

    side = VM_GetU32(vm);
    valueKind = VM_GetU32(vm);
    compareValue = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    pokeValue = func_021D59B4(TR_AI_GetPoke(ai, TR_AI_GetPosition(ai, side)), valueKind);
    return TR_AI_Compare(vm, op, pokeValue, compareValue, jumpOffset);
}

int TR_AI_CmdIfDamageAbove(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareDamage(vm, ai, 6);
    return ai->cmdReturn;
}

int TR_AI_CmdIfDamageBelow(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareDamage(vm, ai, 1);
    return ai->cmdReturn;
}

int TR_AI_CompareDamage(ScriptVm *vm, TrAiWork *ai, int op) {
    int jumpOffset;
    int targetHp;
    u8 attackerId;
    u8 defenderId;
    int damage;

    VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    targetHp = func_021D59B4(ai->targetPoke, 0xd);
    attackerId = BTL_POKEPARAM_GetPokeId(ai->selfPoke);
    defenderId = BTL_POKEPARAM_GetPokeId(ai->targetPoke);
    damage = BTL_SERVER_FLOW_CalcPredictedMoveDamage(ai->serverFlow, attackerId, defenderId, ai->moveId, 1, 0);
    return TR_AI_Compare(vm, op, targetHp, damage, jumpOffset);
}

int TR_AI_CmdIfKnowsMove(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareKnowsMove(vm, ai, 2);
    return ai->cmdReturn;
}

int TR_AI_CmdIfNotKnowsMove(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareKnowsMove(vm, ai, 3);
    return ai->cmdReturn;
}

/*
 * Lever: u16 value/result locals plus result binding give the original cmp operand order.
 * Caller-visible return/second arguments override tail-forwarder declarations.
 */
int TR_AI_CompareKnowsMove(ScriptVm *vm, TrAiWork *ai, int op) {
    u16 value, knownMoveId;
    int side, jumpOffset, found, moveSlot;
    struct BtlPokeParam *poke;
    int pos;
    side = VM_GetU32(vm);
    value = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, side);
    found = 0;
    switch (side) {
    case 1:
        for (moveSlot = 0; moveSlot < BTL_POKEPARAM_GetMoveCount(ai->selfPoke); moveSlot++) {
            knownMoveId = BTL_POKEPARAM_GetMoveId(ai->selfPoke, (u8)moveSlot);
            if (knownMoveId == value) {
                found = 1;
                break;
            }
        }
        break;
    case 3:
        poke = TR_AI_GetPoke(ai, TR_AI_GetPosition(ai, 3));
        if (BTL_POKEPARAM_IsFainted(poke) == 0) {
            for (moveSlot = 0; moveSlot < BTL_POKEPARAM_GetMoveCount(poke); moveSlot++) {
                knownMoveId = BTL_POKEPARAM_GetMoveId(poke, (u8)moveSlot);
                if (knownMoveId == value) {
                    found = 1;
                    break;
                }
            }
        }
        break;
    case 0:
        for (moveSlot = 0; moveSlot < 4; moveSlot++) {
            if (ai->knownMoves[pos][moveSlot] == value) {
                found = 1;
                break;
            }
        }
        break;
    }
    return TR_AI_Compare(vm, op, found, 1, jumpOffset);
}

int TR_AI_CmdIfKnowsMoveParam28(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareKnowsMoveParam28(vm, ai, 2);
    return ai->cmdReturn;
}

int TR_AI_CmdIfNotKnowsMoveParam28(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareKnowsMoveParam28(vm, ai, 3);
    return ai->cmdReturn;
}

/*
 * Extent contains four followers at 021893AC, 021893B4, 021893CC, 021893D4.
 * Followers have 6,22,6,6 code bytes with 2 zero alignment bytes each.
 * Lever: bind each comparison's call result before comparing, per existing cmp idiom.
 * Caller-visible return overrides the tail-forwarder's void declaration.
 */
int TR_AI_CompareKnowsMoveParam28(ScriptVm *vm, TrAiWork *ai, int op) {
    int side, jumpOffset, pos, found, moveSlot, moveParam;
    unsigned int value;
    side = VM_GetU32(vm);
    value = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, side);
    found = 0;
    switch (side) {
    case 1:
        for (moveSlot = 0; moveSlot < BTL_POKEPARAM_GetMoveCount(ai->selfPoke); moveSlot++) {
            moveParam = TR_AI_GetMoveParam(ai, (int)BTL_POKEPARAM_GetMoveId(ai->selfPoke, (u8)moveSlot), 28);
            if (moveParam == value) {
                found = 1;
                break;
            }
        }
        break;
    case 0:
        for (moveSlot = 0; moveSlot < 4; moveSlot++) {
            if (ai->knownMoves[pos][moveSlot] != 0) {
                moveParam = TR_AI_GetMoveParam(ai, ai->knownMoves[pos][moveSlot], 28);
                if (moveParam == value) {
                    found = 1;
                    break;
                }
            }
        }
        break;
    }
    return TR_AI_Compare(vm, op, found, 1, jumpOffset);
}

int TR_AI_CmdNop2(ScriptVm *vm, TrAiWork *ai) { return ai->cmdReturn; }

int TR_AI_CmdSetNoMoveFlag(ScriptVm *vm, TrAiWork *ai) {
    ai->flags |= 2;
    return ai->cmdReturn;
}

int TR_AI_CmdNop3(ScriptVm *vm, TrAiWork *ai) { return ai->cmdReturn; }

int TR_AI_CmdNop4(ScriptVm *vm, TrAiWork *ai) { return ai->cmdReturn; }

int TR_AI_CmdLoadItem(ScriptVm *vm, TrAiWork *ai) {
    int selector;
    u8 pos;
    selector = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, selector);
    selector = BTL_POKEPARAM_GetItem(TR_AI_GetPoke(ai, pos));
    ai->workValue = selector;
    return ai->cmdReturn;
}

int TR_AI_CmdLoadItemEffect(ScriptVm *vm, TrAiWork *ai) {
    int selector;
    u8 pos;
    selector = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, selector);
    selector = BTL_POKEPARAM_GetItem(TR_AI_GetPoke(ai, pos));
    selector = TR_AI_GetItemField(ai, (u16)selector, 1);
    ai->workValue = selector;
    return ai->cmdReturn;
}

int TR_AI_CmdLoadPokeValue12(ScriptVm *vm, TrAiWork *ai) {
    int selector;
    u8 pos;
    selector = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, selector);
    selector = func_021D59B4(TR_AI_GetPoke(ai, pos), 0x12);
    ai->workValue = selector;
    return ai->cmdReturn;
}

int TR_AI_CmdLoadNoSubstitute(ScriptVm *vm, TrAiWork *ai) {
    int selector;
    struct BtlPokeParam *mon;
    u8 pos;
    int hasNoSubstitute;
    selector = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, selector);
    mon = TR_AI_GetPoke(ai, pos);
    hasNoSubstitute = 0;
    if (BTL_POKEPARAM_TestContFlag(mon, 0) == 0) {
        hasNoSubstitute = 1;
    }
    ai->workValue = hasNoSubstitute;
    return ai->cmdReturn;
}

/*
 * TR_AI_CmdLoadRule and TR_AI_CmdLoadCompetitor are the unlabelled store-and-return stubs
 * after the lead function (function_starts seeds).
 */
int TR_AI_CmdLoadPokeValueByte(ScriptVm *vm, TrAiWork *ai) {
    ai->workValue = func_021D69AC(TR_AI_GetPoke(ai, TR_AI_GetPosition(ai, VM_GetU32(vm))), 0);
    return ai->cmdReturn;
}

int TR_AI_CmdLoadRule(ScriptVm *vm, TrAiWork *ai) {
    ai->workValue = ai->rule;
    return ai->cmdReturn;
}

int TR_AI_CmdLoadCompetitor(ScriptVm *vm, TrAiWork *ai) {
    ai->workValue = (int)ai->competitor;
    return ai->cmdReturn;
}

int TR_AI_CmdLoadConsumedItem(ScriptVm *vm, TrAiWork *ai) {
    int selector;
    u8 pos;
    selector = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, selector);
    selector = BTL_POKEPARAM_GetConsumedItem(TR_AI_GetPoke(ai, pos));
    ai->workValue = selector;
    return ai->cmdReturn;
}

int TR_AI_CmdNop5(ScriptVm *vm, TrAiWork *ai) {
    return ai->cmdReturn;
}

int TR_AI_CmdMapMoveParam3(ScriptVm *vm, TrAiWork *ai) {
    int param;
    if (ai->workValue != 0) {
        param = TR_AI_GetMoveParam(ai, (u16)ai->workValue, 3);
    } else {
        param = 0;
    }
    ai->workValue = param;
    return ai->cmdReturn;
}

int TR_AI_CmdMapMoveParam28(ScriptVm *vm, TrAiWork *ai) {
    int param;
    if (ai->workValue != 0) {
        param = TR_AI_GetMoveParam(ai, (u16)ai->workValue, 0x1c);
    } else {
        param = -1;
    }
    ai->workValue = param;
    return ai->cmdReturn;
}

/*
 * 2026-10-05 (wD5 lane01): EXACT. The store is written in each arm (`p[0x38] = 0;` / `p[0x38] = f(q);`);
 *   a value local v merged at the join swapped p and q. Older notes below.
 * 2026-10-04 (wave D2 lane 08): re-tested, still DIFF (10 bytes). Whole-body swap: image p=r4 q=r5, ours p=r5 q=r4. Allocation looks priority-ordered by reference count (q has four references, p four); no source tie-break found without changing the bytes.
 * note: 2026-10-04 Residue: whole-body register swap (original p in r4, q in r5; ours p in r5, q in r4); branch layout and instructions match otherwise. First param is unused (original uses r1 as p). Tried: ternary, early store, v-first, int v, copy of p, hoisted field pointer, struct p, split index locals, || vs && with Y-first.
 * note: 2026-10-05 (wD4 lane20): tried swapped declaration order of q and v, and the nested call chain split into three statements (a = f(x); a = g(p,a); q = h(p,a)); p stays r5, q r4. Residue unchanged: whole-body p/q colour swap (10 bytes).
 */
int TR_AI_CmdLoadMoveStreak(ScriptVm *vm, TrAiWork *ai) {
    struct BtlPokeParam *poke;
    poke = TR_AI_GetPoke(ai, TR_AI_GetPosition(ai, VM_GetU32(vm)));
    if (BTL_POKEPARAM_GetLastUsedMoveId(poke) != 0xB6 && BTL_POKEPARAM_GetLastUsedMoveId(poke) != 0xC5 && BTL_POKEPARAM_GetLastUsedMoveId(poke) != 0xCB)
        ai->workValue = 0;
    else
        ai->workValue = BTL_POKEPARAM_GetMoveStreak(poke);
    return ai->cmdReturn;
}

int TR_AI_CmdJump(ScriptVm *vm, TrAiWork *ai) {
    u32 jumpOffset; jumpOffset = VM_GetU32(vm); VM_Jump(vm, (u32)vm->pc + jumpOffset); return ai->cmdReturn;
}

int TR_AI_CmdEnd(ScriptVm *vm, TrAiWork *ai) {
    ai->flags |= 1; func_02011290(vm); return 1;
}

int TR_AI_CmdCompareStat15(ScriptVm *vm, TrAiWork *ai) {
    int compareKind;
    int jumpOffset;
    int selfValue;
    int targetValue;
    compareKind = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    {
        int cmpOps[3] = { 1, 0, 2 };
        selfValue = func_021D59B4(ai->selfPoke, 15);
        targetValue = func_021D59B4(ai->targetPoke, 15);
        TR_AI_Compare(vm, cmpOps[compareKind], selfValue, targetValue, jumpOffset);
    }
    return ai->cmdReturn;
}

int TR_AI_CmdIfTargetSick11(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareTargetSick11(vm, ai, 2); return ai->cmdReturn;
}

int TR_AI_CmdIfTargetNotSick11(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareTargetSick11(vm, ai, 3); return ai->cmdReturn;
}

int TR_AI_CompareTargetSick11(ScriptVm *vm, TrAiWork *ai, int op) {
    int jumpOffset;
    int hasSick;
    jumpOffset = VM_GetU32(vm);
    hasSick = BTL_POKEPARAM_HasSick((ai->targetPoke), 0xb);
    return TR_AI_Compare(vm, op, hasSick, 1, jumpOffset);
}

int TR_AI_CmdIfSameSide(ScriptVm *vm, TrAiWork *ai) {
    int jumpOffset;
    jumpOffset = VM_GetU32(vm);
    TR_AI_Compare(vm, 2, ai->selfPos & 1, ai->targetPos & 1, jumpOffset);
    return ai->cmdReturn;
}

int TR_AI_CmdLoadHasType(ScriptVm *vm, TrAiWork *ai) {
    int side;
    u8 typeId;
    int hasType;
    int types;
    u8 pos;
    side = VM_GetU32(vm);
    typeId = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, side);
    types = BTL_POKEPARAM_GetTypePair(TR_AI_GetPoke(ai, pos));
    if (typeId == BTLV_CORE_GetHighByte(types) || typeId == BTLV_CORE_GetLowByte(types)) {
        hasType = 1;
    } else {
        hasType = 0;
    }
    ai->workValue = hasType;
    return ai->cmdReturn;
}

int TR_AI_CmdLoadAbilityEquals(ScriptVm *vm, TrAiWork *ai) {
    int selector;
    int ability;
    int matches;
    u8 pos;
    selector = VM_GetU32(vm);
    ability = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, selector);
    matches = TR_AI_GetAbility(ai, selector, pos);
    if (matches == ability) {
        matches = 1;
    } else {
        matches = 0;
    }
    ai->workValue = matches;
    return ai->cmdReturn;
}

int TR_AI_CmdJumpIfContFlag13(ScriptVm *vm, TrAiWork *ai) {
    int side;
    int jumpOffset;
    struct BtlPokeParam *poke;
    u8 pos;
    side = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, side);
    poke = TR_AI_GetPoke(ai, pos);
    if (BTL_POKEPARAM_TestContFlag(poke, 13)) {
        VM_Jump(vm, (int)vm->pc + jumpOffset);
    }
    return ai->cmdReturn;
}

int TR_AI_CmdJumpIfItemEquals(ScriptVm *vm, TrAiWork *ai) {
    int side;
    int itemId;
    int jumpOffset;
    struct BtlPokeParam *poke;
    u8 pos;
    side = VM_GetU32(vm);
    itemId = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, side);
    poke = TR_AI_GetPoke(ai, pos);
    if (itemId == BTL_POKEPARAM_GetItem(poke)) {
        VM_Jump(vm, (int)vm->pc + jumpOffset);
    }
    return ai->cmdReturn;
}

int TR_AI_CmdCompareStaticSlot(ScriptVm *vm, TrAiWork *ai) {
    int slotIndex;
    int jumpOffset;
    int slotObject;
    slotIndex = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    slotObject = BTL_FIELD_GetStaticSlotObject(slotIndex);
    TR_AI_Compare(vm, 2, slotObject, 1, jumpOffset);
    return ai->cmdReturn;
}

int TR_AI_CmdLoadSideEffect(ScriptVm *vm, TrAiWork *ai) {
    int side;
    int effect;
    int lookup;
    side = VM_GetU32(vm);
    effect = VM_GetU32(vm);
    lookup = TR_AI_GetPosition(ai, side);
    lookup = BTL_SERVER_FLOW_GetSideEffectEntry(ai->serverFlow, lookup, effect);
    ai->workValue = lookup;
    return ai->cmdReturn;
}

int TR_AI_CmdIfAnyPartyHpRatio(ScriptVm *vm, TrAiWork *ai) {
    int side;
    int jumpOffset;
    u8 pos;
    int index;
    int hpRatio;
    char *slots;
    side = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, side);
    index = BTL_MAIN_GetSlotClientIdThunk(ai->battleMain, pos);
    slots = BTL_SIDE_GetSlotOfClientThunk(ai->sideTable, index);
    index = BTL_MAIN_GetPositionsPerClientThunk(ai->battleMain, index);
    for (; index < BTL_SLOT_GetCount(slots); index++) {
        if (BTL_POKEPARAM_IsFainted(TR_AI_GetSlotPoke(slots, (u8)index)) == 0) {
            hpRatio = BTL_POKEPARAM_GetHpRatioFixed(TR_AI_GetPoke(ai, pos));
            if (TR_AI_Compare(vm, 0, hpRatio, 100, jumpOffset) != 0) {
                break;
            }
        }
    }
    return ai->cmdReturn;
}

/*
 * Caller-visible return/second arguments override tail-forwarder declarations.
 */
int TR_AI_CmdIfAnyPartyMovePpLost(ScriptVm *vm, TrAiWork *ai) {
    int side, jumpOffset, clientId;
    char *slots;
    int slotIndex, moveSlot;
    u8 pos;
    side = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, side);
    clientId = BTL_MAIN_GetSlotClientIdThunk((char *)(ai->battleMain), pos);
    slots = BTL_SIDE_GetSlotOfClientThunk(ai->sideTable, clientId);
    slotIndex = BTL_MAIN_GetPositionsPerClientThunk((void *)(ai->battleMain), clientId);
    for (; slotIndex < BTL_SLOT_GetCount(slots); slotIndex++) {
        if (BTL_POKEPARAM_IsFainted(TR_AI_GetSlotPoke(slots, (u8)slotIndex)) == 0) {
            for (moveSlot = 0; moveSlot < BTL_POKEPARAM_GetMoveCount(TR_AI_GetPoke(ai, pos)); moveSlot++) {
                if (TR_AI_Compare(vm, 3, BTL_POKEPARAM_GetMovePPLost(TR_AI_GetPoke(ai, pos), moveSlot), 0, jumpOffset) != 0)
                    break;
            }
            if (moveSlot != BTL_POKEPARAM_GetMoveCount(TR_AI_GetPoke(ai, pos)))
                break;
        }
    }
    return ai->cmdReturn;
}

int TR_AI_CmdLoadItemFieldNoSick19(ScriptVm *vm, TrAiWork *ai) {
    int side;
    u8 pos;
    int itemId;
    side = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, side);
    ai->workValue = 0;
    if (BTL_POKEPARAM_HasSick(TR_AI_GetPoke(ai, pos), 0x13) == 0) {
        itemId = BTL_POKEPARAM_GetItem(TR_AI_GetPoke(ai, pos));
        ai->workValue = TR_AI_GetItemField(ai, (u16)itemId, 10);
    }
    return ai->cmdReturn;
}

int TR_AI_GetMovePpChecked(ScriptVm *vm, TrAiWork *ai) {
    ai->workValue = BTL_POKEPARAM_GetMovePPChecked(ai->selfPoke, ai->moveIndex); return ai->cmdReturn;
}

int TR_AI_CmdJumpIfNoMoveValue(ScriptVm *vm, TrAiWork *ai) {
    int side;
    int jumpOffset;
    u8 pos;
    struct BtlPokeParam *poke;
    side = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, side);
    poke = TR_AI_GetPoke(ai, pos);
    if (func_021D5478(poke) >= BTL_POKEPARAM_GetMoveCount(poke) && BTL_POKEPARAM_GetMoveCount(poke) > 1) {
        VM_Jump(vm, (int)vm->pc + jumpOffset);
    }
    return ai->cmdReturn;
}

int TR_AI_GetMoveParam2(ScriptVm *vm, TrAiWork *ai) {
    ai->workValue = TR_AI_GetMoveParam(ai, ai->moveId, 2); return ai->cmdReturn;
}

int TR_AI_GetLastMoveParam2(ScriptVm *vm, TrAiWork *ai) {
    int moveId;
    moveId = BTL_POKEPARAM_GetLastUsedMoveId((ai->targetPoke));
    if (moveId != 0) {
        moveId = TR_AI_GetMoveParam(ai, moveId, 2);
    } else {
        moveId = 0;
    }
    ai->workValue = moveId;
    return ai->cmdReturn;
}

int TR_AI_CmdLoadFasterCount(ScriptVm *vm, TrAiWork *ai) {
    int selector;
    u8 pos;
    selector = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, selector);
    selector = BTL_SERVER_FLOW_CountFasterPokes(ai->serverFlow, TR_AI_GetPoke(ai, pos), 1);
    ai->workValue = selector;
    return ai->cmdReturn;
}

/*
 *           unlabelled Thumb leaf in ov093 (it sits in a .word run in the
 *           ov093 listing), so neither `label` nor `sole-ref/code` can attest
 *           it, and the call at 0x02189AB4 is its only referrer image-wide.
 */
int TR_AI_CmdLoadTurnCountOfPoke(ScriptVm *vm, TrAiWork *ai) {
    int selector;
    u8 pos;
    selector = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, selector);
    selector = BTL_POKEPARAM_GetTurnCount(TR_AI_GetPoke(ai, pos));
    ai->workValue = selector;
    return ai->cmdReturn;
}

/*
 * Lever: the second parameter is a struct pointer (see 02189B78).
 */
int TR_AI_CmdJumpIfPartyDamage(ScriptVm *vm, TrAiWork *ai) {
    int calcFlags;
    int jumpOffset;
    int index;
    char *slots;
    struct BtlPokeParam *poke;
    u32 baseDamage;
    calcFlags = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    index = BTL_MAIN_GetSlotClientIdThunk(ai->battleMain, ai->selfPos);
    slots = BTL_SIDE_GetSlotOfClientThunk(ai->sideTable, index);
    index = BTL_MAIN_GetPositionsPerClientThunk(ai->battleMain, index);
    baseDamage = TR_AI_GetBestDamage(ai, ai->selfPoke, ai->targetPoke, calcFlags);
    for (; index < BTL_SLOT_GetCount(slots); index++) {
        poke = TR_AI_GetSlotPoke(slots, (u8)index);
        BTL_POKEPARAM_GetPokeId(poke);
        if (BTL_POKEPARAM_IsFainted(poke) == 0) {
            if (TR_AI_GetBestDamage(ai, poke, ai->targetPoke, calcFlags) > baseDamage) {
                VM_Jump(vm, (int)vm->pc + jumpOffset);
                break;
            }
        }
    }
    return ai->cmdReturn;
}

/*
 * Lever: the second parameter is a struct pointer; with an int base the
 * loop-invariant b+0xbc/b+0xc0 addresses were hoisted and b spilled.
 */
int TR_AI_CmdJumpIfSuperEffective(ScriptVm *vm, TrAiWork *ai) {
    int jumpOffset;
    int moveSlot;
    int moveId;
    int attackerId;
    int defenderId;
    jumpOffset = VM_GetU32(vm);
    for (moveSlot = 0; moveSlot < BTL_POKEPARAM_GetMoveCount(ai->selfPoke); moveSlot++) {
        moveId = BTL_POKEPARAM_GetMoveId(ai->selfPoke, (u8)moveSlot);
        attackerId = BTL_POKEPARAM_GetPokeId(ai->selfPoke);
        defenderId = BTL_POKEPARAM_GetPokeId(ai->targetPoke);
        if ((u32)(BTL_SERVER_FLOW_CalcMoveTypeEffectiveness(ai->serverFlow, attackerId, defenderId, moveId) - 4) <= 1) {
            VM_Jump(vm, (int)vm->pc + jumpOffset);
            break;
        }
    }
    return ai->cmdReturn;
}

int TR_AI_CmdJumpIfPredictedDamage(ScriptVm *vm, TrAiWork *ai) {
    int side;
    int calcFlags;
    int jumpOffset;
    struct BtlPokeParam *poke;
    unsigned int ownDamage;
    int lastMoveId;
    u8 attackerId;
    u8 defenderId;
    unsigned int predictedDamage;

    side = VM_GetU32(vm);
    calcFlags = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    poke = TR_AI_GetPoke(ai, TR_AI_GetPosition(ai, side));
    ownDamage = TR_AI_GetBestDamage(ai, ai->selfPoke, ai->targetPoke, calcFlags);
    lastMoveId = BTL_POKEPARAM_GetLastUsedMoveId(poke);
    attackerId = BTL_POKEPARAM_GetPokeId(poke);
    defenderId = BTL_POKEPARAM_GetPokeId(ai->targetPoke);
    predictedDamage = BTL_SERVER_FLOW_CalcPredictedMoveDamage(ai->serverFlow, attackerId, defenderId, lastMoveId, 1, calcFlags);
    if (ownDamage < predictedDamage)
        VM_Jump(vm, (int)vm->pc + jumpOffset);
    return ai->cmdReturn;
}

/*
 * Lever: the second parameter is a struct pointer (fields at 0x38, 0xc4);
 * with an int base and a local `int *p = b + 0x38` the store/adds order and
 * the r4/r5 roles were wrong.
 */
int TR_AI_CmdLoadPokeValueSimple(ScriptVm *vm, TrAiWork *ai) {
    u8 pos;
    int stat;
    u32 statSlot;
    pos = TR_AI_GetPosition(ai, VM_GetU32(vm));
    {
        int statIds[7] = { 1, 2, 3, 4, 5, 6, 7 };
        statSlot = 0;
        ai->workValue = 0;
        for (; statSlot < 7; statSlot++) {
            stat = func_021D59B4(TR_AI_GetPoke(ai, pos), statIds[statSlot]);
            if (stat > 6) {
                ai->workValue += stat - 6;
            }
        }
    }
    return ai->cmdReturn;
}

/*
 * TR_AI_NopA, TR_AI_NopB and TR_AI_NopC are the unlabelled
 * return-field stubs after the lead function (function_starts seeds).
 * The unit ends at 0x02189D48, where the next function starts.
 */
int TR_AI_CmdLoadPokeValueTwoArgs(ScriptVm *vm, TrAiWork *ai) {
    int side;
    int valueKind;
    u8 pos;
    struct BtlPokeParam *poke;
    int value;
    side = VM_GetU32(vm);
    valueKind = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, side);
    poke = TR_AI_GetPoke(ai, pos);
    value = func_021D59B4(poke, valueKind);
    ai->workValue = value - func_021D59B4(ai->selfPoke, valueKind);
    return ai->cmdReturn;
}

int TR_AI_NopA(ScriptVm *vm, TrAiWork *ai) {
    return ai->cmdReturn;
}

int TR_AI_NopB(ScriptVm *vm, TrAiWork *ai) {
    return ai->cmdReturn;
}

int TR_AI_NopC(ScriptVm *vm, TrAiWork *ai) {
    return ai->cmdReturn;
}

/*
 * 2026-10-05 (wD5 lane16): EXACT*. BTL_SERVER_FLOW_CalcPredictedMoveDamage takes u8 position arguments (a, b), and x, y, z are
 *   u8 locals (BTL_POKEPARAM_GetPokeId returns u8). That moves the `adds r1,rX` before the y reload at both calls.
 *   The ov093 callee also compiles EXACT with `u8 a, u8 b` (scratch test only, file not changed).
 */
int TR_AI_CmdLoadBestDamagePoke(ScriptVm *vm, TrAiWork *ai) {
    int calcFlags, clientId;
    u8 selfId, otherId;
    u8 *slots;
    int slotIndex, selfSlot;
    u8 targetId;
    u32 best;
    int firstSlot;
    calcFlags = VM_GetU32(vm);
    clientId = BTL_MAIN_GetSlotClientIdThunk((char *)(ai->battleMain), ai->selfPos);
    slots = (u8 *)BTL_SIDE_GetSlotOfClientThunk(ai->sideTable, clientId);
    firstSlot = BTL_MAIN_GetPositionsPerClientThunk(ai->battleMain, clientId);
    selfSlot = BTL_SLOT_FindPoke(slots, (u32)(ai->selfPoke));
    selfId = BTL_POKEPARAM_GetPokeId(ai->selfPoke);
    targetId = BTL_POKEPARAM_GetPokeId(ai->targetPoke);
    best = BTL_SERVER_FLOW_CalcPredictedMoveDamage(ai->serverFlow, selfId, targetId, ai->moveId, 1, calcFlags);
    if (selfSlot < 0 || best == 0) {
        ai->workValue = 0;
        return ai->cmdReturn;
    }
    for (slotIndex = 0; slotIndex < firstSlot; slotIndex++) {
        struct BtlPokeParam *poke = TR_AI_GetSlotPoke(slots, (u8)slotIndex);
        otherId = BTL_POKEPARAM_GetPokeId(poke);
        if (BTL_POKEPARAM_IsAbleToBattle(poke) != 0 && slotIndex != selfSlot) {
            int moveSlot;
            ai->workValue = 2;
            for (moveSlot = 0; moveSlot < (int)BTL_POKEPARAM_GetMoveCount(poke); moveSlot++) {
                u16 moveId = BTL_POKEPARAM_GetMoveId(poke, (u8)moveSlot);
                if (moveSlot != ai->moveIndex) {
                    u32 damage = BTL_SERVER_FLOW_CalcPredictedMoveDamage(ai->serverFlow, otherId, targetId, moveId, 1, calcFlags);
                    if (damage > best) {
                        ai->workValue = 1;
                        break;
                    }
                }
            }
        }
    }
    return ai->cmdReturn;
}

int TR_AI_CmdIfFainted(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareFainted(vm,ai,2); return ai->cmdReturn;
}

int TR_AI_CmdIfNotFainted(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareFainted(vm,ai,3); return ai->cmdReturn;
}

int TR_AI_CompareFainted(ScriptVm *vm, TrAiWork *ai, int op) {
    int side;
    int jumpOffset;
    side = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    return TR_AI_Compare(vm, op, BTL_POKEPARAM_IsFainted(TR_AI_GetPoke(ai, TR_AI_GetPosition(ai, side))), 1, jumpOffset);
}

int TR_AI_CmdLoadPokeValue17(ScriptVm *vm, TrAiWork *ai) {
    int selector; u8 pos; selector = VM_GetU32(vm); pos = TR_AI_GetPosition(ai,selector); ai->workValue = func_021D59B4(TR_AI_GetPoke(ai,pos),17); return ai->cmdReturn;
}

int TR_AI_CmdJumpIfSubstitute(ScriptVm *vm, TrAiWork *ai) {
    int side; u32 jumpOffset; u8 pos; side = VM_GetU32(vm); jumpOffset = VM_GetU32(vm); pos = TR_AI_GetPosition(ai,side); if (BTL_POKEPARAM_HasSubstitute(TR_AI_GetPoke(ai,pos))) VM_Jump(vm, (u32)vm->pc + jumpOffset); return ai->cmdReturn;
}

int TR_AI_CmdLoadSpecies(ScriptVm *vm, TrAiWork *ai) {
    int selector; u8 pos; selector = VM_GetU32(vm); pos = TR_AI_GetPosition(ai,selector); ai->workValue = BTL_POKEPARAM_GetSpecies(TR_AI_GetPoke(ai,pos)); return ai->cmdReturn;
}

int TR_AI_CmdIfLess(ScriptVm *vm, TrAiWork *ai) {
    TR_AI_CompareGeneric(vm,ai,0); return ai->cmdReturn;
}

int TR_AI_CmdIfGreater(ScriptVm *vm, TrAiWork *ai) { TR_AI_CompareGeneric(vm,ai,1); return ai->cmdReturn; }

int TR_AI_CmdIfEqual(ScriptVm *vm, TrAiWork *ai) { TR_AI_CompareGeneric(vm,ai,2); return ai->cmdReturn; }

int TR_AI_CmdIfNotEqual(ScriptVm *vm, TrAiWork *ai) { TR_AI_CompareGeneric(vm,ai,3); return ai->cmdReturn; }

/*
 * Two-byte zero alignment padding follows the compiled function.
 */
int TR_AI_CompareGeneric(ScriptVm *vm, TrAiWork *ai, int op) { int compareValue,jumpOffset; compareValue=VM_GetU32(vm); jumpOffset=VM_GetU32(vm); return TR_AI_Compare(vm,op,ai->randomByte,compareValue,jumpOffset); }

int TR_AI_CmdJumpIfMoveParam28(ScriptVm *vm, TrAiWork *ai) {
    int mode;
    int threshold;
    int tableOffset;
    u16 *table;
    int index;
    int flag;
    mode = VM_GetU32(vm);
    threshold = VM_GetU32(vm);
    tableOffset = VM_GetU32(vm);
    table = (u16 *)(vm->pc + tableOffset);
    flag = 0;
    if (mode == 0) {
        index = TR_AI_GetMoveParam(ai, ai->moveId, 0x1c) * 2;
        if (index / 2 > threshold)
            flag = 1;
    } else {
        flag = 1;
    }
    if (flag == 1)
        return TR_AI_CmdEnd(vm, ai);
    VM_Jump(vm, (u32)((u8 *)table + (table[index] | (table[index + 1] << 16))));
    return ai->cmdReturn;
}

int TR_AI_CmdJumpIfFieldEffect(ScriptVm *vm, TrAiWork *ai) {
    int side;
    int jumpOffset;
    side = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    if (BTL_SERVER_FLOW_CheckFieldEffectActive(ai->serverFlow, TR_AI_GetPosition(ai, side), 3) != 0)
        VM_Jump(vm, (u32)(vm->pc + jumpOffset));
    return ai->cmdReturn;
}

int TR_AI_CmdCompareStat0(ScriptVm *vm, TrAiWork *ai) { TR_AI_CompareStat(vm,ai,0); return ai->cmdReturn; }

int TR_AI_CmdCompareStat1(ScriptVm *vm, TrAiWork *ai) { TR_AI_CompareStat(vm,ai,1); return ai->cmdReturn; }

int TR_AI_CmdCompareStat2(ScriptVm *vm, TrAiWork *ai) { TR_AI_CompareStat(vm,ai,2); return ai->cmdReturn; }

int TR_AI_CompareStat(ScriptVm *vm, TrAiWork *ai, int op) {
    int side;
    int jumpOffset;
    u8 pos;
    side = VM_GetU32(vm);
    jumpOffset = VM_GetU32(vm);
    pos = TR_AI_GetPosition(ai, side);
    func_021D59B4(TR_AI_GetPoke(ai, pos), 8);
    return TR_AI_Compare(vm, op, pos, func_021D59B4(TR_AI_GetPoke(ai, pos), 10), jumpOffset);
}

int TR_AI_Compare(ScriptVm *vm, int op, int left, int right, int jumpOffset) {
    int result = 0;
    switch (op) {
    case 0:
        if (left < right)
            result = 1;
        break;
    case 1:
        if (left > right)
            result = 1;
        break;
    case 2:
        if (left == right)
            result = 1;
        break;
    case 3:
        if (left != right)
            result = 1;
        break;
    case 4:
        if (left & right)
            result = 1;
        break;
    case 5:
        if (!(left & right))
            result = 1;
        break;
    case 6:
        if (left <= right)
            result = 1;
        break;
    case 7:
        if (left >= right)
            result = 1;
        break;
    }
    if (result == 1)
        VM_Jump(vm, (u32)(vm->pc + jumpOffset));
    return result;
}

u8 TR_AI_GetPosition(TrAiWork *ai, int kind) {
    u32 lane;
    switch (kind) {
    case 1:
        return ai->selfPos;
    default:
    case 0:
        return ai->targetPos;
    case 3:
        switch (ai->rule) {
        case 0:
        case 3:
            return ai->selfPos;
        case 1:
            return 2 ^ ai->selfPos;
        case 2:
            lane = (u32)ai->selfPos >> 1;
            if (lane != 2)
                lane = lane + 1;
            else
                lane = 1;
            return BTL_MAIN_GetOwnLanePos(ai->selfPos, (u8)lane);
        }
        break;
    case 2:
        switch (ai->rule) {
        case 0:
        case 3:
            return ai->targetPos;
        case 1:
            return 2 ^ ai->targetPos;
        case 2:
            lane = (u32)ai->targetPos >> 1;
            if (lane != 2)
                lane = lane + 1;
            else
                lane = 1;
            return BTL_MAIN_GetOwnLanePos(ai->targetPos, (u8)lane);
        }
        break;
    }
}

/*
 * 2026-10-04 (wave D2 lane 08): re-tested, still MATCH: 11 of 12 relocations resolve; the only open site is BTLV_EFFECT_GetPokeEffectValue (+002E). The symbols line already carries 'thumb ov094', but the sole witness src/matched/ov/ov094_func_021F8AE8.c lists four 'function:' keys and the parser keeps only the last, so 0x021F8AFC has no witness. Fix belongs in that unit's header or the parser (outside this lane's write set); bytes are correct.
 * its parsed function list: four repeated keys leave only BTLV_EFFECT_ResumeVmWait.
 * Concrete bytes correct; caller-only tu suggest-split has no viable cut.
 * lever: advance p itself before indexed store; random draw helper owns
 * its u64 temporary and returns u32 (random-below-n existing idiom).
 */
int TR_AI_GetAbility(TrAiWork *ai, int kind, u8 pos) {
    void *poke;
    int value, form;
    u32 ability0, ability1, ability2, abilityCount;
    u32 abilities[3];
    poke = (void *)TR_AI_GetPoke(ai, pos);
    if (BTL_POKEPARAM_HasSick(poke, 0x10) != 0)
        return 0;
    if (kind == 0 || kind == 2) {
        ai->abilityCache[pos] = BTLV_EFFECT_GetPokeEffectValue(pos);
        if (ai->abilityCache[pos] != 0)
            return ai->abilityCache[pos];
        value = func_021D59B4(poke, 0x10);
        if (value == 0x17 || value == 0x2a || value == 0x47)
            return value;
        value = BTL_POKEPARAM_GetSpecies(poke);
        form = func_021D59B4(poke, 0x13);
        abilityCount = 0;
        ability0 = func_02019C90(value, form, 0x1a);
        ability1 = func_02019C90(value, form, 0x1b);
        ability2 = func_02019C90(value, form, 0x1c);
        if (ability0 != 0) abilities[abilityCount++] = ability0;
        if (ability1 != 0) abilities[abilityCount++] = ability1;
        if (ability2 != 0) abilities[abilityCount++] = ability2;
        return abilities[draw_below(abilityCount)];
    }
    return func_021D59B4(poke, 0x10);
}

/*
 * Resolved by the BTL_SIDE_GetPokeAtPos label in ov069 (thumb); cross-overlay target.
 */
struct BtlPokeParam *TR_AI_GetPoke(TrAiWork *ai, u8 pos) { return BTL_SIDE_GetPokeAtPos(ai->sideTable, pos); }

/*
 * Resolved by the matched BTL_SLOT_GetPokeParam in ov093 (thumb); cross-overlay target.
 */
struct BtlPokeParam *TR_AI_GetSlotPoke(void *slots, u32 index) { return BTL_SLOT_GetPokeParam(slots, index); }

void TR_AI_ResetScores(TrAiWork *ai) { int i; for (i = 0; i < 4; i++) ai->moveScores[i] = ai->baseScores[i]; }

void TR_AI_RememberLastMove(TrAiWork *ai) {
    struct BtlPokeParam *poke;
    int i;
    u16 knownMove;
    poke = TR_AI_GetPoke(ai, ai->targetPos);
    for (i = 0; i < 4; i++) {
        knownMove = ai->knownMoves[ai->targetPos][i];
        if (knownMove == BTL_POKEPARAM_GetLastUsedMoveId(poke))
            return;
        if (knownMove == 0) {
            ai->knownMoves[ai->targetPos][i] =BTL_POKEPARAM_GetLastUsedMoveId(poke);
            return;
        }
    }
}

int TR_AI_GetMoveParam(TrAiWork *ai, int moveId, int param) { return WAZA_TOOL_GetParam(moveId, param); }

int TR_AI_GetMoveFlag(void *ai, int moveId, int flag) { return WAZA_TOOL_GetFlag(moveId, flag); }

/*
 * 2026-10-04 (wave D2 lane 08): re-tested, still DIFF (10 bytes, size 98 vs 100). Image order in the loop call: str r7,[sp,#4]; ldr r0,[sp,#8]; ldr r1,[sp,#0x10]; adds r0,#0xb4; ldr r0,[r0]; ldr r2. Ours loads a first, then the field, then x. Also tried const-qualified first parameter (callee and function) and a split pointer/xx copy; the compiler folds them back.
 * note: 2026-10-04 Residue: store order only. Original stores the stack arg d ([sp,#4]) before reloading spilled a ([sp,#8]) for the first call argument; ours loads a first. Tried: struct field, ptr casts, local hoist, u32/int d, u16 callee return, while loop, temp for the 54C0 result.
 * note: 2026-10-05 (wD4 lane20): tried the first argument and the 54C0 result as separate locals before the call (c = f(b,i); q = *(a+0xB4); g(q,x,y,c,1,d)) and a u32 first parameter; same 10 bytes (ldr r0,[sp,#8] still ahead of str r7,[sp,#4]).
 * 2026-10-05 (wD5 lane20): no new variant closed it. Reading: original emits the stack argument store (str r7,[sp,#4]) before the spilled-a reload and the field address chain; ours starts the chain first. Same 10 bytes as before; the sibling TR_AI_CmdLoadMoveDamageRank shows the same tie-break in its loop call, so a common cause (IR order of stack-argument stores versus argument 0) is likely.
 * 2026-10-05 (wD6 lane15): EXACT*. BTL_SERVER_FLOW_CalcPredictedMoveDamage takes u8 a, u8 b (as in matched TR_AI_CmdLoadBestDamagePoke)
 *   and x, y are u8 locals; that fixes the stack-argument store order in the loop call.
 */
u32 TR_AI_GetBestDamage(TrAiWork *ai, struct BtlPokeParam *attacker, struct BtlPokeParam *defender, int flags) {
    u32 best = 0;
    u8 attackerId = BTL_POKEPARAM_GetPokeId(attacker);
    u8 defenderId = BTL_POKEPARAM_GetPokeId(defender);
    int i;
    for (i = 0; i < (int)BTL_POKEPARAM_GetMoveCount(attacker); i++) {
        u32 damage = BTL_SERVER_FLOW_CalcPredictedMoveDamage(ai->serverFlow, attackerId, defenderId, (u32)BTL_POKEPARAM_GetMoveId(attacker, (u8)i), 1, flags);
        if (damage > best)
            best = damage;
    }
    return best;
}

/*
 * The apparent register-scheduling residue was a missing third argument:
 *   the image keeps `b` (r1) live and loads the halfword into r2, which is
 *   only possible if the callee takes (field, b, h).  func_02020F20 is
 *   declared with the extra `int` argument and the call passes `b`.
 *   EXACT* because the follower at 0x0218A41A is an unlabelled `movs r0,r0`
 *   pad.
 */
int TR_AI_GetItemField(TrAiWork *ai, int itemId, int field) {
    u16 heapId;
    void *itemData;
    int value;
    heapId = ai->heapId;
    itemData = func_02020F20(ai->itemArchive, itemId, heapId);
    value = FILE_UTIL_Get_1014(itemData, field);
    func_020307B0(itemData);
    return value;
}

void TR_AI_InitScriptCache(u32 heapId) { int i; if(gTrAiScriptCache==0) { gTrAiScriptCache=func_02030734(heapId,24,1,gTrAiAllocSite,3999); for(i=0;i<4;i++) gTrAiScriptCache->id[i]=255; } }

void TR_AI_FreeScriptCache(void) { int i; int zero; if(gTrAiScriptCache!=0) { zero=0; for(i=0;i<4;i++) { if(gTrAiScriptCache->obj[i]!=0) { func_020307B0(gTrAiScriptCache->obj[i]); gTrAiScriptCache->obj[i]=(void *)zero; } } func_020307B0(gTrAiScriptCache); gTrAiScriptCache=0; } }

void *TR_AI_LoadScript(TrAiWork *ai) {
    int i;
    u32 archiveHeap;

    for (i = 0; i < 4; i++) {
        if (gTrAiScriptCache->id[i] == ai->scriptId) {
            gTrAiScriptCache->ref[i]++;
            return gTrAiScriptCache->obj[i];
        }
    }
    for (i = 0; i < 4; i++) {
        if (gTrAiScriptCache->id[i] == 0xff)
            break;
    }
    if (ai->scriptId == 2)
        archiveHeap = (u16)((ai->heapId & 0x7fff) | 0x8000);
    else
        archiveHeap = ai->heapId;
    gTrAiScriptCache->id[i] = ai->scriptId;
    gTrAiScriptCache->ref[i]++;
    gTrAiScriptCache->obj[i] = ARC_TOOL_LoadHandleMember(ai->scriptArchive, ai->scriptId, (u16)archiveHeap);
    return gTrAiScriptCache->obj[i];
}

void TR_AI_ReleaseScript(TrAiWork *ai) {
    int i;

    for (i = 0; i < 4; i++) {
        if (gTrAiScriptCache->id[i] == ai->scriptId) {
            gTrAiScriptCache->ref[i]--;
            if (gTrAiScriptCache->ref[i] == 0) {
                gTrAiScriptCache->id[i] = 0xff;
                func_020307B0(gTrAiScriptCache->obj[i]);
                gTrAiScriptCache->obj[i] = 0;
            }
            return;
        }
    }
}
