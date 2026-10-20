/*
 * file:     field_task_manager.c
 * unit:     yes
 * function: FIELD_TASK_MANAGER_Create, FIELD_TASK_MANAGER_Delete, FIELD_TASK_MANAGER_Update, FIELD_TASK_MANAGER_AddTask, FIELD_TASK_MANAGER_CountUsedSlots, FIELD_TASK_MANAGER_IsEmpty, FIELD_TASK_MANAGER_SetSlot, FIELD_TASK_MANAGER_FreeSlot, FIELD_TASK_MANAGER_UpdateSlot, FIELD_TASK_MANAGER_StartSlotIfPrerequisiteDone, FIELD_TASK_MANAGER_FreeSlotIfFinished, FIELD_TASK_CreateCameraDistanceTween, FIELD_TASK_UpdateCameraDistanceTween, FIELD_TASK_CreateCameraYawTween, FIELD_TASK_CreateCameraPitchTween, FIELD_TASK_InitCameraAngleTween, FIELD_TASK_StepCameraAngleTween, FIELD_TASK_UpdateCameraAngleTween, FIELD_TASK_CreatePlayerSpinLinear, FIELD_TASK_CreateMmdlSpinLinear, FIELD_TASK_CreatePlayerSpinEaseIn, FIELD_TASK_CreatePlayerSpinEaseOut, FIELD_TASK_GetSpinAcmdLinear, FIELD_TASK_GetSpinAcmdEaseIn, FIELD_TASK_GetSpinAcmdEaseOut, FIELD_TASK_UpdateSpinLinear, FIELD_TASK_UpdateSpinEaseIn, FIELD_TASK_UpdateSpinEaseOut, FIELD_TASK_CreatePlayerPosTween, FIELD_TASK_UpdatePlayerPosTween, FIELD_TASK_CreatePlayerDrop, FIELD_TASK_CalcDropOffset, FIELD_TASK_UpdatePlayerDrop, FIELD_TASK_CreateWait, FIELD_TASK_UpdateWait, FIELD_TASK_CreateFade, FIELD_TASK_UpdateFade, FIELD_TASK_CreatePlayerDrawOffsetTween, FIELD_TASK_CreateMmdlDrawOffsetTween, FIELD_TASK_CreateMmdlPosOffsetTween, FIELD_TASK_CalcOffsetByProgress, FIELD_TASK_UpdateMmdlDrawOffsetTween, FIELD_TASK_UpdateMmdlPosOffsetTween, FIELD_TASK_CreateCameraTargetTween, FIELD_TASK_UpdateCameraTargetTween, FIELD_TASK_CreateCameraLerp, FIELD_TASK_UpdateCameraLerp, FIELD_TASK_CreateRepeatPlayerEffect, FIELD_TASK_UpdateRepeatPlayerEffect
 * address:  0x021C6D10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from field_task_manager.c, field_flash.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   d_021DE4E4     0x021DE4E4  data  ov021  a4
 *   FIELD_TASK_MANAGER_FreeSlot  0x021C6E74  thumb  ov021
 *   FIELD_TASK_MANAGER_UpdateSlot  0x021C6E94  thumb  ov021
 *   FIELD_TASK_MANAGER_StartSlotIfPrerequisiteDone  0x021C6EA8  thumb  ov021
 *   FIELD_TASK_MANAGER_FreeSlotIfFinished  0x021C6EDC  thumb  ov021
 *   FIELD_TASK_MANAGER_SetSlot  0x021C6E5C  thumb  ov021
 *   FIELD_TASK_MANAGER_CountUsedSlots  0x021C6E20  thumb  ov021
 *   FIELD_TASK_Delete 0x021C6CA8 thumb ov021
 *   FIELD_TASK_Start 0x021C6CC4 thumb ov021
 *   FIELD_TASK_Update  0x021C6CBC  thumb  ov021
 *   FIELD_TASK_GetState  0x021C6CE0  thumb  ov021
 *   FIELD_TASK_IsFinished  0x021C6CD0  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELD_TASK_Create  0x021C6C70  thumb  ov021
 *   FIELD_TASK_GetWork  0x021C6CCC  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb
 *   FIELD_CAMERA_GetDistance  0x0218ED54  thumb
 *   FIELD_CAMERA_GetMode  0x0218E138  thumb
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb
 *   FIELD_CAMERA_SetDistance  0x0218ED58  thumb
 *   FIELD_CAMERA_GetYaw  0x0218ED40  thumb  ov021
 *   FIELD_CAMERA_GetPitch  0x0218ED2C  thumb  ov021
 *   FIELD_CAMERA_SetPitch  0x0218ED34  thumb  ov021
 *   FIELD_CAMERA_SetYaw  0x0218ED48  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   gSpinAcmdLinear  0x021DAAC0  data  ov021  a2
 *   gSpinAcmdEaseIn  0x021DAAB8  data  ov021  a2
 *   gSpinAcmdEaseOut     0x021DAAC8  data  ov021  a2
 *   sqrt  0x0209C5E0  arm
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   FLDMMDL_MOVE_UpdateHeight  0x02164010  thumb  ov010
 *   BUTTON_MAN_ScaleVec  0x020520A4  arm
 *   VEC_Add  0x0207C9D0  arm
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   FLDEFF_KEMURI_Start  0x021AC528  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FADE_Start  0x0204E720  arm
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FIELD_CAMERA_GetTargetShift  0x0218ECC4  thumb  ov021
 *   FIELD_CAMERA_SetTargetShift  0x0218ECD4  thumb  ov021
 *   VEC_Subtract  0x0207CA00  arm
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb  ov021
 *   VEC_MultAdd  0x0207CEE4  arm
 *   FLDEFF_IWAKUDAKI_Start  0x021ADD7C  thumb  ov021
 *   _f2d                         0x0209BD38  arm
 *   _fadd                        0x0209C95C  arm
 *   _fdiv                        0x0209CE10  arm
 *   _ffix                        0x0209C494  arm
 *   _ffixu                       0x0209C4C8  arm
 *   _fflt                        0x0209BDBC  arm
 *   _ffltu                       0x0209BE04  arm
 *   _fgr                         0x0209BBB0  arm
 *   _fmul                        0x0209C77C  arm
 *   _fsub                        0x0209CB8C  arm
 */
