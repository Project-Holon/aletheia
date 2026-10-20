#ifndef GAME_OV172_CTVT_CAMERA_H
#define GAME_OV172_CTVT_CAMERA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ctvt_camera.c, prototypes copied from their definitions. */

struct CtvtWork;
struct CtvtCamView;

#include "../types.h"
#include "../ov172/ctvt_camera_types.h"

char *CTVT_CAMVIEW_Create(void *work, u16 heapId);
void CTVT_CAMVIEW_Delete(u8 *unused, CtvtCamView *view);
void CTVT_CAMVIEW_Update(char *unused, CtvtCamView *view);
void CTVT_CAMVIEW_UploadWindows(void *work, CtvtCamView *view);
void CTVT_CAMVIEW_StopCapture(struct CtvtWork *unused, CtvtCamView *view);
int CTVT_CAMVIEW_IsShutterIdle(struct CtvtWork *unused, CtvtCamView *view);
void CTVT_CAMVIEW_OnCameraFrame(char *frame, void *work);
void CTVT_CAMVIEW_MarkWindowDirty(void *work, CtvtCamView *view, int slot);
void CTVT_CAMVIEW_ClearWindowDirty(void *work, CtvtCamView *view, int slot);
void CTVT_CAMVIEW_StartLayoutChange(void *work, CtvtCamView *view, int revealArg, int clearArg);
u32 CTVT_CAMVIEW_IsLayoutChanging(struct CtvtWork *unused, CtvtCamView *view);
u32 CTVT_CAMVIEW_GetWindowHeight(void *work, struct CtvtCamView *unused);
u32 CTVT_CAMVIEW_GetWindowWidth(void *work, struct CtvtCamView *unused);
u32 CTVT_CAMVIEW_GetOwnSlotBuffer(void *work, CtvtCamView *view);
int CTVT_CAMVIEW_GetSlotBuffer(void *work, CtvtCamView *view, int slot);
u32 CTVT_CAMVIEW_GetSlotBufferStep(void *work, struct CtvtCamView *unused);
void CTVT_CAMVIEW_SetWindowCurRect(CtvtCamViewWindow *win, u16 x, u16 y, u16 w, u16 h);
void CTVT_CAMVIEW_SetWindowTargetRect(CtvtCamViewWindow *win, u16 x, u16 y, u16 w, u16 h);
int CTVT_CAMVIEW_StepWindow(CtvtCamView *view, CtvtCamViewWindow *win);
int CTVT_CAMVIEW_StepValue(CtvtCamView *view, u16 *value, u16 *limit);
void CTVT_CAMVIEW_SetWindowLayout(void *work, CtvtCamView *view, int slot);
void CTVT_CAMVIEW_RequestWindowAnimation(int unused, CtvtCamView *view, int slot);
u32 CTVT_CAMVIEW_IsWindowMoving(u8 *unused, CtvtCamView *view, int slot);
void CTVT_CAMVIEW_SetCameraEffect(struct CtvtWork *unused, struct CtvtCamView *unused2, int effect);
void CTVT_CAMVIEW_RequestShutterSound0(int unused, CtvtCamView *view);
void CTVT_CAMVIEW_RequestShutterSound1(struct CtvtWork *unused, CtvtCamView *view);
/* END mkheaders: generated region */

#endif
