/*
 * file:     iss_sys.c
 * unit:     yes
 * function: ISS_SYS_Create, ISS_SYS_Delete, ISS_SYS_Update, ISS_SYS_ChangeZone, ISS_SYS_GetSwitchSys, ISS_SYS_Get3dsSys, ISS_SYS_GetDungeonSys, ISS_SYS_ClearFields, ISS_SYS_Setup, ISS_SYS_DeleteSubsystems, ISS_SYS_CreateRoad, ISS_SYS_CreateCity, ISS_SYS_CreateDungeon, ISS_SYS_CreateZone, ISS_SYS_CreateSwitch, ISS_SYS_Create3ds, ISS_SYS_DeleteRoad, ISS_SYS_DeleteCity, ISS_SYS_DeleteDungeon, ISS_SYS_DeleteZone, ISS_SYS_DeleteSwitch, ISS_SYS_Delete3ds, ISS_SYS_UpdateRoad, ISS_SYS_UpdateCity, ISS_SYS_UpdateDungeon, ISS_SYS_UpdateZone, ISS_SYS_UpdateSwitch, ISS_SYS_Update3ds, ISS_SYS_EnterRoad, ISS_SYS_EnterCity, ISS_SYS_EnterDungeon, ISS_SYS_EnterZone, ISS_SYS_EnterSwitch, ISS_SYS_Enter3ds, ISS_SYS_LeaveRoad, ISS_SYS_LeaveCity, ISS_SYS_LeaveDungeon, ISS_SYS_LeaveZone, ISS_SYS_LeaveSwitch, ISS_SYS_Leave3ds, ISS_SYS_OnZoneChangeRoad, ISS_SYS_OnZoneChangeCity, ISS_SYS_OnZoneChangeDungeon, ISS_SYS_OnZoneChangeZone, ISS_SYS_OnZoneChangeSwitch, ISS_SYS_OnZoneChange3ds, ISS_SYS_GetLocation, ISS_SYS_GetZoneId, ISS_SYS_GetCurrentBgmId, ISS_SYS_GetBgmMode, ISS_SYS_HasBgmChanged, ISS_SYS_SwitchMode
 * address:  0x0202B4BC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from iss_3ds_sys.c by tools/splitfile.py.
 *
 * symbols:
 *   ISS_SYS_FileName  0x020A772C  data
 *   ISS_SWITCH_SYS_Create  0x0202C070  thumb
 *   ISS_ROAD_SYS_Update  0x0202B1F4  thumb
 *   ISS_CITY_SYS_Update  0x0202AB38  thumb
 *   ISS_SWITCH_SYS_Main  0x0202C09C  thumb
 *   ISS_CITY_SYS_NotifyZoneChange  0x0202AB5C  thumb
 *   ISS_CITY_SYS_Start  0x0202AB4C  thumb
 *   ISS_CITY_SYS_Stop  0x0202AB54  thumb
 *   ISS_ROAD_SYS_Start  0x0202B1FC  thumb
 *   ISS_ROAD_SYS_Stop  0x0202B204  thumb
 *   ISS_DUNGEON_SYS_SetTargetAreaId  0x0202B420  thumb
 *   ISS_ZONE_SYS_SwitchZone  0x0202BECC  thumb
 *   ISS_SWITCH_SYS_ZoneChange  0x0202C0C8  thumb
 *   ISS_SYS_ModeTable  0x0209FF88  data
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
 *   ISS_3DS_SYS_Create 0x0202B894 thumb arm9
 *   ISS_3DS_SYS_Delete 0x0202B8E4 thumb arm9
 *   ISS_3DS_SYS_Update 0x0202B8F4 thumb arm9
 *   ISS_3DS_SYS_Enter 0x0202B8FC thumb arm9
 *   ISS_3DS_SYS_Leave 0x0202B904 thumb arm9
 *   ISS_3DS_SYS_OnZoneChange 0x0202B90C thumb arm9
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 */
#include "iss_sys_shared_types.h"

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

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 GFL_HEAP_Free(void *p);

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

extern void ISS_DUNGEON_SYS_SetTargetAreaId(IssDungeonSys *dungeon, u16 zoneId);

extern void ISS_ZONE_SYS_SwitchZone(IssZoneSys *zone, u32 zoneId);

extern void ISS_SWITCH_SYS_ZoneChange(IssSwitchSys *sw);

extern const Location *GAME_DATA_GetMyPlayerWork(const GameData *gameData);

extern u16 GAME_DATA_GetPlayerZoneId(const Location *loc);

extern u16 GFL_USE_GetBgmNo(void);

extern const BgmInfoTable *GAME_DATA_GetBagCursor(const GameData *gameData);

extern u8 func_02006E7C(const BgmInfoTable *table, u16 bgmId);

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

extern const char ISS_SYS_FileName[];

extern const IssModeHandler ISS_SYS_ModeTable[];

/* Allocates the ISS object, clears it and creates the six subsystems. */
IssSys *ISS_SYS_Create(GameData *gameData, u32 heapId)
{
    IssSys *iss = GFL_HEAP_Alloc(heapId, sizeof(IssSys), 0, ISS_SYS_FileName, 0xa3);

    ISS_SYS_ClearFields(iss);
    ISS_SYS_Setup(iss, gameData, heapId);
    return iss;
}

/* Tears the subsystems down, then frees the object. */
void ISS_SYS_Delete(IssSys *iss)
{
    ISS_SYS_DeleteSubsystems(iss);
    GFL_HEAP_Free(iss);
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
    ISS_DUNGEON_SYS_SetTargetAreaId(iss->dungeon, zoneId);
}

void ISS_SYS_OnZoneChangeZone(IssSys *iss, u32 zoneId)
{
    ISS_ZONE_SYS_SwitchZone(iss->zone, zoneId);
}

void ISS_SYS_OnZoneChangeSwitch(IssSys *iss, u32 zoneId)
{
    ISS_SWITCH_SYS_ZoneChange(iss->sw);
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
