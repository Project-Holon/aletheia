/*
 * file:     calender.c
 * unit:     yes
 * function: EVENTDATA_SYSTEM_CreateFieldLinkEvent, EVENTDATA_SYSTEM_CheckBicycleUsable, EVENTDATA_SYSTEM_CheckWeatherZone, EVENTDATA_SYSTEM_CheckNormalFieldZone, EVENTDATA_SYSTEM_CheckFrontTileUsable, EVENTDATA_SYSTEM_CheckNormalFieldZoneNotZone34, EVENTDATA_SYSTEM_FieldLinkEnterEvent, EVENTDATA_SYSTEM_CreateFieldLinkEnterEvent, EVENTDATA_SYSTEM_AddFieldLinkObject, EVENTDATA_SYSTEM_ToggleSubscreenEvent, EVENTDATA_SYSTEM_CreateToggleSubscreenEvent, EVENTDATA_SYSTEM_GetHiddenItemIndex, EVENTDATA_SYSTEM_GetHiddenItemFlag, EVENTDATA_SYSTEM_RespawnHiddenItems, EVENTDATA_SYSTEM_GetHiddenItemTable, EVENTDATA_SYSTEM_ScrCmdRunOverlay47, CALENDER_Create, CALENDER_Delete, CALENDER_GetWeatherThunk, CALENDER_ClearResources, CALENDER_OpenArchive, CALENDER_CloseArchive, CALENDER_GetWeather, CALENDER_GetWeatherOnDate, CALENDER_LoadZoneTable, CALENDER_FindZoneOffset, CALENDER_GetDayOfYear, FLD_FACEUP_ScrCmdStart, FLD_FACEUP_ScrCmdPrepareField, FLD_FACEUP_ScrCmdWaitEnd, FLD_FACEUP_Finish, FLD_FACEUP_EndEvent, CALENDER_OverlaySequenceEvent
 * address:  0x021644F4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FieldLinkEventTable     0x02171504  data
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GAME_DATA_GetPlayerObjectCode  0x02012B28  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_GetNowAttribute  0x021A30C8  thumb
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb
 *   MAP_ATTR_IsRoughGround  0x021AB4B8  thumb
 *   ZONEDATA_IsBikeEnabled  0x02013C20  thumb
 *   ZONEDATA_IsNormalFieldZone 0x02013E04 thumb
 *   ZONEDATA_IsWeatherEnabled 0x02013C50 thumb
 *   FISHING_CheckFacingWater  0x021C5C64  thumb  ov021
 *   ZONEDATA_IsZone34   0x02013D20  thumb
 *   ICA_ANIME_GetField20  0x0201210C  thumb
 *   ICA_ANIME_GetField24  0x02012138  thumb
 *   INTRUDE_COMM_IsSessionEndPending  0x0215870C  thumb ov010
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb ov021
 *   FIELDMAP_CheckPlayerRequest  0x02188BF8  thumb ov021
 *   FIELD_PLAYER_StepFormChange  0x021A2F54  thumb ov021
 *   FIELD_PLAYER_WaitModelReady  0x021A34F8  thumb ov021
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   EVENT_MAPCHANGE_CreateIntrudeWarpEvent 0x02185140 thumb ov020
 *   FIELDMAP_GetSubscreen 0x02188CCC thumb ov021
 *   FIELD_SUBSCREEN_GetMode 0x021A0F90 thumb ov021
 *   FIELD_SUBSCREEN_RequestMode 0x021A0F30 thumb ov021
 *   HiddenItemTable     0x02171534  data
 *   ZONEDATA_PopTimeFlagsCleared  0x0201440C  thumb
 *   func_020056EC  0x020056EC  thumb
 *   ZONEDATA_ResetEventFlag  0x0201433C  thumb
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   func_02034AC4 0x02034AC4 arm
 *   FIELD_GIMMICK_BRIDGE_ResetSave 0x021F3800 thumb ov047
 *   func_02034A5C 0x02034A5C arm
 *   ov_id_47 0x0000002F data
 *   func_02030734 0x02030734 arm
 *   CalenderFileName 0x021729B0 data ov010 a1
 *   func_020307B0  0x020307B0  arm
 *   func_020490F4  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   FIELD_CLOCK_GetMonth 0x021690D0 thumb ov010
 *   FIELD_CLOCK_GetDay 0x021690E0 thumb ov010
 *   ZONEDATA_GetWeatherId  0x02013C10  thumb
 *   ARC_TOOL_ReadHandleMemberRange  0x0204944C  arm
 *   DaysPerMonthTable  0x02171C20  data  ov010  a1
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb ov010
 *   func_02011330  0x02011330  thumb
 *   SCRIPT_WORK_SetCheckFlag  0x02159144  thumb ov010
 *   FLD_FACEUP_Create  0x021F5260  thumb ov082
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb ov010
 *   ov_id_52       0x00000052  data
 *   FLD_FACEUP_ResumeLipSync  0x021F558C  thumb
 *   FLD_FACEUP_Delete 0x021F5578 thumb ov082
 *   SCRIPT_WORK_ResetCheckFlag 0x02159168 thumb ov010
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FLD_FACEUP_StartClose  0x021F5550  thumb  ov082
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   FIELD_SOUND_SYSTEM_StartPushAndChangeTask  0x020297AC  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   FIELD_SOUND_SYSTEM_StartPopTask  0x02029690  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   FIELD_SUBSCREEN_ChangeModeNow  0x021A0F40  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask  0x02029CC0  thumb
 *   ov216_id       0x000000D8  data
 *   d_021BDB40     0x021BDB40  data  a1 ov216
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct GameSystem;
struct GameData;
struct PlayerWork;
struct EventWork;
struct GameEvent;
struct FieldMap;
struct FieldPlayer;
struct ArcFile;
struct ScriptVm;
struct ScriptSystem;
struct ScrCmdWork;

/* Overlay ids are linker symbols whose address is the id. */
#define OVERLAY_ID_47 ((int)ov_id_47)
#define OVERLAY_ID_52 ((int)ov_id_52)
#define OVERLAY_ID_216 ((u32)ov216_id)

