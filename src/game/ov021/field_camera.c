/*
 * file:     field_camera.c
 * unit:     yes
 * function: FIELD_CAMERA_Create, FIELD_CAMERA_Delete, FIELD_CAMERA_Main, FIELD_CAMERA_EnterMode, FIELD_CAMERA_GetMode, FIELD_CAMERA_SetMode, FIELD_CAMERA_ReloadSetting, FIELD_CAMERA_SetSetting, FIELD_CAMERA_GetSettingId, FIELD_CAMERA_LoadSetting, FIELD_CAMERA_ReadSetting, FIELD_CAMERA_PullTargetFromTrace, FIELD_CAMERA_PullEyeFromTrace, FIELD_CAMERA_CalcOffsetPoint, FIELD_CAMERA_SolveTargetMode, FIELD_CAMERA_SolveEyeMode, FIELD_CAMERA_SolveFreeMode, FIELD_CAMERA_ApplyToG3d, FIELD_CAMERA_UpdateMode, FIELD_CAMERA_UpdateTargetMode, FIELD_CAMERA_UpdateEyeMode, FIELD_CAMERA_UpdateFreeMode, FIELD_CAMERA_ClearEyeTrace, FIELD_CAMERA_ClearTargetTrace, FIELD_CAMERA_ClearAngles, FIELD_CAMERA_CalcAngles, FIELD_CAMERA_SetAnglesFromVector, FIELD_CAMERA_PrepareTargetMode, FIELD_CAMERA_PrepareEyeMode, FIELD_CAMERA_SolveTrackMode, FIELD_CAMERA_UpdateViewAngles, FIELD_CAMERA_RefineAngles, FIELD_CAMERA_GetG3dCamera, FIELD_CAMERA_SetTraceTarget, FIELD_CAMERA_StopTargetTrace, FIELD_CAMERA_GetTraceTarget, FIELD_CAMERA_ResumeTargetTrace, FIELD_CAMERA_SetG3dNear, FIELD_CAMERA_SetG3dFar, FIELD_CAMERA_SetTarget, FIELD_CAMERA_GetTargetRaw, FIELD_CAMERA_GetTargetShift, FIELD_CAMERA_SetTargetShift, FIELD_CAMERA_GetEyeRaw, FIELD_CAMERA_SetEyeRaw, FIELD_CAMERA_SetEyeShift, FIELD_CAMERA_SetG3dUp, FIELD_CAMERA_GetG3dUp, FIELD_CAMERA_GetPitch, FIELD_CAMERA_SetPitch, FIELD_CAMERA_GetViewPitchPtr, FIELD_CAMERA_GetYaw, FIELD_CAMERA_SetYaw, FIELD_CAMERA_GetViewYawPtr, FIELD_CAMERA_GetDistance, FIELD_CAMERA_SetDistance, FIELD_CAMERA_GetVectorAngles, FIELD_CAMERA_SetFov, FIELD_CAMERA_StepDelay, FIELD_CAMERA_CreateDelay, FIELD_CAMERA_DeleteDelay, FIELD_CAMERA_ApplyDelayToG3d, FIELD_CAMERA_StopDelayLog, FIELD_CAMERA_RestartDelay, FIELD_CAMERA_EndDelay, FIELD_CAMERA_StopDelay, FIELD_CAMERA_IsDelayEnabled, FIELD_CAMERA_HasDelay, FIELD_CAMERA_CopyAreas, FIELD_CAMERA_ClearAreas, FIELD_CAMERA_LoadAreas, FIELD_CAMERA_GetTarget, FIELD_CAMERA_GetEye, FIELD_CAMERA_SetAreasEnabled, FIELD_CAMERA_GetAreasEnabled, FIELD_CAMERA_ApplyTargetArea, FIELD_CAMERA_ApplyEyeArea, FIELD_CAMERA_AreaKeepInBox, FIELD_CAMERA_AreaKeepInRing, FIELD_CAMERA_AreaKeepOutBox, FIELD_CAMERA_TakeView, FIELD_CAMERA_TakeViewConstrained, FIELD_CAMERA_PushState, FIELD_CAMERA_PushStateConstrained, FIELD_CAMERA_PopState, FIELD_CAMERA_SetMoveGoal, FIELD_CAMERA_StartMove, FIELD_CAMERA_StartMoveConstrained, FIELD_CAMERA_StartFreeMove, FIELD_CAMERA_StartMoveToSaved, FIELD_CAMERA_StartMoveToSetting, FIELD_CAMERA_UpdateMove, FIELD_CAMERA_UpdateFreeMove, FIELD_CAMERA_LerpVec, FIELD_CAMERA_LerpFx32, FIELD_CAMERA_LerpAngle, FIELD_CAMERA_ClearMoveCallback, FIELD_CAMERA_IsMoving, FIELD_CAMERA_GetMoveGoal
 * address:  0x0218E018
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_msgbg.c at 0x0218E018: field_camera.c __FILE__ anchor; the functions before it are called only from field_g3d_mapper.c.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   VEC_Add  0x0207C9D0  arm
 *   FX_SinCosTable_     0x020A1B38  data   a2
 *   gFieldCameraFileName     0x021DDA28  data  ov021  a4
 *   G3D_CAMERA_GetMode  0x02048B78  arm
 *   G3D_CAMERA_GetFovyCos  0x02048B88  arm
 *   FX_AcosIdx  0x0207D184  arm
 *   gFieldCameraEnterModeFuncs  0x021DDA0C  data  ov021  a4
 *   gFieldCameraPrepareModeFuncs  0x021DDA00  data  ov021  a4
 *   G3D_SYSTEM_SetSwapBuffersMode  0x02046BE0  arm
 *   G3D_CAMERA_SetFovySin  0x02048B80  arm
 *   G3D_CAMERA_SetFovyCos  0x02048B94  arm
 *   FX_SinCosTable_   0x020A1B38  data
 *   ARC_TOOL_GetHandleMemberSize  0x020493D4  arm
 *   ARC_TOOL_ReadHandleMemberRange  0x0204944C  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   VEC_MultAdd  0x0207CEE4  arm
 *   G3D_CAMERA_SetCamTarget  0x02048B44  arm
 *   G3D_CAMERA_SetEye  0x02048AFC  arm
 *   gFieldCameraUpdateModeFuncs  0x021D3E44  data  ov021  a4
 *   VEC_Mag  0x0207CBD0  arm
 *   FX_Atan2Idx  0x0207CFB8  arm
 *   VEC_Subtract  0x0207CA00  arm
 *   VEC_DotProduct  0x0207CA68  arm
 *   gFieldCameraUpVec     0x021D3E2C  data   ov021  a4
 *   G3D_CAMERA_SetCamUp  0x02048B20  arm
 *   G3D_CAMERA_GetCamUp  0x02048B0C  arm
 *   FX_SinCosTable_  0x020A1B38  data
 *   G3D_CAMERA_GetCamTarget  0x02048B30  arm
 *   G3D_CAMERA_GetEye  0x02048AE8  arm
 *   MI_CpuCopy8   0x02082D44  arm
 *   ARC_UTIL_LoadHandleMember  0x0204A380  arm
 *   gFieldCameraAreaFuncs  0x021DDA18  data  ov021  a4
 *   VEC_Subtract     0x0207CA00  arm
 *   VEC_Mag          0x0207CBD0  arm
 *   FX_Modf          0x0207D14C  arm
 *   VEC_Normalize    0x0207CCA4  arm
 *   VEC_CrossProduct 0x0207CAE8  arm
 *   VEC_DotProduct   0x0207CA68  arm
 *   FX_AcosIdx       0x0207D184  arm
 *   gFieldCameraRingRefVec       0x021D3E38  data   a4
 *   G3D_CAMERA_SetFar            0x02048B6C  arm
 *   G3D_CAMERA_SetNear           0x02048B60  arm
 *   _fadd                        0x0209C95C  arm
 *   _ffix                        0x0209C494  arm
 *   _fflt                        0x0209BDBC  arm
 *   _fsub                        0x0209CB8C  arm
 */
#include "field_camera_types.h"

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define FX_F32_TO_FX32(x) \
    ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))

#include "../types.h"

typedef struct { s16 x, y, z; } VecS16;

