#ifndef GAME_OV021_FIELD_DOOR_ANIME_H
#define GAME_OV021_FIELD_DOOR_ANIME_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_door_anime.c, prototypes copied from their definitions. */

struct DoorAnimeWork;
typedef struct DoorAnimeWork DoorAnimeWork;

#include "../types.h"

int FIELD_DOOR_ANIME_OpenTask(u32 task, u32 *seq, DoorAnimeWork *work);
u32 FIELD_DOOR_ANIME_StartOpen(u32 prio, u32 gameSys, u32 fieldmap);
int FIELD_DOOR_ANIME_SetOpenTask(u32 task, u32 *seq, DoorAnimeWork *work);
u32 FIELD_DOOR_ANIME_StartSetOpen(u32 prio, u32 gameSys, u32 fieldmap);
int FIELD_DOOR_ANIME_CloseTask(u32 task, u32 *seq, DoorAnimeWork *work);
u32 FIELD_DOOR_ANIME_StartClose(u32 prio, u32 gameSys, u32 fieldmap, u32 silent);
/* END mkheaders: generated region */

#endif
