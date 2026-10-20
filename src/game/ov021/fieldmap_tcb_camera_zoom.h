#ifndef GAME_OV021_FIELDMAP_TCB_CAMERA_ZOOM_H
#define GAME_OV021_FIELDMAP_TCB_CAMERA_ZOOM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fieldmap_tcb_camera_zoom.c, prototypes copied from their definitions. */

struct CameraZoomWork;
typedef struct CameraZoomWork CameraZoomWork;

#include "../types.h"

void FIELDMAP_TCB_CAMERA_ZOOM_Create(void *fieldMap, u16 frames, fx32 zoomDelta);
void FIELDMAP_TCB_CAMERA_ZOOM_Main(void *task, CameraZoomWork *w);
void FIELDMAP_TCB_CAMERA_ZOOM_Step(CameraZoomWork *w);
/* END mkheaders: generated region */

#endif
