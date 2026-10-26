#ifndef GAME_OV001_EVENT_GTSNEGO_H
#define GAME_OV001_EVENT_GTSNEGO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_gtsnego.c, prototypes copied from their definitions. */

struct GameEvent;
struct GameSystem;
struct GtsNegoEventWork;
typedef struct GtsNegoEventWork GtsNegoEventWork;

#include "../types.h"

int EVENT_GTSNEGO_Main(struct GameEvent *event, int *seq, void *work);
void *EVENT_GTSNEGO_InitWork(struct GameEvent *event, struct GameSystem *gameSystem, void *arg, int startMode);
struct GameEvent *EVENT_GTSNEGO_Create(struct GameSystem *gameSystem, void *arg);
struct GameEvent *EVENT_GTSNEGO_Entry(struct GameSystem *gameSystem, void *arg);
/* END mkheaders: generated region */

#endif
