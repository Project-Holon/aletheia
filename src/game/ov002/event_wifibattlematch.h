#ifndef GAME_OV002_EVENT_WIFIBATTLEMATCH_H
#define GAME_OV002_EVENT_WIFIBATTLEMATCH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_wifibattlematch.c, prototypes copied from their definitions. */

struct GameEvent;
struct WifiBattleMatchEventWork;
typedef struct WifiBattleMatchEventWork WifiBattleMatchEventWork;

#include "../types.h"

u32 EVENT_WIFIBATTLEMATCH_Main(struct GameEvent *event, u32 *seq, WifiBattleMatchEventWork *work);
void *EVENT_WIFIBATTLEMATCH_Create(void *gameSystem, struct FieldMap *fieldMap, int entryMode, int ratedFlag, int matchKind);
void EVENT_WIFIBATTLEMATCH_Entry(s32 gameSystem, s32 *request);
/* END mkheaders: generated region */

#endif
