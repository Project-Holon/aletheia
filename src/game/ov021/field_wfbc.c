/*
 * file:     field_wfbc.c
 * unit:     yes
 * function: FIELD_WFBC_Create, FIELD_WFBC_Delete, FIELD_WFBC_GetPeopleNum, FIELD_WFBC_WriteSaveData, FIELD_WFBC_ReloadSaveData, FIELD_WFBC_GetPeople, FIELD_WFBC_GetCityType, FIELD_WFBC_IsBackPeople, FIELD_WFBC_PatchLandData, FIELD_WFBC_DisableUnusedConnects, FIELD_WFBC_SetUpCamera, FIELD_WFBC_SetMmdlSys, FIELD_WFBC_SetUp, FIELD_WFBC_RemovePeople, FIELD_WFBC_ApplyGiftMood, FIELD_WFBC_SetWordSetParentName, FIELD_WFBC_ClearPeopleArrivalFlag, FIELD_WFBC_GetPeopleArrivalFlag, FIELD_WFBC_PEOPLE_GetNpcRecord, FIELD_WFBC_PEOPLE_GetPersonData, FIELD_WFBC_LoadResources, FIELD_WFBC_FreeResources, FIELD_WFBC_Clear, FIELD_WFBC_CountPeople, FIELD_WFBC_SetUpPeople, FIELD_WFBC_CopyPeopleToSaveData, FIELD_WFBC_LoadSaveData, FIELD_WFBC_StoreSaveData, FIELD_WFBC_FindPeople, FIELD_WFBC_FindPeopleByNpcId, FIELD_WFBC_PEOPLE_Clear, FIELD_WFBC_PEOPLE_SetUp, FIELD_WFBC_PEOPLE_LoadPerson, FIELD_WFBC_PEOPLE_StorePerson, FIELD_WFBC_BLOCK_ClearGrid, FIELD_WFBC_BLOCK_SetCell, FIELD_WFBC_BLOCK_GetCell, FIELD_WFBC_BLOCK_IsPlaced, FIELD_WFBC_BLOCK_ClearRand, FIELD_WFBC_BLOCK_InitRand, FIELD_WFBC_BLOCK_BuildGrid
 * address:  0x021938AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Lane CL120 cut the tail off at 0x02194284 (field_comm_actor.c), 0x02194670 (talkmsgwin.c) and 0x02196030 (ircbattlemenu.c).
 * Split from field_wfbc.c at 0x021938AC (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm  arm9
 *   sFieldWfbcFileName     0x021DDA60  data   ov021  a1
 *   FLDMMDL_SysSetDrawEnable  0x0216D974  thumb  ov010
 *   GFL_HEAP_Free  0x020307B0  arm
 *   LAND_DATA_PATCH_Create  0x021C939C  thumb  ov021
 *   LAND_DATA_PATCH_OverwriteAttr  0x021C93E4  thumb  ov021
 *   LAND_DATA_PATCH_AddBuildModels  0x021C9450  thumb  ov021
 *   LAND_DATA_PATCH_Delete  0x021C93D0  thumb  ov021
 *   ARC_TOOL_GetHandleMemberSize  0x020493D4  arm
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 *   EVENTDATA_SYSTEM_DisableConnect  0x0216245C  thumb  ov010
 *   sConnectListMemberIds     0x021D3F60  data  a4
 *   ARC_UTIL_LoadHandleMember  0x0204A380  arm
 *   FIELD_CAMERA_SetSetting  0x0218E17C  thumb  ov021
 *   FIELD_WFBC_DATA_LOCAL_ApplyGiftMoodBonus  0x02186748  thumb  ov020
 *   MYSTATUS_Create  0x0200846C  thumb
 *   MYSTATUS_Init  0x020084A0  thumb
 *   MYSTATUS_CopyName  0x020084D4  thumb
 *   MYSTATUS_SetId  0x0200852C  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   FIELD_WFBC_DATA_LOCAL_ClearArrivalFlag  0x02186764  thumb
 *   FIELD_WFBC_DATA_LOCAL_HasArrivalFlag  0x02186770  thumb
 *   FIELD_WFBC_DATA_LOCAL_OpenNpcData  0x021867C4  thumb  ov020
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable  0x02186830  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm  arm9
 *   FIELD_WFBC_DATA_LOCAL_CloseNpcData  0x02186804  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable  0x0218683C  thumb  ov020
 *   MI_CpuFill8  0x02082BCC  arm
 *   FIELD_WFBC_DATA_LOCAL_IsDataComplete  0x0218625C  thumb  ov020
 *   EVENT_FIELD_PROCLINK_IsReturnEntryValid  0x02161ECC  thumb  ov010
 *   FIELD_WFBC_DATA_LOCAL_LoadNpcData  0x02186818  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_GetPositionPair  0x02186844  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_GetNpcRecord  0x0218682C  thumb  ov020
 *   ARC_TOOL_ReadHandleMember  0x0204932C  arm
 *   sBlockTableMemberIds     0x021D3F58  data  a4
 *   FIELD_WFBC_DATA_LOCAL_ClearPeopleList  0x0218609C  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_ClearBackPeopleList  0x021860B8  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_GetNpcId  0x021867B0  thumb  ov020
 *   MI_CpuCopy8  0x02082D44  arm  arm9
 *   FIELD_WFBC_DATA_LOCAL_CountPeople  0x02186278  thumb  ov020
 *   _u32_div_f                   0x0209C2B0  arm
 *   _ull_mul                     0x0209C054  arm
 */
