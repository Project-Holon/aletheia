#ifndef GAME_OV021_LAND_DATA_PATCH_H
#define GAME_OV021_LAND_DATA_PATCH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of land_data_patch.c, prototypes copied from their definitions. */

struct LandDataPatch;
struct BuildModelMan;
struct FieldG3dMap;
typedef struct LandDataPatch LandDataPatch;

#include "../types.h"

LandDataPatch *LAND_DATA_PATCH_Create(u32 patchId, u16 heapId);
void LAND_DATA_PATCH_Delete(void **patch);
void LAND_DATA_PATCH_OverwriteAttr(LandDataPatch *patch, u8 *mapAttr, u32 srcX, u32 srcY, u32 dstX, u32 dstY, u32 width, u32 height);
u32 LAND_DATA_PATCH_AddBuildModels(LandDataPatch *patch, struct BuildModelMan *bmodelMan, struct FieldG3dMap *mapIndex, u32 firstIndex, int offsetX, int offsetZ);
u8 *LAND_DATA_PATCH_GetAttrBlock(LandDataPatch *patch);
u32 *LAND_DATA_PATCH_GetBuildModelBlock(LandDataPatch *patch);
/* END mkheaders: generated region */

#endif
