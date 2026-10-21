#ifndef GAME_ARM9_ZONEDATA_H
#define GAME_ARM9_ZONEDATA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zonedata.c, prototypes copied from their definitions. */

struct ZoneHeader;
struct AreaData;
struct Location;
struct EventWork;

#include "../types.h"
#include "../sdk_fx.h"

void ZONEDATA_Init(u16 heap);
void ZONEDATA_Exit(void);
void ZONEDATA_SetChangeZoneEnable(u32 index, u8 on);
u16 ZONEDATA_GetChangedZoneId(u32 key);
struct ZoneHeader *ZONEDATA_GetHeader(u32 id);
u32 ZONEDATA_IsChangedZoneInTable(u32 id, const u16 *table, int count);
u16 ZONEDATA_GetAreaId(u32 id);
u32 ZONEDATA_GetMatrixId(u32 id);
u32 ZONEDATA_GetMapType(u32 id);
u32 ZONEDATA_GetScriptArcId(u32 id);
u32 ZONEDATA_GetMsgArcId(u32 id);
void ZONEDATA_GetStartPos(u32 id, VecFx32 *out);
void ZONEDATA_GetStartRailPos(u32 id, VecFx32 *out);
u8 ZONEDATA_GetMapChangeType(u32 id);
u8 ZONEDATA_GetCameraId(u32 id);
u32 ZONEDATA_GetCameraAreaId(u32 id);
u32 ZONEDATA_GetBgmId(u32 id, u32 which);
u32 ZONEDATA_GetWeatherId(u32 id);
u32 ZONEDATA_IsBikeEnabled(u32 id);
u32 ZONEDATA_IsRideBgmEnabled(u32 id);
u32 ZONEDATA_IsFlyEnabled(u32 id);
u32 ZONEDATA_IsWeatherEnabled(u32 id);
u32 ZONEDATA_IsPalaceEnabled(u32 id);
int ZONEDATA_IsRailMap(u32 zoneId);
int ZONEDATA_HasSpecialKind(int zoneId);
int ZONEDATA_GetSpecialKind(u16 key);
u32 ZONEDATA_IsUnionRoom(u32 id);
u32 ZONEDATA_IsZone96Pair(u32 id);
u32 ZONEDATA_IsZone4BPair(u32 id);
u32 ZONEDATA_IsZone34(u32 id);
u32 ZONEDATA_IsNoGameEventZone(u32 id);
u32 ZONEDATA_IsEntralink(u32 id);
int ZONEDATA_IsZoneGroup118To13C(u32 key);
u32 ZONEDATA_IsZoneGroup118To120(u32 id);
u32 ZONEDATA_IsRawZoneGroup121To13C(u32 id);
int ZONEDATA_IsZoneInTableDFC0(int zoneId);
int ZONEDATA_IsZoneInTableDFEC(u16 zoneId);
u32 ZONEDATA_IsZone4E(u32 id);
u32 ZONEDATA_IsNormalFieldZone(u32 id);
u32 ZONEDATA_GetParentZoneId(u32 id);
u32 ZONEDATA_GetPlaceNameId(u32 id);
u32 ZONEDATA_GetPlaceNameWindow(u32 id);
u32 ZONEDATA_IsFieldMatrix(u32 id);
u32 ZONEDATA_IsSameMatrixGroup(u32 a, u32 b);
u32 ZONEDATA_GetEncountId(u32 id);
u32 ZONEDATA_GetEventDataId(u32 id);
u8 ZONEDATA_GetFieldEffectSetId(u32 id);
u32 ZONEDATA_GetFogId(u32 id);
u32 ZONEDATA_GetLightId(u32 id);
u32 ZONEDATA_GetFieldSkillMapEffect(u32 id);
int ZONEDATA_GetSecondSpecialKind(u16 key);
u8 ZONEDATA_GetExpObjSetId(u32 id);
u32 ZONEDATA_IsZoneInTableDFDC(u32 id);
u32 ZONEDATA_IsZoneInTableDFB8(u32 id);
u32 ZONEDATA_IsRawZoneF6(u32 id);
u32 ZONEDATA_IsRawZoneF7(u32 id);
u32 ZONEDATA_IsZoneInTableDFD2(u32 id);
u32 ZONEDATA_IsRawZoneGroup4CTo69(u32 id);
u32 ZONEDATA_IsRawZone176Or17A(u32 id);
u8 ZONEDATA_GetMapSubType(u32 id);
u32 ZONEDATA_IsParentZoneD6(u16 id);
void *ZONEDATA_CreateAreaData(u16 heapId, u16 areaId, u32 season);
u32 ZONEDATA_DeleteAreaData(struct AreaData *areaData);
u16 ZONEDATA_GetAreaTexSetId(const struct AreaData *areaData);
u32 ZONEDATA_GetAreaItaAnimeId(const struct AreaData *areaData);
u32 ZONEDATA_GetAreaItpAnimeId(const struct AreaData *areaData);
u8 ZONEDATA_GetAreaInnerOuter(const struct AreaData *areaData);
u8 ZONEDATA_GetAreaLightType(const struct AreaData *areaData);
u8 ZONEDATA_GetAreaEdgeMarkType(const struct AreaData *areaData);
u8 ZONEDATA_GetAreaBillboardColor(const struct AreaData *areaData);
u32 ZONEDATA_IsSeasonArea(u32 areaId);
void ZONEDATA_InitLocation(struct Location *loc);
void ZONEDATA_SetExitLocation(struct Location *loc, u16 zoneId, u16 exitId, u16 dir, u16 exitOffset, u32 x, u32 y, u32 z);
void ZONEDATA_SetExitRailLocation(struct Location *loc, u16 zoneId, int exitId, u16 dir, u16 exitOffset, u16 railIndex, u16 lineGrid, s16 widthGrid);
void ZONEDATA_SetExitLocationIdOnly(struct Location *loc, u16 zoneId, u16 exitId, u16 exitOffset);
void ZONEDATA_SetDirectLocation(struct Location *loc, s32 zoneId, s16 dir, u32 x, u32 y, u32 z);
void ZONEDATA_SetDirectRailLocation(struct Location *loc, int zoneId, int dir, u16 railIndex, u16 lineGrid, s16 widthGrid);
int ZONEDATA_GetLocationPosType(const struct Location *loc);
void ZONEDATA_GetLocationVec(const struct Location *loc, VecFx32 *out);
void ZONEDATA_SetLocationVec(struct Location *loc, const VecFx32 *vec);
void ZONEDATA_SetZoneStartLocation(struct Location *loc, int zoneId);
void ZONEDATA_SetGameStartLocation(struct Location *loc);
u32 ZONEDATA_ExitDirToDir(u32 exitDir);
u32 ZONEDATA_DirToExitDir(u32 dir);
u32 ZONEDATA_GetEventWorkSize(void);
void ZONEDATA_InitEventWork(struct EventWork *ev);
u32 ZONEDATA_CheckEventFlag(struct EventWork *ev, s32 flagId);
void ZONEDATA_SetEventFlag(struct EventWork *ev, int flagId);
void ZONEDATA_ResetEventFlag(struct EventWork *ev, int flagId);
void ZONEDATA_ResetEventFlagRange(struct EventWork *ev, int firstFlagId, int lastFlagId);
u8 *ZONEDATA_GetEventFlagAddress(struct EventWork *ev, u32 flagId);
u16 *ZONEDATA_GetEventWorkAddress(struct EventWork *ev, u32 workId);
void ZONEDATA_ClearEventWorkRange(struct EventWork *ev, u32 firstWorkId, u32 endWorkId);
void ZONEDATA_ClearTimeFlags(struct EventWork *ev);
u8 ZONEDATA_PopTimeFlagsCleared(struct EventWork *ev);
u8 ZONEDATA_DirToRailKey(int dir);
/* END mkheaders: generated region */

#endif
