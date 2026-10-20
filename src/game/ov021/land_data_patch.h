#ifndef GAME_OV021_LAND_DATA_PATCH_H
#define GAME_OV021_LAND_DATA_PATCH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of land_data_patch.c, prototypes copied from their definitions. */

#include "../types.h"

u32 *LAND_DATA_PATCH_Create(u32 patchId, u16 heapId);
void LAND_DATA_PATCH_Delete(void **patch);
void LAND_DATA_PATCH_OverwriteAttr(u32 patch, u8 *mapAttr, u32 srcX, u32 srcY, u32 dstX, u32 dstY, u32 width, u32 height);
u32 LAND_DATA_PATCH_AddBuildModels(u32 patch, u32 bmodelMan, u32 mapIndex, u32 firstIndex, int offsetX, int offsetZ);
int LAND_DATA_PATCH_GetAttrBlock(u32 patch);
int LAND_DATA_PATCH_GetBuildModelBlock(u32 patch);
/* END mkheaders: generated region */

#endif