#define HIDDEN_ITEM_SCRIPT_FIRST 8000
#define HIDDEN_ITEM_SCRIPT_LAST 8799
#define HIDDEN_ITEM_FLAG_BASE 900
#define HIDDEN_ITEM_COUNT 177
#define HIDDEN_ITEM_RESPAWN_PERCENT 20

#define CALENDER_ZONE_MAX 68
#define CALENDER_ARC_ID 0x61

typedef struct GameEvent *(*FieldLinkEventFn)(struct FieldMap *fieldMap, struct GameSystem *gameSystem);

/* One record of the field link event table at FieldLinkEventTable. */
typedef struct FieldLinkEventEntry {
    FieldLinkEventFn create;
    u32 id;
} FieldLinkEventEntry;

/* One record of the hidden item table at HiddenItemTable. */
typedef struct HiddenItemEntry {
    u16 flagIndex;    /* the event flag is flagIndex + HIDDEN_ITEM_FLAG_BASE */
    u8 isDowsable;
    u8 respawns;      /* takes part in the daily respawn roll */
    u16 zoneId;
    u16 gridX;
    u16 gridZ;
} HiddenItemEntry;

/* Days per month: index 0 is unused, February has 29 days. */
typedef struct DaysPerMonth {
    u8 days[13];
} DaysPerMonth;

typedef struct SubscreenToggleWork {
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
} SubscreenToggleWork;

typedef struct LinkEnterWork {
    struct GameSystem *gameSystem;
    u32 frameCount;
} LinkEnterWork;

typedef struct CalenderZoneEntry {
    u16 zoneId;
    u16 offset;       /* offset of the zone's 366 daily weather bytes in the archive */
} CalenderZoneEntry;

/* Weather calendar, 0x11C bytes. */
typedef struct CalenderWork {
    u16 heapId;
    struct GameData *gameData;
    struct ArcFile *arc;
    CalenderZoneEntry zones[CALENDER_ZONE_MAX];
} CalenderWork;

typedef struct FaceUpEndWork {
    struct GameSystem *gameSystem;
} FaceUpEndWork;

/* Argument block of the overlay 216 process. */
typedef struct BeaconSearchProcArgs {
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    u8 mode;
    u8 resultFlag;
    u8 pad[2];
} BeaconSearchProcArgs;

/* Work of the beacon search event, 0x1C bytes. */
typedef struct BeaconSearchEventWork {
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    void *saveControl;
    BeaconSearchProcArgs procArgs;
    u8 mode;
} BeaconSearchEventWork;

