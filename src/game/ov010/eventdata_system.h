#ifndef GAME_OV010_EVENTDATA_SYSTEM_H
#define GAME_OV010_EVENTDATA_SYSTEM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of eventdata_system.c, prototypes copied from their definitions. */

struct EventDataSystem;
struct ConnectData;
struct EventRec;
struct BgEventData;
typedef struct EventDataSystem EventDataSystem;
typedef struct ConnectData ConnectData;
typedef struct BgEventData BgEventData;

#include "../types.h"
#include "../sdk_fx.h"
#include "../arm9/zonedata_types.h"

EventDataSystem *EVENTDATA_SYSTEM_Create(int heapId);
void EVENTDATA_SYSTEM_Delete(EventDataSystem *system);
void EVENTDATA_SYSTEM_Clear(EventDataSystem *system);
void EVENTDATA_SYSTEM_Load(EventDataSystem *system, u16 zoneId, u8 encountParam);
void EVENTDATA_SYSTEM_LoadEventData(EventDataSystem *system, u16 zoneId, u8 unused);
void EVENTDATA_SYSTEM_LoadEncountData(EventDataSystem *system, int zoneId, int encountParam);
u32 EVENTDATA_SYSTEM_GetSpecialScriptData(EventDataSystem *system);
u32 EVENTDATA_SYSTEM_IsEncountDataLoaded(EventDataSystem *system);
void EVENTDATA_SYSTEM_DisableConnect(EventDataSystem *system, u16 index);
int EVENTDATA_SYSTEM_CheckAutoPosEvent(EventDataSystem *system, VecFx32 *pos);
void EVENTDATA_SYSTEM_ReadEventFile(EventDataSystem *system, int zoneId);
void EVENTDATA_SYSTEM_ClearEventTables(EventDataSystem *system);
u32 EVENTDATA_SYSTEM_GetEncountData(u32 systemAddr);
u16 EVENTDATA_SYSTEM_GetConnectCount(EventDataSystem *system);
int EVENTDATA_SYSTEM_SearchConnectIdByGridPos(EventDataSystem *system, const VecFx32 *pos);
int EVENTDATA_SYSTEM_SearchConnectIdByRailLocation(EventDataSystem *system, RailLocation *location);
ConnectData *EVENTDATA_SYSTEM_GetConnectData(const EventDataSystem *system, unsigned index);
int EVENTDATA_SYSTEM_IsSpecialExitConnect(ConnectData *connect);
int EVENTDATA_SYSTEM_SetConnectExitLocation(const EventDataSystem *system, int *exitInfo, int connectIndex, int exitOffset);
void EVENTDATA_SYSTEM_SetConnectExitLocationIdOnly(ConnectData *connect, int exitInfo, int exitOffset);
u16 EVENTDATA_SYSTEM_GetConnectGridExitOffset(ConnectData *connect, VecFx32 *pos);
u16 EVENTDATA_SYSTEM_GetConnectRailExitOffset(ConnectData *connect, RailLocation *location);
int EVENTDATA_SYSTEM_IsConnectExitDir(ConnectData *connect, int dir);
u8 EVENTDATA_SYSTEM_GetConnectExitType(ConnectData *connect);
int EVENTDATA_SYSTEM_IsConnectDisabled(ConnectData *connect);
void EVENTDATA_SYSTEM_SetConnectGridPos(EventDataSystem *system, u32 index, u16 gridX, u32 height, u16 gridZ);
u32 EVENTDATA_SYSTEM_GetNpcHeaders(EventDataSystem *system);
u16 EVENTDATA_SYSTEM_GetNpcCount(EventDataSystem *system);
void EVENTDATA_SYSTEM_SetNpcGridPos(EventDataSystem *system, u32 index, u16 dir, u16 gx, u32 y, u16 gz);
void EVENTDATA_SYSTEM_SetNpcObjCode(EventDataSystem *system, unsigned index, u16 objCode);
void EVENTDATA_SYSTEM_SetNpcEventId(EventDataSystem *system, unsigned index, u16 eventId);
u16 EVENTDATA_SYSTEM_DirToPosEventType(int mode);
struct EventRec *EVENTDATA_SYSTEM_SearchPosEvent(EventDataSystem *system, void *eventWork, VecFx32 *pos, int mode);
struct EventRec *EVENTDATA_SYSTEM_SearchPosEventIgnoreHeight(EventDataSystem *system, void *eventWork, VecFx32 *pos, int mode);
struct EventRec *EVENTDATA_SYSTEM_SearchAutoPosEvent(EventDataSystem *system, void *eventWork, VecFx32 *pos);
struct EventRec *EVENTDATA_SYSTEM_SearchRailPosEvent(EventDataSystem *system, void *eventWork, RailLocation *location);
u16 EVENTDATA_SYSTEM_GetPosEventScriptId(EventDataSystem *system, void *eventWork, VecFx32 *pos, int mode);
u16 EVENTDATA_SYSTEM_GetAutoPosEventScriptId(EventDataSystem *system, void *eventWork, VecFx32 *pos);
u16 EVENTDATA_SYSTEM_GetRailPosEventScriptId(EventDataSystem *system, void *eventWork, RailLocation *location);
u16 EVENTDATA_SYSTEM_SearchBgEventScriptId(EventDataSystem *system, void *eventFlags, const void *pos, u16 facing);
u16 EVENTDATA_SYSTEM_SearchBgEventScriptIdTalk(EventDataSystem *system, void *eventFlags, const void *pos, u16 facing);
u16 EVENTDATA_SYSTEM_SearchBgEventScriptIdHidden(EventDataSystem *system, void *eventFlags, const void *pos, u16 facing);
void EVENTDATA_SYSTEM_GetConnectCenterPosThunk(const ConnectData *connect, VecFx32 *pos);
void EVENTDATA_SYSTEM_GetPosEventCenterPosThunk(const struct EventRec *event, VecFx32 *pos);
void EVENTDATA_SYSTEM_SetBgEventGridPos(const EventDataSystem *system, u32 index, u32 gridX, u32 height, u16 gridZ);
u16 EVENTDATA_SYSTEM_CalcExitOffset(int exitInfo, int playerDir, int isRail, int flipMode, u16 arrivalSize);
u16 EVENTDATA_SYSTEM_CalcConnectGridExitOffset(ConnectData *connect, VecFx32 *pos);
u16 EVENTDATA_SYSTEM_CalcConnectRailExitOffset(ConnectData *connect, RailLocation *location);
int EVENTDATA_SYSTEM_ConnectExitDirToDir(ConnectData *connect);
void EVENTDATA_SYSTEM_GetConnectExitGridPos(ConnectData *connect, int exitOffset, VecFx32 *pos);
void EVENTDATA_SYSTEM_GetConnectCenterPos(const ConnectData *connect, VecFx32 *pos);
int EVENTDATA_SYSTEM_IsConnectGridHit(const ConnectData *connect, const VecFx32 *pos);
void EVENTDATA_SYSTEM_GetConnectExitRailLocation(const ConnectData *connect, int exitOffset, RailLocation *location);
int EVENTDATA_SYSTEM_IsConnectRailHit(ConnectData *connect, RailLocation *location);
int EVENTDATA_SYSTEM_IsBgEventGridHit(BgEventData *bg, const VecFx32 *pos);
int EVENTDATA_SYSTEM_IsBgEventRailHit(BgEventData *bg, const RailLocation *location);
void EVENTDATA_SYSTEM_GetPosEventCenterPos(const struct EventRec *event, VecFx32 *pos);
int EVENTDATA_SYSTEM_IsPosEventGridHit(struct EventRec *event, VecFx32 *pos);
int EVENTDATA_SYSTEM_IsPosEventGridHitIgnoreHeight(struct EventRec *event, VecFx32 *pos);
int EVENTDATA_SYSTEM_IsPosEventRailHit(struct EventRec *event, RailLocation *location);
/* END mkheaders: generated region */

#endif
