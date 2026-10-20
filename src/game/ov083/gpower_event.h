#ifndef GAME_OV083_GPOWER_EVENT_H
#define GAME_OV083_GPOWER_EVENT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gpower_event.c, prototypes copied from their definitions. */

struct GameEvent;
struct GameSystem;
struct FieldMap;
struct WordSet;
struct Strbuf;

#include "../ov083/gpower_event_types.h"
#include "../types.h"

struct GameEvent *GPOWER_EVENT_CreateActivateEvent(struct GameSystem *gameSystem, GPowerActivateParam *param);
struct GameEvent *GPOWER_EVENT_CreateTimeoutScriptEvent(struct GameSystem *gameSystem);
struct GameEvent *GPOWER_EVENT_CreateFlashEvent(struct GameSystem *gameSystem);
struct GameEvent *GPOWER_EVENT_CreateListEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
void GPOWER_EVENT_InitListWork(GPowerListWork *work, struct GameSystem *gameSystem, struct FieldMap *fieldMap);
void GPOWER_EVENT_FreeListWork(GPowerListWork *work);
int GPOWER_EVENT_FlashMain(struct GameEvent *event, int *seq, void *work);
void GPOWER_EVENT_RestoreParty(struct GameSystem *gameSystem, struct WordSet *wordSet, int powerType);
int GPOWER_EVENT_ListMain(struct GameEvent *event, int *seq, GPowerListWork *work);
void GPOWER_EVENT_PrintPowerRow(GPowerListWork *work, struct Strbuf *templateStr, u32 powerId, int minutes, u8 row);
void GPOWER_EVENT_PrintPowerList(GPowerListWork *work);
/* END mkheaders: generated region */

#endif
