/*
 * file:     field_camera_anime.c
 * unit:     yes
 * function: FIELD_CAMERA_ANIME_GetCurrentParam, FIELD_CAMERA_ANIME_Create, FIELD_CAMERA_ANIME_Delete, FIELD_CAMERA_ANIME_SetData, FIELD_CAMERA_ANIME_Setup, FIELD_CAMERA_ANIME_ApplyStartParam, FIELD_CAMERA_ANIME_Start, FIELD_CAMERA_ANIME_Restore, FIELD_CAMERA_ANIME_Alloc, FIELD_CAMERA_ANIME_Free, FIELD_CAMERA_ANIME_Init, FIELD_CAMERA_ANIME_SaveCameraState, FIELD_CAMERA_ANIME_SaveCameraMode, FIELD_CAMERA_ANIME_RestoreCameraState, FIELD_CAMERA_ANIME_SetAnglesFromPos, FIELD_CAMERA_ANIME_SetTargetFromCurrent, FIELD_CAMERA_ANIME_ReadParam, FIELD_CAMERA_ANIME_ApplyEndParam, FIELD_CAMERA_ANIME_StartMoveTasks, FIELD_CAMERA_ANIME_GetCamera, FIELD_CAMERA_ANIME_GetData
 * address:  0x0218FE78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_msgbg.c at 0x0218FE78: field_camera_anime.c __FILE__ anchor at 0x0218FF30; 0x0218FE78 forwards to the anime move code (cut position probable, 0x0218FE50 and 0x0218FE70 read the camera object).
 *
 * symbols:
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   VEC_Subtract  0x0207CA00  arm
 *   d_021DDA38  0x021DDA38  data  ov021  a4
 *   FIELDMAP_GetCamera  0x02188C58  thumb
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb  ov021
 *   FIELD_NOGRID_MAPPER_SetActive  0x021BB260  thumb  ov021
 *   FIELDMAP_GetSceneArea  0x02189A18  thumb  ov021
 *   FLD_SCENEAREA_SetEnabled  0x021AB75C  thumb  ov021
 *   FIELD_TASK_CreateCameraPitchTween  0x021C7058  thumb  ov021
 *   FIELD_TASK_CreateCameraYawTween  0x021C701C  thumb  ov021
 *   FIELD_TASK_CreateCameraDistanceTween  0x021C6F00  thumb  ov021
 *   FIELD_TASK_CreateCameraLerp  0x021C7C10  thumb  ov021
 *   FIELD_TASK_CreateCameraTargetTween  0x021C7AE4  thumb  ov021
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELD_TASK_MANAGER_AddTask  0x021C6DE0  thumb  ov021
 *   FIELD_CAMERA_GetMode  0x0218E138  thumb  ov021
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb  ov021
 *   FIELD_CAMERA_SetTraceTarget  0x0218EC30  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_CAMERA_GetTraceTarget  0x0218EC5C  thumb  ov021
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb  ov021
 *   FIELD_CAMERA_GetTargetShift  0x0218ECC4  thumb  ov021
 *   FIELD_CAMERA_SetTargetShift  0x0218ECD4  thumb  ov021
 *   FIELD_CAMERA_SetPitch  0x0218ED34  thumb  ov021
 *   FIELD_CAMERA_SetYaw  0x0218ED48  thumb  ov021
 *   FIELD_CAMERA_SetDistance  0x0218ED58  thumb  ov021
 *   FIELD_CAMERA_GetVectorAngles  0x0218ED5C  thumb  ov021
 *   FIELD_CAMERA_GetTarget  0x0218F18C  thumb  ov021
 *   FIELD_CAMERA_GetEye  0x0218F19C  thumb  ov021
 *   FIELD_CAMERA_SetAreasEnabled  0x0218F1AC  thumb  ov021
 *   FIELD_CAMERA_GetAreasEnabled  0x0218F1B4  thumb  ov021
 */
#include "../types.h"

#include "field_camera_types.h"

/* Camera anime work (0x20 bytes, heap tag 0xEE). */
typedef struct FieldCameraAnime {
    FieldMap *fieldMap;             /* 0x00 */
    FieldCamera *camera;            /* 0x04 */
    FieldCameraAnimeData *data;     /* 0x08 */
    u32 isSetUp;                    /* 0x0C */
    u32 savedMode;                  /* 0x10 */
    u32 savedTrace;                 /* 0x14 */
    const VecFx32 *savedTarget;     /* 0x18 */
    u32 targetDetached;             /* 0x1C */
} FieldCameraAnime;

