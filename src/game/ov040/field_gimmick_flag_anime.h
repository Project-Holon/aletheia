#ifndef GAME_OV040_FIELD_GIMMICK_FLAG_ANIME_H
#define GAME_OV040_FIELD_GIMMICK_FLAG_ANIME_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_flag_anime.c, prototypes copied from their definitions. */

struct FieldMap;
struct GameEvent;
struct GameSystem;

#include "../types.h"

void FIELD_GIMMICK_FLAG_ANIME_Init(struct FieldMap *fieldMap);
void FIELD_GIMMICK_FLAG_ANIME_Exit(struct FieldMap *fieldMap);
void FIELD_GIMMICK_FLAG_ANIME_Update(struct FieldMap *fieldMap);
void FIELD_GIMMICK_FLAG_ANIME_SetFlag(struct FieldMap *fieldMap);
int FIELD_GIMMICK_FLAG_ANIME_GetFlag(struct FieldMap *fieldMap);
struct GameEvent *FIELD_GIMMICK_FLAG_ANIME_CreateEvent(struct GameSystem *gameSystem, u32 modelIndex);
int FIELD_GIMMICK_FLAG_ANIME_EventPlayAnime(struct GameEvent *event, int *seq, void *work);
/* END mkheaders: generated region */

#endif
