#ifndef GAME_OV010_BEACON_VIEW_EVENT_H
#define GAME_OV010_BEACON_VIEW_EVENT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of beacon_view_event.c, prototypes copied from their definitions. */

struct GameEvent;
struct BeaconSearchEventWork;
struct GameSystem;
typedef struct BeaconSearchEventWork BeaconSearchEventWork;

#include "../types.h"

int BEACON_VIEW_EVENT_Sequence(struct GameEvent *event, u32 *seq, BeaconSearchEventWork *work);
struct GameEvent *BEACON_VIEW_EVENT_Create(struct GameSystem *gameSystem, void *unused, u8 mode);
/* END mkheaders: generated region */

#endif
