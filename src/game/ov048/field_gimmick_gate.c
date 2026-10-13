/*
 * file:     field_gimmick_gate.c
 * unit:     yes
 * function: func_021F36C0, func_021F374C, func_021F376C, func_021F3790, func_021F37A4, func_021F37C4, func_021F37FC, func_021F3818, func_021F3830, func_021F3870, func_021F3880, func_021F38EC, func_021F3908, func_021F392C, func_021F39A8, func_021F39BC, func_021F39E4, func_021F3A50, func_021F3A70, func_021F3A98, func_021F3AB4, func_021F3AD4, func_021F3B64, func_021F3BC0, func_021F3C14, func_021F3C2C, func_021F3CB0
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
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   CONFIG_GetAppliedFlag  0x020083E4  thumb
 *   func_021F3D78  0x021F3D78  thumb  ov048
 *   d_021F4E94     0x021F4E94  data  a4
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021F474C 0x021F474C thumb ov048
 *   func_021F4784 0x021F4784 thumb ov048
 *   func_021BE580 0x021BE580 thumb ov021
 *   d_021F50C0 0x021F50C0 data a4
 *   func_021F47B0 0x021F47B0 thumb ov048
 *   func_0200C0F0 0x0200C0F0 thumb
 *   func_0200C3B8 0x0200C3B8 thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02014314  0x02014314  thumb
 *   func_021F47BC 0x021F47BC thumb ov048
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE4C4  0x021BE4C4  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_021F4698  0x021F4698  thumb  ov048
 *   func_021897A0 0x021897A0 thumb ov021
 *   GAME_DATA_GetSaveControlWork 0x02012EC0 thumb
 *   func_0200C0E8 0x0200C0E8 thumb
 *   func_0200C3B0 0x0200C3B0 thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02049030  0x02049030  arm
 *   GPOWER_GetSpecialPowerId  0x020111E8  thumb
 *   func_021F4C10  0x021F4C10  thumb  ov048
 *   d_021F5224     0x021F5224  data  ov048  a1
 *   func_020307B0 0x020307B0 arm
 *   func_021BE700 0x021BE700 thumb ov021
 *   d_021F50D2 0x021F50D2 data a2
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_020520FC  0x020520FC  arm
 *   func_020142E8 0x020142E8 thumb
 *   SAVE_CONTROL_LoadExtraSave  0x0200725C  thumb
 *   func_020073D8  0x020073D8  thumb
 *   func_0200ECB4  0x0200ECB4  thumb
 *   func_0200ECD0  0x0200ECD0  thumb
 *   func_0200ECF0  0x0200ECF0  thumb
 *   func_020072A4  0x020072A4  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045808  0x02045808  arm
 *   GAME_DATA_GetSaveBlock42  0x02012F68  thumb
 *   func_0200EC14  0x0200EC14  thumb
 *   func_0200EC2C  0x0200EC2C  thumb
 *   func_021F4DE4  0x021F4DE4  thumb  ov048
 *   func_021F4DF4  0x021F4DF4  thumb  ov048
 *   func_021F4E3C  0x021F4E3C  thumb  ov048
 */
#include "field_gimmick_gate_types.h"

