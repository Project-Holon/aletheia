/*
 * file:     btlv_camera.c
 * unit:     yes
 * function: BTLV_CAMERA_Create, BTLV_CAMERA_Delete, BTLV_CAMERA_UpdateMove, BTLV_CAMERA_SetEyeAndTarget, BTLV_CAMERA_RotateOrbit, BTLV_CAMERA_StartMove, BTLV_CAMERA_StartMoveWithEasing, BTLV_CAMERA_GetEyeAndTarget, BTLV_CAMERA_AdvanceOrbitEye, BTLV_CAMERA_GetDefaultEyeAndTarget, BTLV_CAMERA_IsMoving, BTLV_CAMERA_StepMove, BTLV_CAMERA_SyncOrbitFromCamera
 * address:  0x021F6E3C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from btlv_effvm.c, btlv_b_gauge.c, btlv_bg.c, btlv_finger_cursor.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   G3D_CAMERA_Create  0x02048A24  arm
 *   G3D_CAMERA_Reset  0x02048AD0  arm
 *   gBtlvCameraFileName     0x0220AC60  data   ov094  a1
 *   gBtlvCameraInitEye     0x02209CF4  data   ov094
 *   gBtlvCameraInitUp     0x02209D00  data   ov094
 *   gBtlvCameraInitTarget     0x02209CE8  data   ov094
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_CAMERA_SetEye  0x02048AFC  arm
 *   G3D_CAMERA_SetCamTarget  0x02048B44  arm
 *   FX_Div  0x0207C768  arm
 *   G3D_CAMERA_GetEye 0x02048AE8 arm
 *   G3D_CAMERA_GetCamTarget 0x02048B30 arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   FX_Atan2Idx  0x0207CFB8  arm
 *   VEC_Mag  0x0207CBD0  arm
 *   BTLV_EFFECT_ComputeVectorStep 0x021F918C thumb ov094
 *   BTLV_EFFECT_StepMover  0x021F9260  thumb  ov094
 *   BTLV_EFFECT_StepScalarWithLimit 0x021F9220 thumb ov094
 *   _fadd                        0x0209C95C  arm
 *   _ffix                        0x0209C494  arm
 *   _fflt                        0x0209BDBC  arm
 *   _fsub                        0x0209CB8C  arm
 */
#include "btlv_effvm_types.h"
#include "btlv_camera_shared_types.h"

extern void *GFL_HEAP_Alloc(u32, u32, int, const char *, u16);

extern u32 GFL_HEAP_Free(void *p);

extern struct G3dCamera *G3D_CAMERA_Create(int mode, int nearClip, int farClip, int fieldOfView, int aspectRatio, int scale, int roll, int flags,
                                           const BtlvVec3 *eye, const BtlvVec3 *up, const BtlvVec3 *target, int heap);

extern void G3D_CAMERA_Reset(struct G3dCamera *camera);

extern unsigned int G3D_CAMERA_Delete(void *camera);

extern void G3D_CAMERA_SetEye(struct G3dCamera *camera, const BtlvVec3 *eye);

extern void G3D_CAMERA_SetCamTarget(struct G3dCamera *camera, const BtlvVec3 *target);

extern u32 FX_Div(u32 a, u32 b);

extern void G3D_CAMERA_GetEye(struct G3dCamera *camera, BtlvVec3 *out);

extern void G3D_CAMERA_GetCamTarget(struct G3dCamera *camera, BtlvVec3 *out);

extern u16 FX_Atan2Idx(int, int);

extern int VEC_Mag(BtlvVec3 *);

BtlvCamera *BTLV_CAMERA_Create(void *owner, u16 heap);

void BTLV_CAMERA_Delete(BtlvCamera *camera);

void BTLV_CAMERA_UpdateMove(BtlvCamera *camera);

void BTLV_CAMERA_SetEyeAndTarget(BtlvCamera *camera, const BtlvVec3 *eye, const BtlvVec3 *target);

void BTLV_CAMERA_RotateOrbit(BtlvCamera *camera, int dPitch, int dYaw);

void BTLV_CAMERA_StartMove(BtlvCamera *camera, const BtlvVec3 *eyeDest, const BtlvVec3 *targetDest, int frames, int delay, int easeCount);

void BTLV_CAMERA_StartMoveWithEasing(BtlvCamera *camera, int axis, fx32 amplitude, int unused, int frames, int waitTicks, int repeatPairs);