#include "field_task_types.h"
#include "field_flash_shared_types.h"

#include "../arm9/gfl_heap_wrap.h"


extern void FIELD_TASK_MANAGER_SetSlot(FieldTaskManager *manager, u8 slot, FieldTask *task, FieldTask *prerequisite);

extern void FIELD_TASK_MANAGER_FreeSlot(FieldTaskManager *manager, u8 slot);

extern void FIELD_TASK_MANAGER_UpdateSlot(FieldTaskManager *manager, u8 slot);

extern void FIELD_TASK_MANAGER_StartSlotIfPrerequisiteDone(FieldTaskManager *manager, u8 slot);

extern void FIELD_TASK_MANAGER_FreeSlotIfFinished(FieldTaskManager *manager, u8 slot);

extern int d_021DE4E4;

#include "field_task.h"


FieldTaskManager *FIELD_TASK_MANAGER_Create(int count, int heapId);

void FIELD_TASK_MANAGER_Delete(FieldTaskManager *manager);

void FIELD_TASK_MANAGER_Update(FieldTaskManager *manager);

void FIELD_TASK_MANAGER_AddTask(FieldTaskManager *manager, FieldTask *task, FieldTask *prerequisite);

u8 FIELD_TASK_MANAGER_CountUsedSlots(FieldTaskManager *manager);

int FIELD_TASK_MANAGER_IsEmpty(FieldTaskManager *manager);

/* Allocates a manager with count slots. */
FieldTaskManager *FIELD_TASK_MANAGER_Create(int count, int heapId)
{
    FieldTaskManager *manager = GFL_HEAP_Alloc(heapId, 12, 0, (const char *)&d_021DE4E4, 0x34);

    manager->count = count;
    manager->tasks = GFL_HEAP_Alloc(heapId, count * 4, 1, (const char *)&d_021DE4E4, 0x36);
    manager->prerequisites = GFL_HEAP_Alloc(heapId, count * 4, 1, (const char *)&d_021DE4E4, 0x37);
    return manager;
}

/* Frees every task, both slot tables and the manager. */
void FIELD_TASK_MANAGER_Delete(FieldTaskManager *manager)
{
    int slot;
    for (slot = 0; slot < manager->count; slot++)
        FIELD_TASK_MANAGER_FreeSlot(manager, slot);
    GFL_HEAP_Free(manager->tasks);
    GFL_HEAP_Free(manager->prerequisites);
    GFL_HEAP_Free(manager);
}

/* Per frame: run the running tasks, start tasks whose prerequisite finished, free finished tasks. */
void FIELD_TASK_MANAGER_Update(FieldTaskManager *manager)
{
    int slot;

    for (slot = 0; slot < manager->count; slot++)
        FIELD_TASK_MANAGER_UpdateSlot(manager, slot);
    for (slot = 0; slot < manager->count; slot++)
        FIELD_TASK_MANAGER_StartSlotIfPrerequisiteDone(manager, slot);
    for (slot = 0; slot < manager->count; slot++)
        FIELD_TASK_MANAGER_FreeSlotIfFinished(manager, slot);
}

/* Puts a task in the first free slot; starts it now unless it has a prerequisite.
 * With no free slot the task is freed. */
void FIELD_TASK_MANAGER_AddTask(FieldTaskManager *manager, FieldTask *task, FieldTask *prerequisite)
{
    int slot;

    for (slot = 0; slot < manager->count; slot++) {
        if (manager->tasks[slot] == 0) {
            FIELD_TASK_MANAGER_SetSlot(manager, slot, task, prerequisite);
            if (prerequisite == 0)
                FIELD_TASK_Start(task);
            return;
        }
    }
    FIELD_TASK_Delete(task);
}

/* Returns the number of used slots. */
u8 FIELD_TASK_MANAGER_CountUsedSlots(FieldTaskManager *manager)
{
    int slot;
    u8 used = 0;
    for (slot = 0; slot < manager->count; slot++) {
        if (manager->tasks[slot] != 0)
            used++;
    }
    return used;
}

/* TRUE when the manager has no task queued. */
int FIELD_TASK_MANAGER_IsEmpty(FieldTaskManager *manager)
{
    if (FIELD_TASK_MANAGER_CountUsedSlots(manager) == 0) {
        return 1;
    }
    return 0;
}

#define FX_FX32_TO_F32(x) ((f32)((x) / 4096.0f))

#define FX32_ONE 0x1000

#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))

#include "../types.h"

typedef struct FieldEffectCtrl FieldEffectCtrl;

/* The task update function receives its work pointer and returns 1 when finished. */
typedef int (*FieldTaskUpdateFunc)();

/* Camera distance tween: linear in float from the current distance to the target. */
typedef struct CameraDistanceTween {
    FieldMap *fieldMap;
    u8 state;
    u8 pad5;
    u16 frame;
    u16 frames;
    u16 padA;
    fx32 startDistance;
    fx32 targetDistance;
} CameraDistanceTween;

enum CameraAngleAxis {
    CAMERA_ANGLE_AXIS_YAW = 0,
    CAMERA_ANGLE_AXIS_PITCH = 1
};

/* Camera angle tween: smoothstep from the current angle to the target angle. */
typedef struct CameraAngleTween {
    FieldMap *fieldMap;
    FieldCamera *camera;
    u32 axis;
    u8 state;
    u8 padD;
    u16 frame;
    u16 frames;
    u16 pad12;
    u32 from;
    u32 to;
} CameraAngleTween;

/* Spin task: turns a field model through its four facing animations. */
typedef struct MmdlSpinTask {
    FieldMap *fieldMap;
    Mmdl *mmdl;
    u16 frame;
    u16 frames;
    u8 spins;
    u8 padD;
    u16 endDirection;
} MmdlSpinTask;

typedef struct SpinAcmdTable {
    u16 acmd[4];
} SpinAcmdTable;

/* Linear tween of a position between two points (player or camera target). */
typedef struct PosTween {
    u8 state;
    u8 pad1[3];
    FieldMap *fieldMap;
    int frame;
    int frames;
    VecFx32 from;
    VecFx32 to;
} PosTween;

/* Player drop task: draw offset falls from a height to the ground. */
typedef struct PlayerDropTask {
    u8 state;
    FieldMap *fieldMap;
    u16 frame;
    u16 frames;
    float height;
    Mmdl *mmdl;
} PlayerDropTask;

