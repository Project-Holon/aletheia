#ifndef GAME_OV021_ENTRANCE_CAMERA_H
#define GAME_OV021_ENTRANCE_CAMERA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of entrance_camera.c, prototypes copied from their definitions. */

struct FieldCamera;

#include "../ov020/event_mapchange_types.h"
#include "../ov021/entrance_camera_types.h"
#include "../sdk_fx.h"

void *ENTRANCE_CAMERA_Create(FieldMap *fieldMap);
void ENTRANCE_CAMERA_Delete(EntranceCamera *work);
void ENTRANCE_CAMERA_Setup(EntranceCamera *work, const EntranceCameraRequest *request);
void ENTRANCE_CAMERA_Start(EntranceCamera *work);
void ENTRANCE_CAMERA_Restore(EntranceCamera *work);
int ENTRANCE_CAMERA_IsActive(EntranceCamera *work);
int ENTRANCE_CAMERA_IsInstant(EntranceCamera *work);
void *ENTRANCE_CAMERA_AllocWork(int heapId);
void ENTRANCE_CAMERA_FreeWork(void *work);
void ENTRANCE_CAMERA_InitWork(EntranceCamera *work, FieldMap *fieldMap);
void ENTRANCE_CAMERA_CreateAnime(EntranceCamera *work, int heapId);
void ENTRANCE_CAMERA_DeleteAnime(EntranceCamera *work);
void ENTRANCE_CAMERA_SetupLeaveByDir(EntranceCamera *work);
void ENTRANCE_CAMERA_SetupArriveByDir(EntranceCamera *work);
void ENTRANCE_CAMERA_SetupLeaveByRecord(EntranceCamera *work);
void ENTRANCE_CAMERA_SetupArriveByRecord(EntranceCamera *work);
void ENTRANCE_CAMERA_LoadRecord(EntranceCameraRecord *dst, int entranceType);
void ENTRANCE_CAMERA_AimAtTarget(struct FieldCamera *camera, VecFx32 *target);
struct FieldCamera *ENTRANCE_CAMERA_GetCamera(EntranceCamera *work);
EntranceCameraRequest *ENTRANCE_CAMERA_GetRequest(EntranceCamera *work);
void ENTRANCE_CAMERA_SetRequest(EntranceCamera *work, const EntranceCameraRequest *request);
int ENTRANCE_CAMERA_GetEntranceType(EntranceCamera *work);
int ENTRANCE_CAMERA_HasRecord(EntranceCamera *work);
int ENTRANCE_CAMERA_AimsAtEntrance(EntranceCamera *work);
int ENTRANCE_CAMERA_IsPhaseActive(EntranceCamera *work);
/* END mkheaders: generated region */

#endif
