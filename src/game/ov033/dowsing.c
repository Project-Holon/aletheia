/*
 * file:     dowsing.c
 * unit:     yes
 * function: DOWSING_CreateSearch, DOWSING_DeleteSearch, DOWSING_IsTargetAvailable, DOWSING_ResetSearch, DOWSING_FindNextTarget, DOWSING_Create, DOWSING_Delete, DOWSING_Update, DOWSING_UpdateDisplay, DOWSING_TaskTransferPalettes, DOWSING_InitBgsAndActorUnit, DOWSING_ExitBgsAndActorUnit, DOWSING_LoadBackground, DOWSING_FreeBackground, DOWSING_CreateParts, DOWSING_DeleteParts, DOWSING_CreateCloseButton, DOWSING_DeleteCloseButton, DOWSING_UpdateCloseButton, DOWSING_InitFade, DOWSING_ExitFade, DOWSING_UpdateFade
 * address:  0x021EFEC0
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   sDowsingFileName 0x021F0E60 data ov033 a1
 *   GFL_HEAP_Free 0x020307B0 arm
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 *   INTRUDE_FindOfferSlotAt 0x021CFAC0 thumb ov021
 *   EVENTDATA_SYSTEM_GetHiddenItemTable 0x0216476C thumb ov010
 *   INTRUDE_GetNextOfferSpot 0x021CFB68 thumb ov021
 *   ARC_UTIL_LoadMemberWithSize 0x0204A298 arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb ov021
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   INTRUDE_GetFromSave 0x0200BE48 thumb
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   INFOWIN_Update 0x02024ABC thumb
 *   MAP_MATRIX_IsInRangeByPos 0x02159C48 thumb ov010
 *   MAP_MATRIX_GetZoneIdByPos 0x02159BD4 thumb ov010
 *   GAMESYSTEM_GetMyPlayerWork 0x020120F8 thumb
 *   GAME_DATA_GetPlayerPosition 0x02012AA0 thumb
 *   GAME_DATA_GetFieldWork 0x02012974 thumb
 *   ZONEDATA_IsFieldMatrix 0x02013E7C thumb
 *   ZONEDATA_IsZoneGroup118To13C 0x02013D74 thumb
 *   GFL_USE_GetSeSlot 0x02006148 thumb
 *   GFL_USE_PlaySeInSlot 0x0200616C thumb
 *   GFL_USE_SetSeSlotParams 0x02006268 thumb
 *   GFL_USE_IsSeSlotBusy 0x02006224 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   sDowsingLevelTable 0x021F0DC8 data ov033 a4
 *   DOWSING_UpdateFade 0x021F0C44 thumb ov033
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   sDowsingBgSetup 0x021F0DF0 data ov033 a4
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   ARC_UTIL_RegisterObjCharFromHandle 0x02049740 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   BG_SYS_SetFlagField06 0x02041B6C arm
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   sDowsingPartIds 0x021F0DBC data ov033 a1
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   INFOWIN_Init 0x02024A20 thumb
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   APP_ICON_GetStatusAnimFileId 0x02027624 thumb
 *   APP_ICON_GetStatusFrameFileId 0x02027628 thumb
 *   APP_ICON_GetStatusDataFileId 0x0202762C thumb
 *   APP_ICON_GetMoveKindPaletteFileId 0x02027614 thumb
 *   APP_ICON_GetMoveKindAnimFileId 0x02027618 thumb
 *   APP_ICON_GetStatusCellFileId 0x0202761C thumb
 *   APP_ICON_GetStatusPaletteFileId 0x02027620 thumb
 *   func_02049B68 0x02049B68 arm
 *   ARC_UTIL_LoadPaletteDataFromHandle 0x02049EF4 arm
 *   BG_SYS_DrawTileEx 0x020410D0 arm
 *   CLACT_SetActorAutoAnimSpeed 0x0204B954 arm
 *   INFOWIN_Exit 0x02024DCC thumb
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   func_020355D8 0x020355D8 arm
 *   KEY_GetTrg 0x020362DC arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   FIELD_SUBSCREEN_RequestMode 0x021A0F30 thumb ov021
 *   TCB_GetTaskOffset 0x02030CB0 arm
 *   TCB_Init 0x02030CBC arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   TCB_Noop 0x02030DA4 arm
 *   TCB_Main 0x02030D28 arm
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   PALANM_RequestFade 0x0202173C thumb
 *   CLACT_StartActorAnim 0x0204B95C arm
 *   CLACT_StopActorAnim 0x0204B974 arm
 */
#include "../ov021/field_subscreen_types.h"
#include "dowsing_types.h"

#define DOWSING_ARC_ID 0xC3
#define DOWSING_HIDDEN_ITEM_FLAG_BASE 0x384
#define DOWSING_SCAN_ALL 0xFFFF
#define DOWSING_SCAN_PER_UPDATE 11
#define DOWSING_ZONE_NONE 0xFFFF
#define DOWSING_KEY_CLOSE 0x400
#define SCAN_BEST 0
#define SCAN_CURRENT 1

#define reg_GXS_DB_BLDCNT (*(volatile u16 *)0x04001050)

struct FieldSystem;
struct GameData;
struct PlayerAvatar;
struct BgTemplate;
struct Vec3Fx;

