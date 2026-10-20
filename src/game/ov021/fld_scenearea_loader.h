#ifndef GAME_OV021_FLD_SCENEAREA_LOADER_H
#define GAME_OV021_FLD_SCENEAREA_LOADER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fld_scenearea_loader.c, prototypes copied from their definitions. */

#include "../ov021/fld_scenearea_types.h"
#include "../types.h"
#include "../sdk_fx.h"

FldSceneAreaLoader *FLD_SCENEAREA_LOADER_Create(int heapId);
void FLD_SCENEAREA_LOADER_Delete(FldSceneAreaLoader *loader);
void FLD_SCENEAREA_LOADER_Load(FldSceneAreaLoader *loader, int arcIndex, int fileId, u16 heapId);
void FLD_SCENEAREA_LOADER_Unload(FldSceneAreaLoader *loader);
FldSceneAreaRec *FLD_SCENEAREA_LOADER_GetRecs(FldSceneAreaLoader *loader);
u32 FLD_SCENEAREA_LOADER_GetRecCount(FldSceneAreaLoader *loader);
const FldSceneAreaCallbacks *FLD_SCENEAREA_LOADER_GetCallbacks(FldSceneAreaLoader *loader);
int FLD_SCENEAREA_LOADER_CheckSector(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);
void FLD_SCENEAREA_LOADER_ApplySectorCamera(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, const VecFx32 *pos);
void FLD_SCENEAREA_LOADER_ApplyFixedCamera(FldSceneArea *sceneArea, const FldSceneAreaRec *rec);
int FLD_SCENEAREA_LOADER_CheckStrip(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);
void FLD_SCENEAREA_LOADER_ApplyStripCamera(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);
void FLD_SCENEAREA_LOADER_ApplyStripCameraStop(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);
void FLD_SCENEAREA_LOADER_ApplyStripCameraResume(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);
void FLD_SCENEAREA_LOADER_GetStripProgress(const FldSceneAreaRec *rec, VecFx32 *pos, int *length, int *progress);
void FLD_SCENEAREA_LOADER_ApplyStripFull(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);
void FLD_SCENEAREA_LOADER_ApplyStripFullStop(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);
void FLD_SCENEAREA_LOADER_ApplyStripFullResume(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);
void FLD_SCENEAREA_LOADER_ApplyStripTarget(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);
void FLD_SCENEAREA_LOADER_ApplyStripFov(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);
/* END mkheaders: generated region */

#endif
