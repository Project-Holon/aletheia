#ifndef GAME_OV021_EVENT_ENTRANCE_IN_H
#define GAME_OV021_EVENT_ENTRANCE_IN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_entrance_in.c, prototypes copied from their definitions. */

#include "../ov020/event_mapchange_types.h"
#include "../ov020/event_mapchange_types.h"
#include "../types.h"
#include "../ov021/event_entrance_in_types.h"

GameEvent *EVENT_ENTRANCE_IN_Create(EntranceParam *param);
u32 EVENT_ENTRANCE_IN_RunPlain(GameEvent *event, int *seq, EntranceInWork *work);
u32 EVENT_ENTRANCE_IN_RunGroundAnime(GameEvent *event, int *seq, EntranceInWork *work);
u32 EVENT_ENTRANCE_IN_RunObjectAnime(GameEvent *event, int *seq, EntranceInWork *work);
u32 EVENT_ENTRANCE_IN_RunAppear(GameEvent *event, int *seq, EntranceInWork *work);
u32 EVENT_ENTRANCE_IN_RunCamera(GameEvent *event, int *seq, EntranceInWork *work);
u32 EVENT_ENTRANCE_IN_RunFadeSe(GameEvent *event, int *seq, EntranceInWork *work);
u32 EVENT_ENTRANCE_IN_ShouldFadeBgm(EntranceInWork *work);
int EVENT_ENTRANCE_IN_IsDungeonTransition(EntranceInWork *work);
u32 EVENT_ENTRANCE_IN_GetPlayerForm(EntranceInWork *work);
void EVENT_ENTRANCE_IN_ReplaceBgm(EntranceInWork *work);
void EVENT_ENTRANCE_IN_StartBgmFadeOut(EntranceInWork *work, GameEvent *event);
void EVENT_ENTRANCE_IN_CallFadeOut(EntranceInWork *work, GameEvent *event);
/* END mkheaders: generated region */

#endif