extern unsigned short GAME_DATA_GetPlayerZoneId(const struct PlayerWork *player);
extern u32 GAME_DATA_GetPlayerObjectCode(const struct PlayerWork *player);
extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(struct FieldMap *fieldMap);
extern void *FIELD_PLAYER_GetNowAttribute(struct FieldPlayer *fieldPlayer);
extern void *MAP_ATTR_GetTerrainId(void *encountState);
extern int MAP_ATTR_IsRoughGround(void *effect);
extern u32 ZONEDATA_IsBikeEnabled(u32 zoneId);
extern u32 ZONEDATA_IsNormalFieldZone(u32 zoneId);
extern u32 ZONEDATA_IsWeatherEnabled(u32 zoneId);
extern int FISHING_CheckFacingWater(struct GameData *gameData, struct FieldMap *fieldMap, u32 *out);
extern u32 ZONEDATA_IsZone34(u32 zoneId);
extern struct FieldMap *ICA_ANIME_GetField20(const struct GameSystem *gameSystem);
extern void *ICA_ANIME_GetField24(const struct GameSystem *gameSystem);
extern int INTRUDE_COMM_IsSessionEndPending(void *gameComm, int frames);
extern void *FIELDMAP_GetMmdlSys(struct FieldMap *fieldMap);
extern u32 FIELDMAP_CheckPlayerRequest(struct FieldMap *fieldMap);
extern int FIELD_PLAYER_StepFormChange(struct FieldPlayer *fieldPlayer);
extern int FIELD_PLAYER_WaitModelReady(struct FieldPlayer *fieldPlayer);
extern struct GameEvent *func_020122C0(void *gameSystem, void *parent, void *func, u32 size);
extern void *func_020124E8(struct GameEvent *event);
extern void EVENT_MAPCHANGE_CreateIntrudeWarpEvent(struct GameSystem *gameSystem, int id, const void *position, int flags);
extern void *FIELDMAP_GetSubscreen(struct FieldMap *fieldMap);
extern u32 FIELD_SUBSCREEN_GetMode(void *subscreen);
extern int FIELD_SUBSCREEN_RequestMode(void *subscreen, u32 mode);
extern u8 ZONEDATA_PopTimeFlagsCleared(struct EventWork *eventWork);
extern u32 func_020056EC(u32 range);
extern void ZONEDATA_ResetEventFlag(struct EventWork *eventWork, int flagId);
extern struct GameSystem *SCRCMD_WORK_GetGameSystem(struct ScrCmdWork *work);
extern int func_02034AC4(int overlayId);
extern void FIELD_GIMMICK_BRIDGE_ResetSave(struct GameSystem *gameSystem);
extern void func_02034A5C(int overlayId);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern void func_020307B0(void *ptr);
extern struct ArcFile *func_020490F4(u32 arcId, u32 heapId);
extern void ARC_TOOL_DeleteHandle(struct ArcFile *arc);
extern int FIELD_CLOCK_GetMonth(struct GameData *gameData);
extern int FIELD_CLOCK_GetDay(struct GameData *gameData);
extern u8 ZONEDATA_GetWeatherId(u32 zoneId);
extern void ARC_TOOL_ReadHandleMemberRange(struct ArcFile *arc, u32 fileId, u32 offset, u32 size, void *dst);
extern struct ScriptSystem *SCRCMD_WORK_GetScriptWork(struct ScrCmdWork *work);
extern u16 func_02011330(struct ScriptVm *vm);
extern void SCRIPT_WORK_SetCheckFlag(int waitState);
extern void *FLD_FACEUP_Create(int type, int variant, int option, struct GameSystem *gameSystem, struct ScrCmdWork *work);
extern void SCRIPT_SYS_CallEvent(struct ScriptSystem *scriptSystem, void *task);
extern int FLD_FACEUP_ResumeLipSync(struct FieldMap *fieldMap);
extern void FLD_FACEUP_Delete(struct FieldMap *fieldMap);
extern void SCRIPT_WORK_ResetCheckFlag(int waitState);
extern struct GameSystem *GAME_EVENT_GetGameSystem(struct GameEvent *event);
extern void GAME_EVENT_CallEvent(struct GameEvent *parent, struct GameEvent *child);
extern struct GameEvent *FLD_FACEUP_StartClose(struct GameSystem *gameSystem);
extern struct GameData *ICA_ANIME_GetField1C(const struct GameSystem *gameSystem);
extern struct GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeOut(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int mode, int subMode);
extern struct GameEvent *FIELD_STATUS_CreateFieldCloseEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern struct GameEvent *FIELD_SOUND_SYSTEM_StartPushAndChangeTask(struct GameSystem *gameSystem, u32 soundId, u32 mode, u32 flag);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void GAMESYSTEM_CallProc(struct GameSystem *gameSystem, u32 overlayId, void *procData, void *param);
extern u32 GAMESYSTEM_GetProcStatus(const struct GameSystem *gameSystem);
extern struct GameEvent *FIELD_SOUND_SYSTEM_StartPopTask(struct GameSystem *gameSystem, u32 mode, u32 frames);
extern struct GameEvent *FIELD_STATUS_CreateFieldOpenEvent(struct GameSystem *gameSystem);
extern void FIELD_SUBSCREEN_ChangeModeNow(void *subscreen, u32 mode);
extern struct GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeIn(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int mode, int subMode, int enable, u8 optionA, u8 optionB);
extern struct GameEvent *FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(struct GameSystem *gameSystem);

