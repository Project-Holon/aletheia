#ifndef GAME_OV021_FIELD_WFBC_H
#define GAME_OV021_FIELD_WFBC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_wfbc.c, prototypes copied from their definitions. */

struct BuildModelMan;
struct FieldG3dMap;
struct EventDataSystem;
struct FieldCamera;
struct MmdlSys;
struct WordSet;
struct WfbcNpcData;

#include "../ov021/field_wfbc_types.h"
#include "../types.h"
#include "../ov020/field_wfbc_data_local_types.h"

FieldWfbc *FIELD_WFBC_Create(u32 heapId);
u32 FIELD_WFBC_Delete(FieldWfbc *wfbc);
int FIELD_WFBC_GetPeopleNum(FieldWfbc *wfbc);
void FIELD_WFBC_WriteSaveData(FieldWfbc *wfbc, WfbcData *saveData);
void FIELD_WFBC_ReloadSaveData(FieldWfbc *wfbc);
FieldWfbcPeople *FIELD_WFBC_GetPeople(FieldWfbc *wfbc, u32 npcId);
u8 FIELD_WFBC_GetCityType(FieldWfbc *wfbc);
u8 FIELD_WFBC_IsBackPeople(FieldWfbc *wfbc);
int FIELD_WFBC_PatchLandData(FieldWfbc *wfbc, void *attrBuf, struct BuildModelMan *buildModelMan, struct FieldG3dMap *mapBlockIndex, int modelNum, int cellX, int cellZ, u16 heapId);
void FIELD_WFBC_DisableUnusedConnects(FieldWfbc *wfbc, struct EventDataSystem *eventData, int skip, u32 heapId);
void FIELD_WFBC_SetUpCamera(FieldWfbc *wfbc, struct FieldCamera *camera, int heapId);
void FIELD_WFBC_SetMmdlSys(FieldWfbc *wfbc, struct MmdlSys *mmdlSys);
void FIELD_WFBC_SetUp(FieldWfbc *wfbc, WfbcData *saveData, u32 isBackPeople, u32 heapId);
void FIELD_WFBC_RemovePeople(FieldWfbc *wfbc, u32 npcId);
void FIELD_WFBC_ApplyGiftMood(FieldWfbc *wfbc, u32 npcId);
void FIELD_WFBC_SetWordSetParentName(FieldWfbc *wfbc, struct WordSet *wordSet, int npcId, int bufIndex, u16 heapId);
void FIELD_WFBC_ClearPeopleArrivalFlag(FieldWfbc *wfbc, u32 npcId);
int FIELD_WFBC_GetPeopleArrivalFlag(FieldWfbc *wfbc, u32 npcId);
WfbcNpcRecord *FIELD_WFBC_PEOPLE_GetNpcRecord(FieldWfbcPeople *people);
WfbcPerson *FIELD_WFBC_PEOPLE_GetPersonData(FieldWfbcPeople *people);
void FIELD_WFBC_LoadResources(FieldWfbc *wfbc, int heapId);
void FIELD_WFBC_FreeResources(FieldWfbc *wfbc);
void FIELD_WFBC_Clear(FieldWfbc *wfbc);
int FIELD_WFBC_CountPeople(FieldWfbc *wfbc);
void FIELD_WFBC_SetUpPeople(FieldWfbc *wfbc, WfbcData *saveData, int isBackPeople);
void FIELD_WFBC_CopyPeopleToSaveData(FieldWfbc *wfbc, WfbcData *saveData);
void FIELD_WFBC_LoadSaveData(FieldWfbc *wfbc);
void FIELD_WFBC_StoreSaveData(FieldWfbc *wfbc);
FieldWfbcPeople *FIELD_WFBC_FindPeople(FieldWfbc *wfbc, u32 npcId);
FieldWfbcPeople *FIELD_WFBC_FindPeopleByNpcId(FieldWfbc *wfbc, u32 npcId);
void FIELD_WFBC_PEOPLE_Clear(FieldWfbcPeople *people);
void FIELD_WFBC_PEOPLE_SetUp(FieldWfbcPeople *people, const WfbcPerson *person, const WfbcPosition *gridPos, const WfbcNpcRecord *npcRecord);
void FIELD_WFBC_PEOPLE_LoadPerson(FieldWfbcPeople *people, const WfbcPerson *src);
void FIELD_WFBC_PEOPLE_StorePerson(FieldWfbcPeople *people, WfbcPerson *dst);
void FIELD_WFBC_BLOCK_ClearRand(FieldWfbcBlockRand *blockRand);
void FIELD_WFBC_BLOCK_InitRand(FieldWfbcBlockRand *blockRand, WfbcData *data, struct WfbcNpcData *npcData);
/* END mkheaders: generated region */

#endif
