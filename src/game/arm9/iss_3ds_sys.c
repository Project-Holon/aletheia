/*
 * file:     iss_3ds_sys.c
 * unit:     yes
 * function: ISS_3DS_SYS_UpdateImpl, ISS_3DS_SYS_OnZoneChangeImpl, ISS_3DS_SYS_SilenceActiveTracks, ISS_3DS_SYS_StepSourceVolume, ISS_3DS_SYS_StepSourcePan, ISS_3DS_SYS_CalcSourceVolume, ISS_3DS_SYS_RampVolumeUp, ISS_3DS_SYS_RampVolumeDown, ISS_3DS_SYS_ApplySourceVolume, ISS_3DS_SYS_CalcSourcePan, ISS_3DS_SYS_RampPanDown, ISS_3DS_SYS_RampPanUp, ISS_3DS_SYS_ApplySourcePan, ISS_3DS_SYS_StepMasterVolume, ISS_3DS_SYS_ScaleVolume, ISS_SYS_Create, ISS_SYS_Delete, ISS_SYS_Update, ISS_SYS_ChangeZone, ISS_SYS_GetSwitchSys, func_0202B57C, func_0202B584, ISS_SYS_Setup, ISS_SYS_DeleteSubsystems, ISS_SYS_CreateRoad, ISS_SYS_CreateCity, ISS_SYS_CreateDungeon, ISS_SYS_CreateZone, ISS_SYS_CreateSwitch, ISS_SYS_Create3ds, ISS_SYS_DeleteRoad, ISS_SYS_DeleteCity, ISS_SYS_DeleteDungeon, ISS_SYS_DeleteZone, ISS_SYS_DeleteSwitch, ISS_SYS_Delete3ds, ISS_SYS_UpdateRoad, ISS_SYS_UpdateCity, ISS_SYS_UpdateDungeon, ISS_SYS_UpdateZone, ISS_SYS_UpdateSwitch, ISS_SYS_Update3ds, ISS_SYS_EnterRoad, ISS_SYS_EnterCity, ISS_SYS_EnterDungeon, ISS_SYS_EnterZone, ISS_SYS_EnterSwitch, ISS_SYS_Enter3ds, ISS_SYS_LeaveRoad, ISS_SYS_LeaveCity, ISS_SYS_LeaveDungeon, ISS_SYS_LeaveZone, ISS_SYS_LeaveSwitch, ISS_SYS_Leave3ds, func_0202B7B8, ISS_SYS_OnZoneChangeCity, ISS_SYS_OnZoneChangeDungeon, ISS_SYS_OnZoneChangeZone, ISS_SYS_OnZoneChangeSwitch, ISS_SYS_OnZoneChange3ds, ISS_SYS_GetLocation, ISS_SYS_GetZoneId, ISS_SYS_GetCurrentBgmId, ISS_SYS_GetBgmMode, ISS_SYS_HasBgmChanged, ISS_SYS_SwitchMode, ISS_3DS_SYS_Create, ISS_3DS_SYS_Delete, ISS_3DS_SYS_Update, ISS_3DS_SYS_Enter, ISS_3DS_SYS_Leave, ISS_3DS_SYS_OnZoneChange, ISS_3DS_SYS_SetVolume, ISS_3DS_SYS_StartSource, ISS_3DS_SYS_IsSourceActive, ISS_3DS_SYS_SetSourcePos, ISS_3DS_SYS_SetCamera, func_0202B944, ISS_3DS_SYS_LoadTable, ISS_3DS_SYS_FreeTable, ISS_3DS_SYS_SetTableIndex, ISS_3DS_SYS_FindTableIndex, ISS_3DS_SYS_ResetSources, ISS_3DS_SYS_StartSourceImpl, ISS_3DS_SYS_SetSourcePosImpl, ISS_3DS_SYS_SetCameraImpl, ISS_3DS_SYS_EnterImpl, ISS_3DS_SYS_LeaveImpl
 * address:  0x0202B4BC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   ISS_SYS_FileName  0x020A772C  data
 *   ISS_3DS_SYS_FileName  0x020A7738  data
 *   ISS_SWITCH_SYS_Create  0x0202C070  thumb
 *   ISS_ROAD_SYS_Update  0x0202B1F4  thumb
 *   ISS_CITY_SYS_Update  0x0202AB38  thumb
 *   ISS_SWITCH_SYS_Main  0x0202C09C  thumb
 *   ISS_CITY_SYS_NotifyZoneChange  0x0202AB5C  thumb
 *   ISS_CITY_SYS_Start  0x0202AB4C  thumb
 *   ISS_CITY_SYS_Stop  0x0202AB54  thumb
 *   ISS_ROAD_SYS_Start  0x0202B1FC  thumb
 *   ISS_ROAD_SYS_Stop  0x0202B204  thumb
 *   sub_0202B420  0x0202B420  thumb
 *   ISS_ZONE_SYS_SwitchZone  0x0202BECC  thumb
 *   sub_0202C0C8  0x0202C0C8  thumb
 *   ISS_SYS_ModeTable  0x0209FF88  data
 *   ISS_3DS_SYS_OnZoneChangeImpl  0x0202BB40  thumb
 *   ISS_3DS_SYS_SilenceActiveTracks  0x0202BB48  thumb
 *   ISS_DUNGEON_SYS_Start  0x0202B424  thumb
 *   ISS_SWITCH_SYS_On  0x0202C0B8  thumb
 *   ISS_ZONE_SYS_Stop  0x0202BEE4  thumb
 *   ISS_SWITCH_SYS_Off  0x0202C0C0  thumb
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *   GAME_DATA_GetBagCursor  0x0201295C  thumb
 *   ISS_CITY_SYS_Create  0x0202AAF4  thumb
 *   ISS_CITY_SYS_Delete  0x0202AB28  thumb
 *   ISS_ROAD_SYS_Create  0x0202B1AC  thumb
 *   ISS_ROAD_SYS_Delete  0x0202B1EC  thumb
 *   ISS_DUNGEON_SYS_Create  0x0202B3A0  thumb
 *   ISS_DUNGEON_SYS_Delete  0x0202B3EC  thumb
 *   ISS_DUNGEON_SYS_Update  0x0202B404  thumb
 *   ISS_DUNGEON_SYS_Stop  0x0202B42C  thumb
 *   ISS_ZONE_SYS_Create  0x0202BE68  thumb
 *   ISS_ZONE_SYS_Delete  0x0202BEA4  thumb
 *   ISS_ZONE_SYS_Update  0x0202BEBC  thumb
 *   ISS_ZONE_SYS_Start  0x0202BEDC  thumb
 *   ISS_SWITCH_SYS_Delete  0x0202C08C  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   ARC_TOOL_ReadHandleMember  0x0204932C  arm
 *   ARC_TOOL_GetHandleFileCount  0x0204961C  arm
 *   ISS_3DS_SYS_UpdateImpl  0x0202BAF4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* Opaque types owned by other files. */