typedef void (*FieldCameraEnterFunc)(FieldCamera *camera);

#include "../arm9/mi_memory.h"
#include "../arm9/arc_tool.h"
/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define GFL_HEAP_Alloc GFL_HEAP_Alloc_header
#endif
#include "../arm9/gfl_heap_wrap.h"
#ifdef __MWERKS__
#undef GFL_HEAP_Alloc
extern void * GFL_HEAP_Alloc(u16, u32, u32, const char *, u32);
#endif
#include "../arm9/fx_vec.h"
#include "../arm9/g3d_camera.h"
#include "../arm9/fx_asinacosidx.h"
#include "../arm9/g3d_system.h"
#include "../arm9/fx_atanidx.h"
struct ArcHandle;
#include "../arm9/arc_util.h"
#include "../arm9/fx.h"
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
void FIELD_CAMERA_UpdateMove(FieldCamera *camera);
void FIELD_CAMERA_UpdateFreeMove(FieldCamera *camera);
void FIELD_CAMERA_LerpVec(VecFx32 *from, VecFx32 *to, u16 frames, u16 frame, VecFx32 *out);
int FIELD_CAMERA_LerpFx32(int *from, int *to, int frames, int frame);
u16 FIELD_CAMERA_LerpAngle(u16 *from, u16 *to, s32 frames, s32 frame);
void FIELD_CAMERA_ClearMoveCallback(FieldCamera *camera);
int FIELD_CAMERA_IsMoving(FieldCamera *camera);
FieldCameraView *FIELD_CAMERA_GetMoveGoal(FieldCamera *camera);
extern s16 FX_SinCosTable_[];
extern const char gFieldCameraFileName[];
extern FieldCameraEnterFunc gFieldCameraEnterModeFuncs[];
extern FieldCameraEnterFunc gFieldCameraPrepareModeFuncs[];
extern s16 FX_SinCosTable_[];
extern FieldCameraUpdateFunc gFieldCameraUpdateModeFuncs[];
extern VecFx32 gFieldCameraUpVec;
extern s16 FX_SinCosTable_[];
extern FieldCameraAreaFunc gFieldCameraAreaFuncs[];
extern VecFx32 gFieldCameraRingRefVec;

/* Creates the camera work: loads setting 'settingId', binds it to targetSrc and sets up the delay log. */
FieldCamera *FIELD_CAMERA_Create(int settingId, int mode, struct G3dCamera *g3dCamera, VecFx32 *targetSrc, u16 heapId)
{
    int fovSin;
    FieldCamera *camera = GFL_HEAP_Alloc(heapId, 0x1b0, 1, gFieldCameraFileName, 0x80);

    camera->settingId = settingId;
    camera->mode = mode;
    camera->g3dCamera = g3dCamera;
    camera->traceEye = 0;
    camera->heapId = heapId;
    camera->eyeRaw.x = 0;
    camera->eyeRaw.y = 0;
    camera->eyeRaw.z = 0;
    camera->targetRaw.x = 0;
    camera->targetRaw.y = 0;
    camera->targetRaw.z = 0;
    camera->lastSetTarget.x = 0;
    camera->lastSetTarget.y = 0;
    camera->lastSetTarget.z = 0;
    camera->eyeShift.x = 0;
    camera->eyeShift.y = 0;
    camera->eyeShift.z = 0;
    camera->yaw = 0;
    camera->pitch = 0;
    camera->distance = 0x78;
    camera->areasEnabled = 1;
    if (G3D_CAMERA_GetMode(g3dCamera) == 0) {
        G3D_CAMERA_GetFovyCos(g3dCamera, (unsigned int *)(&fovSin));
        camera->fov = FX_AcosIdx(fovSin);
    }
    camera->settingArc = ARC_TOOL_CreateHandle(0x3c, camera->heapId);
    camera->areaArc = ARC_TOOL_CreateHandle(0x6c, camera->heapId);
    camera->areaId = 0xffff;
    FIELD_CAMERA_LoadSetting(camera, targetSrc);
    FIELD_CAMERA_CreateDelay(7, 6, 2, heapId, camera);
    camera->motion.callback = 0;
    return camera;
}

void FIELD_CAMERA_Delete(FieldCamera *camera)
{
    ARC_TOOL_DeleteHandle(camera->settingArc);
    ARC_TOOL_DeleteHandle(camera->areaArc);
    FIELD_CAMERA_DeleteDelay(camera);
    GFL_HEAP_Free(camera);
}

/* Per frame: runs the move callback, then the update of the current mode. */
void FIELD_CAMERA_Main(FieldCamera *camera, u32 arg)
{
    FieldCameraUpdateFunc callback = camera->motion.callback;
    if (callback != 0)
        callback(camera, camera->motion.callbackArg);
    FIELD_CAMERA_UpdateMode(camera, arg);
}

void FIELD_CAMERA_EnterMode(FieldCamera *camera, u32 mode)
{
    camera->mode = mode;
    gFieldCameraEnterModeFuncs[mode](camera);
}

u32 FIELD_CAMERA_GetMode(FieldCamera *camera)
{
    return camera->mode;
}

void FIELD_CAMERA_SetMode(FieldCamera *camera, u32 mode)
{
    if (camera->mode != mode) {
        gFieldCameraPrepareModeFuncs[mode](camera);
        FIELD_CAMERA_EnterMode(camera, mode);
    }
}

/* Goes back to mode FIELD_CAMERA_MODE_TRACK_TARGET and reloads the current setting. */
int FIELD_CAMERA_ReloadSetting(FieldCamera *camera)
{
    FIELD_CAMERA_EnterMode(camera, FIELD_CAMERA_MODE_TRACK_TARGET);
    FIELD_CAMERA_LoadSetting(camera, camera->boundTarget);
    camera->areasEnabled = 1;
    return 1;
}

/* Switches to another camera setting. */
void FIELD_CAMERA_SetSetting(FieldCamera *camera, u32 settingId)
{
    camera->settingId = settingId;
    FIELD_CAMERA_ReloadSetting(camera);
}

int FIELD_CAMERA_GetSettingId(FieldCamera *camera)
{
    return camera->settingId;
}

/* Loads the current setting record into the camera and the G3D camera. */
void FIELD_CAMERA_LoadSetting(FieldCamera *camera, const VecFx32 *targetSrc)
{
    FieldCameraSetting setting;

    FIELD_CAMERA_ReadSetting(camera, &setting);
    camera->distance = setting.distance << 12;
    camera->pitch = setting.pitch;
    camera->yaw = setting.yaw;
    camera->fov = setting.fov;
    FIELD_CAMERA_SetG3dFar(camera, setting.g3dFar);
    FIELD_CAMERA_SetG3dNear(camera, setting.g3dNear);
    switch (setting.projection) {
    case 0:
        G3D_SYSTEM_SetSwapBuffersMode(0, 0);
        break;
    case 1:
        G3D_SYSTEM_SetSwapBuffersMode(0, 1);
        break;
    }
    if (G3D_CAMERA_GetMode(camera->g3dCamera) == 0) {
        G3D_CAMERA_SetFovySin(camera->g3dCamera, FX_SinCosTable_[(camera->fov >> 4) * 2]);
        G3D_CAMERA_SetFovyCos(camera->g3dCamera, FX_SinCosTable_[(camera->fov >> 4) * 2 + 1]);
    }
    if (setting.hasTarget != 0) {
        camera->boundTarget = targetSrc;
        camera->traceTarget = targetSrc;
        camera->targetRaw = *targetSrc;
        camera->targetShift = setting.vec;
    } else {
        camera->boundTarget = 0;
        camera->traceTarget = 0;
        camera->targetRaw = setting.vec;
        camera->targetShift.x = 0;
        camera->targetShift.y = 0;
        camera->targetShift.z = 0;
    }
}

/* Reads the current setting record out of archive 0x3C. */
void FIELD_CAMERA_ReadSetting(FieldCamera *camera, FieldCameraSetting *out)
{
    ARC_TOOL_GetHandleMemberSize((struct ArcHandle *)camera->settingArc, 0);
    ARC_TOOL_ReadHandleMemberRange((struct ArcHandle *)camera->settingArc, 0, sizeof(FieldCameraSetting) * camera->settingId, sizeof(FieldCameraSetting), out);
}

