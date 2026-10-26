/*
 * file:     field_g3d_mapper.c
 * unit:     yes
 * function: FIELD_G3D_MAPPER_Create, FIELD_G3D_MAPPER_Delete, FIELD_G3D_MAPPER_UpdateBlocking, FIELD_G3D_MAPPER_UpdateStep, FIELD_G3D_MAPPER_StepBlocks, FIELD_G3D_MAPPER_Draw, FIELD_G3D_MAPPER_AppendMatrix, FIELD_G3D_MAPPER_GetHeightEx, FIELD_G3D_MAPPER_Setup, FIELD_G3D_MAPPER_ReleaseBlocks, FIELD_G3D_MAPPER_TintTexture, FIELD_G3D_MAPPER_LoadTexture, FIELD_G3D_MAPPER_FreeTexture, FIELD_G3D_MAPPER_SetFocusPos, FIELD_G3D_MAPPER_GetFocusSlot, FIELD_G3D_MAPPER_LayoutLinear, FIELD_G3D_MAPPER_LayoutWindowClipped, FIELD_G3D_MAPPER_LayoutWindowWrapped, FIELD_G3D_MAPPER_LayoutLayers, FIELD_G3D_MAPPER_ApplyLayout, FIELD_G3D_MAPPER_GetWindowStartEven, FIELD_G3D_MAPPER_GetWindowStartOdd, FIELD_G3D_MAPPER_GetWindowStartWrapped, FIELD_G3D_MAPPER_ClearHit, FIELD_G3D_MAPPER_ClearHitList, FIELD_G3D_MAPPER_QueryHits, FIELD_G3D_MAPPER_QueryNearestHit, FIELD_G3D_MAPPER_QuerySlotPlane, FIELD_G3D_MAPPER_CheckSlotReady, FIELD_G3D_MAPPER_IsOutsideGrid, FIELD_G3D_MAPPER_SetOriginOffset, FIELD_G3D_MAPPER_GetOriginOffset, FIELD_G3D_MAPPER_GetBuildModel, FIELD_G3D_MAPPER_GetWfbc, FIELD_G3D_MAPPER_SetupWfbc, FIELD_G3D_MAPPER_CreateGroundAnime, FIELD_G3D_MAPPER_SlotResHasGroundAnime, FIELD_G3D_MAPPER_SlotResGetGroundAnime, FIELD_G3D_MAPPER_SlotResGetBuildModel, FIELD_G3D_MAPPER_SlotResGetWfbc, FIELD_G3D_MAPPER_SlotResGetSlotIndex, FIELD_G3D_MAPPER_SlotResGetHeapId, FIELD_G3D_MAPPER_InitSlotRes, FIELD_G3D_MAPPER_FreeGroundAnimeSlot, FIELD_G3D_MAPPER_ReleaseGroundAnimeSlot, FIELD_G3D_MAPPER_SlotResTestGroundAnime, FIELD_G3D_MAPPER_SlotResReadGroundAnime, FIELD_G3D_MAPPER_ResetCell, FIELD_G3D_MAPPER_SetCellGridIndex, FIELD_G3D_MAPPER_IsCellUsed, FIELD_G3D_MAPPER_GetCellGridIndex, FIELD_G3D_MAPPER_SetCellPos, FIELD_G3D_MAPPER_GetCellPos, FIELD_G3D_MAPPER_AppendHeightExHits, FIELD_G3D_MAPPER_BeginDrawOrder, FIELD_G3D_MAPPER_StampFrame, FIELD_G3D_MAPPER_InsertDrawOrder, FIELD_G3D_MAPPER_CountFittingSlots, FIELD_G3D_MAPPER_GetDrawSlot
 * address:  0x0218C9E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_msgbg.c at 0x0218C9E8: field_g3d_mapper.c __FILE__ anchor; the functions before it are called only from field_buildmodel.c or use its data.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   G3D_SYSTEM_CreateResourceArc  0x02046DB8  arm
 *   G3D_SYSTEM_TransVramTextureAndCut  0x020470A8  arm
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm
 *   FIELD_G3D_MAP_GetPos  0x02169510  thumb
 *   gFieldG3dMapperSrcName     0x021DD9EC  data  ov021  a4
 *   FIELD_WFBC_Create  0x021938AC  thumb ov021
 *   HEIGHT_EX_CreateTable  0x021C05D4  thumb ov021
 *   HEIGHT_EX_FreeTable  0x021C0674  thumb  ov021
 *   FIELD_WFBC_Delete  0x021938D4  thumb  ov021
 *   FIELD_G3D_MAP_WaitLoad  0x0216932C  thumb ov010
 *   FIELD_G3D_MAP_GetActiveRef  0x02169520  thumb  ov010
 *   FIELD_G3D_MAP_Update  0x02169308  thumb  ov010
 *   FX_Div  0x0207C768  arm
 *   FIELD_GROUND_ANIME_Update  0x021A73DC  thumb  ov021
 *   FIELD_G3D_MAP_SetPos  0x02169500  thumb ov010
 *   FIELD_G3D_MAP_DrawWithModels  0x02169354  thumb ov010
 *   MAP_MATRIX_GetWidth  0x02159BF4  thumb
 *   MAP_MATRIX_GetHeight  0x02159BF8  thumb
 *   MAP_MATRIX_GetCount  0x02159BFC  thumb
 *   MAP_MATRIX_GetMapGrid  0x02159C20  thumb
 *   MAP_MATRIX_SetSize  0x02159C00  thumb
 *   GAME_DATA_GetFieldWork  0x02012974  thumb
 *   gFieldG3dMapperMapTypeTable     0x021D3DDC  data
 *   FIELD_G3D_MAP_Create  0x02169148  thumb  ov010
 *   FIELD_G3D_MAP_OpenArchive  0x0216937C  thumb  ov010
 *   FIELD_G3D_MAP_SetAltTextureRes  0x021693B4  thumb  ov010
 *   FIELD_G3D_MAP_SetPlacedModels  0x021693C4  thumb  ov010
 *   FIELD_G3D_MAP_ClearPlacedModels  0x021693CC  thumb ov010
 *   FIELD_G3D_MAP_ClearAltTextureRes  0x021693BC  thumb ov010
 *   FIELD_G3D_MAP_CloseArchive  0x021693A0  thumb ov010
 *   FIELD_G3D_MAP_Destroy  0x0216928C  thumb ov010
 *   FIELD_GROUND_ANIME_Delete  0x021A73C0  thumb ov021
 *   PALANM_ConvertGrayTable  0x02022040  thumb
 *   FIELD_G3D_MAP_IsVisible  0x021694FC  thumb ov010
 *   FIELD_G3D_MAP_SetVisible  0x021694F8  thumb ov010
 *   FIELD_G3D_MAP_Unload  0x021694D4  thumb ov010
 *   FIELD_G3D_MAP_StartLoad  0x02169470  thumb ov010
 *   FIELD_G3D_MAP_QueryHits  0x02169800  thumb ov010
 *   MAP_ATTR_IsPresent  0x021AB100  thumb ov021
 *   FIELD_G3D_MAP_QueryPlane  0x02169848  thumb  ov010
 *   FIELD_G3D_MAP_CanQueryHits  0x021697E0  thumb ov010
 *   FIELD_WFBC_SetUp  0x02193B04  thumb  ov021
 *   gFieldG3dMapperGroundAnimeParam     0x021DD9E0  data ov021 a2
 *   g_021DD9E0     0x021DD9E0  data ov021 a2
 *   FIELD_GROUND_ANIME_Create  0x021A7360  thumb ov021
 *   FIELD_GROUND_ANIME_GetAnmEntry  0x021A7404  thumb  ov021
 *   FIELD_GROUND_ANIME_UnbindAnm  0x021A7418  thumb
 *   gFieldG3dMapperDefaultHitHead     0x021D3DD4  data a2
 *   HEIGHT_EX_GetAreaCount  0x021C0688  thumb ov021
 *   HEIGHT_EX_IsPointInAreaAt  0x021C068C  thumb ov021
 *   HEIGHT_EX_GetAreaAttr  0x021C06B4  thumb ov021
 *   HEIGHT_EX_GetAreaHeight  0x021C06A8  thumb ov021
 *   FIELD_G3D_MAP_GetRenderObj  0x02169598  thumb ov010
 *   FIELD_G3D_MAP_GetTotalBytes  0x02169538  thumb ov010
 *   FIELD_BUILDMODEL_Create  0x0218B754  thumb  ov021
 *   FIELD_BUILDMODEL_Delete  0x0218B7F8  thumb  ov021
 *   FIELD_BUILDMODEL_UpdateSeason  0x0218B83C  thumb  ov021
 *   FIELD_BUILDMODEL_DrawNodes  0x0218B88C  thumb  ov021
 *   FIELD_BUILDMODEL_UnregisterObject  0x0218B9FC  thumb  ov021
 *   FIELD_BUILDMODEL_GetHandleTable  0x0218BB04  thumb  ov021
 *   _u32_div_f     0x0209C2B0  arm
 *   G3D_SYSTEM_GetResourceFile  0x02046F48  arm  arm9
 *   NNS_G3dGetTex  0x0206E964  arm  arm9
 */
