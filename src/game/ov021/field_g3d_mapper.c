/*
 * file:     field_g3d_mapper.c
 * unit:     yes
 * function: func_0218C9E8, func_0218CA4C, func_0218CA78, func_0218CB34, func_0218CC34, func_0218CC64, func_0218CD20, func_0218CEE0, func_0218CEE4, func_0218D05C, func_0218D0D8, func_0218D104, func_0218D13C, func_0218D158, func_0218D168, func_0218D1D0, func_0218D304, func_0218D444, func_0218D570, func_0218D7A8, func_0218D934, func_0218D970, func_0218D980, func_0218D9B8, func_0218D9C8, func_0218D9E8, func_0218DAEC, func_0218DBAC, func_0218DBD4, func_0218DC04, func_0218DC4C, func_0218DC5C, func_0218DC6C, func_0218DC70, func_0218DC74, func_0218DC84, func_0218DCF4, func_0218DCFC, func_0218DD04, func_0218DD08, func_0218DD0C, func_0218DD10, func_0218DD14, func_0218DD38, func_0218DD4C, func_0218DD5C, func_0218DD6C, func_0218DD70, func_0218DD80, func_0218DD84, func_0218DD98, func_0218DD9C, func_0218DDA4, func_0218DDB4, func_0218DE78, func_0218DEF0, func_0218DEFC, func_0218DF80, func_0218DFE0
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
 *   func_020120F4  0x020120F4  thumb
 *   func_02188C80  0x02188C80  thumb
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02046DB8  0x02046DB8  arm
 *   func_020470A8  0x020470A8  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_02169510  0x02169510  thumb
 *   d_021DD9EC     0x021DD9EC  data  ov021  a4
 *   func_021938AC  0x021938AC  thumb ov021
 *   func_021C05D4  0x021C05D4  thumb ov021
 *   func_021C0674  0x021C0674  thumb  ov021
 *   func_021938D4  0x021938D4  thumb  ov021
 *   func_0216932C  0x0216932C  thumb ov010
 *   func_02169520  0x02169520  thumb  ov010
 *   func_02169308  0x02169308  thumb  ov010
 *   FX_Div  0x0207C768  arm
 *   func_021A73DC  0x021A73DC  thumb  ov021
 *   func_02169500  0x02169500  thumb ov010
 *   func_02169354  0x02169354  thumb ov010
 *   func_02159BF4  0x02159BF4  thumb
 *   func_02159BF8  0x02159BF8  thumb
 *   func_02159BFC  0x02159BFC  thumb
 *   func_02159C20  0x02159C20  thumb
 *   func_02159C00  0x02159C00  thumb
 *   func_02012974  0x02012974  thumb
 *   d_021D3DDC     0x021D3DDC  data
 *   func_02169148  0x02169148  thumb  ov010
 *   func_0216937C  0x0216937C  thumb  ov010
 *   func_021693B4  0x021693B4  thumb  ov010
 *   func_021693C4  0x021693C4  thumb  ov010
 *   func_021693CC  0x021693CC  thumb ov010
 *   func_021693BC  0x021693BC  thumb ov010
 *   func_021693A0  0x021693A0  thumb ov010
 *   func_0216928C  0x0216928C  thumb ov010
 *   func_021A73C0  0x021A73C0  thumb ov021
 *   func_02022040  0x02022040  thumb
 *   func_021694FC  0x021694FC  thumb ov010
 *   func_021694F8  0x021694F8  thumb ov010
 *   func_021694D4  0x021694D4  thumb ov010
 *   func_02169470  0x02169470  thumb ov010
 *   func_02169800  0x02169800  thumb ov010
 *   func_021AB100  0x021AB100  thumb ov021
 *   func_02169848  0x02169848  thumb  ov010
 *   func_021697E0  0x021697E0  thumb ov010
 *   func_02193B04  0x02193B04  thumb  ov021
 *   d_021DD9E0     0x021DD9E0  data ov021 a2
 *   g_021DD9E0     0x021DD9E0  data ov021 a2
 *   func_021A7360  0x021A7360  thumb ov021
 *   func_021A7404  0x021A7404  thumb  ov021
 *   func_021A7418  0x021A7418  thumb
 *   d_021D3DD4     0x021D3DD4  data a2
 *   func_021C0688  0x021C0688  thumb ov021
 *   func_021C068C  0x021C068C  thumb ov021
 *   func_021C06B4  0x021C06B4  thumb ov021
 *   func_021C06A8  0x021C06A8  thumb ov021
 *   func_02169598  0x02169598  thumb ov010
 *   func_02169538  0x02169538  thumb ov010
 *   func_0218B754  0x0218B754  thumb  ov021
 *   func_0218B7F8  0x0218B7F8  thumb  ov021
 *   func_0218B83C  0x0218B83C  thumb  ov021
 *   func_0218B88C  0x0218B88C  thumb  ov021
 *   func_0218B9FC  0x0218B9FC  thumb  ov021
 *   func_0218BB04  0x0218BB04  thumb  ov021
 *   _u32_div_f     0x0209C2B0  arm
 */
#include "field_g3d_mapper_types.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
typedef long long      fx64;

#define HW_VBLANK_COUNT_BUF (*(volatile u32 *)0x02FFFC3C)
#define REG_VCOUNT          (*(volatile u16 *)0x04000006)

struct MapMatrix;
struct FieldBuildModel;
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

