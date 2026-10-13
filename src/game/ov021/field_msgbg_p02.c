/*
 * file:     field_msgbg_p02.c
 * unit:     yes
 * function: func_02193628, func_02193790
 * address:  0x02193628
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_wfbc.c at 0x021938AC (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
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
 *   func_0218DD08  0x0218DD08  thumb ov021
 *   func_0218DD0C  0x0218DD0C  thumb ov021
 *   func_0218DD10  0x0218DD10  thumb ov021
 *   func_0218B974  0x0218B974  thumb ov021
 *   func_0218DCF4  0x0218DCF4  thumb ov021
 *   func_0218DCFC  0x0218DCFC  thumb ov021
 *   func_021A7410  0x021A7410  thumb ov021
 *   func_0207C768  0x0207C768  arm
 *   func_02193924 0x02193924 thumb ov021
 */
struct MapLoader;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef int fx32;

typedef long long s64;

typedef struct Vec {
    fx32 x;
    fx32 y;
    fx32 z;
} Vec;

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

/* Per-loader state: phase 0 idle, 1 start, 2 wait for data, 3 build, 4 finish. */
typedef struct MapLoadState {
    u16 phase;
    u8 gap02[22];
    int flag18;
    int flag1C;
    int flag20;
} MapLoadState;

/* Header of a loaded map block; the offsets are relative to the block start. */
typedef struct MapBlockHeader {
    u8 gap00[4];
    int attrOffset;
    int objectOffset;
    int textureOffset;
    int textureEndOffset;
} MapBlockHeader;

extern int func_02169520(int loader, int stateOut);
extern void func_0216959C(u8 *loader);
extern void func_02169530(unsigned char *loader, int *chunkSizeOut);
extern void func_021695BC(struct MapLoader *loader, int chunkSize);
extern int func_02169620(struct MapLoader *loader);
extern void func_02169528(unsigned char *loader, int *blockDataOut);
extern void func_02169540(unsigned char *loader, unsigned int attrData);
extern int func_02169580(int loader);
extern int func_02169560(unsigned char *loader);
extern int func_02169578(unsigned char *loader);
extern unsigned int func_02169598(u8 *loader);
extern int func_0218DD04(u8 *request);
extern int func_0218DD08(u8 *request);
extern int func_0218DD0C(u8 *request);
extern u16 func_0218DD10(u8 *request);
extern int func_0218B974(int heapId, int loader, void *data, int size);
extern int func_0218DCF4(unsigned int *request);
extern int func_0218DCFC(unsigned int *request);
extern int func_021A7410(u32 requestArg, u32 loaderA, u32 loaderB, u32 loaderC);
extern u32 func_0207C768(u32 dividend, u32 divisor);
int func_02193628(u8 *loader, unsigned int *request);
void func_02193790(CollisionPlane *out, const int *mapData, Vec *pos, fx32 mapSize, fx32 baseHeight);
int func_02193924(u8 *ownerId, void *objectData, int heapId, int loader, int usedCount, int cellX, int cellY, u16 variant);



















/*
 * Map block loader state machine (phases in MapLoadState).  Returns 1 while
 * the load is running and 0 once it has finished.
 *
 * Addresses are Black-image addresses.
 */
int func_02193628(u8 *loader, unsigned int *request)
{
    MapLoadState *state;
    int chunkSize;
    char *blockData;
    int objectOff;
    char *objectData;
    int cellY;
    int cellY0;
    int heapId;
    int ownerId;
    u16 variant;
    MapBlockHeader *header;
    int textureOff;
    int usedCount;
    int quadrant;
    int cellX;
    int cellX0;

    func_0218DD10((u8 *)request);
    func_02169520((int)loader, (int)(&state));
    switch (state->phase) {
    case 1:
        func_0216959C((u8 *)loader);
        func_02169530((unsigned char *)loader, &chunkSize);
        func_021695BC((struct MapLoader *)loader, chunkSize);
        state->phase = 2;
        break;
    case 2:
        if (func_02169620((struct MapLoader *)loader) != 0)
            break;
        state->flag18 = 1;
        state->flag1C = 1;
        state->flag20 = 1;
        state->phase = 3;
        break;
    case 3:
        func_02169528((unsigned char *)loader, (int *)(&blockData));
        header = (MapBlockHeader *)blockData;
        func_02169540((unsigned char *)loader, (unsigned int)((char *)header + header->attrOffset));
        textureOff = header->textureOffset;
        if (textureOff != header->textureEndOffset)
            usedCount = func_0218B974(func_0218DD04((u8 *)request), (int)loader, blockData + textureOff + 4, *(int *)(blockData + textureOff));
        heapId = func_0218DD04((u8 *)request);
        objectData = blockData;
        objectOff = header->objectOffset;
        quadrant = func_0218DD0C((u8 *)request);
        ownerId = func_0218DD08((u8 *)request);
        variant = func_0218DD10((u8 *)request);
        cellX0 = (quadrant % 2) * 4;
        cellY0 = (quadrant / 2) * 4;
        for (cellY = 0; cellY < 4; cellY++) {
            for (cellX = 0; cellX < 4; cellX++) {
                usedCount = func_02193924((u8 *)ownerId, objectData + objectOff, heapId, (int)loader, usedCount, cellX0 + cellX, cellY0 + cellY, variant);
            }
        }
        func_02169580((int)loader);
        if (func_0218DCF4(request))
            func_021A7410(func_0218DCFC((unsigned int *)request), func_02169560((unsigned char *)loader), func_02169578((unsigned char *)loader), func_02169598(loader));
        state->phase = 4;
        break;
    case 4:
        state->phase = 0;
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
