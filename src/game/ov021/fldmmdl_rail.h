#ifndef GAME_OV021_FLDMMDL_RAIL_H
#define GAME_OV021_FLDMMDL_RAIL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldmmdl_rail.c, prototypes copied from their definitions. */

#include "../ov010/fldmmdl_types.h"
#include "../arm9/zonedata_types.h"
#include "../ov021/field_rail_types.h"
#include "../types.h"

void FLDMMDL_RAIL_SetLocation(Mmdl *mmdl, RailLocation *loc);
void FLDMMDL_RAIL_GetNextLocation(Mmdl *mmdl, RailLocation *outLoc);
void FLDMMDL_RAIL_GetNowLocation(Mmdl *mmdl, RailLocation *outLoc);
RailWork *FLDMMDL_RAIL_GetRailWork(Mmdl *mmdl);
void FLDMMDL_RAIL_UpdateRailWork(Mmdl *mmdl);
void FLDMMDL_RAIL_SetMoveRequest(Mmdl *mmdl, u32 dir, u32 key);
u32 FLDMMDL_RAIL_GetHitBitsLocation(Mmdl *mmdl, RailLocation *nowLoc, RailLocation *nextLoc, u32 *outAttr);
int FLDMMDL_RAIL_GetHitBitsDirNoAttr(Mmdl *mmdl, u16 dir);
int FLDMMDL_RAIL_GetHitBitsDir(Mmdl *mmdl, u32 dir, u32 *outAttr);
int FLDMMDL_RAIL_CheckHitMmdl(Mmdl *mmdl, RailLocation *loc);
Mmdl *FLDMMDL_RAIL_SearchMmdlByLocation(MmdlSys *mmdlSys, RailLocation *loc, u32 includeNow);
int FLDMMDL_RAIL_GetFrontLocation(Mmdl *mmdl, RailLocation *outLoc);
int FLDMMDL_RAIL_GetLocationByDir(Mmdl *mmdl, u32 dir, RailLocation *outLoc);
void FLDMMDL_RAIL_SetGridPosByDir(Mmdl *mmdl, u16 dir);
void FLDMMDL_RAIL_GetDrawOffset(Mmdl *mmdl, s16 *outOffset);
void FLDMMDL_RAIL_GetDrawOffsetByDir(Mmdl *mmdl, u32 dir, s16 *outOffset);
void FLDMMDL_RAIL_StayMove(Mmdl *mmdl, u32 unused1, u32 unused2, u32 unused3);
void FLDMMDL_RAIL_StayDelete(Mmdl *mmdl, u32 unused1, u32 unused2, u32 unused3);
void FLDMMDL_RAIL_AcquireRailWorkBody(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundInitKind0(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundInitKind1(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundInitKind2(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundInitKind3(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundInitKind4(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundInitKind5(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundInitKind6(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundInitKind7(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundInitKind8(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundInitKind9(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundInitKind10(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundMove(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundDelete(Mmdl *mmdl);
void FLDMMDL_RAIL_WanderInitKind0(Mmdl *mmdl);
void FLDMMDL_RAIL_WanderInitKind9(Mmdl *mmdl);
void FLDMMDL_RAIL_WanderMove(Mmdl *mmdl);
void FLDMMDL_RAIL_WanderDelete(Mmdl *mmdl);
void FLDMMDL_RAIL_ShuttleInit(Mmdl *mmdl);
void FLDMMDL_RAIL_ShuttleMove(Mmdl *mmdl);
void FLDMMDL_RAIL_ShuttleDelete(Mmdl *mmdl);
u32 FLDMMDL_RAIL_DirToRailKey(int dir);
u32 FLDMMDL_RAIL_RailKeyToDir(int key);
int FLDMMDL_RAIL_CheckOutsideHomeArea(Mmdl *mmdl, int homeLine, int homeWidth, RailLocation *loc);
int FLDMMDL_RAIL_GetTableLength(u32 *table, u32 terminator);
int FLDMMDL_RAIL_GetRandomTableEntry(u32 *table, int terminator);
u32 FLDMMDL_RAIL_GetRandomDirOfKind(u32 kind, u32 terminator);
u32 *FLDMMDL_RAIL_GetDirListOfKind(int kind);
void FLDMMDL_RAIL_LookAroundInit(Mmdl *mmdl, u16 kind);
void FLDMMDL_RAIL_LookAroundMoveBody(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundDeleteBody(Mmdl *mmdl);
void FLDMMDL_RAIL_WanderInit(Mmdl *mmdl, u32 kind);
void FLDMMDL_RAIL_WanderMoveBody(Mmdl *mmdl);
void FLDMMDL_RAIL_WanderDeleteBody(Mmdl *mmdl);
void FLDMMDL_RAIL_ShuttleInitBody(Mmdl *mmdl);
void FLDMMDL_RAIL_ShuttleMoveBody(Mmdl *mmdl);
void FLDMMDL_RAIL_ShuttleDeleteBody(Mmdl *mmdl);
/* END mkheaders: generated region */

#endif
