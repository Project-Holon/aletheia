/*
 * file:     field_gimmick_gate.c
 * unit:     yes
 * function: FIELD_GIMMICK_GATE_Init, FIELD_GIMMICK_GATE_Exit, FIELD_GIMMICK_GATE_Update, FIELD_GIMMICK_GATE_GetBoardFacing, FIELD_GIMMICK_GATE_GetSave, FIELD_GIMMICK_GATE_SaveState, FIELD_GIMMICK_GATE_LoadState, FIELD_GIMMICK_GATE_StoreMiscSaveValue, FIELD_GIMMICK_GATE_RestoreLoggedFlags, FIELD_GIMMICK_GATE_ApplyBoardScroll, FIELD_GIMMICK_GATE_CreateWork, FIELD_GIMMICK_GATE_DeleteWork, FIELD_GIMMICK_GATE_InitMiscSaveValue, FIELD_GIMMICK_GATE_LoadBoardRecord, FIELD_GIMMICK_GATE_FreeBoardRecord, FIELD_GIMMICK_GATE_StartBoardAnime, FIELD_GIMMICK_GATE_PlaceBoardModel, FIELD_GIMMICK_GATE_LogMessage, FIELD_GIMMICK_GATE_HasMessagesToShow, FIELD_GIMMICK_GATE_IsSaveBlockListOn, FIELD_GIMMICK_GATE_IsExtraSaveListOn, FIELD_GIMMICK_GATE_ReadExtraSaveValues, FIELD_GIMMICK_GATE_ReadSaveBlockValues, FIELD_GIMMICK_GATE_LoadNewsList, FIELD_GIMMICK_GATE_FreeNewsList, FIELD_GIMMICK_GATE_FindNewsEntry, FIELD_GIMMICK_GATE_FindListNewsEntry
 * address:  0x021F36C0
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   CONFIG_GetAppliedFlag  0x020083E4  thumb
 *   GIMMICK_OBJ_ELBOARD_FillMessages  0x021F3D78  thumb  ov048
 *   gGateExpObjSetups     0x021F4E94  data  a4
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   GIMMICK_OBJ_ELBOARD_Delete 0x021F474C thumb ov048
 *   GIMMICK_OBJ_ELBOARD_Advance 0x021F4784 thumb ov048
 *   FLD_EXP_OBJ_UpdateAnimes 0x021BE580 thumb ov021
 *   gElboardLayout 0x021F50C0 data a4
 *   func_021F47B0 0x021F47B0 thumb ov048
 *   BEACON_GetBlock 0x0200C0F0 thumb
 *   BEACON_SetGatePoints 0x0200C3B8 thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_SetEventFlag  0x02014314  thumb
 *   GIMMICK_OBJ_ELBOARD_SetScroll 0x021F47BC thumb ov048
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FLD_EXP_OBJ_GetModelObject  0x021BE4C4  thumb  ov021
 *   MI_CpuFill8  0x02082BCC  arm
 *   GIMMICK_OBJ_ELBOARD_Create  0x021F4698  thumb  ov048
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb ov021
 *   GAME_DATA_GetSaveControlWork 0x02012EC0 thumb
 *   BEACON_GetFromSave 0x0200C0E8 thumb
 *   BEACON_GetGatePoints 0x0200C3B0 thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   ARC_TOOL_GetArchiveFileCount  0x02049030  arm
 *   GPOWER_GetSpecialPowerId  0x020111E8  thumb
 *   GIMMICK_OBJ_ELBOARD_ReadGateInfo  0x021F4C10  thumb  ov048
 *   gGateSourceFileName     0x021F5224  data  ov048  a1
 *   GFL_HEAP_Free 0x020307B0 arm
 *   FLD_EXP_OBJ_SetAnimeEnabled 0x021BE700 thumb ov021
 *   gGateBoardAnimeTable 0x021F50D2 data a2
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   BUTTON_MAN_MakeRotMtxXYZ  0x020520FC  arm
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 *   SAVE_CONTROL_LoadExtraSave  0x0200725C  thumb
 *   SAVE_CONTROL_GetExtraSaveRecord  0x020073D8  thumb
 *   MISC_SAVEDATA_GetRingIndex  0x0200ECB4  thumb
 *   func_0200ECD0  0x0200ECD0  thumb
 *   MISC_SAVEDATA_ExportRingRecord  0x0200ECF0  thumb
 *   SAVE_CONTROL_DeleteExtraSave  0x020072A4  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   GAME_DATA_GetSaveBlock42  0x02012F68  thumb
 *   MISC_SAVEDATA_FindFreeRecordSlot  0x0200EC14  thumb
 *   MISC_SAVEDATA_ExportRecord  0x0200EC2C  thumb
 *   GIMMICK_OBJ_ELBOARD_ReadGateEntry  0x021F4DE4  thumb  ov048
 *   GIMMICK_OBJ_ELBOARD_CheckEntryZone  0x021F4DF4  thumb  ov048
 *   GIMMICK_OBJ_ELBOARD_CheckEntryGPower  0x021F4E3C  thumb  ov048
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb  arm9
 *   GIMMICK_WORK_GetWork  0x0200B3A4  thumb  arm9
 *   GIMMICK_WORK_GetId  0x0200B3AC  thumb  arm9
 */
