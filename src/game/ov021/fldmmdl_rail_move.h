#ifndef GAME_OV021_FLDMMDL_RAIL_MOVE_H
#define GAME_OV021_FLDMMDL_RAIL_MOVE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldmmdl_rail_move.c, prototypes copied from their definitions. */

#include "../ov010/fldmmdl_types.h"
#include "../arm9/zonedata_types.h"
#include "../types.h"

void FLDMMDL_RAIL_MOVE_InitMove(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_UpdateMove(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_GetLocationAttr(Mmdl *mmdl, RailLocation *location);
u32 FLDMMDL_RAIL_MOVE_GetDirByAngle(Mmdl *mmdl, int angle);
int FLDMMDL_RAIL_MOVE_CheckMoveStart(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_UpdateAttrBeforeMove(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_ProcMoveStartFirst(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_ProcMoveStartSecond(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_ProcMoveEnd(Mmdl *mmdl);
u32 FLDMMDL_RAIL_MOVE_UpdateCurrentAttr(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_MapAttrProcMoveStartFirst(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_MapAttrProcMoveStartSecond(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_MapAttrProcMoveStartJumpSecond(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_MapAttrProcMoveEnd(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_MapAttrProcMoveEndJump(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_MapAttrGrassProc0(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
void FLDMMDL_RAIL_MOVE_MapAttrGrassProc12(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
void FLDMMDL_RAIL_MOVE_MapAttrFootMarkProc1(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
void FLDMMDL_RAIL_MOVE_MapAttrShadowProc0(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
void FLDMMDL_RAIL_MOVE_MapAttrShadowProc12(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
void FLDMMDL_RAIL_MOVE_MapAttrEndNopProc(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
int FLDMMDL_RAIL_MOVE_MapAttrGroundSmokeProc2(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
void FLDMMDL_RAIL_MOVE_MapAttrReflectProc01(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
void FLDMMDL_RAIL_MOVE_MapAttrReflectProc2(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
u32 FLDMMDL_RAIL_MOVE_GetFldEffCtrl(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcEnd(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcNextStep(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_AcDirSet(Mmdl *mmdl, u32 dir);
int FLDMMDL_RAIL_MOVE_AcDirU0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcDirD0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcDirL0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcDirR0(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_AcWalkSet(Mmdl *mmdl, u32 dir, u32 frames, u16 drawStatus);
int FLDMMDL_RAIL_MOVE_AcWalk1(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkEnd(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkU16F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkD16F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkL16F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkR16F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkU8F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkD8F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkL8F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkR8F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkU4F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkD4F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkL4F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkR4F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkU2F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkD2F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkL2F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkR2F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcDashU4F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcDashD4F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcDashL4F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcDashR4F0(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_AcStayWalkSet(Mmdl *mmdl, u32 dir, u16 frames, u16 drawStatus);
int FLDMMDL_RAIL_MOVE_AcStayWalk1(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkU32F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkD32F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkL32F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkR32F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkU16F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkD16F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkL16F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkR16F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkU8F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkD8F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkL8F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkR8F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkU2F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkD2F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkL2F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkR2F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkU4F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkD4F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkL4F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkR4F0(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_AcJumpSetSe(Mmdl *mmdl, u32 dir, u32 speed, u8 frames, u16 drawStatus, s16 heightTable, u16 heightStep, u32 seNo);
void FLDMMDL_RAIL_MOVE_AcJumpSet(Mmdl *mmdl, u32 dir, u32 speed, u8 frames, u16 drawStatus, s16 heightTable, u16 heightStep);
int FLDMMDL_RAIL_MOVE_AcJump1(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcJumpU8F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcJumpD8F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcJumpL8F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcJumpR8F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcJumpU16F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcJumpD16F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcJumpL16F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcJumpR16F0(Mmdl *mmdl);
/* END mkheaders: generated region */

#endif