extern void MI_CpuFill8(void *dst, u8 value, u32 size);
extern int FX_Div(int a, int b);
extern int FX_ModS32(int a, int b);
extern struct GameSystem *func_02188C80(FieldMap *fieldMap);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern u32 func_02012974(const struct GameData *gameData);
extern void *func_02030734(u16 heapId, u32 size, u32 clear, const void *site, u32 line);
extern u32 func_020307B0(void *p);
extern G3dResource *func_02046DB8(u32 archiveId, u32 memberId);
extern u32 func_020470A8(G3dResource *res);
extern int func_020470D0(G3dResource *res);
extern void func_02046EFC(G3dResource *res);
extern void *func_02046F48(G3dResource *res);
extern G3dResTexView *func_0206E964(void *file);
extern void func_02022040(u16 *palette, int count, const u8 *tintTable);
extern u16 func_02159BF4(const struct MapMatrix *matrix);
extern u16 func_02159BF8(const struct MapMatrix *matrix);
extern int func_02159BFC(const struct MapMatrix *matrix);
extern u32 *func_02159C20(struct MapMatrix *matrix);
extern void func_02159C00(struct MapMatrix *matrix, u8 width, u8 height);

extern FieldG3dMap *func_02169148(const FieldG3dMapConfig *config, u32 heapId);
extern void func_0216928C(FieldG3dMap *map);
extern void func_02169308(FieldG3dMap *map);
extern int func_0216932C(FieldG3dMap *map);
extern int func_02169354(FieldG3dMap *map, struct G3dCamera *camera);
extern void func_0216937C(FieldG3dMap *map, int archiveId, int heapId);
extern void func_021693A0(FieldG3dMap *map);
extern void func_021693B4(FieldG3dMap *map, G3dResource *textureRes);
extern void func_021693BC(FieldG3dMap *map);
extern void func_021693C4(FieldG3dMap *map, FieldG3dMapModelSet *placedModels);
extern void func_021693CC(FieldG3dMap *map);
extern void func_02169470(FieldG3dMap *map, u32 memberIndex);
extern void func_021694D4(FieldG3dMap *map);
extern void func_021694F8(FieldG3dMap *map, u16 visible);
extern u16 func_021694FC(FieldG3dMap *map);
extern void func_02169500(FieldG3dMap *map, const VecFx32 *pos);
extern void func_02169510(FieldG3dMap *map, VecFx32 *dst);
extern u16 *func_02169520(FieldG3dMap *map, u16 **out);
extern void func_02169538(FieldG3dMap *map, int *out);
extern FieldG3dMapRenderObj *func_02169598(FieldG3dMap *map);
extern int func_021697E0(FieldG3dMap *map);
extern void func_02169800(FieldG3dMapHitList *out, FieldG3dMap *map, const VecFx32 *pos, u32 gridSize);
extern void func_02169848(u32 *plane, FieldG3dMap *map, const VecFx32 *pos, u32 gridSize);

extern int func_021AB100(u32 attr);
extern struct FieldGroundAnime *func_021A7360(const FieldG3dMapperGroundAnimeParam *param, G3dResource *textureRes, u32 heapId);
extern struct FieldGroundAnime *func_021A7404(struct FieldGroundAnime *groundAnime, int slotIndex);
extern void func_021A7418(struct FieldGroundAnime *slot);
extern void func_021A73C0(struct FieldGroundAnime *groundAnime);
extern void func_021A73DC(struct FieldGroundAnime *groundAnime);
extern struct FieldWfbc *func_021938AC(u32 heapId);
extern u32 func_021938D4(struct FieldWfbc *wfbc);
extern int func_02193B04(struct FieldWfbc *wfbc, void *wfbcData, u32 param, u32 heapId);
extern struct HeightEx *func_021C05D4(int capacity, u8 heapId);
extern void func_021C0674(struct HeightEx *heightEx);
extern u32 func_021C0688(struct HeightEx *heightEx);
extern int func_021C068C(int blockX, int blockZ, struct HeightEx *heightEx, u8 index);
extern int func_021C06A8(u8 index, struct HeightEx *heightEx);
extern int func_021C06B4(u8 index, struct HeightEx *heightEx);
extern struct FieldBuildModel *func_0218B754(u16 heapId, FieldG3dMapper *mapper, u16 param);
extern void func_0218B7F8(struct FieldBuildModel *buildModel);
extern void func_0218B83C(struct FieldBuildModel *buildModel);
extern void func_0218B88C(struct FieldBuildModel *buildModel);
extern void func_0218B9FC(struct FieldBuildModel *buildModel, FieldG3dMap *map);
extern FieldG3dMapModelSet *func_0218BB04(struct FieldBuildModel *buildModel);

extern const char d_021DD9EC[];
extern FieldG3dMapType d_021D3DDC[];
extern FieldG3dMapperGroundAnimeParam d_021DD9E0;
/* Second name of the same address: the image loads the call argument through its own pool word. */
extern FieldG3dMapperGroundAnimeParam g_021DD9E0;
extern FieldG3dMapperHitHead d_021D3DD4;

