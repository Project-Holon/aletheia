#ifndef GAME_OV021_FLDEFF_REFLECT_H
#define GAME_OV021_FLDEFF_REFLECT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldeff_reflect.c, prototypes copied from their definitions. */

struct ReflectEffectWork;
struct FieldEffectSys;
struct MmdlSys;
struct Mmdl;
struct ReflectTaskWork;
typedef struct ReflectEffectWork ReflectEffectWork;
typedef struct ReflectTaskWork ReflectTaskWork;

#include "../types.h"
#include "../ov021/field_effect_types.h"

ReflectEffectWork *FLDEFF_REFLECT_Init(struct FieldEffectSys *fieldEffectCtrl, int heapId);
void FLDEFF_REFLECT_Delete(struct FieldEffectSys *fieldEffectCtrl, u8 *effWork);
void FLDEFF_REFLECT_InitResource(void);
void FLDEFF_REFLECT_DeleteResource(void *effWork);
void FLDEFF_REFLECT_SetMMdl(struct MmdlSys *mmdlSys, struct Mmdl *mmdl, struct FieldEffectSys *fieldEffectCtrl, u32 type);
void FLDEFF_REFLECT_InitTask(FieldEffectObj *task, ReflectTaskWork *work);
void FLDEFF_REFLECT_DeleteTask(FieldEffectObj *task, ReflectTaskWork *work);
void FLDEFF_REFLECT_UpdateTask(FieldEffectObj *task, ReflectTaskWork *work);
void FLDEFF_REFLECT_DrawTask(FieldEffectObj *task, ReflectTaskWork *work);
void FLDEFF_REFLECT_UpdateActor(u16 actId, ReflectTaskWork *work);
int FLDEFF_REFLECT_GetZoneRotateOffset(u32 zoneId);
int FLDEFF_REFLECT_GetZoneHeightOffset(int zoneId, int mdlSize);
/* END mkheaders: generated region */

#endif
