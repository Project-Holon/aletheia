#ifndef GAME_OV007_EVENT_BSUBWAY_COMM_H
#define GAME_OV007_EVENT_BSUBWAY_COMM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_bsubway_comm.c, prototypes copied from their definitions. */

struct GameEvent;
struct GameSystem;
struct BsubwayProcArgs;
typedef struct BsubwayProcArgs BsubwayProcArgs;

#include "../types.h"

struct GameEvent *EVENT_BSUBWAY_COMM_Start(struct GameSystem *gameSystem, void *arg);
struct GameEvent *EVENT_BSUBWAY_COMM_CreateEvent(struct GameSystem *gameSystem, int value, int *resultPtr);
u32 EVENT_BSUBWAY_COMM_EventMain(void *event, u32 *stage, u32 *work);
/* END mkheaders: generated region */

#endif