/* Copies the traced target position into the raw target. */
void FIELD_CAMERA_PullTargetFromTrace(FieldCamera *camera)
{
    const VecFx32 *src = camera->traceTarget;
    if (src != 0)
        camera->targetRaw = *src;
}

/* Copies the traced eye position into the raw eye; returns 1 when there is one. */
int FIELD_CAMERA_PullEyeFromTrace(FieldCamera *camera)
{
    const VecFx32 *src = camera->traceEye;
    if (src != 0) {
        camera->eyeRaw = *src;
        return 1;
    }
    return 0;
}

/* Puts out = base + distance * unit(yaw, pitch direction). */
void FIELD_CAMERA_CalcOffsetPoint(VecFx32 *base, VecFx32 *out, int yaw, int pitch, int distance)
{
    VecFx32 dir;
    int yawSin, yawCos;
    s16 pitchSin, pitchCos;
    int idx;

    idx = (yaw >> 4) * 2;
    yawSin = FX_SinCosTable_[idx];
    yawCos = FX_SinCosTable_[idx + 1];
    pitchSin = FX_SinCosTable_[(pitch >> 4) * 2];
    pitchCos = FX_SinCosTable_[(pitch >> 4) * 2 + 1];
    if (pitchCos < 0) pitchCos = -pitchCos;
    if (pitchCos < 0x200) pitchCos = 0x200;
    dir.x = (int)(((long long)yawSin * pitchCos + 0x800) >> 12);
    dir.y = pitchSin;
    dir.z = (int)(((long long)yawCos * pitchCos + 0x800) >> 12);
    VEC_Normalize(&dir, &dir);
    VEC_MultAdd(distance, &dir, base, &dir);
    *out = dir;
}

/* Target mode solve: raw target -> target (areas) -> raw eye -> eye (areas). */
void FIELD_CAMERA_SolveTargetMode(FieldCamera *camera)
{
    int i;

    camera->target = camera->targetRaw;
    if (camera->areasEnabled != 0) {
        for (i = 0; i < camera->areaCount; i++) {
            FIELD_CAMERA_ApplyTargetArea(&camera->areas[i], &camera->target);
        }
    }
    FIELD_CAMERA_CalcOffsetPoint(&camera->target, &camera->eyeRaw, camera->yaw, camera->pitch, camera->distance);
    camera->eye = camera->eyeRaw;
    if (camera->areasEnabled != 0) {
        for (i = 0; i < camera->areaCount; i++) {
            FIELD_CAMERA_ApplyEyeArea(&camera->areas[i], &camera->eye);
        }
    }
}

/* Eye mode solve: mirror of the target mode solve. */
void FIELD_CAMERA_SolveEyeMode(FieldCamera *camera)
{
    int i;

    camera->eye = camera->eyeRaw;
    if (camera->areasEnabled != 0) {
        for (i = 0; i < camera->areaCount; i++) {
            FIELD_CAMERA_ApplyEyeArea(&camera->areas[i], &camera->eye);
        }
    }
    FIELD_CAMERA_CalcOffsetPoint(&camera->eye, &camera->targetRaw, camera->yaw, camera->pitch, camera->distance);
    camera->target = camera->targetRaw;
    if (camera->areasEnabled != 0) {
        for (i = 0; i < camera->areaCount; i++) {
            FIELD_CAMERA_ApplyTargetArea(&camera->areas[i], &camera->target);
        }
    }
}

/* Free mode solve: both raw points go through the areas unchanged. */
void FIELD_CAMERA_SolveFreeMode(FieldCamera *camera)
{
    int i;

    camera->eye = camera->eyeRaw;
    if (camera->areasEnabled != 0) {
        for (i = 0; i < camera->areaCount; i++) {
            FIELD_CAMERA_ApplyEyeArea(&camera->areas[i], &camera->eye);
        }
    }
    camera->target = camera->targetRaw;
    if (camera->areasEnabled != 0) {
        for (i = 0; i < camera->areaCount; i++) {
            FIELD_CAMERA_ApplyTargetArea(&camera->areas[i], &camera->target);
        }
    }
}

/* Sends eye and target (plus their shifts) to the G3D camera and refreshes the view angles. */
void FIELD_CAMERA_ApplyToG3d(FieldCamera *camera)
{
    VecFx32 targetWithShift;
    VecFx32 eyeWithShift;

    VEC_Add(&camera->target, &camera->targetShift, &targetWithShift);
    VEC_Add(&camera->eye, &camera->eyeShift, &eyeWithShift);
    G3D_CAMERA_SetCamTarget(camera->g3dCamera, &targetWithShift);
    G3D_CAMERA_SetEye(camera->g3dCamera, &eyeWithShift);
    FIELD_CAMERA_ApplyDelayToG3d(camera);
    FIELD_CAMERA_UpdateViewAngles(camera, &targetWithShift, &camera->eye);
}

void FIELD_CAMERA_UpdateMode(FieldCamera *camera, u32 arg)
{
    gFieldCameraUpdateModeFuncs[camera->mode](camera, arg);
}

void FIELD_CAMERA_UpdateTargetMode(FieldCamera *camera, u32 arg)
{
    FIELD_CAMERA_PullTargetFromTrace(camera);
    FIELD_CAMERA_SolveTargetMode(camera);
    FIELD_CAMERA_ApplyToG3d(camera);
}

void FIELD_CAMERA_UpdateEyeMode(FieldCamera *camera, u32 arg)
{
    FIELD_CAMERA_PullEyeFromTrace(camera);
    FIELD_CAMERA_SolveEyeMode(camera);
    FIELD_CAMERA_ApplyToG3d(camera);
}

void FIELD_CAMERA_UpdateFreeMode(FieldCamera *camera, u32 arg)
{
    FIELD_CAMERA_PullTargetFromTrace(camera);
    FIELD_CAMERA_PullEyeFromTrace(camera);
    FIELD_CAMERA_SolveFreeMode(camera);
    FIELD_CAMERA_ApplyToG3d(camera);
}

void FIELD_CAMERA_ClearEyeTrace(FieldCamera *camera)
{
    camera->traceEye = 0;
}

void FIELD_CAMERA_ClearTargetTrace(FieldCamera *camera)
{
    camera->traceTarget = 0;
}

void FIELD_CAMERA_ClearAngles(FieldCamera *camera)
{
    camera->pitch = 0;
    camera->yaw = 0;
    camera->distance = 0;
}

/* Converts a vector to pitch and yaw angles plus its length. */
void FIELD_CAMERA_CalcAngles(VecFx32 *vec, u16 *pitch, u16 *yaw, int *distance)
{
    VecFx32 unit;
    VecFx32 flat;
    u16 angles[2];
    int length;

    length = VEC_Mag(vec);
    VEC_Normalize(vec, &unit);
    flat.x = unit.x;
    flat.y = 0;
    flat.z = unit.z;
    angles[1] = FX_Atan2Idx(unit.y, VEC_Mag(&flat));
    angles[0] = FX_Atan2Idx(unit.x, unit.z);
    FIELD_CAMERA_RefineAngles(&unit, angles[0], angles[1], angles, &angles[1]);
    *pitch = angles[1];
    *yaw = angles[0];
    *distance = length;
}

/* Takes pitch, yaw and distance from a vector. */
void FIELD_CAMERA_SetAnglesFromVector(FieldCamera *camera, VecFx32 *vec)
{
    struct { u16 yaw, pitch; u32 distance; } result;

    FIELD_CAMERA_CalcAngles(vec, &result.pitch, &result.yaw, (int *)(&result.distance));
    camera->pitch = result.pitch;
    camera->yaw = result.yaw;
    camera->distance = result.distance;
}

/* Prepares the switch to target mode: reverses the angles from eye mode, else derives them from eye - target. */
void FIELD_CAMERA_PrepareTargetMode(FieldCamera *camera)
{
    VecFx32 dir;

    if (camera->mode == FIELD_CAMERA_MODE_TRACK_EYE) {
        camera->yaw = camera->yaw + 0x8000;
        camera->pitch = camera->pitch + 0x8000;
    } else {
        VEC_Subtract(&camera->eyeRaw, &camera->target, &dir);
        FIELD_CAMERA_SetAnglesFromVector(camera, &dir);
    }
}