#include "field_g3d_mapper_types.h"
#include "../sdk_ioreg.h"

#include "../types.h"

#define HW_VBLANK_COUNT_BUF (*(volatile u32 *)0x02FFFC3C)
#define REG_VCOUNT          (*(volatile u16 *)REG_VCOUNT_ADDR)

struct MapMatrix;
struct BuildModelMan;
struct FieldGroundAnime;
struct FieldWfbc;
struct HeightEx;

/* Palette block of a texture resource (the fields the tint pass reads). */
typedef struct G3dResTexView {
    u8 pad00[0x30];
    u16 plttSize;                  /* 0x30, in 8 byte units */
    u8 pad32[6];
    u32 plttDataOffset;            /* 0x38 */
} G3dResTexView;

#include "../arm9/mi_memory.h"
#include "../arm9/fx_cp.h"
#include "fieldmap.h"
#include "../arm9/gamesystem.h"
#include "../arm9/game_data.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/g3d_system.h"
struct G3dResource;
#include "../arm9/nns_g3d_res.h"
#include "../arm9/palanm.h"
/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define MAP_MATRIX_SetSize MAP_MATRIX_SetSize_header
#endif
#include "../ov010/map_matrix.h"
#ifdef __MWERKS__
#undef MAP_MATRIX_SetSize
extern void MAP_MATRIX_SetSize(struct MapMatrix *, u8, u8);
#endif

#include "../ov010/field_g3d_map.h"
struct FieldG3dMap;
struct VecFx32;
struct FieldG3dMapHitList;

#include "map_attr.h"
struct GroundAnimeDesc;
#include "field_ground_anime.h"
struct GroundAnmEntry;
#include "field_wfbc.h"
struct HeightExTable;
#include "height_ex.h"
struct BuildModelMan;
#include "field_buildmodel.h"
struct BuildModelHandleTable;

extern const char gFieldG3dMapperSrcName[];
extern FieldG3dMapType gFieldG3dMapperMapTypeTable[];
extern FieldG3dMapperGroundAnimeParam gFieldG3dMapperGroundAnimeParam;
/* Second name of the same address: the image loads the call argument through its own pool word. */
extern FieldG3dMapperGroundAnimeParam g_021DD9E0;
extern FieldG3dMapperHitHead gFieldG3dMapperDefaultHitHead;

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

/* Fixed point multiply with rounding (the SDK inline). */
static inline s32 FX_Mul(s32 a, s32 b)
{
    return (s32)(((fx64)a * b + 0x800) >> 12);
}

static inline void SetVecFx32(VecFx32 *dst, s32 x, s32 y, s32 z)
{
    dst->x = x;
    dst->y = y;
    dst->z = z;
}

FieldG3dMapper *FIELD_G3D_MAPPER_Create(u16 heapId, u16 buildModelParam)
{
    FieldG3dMapper *mapper = GFL_HEAP_Alloc(heapId, sizeof(*mapper), 1, (char *)gFieldG3dMapperSrcName, 0xf9);
    mapper->heapId = heapId;
    mapper->focusPos.x = 0;
    mapper->focusPos.y = 0;
    mapper->focusPos.z = 0;
    mapper->gridWidth = 0;
    mapper->gridDepth = 0;
    mapper->blockCount = 0;
    mapper->blockGrid = 0;
    mapper->cellSize = 0;
    mapper->layerHeight = 0;
    mapper->layout = 1;
    mapper->mapArchiveId = -1;
    mapper->drawReserve = 0;
    mapper->groundAnime = 0;
    mapper->buildModel = (struct BuildModelMan *)FIELD_BUILDMODEL_Create(mapper->heapId, mapper, buildModelParam);
    mapper->wfbc = FIELD_WFBC_Create(heapId);
    mapper->heightEx = (struct HeightEx *)HEIGHT_EX_CreateTable(0x10, (u8)heapId);
    return mapper;
}

int FIELD_G3D_MAPPER_Delete(FieldG3dMapper *mapper)
{
    HEIGHT_EX_FreeTable((struct HeightExTable *)mapper->heightEx);
    FIELD_G3D_MAPPER_ReleaseBlocks(mapper);
    FIELD_WFBC_Delete(mapper->wfbc);
    if (mapper->buildModel != 0) {
        FIELD_BUILDMODEL_Delete((struct BuildModelMan *)mapper->buildModel);
        mapper->buildModel = 0;
    }
    return GFL_HEAP_Free(mapper);
}

void FIELD_G3D_MAPPER_UpdateBlocking(FieldG3dMapper *mapper)
{
    int i;
    int cellX;
    int cellZ;

    if (mapper->blockGrid == 0)
        return;
    for (i = 0; i < mapper->slotCount; i++)
        FIELD_G3D_MAPPER_ResetCell(&mapper->cells[i]);
    switch (mapper->layout) {
    case 0:
        FIELD_G3D_MAPPER_LayoutLinear(mapper, &mapper->focusPos, mapper->cells);
        break;
    case 1:
    default:
        FIELD_G3D_MAPPER_LayoutWindowClipped(mapper, &mapper->focusPos, mapper->cells);
        break;
    case 2:
        FIELD_G3D_MAPPER_LayoutWindowWrapped(mapper, &mapper->focusPos, mapper->cells);
        break;
    case 3:
        FIELD_G3D_MAPPER_LayoutLayers(mapper, &mapper->focusPos, mapper->cells);
        break;
    }
    FIELD_G3D_MAPPER_ApplyLayout(mapper, mapper->cells);
    for (i = 0; i < mapper->slotCount; i++)
        FIELD_G3D_MAP_WaitLoad(mapper->slots[i].map);
    cellX = FX_Div(mapper->focusPos.x, mapper->cellSize);
    cellZ = FX_Div(mapper->focusPos.z, mapper->cellSize);
    mapper->focusCell = (cellX >> 12) + (cellZ >> 12) * mapper->gridWidth;
}