#include "field_gimmick_gate_types.h"

/* The functions of overlay 21 and arm9 that the gimmick uses. */
extern FldExpObjCnt *FIELDMAP_GetExpObj(FieldMap *fieldMap);
extern struct GameSystem *FIELDMAP_GetGameSystem(FieldMap *fieldMap);
extern u16 FIELDMAP_GetHeapId(FieldMap *fieldMap);
extern u16 FIELDMAP_GetZoneId(FieldMap *fieldMap);
extern void *FIELDMAP_AllocCommonWork(FieldMap *fieldMap, int id, int heapId, int size);
extern void FIELDMAP_FreeCommonWork(FieldMap *fieldMap, int id);
extern void *FIELDMAP_GetCommonWork(FieldMap *fieldMap, int id);
extern struct GameData *ICA_ANIME_GetField1C(const struct GameSystem *gameSystem);
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern struct SaveControl *GAME_DATA_GetSaveControlWork(struct GameData *gameData);
extern struct GimmickWork *GAME_DATA_GetFieldSave(struct GameData *gameData);
extern struct EventWork *GAME_DATA_GetEventWork(struct GameData *gameData);
extern void *GAME_DATA_GetSaveBlock42(struct GameData *gameData);
extern void *GIMMICK_WORK_GetWork(struct GimmickWork *gimmickWork, u32 gimmickId);
extern s32 GIMMICK_WORK_GetId(struct GimmickWork *gimmickWork);
extern struct ConfigSave *func_0200873C(struct SaveControl *saveControl);
extern int CONFIG_GetAppliedFlag(struct ConfigSave *config);
extern void *BEACON_GetFromSave(struct SaveControl *saveControl);
extern u16 BEACON_GetGatePoints(struct MiscSave *miscSave);
extern struct MiscSave *BEACON_GetBlock(struct SaveControl *saveControl);
extern void BEACON_SetGatePoints(struct MiscSave *miscSave, u16 value);
extern u32 ZONEDATA_CheckEventFlag(struct EventWork *eventWork, s32 flagId);
extern void ZONEDATA_SetEventFlag(struct EventWork *eventWork, int flagId);
extern u32 SAVE_CONTROL_LoadExtraSave(struct SaveControl *saveControl, u32 id, u32 heapId);
extern struct ExtraSaveRecord *SAVE_CONTROL_GetExtraSaveRecord(struct SaveControl *saveControl, u32 id, u32 value);
extern void SAVE_CONTROL_DeleteExtraSave(struct SaveControl *saveControl, u32 id);
extern u32 MISC_SAVEDATA_GetRingIndex(struct ExtraSaveRecord *record);
extern int func_0200ECD0(struct ExtraSaveRecord *record, int index);
extern void MISC_SAVEDATA_ExportRingRecord(struct ExtraSaveRecord *record, u32 type, u32 index, GateListEntry *entry);
extern int MISC_SAVEDATA_FindFreeRecordSlot(void *saveBlock);
extern void MISC_SAVEDATA_ExportRecord(void *saveBlock, int index, GateListEntry *entry);
extern struct StrBuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_Delete(struct StrBuf *str);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 GFL_HEAP_Free(void *memory);
extern u32 ARC_TOOL_GetArchiveFileCount(u32 archiveId);
extern u32 GPOWER_GetSpecialPowerId(void);
extern void MI_CpuFill8(void *dst, int value, int size);
extern void BUTTON_MAN_MakeRotMtxXYZ(int angleX, int angleY, int angleZ, MtxFx33 *dst);
extern void FLD_EXP_OBJ_AddUnitFromArchive(FldExpObjCnt *expObj, const G3dUtilSetup *setup, int unitIndex);
extern G3dObject *FLD_EXP_OBJ_GetModelObject(FldExpObjCnt *expObj, u32 unitIndex, int modelIndex);
extern G3dObjectStatus *FLD_EXP_OBJ_GetModelStatus(FldExpObjCnt *expObj, unsigned unitIndex, int modelIndex);
extern void FLD_EXP_OBJ_UpdateAnimes(FldExpObjCnt *expObj);
extern void FLD_EXP_OBJ_SetAnimeEnabled(FldExpObjCnt *expObj, int unitIndex, int modelIndex, int animeIndex, int enable);

