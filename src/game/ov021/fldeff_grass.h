#ifndef GAME_OV021_FLDEFF_GRASS_H
#define GAME_OV021_FLDEFF_GRASS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldeff_grass.c, prototypes copied from their definitions. */

struct FldeffGrass;
struct GrassWork;
typedef struct FldeffGrass FldeffGrass;
typedef struct GrassWork GrassWork;

#include "../ov021/field_effect_types.h"
#include "../ov010/fldmmdl_types.h"
#include "../types.h"

FldeffGrass *FLDEFF_GRASS_Create(FieldEffectSys *sys, int heapId);
void FLDEFF_GRASS_Delete(FieldEffectSys *sys, FldeffGrass *grass);
void FLDEFF_GRASS_CreateSlots(FldeffGrass *grass);
void FLDEFF_GRASS_DeleteSlots(FldeffGrass *grass);
void FLDEFF_GRASS_Start(FieldEffectSys *sys, Mmdl *mmdl, u32 mode, int index);
void FLDEFF_GRASS_Init(FieldEffectObj *effect, GrassWork *work);
void FLDEFF_GRASS_Exit(FieldEffectObj *effect, GrassWork *work);
void FLDEFF_GRASS_Update(FieldEffectObj *effect, GrassWork *work);
void FLDEFF_GRASS_Draw(void);
int FLDEFF_GRASS_IsModelOnTile(GrassWork *work);
/* END mkheaders: generated region */

#endif