struct ArcHandle;
struct EventDataSystem;
struct MmdlSys;
struct MyStatus;
struct WordSet;
struct WfbcNpcData;
struct LandDataPatch;

#include "../types.h"

#include "field_wfbc_types.h"

#include "../arm9/gfl_heap_wrap.h"
#include "../ov010/fldmmdl.h"
#include "land_data_patch.h"
#ifdef __MWERKS__
/* The original declares the heap id of the member loader as u16, so each call truncates it. */
struct ArcHandle;
void *ARC_TOOL_CreateHandle(u32 archiveID, unsigned int heapID);
void ARC_TOOL_DeleteHandle(void *handle);
void *ARC_TOOL_LoadHandleMember(struct ArcHandle *arc, u32 memberIdx, u16 heapID);
void ARC_TOOL_ReadHandleMember(struct ArcHandle *arc, u32 memberIdx, void *dst);
u32 ARC_TOOL_GetHandleMemberSize(struct ArcHandle *arc, u32 memberIdx);
#else
#include "../arm9/arc_tool.h"
#endif
#include "../ov010/eventdata_system.h"
#include "../arm9/arc_util.h"
struct FieldCamera;
#include "field_camera.h"
#include "../ov020/field_wfbc_data_local.h"
#include "../arm9/mystatus.h"
#include "../arm9/wordset.h"
struct WfbcPosition;
#include "../arm9/mi_memory.h"
#include "../ov010/event_field_proclink_return.h"
#include "../ov010/event_field_proclink_types.h"

/* The resident records have the layout of the proc link entries: the proc link function of ov010 serves both. */
static inline int WFBC_IsReturnEntryValid(const WfbcPerson *person)
{
    return EVENT_FIELD_PROCLINK_IsReturnEntryValid((ProcLinkEntry *)person);
}
FieldWfbc *FIELD_WFBC_Create(u32 heapId);
u32 FIELD_WFBC_Delete(FieldWfbc *wfbc);
int FIELD_WFBC_GetPeopleNum(FieldWfbc *wfbc);
void FIELD_WFBC_WriteSaveData(FieldWfbc *wfbc, WfbcData *saveData);
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
void FIELD_WFBC_BLOCK_ClearGrid(FieldWfbcBlock (*blocks)[8]);
void FIELD_WFBC_BLOCK_SetCell(FieldWfbcBlock (*blocks)[8], int x, int z, FieldWfbcBlockPos pos, u16 blockId);
FieldWfbcBlock FIELD_WFBC_BLOCK_GetCell(FieldWfbcBlock (*blocks)[8], int x, int z);
int FIELD_WFBC_BLOCK_IsPlaced(FieldWfbcBlock (*blocks)[8], u16 type, u16 blockId);
void FIELD_WFBC_BLOCK_ClearRand(FieldWfbcBlockRand *blockRand);
void FIELD_WFBC_BLOCK_InitRand(FieldWfbcBlockRand *blockRand, WfbcData *data, struct WfbcNpcData *npcData);
void FIELD_WFBC_BLOCK_BuildGrid(FieldWfbcBlockRand *blockRand, FieldWfbcBlockTable *table, FieldWfbcBlock (*blocks)[8]);
extern char sFieldWfbcFileName[];
extern int sConnectListMemberIds[];
extern int sBlockTableMemberIds[];

