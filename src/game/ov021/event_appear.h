#ifndef GAME_OV021_EVENT_APPEAR_H
#define GAME_OV021_EVENT_APPEAR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_appear.c, prototypes copied from their definitions. */

struct EventAppearWork;
typedef struct EventAppearWork EventAppearWork;

#include "../ov020/event_mapchange_types.h"
#include "../ov020/event_mapchange_types.h"
#include "../ov020/event_mapchange_types.h"
#include "../ov020/event_mapchange_types.h"

GameEvent *EVENT_APPEAR_CreatePlayerDrop(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_APPEAR_CreateSpinZoom(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int showSeasonScoreboard, int seasonShown, int seasonTarget);
GameEvent *EVENT_APPEAR_CreateSpinZoomAlt(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int showSeasonScoreboard, int seasonShown, int seasonTarget);
GameEvent *EVENT_APPEAR_CreateSpinZoomSmoke(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_APPEAR_CreateDescendingSpin(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_APPEAR_CreateMoveAnime(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap);
int EVENT_APPEAR_RunPlayerDrop(GameEvent *event, int *seq, EventAppearWork *work);
int EVENT_APPEAR_RunSpinZoom(GameEvent *event, int *seq, EventAppearWork *work);
void EVENT_APPEAR_StartZoomOut(EventAppearWork *work);
void EVENT_APPEAR_EndZoomOut(EventAppearWork *work);
void EVENT_APPEAR_StartPlayerSpin(EventAppearWork *work);
GameEvent *EVENT_APPEAR_CreateFadeIn(EventAppearWork *work);
void EVENT_APPEAR_OnScoreboardEnd(EventAppearWork *work);
int EVENT_APPEAR_RunSpinZoomAlt(GameEvent *event, int *seq, EventAppearWork *work);
void EVENT_APPEAR_StartZoomOutAlt(EventAppearWork *work);
void EVENT_APPEAR_EndZoomOutAlt(EventAppearWork *work);
void EVENT_APPEAR_StartPlayerSpinAlt(EventAppearWork *work);
GameEvent *EVENT_APPEAR_CreateFadeInAlt(EventAppearWork *work);
void EVENT_APPEAR_OnScoreboardEndAlt(EventAppearWork *work);
int EVENT_APPEAR_RunSpinZoomSmoke(GameEvent *event, int *seq, EventAppearWork *work);
int EVENT_APPEAR_RunDescendingSpin(GameEvent *event, int *seq, EventAppearWork *work);
int EVENT_APPEAR_RunMoveAnime(GameEvent *event, int *seq, EventAppearWork *work);
/* END mkheaders: generated region */

#endif