/* Prepares the switch to eye mode: reverses the angles from target mode, else derives them from target - eye. */
void FIELD_CAMERA_PrepareEyeMode(FieldCamera *camera)
{
    VecFx32 dir;

    if (camera->mode == FIELD_CAMERA_MODE_TRACK_TARGET) {
        camera->yaw = camera->yaw + 0x8000;
        camera->pitch = camera->pitch + 0x8000;
    } else {
        VEC_Subtract(&camera->targetRaw, &camera->eye, &dir);
        FIELD_CAMERA_SetAnglesFromVector(camera, &dir);
    }
}

/* Solves the current tracking mode (target or eye). */
void FIELD_CAMERA_SolveTrackMode(FieldCamera *camera)
{
    u32 mode = camera->mode;
    if (mode == FIELD_CAMERA_MODE_TRACK_TARGET) {
        FIELD_CAMERA_PullTargetFromTrace(camera);
        FIELD_CAMERA_SolveTargetMode(camera);
    } else if (mode == FIELD_CAMERA_MODE_TRACK_EYE) {
        FIELD_CAMERA_PullEyeFromTrace(camera);
        FIELD_CAMERA_SolveEyeMode(camera);
    }
}

/* Derives the view yaw and view pitch from the vector between eye and target. */
void FIELD_CAMERA_UpdateViewAngles(FieldCamera *camera, VecFx32 *targetPos, VecFx32 *eyePos)
{
    VecFx32 dir;
    VecFx32 up;
    VecFx32 flat;
    int upDot, flatDot;
    int pitch;

    VEC_Subtract(eyePos, targetPos, &dir);
    VEC_Normalize(&dir, &dir);
    camera->viewYaw = FX_Atan2Idx(dir.x, dir.z);
    up = gFieldCameraUpVec;
    upDot = VEC_DotProduct(&up, &dir);
    flat = dir;
    pitch = 0;
    flat.y = 0;
    VEC_Normalize(&flat, &flat);
    flatDot = VEC_DotProduct(&flat, &dir);
    if (flatDot != 0) {
        pitch = FX_Atan2Idx(upDot, flatDot);
    }
    camera->viewPitch = pitch;
}

static inline int FxMulRound(int a, int b)
{
    return (int)(((long long)a * b + 0x800) >> 12);
}

/*
 * Refines two 16-bit angles (yaw, pitch) toward a target vector: builds the unit
 * direction for the current angles and for yaw +/- one degree (0xb6), then nudges each
 * angle by a linear interpolation per quadrant. Writes the results to outYaw/outPitch.
 */
void FIELD_CAMERA_RefineAngles(VecFx32 *vec, u16 yaw, u16 pitch, u16 *outYaw, u16 *outPitch)
{
    VecS16 cur = {0, 0, 0};
    VecS16 minus = {0, 0, 0};
    VecS16 plus = {0, 0, 0};
    int pitchCos;
    int pitchSinMinus, pitchSinPlus;
    int yawIdx, pitchIdx, yawIdxMinus, yawIdxPlus;
    *outYaw = yaw;
    *outPitch = pitch;
    yawIdx = (yaw >> 4) * 2;
    pitchIdx = (pitch >> 4) * 2;
    pitchCos = FX_SinCosTable_[pitchIdx + 1];
    cur.x = FxMulRound(FX_SinCosTable_[yawIdx], pitchCos);
    cur.y = FX_SinCosTable_[pitchIdx];
    cur.z = FxMulRound(FX_SinCosTable_[yawIdx + 1], pitchCos);
    yawIdxMinus = ((yaw - 0xb6) >> 4) * 2;
    minus.x = FxMulRound(FX_SinCosTable_[yawIdxMinus], pitchCos);
    minus.z = FxMulRound(FX_SinCosTable_[yawIdxMinus + 1], pitchCos);
    pitchSinMinus = FX_SinCosTable_[((pitch - 0xb6) >> 4) * 2];
    yawIdxPlus = ((yaw + 0xb6) >> 4) * 2;
    plus.x = FxMulRound(FX_SinCosTable_[yawIdxPlus], pitchCos);
    plus.z = FxMulRound(FX_SinCosTable_[yawIdxPlus + 1], pitchCos);
    pitchSinPlus = FX_SinCosTable_[((pitch + 0xb6) >> 4) * 2];
    if (yaw < 0x4000) {
        if (cur.x < vec->x && cur.z > vec->z) {
            if (ABS(cur.x - vec->x) >= ABS(cur.z - vec->z)) {
                yaw = yaw - (u16)(0xb6 * (vec->x - cur.x) / (minus.x - cur.x));
            } else {
                yaw = yaw - (u16)(0xb6 * (cur.z - vec->z) / (cur.z - minus.z));
            }
        } else if (cur.x > vec->x && cur.z < vec->z) {
            if (ABS(cur.x - vec->x) >= ABS(cur.z - vec->z)) {
                yaw = yaw + (u16)(0xb6 * (cur.x - vec->x) / (cur.x - plus.x));
            } else {
                yaw = yaw + (u16)(0xb6 * (vec->z - cur.z) / (plus.z - cur.z));
            }
        }
    } else if (yaw < 0x8000) {
        if (cur.x > vec->x && cur.z > vec->z) {
            if (ABS(cur.x - vec->x) >= ABS(cur.z - vec->z)) {
                yaw = yaw - (u16)(0xb6 * (cur.x - vec->x) / (cur.x - minus.x));
            } else {
                yaw = yaw - (u16)(0xb6 * (cur.z - vec->z) / (cur.z - minus.z));
            }
        } else if (cur.x < vec->x && cur.z < vec->z) {
            if (ABS(cur.x - vec->x) >= ABS(cur.z - vec->z)) {
                yaw = yaw + (u16)(0xb6 * (vec->x - cur.x) / (plus.x - cur.x));
            } else {
                yaw = yaw + (u16)(0xb6 * (vec->z - cur.z) / (plus.z - cur.z));
            }
        }
    } else if (yaw < 0xC000) {
        if (cur.x > vec->x && cur.z < vec->z) {
            if (ABS(cur.x - vec->x) >= ABS(cur.z - vec->z)) {
                yaw = yaw - (u16)(0xb6 * (cur.x - vec->x) / (cur.x - minus.x));
            } else {
                yaw = yaw - (u16)(0xb6 * (vec->z - cur.z) / (minus.z - cur.z));
            }
        } else if (cur.x < vec->x && cur.z > vec->z) {
            if (ABS(cur.x - vec->x) >= ABS(cur.z - vec->z)) {
                yaw = yaw + (u16)(0xb6 * (vec->x - cur.x) / (plus.x - cur.x));
            } else {
                yaw = yaw + (u16)(0xb6 * (cur.z - vec->z) / (cur.z - plus.z));
            }
        }
    } else {
        if (cur.x < vec->x && cur.z < vec->z) {
            if (ABS(cur.x - vec->x) >= ABS(cur.z - vec->z)) {
                yaw = yaw - (u16)(0xb6 * (vec->x - cur.x) / (minus.x - cur.x));
            } else {
                yaw = yaw - (u16)(0xb6 * (vec->z - cur.z) / (minus.z - cur.z));
            }
        } else if (cur.x > vec->x && cur.z > vec->z) {
            if (ABS(cur.x - vec->x) >= ABS(cur.z - vec->z)) {
                yaw = yaw + (u16)(0xb6 * (cur.x - vec->x) / (cur.x - plus.x));
            } else {
                yaw = yaw + (u16)(0xb6 * (cur.z - vec->z) / (cur.z - plus.z));
            }
        }
    }
    if (pitch < 0x4000) {
        if (cur.y > vec->y) {
            pitch = pitch - (u16)(0xb6 * (cur.y - vec->y) / (cur.y - pitchSinMinus));
        } else if (cur.y < vec->y) {
            pitch = pitch + (u16)(0xb6 * (vec->y - cur.y) / (pitchSinPlus - cur.y));
        }
    } else if (pitch >= 0xC000) {
        if (cur.y > vec->y) {
            pitch = pitch - (u16)(0xb6 * (cur.y - vec->y) / (cur.y - pitchSinMinus));
        } else if (cur.y < vec->y) {
            pitch = pitch + (u16)(0xb6 * (vec->y - cur.y) / (pitchSinPlus - cur.y));
        }
    }
    *outYaw = yaw;
    *outPitch = pitch;
}

