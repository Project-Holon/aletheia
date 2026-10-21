#ifndef GAME_OV021_FLDEFF_FOOTMARK_H
#define GAME_OV021_FLDEFF_FOOTMARK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldeff_footmark.c, prototypes copied from their definitions. */

struct FootmarkEffectWork;
struct Mmdl;
struct FieldEffectSys;
struct FootmarkTaskWork;
typedef struct FootmarkEffectWork FootmarkEffectWork;
typedef struct FootmarkTaskWork FootmarkTaskWork;

#include "../types.h"
#include "../ov021/field_effect_types.h"

FootmarkEffectWork *FLDEFF_FOOTMARK_Init(void *fieldEffectCtrl, u32 heapId);
void FLDEFF_FOOTMARK_Delete(u32 unused, FootmarkEffectWork *effWork);
void FLDEFF_FOOTMARK_InitResource(FootmarkEffectWork *effWork);
void FLDEFF_FOOTMARK_DeleteResource(FootmarkEffectWork *effWork);
int FLDEFF_FOOTMARK_GetSlotIndex(FootmarkEffectWork *effWork, int type, int dir, int oldDir);
void FLDEFF_FOOTMARK_SetMMdl(struct Mmdl *mmdl, struct FieldEffectSys *fieldEffectCtrl, int type);
void FLDEFF_FOOTMARK_InitTask(FieldEffectObj *task, FootmarkTaskWork *work);
void FLDEFF_FOOTMARK_DeleteTask(FieldEffectObj *task, FootmarkTaskWork *work);
void FLDEFF_FOOTMARK_UpdateTask(FieldEffectObj *task, FootmarkTaskWork *work);
void FLDEFF_FOOTMARK_DrawTask(void);
/* END mkheaders: generated region */

#endif