typedef struct Vec3Fx {
    int x, y, z;
} Vec3Fx;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int align, const char *file, u16 line);
extern u32 GFL_HEAP_Free(void *mem);
extern u32 ZONEDATA_CheckEventFlag(void *flagBitmap, s32 flagId);
extern int INTRUDE_FindOfferSlotAt(void *eventData, int zoneId, int x, int y, int z);
extern const DowsingHiddenItem *EVENTDATA_SYSTEM_GetHiddenItemTable(u16 *count);
extern const DowsingMapEvent *INTRUDE_GetNextOfferSpot(void *eventData, unsigned *index);
extern void *ARC_UTIL_LoadMemberWithSize(u32 arcId, u32 fileId, int compressed, u32 heapId, u32 *outSize);
extern struct Task *GFL_USE_AddMainTask(void (*proc)(int, DowsingWork *), DowsingWork *work, u32 priority);
extern struct FieldSystem *FIELDMAP_GetGameSystem(void *fieldMap);
extern struct GameData *GAMESYSTEM_GetGameData(const struct FieldSystem *fieldSystem);
extern void *GAME_DATA_GetEventWork(const struct GameData *gameData);
extern void *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern void *INTRUDE_GetFromSave(void *sys);
extern void G2x_SetBlendAlpha_(u32 reg, int plane1, int plane2, int ev1, int ev2);
extern void GFL_NET_RestartWithDefaultTimeout(u32, u32);
extern void TCB_DeleteTask(struct Task *task);
extern void INFOWIN_Update(void);
extern struct PlayerAvatar *GAMESYSTEM_GetMyPlayerWork(const struct FieldSystem *fieldSystem);
extern const Vec3Fx *GAME_DATA_GetPlayerPosition(const struct PlayerAvatar *player);
extern u32 GAME_DATA_GetFieldWork(const struct GameData *gameData);
extern int MAP_MATRIX_IsInRangeByPos(int mapId, int x, int z);
extern int MAP_MATRIX_GetZoneIdByPos(int mapId, int x, int z);
extern u32 ZONEDATA_IsFieldMatrix(u32 zoneId);
extern int ZONEDATA_IsZoneGroup118To13C(u32 zoneId);
extern int GFL_USE_GetSeSlot(u32 se);
extern void GFL_USE_PlaySeInSlot(u32 se, int handle);
extern void GFL_USE_SetSeSlotParams(int handle, u32 volume, u32 pitch, u32 pan);
extern int GFL_USE_IsSeSlotBusy(u32 handle);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern void DOWSING_UpdateFade(DowsingWork *work);
extern void TCB_Main(struct TaskSys *taskSys);
extern u32 PALANM_GetFadeRequestBits(const struct PalAnmSlot *palAnm);
extern int PALANM_RequestFade(struct PalAnmSlot *palAnm, u16 slotMask, u16 paletteMask, s16 wait, u8 startLevel, u8 endLevel, u16 color, struct TaskSys *taskSys);
extern void CLACT_StartActorAnim(struct ClactActor *actor);
extern void CLACT_StopActorAnim(struct ClactActor *actor);
extern void CLACT_SetActorDrawEnable(struct ClactActor *actor, u32 visible);
extern void CLACT_AddActorSurfacePos(struct ClactActor *actor, const ScreenPos *pos, u32 which);
extern void CLACT_SetActorAnimSeq(struct ClactActor *actor, u16 anim);
extern void CLACT_SetActorAutoAnim(struct ClactActor *actor, u32 enable);
extern void CLACT_SetActorAnimFrame(struct ClactActor *actor, u32 frame);
extern void PALANM_TransferPalettes(struct PalAnmSlot *palAnm);
extern void BG_SYS_SetPlaneVisible(unsigned char bgId, unsigned char visible);
extern void BG_SYS_InitBgLayer(unsigned int bgId, const struct BgTemplate *bgTemplate, unsigned int bgType);
extern void BG_SYS_FreeSlot(unsigned char bgId);
extern void BG_SYS_FillScrollArea(unsigned char bgId, unsigned attr, unsigned value);
extern struct ClactUnit *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct ClactUnit *unit);
extern void BG_SYS_SetSubPlaneVisible(unsigned, unsigned);
extern unsigned int CLACT_DeleteUnit(struct ClactUnit *unit);
extern void BG_SYS_FreeLayerBuf(u32 bgId);
extern void *ARC_TOOL_CreateHandle(unsigned int arcId, unsigned int heapId);
extern void ARC_UTIL_UploadPaletteFromHandle(void *archive, u32 fileId, u32 bgId, u32 offset, u32 size, u32 palSize, u16 heapId);
extern u32 ARC_UTIL_RegisterObjCharFromHandle(void *archive, u32 fileId, u32 bgId, u32 offset, u32 size, u16 heapId);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *archive, u32 fileId, u32 bgId, u32 offset, u32 charRegion, u32 x, u32 y, u16 heapId);
extern void ARC_TOOL_DeleteHandle(void *archive);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void BG_SYS_SetFlagField06(unsigned bgId);
extern void BG_SYS_DeleteHalf(u32 bgId, u32 offset, u32 size);
extern s32 CLACT_RegisterPaletteEx(void *archive, u32 fileId, u32 slotCount, u32 offset, u16 e, u16 f, u16 heapId);
extern s32 CLACT_RegisterCharacter(void *archive, u32 fileId, u32 compressed, u32 mode, u16 heapId);
extern s32 CLACT_RegisterCellAnim(void *archive, u32 cellFileId, u32 animFileId, u32 heapId);
extern struct ClactActor *CLACT_CreateActor(struct ClactUnit *unit, s32 charRes, s32 palRes, s32 cellRes, const ClactSetup *setup, unsigned short mode, unsigned short heapId);
extern void CLACT_SetActorObjMode(struct ClactActor *actor, u32 value);
extern void CLACT_DeleteActor(struct ClactActor *actor);
extern void CLACT_ReleaseCellAnim(s32 cellRes);
extern void CLACT_ReleaseCharacter(s32 charRes);
extern void CLACT_ReleasePalette(s32 palRes);
extern void INFOWIN_Init(u8 a0, u8 a1, struct GameData *gameData, u16 heapId);
extern u32 APP_ICON_GetArchiveId(void);
extern u32 APP_ICON_GetStatusAnimFileId(void);
extern u32 APP_ICON_GetStatusFrameFileId(void);
extern u32 APP_ICON_GetStatusDataFileId(void);
extern u32 APP_ICON_GetMoveKindPaletteFileId(void);
extern u32 APP_ICON_GetMoveKindAnimFileId(void);
extern u32 APP_ICON_GetStatusCellFileId(u32);
extern u32 APP_ICON_GetStatusPaletteFileId(u32);
extern void func_02049B68(void *archive, u32 fileId, u32 bgId, u32 offset, u32 size, u16 heapId);
extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *archive, u32 fileId, u32 compressed, void **outData, u16 heapId);
extern void BG_SYS_DrawTileEx(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void CLACT_SetActorAutoAnimSpeed(struct ClactActor *actor, u32 value);
extern int INFOWIN_Exit(void);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outX, u32 *outY);
extern void func_020355D8(u8 touchMode);
extern u32 KEY_GetTrg(void);
extern u32 CLACT_IsActorAnimActive(struct ClactActor *actor);
extern int FIELD_SUBSCREEN_RequestMode(FieldSubscreen *subscreen, u32 mode);
extern unsigned TCB_GetTaskOffset(unsigned);
extern struct TaskSys *TCB_Init(u32 capacity, void *mem);
extern struct PalAnmSlot *PALANM_Create(u32 heapId);
extern void PALANM_SetAutoTransfer(struct PalAnmSlot *palAnm, int enable);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *palAnm, u32 slot, u32 size, u32 heapId);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *palAnm, u32 slot, u32 offset, u32 size);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *palAnm, u32 slot);
extern u32 PALANM_Delete(struct PalAnmSlot *palAnm);
extern void TCB_Noop(struct TaskSys *taskSys);

