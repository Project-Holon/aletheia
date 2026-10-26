#ifndef GAME_OV002_EVENT_WIFIBATTLEMATCH_H
#define GAME_OV002_EVENT_WIFIBATTLEMATCH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_wifibattlematch.c, prototypes copied from their definitions. */

struct GameEvent;
struct GameSystem;
struct WifiBattleMatchRequest;
typedef struct WifiBattleMatchRequest WifiBattleMatchRequest;
struct WifiBattleMatchEventWork;
typedef struct WifiBattleMatchEventWork WifiBattleMatchEventWork;

#include "../types.h"

int EVENT_WIFIBATTLEMATCH_Main(struct GameEvent *event, int *seq, void *work);
void *EVENT_WIFIBATTLEMATCH_Create(void *gameSystem, struct FieldMap *fieldMap, int entryMode, int ratedFlag, int matchKind);
struct GameEvent *EVENT_WIFIBATTLEMATCH_Entry(struct GameSystem *gameSystem, WifiBattleMatchRequest *request);
/* END mkheaders: generated region */

#endif