int FIELD_G3D_MAPPER_UpdateStep(FieldG3dMapper *mapper)
{
    int i;
    int busy;
    int cellX;
    int cellZ;
    u16 *active;

    if (mapper->blockGrid == 0)
        return 0;
    for (i = 0; i < mapper->slotCount; i++)
        FIELD_G3D_MAPPER_ResetCell(&mapper->cells[i]);
    switch (mapper->layout) {
    case 0:
        FIELD_G3D_MAPPER_LayoutLinear(mapper, &mapper->focusPos, mapper->cells);
        break;
    case 1:
    default:
        FIELD_G3D_MAPPER_LayoutWindowClipped(mapper, &mapper->focusPos, mapper->cells);
        break;
    case 2:
        FIELD_G3D_MAPPER_LayoutWindowWrapped(mapper, &mapper->focusPos, mapper->cells);
        break;
    case 3:
        FIELD_G3D_MAPPER_LayoutLayers(mapper, &mapper->focusPos, mapper->cells);
        break;
    }
    FIELD_G3D_MAPPER_ApplyLayout(mapper, mapper->cells);
    busy = 0;
    FIELD_G3D_MAPPER_BeginDrawOrder(mapper);
    for (i = 0; i < mapper->slotCount; i++) {
        FIELD_G3D_MAP_GetActiveRef(mapper->slots[i].map, &active);
        if (*active == 1)
            busy = 1;
        FIELD_G3D_MAP_Update(mapper->slots[i].map);
        FIELD_G3D_MAPPER_InsertDrawOrder(mapper, mapper->slots[i].map, i);
    }
    FIELD_G3D_MAPPER_CountFittingSlots(mapper);
    cellX = FX_Div(mapper->focusPos.x, mapper->cellSize);
    cellZ = FX_Div(mapper->focusPos.z, mapper->cellSize);
    mapper->focusCell = (cellX >> 12) + (cellZ >> 12) * mapper->gridWidth;
    FIELD_BUILDMODEL_UpdateSeason((struct BuildModelMan *)mapper->buildModel);
    if (mapper->groundAnime != 0)
        FIELD_GROUND_ANIME_Update(mapper->groundAnime);
    return busy;
}

void FIELD_G3D_MAPPER_StepBlocks(FieldG3dMapper *mapper)
{
    int i;
    if (mapper->blockGrid != 0) {
        for (i = 0; i < mapper->slotCount; i++)
            FIELD_G3D_MAP_Update(mapper->slots[i].map);
        FIELD_G3D_MAPPER_StampFrame(mapper);
    }
}

void FIELD_G3D_MAPPER_Draw(FieldG3dMapper *mapper, struct G3dCamera *camera, int pass)
{
    VecFx32 mapPos;
    VecFx32 drawPos;
    u32 slotIndex;
    int i;
    u8 *drawnCount;

    if (pass == 0 && mapper->drawReserve == 0)
        return;
    for (i = 0; i < mapper->slotCount; i++) {
        if (FIELD_G3D_MAPPER_GetDrawSlot(mapper, i, pass, &slotIndex)) {
            int drawn;
            drawnCount = &mapper->drawnCount;
            FIELD_G3D_MAP_GetPos(mapper->slots[slotIndex].map, (struct VecFx32 *)(&mapPos));
            drawPos.x = mapPos.x + mapper->originOffset.x;
            drawPos.y = mapPos.y + mapper->originOffset.y;
            drawPos.z = mapPos.z + mapper->originOffset.z;
            FIELD_G3D_MAP_SetPos(mapper->slots[slotIndex].map, (struct VecFx32 *)(&drawPos));
            drawn = FIELD_G3D_MAP_DrawWithModels(mapper->slots[slotIndex].map, camera);
            FIELD_G3D_MAP_SetPos(mapper->slots[slotIndex].map, (struct VecFx32 *)(&mapPos));
            if (drawn != 0 && mapper->drawnCount < mapper->slotCount)
                *drawnCount = *drawnCount + 1;
        }
    }
    if (pass == 1)
        FIELD_BUILDMODEL_DrawNodes((struct BuildModelMan *)mapper->buildModel);
}

/*
 * Appends a matrix of map blocks to the right of the block grid and remaps
 * the grid indices of the loaded cells to the wider grid.
 *
 * Grid entries are 4-byte structs (FieldG3dMapperGridEntry): the entry copies
 * are struct assignments, which is what gives the copy loops the image's load
 * order and colours. The matrix's own entries are plain words (.mapModelIndex
 * store).
 *
 * Addresses are Black-image addresses.
 */
int FIELD_G3D_MAPPER_AppendMatrix(FieldMap *fieldMap, FieldG3dMapper *mapper, struct MapMatrix *matrix)
{
    u32 *matrixCells;
    u32 newCount;
    FieldG3dMapperGridEntry *newGrid;
    u32 gridIndex;
    u32 cellRow;
    u16 newDepth;
    int matrixDepth;
    u16 newWidth;
    u16 matrixWidth;
    int matrixCount;
    u32 k;
    u32 oldWidth;
    FieldG3dMapperSlot *slot;
    int row;
    int col;

    matrixWidth = MAP_MATRIX_GetWidth(matrix);
    matrixDepth = MAP_MATRIX_GetHeight(matrix);
    matrixCount = MAP_MATRIX_GetCount(matrix);
    matrixCells = MAP_MATRIX_GetMapGrid(matrix);
    newWidth = mapper->gridWidth + matrixWidth;
    newDepth = mapper->gridDepth;
    newCount = mapper->blockCount + matrixCount;
    if (newDepth != matrixDepth)
        return 0;
    if (newCount > 900 || newWidth > 30 || newDepth > 30)
        return 0;

    newGrid = GFL_HEAP_Alloc((u16)((mapper->heapId & 0x7FFF) | 0x8000), newCount * 4, 0, (char *)gFieldG3dMapperSrcName, 0x25F);
    for (row = 0; row < mapper->gridDepth; row++) {
        for (col = 0; col < mapper->gridWidth; col++)
            newGrid[row * newWidth + col] = mapper->blockGrid[row * mapper->gridWidth + col];
    }
    for (row = 0; row < matrixDepth; row++) {
        for (col = 0; col < matrixWidth; col++)
            newGrid[row * newWidth + mapper->gridWidth + col].mapModelIndex = matrixCells[row * matrixWidth + col];
    }
    for (k = 0; k < newCount; k++)
        mapper->blockGrid[k] = newGrid[k];

    oldWidth = mapper->gridWidth;
    gridIndex = mapper->focusCell;
    mapper->focusCell = gridIndex % oldWidth + gridIndex / oldWidth * newWidth;
    for (row = 0; row < mapper->slotCount; row++) {
        if (FIELD_G3D_MAPPER_IsCellUsed(&mapper->slots[row].cell)) {
            oldWidth = mapper->gridWidth;
            slot = &mapper->slots[row];
            cellRow = slot->cell.gridIndex;
            slot->cell.gridIndex = cellRow % oldWidth + cellRow / oldWidth * newWidth;
        }
    }
    mapper->gridWidth = newWidth;
    mapper->gridDepth = newDepth;
    mapper->blockCount = newCount;
    MAP_MATRIX_SetSize(GAME_DATA_GetFieldWork(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap))), newWidth, newDepth);
    GFL_HEAP_Free(newGrid);
    return 1;
}

/*
 * Unlabelled 4-byte getter (ldr r0, [r0, #0x70]; bx lr), a leaf of
 * ov043 FIELD_GIMMICK_LIFT_ELEVATOR_Init.
 */
struct HeightEx *FIELD_G3D_MAPPER_GetHeightEx(FieldG3dMapper *mapper)
{
    return mapper->heightEx;
}

/*
 * Addresses are Black-image addresses.
 *
 * setup is const: that lets the scheduler pull the long-lived field loads
 * (blockCount, layout, cols, rows) above the stores into mapper, as in the
 * image.
 */
