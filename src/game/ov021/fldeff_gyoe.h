#ifndef GAME_OV021_FLDEFF_GYOE_H
#define GAME_OV021_FLDEFF_GYOE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldeff_gyoe.c, prototypes copied from their definitions. */

struct FldeffGyoe;
struct FieldEffectObj;
struct FldeffGyoeTaskWork;
typedef struct FldeffGyoe FldeffGyoe;
typedef struct FldeffGyoeTaskWork FldeffGyoeTaskWork;

#include "../types.h"
#include "../ov010/fldmmdl_types.h"
#include "../sdk_fx.h"
#include "../sdk_fx.h"

FldeffGyoe *FLDEFF_GYOE_Init(void *fieldEffectCtrl, u16 heapId);
void FLDEFF_GYOE_Delete(void *fieldEffectCtrl, FldeffGyoe *gyoe);
void FLDEFF_GYOE_InitResource(FldeffGyoe *gyoe);
void FLDEFF_GYOE_DeleteResource(FldeffGyoe *gyoe);
void *FLDEFF_GYOE_SetMMdl(void *fieldEffectCtrl, Mmdl *mmdl, u32 type, u32 sePlay);
struct FieldEffectObj *FLDEFF_GYOE_StartHeld(void *fieldEffectCtrl, Mmdl *mmdl, int type, int sePlay);
int FLDEFF_GYOE_IsFinished(void *task);
void FLDEFF_GYOE_InitHeldTask(void *task, FldeffGyoeTaskWork *work);
void FLDEFF_GYOE_DeleteTask(void);
void FLDEFF_GYOE_UpdateHeldTask(void *task, FldeffGyoeTaskWork *work);
void FLDEFF_GYOE_UpdateTask(void *task, FldeffGyoeTaskWork *work);
void FLDEFF_GYOE_DrawTask(void *task, FldeffGyoeTaskWork *work);
void FLDEFF_GYOE_PlaySe(int type);
void FLDEFF_GYOE_RotateByCamera(void *g3dCamera, VecFx32 *src, VecFx32 *dst);
void FLDEFF_GYOE_StepAnimation(FldeffGyoeTaskWork *work, VecFx32 *out);
/* END mkheaders: generated region */

#endif