/* The functions of overlay 21 and arm9 that the gimmick uses. */
extern FldExpObjCnt *func_02188D2C(FieldMap *fieldMap);
extern struct GameSystem *func_02188C80(FieldMap *fieldMap);
extern u16 func_02188C84(FieldMap *fieldMap);
extern u16 func_02188C9C(FieldMap *fieldMap);
extern void *func_02189764(FieldMap *fieldMap, int id, int heapId, int size);
extern void func_021897A0(FieldMap *fieldMap, int id);
extern void *func_021897BC(FieldMap *fieldMap, int id);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct SaveControl *func_02012EBC(struct GameData *gameData);
extern struct SaveControl *GAME_DATA_GetSaveControlWork(struct GameData *gameData);
extern struct GimmickWork *func_02012EC4(struct GameData *gameData);
extern struct EventWork *func_0201296C(struct GameData *gameData);
extern void *GAME_DATA_GetSaveBlock42(struct GameData *gameData);
extern void *func_0200B3A4(struct GimmickWork *gimmickWork, u32 gimmickId);
extern s32 func_0200B3AC(struct GimmickWork *gimmickWork);
extern struct ConfigSave *func_0200873C(struct SaveControl *saveControl);
extern int CONFIG_GetAppliedFlag(struct ConfigSave *config);
extern void *func_0200C0E8(struct SaveControl *saveControl);
extern u16 func_0200C3B0(struct MiscSave *miscSave);
extern struct MiscSave *func_0200C0F0(struct SaveControl *saveControl);
extern void func_0200C3B8(struct MiscSave *miscSave, u16 value);
extern u32 func_020142E8(struct EventWork *eventWork, s32 flagId);
extern void func_02014314(struct EventWork *eventWork, int flagId);
extern u32 SAVE_CONTROL_LoadExtraSave(struct SaveControl *saveControl, u32 id, u32 heapId);
extern struct ExtraSaveRecord *func_020073D8(struct SaveControl *saveControl, u32 id, u32 value);
extern void func_020072A4(struct SaveControl *saveControl, u32 id);
extern u32 func_0200ECB4(struct ExtraSaveRecord *record);
extern int func_0200ECD0(struct ExtraSaveRecord *record, int index);
extern void func_0200ECF0(struct ExtraSaveRecord *record, u32 type, u32 index, GateListEntry *entry);
extern int func_0200EC14(void *saveBlock);
extern void func_0200EC2C(void *saveBlock, int index, GateListEntry *entry);
extern struct StrBuf *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct StrBuf *str);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *memory);
extern u32 func_02049030(u32 archiveId);
extern u32 GPOWER_GetSpecialPowerId(void);
extern void func_02082BCC(void *dst, int value, int size);
extern void func_020520FC(int angleX, int angleY, int angleZ, MtxFx33 *dst);
extern void func_021BE760(FldExpObjCnt *expObj, const G3dUtilSetup *setup, int unitIndex);
extern G3dObject *func_021BE4C4(FldExpObjCnt *expObj, u32 unitIndex, int modelIndex);
extern G3dObjectStatus *func_021BE480(FldExpObjCnt *expObj, unsigned unitIndex, int modelIndex);
extern void func_021BE580(FldExpObjCnt *expObj);
extern void func_021BE700(FldExpObjCnt *expObj, int unitIndex, int modelIndex, int animeIndex, int enable);

/* The board object (gimmick_obj_elboard.c). */
extern struct GimmickObjElboard *func_021F4698(GateElboardSetup *setup);
extern void func_021F474C(struct GimmickObjElboard *board);
extern void func_021F4784(struct GimmickObjElboard *board, int scrollStep);
extern int func_021F47B0(struct GimmickObjElboard *board);
extern void func_021F47BC(struct GimmickObjElboard *board, int scrollPos);
extern void func_021F3D78(GateWork *work);
extern int func_021F4C10(GateBoardRecord *dst, int archiveId, int index);
extern int func_021F4DE4(GateNewsEntry *dst, int archiveId, int index);
extern int func_021F4DF4(GateNewsEntry *entry, int zoneId);
extern int func_021F4E3C(GateNewsEntry *entry);

void func_021F36C0(FieldMap *fieldMap);
void func_021F374C(FieldMap *fieldMap);
void func_021F376C(FieldMap *fieldMap);
u8 func_021F3790(FieldMap *fieldMap);
GateSave *func_021F37A4(FieldMap *fieldMap);
void func_021F37C4(GateWork *work);
void func_021F37FC(GateWork *work);
void func_021F3818(GateWork *work);
void func_021F3830(GateWork *work);
void func_021F3870(GateWork *work);
GateWork *func_021F3880(FieldMap *fieldMap);
void func_021F38EC(GateWork *work);
void func_021F3908(GateWork *work);
void func_021F392C(GateWork *work);
void func_021F39A8(GateWork *work);
void func_021F39BC(GateWork *work);
void func_021F39E4(GateWork *work);
void func_021F3A50(GateWork *work, int messageType, int flagId);
int func_021F3A70(GateWork *work);
int func_021F3A98(GateWork *work);
int func_021F3AB4(GateWork *work);
void func_021F3AD4(const GateWork *work, u32 *values, int *count);
void func_021F3B64(GateWork *work, u32 *values, int *count);
void func_021F3BC0(GateWork *work);
void func_021F3C14(GateWork *work);
GateNewsEntry *func_021F3C2C(GateWork *work);
GateNewsEntry *func_021F3CB0(GateWork *work);

