#ifndef GAME_ARM9_G3D_UTIL_H
#define GAME_ARM9_G3D_UTIL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of g3d_util.c, prototypes copied from their definitions. */

struct ArcHandle;

#include "../arm9/g3d_util_types.h"
#include "../types.h"
#include "../arm9/g3d_system_types.h"

G3dUtil *G3D_UTIL_Create(u16 resCount, u16 objCount, u16 heapID);
void G3D_UTIL_Delete(G3dUtil *util);
u16 G3D_UTIL_AddUnit(G3dUtil *util, const G3dUtilSetup *setup);
u16 G3D_UTIL_AddUnitLoaded(G3dUtil *util, const G3dUtilSetup *setup);
u16 G3D_UTIL_AddUnitFromArchive(G3dUtil *util, const G3dUtilSetup *setup, struct ArcHandle *archive);
void G3D_UTIL_RemoveUnit(G3dUtil *util, u32 unitIdx);
void G3D_UTIL_LoadUnitResources(G3dUtil *util, u16 unitIdx, const G3dUtilSetup *setup, u16 heapID);
void G3D_UTIL_LoadUnitResourcesFromArchive(G3dUtil *util, u16 unitIdx, const G3dUtilSetup *setup, u32 heapID, struct ArcHandle *arc);
void G3D_UTIL_FreeUnitResources(G3dUtil *util, u32 unitIdx);
void G3D_UTIL_BuildUnitObjects(G3dUtil *util, u16 unitIdx, const G3dUtilSetup *setup, u16 heapID);
void G3D_UTIL_BuildUnitObjectsLoaded(G3dUtil *util, u16 unitIdx, const G3dUtilSetup *setup, u16 heapID);
void G3D_UTIL_FreeUnitObjects(G3dUtil *util, u32 unitIdx);
u32 G3D_UTIL_GetUnitObjIdx(G3dUtil *util, int unitIdx);
u16 G3D_UTIL_GetUnitObjCount(G3dUtil *util, int unitIdx);
void *G3D_UTIL_GetResource(G3dUtil *util, int resIdx);
G3dObject *G3D_UTIL_GetObject(G3dUtil *util, int objIdx);
/* END mkheaders: generated region */

#endif