/* field_camera.c */
#include "field_camera.h"

void FIELD_CAMERA_ANIME_GetCurrentParam(FieldCamera *camera, FieldCameraParam *param);
FieldCameraAnime *FIELD_CAMERA_ANIME_Create(FieldMap *fieldMap);
void FIELD_CAMERA_ANIME_Delete(FieldCameraAnime *anime);
void FIELD_CAMERA_ANIME_SetData(FieldCameraAnime *anime, FieldCameraAnimeData *data);
int FIELD_CAMERA_ANIME_Setup(FieldCameraAnime *anime);
void FIELD_CAMERA_ANIME_ApplyStartParam(FieldCameraAnime *anime);
void FIELD_CAMERA_ANIME_Start(FieldCameraAnime *anime);
void FIELD_CAMERA_ANIME_Restore(FieldCameraAnime *anime);
FieldCameraAnime *FIELD_CAMERA_ANIME_Alloc(u16 heapId);
void FIELD_CAMERA_ANIME_Free(FieldCameraAnime *anime);
void FIELD_CAMERA_ANIME_Init(FieldCameraAnime *anime, FieldMap *fieldMap);
u32 FIELD_CAMERA_ANIME_SaveCameraState(FieldCameraAnime *anime);
void FIELD_CAMERA_ANIME_SaveCameraMode(FieldCameraAnime *anime);
void FIELD_CAMERA_ANIME_RestoreCameraState(FieldCameraAnime *anime);
void FIELD_CAMERA_ANIME_SetAnglesFromPos(FieldCamera *camera);
void FIELD_CAMERA_ANIME_SetTargetFromCurrent(FieldCamera *camera);
void FIELD_CAMERA_ANIME_ReadParam(FieldCamera *camera, FieldCameraParam *param);
void FIELD_CAMERA_ANIME_ApplyEndParam(FieldCameraAnime *anime);
void FIELD_CAMERA_ANIME_StartMoveTasks(FieldCameraAnime *anime);
FieldCamera *FIELD_CAMERA_ANIME_GetCamera(FieldCameraAnime *anime);
FieldCameraAnimeData *FIELD_CAMERA_ANIME_GetData(FieldCameraAnime *anime);

#include "fieldmap.h"
#include "../arm9/mi_memory.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/fx_vec.h"
struct FieldMap;
struct FieldNogridMapper;
#include "field_nogrid_mapper.h"
struct FieldMap;
struct FldSceneArea;
#include "fld_scenearea.h"
#include "field_task_manager.h"
struct FieldTask;
struct FieldTaskManager;
extern const char d_021DDA38[];

void FIELD_CAMERA_ANIME_GetCurrentParam(FieldCamera *camera, FieldCameraParam *param)
{
    FIELD_CAMERA_ANIME_ReadParam(camera, param);
}

FieldCameraAnime *FIELD_CAMERA_ANIME_Create(FieldMap *fieldMap)
{
    FieldCameraAnime *anime = FIELD_CAMERA_ANIME_Alloc(FIELDMAP_GetHeapId(fieldMap));
    FIELD_CAMERA_ANIME_Init(anime, fieldMap);
    return anime;
}

void FIELD_CAMERA_ANIME_Delete(FieldCameraAnime *anime)
{
    FIELD_CAMERA_ANIME_Free(anime);
}

void FIELD_CAMERA_ANIME_SetData(FieldCameraAnime *anime, FieldCameraAnimeData *data)
{
    anime->data = data;
}

int FIELD_CAMERA_ANIME_Setup(FieldCameraAnime *anime)
{
    FIELD_CAMERA_ANIME_SaveCameraMode(anime);
    FIELD_CAMERA_ANIME_SetAnglesFromPos(anime->camera);
    FIELD_CAMERA_ANIME_SetTargetFromCurrent(anime->camera);
    return FIELD_CAMERA_ANIME_SaveCameraState(anime);
}

