#ifndef GAME_OV021_FIELD_DOOR_ANIME_H
#define GAME_OV021_FIELD_DOOR_ANIME_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_door_anime.c, prototypes copied from their definitions. */

struct GameEvent;
struct DoorAnimeWork;
struct GameSystem;
struct FieldMap;
typedef struct DoorAnimeWork DoorAnimeWork;

#include "../types.h"

int FIELD_DOOR_ANIME_OpenTask(struct GameEvent *task, int *seq, void *work);
struct GameEvent *FIELD_DOOR_ANIME_StartOpen(struct GameEvent *parent, struct GameSystem *gameSys, struct FieldMap *fieldmap);
int FIELD_DOOR_ANIME_SetOpenTask(struct GameEvent *task, int *seq, void *work);
struct GameEvent *FIELD_DOOR_ANIME_StartSetOpen(struct GameEvent *parent, struct GameSystem *gameSys, struct FieldMap *fieldmap);
int FIELD_DOOR_ANIME_CloseTask(struct GameEvent *task, int *seq, void *work);
struct GameEvent *FIELD_DOOR_ANIME_StartClose(struct GameEvent *parent, struct GameSystem *gameSys, struct FieldMap *fieldmap, u32 silent);
/* END mkheaders: generated region */

#endif