FieldWfbc *FIELD_WFBC_Create(u32 heapId)
{
    FieldWfbc *wfbc = GFL_HEAP_Alloc(heapId, sizeof(FieldWfbc), 1, sFieldWfbcFileName, 0x12A);
    FIELD_WFBC_Clear(wfbc);
    return wfbc;
}

u32 FIELD_WFBC_Delete(FieldWfbc *wfbc)
{
    FIELD_WFBC_FreeResources(wfbc);
    if (wfbc->mmdlSys != 0) {
        FLDMMDL_SysSetDrawEnable(wfbc->mmdlSys, 1);
    }
    return GFL_HEAP_Free(wfbc);
}

int FIELD_WFBC_GetPeopleNum(FieldWfbc *wfbc)
{
    return FIELD_WFBC_CountPeople(wfbc);
}

void FIELD_WFBC_WriteSaveData(FieldWfbc *wfbc, WfbcData *saveData)
{
    FIELD_WFBC_CopyPeopleToSaveData(wfbc, saveData);
}

void FIELD_WFBC_ReloadSaveData(FieldWfbc *wfbc)
{
    FIELD_WFBC_LoadSaveData(wfbc);
}

FieldWfbcPeople *FIELD_WFBC_GetPeople(FieldWfbc *wfbc, u32 npcId)
{
    if (npcId < 30) {
        return FIELD_WFBC_FindPeopleByNpcId(wfbc, npcId);
    }
    return 0;
}

u8 FIELD_WFBC_GetCityType(FieldWfbc *wfbc)
{
    return wfbc->cityType;
}

u8 FIELD_WFBC_IsBackPeople(FieldWfbc *wfbc)
{
    return wfbc->isBackPeople;
}

/*
 * The cell comes back from FIELD_WFBC_BLOCK_GetCell as a 4-byte struct in r0; the high
 * nibble is read before the low one.
 */
int FIELD_WFBC_PatchLandData(FieldWfbc *wfbc, void *attrBuf, struct BuildModelMan *buildModelMan, struct FieldG3dMap *mapBlockIndex, int modelNum, int cellX, int cellZ, u16 heapId)
{
    FieldWfbcBlock cell = FIELD_WFBC_BLOCK_GetCell(wfbc->blocks, cellX, cellZ);
    struct LandDataPatch *patch;
    int dstX, dstZ;
    int offsetX, offsetZ;

    if (cell.pos.type != 0xFF) {
        dstX = (cellX * 8) & 0x1F;
        dstZ = (cellZ * 8) & 0x1F;
        patch = LAND_DATA_PATCH_Create(cell.blockId, (u16)((heapId & 0x7FFF) | 0x8000));
        offsetZ = cell.pos.offsetZ;
        offsetX = cell.pos.offsetX;
        LAND_DATA_PATCH_OverwriteAttr(patch, attrBuf, offsetX * 8, offsetZ * 8, dstX, dstZ, 8, 8);
        if (offsetX == 0 && offsetZ == 0) {
            modelNum = LAND_DATA_PATCH_AddBuildModels(patch, buildModelMan, mapBlockIndex, modelNum, dstX, dstZ);
        }
        LAND_DATA_PATCH_Delete((void **)patch);
    }
    return modelNum;
}

