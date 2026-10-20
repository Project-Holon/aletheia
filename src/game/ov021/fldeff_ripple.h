#ifndef GAME_OV021_FLDEFF_RIPPLE_H
#define GAME_OV021_FLDEFF_RIPPLE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldeff_ripple.c, prototypes copied from their definitions. */

struct RippleWork;
struct RippleObjWork;
typedef struct RippleWork RippleWork;
typedef struct RippleObjWork RippleObjWork;

#include "../ov021/field_effect_types.h"
#include "../types.h"

RippleWork *FLDEFF_RIPPLE_Create(FieldEffectSys *fieldEffect, u32 heapId);
void FLDEFF_RIPPLE_Delete(u32 unused, RippleWork *work);
void FLDEFF_RIPPLE_AddActor(RippleWork *work);
void FLDEFF_RIPPLE_RemoveActor(RippleWork *work);
void FLDEFF_RIPPLE_Start(FieldEffectSys *fieldEffect, int gridX, int gridZ, fx32 height);
void FLDEFF_RIPPLE_InitObj(FieldEffectObj *obj, RippleObjWork *work);
void FLDEFF_RIPPLE_ExitObj(FieldEffectObj *obj, RippleObjWork *work);
void FLDEFF_RIPPLE_UpdateObj(FieldEffectObj *obj, RippleObjWork *work);
void FLDEFF_RIPPLE_DrawObj(void);
/* END mkheaders: generated region */

#endif