void FIELD_CAMERA_ANIME_ApplyStartParam(FieldCameraAnime *anime)
{
    FieldCamera *camera = FIELD_CAMERA_ANIME_GetCamera(anime);
    FieldCameraParam *start = &FIELD_CAMERA_ANIME_GetData(anime)->start;
    FIELD_CAMERA_SetPitch(camera, start->pitch);
    FIELD_CAMERA_SetYaw(camera, start->yaw);
    FIELD_CAMERA_SetDistance(camera, start->distance);
    FIELD_CAMERA_SetTarget(camera, &start->target);
    FIELD_CAMERA_SetTargetShift(camera, &start->shift);
}

void FIELD_CAMERA_ANIME_Start(FieldCameraAnime *anime)
{
    if (FIELD_CAMERA_ANIME_GetData(anime)->frames == 0) {
        FIELD_CAMERA_ANIME_ApplyEndParam(anime);
        return;
    }
    FIELD_CAMERA_ANIME_StartMoveTasks(anime);
}

void FIELD_CAMERA_ANIME_Restore(FieldCameraAnime *anime)
{
    if (anime->isSetUp != 0)
        FIELD_CAMERA_ANIME_RestoreCameraState(anime);
}

FieldCameraAnime *FIELD_CAMERA_ANIME_Alloc(u16 heapId)
{
    return GFL_HEAP_Alloc(heapId, sizeof(FieldCameraAnime), 0, (char *)d_021DDA38, 0xee);
}

void FIELD_CAMERA_ANIME_Free(FieldCameraAnime *anime)
{
    GFL_HEAP_Free(anime);
}

void FIELD_CAMERA_ANIME_Init(FieldCameraAnime *anime, FieldMap *fieldMap)
{
    MI_CpuFill8(anime, 0, sizeof(FieldCameraAnime));
    anime->fieldMap = fieldMap;
    anime->camera = FIELDMAP_GetCamera(fieldMap);
    anime->data = 0;
    anime->isSetUp = 0;
    anime->savedTrace = 0;
    anime->savedTarget = 0;
    anime->targetDetached = 0;
}

u32 FIELD_CAMERA_ANIME_SaveCameraState(FieldCameraAnime *anime)
{
    FieldMap *fieldMap = anime->fieldMap;
    FieldCamera *camera = anime->camera;
    FieldCameraAnimeData *data = FIELD_CAMERA_ANIME_GetData(anime);
    if (FIELDMAP_GetMoveKind(fieldMap) == 1)
        FIELD_NOGRID_MAPPER_SetActive(FIELDMAP_GetNogridMapper(fieldMap), 0);
    if (data->detachTarget != 0) {
        if (FIELD_CAMERA_GetTraceTarget(anime->camera) != 0) {
            anime->targetDetached = 1;
            anime->savedTarget = FIELD_CAMERA_GetTraceTarget(camera);
            FIELD_CAMERA_StopTargetTrace(camera);
        }
    }
    if (data->stopTrace != 0) {
        anime->savedTrace = FIELD_CAMERA_GetAreasEnabled(camera);
        FIELD_CAMERA_SetAreasEnabled(camera, 0);
    }
    FLD_SCENEAREA_SetEnabled((struct FldSceneArea *)FIELDMAP_GetSceneArea(fieldMap), 0);
    anime->isSetUp = 1;
    return anime->isSetUp;
}

void FIELD_CAMERA_ANIME_SaveCameraMode(FieldCameraAnime *anime)
{
    FieldCamera *camera = anime->camera;
    anime->savedMode = FIELD_CAMERA_GetMode(camera);
    FIELD_CAMERA_SetMode(camera, 0);
}

void FIELD_CAMERA_ANIME_RestoreCameraState(FieldCameraAnime *anime)
{
    FieldMap *fieldMap = anime->fieldMap;
    FieldCamera *camera = anime->camera;
    FieldCameraAnimeData *data = FIELD_CAMERA_ANIME_GetData(anime);
    FLD_SCENEAREA_SetEnabled((struct FldSceneArea *)FIELDMAP_GetSceneArea(fieldMap), 1);
    if (data->stopTrace != 0)
        FIELD_CAMERA_SetAreasEnabled(camera, anime->savedTrace);
    if (anime->targetDetached != 0)
        FIELD_CAMERA_SetTraceTarget(camera, anime->savedTarget);
    FIELD_CAMERA_SetMode(camera, anime->savedMode);
    if (FIELDMAP_GetMoveKind(fieldMap) == 1)
        FIELD_NOGRID_MAPPER_SetActive(FIELDMAP_GetNogridMapper(fieldMap), 1);
}

