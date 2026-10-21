#ifndef GAME_OV021_FIELD_RAIL_H
#define GAME_OV021_FIELD_RAIL_H

/* Kept by hand: mkheaders cannot read __restrict, and the definition needs it for the load/store order. */
#include "../ov021/field_rail_types.h"
void FIELD_RAIL_WORK_GetLocation(RailWork *work, RailLocation * __restrict outLocation);

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_rail.c, prototypes copied from their definitions. */

struct FieldCamera;

#include "../ov021/field_rail_types.h"
#include "../types.h"
#include "../sdk_fx.h"
#include "../arm9/zonedata_types.h"

RailManager *FIELD_RAIL_Create(u16 heapId, u32 workMax, struct FieldCamera *fieldCamera);
void FIELD_RAIL_Delete(RailManager *manager);
void FIELD_RAIL_SetSetting(RailManager *manager, FieldRailSetting *setting);
u32 FIELD_RAIL_ClearSetting(RailManager *manager);
RailWork *FIELD_RAIL_ActivateFreeWork(RailManager *manager);
int FIELD_RAIL_ReleaseWork(RailManager *manager, RailWork *work);
void FIELD_RAIL_SetFocusWork(RailManager *manager, RailWork *work);
void FIELD_RAIL_ClearFocusWork(RailManager *manager);
void FIELD_RAIL_GetFocusPos(RailManager *manager, VecFx32 *outPos);
void FIELD_RAIL_Update(RailManager *manager);
int FIELD_RAIL_UpdateCamera(RailManager *manager, int force);
int FIELD_RAIL_FindSegmentLocation(RailManager *manager, const VecFx32 *startPos, const VecFx32 *endPos, RailLocation *outLocation, VecFx32 *outPos);
void FIELD_RAIL_SetLineEnable(RailManager *manager, int lineIndex, int enable);
int FIELD_RAIL_GetUnitScale(RailManager *manager);
void FIELD_RAIL_MakeLineLocation(RailManager *manager, FieldRailSetting *setting, u16 railIndex, u16 lineGrid, u16 widthPos, RailLocation *outLocation);
int FIELD_RAIL_StepLocation(RailManager *manager, RailLocation *location, u16 key, VecFx32 *outPos);
int FIELD_RAIL_TryStepLocation(RailManager *manager, const RailLocation *location, u32 key, RailLocation *outLocation);
void FIELD_RAIL_GetLocationPos(RailManager *manager, RailLocation *location, VecFx32 *outPos);
int FIELD_RAIL_GetLocationWidthGrid(RailManager *manager, RailLocation *location);
void FIELD_RAIL_UpdateCameraAtLocation(RailManager *manager, const RailLocation *location);
int FIELD_RAIL_WORK_IsLocationValid(RailWork *work, RailLocation *location);
u8 FIELD_RAIL_WORK_QueryStep(RailWork *work, u32 key, RailLocation *outLocation, VecFx32 *outPos);
void FIELD_RAIL_WORK_GetPrevPos(RailWork *work, VecFx32 *outPos);
void FIELD_RAIL_WORK_SetLocation(RailWork *work, const RailLocation *location);
void FIELD_RAIL_WORK_GetPos(RailWork *work, VecFx32 *outPos);
u8 FIELD_RAIL_WORK_GetLastKey(RailWork *work);
u8 FIELD_RAIL_WORK_IsMoving(RailWork *work);
u8 FIELD_RAIL_WORK_HasStepped(RailWork *work);
void FIELD_RAIL_WORK_GetStepVector(RailWork *work, s16 *outStep);
u32 FIELD_RAIL_WORK_GetLineKey(RailWork *work);
int FIELD_RAIL_WORK_StartStep(RailWork *work, u32 speedIndex, u32 stepKey);
void FIELD_RAIL_WORK_UpdateStep(RailWork *work);
struct FieldCamera *FIELD_RAIL_GetFieldCamera(RailManager *manager);
RailWork *FIELD_RAIL_GetFocusWork(RailManager *manager);
RailPoint *FIELD_RAIL_GetPoint(RailManager *manager, u32 pointIndex);
RailLine *FIELD_RAIL_GetLine(RailManager *manager, u32 lineIndex);
RailLinePos *FIELD_RAIL_GetLinePos(RailManager *manager, int linePosIndex);
u32 FIELD_RAIL_GetUnitScaleRaw(RailManager *manager);
RailWork *FIELD_RAIL_GetProbeWork(RailManager *manager);
void FIELD_RAIL_ClampLocation(const RailManager *manager, const RailLocation *location, RailLocation *outLocation);
u16 FIELD_RAIL_WORK_GetMode(RailWork *work);
RailSpot *FIELD_RAIL_WORK_GetSpot(RailWork *work);
u32 FIELD_RAIL_WORK_GetLineOffset(RailWork *work);
u32 FIELD_RAIL_WORK_GetLineEndOffset(RailWork *work);
u32 FIELD_RAIL_WORK_GetWidthOffsetRaw(RailWork *work);
u32 FIELD_RAIL_WORK_GetWidthLimit(RailWork *work);
u32 FIELD_RAIL_WORK_GetUnitScale(RailWork *work);
RailCamera *FIELD_RAIL_WORK_GetCamera(RailWork *work);
void FIELD_RAIL_WORK_GetCentrePos(RailWork *work, VecFx32 *outPos);
void FIELD_RAIL_WORK_GetPosAtLineOffset(RailWork *work, int lineOffset, VecFx32 *outPos);
RailPoint *FIELD_RAIL_WORK_GetStartPoint(RailWork *work);
RailPoint *FIELD_RAIL_WORK_GetEndPoint(RailWork *work);
RailLinePos *FIELD_RAIL_WORK_GetLinePos(RailWork *work);
RailCamera *FIELD_RAIL_WORK_GetPointCamera(RailWork *work, RailPoint *point);
int FIELD_RAIL_RoundToGrid(int x);
int FIELD_RAIL_IsPosNear(const s32 *a, const s32 *b, s32 r);
void FIELD_RAIL_WORK_GetLocationParts(RailWork *work, u16 *outRailIndex, u16 *outLineGrid, u16 *outWidthGrid);
void FIELD_RAIL_WORK_SetLineLocation(RailWork *work, u32 railIndex, u32 lineGrid, int widthPos);
RailLine *FIELD_RAIL_POINT_FindLine(RailPoint *point, u32 key, FieldRailSetting *setting, RailClosedLines *closedLines, int checkClosed);
int FIELD_RAIL_WORK_TryEnterLine(RailWork *work, RailLine *line, u32 key, int lineOffset, int widthOffset, int lineLength, int widthMax);
void FIELD_RAIL_WORK_EnterLine(RailWork *work, RailLine *line, u32 key, u32 lineOffset, u32 widthOffset, u32 lineEnd, u32 widthLimit);
int FIELD_RAIL_LINE_StartsAtPoint(FieldRailSetting *setting, RailLine *line, RailPoint *point);
int FIELD_RAIL_LINE_EndsAtPoint(FieldRailSetting *setting, RailLine *line, RailPoint *point);
void FIELD_RAIL_GetNeighbourLimits(FieldRailSetting *setting, const RailLine *line, int *outLengthLimit, int *outWidthLimit, RailClosedLines *closedLines, int unitScale);
void FIELD_RAIL_SETTING_Clear(FieldRailSetting *setting);
void FIELD_RAIL_SETTING_Copy(FieldRailSetting *dst, const FieldRailSetting *src);
RailPoint *FIELD_RAIL_SETTING_GetPoint(FieldRailSetting *setting, u32 pointIndex);
RailLine *FIELD_RAIL_SETTING_GetLine(FieldRailSetting *setting, u32 lineIndex);
RailCamera *FIELD_RAIL_SETTING_GetCamera(FieldRailSetting *setting, u32 cameraIndex);
RailLinePos *FIELD_RAIL_SETTING_GetLinePos(FieldRailSetting *setting, u32 linePosIndex);
RailCameraFunc FIELD_RAIL_SETTING_GetCameraFunc(FieldRailSetting *setting, u32 funcIndex);
RailLinePosFunc FIELD_RAIL_SETTING_GetLinePosFunc(FieldRailSetting *setting, u32 funcIndex);
RailLineFunc FIELD_RAIL_SETTING_GetLineFunc(FieldRailSetting *setting, u32 funcIndex);
int FIELD_RAIL_WORK_Advance(RailWork *work, int key, int step);
void FIELD_RAIL_WORK_Init(RailWork *work, FieldRailSetting *setting, RailManager *manager);
void FIELD_RAIL_WORK_Reset(RailWork *work, FieldRailSetting *setting);
u16 FIELD_RAIL_WORK_IsInUse(RailWork *work);
int FIELD_RAIL_WORK_IsActive(RailWork *work);
RailCamera *FIELD_RAIL_WORK_GetSpotCamera(RailWork *work);
void FIELD_RAIL_WORK_GetSpotPos(RailWork *work, VecFx32 *outPos);
void FIELD_RAIL_WORK_GetLocationFromSpot(const RailWork *work, RailLocation *outLocation);
int FIELD_RAIL_LINE_GetLength(const RailLine *line, int unitScale, const FieldRailSetting *setting);
int FIELD_RAIL_LINE_GetWidthAt(const RailLine *line, u32 offset, u32 length, const FieldRailSetting *setting);
int FIELD_RAIL_WORK_ClampWidth(RailWork *work, RailLine *line, u32 lineEnd, int key);
int FIELD_RAIL_ProbeStep(RailManager *manager, RailLocation *location, u32 key, int steps, VecFx32 *outPos);
int FIELD_RAIL_KEY_Opposite(int key);
int FIELD_RAIL_KEY_TurnRight(int key);
int FIELD_RAIL_KEY_TurnLeft(int key);
RailClosedLines *FIELD_RAIL_CLOSED_Clear(RailClosedLines *closedLines);
void FIELD_RAIL_CLOSED_Add(RailClosedLines *closedLines, u16 lineIndex);
void FIELD_RAIL_CLOSED_Remove(RailClosedLines *closedLines, u16 lineIndex);
int FIELD_RAIL_CLOSED_Contains(RailClosedLines *closedLines, u16 lineIndex);
int FIELD_RAIL_CLOSED_ContainsLine(RailClosedLines *closedLines, RailLine *line, FieldRailSetting *setting);
RailLine *FIELD_RAIL_GetOpenLine(RailClosedLines *closedLines, FieldRailSetting *setting, u32 lineIndex);
void FIELD_RAIL_WORK_MoveClamped(RailClosedLines *closedLines, RailWork *work, int lineDelta, int widthDelta, int key);
int FIELD_RAIL_IsLocationInLine(RailClosedLines *closedLines, RailLine *line, int lineOffset, int widthOffset, FieldRailSetting *setting, int unitScale);
u32 FIELD_RAIL_POINT_GetLineKey(RailPoint *point, RailLine *line, FieldRailSetting *setting);
int FIELD_RAIL_LINE_IsConsistent(RailLine *line, FieldRailSetting *setting);
int FIELD_RAIL_POINT_IsConsistent(RailPoint *point, FieldRailSetting *setting);
void FIELD_RAIL_DebugPrintPos(const char *label, VecFx32 *pos);
void FIELD_RAIL_POINT_DebugPrint(const char *prefix, RailPoint *point, const char *suffix);
void FIELD_RAIL_WORK_DebugCheck(RailWork *work);
int FIELD_RAIL_SETTING_GetPointIndex(FieldRailSetting *setting, RailPoint *point);
int FIELD_RAIL_SETTING_GetLineIndex(FieldRailSetting *setting, RailLine *line);
int FIELD_RAIL_IntersectSegmentPlane(VecFx32 *dirA, VecFx32 *dirB, VecFx32 *planePoint, VecFx32 *segStart, VecFx32 *segEnd, VecFx32 *out);
void FIELD_RAIL_SlerpDir(VecFx32 *out, VecFx32 *from, VecFx32 *to, int t);
void FIELD_RAIL_SlerpVec(VecFx32 *out, VecFx32 *from, VecFx32 *to, int t);
void FIELD_RAIL_LINEPOS_Straight(RailWork *work, VecFx32 *outPos);
void FIELD_RAIL_LINEPOS_ArcFlat(RailWork *work, VecFx32 *outPos);
void FIELD_RAIL_LINEPOS_Arc(RailWork *work, VecFx32 *outPos);
int FIELD_RAIL_LINEFUNC_Straight(int lineIndex, RailManager *manager, const VecFx32 *pos, RailLocation *outLocation, VecFx32 *outPos);
int FIELD_RAIL_LINEFUNC_Arc(int lineIndex, RailManager *manager, const VecFx32 *pos, RailLocation *outLocation, VecFx32 *outPos);
void FIELD_RAIL_CAMERA_EyeOffsetFromFocus(RailManager *manager);
void FIELD_RAIL_CAMERA_FixedAngle(RailManager *manager);
void FIELD_RAIL_CAMERA_FixedAngleAtCentre(RailManager *manager);
void FIELD_RAIL_CAMERA_BlendAngles(RailManager *manager);
void FIELD_RAIL_CAMERA_BlendAnglesAtFocus(RailManager *manager);
void FIELD_RAIL_CAMERA_BlendAnglesAtCentre(RailManager *manager);
void FIELD_RAIL_CAMERA_FixedEyeTarget(RailManager *manager);
void FIELD_RAIL_CAMERA_BlendEyeTarget(RailManager *manager);
void FIELD_RAIL_CAMERA_BlendOrbit(RailManager *manager);
void FIELD_RAIL_CAMERA_Orbit(RailManager *manager);
void FIELD_RAIL_CAMERA_SetOrbit(RailManager *manager, u16 pitch, int distance, VecFx32 *point);
void FIELD_RAIL_CAMERA_OrbitMovingPoint(RailManager *manager);
void FIELD_RAIL_CAMERA_YawFromPoint(RailManager *manager);
void FIELD_RAIL_CAMERA_FollowHeading(RailManager *manager);
void FIELD_RAIL_CAMERA_FollowHeadingSlope(RailManager *manager);
void FIELD_RAIL_CAMERA_FollowHeadingAtCentre(RailManager *manager);
void FIELD_RAIL_CAMERA_ApplyLineStart(RailManager *manager);
void FIELD_RAIL_CAMERA_ApplyLineEnd(RailManager *manager);
void FIELD_RAIL_CAMERA_FixedAngleShift(RailManager *manager);
void FIELD_RAIL_CAMERA_FixedAngleShiftAtFocus(RailManager *manager);
void FIELD_RAIL_CAMERA_BlendAnglesShift(RailManager *manager);
int FIELD_RAIL_ProjectOnSegment(RailPoint *startPoint, RailPoint *endPoint, const VecFx32 *pos, VecFx32 *outHit, fx32 *outDist, VecFx32 *outAxis);
void FIELD_RAIL_CAMERA_ApplyPoint(RailManager *manager, RailWork *work, RailPoint *point);
/* END mkheaders: generated region */

#endif
