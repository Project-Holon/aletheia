#ifndef GAME_OV021_FLDEFF_BTRAIN_H
#define GAME_OV021_FLDEFF_BTRAIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldeff_btrain.c, prototypes copied from their definitions. */

struct BtrainRes;
struct BtrainWork;
typedef struct BtrainRes BtrainRes;
typedef struct BtrainWork BtrainWork;

#include "../ov021/field_effect_types.h"
#include "../types.h"
#include "../sdk_fx.h"

BtrainRes *FLDEFF_BTRAIN_Create(FieldEffectSys *fieldEffect, u32 heapId);
void FLDEFF_BTRAIN_Delete(FieldEffectSys *fieldEffect, BtrainRes *res);
void FLDEFF_BTRAIN_LoadResources(BtrainRes *res, int modelIndex);
void FLDEFF_BTRAIN_FreeResources(BtrainRes *res);
FieldEffectObj *FLDEFF_BTRAIN_Start(FieldEffectSys *fieldEffect, u32 modelIndex, const VecFx32 *pos);
void FLDEFF_BTRAIN_SetAnime(FieldEffectObj *effect, u32 animeIndex);
void FLDEFF_BTRAIN_SetHidden(FieldEffectObj *effect, u32 hidden);
void FLDEFF_BTRAIN_Init(FieldEffectObj *effect, BtrainWork *work);
void FLDEFF_BTRAIN_Exit(FieldEffectObj *effect, BtrainWork *work);
void FLDEFF_BTRAIN_Update(FieldEffectObj *effect, BtrainWork *work);
void FLDEFF_BTRAIN_Draw(FieldEffectObj *effect, BtrainWork *work);
/* END mkheaders: generated region */

#endif
