#ifndef GAME_OV021_FLDEFF_NAMIPOKE_H
#define GAME_OV021_FLDEFF_NAMIPOKE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldeff_namipoke.c, prototypes copied from their definitions. */

struct NamipokeRes;
struct NamipokeWork;
struct NamipokeSplashRes;
struct NamipokeSplashWork;
typedef struct NamipokeRes NamipokeRes;
typedef struct NamipokeWork NamipokeWork;
typedef struct NamipokeSplashRes NamipokeSplashRes;
typedef struct NamipokeSplashWork NamipokeSplashWork;

#include "../ov021/field_effect_types.h"
#include "../types.h"
#include "../sdk_fx.h"
#include "../ov010/fldmmdl_types.h"

NamipokeRes *FLDEFF_NAMIPOKE_Create(FieldEffectSys *fieldEffect, int heapId);
void FLDEFF_NAMIPOKE_Delete(FieldEffectSys *fieldEffect, NamipokeRes *res);
void FLDEFF_NAMIPOKE_LoadResources(NamipokeRes *res);
void FLDEFF_NAMIPOKE_FreeResources(NamipokeRes *res);
FieldEffectObj *FLDEFF_NAMIPOKE_Start(FieldEffectSys *fieldEffect, u32 facing, const VecFx32 *pos, Mmdl *mmdl, u32 followMode);
void FLDEFF_NAMIPOKE_SetFollowMode(FieldEffectObj *effect, u8 followMode);
void FLDEFF_NAMIPOKE_SetWakeEnabled(FieldEffectObj *effect, int wakeEnabled);
int FLDEFF_NAMIPOKE_GetWakeScale(int distance);
int FLDEFF_NAMIPOKE_GetWakeLength(const VecFx32 *from, const VecFx32 *to, u32 dir);
void FLDEFF_NAMIPOKE_Init(FieldEffectObj *effect, NamipokeWork *work);
void FLDEFF_NAMIPOKE_Exit(void);
void FLDEFF_NAMIPOKE_PlaceObjects(FieldEffectObj *effect, NamipokeWork *work);
void FLDEFF_NAMIPOKE_UpdateGrid(FieldEffectObj *effect, NamipokeWork *work);
void FLDEFF_NAMIPOKE_DrawGrid(FieldEffectObj *effect, NamipokeWork *work);
void FLDEFF_NAMIPOKE_UpdateRail(FieldEffectObj *effect, NamipokeWork *work);
void FLDEFF_NAMIPOKE_DrawRail(FieldEffectObj *effect, NamipokeWork *work);
NamipokeSplashRes *FLDEFF_NAMIPOKE_SPLASH_Create(FieldEffectSys *fieldEffect, int heapId);
void FLDEFF_NAMIPOKE_SPLASH_Delete(FieldEffectSys *fieldEffect, NamipokeSplashRes *res);
void FLDEFF_NAMIPOKE_SPLASH_LoadResources(NamipokeSplashRes *res);
void FLDEFF_NAMIPOKE_SPLASH_FreeResources(NamipokeSplashRes *res);
FieldEffectObj *FLDEFF_NAMIPOKE_SPLASH_StartOnEffect(FieldEffectSys *fieldEffect, int type, FieldEffectObj *parent);
void FLDEFF_NAMIPOKE_SPLASH_StartAtPos(FieldEffectSys *fieldEffect, int type, const VecFx32 *pos);
int FLDEFF_NAMIPOKE_SPLASH_IsFinished(FieldEffectObj *effect);
void FLDEFF_NAMIPOKE_SPLASH_Init(FieldEffectObj *effect, NamipokeSplashWork *work);
void FLDEFF_NAMIPOKE_SPLASH_Exit(FieldEffectObj *effect, NamipokeSplashWork *work, u32 unused0, u32 unused1);
void FLDEFF_NAMIPOKE_SPLASH_Update(FieldEffectObj *effect, NamipokeSplashWork *work);
void FLDEFF_NAMIPOKE_SPLASH_Draw(FieldEffectObj *effect, NamipokeSplashWork *work);
/* END mkheaders: generated region */

#endif
