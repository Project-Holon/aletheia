/*
 * file:     unit_021932C0.c
 * unit:     yes
 * function: func_021932C0, func_02193398, func_021933C0, func_02193498, func_021934F8, func_02193544, func_0219361C, func_02193628, func_02193790
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_02169520  0x02169520  thumb ov010
 *   func_0216959C  0x0216959C  thumb ov010
 *   func_02169530  0x02169530  thumb ov010
 *   func_021695BC  0x021695BC  thumb ov010
 *   func_02169620  0x02169620  thumb ov010
 *   func_02169528  0x02169528  thumb ov010
 *   func_02169540  0x02169540  thumb ov010
 *   func_02169580  0x02169580  thumb ov010
 *   func_02169560  0x02169560  thumb ov010
 *   func_02169578  0x02169578  thumb ov010
 *   func_02169598  0x02169598  thumb ov010
 *   func_0218DD04  0x0218DD04  thumb ov021
 *   func_0218B974  0x0218B974  thumb ov021
 *   func_0218DCF4  0x0218DCF4  thumb ov021
 *   func_0218DCFC  0x0218DCFC  thumb ov021
 *   func_021A7410  0x021A7410  thumb ov021
 *   func_021D14C4  0x021D14C4  thumb  ov021
 *   func_0218DD08  0x0218DD08  thumb ov021
 *   func_0218DD0C  0x0218DD0C  thumb ov021
 *   func_0218DD10  0x0218DD10  thumb ov021
 *   func_0207C768  0x0207C768  arm
 *   func_02193924 0x02193924 thumb ov021
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
    u16 pad02;
    u32 bufferOffset;             /* 0x04 */
    u32 loadedBytes;              /* 0x08 */
    u32 totalBytes;               /* 0x0C */
    u32 loadStageA;               /* 0x10 */
    u32 loadStageB;               /* 0x14 */
    u32 loadStageC;               /* 0x18 */
    u32 loadStageD;               /* 0x1C */
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
    s16 gap06;
    u32 attr;
    fx32 height;
    int gap10[0x3C];
    int valid;
} CollisionPlane;

typedef struct Vec {
    fx32 x;
    fx32 y;
    fx32 z;
} Vec;

extern FieldG3dMapLoadState *func_02169520(FieldG3dMap *map, FieldG3dMapLoadState **out);
extern void func_0216959C(FieldG3dMap *map);
extern void func_02169530(FieldG3dMap *map, u32 *out);
extern void func_021695BC(FieldG3dMap *map, u32 member);
extern int func_02169620(FieldG3dMap *map);
extern void func_02169528(FieldG3dMap *map, u8 **out);
extern void func_02169540(FieldG3dMap *map, u32 value);
extern void func_02169580(FieldG3dMap *map);
extern void *func_02169560(FieldG3dMap *map);
extern void *func_02169578(FieldG3dMap *map);
extern FieldG3dMapRenderObj *func_02169598(FieldG3dMap *map);
extern int func_0218DD04(struct FieldG3dMapper *mapper);
extern int func_0218DCF4(struct FieldG3dMapper *mapper);
extern int func_0218DCFC(struct FieldG3dMapper *mapper);
extern int func_0218B974(int buildModel, FieldG3dMap *map, const void *entries, int count);
extern int func_021A7410(int handle, void *modelRes, void *textureRes, FieldG3dMapRenderObj *renderObj);
extern void func_021D14C4(FieldG3dMapHitList *out, int index, const void *plane, FieldG3dMapVec *localPos, int gridSize, int height);
extern u32 func_02082BCC(void *dst, int value, u32 size);
extern struct FieldWfbc *func_0218DD08(struct FieldG3dMapper *mapper);
extern int func_0218DD0C(struct FieldG3dMapper *mapper);
extern u16 func_0218DD10(struct FieldG3dMapper *mapper);
extern int func_02193924(struct FieldWfbc *wfbc, void *attrBuf, int buildModelMan, int mapBlockIndex, int modelNum, int cellX, int cellZ, u16 heapId);
extern u32 func_0207C768(u32 dividend, u32 divisor);

/*
 * From here on: callbacks of the field 3D map block types (see
 * FieldG3dMapType in ../ov010/field_g3d_map_types.h). Each block type has an
 * update callback that loads the block step by step and a query callback that
 * fills the hit list.
 */

