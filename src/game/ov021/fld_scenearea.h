#ifndef GAME_OV021_FLD_SCENEAREA_H
#define GAME_OV021_FLD_SCENEAREA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fld_scenearea.c, prototypes copied from their definitions. */

#include "../ov021/fld_scenearea_types.h"
#include "../types.h"
#include "../sdk_fx.h"

FldSceneArea *FLD_SCENEAREA_Create(int heapId, void *camera, void *fieldMap);
void FLD_SCENEAREA_Delete(FldSceneArea *sceneArea);
void FLD_SCENEAREA_SetData(FldSceneArea *sceneArea, FldSceneAreaRec *recs, u32 count, const FldSceneAreaCallbacks *callbacks);
void FLD_SCENEAREA_ClearData(FldSceneArea *sceneArea);
int FLD_SCENEAREA_Update(FldSceneArea *sceneArea, VecFx32 *pos);
void FLD_SCENEAREA_SetEnabled(FldSceneArea *sceneArea, u32 enabled);
void *FLD_SCENEAREA_GetCamera(FldSceneArea *sceneArea);
void *FLD_SCENEAREA_GetFieldMap(FldSceneArea *sceneArea);
int FLD_SCENEAREA_HasCheck(const FldSceneAreaCallbacks *callbacks, u32 checkId);
int FLD_SCENEAREA_HasAction(const FldSceneAreaCallbacks *callbacks, u32 actionId);
int FLD_SCENEAREA_RunCheck(const FldSceneAreaCallbacks *callbacks, int checkId, FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);
void FLD_SCENEAREA_RunAction(const FldSceneAreaCallbacks *callbacks, int actionId, FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);
/* END mkheaders: generated region */

#endif