struct G3dCamera *FIELD_CAMERA_GetG3dCamera(FieldCamera *camera)
{
    return camera->g3dCamera;
}

/* Makes the camera follow a position: the target jumps there. */
void FIELD_CAMERA_SetTraceTarget(FieldCamera *camera, const VecFx32 *target)
{
    camera->traceTarget = target;
    camera->lastSetTarget = *target;
    camera->targetRaw = *target;
}

void FIELD_CAMERA_StopTargetTrace(FieldCamera *camera)
{
    camera->traceTarget = 0;
}

const VecFx32 *FIELD_CAMERA_GetTraceTarget(FieldCamera *camera)
{
    return camera->traceTarget;
}

/* Follows the bound position again. */
void FIELD_CAMERA_ResumeTargetTrace(FieldCamera *camera)
{
    camera->traceTarget = camera->boundTarget;
}

void FIELD_CAMERA_SetG3dNear(FieldCamera *camera, u32 scale, ...)
{
    G3D_CAMERA_SetNear(camera->g3dCamera, &scale);
}

void FIELD_CAMERA_SetG3dFar(FieldCamera *camera, u32 roll, ...)
{
    G3D_CAMERA_SetFar(camera->g3dCamera, &roll);
}

void FIELD_CAMERA_SetTarget(FieldCamera *camera, const VecFx32 *target)
{
    camera->targetRaw = *target;
    camera->lastSetTarget = *target;
}

void FIELD_CAMERA_GetTargetRaw(FieldCamera *camera, VecFx32 *out)
{
    *out = camera->targetRaw;
}

void FIELD_CAMERA_GetTargetShift(FieldCamera *camera, VecFx32 *out)
{
    *out = camera->targetShift;
}

void FIELD_CAMERA_SetTargetShift(FieldCamera *camera, const VecFx32 *shift)
{
    camera->targetShift = *shift;
}

void FIELD_CAMERA_GetEyeRaw(FieldCamera *camera, VecFx32 *out)
{
    *out = camera->eyeRaw;
}

void FIELD_CAMERA_SetEyeRaw(FieldCamera *camera, const VecFx32 *eye)
{
    camera->eyeRaw = *eye;
}

void FIELD_CAMERA_SetEyeShift(FieldCamera *camera, const VecFx32 *shift)
{
    camera->eyeShift = *shift;
}

void FIELD_CAMERA_SetG3dUp(FieldCamera *camera, const VecFx32 *up)
{
    G3D_CAMERA_SetCamUp(camera->g3dCamera, up);
}

void FIELD_CAMERA_GetG3dUp(FieldCamera *camera, VecFx32 *out)
{
    G3D_CAMERA_GetCamUp(camera->g3dCamera, out);
}

u16 FIELD_CAMERA_GetPitch(FieldCamera *camera)
{
    return camera->pitch;
}

void FIELD_CAMERA_SetPitch(FieldCamera *camera, u16 pitch)
{
    camera->pitch = pitch;
}

u16 *FIELD_CAMERA_GetViewPitchPtr(FieldCamera *camera)
{
    return &camera->viewPitch;
}

u16 FIELD_CAMERA_GetYaw(FieldCamera *camera)
{
    return camera->yaw;
}

void FIELD_CAMERA_SetYaw(FieldCamera *camera, u32 yaw)
{
    camera->yaw = yaw;
}

u16 *FIELD_CAMERA_GetViewYawPtr(FieldCamera *camera)
{
    return &camera->viewYaw;
}

u32 FIELD_CAMERA_GetDistance(FieldCamera *camera)
{
    return camera->distance;
}

void FIELD_CAMERA_SetDistance(FieldCamera *camera, u32 distance)
{
    camera->distance = distance;
}

void FIELD_CAMERA_GetVectorAngles(VecFx32 *vec, u16 *pitch, u16 *yaw, int *distance)
{
    FIELD_CAMERA_CalcAngles(vec, pitch, yaw, distance);
}

/* Sets the field of view angle and the matching sin and cos in the G3D camera. */
void FIELD_CAMERA_SetFov(FieldCamera *camera, u16 fov)
{
    camera->fov = fov;
    G3D_CAMERA_SetFovySin(camera->g3dCamera, FX_SinCosTable_[(camera->fov >> 4) * 2]);
    G3D_CAMERA_SetFovyCos(camera->g3dCamera, FX_SinCosTable_[(camera->fov >> 4) * 2 + 1]);
}

/* Pushes a target and an eye into the delay log and reads the delayed pair back. */
void FIELD_CAMERA_StepDelay(FieldCameraDelay *delay, VecFx32 *target, VecFx32 *eye, VecFx32 *outTarget, VecFx32 *outEye)
{
    int readPos;
    int writePos;

    if (delay == 0) {
        *outTarget = *target;
        *outEye = *eye;
        return;
    }
    if (delay->enabled == 0) {
        *outTarget = *target;
        *outEye = *eye;
        return;
    }
    readPos = delay->readPos;
    writePos = delay->writePos;
    if (delay->draining == 0) {
        delay->targetLog[writePos] = *target;
        delay->eyeLog[writePos] = *eye;
        writePos = (writePos + 1) % delay->count;
    }
    if (delay->filled != 0) {
        *outTarget = delay->targetLog[readPos];
        *outEye = delay->eyeLog[readPos];
    } else {
        *outTarget = delay->targetLog[delay->delayFrames];
        *outEye = delay->eyeLog[delay->delayFrames];
        if (readPos == delay->delayFrames)
            delay->filled = 1;
    }
    if (delay->draining != 0) {
        if (readPos != writePos) {
            readPos = (readPos + 1) % delay->count;
            if (readPos == writePos)
                FIELD_CAMERA_StopDelayLog(delay);
        }
    } else {
        readPos = (readPos + 1) % delay->count;
    }
    delay->readPos = readPos;
    delay->writePos = writePos;
    if (delay->delayX == 0) {
        outTarget->x = target->x;
        outEye->x = eye->x;
    }
    if (delay->delayY == 0) {
        outTarget->y = target->y;
        outEye->y = eye->y;
    }
    if (delay->delayZ == 0) {
        outTarget->z = target->z;
        outEye->z = eye->z;
    }
}

/*
 * Creates the delay log (count entries per log) when the camera follows a
 * position. flags bit 0, 1, 2 delay the x, y, z component.
 */
void FIELD_CAMERA_CreateDelay(int count, u32 delayFrames, u32 flags, u32 heapId, FieldCamera *camera)
{
    if (camera->traceTarget != 0) {
        int i = 0;
        FieldCameraDelay *delay = GFL_HEAP_Alloc(heapId, sizeof(FieldCameraDelay), 0, gFieldCameraFileName, 0x6aa);
        delay->targetLog = GFL_HEAP_Alloc(heapId, count * sizeof(VecFx32), 0, gFieldCameraFileName, 0x6ab);
        delay->eyeLog = GFL_HEAP_Alloc(heapId, count * sizeof(VecFx32), 0, gFieldCameraFileName, 0x6ac);
        for (; i < count; i++) {
            VecFx32 *entry = &delay->targetLog[i];
            entry->x = 0;
            entry->y = 0;
            entry->z = 0;
            entry = &delay->eyeLog[i];
            entry->x = 0;
            entry->y = 0;
            entry->z = 0;
        }
        delay->count = count;
        delay->delayFrames = delayFrames;
        delay->filled = 0;
        delay->readPos = 0;
        delay->writePos = delayFrames;
        delay->delayX = 0;
        delay->delayY = 0;
        delay->delayZ = 0;
        if (flags & 1)
            delay->delayX = 1;
        if (flags & 2)
            delay->delayY = 1;
        if (flags & 4)
            delay->delayZ = 1;
        delay->enabled = 1;
        delay->draining = 0;
        camera->delay = delay;
    }
}

