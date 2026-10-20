#ifndef GAME_OV010_EVENT_WIFI_PROC_H
#define GAME_OV010_EVENT_WIFI_PROC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_wifi_proc.c, prototypes copied from their definitions. */

struct GameEvent;
struct GameSystem;
struct FieldMap;

#include "../types.h"

struct GameEvent *EVENT_WIFI_PROC_CreateOv020Event(struct GameSystem *gameSystem, u32 initParam);
struct GameEvent *EVENT_WIFI_PROC_LoadOv020Task(struct GameSystem *gameSystem);
void EVENT_WIFI_PROC_LoadOv020(void);
void EVENT_WIFI_PROC_UnloadOv020(void);
int EVENT_WIFI_PROC_EventMain(struct GameEvent *event, u32 *seq, void *workArg);
struct GameEvent *EVENT_WIFI_PROC_Create(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct GameEvent *event, int createNew);
/* END mkheaders: generated region */

#endif