/* The two sets of board resources (one per text mode), and the board data shared with gimmick_obj_elboard.c. */
extern G3dUtilSetup d_021F4E94[];
extern int d_021F50C0[];            /* element 0: scroll step per frame */
extern const u16 d_021F50D2[];      /* animation index by GateBoardRecord.animeKind */
extern const char d_021F5224[];     /* file name passed to the heap allocations below */

/* Gimmick start: loads the board resources and model, restores the saved state and places the board. */
void func_021F36C0(FieldMap *fieldMap)
{
    FldExpObjCnt *expObj;
    int setupIndex;
    GateWork *work;
    int textMode;

    expObj = func_02188D2C(fieldMap);
    textMode = CONFIG_GetAppliedFlag(func_0200873C(func_02012EBC(func_020120F4(func_02188C80(fieldMap)))));
    if (textMode != 0) {
        if (textMode == 1) {
            setupIndex = 0;
        }
    } else {
        setupIndex = 1;
    }
    func_021BE760(expObj, &d_021F4E94[setupIndex], GATE_EXP_OBJ_UNIT_INDEX);
    work = func_021F3880(fieldMap);
    func_021F392C(work);
    func_021F3BC0(work);
    func_021F37FC(work);
    if (work->initialized == 0) {
        func_021F3908(work);
    } else {
        func_021F3818(work);
        func_021F3830(work);
    }
    func_021F3D78(work);
    func_021F3870(work);
    func_021F39E4(work);
    func_021F39BC(work);
}

/* Gimmick end: saves the state, deletes the board and frees the work. */
void func_021F374C(FieldMap *fieldMap)
{
    GateWork *work;

    work = func_021897BC(fieldMap, GATE_WORK_ID);
    func_021F37C4(work);
    if (work->board) {
        func_021F474C(work->board);
    }
    func_021F38EC(work);
}

/* Gimmick update, once per frame: scrolls the board and advances the model animations. */
void func_021F376C(FieldMap *fieldMap)
{
    GateWork *work;

    work = func_021897BC(fieldMap, GATE_WORK_ID);
    func_021F4784(work->board, d_021F50C0[0]);
    func_021BE580(func_02188D2C(fieldMap));
}

/* The facing of the board of the zone (GateFacing), used by the camera of the board view. */
u8 func_021F3790(FieldMap *fieldMap)
{
    GateWork *work = func_021897BC(fieldMap, GATE_WORK_ID);

    return (u8)work->record->facing;
}

/* The save area of the active gimmick. */
GateSave *func_021F37A4(FieldMap *fieldMap)
{
    struct GimmickWork *gimmickWork;

    gimmickWork = func_02012EC4(func_020120F4(func_02188C80(fieldMap)));
    return func_0200B3A4(gimmickWork, func_0200B3AC(gimmickWork));
}

/* Copies the board state (scroll, misc value, message log) into the save area. */
void func_021F37C4(GateWork *work)
{
    GateSave *save;

    save = func_021F37A4(work->fieldMap);
    save->initialized = work->initialized;
    save->scrollPos = func_021F47B0(work->board) >> 12;
    save->miscSaveValue = work->miscSaveValue;
    save->messageLog = work->messageLog;
}

/* Reads the board state back from the save area. */
void func_021F37FC(GateWork *work)
{
    GateSave *save;

    save = func_021F37A4(work->fieldMap);
    work->initialized = save->initialized;
    work->scrollPos = save->scrollPos;
    work->miscSaveValue = save->miscSaveValue;
}

/* Writes the work's misc value to the misc save. */
void func_021F3818(GateWork *work)
{
    func_0200C3B8(func_0200C0F0(func_02012EBC(work->gameData)), work->miscSaveValue);
}

/* Sets the event flag of every news message that was logged as shown. */
void func_021F3830(GateWork *work)
{
    struct EventWork *eventWork;
    int i;
    GateMessageLog *log;

    eventWork = func_0201296C(work->gameData);
    log = &func_021F37A4(work->fieldMap)->messageLog;
    for (i = 0; i < log->count; i++) {
        if (log->messageType[i] == GATE_MESSAGE_TYPE_NEWS) {
            func_02014314(eventWork, (u16)log->flagId[i]);
        }
    }
}

