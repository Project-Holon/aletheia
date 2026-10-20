#ifndef GAME_OV094_BTLV_CAMERA_H
#define GAME_OV094_BTLV_CAMERA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btlv_camera.c, prototypes copied from their definitions. */

#include "../ov094/btlv_camera_shared_types.h"
#include "../types.h"
#include "../sdk_fx.h"
#include "../sdk_fx.h"

BtlvCamera *BTLV_CAMERA_Create(void *owner, u16 heap);
void BTLV_CAMERA_Delete(BtlvCamera *camera);
void BTLV_CAMERA_UpdateMove(BtlvCamera *camera);
void BTLV_CAMERA_SetEyeAndTarget(BtlvCamera *camera, const VecFx32 *eye, const VecFx32 *target);
void BTLV_CAMERA_RotateOrbit(BtlvCamera *camera, int dPitch, int dYaw);
void BTLV_CAMERA_StartMove(BtlvCamera *camera, const VecFx32 *eyeDest, const VecFx32 *targetDest, int frames, int delay, int easeCount);
void BTLV_CAMERA_StartMoveWithEasing(BtlvCamera *camera, int axis, fx32 amplitude, int unused, int frames, int waitTicks, int repeatPairs);
void BTLV_CAMERA_GetEyeAndTarget(BtlvCamera *camera, VecFx32 *eyeOut, VecFx32 *targetOut);
void BTLV_CAMERA_AdvanceOrbitEye(BtlvCamera *camera, int dPitch, int dYaw, VecFx32 *eyeOut, VecFx32 *targetBase);
void BTLV_CAMERA_GetDefaultEyeAndTarget(VecFx32 *eyeOut, VecFx32 *targetOut);
int BTLV_CAMERA_IsMoving(BtlvCamera *camera);
void BTLV_CAMERA_StepMove(BtlvCamera *camera);
void BTLV_CAMERA_SyncOrbitFromCamera(BtlvCamera *camera);
/* END mkheaders: generated region */

#endif