typedef struct WaitTask {
    u16 frame;
    u16 frames;
} WaitTask;

typedef struct FadeTask {
    FieldMap *fieldMap;
    u32 fadeMode;
    u32 startBrightness;
    u32 endBrightness;
    u32 wait;
} FadeTask;

/* Field model offset tween (draw offset or position offset). */
typedef struct MmdlOffsetTween {
    u8 state;
    u8 pad1[3];
    FieldMap *fieldMap;
    int reverse;
    u16 frame;
    u16 frames;
    VecFx32 offset;
    VecFx32 startPos;
    Mmdl *mmdl;
} MmdlOffsetTween;

/* Camera target linear interpolation. */
typedef struct CameraLerpTask {
    u8 state;
    u8 pad1[3];
    FieldMap *fieldMap;
    u16 frame;
    u16 frames;
    VecFx32 start;
    VecFx32 end;
    VecFx32 delta;
    int savedFlag;
} CameraLerpTask;

/* Calls a player effect every `interval` frames for `frames` frames. */
typedef struct RepeatEffectTask {
    FieldMap *fieldMap;
    FieldEffectCtrl *effectCtrl;
    Mmdl *mmdl;
    u8 state;
    u8 padD;
    u16 frame;
    u16 frames;
    u16 interval;
} RepeatEffectTask;




#include "fieldmap.h"

struct FieldTask;


struct FieldCamera;

#include "field_camera.h"









#include "field_player.h"

#include "../ov010/fldmmdl.h"

#include "../arm9/cw_runtime.h"





#include "../ov010/fldmmdl_move.h"

#include "../arm9/button_man.h"

#include "../arm9/fx_vec.h"
struct FieldMap;
struct FieldEffectSys;

struct VecFx32;
struct Mmdl;

struct FieldEffectSys;

#include "fldeff_kemuri.h"

#include "../arm9/gfl_use.h"

#include "../arm9/fade.h"








#include "fldeff_iwakudaki.h"

/* Spin acmd tables (u16 per facing direction) and the FLD3D_CI id table (key, id pairs). */
extern SpinAcmdTable gSpinAcmdLinear;

extern SpinAcmdTable gSpinAcmdEaseIn;

extern SpinAcmdTable gSpinAcmdEaseOut;

void FIELD_TASK_MANAGER_SetSlot(FieldTaskManager *list, u8 slot, FieldTask *task, FieldTask *prerequisite);

void FIELD_TASK_MANAGER_FreeSlot(FieldTaskManager *list, u8 slot);

void FIELD_TASK_MANAGER_UpdateSlot(FieldTaskManager *list, u8 slot);

void FIELD_TASK_MANAGER_StartSlotIfPrerequisiteDone(FieldTaskManager *list, u8 slot);

void FIELD_TASK_MANAGER_FreeSlotIfFinished(FieldTaskManager *list, u8 slot);

FieldTask *FIELD_TASK_CreateCameraDistanceTween(FieldMap *fieldMap, u16 frames, fx32 targetDistance);

int FIELD_TASK_UpdateCameraDistanceTween(CameraDistanceTween *tween);

FieldTask *FIELD_TASK_CreateCameraYawTween(FieldMap *fieldMap, u32 frames, u32 targetAngle);

FieldTask *FIELD_TASK_CreateCameraPitchTween(FieldMap *fieldMap, u32 frames, u32 targetAngle);

void FIELD_TASK_InitCameraAngleTween(CameraAngleTween *tween);

void FIELD_TASK_StepCameraAngleTween(CameraAngleTween *tween);

int FIELD_TASK_UpdateCameraAngleTween(CameraAngleTween *tween);

FieldTask *FIELD_TASK_CreatePlayerSpinLinear(FieldMap *fieldMap, u32 frames, u32 spins);

FieldTask *FIELD_TASK_CreateMmdlSpinLinear(FieldMap *fieldMap, u16 frames, int spins, Mmdl *mmdl);

FieldTask *FIELD_TASK_CreatePlayerSpinEaseIn(FieldMap *fieldMap, u16 frames, int spins);

FieldTask *FIELD_TASK_CreatePlayerSpinEaseOut(FieldMap *fieldMap, u16 frames, int spins, int endDirection);

u16 FIELD_TASK_GetSpinAcmdLinear(float frame, float frames, float spins);

u16 FIELD_TASK_GetSpinAcmdEaseIn(float frame, float frames, float spins);

u16 FIELD_TASK_GetSpinAcmdEaseOut(float frame, float frames, float spins);

int FIELD_TASK_UpdateSpinLinear(MmdlSpinTask *task);

int FIELD_TASK_UpdateSpinEaseIn(MmdlSpinTask *task);

int FIELD_TASK_UpdateSpinEaseOut(MmdlSpinTask *task);

FieldTask *FIELD_TASK_CreatePlayerPosTween(FieldMap *fieldMap, u32 frames, VecFx32 *to);

int FIELD_TASK_UpdatePlayerPosTween(PosTween *tween);

FieldTask *FIELD_TASK_CreatePlayerDrop(FieldMap *fieldMap, Mmdl *mmdl, int frames, int height);

void FIELD_TASK_CalcDropOffset(VecFx32 *out, float frame, float frames, float height);

int FIELD_TASK_UpdatePlayerDrop(PlayerDropTask *task);

FieldTask *FIELD_TASK_CreateWait(FieldMap *fieldMap, u16 frames);

int FIELD_TASK_UpdateWait(WaitTask *task);

FieldTask *FIELD_TASK_CreateFade(FieldMap *fieldMap, u32 fadeMode, u32 startBrightness, u32 endBrightness, u32 wait);

int FIELD_TASK_UpdateFade(FadeTask *task);

FieldTask *FIELD_TASK_CreatePlayerDrawOffsetTween(FieldMap *fieldMap, int frames, const VecFx32 *offset);

FieldTask *FIELD_TASK_CreateMmdlDrawOffsetTween(FieldMap *fieldMap, int frames, const VecFx32 *offset, Mmdl *mmdl);

FieldTask *FIELD_TASK_CreateMmdlPosOffsetTween(FieldMap *fieldMap, int frames, const VecFx32 *offset, Mmdl *mmdl);