struct GameData;
struct Location;
struct BgmInfoTable;
struct IssCitySys;
struct IssRoadSys;
struct IssDungeonSys;
struct IssZoneSys;
struct IssSwitchSys;

typedef struct GameData GameData;
typedef struct Location Location;
typedef struct BgmInfoTable BgmInfoTable;
typedef struct IssCitySys IssCitySys;
typedef struct IssRoadSys IssRoadSys;
typedef struct IssDungeonSys IssDungeonSys;
typedef struct IssZoneSys IssZoneSys;
typedef struct IssSwitchSys IssSwitchSys;

typedef struct {
    int x, y, z;
} IssVec3;

/* One entry of the 3D sound table: the BGM that uses it and the sound it plays. */
typedef struct {
    u32 bgmId;
    u32 soundId;
} Iss3dsTableEntry;

enum {
    ISS_3DS_SLOT_COUNT = 16
};

/* The enum type keeps the slot counter out of constant folding (see
 * docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md). */
typedef enum {
    ISS_3DS_SLOT_FIRST,
    ISS_3DS_SLOT_LIMIT = ISS_3DS_SLOT_COUNT
} Iss3dsSlotIndex;

/* One positional sound source. */
typedef struct {
    u32 active;
    IssVec3 pos;
    int radius;
    int amp;
    u16 trackMask;
    u16 reserved;
} Iss3dsSlot;

/* 3D sound subsystem, 0x26c bytes. */
typedef struct {
    u16 heapId;
    u16 reserved02;
    u32 entered;
    u8 volume;
    u8 maxVolume;
    u8 fadeSpeed;
    u8 reserved0B;
    IssVec3 cameraPos;
    IssVec3 cameraTarget;
    Iss3dsSlot slots[ISS_3DS_SLOT_COUNT];
    u32 slotLevelA[ISS_3DS_SLOT_COUNT];
    u32 slotLevelB[ISS_3DS_SLOT_COUNT];
    Iss3dsTableEntry *table;
    u8 tableCount;
    u8 tableIndex;
} Iss3dsSys;

/* Interactive sound system, 0x28 bytes: one object per subsystem. */
typedef struct {
    u16 heapId;
    u16 reserved02;
    GameData *gameData;
    u32 lastBgmId;
    u32 frameCount;
    IssCitySys *city;
    IssRoadSys *road;
    IssDungeonSys *dungeon;
    IssZoneSys *zone;
    IssSwitchSys *sw;
    Iss3dsSys *sound3d;
} IssSys;

/* Per-mode callbacks, selected by the mode the current BGM maps to. */
typedef struct {
    u8 mode;
    u8 reserved[3];
    void (*onEnter)(IssSys *);
    void (*onLeave)(IssSys *);
} IssModeHandler;

