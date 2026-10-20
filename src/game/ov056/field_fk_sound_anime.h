#ifndef GAME_OV056_FIELD_FK_SOUND_ANIME_H
#define GAME_OV056_FIELD_FK_SOUND_ANIME_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_fk_sound_anime.c, prototypes copied from their definitions. */

struct FieldSubproc;
struct FieldMap;

#include "../ov056/field_fk_demo_types.h"
#include "../types.h"

void FIELD_FK_SOUND_ANIME_InitFrameSound(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkFrameSoundWork *work);
void FIELD_FK_SOUND_ANIME_ExitFrameSound(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkFrameSoundWork *work);
void FIELD_FK_SOUND_ANIME_UpdateFrameSound(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkFrameSoundWork *work);
void FIELD_FK_SOUND_ANIME_InitAmbientSoundA(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work);
void FIELD_FK_SOUND_ANIME_ExitAmbientSoundA(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work);
void FIELD_FK_SOUND_ANIME_UpdateAmbientSoundA(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work);
void FIELD_FK_SOUND_ANIME_InitAmbientSoundB(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work);
void FIELD_FK_SOUND_ANIME_ExitAmbientSoundB(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work);
void FIELD_FK_SOUND_ANIME_UpdateAmbientSoundB(struct FieldSubproc *proc, struct FieldMap *fieldMap, FkAmbientSoundWork *work);
FkSoundAnime *FIELD_FK_SOUND_ANIME_Create(const void *soundIds, u32 arcId, u32 dataId, u32 bufFrameNum, u16 heapId);
void FIELD_FK_SOUND_ANIME_Delete(FkSoundAnime *sound);
int FIELD_FK_SOUND_ANIME_Step(FkSoundAnime *sound);
void FIELD_FK_SOUND_ANIME_PlaySe(FkSoundAnime *sound, u32 channel);
void FIELD_FK_SOUND_ANIME_StopSe(FkSoundAnime *sound, u32 channel);
/* END mkheaders: generated region */

#endif