void FIELD_WFBC_DisableUnusedConnects(FieldWfbc *wfbc, struct EventDataSystem *eventData, int skip, u32 heapId)
{
    u32 entryNum;
    FieldWfbcConnectEntry *entries;
    u32 *placedConnects;
    u32 placedNum;
    u32 i;
    u32 j;
    FieldWfbcConnectEntry *cur;

    if (skip != 0)
        return;
    entryNum = ARC_TOOL_GetHandleMemberSize(wfbc->arcHandle, sConnectListMemberIds[wfbc->cityType]);
    heapId = (heapId & 0x7FFF) | 0x8000;
    entries = ARC_TOOL_LoadHandleMember(wfbc->arcHandle, sConnectListMemberIds[wfbc->cityType], (u16)heapId);
    entryNum >>= 3;
    placedConnects = GFL_HEAP_Alloc((u16)heapId, entryNum * 4, 1, sFieldWfbcFileName, 0x208);
    placedNum = 0;
    for (i = 0; i < entryNum; i++) {
        cur = &entries[i];
        if (FIELD_WFBC_BLOCK_IsPlaced(wfbc->blocks, entries[i].blockType, cur->blockId)) {
            placedConnects[placedNum] = cur->connectIndex;
            placedNum++;
        } else {
            for (j = 0; j < placedNum; j++) {
                if (placedConnects[j] == entries[i].connectIndex)
                    break;
            }
            if (j >= placedNum) {
                for (j = i + 1; j < entryNum; j++) {
                    if (cur->connectIndex == entries[j].connectIndex)
                        break;
                }
                if (j >= entryNum)
                    EVENTDATA_SYSTEM_DisableConnect(eventData, (u16)cur->connectIndex);
            }
        }
    }
    GFL_HEAP_Free(placedConnects);
    GFL_HEAP_Free(entries);
}

void FIELD_WFBC_SetUpCamera(FieldWfbc *wfbc, struct FieldCamera *camera, int heapId)
{
    u16 *values;
    values = ARC_UTIL_LoadHandleMember(wfbc->arcHandle, 0x24, 0, (u16)((heapId & 0x7fff) | 0x8000));
    FIELD_CAMERA_SetSetting((struct FieldCamera *)camera, values[FIELD_WFBC_GetPeopleNum(wfbc)]);
    GFL_HEAP_Free(values);
}

void FIELD_WFBC_SetMmdlSys(FieldWfbc *wfbc, struct MmdlSys *mmdlSys)
{
    wfbc->mmdlSys = mmdlSys;
}

void FIELD_WFBC_SetUp(FieldWfbc *wfbc, WfbcData *saveData, u32 isBackPeople, u32 heapId)
{
    FIELD_WFBC_LoadResources(wfbc, heapId);
    FIELD_WFBC_SetUpPeople(wfbc, saveData, isBackPeople);
}

void FIELD_WFBC_RemovePeople(FieldWfbc *wfbc, u32 npcId)
{
    FIELD_WFBC_LoadSaveData(wfbc);
    FIELD_WFBC_PEOPLE_Clear(FIELD_WFBC_FindPeople(wfbc, npcId));
    FIELD_WFBC_StoreSaveData(wfbc);
}

void FIELD_WFBC_ApplyGiftMood(FieldWfbc *wfbc, u32 npcId)
{
    FieldWfbcPeople *people;
    FIELD_WFBC_LoadSaveData(wfbc);
    people = FIELD_WFBC_FindPeople(wfbc, npcId);
    if (wfbc->isBackPeople == 0) {
        FIELD_WFBC_DATA_LOCAL_ApplyGiftMoodBonus(&people->person);
        FIELD_WFBC_StoreSaveData(wfbc);
    }
}