void FIELD_TASK_CalcOffsetByProgress(VecFx32 *out, u16 frame, VecFx32 *offset, u16 frames);

int FIELD_TASK_UpdateMmdlDrawOffsetTween(MmdlOffsetTween *tween);

int FIELD_TASK_UpdateMmdlPosOffsetTween(MmdlOffsetTween *tween);

FieldTask *FIELD_TASK_CreateCameraTargetTween(FieldMap *fieldMap, u32 frames, const VecFx32 *to);

int FIELD_TASK_UpdateCameraTargetTween(PosTween *tween);

FieldTask *FIELD_TASK_CreateCameraLerp(FieldMap *fieldMap, u16 frames, const VecFx32 *start, const VecFx32 *end);

int FIELD_TASK_UpdateCameraLerp(CameraLerpTask *task);

FieldTask *FIELD_TASK_CreateRepeatPlayerEffect(FieldMap *fieldMap, struct Mmdl *unused, u16 frames, u16 interval);

int FIELD_TASK_UpdateRepeatPlayerEffect(RepeatEffectTask *task);

void FIELD_TASK_MANAGER_SetSlot(FieldTaskManager *list, u8 slot, FieldTask *task, FieldTask *prerequisite)
{
    if (list->tasks[slot] == 0) {
        list->tasks[slot] = task;
        list->prerequisites[slot] = prerequisite;
    }
}

void FIELD_TASK_MANAGER_FreeSlot(FieldTaskManager *list, u8 slot)
{
    if (list->tasks[slot] != 0) {
        FIELD_TASK_Delete(list->tasks[slot]);
        list->tasks[slot] = 0;
        list->prerequisites[slot] = 0;
    }
}

void FIELD_TASK_MANAGER_UpdateSlot(FieldTaskManager *list, u8 slot)
{
    if (list->tasks[slot] != 0)
        FIELD_TASK_Update(list->tasks[slot]);
}

void FIELD_TASK_MANAGER_StartSlotIfPrerequisiteDone(FieldTaskManager *list, u8 slot)
{
    if (list->tasks[slot] != 0 && list->prerequisites[slot] != 0) {
        if (FIELD_TASK_GetState(list->tasks[slot]) == 0 && FIELD_TASK_GetState(list->prerequisites[slot]) == 2)
            FIELD_TASK_Start(list->tasks[slot]);
    }
}

void FIELD_TASK_MANAGER_FreeSlotIfFinished(FieldTaskManager *list, u8 slot)
{
    if (list->tasks[slot] != 0 && FIELD_TASK_IsFinished(list->tasks[slot]) == 1)
        FIELD_TASK_MANAGER_FreeSlot(list, slot);
}

FieldTask *FIELD_TASK_CreateCameraDistanceTween(FieldMap *fieldMap, u16 frames, fx32 targetDistance)
{
    FieldTask *task = FIELD_TASK_Create(FIELDMAP_GetHeapId(fieldMap), 0x14, (FieldTaskCheckFunc)FIELD_TASK_UpdateCameraDistanceTween);
    CameraDistanceTween *tween = (CameraDistanceTween *)FIELD_TASK_GetWork(task);
    tween->state = 0;
    tween->fieldMap = fieldMap;
    tween->frame = 0;
    tween->frames = frames;
    tween->targetDistance = targetDistance;
    return task;
}

int FIELD_TASK_UpdateCameraDistanceTween(CameraDistanceTween *tween)
{
    FieldCamera *camera;
    u32 savedBits;
    f32 t;
    f32 start;
    f32 target;
    f32 distance;
    camera = FIELDMAP_GetCamera(tween->fieldMap);
    switch (tween->state) {
    case 0:
        tween->startDistance = FIELD_CAMERA_GetDistance(camera);
        tween->state++;
        break;
    case 1:
        tween->frame++;
        savedBits = FIELD_CAMERA_GetMode(camera);
        FIELD_CAMERA_SetMode(camera, 0);
        t = (f32)tween->frame / (f32)tween->frames;
        start = FX_FX32_TO_F32(tween->startDistance);
        target = FX_FX32_TO_F32(tween->targetDistance);
        distance = (1.0f - t) * start + t * target;
        FIELD_CAMERA_SetDistance(camera, FX_F32_TO_FX32(distance));
        FIELD_CAMERA_SetMode(camera, savedBits);
        if (tween->frames <= tween->frame)
            return 1;
        break;
    }
    return 0;
}

FieldTask *FIELD_TASK_CreateCameraYawTween(FieldMap *fieldMap, u32 frames, u32 targetAngle)
{
    FieldTask *task = FIELD_TASK_Create(FIELDMAP_GetHeapId(fieldMap), 0x1c, (FieldTaskCheckFunc)FIELD_TASK_UpdateCameraAngleTween);
    CameraAngleTween *tween = (CameraAngleTween *)FIELD_TASK_GetWork(task);
    tween->fieldMap = fieldMap;
    tween->camera = FIELDMAP_GetCamera(fieldMap);
    tween->state = 0;
    tween->axis = CAMERA_ANGLE_AXIS_YAW;
    tween->frame = 0;
    tween->frames = frames;
    tween->to = targetAngle;
    return task;
}

FieldTask *FIELD_TASK_CreateCameraPitchTween(FieldMap *fieldMap, u32 frames, u32 targetAngle)
{
    FieldTask *task = FIELD_TASK_Create(FIELDMAP_GetHeapId(fieldMap), 0x1c, (FieldTaskCheckFunc)FIELD_TASK_UpdateCameraAngleTween);
    CameraAngleTween *tween = (CameraAngleTween *)FIELD_TASK_GetWork(task);
    tween->fieldMap = fieldMap;
    tween->camera = FIELDMAP_GetCamera(fieldMap);
    tween->state = 0;
    tween->axis = CAMERA_ANGLE_AXIS_PITCH;
    tween->frame = 0;
    tween->frames = frames;
    tween->to = targetAngle;
    return task;
}