extern FieldLinkEventEntry FieldLinkEventTable[];
extern const HiddenItemEntry HiddenItemTable[];
extern u8 ov_id_47[];
extern const char CalenderFileName[];
extern const DaysPerMonth DaysPerMonthTable;
extern u8 ov_id_52[];
extern u8 ov216_id[];
extern const u8 d_021BDB40[];

struct GameEvent *EVENTDATA_SYSTEM_CreateFieldLinkEvent(int index, struct GameSystem *gameSystem, struct FieldMap *fieldMap);
int EVENTDATA_SYSTEM_CheckBicycleUsable(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player);
int EVENTDATA_SYSTEM_CheckWeatherZone(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player);
int EVENTDATA_SYSTEM_CheckNormalFieldZone(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player);
int EVENTDATA_SYSTEM_CheckFrontTileUsable(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player);
int EVENTDATA_SYSTEM_CheckNormalFieldZoneNotZone34(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player);
int EVENTDATA_SYSTEM_FieldLinkEnterEvent(struct GameEvent *event, int *seq, LinkEnterWork *work);
struct GameEvent *EVENTDATA_SYSTEM_CreateFieldLinkEnterEvent(struct FieldMap *fieldMap, struct GameSystem *gameSystem);
void EVENTDATA_SYSTEM_AddFieldLinkObject(struct FieldMap *fieldMap, struct GameSystem *gameSystem);
int EVENTDATA_SYSTEM_ToggleSubscreenEvent(struct GameEvent *event, u32 *seq, SubscreenToggleWork *work);
struct GameEvent *EVENTDATA_SYSTEM_CreateToggleSubscreenEvent(struct FieldMap *fieldMap, struct GameSystem *gameSystem);
u16 EVENTDATA_SYSTEM_GetHiddenItemIndex(u32 scriptId);
u16 EVENTDATA_SYSTEM_GetHiddenItemFlag(u16 scriptId);
void EVENTDATA_SYSTEM_RespawnHiddenItems(struct EventWork *eventWork);
const HiddenItemEntry *EVENTDATA_SYSTEM_GetHiddenItemTable(unsigned short *count);
int EVENTDATA_SYSTEM_ScrCmdRunOverlay47(struct ScriptVm *vm, struct ScrCmdWork *work);
CalenderWork *CALENDER_Create(struct GameData *gameData, u32 heapId);
void CALENDER_Delete(CalenderWork *calender);
u32 CALENDER_GetWeatherThunk(CalenderWork *calender, unsigned int zoneId);
void CALENDER_ClearResources(CalenderWork *calender);
struct ArcFile *CALENDER_OpenArchive(CalenderWork *calender);
void CALENDER_CloseArchive(CalenderWork *calender);
u8 CALENDER_GetWeather(CalenderWork *calender, u32 zoneId);
u8 CALENDER_GetWeatherOnDate(CalenderWork *calender, u32 zoneId, u8 month, u8 day);
void CALENDER_LoadZoneTable(CalenderWork *calender);
u32 CALENDER_FindZoneOffset(CalenderWork *calender, u32 zoneId);
u16 CALENDER_GetDayOfYear(int month, int day);
int FLD_FACEUP_ScrCmdStart(struct ScriptVm *vm, struct ScrCmdWork *work);
int FLD_FACEUP_ScrCmdPrepareField(struct ScriptVm *vm, struct ScrCmdWork *work);
int FLD_FACEUP_ScrCmdWaitEnd(struct ScriptVm *vm, struct ScrCmdWork *work);
int FLD_FACEUP_Finish(FaceUpEndWork *work);
int FLD_FACEUP_EndEvent(struct GameEvent *event, int *seq);
int CALENDER_OverlaySequenceEvent(struct GameEvent *event, u32 *seq, BeaconSearchEventWork *work);