/* Update callback, block type with one plane section and a model section. */
int func_021932C0(FieldG3dMap *map, struct FieldG3dMapper *mapper)
{
    FieldG3dMapLoadState *load;
    u32 memberIndex;
    u8 *blockData;
    FieldG3dMapBlockHeader *header;
    int sectionOffset;

    func_02169520(map, &load);
    switch (load->active) {
    case 1:
        func_0216959C(map);
        func_02169530(map, &memberIndex);
        func_021695BC(map, memberIndex);
        load->active = 2;
        break;
    case 2:
        if (func_02169620(map) != 0)
            break;
        load->loadStageC = 1;
        load->loadStageD = 1;
        load->dataReady = 1;
        load->active = 3;
        /* fall through */
    case 3:
        func_02169528(map, &blockData);
        header = (FieldG3dMapBlockHeader *)blockData;
        func_02169540(map, (u32)(blockData + header->modelOffset));
        sectionOffset = header->sectionOffset[1];
        if (sectionOffset != header->sectionOffset[2])
            func_0218B974(func_0218DD04(mapper), map, blockData + sectionOffset + 4, *(int *)(blockData + sectionOffset));
        func_02169580(map);
        if (func_0218DCF4(mapper))
            func_021A7410(func_0218DCFC(mapper), func_02169560(map), func_02169578(map), func_02169598(map));
        load->active = 0;
        return 0;
    }
    return 1;
}

/* Query callback, one plane. */
void func_02193398(FieldG3dMapHitList *hitList, const FieldG3dMapBlockHeader *header, FieldG3dMapVec *localPos, int gridSize, int height)
{
    func_021D14C4(hitList, 0, (const u8 *)header + header->sectionOffset[0], localPos, gridSize, height);
    hitList->count = 1;
}

/* Update callback, block type with two plane sections. */
int func_021933C0(FieldG3dMap *map, struct FieldG3dMapper *mapper)
{
    FieldG3dMapLoadState *load;
    u32 memberIndex;
    u8 *blockData;
    FieldG3dMapBlockHeader *header;
    int sectionOffset;

    func_02169520(map, &load);
    switch (load->active) {
    case 1:
        func_0216959C(map);
        func_02169530(map, &memberIndex);
        func_021695BC(map, memberIndex);
        load->active = 2;
        break;
    case 2:
        if (func_02169620(map) != 0)
            break;
        load->loadStageC = 1;
        load->loadStageD = 1;
        load->dataReady = 1;
        load->active = 3;
        /* fall through */
    case 3:
        func_02169528(map, &blockData);
        header = (FieldG3dMapBlockHeader *)blockData;
        func_02169540(map, (u32)(blockData + header->modelOffset));
        sectionOffset = header->sectionOffset[2];
        if (sectionOffset != header->sectionOffset[3])
            func_0218B974(func_0218DD04(mapper), map, blockData + sectionOffset + 4, *(int *)(blockData + sectionOffset));
        func_02169580(map);
        if (func_0218DCF4(mapper))
            func_021A7410(func_0218DCFC(mapper), func_02169560(map), func_02169578(map), func_02169598(map));
        load->active = 0;
        return 0;
    }
    return 1;
}

/* Query callback, two planes. */
void func_02193498(FieldG3dMapHitList *hitList, const FieldG3dMapBlockHeader *header, FieldG3dMapVec *localPos, int gridSize, int height)
{
    FieldG3dMapHitList buf;

    func_02082BCC(&buf, 0, sizeof(buf));
    func_021D14C4(&buf, 0, (const u8 *)header + header->sectionOffset[0], localPos, gridSize, height);
    func_021D14C4(&buf, 1, (const u8 *)header + header->sectionOffset[1], localPos, gridSize, height);
    *hitList = buf;
    hitList->count = 2;
}

/* Query callback, one plane (builds the list in a local buffer first). */
void func_021934F8(FieldG3dMapHitList *hitList, const FieldG3dMapBlockHeader *header, FieldG3dMapVec *localPos, int gridSize, int height)
{
    FieldG3dMapHitList buf;

    func_02082BCC(&buf, 0, sizeof(buf));
    func_021D14C4(&buf, 0, (const u8 *)header + header->sectionOffset[0], localPos, gridSize, height);
    *hitList = buf;
    hitList->count = 1;
}

