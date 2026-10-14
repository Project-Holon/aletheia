/*
 * file:     field_g3d_map_block.c
 * unit:     yes
 * function: FIELD_G3D_MAP_BLOCK_UpdateOnePlane, FIELD_G3D_MAP_BLOCK_QueryOnePlane, FIELD_G3D_MAP_BLOCK_UpdateTwoPlane, FIELD_G3D_MAP_BLOCK_QueryTwoPlane, FIELD_G3D_MAP_BLOCK_QueryOnePlaneBuffered, FIELD_G3D_MAP_BLOCK_UpdateNoPlane, FIELD_G3D_MAP_BLOCK_QueryClear, FIELD_G3D_MAP_BLOCK_UpdateWfbc, FIELD_G3D_MAP_BLOCK_GetCollisionPlane
 * address:  0x021932C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_msgbg.c at 0x021932C0 and field_msgbg_p02.c (lane FXC2, CL114b: FieldG3dMap block type callbacks, no __FILE__ anchor between 021932C0 and the field_wfbc.c anchor at 021938AC).
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   FIELD_G3D_MAP_GetActiveRef  0x02169520  thumb ov010
 *   FIELD_G3D_MAP_ResetLoadState  0x0216959C  thumb ov010
 *   FIELD_G3D_MAP_GetMemberIndex  0x02169530  thumb ov010
 *   FIELD_G3D_MAP_BeginChunkedLoad  0x021695BC  thumb ov010
 *   FIELD_G3D_MAP_ReadNextChunk  0x02169620  thumb ov010
 *   FIELD_G3D_MAP_GetBuffer  0x02169528  thumb ov010
 *   FIELD_G3D_MAP_SetModelRes  0x02169540  thumb ov010
 *   FIELD_G3D_MAP_BindRenderObj  0x02169580  thumb ov010
 *   FIELD_G3D_MAP_GetModelRes  0x02169560  thumb ov010
 *   FIELD_G3D_MAP_GetTextureRes  0x02169578  thumb ov010
 *   FIELD_G3D_MAP_GetRenderObj  0x02169598  thumb ov010
 *   FIELD_G3D_MAPPER_SlotResGetBuildModel  0x0218DD04  thumb ov021
 *   FIELD_BUILDMODEL_RegisterObjects  0x0218B974  thumb ov021
 *   FIELD_G3D_MAPPER_SlotResHasGroundAnime  0x0218DCF4  thumb ov021
 *   FIELD_G3D_MAPPER_SlotResGetGroundAnime  0x0218DCFC  thumb ov021
 *   FIELD_GROUND_ANIME_BindAnm  0x021A7410  thumb ov021
 *   FIELD_G3D_MAPPER_GetTilePlane  0x021D14C4  thumb  ov021
 *   FIELD_G3D_MAPPER_SlotResGetWfbc  0x0218DD08  thumb ov021
 *   FIELD_G3D_MAPPER_SlotResGetSlotIndex  0x0218DD0C  thumb ov021
 *   FIELD_G3D_MAPPER_SlotResGetHeapId  0x0218DD10  thumb ov021
 *   func_0207C768  0x0207C768  arm
 *   FIELD_WFBC_PatchLandData 0x02193924 thumb ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef int fx32;
typedef long long s64;

#include "../ov010/field_g3d_map_types.h"

struct FieldG3dMapper;
struct FieldWfbc;

/* View of FieldG3dMap from its active flag (0xB0) to the end of its load progress fields (0xD0). */
typedef struct FieldG3dMapLoadState {
    u16 active;                   /* 0x00, load step: 1 start, 2 reading, 3 build, 0 done */
    u16 padding02;
    u32 bufferOffset;             /* 0x04 */
    u32 loadedBytes;              /* 0x08 */
    u32 totalBytes;               /* 0x0C */
    u32 resetFlag;               /* 0x10 */
    u32 spareWord;               /* 0x14 */
    u32 readFinished;               /* 0x18 */
    u32 buildStarted;               /* 0x1C */
    u32 dataReady;                /* 0x20 */
} FieldG3dMapLoadState;

/* Head of a map block file: offsets from the start of the file. */
typedef struct FieldG3dMapBlockHeader {
    u32 reserved00;               /* 0x00 */
    u32 modelOffset;              /* 0x04 */
    u32 sectionOffset[4];         /* 0x08, plane sections, then the placed model section and its end */
} FieldG3dMapBlockHeader;