/* Reads the current angle and moves the target by a full turn when the short way round crosses the wrap. */
void FIELD_TASK_InitCameraAngleTween(CameraAngleTween *tween)
{
    u32 axis = tween->axis;
    u32 from = (u32)tween->camera;
    u32 to = tween->to;
    u32 diff;
    if (axis == 0 || axis != 1)
        from = FIELD_CAMERA_GetYaw((FieldCamera *)from);
    else
        from = FIELD_CAMERA_GetPitch((FieldCamera *)from);
    if (from < to) {
        diff = to - from;
        if (diff > 0x8000)
            from += 0x10000;
    } else if (to < from) {
        diff = from - to;
        if (diff > 0x8000)
            to += 0x10000;
    }
    tween->from = from;
    tween->to = to;
}

void FIELD_TASK_StepCameraAngleTween(CameraAngleTween *tween)
{
    u16 frames;
    FieldCamera *camera;
    f32 t;
    f32 s;
    u16 angle;
    u32 savedBits;
    frames = tween->frames;
    camera = tween->camera;
    tween->frame++;
    if (tween->frame > frames)
        return;
    t = (f32)tween->frame / (f32)frames;
    s = (3.0f + -2.0f * t) * (t * t);
    angle = (u16)((1.0f - s) * (f32)tween->from + s * (f32)tween->to);
    savedBits = FIELD_CAMERA_GetMode(camera);
    FIELD_CAMERA_SetMode(camera, 0);
    switch (tween->axis) {
    case CAMERA_ANGLE_AXIS_YAW:
        FIELD_CAMERA_SetYaw(camera, angle);
        break;
    case CAMERA_ANGLE_AXIS_PITCH:
        FIELD_CAMERA_SetPitch(camera, angle);
        break;
    }
    FIELD_CAMERA_SetMode(camera, savedBits);
}

int FIELD_TASK_UpdateCameraAngleTween(CameraAngleTween *tween)
{
    switch (tween->state) {
    case 0:
        FIELD_TASK_InitCameraAngleTween(tween);
        tween->state++;
        break;
    case 1:
        FIELD_TASK_StepCameraAngleTween(tween);
        if (tween->frames <= tween->frame)
            return 1;
        break;
    }
    return 0;
}

/* Spin the player: linear rate of turn. */
FieldTask *FIELD_TASK_CreatePlayerSpinLinear(FieldMap *fieldMap, u32 frames, u32 spins)
{
    u32 heapId = FIELDMAP_GetHeapId(fieldMap);
    FieldPlayer *player = FIELDMAP_GetFieldPlayer(fieldMap);
    FieldTask *task = FIELD_TASK_Create(heapId, 0x10, (FieldTaskCheckFunc)FIELD_TASK_UpdateSpinLinear);
    MmdlSpinTask *spin = (MmdlSpinTask *)FIELD_TASK_GetWork(task);
    Mmdl *mmdl;
    spin->fieldMap = fieldMap;
    mmdl = FIELD_PLAYER_GetMmdl(player);
    spin->mmdl = mmdl;
    spin->frame = 0;
    spin->frames = frames;
    spin->spins = spins;
    spin->endDirection = FLDMMDL_GetDirDisp(mmdl);
    return task;
}

/* Spin the given model: linear rate of turn. */
FieldTask *FIELD_TASK_CreateMmdlSpinLinear(FieldMap *fieldMap, u16 frames, int spins, Mmdl *mmdl)
{
    FieldTask *task;
    MmdlSpinTask *spin;
    task = FIELD_TASK_Create(FIELDMAP_GetHeapId(fieldMap), 0x10, (FieldTaskCheckFunc)FIELD_TASK_UpdateSpinLinear);
    spin = (MmdlSpinTask *)FIELD_TASK_GetWork(task);
    spin->fieldMap = fieldMap;
    spin->mmdl = mmdl;
    spin->frame = 0;
    spin->frames = frames;
    spin->spins = spins;
    spin->endDirection = FLDMMDL_GetDirDisp(mmdl);
    return task;
}

/* Spin the player: rate of turn grows (ease in). */
FieldTask *FIELD_TASK_CreatePlayerSpinEaseIn(FieldMap *fieldMap, u16 frames, int spins)
{
    FieldTask *task;
    MmdlSpinTask *spin;
    u32 heapId;
    FieldPlayer *player;
    Mmdl *mmdl;
    heapId = FIELDMAP_GetHeapId(fieldMap);
    player = FIELDMAP_GetFieldPlayer(fieldMap);
    task = FIELD_TASK_Create(heapId, 0x10, (FieldTaskCheckFunc)FIELD_TASK_UpdateSpinEaseIn);
    spin = (MmdlSpinTask *)FIELD_TASK_GetWork(task);
    spin->fieldMap = fieldMap;
    mmdl = FIELD_PLAYER_GetMmdl(player);
    spin->mmdl = mmdl;
    spin->frame = 0;
    spin->frames = frames;
    spin->spins = spins;
    spin->endDirection = FLDMMDL_GetDirDisp(mmdl);
    return task;
}

/* Spin the player: rate of turn drops (ease out); ends facing endDirection. */
FieldTask *FIELD_TASK_CreatePlayerSpinEaseOut(FieldMap *fieldMap, u16 frames, int spins, int endDirection)
{
    FieldTask *task;
    MmdlSpinTask *spin;
    u32 heapId;
    FieldPlayer *player;
    heapId = FIELDMAP_GetHeapId(fieldMap);
    player = FIELDMAP_GetFieldPlayer(fieldMap);
    task = FIELD_TASK_Create(heapId, 0x10, (FieldTaskCheckFunc)FIELD_TASK_UpdateSpinEaseOut);
    spin = (MmdlSpinTask *)FIELD_TASK_GetWork(task);
    spin->fieldMap = fieldMap;
    spin->mmdl = FIELD_PLAYER_GetMmdl(player);
    spin->frame = 0;
    spin->frames = frames;
    spin->spins = spins;
    spin->endDirection = endDirection;
    return task;
}

/*
 * Picks one of four halfwords from a table by (int)(4*c/b*a) % 4, in soft float.
 * The last multiply keeps its operand order only through a named float local;
 * inline it and the compiler swaps to a * f.
 */
u16 FIELD_TASK_GetSpinAcmdLinear(float frame, float frames, float spins)
{
    SpinAcmdTable table = gSpinAcmdLinear;
    float turnsPerFrame = 4.0f * spins / frames;
    int index = (int)(turnsPerFrame * frame);
    return table.acmd[index % 4];
}