FieldG3dMapper *func_0218C9E8(u16 heapId, u16 buildModelParam);
int func_0218CA4C(FieldG3dMapper *mapper);
void func_0218CA78(FieldG3dMapper *mapper);
int func_0218CB34(FieldG3dMapper *mapper);
void func_0218CC34(FieldG3dMapper *mapper);
void func_0218CC64(FieldG3dMapper *mapper, struct G3dCamera *camera, int pass);
int func_0218CD20(FieldMap *fieldMap, FieldG3dMapper *mapper, struct MapMatrix *matrix);
struct HeightEx *func_0218CEE0(FieldG3dMapper *mapper);
void func_0218CEE4(FieldG3dMapper *mapper, const FieldG3dMapperSetup *setup, const u8 *tintTable);
void func_0218D05C(FieldG3dMapper *mapper);
int func_0218D0D8(G3dResource *res, const u8 *tintTable);
void func_0218D104(FieldG3dMapper *mapper, const FieldG3dMapperSetup *setup, const u8 *tintTable);
void func_0218D13C(FieldG3dMapper *mapper);
void func_0218D158(FieldG3dMapper *mapper, const VecFx32 *pos);
int func_0218D168(FieldG3dMapper *mapper);
void func_0218D1D0(FieldG3dMapper *mapper, const VecFx32 *focusPos, FieldG3dMapperCell *cells);
void func_0218D304(FieldG3dMapper *mapper, const VecFx32 *focusPos, FieldG3dMapperCell *cells);
void func_0218D444(FieldG3dMapper *mapper, const VecFx32 *focusPos, FieldG3dMapperCell *cells);
void func_0218D570(FieldG3dMapper *mapper, const VecFx32 *focusPos, FieldG3dMapperCell *cells);
int func_0218D7A8(FieldG3dMapper *mapper, FieldG3dMapperCell *newCells);
int func_0218D934(u32 count, int cellSize, int pos);
int func_0218D970(u32 count, int cellSize, int pos);
int func_0218D980(u32 count, int cellSize, int pos);
FieldG3dMapHit *func_0218D9B8(FieldG3dMapHit *hit);
void func_0218D9C8(FieldG3dMapperHitList *list);
int func_0218D9E8(FieldG3dMapper *mapper, const VecFx32 *pos, FieldG3dMapperHitList *list);
int func_0218DAEC(FieldG3dMapper *mapper, const VecFx32 *pos, FieldG3dMapHit *outHit);
int func_0218DBAC(FieldG3dMapper *mapper, int slotIndex, const VecFx32 *pos, FieldG3dMapHit *outHit);
int func_0218DBD4(FieldG3dMapper *mapper, int slotIndex);
int func_0218DC04(FieldG3dMapper *mapper, const VecFx32 *pos);
void func_0218DC4C(FieldG3dMapper *mapper, const VecFx32 *offset);
void func_0218DC5C(FieldG3dMapper *mapper, VecFx32 *offset);
struct FieldBuildModel *func_0218DC6C(FieldG3dMapper *mapper);
struct FieldWfbc *func_0218DC70(FieldG3dMapper *mapper);
int func_0218DC74(FieldG3dMapper *mapper, void *wfbcData, u32 param);
struct FieldGroundAnime *func_0218DC84(int slotCount, G3dResource *textureRes, const int *animeIds, int heapId);
int func_0218DCF4(FieldG3dMapperSlotRes *res);
struct FieldGroundAnime *func_0218DCFC(FieldG3dMapperSlotRes *res);
struct FieldBuildModel *func_0218DD04(FieldG3dMapperSlotRes *res);
struct FieldWfbc *func_0218DD08(FieldG3dMapperSlotRes *res);
int func_0218DD0C(FieldG3dMapperSlotRes *res);
u16 func_0218DD10(FieldG3dMapperSlotRes *res);
void func_0218DD14(FieldG3dMapperSlotRes *res, FieldG3dMapper *mapper, int slotIndex, int heapId);
void func_0218DD38(struct FieldGroundAnime **slot);
void func_0218DD4C(struct FieldGroundAnime **slot);
int func_0218DD5C(FieldG3dMapperSlotRes *res);
struct FieldGroundAnime *func_0218DD6C(FieldG3dMapperSlotRes *res);
FieldG3dMapperCell *func_0218DD70(FieldG3dMapperCell *cell);
void func_0218DD80(FieldG3dMapperCell *cell, u32 gridIndex);
int func_0218DD84(FieldG3dMapperCell *cell);
u32 func_0218DD98(FieldG3dMapperCell *cell);
FieldG3dMapperCell *func_0218DD9C(FieldG3dMapperCell *cell, int x, int y, int z);
void func_0218DDA4(FieldG3dMapperCell *cell, VecFx32 *pos);
void func_0218DDB4(const FieldG3dMapper *mapper, const VecFx32 *pos, FieldG3dMapperHitList *list);
void func_0218DE78(FieldG3dMapper *mapper);
void func_0218DEF0(FieldG3dMapper *mapper);
void func_0218DEFC(FieldG3dMapper *mapper, FieldG3dMap *map, int slotIndex);
void func_0218DF80(FieldG3dMapper *mapper);
int func_0218DFE0(FieldG3dMapper *mapper, u32 order, int pass, u32 *slotIndex);

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

FieldG3dMapper *func_0218C9E8(u16 heapId, u16 buildModelParam)
{
    FieldG3dMapper *mapper = func_02030734(heapId, 0x74, 1, d_021DD9EC, 0xf9);
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
    mapper->buildModel = func_0218B754(mapper->heapId, mapper, buildModelParam);
    mapper->wfbc = func_021938AC(heapId);
    mapper->heightEx = func_021C05D4(0x10, (u8)heapId);
    return mapper;
}

int func_0218CA4C(FieldG3dMapper *mapper)
{
    func_021C0674(mapper->heightEx);
    func_0218D05C(mapper);
    func_021938D4(mapper->wfbc);
    if (mapper->buildModel != 0) {
        func_0218B7F8(mapper->buildModel);
        mapper->buildModel = 0;
    }
    return func_020307B0(mapper);
}