/*
 * Creates the event of entry index in the field link event table and
 * returns it.
 */
struct GameEvent *EVENTDATA_SYSTEM_CreateFieldLinkEvent(int index, struct GameSystem *gameSystem, struct FieldMap *fieldMap)
{
    return FieldLinkEventTable[index].create(fieldMap, gameSystem);
}

/*
 * Field skill check, slot 0: whether the bicycle can be used here. Only
 * allowed while no encounter effect is active; getting on also needs a
 * bicycle zone and the walking body.
 */
int EVENTDATA_SYSTEM_CheckBicycleUsable(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player)
{
    u16 zoneId;
    u8 objectCode;
    int encountEffect;

    zoneId = GAME_DATA_GetPlayerZoneId(player);
    objectCode = GAME_DATA_GetPlayerObjectCode(player);
    encountEffect = MAP_ATTR_IsRoughGround(MAP_ATTR_GetTerrainId(FIELD_PLAYER_GetNowAttribute(FIELDMAP_GetFieldPlayer(fieldMap))));
    if (objectCode == 1) {
        if (encountEffect == 0) {
            return 1;
        }
        return 0;
    }
    if (ZONEDATA_IsBikeEnabled(zoneId) == 0) {
        return 0;
    }
    if (objectCode != 0) {
        return 0;
    }
    if (encountEffect == 0) {
        return 1;
    }
    return 0;
}

/* Field skill check: normal field zone that has weather. */
int EVENTDATA_SYSTEM_CheckWeatherZone(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player)
{
    u16 zoneId = GAME_DATA_GetPlayerZoneId(player);

    if (!ZONEDATA_IsNormalFieldZone(zoneId)) {
        return 0;
    }
    if (ZONEDATA_IsWeatherEnabled(zoneId)) {
        return 1;
    }
    return 0;
}

/* Field skill check: normal field zone (2-byte zero padding follows at 0x0216459A). */
int EVENTDATA_SYSTEM_CheckNormalFieldZone(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player)
{
    return ZONEDATA_IsNormalFieldZone(GAME_DATA_GetPlayerZoneId(player));
}

/*
 * Field skill check: normal field zone and the tile in front passes the
 * check of FISHING_CheckFacingWater (overlay 21, defined in the co-resident ov021).
 */
int EVENTDATA_SYSTEM_CheckFrontTileUsable(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player)
{
    if (ZONEDATA_IsNormalFieldZone(GAME_DATA_GetPlayerZoneId(player)) == 0) {
        return 0;
    }
    return FISHING_CheckFacingWater(gameData, fieldMap, 0);
}

/* Field skill check: normal field zone, except the zone of ZONEDATA_IsZone34. */
int EVENTDATA_SYSTEM_CheckNormalFieldZoneNotZone34(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player)
{
    int zoneId = GAME_DATA_GetPlayerZoneId(player);

    if (ZONEDATA_IsZone34(zoneId) != 0) {
        return 0;
    }
    return ZONEDATA_IsNormalFieldZone(zoneId);
}

/*
 * Event: waits up to 30 frames for the comm check, then runs two field
 * player steps in turn.
 */
int EVENTDATA_SYSTEM_FieldLinkEnterEvent(struct GameEvent *event, int *seq, LinkEnterWork *work)
{
    void *gameComm;
    struct FieldMap *fieldMap;

    fieldMap = ICA_ANIME_GetField20(work->gameSystem);
    FIELDMAP_GetMmdlSys(fieldMap);
    switch (*seq) {
    case 0:
        gameComm = ICA_ANIME_GetField24(work->gameSystem);
        work->frameCount++;
        if (INTRUDE_COMM_IsSessionEndPending(gameComm, work->frameCount) == 1 && work->frameCount < 30) {
            break;
        }
        FIELDMAP_CheckPlayerRequest(fieldMap);
        (*seq)++;
        /* fall through */
    case 1:
        if (FIELD_PLAYER_StepFormChange(FIELDMAP_GetFieldPlayer(fieldMap)) == 1) {
            (*seq)++;
        }
        break;
    case 2:
        if (FIELD_PLAYER_WaitModelReady(FIELDMAP_GetFieldPlayer(fieldMap)) == 1) {
            return 1;
        }
        break;
    }
    return 0;
}

