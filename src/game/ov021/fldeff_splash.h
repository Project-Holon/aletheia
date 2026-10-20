#ifndef GAME_OV021_FLDEFF_SPLASH_H
#define GAME_OV021_FLDEFF_SPLASH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldeff_splash.c, prototypes copied from their definitions. */

struct SplashBoardRes;
struct SplashBoardWork;
struct SplashModelRes;
struct SplashModelWork;
typedef struct SplashBoardRes SplashBoardRes;
typedef struct SplashBoardWork SplashBoardWork;
typedef struct SplashModelRes SplashModelRes;
typedef struct SplashModelWork SplashModelWork;

#include "../ov021/field_effect_types.h"
#include "../types.h"
#include "../ov010/fldmmdl_types.h"

SplashBoardRes *FLDEFF_SPLASH_CreateBoardRes(FieldEffectSys *sys, u32 heapId);
void FLDEFF_SPLASH_DeleteBoardRes(u32 unused, SplashBoardRes *res);
void FLDEFF_SPLASH_LoadBoardImage(SplashBoardRes *res);
void FLDEFF_SPLASH_UnloadBoardImage(SplashBoardRes *res);
void FLDEFF_SPLASH_AddBoard(FieldEffectSys *sys, Mmdl *mmdl);
void FLDEFF_SPLASH_InitBoardObj(FieldEffectObj *obj, SplashBoardWork *work);
void FLDEFF_SPLASH_ExitBoardObj(FieldEffectObj *obj, SplashBoardWork *work);
void FLDEFF_SPLASH_UpdateBoardObj(FieldEffectObj *obj, SplashBoardWork *work);
void FLDEFF_SPLASH_DrawBoardObj(void);
SplashModelRes *FLDEFF_SPLASH_CreateModelRes(FieldEffectSys *sys, u32 heapId);
void FLDEFF_SPLASH_DeleteModelRes(u32 unused, SplashModelRes *res);
void FLDEFF_SPLASH_LoadModel(SplashModelRes *res);
void FLDEFF_SPLASH_UnloadModel(SplashModelRes *res);
void FLDEFF_SPLASH_AddModel(FieldEffectSys *sys, Mmdl *mmdl);
void FLDEFF_SPLASH_InitModelObj(FieldEffectObj *obj, SplashModelWork *work);
void FLDEFF_SPLASH_ExitModelObj(void);
void FLDEFF_SPLASH_UpdateModelObj(FieldEffectObj *obj, SplashModelWork *work);
void FLDEFF_SPLASH_DrawModelObj(FieldEffectObj *obj, SplashModelWork *work);
/* END mkheaders: generated region */

#endif