void func_0218CA78(FieldG3dMapper *mapper)
{
    int i;
    int cellX;
    int cellZ;

    if (mapper->blockGrid == 0)
        return;
    for (i = 0; i < mapper->slotCount; i++)
        func_0218DD70(&mapper->cells[i]);
    switch (mapper->layout) {
    case 0:
        func_0218D1D0(mapper, &mapper->focusPos, mapper->cells);
        break;
    case 1:
    default:
        func_0218D304(mapper, &mapper->focusPos, mapper->cells);
        break;
    case 2:
        func_0218D444(mapper, &mapper->focusPos, mapper->cells);
        break;
    case 3:
        func_0218D570(mapper, &mapper->focusPos, mapper->cells);
        break;
    }
    func_0218D7A8(mapper, mapper->cells);
    for (i = 0; i < mapper->slotCount; i++)
        func_0216932C(mapper->slots[i].map);
    cellX = FX_Div(mapper->focusPos.x, mapper->cellSize);
    cellZ = FX_Div(mapper->focusPos.z, mapper->cellSize);
    mapper->focusCell = (cellX >> 12) + (cellZ >> 12) * mapper->gridWidth;
}

int func_0218CB34(FieldG3dMapper *mapper)
{
    int i;
    int busy;
    int cellX;
    int cellZ;
    u16 *active;

    if (mapper->blockGrid == 0)
        return 0;
    for (i = 0; i < mapper->slotCount; i++)
        func_0218DD70(&mapper->cells[i]);
    switch (mapper->layout) {
    case 0:
        func_0218D1D0(mapper, &mapper->focusPos, mapper->cells);
        break;
    case 1:
    default:
        func_0218D304(mapper, &mapper->focusPos, mapper->cells);
        break;
    case 2:
        func_0218D444(mapper, &mapper->focusPos, mapper->cells);
        break;
    case 3:
        func_0218D570(mapper, &mapper->focusPos, mapper->cells);
        break;
    }
    func_0218D7A8(mapper, mapper->cells);
    busy = 0;
    func_0218DE78(mapper);
    for (i = 0; i < mapper->slotCount; i++) {
        func_02169520(mapper->slots[i].map, &active);
        if (*active == 1)
            busy = 1;
        func_02169308(mapper->slots[i].map);
        func_0218DEFC(mapper, mapper->slots[i].map, i);
    }
    func_0218DF80(mapper);
    cellX = FX_Div(mapper->focusPos.x, mapper->cellSize);
    cellZ = FX_Div(mapper->focusPos.z, mapper->cellSize);
    mapper->focusCell = (cellX >> 12) + (cellZ >> 12) * mapper->gridWidth;
    func_0218B83C(mapper->buildModel);
    if (mapper->groundAnime != 0)
        func_021A73DC(mapper->groundAnime);
    return busy;
}

void func_0218CC34(FieldG3dMapper *mapper)
{
    int i;
    if (mapper->blockGrid != 0) {
        for (i = 0; i < mapper->slotCount; i++)
            func_02169308(mapper->slots[i].map);
        func_0218DEF0(mapper);
    }
}

void func_0218CC64(FieldG3dMapper *mapper, struct G3dCamera *camera, int pass)
{
    VecFx32 mapPos;
    VecFx32 drawPos;
    u32 slotIndex;
    int i;
    u8 *drawnCount;

    if (pass == 0 && mapper->drawReserve == 0)
        return;
    for (i = 0; i < mapper->slotCount; i++) {
        if (func_0218DFE0(mapper, i, pass, &slotIndex)) {
            int drawn;
            drawnCount = &mapper->drawnCount;
            func_02169510(mapper->slots[slotIndex].map, &mapPos);
            drawPos.x = mapPos.x + mapper->originOffset.x;
            drawPos.y = mapPos.y + mapper->originOffset.y;
            drawPos.z = mapPos.z + mapper->originOffset.z;
            func_02169500(mapper->slots[slotIndex].map, &drawPos);
            drawn = func_02169354(mapper->slots[slotIndex].map, camera);
            func_02169500(mapper->slots[slotIndex].map, &mapPos);
            if (drawn != 0 && mapper->drawnCount < mapper->slotCount)
                *drawnCount = *drawnCount + 1;
        }
    }
    if (pass == 1)
        func_0218B88C(mapper->buildModel);
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
int func_0218CD20(FieldMap *fieldMap, FieldG3dMapper *mapper, struct MapMatrix *matrix)
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

    matrixWidth = func_02159BF4(matrix);
    matrixDepth = func_02159BF8(matrix);
    matrixCount = func_02159BFC(matrix);
    matrixCells = func_02159C20(matrix);
    newWidth = mapper->gridWidth + matrixWidth;
    newDepth = mapper->gridDepth;
    newCount = mapper->blockCount + matrixCount;
    if (newDepth != matrixDepth)
        return 0;
    if (newCount > 900 || newWidth > 30 || newDepth > 30)
        return 0;

    newGrid = func_02030734((u16)((mapper->heapId & 0x7FFF) | 0x8000), newCount * 4, 0, d_021DD9EC, 0x25F);
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
        if (func_0218DD84(&mapper->slots[row].cell)) {
            oldWidth = mapper->gridWidth;
            slot = &mapper->slots[row];
            cellRow = slot->cell.gridIndex;
            slot->cell.gridIndex = cellRow % oldWidth + cellRow / oldWidth * newWidth;
        }
    }
    mapper->gridWidth = newWidth;
    mapper->gridDepth = newDepth;
    mapper->blockCount = newCount;
    func_02159C00((struct MapMatrix *)func_02012974(func_020120F4(func_02188C80(fieldMap))), newWidth, newDepth);
    func_020307B0(newGrid);
    return 1;
}

/*
 * Unlabelled 4-byte getter (ldr r0, [r0, #0x70]; bx lr), a leaf of
 * ov043 func_021F36C0.
 */
