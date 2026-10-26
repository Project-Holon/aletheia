#ifndef GAME_OV021_FIELD_TASK_MANAGER_H
#define GAME_OV021_FIELD_TASK_MANAGER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_task_manager.c, prototypes copied from their definitions. */

struct CameraDistanceTween;
struct CameraAngleTween;
struct MmdlSpinTask;
struct PosTween;
struct PlayerDropTask;
struct WaitTask;
struct FadeTask;
struct MmdlOffsetTween;
struct CameraLerpTask;
struct Mmdl;
struct RepeatEffectTask;
typedef struct CameraDistanceTween CameraDistanceTween;
typedef struct CameraAngleTween CameraAngleTween;
typedef struct MmdlSpinTask MmdlSpinTask;
typedef struct PosTween PosTween;
typedef struct PlayerDropTask PlayerDropTask;
typedef struct WaitTask WaitTask;
typedef struct FadeTask FadeTask;
typedef struct MmdlOffsetTween MmdlOffsetTween;
typedef struct CameraLerpTask CameraLerpTask;
typedef struct RepeatEffectTask RepeatEffectTask;

#include "../ov021/field_task_types.h"
#include "../types.h"
#include "../ov020/event_mapchange_types.h"
#include "../ov010/fldmmdl_types.h"
#include "../sdk_fx.h"

FieldTaskManager *FIELD_TASK_MANAGER_Create(int count, int heapId);
void FIELD_TASK_MANAGER_Delete(FieldTaskManager *manager);
void FIELD_TASK_MANAGER_Update(FieldTaskManager *manager);
void FIELD_TASK_MANAGER_AddTask(FieldTaskManager *manager, FieldTask *task, FieldTask *prerequisite);
u8 FIELD_TASK_MANAGER_CountUsedSlots(FieldTaskManager *manager);
int FIELD_TASK_MANAGER_IsEmpty(FieldTaskManager *manager);
void FIELD_TASK_MANAGER_SetSlot(FieldTaskManager *list, u8 slot, FieldTask *task, FieldTask *prerequisite);
void FIELD_TASK_MANAGER_FreeSlot(FieldTaskManager *list, u8 slot);
void FIELD_TASK_MANAGER_UpdateSlot(FieldTaskManager *list, u8 slot);
void FIELD_TASK_MANAGER_StartSlotIfPrerequisiteDone(FieldTaskManager *list, u8 slot);
void FIELD_TASK_MANAGER_FreeSlotIfFinished(FieldTaskManager *list, u8 slot);
FieldTask *FIELD_TASK_CreateCameraDistanceTween(FieldMap *fieldMap, u16 frames, fx32 targetDistance);
int FIELD_TASK_UpdateCameraDistanceTween(void *arg);
FieldTask *FIELD_TASK_CreateCameraYawTween(FieldMap *fieldMap, u32 frames, u32 targetAngle);
FieldTask *FIELD_TASK_CreateCameraPitchTween(FieldMap *fieldMap, u32 frames, u32 targetAngle);
void FIELD_TASK_InitCameraAngleTween(CameraAngleTween *tween);
void FIELD_TASK_StepCameraAngleTween(CameraAngleTween *tween);
int FIELD_TASK_UpdateCameraAngleTween(void *arg);
FieldTask *FIELD_TASK_CreatePlayerSpinLinear(FieldMap *fieldMap, u32 frames, u32 spins);
FieldTask *FIELD_TASK_CreateMmdlSpinLinear(FieldMap *fieldMap, u16 frames, int spins, Mmdl *mmdl);
FieldTask *FIELD_TASK_CreatePlayerSpinEaseIn(FieldMap *fieldMap, u16 frames, int spins);
FieldTask *FIELD_TASK_CreatePlayerSpinEaseOut(FieldMap *fieldMap, u16 frames, int spins, int endDirection);
u16 FIELD_TASK_GetSpinAcmdLinear(float frame, float frames, float spins);
u16 FIELD_TASK_GetSpinAcmdEaseIn(float frame, float frames, float spins);
u16 FIELD_TASK_GetSpinAcmdEaseOut(float frame, float frames, float spins);
int FIELD_TASK_UpdateSpinLinear(void *arg);
int FIELD_TASK_UpdateSpinEaseIn(void *arg);
int FIELD_TASK_UpdateSpinEaseOut(void *arg);
FieldTask *FIELD_TASK_CreatePlayerPosTween(FieldMap *fieldMap, u32 frames, VecFx32 *to);
int FIELD_TASK_UpdatePlayerPosTween(void *arg);
FieldTask *FIELD_TASK_CreatePlayerDrop(FieldMap *fieldMap, Mmdl *mmdl, int frames, int height);
void FIELD_TASK_CalcDropOffset(VecFx32 *out, float frame, float frames, float height);
int FIELD_TASK_UpdatePlayerDrop(void *arg);
FieldTask *FIELD_TASK_CreateWait(FieldMap *fieldMap, u16 frames);
int FIELD_TASK_UpdateWait(void *arg);
FieldTask *FIELD_TASK_CreateFade(FieldMap *fieldMap, u32 fadeMode, u32 startBrightness, u32 endBrightness, u32 wait);
int FIELD_TASK_UpdateFade(void *arg);
FieldTask *FIELD_TASK_CreatePlayerDrawOffsetTween(FieldMap *fieldMap, int frames, const VecFx32 *offset);
FieldTask *FIELD_TASK_CreateMmdlDrawOffsetTween(FieldMap *fieldMap, int frames, const VecFx32 *offset, Mmdl *mmdl);
FieldTask *FIELD_TASK_CreateMmdlPosOffsetTween(FieldMap *fieldMap, int frames, const VecFx32 *offset, Mmdl *mmdl);
void FIELD_TASK_CalcOffsetByProgress(VecFx32 *out, u16 frame, VecFx32 *offset, u16 frames);
int FIELD_TASK_UpdateMmdlDrawOffsetTween(void *arg);
int FIELD_TASK_UpdateMmdlPosOffsetTween(void *arg);
FieldTask *FIELD_TASK_CreateCameraTargetTween(FieldMap *fieldMap, u32 frames, const VecFx32 *to);
int FIELD_TASK_UpdateCameraTargetTween(void *arg);
FieldTask *FIELD_TASK_CreateCameraLerp(FieldMap *fieldMap, u16 frames, const VecFx32 *start, const VecFx32 *end);
int FIELD_TASK_UpdateCameraLerp(void *arg);
FieldTask *FIELD_TASK_CreateRepeatPlayerEffect(FieldMap *fieldMap, struct Mmdl *unused, u16 frames, u16 interval);
int FIELD_TASK_UpdateRepeatPlayerEffect(void *arg);
/* END mkheaders: generated region */

#endif
