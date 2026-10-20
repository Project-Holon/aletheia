#ifndef GAME_OV021_FLDEFF_SHADOW_H
#define GAME_OV021_FLDEFF_SHADOW_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldeff_shadow.c, prototypes copied from their definitions. */

struct FldeffShadow;
struct FldeffShadowWork;
typedef struct FldeffShadow FldeffShadow;
typedef struct FldeffShadowWork FldeffShadowWork;

#include "../ov021/field_effect_types.h"
#include "../ov010/fldmmdl_types.h"

FldeffShadow *FLDEFF_SHADOW_Create(FieldEffectSys *sys, int heapId);
void FLDEFF_SHADOW_Delete(FieldEffectSys *sys, FldeffShadow *shadow);
void FLDEFF_SHADOW_CreateSlot(FldeffShadow *shadow);
void FLDEFF_SHADOW_DeleteSlot(FldeffShadow *shadow);
void FLDEFF_SHADOW_Start(Mmdl *mmdl, FieldEffectSys *sys);
void FLDEFF_SHADOW_Init(FieldEffectObj *obj, FldeffShadowWork *work);
void FLDEFF_SHADOW_Exit(FieldEffectObj *obj, FldeffShadowWork *work);
void FLDEFF_SHADOW_Update(FieldEffectObj *obj, FldeffShadowWork *work);
void FLDEFF_SHADOW_Draw(FieldEffectObj *obj, FldeffShadowWork *work);
/* END mkheaders: generated region */

#endif