void FIELD_WFBC_SetWordSetParentName(FieldWfbc *wfbc, struct WordSet *wordSet, int npcId, int bufIndex, u16 heapId)
{
    FieldWfbcPeople *people;
    struct MyStatus *myStatus;
    FIELD_WFBC_LoadSaveData(wfbc);
    people = FIELD_WFBC_FindPeopleByNpcId(wfbc, npcId);
    myStatus = MYSTATUS_Create((u16)((heapId & 0x7fff) | 0x8000));
    MYSTATUS_Init(myStatus);
    MYSTATUS_CopyName((u16 *)myStatus, people->person.parentName);
    MYSTATUS_SetId(myStatus, people->person.parentId);
    WORDSET_SetSlotMyStatus(wordSet, bufIndex, myStatus);
    GFL_HEAP_Free(myStatus);
}

void FIELD_WFBC_ClearPeopleArrivalFlag(FieldWfbc *wfbc, u32 npcId)
{
    FIELD_WFBC_LoadSaveData(wfbc);
    FIELD_WFBC_DATA_LOCAL_ClearArrivalFlag(&FIELD_WFBC_FindPeople(wfbc, npcId)->person);
    FIELD_WFBC_StoreSaveData(wfbc);
}

int FIELD_WFBC_GetPeopleArrivalFlag(FieldWfbc *wfbc, u32 npcId)
{
    FIELD_WFBC_LoadSaveData(wfbc);
    return FIELD_WFBC_DATA_LOCAL_HasArrivalFlag(&FIELD_WFBC_FindPeopleByNpcId(wfbc, npcId)->person);
}

WfbcNpcRecord *FIELD_WFBC_PEOPLE_GetNpcRecord(FieldWfbcPeople *people)
{
    return &people->npcRecord;
}

WfbcPerson *FIELD_WFBC_PEOPLE_GetPersonData(FieldWfbcPeople *people)
{
    return &people->person;
}

void FIELD_WFBC_LoadResources(FieldWfbc *wfbc, int heapId)
{
    int i;
    if (wfbc->npcData == 0) {
        i = 0;
        wfbc->npcData = FIELD_WFBC_DATA_LOCAL_OpenNpcData(0, heapId);
        wfbc->people = GFL_HEAP_Alloc(heapId, 10 * sizeof(FieldWfbcPeople), 1, sFieldWfbcFileName, 0x39e);
        for (i = 0; i < 10; i++) {
            FIELD_WFBC_PEOPLE_Clear(&wfbc->people[i]);
        }
        wfbc->arcHandle = ARC_TOOL_CreateHandle(0x9a, heapId);
        wfbc->blockTable = GFL_HEAP_Alloc(heapId, sizeof(FieldWfbcBlockTable), 1, sFieldWfbcFileName, 0x3ab);
        wfbc->mmdlPosTable = FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable(wfbc->npcData, wfbc->cityType, heapId);
    }
}

void FIELD_WFBC_FreeResources(FieldWfbc *wfbc)
{
    if (wfbc->npcData != 0) {
        FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable((struct WfbcPosition *)wfbc->mmdlPosTable);
        GFL_HEAP_Free(wfbc->blockTable);
        ARC_TOOL_DeleteHandle(wfbc->arcHandle);
        FIELD_WFBC_DATA_LOCAL_CloseNpcData(wfbc->npcData);
        GFL_HEAP_Free(wfbc->people);
        wfbc->npcData = 0;
        wfbc->people = 0;
        wfbc->arcHandle = 0;
        wfbc->blockTable = 0;
        wfbc->mmdlPosTable = 0;
    }
}

void FIELD_WFBC_Clear(FieldWfbc *wfbc)
{
    int i;
    FieldWfbcPeople *people = wfbc->people;
    wfbc->cityType = 0;
    wfbc->isBackPeople = 0;
    wfbc->saveData = 0;
    if (people != 0) {
        for (i = 0; i < 10; i++)
            FIELD_WFBC_PEOPLE_Clear(&wfbc->people[i]);
    }
    if (wfbc->blockTable != 0)
        MI_CpuFill8(wfbc->blockTable, 0, sizeof(FieldWfbcBlockTable));
    FIELD_WFBC_BLOCK_ClearGrid(wfbc->blocks);
    FIELD_WFBC_BLOCK_ClearRand(&wfbc->blockRand);
}

