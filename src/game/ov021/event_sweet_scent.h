#ifndef GAME_OV021_EVENT_SWEET_SCENT_H
#define GAME_OV021_EVENT_SWEET_SCENT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_sweet_scent.c, prototypes copied from their definitions. */

struct SweetScentWork;
struct SweetScentFade;
typedef struct SweetScentWork SweetScentWork;
typedef struct SweetScentFade SweetScentFade;

#include "../types.h"

void *SWEET_SCENT_CreateEventNoPokemon(void *fieldMap, void *gameSys);
void *SWEET_SCENT_CreateEvent(void *gameSys, void *fieldMap, u8 partyIdx);
int SWEET_SCENT_EventMain(struct GameEvent *task, int *state, void *work);
int SWEET_SCENT_CheckWeatherClear(SweetScentWork *w);
void SWEET_SCENT_StartFade(void *task, void *gameSys, void *fieldMap);
int SWEET_SCENT_FadeMain(struct GameEvent *task, int *state, void *work);
void SWEET_SCENT_FadeSetup(SweetScentFade *fade);
void SWEET_SCENT_FadeCleanup(SweetScentFade *fade);
/* END mkheaders: generated region */

#endif