/* The board object (gimmick_obj_elboard.c). */
extern struct GimmickObjElboard *GIMMICK_OBJ_ELBOARD_Create(GateElboardSetup *setup);
extern void GIMMICK_OBJ_ELBOARD_Delete(struct GimmickObjElboard *board);
extern void GIMMICK_OBJ_ELBOARD_Advance(struct GimmickObjElboard *board, int scrollStep);
extern int func_021F47B0(struct GimmickObjElboard *board);
extern void GIMMICK_OBJ_ELBOARD_SetScroll(struct GimmickObjElboard *board, int scrollPos);
extern void GIMMICK_OBJ_ELBOARD_FillMessages(GateWork *work);
extern int GIMMICK_OBJ_ELBOARD_ReadGateInfo(GateBoardRecord *dst, int archiveId, int index);
extern int GIMMICK_OBJ_ELBOARD_ReadGateEntry(GateNewsEntry *dst, int archiveId, int index);
extern int GIMMICK_OBJ_ELBOARD_CheckEntryZone(GateNewsEntry *entry, int zoneId);
extern int GIMMICK_OBJ_ELBOARD_CheckEntryGPower(GateNewsEntry *entry);

void FIELD_GIMMICK_GATE_Init(FieldMap *fieldMap);
void FIELD_GIMMICK_GATE_Exit(FieldMap *fieldMap);
void FIELD_GIMMICK_GATE_Update(FieldMap *fieldMap);
u8 FIELD_GIMMICK_GATE_GetBoardFacing(FieldMap *fieldMap);
GateSave *FIELD_GIMMICK_GATE_GetSave(FieldMap *fieldMap);
void FIELD_GIMMICK_GATE_SaveState(GateWork *work);
void FIELD_GIMMICK_GATE_LoadState(GateWork *work);
void FIELD_GIMMICK_GATE_StoreMiscSaveValue(GateWork *work);
void FIELD_GIMMICK_GATE_RestoreLoggedFlags(GateWork *work);
void FIELD_GIMMICK_GATE_ApplyBoardScroll(GateWork *work);
GateWork *FIELD_GIMMICK_GATE_CreateWork(FieldMap *fieldMap);
void FIELD_GIMMICK_GATE_DeleteWork(GateWork *work);
void FIELD_GIMMICK_GATE_InitMiscSaveValue(GateWork *work);
void FIELD_GIMMICK_GATE_LoadBoardRecord(GateWork *work);
void FIELD_GIMMICK_GATE_FreeBoardRecord(GateWork *work);
void FIELD_GIMMICK_GATE_StartBoardAnime(GateWork *work);
void FIELD_GIMMICK_GATE_PlaceBoardModel(GateWork *work);
void FIELD_GIMMICK_GATE_LogMessage(GateWork *work, int messageType, int flagId);
int FIELD_GIMMICK_GATE_HasMessagesToShow(GateWork *work);
int FIELD_GIMMICK_GATE_IsSaveBlockListOn(GateWork *work);
int FIELD_GIMMICK_GATE_IsExtraSaveListOn(GateWork *work);
void FIELD_GIMMICK_GATE_ReadExtraSaveValues(const GateWork *work, u32 *values, int *count);
void FIELD_GIMMICK_GATE_ReadSaveBlockValues(GateWork *work, u32 *values, int *count);
void FIELD_GIMMICK_GATE_LoadNewsList(GateWork *work);
void FIELD_GIMMICK_GATE_FreeNewsList(GateWork *work);
GateNewsEntry *FIELD_GIMMICK_GATE_FindNewsEntry(GateWork *work);
GateNewsEntry *FIELD_GIMMICK_GATE_FindListNewsEntry(GateWork *work);