/* Moves the board to the saved scroll position. */
void func_021F3870(GateWork *work)
{
    func_021F47BC(work->board, work->scrollPos << 12);
}

/* Allocates and clears the work, and creates the board object on the board model. */
GateWork *func_021F3880(FieldMap *fieldMap)
{
    u16 heapId;
    FldExpObjCnt *expObj;
    GateWork *work;
    struct GameSystem *gameSystem;
    GateElboardSetup setup;

    heapId = func_02188C84(fieldMap);
    expObj = func_02188D2C(fieldMap);
    work = func_02189764(fieldMap, GATE_WORK_ID, heapId, sizeof(GateWork));
    func_02082BCC(work, 0, sizeof(GateWork));
    work->heapId = heapId;
    work->fieldMap = fieldMap;
    gameSystem = func_02188C80(fieldMap);
    work->gameSystem = gameSystem;
    work->gameData = func_020120F4(gameSystem);
    work->initialized = 0;
    setup.heapId = heapId;
    setup.maxMessages = 7;
    setup.bitmapWidthCells = 8;
    setup.bitmapHeightCells = 3;
    setup.model = func_021BE4C4(expObj, GATE_EXP_OBJ_UNIT_INDEX, GATE_EXP_OBJ_MODEL_BOARD);
    work->board = func_021F4698(&setup);
    return work;
}

/* Frees the board record and the news list, then the work. */
void func_021F38EC(GateWork *work)
{
    if (work) {
        func_021F39A8(work);
        func_021F3C14(work);
        func_021897A0(work->fieldMap, GATE_WORK_ID);
    }
}

/* First visit: takes the misc value from the misc save. */
void func_021F3908(GateWork *work)
{
    if (work->initialized == 0) {
        work->miscSaveValue = func_0200C3B0(func_0200C0E8(GAME_DATA_GetSaveControlWork(work->gameData)));
        work->initialized = 1;
    }
}

