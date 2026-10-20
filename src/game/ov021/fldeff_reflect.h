#ifndef GAME_OV021_FLDEFF_REFLECT_H
#define GAME_OV021_FLDEFF_REFLECT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldeff_reflect.c, prototypes copied from their definitions. */

struct ReflectEffectWork;
struct ReflectTaskWork;
typedef struct ReflectEffectWork ReflectEffectWork;
typedef struct ReflectTaskWork ReflectTaskWork;

#include "../types.h"

ReflectEffectWork *FLDEFF_REFLECT_Init(int fieldEffectCtrl, int heapId);
void FLDEFF_REFLECT_Delete(u32 fieldEffectCtrl, u8 *effWork);
void FLDEFF_REFLECT_InitResource(void);
void FLDEFF_REFLECT_DeleteResource(void *effWork);
void FLDEFF_REFLECT_SetMMdl(u32 mmdlSys, u32 mmdl, u32 fieldEffectCtrl, u32 type);
void FLDEFF_REFLECT_InitTask(u32 task, ReflectTaskWork *work);
void FLDEFF_REFLECT_DeleteTask(int task, ReflectTaskWork *work);
void FLDEFF_REFLECT_UpdateTask(u32 task, ReflectTaskWork *work);
void FLDEFF_REFLECT_DrawTask(int task, ReflectTaskWork *work);
void FLDEFF_REFLECT_UpdateActor(u16 actId, ReflectTaskWork *work);
int FLDEFF_REFLECT_GetZoneRotateOffset(u32 zoneId);
int FLDEFF_REFLECT_GetZoneHeightOffset(int zoneId, int mdlSize);
/* END mkheaders: generated region */

#endif
