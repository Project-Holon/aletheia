#ifndef GAME_OV021_FLDEFF_ENCOUNT_H
#define GAME_OV021_FLDEFF_ENCOUNT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldeff_encount.c, prototypes copied from their definitions. */

struct EncountModelSet;
struct EncountDrawSet;
struct EncountSys;
struct EncountWork;
typedef struct EncountModelSet EncountModelSet;
typedef struct EncountDrawSet EncountDrawSet;
typedef struct EncountSys EncountSys;
typedef struct EncountWork EncountWork;

#include "../ov021/field_effect_types.h"
#include "../types.h"

EncountModelSet *FLDEFF_ENCOUNT_CreateKind0(FieldEffectSys *fieldEffect, int heapId);
EncountModelSet *FLDEFF_ENCOUNT_CreateKind1(FieldEffectSys *fieldEffect, int heapId);
EncountModelSet *FLDEFF_ENCOUNT_CreateKind2(FieldEffectSys *fieldEffect, int heapId);
EncountModelSet *FLDEFF_ENCOUNT_CreateKind3(FieldEffectSys *fieldEffect, int heapId);
EncountModelSet *FLDEFF_ENCOUNT_CreateKind4(FieldEffectSys *fieldEffect, int heapId);
EncountModelSet *FLDEFF_ENCOUNT_CreateKind5(FieldEffectSys *fieldEffect, int heapId);
void FLDEFF_ENCOUNT_Delete(FieldEffectSys *fieldEffect, EncountModelSet *set);
EncountModelSet *FLDEFF_ENCOUNT_Create(FieldEffectSys *fieldEffect, int heapId, u32 kind);
void FLDEFF_ENCOUNT_LoadKind(EncountModelSet *set, u32 kind);
void FLDEFF_ENCOUNT_BuildDrawSet(EncountDrawSet *draw, EncountModelSet *set, int modelIndex);
void FLDEFF_ENCOUNT_DeleteDrawSet(EncountDrawSet *draw, EncountModelSet *set);
void FLDEFF_ENCOUNT_FreeResources(EncountModelSet *set);
FieldEffectObj *FLDEFF_ENCOUNT_Start(EncountSys *encount, FieldEffectSys *fieldEffect, int gridX, int gridZ, int y, int setIndex);
void FLDEFF_ENCOUNT_SetPaused(FieldEffectObj *effect, int paused);
void FLDEFF_ENCOUNT_SetDrawHidden(FieldEffectObj *effect, int hidden);
void FLDEFF_ENCOUNT_Init(FieldEffectObj *effect, EncountWork *work);
void FLDEFF_ENCOUNT_Exit(void);
void FLDEFF_ENCOUNT_Update(FieldEffectObj *effect, EncountWork *work);
void FLDEFF_ENCOUNT_PlaySound(EncountWork *work, EncountModelSet *set);
void FLDEFF_ENCOUNT_DrawSlotObject(FieldEffectObj *effect, EncountWork *work);
/* END mkheaders: generated region */

#endif
