#ifndef GAME_OV021_FLDEFF_HIDE_H
#define GAME_OV021_FLDEFF_HIDE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldeff_hide.c, prototypes copied from their definitions. */

struct HideRes;
struct HideWork;
typedef struct HideRes HideRes;
typedef struct HideWork HideWork;

#include "../ov021/field_effect_types.h"
#include "../types.h"
#include "../ov010/fldmmdl_types.h"

HideRes *FLDEFF_HIDE_CreateResources(FieldEffectSys *fieldEffect, u32 heapId);
void FLDEFF_HIDE_DeleteResources(FieldEffectSys *fieldEffect, HideRes *res);
void FLDEFF_HIDE_LoadResources(HideRes *res);
void FLDEFF_HIDE_FreeResources(HideRes *res);
FieldEffectObj *FLDEFF_HIDE_Start(FieldEffectSys *fieldEffect, Mmdl *mmdl, u32 kind);
void FLDEFF_HIDE_RequestEnd(FieldEffectObj *effect);
int FLDEFF_HIDE_IsFinished(FieldEffectObj *effect);
void FLDEFF_HIDE_Init(FieldEffectObj *effect, HideWork *work);
void FLDEFF_HIDE_Exit(FieldEffectObj *effect, HideWork *work);
void FLDEFF_HIDE_Update(FieldEffectObj *effect, HideWork *work);
void FLDEFF_HIDE_Draw(FieldEffectObj *effect, HideWork *work);
/* END mkheaders: generated region */

#endif
