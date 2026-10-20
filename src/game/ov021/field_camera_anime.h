#ifndef GAME_OV021_FIELD_CAMERA_ANIME_H
#define GAME_OV021_FIELD_CAMERA_ANIME_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_camera_anime.c, prototypes copied from their definitions. */

struct FieldCameraAnime;
typedef struct FieldCameraAnime FieldCameraAnime;

#include "../ov021/field_camera_types.h"
#include "../ov021/field_camera_types.h"
#include "../ov020/event_mapchange_types.h"
#include "../types.h"

void FIELD_CAMERA_ANIME_GetCurrentParam(FieldCamera *camera, FieldCameraParam *param);
FieldCameraAnime *FIELD_CAMERA_ANIME_Create(FieldMap *fieldMap);
void FIELD_CAMERA_ANIME_Delete(FieldCameraAnime *anime);
void FIELD_CAMERA_ANIME_SetData(FieldCameraAnime *anime, FieldCameraAnimeData *data);
int FIELD_CAMERA_ANIME_Setup(FieldCameraAnime *anime);
void FIELD_CAMERA_ANIME_ApplyStartParam(FieldCameraAnime *anime);
void FIELD_CAMERA_ANIME_Start(FieldCameraAnime *anime);
void FIELD_CAMERA_ANIME_Restore(FieldCameraAnime *anime);
FieldCameraAnime *FIELD_CAMERA_ANIME_Alloc(u16 heapId);
void FIELD_CAMERA_ANIME_Free(FieldCameraAnime *anime);
void FIELD_CAMERA_ANIME_Init(FieldCameraAnime *anime, FieldMap *fieldMap);
u32 FIELD_CAMERA_ANIME_SaveCameraState(FieldCameraAnime *anime);
void FIELD_CAMERA_ANIME_SaveCameraMode(FieldCameraAnime *anime);
void FIELD_CAMERA_ANIME_RestoreCameraState(FieldCameraAnime *anime);
void FIELD_CAMERA_ANIME_SetAnglesFromPos(FieldCamera *camera);
void FIELD_CAMERA_ANIME_SetTargetFromCurrent(FieldCamera *camera);
void FIELD_CAMERA_ANIME_ReadParam(FieldCamera *camera, FieldCameraParam *param);
void FIELD_CAMERA_ANIME_ApplyEndParam(FieldCameraAnime *anime);
void FIELD_CAMERA_ANIME_StartMoveTasks(FieldCameraAnime *anime);
FieldCamera *FIELD_CAMERA_ANIME_GetCamera(FieldCameraAnime *anime);
FieldCameraAnimeData *FIELD_CAMERA_ANIME_GetData(FieldCameraAnime *anime);
/* END mkheaders: generated region */

#endif
