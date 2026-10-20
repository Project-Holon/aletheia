#ifndef GAME_OV010_FIELD_INTRUDE_EVENT_H
#define GAME_OV010_FIELD_INTRUDE_EVENT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_intrude_event.c, prototypes copied from their definitions. */

struct GameEvent;
struct GameSystem;

#include "../types.h"
#include "../ov010/field_intrude_event_shared_types.h"
#include "../ov010/field_intrude_event_shared_types.h"

struct GameEvent *FIELD_INTRUDE_EVENT_CreateIntrudeRequestEvent(struct GameSystem *gameSystem, u16 *result, int requestType);
void FIELD_INTRUDE_EVENT_GetEdgePosition(FxVec3 *src, int edge, FxVec3 *dst);
struct GameEvent *FIELD_INTRUDE_EVENT_CreateSymbolEntryEvent(struct GameSystem *gameSystem, int playSe, FxVec3 *position, int edge, int cellId);
struct GameEvent *FIELD_INTRUDE_EVENT_StartSymbolEntry(struct GameSystem *gameSystem, int edge, int cellId);
/* END mkheaders: generated region */

#endif