enum {
    ISS_MODE_COUNT = 9
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern IssRoadSys *ISS_ROAD_SYS_Create(const Location *loc, u32 heapId);
extern IssCitySys *ISS_CITY_SYS_Create(const Location *loc, u32 heapId);
extern IssDungeonSys *ISS_DUNGEON_SYS_Create(const GameData *gameData, const Location *loc, u32 heapId);
extern IssZoneSys *ISS_ZONE_SYS_Create(u32 heapId);
extern IssSwitchSys *ISS_SWITCH_SYS_Create(u32 heapId);
extern void ISS_ROAD_SYS_Delete(IssRoadSys *road);
extern void ISS_CITY_SYS_Delete(IssCitySys *city);
extern void ISS_DUNGEON_SYS_Delete(IssDungeonSys *dungeon);
extern void ISS_ZONE_SYS_Delete(IssZoneSys *zone);
extern void ISS_SWITCH_SYS_Delete(IssSwitchSys *sw);
extern void ISS_ROAD_SYS_Update(IssRoadSys *road);
extern void ISS_CITY_SYS_Update(IssCitySys *city);
extern void ISS_DUNGEON_SYS_Update(IssDungeonSys *dungeon);
extern void ISS_ZONE_SYS_Update(IssZoneSys *zone);
extern void ISS_SWITCH_SYS_Main(IssSwitchSys *sw);
extern void ISS_ROAD_SYS_Start(IssRoadSys *road);
extern void ISS_CITY_SYS_Start(IssCitySys *city);
extern void ISS_DUNGEON_SYS_Start(IssDungeonSys *dungeon);
extern void ISS_SWITCH_SYS_On(IssSwitchSys *sw);
extern void ISS_ROAD_SYS_Stop(IssRoadSys *road);
extern void ISS_CITY_SYS_Stop(IssCitySys *city);
extern void ISS_DUNGEON_SYS_Stop(IssDungeonSys *dungeon);
extern void ISS_ZONE_SYS_Stop(IssZoneSys *zone);
extern void ISS_SWITCH_SYS_Off(IssSwitchSys *sw);
extern void ISS_ZONE_SYS_Start(IssZoneSys *zone, int zoneId);
extern void ISS_CITY_SYS_NotifyZoneChange(IssCitySys *city, u32 zoneId);
extern void sub_0202B420(IssDungeonSys *dungeon, u16 zoneId);
extern void ISS_ZONE_SYS_SwitchZone(IssZoneSys *zone, u32 zoneId);
extern void sub_0202C0C8(IssSwitchSys *sw);
extern const Location *GAME_DATA_GetMyPlayerWork(const GameData *gameData);
extern u16 GAME_DATA_GetPlayerZoneId(const Location *loc);
extern u16 GFL_USE_GetBgmNo(void);
extern const BgmInfoTable *GAME_DATA_GetBagCursor(const GameData *gameData);
extern u8 func_02006E7C(const BgmInfoTable *table, u16 bgmId);
struct Iss3dsSound;
extern void ISS_3DS_SYS_UpdateImpl(struct Iss3dsSound *sys);
extern void ISS_3DS_SYS_OnZoneChangeImpl(struct Iss3dsSound *sys);
extern void *func_020490F4(u32 archiveId, u32 heapId);
extern u16 ARC_TOOL_GetHandleFileCount(void *arc);
extern void ARC_TOOL_ReadHandleMember(void *arc, u32 member, void *dst);
extern void ARC_TOOL_DeleteHandle(void *arc);
extern void ISS_3DS_SYS_SilenceActiveTracks(struct Iss3dsSound *sys);

IssSys *ISS_SYS_Create(GameData *gameData, u32 heapId);
void ISS_SYS_Delete(IssSys *iss);
void ISS_SYS_Update(IssSys *iss);
void ISS_SYS_ChangeZone(IssSys *iss, u16 zoneId);
IssSwitchSys *ISS_SYS_GetSwitchSys(IssSys *iss);
Iss3dsSys *ISS_SYS_Get3dsSys(IssSys *iss);
IssDungeonSys *ISS_SYS_GetDungeonSys(IssSys *iss);
void ISS_SYS_ClearFields(IssSys *iss);
void ISS_SYS_Setup(IssSys *iss, GameData *gameData, u32 heapId);
void ISS_SYS_DeleteSubsystems(IssSys *iss);
void ISS_SYS_CreateRoad(IssSys *iss);
void ISS_SYS_CreateCity(IssSys *iss);
void ISS_SYS_CreateDungeon(IssSys *iss);
void ISS_SYS_CreateZone(IssSys *iss);
void ISS_SYS_CreateSwitch(IssSys *iss);
void ISS_SYS_Create3ds(IssSys *iss);
void ISS_SYS_DeleteRoad(IssSys *iss);
void ISS_SYS_DeleteCity(IssSys *iss);
void ISS_SYS_DeleteDungeon(IssSys *iss);
void ISS_SYS_DeleteZone(IssSys *iss);
void ISS_SYS_DeleteSwitch(IssSys *iss);
void ISS_SYS_Delete3ds(IssSys *iss);
void ISS_SYS_UpdateRoad(IssSys *iss);
void ISS_SYS_UpdateCity(IssSys *iss);
void ISS_SYS_UpdateDungeon(IssSys *iss);
void ISS_SYS_UpdateZone(IssSys *iss);
void ISS_SYS_UpdateSwitch(IssSys *iss);
void ISS_SYS_Update3ds(IssSys *iss);
void ISS_SYS_EnterRoad(IssSys *iss);
void ISS_SYS_EnterCity(IssSys *iss);
void ISS_SYS_EnterDungeon(IssSys *iss);
void ISS_SYS_EnterZone(IssSys *iss);
void ISS_SYS_EnterSwitch(IssSys *iss);
void ISS_SYS_Enter3ds(IssSys *iss);
void ISS_SYS_LeaveRoad(IssSys *iss);
void ISS_SYS_LeaveCity(IssSys *iss);
void ISS_SYS_LeaveDungeon(IssSys *iss);
void ISS_SYS_LeaveZone(IssSys *iss);
void ISS_SYS_LeaveSwitch(IssSys *iss);
void ISS_SYS_Leave3ds(IssSys *iss);
void ISS_SYS_OnZoneChangeRoad(void);
void ISS_SYS_OnZoneChangeCity(IssSys *iss, u32 zoneId);
void ISS_SYS_OnZoneChangeDungeon(IssSys *iss, u16 zoneId);
void ISS_SYS_OnZoneChangeZone(IssSys *iss, u32 zoneId);
void ISS_SYS_OnZoneChangeSwitch(IssSys *iss, u32 zoneId);
void ISS_SYS_OnZoneChange3ds(IssSys *iss, u32 zoneId);
const Location *ISS_SYS_GetLocation(IssSys *iss);
u16 ISS_SYS_GetZoneId(IssSys *iss);
u32 ISS_SYS_GetCurrentBgmId(void);
u8 ISS_SYS_GetBgmMode(IssSys *iss);
u32 ISS_SYS_HasBgmChanged(IssSys *iss);
void ISS_SYS_SwitchMode(IssSys *iss);
Iss3dsSys *ISS_3DS_SYS_Create(u32 heapId);
void ISS_3DS_SYS_Delete(Iss3dsSys *sys);
void ISS_3DS_SYS_Update(Iss3dsSys *sys);
void ISS_3DS_SYS_Enter(Iss3dsSys *sys);
void ISS_3DS_SYS_Leave(Iss3dsSys *sys);
void ISS_3DS_SYS_OnZoneChange(Iss3dsSys *sys);
void ISS_3DS_SYS_SetVolume(Iss3dsSys *sys, u32 volume);
void ISS_3DS_SYS_StartSource(Iss3dsSys *sys, int slot, int radius, int amp);
int ISS_3DS_SYS_IsSourceActive(Iss3dsSys *sys, int slot);
void ISS_3DS_SYS_SetSourcePos(Iss3dsSys *sys, int slot, const IssVec3 *pos);
void ISS_3DS_SYS_SetCamera(Iss3dsSys *sys, const int *cameraPos, const int *cameraTarget);
void ISS_3DS_SYS_ClearTable(Iss3dsSys *sys);
void ISS_3DS_SYS_LoadTable(Iss3dsSys *sys);
void ISS_3DS_SYS_FreeTable(Iss3dsSys *sys);
Iss3dsSys *ISS_3DS_SYS_SetTableIndex(Iss3dsSys *sys, u32 index);
u8 ISS_3DS_SYS_FindTableIndex(const Iss3dsSys *sys, u32 bgmId);
void ISS_3DS_SYS_ResetSources(Iss3dsSys *sys);
void ISS_3DS_SYS_StartSourceImpl(Iss3dsSys *sys, int slot, int radius, int amp);
void ISS_3DS_SYS_SetSourcePosImpl(Iss3dsSys *sys, int slot, const IssVec3 *pos);
void ISS_3DS_SYS_SetCameraImpl(Iss3dsSys *sys, const int *cameraPos, const int *cameraTarget);
void ISS_3DS_SYS_EnterImpl(Iss3dsSys *sys);
void ISS_3DS_SYS_LeaveImpl(Iss3dsSys *sys);
extern const char ISS_SYS_FileName[];
extern const char ISS_3DS_SYS_FileName[];
extern const IssModeHandler ISS_SYS_ModeTable[];

static inline void ISS_3DS_SYS_SetVec3(IssVec3 *dst, int x, int y, int z)
{
    dst->x = x;
    dst->y = y;
    dst->z = z;
}

/* Allocates the ISS object, clears it and creates the six subsystems. */
IssSys *ISS_SYS_Create(GameData *gameData, u32 heapId)
{
    IssSys *iss = func_02030734(heapId, sizeof(IssSys), 0, ISS_SYS_FileName, 0xa3);

    ISS_SYS_ClearFields(iss);
    ISS_SYS_Setup(iss, gameData, heapId);
    return iss;
}

/* Tears the subsystems down, then frees the object. */
void ISS_SYS_Delete(IssSys *iss)
{
    ISS_SYS_DeleteSubsystems(iss);
    func_020307B0(iss);
}

/* Per-frame update: when the BGM changed, switch the active mode; then step
 * every subsystem (road, city and 3D sound only on even frames). */
void ISS_SYS_Update(IssSys *iss)
{
    if (ISS_SYS_HasBgmChanged(iss) == 1) {
        ISS_SYS_SwitchMode(iss);
        iss->lastBgmId = ISS_SYS_GetCurrentBgmId();
    }
    ISS_SYS_UpdateRoad(iss);
    ISS_SYS_UpdateCity(iss);
    ISS_SYS_UpdateDungeon(iss);
    ISS_SYS_UpdateZone(iss);
    ISS_SYS_UpdateSwitch(iss);
    ISS_SYS_Update3ds(iss);
    iss->frameCount = iss->frameCount + 1;
}

/* Tells every subsystem that the player moved to another zone. */
void ISS_SYS_ChangeZone(IssSys *iss, u16 zoneId)
{
    ISS_SYS_OnZoneChangeRoad();
    ISS_SYS_OnZoneChangeCity(iss, zoneId);
    ISS_SYS_OnZoneChangeDungeon(iss, zoneId);
    ISS_SYS_OnZoneChangeZone(iss, zoneId);
    ISS_SYS_OnZoneChangeSwitch(iss, zoneId);
    ISS_SYS_OnZoneChange3ds(iss, zoneId);
}

IssSwitchSys *ISS_SYS_GetSwitchSys(IssSys *iss)
{
    return iss->sw;
}

Iss3dsSys *ISS_SYS_Get3dsSys(IssSys *iss)
{
    return iss->sound3d;
}

IssDungeonSys *ISS_SYS_GetDungeonSys(IssSys *iss)
{
    return iss->dungeon;
}

/* Zeroes every field. */
void ISS_SYS_ClearFields(IssSys *iss)
{
    iss->heapId = 0;
    iss->gameData = 0;
    iss->lastBgmId = 0;
    iss->frameCount = 0;
    iss->city = 0;
    iss->road = 0;
    iss->dungeon = 0;
    iss->zone = 0;
    iss->sw = 0;
    iss->sound3d = 0;
}

/* Fills the header fields and creates the subsystems. */
void ISS_SYS_Setup(IssSys *iss, GameData *gameData, u32 heapId)
{
    iss->gameData = gameData;
    iss->lastBgmId = 0xffffffff;
    iss->heapId = (u16)heapId;
    iss->frameCount = 0;

    ISS_SYS_CreateRoad(iss);
    ISS_SYS_CreateCity(iss);
    ISS_SYS_CreateDungeon(iss);
    ISS_SYS_CreateZone(iss);
    ISS_SYS_CreateSwitch(iss);
    ISS_SYS_Create3ds(iss);
}

/* Deletes the six subsystems. */
void ISS_SYS_DeleteSubsystems(IssSys *iss)
{
    ISS_SYS_DeleteRoad(iss);
    ISS_SYS_DeleteCity(iss);
    ISS_SYS_DeleteDungeon(iss);
    ISS_SYS_DeleteZone(iss);
    ISS_SYS_DeleteSwitch(iss);
    ISS_SYS_Delete3ds(iss);
}

void ISS_SYS_CreateRoad(IssSys *iss)
{
    iss->road = ISS_ROAD_SYS_Create(ISS_SYS_GetLocation(iss), iss->heapId);
}

void ISS_SYS_CreateCity(IssSys *iss)
{
    iss->city = ISS_CITY_SYS_Create(ISS_SYS_GetLocation(iss), iss->heapId);
}

void ISS_SYS_CreateDungeon(IssSys *iss)
{
    iss->dungeon = ISS_DUNGEON_SYS_Create(iss->gameData, ISS_SYS_GetLocation(iss), iss->heapId);
}

void ISS_SYS_CreateZone(IssSys *iss)
{
    iss->zone = ISS_ZONE_SYS_Create(iss->heapId);
}

void ISS_SYS_CreateSwitch(IssSys *iss)
{
    iss->sw = ISS_SWITCH_SYS_Create(iss->heapId);
}

void ISS_SYS_Create3ds(IssSys *iss)
{
    iss->sound3d = ISS_3DS_SYS_Create(iss->heapId);
}

void ISS_SYS_DeleteRoad(IssSys *iss)
{
    ISS_ROAD_SYS_Delete(iss->road);
    iss->road = 0;
}

void ISS_SYS_DeleteCity(IssSys *iss)
{
    ISS_CITY_SYS_Delete(iss->city);
    iss->city = 0;
}

void ISS_SYS_DeleteDungeon(IssSys *iss)
{
    ISS_DUNGEON_SYS_Delete(iss->dungeon);
    iss->dungeon = 0;
}

void ISS_SYS_DeleteZone(IssSys *iss)
{
    ISS_ZONE_SYS_Delete(iss->zone);
    iss->zone = 0;
}

void ISS_SYS_DeleteSwitch(IssSys *iss)
{
    ISS_SWITCH_SYS_Delete(iss->sw);
    iss->sw = 0;
}

void ISS_SYS_Delete3ds(IssSys *iss)
{
    ISS_3DS_SYS_Delete(iss->sound3d);
    iss->sound3d = 0;
}

void ISS_SYS_UpdateRoad(IssSys *iss)
{
    if ((iss->frameCount & 1) == 0) {
        ISS_ROAD_SYS_Update(iss->road);
    }
}

void ISS_SYS_UpdateCity(IssSys *iss)
{
    if ((iss->frameCount & 1) == 0) {
        ISS_CITY_SYS_Update(iss->city);
    }
}

void ISS_SYS_UpdateDungeon(IssSys *iss)
{
    ISS_DUNGEON_SYS_Update(iss->dungeon);
}

void ISS_SYS_UpdateZone(IssSys *iss)
{
    ISS_ZONE_SYS_Update(iss->zone);
}

void ISS_SYS_UpdateSwitch(IssSys *iss)
{
    ISS_SWITCH_SYS_Main(iss->sw);
}

void ISS_SYS_Update3ds(IssSys *iss)
{
    if ((iss->frameCount & 1) == 0) {
        ISS_3DS_SYS_Update(iss->sound3d);
    }
}

void ISS_SYS_EnterRoad(IssSys *iss)
{
    ISS_ROAD_SYS_Start(iss->road);
}

void ISS_SYS_EnterCity(IssSys *iss)
{
    ISS_CITY_SYS_Start(iss->city);
}

void ISS_SYS_EnterDungeon(IssSys *iss)
{
    ISS_DUNGEON_SYS_Start(iss->dungeon);
}

void ISS_SYS_EnterZone(IssSys *iss)
{
    ISS_ZONE_SYS_Start(iss->zone, ISS_SYS_GetZoneId(iss));
}

void ISS_SYS_EnterSwitch(IssSys *iss)
{
    ISS_SWITCH_SYS_On(iss->sw);
}

void ISS_SYS_Enter3ds(IssSys *iss)
{
    ISS_3DS_SYS_Enter(iss->sound3d);
}

void ISS_SYS_LeaveRoad(IssSys *iss)
{
    ISS_ROAD_SYS_Stop(iss->road);
}

void ISS_SYS_LeaveCity(IssSys *iss)
{
    ISS_CITY_SYS_Stop(iss->city);
}

void ISS_SYS_LeaveDungeon(IssSys *iss)
{
    ISS_DUNGEON_SYS_Stop(iss->dungeon);
}

void ISS_SYS_LeaveZone(IssSys *iss)
{
    ISS_ZONE_SYS_Stop(iss->zone);
}

void ISS_SYS_LeaveSwitch(IssSys *iss)
{
    ISS_SWITCH_SYS_Off(iss->sw);
}

void ISS_SYS_Leave3ds(IssSys *iss)
{
    ISS_3DS_SYS_Leave(iss->sound3d);
}

/* The road subsystem has no zone-change handler. */
void ISS_SYS_OnZoneChangeRoad(void)
{
}

void ISS_SYS_OnZoneChangeCity(IssSys *iss, u32 zoneId)
{
    ISS_CITY_SYS_NotifyZoneChange(iss->city, zoneId);
}

void ISS_SYS_OnZoneChangeDungeon(IssSys *iss, u16 zoneId)
{
    sub_0202B420(iss->dungeon, zoneId);
}

void ISS_SYS_OnZoneChangeZone(IssSys *iss, u32 zoneId)
{
    ISS_ZONE_SYS_SwitchZone(iss->zone, zoneId);
}

void ISS_SYS_OnZoneChangeSwitch(IssSys *iss, u32 zoneId)
{
    sub_0202C0C8(iss->sw);
}

void ISS_SYS_OnZoneChange3ds(IssSys *iss, u32 zoneId)
{
    ISS_3DS_SYS_OnZoneChange(iss->sound3d);
}

/* The player's current location, from the game data. */
const Location *ISS_SYS_GetLocation(IssSys *iss)
{
    return GAME_DATA_GetMyPlayerWork(iss->gameData);
}

u16 ISS_SYS_GetZoneId(IssSys *iss)
{
    return GAME_DATA_GetPlayerZoneId(ISS_SYS_GetLocation(iss));
}

/* The BGM that is playing now. */
u32 ISS_SYS_GetCurrentBgmId(void)
{
    return GFL_USE_GetBgmNo();
}

/* The ISS mode that the BGM now playing maps to. */
u8 ISS_SYS_GetBgmMode(IssSys *iss)
{
    const BgmInfoTable *table = GAME_DATA_GetBagCursor(iss->gameData);

    return func_02006E7C(table, (u16)ISS_SYS_GetCurrentBgmId());
}

/* 1 when the BGM differs from the one the last update saw, else 0. */
u32 ISS_SYS_HasBgmChanged(IssSys *iss)
{
    if (iss->lastBgmId == ISS_SYS_GetCurrentBgmId()) {
        return 0;
    }
    return 1;
}

/* Leaves every mode except the new one, then enters the new one.
 * ISS_SYS_ModeTable + 4 (the onEnter field) is reached through its own pool
 * word because a register-offset load has no immediate (docs/idioms/
 * pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md). */
void ISS_SYS_SwitchMode(IssSys *iss)
{
    int mode = ISS_SYS_GetBgmMode(iss);
    int i;

    for (i = 0; i < ISS_MODE_COUNT; i++) {
        if (mode != ISS_SYS_ModeTable[i].mode && ISS_SYS_ModeTable[i].onLeave != 0) {
            ISS_SYS_ModeTable[i].onLeave(iss);
        }
    }
    if (ISS_SYS_ModeTable[mode].onEnter != 0) {
        ISS_SYS_ModeTable[mode].onEnter(iss);
    }
}

/* Allocates and clears the 3D sound subsystem, then loads its BGM table. */
Iss3dsSys *ISS_3DS_SYS_Create(u32 heapId)
{
    Iss3dsSys *sys = func_02030734(heapId, sizeof(Iss3dsSys), 0, ISS_3DS_SYS_FileName, 0xa3);

    sys->heapId = (u16)heapId;
    sys->entered = 0;
    sys->volume = 0x7f;
    sys->maxVolume = 0x7f;
    sys->fadeSpeed = 4;
    sys->cameraPos.x = 0;
    sys->cameraPos.y = 0;
    sys->cameraPos.z = 0;
    sys->cameraTarget.x = 0;
    sys->cameraTarget.y = 0;
    sys->cameraTarget.z = 0;

    ISS_3DS_SYS_ResetSources(sys);
    ISS_3DS_SYS_ClearTable(sys);
    ISS_3DS_SYS_LoadTable(sys);
    return sys;
}

/* Frees the BGM table, then the object. */
void ISS_3DS_SYS_Delete(Iss3dsSys *sys)
{
    ISS_3DS_SYS_FreeTable(sys);
    func_020307B0(sys);
}

/* The four thunks below are linker veneers into the 3D sound code:
 * update, enter, leave and zone change. */
void ISS_3DS_SYS_Update(Iss3dsSys *sys)
{
    ISS_3DS_SYS_UpdateImpl((struct Iss3dsSound *)sys);
}

void ISS_3DS_SYS_Enter(Iss3dsSys *sys)
{
    ISS_3DS_SYS_EnterImpl(sys);
}

void ISS_3DS_SYS_Leave(Iss3dsSys *sys)
{
    ISS_3DS_SYS_LeaveImpl(sys);
}

void ISS_3DS_SYS_OnZoneChange(Iss3dsSys *sys)
{
    ISS_3DS_SYS_OnZoneChangeImpl((struct Iss3dsSound *)sys);
}

/* Stores the volume, clamped to 0x7f. */
void ISS_3DS_SYS_SetVolume(Iss3dsSys *sys, u32 volume)
{
    if (volume > 0x7f) {
        volume = 0x7f;
    }
    sys->volume = (u8)volume;
}

/* Starts a sound source in a free slot. */
void ISS_3DS_SYS_StartSource(Iss3dsSys *sys, int slot, int radius, int amp)
{
    ISS_3DS_SYS_StartSourceImpl(sys, slot, radius, amp);
}

/* Returns the active flag of a slot. */
int ISS_3DS_SYS_IsSourceActive(Iss3dsSys *sys, int slot)
{
    return sys->slots[slot].active;
}

void ISS_3DS_SYS_SetSourcePos(Iss3dsSys *sys, int slot, const IssVec3 *pos)
{
    ISS_3DS_SYS_SetSourcePosImpl(sys, slot, pos);
}

void ISS_3DS_SYS_SetCamera(Iss3dsSys *sys, const int *cameraPos, const int *cameraTarget)
{
    ISS_3DS_SYS_SetCameraImpl(sys, cameraPos, cameraTarget);
}

/* Empties the BGM table. */
void ISS_3DS_SYS_ClearTable(Iss3dsSys *sys)
{
    sys->table = 0;
    sys->tableCount = 0;
    sys->tableIndex = 0xff;
}

/* Loads the BGM table from archive 0xb9 into a heap block, one 8-byte entry
 * per archive member. */
void ISS_3DS_SYS_LoadTable(Iss3dsSys *sys)
{
    u32 heapId = sys->heapId;
    void *arc = func_020490F4(0xb9, (u16)((heapId & 0x7fff) | 0x8000));
    u8 count = (u8)ARC_TOOL_GetHandleFileCount(arc);
    u32 i;

    sys->tableCount = count;
    sys->table = func_02030734(heapId, (u32)(count << 3), 0, ISS_3DS_SYS_FileName, 0x178);

    for (i = 0; i < (u32)count; i++) {
        ARC_TOOL_ReadHandleMember(arc, i, sys->table + i);
    }
    ARC_TOOL_DeleteHandle(arc);
}

/* Frees the BGM table and empties it. */
void ISS_3DS_SYS_FreeTable(Iss3dsSys *sys)
{
    func_020307B0(sys->table);
    ISS_3DS_SYS_ClearTable(sys);
}

/* Selects a table entry; leaves the table index alone when it is unchanged. */
Iss3dsSys *ISS_3DS_SYS_SetTableIndex(Iss3dsSys *sys, u32 index)
{
    if (sys->tableIndex != index) {
        sys->tableIndex = (u8)index;
    } else {
        return sys;
    }
}

/* Finds the table entry for a BGM; 0xff when there is none. */
u8 ISS_3DS_SYS_FindTableIndex(const Iss3dsSys *sys, u32 bgmId)
{
    const Iss3dsTableEntry *table = sys->table;
    u8 count;
    u8 i;

    if (table == 0) {
        return 0xff;
    }

    count = sys->tableCount;
    for (i = 0; i < count; i++) {
        if (table[i].bgmId == bgmId) {
            return i;
        }
    }

    return 0xff;
}

/* Resets the slots (inactive, full amplitude, one track-mask bit each) and the
 * two level arrays.  The loop keeps its zero-trip guard because the counter is
 * an enum, and the level stores write 0 rather than the counter. */
void ISS_3DS_SYS_ResetSources(Iss3dsSys *sys)
{
    Iss3dsSlotIndex i;

    for (i = 0; i < ISS_3DS_SLOT_COUNT; i++) {
        sys->slots[i].active = 0;
        sys->slots[i].amp = 0x7f;
        sys->slots[i].trackMask = 1 << i;
        sys->slotLevelA[i] = 0;
        sys->slotLevelB[i] = 0;
    }
}

void ISS_3DS_SYS_StartSourceImpl(Iss3dsSys *sys, int slot, int radius, int amp)
{
    Iss3dsSlot *s = &sys->slots[slot];

    if (s->active != 1) {
        s->active = 1;
        s->radius = radius;
        s->amp = amp;
    }
}

void ISS_3DS_SYS_SetSourcePosImpl(Iss3dsSys *sys, int slot, const IssVec3 *pos)
{
    Iss3dsSlot *s = &sys->slots[slot];

    if (s->active != 0) {
        ISS_3DS_SYS_SetVec3(&s->pos, pos->x, pos->y, pos->z);
    }
}

void ISS_3DS_SYS_SetCameraImpl(Iss3dsSys *sys, const int *cameraPos, const int *cameraTarget)
{
    ISS_3DS_SYS_SetVec3(&sys->cameraPos, cameraPos[0], cameraPos[1], cameraPos[2]);
    ISS_3DS_SYS_SetVec3(&sys->cameraTarget, cameraTarget[0], cameraTarget[1], cameraTarget[2]);
}

/* Enter: once per entry, pick the table entry for the BGM now playing. */
void ISS_3DS_SYS_EnterImpl(Iss3dsSys *sys)
{
    if (sys->entered != 0) {
        return;
    }
    sys->entered = 1;
    ISS_3DS_SYS_SetTableIndex(sys, ISS_3DS_SYS_FindTableIndex(sys, GFL_USE_GetBgmNo()));
    ISS_3DS_SYS_SilenceActiveTracks((struct Iss3dsSound *)sys);
}

/* Leave: clears the entered flag (the test is redundant but original). */
void ISS_3DS_SYS_LeaveImpl(Iss3dsSys *sys)
{
    if (sys->entered != 0) {
        sys->entered = 0;
    }
}

/*
 * Moved from iss_zone_sys.c (wave 12 MP-7): the iss_3ds_sys.c per-source view
 * of the same 0x26c-byte sound object that Iss3dsSys above reads, plus the
 * per-source volume and pan ramps that step it.  The view is the same layout
 * under other field names (enabled/entered, targetVolume/maxVolume,
 * sources/slots, volumeLevel/slotLevelA, panLevel/slotLevelB,
 * records/table, recordCount/tableCount, activeRecord/tableIndex).
 */
typedef signed int s32;
typedef signed long long s64;

struct Vec {
    s32 x, y, z;
};

/* One 8-byte zone record of the record table at the end of the object. */
struct IssZoneRecord {
    u16 key;
    u16 audibleMask;
    u16 mutedMask;
    u16 fadeSteps;
};

typedef enum { ISS_3DS_SOURCE_FIRST, ISS_3DS_SOURCE_MAX = 16 } Iss3dsSourceIndex;

/* One 3D sound source: a point that drives the volume and pan of some tracks. */
struct Iss3dsSource {
    u32 active;
    struct Vec pos;
    s32 radius;
    s32 amplitude;
    u16 trackMask;
    u16 padding1A;
};

/* The per-source view of the iss_3ds_sys object that the moved code reads. */
struct Iss3dsSound {
    u8  padding00[4];
    u32 enabled;
    u8  targetVolume;
    u8  volume;
    u8  volumeStep;
    u8  padding0B;
    struct Vec listenerPos;
    struct Vec listenerTarget;
    struct Iss3dsSource sources[ISS_3DS_SOURCE_MAX];
    s32 volumeLevel[ISS_3DS_SOURCE_MAX];
    s32 panLevel[ISS_3DS_SOURCE_MAX];
    struct IssZoneRecord *records;
    u8  recordCount;
    u8  activeRecord;
};

extern void VEC_Subtract(const struct Vec *a, const struct Vec *b, struct Vec *out);
extern s32  VEC_Mag(const struct Vec *v);
extern u32  FX_Div(u32 numerator, u32 denominator);
extern void VEC_Normalize(const struct Vec *v, struct Vec *out);
extern void VEC_CrossProduct(const struct Vec *a, const struct Vec *b, struct Vec *out);
extern s32  VEC_DotProduct(const struct Vec *a, const struct Vec *b);
extern void GFL_USE_SetBgmTrackParams(u32 trackMask, u32 paramKind, u32 unused, u32 value);
extern void GFL_USE_SetBgmTrackVolume(u32 trackMask, u32 volume);

void ISS_3DS_SYS_UpdateImpl(struct Iss3dsSound *sys);
void ISS_3DS_SYS_OnZoneChangeImpl(struct Iss3dsSound *sys);
void ISS_3DS_SYS_SilenceActiveTracks(struct Iss3dsSound *sys);
void ISS_3DS_SYS_StepSourceVolume(struct Iss3dsSound *sys, int sourceIndex);
void ISS_3DS_SYS_StepSourcePan(struct Iss3dsSound *sys, int sourceIndex);
s32 ISS_3DS_SYS_CalcSourceVolume(struct Iss3dsSource *source, const struct Vec *listenerPos);
void ISS_3DS_SYS_RampVolumeUp(struct Iss3dsSound *sys, u32 sourceIndex, s32 cap);
void ISS_3DS_SYS_RampVolumeDown(struct Iss3dsSound *sys, u32 sourceIndex, s32 cap);
void ISS_3DS_SYS_ApplySourceVolume(struct Iss3dsSound *sys, u32 sourceIndex);
s32 ISS_3DS_SYS_CalcSourcePan(const struct Iss3dsSource *source, const struct Vec *listenerPos, const struct Vec *listenerTarget);
void ISS_3DS_SYS_RampPanDown(struct Iss3dsSound *sys, u32 sourceIndex, s32 cap);
void ISS_3DS_SYS_RampPanUp(struct Iss3dsSound *sys, u32 sourceIndex, s32 cap);
void ISS_3DS_SYS_ApplySourcePan(struct Iss3dsSound *sys, u32 sourceIndex);
void ISS_3DS_SYS_StepMasterVolume(struct Iss3dsSound *sys);
u32 ISS_3DS_SYS_ScaleVolume(struct Iss3dsSound *sys, u32 level, void *unused);

/*
 * iss_3ds_sys.c per-frame step: returns when +0x04 is zero, then runs the
 * four per-entry steps over every live entry of the 0x10-slot table.
 * The listing extent (84) runs into the 8-byte thunk at 0x0202BB40; the
 * function itself is 74 bytes.
 *
 * The kept `cmp r4, #0x10; bge` zero-trip guard is an enum-typed
 * counter (docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md),
 * the same lever as its sibling ISS_3DS_SYS_ResetSources.
 */
void ISS_3DS_SYS_UpdateImpl(struct Iss3dsSound *sys)
{
    Iss3dsSourceIndex i;

    if (sys->enabled == 0) {
        return;
    }
    ISS_3DS_SYS_StepMasterVolume(sys);
    for (i = 0; i < 0x10; i++) {
        if (sys->sources[i].active != 0) {
            ISS_3DS_SYS_StepSourceVolume(sys, i);
            ISS_3DS_SYS_StepSourcePan(sys, i);
            ISS_3DS_SYS_ApplySourceVolume(sys, i);
            ISS_3DS_SYS_ApplySourcePan(sys, i);
        }
    }
}

/*
 * iss_3ds_sys.c: a bare tail-call thunk to ISS_3DS_SYS_ResetSources (ldr r3, [pc, #0];
 * bx r3; .word 0x0202BA25), the target of the thunk at 0x0202B90C.
 */
void ISS_3DS_SYS_OnZoneChangeImpl(struct Iss3dsSound *sys)
{
    ISS_3DS_SYS_ResetSources((Iss3dsSys *)sys);
}

/* Silences the tracks of the active record, when there is one. */
void ISS_3DS_SYS_SilenceActiveTracks(struct Iss3dsSound *sys)
{
    u8 record = sys->activeRecord;

    if (record != 0xff) {
        GFL_USE_SetBgmTrackVolume(sys->records[record].mutedMask, 0);
    }
}

/*
 * iss_3ds_sys.c, the per-slot twins that ISS_3DS_SYS_UpdateImpl steps: for a live
 * source (0x1c-byte stride at +0x24), compute the target level and move the
 * source's s32 level (volumeLevel or panLevel, indexed by sourceIndex) toward
 * it through the clamp helpers ISS_3DS_SYS_RampVolumeUp / ISS_3DS_SYS_RampPanDown / ISS_3DS_SYS_RampPanUp,
 * which take the computed level as their third argument.
 *
 * Callee arity is read from the callee bodies: both clamp helpers compare
 * against r2, so they are declared (sys, index, cap).
 */
void ISS_3DS_SYS_StepSourceVolume(struct Iss3dsSound *sys, int sourceIndex)
{
    struct Iss3dsSource *sources = sys->sources;
    s32 target;
    s32 level;

    if (sources[sourceIndex].active == 0) {
        return;
    }
    target = ISS_3DS_SYS_CalcSourceVolume(&sources[sourceIndex], &sys->listenerPos);
    level  = sys->volumeLevel[sourceIndex];
    if (level < target) {
        ISS_3DS_SYS_RampVolumeUp(sys, sourceIndex, target);
        return;
    }
    if (target < level) {
        ISS_3DS_SYS_RampVolumeDown(sys, sourceIndex, target);
    }
}

void ISS_3DS_SYS_StepSourcePan(struct Iss3dsSound *sys, int sourceIndex)
{
    struct Iss3dsSource *sources = sys->sources;
    s32 target;
    s32 level;

    if (sources[sourceIndex].active == 0) {
        return;
    }
    target = ISS_3DS_SYS_CalcSourcePan(&sources[sourceIndex], &sys->listenerPos, &sys->listenerTarget);
    level  = sys->panLevel[sourceIndex];
    if (target < level) {
        ISS_3DS_SYS_RampPanDown(sys, sourceIndex, target);
        return;
    }
    if (level < target) {
        ISS_3DS_SYS_RampPanUp(sys, sourceIndex, target);
    }
}

/*
 * Distance falloff: the source position is taken relative to the listener
 * point, and the remaining headroom (the radius less that distance) is
 * divided by the radius through the hardware divider FX_Div. The
 * quotient is an FX32, so it is scaled back by 4096.0f in float before
 * multiplying the amplitude and truncating; that is the pool word 0x45800000
 * at 0x0202BC44. Outside the radius the answer is 0.
 *
 * The compare is signed (bge), so the radius field is s32 and the
 * `mag >= radius` arm is the one written first.
 */
s32 ISS_3DS_SYS_CalcSourceVolume(struct Iss3dsSource *source, const struct Vec *listenerPos)
{
    struct Vec delta;
    s32 distance;
    float ratio;

    VEC_Subtract(&source->pos, listenerPos, &delta);
    distance = VEC_Mag(&delta);
    if (source->radius < distance) {
        return 0;
    }
    ratio = (float)(s32)FX_Div((s32)(source->radius - distance), (s32)source->radius) / 4096.0f;
    return (s32)((float)source->amplitude * ratio);
}

/*
 * A clamp-increment and a clamp-decrement on the same signed 32-bit array
 * (volumeLevel), indexed by the second argument and clamped against a
 * caller-supplied bound passed as the third: ISS_3DS_SYS_RampVolumeUp adds 0x10 and caps
 * at the bound from above, ISS_3DS_SYS_RampVolumeDown subtracts 0x10 and floors at the
 * bound from below.
 *
 * The comparison order in each is a deliberate `cmp`-operand tell
 * (docs/idioms/cmp-operand-order-names-the-temporary.md): ISS_3DS_SYS_RampVolumeUp
 * compares the bound against the computed value (`cmp r2, r1`), which is
 * what `if (cap < v)` compiles to, not `if (v > cap)`.
 */
void ISS_3DS_SYS_RampVolumeUp(struct Iss3dsSound *sys, u32 sourceIndex, s32 cap)
{
    s32 *levels = sys->volumeLevel;
    s32 level = levels[sourceIndex] + 0x10;

    if (cap < level) {
        level = cap;
    }
    levels[sourceIndex] = level;
}

void ISS_3DS_SYS_RampVolumeDown(struct Iss3dsSound *sys, u32 sourceIndex, s32 cap)
{
    s32 *levels = sys->volumeLevel;
    s32 level = levels[sourceIndex] - 0x10;

    if (level < cap) {
        level = cap;
    }
    levels[sourceIndex] = level;
}

/* Applies the master volume to the source's level and sets its tracks' volume. */
void ISS_3DS_SYS_ApplySourceVolume(struct Iss3dsSound *sys, u32 sourceIndex)
{
    u8 *slot = (u8 *)sys + sourceIndex * 4;
    int volume = ISS_3DS_SYS_ScaleVolume(sys, (u8)*(int *)(slot + 0x1E4), slot);

    GFL_USE_SetBgmTrackVolume(sys->sources[sourceIndex].trackMask, volume);
}

/*
 * Signed pan, -0x80..0x7f, for a source heard from a listener: build the
 * listener's right-hand axis by crossing its facing vector with world up
 * (and normalising twice, which is what the doubled VEC_Normalize pair is),
 * then project the listener-to-source direction onto it.  The three
 * _ll_mul + shift-by-12 triples are FX_Mul in its open form, scaling the
 * normalised axis by the source distance.
 *
 * The two vector arguments arrive as pointers and are copied into locals
 * before use; the ldm/stm pairs at the top are those copies, not aliasing
 * work (see docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * The 4096.0f divisor is the pool word 0x45800000 at 0x0202BDCC; 0x43000000
 * is 128.0f, materialised as movs #0x43 / lsls #0x18 rather than pooled.
 */
s32 ISS_3DS_SYS_CalcSourcePan(const struct Iss3dsSource *source, const struct Vec *listenerPos,
                  const struct Vec *listenerTarget)
{
    struct Vec facing;
    struct Vec toSource;
    struct Vec horizontal;
    struct Vec up;
    struct Vec verticalPart;
    struct Vec right;
    struct Vec upAxis;
    struct Vec facingUnit;
    struct Vec listener;
    struct Vec target;
    struct Vec sourcePos;
    s32 height;
    s32 pan;

    listener = *listenerPos;
    target = *listenerTarget;
    sourcePos = source->pos;
    VEC_Subtract(&target, &listener, &facing);
    VEC_Subtract(&sourcePos, &listener, &toSource);

    up.x = 0;
    up.y = 0x1000;
    up.z = 0;
    VEC_Normalize(&facing, &facingUnit);
    VEC_CrossProduct(&facingUnit, &up, &right);
    VEC_Normalize(&right, &right);
    VEC_CrossProduct(&right, &facingUnit, &upAxis);
    VEC_Normalize(&upAxis, &upAxis);
    VEC_Normalize(&upAxis, &upAxis);

    height = VEC_DotProduct(&toSource, &upAxis);
    verticalPart.x = (s32)(((s64)upAxis.x * height + 0x800) >> 12);
    verticalPart.y = (s32)(((s64)upAxis.y * height + 0x800) >> 12);
    verticalPart.z = (s32)(((s64)upAxis.z * height + 0x800) >> 12);

    VEC_Subtract(&toSource, &verticalPart, &horizontal);
    VEC_Normalize(&horizontal, &horizontal);
    pan = (s32)((float)VEC_DotProduct(&right, &horizontal) / 4096.0f * 128.0f);
    if (pan < -0x80) {
        pan = -0x80;
    }
    if (pan > 0x7f) {
        pan = 0x7f;
    }
    return pan;
}

/*
 * A clamp-decrement on the same shape as ISS_3DS_SYS_RampVolumeDown, on panLevel (offset
 * 0x224 of the object) with a different step (0x20). Matched as a
 * one-function unit rather than with `one`: this function is followed by two
 * bytes of inter-section padding before the next label.
 */
void ISS_3DS_SYS_RampPanDown(struct Iss3dsSound *sys, u32 sourceIndex, s32 cap)
{
    s32 *levels = sys->panLevel;
    s32 level = levels[sourceIndex] - 0x20;

    if (level < cap) {
        level = cap;
    }
    levels[sourceIndex] = level;
}

/*
 * A clamp-increment on the same shape as ISS_3DS_SYS_RampVolumeUp, on panLevel (offset
 * 0x224) with step 0x20. Matched as a one-function unit rather than with
 * `one`, for the same trailing-padding reason as ISS_3DS_SYS_RampPanDown.
 */
void ISS_3DS_SYS_RampPanUp(struct Iss3dsSound *sys, u32 sourceIndex, s32 cap)
{
    s32 *levels = sys->panLevel;
    s32 level = levels[sourceIndex] + 0x20;

    if (cap < level) {
        level = cap;
    }
    levels[sourceIndex] = level;
}

/*
 * Sets the pan of one source's tracks (trackMask halfword at +0x3c of the
 * object) to its panLevel (+0x224 array).
 */
void ISS_3DS_SYS_ApplySourcePan(struct Iss3dsSound *sys, u32 sourceIndex)
{
    GFL_USE_SetBgmTrackParams(sys->sources[sourceIndex].trackMask, 0x100, 0,
                  sys->panLevel[sourceIndex]);
}

/*
 * Moves the master volume one step toward targetVolume: a full step when
 * the distance is at least volumeStep, the exact distance otherwise.
 */
void ISS_3DS_SYS_StepMasterVolume(struct Iss3dsSound *sys)
{
    int target = sys->targetVolume;
    int current = sys->volume;
    int diff;
    int abs_diff;
    int step;

    if (current == target) {
        return;
    }

    diff = target - current;
    abs_diff = diff;
    if (diff <= 0) {
        abs_diff = -diff;
    }

    step = sys->volumeStep;
    if (abs_diff >= step) {
        if (diff < 0) {
            diff = -step;
        } else {
            diff = step;
        }
    }

    sys->volume += diff;
}

/*
 * Returns (volume * level) / 0x7f truncated to a byte: the source level
 * scaled by the master volume. The third argument is unused.
 */
u32 ISS_3DS_SYS_ScaleVolume(struct Iss3dsSound *sys, u32 level, void *unused)
{
    return (u8)((sys->volume * level) / 0x7f);
}