int FIELD_WFBC_CountPeople(FieldWfbc *wfbc)
{
    int count = 0;
    int i;
    FieldWfbcPeople *people = wfbc->people;
    if (people != 0) {
        for (i = 0; i < 10; i++) {
            if (people[i].isActive != 0)
                count++;
        }
    }
    return count;
}

/*
 * The back-list branch calls FIELD_WFBC_DATA_LOCAL_GetNpcRecord once more before the call whose
 * result it passes; the call is kept (the original code makes it).
 */
void FIELD_WFBC_SetUpPeople(FieldWfbc *wfbc, WfbcData *saveData, int isBackPeople)
{
    int i;
    const WfbcPosition *gridPos;
    FIELD_WFBC_DATA_LOCAL_IsDataComplete(saveData);
    FIELD_WFBC_Clear(wfbc);
    wfbc->cityType = saveData->cityType;
    wfbc->isBackPeople = isBackPeople;
    for (i = 0; i < 10; i++) {
        if (isBackPeople == 0) {
            if (WFBC_IsReturnEntryValid(&saveData->people[i])) {
                FIELD_WFBC_DATA_LOCAL_LoadNpcData(wfbc->npcData, saveData->people[i].npcId);
                FIELD_WFBC_PEOPLE_SetUp(&wfbc->people[i], &saveData->people[i],
                              FIELD_WFBC_DATA_LOCAL_GetPositionPair(wfbc->mmdlPosTable, i),
                              FIELD_WFBC_DATA_LOCAL_GetNpcRecord(wfbc->npcData));
            }
        } else {
            if (WFBC_IsReturnEntryValid(&saveData->backPeople[i])) {
                FIELD_WFBC_DATA_LOCAL_LoadNpcData(wfbc->npcData, saveData->backPeople[i].npcId);
                gridPos = FIELD_WFBC_DATA_LOCAL_GetPositionPair(wfbc->mmdlPosTable, i);
                FIELD_WFBC_DATA_LOCAL_GetNpcRecord(wfbc->npcData);
                FIELD_WFBC_PEOPLE_SetUp(&wfbc->people[i], &saveData->backPeople[i],
                              gridPos, FIELD_WFBC_DATA_LOCAL_GetNpcRecord(wfbc->npcData));
            }
        }
    }
    FIELD_WFBC_BLOCK_InitRand(&wfbc->blockRand, saveData, wfbc->npcData);
    if (isBackPeople == 0)
        wfbc->saveData = saveData;
    else
        wfbc->saveData = 0;
    ARC_TOOL_GetHandleMemberSize(wfbc->arcHandle, sBlockTableMemberIds[wfbc->cityType]);
    ARC_TOOL_ReadHandleMember(wfbc->arcHandle, sBlockTableMemberIds[wfbc->cityType], wfbc->blockTable);
    FIELD_WFBC_BLOCK_BuildGrid(&wfbc->blockRand, wfbc->blockTable, wfbc->blocks);
}

void FIELD_WFBC_CopyPeopleToSaveData(FieldWfbc *wfbc, WfbcData *saveData)
{
    int i;
    saveData->isValid = 1;
    saveData->cityType = wfbc->cityType;
    if (wfbc->isBackPeople == 0) {
        FIELD_WFBC_DATA_LOCAL_ClearPeopleList(saveData);
        for (i = 0; i < 10; i++)
            FIELD_WFBC_PEOPLE_StorePerson(&wfbc->people[i], &saveData->people[i]);
    } else {
        FIELD_WFBC_DATA_LOCAL_ClearBackPeopleList(saveData);
        for (i = 0; i < 10; i++)
            FIELD_WFBC_PEOPLE_StorePerson(&wfbc->people[i], &saveData->backPeople[i]);
    }
}

void FIELD_WFBC_LoadSaveData(FieldWfbc *wfbc)
{
    int i;
    if (wfbc->isBackPeople == 0 && wfbc->saveData != 0) {
        for (i = 0; i < 10; i++)
            FIELD_WFBC_PEOPLE_LoadPerson(&wfbc->people[i], &wfbc->saveData->people[i]);
    }
}

