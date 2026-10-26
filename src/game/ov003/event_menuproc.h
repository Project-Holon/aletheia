#ifndef GAME_OV003_EVENT_MENUPROC_H
#define GAME_OV003_EVENT_MENUPROC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_menuproc.c, prototypes copied from their definitions. */

struct GameEvent;
struct MenuProcEventWork;
typedef struct MenuProcEventWork MenuProcEventWork;

#include "../types.h"

int EVENT_MENUPROC_Main(struct GameEvent *event, int *seq, void *work);
void *EVENT_MENUPROC_Create(void *gameSystem, struct FieldMap *fieldMap, int procKind);
/* END mkheaders: generated region */

#endif
