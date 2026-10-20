#ifndef GAME_OV054_FIELD_GIMMICK_SOUND_OBJS_B_H
#define GAME_OV054_FIELD_GIMMICK_SOUND_OBJS_B_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_sound_objs_b.c, prototypes copied from their definitions. */

struct FieldMap;

#include "../ov054/field_gimmick_sound_objs_b_types.h"

void FIELD_GIMMICK_SOUND_OBJS_B_Init(struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_B_Exit(struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_B_Update(struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_B_CreateSoundObjs(FieldGimmickSoundObjsBWork *work, struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_B_LoadWaitLimits(FieldGimmickSoundObjsBWork *work);
void FIELD_GIMMICK_SOUND_OBJS_B_SaveAnimeFrames(FieldGimmickSoundObjsBWork *work, struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_B_ExitSoundObjs(FieldGimmickSoundObjsBWork *work, struct FieldMap *fieldMap);
void FIELD_GIMMICK_SOUND_OBJS_B_StartWait(FieldGimmickSoundObjsBWork *work, int index);
void FIELD_GIMMICK_SOUND_OBJS_B_RestartAnime(FieldGimmickSoundObjsBWork *work, int index);
/* END mkheaders: generated region */

#endif
