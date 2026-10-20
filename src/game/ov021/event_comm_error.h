#ifndef GAME_OV021_EVENT_COMM_ERROR_H
#define GAME_OV021_EVENT_COMM_ERROR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_comm_error.c, prototypes copied from their definitions. */

#include "../ov020/event_mapchange_types.h"
#include "../ov020/event_mapchange_types.h"
#include "../ov020/event_mapchange_types.h"

GameEvent *EVENT_COMM_ERROR_Create(GameSystem *gameSystem, FieldMap *fieldMap);
int EVENT_COMM_ERROR_Run(GameEvent *event, int *seq, void *work);
int EVENT_COMM_ERROR_RunCommExit(GameEvent *event, int *seq, void *work);
int EVENT_COMM_ERROR_SubProcInit(void *proc, int *seq, void *procWork, void *myWork);
int EVENT_COMM_ERROR_SubProcMain(void *proc, int *seq, void *procWork, void *myWork);
int EVENT_COMM_ERROR_SubProcEnd(void *proc, int *seq, void *procWork, void *myWork);
/* END mkheaders: generated region */

#endif
