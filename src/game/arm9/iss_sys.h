#ifndef GAME_ARM9_ISS_SYS_H
#define GAME_ARM9_ISS_SYS_H

struct GameData;
struct Iss3dsSys;

struct IssSys *ISS_SYS_Create(struct GameData *gameData, u32 heapId);
struct IssSwitchSys *ISS_SYS_GetSwitchSys(struct IssSys *iss);
struct Iss3dsSys *ISS_SYS_Get3dsSys(struct IssSys *iss);
struct IssDungeonSys *ISS_SYS_GetDungeonSys(struct IssSys *iss);

typedef struct IssSys IssSys;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of iss_sys.c, prototypes copied from their definitions. */

struct IssSys;
struct IssSwitchSys;
struct IssDungeonSys;
typedef struct IssSys IssSys;
typedef struct IssSwitchSys IssSwitchSys;
typedef struct IssDungeonSys IssDungeonSys;

#include "../types.h"
#include "../arm9/iss_sys_shared_types.h"
#include "../arm9/zonedata_types.h"

void ISS_SYS_Delete(IssSys *iss);
void ISS_SYS_Update(IssSys *iss);
void ISS_SYS_ChangeZone(IssSys *iss, u16 zoneId);
IssSwitchSys *ISS_SYS_GetSwitchSys(IssSys *iss);
Iss3dsSys *ISS_SYS_Get3dsSys(IssSys *iss);
IssDungeonSys *ISS_SYS_GetDungeonSys(IssSys *iss);
void ISS_SYS_ClearFields(IssSys *iss);
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
/* END mkheaders: generated region */

#endif