void FIELD_CAMERA_DeleteDelay(FieldCamera *camera)
{
    if (camera->delay != 0) {
        GFL_HEAP_Free(camera->delay->targetLog);
        GFL_HEAP_Free(camera->delay->eyeLog);
        GFL_HEAP_Free(camera->delay);
        camera->delay = 0;
    }
}

/* Runs the G3D camera target and eye through the delay log. */
void FIELD_CAMERA_ApplyDelayToG3d(FieldCamera *camera)
{
    if (camera->traceTarget != 0) {
        VecFx32 eyeNow;
        VecFx32 targetNow;
        VecFx32 eyeDelayed;
        VecFx32 targetDelayed;

        G3D_CAMERA_GetCamTarget(camera->g3dCamera, &targetNow);
        G3D_CAMERA_GetEye(camera->g3dCamera, &eyeNow);
        FIELD_CAMERA_StepDelay(camera->delay, &targetNow, &eyeNow, &targetDelayed, &eyeDelayed);
        G3D_CAMERA_SetCamTarget(camera->g3dCamera, &targetDelayed);
        G3D_CAMERA_SetEye(camera->g3dCamera, &eyeDelayed);
    }
}

/* Switches the delay log off. */
void FIELD_CAMERA_StopDelayLog(FieldCameraDelay *delay)
{
    delay->draining = 0;
    delay->enabled = 0;
    delay->filled = 0;
}

/* Clears both logs and restarts the delay. */
void FIELD_CAMERA_RestartDelay(FieldCamera *camera)
{
    FieldCameraDelay *delay = camera->delay;
    int i;

    if (delay != 0) {
        for (i = 0; i < delay->count; i++) {
            VecFx32 *entry = &delay->targetLog[i];
            entry->x = 0;
            entry->y = 0;
            entry->z = 0;
            entry = &delay->eyeLog[i];
            entry->x = 0;
            entry->y = 0;
            entry->z = 0;
        }
        delay->readPos = 0;
        delay->writePos = delay->delayFrames;
        delay->filled = 0;
        delay->enabled = 1;
        delay->draining = 0;
    }
}

/* Ends the delay: at once while it is still warming up, else after the log has played out. */
void FIELD_CAMERA_EndDelay(FieldCamera *camera)
{
    FieldCameraDelay *delay = camera->delay;

    if (delay != 0) {
        if (delay->filled == 0 && delay->writePos == delay->delayFrames && delay->readPos == 0)
            FIELD_CAMERA_StopDelayLog(delay);
        else
            delay->draining = 1;
    }
}

void FIELD_CAMERA_StopDelay(FieldCamera *camera, int unused)
{
    FieldCameraDelay *delay = camera->delay;

    if (delay != 0) {
        delay->draining = 0;
        delay->enabled = 0;
        delay->filled = 0;
    }
}

u32 FIELD_CAMERA_IsDelayEnabled(FieldCamera *camera)
{
    FieldCameraDelay *delay = camera->delay;

    if (delay == 0)
        return 0;
    return delay->enabled;
}

int FIELD_CAMERA_HasDelay(FieldCamera *camera)
{
    if (camera->traceTarget == 0)
        return 0;
    if (camera->delay != 0)
        return 1;
    return 0;
}

/* Copies the areas of an area set into the camera. */
void FIELD_CAMERA_CopyAreas(FieldCamera *camera, FieldCameraAreaSet *set)
{
    MI_CpuCopy8(set->areas, camera->areas, sizeof(FieldCameraArea) * set->count);
    camera->areaCount = set->count;
}

void FIELD_CAMERA_ClearAreas(FieldCamera *camera)
{
    MI_CpuFill8(camera->areas, 0, sizeof(camera->areas));
    camera->areaCount = 0;
}

/* Loads the area set areaId from archive 0x6C unless it is loaded already. */
void FIELD_CAMERA_LoadAreas(FieldCamera *camera, u32 areaId, u32 heapId)
{
    FieldCameraAreaSet *set;

    if (camera->areaId != areaId) {
        set = ARC_UTIL_LoadHandleMember(camera->areaArc, areaId, 0, (u16)((heapId & 0x7fff) | 0x8000));
        FIELD_CAMERA_CopyAreas(camera, set);
        GFL_HEAP_Free(set);
        camera->areaId = areaId;
    }
}

void FIELD_CAMERA_GetTarget(FieldCamera *camera, VecFx32 *out)
{
    *out = camera->target;
}

void FIELD_CAMERA_GetEye(FieldCamera *camera, VecFx32 *out)
{
    *out = camera->eye;
}

void FIELD_CAMERA_SetAreasEnabled(FieldCamera *camera, u32 enabled)
{
    camera->areasEnabled = enabled;
}

unsigned char FIELD_CAMERA_GetAreasEnabled(FieldCamera *camera)
{
    return camera->areasEnabled;
}

/* Runs an area on a point when the area limits the target. */
void FIELD_CAMERA_ApplyTargetArea(FieldCameraArea *area, VecFx32 *point)
{
    if (area->applyTo == FIELD_CAMERA_AREA_ON_TARGET) {
        FieldCameraAreaFunc func = gFieldCameraAreaFuncs[area->shape];
        if (func != 0)
            func(area, point, point);
    }
}

/* Runs an area on a point when the area limits the eye. */
void FIELD_CAMERA_ApplyEyeArea(FieldCameraArea *area, VecFx32 *point)
{
    if (area->applyTo == FIELD_CAMERA_AREA_ON_EYE) {
        FieldCameraAreaFunc func = gFieldCameraAreaFuncs[area->shape];
        if (func != 0)
            func(area, point, point);
    }
}

/* Clamps a point into the box (whole units, converted to fx32); returns 1 when it moved. */
int FIELD_CAMERA_AreaKeepInBox(const FieldCameraArea *area, VecFx32 *in, VecFx32 *out)
{
    VecFx32 p;
    int moved;

    p = *in;
    moved = 0;
    out->x = p.x;
    out->z = p.z;
    out->y = p.y;
    if (FX_F32_TO_FX32(area->u.box.minX) > p.x) {
        moved = 1;
        out->x = FX_F32_TO_FX32(area->u.box.minX);
    } else if (area->u.box.maxX * 4096 < p.x) {
        moved = 1;
        out->x = FX_F32_TO_FX32(area->u.box.maxX);
    }
    if (area->u.box.minZ * 4096 > p.z) {
        moved = 1;
        out->z = FX_F32_TO_FX32(area->u.box.minZ);
    } else if (area->u.box.maxZ * 4096 < p.z) {
        moved = 1;
        out->z = FX_F32_TO_FX32(area->u.box.maxZ);
    }
    return moved;
}

/*
 * Clamps a point to a ring sector around the center: radius capped at
 * maxRadius, angle clamped between minAngle and maxAngle; returns 1 when clamped.
 * `const` on area lets the center z load schedule above the flat.y = 0 store
 * (docs/idioms/a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer.md);
 * the table entry read into an s16 local puts it in r0:r1 of _ll_mul, and
 * `clamped = 1` repeated in both inner arms gives the cross-jumped clamp blocks.
 */