u16 FIELD_TASK_GetSpinAcmdEaseIn(float frame, float frames, float spins)
{
    SpinAcmdTable table = gSpinAcmdEaseIn;
    float turnsPerFrame = 4.0f * spins / (frames * frames);
    float turns = turnsPerFrame * frame;
    int index = (int)(frame * turns);
    return table.acmd[index % 4];
}

u16 FIELD_TASK_GetSpinAcmdEaseOut(float frame, float frames, float spins)
{
    SpinAcmdTable table = gSpinAcmdEaseOut;
    float fullTurns = 4.0f * spins;
    float rate = fullTurns * fullTurns / frames;
    int index = (int)(float)sqrt((double)(rate * frame));
    return table.acmd[index % 4];
}

int FIELD_TASK_UpdateSpinLinear(MmdlSpinTask *task)
{
    Mmdl *mmdl;
    u16 acmd;
    mmdl = task->mmdl;
    FLDMMDL_SetAcmd(mmdl, FIELD_TASK_GetSpinAcmdLinear((float)(u32)task->frame, (float)(u32)task->frames, (float)(u32)task->spins));
    task->frame = task->frame + 1;
    if (task->frames < task->frame) {
        switch (task->endDirection) {
        default:
        case 0: acmd = 0; break;
        case 1: acmd = 1; break;
        case 2: acmd = 2; break;
        case 3: acmd = 3; break;
        }
        FLDMMDL_SetAcmd(mmdl, acmd);
        return 1;
    }
    return 0;
}

int FIELD_TASK_UpdateSpinEaseIn(MmdlSpinTask *task)
{
    Mmdl *mmdl;
    u16 acmd;
    mmdl = task->mmdl;
    FLDMMDL_SetAcmd(mmdl, FIELD_TASK_GetSpinAcmdEaseIn((float)(u32)task->frame, (float)(u32)task->frames, (float)(u32)task->spins));
    task->frame = task->frame + 1;
    if (task->frames < task->frame) {
        switch (task->endDirection) {
        default:
        case 0: acmd = 0; break;
        case 1: acmd = 1; break;
        case 2: acmd = 2; break;
        case 3: acmd = 3; break;
        }
        FLDMMDL_SetAcmd(mmdl, acmd);
        return 1;
    }
    return 0;
}

int FIELD_TASK_UpdateSpinEaseOut(MmdlSpinTask *task)
{
    Mmdl *mmdl;
    mmdl = task->mmdl;
    FLDMMDL_SetAcmd(mmdl, FIELD_TASK_GetSpinAcmdEaseOut((float)(u32)task->frame, (float)(u32)task->frames, (float)(u32)task->spins));
    task->frame = task->frame + 1;
    if (task->frames < task->frame) {
        FLDMMDL_SetDirDispCheckPause(mmdl, task->endDirection);
        return 1;
    }
    return 0;
}

/* The inline setter evaluates its arguments right to left, which puts y in r1 and z in r2
 * (three plain field copies swap them; a struct assignment is ldm/stm). */
static inline void setVec(VecFx32 *dst, int x, int y, int z)
{
    dst->x = x;
    dst->y = y;
    dst->z = z;
}

/* Tween the player position to a point. */
FieldTask *FIELD_TASK_CreatePlayerPosTween(FieldMap *fieldMap, u32 frames, VecFx32 *to)
{
    FieldTask *task = FIELD_TASK_Create(FIELDMAP_GetHeapId(fieldMap), 0x28, (FieldTaskCheckFunc)FIELD_TASK_UpdatePlayerPosTween);
    PosTween *tween = (PosTween *)FIELD_TASK_GetWork(task);
    tween->state = 0;
    tween->fieldMap = fieldMap;
    tween->frame = 0;
    tween->frames = frames;
    setVec(&tween->to, to->x, to->y, to->z);
    return task;
}

int FIELD_TASK_UpdatePlayerPosTween(PosTween *tween)
{
    FieldPlayer *player;
    Mmdl *mmdl;
    fx32 t;
    VecFx32 fromPart;
    VecFx32 toPart;
    VecFx32 pos;
    player = FIELDMAP_GetFieldPlayer(tween->fieldMap);
    mmdl = FIELD_PLAYER_GetMmdl(player);
    switch (tween->state) {
    case 0:
        FIELD_PLAYER_GetPos(player, &tween->from);
        tween->state++;
        break;
    case 1:
        tween->frame++;
        t = FX_F32_TO_FX32((f32)tween->frame / (f32)tween->frames);
        BUTTON_MAN_ScaleVec(&tween->from, FX32_ONE - t, &fromPart);
        BUTTON_MAN_ScaleVec(&tween->to, t, &toPart);
        VEC_Add(&fromPart, &toPart, &pos);
        FIELD_PLAYER_SetPos(player, &pos);
        FLDMMDL_MOVE_UpdateHeight(mmdl);
        if (tween->frames <= tween->frame)
            return 1;
        break;
    }
    return 0;
}

/* Player drop: the draw offset falls from `height` to the ground. */
FieldTask *FIELD_TASK_CreatePlayerDrop(FieldMap *fieldMap, Mmdl *mmdl, int frames, int height)
{
    FieldTask *task;
    PlayerDropTask *drop;
    task = FIELD_TASK_Create(FIELDMAP_GetHeapId(fieldMap), 0x14, (FieldTaskCheckFunc)FIELD_TASK_UpdatePlayerDrop);
    drop = (PlayerDropTask *)FIELD_TASK_GetWork(task);
    drop->state = 0;
    drop->fieldMap = fieldMap;
    drop->frame = 0;
    drop->frames = frames;
    drop->height = (float)height;
    drop->mmdl = mmdl;
    return task;
}

#undef FX_F32_TO_FX32

#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))

/* Draw offset y of a falling model: height * (1 - (frame / frames)^2). */
void FIELD_TASK_CalcDropOffset(VecFx32 *out, float frame, float frames, float height)
{
    float rate = height / (frames * frames);
    float drop = rate * frame;
    float offsetY = height - frame * drop;
    out->x = 0;
    out->y = FX_F32_TO_FX32(offsetY);
    out->z = 0;
}

