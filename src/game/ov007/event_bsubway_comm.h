#ifndef GAME_OV007_EVENT_BSUBWAY_COMM_H
#define GAME_OV007_EVENT_BSUBWAY_COMM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_bsubway_comm.c, prototypes copied from their definitions. */

struct BsubwayProcArgs;
typedef struct BsubwayProcArgs BsubwayProcArgs;

#include "../types.h"

int EVENT_BSUBWAY_COMM_Start(int gameSystem, BsubwayProcArgs *args);
void *EVENT_BSUBWAY_COMM_CreateEvent(void *gameSystem, int value, int resultPtr);
u32 EVENT_BSUBWAY_COMM_EventMain(void *event, u32 *stage, u32 *work);
/* END mkheaders: generated region */

#endif