int FIELD_CAMERA_AreaKeepInRing(const FieldCameraArea *area, VecFx32 *in, VecFx32 *out)
{
    VecFx32 ref;
    VecFx32 flat;
    VecFx32 orig;
    VecFx32 center;
    VecFx32 offset;
    VecFx32 cross;
    int radius;
    int clamped;
    u16 angle;
    u16 minAngle, maxAngle;
    int distToMax, distToMin;
    int idx;
    s16 trig;

    ref = gFieldCameraRingRefVec;
    flat = *in;
    orig = *in;
    out->x = in->x;
    out->y = in->y;
    out->z = in->z;
    center.x = area->u.ring.centerX;
    center.y = 0;
    clamped = 0;
    flat.y = 0;
    center.z = area->u.ring.centerZ;
    VEC_Subtract(&flat, &center, &offset);
    radius = VEC_Mag(&offset);
    if (FX_Modf(radius, &radius) > 0) {
        radius += 0x1000;
    }
    VEC_Normalize(&offset, &offset);
    VEC_CrossProduct(&ref, &offset, &cross);
    angle = FX_AcosIdx(VEC_DotProduct(&ref, &offset));
    if (cross.y < 0) {
        angle = 0x10000 - angle;
    }
    if (radius > area->u.ring.maxRadius) {
        radius = area->u.ring.maxRadius;
        clamped = 1;
    }
    minAngle = area->u.ring.minAngle;
    maxAngle = area->u.ring.maxAngle;
    if (maxAngle != minAngle) {
        if (maxAngle > minAngle) {
            if (minAngle < angle && maxAngle >= angle) {
                distToMax = maxAngle - angle;
                if (distToMax < 0) distToMax = -distToMax;
                distToMin = minAngle - angle;
                if (distToMin < 0) distToMin = -distToMin;
                if (distToMin > distToMax) {
                    angle = maxAngle;
                    clamped = 1;
                } else {
                    angle = minAngle;
                    clamped = 1;
                }
            }
        } else if (maxAngle > angle) {
            angle = maxAngle;
            clamped = 1;
        } else if (minAngle < angle) {
            angle = minAngle;
            clamped = 1;
        }
    }
    if (clamped != 0) {
        idx = (angle >> 4) * 2;
        trig = FX_SinCosTable_[idx];
        out->x = center.x + (int)(((long long)trig * radius + 0x800) >> 12);
        trig = FX_SinCosTable_[idx + 1];
        out->z = center.z + (int)(((long long)trig * radius + 0x800) >> 12);
        out->y = orig.y;
    }
    return clamped;
}

/*
 * Pushes a point inside the box (whole units, converted to fx32) out through
 * the nearest side; returns 1 when it moved.
 * Reading p.z directly (no named local) is what puts its CSE slot below the
 * minX temp.
 */
int FIELD_CAMERA_AreaKeepOutBox(FieldCameraArea *area, VecFx32 *in, VecFx32 *out)
{
    VecFx32 p;
    int moved;
    int best;
    int side;

    p = *in;
    moved = 0;
    out->x = p.x;
    out->z = p.z;
    out->y = p.y;
    if (FX_F32_TO_FX32(area->u.box.minX) < p.x && FX_F32_TO_FX32(area->u.box.maxX) > p.x &&
        FX_F32_TO_FX32(area->u.box.minZ) < p.z && FX_F32_TO_FX32(area->u.box.maxZ) > p.z) {
        moved = 1;
        best = out->x - FX_F32_TO_FX32(area->u.box.minX);
        side = 0;
        if (best > FX_F32_TO_FX32(area->u.box.maxX) - out->x) {
            best = FX_F32_TO_FX32(area->u.box.maxX) - out->x;
            side = 1;
        }
        if (best > out->z - FX_F32_TO_FX32(area->u.box.minZ)) {
            best = out->z - FX_F32_TO_FX32(area->u.box.minZ);
            side = 2;
        }
        if (best > FX_F32_TO_FX32(area->u.box.maxZ) - out->z) {
            best = FX_F32_TO_FX32(area->u.box.maxZ) - out->z;
            side = 3;
        }
        switch (side) {
        case 0:
            out->x = FX_F32_TO_FX32(area->u.box.minX);
            break;
        case 1:
            out->x = FX_F32_TO_FX32(area->u.box.maxX);
            break;
        case 2:
            out->z = FX_F32_TO_FX32(area->u.box.minZ);
            break;
        case 3:
            out->z = FX_F32_TO_FX32(area->u.box.maxZ);
            break;
        }
    }
    return moved;
}

/* Takes a snapshot of the camera pose (raw eye and raw target). */
void FIELD_CAMERA_TakeView(FieldCamera *camera, FieldCameraView *view)
{
    view->eye = camera->eyeRaw;
    view->target = camera->targetRaw;
    view->pitch = camera->pitch;
    view->yaw = camera->yaw;
    view->distance = camera->distance;
    view->fov = camera->fov;
    view->shift = camera->targetShift;
}

/* Same as above, but with the target after the areas. */
void FIELD_CAMERA_TakeViewConstrained(FieldCamera *camera, FieldCameraView *view)
{
    view->eye = camera->eyeRaw;
    FIELD_CAMERA_GetTarget(camera, &view->target);
    view->pitch = camera->pitch;
    view->yaw = camera->yaw;
    view->distance = camera->distance;
    view->fov = camera->fov;
    view->shift = camera->targetShift;
}

/* Saves mode and pose (raw target) once, then switches to target mode. */
void FIELD_CAMERA_PushState(FieldCamera *camera)
{
    if (camera != 0) {
        FieldCameraMotion *motion = &camera->motion;
        if (motion->stateSaved == 0) {
            motion->savedMode = camera->mode;
            FIELD_CAMERA_SetMode(camera, FIELD_CAMERA_MODE_TRACK_TARGET);
            FIELD_CAMERA_TakeView(camera, &motion->saved);
            motion->stateSaved = 1;
        }
    }
}

/* Same as above, saving the target after the areas. */
void FIELD_CAMERA_PushStateConstrained(FieldCamera *camera)
{
    if (camera != 0) {
        FieldCameraMotion *motion = &camera->motion;
        if (motion->stateSaved == 0) {
            motion->savedMode = camera->mode;
            FIELD_CAMERA_SetMode(camera, FIELD_CAMERA_MODE_TRACK_TARGET);
            FIELD_CAMERA_TakeViewConstrained(camera, &motion->saved);
            motion->stateSaved = 1;
        }
    }
}

/* Restores the mode saved by the two calls above. */
void FIELD_CAMERA_PopState(FieldCamera *camera)
{
    if (camera != 0) {
        FieldCameraMotion *motion = &camera->motion;
        if (motion->stateSaved != 0) {
            FIELD_CAMERA_SetMode(camera, motion->savedMode);
            motion->stateSaved = 0;
        }
    }
}

/* Sets up a move to request->goal and arms the per-frame callback. */
void FIELD_CAMERA_SetMoveGoal(FieldCamera *camera, FieldCameraMoveRequest *request, u16 frames)
{
    FieldCameraMotion *motion;

    if (camera) {
        motion = &camera->motion;
        FIELD_CAMERA_SetMode(camera, FIELD_CAMERA_MODE_TRACK_TARGET);
        motion->to = request->goal;
        motion->frame = 0;
        motion->frames = frames;
        motion->channels = request->channels;
        camera->motion.callback = (FieldCameraUpdateFunc)FIELD_CAMERA_UpdateMove;
        motion->callbackArg = 0;
        motion->moving = 1;
    }
}

/* Moves from the current pose (raw target) to request->goal. */
void FIELD_CAMERA_StartMove(FieldCamera *camera, FieldCameraMoveRequest *request, u16 frames)
{
    if (camera != 0) {
        FIELD_CAMERA_SetMoveGoal(camera, request, frames);
        FIELD_CAMERA_TakeView(camera, &camera->motion.from);
    }
}

/* Same as above, starting from the target after the areas. */
void FIELD_CAMERA_StartMoveConstrained(FieldCamera *camera, FieldCameraMoveRequest *request, u16 frames)
{
    if (camera != 0) {
        FIELD_CAMERA_SetMoveGoal(camera, request, frames);
        FIELD_CAMERA_TakeViewConstrained(camera, &camera->motion.from);
    }
}

/* Moves eye and target to the two goals in free mode. */
void FIELD_CAMERA_StartFreeMove(FieldCamera *camera, VecFx32 *eyeGoal, VecFx32 *targetGoal, FieldCameraMoveChannels *channels, u16 frames)
{
    FieldCameraMotion *motion;
    FieldCameraMoveChannels loc;

    if (camera) {
        motion = &camera->motion;
        FIELD_CAMERA_SetMode(camera, FIELD_CAMERA_MODE_FREE);
        FIELD_CAMERA_TakeView(camera, &motion->from);
        motion->to.eye = *eyeGoal;
        motion->to.target = *targetGoal;
        motion->frame = 0;
        motion->frames = frames;
        loc.target = channels->target;
        loc.pitch = 0;
        loc.fov = channels->fov;
        loc.yaw = 0;
        loc.distance = 0;
        loc.shift = channels->shift;
        motion->channels = loc;
        camera->motion.callback = (FieldCameraUpdateFunc)FIELD_CAMERA_UpdateFreeMove;
        motion->callbackArg = 0;
        motion->moving = 1;
    }
}