int FIELD_TASK_UpdatePlayerDrop(PlayerDropTask *task)
{
    VecFx32 offset;
    Mmdl *mmdl;
    FIELDMAP_GetFieldPlayer(task->fieldMap);
    mmdl = task->mmdl;
    switch (task->state) {
    case 0:
        FIELD_TASK_CalcDropOffset(&offset, (float)(u32)task->frame, (float)(u32)task->frames, task->height);
        FLDMMDL_SetDrawOffset(mmdl, (struct VecFx32 *)(&offset));
        GFL_USE_PlaySeDefaultVolume(0x681);
        task->state = task->state + 1;
        break;
    case 1:
        task->frame = task->frame + 1;
        FIELD_TASK_CalcDropOffset(&offset, (float)(u32)task->frame, (float)(u32)task->frames, task->height);
        FLDMMDL_SetDrawOffset(mmdl, (struct VecFx32 *)(&offset));
        if (task->frames <= task->frame) {
            FLDEFF_KEMURI_Start(mmdl, (struct FieldEffectSys *)FIELDMAP_GetEffect(task->fieldMap));
            GFL_USE_PlaySeDefaultVolume(0x682);
            return 1;
        }
        break;
    }
    return 0;
}

FieldTask *FIELD_TASK_CreateWait(FieldMap *fieldMap, u16 frames)
{
    FieldTask *task = FIELD_TASK_Create(FIELDMAP_GetHeapId(fieldMap), 4, (FieldTaskCheckFunc)FIELD_TASK_UpdateWait);
    WaitTask *wait = (WaitTask *)FIELD_TASK_GetWork(task);
    wait->frame = 0;
    wait->frames = frames;
    return task;
}

int FIELD_TASK_UpdateWait(WaitTask *task)
{
    task->frame++;
    if (task->frames <= task->frame)
        return 1;
    return 0;
}

FieldTask *FIELD_TASK_CreateFade(FieldMap *fieldMap, u32 fadeMode, u32 startBrightness, u32 endBrightness, u32 wait)
{
    FieldTask *task = FIELD_TASK_Create(FIELDMAP_GetHeapId(fieldMap), 0x14, (FieldTaskCheckFunc)FIELD_TASK_UpdateFade);
    FadeTask *fade = (FadeTask *)FIELD_TASK_GetWork(task);
    fade->fieldMap = fieldMap;
    fade->fadeMode = fadeMode;
    fade->startBrightness = startBrightness;
    fade->endBrightness = endBrightness;
    fade->wait = wait;
    return task;
}

int FIELD_TASK_UpdateFade(FadeTask *task)
{
    FADE_Start(task->fadeMode, task->startBrightness, task->endBrightness, task->wait);
    return 1;
}

FieldTask *FIELD_TASK_CreatePlayerDrawOffsetTween(FieldMap *fieldMap, int frames, const VecFx32 *offset)
{
    return FIELD_TASK_CreateMmdlDrawOffsetTween(fieldMap, frames, offset, FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap)));
}

#undef FX_F32_TO_FX32

#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))

/* Draw offset of a model slides from zero to `offset` (negative frames: from `offset` back to zero). */
FieldTask *FIELD_TASK_CreateMmdlDrawOffsetTween(FieldMap *fieldMap, int frames, const VecFx32 *offset, Mmdl *mmdl)
{
    MmdlOffsetTween *tween;
    FieldTask *task;
    task = FIELD_TASK_Create(FIELDMAP_GetHeapId(fieldMap), 0x2c, (FieldTaskCheckFunc)FIELD_TASK_UpdateMmdlDrawOffsetTween);
    tween = (MmdlOffsetTween *)FIELD_TASK_GetWork(task);
    tween->state = 0;
    tween->fieldMap = fieldMap;
    tween->mmdl = mmdl;
    FLDMMDL_GetPos(mmdl, (struct VecFx32 *)(&tween->startPos));
    if (frames >= 0) {
        tween->reverse = 0;
        tween->frame = 0;
        tween->frames = frames;
    } else {
        tween->reverse = 1;
        tween->frame = 0;
        tween->frames = -frames;
    }
    setVec(&tween->offset, offset->x, offset->y, offset->z);
    return task;
}

/* Position of a model slides by `offset` from its start position. */
FieldTask *FIELD_TASK_CreateMmdlPosOffsetTween(FieldMap *fieldMap, int frames, const VecFx32 *offset, Mmdl *mmdl)
{
    MmdlOffsetTween *tween;
    FieldTask *task;
    task = FIELD_TASK_Create(FIELDMAP_GetHeapId(fieldMap), 0x2c, (FieldTaskCheckFunc)FIELD_TASK_UpdateMmdlPosOffsetTween);
    tween = (MmdlOffsetTween *)FIELD_TASK_GetWork(task);
    tween->state = 0;
    tween->fieldMap = fieldMap;
    tween->mmdl = mmdl;
    FLDMMDL_GetPos(mmdl, (struct VecFx32 *)(&tween->startPos));
    if (frames >= 0) {
        tween->reverse = 0;
        tween->frame = 0;
        tween->frames = frames;
    } else {
        tween->reverse = 1;
        tween->frame = 0;
        tween->frames = -frames;
    }
    setVec(&tween->offset, offset->x, offset->y, offset->z);
    return task;
}

/* out = offset * (frame / frames) in fixed point. */
void FIELD_TASK_CalcOffsetByProgress(VecFx32 *out, u16 frame, VecFx32 *offset, u16 frames)
{
    fx32 t;
    t = FX_F32_TO_FX32((f32)frame / (f32)frames);
    out->x = (fx32)(((long long)offset->x * t + 0x800) >> 12);
    out->y = (fx32)(((long long)offset->y * t + 0x800) >> 12);
    out->z = (fx32)(((long long)offset->z * t + 0x800) >> 12);
}

int FIELD_TASK_UpdateMmdlDrawOffsetTween(MmdlOffsetTween *tween)
{
    Mmdl *mmdl = tween->mmdl;
    VecFx32 offset;
    if (tween->state == 0) {
        tween->frame = tween->frame + 1;
        if (tween->reverse == 0) {
            FIELD_TASK_CalcOffsetByProgress(&offset, tween->frame, &tween->offset, tween->frames);
        } else if (tween->reverse == 1) {
            FIELD_TASK_CalcOffsetByProgress(&offset, tween->frames - tween->frame, &tween->offset, tween->frames);
        }
        FLDMMDL_SetDrawOffset(mmdl, (struct VecFx32 *)(&offset));
        if (tween->frames <= tween->frame) {
            return 1;
        }
    }
    return 0;
}

