#ifndef GAME_OV021_EVENT_NAMEIN_H
#define GAME_OV021_EVENT_NAMEIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_namein.c, prototypes copied from their definitions. */

struct GameEvent;
struct NameInEvent;
struct NameInParam;
typedef struct NameInEvent NameInEvent;
typedef struct NameInParam NameInParam;

#include "../types.h"

struct GameEvent *EVENT_NAMEIN_Create(void *gameSystem, void *fieldMap, void *parentEvent, u32 mode, u16 *resultVar);
int EVENT_NAMEIN_Main(struct GameEvent *event, int *seq, NameInEvent *work);
void EVENT_NAMEIN_StoreResult(NameInEvent *work, NameInParam *param);
/* END mkheaders: generated region */

#endif