void FIELD_G3D_MAPPER_Setup(FieldG3dMapper *mapper, const FieldG3dMapperSetup *setup, const u8 *tintTable)
{
    FieldG3dMapConfig config;
    int i;
    FieldG3dMap *map;

    mapper->cellSize = setup->cellSize;
    mapper->layerHeight = setup->layerHeight;
    mapper->mapArchiveId = setup->mapArchiveId;
    mapper->gridWidth = setup->gridWidth;
    mapper->gridDepth = setup->gridDepth;
    mapper->blockCount = setup->blockCount;
    mapper->layout = setup->layout;
    mapper->blockGrid = setup->blockGrid;
    mapper->cols = setup->cols;
    mapper->rows = setup->rows;
    mapper->slotCount = setup->cols * setup->rows;
    mapper->drawReserve = setup->drawReserve;
    mapper->lastDrawnCount = mapper->slotCount;
    mapper->drawnCount = mapper->slotCount;
    switch (setup->layout) {
    case 0:
        if (setup->blockCount > mapper->slotCount)
            mapper->layout = 1;
        break;
    case 3:
        if (mapper->gridWidth * mapper->gridDepth > mapper->slotCount / 2)
            mapper->layout = 1;
        break;
    }
    mapper->textureMode = setup->textureMode;
    FIELD_G3D_MAPPER_LoadTexture(mapper, setup, tintTable);
    mapper->groundAnime = FIELD_G3D_MAPPER_CreateGroundAnime(mapper->slotCount, mapper->textureRes, setup->groundAnimeIds, mapper->heapId);
    config.bufferSize = setup->blockBufferSize;
    config.texVramSize = 0;
    config.typeTable = gFieldG3dMapperMapTypeTable;
    config.userParam = 0;
    config.chunkSize = 0x800;
    config.placementCountA = 0x20;
    config.placementCountB = 0;
    config.extraParam0 = 0x1000000;
    config.extraParam1 = 0x400000;
    mapper->slots = GFL_HEAP_Alloc(mapper->heapId, mapper->slotCount * sizeof(FieldG3dMapperSlot), 1, (char *)gFieldG3dMapperSrcName, 0x306);
    mapper->cells = GFL_HEAP_Alloc(mapper->heapId, mapper->slotCount * sizeof(FieldG3dMapperCell), 1, (char *)gFieldG3dMapperSrcName, 0x307);
    mapper->drawOrder = GFL_HEAP_Alloc(mapper->heapId, mapper->slotCount, 1, (char *)gFieldG3dMapperSrcName, 0x308);
    for (i = 0; i < mapper->slotCount; i++) {
        FIELD_G3D_MAPPER_ResetCell(&mapper->slots[i].cell);
        FIELD_G3D_MAPPER_InitSlotRes(&mapper->slots[i].res, mapper, i, mapper->heapId);
        config.userParam = &mapper->slots[i].res;
        map = FIELD_G3D_MAP_Create(&config, mapper->heapId);
        mapper->slots[i].map = map;
        FIELD_G3D_MAP_OpenArchive(map, mapper->mapArchiveId, mapper->heapId);
        if (mapper->textureRes != 0)
            FIELD_G3D_MAP_SetAltTextureRes(map, mapper->textureRes);
        FIELD_G3D_MAP_SetPlacedModels(map, (struct FieldG3dMapModelSet *)FIELD_BUILDMODEL_GetHandleTable((struct BuildModelMan *)mapper->buildModel));
    }
}

void FIELD_G3D_MAPPER_ReleaseBlocks(FieldG3dMapper *mapper)
{
    int i;

    if (mapper->slots != 0) {
        for (i = 0; i < mapper->slotCount; i++) {
            FIELD_G3D_MAP_ClearPlacedModels(mapper->slots[i].map);
            FIELD_G3D_MAP_ClearAltTextureRes(mapper->slots[i].map);
            FIELD_G3D_MAP_CloseArchive(mapper->slots[i].map);
            FIELD_G3D_MAP_Destroy(mapper->slots[i].map);
            FIELD_G3D_MAPPER_FreeGroundAnimeSlot(&mapper->slots[i].res.groundAnimeSlot);
        }
        GFL_HEAP_Free(mapper->slots);
        GFL_HEAP_Free(mapper->cells);
        GFL_HEAP_Free(mapper->drawOrder);
        mapper->cells = 0;
        mapper->slots = 0;
        mapper->drawOrder = 0;
        mapper->slotCount = 0;
    }
    if (mapper->groundAnime != 0) {
        FIELD_GROUND_ANIME_Delete(mapper->groundAnime);
        mapper->groundAnime = 0;
    }
    FIELD_G3D_MAPPER_FreeTexture(mapper);
}

/*
 * 2026-10-01: MATCH, capped only by the call to PALANM_ConvertGrayTable (arm9, Thumb,
 * unlabelled, no witness outside this function). It is a ~64+ byte RGB555
 * pixel converter (luma weights 76/151/29 over a lookup table); filing it
 * as an arm9 witness would lift this to EXACT.
 */
int FIELD_G3D_MAPPER_TintTexture(G3dResource *res, const u8 *tintTable)
{
    G3dResTexView *tex = (struct G3dResTexView *)NNS_G3dGetTex(G3D_SYSTEM_GetResourceFile(res));
    if (tex != 0) {
        u32 size = tex->plttSize << 3;
        u32 offset = tex->plttDataOffset;
        if (tintTable != 0)
            PALANM_ConvertGrayTable((u16 *)((u8 *)tex + offset), size >> 1, tintTable);
        return 1;
    }
    return 0;
}

void FIELD_G3D_MAPPER_LoadTexture(FieldG3dMapper *mapper, const FieldG3dMapperSetup *setup, const u8 *tintTable)
{
    u32 mode = setup->textureMode;
    if (mode != 0) {
        if (mode == 1) {
            const u32 *textureIds = setup->textureIds;
            mapper->textureRes = G3D_SYSTEM_CreateResourceArc(textureIds[0], textureIds[1]);
            if (tintTable != 0)
                FIELD_G3D_MAPPER_TintTexture(mapper->textureRes, tintTable);
            G3D_SYSTEM_TransVramTextureAndCut(mapper->textureRes);
        }
    } else {
        mapper->textureRes = 0;
    }
}

void FIELD_G3D_MAPPER_FreeTexture(FieldG3dMapper *mapper)
{
    if (mapper->textureRes != 0) {
        G3D_SYSTEM_FreeVramTexture(mapper->textureRes);
        G3D_SYSTEM_DeleteResource(mapper->textureRes);
        mapper->textureRes = 0;
    }
}

/*
 * Copies a vector into the focus position through an inline SetVecFx32
 * helper with a const source.  The image's c,b,a load order with the b,a,c
 * store order needs both: without const (or with plain statements or locals)
 * the stores come out in a,b,c order.  EXACT* only for the 2-byte alignment
 * pad.
 */
void FIELD_G3D_MAPPER_SetFocusPos(FieldG3dMapper *mapper, const VecFx32 *pos)
{
    SetVecFx32(&mapper->focusPos, pos->x, pos->y, pos->z);
}

int FIELD_G3D_MAPPER_GetFocusSlot(FieldG3dMapper *mapper)
{
    VecFx32 slotPos;
    unsigned int i;

    for (i = 0; i < mapper->slotCount; i++) {
        if (FIELD_G3D_MAP_IsVisible(mapper->slots[i].map)) {
            int half;
            int centerX;
            int centerZ;
            int minX;
            int maxX;
            int minZ;
            int maxZ;
            FIELD_G3D_MAP_GetPos(mapper->slots[i].map, (struct VecFx32 *)(&slotPos));
            half = mapper->cellSize / 2;
            centerX = slotPos.x;
            centerZ = slotPos.z;
            minX = centerX - half;
            minZ = centerZ - half;
            maxX = centerX + half;
            maxZ = centerZ + half;
            if (mapper->focusPos.x >= minX && mapper->focusPos.x < maxX
                && mapper->focusPos.z >= minZ && mapper->focusPos.z < maxZ)
                return i;
        }
    }
    return 0;
}

