/*
 * file:     field_g3d_tile_plane.c
 * unit:     yes
 * function: FIELD_G3D_MAPPER_GetTilePlane
 * address:  0x021D14C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Boundary audit (wave 16): FIELD_G3D_MAPPER_GetTilePlane 021D14C4..021D166F with its tables gTileNormalTable and gTilePlaneDistTable (0x021DB9A0, 0x021DC158). Cut from scrcmd_misc.c: nothing else in that file uses these tables or the function, and its only callers are in field_g3d_map_block.c at 021932C0, so it is not a script command. Original file name unknown (the FIELD_G3D_MAPPER_ prefix belongs to field_g3d_mapper.c, which lies at 0218C9E8).
 *
 * symbols:
 *   gTileNormalTable     0x021DB9A0  data
 *   gTilePlaneDistTable     0x021DC158  data
 *   FX_Div  0x0207C768  arm
 */
#include "../arm9/script_vm_types.h"
#include "fieldmap_types.h"

#include "../types.h"

/* Packed collision tile of a map block (8 bytes of packed indices plus the attribute word). */
typedef struct PackedTile {
    u16 type : 2;             /* 0 one plane, 2 two planes (split record), other: flat */
    u16 normalIndex : 14;     /* normal triple index in gTileNormalTable */
    u16 distIndex;            /* plane distance index in gTilePlaneDistTable; split record index for type 2 */
    u32 attr : 31;
    u32 diagonalFlip : 1;
} PackedTile;

/* Two planes of a split tile, one per triangle. */
typedef struct PackedTileSplit {
    u16 type : 2;
    u16 normalIndexA : 14;
    u16 normalIndexB;
    u16 distIndexA;
    u16 distIndexB;
} PackedTileSplit;

/* Collision grid of a map block: width and height in tiles, then the tiles, then the split records. */
typedef struct PackedTileMap {
    u16 width;
    u16 height;
    PackedTile tiles[1];
} PackedTileMap;

/* Normal component of the packed normal table, and one (x, y, z) triple of it. */
typedef short NormComp;

typedef struct NormTriple {
    NormComp x;
    NormComp y;
    NormComp z;
} NormTriple;

/* Plane found under a position (fields of the first 12 bytes of CollisionPlane in field_g3d_map_block.c). */
typedef struct TileSurface {
    NormComp normalX;
    NormComp normalY;
    NormComp normalZ;
    NormComp padding06;
    u32 attr;
    fx32 height;
} TileSurface;

#define NRM(i) ((NormComp *)gTileNormalTable)[i]

extern u32 FX_Div(u32 a, u32 b);

void FIELD_G3D_MAPPER_GetTilePlane(TileSurface *out, int idx, PackedTileMap *map, VecFx32 *pos, fx32 size, fx32 base);

extern NormTriple gTileNormalTable[];

extern const fx32 gTilePlaneDistTable[];

static inline fx32 FX_MUL(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}

static inline void TileSurface_SetNormal(TileSurface *surface, int x, int y, int z)
{
    surface->normalX = x;
    surface->normalY = y;
    surface->normalZ = z;
}

/*
 * The a/0/0/8 grid tile reader (see docs/notes/func_021D14C4_tile_record_reader.c.txt):
 * picks the tile under pos, writes its surface normal, attribute word and
 * solved height into out[idx].
 *
 * Shape notes, each one measured:
 * - the normal table is read through an NormComp pointer cast of a differently
 *   typed object, so mwcc cannot prove it disjoint from out: the setter's
 *   right-to-left arguments then stay as z, y, x temporaries (y spilled) and
 *   the pool word is reloaded per access. A plain NormComp array sinks the loads.
 * - the height table is const (its load is scheduled above the z store).
 * - the tile record is read through a volatile pointer: the image reloads
 *   the norm halfword after the type test instead of reusing the type load;
 *   no non-volatile spelling (casts, unions, other access paths, const)
 *   stopped mwcc from CSE-ing the two halfword loads.
 * - the row index is x/0x10000 + w * (z/0x10000) in that operand order;
 *   p (= &out[idx]) is live into the tail, where only the x read uses it.
 */
void FIELD_G3D_MAPPER_GetTilePlane(TileSurface *out, int idx, PackedTileMap *map, VecFx32 *pos, fx32 size, fx32 base)
{
    fx32 half = size / 2;
    fx32 z = pos->z + half;
    fx32 x = pos->x + half;
    int fracX = x % 0x10000;
    int fracZ = z % 0x10000;
    int tileIndex = x / 0x10000 + ((size >> 12) / 16) * (z / 0x10000);
    volatile PackedTile *tile = &map->tiles[tileIndex];
    fx32 planeDist;
    TileSurface *surface;
    u8 tileType = tile->type;

    if (tileType == 0) {
        int normalOffset = tile->normalIndex * 3;
        int distIndex = tile->distIndex;
        TileSurface_SetNormal(surface = &out[idx], NRM(normalOffset), NRM(normalOffset + 1), -NRM(normalOffset + 2));
        planeDist = gTilePlaneDistTable[distIndex];
    } else if (tileType == 2) {
        PackedTileSplit *split = (PackedTileSplit *)(map->tiles + map->width * map->height) + tile->distIndex;
        int normalOffset;
        int distIndex;
        if (tile->diagonalFlip == 0) {
            if (fracX + fracZ < 0x10000) {
                normalOffset = split->normalIndexA * 3;
                distIndex = split->distIndexA;
            } else {
                normalOffset = split->normalIndexB * 3;
                distIndex = split->distIndexB;
            }
        } else {
            if (fracX > fracZ) {
                normalOffset = split->normalIndexA * 3;
                distIndex = split->distIndexA;
            } else {
                normalOffset = split->normalIndexB * 3;
                distIndex = split->distIndexB;
            }
        }
        TileSurface_SetNormal(surface = &out[idx], NRM(normalOffset), NRM(normalOffset + 1), -NRM(normalOffset + 2));
        planeDist = gTilePlaneDistTable[distIndex];
    } else {
        TileSurface_SetNormal(surface = &out[idx], 0, 0x1000, 0);
        planeDist = 0;
    }
    {
        fx32 normalY = out[idx].normalY;
        fx32 dotZ = FX_MUL(out[idx].normalZ, pos->z);
        fx32 dotX = FX_MUL(surface->normalX, pos->x);
        out[idx].attr = tile->attr;
        out[idx].height = base + FX_Div(-(planeDist + (dotX + dotZ)), normalY);
    }
}