void BTLV_CAMERA_GetEyeAndTarget(BtlvCamera *camera, BtlvVec3 *eyeOut, BtlvVec3 *targetOut);

void BTLV_CAMERA_AdvanceOrbitEye(BtlvCamera *camera, int dPitch, int dYaw, BtlvVec3 *eyeOut, BtlvVec3 *targetBase);

void BTLV_CAMERA_GetDefaultEyeAndTarget(BtlvVec3 *eyeOut, BtlvVec3 *targetOut);

int BTLV_CAMERA_IsMoving(BtlvCamera *camera);

void BTLV_CAMERA_StepMove(BtlvCamera *camera);

void BTLV_CAMERA_SyncOrbitFromCamera(BtlvCamera *camera);

void BTLV_EFFECT_ComputeVectorStep(const BtlvVec3 *from, const BtlvVec3 *to, BtlvVec3 *stepOut, fx32 frames);

void BTLV_EFFECT_StepScalarWithLimit(fx32 *value, fx32 *step, fx32 *limit, int *notDone);

int BTLV_EFFECT_StepMover(BtlvMover *mover, BtlvVec3 *out);

extern const char gBtlvCameraFileName[];

extern BtlvVec3 gBtlvCameraInitEye; /* (0x6b33, 0x6b33, 0x114cd): eye */

extern BtlvVec3 gBtlvCameraInitUp; /* (0, 0x1000, 0): up */

extern BtlvVec3 gBtlvCameraInitTarget; /* (0, 0x299a, 0): look-at point */

extern const s16 FX_SinCosTable_[];

#define FX_INT_TO_FX32(x) ((fx32)(((x) > 0) ? ((float)((x) << 12) + .5f) \
                                            : ((float)((x) << 12) - .5f)))

#define MUL(a,b) ((int)(((long long)(a) * (b) + 0x800) >> 12))

BtlvCamera *BTLV_CAMERA_Create(void *owner, u16 heap)
{
    BtlvCamera *camera = GFL_HEAP_Alloc(heap, 0xb8, 1, gBtlvCameraFileName, 0x56);

    camera->heap = heap;
    camera->owner = owner;
    camera->camera = G3D_CAMERA_Create(0, 0x399, 0xf97, 0x159a, 0, 0x1000, 0x200000, 0,
                                       &gBtlvCameraInitEye, &gBtlvCameraInitUp, &gBtlvCameraInitTarget, heap);
    BTLV_CAMERA_SyncOrbitFromCamera(camera);
    G3D_CAMERA_Reset(camera->camera);
    BTLV_CAMERA_GetDefaultEyeAndTarget(&camera->eye, &camera->target);
    return camera;
}

/*
 * Releases the G3D camera, then frees the object.
 */
void BTLV_CAMERA_Delete(BtlvCamera *camera)
{
    G3D_CAMERA_Delete(camera->camera);
    GFL_HEAP_Free(camera);
}

void BTLV_CAMERA_UpdateMove(BtlvCamera *camera)
{
    BTLV_CAMERA_StepMove(camera);
}

/*
 * EXACT*: inferred extent is two bytes long; the follower is an unlabelled
 * leaf that disasm.py did not label.
 */
void BTLV_CAMERA_SetEyeAndTarget(BtlvCamera *camera, const BtlvVec3 *eye, const BtlvVec3 *target)
{
    if (eye) {
        camera->eye.x = eye->x;
        camera->eye.y = eye->y;
        camera->eye.z = eye->z;
        G3D_CAMERA_SetEye(camera->camera, eye);
    }
    if (target) {
        camera->target.x = target->x;
        camera->target.y = target->y;
        camera->target.z = target->z;
        G3D_CAMERA_SetCamTarget(camera->camera, target);
    }
    G3D_CAMERA_Reset(camera->camera);
    BTLV_CAMERA_SyncOrbitFromCamera(camera);
}

/*
 * Turns the orbit by the two angles, then sets the eye from the orbit and commits.
 */
void BTLV_CAMERA_RotateOrbit(BtlvCamera *camera, int dPitch, int dYaw)
{
    BTLV_CAMERA_AdvanceOrbitEye(camera, dPitch, dYaw, &camera->eye, &camera->target);
    G3D_CAMERA_SetEye(camera->camera, &camera->eye);
    G3D_CAMERA_Reset(camera->camera);
}

