#ifndef GAME_OV021_EVENT_ENTRANCE_OUT_H
#define GAME_OV021_EVENT_ENTRANCE_OUT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_entrance_out.c, prototypes copied from their definitions. */

#include "../ov020/event_mapchange_types.h"
#include "../ov020/event_mapchange_types.h"
#include "../types.h"
#include "../ov021/event_entrance_in_types.h"

GameEvent *EVENT_ENTRANCE_OUT_Create(EntranceParam *param);
u32 EVENT_ENTRANCE_OUT_RunPlain(GameEvent *event, int *seq, EntranceOutWork *work);
u32 EVENT_ENTRANCE_OUT_RunGroundAnime(GameEvent *event, int *seq, EntranceOutWork *work);
u32 EVENT_ENTRANCE_OUT_RunObjectAnime(GameEvent *event, int *seq, EntranceOutWork *work);
u32 EVENT_ENTRANCE_OUT_RunAppear(GameEvent *event, int *seq, EntranceOutWork *work);
u32 EVENT_ENTRANCE_OUT_RunCamera(GameEvent *event, int *seq, EntranceOutWork *work);
u32 EVENT_ENTRANCE_OUT_RunFadeSe(GameEvent *event, int *seq, EntranceOutWork *work);
void EVENT_ENTRANCE_OUT_PostBgmFadeIn(EntranceOutWork *work);
void EVENT_ENTRANCE_OUT_StartBgmFadeIn(EntranceOutWork *work, GameEvent *event);
void EVENT_ENTRANCE_OUT_CallFadeIn(EntranceOutWork *work, GameEvent *event);
void EVENT_ENTRANCE_OUT_ShowPlaceName(EntranceOutWork *work);
/* END mkheaders: generated region */

#endif