/* One tile of a map block's collision grid: two triangles sharing a diagonal. */
typedef struct CollisionTile {
    s16 normalA[3];
    s16 normalB[3];
    fx32 distA;
    fx32 distB;
    u32 attr : 31;
    u32 diagonalFlip : 1;
} CollisionTile;

/* Collision plane found under a position. */
typedef struct CollisionPlane {
    s16 normalX;
    s16 normalY;
    s16 normalZ;
    s16 padding06;
    u32 attr;
    fx32 height;
    int reserved10[0x3C];
    int valid;
} CollisionPlane;

extern FieldG3dMapLoadState *FIELD_G3D_MAP_GetActiveRef(FieldG3dMap *map, FieldG3dMapLoadState **out);
extern void FIELD_G3D_MAP_ResetLoadState(FieldG3dMap *map);
extern void FIELD_G3D_MAP_GetMemberIndex(FieldG3dMap *map, u32 *out);
extern void FIELD_G3D_MAP_BeginChunkedLoad(FieldG3dMap *map, u32 member);
extern int FIELD_G3D_MAP_ReadNextChunk(FieldG3dMap *map);
extern void FIELD_G3D_MAP_GetBuffer(FieldG3dMap *map, u8 **out);
extern void FIELD_G3D_MAP_SetModelRes(FieldG3dMap *map, u32 value);
extern void FIELD_G3D_MAP_BindRenderObj(FieldG3dMap *map);
extern void *FIELD_G3D_MAP_GetModelRes(FieldG3dMap *map);
extern void *FIELD_G3D_MAP_GetTextureRes(FieldG3dMap *map);
extern FieldG3dMapRenderObj *FIELD_G3D_MAP_GetRenderObj(FieldG3dMap *map);
extern int FIELD_G3D_MAPPER_SlotResGetBuildModel(struct FieldG3dMapper *mapper);
extern int FIELD_G3D_MAPPER_SlotResHasGroundAnime(struct FieldG3dMapper *mapper);
extern int FIELD_G3D_MAPPER_SlotResGetGroundAnime(struct FieldG3dMapper *mapper);
extern int FIELD_BUILDMODEL_RegisterObjects(int buildModel, FieldG3dMap *map, const void *entries, int count);
extern int FIELD_GROUND_ANIME_BindAnm(int handle, void *modelRes, void *textureRes, FieldG3dMapRenderObj *renderObj);
extern void FIELD_G3D_MAPPER_GetTilePlane(FieldG3dMapHitList *out, int index, const void *plane, FieldG3dMapVec *localPos, int gridSize, int height);
extern u32 MI_CpuFill8(void *dst, int value, u32 size);
extern struct FieldWfbc *FIELD_G3D_MAPPER_SlotResGetWfbc(struct FieldG3dMapper *mapper);
extern int FIELD_G3D_MAPPER_SlotResGetSlotIndex(struct FieldG3dMapper *mapper);
extern u16 FIELD_G3D_MAPPER_SlotResGetHeapId(struct FieldG3dMapper *mapper);
extern int FIELD_WFBC_PatchLandData(struct FieldWfbc *wfbc, void *attrBuf, int buildModelMan, int mapBlockIndex, int modelNum, int cellX, int cellZ, u16 heapId);
extern u32 func_0207C768(u32 dividend, u32 divisor);

/*
 * From here on: callbacks of the field 3D map block types (see
 * FieldG3dMapType in ../ov010/field_g3d_map_types.h). Each block type has an
 * update callback that loads the block step by step and a query callback that
 * fills the hit list.
 */

