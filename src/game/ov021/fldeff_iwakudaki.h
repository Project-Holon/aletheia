#ifndef GAME_OV021_FLDEFF_IWAKUDAKI_H
#define GAME_OV021_FLDEFF_IWAKUDAKI_H
struct TcbTask;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldeff_iwakudaki.c, prototypes copied from their definitions. */

struct IwakudakiRes;
struct IwakudakiWork;
typedef struct IwakudakiRes IwakudakiRes;
typedef struct IwakudakiWork IwakudakiWork;

#include "../ov021/field_effect_types.h"
#include "../types.h"
#include "../ov010/fldmmdl_types.h"

IwakudakiRes *FLDEFF_IWAKUDAKI_Create(FieldEffectSys *fieldEffect, u32 heapId);
void FLDEFF_IWAKUDAKI_Delete(FieldEffectSys *fieldEffect, IwakudakiRes *res);
void FLDEFF_IWAKUDAKI_LoadResources(IwakudakiRes *res);
void FLDEFF_IWAKUDAKI_FreeResources(IwakudakiRes *res);
void FLDEFF_IWAKUDAKI_UploadTexturesTask(struct TcbTask * taskArg, void *work);
void FLDEFF_IWAKUDAKI_Start(const Mmdl *mmdl, FieldEffectSys *fieldEffect);
void FLDEFF_IWAKUDAKI_Init(FieldEffectObj *effect, IwakudakiWork *work);
void FLDEFF_IWAKUDAKI_Exit(void *task, IwakudakiWork *work);
void FLDEFF_IWAKUDAKI_Update(FieldEffectObj *effect, IwakudakiWork *work);
void FLDEFF_IWAKUDAKI_Draw(FieldEffectObj *effect, IwakudakiWork *work);
/* END mkheaders: generated region */

#endif
