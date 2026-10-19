#ifndef HAND_COMMON_PROTOS_H
#define HAND_COMMON_PROTOS_H
/*
 * ov093 ability and move handlers: the one prototype of each battle service that
 * several handler files call.
 */
#include "hand_common_types.h"

struct BtlServerFlow;
struct BtlParty;
struct BtlHitRecord;

/* Services of the event variable stack and of the event factors. */
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern void BTL_EVENT_MultiplyVar(int key, s32 multiplier);
extern void BTL_EVENT_SetFactorSkipCheck(struct BtlEventFactor *factor, BtlEventSkipCheck skipCheck);

/* Services of the battle main object. */
extern u8 BTL_MAIN_IsPokeIdInSecondPair(u32 pokeId);
extern int BTL_MAIN_IsPokeSamePair(u32 pokeIdA, u32 pokeIdB);

/* Services of the battle server flow. */
extern int BTL_SERVER_FLOW_AreAllOtherActionsDone(struct BtlServerFlow *flow, int pokeId);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *message, int strType, int strId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(void *message, u32 arg);
extern u8 BTL_SERVER_FLOW_CollectAlivePokeIds(struct BtlServerFlow *flow, int posKey, u8 *outPokeIds);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(struct BtlServerFlow *flow, int kind, int pokeId);
extern void BTL_SERVER_FLOW_CommitCmdRecord(struct BtlServerFlow *flow, void *record);
extern void BTL_SERVER_FLOW_PushCmdRecord(struct BtlServerFlow *flow, int kind, int pokeId);
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlServerFlow *flow, int pokeId);
extern int BTL_SERVER_FLOW_GetPokeViewPos(struct BtlServerFlow *flow, int pokeId);
extern u8 *BTL_SERVER_FLOW_GetScratchBuffer(struct BtlServerFlow *flow, int bufferId);
extern void BTL_SERVER_FLOW_SetCurTurnStateFlag(struct BtlServerFlow *flow, int flag);

/* Services of the move data. */
extern u32 WAZA_TOOL_GetFlag(u16 moveId, u32 flagBit);

/* Services of the volatile condition records and of the battle viewer slots. */
extern union SickCont BTL_SICKCONT_MakeKind1Empty(void);
extern union SickCont BTL_SICKCONT_MakeKind2(int turns, int moveId);
extern union SickCont BTL_SICKCONT_MakeKind2Index(int turns);
extern union SickCont BTL_SICKCONT_MakeKind3(int pokeId);
extern void BTL_SICKCONT_SetValue(union SickCont *slot, u16 value);
extern u16 BTL_TYPEPAIR_MakeSingle(int value);
extern union SickCont BTL_CALC_MakeDefaultSickCont(int sickKind);

/* Services of the poke parameter. */
extern u16 BTL_POKEPARAM_GetItem(struct BtlPokeParam *bpp);
extern u16 BTL_POKEPARAM_GetSpecies(struct BtlPokeParam *bpp);
extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *bpp, int sickKind);
extern int BTL_POKEPARAM_IsFainted(struct BtlPokeParam *bpp);
extern u8 BTL_POKEPARAM_FindMoveSlot(struct BtlPokeParam *bpp, int moveId);
extern u8 BTL_POKEPARAM_GetCounter(struct BtlPokeParam *bpp, int counterId);
extern int BTL_POKEPARAM_GetHitRecord(const struct BtlPokeParam *bpp, int turnsAgo, u32 hitsAgo, struct BtlHitRecord *out);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct BtlPokeParam *bpp);
extern u8 BTL_POKEPARAM_GetPokeId(struct BtlPokeParam *bpp);
extern int BTL_POKEPARAM_TestContFlag(struct BtlPokeParam *bpp, u32 flag);
extern int BTL_POKEPARAM_TestTurnFlag(struct BtlPokeParam *bpp, u32 flag);
extern int BTL_POKEPARAM_GetValue(struct BtlPokeParam *bpp, int valueId);

/* Services declared by several handler files (kept identical so the files can be merged). */
extern struct BtlEventFactor *BTL_EVENT_AddFactor(int factorType, u32 key, int priority, u32 subPriority, u8 ownerId, BtlEventHandler *handlers, u16 handlerCount);
extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 value);
extern void BTL_EVENT_RemoveFactor(struct BtlEventFactor *factor);
extern void BTL_EVENT_MarkFactorDead(struct BtlEventFactor *factor);
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(struct BtlServerFlow *flow);
extern int BTL_SERVER_FLOW_GetRule(struct BtlServerFlow *flow);
extern u16 BTL_SERVER_FLOW_GetFrontPosOfPoke(struct BtlServerFlow *flow, int pokeId);
extern struct BtlParty *BTL_SERVER_FLOW_GetPartyOfPoke(struct BtlServerFlow *flow, int pokeId);
extern int BTL_SERVER_FLOW_DecideMoveTarget(struct BtlServerFlow *flow, int pokeId, int moveId);
extern int BTL_SERVER_FLOW_GetActionWordByPokeId(struct BtlServerFlow *flow, int pokeId, u32 *actionWord);
extern u8 BTL_SERVER_FLOW_CollectOpponentPokeIds(struct BtlServerFlow *flow, int pokeId, u8 *outFoeIds);
extern u32 BTL_ACTION_GetFightMove(u32 *actionWord);
extern u8 BTL_MAIN_GetEnemyLanePos(int rule, u32 position, u32 lane);
extern u8 BTL_SLOT_GetCount(struct BtlParty *party);
extern struct BtlPokeParam *BTL_SLOT_GetPokeParam(struct BtlParty *party, u32 index);
extern int BTL_POKEPARAM_GetMovePPChecked(struct BtlPokeParam *bpp, u32 moveSlot);
extern u16 BTL_POKEPARAM_GetLastUsedMoveId(struct BtlPokeParam *bpp);
extern int BTL_POKEPARAM_HasType(struct BtlPokeParam *bpp, int typeId);
extern int BTL_CALC_DivideMaxHpMin1(struct BtlPokeParam *bpp, u32 divisor);
extern u32 BTL_CALC_GetMonParamWithHeap(u32 itemId, u32 paramId);
extern u32 WAZA_TOOL_IsDamaging(u32 moveId);
extern int BTL_ID_IsMetronomeItemIgnoredMove(u16 moveId);
extern void HAND_TOKUSEI_BlockStatDrop(struct BtlServerFlow *flow, int pokeId, int *work, int blockedCause);
extern void HAND_TOKUSEI_ShowStatDropGuardMessage(struct BtlServerFlow *flow, int pokeId, int *work, int stringId);
extern int HAND_TOKUSEI_AbsorbCheckMoveType(struct BtlServerFlow *flow, int pokeId, int moveType);
extern void HAND_TOKUSEI_AbsorbRaiseStat(struct BtlServerFlow *flow, int pokeId, u32 statId, int amount);
extern void HAND_WAZA_RemoveMoveHandlerById(int ownerId, int moveId);
extern void HAND_WAZA_ProtectIncrementStreak(struct BtlServerFlow *flow, int pokeId, int silent);

/* Item tests of overlay 095 (Arceus plates and Genesect drives). */
extern int BTL_ID_IsArceusPlate(int itemId);
extern int BTL_ID_IsGenesectDrive(int itemId);

/* Shared helpers of the ability, item and move handlers (hand_common.c). */
extern int HAND_COMMON_IsMoveTarget(int pokeId);
extern int HAND_COMMON_IsLastToAct(struct BtlServerFlow *flow, int pokeId);
extern int HAND_COMMON_IsItemBoundToSpecies(int speciesId, int itemId);

#endif