/* Creates the event of EVENTDATA_SYSTEM_FieldLinkEnterEvent (field link entry 0). */
struct GameEvent *EVENTDATA_SYSTEM_CreateFieldLinkEnterEvent(struct FieldMap *fieldMap, struct GameSystem *gameSystem)
{
    struct GameEvent *event;
    LinkEnterWork *work;

    event = func_020122C0(gameSystem, 0, (void *)EVENTDATA_SYSTEM_FieldLinkEnterEvent, sizeof(LinkEnterWork));
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->frameCount = 0;
    return event;
}

/*
 * Field link entry 1: adds the object 279 of overlay 20 at a fixed
 * position (2-byte zero padding follows at 0x0216469E).
 */
void EVENTDATA_SYSTEM_AddFieldLinkObject(struct FieldMap *fieldMap, struct GameSystem *gameSystem)
{
    struct {
        int x;
        int y;
        int z;
    } position;

    position.x = 0x200000;
    position.y = 32;
    position.z = 0x1E8000;
    EVENT_MAPCHANGE_CreateIntrudeWarpEvent(gameSystem, 279, &position, 0);
}

/* Event: switches the subscreen between mode 6 and mode 0. */
int EVENTDATA_SYSTEM_ToggleSubscreenEvent(struct GameEvent *event, u32 *seq, SubscreenToggleWork *work)
{
    void *subscreen = FIELDMAP_GetSubscreen(work->fieldMap);

    if (FIELD_SUBSCREEN_GetMode(subscreen) == 6) {
        FIELD_SUBSCREEN_RequestMode(subscreen, 0);
    } else {
        FIELD_SUBSCREEN_RequestMode(subscreen, 6);
    }
    return 1;
}

/* Creates the event of EVENTDATA_SYSTEM_ToggleSubscreenEvent (field link entry 5). */
struct GameEvent *EVENTDATA_SYSTEM_CreateToggleSubscreenEvent(struct FieldMap *fieldMap, struct GameSystem *gameSystem)
{
    struct GameEvent *event = func_020122C0(gameSystem, 0, (void *)EVENTDATA_SYSTEM_ToggleSubscreenEvent, sizeof(SubscreenToggleWork));
    SubscreenToggleWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    return event;
}

/*
 * Hidden item index of a script id, or 0 when the id is outside the
 * hidden item script range.
 */
u16 EVENTDATA_SYSTEM_GetHiddenItemIndex(u32 scriptId)
{
    if (scriptId < HIDDEN_ITEM_SCRIPT_FIRST || scriptId > HIDDEN_ITEM_SCRIPT_LAST) {
        return 0;
    }
    return scriptId - HIDDEN_ITEM_SCRIPT_FIRST;
}

/* Event flag of the hidden item that a script id stands for. */
u16 EVENTDATA_SYSTEM_GetHiddenItemFlag(u16 scriptId)
{
    return HiddenItemTable[EVENTDATA_SYSTEM_GetHiddenItemIndex(scriptId)].flagIndex + HIDDEN_ITEM_FLAG_BASE;
}

/*
 * Daily hidden item respawn: when the time flags were cleared, every
 * respawning entry has a 20% chance to reset its event flag.
 */
void EVENTDATA_SYSTEM_RespawnHiddenItems(struct EventWork *eventWork)
{
    u32 i;

    if (ZONEDATA_PopTimeFlagsCleared(eventWork) != 0) {
        for (i = 0; i < HIDDEN_ITEM_COUNT; i++) {
            const HiddenItemEntry *entry = HiddenItemTable + i;

            if (entry->respawns != 0) {
                if (func_020056EC(100) < HIDDEN_ITEM_RESPAWN_PERCENT) {
                    ZONEDATA_ResetEventFlag(eventWork, (u16)(entry->flagIndex + HIDDEN_ITEM_FLAG_BASE));
                }
            }
        }
    }
}

/* Returns the hidden item table and stores its entry count. */
const HiddenItemEntry *EVENTDATA_SYSTEM_GetHiddenItemTable(unsigned short *count)
{
    *count = HIDDEN_ITEM_COUNT;
    return HiddenItemTable;
}

/* Script command: loads overlay 47 and runs its entry on the game system. */
int EVENTDATA_SYSTEM_ScrCmdRunOverlay47(struct ScriptVm *vm, struct ScrCmdWork *work)
{
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(work);

    func_02034AC4(OVERLAY_ID_47);
    FIELD_GIMMICK_BRIDGE_ResetSave(gameSystem);
    func_02034A5C(OVERLAY_ID_47);
    return 0;
}