void BTLV_CAMERA_StartMove(BtlvCamera *camera, const BtlvVec3 *eyeDest, const BtlvVec3 *targetDest, int frames, int delay, int easeCount)
{
    camera->easeCount = easeCount;
    camera->moveWait = delay;
    camera->moveWaitReset = delay;
    if (eyeDest != 0) {
        camera->eyeDest.x = eyeDest->x;
        camera->eyeDest.y = eyeDest->y;
        camera->eyeDest.z = eyeDest->z;
        BTLV_EFFECT_ComputeVectorStep(&camera->eye, eyeDest, &camera->eyeStep, FX_INT_TO_FX32(frames));
        camera->moveFlags |= BTLV_CAMERA_MOVE_EYE;
    }
    if (targetDest != 0) {
        camera->targetDest.x = targetDest->x;
        camera->targetDest.y = targetDest->y;
        camera->targetDest.z = targetDest->z;
        BTLV_EFFECT_ComputeVectorStep(&camera->target, targetDest, &camera->targetStep, FX_INT_TO_FX32(frames));
        camera->moveFlags |= BTLV_CAMERA_MOVE_TARGET;
    }
}

/*
 * Follower of BTLV_CAMERA_StartMove; bl from ov094 at 0x021FA08E.
 * Starts the shake mover: axis 1 swings the first component, any other value the second.
 */
void BTLV_CAMERA_StartMoveWithEasing(BtlvCamera *camera, int axis, fx32 amplitude, int unused, int frames, int waitTicks, int repeatPairs)
{
    camera->shake.mode = 3;
    camera->shake.count = frames;
    camera->shake.countReset = frames;
    camera->shake.wait = 0;
    camera->shake.waitReset = waitTicks;
    camera->shake.start.x = 0;
    camera->shake.repeat = repeatPairs * 4;
    camera->shake.start.y = 0;
    camera->shake.start.z = 0;
    if (axis == 1) {
        camera->shake.end.x = amplitude;
        camera->shake.end.y = 0;
        camera->shake.step.x = FX_Div(amplitude, FX_INT_TO_FX32(frames));
        camera->shake.step.y = 0;
    } else {
        camera->shake.end.x = 0;
        camera->shake.end.y = amplitude;
        camera->shake.step.x = 0;
        camera->shake.step.y = FX_Div(amplitude, FX_INT_TO_FX32(frames));
    }
    camera->shake.end.z = 0;
    camera->shake.step.z = 0;
    camera->moveFlags |= BTLV_CAMERA_MOVE_SHAKE;
}

/*
 * EXACT*: the listing extent includes two bytes of trailing alignment padding.
 *
 * Reads the current eye and target positions out of the G3D camera.
 */
void BTLV_CAMERA_GetEyeAndTarget(BtlvCamera *camera, BtlvVec3 *eyeOut, BtlvVec3 *targetOut)
{
    G3D_CAMERA_GetEye(camera->camera, eyeOut);
    G3D_CAMERA_GetCamTarget(camera->camera, targetOut);
}

void BTLV_CAMERA_AdvanceOrbitEye(BtlvCamera *camera, int dPitch, int dYaw, BtlvVec3 *eyeOut, BtlvVec3 *targetBase)
{
    G3D_CAMERA_GetCamTarget(camera->camera, targetBase);
    camera->orbitPitch += dPitch;
    camera->orbitYaw += dYaw;
    eyeOut->x = MUL(FX_SinCosTable_[(camera->orbitYaw >> 4) * 2 + 1], FX_SinCosTable_[(camera->orbitPitch >> 4) * 2 + 1]);
    eyeOut->y = FX_SinCosTable_[(camera->orbitPitch >> 4) * 2];
    eyeOut->z = MUL(FX_SinCosTable_[(camera->orbitYaw >> 4) * 2], FX_SinCosTable_[(camera->orbitPitch >> 4) * 2 + 1]);
    eyeOut->x = MUL(eyeOut->x, camera->orbitRadius);
    eyeOut->y = MUL(eyeOut->y, camera->orbitRadius);
    eyeOut->z = MUL(eyeOut->z, camera->orbitRadius);
    eyeOut->x += targetBase->x;
    eyeOut->y += targetBase->y;
    eyeOut->z += targetBase->z;
}

