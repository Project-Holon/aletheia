#ifndef GAME_OV053_FIELD_GIMMICK_SOUND_OBJS_H
#define GAME_OV053_FIELD_GIMMICK_SOUND_OBJS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_sound_objs.c, prototypes copied from their definitions. */

struct FieldMap;
struct FieldCamera;
struct FieldPlayer;

#include "../ov053/field_gimmick_sound_objs_types.h"

void FIELD_GIMMICK_SOUND_OBJS_Init(struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_Exit(struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_Update(struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_CreateSoundObjs(FieldGimmickSoundObjsWork *work, struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_LoadWaitLimits(FieldGimmickSoundObjsWork *work);
void FIELD_GIMMICK_SOUND_OBJS_LoadBgmFade(FieldGimmickSoundObjsWork *work);
void FIELD_GIMMICK_SOUND_OBJS_SaveAnimeFrames(FieldGimmickSoundObjsWork *work, struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_RestoreAnimeFrames(FieldGimmickSoundObjsWork *work, struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_StartWait(FieldGimmickSoundObjsWork *work, int index);
void FIELD_GIMMICK_SOUND_OBJS_RestartAnime(FieldGimmickSoundObjsWork *work, int index);
void FIELD_GIMMICK_SOUND_OBJS_ApplyBgmVolume(FieldGimmickSoundObjsWork *work);
void FIELD_GIMMICK_SOUND_OBJS_UpdateBgmFade(FieldGimmickSoundObjsWork *work, struct FieldMap *fieldMap);
int FIELD_GIMMICK_SOUND_OBJS_GetBgmTargetVolume(FieldGimmickSoundObjsWork *work, struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_RaiseBgmVolume(FieldGimmickSoundObjsWork *work, int target);
void FIELD_GIMMICK_SOUND_OBJS_LowerBgmVolume(FieldGimmickSoundObjsWork *work, int target);
void FIELD_GIMMICK_SOUND_OBJS_ClearSlideSe(FieldGimmickSoundObjsSlideSe *slideSe);
void FIELD_GIMMICK_SOUND_OBJS_UpdateSlideSe(FieldGimmickSoundObjsSlideSe *slideSe, struct FieldCamera *camera, struct FieldPlayer *fieldPlayer);
/* END mkheaders: generated region */

#endif