void FIELD_G3D_MAPPER_LayoutLinear(FieldG3dMapper *mapper, const VecFx32 *focusPos, FieldG3dMapperCell *cells)
{
    int cellZ;
    int cellX;
    int cellIndex;
    int col;
    u32 layers;
    u32 layerCells;
    int base;
    u32 layer;
    int y;
    int layerHeight;
    int cellSize;

    layerCells = mapper->gridWidth * mapper->gridDepth;
    layers = mapper->blockCount / layerCells;
    if (mapper->blockCount % layerCells != 0)
        layers++;
    cellSize = mapper->cellSize;
    base = FX_Div(mapper->cellSize, 0x2000);
    cellIndex = 0;
    layerHeight = mapper->layerHeight;
    for (layer = 0; layer < layers; layer++) {
        for (col = 0; col < layerCells; col++) {
            y = FX_Mul(layer << 12, layerHeight);
            cellX = col % mapper->gridWidth;
            cellZ = col / mapper->gridWidth;
            if (cellIndex >= mapper->blockCount)
                cellIndex = -1;
            FIELD_G3D_MAPPER_SetCellGridIndex(cells + cellIndex, cellIndex);
            FIELD_G3D_MAPPER_SetCellPos(cells + cellIndex, base + FX_Mul(cellX << 12, cellSize), y, base + FX_Mul(cellZ << 12, cellSize));
            cellIndex++;
        }
    }
}

/*
 * Addresses are Black-image addresses.
 *
 * The inner loop is a guarded do-while: a plain for with y hoisted by the
 * compiler re-tests the bound after the preheader (extra cmp/ble).
 */
void FIELD_G3D_MAPPER_LayoutWindowClipped(FieldG3dMapper *mapper, const VecFx32 *focusPos, FieldG3dMapperCell *cells){
    int firstCol;
    int firstRow;
    int x;
    int y;
    int base;
    int cellSize;
    int winRow;
    int gridDepth;
    int gridWidth;
    int winCol;
    int gridRow;
    int gridCol;
    int cellIndex;

    gridWidth = mapper->gridWidth;
    gridDepth = mapper->gridDepth;
    cellSize = mapper->cellSize;
    base = FX_Div(mapper->cellSize, 0x2000);
    if (mapper->cols % 2 == 0)
        firstCol = FIELD_G3D_MAPPER_GetWindowStartEven(mapper->cols, cellSize, focusPos->x);
    else
        firstCol = FIELD_G3D_MAPPER_GetWindowStartOdd(mapper->cols, cellSize, focusPos->x);
    if (mapper->rows % 2 == 0)
        firstRow = FIELD_G3D_MAPPER_GetWindowStartEven(mapper->rows, cellSize, focusPos->z);
    else
        firstRow = FIELD_G3D_MAPPER_GetWindowStartOdd(mapper->rows, cellSize, focusPos->z);
    for (winRow = 0; winRow < mapper->rows; winRow++) {
        gridRow = firstRow + winRow;
        if (gridRow < 0 || gridRow >= gridDepth)
            continue;
        winCol = 0;
        if (winCol >= mapper->cols)
            continue;
        y = FX_Mul(gridRow << 12, cellSize);
        do {
            gridCol = firstCol + winCol;
            if (gridCol < 0 || gridCol >= gridWidth)
                continue;
            cellIndex = winCol + winRow * mapper->cols;
            FIELD_G3D_MAPPER_SetCellGridIndex(cells + cellIndex, gridCol + gridRow * gridWidth);
            x = FX_Mul(gridCol << 12, cellSize);
            FIELD_G3D_MAPPER_SetCellPos(cells + cellIndex, base + x, 0, base + y);
        } while (++winCol < mapper->cols);
    }
}

/*
 * Addresses are Black-image addresses.
 *
 * The fx32 multiplies use a long long copy of the scale (scale64) assigned in
 * the outer loop body: LICM hoists it as a 64-bit temporary, which reserves
 * the 8-byte frame slot whose low word is never stored. The outer loop is an
 * explicit guard plus do-while (a plain for duplicates the guard around the
 * hoisted block), and FX_Div re-reads cellSize instead of taking the local,
 * which puts the local below the hoisted wrapRow*gridWidth temporary.
 */
void FIELD_G3D_MAPPER_LayoutWindowWrapped(FieldG3dMapper *mapper, const VecFx32 *focusPos, FieldG3dMapperCell *cells){
    int cellIndex;
    FieldG3dMapperCell *cell;
    int winCol;
    int base;
    int gridWidth;
    int y;
    int winRow;
    int firstCol;
    int firstRow;
    int gridCol;
    int gridRow;
    int gridDepth;
    long long scale64;
    int cellSize;
    int wrapRow;

    gridWidth = mapper->gridWidth;
    gridDepth = mapper->gridDepth;
    cellSize = mapper->cellSize;
    base = FX_Div(mapper->cellSize, 0x2000);
    firstCol = FIELD_G3D_MAPPER_GetWindowStartWrapped(mapper->cols, cellSize, focusPos->x);
    firstRow = FIELD_G3D_MAPPER_GetWindowStartWrapped(mapper->rows, cellSize, focusPos->z);
    winRow = 0;
    if (winRow < mapper->rows) {
        do {
            scale64 = cellSize;
            gridRow = firstRow + winRow;
            wrapRow = gridRow % gridDepth;
            if (wrapRow < 0)
                wrapRow += gridDepth;
            for (winCol = 0; winCol < mapper->cols; winCol++) {
                y = (int)(((long long)(gridRow << 12) * scale64 + 0x800LL) >> 12);
                gridCol = firstCol + winCol;
                cellIndex = gridCol % gridWidth;
                if (cellIndex < 0)
                    cellIndex += gridWidth;
                cell = &cells[winCol + winRow * mapper->cols];
                FIELD_G3D_MAPPER_SetCellGridIndex(cell, cellIndex + wrapRow * gridWidth);
                FIELD_G3D_MAPPER_SetCellPos(cell, base + (int)(((long long)(gridCol << 12) * scale64 + 0x800LL) >> 12), 0, base + y);
            }
            winRow++;
        } while (winRow < mapper->rows);
    }
}

/*
 * Fills the cell array for the two grid layers nearest the focus: the
 * layer containing focusPos->y, then its neighbour on the side focusPos->y
 * leans toward.  Each cell gets its grid index (or -1 past the end) and its
 * centred position.  `size` is loaded into a local but FX_Mul is passed the
 * field read, which keeps the hoisted sign-extension pair off size's slot
 * (see docs/idioms/an-unused-frame-word-under-a-sign-extension-spill-is-a-
 * field-passed-to-an-earlier-call.md).
 */
void FIELD_G3D_MAPPER_LayoutLayers(FieldG3dMapper *mapper, const VecFx32 *focusPos, FieldG3dMapperCell *cells)
{
    u32 layer;
    u32 layerCells;
    s32 layerHeight;
    s32 half;
    s32 y;
    s32 cellSize;
    u16 gridWidth;
    int row;
    int dir;
    int col;
    u32 rem;
    int i;
    u32 n;
    u32 gridIndex;

    gridWidth = mapper->gridWidth;
    layerCells = gridWidth * mapper->gridDepth;
    cellSize = mapper->cellSize;
    half = FX_Div(mapper->cellSize, 0x2000);
    layerHeight = mapper->layerHeight;
    layer = FX_Div(focusPos->y, layerHeight) >> 12;
    rem = focusPos->y - layer * layerHeight;
    if (rem > layerHeight / 2)
        dir = 1;
    else
        dir = -1;
    n = 0;
    for (i = 0; i < layerCells; i++, n++) {
        y = FX_Mul(layer << 12, layerHeight);
        col = i % mapper->gridWidth;
        row = i / mapper->gridWidth;
        gridIndex = layer * layerCells + row * gridWidth + col;
        if (gridIndex >= mapper->blockCount)
            gridIndex = -1;
        FIELD_G3D_MAPPER_SetCellGridIndex(&cells[n], gridIndex);
        FIELD_G3D_MAPPER_SetCellPos(&cells[n], half + FX_Mul(col << 12, cellSize), y, half + FX_Mul(row << 12, cellSize));
    }
    for (i = 0; i < layerCells; i++, n++) {
        y = FX_Mul((layer + dir) << 12, layerHeight);
        col = i % mapper->gridWidth;
        row = i / mapper->gridWidth;
        gridIndex = (layer + dir) * layerCells + row * gridWidth + col;
        if (gridIndex >= mapper->blockCount)
            gridIndex = -1;
        FIELD_G3D_MAPPER_SetCellGridIndex(&cells[n], gridIndex);
        FIELD_G3D_MAPPER_SetCellPos(&cells[n], half + FX_Mul(col << 12, cellSize), y, half + FX_Mul(row << 12, cellSize));
    }
}