DowsingSearch *DOWSING_CreateSearch(u32 heapId, void *eventFlags, void *eventData);
void DOWSING_DeleteSearch(DowsingSearch *search);
int DOWSING_IsTargetAvailable(DowsingSearch *search, DowsingTarget *target);
void DOWSING_ResetSearch(DowsingSearch *search);
int DOWSING_FindNextTarget(DowsingSearch *search, DowsingTarget *out, int mode);
DowsingWork *DOWSING_Create(u32 heapId, u32 ownerHeapId, FieldSubscreen *subscreen, void *fieldMap);
void DOWSING_Delete(DowsingWork *work);
void DOWSING_Update(DowsingWork *work, int isOn);
void DOWSING_UpdateDisplay(DowsingWork *work, int draw);
void DOWSING_TaskTransferPalettes(int taskId, DowsingWork *work);
void DOWSING_InitBgsAndActorUnit(DowsingWork *work);
void DOWSING_ExitBgsAndActorUnit(DowsingWork *work);
void DOWSING_LoadBackground(DowsingWork *work);
void DOWSING_FreeBackground(DowsingWork *work);
void DOWSING_CreateParts(DowsingWork *work);
void DOWSING_DeleteParts(DowsingWork *work);
void DOWSING_CreateCloseButton(DowsingWork *work);
void DOWSING_DeleteCloseButton(DowsingWork *work);
void DOWSING_UpdateCloseButton(DowsingWork *work);
void DOWSING_InitFade(DowsingWork *work);
void DOWSING_ExitFade(DowsingWork *work);
extern const char sDowsingFileName[];
extern const DowsingLevelEntry sDowsingLevelTable[];
extern DowsingBgSetup sDowsingBgSetup[];
extern const DowsingPartIds sDowsingPartIds[];

DowsingSearch *DOWSING_CreateSearch(u32 heapId, void *eventFlags, void *eventData)
{
    DowsingSearch *search;
    search = GFL_HEAP_Alloc(heapId, sizeof(DowsingSearch), 1, sDowsingFileName, 0x8d);
    search->eventFlags = eventFlags;
    search->itemIndex = 0;
    search->eventData = eventData;
    search->eventIndex = 0;
    return search;
}

void DOWSING_DeleteSearch(DowsingSearch *search)
{
    GFL_HEAP_Free(search);
}

/* Is the target still there: item not picked up yet, object still on the map. */
int DOWSING_IsTargetAvailable(DowsingSearch *search, DowsingTarget *target)
{
    int available;
    if (target->kind == DOWSING_TARGET_HIDDEN_ITEM) {
        const DowsingHiddenItem *item = target->item;
        return ZONEDATA_CheckEventFlag(search->eventFlags, (u16)(item->flagIndex + DOWSING_HIDDEN_ITEM_FLAG_BASE)) == 0;
    }
    if (target->kind == DOWSING_TARGET_MAP_EVENT) {
        const DowsingMapEvent *event = target->event;
        available = 0;
        if (INTRUDE_FindOfferSlotAt(search->eventData, (unsigned short)event->zoneId, event->x, event->y, event->z) != 0xFF)
            available = 1;
        return available;
    }
    return 0;
}

void DOWSING_ResetSearch(DowsingSearch *search)
{
    search->itemIndex = 0;
    search->eventIndex = 0;
}

/*
 * Moves the cursor to the next available target of the kinds that mode
 * allows (0 both, 1 hidden items, 2 map events). Returns 1 and fills out,
 * or returns 0 with out->kind cleared when the end is reached.
 */
int DOWSING_FindNextTarget(DowsingSearch *search, DowsingTarget *out, int mode)
{
    u16 itemCount;
    unsigned eventIndex;
    DowsingTarget candidate;
    const DowsingHiddenItem *items;
    const DowsingMapEvent *event;
    int found;

    found = 0;
    items = EVENTDATA_SYSTEM_GetHiddenItemTable(&itemCount);
    eventIndex = search->eventIndex;
    if (mode == 0 || mode == 1) {
        while (search->itemIndex < itemCount) {
            candidate.kind = DOWSING_TARGET_HIDDEN_ITEM;
            candidate.item = items + search->itemIndex;
            if (DOWSING_IsTargetAvailable(search, &candidate)) {
                out->kind = candidate.kind;
                out->item = candidate.item;
                found = 1;
            }
            search->itemIndex++;
            if (found)
                return 1;
        }
    }
    if (mode == 0 || mode == 2) {
        event = INTRUDE_GetNextOfferSpot(search->eventData, &eventIndex);
        search->eventIndex = eventIndex;
        while (event != 0) {
            candidate.event = event;
            candidate.kind = DOWSING_TARGET_MAP_EVENT;
            if (DOWSING_IsTargetAvailable(search, &candidate)) {
                out->kind = candidate.kind;
                out->event = candidate.event;
                found = 1;
            }
            if (found)
                return 1;
            event = INTRUDE_GetNextOfferSpot(search->eventData, &eventIndex);
            search->eventIndex = eventIndex;
        }
    }
    out->kind = DOWSING_TARGET_NONE;
    return 0;
}

