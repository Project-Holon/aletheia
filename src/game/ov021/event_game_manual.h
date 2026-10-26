#ifndef GAME_OV021_EVENT_GAME_MANUAL_H
#define GAME_OV021_EVENT_GAME_MANUAL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_game_manual.c, prototypes copied from their definitions. */

struct GameEvent;
struct GameSystem;
struct EventGameManualWork;
typedef struct EventGameManualWork EventGameManualWork;

#include "../types.h"

struct GameEvent *EVENT_GAME_MANUAL_Create(struct GameSystem *gameSystem, u16 *resultOut);
int EVENT_GAME_MANUAL_Main(struct GameEvent *event, int *seq, void *work);
void EVENT_GAME_MANUAL_SetResult(EventGameManualWork *work);
/* END mkheaders: generated region */

#endif