void FIELD_WFBC_StoreSaveData(FieldWfbc *wfbc)
{
    if (wfbc->isBackPeople == 0 && wfbc->saveData != 0)
        FIELD_WFBC_WriteSaveData(wfbc, wfbc->saveData);
}

FieldWfbcPeople *FIELD_WFBC_FindPeople(FieldWfbc *wfbc, u32 npcId)
{
    int i;
    if (wfbc->people != 0) {
        for (i = 0; i < 10; i++) {
            if (wfbc->people[i].isActive != 0 && npcId == FIELD_WFBC_DATA_LOCAL_GetNpcId(&wfbc->people[i].person))
                return &wfbc->people[i];
        }
    }
    return 0;
}

/* Same code as FIELD_WFBC_FindPeople; the callers use both. */
FieldWfbcPeople *FIELD_WFBC_FindPeopleByNpcId(FieldWfbc *wfbc, u32 npcId)
{
    int i;
    if (wfbc->people != 0) {
        for (i = 0; i < 10; i++) {
            if (wfbc->people[i].isActive != 0 && npcId == FIELD_WFBC_DATA_LOCAL_GetNpcId(&wfbc->people[i].person))
                return &wfbc->people[i];
        }
    }
    return 0;
}

void FIELD_WFBC_PEOPLE_Clear(FieldWfbcPeople *people)
{
    MI_CpuFill8(people, 0, sizeof(FieldWfbcPeople));
    people->isActive = 0;
}

void FIELD_WFBC_PEOPLE_SetUp(FieldWfbcPeople *people, const WfbcPerson *person, const WfbcPosition *gridPos, const WfbcNpcRecord *npcRecord)
{
    WFBC_IsReturnEntryValid(person);
    people->isActive = 1;
    MI_CpuCopy8(person, &people->person, sizeof(WfbcPerson));
    MI_CpuCopy8(npcRecord, &people->npcRecord, sizeof(WfbcNpcRecord));
    people->gridX = gridPos->x;
    people->gridZ = gridPos->z;
}

void FIELD_WFBC_PEOPLE_LoadPerson(FieldWfbcPeople *people, const WfbcPerson *src)
{
    if (people->isActive == 1) {
        MI_CpuCopy8(src, &people->person, sizeof(WfbcPerson));
    }
}

void FIELD_WFBC_PEOPLE_StorePerson(FieldWfbcPeople *people, WfbcPerson *dst)
{
    if (people->isActive == 1) {
        MI_CpuCopy8(&people->person, dst, sizeof(WfbcPerson));
    }
}

void FIELD_WFBC_BLOCK_ClearGrid(FieldWfbcBlock (*blocks)[8])
{
    int z;
    int x;
    for (z = 0; z < 8; z++) {
        for (x = 0; x < 8; x++) {
            blocks[z][x].pos.type = 0xFF;
            blocks[z][x].blockId = 0xFFFF;
        }
    }
}

/*
 * The cell holds the position as one member; the struct copy
 * blocks[z][x].pos = pos emits the two byte stores, the first one addressed
 * [x*4, row].
 */
void FIELD_WFBC_BLOCK_SetCell(FieldWfbcBlock (*blocks)[8], int x, int z, FieldWfbcBlockPos pos, u16 blockId)
{
    blocks[z][x].pos = pos;
    blocks[z][x].blockId = blockId;
}

FieldWfbcBlock FIELD_WFBC_BLOCK_GetCell(FieldWfbcBlock (*blocks)[8], int x, int z)
{
    return blocks[z][x];
}

int FIELD_WFBC_BLOCK_IsPlaced(FieldWfbcBlock (*blocks)[8], u16 type, u16 blockId)
{
    int z;
    int x;
    for (z = 0; z < 8; z++) {
        for (x = 0; x < 8; x++) {
            if (type == blocks[z][x].pos.type && blockId == blocks[z][x].blockId) {
                return 1;
            }
        }
    }
    return 0;
}