/*
 * Allocates the weather calendar and loads its archive and zone table.
 * The file name and line (0x53) given to the allocator are those of the
 * original call site.
 */
CalenderWork *CALENDER_Create(struct GameData *gameData, u32 heapId)
{
    CalenderWork *calender;

    calender = func_02030734(heapId, sizeof(CalenderWork), 0, CalenderFileName, 0x53);
    CALENDER_ClearResources(calender);
    calender->heapId = heapId;
    calender->gameData = gameData;
    CALENDER_OpenArchive(calender);
    CALENDER_LoadZoneTable(calender);
    return calender;
}

/* Closes the archive and frees the weather calendar. */
void CALENDER_Delete(CalenderWork *calender)
{
    CALENDER_CloseArchive(calender);
    func_020307B0(calender);
}

/*
 * Tail call to CALENDER_GetWeather through a pool word and `bx r3`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Unlabelled in the
 * listing: no prologue, and its only caller is func_0202C794 in arm9.
 */
u32 CALENDER_GetWeatherThunk(CalenderWork *calender, unsigned int zoneId)
{
    return CALENDER_GetWeather(calender, zoneId);
}

/* Clears the calendar fields that hold resources. */
void CALENDER_ClearResources(CalenderWork *calender)
{

    calender->heapId = 0;
    calender->gameData = 0;
    calender->arc = 0;
}

/* Opens the calendar archive. */
struct ArcFile *CALENDER_OpenArchive(CalenderWork *calender)
{
    struct ArcFile *arc;

    arc = func_020490F4(CALENDER_ARC_ID, calender->heapId);
    calender->arc = arc;
    return arc;
}

/* Closes the calendar archive. */
void CALENDER_CloseArchive(CalenderWork *calender)
{
    ARC_TOOL_DeleteHandle(calender->arc);
    calender->arc = 0;
}

/* Weather of a zone on the current date. */
u8 CALENDER_GetWeather(CalenderWork *calender, u32 zoneId)
{
    int month = FIELD_CLOCK_GetMonth(calender->gameData);
    int day = FIELD_CLOCK_GetDay(calender->gameData);

    return CALENDER_GetWeatherOnDate(calender, zoneId, month, day);
}

/*
 * Weather of a zone on a date: reads the byte at the zone's offset plus
 * the day of the year. A zone without a calendar entry takes its default
 * weather.
 */
u8 CALENDER_GetWeatherOnDate(CalenderWork *calender, u32 zoneId, u8 month, u8 day)
{
    u32 zoneOffset = CALENDER_FindZoneOffset(calender, zoneId);
    u8 weather;
    u16 position;

    if (zoneOffset == 0xffff) {
        return ZONEDATA_GetWeatherId(zoneId);
    }
    position = zoneOffset + CALENDER_GetDayOfYear(month, day);
    ARC_TOOL_ReadHandleMemberRange(calender->arc, 0, position, 1, &weather);
    return weather;
}

/* Loads the zone offset table (archive file 1, from byte 2). */
void CALENDER_LoadZoneTable(CalenderWork *calender)
{
    ARC_TOOL_ReadHandleMemberRange(calender->arc, 1, 2, sizeof(calender->zones), calender->zones);
}

/* Archive offset of a zone's calendar, or 0xFFFF when the zone has none. */
u32 CALENDER_FindZoneOffset(CalenderWork *calender, u32 zoneId)
{
    int i;
    u32 zoneOffset = 0xffff;

    for (i = 0; i < CALENDER_ZONE_MAX; i++) {
        if (zoneId == calender->zones[i].zoneId) {
            zoneOffset = calender->zones[i].offset;
            break;
        }
    }
    return zoneOffset;
}

/*
 * Zero-based day of the year (leap year layout): the days of the months
 * before `month`, plus day - 1. The month table is copied to the stack
 * from the pool copy at DaysPerMonthTable.
 */
u16 CALENDER_GetDayOfYear(int month, int day)
{
    DaysPerMonth daysPerMonth = DaysPerMonthTable;
    int i;
    u16 sum = 0;

    for (i = 0; i < month; i++) {
        sum = sum + daysPerMonth.days[i];
    }
    return sum + (u16)(day - 1);
}

/*
 * Script command: reads three values off the script, loads overlay 82 and
 * starts the face-up scene; waits for it when a task was created.
 */