/* The two sets of board resources (one per text mode), and the board data shared with gimmick_obj_elboard.c. */
extern G3dUtilSetup gGateExpObjSetups[];
extern int gElboardLayout[];            /* element 0: scroll step per frame */
extern const u16 gGateBoardAnimeTable[];      /* animation index by GateBoardRecord.animeKind */
extern const char gGateSourceFileName[];     /* file name passed to the heap allocations below */

/* Gimmick start: loads the board resources and model, restores the saved state and places the board. */
void FIELD_GIMMICK_GATE_Init(FieldMap *fieldMap)
{
    FldExpObjCnt *expObj;
    int setupIndex;
    GateWork *work;
    int textMode;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    textMode = CONFIG_GetAppliedFlag(func_0200873C(GAME_DATA_GetSaveControl(ICA_ANIME_GetField1C(FIELDMAP_GetGameSystem(fieldMap)))));
    if (textMode != 0) {
        if (textMode == 1) {
            setupIndex = 0;
        }
    } else {
        setupIndex = 1;
    }
    FLD_EXP_OBJ_AddUnitFromArchive(expObj, &gGateExpObjSetups[setupIndex], GATE_EXP_OBJ_UNIT_INDEX);
    work = FIELD_GIMMICK_GATE_CreateWork(fieldMap);
    FIELD_GIMMICK_GATE_LoadBoardRecord(work);
    FIELD_GIMMICK_GATE_LoadNewsList(work);
    FIELD_GIMMICK_GATE_LoadState(work);
    if (work->initialized == 0) {
        FIELD_GIMMICK_GATE_InitMiscSaveValue(work);
    } else {
        FIELD_GIMMICK_GATE_StoreMiscSaveValue(work);
        FIELD_GIMMICK_GATE_RestoreLoggedFlags(work);
    }
    GIMMICK_OBJ_ELBOARD_FillMessages(work);
    FIELD_GIMMICK_GATE_ApplyBoardScroll(work);
    FIELD_GIMMICK_GATE_PlaceBoardModel(work);
    FIELD_GIMMICK_GATE_StartBoardAnime(work);
}

/* Gimmick end: saves the state, deletes the board and frees the work. */
void FIELD_GIMMICK_GATE_Exit(FieldMap *fieldMap)
{
    GateWork *work;

    work = FIELDMAP_GetCommonWork(fieldMap, GATE_WORK_ID);
    FIELD_GIMMICK_GATE_SaveState(work);
    if (work->board) {
        GIMMICK_OBJ_ELBOARD_Delete(work->board);
    }
    FIELD_GIMMICK_GATE_DeleteWork(work);
}

/* Gimmick update, once per frame: scrolls the board and advances the model animations. */
void FIELD_GIMMICK_GATE_Update(FieldMap *fieldMap)
{
    GateWork *work;

    work = FIELDMAP_GetCommonWork(fieldMap, GATE_WORK_ID);
    GIMMICK_OBJ_ELBOARD_Advance(work->board, gElboardLayout[0]);
    FLD_EXP_OBJ_UpdateAnimes(FIELDMAP_GetExpObj(fieldMap));
}

/* The facing of the board of the zone (GateFacing), used by the camera of the board view. */
u8 FIELD_GIMMICK_GATE_GetBoardFacing(FieldMap *fieldMap)
{
    GateWork *work = FIELDMAP_GetCommonWork(fieldMap, GATE_WORK_ID);

    return (u8)work->record->facing;
}

/* The save area of the active gimmick. */
GateSave *FIELD_GIMMICK_GATE_GetSave(FieldMap *fieldMap)
{
    struct GimmickWork *gimmickWork;

    gimmickWork = GAME_DATA_GetFieldSave(ICA_ANIME_GetField1C(FIELDMAP_GetGameSystem(fieldMap)));
    return GIMMICK_WORK_GetWork(gimmickWork, GIMMICK_WORK_GetId(gimmickWork));
}

/* Copies the board state (scroll, misc value, message log) into the save area. */
void FIELD_GIMMICK_GATE_SaveState(GateWork *work)
{
    GateSave *save;

    save = FIELD_GIMMICK_GATE_GetSave(work->fieldMap);
    save->initialized = work->initialized;
    save->scrollPos = func_021F47B0(work->board) >> 12;
    save->miscSaveValue = work->miscSaveValue;
    save->messageLog = work->messageLog;
}

