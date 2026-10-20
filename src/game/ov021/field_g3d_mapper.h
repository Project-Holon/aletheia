#ifndef GAME_OV021_FIELD_G3D_MAPPER_H
#define GAME_OV021_FIELD_G3D_MAPPER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_g3d_mapper.c, prototypes copied from their definitions. */

struct G3dCamera;
struct MapMatrix;
struct HeightEx;
struct BuildModelMan;
struct FieldWfbc;
struct FieldGroundAnime;

#include "../ov021/field_g3d_mapper_types.h"
#include "../types.h"
#include "../ov020/event_mapchange_types.h"
#include "../arm9/g3d_system_types.h"
#include "../sdk_fx.h"
#include "../ov010/field_g3d_map_types.h"
#include "../ov010/field_g3d_map_types.h"

FieldG3dMapper *FIELD_G3D_MAPPER_Create(u16 heapId, u16 buildModelParam);
int FIELD_G3D_MAPPER_Delete(FieldG3dMapper *mapper);
void FIELD_G3D_MAPPER_UpdateBlocking(FieldG3dMapper *mapper);
int FIELD_G3D_MAPPER_UpdateStep(FieldG3dMapper *mapper);
void FIELD_G3D_MAPPER_StepBlocks(FieldG3dMapper *mapper);
void FIELD_G3D_MAPPER_Draw(FieldG3dMapper *mapper, struct G3dCamera *camera, int pass);
int FIELD_G3D_MAPPER_AppendMatrix(FieldMap *fieldMap, FieldG3dMapper *mapper, struct MapMatrix *matrix);
struct HeightEx *FIELD_G3D_MAPPER_GetHeightEx(FieldG3dMapper *mapper);
void FIELD_G3D_MAPPER_Setup(FieldG3dMapper *mapper, const FieldG3dMapperSetup *setup, const u8 *tintTable);
void FIELD_G3D_MAPPER_ReleaseBlocks(FieldG3dMapper *mapper);
int FIELD_G3D_MAPPER_TintTexture(G3dResource *res, const u8 *tintTable);
void FIELD_G3D_MAPPER_LoadTexture(FieldG3dMapper *mapper, const FieldG3dMapperSetup *setup, const u8 *tintTable);
void FIELD_G3D_MAPPER_FreeTexture(FieldG3dMapper *mapper);
void FIELD_G3D_MAPPER_SetFocusPos(FieldG3dMapper *mapper, const VecFx32 *pos);
int FIELD_G3D_MAPPER_GetFocusSlot(FieldG3dMapper *mapper);
void FIELD_G3D_MAPPER_LayoutLinear(FieldG3dMapper *mapper, const VecFx32 *focusPos, FieldG3dMapperCell *cells);
void FIELD_G3D_MAPPER_LayoutWindowClipped(FieldG3dMapper *mapper, const VecFx32 *focusPos, FieldG3dMapperCell *cells);
void FIELD_G3D_MAPPER_LayoutWindowWrapped(FieldG3dMapper *mapper, const VecFx32 *focusPos, FieldG3dMapperCell *cells);
void FIELD_G3D_MAPPER_LayoutLayers(FieldG3dMapper *mapper, const VecFx32 *focusPos, FieldG3dMapperCell *cells);
int FIELD_G3D_MAPPER_ApplyLayout(FieldG3dMapper *mapper, FieldG3dMapperCell *newCells);
int FIELD_G3D_MAPPER_GetWindowStartEven(u32 count, int cellSize, int pos);
int FIELD_G3D_MAPPER_GetWindowStartOdd(u32 count, int cellSize, int pos);
int FIELD_G3D_MAPPER_GetWindowStartWrapped(u32 count, int cellSize, int pos);
FieldG3dMapHit *FIELD_G3D_MAPPER_ClearHit(FieldG3dMapHit *hit);
void FIELD_G3D_MAPPER_ClearHitList(FieldG3dMapperHitList *list);
int FIELD_G3D_MAPPER_QueryHits(FieldG3dMapper *mapper, const VecFx32 *pos, FieldG3dMapperHitList *list);
int FIELD_G3D_MAPPER_QueryNearestHit(FieldG3dMapper *mapper, const VecFx32 *pos, FieldG3dMapHit *outHit);
int FIELD_G3D_MAPPER_QuerySlotPlane(FieldG3dMapper *mapper, int slotIndex, const VecFx32 *pos, FieldG3dMapHit *outHit);
int FIELD_G3D_MAPPER_CheckSlotReady(FieldG3dMapper *mapper, int slotIndex);
int FIELD_G3D_MAPPER_IsOutsideGrid(FieldG3dMapper *mapper, const VecFx32 *pos);
void FIELD_G3D_MAPPER_SetOriginOffset(FieldG3dMapper *mapper, const VecFx32 *offset);
void FIELD_G3D_MAPPER_GetOriginOffset(FieldG3dMapper *mapper, VecFx32 *offset);
struct BuildModelMan *FIELD_G3D_MAPPER_GetBuildModel(FieldG3dMapper *mapper);
struct FieldWfbc *FIELD_G3D_MAPPER_GetWfbc(FieldG3dMapper *mapper);
void FIELD_G3D_MAPPER_SetupWfbc(FieldG3dMapper *mapper, void *wfbcData, u32 param);
struct FieldGroundAnime *FIELD_G3D_MAPPER_CreateGroundAnime(int slotCount, G3dResource *textureRes, const int *animeIds, int heapId);
int FIELD_G3D_MAPPER_SlotResHasGroundAnime(FieldG3dMapperSlotRes *res);
struct FieldGroundAnime *FIELD_G3D_MAPPER_SlotResGetGroundAnime(FieldG3dMapperSlotRes *res);
struct BuildModelMan *FIELD_G3D_MAPPER_SlotResGetBuildModel(FieldG3dMapperSlotRes *res);
struct FieldWfbc *FIELD_G3D_MAPPER_SlotResGetWfbc(FieldG3dMapperSlotRes *res);
int FIELD_G3D_MAPPER_SlotResGetSlotIndex(FieldG3dMapperSlotRes *res);
u16 FIELD_G3D_MAPPER_SlotResGetHeapId(FieldG3dMapperSlotRes *res);
void FIELD_G3D_MAPPER_InitSlotRes(FieldG3dMapperSlotRes *res, FieldG3dMapper *mapper, int slotIndex, int heapId);
void FIELD_G3D_MAPPER_FreeGroundAnimeSlot(struct FieldGroundAnime **slot);
void FIELD_G3D_MAPPER_ReleaseGroundAnimeSlot(struct FieldGroundAnime **slot);
int FIELD_G3D_MAPPER_SlotResTestGroundAnime(FieldG3dMapperSlotRes *res);
struct FieldGroundAnime *FIELD_G3D_MAPPER_SlotResReadGroundAnime(FieldG3dMapperSlotRes *res);
FieldG3dMapperCell *FIELD_G3D_MAPPER_ResetCell(FieldG3dMapperCell *cell);
void FIELD_G3D_MAPPER_SetCellGridIndex(FieldG3dMapperCell *cell, u32 gridIndex);
int FIELD_G3D_MAPPER_IsCellUsed(FieldG3dMapperCell *cell);
u32 FIELD_G3D_MAPPER_GetCellGridIndex(FieldG3dMapperCell *cell);
FieldG3dMapperCell *FIELD_G3D_MAPPER_SetCellPos(FieldG3dMapperCell *cell, int x, int y, int z);
void FIELD_G3D_MAPPER_GetCellPos(FieldG3dMapperCell *cell, VecFx32 *pos);
void FIELD_G3D_MAPPER_AppendHeightExHits(const FieldG3dMapper *mapper, const VecFx32 *pos, FieldG3dMapperHitList *list);
void FIELD_G3D_MAPPER_BeginDrawOrder(FieldG3dMapper *mapper);
void FIELD_G3D_MAPPER_StampFrame(FieldG3dMapper *mapper);
void FIELD_G3D_MAPPER_InsertDrawOrder(FieldG3dMapper *mapper, FieldG3dMap *map, int slotIndex);
void FIELD_G3D_MAPPER_CountFittingSlots(FieldG3dMapper *mapper);
int FIELD_G3D_MAPPER_GetDrawSlot(FieldG3dMapper *mapper, u32 order, int pass, u32 *slotIndex);
/* END mkheaders: generated region */

#endif