DowsingWork *DOWSING_Create(u32 heapId, u32 ownerHeapId, FieldSubscreen *subscreen, void *fieldMap)
{
    DowsingWork *work;
    u32 size;
    struct GameData *gameData;
    void *eventFlags;

    work = GFL_HEAP_Alloc(heapId, sizeof(DowsingWork), 1, sDowsingFileName, 0x272);
    work->heapId = heapId;
    work->ownerHeapId = ownerHeapId;
    work->subscreen = subscreen;
    work->fieldMap = fieldMap;
    DOWSING_InitBgsAndActorUnit(work);
    DOWSING_LoadBackground(work);
    DOWSING_CreateParts(work);
    DOWSING_CreateCloseButton(work);
    work->levelGrid = ARC_UTIL_LoadMemberWithSize(DOWSING_ARC_ID, 0xD, 0, work->heapId, &size);
    work->task = GFL_USE_AddMainTask(DOWSING_TaskTransferPalettes, work, 1);
    work->tick = 0;
    work->isOn = 1;
    DOWSING_InitFade(work);
    work->prevLevel = 10;
    work->level = DOWSING_LEVEL_NONE;
    work->shownLevel = 10;
    work->prevTarget.kind = 0;
    work->target.kind = 0;
    work->gridX = 0;
    work->gridY = 0;
    work->gridZ = 0;
    work->hasSearched = 0;
    work->seStarted = 0;
    work->restartFoundAnim = 0;
    DOWSING_UpdateDisplay(work, 1);
    work->needReset = 1;
    work->needFullScan = 1;
    gameData = GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(work->fieldMap));
    eventFlags = GAME_DATA_GetEventWork(gameData);
    work->search = DOWSING_CreateSearch(work->heapId, eventFlags, INTRUDE_GetFromSave(GAME_DATA_GetSaveControl(gameData)));
    G2x_SetBlendAlpha_((u32)&reg_GXS_DB_BLDCNT, 0x10, 0x18, 1, 7);
    GFL_NET_RestartWithDefaultTimeout(0, work->heapId);
    return work;
}

void DOWSING_Delete(DowsingWork *work)
{
    reg_GXS_DB_BLDCNT = 0;
    DOWSING_DeleteSearch(work->search);
    DOWSING_ExitFade(work);
    TCB_DeleteTask(work->task);
    GFL_HEAP_Free(work->levelGrid);
    DOWSING_DeleteCloseButton(work);
    DOWSING_DeleteParts(work);
    DOWSING_FreeBackground(work);
    DOWSING_ExitBgsAndActorUnit(work);
    GFL_HEAP_Free(work);
}

/*
 * Per-frame update while the screen runs. When the machine is on it finds
 * the nearest target within the 32 x 24 window around the player, reads the
 * level of that cell and plays the proximity sounds.
 */
