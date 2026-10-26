#ifndef GAME_ARM9_FIELD_STATUS_H
#define GAME_ARM9_FIELD_STATUS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_status.c, prototypes copied from their definitions. */

struct FieldStatus;
struct GameEvent;
struct GameSystem;
struct FieldMap;

#include "../types.h"

struct FieldStatus *FIELD_STATUS_Create(int heapId);
void FIELD_STATUS_Delete(struct FieldStatus *fs);
u32 FIELD_STATUS_GetMapMode(struct FieldStatus *fs);
void FIELD_STATUS_SetMapMode(struct FieldStatus *fs, u32 mapMode);
void FIELD_STATUS_SetFieldInitFlag(struct FieldStatus *fs, u8 fieldInitFlag);
u8 FIELD_STATUS_GetFieldInitFlag(struct FieldStatus *fs);
void FIELD_STATUS_SetContinueFlag(struct FieldStatus *fs, u8 continueFlag);
u8 FIELD_STATUS_GetContinueFlag(struct FieldStatus *fs);
void FIELD_STATUS_SetFlashActive(struct FieldStatus *fs, u8 flashActive);
u8 FIELD_STATUS_IsFlashActive(struct FieldStatus *fs);
void FIELD_STATUS_SetMapEffectMask(struct FieldStatus *fs, u32 mapEffectMask);
u16 FIELD_STATUS_GetMapEffectMask(struct FieldStatus *fs);
void FIELD_STATUS_SetProcAction(struct FieldStatus *fs, u16 procAction);
u16 FIELD_STATUS_GetProcAction(struct FieldStatus *fs);
u8 FIELD_STATUS_SwapSeasonDispFlag(struct FieldStatus *fs, u8 seasonDispFlag);
u8 FIELD_STATUS_GetSeasonDispFlag(struct FieldStatus *fs);
int FIELD_STATUS_FieldCloseEvent(struct GameEvent *event, int *seq, void *work);
struct GameEvent *FIELD_STATUS_CreateFieldCloseEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
int FIELD_STATUS_FieldCloseNoSoundWaitEvent(struct GameEvent *event, int *seq, void *work);
struct GameEvent *FIELD_STATUS_CreateFieldCloseNoSoundWaitEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
int FIELD_STATUS_FieldOpenEvent(struct GameEvent *event, int *seq, void *work);
struct GameEvent *FIELD_STATUS_CreateFieldOpenEvent(struct GameSystem *gameSystem);
struct GameEvent *FIELD_STATUS_CreateFieldOpenNoNotifyEvent(struct GameSystem *gameSystem);
int FIELD_STATUS_SubProcEvent(struct GameEvent *event, int *seq, void *work);
int FIELD_STATUS_SubProcNoFadeEvent(struct GameEvent *event, int *seq, void *work);
struct GameEvent *FIELD_STATUS_CreateSubProcEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 overlayId, void *procData, void *procWork);
struct GameEvent *FIELD_STATUS_CreateSubProcNoFadeEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 overlayId, void *procData, void *procWork);
int FIELD_STATUS_SubProcCallbackEvent(struct GameEvent *event, int *seq, void *work);
int FIELD_STATUS_SubProcNoFadeCallbackEvent(struct GameEvent *event, int *seq, void *work);
struct GameEvent *FIELD_STATUS_CreateSubProcCallbackEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 overlayId, void *procData, void *procWork, void (*callback)(void *), void *callbackWork);
struct GameEvent *FIELD_STATUS_CreateSubProcNoFadeCallbackEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 overlayId, void *procData, void *procWork, void (*callback)(void *), void *callbackWork);
int FIELD_STATUS_SubProcListEvent(struct GameEvent *event, u32 *seq, void *work);
void *FIELD_STATUS_CreateSubProcListEvent(void *anime, void *fieldMap, void *listParam, void *statusParam);
/* END mkheaders: generated region */

#endif
