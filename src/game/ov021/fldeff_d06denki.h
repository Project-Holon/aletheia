#ifndef GAME_OV021_FLDEFF_D06DENKI_H
#define GAME_OV021_FLDEFF_D06DENKI_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldeff_d06denki.c, prototypes copied from their definitions. */

struct D06DenkiRes;
struct D06DenkiSparkWork;
struct D06DenkiFollowWork;
struct D06DenkiPulseWork;
typedef struct D06DenkiRes D06DenkiRes;
typedef struct D06DenkiSparkWork D06DenkiSparkWork;
typedef struct D06DenkiFollowWork D06DenkiFollowWork;
typedef struct D06DenkiPulseWork D06DenkiPulseWork;

#include "../ov021/field_effect_types.h"
#include "../types.h"
#include "../ov010/fldmmdl_types.h"
#include "../sdk_fx.h"

D06DenkiRes *FLDEFF_D06DENKI_Create(FieldEffectSys *fieldEffect, u32 heapId);
void FLDEFF_D06DENKI_Delete(FieldEffectSys *fieldEffect, D06DenkiRes *res);
void FLDEFF_D06DENKI_LoadResources(D06DenkiRes *res);
void FLDEFF_D06DENKI_FreeResources(D06DenkiRes *res);
void FLDEFF_D06DENKI_StartSpark(const Mmdl *mmdl, FieldEffectSys *fieldEffect);
void FLDEFF_D06DENKI_SparkInit(FieldEffectObj *effect, D06DenkiSparkWork *work);
void FLDEFF_D06DENKI_SparkExit(void);
void FLDEFF_D06DENKI_SparkUpdate(FieldEffectObj *effect, D06DenkiSparkWork *work);
void FLDEFF_D06DENKI_SparkDraw(FieldEffectObj *effect, D06DenkiSparkWork *work);
FieldEffectObj *FLDEFF_D06DENKI_StartFollow(FieldEffectSys *fieldEffect, const VecFx32 *pos, Mmdl *mmdl);
void FLDEFF_D06DENKI_FollowFreezeLoop(FieldEffectObj *effect);
void FLDEFF_D06DENKI_FollowStartEnding(FieldEffectObj *effect);
int FLDEFF_D06DENKI_FollowIsEnded(FieldEffectObj *effect);
void FLDEFF_D06DENKI_FollowInit(FieldEffectObj *effect, D06DenkiFollowWork *work);
void FLDEFF_D06DENKI_FollowExit(void *task, D06DenkiFollowWork *work);
void FLDEFF_D06DENKI_FollowUpdate(FieldEffectObj *effect, D06DenkiFollowWork *work);
void FLDEFF_D06DENKI_FollowDraw(FieldEffectObj *effect, D06DenkiFollowWork *work);
FieldEffectObj *FLDEFF_D06DENKI_StartPulse(FieldEffectSys *fieldEffect, const VecFx32 *pos);
void FLDEFF_D06DENKI_PulseTrigger(FieldEffectObj *effect);
void FLDEFF_D06DENKI_PulseInit(FieldEffectObj *effect, D06DenkiPulseWork *work);
void FLDEFF_D06DENKI_PulseExit(void *task, D06DenkiPulseWork *work);
void FLDEFF_D06DENKI_PulseUpdate(void *task, D06DenkiPulseWork *work);
void FLDEFF_D06DENKI_PulseDraw(FieldEffectObj *effect, D06DenkiPulseWork *work);
/* END mkheaders: generated region */

#endif
