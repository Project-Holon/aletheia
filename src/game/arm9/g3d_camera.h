#ifndef GAME_ARM9_G3D_CAMERA_H
#define GAME_ARM9_G3D_CAMERA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of g3d_camera.c, prototypes copied from their definitions. */

struct G3dCamera;

#include "../types.h"
#include "../sdk_fx.h"
#include "../sdk_fx.h"
#include "../sdk_fx.h"

struct G3dCamera *G3D_CAMERA_Create(u32 mode, u32 nearClip, u32 farClip, u32 fieldOfView, u32 aspectRatio, u32 scale, u32 roll, u32 flags, VecFx32 *eye, VecFx32 *target, VecFx32 *up, u16 heapID);
u32 G3D_CAMERA_Delete(void *camera);
void G3D_CAMERA_Reset(struct G3dCamera *camera);
void G3D_CAMERA_GetEye(struct G3dCamera *camera, VecFx32 *out);
void G3D_CAMERA_SetEye(struct G3dCamera *camera, const VecFx32 *in);
void G3D_CAMERA_GetCamUp(struct G3dCamera *camera, VecFx32 *out);
void G3D_CAMERA_SetCamUp(struct G3dCamera *camera, const VecFx32 *in);
void G3D_CAMERA_GetCamTarget(struct G3dCamera *camera, VecFx32 *out);
void G3D_CAMERA_SetCamTarget(struct G3dCamera *camera, const VecFx32 *in);
void G3D_CAMERA_GetNear(struct G3dCamera *camera, u32 *out);
void G3D_CAMERA_SetNear(struct G3dCamera *camera, const u32 *in);
void G3D_CAMERA_SetFar(struct G3dCamera *camera, const u32 *in);
int G3D_CAMERA_GetMode(struct G3dCamera *camera);
void G3D_CAMERA_SetFovySin(struct G3dCamera *camera, u32 v);
void G3D_CAMERA_GetFovyCos(struct G3dCamera *camera, u32 *out);
void G3D_CAMERA_SetFovyCos(struct G3dCamera *camera, u32 v);
void G3D_CAMERA_GetNearClipAlt(struct G3dCamera *camera, u32 *out);
void G3D_CAMERA_SetNearClipAlt(struct G3dCamera *camera, u32 v);
void G3D_CAMERA_GetFarClipAlt(struct G3dCamera *camera, u32 *out);
void G3D_CAMERA_SetFarClipAlt(struct G3dCamera *camera, u32 v);
/* END mkheaders: generated region */

#endif
