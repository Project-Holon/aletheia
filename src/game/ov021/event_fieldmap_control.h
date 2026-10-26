#ifndef GAME_OV021_EVENT_FIELDMAP_CONTROL_H
#define GAME_OV021_EVENT_FIELDMAP_CONTROL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_fieldmap_control.c, prototypes copied from their definitions. */

struct FieldFadeWork;
typedef struct FieldFadeWork FieldFadeWork;

#include "../types.h"
#include "../ov020/event_mapchange_types.h"
#include "../ov020/event_mapchange_types.h"
#include "../ov020/event_mapchange_types.h"
#include "../ov021/event_fieldmap_control_types.h"

int EVENT_FIELDMAP_CONTROL_GetExitEffect(int fromZoneId, u32 toZoneId);
int EVENT_FIELDMAP_CONTROL_GetEntranceEffect(int fromZoneId, int toZoneId);
GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeOut(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait);
GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeIn(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait, int restoreBg, u8 seasonShown, u8 seasonTarget);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateSeasonFadeInEventWithCallback(GameSystem *gameSystem, FieldMap *fieldMap, int seasonShown, int seasonTarget, FieldFadeCallback finishCallback, void *finishCallbackArg);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeInEventWithBgRestore(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait, int fadeSpeed);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEvent(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait);
int EVENT_FIELDMAP_CONTROL_GetFadeKind(int effect);
u32 EVENT_FIELDMAP_CONTROL_LookupExitEffect(int fromGroup, int toGroup);
u32 EVENT_FIELDMAP_CONTROL_LookupEntranceEffect(int fromGroup, int toGroup);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventForEffect(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeInEventForEffect(GameSystem *gameSystem, FieldMap *fieldMap, int effect, int skipWait, int restoreBg);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventDefault(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeInEventDefault(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateSeasonFadeInEvent(GameSystem *gameSystem, FieldMap *fieldMap, int seasonShown, int seasonTarget);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect4(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect5(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect5(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect6(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect6(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect7(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect7(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeOutEventEffect8(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect8(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeOutByFacing(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeInByFacing(GameSystem *gameSystem, FieldMap *fieldMap);
int EVENT_FIELDMAP_CONTROL_RunFadeOut(struct GameEvent *event, int *seq, void *work);
int EVENT_FIELDMAP_CONTROL_RunFadeIn(struct GameEvent *event, int *seq, void *work);
int EVENT_FIELDMAP_CONTROL_RunDefaultFadeOut(struct GameEvent *event, int *seq, void *work);
int EVENT_FIELDMAP_CONTROL_RunDefaultFadeIn(struct GameEvent *event, int *seq, void *work);
int EVENT_FIELDMAP_CONTROL_RunSeasonFadeIn(struct GameEvent *event, int *seq, void *work);
int EVENT_FIELDMAP_CONTROL_RunSeasonFadeInWithCallback(struct GameEvent *event, int *seq, void *work);
int EVENT_FIELDMAP_CONTROL_RunWipeOutEffect4(struct GameEvent *event, int *seq, void *work);
int EVENT_FIELDMAP_CONTROL_RunWipeOutEffect5(struct GameEvent *event, int *seq, void *work);
int EVENT_FIELDMAP_CONTROL_RunWipeOutEffect6(struct GameEvent *event, int *seq, void *work);
int EVENT_FIELDMAP_CONTROL_RunWipeOutEffect7(struct GameEvent *event, int *seq, void *work);
int EVENT_FIELDMAP_CONTROL_RunWipeOutEffect8(struct GameEvent *event, int *seq, void *work);
int EVENT_FIELDMAP_CONTROL_RunWipeInEffect5(struct GameEvent *event, int *seq, void *work);
int EVENT_FIELDMAP_CONTROL_RunWipeInEffect6(struct GameEvent *event, int *seq, void *work);
int EVENT_FIELDMAP_CONTROL_RunWipeInEffect7(struct GameEvent *event, int *seq, void *work);
int EVENT_FIELDMAP_CONTROL_RunWipeInEffect8(struct GameEvent *event, int *seq, void *work);
int EVENT_FIELDMAP_CONTROL_RunFadeInWithBgRestore(struct GameEvent *event, int *seq, void *work);
void EVENT_FIELDMAP_CONTROL_ResetBgModeKeepPlanes();
void EVENT_FIELDMAP_CONTROL_ResetBgAffine(FieldMap *fieldMap);
/* END mkheaders: generated region */

#endif
