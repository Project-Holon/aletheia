#ifndef GAME_OV000_EVENT_GSYNC_H
#define GAME_OV000_EVENT_GSYNC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_gsync.c, prototypes copied from their definitions. */

struct GameEvent;
struct GsyncEventWork;
typedef struct GsyncEventWork GsyncEventWork;

#include "../types.h"

u32 EVENT_GSYNC_Main(struct GameEvent *event, u32 *seq, GsyncEventWork *work);
void *EVENT_GSYNC_Entry(void *gameSystem);
void *EVENT_GSYNC_Create(void *gameSystem);
/* END mkheaders: generated region */

#endif