/* Loads the board record of the current zone (and of the active Entralink power) from the archive. */
void func_021F392C(GateWork *work)
{
    u32 i;
    u32 recordCount;
    u32 zoneId;
    GateBoardRecord record;

    if (work->record == 0) {
        zoneId = func_02188C9C(work->fieldMap);
        i = 0;
        /* 0x387: line of the allocation in the original source file */
        work->record = func_02030734(work->heapId, sizeof(GateBoardRecord), 0, d_021F5224, 0x387);
        recordCount = func_02049030(GATE_BOARD_ARCHIVE_ID);
        for (; i < recordCount; i++) {
            func_021F4C10(&record, GATE_BOARD_ARCHIVE_ID, i);
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
void func_021F39A8(GateWork *work)
{
    if (work->record) {
        func_020307B0(work->record);
        work->record = 0;
    }
}

/* Switches on the animation of the board model that the record names. */
void func_021F39BC(GateWork *work)
{
    func_021BE700(func_02188D2C(work->fieldMap), GATE_EXP_OBJ_UNIT_INDEX, GATE_EXP_OBJ_MODEL_BOARD,
                  d_021F50D2[work->record->animeKind], 1);
}

/* Puts the board model at the record's position and turns it to face the record's direction. */
void func_021F39E4(GateWork *work)
{
    G3dObjectStatus *status;
    GateBoardRecord *record;
    int angle;

    angle = 0;
    status = func_021BE480(func_02188D2C(work->fieldMap), GATE_EXP_OBJ_UNIT_INDEX, GATE_EXP_OBJ_MODEL_BOARD);
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
    func_020520FC(0, (u16)(angle * 0xb6), 0, &status->rotate);
}

/* Logs a message that the board shows (until the log is full). */
void func_021F3A50(GateWork *work, int messageType, int flagId)
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
int func_021F3A70(GateWork *work)
{
    if (func_021F3A98(work) == 1 || func_021F3AB4(work) == 1) {
        if (work->miscSaveValue != 0) {
            return 1;
        }
    }
    return 0;
}

/* The board lists the values of the save block. */
int func_021F3A98(GateWork *work)
{
    return func_020142E8(func_0201296C(work->gameData), GATE_FLAG_SAVE_BLOCK_LIST) == 1;
}

/* The board lists the values of the extra save. */
int func_021F3AB4(GateWork *work)
{
    return func_020142E8(func_0201296C(work->gameData), GATE_FLAG_EXTRA_SAVE_LIST) == 1;
}

/* Reads the values of the extra save list (count and one value per entry). */
void func_021F3AD4(const GateWork *work, u32 *values, int *count)
{
    int i;
    struct SaveControl *saveControl;
    struct ExtraSaveRecord *record;
    GateListEntry entry;

    i = 0;
    *count = 0;
    saveControl = func_02012EBC(work->gameData);
    if (SAVE_CONTROL_LoadExtraSave(saveControl, GATE_EXTRA_SAVE_ID, work->heapId) - 1 <= 1) {
        record = func_020073D8(saveControl, GATE_EXTRA_SAVE_ID, i);
        if (func_0200ECB4(record) != 0) {
            *count = func_0200ECD0(record, i);
            for (; i < *count; i++) {
                entry.nameStr = func_020457B0(0x40, work->heapId);
                entry.placeStr = func_020457B0(0x40, work->heapId);
                func_0200ECF0(record, 0, i, &entry);
                values[i] = entry.entryId;
                func_02045808(entry.nameStr);
                func_02045808(entry.placeStr);
            }
        }
    }
    func_020072A4(saveControl, GATE_EXTRA_SAVE_ID);
}

/* Reads the values of the save block list (count and one value per entry). */
void func_021F3B64(GateWork *work, u32 *values, int *count)
{
    void *saveBlock;
    int i;
    GateListEntry entry;

    saveBlock = GAME_DATA_GetSaveBlock42(work->gameData);
    *count = func_0200EC14(saveBlock);
    for (i = 0; i < *count; i++) {
        entry.nameStr = func_020457B0(0x40, work->heapId);
        entry.placeStr = func_020457B0(0x40, work->heapId);
        func_0200EC2C(saveBlock, i, &entry);
        values[i] = entry.entryId;
        func_02045808(entry.nameStr);
        func_02045808(entry.placeStr);
    }
}

/* Loads the news list from the archive. */
void func_021F3BC0(GateWork *work)
{
    int count;
    int i;

    if (work->newsList == 0) {
        count = func_02049030(GATE_NEWS_ARCHIVE_ID);
        /* 0x4cb: line of the allocation in the original source file */
        work->newsList = func_02030734(work->heapId, count * sizeof(GateNewsEntry), 0, d_021F5224, 0x4cb);
        for (i = 0; i < count; i++) {
            func_021F4DE4(&work->newsList[i], GATE_NEWS_ARCHIVE_ID, i);
        }
        work->newsCount = count;
    }
}

/* Frees the news list. */
void func_021F3C14(GateWork *work)
{
    if (work->newsList) {
        func_020307B0(work->newsList);
        work->newsList = 0;
        work->newsCount = 0;
    }
}

/* The first news entry that fits the zone and the Entralink power and whose event flag is set, or 0. */
GateNewsEntry *func_021F3C2C(GateWork *work)
{
    int zoneId;
    struct EventWork *eventWork;
    int i;
    int flagSet;
    int zoneMatches;

    zoneId = func_02188C9C(work->fieldMap);
    eventWork = func_0201296C(work->gameData);
    if (work->newsList == 0) {
        return 0;
    }
    for (i = 0; i < work->newsCount; i++) {
        flagSet = func_020142E8(eventWork, (u16)work->newsList[i].eventFlag);
        zoneMatches = func_021F4DF4(&work->newsList[i], zoneId);
        if (func_021F4E3C(&work->newsList[i]) && flagSet && zoneMatches) {
            return &work->newsList[i];
        }
    }
    return 0;
}

/* The first list kind news entry that fits the zone and whose event flag is set, or 0. */
GateNewsEntry *func_021F3CB0(GateWork *work)
{
    int zoneId = func_02188C9C(work->fieldMap);
    struct EventWork *eventWork = func_0201296C(work->gameData);
    int i;

    if (work->newsList == 0) {
        return 0;
    }
    for (i = 0; i < work->newsCount; i++) {
        int flagSet = func_020142E8(eventWork, (u16)work->newsList[i].eventFlag);
        int zoneMatches = func_021F4DF4(&work->newsList[i], zoneId);

        if (flagSet != 0 && zoneMatches != 0 && work->newsList[i].kind == GATE_NEWS_KIND_LIST) {
            return &work->newsList[i];
        }
    }
    return 0;
}
