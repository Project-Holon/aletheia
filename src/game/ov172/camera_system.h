#ifndef GAME_OV172_CAMERA_SYSTEM_H
#define GAME_OV172_CAMERA_SYSTEM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of camera_system.c, prototypes copied from their definitions. */

struct Camera;
typedef struct Camera Camera;

#include "../types.h"

Camera *CTVT_CAMERA_Create(int id);
void CTVT_CAMERA_OnPowerOff(Camera *p);
void CTVT_CAMERA_Delete(Camera *p);
void CTVT_CAMERA_StartFrameDma(Camera *p);
void CTVT_CAMERA_UpdateShutterSound(Camera *p);
void CTVT_CAMERA_LoadShutterSound(Camera *obj, int mode);
void CTVT_CAMERA_FreeShutterSound(Camera *p);
void CTVT_CAMERA_OnBufferError(void);
void CTVT_CAMERA_OnReboot(int x);
void CTVT_CAMERA_OnVsync(void);
void CTVT_CAMERA_OnFrameDmaDone(void);
void CTVT_CAMERA_SetFrameCallback(Camera *p, void (*a)(u32, u32), u32 b);
void CTVT_CAMERA_AllocFrames(Camera *p, int count, u16 heap);
void CTVT_CAMERA_FreeFrames(Camera *p);
void CTVT_CAMERA_StartCapture(Camera *camera);
void CTVT_CAMERA_StopCapture(Camera *p);
int CTVT_CAMERA_IsShutterSoundIdle(Camera *p);
void CTVT_CAMERA_ResetTrimming(Camera *p);
u16 CTVT_CAMERA_GetWidth(Camera *p);
u16 CTVT_CAMERA_GetHeight(Camera *p);
void CTVT_CAMERA_SetSize(Camera *p, int v);
int CTVT_CAMERA_GetSizeWidth(Camera *p);
int CTVT_CAMERA_GetSizeHeight(Camera *p);
void CTVT_CAMERA_SelectCamera(Camera *p, u32 v);
void CTVT_CAMERA_RequestShutterSound0(Camera *p);
void CTVT_CAMERA_RequestShutterSound1(Camera *p);
/* END mkheaders: generated region */

#endif