/* Reads the board state back from the save area. */
void FIELD_GIMMICK_GATE_LoadState(GateWork *work)
{
    GateSave *save;

    save = FIELD_GIMMICK_GATE_GetSave(work->fieldMap);
    work->initialized = save->initialized;
    work->scrollPos = save->scrollPos;
    work->miscSaveValue = save->miscSaveValue;
}

/* Writes the work's misc value to the misc save. */
void FIELD_GIMMICK_GATE_StoreMiscSaveValue(GateWork *work)
{
    BEACON_SetGatePoints(BEACON_GetBlock(GAME_DATA_GetSaveControl(work->gameData)), work->miscSaveValue);
}

/* Sets the event flag of every news message that was logged as shown. */
void FIELD_GIMMICK_GATE_RestoreLoggedFlags(GateWork *work)
{
    struct EventWork *eventWork;
    int i;
    GateMessageLog *log;

    eventWork = GAME_DATA_GetEventWork(work->gameData);
    log = &FIELD_GIMMICK_GATE_GetSave(work->fieldMap)->messageLog;
    for (i = 0; i < log->count; i++) {
        if (log->messageType[i] == GATE_MESSAGE_TYPE_NEWS) {
            ZONEDATA_SetEventFlag(eventWork, (u16)log->flagId[i]);
        }
    }
}

/* Moves the board to the saved scroll position. */
void FIELD_GIMMICK_GATE_ApplyBoardScroll(GateWork *work)
{
    GIMMICK_OBJ_ELBOARD_SetScroll(work->board, work->scrollPos << 12);
}

/* Allocates and clears the work, and creates the board object on the board model. */
GateWork *FIELD_GIMMICK_GATE_CreateWork(FieldMap *fieldMap)
{
    u16 heapId;
    FldExpObjCnt *expObj;
    GateWork *work;
    struct GameSystem *gameSystem;
    GateElboardSetup setup;

    heapId = FIELDMAP_GetHeapId(fieldMap);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_AllocCommonWork(fieldMap, GATE_WORK_ID, heapId, sizeof(GateWork));
    MI_CpuFill8(work, 0, sizeof(GateWork));
    work->heapId = heapId;
    work->fieldMap = fieldMap;
    gameSystem = FIELDMAP_GetGameSystem(fieldMap);
    work->gameSystem = gameSystem;
    work->gameData = ICA_ANIME_GetField1C(gameSystem);
    work->initialized = 0;
    setup.heapId = heapId;
    setup.maxMessages = 7;
    setup.bitmapWidthCells = 8;
    setup.bitmapHeightCells = 3;
    setup.model = FLD_EXP_OBJ_GetModelObject(expObj, GATE_EXP_OBJ_UNIT_INDEX, GATE_EXP_OBJ_MODEL_BOARD);
    work->board = GIMMICK_OBJ_ELBOARD_Create(&setup);
    return work;
}

/* Frees the board record and the news list, then the work. */
void FIELD_GIMMICK_GATE_DeleteWork(GateWork *work)
{
    if (work) {
        FIELD_GIMMICK_GATE_FreeBoardRecord(work);
        FIELD_GIMMICK_GATE_FreeNewsList(work);
        FIELDMAP_FreeCommonWork(work->fieldMap, GATE_WORK_ID);
    }
}

/* First visit: takes the misc value from the misc save. */
void FIELD_GIMMICK_GATE_InitMiscSaveValue(GateWork *work)
{
    if (work->initialized == 0) {
        work->miscSaveValue = BEACON_GetGatePoints(BEACON_GetFromSave(GAME_DATA_GetSaveControlWork(work->gameData)));
        work->initialized = 1;
    }
}

/* Loads the board record of the current zone (and of the active Entralink power) from the archive. */
void FIELD_GIMMICK_GATE_LoadBoardRecord(GateWork *work)
{
    u32 i;
    u32 recordCount;
    u32 zoneId;
    GateBoardRecord record;

    if (work->record == 0) {
        zoneId = FIELDMAP_GetZoneId(work->fieldMap);
        i = 0;
        /* 0x387: line of the allocation in the original source file */
        work->record = GFL_HEAP_Alloc(work->heapId, sizeof(GateBoardRecord), 0, gGateSourceFileName, 0x387);
        recordCount = ARC_TOOL_GetArchiveFileCount(GATE_BOARD_ARCHIVE_ID);
        for (; i < recordCount; i++) {
            GIMMICK_OBJ_ELBOARD_ReadGateInfo(&record, GATE_BOARD_ARCHIVE_ID, i);
            if (record.zoneId == zoneId) {
                if (record.specialPowerId == 0 || record.specialPowerId == GPOWER_GetSpecialPowerId()) {
                    *work->record = record;
                    return;
                }
            }
        }
    }
}