void FIELD_WFBC_BLOCK_ClearRand(FieldWfbcBlockRand *blockRand)
{
    MI_CpuFill8(blockRand, 0, sizeof(FieldWfbcBlockRand));
}

/*
 * WfbcNpcRecord+0x2E (pad2E in the ov020 header) is summed into the random
 * range here; it is read raw until the header owner names it.
 */
void FIELD_WFBC_BLOCK_InitRand(FieldWfbcBlockRand *blockRand, WfbcData *data, struct WfbcNpcData *npcData)
{
    int recordSum;
    int npcIdSum;
    int i;
    recordSum = 0;
    npcIdSum = 0;
    for (i = 0; i < 10; i++) {
        if (WFBC_IsReturnEntryValid(&data->people[i]) != 0) {
            FIELD_WFBC_DATA_LOCAL_LoadNpcData(npcData, data->people[i].npcId);
            recordSum += *(u16 *)((u8 *)FIELD_WFBC_DATA_LOCAL_GetNpcRecord(npcData) + 0x2E);
            npcIdSum += data->people[i].npcId;
        }
    }
    blockRand->peopleNum = FIELD_WFBC_DATA_LOCAL_CountPeople(data, 0);
    blockRand->rand.x = data->playerId;
    blockRand->rand.mul = 0x5D588B656C078965ULL;
    blockRand->rand.add = 0x269EC3;
    if (blockRand->peopleNum == 0) {
        blockRand->randRange = 1;
    } else {
        blockRand->randRange = recordSum + 2;
    }
    blockRand->npcIdSum = npcIdSum;
    blockRand->seed = data->playerId;
}

static inline void MATH_InitRand32(MATHRandContext32 *context, u64 seed)
{
    context->x = seed;
    context->mul = 0x5d588b656c078965ULL;
    context->add = 0x269ec3ULL;
}

static inline u32 MATH_Rand32(MATHRandContext32 *context, u32 max)
{
    context->x = context->mul * context->x + context->add;
    if (max) {
        return (u32)(((context->x >> 32) * max) >> 32);
    } else {
        return (u32)(context->x >> 32);
    }
}

/*
 * Seeds a NitroSDK MATHRandContext32 at the head of blockRand
 * (MATH_InitRand32 inline) and fills the 8x8 block grid through
 * FIELD_WFBC_BLOCK_SetCell. Spill-slot order (u64 max temp at the top, then row, z,
 * type, variant) needs the explicit locals in this declaration order; the
 * index `index += variant * 8` must be folded into index before the call or
 * the tail's loads schedule differently.
 */
void FIELD_WFBC_BLOCK_BuildGrid(FieldWfbcBlockRand *blockRand, FieldWfbcBlockTable *table, FieldWfbcBlock (*blocks)[8])
{
    FieldWfbcBlockPos pos;
    u32 range;
    FieldWfbcBlockPos *row;
    int z;
    u8 type;
    u8 variant;
    int x;
    int index;
    int originX;
    int originZ;
    MATH_InitRand32(&blockRand->rand, blockRand->seed);
    for (z = 0; z < 8; z++) {
        row = table->layout[z];
        for (x = 0; x < 8; x++) {
            pos = row[x];
            type = pos.type;
            if (type == 0xFF) {
                continue;
            }
            if (pos.offsetX != 0 || pos.offsetZ != 0) {
                FIELD_WFBC_BLOCK_SetCell(blocks, x, z, pos, blocks[z - pos.offsetZ][x - pos.offsetX].blockId);
            } else {
                originX = x - pos.offsetX;
                originZ = z - pos.offsetZ;
                variant = (u8)((u8)((u8)blockRand->npcIdSum + (u8)(originX + originZ)) / (u32)((originX + 3) + (originZ + 1))) % 2;
                index = (blockRand->peopleNum * 8) / 10;
                range = blockRand->randRange;
                index += MATH_Rand32(&blockRand->rand, range);
                if (index >= 8) {
                    index = 7;
                }
                index += variant * 8;
                FIELD_WFBC_BLOCK_SetCell(blocks, x, z, pos, table->blockIds[type][index]);
            }
        }
    }
}
