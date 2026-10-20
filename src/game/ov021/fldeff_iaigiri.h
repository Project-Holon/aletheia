#ifndef GAME_OV021_FLDEFF_IAIGIRI_H
#define GAME_OV021_FLDEFF_IAIGIRI_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldeff_iaigiri.c, prototypes copied from their definitions. */

struct IaigiriRes;
struct IaigiriTaskWork;
typedef struct IaigiriRes IaigiriRes;
typedef struct IaigiriTaskWork IaigiriTaskWork;

#include "../ov021/field_effect_types.h"
#include "../types.h"
#include "../ov010/fldmmdl_types.h"

IaigiriRes *FLDEFF_IAIGIRI_Create(FieldEffectSys *fieldEffect, u32 heapId);
void FLDEFF_IAIGIRI_Delete(FieldEffectSys *fieldEffect, IaigiriRes *res);
void FLDEFF_IAIGIRI_LoadResources(IaigiriRes *res);
void FLDEFF_IAIGIRI_FreeResources(IaigiriRes *res);
void FLDEFF_IAIGIRI_Start(const Mmdl *mmdl, FieldEffectSys *fieldEffect);
void FLDEFF_IAIGIRI_Init(FieldEffectObj *effect, IaigiriTaskWork *work);
void FLDEFF_IAIGIRI_Exit(void *task, IaigiriTaskWork *work);
void FLDEFF_IAIGIRI_Update(FieldEffectObj *effect, IaigiriTaskWork *work);
void FLDEFF_IAIGIRI_Draw(FieldEffectObj *effect, IaigiriTaskWork *work);
/* END mkheaders: generated region */

#endif
