#ifndef GAME_OV021_EVENT_DISAPPEAR_H
#define GAME_OV021_EVENT_DISAPPEAR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_disappear.c, prototypes copied from their definitions. */

struct EventDisappearWork;
typedef struct EventDisappearWork EventDisappearWork;

#include "../ov020/event_mapchange_types.h"
#include "../ov020/event_mapchange_types.h"
#include "../ov020/event_mapchange_types.h"
#include "../ov020/event_mapchange_types.h"
#include "../sdk_fx.h"

GameEvent *EVENT_DISAPPEAR_CreateWalkFall(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, const VecFx32 *targetPos);
GameEvent *EVENT_DISAPPEAR_CreateSpinZoom(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int seasonChanged);
GameEvent *EVENT_DISAPPEAR_CreateSpinZoomEffect(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int seasonChanged);
GameEvent *EVENT_DISAPPEAR_CreateSpinFade(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap, int soundVariant);
GameEvent *EVENT_DISAPPEAR_CreateRisingSpin(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap);
int EVENT_DISAPPEAR_RunWalkFall(GameEvent *event, int *seq, EventDisappearWork *work);
int EVENT_DISAPPEAR_RunSpinZoom(GameEvent *event, int *seq, EventDisappearWork *work);
void EVENT_DISAPPEAR_StartSpin(EventDisappearWork *work);
void EVENT_DISAPPEAR_StartZoomIn(EventDisappearWork *work);
void EVENT_DISAPPEAR_EndZoomIn(EventDisappearWork *work);
GameEvent *EVENT_DISAPPEAR_CreateFadeOut(EventDisappearWork *work);
int EVENT_DISAPPEAR_RunSpinZoomEffect(GameEvent *event, int *seq, EventDisappearWork *work);
void EVENT_DISAPPEAR_StartSpinAndEffect(EventDisappearWork *work);
void EVENT_DISAPPEAR_StartZoomInAlt(EventDisappearWork *work);
void EVENT_DISAPPEAR_EndZoomInAlt(EventDisappearWork *work);
GameEvent *EVENT_DISAPPEAR_CreateFadeOutAlt(EventDisappearWork *work);
int EVENT_DISAPPEAR_RunSpinFade(GameEvent *event, int *seq, EventDisappearWork *work);
int EVENT_DISAPPEAR_RunRisingSpin(GameEvent *event, int *seq, EventDisappearWork *work);
/* END mkheaders: generated region */

#endif