void BTLV_CAMERA_GetDefaultEyeAndTarget(BtlvVec3 *eyeOut, BtlvVec3 *targetOut)
{
    eyeOut->x = 0x6b33;
    eyeOut->y = 0x6b33;
    eyeOut->z = 0x114cd;
    targetOut->x = 0;
    targetOut->y = 0x299a;
    targetOut->z = 0;
}

int BTLV_CAMERA_IsMoving(BtlvCamera *camera)
{
    return camera->moveFlags != 0;
}

void BTLV_CAMERA_StepMove(BtlvCamera *camera)
{
    BtlvVec3 eye;
    BtlvVec3 target;
    int allDone = 1;
    int half;
    if (camera->moveFlags == 0) return;
    if (camera->moveWait == 0) {
        camera->moveWait = camera->moveWaitReset;
        if (camera->easeCount != 0) {
            if (--camera->easeCount == 0) {
                half = camera->eyeStep.x >> 1; if (half) camera->eyeStep.x = half;
                half = camera->eyeStep.y >> 1; if (half) camera->eyeStep.y = half;
                half = camera->eyeStep.z >> 1; if (half) camera->eyeStep.z = half;
                half = camera->targetStep.x >> 1; if (half) camera->targetStep.x = half;
                half = camera->targetStep.y >> 1; if (half) camera->targetStep.y = half;
                half = camera->targetStep.z >> 1; if (half) camera->targetStep.z = half;
            }
        }
        if (camera->moveFlags & BTLV_CAMERA_MOVE_EYE) {
            BTLV_EFFECT_StepScalarWithLimit(&camera->eye.x, &camera->eyeStep.x, &camera->eyeDest.x, &allDone);
            BTLV_EFFECT_StepScalarWithLimit(&camera->eye.y, &camera->eyeStep.y, &camera->eyeDest.y, &allDone);
            BTLV_EFFECT_StepScalarWithLimit(&camera->eye.z, &camera->eyeStep.z, &camera->eyeDest.z, &allDone);
            if (allDone == 1) camera->moveFlags &= ~BTLV_CAMERA_MOVE_EYE;
        }
        if (camera->moveFlags & BTLV_CAMERA_MOVE_TARGET) {
            BTLV_EFFECT_StepScalarWithLimit(&camera->target.x, &camera->targetStep.x, &camera->targetDest.x, &allDone);
            BTLV_EFFECT_StepScalarWithLimit(&camera->target.y, &camera->targetStep.y, &camera->targetDest.y, &allDone);
            BTLV_EFFECT_StepScalarWithLimit(&camera->target.z, &camera->targetStep.z, &camera->targetDest.z, &allDone);
            if (allDone == 1) camera->moveFlags &= ~BTLV_CAMERA_MOVE_TARGET;
        }
        if (camera->moveFlags & BTLV_CAMERA_MOVE_SHAKE) {
            allDone = BTLV_EFFECT_StepMover(&camera->shake, &camera->shakeOffset);
            if (allDone == 1) camera->moveFlags &= ~BTLV_CAMERA_MOVE_SHAKE;
        }
        eye.x = camera->eye.x + camera->shakeOffset.x;
        eye.y = camera->eye.y + camera->shakeOffset.y;
        eye.z = camera->eye.z + camera->shakeOffset.z;
        target.x = camera->target.x + camera->shakeOffset.x;
        target.y = camera->target.y + camera->shakeOffset.y;
        target.z = camera->target.z + camera->shakeOffset.z;
        G3D_CAMERA_SetEye(camera->camera, &eye);
        G3D_CAMERA_SetCamTarget(camera->camera, &target);
        G3D_CAMERA_Reset(camera->camera);
        BTLV_CAMERA_SyncOrbitFromCamera(camera);
    } else {
        camera->moveWait--;
    }
}

void BTLV_CAMERA_SyncOrbitFromCamera(BtlvCamera *camera)
{
    BtlvVec3 eye;
    BtlvVec3 target;
    G3D_CAMERA_GetEye(camera->camera, &eye);
    G3D_CAMERA_GetCamTarget(camera->camera, &target);
    eye.x -= target.x;
    eye.y -= target.y;
    eye.z -= target.z;
    camera->orbitPitch = FX_Atan2Idx(eye.y, eye.z);
    camera->orbitYaw = FX_Atan2Idx(eye.z, eye.x);
    camera->orbitRadius = VEC_Mag(&eye);
}