/* Update callback, block type with one plane section and a model section. */
int FIELD_G3D_MAP_BLOCK_UpdateOnePlane(FieldG3dMap *map, struct FieldG3dMapper *mapper)
{
    FieldG3dMapLoadState *load;
    u32 memberIndex;
    u8 *blockData;
    FieldG3dMapBlockHeader *header;
    int sectionOffset;

    FIELD_G3D_MAP_GetActiveRef(map, &load);
    switch (load->active) {
    case 1:
        FIELD_G3D_MAP_ResetLoadState(map);
        FIELD_G3D_MAP_GetMemberIndex(map, &memberIndex);
        FIELD_G3D_MAP_BeginChunkedLoad(map, memberIndex);
        load->active = 2;
        break;
    case 2:
        if (FIELD_G3D_MAP_ReadNextChunk(map) != 0)
            break;
        load->readFinished = 1;
        load->buildStarted = 1;
        load->dataReady = 1;
        load->active = 3;
        /* fall through */
    case 3:
        FIELD_G3D_MAP_GetBuffer(map, &blockData);
        header = (FieldG3dMapBlockHeader *)blockData;
        FIELD_G3D_MAP_SetModelRes(map, (u32)(blockData + header->modelOffset));
        sectionOffset = header->sectionOffset[1];
        if (sectionOffset != header->sectionOffset[2])
            FIELD_BUILDMODEL_RegisterObjects(FIELD_G3D_MAPPER_SlotResGetBuildModel(mapper), map, blockData + sectionOffset + 4, *(int *)(blockData + sectionOffset));
        FIELD_G3D_MAP_BindRenderObj(map);
        if (FIELD_G3D_MAPPER_SlotResHasGroundAnime(mapper))
            FIELD_GROUND_ANIME_BindAnm(FIELD_G3D_MAPPER_SlotResGetGroundAnime(mapper), FIELD_G3D_MAP_GetModelRes(map), FIELD_G3D_MAP_GetTextureRes(map), FIELD_G3D_MAP_GetRenderObj(map));
        load->active = 0;
        return 0;
    }
    return 1;
}

/* Query callback, one plane. */
void FIELD_G3D_MAP_BLOCK_QueryOnePlane(FieldG3dMapHitList *hitList, const FieldG3dMapBlockHeader *header, FieldG3dMapVec *localPos, int gridSize, int height)
{
    FIELD_G3D_MAPPER_GetTilePlane(hitList, 0, (const u8 *)header + header->sectionOffset[0], localPos, gridSize, height);
    hitList->count = 1;
}

/* Update callback, block type with two plane sections. */
int FIELD_G3D_MAP_BLOCK_UpdateTwoPlane(FieldG3dMap *map, struct FieldG3dMapper *mapper)
{
    FieldG3dMapLoadState *load;
    u32 memberIndex;
    u8 *blockData;
    FieldG3dMapBlockHeader *header;
    int sectionOffset;

    FIELD_G3D_MAP_GetActiveRef(map, &load);
    switch (load->active) {
    case 1:
        FIELD_G3D_MAP_ResetLoadState(map);
        FIELD_G3D_MAP_GetMemberIndex(map, &memberIndex);
        FIELD_G3D_MAP_BeginChunkedLoad(map, memberIndex);
        load->active = 2;
        break;
    case 2:
        if (FIELD_G3D_MAP_ReadNextChunk(map) != 0)
            break;
        load->readFinished = 1;
        load->buildStarted = 1;
        load->dataReady = 1;
        load->active = 3;
        /* fall through */
    case 3:
        FIELD_G3D_MAP_GetBuffer(map, &blockData);
        header = (FieldG3dMapBlockHeader *)blockData;
        FIELD_G3D_MAP_SetModelRes(map, (u32)(blockData + header->modelOffset));
        sectionOffset = header->sectionOffset[2];
        if (sectionOffset != header->sectionOffset[3])
            FIELD_BUILDMODEL_RegisterObjects(FIELD_G3D_MAPPER_SlotResGetBuildModel(mapper), map, blockData + sectionOffset + 4, *(int *)(blockData + sectionOffset));
        FIELD_G3D_MAP_BindRenderObj(map);
        if (FIELD_G3D_MAPPER_SlotResHasGroundAnime(mapper))
            FIELD_GROUND_ANIME_BindAnm(FIELD_G3D_MAPPER_SlotResGetGroundAnime(mapper), FIELD_G3D_MAP_GetModelRes(map), FIELD_G3D_MAP_GetTextureRes(map), FIELD_G3D_MAP_GetRenderObj(map));
        load->active = 0;
        return 0;
    }
    return 1;
}

/* Query callback, two planes. */
void FIELD_G3D_MAP_BLOCK_QueryTwoPlane(FieldG3dMapHitList *hitList, const FieldG3dMapBlockHeader *header, FieldG3dMapVec *localPos, int gridSize, int height)
{
    FieldG3dMapHitList buf;

    MI_CpuFill8(&buf, 0, sizeof(buf));
    FIELD_G3D_MAPPER_GetTilePlane(&buf, 0, (const u8 *)header + header->sectionOffset[0], localPos, gridSize, height);
    FIELD_G3D_MAPPER_GetTilePlane(&buf, 1, (const u8 *)header + header->sectionOffset[1], localPos, gridSize, height);
    *hitList = buf;
    hitList->count = 2;
}

