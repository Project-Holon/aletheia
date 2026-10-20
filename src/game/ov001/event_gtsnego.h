#ifndef GAME_OV001_EVENT_GTSNEGO_H
#define GAME_OV001_EVENT_GTSNEGO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_gtsnego.c, prototypes copied from their definitions. */

struct GameEvent;
struct GtsNegoEventWork;
typedef struct GtsNegoEventWork GtsNegoEventWork;

#include "../types.h"

u32 EVENT_GTSNEGO_Main(struct GameEvent *event, u32 *seq, GtsNegoEventWork *work);
void *EVENT_GTSNEGO_InitWork(void *event, void *gameSystem, int a, int startMode);
void *EVENT_GTSNEGO_Create(void *gameSystem, int a);
void *EVENT_GTSNEGO_Entry(void *gameSystem, int a);
/* END mkheaders: generated region */

#endif