struct HeightEx *func_0218CEE0(FieldG3dMapper *mapper)
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
void func_0218CEE4(FieldG3dMapper *mapper, const FieldG3dMapperSetup *setup, const u8 *tintTable)
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
    func_0218D104(mapper, setup, tintTable);
    mapper->groundAnime = func_0218DC84(mapper->slotCount, mapper->textureRes, setup->groundAnimeIds, mapper->heapId);
    config.bufferSize = setup->blockBufferSize;
    config.texVramSize = 0;
    config.typeTable = d_021D3DDC;
    config.userParam = 0;
    config.chunkSize = 0x800;
    config.placementCountA = 0x20;
    config.placementCountB = 0;
    config.extraParam0 = 0x1000000;
    config.extraParam1 = 0x400000;
    mapper->slots = func_02030734(mapper->heapId, mapper->slotCount * sizeof(FieldG3dMapperSlot), 1, d_021DD9EC, 0x306);
    mapper->cells = func_02030734(mapper->heapId, mapper->slotCount * sizeof(FieldG3dMapperCell), 1, d_021DD9EC, 0x307);
    mapper->drawOrder = func_02030734(mapper->heapId, mapper->slotCount, 1, d_021DD9EC, 0x308);
    for (i = 0; i < mapper->slotCount; i++) {
        func_0218DD70(&mapper->slots[i].cell);
        func_0218DD14(&mapper->slots[i].res, mapper, i, mapper->heapId);
        config.userParam = (u32)&mapper->slots[i].res;
        map = func_02169148(&config, mapper->heapId);
        mapper->slots[i].map = map;
        func_0216937C(map, mapper->mapArchiveId, mapper->heapId);
        if (mapper->textureRes != 0)
            func_021693B4(map, mapper->textureRes);
        func_021693C4(map, func_0218BB04(mapper->buildModel));
    }
}

void func_0218D05C(FieldG3dMapper *mapper)
{
    int i;

    if (mapper->slots != 0) {
        for (i = 0; i < mapper->slotCount; i++) {
            func_021693CC(mapper->slots[i].map);
            func_021693BC(mapper->slots[i].map);
            func_021693A0(mapper->slots[i].map);
            func_0216928C(mapper->slots[i].map);
            func_0218DD38(&mapper->slots[i].res.groundAnimeSlot);
        }
        func_020307B0(mapper->slots);
        func_020307B0(mapper->cells);
        func_020307B0(mapper->drawOrder);
        mapper->cells = 0;
        mapper->slots = 0;
        mapper->drawOrder = 0;
        mapper->slotCount = 0;
    }
    if (mapper->groundAnime != 0) {
        func_021A73C0(mapper->groundAnime);
        mapper->groundAnime = 0;
    }
    func_0218D13C(mapper);
}

/*
 * 2026-10-01: MATCH, capped only by the call to func_02022040 (arm9, Thumb,
 * unlabelled, no witness outside this function). It is a ~64+ byte RGB555
 * pixel converter (luma weights 76/151/29 over a lookup table); filing it
 * as an arm9 witness would lift this to EXACT.
 */
int func_0218D0D8(G3dResource *res, const u8 *tintTable)
{
    G3dResTexView *tex = func_0206E964(func_02046F48(res));
    if (tex != 0) {
        u32 size = tex->plttSize << 3;
        u32 offset = tex->plttDataOffset;
        if (tintTable != 0)
            func_02022040((u16 *)((u8 *)tex + offset), size >> 1, tintTable);
        return 1;
    }
    return 0;
}

void func_0218D104(FieldG3dMapper *mapper, const FieldG3dMapperSetup *setup, const u8 *tintTable)
{
    u32 mode = setup->textureMode;
    if (mode != 0) {
        if (mode == 1) {
            const u32 *textureIds = setup->textureIds;
            mapper->textureRes = func_02046DB8(textureIds[0], textureIds[1]);
            if (tintTable != 0)
                func_0218D0D8(mapper->textureRes, tintTable);
            func_020470A8(mapper->textureRes);
        }
    } else {
        mapper->textureRes = 0;
    }
}