void FIELD_CAMERA_ANIME_SetAnglesFromPos(FieldCamera *camera)
{
    VecFx32 target, pos, dir;
    fx32 distance;
    u16 pitch, yaw;
    FIELD_CAMERA_GetEye(camera, &pos);
    FIELD_CAMERA_GetTarget(camera, &target);
    VEC_Subtract(&pos, &target, &dir);
    FIELD_CAMERA_GetVectorAngles(&dir, &pitch, &yaw, &distance);
    FIELD_CAMERA_SetDistance(camera, distance);
    FIELD_CAMERA_SetPitch(camera, pitch);
    FIELD_CAMERA_SetYaw(camera, yaw);
}

void FIELD_CAMERA_ANIME_SetTargetFromCurrent(FieldCamera *camera)
{
    VecFx32 target;
    FIELD_CAMERA_GetTarget(camera, &target);
    FIELD_CAMERA_SetTarget(camera, &target);
}

void FIELD_CAMERA_ANIME_ReadParam(FieldCamera *camera, FieldCameraParam *param)
{
    VecFx32 target;
    VecFx32 pos;
    VecFx32 dir;
    FIELD_CAMERA_GetEye(camera, &pos);
    FIELD_CAMERA_GetTarget(camera, &target);
    VEC_Subtract(&pos, &target, &dir);
    FIELD_CAMERA_GetVectorAngles(&dir, &param->pitch, &param->yaw, &param->distance);
    FIELD_CAMERA_GetTarget(camera, &param->target);
    FIELD_CAMERA_GetTargetShift(camera, &param->shift);
}

void FIELD_CAMERA_ANIME_ApplyEndParam(FieldCameraAnime *anime)
{
    FieldCamera *camera = anime->camera;
    FieldCameraParam *end = &FIELD_CAMERA_ANIME_GetData(anime)->end;
    FIELD_CAMERA_SetPitch(camera, end->pitch);
    FIELD_CAMERA_SetYaw(camera, end->yaw);
    FIELD_CAMERA_SetDistance(camera, end->distance);
    FIELD_CAMERA_SetTarget(camera, &end->target);
    FIELD_CAMERA_SetTargetShift(camera, &end->shift);
}

void FIELD_CAMERA_ANIME_StartMoveTasks(FieldCameraAnime *anime)
{
    FieldMap *fieldMap = anime->fieldMap;
    FieldCameraAnimeData *data = FIELD_CAMERA_ANIME_GetData(anime);
    u32 frames = data->frames;
    FieldCameraParam *end = &data->end;
    struct FieldTask *pitchTask;
    struct FieldTask *yawTask;
    struct FieldTask *distanceTask;
    struct FieldTask *targetTask;
    struct FieldTask *shiftTask;
    pitchTask = FIELD_TASK_CreateCameraPitchTween(fieldMap, frames, end->pitch);
    yawTask = FIELD_TASK_CreateCameraYawTween(fieldMap, frames, end->yaw);
    distanceTask = FIELD_TASK_CreateCameraDistanceTween(fieldMap, frames, end->distance);
    targetTask = FIELD_TASK_CreateCameraLerp(fieldMap, frames, &data->start.target, &end->target);
    shiftTask = FIELD_TASK_CreateCameraTargetTween(fieldMap, frames, &end->shift);
    /* the original reuses the field map variable for the task manager */
    fieldMap = (FieldMap *)FIELDMAP_GetTaskManager(fieldMap);
    FIELD_TASK_MANAGER_AddTask((struct FieldTaskManager *)fieldMap, pitchTask, 0);
    FIELD_TASK_MANAGER_AddTask((struct FieldTaskManager *)fieldMap, yawTask, 0);
    FIELD_TASK_MANAGER_AddTask((struct FieldTaskManager *)fieldMap, distanceTask, 0);
    FIELD_TASK_MANAGER_AddTask((struct FieldTaskManager *)fieldMap, targetTask, 0);
    FIELD_TASK_MANAGER_AddTask((struct FieldTaskManager *)fieldMap, shiftTask, 0);
}

FieldCamera *FIELD_CAMERA_ANIME_GetCamera(FieldCameraAnime *anime)
{
    return anime->camera;
}

FieldCameraAnimeData *FIELD_CAMERA_ANIME_GetData(FieldCameraAnime *anime)
{
    return anime->data;
}
