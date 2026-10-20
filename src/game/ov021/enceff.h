#ifndef GAME_OV021_ENCEFF_H
#define GAME_OV021_ENCEFF_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of enceff.c, prototypes copied from their definitions. */

struct EncEffWork;
struct FieldMap;
struct GameEvent;
typedef struct EncEffWork EncEffWork;

#include "../types.h"

EncEffWork *ENCEFF_Create(u32 heapId, struct FieldMap *fieldMap);
int ENCEFF_Delete(EncEffWork *eff);
void ENCEFF_Start(EncEffWork *eff, struct GameEvent *parentEvent, int kind);
struct GameEvent *ENCEFF_GetEffect(EncEffWork *eff);
void ENCEFF_RunUpdate(EncEffWork *eff);
void ENCEFF_AllocWork(EncEffWork *eff, u32 size, u32 heapId);
void ENCEFF_FreeWork(EncEffWork *eff);
void *ENCEFF_GetWork(EncEffWork *eff);
void ENCEFF_LoadOverlay(EncEffWork *eff, u32 overlayId);
void ENCEFF_LoadOverlays4B4D(EncEffWork *eff);
void ENCEFF_LoadOverlay4B(EncEffWork *eff);
void ENCEFF_UnloadOverlays(EncEffWork *eff);
void ENCEFF_SelectEffectAndBgm(int species, int effectId, int hasWildOpponent, struct FieldMap *fieldMap, u32 *outEffectKind, u16 *outBgmId);
void ENCEFF_SelectEffectAndBgmForTrainer(void *trainerData, struct FieldMap *fieldMap, int *outEffectKind, u16 *outBgmId);
/* END mkheaders: generated region */

#endif