/* Frees the board record. */
void FIELD_GIMMICK_GATE_FreeBoardRecord(GateWork *work)
{
    if (work->record) {
        GFL_HEAP_Free(work->record);
        work->record = 0;
    }
}

/* Switches on the animation of the board model that the record names. */
void FIELD_GIMMICK_GATE_StartBoardAnime(GateWork *work)
{
    FLD_EXP_OBJ_SetAnimeEnabled(FIELDMAP_GetExpObj(work->fieldMap), GATE_EXP_OBJ_UNIT_INDEX, GATE_EXP_OBJ_MODEL_BOARD,
                  gGateBoardAnimeTable[work->record->animeKind], 1);
}

/* Puts the board model at the record's position and turns it to face the record's direction. */
void FIELD_GIMMICK_GATE_PlaceBoardModel(GateWork *work)
{
    G3dObjectStatus *status;
    GateBoardRecord *record;
    int angle;

    angle = 0;
    status = FLD_EXP_OBJ_GetModelStatus(FIELDMAP_GetExpObj(work->fieldMap), GATE_EXP_OBJ_UNIT_INDEX, GATE_EXP_OBJ_MODEL_BOARD);
    record = work->record;
    status->trans.x = record->x << 12;
    status->trans.y = record->y << 12;
    status->trans.z = record->z << 12;
    switch (record->facing) {
    case GATE_FACING_DOWN:
        angle = 0;
        break;
    case GATE_FACING_RIGHT:
        angle = 90;
        break;
    case GATE_FACING_UP:
        angle = 180;
        break;
    case GATE_FACING_LEFT:
        angle = 270;
        break;
    default:
        angle = 0;
        break;
    }
    BUTTON_MAN_MakeRotMtxXYZ(0, (u16)(angle * 0xb6), 0, &status->rotate);
}

/* Logs a message that the board shows (until the log is full). */
void FIELD_GIMMICK_GATE_LogMessage(GateWork *work, int messageType, int flagId)
{
    GateMessageLog *log;
    int i;

    log = &work->messageLog;
    i = log->count;
    if (i < GATE_MESSAGE_LOG_MAX) {
        log->messageType[i] = messageType;
        log->flagId[i] = flagId;
        log->count = i + 1;
    }
}

/* The board has messages to show: a list mode flag is set and the misc value is not zero. */
int FIELD_GIMMICK_GATE_HasMessagesToShow(GateWork *work)
{
    if (FIELD_GIMMICK_GATE_IsSaveBlockListOn(work) == 1 || FIELD_GIMMICK_GATE_IsExtraSaveListOn(work) == 1) {
        if (work->miscSaveValue != 0) {
            return 1;
        }
    }
    return 0;
}

/* The board lists the values of the save block. */
int FIELD_GIMMICK_GATE_IsSaveBlockListOn(GateWork *work)
{
    return ZONEDATA_CheckEventFlag(GAME_DATA_GetEventWork(work->gameData), GATE_FLAG_SAVE_BLOCK_LIST) == 1;
}

/* The board lists the values of the extra save. */
int FIELD_GIMMICK_GATE_IsExtraSaveListOn(GateWork *work)
{
    return ZONEDATA_CheckEventFlag(GAME_DATA_GetEventWork(work->gameData), GATE_FLAG_EXTRA_SAVE_LIST) == 1;
}

/* Reads the values of the extra save list (count and one value per entry). */
void FIELD_GIMMICK_GATE_ReadExtraSaveValues(const GateWork *work, u32 *values, int *count)
{
    int i;
    struct SaveControl *saveControl;
    struct ExtraSaveRecord *record;
    GateListEntry entry;

    i = 0;
    *count = 0;
    saveControl = GAME_DATA_GetSaveControl(work->gameData);
    if (SAVE_CONTROL_LoadExtraSave(saveControl, GATE_EXTRA_SAVE_ID, work->heapId) - 1 <= 1) {
        record = SAVE_CONTROL_GetExtraSaveRecord(saveControl, GATE_EXTRA_SAVE_ID, i);
        if (MISC_SAVEDATA_GetRingIndex(record) != 0) {
            *count = func_0200ECD0(record, i);
            for (; i < *count; i++) {
                entry.nameStr = STRBUF_Create(0x40, work->heapId);
                entry.placeStr = STRBUF_Create(0x40, work->heapId);
                MISC_SAVEDATA_ExportRingRecord(record, 0, i, &entry);
                values[i] = entry.entryId;
                STRBUF_Delete(entry.nameStr);
                STRBUF_Delete(entry.placeStr);
            }
        }
    }
    SAVE_CONTROL_DeleteExtraSave(saveControl, GATE_EXTRA_SAVE_ID);
}