/* Moves from the current pose back to the pose saved by the push state calls. */
void FIELD_CAMERA_StartMoveToSaved(FieldCamera *camera, FieldCameraMoveChannels *channels, u16 frames)
{
    FieldCameraMotion *motion;

    if (camera) {
        motion = &camera->motion;
        if (motion->stateSaved != 0 && frames != 0) {
            FIELD_CAMERA_SetMode(camera, FIELD_CAMERA_MODE_TRACK_TARGET);
            FIELD_CAMERA_TakeView(camera, &motion->from);
            motion->to = motion->saved;
            motion->frame = 0;
            motion->frames = frames;
            motion->channels = *channels;
            camera->motion.callback = (FieldCameraUpdateFunc)FIELD_CAMERA_UpdateMove;
            motion->callbackArg = 0;
            motion->moving = 1;
        }
    }
}

/*
 * Moves from the current pose to the pose of the current setting record.
 * The two vector copies into motion->to.target are tail-merged by the
 * compiler (a shared source pointer variable compiles the same).
 */
void FIELD_CAMERA_StartMoveToSetting(FieldCamera *camera, u16 frames)
{
    FieldCameraMotion *motion;
    FieldCameraSetting setting;

    if (camera) {
        motion = &camera->motion;
        if (motion->stateSaved != 0 && frames != 0) {
            FIELD_CAMERA_SetMode(camera, FIELD_CAMERA_MODE_TRACK_TARGET);
            FIELD_CAMERA_TakeView(camera, &motion->from);
            FIELD_CAMERA_ReadSetting(camera, &setting);
            motion->to.pitch = setting.pitch;
            motion->to.yaw = setting.yaw;
            motion->to.distance = setting.distance << 12;
            motion->to.fov = setting.fov;
            if (setting.hasTarget != 0) {
                motion->to.shift = setting.vec;
                motion->to.target = *camera->boundTarget;
            } else {
                motion->to.shift.x = 0;
                motion->to.shift.y = 0;
                motion->to.shift.z = 0;
                motion->to.target = setting.vec;
            }
            motion->frame = 0;
            motion->frames = frames;
            motion->channels.shift = 1;
            motion->channels.pitch = 1;
            motion->channels.yaw = 1;
            motion->channels.distance = 1;
            motion->channels.fov = 1;
            motion->channels.target = 1;
            camera->motion.callback = (FieldCameraUpdateFunc)FIELD_CAMERA_UpdateMove;
            motion->callbackArg = 0;
            motion->moving = 1;
        }
    }
}

/*
 * Per-frame callback of the moves above: steps the frame counter and
 * interpolates each enabled channel from the start pose toward the goal pose.
 */
void FIELD_CAMERA_UpdateMove(FieldCamera *camera)
{
    FieldCameraMotion *motion;
    FieldCameraView *from;
    FieldCameraView *to;

    motion = &camera->motion;
    if (motion->moving == 0) {
        return;
    }
    (motion->frame)++;
    from = &motion->from;
    to = &motion->to;
    if (motion->channels.pitch != 0) {
        camera->pitch = FIELD_CAMERA_LerpAngle(&from->pitch, &to->pitch,
                                      motion->frames, motion->frame);
    }
    if (motion->channels.yaw != 0) {
        camera->yaw = FIELD_CAMERA_LerpAngle(&from->yaw, &to->yaw,
                                    motion->frames, motion->frame);
    }
    if (motion->channels.target != 0) {
        FIELD_CAMERA_LerpVec(&from->target, &to->target, motion->frames, motion->frame, &camera->targetRaw);
    }
    if (motion->channels.fov != 0) {
        camera->fov = FIELD_CAMERA_LerpAngle(&from->fov, &to->fov,
                                    motion->frames, motion->frame);
        G3D_CAMERA_SetFovySin(camera->g3dCamera, FX_SinCosTable_[(camera->fov >> 4) * 2]);
        G3D_CAMERA_SetFovyCos(camera->g3dCamera, FX_SinCosTable_[(camera->fov >> 4) * 2 + 1]);
    }
    if (motion->channels.distance != 0) {
        camera->distance = FIELD_CAMERA_LerpFx32(&from->distance, &to->distance,
                                         motion->frames, motion->frame);
    }
    if (motion->channels.shift != 0) {
        FIELD_CAMERA_LerpVec(&from->shift, &to->shift, motion->frames, motion->frame, &camera->targetShift);
    }
    if (motion->frame >= motion->frames) {
        motion->moving = 0;
        FIELD_CAMERA_ClearMoveCallback(camera);
    }
}

/* Per-frame callback of the free mode move: eye and target, fov and shift channels. */
void FIELD_CAMERA_UpdateFreeMove(FieldCamera *camera)
{
    FieldCameraMotion *motion;
    FieldCameraView *from;
    FieldCameraView *to;

    motion = &camera->motion;
    if (motion->moving == 0) {
        return;
    }
    (motion->frame)++;
    from = &motion->from;
    to = &motion->to;
    if (motion->channels.target != 0) {
        FIELD_CAMERA_LerpVec(&from->target, &to->target, motion->frames, motion->frame, &camera->targetRaw);
        FIELD_CAMERA_LerpVec(&from->eye, &to->eye, motion->frames, motion->frame, &camera->eyeRaw);
    }
    if (motion->channels.fov != 0) {
        camera->fov = FIELD_CAMERA_LerpAngle(&from->fov, &to->fov,
                                    motion->frames, motion->frame);
        G3D_CAMERA_SetFovySin(camera->g3dCamera, FX_SinCosTable_[(camera->fov >> 4) * 2]);
        G3D_CAMERA_SetFovyCos(camera->g3dCamera, FX_SinCosTable_[(camera->fov >> 4) * 2 + 1]);
    }
    if (motion->channels.shift != 0) {
        FIELD_CAMERA_LerpVec(&from->shift, &to->shift, motion->frames, motion->frame, &camera->targetShift);
    }
    if (motion->frame >= motion->frames) {
        motion->moving = 0;
        FIELD_CAMERA_ClearMoveCallback(camera);
    }
}

/*
 * frames and frame are u16 (the caller passes u16 fields): with int parameters the
 * scheduler hoists the third call's pointer bumps above the store of out->y.
 */
void FIELD_CAMERA_LerpVec(VecFx32 *from, VecFx32 *to, u16 frames, u16 frame, VecFx32 *out)
{
    if (frames == 0)
        *out = *to;
    out->x = FIELD_CAMERA_LerpFx32(&from->x, &to->x, frames, frame);
    out->y = FIELD_CAMERA_LerpFx32(&from->y, &to->y, frames, frame);
    out->z = FIELD_CAMERA_LerpFx32(&from->z, &to->z, frames, frame);
}

/* Linear interpolation from *from to *to after frame of frames steps. */
int FIELD_CAMERA_LerpFx32(int *from, int *to, int frames, int frame)
{
    int start = *from;
    int end = *to;
    int diff;
    if (frames == frame)
        return end;
    diff = end - start;
    return start + diff * frame / frames;
}

/* Same for 16-bit angles, along the shorter way round. */
u16 FIELD_CAMERA_LerpAngle(u16 *from, u16 *to, s32 frames, s32 frame)
{
    u16 start, delta, rem;
    if (frames == 0)
        return *to;
    start = *from;
    delta = *to - start;
    rem = 0x10000 - delta;
    if (delta <= rem)
        return start + (u16)(delta * frame / frames);
    return start - (u16)(rem * frame / frames);
}

void FIELD_CAMERA_ClearMoveCallback(FieldCamera *camera)
{
    camera->motion.callback = 0;
    camera->motion.callbackArg = 0;
}

/* 1 while a move callback is armed and the move is running. */
int FIELD_CAMERA_IsMoving(FieldCamera *camera)
{
    FieldCameraMotion *motion = &camera->motion;
    if (camera->motion.callback != 0 && motion->moving != 0)
        return 1;
    return 0;
}

/* Returns the goal pose of the running move. */
FieldCameraView *FIELD_CAMERA_GetMoveGoal(FieldCamera *camera)
{
    return &camera->motion.to;
}