/* Update callback, block type without plane sections. */
int func_02193544(FieldG3dMap *map, struct FieldG3dMapper *mapper)
{
    FieldG3dMapLoadState *load;
    u32 memberIndex;
    u8 *blockData;
    FieldG3dMapBlockHeader *header;
    int sectionOffset;

    func_02169520(map, &load);
    switch (load->active) {
    case 1:
        func_0216959C(map);
        func_02169530(map, &memberIndex);
        func_021695BC(map, memberIndex);
        load->active = 2;
        break;
    case 2:
        if (func_02169620(map) != 0)
            break;
        load->loadStageC = 1;
        load->loadStageD = 1;
        load->dataReady = 1;
        load->active = 3;
        /* fall through */
    case 3:
        func_02169528(map, &blockData);
        header = (FieldG3dMapBlockHeader *)blockData;
        func_02169540(map, (u32)(blockData + header->modelOffset));
        sectionOffset = header->sectionOffset[0];
        if (sectionOffset != header->sectionOffset[1])
            func_0218B974(func_0218DD04(mapper), map, blockData + sectionOffset + 4, *(int *)(blockData + sectionOffset));
        func_02169580(map);
        if (func_0218DCF4(mapper))
            func_021A7410(func_0218DCFC(mapper), func_02169560(map), func_02169578(map), func_02169598(map));
        load->active = 0;
        return 0;
    }
    return 1;
}

void func_0219361C(FieldG3dMapHitList *hitList)
{
    hitList->count = 0;
}

/*
 * Update callback, block type with a model section and a placed object
 * section. Returns 1 while the load is running and 0 once it has finished.
 */
int func_02193628(FieldG3dMap *map, struct FieldG3dMapper *mapper)
{
    FieldG3dMapLoadState *state;
    u32 chunkSize;
    u8 *blockData;
    int objectOff;
    u8 *objectData;
    int cellY;
    int cellY0;
    int heapId;
    struct FieldWfbc *ownerId;
    u16 variant;
    FieldG3dMapBlockHeader *header;
    int textureOff;
    int usedCount;
    int quadrant;
    int cellX;
    int cellX0;

    func_0218DD10(mapper);
    func_02169520(map, &state);
    switch (state->active) {
    case 1:
        func_0216959C(map);
        func_02169530(map, &chunkSize);
        func_021695BC(map, chunkSize);
        state->active = 2;
        break;
    case 2:
        if (func_02169620(map) != 0)
            break;
        state->loadStageC = 1;
        state->loadStageD = 1;
        state->dataReady = 1;
        state->active = 3;
        break;
    case 3:
        func_02169528(map, &blockData);
        header = (FieldG3dMapBlockHeader *)blockData;
        func_02169540(map, (u32)((u8 *)header + header->modelOffset));
        textureOff = header->sectionOffset[1];
        if (textureOff != header->sectionOffset[2])
            usedCount = func_0218B974(func_0218DD04(mapper), map, blockData + textureOff + 4, *(int *)(blockData + textureOff));
        heapId = func_0218DD04(mapper);
        objectData = blockData;
        objectOff = header->sectionOffset[0];
        quadrant = func_0218DD0C(mapper);
        ownerId = func_0218DD08(mapper);
        variant = func_0218DD10(mapper);
        cellX0 = (quadrant % 2) * 4;
        cellY0 = (quadrant / 2) * 4;
        for (cellY = 0; cellY < 4; cellY++) {
            for (cellX = 0; cellX < 4; cellX++) {
                usedCount = func_02193924(ownerId, objectData + objectOff, heapId, (int)map, usedCount, cellX0 + cellX, cellY0 + cellY, variant);
            }
        }
        func_02169580(map);
        if (func_0218DCF4(mapper))
            func_021A7410(func_0218DCFC(mapper), func_02169560(map), func_02169578(map), func_02169598(map));
        state->active = 4;
        break;
    case 4:
        state->active = 0;
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
void func_02193790(CollisionPlane *out, const int *mapData, Vec *pos, fx32 mapSize, fx32 baseHeight)
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