void DOWSING_Update(DowsingWork *work, int isOn)
{
    DowsingTarget scan[2]; /* SCAN_BEST, SCAN_CURRENT */
    int playLevelSound;
    int levelChanged;
    int prevX;
    u32 mapId;
    struct FieldSystem *fieldSystem;
    int gridX, gridY, gridZ;
    int zoneId;
    int zoneFlag;
    u32 scanCount;
    int minX, maxX, minZ, maxZ;
    int bestDist;
    u16 bestCell;
    const DowsingHiddenItem *item;
    const DowsingMapEvent *event;
    int newX, newZ;
    const Vec3Fx *pos;
    int runScan;
    int startSe;
    u16 targetIndex;
    int x, z;
    int dx, dz;
    u16 cell;
    u32 dist;
    int handle;
    int pan;
    int level;
    u32 kind;

    work->isOn = isOn;
    if (isOn)
        work->fadeRequest = DOWSING_FADE_IN;
    else
        work->fadeRequest = DOWSING_FADE_OUT;
    INFOWIN_Update();
    if (isOn == 0)
        return;
    work->prevLevel = work->level;
    work->prevTarget.kind = work->target.kind;
    if (work->prevTarget.kind == DOWSING_TARGET_HIDDEN_ITEM)
        work->prevTarget.item = work->target.item;
    else if (work->prevTarget.kind == DOWSING_TARGET_MAP_EVENT)
        work->prevTarget.event = work->target.event;
    fieldSystem = FIELDMAP_GetGameSystem(work->fieldMap);
    pos = GAME_DATA_GetPlayerPosition(GAMESYSTEM_GetMyPlayerWork(fieldSystem));
    gridX = (pos->x >> 4) / 4096;
    gridY = (pos->y >> 4) / 4096;
    gridZ = (pos->z >> 4) / 4096;
    mapId = GAME_DATA_GetFieldWork(GAMESYSTEM_GetGameData(fieldSystem));
    zoneId = DOWSING_ZONE_NONE;
    zoneFlag = 0;
    if (MAP_MATRIX_IsInRangeByPos((int)mapId, pos->x, pos->z) == 1) {
        zoneId = MAP_MATRIX_GetZoneIdByPos((int)mapId, pos->x, pos->z);
        zoneFlag = (int)ZONEDATA_IsFieldMatrix((u16)zoneId);
    }
    /* Both branches scan; the flag only records that a scan happened. */
    if (work->hasSearched == 0) {
        work->hasSearched = 1;
        runScan = 1;
    } else {
        runScan = 1;
    }
    if (runScan) {
        minX = gridX - 15;
        maxX = gridX + 17;
        minZ = gridZ - 11;
        maxZ = gridZ + 13;
        bestDist = -1;
        scan[SCAN_BEST].kind = DOWSING_TARGET_NONE;
        if (work->needReset != 0) {
            DOWSING_ResetSearch(work->search);
            work->needReset = 0;
        }
        if (work->needFullScan != 0) {
            scanCount = DOWSING_SCAN_ALL;
            work->needFullScan = 0;
        } else {
            scanCount = DOWSING_SCAN_PER_UPDATE;
        }
        for (targetIndex = 0; targetIndex < scanCount; targetIndex++) {
            if (targetIndex == 0) {
                if (work->prevTarget.kind != DOWSING_TARGET_NONE) {
                    if (DOWSING_IsTargetAvailable(work->search, &work->prevTarget)) {
                        scan[SCAN_CURRENT].kind = work->prevTarget.kind;
                        if (scan[SCAN_CURRENT].kind == DOWSING_TARGET_HIDDEN_ITEM)
                            scan[SCAN_CURRENT].item = work->prevTarget.item;
                        else if (scan[SCAN_CURRENT].kind == DOWSING_TARGET_MAP_EVENT)
                            scan[SCAN_CURRENT].event = work->prevTarget.event;
                    } else {
                        work->needReset = 1;
                        work->needFullScan = 1;
                        break;
                    }
                }
            } else {
                if ((work->needReset = DOWSING_FindNextTarget(work->search, &scan[SCAN_CURRENT], 0) ? 0 : 1) != 0)
                    break;
            }
            if (zoneId == DOWSING_ZONE_NONE)
                continue;
            if (scan[SCAN_CURRENT].kind == DOWSING_TARGET_HIDDEN_ITEM) {
                item = scan[SCAN_CURRENT].item;
                if (zoneId != item->zoneId) {
                    if (item->crossZone == 0)
                        continue;
                    if (zoneFlag == 0)
                        continue;
                    if (ZONEDATA_IsZoneGroup118To13C(item->zoneId) != 0)
                        continue;
                }
                x = item->x;
                z = item->z;
            } else if (scan[SCAN_CURRENT].kind == DOWSING_TARGET_MAP_EVENT) {
                event = scan[SCAN_CURRENT].event;
                if ((int)ZONEDATA_IsFieldMatrix((u16)event->zoneId) == 0)
                    continue;
                if (zoneFlag == 0)
                    continue;
                x = event->x;
                z = event->z;
            }
            if (minX <= x && x < maxX && minZ <= z && z < maxZ) {
                dz = z - gridZ;
                dx = x - gridX;
                cell = (u16)(dx + 15 + (dz + 11) * 32);
                if (work->levelGrid[cell] == DOWSING_LEVEL_NONE)
                    continue;
                dist = dx * dx + dz * dz;
                if (dist < (u32)bestDist) {
                    bestCell = cell;
                    bestDist = dist;
                    scan[SCAN_BEST].kind = scan[SCAN_CURRENT].kind;
                    if (scan[SCAN_CURRENT].kind == DOWSING_TARGET_HIDDEN_ITEM)
                        scan[SCAN_BEST].item = scan[SCAN_CURRENT].item;
                    else if (scan[SCAN_CURRENT].kind == DOWSING_TARGET_MAP_EVENT)
                        scan[SCAN_BEST].event = scan[SCAN_CURRENT].event;
                }
            }
        }
        kind = scan[SCAN_BEST].kind;
        work->target.kind = kind;
        if (kind != DOWSING_TARGET_NONE) {
            work->level = work->levelGrid[bestCell];
            if (kind == DOWSING_TARGET_HIDDEN_ITEM)
                work->target.item = scan[SCAN_BEST].item;
            else if (kind == DOWSING_TARGET_MAP_EVENT)
                work->target.event = scan[SCAN_BEST].event;
        } else {
            work->level = DOWSING_LEVEL_NONE;
        }
    }
    playLevelSound = 1;
    if (work->level == DOWSING_LEVEL_ON_TARGET) {
        startSe = 0;
        if (work->seStarted == 0) {
            startSe = 1;
            work->seStarted = 1;
        } else if (work->seTimer == 6) {
            if (GFL_USE_IsSeSlotBusy(work->seHandle) == 0)
                work->seTimer--;
        } else if (work->seTimer == 0) {
            startSe = 1;
        } else {
            work->seTimer--;
        }
        if (startSe) {
            work->seHandle = GFL_USE_GetSeSlot(DOWSING_SE_PROXIMITY);
            GFL_USE_PlaySeInSlot(DOWSING_SE_PROXIMITY, work->seHandle);
            GFL_USE_SetSeSlotParams(work->seHandle, -1, 0x180, -1);
            work->seTimer = 6;
            work->restartFoundAnim = 1;
        }
        playLevelSound = 0;
    } else {
        work->seStarted = 0;
    }
    if (playLevelSound && (level = work->level) != DOWSING_LEVEL_ON_TARGET && work->target.kind != DOWSING_TARGET_NONE) {
        levelChanged = 0;
        if (work->prevTarget.kind == DOWSING_TARGET_HIDDEN_ITEM) {
            item = work->prevTarget.item;
            prevX = item->x;
            z = item->z;
        } else if (work->prevTarget.kind == DOWSING_TARGET_MAP_EVENT) {
            event = work->prevTarget.event;
            prevX = event->x;
            z = event->z;
        } else {
            levelChanged = 1;
            goto done;
        }
        if (work->target.kind == DOWSING_TARGET_HIDDEN_ITEM) {
            item = work->target.item;
            newX = item->x;
            newZ = item->z;
        } else if (work->target.kind == DOWSING_TARGET_MAP_EVENT) {
            event = work->target.event;
            newX = event->x;
            newZ = event->z;
        }
        if ((prevX != newX || z != newZ) && work->prevLevel != level)
            levelChanged = 1;
    done:
        if (levelChanged) {
            handle = GFL_USE_GetSeSlot(DOWSING_SE_PROXIMITY);
            pan = ((int)sDowsingLevelTable[work->level].pan - 8) * 16;
            if (pan < -127)
                pan = -127;
            else if (pan > 127)
                pan = 127;
            GFL_USE_PlaySeInSlot(DOWSING_SE_PROXIMITY, handle);
            GFL_USE_SetSeSlotParams(handle, -1, -1, pan);
            playLevelSound = 0;
        }
    }
    if (playLevelSound && work->prevLevel != work->level)
        GFL_USE_PlaySeDefaultVolume(DOWSING_SE_LEVEL_CHANGE);
    work->gridX = gridX;
    work->gridY = gridY;
    work->gridZ = gridZ;
    DOWSING_UpdateCloseButton(work);
}