/*
 * Reconciles the slots' live blocks with a freshly laid-out cell array
 * (FIELD_G3D_MAPPER_UpdateBlocking's tail): slots whose grid index survives move to the new
 * position, the rest are hidden and released; new cells then take a free
 * slot.  Returns 1 when any free slot was claimed.
 */
int FIELD_G3D_MAPPER_ApplyLayout(FieldG3dMapper *mapper, FieldG3dMapperCell *newCells)
{
    int placed;
    int moved;
    int changed;
    int result;
    int i;
    int j;

    result = 0;
    for (i = 0; i < mapper->slotCount; i++) {
        if (FIELD_G3D_MAPPER_IsCellUsed(&mapper->slots[i].cell)) {
            u32 gridIndex;
            moved = 0;
            gridIndex = FIELD_G3D_MAPPER_GetCellGridIndex(&mapper->slots[i].cell);
            for (j = 0; j < mapper->slotCount; j++) {
                if (gridIndex == FIELD_G3D_MAPPER_GetCellGridIndex(&newCells[j]) && !moved) {
                    VecFx32 cellPos;
                    FIELD_G3D_MAPPER_GetCellPos(&newCells[j], &cellPos);
                    FIELD_G3D_MAP_SetPos(mapper->slots[i].map, (struct VecFx32 *)(&cellPos));
                    FIELD_G3D_MAPPER_ResetCell(&newCells[j]);
                    moved = 1;
                }
            }
            if (!moved) {
                FIELD_G3D_MAPPER_ResetCell(&mapper->slots[i].cell);
                FIELD_G3D_MAP_SetVisible(mapper->slots[i].map, 0);
                FIELD_BUILDMODEL_UnregisterObject((struct BuildModelMan *)mapper->buildModel, mapper->slots[i].map);
                FIELD_G3D_MAPPER_ReleaseGroundAnimeSlot(&mapper->slots[i].res.groundAnimeSlot);
                FIELD_G3D_MAP_Unload(mapper->slots[i].map);
            }
        }
    }
    changed = 0;
    for (i = 0; i < mapper->slotCount; i++) {
        if (FIELD_G3D_MAPPER_IsCellUsed(&newCells[i])) {
            placed = 0;
            for (j = 0; j < mapper->slotCount; j++) {
                if (!FIELD_G3D_MAPPER_IsCellUsed(&mapper->slots[j].cell) && !placed) {
                    int mapModelIndex = mapper->blockGrid[FIELD_G3D_MAPPER_GetCellGridIndex(&newCells[i])].mapModelIndex;
                    VecFx32 cellPos;
                    FIELD_G3D_MAPPER_GetCellPos(&newCells[i], &cellPos);
                    if (mapModelIndex != -1) {
                        FIELD_G3D_MAP_StartLoad(mapper->slots[j].map, mapModelIndex);
                        FIELD_G3D_MAP_SetPos(mapper->slots[j].map, (struct VecFx32 *)(&cellPos));
                        FIELD_G3D_MAP_SetVisible(mapper->slots[j].map, 1);
                    }
                    mapper->slots[j].cell = newCells[i];
                    placed = 1;
                    changed = 1;
                }
            }
        }
    }
    if (changed == 1)
        result = 1;
    return result;
}

int FIELD_G3D_MAPPER_GetWindowStartEven(u32 count, int cellSize, int pos)
{
    int first = -(int)((count >> 1) - 1);
    int cell = pos / cellSize;
    if (pos % cellSize < FX_Div(cellSize, 0x2000))
        first += cell - 1;
    else
        first += cell;
    return first;
}

int FIELD_G3D_MAPPER_GetWindowStartOdd(u32 count, int cellSize, int pos)
{
    int first = -(int)(count >> 1);
    first += pos / cellSize;
    return first;
}

int FIELD_G3D_MAPPER_GetWindowStartWrapped(u32 count, int cellSize, int pos)
{
    int first = (FX_Div(pos, cellSize) >> 12) - (count >> 1);
    if ((count & 1) == 0) {
        int rem = FX_ModS32(pos, cellSize);
        if (FX_Div(cellSize, 0x2000) < rem)
            first++;
    }
    return first;
}

FieldG3dMapHit *FIELD_G3D_MAPPER_ClearHit(FieldG3dMapHit *hit)
{
    hit->kind = 0;
    hit->index = 0;
    hit->flags = 0;
    hit->attr = 0;
    hit->height = 0;
    return hit;
}

void FIELD_G3D_MAPPER_ClearHitList(FieldG3dMapperHitList *list)
{
    int i;
    for (i = 0; i < 16; i++)
        FIELD_G3D_MAPPER_ClearHit(&list->hits[i]);
    list->count = 0;
}

int FIELD_G3D_MAPPER_QueryHits(FieldG3dMapper *mapper, const VecFx32 *pos, FieldG3dMapperHitList *list)
{
    VecFx32 slotPos;
    FieldG3dMapHitList slotHits;
    int half;
    int i;
    u32 n;

    if (mapper->blockGrid == 0)
        return 0;
    FIELD_G3D_MAPPER_ClearHitList(list);
    n = 0;
    half = mapper->cellSize >> 1;
    for (i = 0; i < mapper->slotCount; i++) {
        if (FIELD_G3D_MAP_IsVisible(mapper->slots[i].map) == 1) {
            int centerX;
            int centerZ;
            int minX;
            int maxX;
            int minZ;
            int maxZ;
            FIELD_G3D_MAP_GetPos(mapper->slots[i].map, (struct VecFx32 *)(&slotPos));
            centerX = slotPos.x;
            centerZ = slotPos.z;
            minX = centerX - half;
            minZ = centerZ - half;
            maxX = centerX + half;
            maxZ = centerZ + half;
            if (pos->x >= minX && pos->x < maxX && pos->z >= minZ && pos->z < maxZ) {
                u32 j;
                FIELD_G3D_MAP_QueryHits(&slotHits, mapper->slots[i].map, (struct VecFx32 *)pos, mapper->cellSize);
                if (slotHits.count != 0) {
                    if (n + slotHits.count >= 16)
                        break;
                    for (j = 0; j < slotHits.count; j++) {
                        list->hits[n + j].kind = slotHits.hits[j].kind;
                        list->hits[n + j].index = slotHits.hits[j].index;
                        list->hits[n + j].flags = slotHits.hits[j].flags;
                        list->hits[n + j].attr = slotHits.hits[j].attr;
                        list->hits[n + j].height = slotHits.hits[j].height;
                    }
                    n += slotHits.count;
                }
            }
        }
    }
    list->count = n;
    FIELD_G3D_MAPPER_AppendHeightExHits(mapper, pos, list);
    if (list->count != 0)
        return 1;
    return 0;
}

