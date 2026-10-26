#ifndef GAME_OV020_FIELD_WFBC_DATA_LOCAL_H
#define GAME_OV020_FIELD_WFBC_DATA_LOCAL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_wfbc_data_local.c, prototypes copied from their definitions. */

struct Mmdl;
struct MyStatus;
struct GameData;
struct ScrcmdWork;
struct GameEvent;
struct GameSystem;

#include "../ov020/field_wfbc_data_local_types.h"
#include "../types.h"
#include "../ov010/fldmmdl_types.h"
#include "../arm9/script_vm_types.h"

int FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl(struct Mmdl *mmdl);
void FIELD_WFBC_DATA_LOCAL_ClearPeopleList(WfbcData *data);
void FIELD_WFBC_DATA_LOCAL_ClearBackPeopleList(WfbcData *data);
void FIELD_WFBC_DATA_LOCAL_Init(WfbcData *data, const struct MyStatus *myStatus, int heapSeed);
int FIELD_WFBC_DATA_LOCAL_IsFullyPopulated(WfbcData *data);
void FIELD_WFBC_DATA_LOCAL_Sanitize(WfbcData *data, const struct MyStatus *myStatus);
int FIELD_WFBC_DATA_LOCAL_IsDataComplete(WfbcData *data);
int FIELD_WFBC_DATA_LOCAL_CountPeople(const WfbcData *data, int which);
void FIELD_WFBC_DATA_LOCAL_AdvanceDays(struct GameData *gameData, int days, u32 heapSeed);
void FIELD_WFBC_DATA_LOCAL_MoveBoredPeopleToBackList(struct GameData *gameData);
void FIELD_WFBC_DATA_LOCAL_ApplyTalkedMoodBonus(u8 *data);
void FIELD_WFBC_DATA_LOCAL_InsertPersonForCity(WfbcData *data, const struct MyStatus *myStatus, WfbcPerson *person);
MmdlHeader *FIELD_WFBC_DATA_LOCAL_CreateMmdlHeaders(WfbcData *data, int which, int heapSeed);
void FIELD_WFBC_DATA_LOCAL_FillPeopleListEntries(const WfbcData *data, WfbcListEntry *entries, u16 *entryCount, int page, u16 heapId);
void FIELD_WFBC_DATA_LOCAL_ValidatePerson(WfbcPerson *person);
void FIELD_WFBC_DATA_LOCAL_ApplyGiftMoodBonus(WfbcPerson *person);
void FIELD_WFBC_DATA_LOCAL_ClearArrivalFlag(WfbcPerson *person);
int FIELD_WFBC_DATA_LOCAL_HasArrivalFlag(const WfbcPerson *person);
void FIELD_WFBC_DATA_LOCAL_SetPersonParent(WfbcPerson *person, const struct MyStatus *myStatus);
int FIELD_WFBC_DATA_LOCAL_HasParent(const WfbcPerson *person);
int FIELD_WFBC_DATA_LOCAL_GetNpcId(const WfbcPerson *person);
int FIELD_WFBC_DATA_LOCAL_IsMoodLow(const WfbcPerson *person);
WfbcNpcData *FIELD_WFBC_DATA_LOCAL_OpenNpcData(int fileId, int heapId);
void FIELD_WFBC_DATA_LOCAL_CloseNpcData(WfbcNpcData *npcData);
void FIELD_WFBC_DATA_LOCAL_LoadNpcData(WfbcNpcData *npcData, u32 fileId);
WfbcNpcRecord *FIELD_WFBC_DATA_LOCAL_GetNpcRecord(WfbcNpcData *npcData);
WfbcPosition *FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable(WfbcNpcData *npcData, int cityType, unsigned int heapId);
void FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable(WfbcPosition *positions);
WfbcPosition *FIELD_WFBC_DATA_LOCAL_GetPositionPair(WfbcPosition *positions, int index);
WfbcPosition *FIELD_WFBC_DATA_LOCAL_GetItemPositionPair(WfbcPosition *positions, int index);
int FIELD_WFBC_DATA_LOCAL_CountItemSlots(const u16 *itemSlots);
int FIELD_WFBC_DATA_LOCAL_SetItemSlotIfEmpty(u16 *itemSlots, u16 itemId, int slot);
u16 FIELD_WFBC_DATA_LOCAL_GetItemSlot(const u16 *itemSlots, int slot);
int FIELD_WFBC_DATA_LOCAL_IsItemSlotUsed(const u16 *itemSlots, int slot);
MmdlHeader *FIELD_WFBC_DATA_LOCAL_CreateItemMmdlHeaders(u16 *itemSlots, int which, int cityType, int heapSeed);
u16 FIELD_WFBC_DATA_LOCAL_GetCounter(const WfbcDailyState *dailyState);
void FIELD_WFBC_DATA_LOCAL_IncCounter(WfbcDailyState *dailyState);
u16 FIELD_WFBC_DATA_LOCAL_GetValue(const WfbcDailyState *dailyState);
void FIELD_WFBC_DATA_LOCAL_AddValuePoints(WfbcDailyState *dailyState);
u16 FIELD_WFBC_DATA_LOCAL_ReadValue(const WfbcDailyState *dailyState);
void FIELD_WFBC_DATA_LOCAL_WriteValue(WfbcDailyState *dailyState, u16 value);
u16 FIELD_WFBC_DATA_LOCAL_ReadCounter(const WfbcDailyState *dailyState);
void FIELD_WFBC_DATA_LOCAL_WriteCounter(WfbcDailyState *dailyState, u16 counter);
WfbcNpcRecord *FIELD_WFBC_DATA_LOCAL_PickNpcByWeight(const WfbcData *data, int limit, WfbcNpcData *npcData, int *outNpcId);
int FIELD_WFBC_DATA_LOCAL_GetNthAbsentNpcId(const WfbcData *data, int nth);
int FIELD_WFBC_DATA_LOCAL_IsNpcPresent(const WfbcData *data, int npcId);
void FIELD_WFBC_DATA_LOCAL_InsertPerson(WfbcData *data, const struct MyStatus *myStatus, WfbcPerson *person, int setParent);
int FIELD_WFBC_DATA_LOCAL_IsPeopleListFull(const WfbcPerson *list);
WfbcPerson *FIELD_WFBC_DATA_LOCAL_PushPersonFront(WfbcPerson *list, const WfbcPerson *person);
WfbcPerson *FIELD_WFBC_DATA_LOCAL_FindEmptyPersonSlot(WfbcPerson *list);
void FIELD_WFBC_DATA_LOCAL_InitNewPerson(WfbcPerson *person, int npcId, const struct MyStatus *myStatus, int mood, int setParent);
int FIELD_WFBC_DATA_LOCAL_IsMoodZero(const WfbcPerson *person);
int FIELD_WFBC_DATA_LOCAL_AddMood(WfbcPerson *person, int delta);
void FIELD_WFBC_DATA_LOCAL_SetMood(WfbcPerson *person, int mood);
int FIELD_WFBC_DATA_LOCAL_ScrCmdMarkFacingPerson(ScriptVm *vm, struct ScrcmdWork *work);
int FIELD_WFBC_DATA_LOCAL_ScrCmdCheckAndMarkFacingPerson(ScriptVm *vm, struct ScrcmdWork *work);
int FIELD_WFBC_DATA_LOCAL_ScrCmdSetFacingPersonParam(ScriptVm *vm, struct ScrcmdWork *work);
int FIELD_WFBC_DATA_LOCAL_ScrCmdGetWfbcValue(ScriptVm *vm, struct ScrcmdWork *work);
int FIELD_WFBC_DATA_LOCAL_ScrCmdAddPoints(ScriptVm *vm, struct ScrcmdWork *work);
int FIELD_WFBC_DATA_LOCAL_ScrCmdFindTargetPokemonInParty(ScriptVm *vm, struct ScrcmdWork *work);
int FIELD_WFBC_DATA_LOCAL_ScrCmdGetFacingPersonMessageIndex(ScriptVm *vm, struct ScrcmdWork *work);
int FIELD_WFBC_DATA_LOCAL_ScrCmdCallPersonTalkEvent(ScriptVm *vm, struct ScrcmdWork *work);
struct GameEvent *FIELD_WFBC_DATA_LOCAL_CreatePersonTalkEvent(struct GameSystem *gameSystem, void *fieldSystem);
int FIELD_WFBC_DATA_LOCAL_PersonTalkEventMain(struct GameEvent *event, int *state, void *work);
void FIELD_WFBC_DATA_LOCAL_StartTalkMessage(WfbcTalkEvent *talk, int messageSlot, int *state, int nextState);
void FIELD_WFBC_DATA_LOCAL_StartTalkMessageWithChoice(WfbcTalkEvent *talk, int messageSlot, int *state, int yesStateId, u16 noStateId);
int FIELD_WFBC_DATA_LOCAL_UpdateTalkMessage(WfbcTalkEvent *talk);
int FIELD_WFBC_DATA_LOCAL_FreeTalkMessage(WfbcTalkEvent *talk);
/* END mkheaders: generated region */

#endif
