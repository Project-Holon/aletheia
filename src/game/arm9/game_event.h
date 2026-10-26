#ifndef GAME_ARM9_GAME_EVENT_H
#define GAME_ARM9_GAME_EVENT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of game_event.c, prototypes copied from their definitions. */

struct GameEvent;
struct GameSystem;

#include "../arm9/ica_anime_shared_types.h"
#include "../types.h"

struct GameEvent *GAME_EVENT_Create(struct GameSystem *gameSystem, struct GameEvent *parent, GameEventFunc func, u32 workSize);
int GAME_EVENT_RunFunc(struct GameEvent *event);
void GAME_EVENT_Delete(struct GameEvent *event);
void GAME_EVENT_Change(struct GameEvent *event, GameEventFunc func, u32 workSize);
void GAME_EVENT_ChangeEvent(struct GameEvent *now, struct GameEvent *next);
void GAME_EVENT_CallEvent(struct GameEvent *parent, struct GameEvent *child);
int GAME_EVENT_Control(struct GameSystem *gameSystem);
int GAME_EVENT_IsRunning(struct GameSystem *gameSystem);
int GAME_EVENT_StartByCreator(struct GameSystem *gameSystem, GameEventCreatorFn creator, void *arg);
int GAME_EVENT_CallProcSeq(struct GameEvent *event, int *seq, void *work);
void GAME_EVENT_CallProc(struct GameEvent *parent, u32 overlayId, void *procData, void *param);
int GAME_EVENT_OverlaySeq(struct GameEvent *event, int *seq, void *work);
struct GameEvent *GAME_EVENT_CreateOverlayEvent(struct GameSystem *gameSystem, u32 overlayId, GameEventCreatorFn creator, void *arg);
struct GameSystem *GAME_EVENT_GetGameSystem(struct GameEvent *event);
void *GAME_EVENT_GetWork(struct GameEvent *event);
int *GAME_EVENT_GetSeq(struct GameEvent *event);
struct GameEvent *GAME_EVENT_GetParent(struct GameEvent *event);
/* END mkheaders: generated region */

#endif
