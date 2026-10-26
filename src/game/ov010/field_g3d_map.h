#ifndef GAME_OV010_FIELD_G3D_MAP_H
#define GAME_OV010_FIELD_G3D_MAP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_g3d_map.c, prototypes copied from their definitions. */

#include "../ov010/field_g3d_map_types.h"
#include "../ov010/field_g3d_map_types.h"
#include "../types.h"
#include "../sdk_fx.h"

FieldG3dMap *FIELD_G3D_MAP_Create(const FieldG3dMapConfig *cfg, u32 heapId);
void FIELD_G3D_MAP_Destroy(FieldG3dMap *map);
void FIELD_G3D_MAP_Update(FieldG3dMap *map);
int FIELD_G3D_MAP_WaitLoad(FieldG3dMap *map);
int FIELD_G3D_MAP_DrawWithModels(FieldG3dMap *map, void *arg);
void FIELD_G3D_MAP_OpenArchive(FieldG3dMap *map, int archiveId, int heapId);
void FIELD_G3D_MAP_CloseArchive(FieldG3dMap *map);
void FIELD_G3D_MAP_SetAltTextureRes(FieldG3dMap *map, void *textureRes);
void FIELD_G3D_MAP_ClearAltTextureRes(FieldG3dMap *map);
void FIELD_G3D_MAP_SetPlacedModels(FieldG3dMap *map, FieldG3dMapModelSet *placedModels);
void FIELD_G3D_MAP_ClearPlacedModels(FieldG3dMap *map);
void FIELD_G3D_MAP_SetPlacement(FieldG3dMap *map, FieldG3dMapPlacement *src, u32 index);
void FIELD_G3D_MAP_ClearPlacement(FieldG3dMap *map, u32 index);
FieldG3dMapPlacement *FIELD_G3D_MAP_GetPlacement(FieldG3dMap *map, u32 index);
void FIELD_G3D_MAP_StartLoad(FieldG3dMap *map, u32 memberIndex);
void FIELD_G3D_MAP_Unload(FieldG3dMap *map);
void FIELD_G3D_MAP_SetVisible(FieldG3dMap *map, u16 visible);
u16 FIELD_G3D_MAP_IsVisible(FieldG3dMap *map);
void FIELD_G3D_MAP_SetPos(FieldG3dMap *map, const VecFx32 *pos);
void FIELD_G3D_MAP_GetPos(FieldG3dMap *map, VecFx32 *dst);
u16 *FIELD_G3D_MAP_GetActiveRef(FieldG3dMap *map, u16 **out);
void FIELD_G3D_MAP_GetBuffer(FieldG3dMap *map, u8 **out);
void FIELD_G3D_MAP_GetMemberIndex(FieldG3dMap *map, u32 *out);
void FIELD_G3D_MAP_GetTotalBytes(FieldG3dMap *map, u32 *out);
void FIELD_G3D_MAP_SetModelRes(FieldG3dMap *map, u8 *value);
void FIELD_G3D_MAP_ClearModelRes(FieldG3dMap *map);
void *FIELD_G3D_MAP_GetModelRes(FieldG3dMap *map);
void FIELD_G3D_MAP_ClearTextureRes(FieldG3dMap *map);
void *FIELD_G3D_MAP_GetTextureRes(FieldG3dMap *map);
void FIELD_G3D_MAP_BindRenderObj(FieldG3dMap *map);
FieldG3dMapRenderObj *FIELD_G3D_MAP_GetRenderObj(FieldG3dMap *map);
void FIELD_G3D_MAP_ResetLoadState(FieldG3dMap *map);
void FIELD_G3D_MAP_BeginChunkedLoad(FieldG3dMap *map, u32 member);
int FIELD_G3D_MAP_ReadNextChunk(FieldG3dMap *map);
int FIELD_G3D_MAP_Draw(FieldG3dMap *map);
void FIELD_G3D_MAP_DrawPlacedModels(FieldG3dMap *map, void *unused);
int FIELD_G3D_MAP_CanQueryHits(FieldG3dMap *map);
void FIELD_G3D_MAP_QueryHits(FieldG3dMapHitList *out, FieldG3dMap *map, const VecFx32 *pos, u32 gridSize);
void FIELD_G3D_MAP_QueryPlane(u32 *plane, FieldG3dMap *map, const VecFx32 *pos, u32 gridSize);
void FIELD_G3D_MAP_ClearPlacements(FieldG3dMap *map);
void FIELD_G3D_MAP_Reset(FieldG3dMap *map);
void FIELD_G3D_MAP_InitRenderObj(FieldG3dMapRenderObj *renderObj, void *modelRes, void *textureRes);
FieldG3dMapRenderObj *FIELD_G3D_MAP_ClearRenderObjModel(FieldG3dMapRenderObj *renderObj);
int FIELD_G3D_MAP_TestModelBox(FieldG3dMapModel *model);
u32 FIELD_G3D_MAP_RunBoxTest(const short *box);
void *FIELD_G3D_MAP_PickTextureRes(FieldG3dMap *map);
void FIELD_G3D_MAP_ReadWhole(FieldG3dMap *map, u32 member);
/* END mkheaders: generated region */

#endif
