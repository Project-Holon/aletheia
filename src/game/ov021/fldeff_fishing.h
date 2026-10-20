#ifndef GAME_OV021_FLDEFF_FISHING_H
#define GAME_OV021_FLDEFF_FISHING_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldeff_fishing.c, prototypes copied from their definitions. */

struct FishingRodRes;
struct FishingRodWork;
typedef struct FishingRodRes FishingRodRes;
typedef struct FishingRodWork FishingRodWork;

#include "../ov021/field_effect_types.h"
#include "../types.h"
#include "../sdk_fx.h"

FishingRodRes *FLDEFF_FISHING_Create(FieldEffectSys *fieldEffect, u32 heapId);
void FLDEFF_FISHING_Delete(FieldEffectSys *fieldEffect, FishingRodRes *res);
void FLDEFF_FISHING_LoadResources(FishingRodRes *res);
void FLDEFF_FISHING_FreeResources(FishingRodRes *res);
FieldEffectObj *FLDEFF_FISHING_Start(FieldEffectSys *fieldEffect, const VecFx32 *pos, u32 rodKind, u32 side);
void FLDEFF_FISHING_SetAnimeSpeed(FieldEffectObj *effect, u16 animeSpeed);
void FLDEFF_FISHING_Init(FieldEffectObj *effect, FishingRodWork *work);
void FLDEFF_FISHING_Exit(void);
void FLDEFF_FISHING_Update(FieldEffectObj *effect, FishingRodWork *work);
void FLDEFF_FISHING_Draw(FieldEffectObj *effect, FishingRodWork *work);
/* END mkheaders: generated region */

#endif
