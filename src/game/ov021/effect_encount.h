#ifndef GAME_OV021_EFFECT_ENCOUNT_H
#define GAME_OV021_EFFECT_ENCOUNT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of effect_encount.c, prototypes copied from their definitions. */

struct GameEvent;
struct EffectEncountArea;
typedef struct EffectEncountArea EffectEncountArea;

#include "../ov021/effect_encount_types.h"
#include "../ov021/field_encount_types.h"
#include "../types.h"

EffectEncount *EFFECT_ENCOUNT_Create(int heapId);
int EFFECT_ENCOUNT_Delete(EffectEncount *effectEncount);
void EFFECT_ENCOUNT_Init(FieldEncount *encount, EffectEncount *effectEncount);
void EFFECT_ENCOUNT_Exit(FieldEncount *encount, EffectEncount *effectEncount);
void EFFECT_ENCOUNT_LoadSetting(FieldEncount *encount, EffectEncount *effectEncount);
void EFFECT_ENCOUNT_OnPlayerStep(FieldEncount *encount);
void EFFECT_ENCOUNT_Reset(FieldEncount *encount);
void EFFECT_ENCOUNT_UpdateOccupiedSpot(FieldEncount *encount);
int EFFECT_ENCOUNT_IsSpotAt(FieldEncount *encount, short *pos);
struct GameEvent *EFFECT_ENCOUNT_TriggerSpot(FieldEncount *encount);
int EFFECT_ENCOUNT_GetSpotDistance(FieldEncount *encount, short *out);
void EFFECT_ENCOUNT_ConsumeSpot(FieldEncount *encount);
void EFFECT_ENCOUNT_SetEffectPaused(FieldEncount *encount, int paused);
void EFFECT_ENCOUNT_SetEffectFlag(FieldEncount *encount, int flag);
u16 EFFECT_ENCOUNT_GetItemId(FieldEncount *encount);
void EFFECT_ENCOUNT_MarkSpotForRestore(FieldEncount *encount);
void EFFECT_ENCOUNT_RestoreSpot(FieldEncount *encount, EffectEncount *effectEncount);
int EFFECT_ENCOUNT_CountStep(EncountGimmickWork *gimmick, EffectEncount *effectEncount);
void EFFECT_ENCOUNT_ResetStepCount(EncountGimmickWork *gimmick);
void EFFECT_ENCOUNT_MakeSearchArea(FieldEncount *encount, EffectEncount *effectEncount, EffectEncountArea *area);
void EFFECT_ENCOUNT_CollectCandidates(FieldEncount *encount, EffectEncount *effectEncount);
void EFFECT_ENCOUNT_PickSpot(FieldEncount *encount, EffectEncount *effectEncount);
int EFFECT_ENCOUNT_IsTileOccupied(FieldEncount *encount, s16 gridX, s16 gridHeight, s16 gridZ, int ignorePlayer);
int EFFECT_ENCOUNT_ClearSpotIfOccupied(FieldEncount *encount);
void EFFECT_ENCOUNT_ClearSpot(FieldEncount *encount, EffectEncount *effectEncount);
void EFFECT_ENCOUNT_CreateEffectObj(FieldEncount *encount, EffectEncount *effectEncount, EffectEncountSpot *spot);
void EFFECT_ENCOUNT_DeleteEffectObj(EffectEncount *effectEncount);
unsigned short EFFECT_ENCOUNT_PickItemKind4(void);
u16 EFFECT_ENCOUNT_PickItemKind7(void);
struct GameEvent *EFFECT_ENCOUNT_StartItemEvent(FieldEncount *encount, u16 itemId);
/* END mkheaders: generated region */

#endif