int FIELD_G3D_MAPPER_QueryNearestHit(FieldG3dMapper *mapper, const VecFx32 *pos, FieldG3dMapHit *outHit)
{
    FieldG3dMapperHitList hitList;
    int i;
    int best;
    int minDistance;

    FIELD_G3D_MAPPER_ClearHit(outHit);
    if (FIELD_G3D_MAPPER_QueryHits(mapper, pos, &hitList) == 0)
        return 0;
    if (hitList.count == 1) {
        *outHit = hitList.hits[0];
        return 1;
    }
    best = 0;
    minDistance = 0x00FFF000;
    for (i = 0; i < hitList.count; i++) {
        if (MAP_ATTR_IsPresent(hitList.hits[i].attr)) {
            int distance = hitList.hits[i].height - pos->y;
            if (distance < 0)
                distance = FX_Mul(distance, -4096);
            if (distance < minDistance) {
                best = i;
                minDistance = distance;
            }
        }
    }
    *outHit = hitList.hits[best];
    return 1;
}

int FIELD_G3D_MAPPER_QuerySlotPlane(FieldG3dMapper *mapper, int slotIndex, const VecFx32 *pos, FieldG3dMapHit *outHit)
{
    u32 plane[0x41];
    FIELD_G3D_MAP_QueryPlane(plane, mapper->slots[slotIndex].map, (struct VecFx32 *)pos, mapper->cellSize);
    outHit->attr = plane[2];
    outHit->height = plane[3];
    return 1;
}

int FIELD_G3D_MAPPER_CheckSlotReady(FieldG3dMapper *mapper, int slotIndex)
{
    if (mapper->blockGrid == 0)
        return 0;
    if (FIELD_G3D_MAP_IsVisible(mapper->slots[slotIndex].map) == 0)
        return 0;
    return FIELD_G3D_MAP_CanQueryHits(mapper->slots[slotIndex].map);
}

/*
 * Unlabelled ov021 leaf (a `.word` run in the listing, no lr save), the
 * sole blocker of ov010 FLDMMDL_MOVE_HitCheckMove. Returns 1 (outside) unless the
 * grid is present, not in layout 2, and pos.x/pos.z fall inside the
 * gridWidth*cell by gridDepth*cell rectangle.
 */
int FIELD_G3D_MAPPER_IsOutsideGrid(FieldG3dMapper *mapper, const VecFx32 *pos)
{
    s32 width;
    s32 depth;
    if (mapper->blockGrid == 0)
        return 1;
    if (mapper->layout == 2)
        return 0;
    width = mapper->gridWidth * mapper->cellSize;
    depth = mapper->gridDepth * mapper->cellSize;
    if (pos->x >= 0 && pos->x < width && pos->z >= 0 && pos->z < depth)
        return 0;
    return 1;
}

/*
 * Unlabelled leaf: copies the 12-byte vector at r1 into the object at +0x54.
 * Filed as the only blocker of ov052 FIELD_GIMMICK_BSUBWAY_UpdateTrainSway.
 */
void FIELD_G3D_MAPPER_SetOriginOffset(FieldG3dMapper *mapper, const VecFx32 *offset)
{
    mapper->originOffset = *offset;
}

void FIELD_G3D_MAPPER_GetOriginOffset(FieldG3dMapper *mapper, VecFx32 *offset)
{
    *offset = mapper->originOffset;
}

/*
 * Loads the 32-bit word at byte +0x64 of the object.
 */
struct BuildModelMan *FIELD_G3D_MAPPER_GetBuildModel(FieldG3dMapper *mapper)
{
    return mapper->buildModel;
}

/*
 * Loads the 32-bit word at byte +0x6c of the object.
 */
struct FieldWfbc *FIELD_G3D_MAPPER_GetWfbc(FieldG3dMapper *mapper)
{
    return mapper->wfbc;
}

void FIELD_G3D_MAPPER_SetupWfbc(FieldG3dMapper *mapper, void *wfbcData, u32 param)
{
    FIELD_WFBC_SetUp(mapper->wfbc, wfbcData, param, mapper->heapId);
}

struct FieldGroundAnime *FIELD_G3D_MAPPER_CreateGroundAnime(int slotCount, G3dResource *textureRes, const int *animeIds, int heapId)
{
    int firstId;
    int secondId;
    gFieldG3dMapperGroundAnimeParam.slotCount = slotCount;
    firstId = animeIds[0];
    if (firstId == -1) {
        gFieldG3dMapperGroundAnimeParam.useFlags = gFieldG3dMapperGroundAnimeParam.useFlags & ~0xff;
    } else {
        gFieldG3dMapperGroundAnimeParam.useFlags = (gFieldG3dMapperGroundAnimeParam.useFlags & ~0xff) | 1;
        gFieldG3dMapperGroundAnimeParam.firstId = firstId;
    }
    secondId = animeIds[1];
    if (secondId == -1) {
        gFieldG3dMapperGroundAnimeParam.useFlags = gFieldG3dMapperGroundAnimeParam.useFlags & 0xffff00ff;
    } else {
        gFieldG3dMapperGroundAnimeParam.useFlags = (gFieldG3dMapperGroundAnimeParam.useFlags & 0xffff00ff) | 0x100;
        gFieldG3dMapperGroundAnimeParam.secondId = secondId;
    }
    return FIELD_GROUND_ANIME_Create((struct GroundAnimeDesc *)(&g_021DD9E0), textureRes, (u16)heapId);
}

/*
 * Tail-call thunk: forwards to FIELD_G3D_MAPPER_SlotResTestGroundAnime with no argument change.
 *
 * Addresses are Black-image addresses.
 */
int FIELD_G3D_MAPPER_SlotResHasGroundAnime(FieldG3dMapperSlotRes *res)
{
    return FIELD_G3D_MAPPER_SlotResTestGroundAnime(res);
}

/*
 * Tail-call thunk: forwards to FIELD_G3D_MAPPER_SlotResReadGroundAnime with no argument change.
 *
 * Addresses are Black-image addresses.
 */
struct FieldGroundAnime *FIELD_G3D_MAPPER_SlotResGetGroundAnime(FieldG3dMapperSlotRes *res)
{
    return FIELD_G3D_MAPPER_SlotResReadGroundAnime(res);
}

/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
struct BuildModelMan *FIELD_G3D_MAPPER_SlotResGetBuildModel(FieldG3dMapperSlotRes *res)
{
    return res->buildModel;
}

/*
 * Unlabelled leaf accessor: returns the word at +0x8.
 *
 * Addresses are Black-image addresses.
 */
struct FieldWfbc *FIELD_G3D_MAPPER_SlotResGetWfbc(FieldG3dMapperSlotRes *res)
{
    return res->wfbc;
}

/*
 * Unlabelled leaf accessor: returns the word at +0xC.
 *
 * Addresses are Black-image addresses.
 */
int FIELD_G3D_MAPPER_SlotResGetSlotIndex(FieldG3dMapperSlotRes *res)
{
    return res->slotIndex;
}

/*
 * Loads the 16-bit halfword at +0x10 of the object.
 */
u16 FIELD_G3D_MAPPER_SlotResGetHeapId(FieldG3dMapperSlotRes *res)
{
    return res->heapId;
}

/*
 * Fills a 0x14-byte slot resource record: the ground anime handle from
 * FIELD_GROUND_ANIME_GetAnmEntry(mapper->groundAnime, slotIndex), then the build model, the
 * wfbc, the slot index, and the heap id as a halfword at +0x10.
 * Callee of FIELD_G3D_MAPPER_Setup.  EXACT* (unlabelled follower 0x0218DD38).
 */
