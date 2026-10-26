#ifndef GAME_OV021_EVENT_FISHING_H
#define GAME_OV021_EVENT_FISHING_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_fishing.c, prototypes copied from their definitions. */

struct FieldMap;

#include "../sdk_fx.h"
#include "../ov021/event_fishing_types.h"
#include "../types.h"

int FISHING_CheckFacingWater(void *unused, void *fieldMap, VecFx32 *outPos);
void *FISHING_CreateEvent(struct FieldMap *fieldMap, void *gameSystem);
int FISHING_EventMain(struct GameEvent *task, int *state, void *work);
int FISHING_StepCounter(FishingWork *w, u32 limit);
int FISHING_WaitBite(FishingWork *w, u32 limit);
void FISHING_ShowBiteMark(FishingWork *w);
void FISHING_HideBiteMark(FishingWork *w);
void FISHING_StartRodEffect(FishingWork *w);
void FISHING_EndRodEffect(FishingWork *w);
/* END mkheaders: generated region */

#endif
