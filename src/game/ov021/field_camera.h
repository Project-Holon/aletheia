#ifndef GAME_OV021_FIELD_CAMERA_H
#define GAME_OV021_FIELD_CAMERA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_camera.c, prototypes copied from their definitions. */

struct G3dCamera;

#include "../ov021/field_camera_types.h"
#include "../sdk_fx.h"
#include "../types.h"

FieldCamera *FIELD_CAMERA_Create(int settingId, int mode, struct G3dCamera *g3dCamera, VecFx32 *targetSrc, u16 heapId);
void FIELD_CAMERA_Delete(FieldCamera *camera);
void FIELD_CAMERA_Main(FieldCamera *camera, u32 arg);
void FIELD_CAMERA_EnterMode(FieldCamera *camera, u32 mode);
u32 FIELD_CAMERA_GetMode(FieldCamera *camera);
void FIELD_CAMERA_SetMode(FieldCamera *camera, u32 mode);
int FIELD_CAMERA_ReloadSetting(FieldCamera *camera);
void FIELD_CAMERA_SetSetting(FieldCamera *camera, u32 settingId);
int FIELD_CAMERA_GetSettingId(FieldCamera *camera);
void FIELD_CAMERA_LoadSetting(FieldCamera *camera, const VecFx32 *targetSrc);
void FIELD_CAMERA_ReadSetting(FieldCamera *camera, FieldCameraSetting *out);
void FIELD_CAMERA_PullTargetFromTrace(FieldCamera *camera);
int FIELD_CAMERA_PullEyeFromTrace(FieldCamera *camera);
void FIELD_CAMERA_CalcOffsetPoint(VecFx32 *base, VecFx32 *out, int yaw, int pitch, int distance);
void FIELD_CAMERA_SolveTargetMode(FieldCamera *camera);
void FIELD_CAMERA_SolveEyeMode(FieldCamera *camera);
void FIELD_CAMERA_SolveFreeMode(FieldCamera *camera);
void FIELD_CAMERA_ApplyToG3d(FieldCamera *camera);
void FIELD_CAMERA_UpdateMode(FieldCamera *camera, u32 arg);
void FIELD_CAMERA_UpdateTargetMode(FieldCamera *camera, u32 arg);
void FIELD_CAMERA_UpdateEyeMode(FieldCamera *camera, u32 arg);
void FIELD_CAMERA_UpdateFreeMode(FieldCamera *camera, u32 arg);
void FIELD_CAMERA_ClearEyeTrace(FieldCamera *camera);
void FIELD_CAMERA_ClearTargetTrace(FieldCamera *camera);
void FIELD_CAMERA_ClearAngles(FieldCamera *camera);
void FIELD_CAMERA_CalcAngles(VecFx32 *vec, u16 *pitch, u16 *yaw, int *distance);
void FIELD_CAMERA_SetAnglesFromVector(FieldCamera *camera, VecFx32 *vec);
void FIELD_CAMERA_PrepareTargetMode(FieldCamera *camera);
void FIELD_CAMERA_PrepareEyeMode(FieldCamera *camera);
void FIELD_CAMERA_SolveTrackMode(FieldCamera *camera);
void FIELD_CAMERA_UpdateViewAngles(FieldCamera *camera, VecFx32 *targetPos, VecFx32 *eyePos);
void FIELD_CAMERA_RefineAngles(VecFx32 *vec, u16 yaw, u16 pitch, u16 *outYaw, u16 *outPitch);
struct G3dCamera *FIELD_CAMERA_GetG3dCamera(FieldCamera *camera);
void FIELD_CAMERA_SetTraceTarget(FieldCamera *camera, const VecFx32 *target);
void FIELD_CAMERA_StopTargetTrace(FieldCamera *camera);
const VecFx32 *FIELD_CAMERA_GetTraceTarget(FieldCamera *camera);
void FIELD_CAMERA_ResumeTargetTrace(FieldCamera *camera);
void FIELD_CAMERA_SetG3dNear(FieldCamera *camera, u32 scale, ...);
void FIELD_CAMERA_SetG3dFar(FieldCamera *camera, u32 roll, ...);
void FIELD_CAMERA_SetTarget(FieldCamera *camera, const VecFx32 *target);
void FIELD_CAMERA_GetTargetRaw(FieldCamera *camera, VecFx32 *out);
void FIELD_CAMERA_GetTargetShift(FieldCamera *camera, VecFx32 *out);
void FIELD_CAMERA_SetTargetShift(FieldCamera *camera, const VecFx32 *shift);
void FIELD_CAMERA_GetEyeRaw(FieldCamera *camera, VecFx32 *out);
void FIELD_CAMERA_SetEyeRaw(FieldCamera *camera, const VecFx32 *eye);
void FIELD_CAMERA_SetEyeShift(FieldCamera *camera, const VecFx32 *shift);
void FIELD_CAMERA_SetG3dUp(FieldCamera *camera, const VecFx32 *up);
void FIELD_CAMERA_GetG3dUp(FieldCamera *camera, VecFx32 *out);
u16 FIELD_CAMERA_GetPitch(FieldCamera *camera);
void FIELD_CAMERA_SetPitch(FieldCamera *camera, u16 pitch);
u16 *FIELD_CAMERA_GetViewPitchPtr(FieldCamera *camera);
u16 FIELD_CAMERA_GetYaw(FieldCamera *camera);
void FIELD_CAMERA_SetYaw(FieldCamera *camera, u32 yaw);
u16 *FIELD_CAMERA_GetViewYawPtr(FieldCamera *camera);
u32 FIELD_CAMERA_GetDistance(FieldCamera *camera);
void FIELD_CAMERA_SetDistance(FieldCamera *camera, u32 distance);
void FIELD_CAMERA_GetVectorAngles(VecFx32 *vec, u16 *pitch, u16 *yaw, int *distance);
void FIELD_CAMERA_SetFov(FieldCamera *camera, u16 fov);
void FIELD_CAMERA_StepDelay(FieldCameraDelay *delay, VecFx32 *target, VecFx32 *eye, VecFx32 *outTarget, VecFx32 *outEye);
void FIELD_CAMERA_CreateDelay(int count, u32 delayFrames, u32 flags, u32 heapId, FieldCamera *camera);
void FIELD_CAMERA_DeleteDelay(FieldCamera *camera);
void FIELD_CAMERA_ApplyDelayToG3d(FieldCamera *camera);
void FIELD_CAMERA_StopDelayLog(FieldCameraDelay *delay);
void FIELD_CAMERA_RestartDelay(FieldCamera *camera);
void FIELD_CAMERA_EndDelay(FieldCamera *camera);
void FIELD_CAMERA_StopDelay(FieldCamera *camera, int unused);
u32 FIELD_CAMERA_IsDelayEnabled(FieldCamera *camera);
int FIELD_CAMERA_HasDelay(FieldCamera *camera);
void FIELD_CAMERA_CopyAreas(FieldCamera *camera, FieldCameraAreaSet *set);
void FIELD_CAMERA_ClearAreas(FieldCamera *camera);
void FIELD_CAMERA_LoadAreas(FieldCamera *camera, u32 areaId, u32 heapId);
void FIELD_CAMERA_GetTarget(FieldCamera *camera, VecFx32 *out);
void FIELD_CAMERA_GetEye(FieldCamera *camera, VecFx32 *out);
void FIELD_CAMERA_SetAreasEnabled(FieldCamera *camera, u32 enabled);
unsigned char FIELD_CAMERA_GetAreasEnabled(FieldCamera *camera);
void FIELD_CAMERA_ApplyTargetArea(FieldCameraArea *area, VecFx32 *point);
void FIELD_CAMERA_ApplyEyeArea(FieldCameraArea *area, VecFx32 *point);
int FIELD_CAMERA_AreaKeepInBox(const FieldCameraArea *area, VecFx32 *in, VecFx32 *out);
int FIELD_CAMERA_AreaKeepInRing(const FieldCameraArea *area, VecFx32 *in, VecFx32 *out);
int FIELD_CAMERA_AreaKeepOutBox(FieldCameraArea *area, VecFx32 *in, VecFx32 *out);
void FIELD_CAMERA_TakeView(FieldCamera *camera, FieldCameraView *view);
void FIELD_CAMERA_TakeViewConstrained(FieldCamera *camera, FieldCameraView *view);
void FIELD_CAMERA_PushState(FieldCamera *camera);
void FIELD_CAMERA_PushStateConstrained(FieldCamera *camera);
void FIELD_CAMERA_PopState(FieldCamera *camera);
void FIELD_CAMERA_SetMoveGoal(FieldCamera *camera, FieldCameraMoveRequest *request, u16 frames);
void FIELD_CAMERA_StartMove(FieldCamera *camera, FieldCameraMoveRequest *request, u16 frames);
void FIELD_CAMERA_StartMoveConstrained(FieldCamera *camera, FieldCameraMoveRequest *request, u16 frames);
void FIELD_CAMERA_StartFreeMove(FieldCamera *camera, VecFx32 *eyeGoal, VecFx32 *targetGoal, FieldCameraMoveChannels *channels, u16 frames);
void FIELD_CAMERA_StartMoveToSaved(FieldCamera *camera, FieldCameraMoveChannels *channels, u16 frames);
void FIELD_CAMERA_StartMoveToSetting(FieldCamera *camera, u16 frames);
void FIELD_CAMERA_UpdateMove(struct FieldCamera *camera, unsigned int unused1);
void FIELD_CAMERA_UpdateFreeMove(struct FieldCamera *camera, unsigned int unused1);
void FIELD_CAMERA_LerpVec(VecFx32 *from, VecFx32 *to, u16 frames, u16 frame, VecFx32 *out);
int FIELD_CAMERA_LerpFx32(int *from, int *to, int frames, int frame);
u16 FIELD_CAMERA_LerpAngle(u16 *from, u16 *to, s32 frames, s32 frame);
void FIELD_CAMERA_ClearMoveCallback(FieldCamera *camera);
int FIELD_CAMERA_IsMoving(FieldCamera *camera);
FieldCameraView *FIELD_CAMERA_GetMoveGoal(FieldCamera *camera);
/* END mkheaders: generated region */

#endif