void FIELD_G3D_MAPPER_InitSlotRes(FieldG3dMapperSlotRes *res, FieldG3dMapper *mapper, int slotIndex, int heapId)
{
    res->groundAnimeSlot = (struct FieldGroundAnime *)FIELD_GROUND_ANIME_GetAnmEntry(mapper->groundAnime, slotIndex);
    res->buildModel = mapper->buildModel;
    res->wfbc = mapper->wfbc;
    res->slotIndex = slotIndex;
    res->heapId = heapId;
}

void FIELD_G3D_MAPPER_FreeGroundAnimeSlot(struct FieldGroundAnime **slot)
{
    if (*slot != 0) {
        FIELD_GROUND_ANIME_UnbindAnm((struct GroundAnmEntry *)(*slot));
        *slot = 0;
    }
}

void FIELD_G3D_MAPPER_ReleaseGroundAnimeSlot(struct FieldGroundAnime **slot)
{
    if (*slot != 0)
        FIELD_GROUND_ANIME_UnbindAnm((struct GroundAnmEntry *)(*slot));
}

/*
 * Disasm reads its bytes as `.word` because it saves no lr; it is the
 * callee of the thunk at 0x0218DCF4.
 *
 * Addresses are Black-image addresses.
 */
int FIELD_G3D_MAPPER_SlotResTestGroundAnime(FieldG3dMapperSlotRes *res)
{
    return res->groundAnimeSlot != 0;
}

/*
 * Unlabelled leaf getter (no lr save), callee of FIELD_G3D_MAPPER_SlotResGetGroundAnime.
 *
 * Addresses are Black-image addresses.
 */
struct FieldGroundAnime *FIELD_G3D_MAPPER_SlotResReadGroundAnime(FieldG3dMapperSlotRes *res)
{
    return res->groundAnimeSlot;
}

FieldG3dMapperCell *FIELD_G3D_MAPPER_ResetCell(FieldG3dMapperCell *cell)
{
    cell->gridIndex = -1;
    cell->pos.x = 0;
    cell->pos.y = 0;
    cell->pos.z = 0;
    return cell;
}

/*
 * Field setter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
void FIELD_G3D_MAPPER_SetCellGridIndex(FieldG3dMapperCell *cell, u32 gridIndex)
{
    cell->gridIndex = gridIndex;
}

int FIELD_G3D_MAPPER_IsCellUsed(FieldG3dMapperCell *cell)
{
    if (cell->gridIndex != -1) {
        return 1;
    }
    return 0;
}

/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u32 FIELD_G3D_MAPPER_GetCellGridIndex(FieldG3dMapperCell *cell)
{
    return cell->gridIndex;
}

FieldG3dMapperCell *FIELD_G3D_MAPPER_SetCellPos(FieldG3dMapperCell *cell, int x, int y, int z)
{
    cell->pos.x = x;
    cell->pos.y = y;
    cell->pos.z = z;
    return cell;
}

void FIELD_G3D_MAPPER_GetCellPos(FieldG3dMapperCell *cell, VecFx32 *pos)
{
    *pos = cell->pos;
}

void FIELD_G3D_MAPPER_AppendHeightExHits(const FieldG3dMapper *mapper, const VecFx32 *pos, FieldG3dMapperHitList *list)
{
    FieldG3dMapperHitHead head = gFieldG3dMapperDefaultHitHead;
    int added = 0;
    int base = list->count;
    int boxCount = HEIGHT_EX_GetAreaCount((struct HeightExTable *)mapper->heightEx);
    int blockZ;
    int blockX;
    int i;

    blockX = pos->x / 0x10000;
    blockZ = pos->z / 0x10000;
    for (i = 0; i < boxCount; i++) {
        if (HEIGHT_EX_IsPointInAreaAt(blockX, blockZ, (struct HeightExTable *)mapper->heightEx, i)) {
            int hitIndex = base + ++added - 1;
            FieldG3dMapHit *hit;
            if (hitIndex >= 0x10)
                break;
            hit = &list->hits[hitIndex];
            /* stand-in: the 6-byte head is copied as one struct; three halfword stores change the bytes */
            *(FieldG3dMapperHitHead *)hit = head;
            hit->attr = HEIGHT_EX_GetAreaAttr(i, (struct HeightExTable *)mapper->heightEx);
            hit->height = HEIGHT_EX_GetAreaHeight(i, (struct HeightExTable *)mapper->heightEx);
        }
    }
    list->count += (u16)added;
}

void FIELD_G3D_MAPPER_BeginDrawOrder(FieldG3dMapper *mapper)
{
    int scanline;
    MI_CpuFill8(mapper->drawOrder, 0xff, mapper->slotCount);
    mapper->sortedCount = 0;
    mapper->lastDrawnCount = mapper->drawnCount;
    mapper->drawnCount = 0;
    mapper->fitCount = 0;
    if ((int)(HW_VBLANK_COUNT_BUF - mapper->frameStamp) >= 2) {
        mapper->scanline = 0xff;
        mapper->drawBudget = 0;
        return;
    }
    scanline = REG_VCOUNT;
    mapper->scanline = scanline;
    if (scanline > 0xc0 || scanline <= 10) {
        mapper->drawBudget = 0xf000;
        return;
    }
    mapper->drawBudget = 0xf000 - ((scanline - 10) << 10);
}

void FIELD_G3D_MAPPER_StampFrame(FieldG3dMapper *mapper)
{
    mapper->frameStamp = HW_VBLANK_COUNT_BUF;
}

void FIELD_G3D_MAPPER_InsertDrawOrder(FieldG3dMapper *mapper, FieldG3dMap *map, int slotIndex)
{
    int bytes;
    int otherBytes;
    int budgetLeft;
    int otherLeft;
    int i;

    if (FIELD_G3D_MAP_GetRenderObj(map) == 0)
        return;
    if (FIELD_G3D_MAP_IsVisible(map) == 0)
        return;
    FIELD_G3D_MAP_GetTotalBytes(map, (u32 *)(&bytes));
    budgetLeft = mapper->drawBudget - bytes;
    for (i = mapper->sortedCount; i > 0; i--) {
        FIELD_G3D_MAP_GetTotalBytes(mapper->slots[mapper->drawOrder[i - 1]].map, (u32 *)(&otherBytes));
        otherLeft = mapper->drawBudget - otherBytes;
        if (otherLeft >= 0 && budgetLeft >= otherLeft)
            break;
        if (budgetLeft < 0)
            break;
        mapper->drawOrder[i] = mapper->drawOrder[i - 1];
    }
    mapper->drawOrder[i] = slotIndex;
    mapper->sortedCount = mapper->sortedCount + 1;
}

/*
 * Counts how many leading entries of the draw order fit the size budget.
 *
 * Addresses are Black-image addresses.
 */
void FIELD_G3D_MAPPER_CountFittingSlots(FieldG3dMapper *mapper)
{
    int limit;
    int i;
    int sum = 0;
    int bytes;

    mapper->fitCount = 0;
    limit = mapper->lastDrawnCount - (mapper->slotCount - mapper->drawReserve);
    if (limit > 0) {
        for (i = 0; i < limit; i++) {
            u8 *fitCount = &mapper->fitCount;
            int slotIndex = mapper->drawOrder[i];
            if (slotIndex == 0xFF) break;
            FIELD_G3D_MAP_GetTotalBytes(mapper->slots[slotIndex].map, (u32 *)(&bytes));
            sum += bytes;
            if (mapper->drawBudget < sum) break;
            *fitCount = *fitCount + 1;
        }
    }
}

int FIELD_G3D_MAPPER_GetDrawSlot(FieldG3dMapper *mapper, u32 order, int pass, u32 *slotIndex)
{
    u32 v = mapper->drawOrder[order];
    if (v == 0xff)
        return 0;
    *slotIndex = v;
    if (pass == 0) {
        if (order < mapper->fitCount)
            return 1;
    } else if (order >= mapper->fitCount) {
        return 1;
    }
    return 0;
}