void func_0218D13C(FieldG3dMapper *mapper)
{
    if (mapper->textureRes != 0) {
        func_020470D0(mapper->textureRes);
        func_02046EFC(mapper->textureRes);
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
void func_0218D158(FieldG3dMapper *mapper, const VecFx32 *pos)
{
    SetVecFx32(&mapper->focusPos, pos->x, pos->y, pos->z);
}

int func_0218D168(FieldG3dMapper *mapper)
{
    VecFx32 slotPos;
    unsigned int i;

    for (i = 0; i < mapper->slotCount; i++) {
        if (func_021694FC(mapper->slots[i].map)) {
            int half;
            int centerX;
            int centerZ;
            int minX;
            int maxX;
            int minZ;
            int maxZ;
            func_02169510(mapper->slots[i].map, &slotPos);
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

void func_0218D1D0(FieldG3dMapper *mapper, const VecFx32 *focusPos, FieldG3dMapperCell *cells)
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
            func_0218DD80(cells + cellIndex, cellIndex);
            func_0218DD9C(cells + cellIndex, base + FX_Mul(cellX << 12, cellSize), y, base + FX_Mul(cellZ << 12, cellSize));
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
void func_0218D304(FieldG3dMapper *mapper, const VecFx32 *focusPos, FieldG3dMapperCell *cells){
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
        firstCol = func_0218D934(mapper->cols, cellSize, focusPos->x);
    else
        firstCol = func_0218D970(mapper->cols, cellSize, focusPos->x);
    if (mapper->rows % 2 == 0)
        firstRow = func_0218D934(mapper->rows, cellSize, focusPos->z);
    else
        firstRow = func_0218D970(mapper->rows, cellSize, focusPos->z);
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
            func_0218DD80(cells + cellIndex, gridCol + gridRow * gridWidth);
            x = FX_Mul(gridCol << 12, cellSize);
            func_0218DD9C(cells + cellIndex, base + x, 0, base + y);
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
void func_0218D444(FieldG3dMapper *mapper, const VecFx32 *focusPos, FieldG3dMapperCell *cells){
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
    firstCol = func_0218D980(mapper->cols, cellSize, focusPos->x);
    firstRow = func_0218D980(mapper->rows, cellSize, focusPos->z);
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
                func_0218DD80(cell, cellIndex + wrapRow * gridWidth);
                func_0218DD9C(cell, base + (int)(((long long)(gridCol << 12) * scale64 + 0x800LL) >> 12), 0, base + y);
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
void func_0218D570(FieldG3dMapper *mapper, const VecFx32 *focusPos, FieldG3dMapperCell *cells)
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
        func_0218DD80(&cells[n], gridIndex);
        func_0218DD9C(&cells[n], half + FX_Mul(col << 12, cellSize), y, half + FX_Mul(row << 12, cellSize));
    }
    for (i = 0; i < layerCells; i++, n++) {
        y = FX_Mul((layer + dir) << 12, layerHeight);
        col = i % mapper->gridWidth;
        row = i / mapper->gridWidth;
        gridIndex = (layer + dir) * layerCells + row * gridWidth + col;
        if (gridIndex >= mapper->blockCount)
            gridIndex = -1;
        func_0218DD80(&cells[n], gridIndex);
        func_0218DD9C(&cells[n], half + FX_Mul(col << 12, cellSize), y, half + FX_Mul(row << 12, cellSize));
    }
}

/*
 * Reconciles the slots' live blocks with a freshly laid-out cell array
 * (func_0218CA78's tail): slots whose grid index survives move to the new
 * position, the rest are hidden and released; new cells then take a free
 * slot.  Returns 1 when any free slot was claimed.
 */
int func_0218D7A8(FieldG3dMapper *mapper, FieldG3dMapperCell *newCells)
{
    int placed;
    int moved;
    int changed;
    int result;
    int i;
    int j;

    result = 0;
    for (i = 0; i < mapper->slotCount; i++) {
        if (func_0218DD84(&mapper->slots[i].cell)) {
            u32 gridIndex;
            moved = 0;
            gridIndex = func_0218DD98(&mapper->slots[i].cell);
            for (j = 0; j < mapper->slotCount; j++) {
                if (gridIndex == func_0218DD98(&newCells[j]) && !moved) {
                    VecFx32 cellPos;
                    func_0218DDA4(&newCells[j], &cellPos);
                    func_02169500(mapper->slots[i].map, &cellPos);
                    func_0218DD70(&newCells[j]);
                    moved = 1;
                }
            }
            if (!moved) {
                func_0218DD70(&mapper->slots[i].cell);
                func_021694F8(mapper->slots[i].map, 0);
                func_0218B9FC(mapper->buildModel, mapper->slots[i].map);
                func_0218DD4C(&mapper->slots[i].res.groundAnimeSlot);
                func_021694D4(mapper->slots[i].map);
            }
        }
    }
    changed = 0;
    for (i = 0; i < mapper->slotCount; i++) {
        if (func_0218DD84(&newCells[i])) {
            placed = 0;
            for (j = 0; j < mapper->slotCount; j++) {
                if (!func_0218DD84(&mapper->slots[j].cell) && !placed) {
                    int mapModelIndex = mapper->blockGrid[func_0218DD98(&newCells[i])].mapModelIndex;
                    VecFx32 cellPos;
                    func_0218DDA4(&newCells[i], &cellPos);
                    if (mapModelIndex != -1) {
                        func_02169470(mapper->slots[j].map, mapModelIndex);
                        func_02169500(mapper->slots[j].map, &cellPos);
                        func_021694F8(mapper->slots[j].map, 1);
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

int func_0218D934(u32 count, int cellSize, int pos)
{
    int first = -(int)((count >> 1) - 1);
    int cell = pos / cellSize;
    if (pos % cellSize < FX_Div(cellSize, 0x2000))
        first += cell - 1;
    else
        first += cell;
    return first;
}

int func_0218D970(u32 count, int cellSize, int pos)
{
    int first = -(int)(count >> 1);
    first += pos / cellSize;
    return first;
}

int func_0218D980(u32 count, int cellSize, int pos)
{
    int first = (FX_Div(pos, cellSize) >> 12) - (count >> 1);
    if ((count & 1) == 0) {
        int rem = FX_ModS32(pos, cellSize);
        if (FX_Div(cellSize, 0x2000) < rem)
            first++;
    }
    return first;
}

FieldG3dMapHit *func_0218D9B8(FieldG3dMapHit *hit)
{
    hit->kind = 0;
    hit->index = 0;
    hit->flags = 0;
    hit->depth = 0;
    hit->height = 0;
    return hit;
}

void func_0218D9C8(FieldG3dMapperHitList *list)
{
    int i;
    for (i = 0; i < 16; i++)
        func_0218D9B8(&list->hits[i]);
    list->count = 0;
}

int func_0218D9E8(FieldG3dMapper *mapper, const VecFx32 *pos, FieldG3dMapperHitList *list)
{
    VecFx32 slotPos;
    FieldG3dMapHitList slotHits;
    int half;
    int i;
    u32 n;

    if (mapper->blockGrid == 0)
        return 0;
    func_0218D9C8(list);
    n = 0;
    half = mapper->cellSize >> 1;
    for (i = 0; i < mapper->slotCount; i++) {
        if (func_021694FC(mapper->slots[i].map) == 1) {
            int centerX;
            int centerZ;
            int minX;
            int maxX;
            int minZ;
            int maxZ;
            func_02169510(mapper->slots[i].map, &slotPos);
            centerX = slotPos.x;
            centerZ = slotPos.z;
            minX = centerX - half;
            minZ = centerZ - half;
            maxX = centerX + half;
            maxZ = centerZ + half;
            if (pos->x >= minX && pos->x < maxX && pos->z >= minZ && pos->z < maxZ) {
                u32 j;
                func_02169800(&slotHits, mapper->slots[i].map, pos, mapper->cellSize);
                if (slotHits.count != 0) {
                    if (n + slotHits.count >= 16)
                        break;
                    for (j = 0; j < slotHits.count; j++) {
                        list->hits[n + j].kind = slotHits.hits[j].kind;
                        list->hits[n + j].index = slotHits.hits[j].index;
                        list->hits[n + j].flags = slotHits.hits[j].flags;
                        list->hits[n + j].depth = slotHits.hits[j].depth;
                        list->hits[n + j].height = slotHits.hits[j].height;
                    }
                    n += slotHits.count;
                }
            }
        }
    }
    list->count = n;
    func_0218DDB4(mapper, pos, list);
    if (list->count != 0)
        return 1;
    return 0;
}

int func_0218DAEC(FieldG3dMapper *mapper, const VecFx32 *pos, FieldG3dMapHit *outHit)
{
    FieldG3dMapperHitList hitList;
    int i;
    int best;
    int minDistance;

    func_0218D9B8(outHit);
    if (func_0218D9E8(mapper, pos, &hitList) == 0)
        return 0;
    if (hitList.count == 1) {
        *outHit = hitList.hits[0];
        return 1;
    }
    best = 0;
    minDistance = 0x00FFF000;
    for (i = 0; i < hitList.count; i++) {
        if (func_021AB100(hitList.hits[i].depth)) {
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

int func_0218DBAC(FieldG3dMapper *mapper, int slotIndex, const VecFx32 *pos, FieldG3dMapHit *outHit)
{
    u32 plane[0x41];
    func_02169848(plane, mapper->slots[slotIndex].map, pos, mapper->cellSize);
    outHit->depth = plane[2];
    outHit->height = plane[3];
    return 1;
}

int func_0218DBD4(FieldG3dMapper *mapper, int slotIndex)
{
    if (mapper->blockGrid == 0)
        return 0;
    if (func_021694FC(mapper->slots[slotIndex].map) == 0)
        return 0;
    return func_021697E0(mapper->slots[slotIndex].map);
}

/*
 * Unlabelled ov021 leaf (a `.word` run in the listing, no lr save), the
 * sole blocker of ov010 func_021638CC. Returns 1 (outside) unless the
 * grid is present, not in layout 2, and pos.x/pos.z fall inside the
 * gridWidth*cell by gridDepth*cell rectangle.
 */
int func_0218DC04(FieldG3dMapper *mapper, const VecFx32 *pos)
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
 * Filed as the only blocker of ov052 func_021F38F0.
 */
void func_0218DC4C(FieldG3dMapper *mapper, const VecFx32 *offset)
{
    mapper->originOffset = *offset;
}

void func_0218DC5C(FieldG3dMapper *mapper, VecFx32 *offset)
{
    *offset = mapper->originOffset;
}

/*
 * Loads the 32-bit word at byte +0x64 of the object.
 */
struct FieldBuildModel *func_0218DC6C(FieldG3dMapper *mapper)
{
    return mapper->buildModel;
}

/*
 * Loads the 32-bit word at byte +0x6c of the object.
 */
struct FieldWfbc *func_0218DC70(FieldG3dMapper *mapper)
{
    return mapper->wfbc;
}

int func_0218DC74(FieldG3dMapper *mapper, void *wfbcData, u32 param)
{
    return func_02193B04(mapper->wfbc, wfbcData, param, mapper->heapId);
}

struct FieldGroundAnime *func_0218DC84(int slotCount, G3dResource *textureRes, const int *animeIds, int heapId)
{
    int firstId;
    int secondId;
    d_021DD9E0.slotCount = slotCount;
    firstId = animeIds[0];
    if (firstId == -1) {
        d_021DD9E0.useFlags = d_021DD9E0.useFlags & ~0xff;
    } else {
        d_021DD9E0.useFlags = (d_021DD9E0.useFlags & ~0xff) | 1;
        d_021DD9E0.firstId = firstId;
    }
    secondId = animeIds[1];
    if (secondId == -1) {
        d_021DD9E0.useFlags = d_021DD9E0.useFlags & 0xffff00ff;
    } else {
        d_021DD9E0.useFlags = (d_021DD9E0.useFlags & 0xffff00ff) | 0x100;
        d_021DD9E0.secondId = secondId;
    }
    return func_021A7360(&g_021DD9E0, textureRes, (u16)heapId);
}

/*
 * Tail-call thunk: forwards to func_0218DD5C with no argument change.
 *
 * Addresses are Black-image addresses.
 */
int func_0218DCF4(FieldG3dMapperSlotRes *res)
{
    return func_0218DD5C(res);
}

/*
 * Tail-call thunk: forwards to func_0218DD6C with no argument change.
 *
 * Addresses are Black-image addresses.
 */
struct FieldGroundAnime *func_0218DCFC(FieldG3dMapperSlotRes *res)
{
    return func_0218DD6C(res);
}

/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
struct FieldBuildModel *func_0218DD04(FieldG3dMapperSlotRes *res)
{
    return res->buildModel;
}

/*
 * Unlabelled leaf accessor: returns the word at +0x8.
 *
 * Addresses are Black-image addresses.
 */
struct FieldWfbc *func_0218DD08(FieldG3dMapperSlotRes *res)
{
    return res->wfbc;
}

/*
 * Unlabelled leaf accessor: returns the word at +0xC.
 *
 * Addresses are Black-image addresses.
 */
int func_0218DD0C(FieldG3dMapperSlotRes *res)
{
    return res->slotIndex;
}

/*
 * Loads the 16-bit halfword at +0x10 of the object.
 */
u16 func_0218DD10(FieldG3dMapperSlotRes *res)
{
    return res->heapId;
}

/*
 * Fills a 0x14-byte slot resource record: the ground anime handle from
 * func_021A7404(mapper->groundAnime, slotIndex), then the build model, the
 * wfbc, the slot index, and the heap id as a halfword at +0x10.
 * Callee of func_0218CEE4.  EXACT* (unlabelled follower 0x0218DD38).
 */
void func_0218DD14(FieldG3dMapperSlotRes *res, FieldG3dMapper *mapper, int slotIndex, int heapId)
{
    res->groundAnimeSlot = func_021A7404(mapper->groundAnime, slotIndex);
    res->buildModel = mapper->buildModel;
    res->wfbc = mapper->wfbc;
    res->slotIndex = slotIndex;
    res->heapId = heapId;
}

void func_0218DD38(struct FieldGroundAnime **slot)
{
    if (*slot != 0) {
        func_021A7418(*slot);
        *slot = 0;
    }
}

void func_0218DD4C(struct FieldGroundAnime **slot)
{
    if (*slot != 0)
        func_021A7418(*slot);
}

/*
 * Disasm reads its bytes as `.word` because it saves no lr; it is the
 * callee of the thunk at 0x0218DCF4.
 *
 * Addresses are Black-image addresses.
 */
int func_0218DD5C(FieldG3dMapperSlotRes *res)
{
    return res->groundAnimeSlot != 0;
}

/*
 * Unlabelled leaf getter (no lr save), callee of func_0218DCFC.
 *
 * Addresses are Black-image addresses.
 */
struct FieldGroundAnime *func_0218DD6C(FieldG3dMapperSlotRes *res)
{
    return res->groundAnimeSlot;
}

FieldG3dMapperCell *func_0218DD70(FieldG3dMapperCell *cell)
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
void func_0218DD80(FieldG3dMapperCell *cell, u32 gridIndex)
{
    cell->gridIndex = gridIndex;
}

int func_0218DD84(FieldG3dMapperCell *cell)
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
u32 func_0218DD98(FieldG3dMapperCell *cell)
{
    return cell->gridIndex;
}

FieldG3dMapperCell *func_0218DD9C(FieldG3dMapperCell *cell, int x, int y, int z)
{
    cell->pos.x = x;
    cell->pos.y = y;
    cell->pos.z = z;
    return cell;
}

void func_0218DDA4(FieldG3dMapperCell *cell, VecFx32 *pos)
{
    *pos = cell->pos;
}

void func_0218DDB4(const FieldG3dMapper *mapper, const VecFx32 *pos, FieldG3dMapperHitList *list)
{
    FieldG3dMapperHitHead head = d_021D3DD4;
    int added = 0;
    int base = list->count;
    int boxCount = func_021C0688(mapper->heightEx);
    int blockZ;
    int blockX;
    int i;

    blockX = pos->x / 0x10000;
    blockZ = pos->z / 0x10000;
    for (i = 0; i < boxCount; i++) {
        if (func_021C068C(blockX, blockZ, mapper->heightEx, i)) {
            int hitIndex = base + ++added - 1;
            FieldG3dMapHit *hit;
            if (hitIndex >= 0x10)
                break;
            hit = &list->hits[hitIndex];
            /* stand-in: the 6-byte head is copied as one struct; three halfword stores change the bytes */
            *(FieldG3dMapperHitHead *)hit = head;
            hit->depth = func_021C06B4(i, mapper->heightEx);
            hit->height = func_021C06A8(i, mapper->heightEx);
        }
    }
    list->count += (u16)added;
}

void func_0218DE78(FieldG3dMapper *mapper)
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

void func_0218DEF0(FieldG3dMapper *mapper)
{
    mapper->frameStamp = HW_VBLANK_COUNT_BUF;
}

void func_0218DEFC(FieldG3dMapper *mapper, FieldG3dMap *map, int slotIndex)
{
    int bytes;
    int otherBytes;
    int budgetLeft;
    int otherLeft;
    int i;

    if (func_02169598(map) == 0)
        return;
    if (func_021694FC(map) == 0)
        return;
    func_02169538(map, &bytes);
    budgetLeft = mapper->drawBudget - bytes;
    for (i = mapper->sortedCount; i > 0; i--) {
        func_02169538(mapper->slots[mapper->drawOrder[i - 1]].map, &otherBytes);
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
void func_0218DF80(FieldG3dMapper *mapper)
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
            func_02169538(mapper->slots[slotIndex].map, &bytes);
            sum += bytes;
            if (mapper->drawBudget < sum) break;
            *fitCount = *fitCount + 1;
        }
    }
}

int func_0218DFE0(FieldG3dMapper *mapper, u32 order, int pass, u32 *slotIndex)
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