/* Query callback, one plane (builds the list in a local buffer first). */
void FIELD_G3D_MAP_BLOCK_QueryOnePlaneBuffered(FieldG3dMapHitList *hitList, const FieldG3dMapBlockHeader *header, FieldG3dMapVec *localPos, int gridSize, int height)
{
    FieldG3dMapHitList buf;

    MI_CpuFill8(&buf, 0, sizeof(buf));
    FIELD_G3D_MAPPER_GetTilePlane(&buf, 0, (const u8 *)header + header->sectionOffset[0], localPos, gridSize, height);
    *hitList = buf;
    hitList->count = 1;
}

/* Update callback, block type without plane sections. */
int FIELD_G3D_MAP_BLOCK_UpdateNoPlane(FieldG3dMap *map, struct FieldG3dMapper *mapper)
{
    FieldG3dMapLoadState *load;
    u32 memberIndex;
    u8 *blockData;
    FieldG3dMapBlockHeader *header;
    int sectionOffset;

    FIELD_G3D_MAP_GetActiveRef(map, &load);
    switch (load->active) {
    case 1:
        FIELD_G3D_MAP_ResetLoadState(map);
        FIELD_G3D_MAP_GetMemberIndex(map, &memberIndex);
        FIELD_G3D_MAP_BeginChunkedLoad(map, memberIndex);
        load->active = 2;
        break;
    case 2:
        if (FIELD_G3D_MAP_ReadNextChunk(map) != 0)
            break;
        load->readFinished = 1;
        load->buildStarted = 1;
        load->dataReady = 1;
        load->active = 3;
        /* fall through */
    case 3:
        FIELD_G3D_MAP_GetBuffer(map, &blockData);
        header = (FieldG3dMapBlockHeader *)blockData;
        FIELD_G3D_MAP_SetModelRes(map, (u32)(blockData + header->modelOffset));
        sectionOffset = header->sectionOffset[0];
        if (sectionOffset != header->sectionOffset[1])
            FIELD_BUILDMODEL_RegisterObjects(FIELD_G3D_MAPPER_SlotResGetBuildModel(mapper), map, blockData + sectionOffset + 4, *(int *)(blockData + sectionOffset));
        FIELD_G3D_MAP_BindRenderObj(map);
        if (FIELD_G3D_MAPPER_SlotResHasGroundAnime(mapper))
            FIELD_GROUND_ANIME_BindAnm(FIELD_G3D_MAPPER_SlotResGetGroundAnime(mapper), FIELD_G3D_MAP_GetModelRes(map), FIELD_G3D_MAP_GetTextureRes(map), FIELD_G3D_MAP_GetRenderObj(map));
        load->active = 0;
        return 0;
    }
    return 1;
}

void FIELD_G3D_MAP_BLOCK_QueryClear(FieldG3dMapHitList *hitList)
{
    hitList->count = 0;
}

/*
 * Update callback, block type with a model section and a placed object
 * section. Returns 1 while the load is running and 0 once it has finished.
 */