int FIELD_TASK_UpdateMmdlPosOffsetTween(MmdlOffsetTween *tween)
{
    Mmdl *mmdl = tween->mmdl;
    VecFx32 offset;
    if (tween->state == 0) {
        tween->frame = tween->frame + 1;
        if (tween->reverse == 0) {
            FIELD_TASK_CalcOffsetByProgress(&offset, tween->frame, &tween->offset, tween->frames);
        } else if (tween->reverse == 1) {
            FIELD_TASK_CalcOffsetByProgress(&offset, tween->frames - tween->frame, &tween->offset, tween->frames);
        }
        VEC_Add(&offset, &tween->startPos, &offset);
        FLDMMDL_SetPos(mmdl, (struct VecFx32 *)(&offset));
        if (tween->frames <= tween->frame) {
            return 1;
        }
    }
    return 0;
}

/*
 * The source vector is const: the const lets the scheduler hoist each
 * load above the preceding store (ldr x; str frames; ldr y; str x; ...).  The
 * sibling FIELD_TASK_CreatePlayerPosTween takes a plain pointer and keeps loads after the frames store.
 */
FieldTask *FIELD_TASK_CreateCameraTargetTween(FieldMap *fieldMap, u32 frames, const VecFx32 *to)
{
    FieldTask *task = FIELD_TASK_Create(FIELDMAP_GetHeapId(fieldMap), 0x28, (FieldTaskCheckFunc)FIELD_TASK_UpdateCameraTargetTween);
    PosTween *tween = (PosTween *)FIELD_TASK_GetWork(task);
    tween->state = 0;
    tween->fieldMap = fieldMap;
    tween->frame = 0;
    tween->frames = frames;
    setVec(&tween->to, to->x, to->y, to->z);
    return task;
}

/* Tween the camera target offset between two points. */
int FIELD_TASK_UpdateCameraTargetTween(PosTween *tween)
{
    FieldCamera *camera;
    fx32 t;
    VecFx32 fromPart;
    VecFx32 toPart;
    VecFx32 pos;
    camera = FIELDMAP_GetCamera(tween->fieldMap);
    switch (tween->state) {
    case 0:
        FIELD_CAMERA_GetTargetShift(camera, &tween->from);
        tween->state++;
        break;
    case 1:
        tween->frame++;
        t = FX_F32_TO_FX32((f32)tween->frame / (f32)tween->frames);
        BUTTON_MAN_ScaleVec(&tween->from, FX32_ONE - t, &fromPart);
        BUTTON_MAN_ScaleVec(&tween->to, t, &toPart);
        VEC_Add(&fromPart, &toPart, &pos);
        FIELD_CAMERA_SetTargetShift(camera, &pos);
        if (tween->frames <= tween->frame)
            return 1;
        break;
    }
    return 0;
}

/* Move the camera along a line from `start` to `end`. */
FieldTask *FIELD_TASK_CreateCameraLerp(FieldMap *fieldMap, u16 frames, const VecFx32 *start, const VecFx32 *end)
{
    int heapId;
    FieldTask *task;
    CameraLerpTask *lerp;
    heapId = FIELDMAP_GetHeapId(fieldMap);
    FIELDMAP_GetCamera(fieldMap);
    task = FIELD_TASK_Create(heapId, 0x34, (FieldTaskCheckFunc)FIELD_TASK_UpdateCameraLerp);
    lerp = (CameraLerpTask *)FIELD_TASK_GetWork(task);
    lerp->state = 0;
    lerp->fieldMap = fieldMap;
    lerp->frame = 0;
    lerp->frames = frames;
    lerp->start = *start;
    lerp->end = *end;
    VEC_Subtract(&lerp->end, &lerp->start, &lerp->delta);
    return task;
}

int FIELD_TASK_UpdateCameraLerp(CameraLerpTask *task)
{
    FieldCamera *camera;
    int t;
    float progress;
    VecFx32 pos;
    camera = FIELDMAP_GetCamera(task->fieldMap);
    switch (task->state) {
    case 0:
        task->savedFlag = FIELD_CAMERA_GetMode(camera);
        FIELD_CAMERA_SetMode(camera, 0);
        task->state = task->state + 1;
        break;
    case 1:
        task->frame = task->frame + 1;
        progress = (float)(u32)task->frame / (float)(u32)task->frames;
        if (progress > 0.0f) {
            t = (int)(4096.0f * progress + 0.5f);
        } else {
            t = (int)(4096.0f * progress - 0.5f);
        }
        VEC_MultAdd(t, &task->delta, &task->start, &pos);
        FIELD_CAMERA_SetTarget(camera, &pos);
        if (task->frames <= task->frame) {
            FIELD_CAMERA_SetMode(camera, task->savedFlag);
            return 1;
        }
        break;
    }
    return 0;
}

/* Run the player effect every `interval` frames for `frames` frames. */
FieldTask *FIELD_TASK_CreateRepeatPlayerEffect(FieldMap *fieldMap, struct Mmdl *unused, u16 frames, u16 interval)
{
    int heapId;
    FieldPlayer *player;
    FieldTask *task;
    RepeatEffectTask *effect;
    heapId = FIELDMAP_GetHeapId(fieldMap);
    player = FIELDMAP_GetFieldPlayer(fieldMap);
    task = FIELD_TASK_Create(heapId, 0x14, (FieldTaskCheckFunc)FIELD_TASK_UpdateRepeatPlayerEffect);
    effect = (RepeatEffectTask *)FIELD_TASK_GetWork(task);
    effect->fieldMap = fieldMap;
    effect->effectCtrl = (struct FieldEffectCtrl *)FIELDMAP_GetEffect(fieldMap);
    effect->mmdl = FIELD_PLAYER_GetMmdl(player);
    effect->state = 0;
    effect->frame = 0;
    effect->frames = frames;
    effect->interval = interval;
    return task;
}

int FIELD_TASK_UpdateRepeatPlayerEffect(RepeatEffectTask *task)
{
    if (task->state == 0) {
        if (task->frame % task->interval == 0)
            FLDEFF_IWAKUDAKI_Start(task->mmdl, (struct FieldEffectSys *)task->effectCtrl);
        if (task->frames <= task->frame++)
            return 1;
    }
    return 0;
}
