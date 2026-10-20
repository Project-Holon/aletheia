#ifndef GAME_TWL_CAMERA_API_H
#define GAME_TWL_CAMERA_API_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of camera_api.c, prototypes copied from their definitions. */

#include "../types.h"

void CAMERA_CameraIntr(void);
u32 CAMERA_GetWhiteBalanceFromPhotoMode(u32 mode);
s32 CAMERA_GetSharpnessFromPhotoMode(u32 mode);
u32 CAMERA_GetExposureFromPhotoMode(u32 mode);
void CAMERA_GoReboot(void);
void CAMERA_Reboot(u32 result, u32 step);
u32 CAMERA_CheckRetryCount(void);
void CAMERA_MonitorThread(void *arg);
u32 CAMERA_InitCore(void);
void CAMERA_EndCore(void);
void CAMERA_StopCore(void);
u32 CAMERA_I2CInitCore(u32 camera);
u32 CAMERA_I2CActivateCore(u32 camera);
u32 CAMERA_I2CSizeExCore(u32 camera, u32 context, u32 size);
u32 CAMERA_I2CEffectExCore(u32 camera, u32 context, u32 effect);
u32 CAMERA_I2CAutoExposureCore(u32 camera, u32 enable);
u32 CAMERA_I2CAutoWhiteBalanceCore(u32 camera, u32 enable);
int CameraSendPxiCommand(u32 command, u32 paramCount, u32 firstParam);
void CameraSendPxiData(const u8 *params);
void CameraPxiCallback(int tag, u32 data, int err);
void CameraSyncCallback(u32 result, u32 arg);
void CameraCallCallbackAndUnlock(u32 result);
void CameraWaitBusy(void);
/* END mkheaders: generated region */

#endif
