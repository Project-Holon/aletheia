#ifndef GAME_OV021_FLDEFF_KEMURI_H
#define GAME_OV021_FLDEFF_KEMURI_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldeff_kemuri.c, prototypes copied from their definitions. */

struct FldeffKemuri;
struct FldeffKemuriWork;
typedef struct FldeffKemuri FldeffKemuri;
typedef struct FldeffKemuriWork FldeffKemuriWork;

#include "../ov021/field_effect_types.h"
#include "../ov010/fldmmdl_types.h"

FldeffKemuri *FLDEFF_KEMURI_Create(FieldEffectSys *sys, int heapId);
void FLDEFF_KEMURI_Delete(FieldEffectSys *sys, FldeffKemuri *kemuri);
void FLDEFF_KEMURI_LoadResource(FldeffKemuri *kemuri);
void FLDEFF_KEMURI_FreeResource(FldeffKemuri *kemuri);
void FLDEFF_KEMURI_Start(Mmdl *mmdl, FieldEffectSys *sys);
void FLDEFF_KEMURI_StartFacing(Mmdl *mmdl, FieldEffectSys *sys);
void FLDEFF_KEMURI_Init(FieldEffectObj *obj, FldeffKemuriWork *work);
void FLDEFF_KEMURI_Exit(FieldEffectObj *obj, FldeffKemuriWork *work);
void FLDEFF_KEMURI_Update(FieldEffectObj *obj, FldeffKemuriWork *work);
void FLDEFF_KEMURI_Draw(void);
/* END mkheaders: generated region */

#endif
