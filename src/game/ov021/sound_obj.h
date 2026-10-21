#ifndef GAME_OV021_SOUND_OBJ_H
#define GAME_OV021_SOUND_OBJ_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sound_obj.c, prototypes copied from their definitions. */

struct SoundObj;
typedef struct SoundObj SoundObj;

#include "../ov020/event_mapchange_types.h"
#include "../sdk_fx.h"
#include "../types.h"
#include "../arm9/g3d_system_types.h"

SoundObj *SOUND_OBJ_Create(FieldMap *fieldMap, VecFx32 *pos, u32 sourceId, u32 startArg0, u32 startArg1);
SoundObj *SOUND_OBJ_CreateNoSource(FieldMap *fieldMap, G3dObjectStatus *target);
int SOUND_OBJ_Delete(SoundObj *obj);
void SOUND_OBJ_SetAnime(SoundObj *obj, u32 arcId, u32 dataId, u32 bufFrameNum);
u32 SOUND_OBJ_AdvanceAnime(SoundObj *obj, s32 deltaFrame);
void SOUND_OBJ_SetAnimeFrame(SoundObj *obj, s32 frame);
u32 SOUND_OBJ_GetAnimeFrame(SoundObj *obj);
void SOUND_OBJ_ApplyPosition(SoundObj *obj);
void SOUND_OBJ_ApplyRotation(SoundObj *obj);
/* END mkheaders: generated region */

#endif