/* Redraws the sprites after the level changed and runs the fade. */
void DOWSING_UpdateDisplay(DowsingWork *work, int draw)
{
    ScreenPos pos;

    DOWSING_UpdateFade(work);
    if (draw == 0)
        return;
    if (work->shownLevel != work->level) {
        CLACT_SetActorDrawEnable(work->parts[DOWSING_PART_DIRECTION].actor,
                      (work->level == DOWSING_LEVEL_ON_TARGET || work->level == DOWSING_LEVEL_NONE) ? 0 : 1);
        CLACT_SetActorDrawEnable(work->parts[DOWSING_PART_FOUND_MARK].actor, work->level == DOWSING_LEVEL_ON_TARGET);
        pos.x = sDowsingLevelTable[work->level].directionX;
        pos.y = sDowsingLevelTable[work->level].directionY;
        CLACT_AddActorSurfacePos(work->parts[DOWSING_PART_DIRECTION].actor, &pos, 1);
        CLACT_SetActorAnimSeq(work->parts[DOWSING_PART_LEFT_GAUGE].actor, sDowsingLevelTable[work->level].leftAnim);
        CLACT_SetActorAnimSeq(work->parts[DOWSING_PART_RIGHT_GAUGE].actor, sDowsingLevelTable[work->level].rightAnim);
        CLACT_SetActorAnimSeq(work->parts[DOWSING_PART_DIRECTION].actor, sDowsingLevelTable[work->level].directionAnim);
        work->shownLevel = work->level;
    }
    if (work->level == DOWSING_LEVEL_ON_TARGET && work->restartFoundAnim != 0) {
        CLACT_SetActorAnimSeq(work->parts[DOWSING_PART_FOUND_MARK].actor, 0);
        CLACT_SetActorAutoAnim(work->parts[DOWSING_PART_FOUND_MARK].actor, 1);
        CLACT_SetActorAnimFrame(work->parts[DOWSING_PART_FOUND_MARK].actor, 0);
        work->restartFoundAnim = 0;
    }
}

/* Task that transfers the palettes every frame and ticks the counter. */
void DOWSING_TaskTransferPalettes(int taskId, DowsingWork *work)
{
    PALANM_TransferPalettes(work->palAnm);
    if (work->isOn != 0) {
        if (work->tick >= 4)
            work->tick = 0;
        work->tick++;
    }
}