int FLD_FACEUP_ScrCmdStart(struct ScriptVm *vm, struct ScrCmdWork *work)
{
    struct ScriptSystem *scriptSystem = SCRCMD_WORK_GetScriptWork(work);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(work);
    u8 type = func_02011330(vm);
    u8 variant = func_02011330(vm);
    u32 option = func_02011330(vm);
    void *task;

    SCRIPT_WORK_SetCheckFlag(7);
    func_02034AC4(OVERLAY_ID_52);
    task = FLD_FACEUP_Create(type, variant, option, gameSystem, work);
    if (task == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptSystem, task);
    return 1;
}

/* Script command: finishes the face-up scene on the field map. */
int FLD_FACEUP_ScrCmdPrepareField(struct ScriptVm *vm, struct ScrCmdWork *work)
{
    struct GameSystem *gameSystem;

    SCRCMD_WORK_GetScriptWork(work);
    gameSystem = SCRCMD_WORK_GetGameSystem(work);
    FLD_FACEUP_ResumeLipSync(ICA_ANIME_GetField20(gameSystem));
    return 0;
}

/* Script command: creates the face-up wait event and waits for it. */
int FLD_FACEUP_ScrCmdWaitEnd(struct ScriptVm *vm, struct ScrCmdWork *work)
{
    struct ScriptSystem *scriptSystem = SCRCMD_WORK_GetScriptWork(work);
    struct GameEvent *event = func_020122C0(SCRCMD_WORK_GetGameSystem(work), 0, (void *)FLD_FACEUP_EndEvent, 0);

    if (event == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptSystem, event);
    return 1;
}

/* Ends the face-up scene: releases the field map part, the script state and overlay 82. */
int FLD_FACEUP_Finish(FaceUpEndWork *work)
{
    FLD_FACEUP_Delete(ICA_ANIME_GetField20(work->gameSystem));
    SCRIPT_WORK_ResetCheckFlag(7);
    func_02034A5C(OVERLAY_ID_52);
    return 1;
}

/* Event: step 0 starts the face-up end request, step 1 releases it and the overlay. */
int FLD_FACEUP_EndEvent(struct GameEvent *event, int *seq)
{
    struct GameSystem *gameSystem = GAME_EVENT_GetGameSystem(event);

    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(event, FLD_FACEUP_StartClose(gameSystem));
        (*seq)++;
        break;
    case 1:
        SCRIPT_WORK_ResetCheckFlag(7);
        func_02034A5C(OVERLAY_ID_52);
        return 1;
    }
    return 0;
}

/*
 * Beacon search event: eight steps, each starting one child event or
 * process (the overlay 216 one through GAMESYSTEM_CallProc with a 12-byte
 * argument block), then done. Step 2 falls through into step 3.
 * d_021BDB40 is the process template and lives in overlay 216.
 */
int CALENDER_OverlaySequenceEvent(struct GameEvent *event, u32 *seq, BeaconSearchEventWork *work)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;

    gameSystem = work->gameSystem;
    ICA_ANIME_GetField1C(gameSystem);
    fieldMap = ICA_ANIME_GetField20(gameSystem);
    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, 0, 0));
        (*seq)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldCloseEvent(gameSystem, fieldMap));
        (*seq)++;
        break;
    case 2:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPushAndChangeTask(gameSystem, 0x483, 6, 0));
        (*seq)++;
        /* fall through */
    case 3:
        MI_CpuFill8(&work->procArgs, 0, sizeof(BeaconSearchProcArgs));
        work->procArgs.gameSystem = work->gameSystem;
        work->procArgs.gameData = work->gameData;
        work->procArgs.mode = work->mode;
        GAMESYSTEM_CallProc(gameSystem, OVERLAY_ID_216, (void *)d_021BDB40, &work->procArgs);
        (*seq)++;
        break;
    case 4:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0) {
            GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPopTask(gameSystem, 6, 0x3C));
            (*seq)++;
        }
        break;
    case 5:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        (*seq)++;
        break;
    case 6:
        if (work->procArgs.resultFlag != 0) {
            FIELD_SUBSCREEN_ChangeModeNow(FIELDMAP_GetSubscreen(fieldMap), 0);
        }
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, fieldMap, 0, 0, 1, 0, 0));
        (*seq)++;
        break;
    case 7:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(gameSystem));
        (*seq)++;
        break;
    case 8:
        return 1;
    }
    return 0;
}