int FIELD_G3D_MAP_BLOCK_UpdateWfbc(FieldG3dMap *map, struct FieldG3dMapper *mapper)
{
    FieldG3dMapLoadState *load;
    u32 memberIndex;
    u8 *blockData;
    int landDataOffset;
    u8 *landData;
    int cellY;
    int cellY0;
    int buildModel;
    struct FieldWfbc *wfbc;
    u16 heapId;
    FieldG3dMapBlockHeader *header;
    int buildObjectsOffset;
    int modelNum;
    int slotIndex;
    int cellX;
    int cellX0;

    FIELD_G3D_MAPPER_SlotResGetHeapId(mapper);
    FIELD_G3D_MAP_GetActiveRef(map, &load);
    switch (load->active) {
    case 1:
        FIELD_G3D_MAP_ResetLoadState(map);
        FIELD_G3D_MAP_GetMemberIndex(map, &memberIndex);
        FIELD_G3D_MAP_BeginChunkedLoad(map, memberIndex);
        load->active = 2;
        break;
    case 2:
        if (FIELD_G3D_MAP_ReadNextChunk(map) != 0)
            break;
        load->readFinished = 1;
        load->buildStarted = 1;
        load->dataReady = 1;
        load->active = 3;
        break;
    case 3:
        FIELD_G3D_MAP_GetBuffer(map, &blockData);
        header = (FieldG3dMapBlockHeader *)blockData;
        FIELD_G3D_MAP_SetModelRes(map, (u32)((u8 *)header + header->modelOffset));
        buildObjectsOffset = header->sectionOffset[1];
        if (buildObjectsOffset != header->sectionOffset[2])
            modelNum = FIELD_BUILDMODEL_RegisterObjects(FIELD_G3D_MAPPER_SlotResGetBuildModel(mapper), map, blockData + buildObjectsOffset + 4, *(int *)(blockData + buildObjectsOffset));
        buildModel = FIELD_G3D_MAPPER_SlotResGetBuildModel(mapper);
        landData = blockData;
        landDataOffset = header->sectionOffset[0];
        slotIndex = FIELD_G3D_MAPPER_SlotResGetSlotIndex(mapper);
        wfbc = FIELD_G3D_MAPPER_SlotResGetWfbc(mapper);
        heapId = FIELD_G3D_MAPPER_SlotResGetHeapId(mapper);
        cellX0 = (slotIndex % 2) * 4;
        cellY0 = (slotIndex / 2) * 4;
        for (cellY = 0; cellY < 4; cellY++) {
            for (cellX = 0; cellX < 4; cellX++) {
                modelNum = FIELD_WFBC_PatchLandData(wfbc, landData + landDataOffset, buildModel, (int)map, modelNum, cellX0 + cellX, cellY0 + cellY, heapId);
            }
        }
        FIELD_G3D_MAP_BindRenderObj(map);
        if (FIELD_G3D_MAPPER_SlotResHasGroundAnime(mapper))
            FIELD_GROUND_ANIME_BindAnm(FIELD_G3D_MAPPER_SlotResGetGroundAnime(mapper), FIELD_G3D_MAP_GetModelRes(map), FIELD_G3D_MAP_GetTextureRes(map), FIELD_G3D_MAP_GetRenderObj(map));
        load->active = 4;
        break;
    case 4:
        load->active = 0;
        return 0;
    }
    return 1;
}

static inline fx32 FX_MUL(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}

static inline void PlaneSetNormal(CollisionPlane *plane, int x, int y, int z)
{
    plane->normalX = x;
    plane->normalY = y;
    plane->normalZ = z;
}

/*
 * Find the collision plane under pos in a map block: pick the tile of the
 * grid, then the triangle of the tile, and compute the plane height at pos.
 */
void FIELD_G3D_MAP_BLOCK_GetCollisionPlane(CollisionPlane *out, const int *mapData, FieldG3dMapVec *pos, fx32 mapSize, fx32 baseHeight)
{
    fx32 half = mapSize / 2;
    fx32 z = pos->z + half;
    fx32 x = pos->x + half;
    int tileFracX = x % 0x10000;
    int tileFracZ = z % 0x10000;
    CollisionTile *tile = (CollisionTile *)((char *)mapData + mapData[2] + 4) + (x / 0x10000 + ((mapSize >> 12) / 16) * (z / 0x10000));
    fx32 planeDist;

    if (tile->diagonalFlip == 0) {
        if (tileFracX + tileFracZ < 0x10000) {
            PlaneSetNormal(out, tile->normalA[0], tile->normalA[1], -tile->normalA[2]);
            planeDist = tile->distA;
        } else {
            PlaneSetNormal(out, tile->normalB[0], tile->normalB[1], -tile->normalB[2]);
            planeDist = tile->distB;
        }
    } else {
        if (tileFracX > tileFracZ) {
            PlaneSetNormal(out, tile->normalA[0], tile->normalA[1], -tile->normalA[2]);
            planeDist = tile->distA;
        } else {
            PlaneSetNormal(out, tile->normalB[0], tile->normalB[1], -tile->normalB[2]);
            planeDist = tile->distB;
        }
    }
    {
        fx32 normalY = out->normalY;
        fx32 dotZ = FX_MUL(out->normalZ, pos->z);
        fx32 dotX = FX_MUL(out->normalX, pos->x);
        out->attr = tile->attr;
        out->height = baseHeight + func_0207C768(-(planeDist + (dotX + dotZ)), normalY);
    }
    out->valid = 1;
}