/* Hides BG 4 to 7, sets up the two screen layers and the actor unit. */
void DOWSING_InitBgsAndActorUnit(DowsingWork *work)
{
    int i;
    unsigned bgId;
    DowsingBgSetup *setup;
    unsigned j;
    for (i = 4; i <= 7; i++)
        BG_SYS_SetPlaneVisible((unsigned char)i, (unsigned char)0);
    for (j = 0; j < 2; j++) {
        setup = &sDowsingBgSetup[j];
        bgId = setup->bgId;
        BG_SYS_InitBgLayer((unsigned char)bgId, (const struct BgTemplate *)setup->bgTemplate, (unsigned char)setup->bgType);
        BG_SYS_FreeSlot(bgId);
        BG_SYS_SetPlaneVisible((unsigned char)bgId, (unsigned char)setup->visible);
        BG_SYS_FillScrollArea(bgId, 0, 0);
        BG_SYS_FillScrollArea(bgId, 3, 0);
    }
    work->clactUnit = CLACT_CreateUnit(8, 0, work->heapId);
    CLACT_SetUnitDefaultRenderer(work->clactUnit);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

void DOWSING_ExitBgsAndActorUnit(DowsingWork *work)
{
    unsigned i;
    CLACT_DeleteUnit(work->clactUnit);
    for (i = 0; i < 2; i++)
        BG_SYS_FreeLayerBuf((unsigned char)sDowsingBgSetup[i].bgId);
}

/* Loads palette, tiles and screen of BG 7 from the archive. */
void DOWSING_LoadBackground(DowsingWork *work)
{
    unsigned heapId = work->ownerHeapId;
    void *archive = ARC_TOOL_CreateHandle(DOWSING_ARC_ID, heapId);
    unsigned charRegion;
    ARC_UTIL_UploadPaletteFromHandle(archive, 0, 4, 0, 0, 0x40, heapId);
    charRegion = ARC_UTIL_RegisterObjCharFromHandle(archive, 2, 7, 0, 0, heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(archive, 7, 7, 0, (unsigned short)charRegion, 0, 0, heapId);
    ARC_TOOL_DeleteHandle(archive);
    BG_SYS_FillTileMap(7, 0, 0, 0x20, 0x18, 1);
    BG_SYS_SetFlagField06(7);
    work->bgCharRegion7 = charRegion;
}

void DOWSING_FreeBackground(DowsingWork *work)
{
    unsigned region = work->bgCharRegion7;
    BG_SYS_DeleteHalf(7, (unsigned short)region, (unsigned short)(region >> 16));
}

/*
 * Creates the four sprite parts. The right gauge (part 1) shares the
 * resources of the left gauge.
 *
 * note:     the four `strh #0` at the loop top are `ClactSetup setup = {0};`
 *           declared in the loop body (field-by-field zeroing ends in two
 *           strb), and `pos` lives in its own block after the loop so it
 *           takes the lower slot (sp+0x10) below `setup` (sp+0x14).
 */
void DOWSING_CreateParts(DowsingWork *work)
{
    void *archive;
    u8 i;

    archive = ARC_TOOL_CreateHandle(DOWSING_ARC_ID, work->ownerHeapId);
    work->partsPalRes = CLACT_RegisterPaletteEx(archive, 1, 1, 0, 0, 1, work->heapId);
    for (i = 0; i < DOWSING_PART_COUNT; i++) {
        ClactSetup setup = {0};
        if (i == DOWSING_PART_RIGHT_GAUGE) {
            work->parts[i].charRes = work->parts[DOWSING_PART_LEFT_GAUGE].charRes;
            work->parts[i].cellRes = work->parts[DOWSING_PART_LEFT_GAUGE].cellRes;
        } else {
            work->parts[i].charRes = CLACT_RegisterCharacter(archive, sDowsingPartIds[i].charId, 0, 1, work->heapId);
            work->parts[i].cellRes = CLACT_RegisterCellAnim(archive, sDowsingPartIds[i].cellId, sDowsingPartIds[i].animId, work->heapId);
        }
        setup.priority = i;
        work->parts[i].actor = CLACT_CreateActor(work->clactUnit, work->parts[i].charRes, work->partsPalRes, work->parts[i].cellRes, &setup, 1, work->heapId);
        CLACT_SetActorAutoAnim(work->parts[i].actor, 1);
        CLACT_SetActorObjMode(work->parts[i].actor, 1);
    }
    ARC_TOOL_DeleteHandle(archive);
    {
        ScreenPos pos;

        pos.x = 0x50;
        pos.y = 0x60;
        CLACT_AddActorSurfacePos(work->parts[DOWSING_PART_LEFT_GAUGE].actor, &pos, 1);
        pos.x = 0xB0;
        pos.y = 0x60;
        CLACT_AddActorSurfacePos(work->parts[DOWSING_PART_RIGHT_GAUGE].actor, &pos, 1);
        pos.x = 0x80;
        pos.y = 0x60;
        CLACT_AddActorSurfacePos(work->parts[DOWSING_PART_FOUND_MARK].actor, &pos, 1);
    }
}

void DOWSING_DeleteParts(DowsingWork *work)
{
    unsigned char i;
    for (i = 0; i < DOWSING_PART_COUNT; i++) {
        CLACT_DeleteActor(work->parts[i].actor);
        if (i != DOWSING_PART_RIGHT_GAUGE) {
            CLACT_ReleaseCellAnim(work->parts[i].cellRes);
            CLACT_ReleaseCharacter(work->parts[i].charRes);
        }
    }
    CLACT_ReleasePalette(work->partsPalRes);
}

/*
 * Builds the close button (BG 4 panel and one actor).
 *
 * note:     the four `strh #0` after INFOWIN_Init are `ClactSetup setup = {0};`
 *           opening an inner block there; declared at the top they land
 *           before the first call.
 */
void DOWSING_CreateCloseButton(DowsingWork *work)
{
    ScreenData *screen;
    u32 ownerHeapId;

    ownerHeapId = work->ownerHeapId;
    INFOWIN_Init(4, 3, GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(work->fieldMap)), work->heapId);
    {
        ClactSetup setup = {0};
        void *screenFile;
        void *archive;
        u16 *tiles;
        u16 i;
        u16 base;

        archive = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), ownerHeapId);
        func_02049B68(archive, APP_ICON_GetStatusAnimFileId(), 4, 0x40, 0x20, ownerHeapId);
        work->bgCharRegion4 = ARC_UTIL_RegisterObjCharFromHandle(archive, APP_ICON_GetStatusFrameFileId(), 4, 0, 0, ownerHeapId);
        screenFile = ARC_UTIL_LoadPaletteDataFromHandle(archive, APP_ICON_GetStatusDataFileId(), 0, (void **)&screen, ownerHeapId);
        base = work->bgCharRegion4;
        tiles = screen->tiles;
        for (i = 0; i < 0x300; i++) {
            tiles[i] &= 0xFFF;
            tiles[i] = (base + tiles[i]) | 0x2000;
        }
        BG_SYS_DrawTileEx(4, 0, 0x15, 0x20, 3, (u32)screen->tiles, 0, 0x15, 0x20, 0x18);
        BG_SYS_SetFlagField06(4);
        GFL_HEAP_Free(screenFile);
        work->buttonPalRes = CLACT_RegisterPaletteEx(archive, APP_ICON_GetMoveKindPaletteFileId(), 1, 0x20, 0, 3, work->heapId);
        work->buttonCharRes = CLACT_RegisterCharacter(archive, APP_ICON_GetMoveKindAnimFileId(), 0, 1, work->heapId);
        work->buttonCellRes = CLACT_RegisterCellAnim(archive, APP_ICON_GetStatusCellFileId(0), APP_ICON_GetStatusPaletteFileId(0), work->heapId);
        setup.x = 0xE8;
        setup.y = 0xA8;
        work->buttonActor = CLACT_CreateActor(work->clactUnit, work->buttonCharRes, work->buttonPalRes, work->buttonCellRes, &setup, 1, work->heapId);
        CLACT_SetActorAutoAnim(work->buttonActor, 1);
        CLACT_SetActorAutoAnimSpeed(work->buttonActor, 0x2000);
        CLACT_SetActorAnimSeq(work->buttonActor, 0);
        ARC_TOOL_DeleteHandle(archive);
        work->buttonState = DOWSING_BUTTON_IDLE;
    }
}

