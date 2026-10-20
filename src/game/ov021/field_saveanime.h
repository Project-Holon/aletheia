#ifndef GAME_OV021_FIELD_SAVEANIME_H
#define GAME_OV021_FIELD_SAVEANIME_H

typedef struct FieldSaveAnime FieldSaveAnime;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_saveanime.c, prototypes copied from their definitions. */

struct FieldSaveAnime;
typedef struct FieldSaveAnime FieldSaveAnime;

#include "../types.h"

FieldSaveAnime *FIELD_SAVEANIME_Create(u32 heapId, void *fieldMap);
int FIELD_SAVEANIME_Delete(FieldSaveAnime *work);
void FIELD_SAVEANIME_Start(FieldSaveAnime *work);
void FIELD_SAVEANIME_Stop(FieldSaveAnime *work);
void FIELD_SAVEANIME_LoadResource(FieldSaveAnime *work, u32 heapId);
u32 FIELD_SAVEANIME_DeleteResource(FieldSaveAnime *work);
void FIELD_SAVEANIME_CreateWindow(FieldSaveAnime *work);
u32 FIELD_SAVEANIME_DeleteWindow(FieldSaveAnime *work);
void FIELD_SAVEANIME_ShowWindow(FieldSaveAnime *work);
void FIELD_SAVEANIME_HideWindow(FieldSaveAnime *work);
void FIELD_SAVEANIME_DrawFrame(FieldSaveAnime *work, u32 frame);
void FIELD_SAVEANIME_AnimTask(void *tcb, FieldSaveAnime *work);
/* END mkheaders: generated region */

#endif