/* Reads the values of the save block list (count and one value per entry). */
void FIELD_GIMMICK_GATE_ReadSaveBlockValues(GateWork *work, u32 *values, int *count)
{
    void *saveBlock;
    int i;
    GateListEntry entry;

    saveBlock = GAME_DATA_GetSaveBlock42(work->gameData);
    *count = MISC_SAVEDATA_FindFreeRecordSlot(saveBlock);
    for (i = 0; i < *count; i++) {
        entry.nameStr = STRBUF_Create(0x40, work->heapId);
        entry.placeStr = STRBUF_Create(0x40, work->heapId);
        MISC_SAVEDATA_ExportRecord(saveBlock, i, &entry);
        values[i] = entry.entryId;
        STRBUF_Delete(entry.nameStr);
        STRBUF_Delete(entry.placeStr);
    }
}

/* Loads the news list from the archive. */
void FIELD_GIMMICK_GATE_LoadNewsList(GateWork *work)
{
    int count;
    int i;

    if (work->newsList == 0) {
        count = ARC_TOOL_GetArchiveFileCount(GATE_NEWS_ARCHIVE_ID);
        /* 0x4cb: line of the allocation in the original source file */
        work->newsList = GFL_HEAP_Alloc(work->heapId, count * sizeof(GateNewsEntry), 0, gGateSourceFileName, 0x4cb);
        for (i = 0; i < count; i++) {
            GIMMICK_OBJ_ELBOARD_ReadGateEntry(&work->newsList[i], GATE_NEWS_ARCHIVE_ID, i);
        }
        work->newsCount = count;
    }
}

/* Frees the news list. */
void FIELD_GIMMICK_GATE_FreeNewsList(GateWork *work)
{
    if (work->newsList) {
        GFL_HEAP_Free(work->newsList);
        work->newsList = 0;
        work->newsCount = 0;
    }
}

/* The first news entry that fits the zone and the Entralink power and whose event flag is set, or 0. */
GateNewsEntry *FIELD_GIMMICK_GATE_FindNewsEntry(GateWork *work)
{
    int zoneId;
    struct EventWork *eventWork;
    int i;
    int flagSet;
    int zoneMatches;

    zoneId = FIELDMAP_GetZoneId(work->fieldMap);
    eventWork = GAME_DATA_GetEventWork(work->gameData);
    if (work->newsList == 0) {
        return 0;
    }
    for (i = 0; i < work->newsCount; i++) {
        flagSet = ZONEDATA_CheckEventFlag(eventWork, (u16)work->newsList[i].eventFlag);
        zoneMatches = GIMMICK_OBJ_ELBOARD_CheckEntryZone(&work->newsList[i], zoneId);
        if (GIMMICK_OBJ_ELBOARD_CheckEntryGPower(&work->newsList[i]) && flagSet && zoneMatches) {
            return &work->newsList[i];
        }
    }
    return 0;
}

/* The first list kind news entry that fits the zone and whose event flag is set, or 0. */
GateNewsEntry *FIELD_GIMMICK_GATE_FindListNewsEntry(GateWork *work)
{
    int zoneId = FIELDMAP_GetZoneId(work->fieldMap);
    struct EventWork *eventWork = GAME_DATA_GetEventWork(work->gameData);
    int i;

    if (work->newsList == 0) {
        return 0;
    }
    for (i = 0; i < work->newsCount; i++) {
        int flagSet = ZONEDATA_CheckEventFlag(eventWork, (u16)work->newsList[i].eventFlag);
        int zoneMatches = GIMMICK_OBJ_ELBOARD_CheckEntryZone(&work->newsList[i], zoneId);

        if (flagSet != 0 && zoneMatches != 0 && work->newsList[i].kind == GATE_NEWS_KIND_LIST) {
            return &work->newsList[i];
        }
    }
    return 0;
}