void DOWSING_DeleteCloseButton(DowsingWork *work)
{
    unsigned region;
    CLACT_DeleteActor(work->buttonActor);
    CLACT_ReleaseCellAnim(work->buttonCellRes);
    CLACT_ReleaseCharacter(work->buttonCharRes);
    CLACT_ReleasePalette(work->buttonPalRes);
    region = work->bgCharRegion4;
    BG_SYS_DeleteHalf(4, (unsigned short)region, (unsigned short)(region >> 16));
    INFOWIN_Exit();
}

/* Close button: touch box or key press, press animation, then the mode change. */
void DOWSING_UpdateCloseButton(DowsingWork *work)
{
    unsigned touchX;
    unsigned touchY;
    int pressed;

    switch (work->buttonState) {
    case DOWSING_BUTTON_IDLE:
        pressed = 0;
        if (TOUCHPANEL_GetPointTrg(&touchX, &touchY) != 0) {
            if (touchX >= 0xE8 && touchX < 0x100 && touchY >= 0xA8 && touchY < 0xC0) {
                func_020355D8(1);
                pressed = 1;
            }
        }
        if (pressed == 0) {
            if (KEY_GetTrg() & DOWSING_KEY_CLOSE) {
                func_020355D8(0);
                pressed = 1;
            }
        }
        if (pressed != 0) {
            work->buttonState = DOWSING_BUTTON_PRESSED;
            CLACT_SetActorAnimSeq(work->buttonActor, 8);
            GFL_USE_PlaySeDefaultVolume(DOWSING_SE_CLOSE);
            return;
        }
        break;
    case DOWSING_BUTTON_PRESSED:
        if (CLACT_IsActorAnimActive(work->buttonActor) == 0) {
            work->buttonState = DOWSING_BUTTON_RELEASED;
            CLACT_SetActorAnimSeq(work->buttonActor, 0);
            return;
        }
        break;
    case DOWSING_BUTTON_RELEASED:
        FIELD_SUBSCREEN_RequestMode(work->subscreen, 0);
        work->buttonState = DOWSING_BUTTON_CLOSE_REQUESTED;
        break;
    case DOWSING_BUTTON_CLOSE_REQUESTED:
        break;
    }
}

/*
 * note:     TCB_Init takes (n, mem) (GFL_USE_InitSystem): the 0xB8 result
 *           left in r1 before `blx TCB_Init` is its second argument.
 */
void DOWSING_InitFade(DowsingWork *work)
{
    work->fadeTaskMem = GFL_HEAP_Alloc(work->heapId, TCB_GetTaskOffset(2), 1, sDowsingFileName, 0x6DF);
    work->fadeTaskSys = TCB_Init(2, work->fadeTaskMem);
    work->palAnm = PALANM_Create(work->heapId);
    PALANM_SetAutoTransfer(work->palAnm, 1);
    PALANM_AllocSlotBuffers(work->palAnm, 1, 0x60, work->heapId);
    PALANM_AllocSlotBuffers(work->palAnm, 3, 0x80, work->heapId);
    PALANM_CopyHwPaletteToSlot(work->palAnm, 1, 0, 0x60);
    PALANM_CopyHwPaletteToSlot(work->palAnm, 3, 0, 0x80);
    work->fadeRequest = DOWSING_FADE_NONE;
    work->fadeState = 0;
}

void DOWSING_ExitFade(DowsingWork *work)
{
    PALANM_FreeSlotBuffers(work->palAnm, 1);
    PALANM_FreeSlotBuffers(work->palAnm, 3);
    PALANM_Delete(work->palAnm);
    TCB_Noop(work->fadeTaskSys);
    GFL_HEAP_Free(work->fadeTaskMem);
}

/*
 * Runs the fade task system and, once the previous fade is done, applies the
 * requested fade of the two palette slots: in shows the sprites and starts
 * their animations, out darkens them and stops the animations.
 */
void DOWSING_UpdateFade(DowsingWork *work)
{
    u16 paletteMask;
    u8 i;

    TCB_Main(work->fadeTaskSys);
    if (work->fadeRequest == DOWSING_FADE_NONE || PALANM_GetFadeRequestBits(work->palAnm) != 0)
        return;
    switch (work->fadeRequest) {
    case DOWSING_FADE_IN:
        if (work->fadeState != 0) {
            paletteMask = 0;
            for (i = 0; i < 3; i++)
                paletteMask |= (u16)(1 << i);
            PALANM_RequestFade(work->palAnm, 2, paletteMask, 0, 0, 0, 0, work->fadeTaskSys);
            paletteMask = 0;
            for (i = 0; i < 4; i++)
                paletteMask |= (u16)(1 << i);
            PALANM_RequestFade(work->palAnm, 8, paletteMask, 0, 0, 0, 0, work->fadeTaskSys);
            work->fadeState = 0;
            for (i = 0; i < DOWSING_PART_COUNT; i++)
                CLACT_StartActorAnim(work->parts[i].actor);
        }
        break;
    case DOWSING_FADE_OUT:
        if (work->fadeState != 1) {
            paletteMask = 0;
            for (i = 0; i < 3; i++)
                paletteMask |= (u16)(1 << i);
            PALANM_RequestFade(work->palAnm, 2, paletteMask, 0, 8, 8, 0, work->fadeTaskSys);
            paletteMask = 0;
            for (i = 0; i < 4; i++)
                paletteMask |= (u16)(1 << i);
            PALANM_RequestFade(work->palAnm, 8, paletteMask, 0, 8, 8, 0, work->fadeTaskSys);
            work->fadeState = 1;
            for (i = 0; i < DOWSING_PART_COUNT; i++)
                CLACT_StopActorAnim(work->parts[i].actor);
        }
        break;
    }
    work->fadeRequest = DOWSING_FADE_NONE;
}
