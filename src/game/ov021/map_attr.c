/*
 * file:     map_attr.c
 * unit:     yes
 * function: MAP_ATTR_GetAt, MAP_ATTR_GetTerrainId, MAP_ATTR_GetFlags, MAP_ATTR_IsPresent, MAP_ATTR_IsBlocked, MAP_ATTR_IsTallGrass, MAP_ATTR_IsLedgeNorth, MAP_ATTR_IsLedgeSouth, MAP_ATTR_IsLedgeWest, MAP_ATTR_IsLedgeEast, MAP_ATTR_IsNoInteract, MAP_ATTR_IsCameraStep, MAP_ATTR_IsGimmickD6, MAP_ATTR_IsGimmickD7, MAP_ATTR_IsGimmickD8, MAP_ATTR_IsGimmickE2, MAP_ATTR_IsGimmickD9, MAP_ATTR_IsGimmickDA, MAP_ATTR_IsGimmickDB, MAP_ATTR_IsGimmickDC, MAP_ATTR_IsGimmickDD, MAP_ATTR_IsGimmickDE, MAP_ATTR_IsGimmickDF, MAP_ATTR_IsGimmickE0, MAP_ATTR_IsGimmickE1, MAP_ATTR_IsGrassSingle, MAP_ATTR_IsGrassDouble, MAP_ATTR_IsTallGrassSingle, MAP_ATTR_IsTallGrassDouble, MAP_ATTR_IsAnySingleGrass, MAP_ATTR_IsAnyDoubleGrass, MAP_ATTR_IsAnyGrass, MAP_ATTR_IsHole, MAP_ATTR_IsLongHopEdge, MAP_ATTR_IsRippleWater, MAP_ATTR_IsSplashWater, MAP_ATTR_IsWaterfall, MAP_ATTR_IsSnow, MAP_ATTR_IsDeepSnow, MAP_ATTR_IsSnowTile, MAP_ATTR_IsForcedSlide, MAP_ATTR_IsIce, MAP_ATTR_IsSplashWaterB, MAP_ATTR_IsSandD, MAP_ATTR_IsSandVariant, MAP_ATTR_IsAnySand, MAP_ATTR_IsFishableWater, MAP_ATTR_IsPuddle, MAP_ATTR_IsMud, MAP_ATTR_IsElectricFloor, MAP_ATTR_IsElectricPanel, MAP_ATTR_IsDeepSand, MAP_ATTR_IsDeepSandB, MAP_ATTR_IsSand, MAP_ATTR_IsGrassSingleB, MAP_ATTR_IsGrassDoubleB, MAP_ATTR_IsMirrorFloor, MAP_ATTR_IsNoDash, MAP_ATTR_IsSlopeYA, MAP_ATTR_IsSlopeYB, MAP_ATTR_IsSlopeXB, MAP_ATTR_IsSlopeXA, MAP_ATTR_IsRoughGround, MAP_ATTR_IsGrassSingleC, MAP_ATTR_IsGrassDoubleC, MAP_ATTR_GetEncounterEffectKind, MAP_ATTR_GetBattleBackground, MAP_ATTR_IsHopTransition
 * address:  0x021AB0D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_effect.c at 0x021AB0D4: no __FILE__ anchor: 0x021AB0D4..0x021AB5AC read and test
 * map attribute values (value in bits 0..15, flags in bits 16..31) and are called from about 15 files;
 * file name inferred from the MAPATTR module.
 *
 * symbols:
 *   FIELD_G3D_MAPPER_QueryNearestHit  0x0218DAEC  thumb
 *   data_021D8EA0  0x021D8EA0  data
 *   data_021D8EA1  0x021D8EA1  data
 */
#include "../types.h"

#include "map_attr_types.h"
extern int FIELD_G3D_MAPPER_QueryNearestHit(void *g3dMapper, void *pos, u32 *out);
int MAP_ATTR_GetAt(void *g3dMapper, void *pos);
u16 MAP_ATTR_GetTerrainId(u32 attr);
u16 MAP_ATTR_GetFlags(u32 attr);
BOOL MAP_ATTR_IsPresent(u32 attr);
BOOL MAP_ATTR_IsBlocked(u32 attr);
int MAP_ATTR_IsTallGrass(int terrainId);
BOOL MAP_ATTR_IsLedgeNorth(u16 terrainId);
BOOL MAP_ATTR_IsLedgeSouth(u16 terrainId);
BOOL MAP_ATTR_IsLedgeWest(u16 terrainId);
BOOL MAP_ATTR_IsLedgeEast(u16 terrainId);
BOOL MAP_ATTR_IsNoInteract(u16 terrainId);
BOOL MAP_ATTR_IsCameraStep(u16 terrainId);
int MAP_ATTR_IsGimmickD6(int terrainId);
BOOL MAP_ATTR_IsGimmickD7(u16 terrainId);
BOOL MAP_ATTR_IsGimmickD8(u16 terrainId);
BOOL MAP_ATTR_IsGimmickE2(u16 terrainId);
BOOL MAP_ATTR_IsGimmickD9(u16 terrainId);
BOOL MAP_ATTR_IsGimmickDA(u16 terrainId);
BOOL MAP_ATTR_IsGimmickDB(u16 terrainId);
BOOL MAP_ATTR_IsGimmickDC(u16 terrainId);
BOOL MAP_ATTR_IsGimmickDD(u16 terrainId);
BOOL MAP_ATTR_IsGimmickDE(u16 terrainId);
BOOL MAP_ATTR_IsGimmickDF(u16 terrainId);
BOOL MAP_ATTR_IsGimmickE0(u16 terrainId);
BOOL MAP_ATTR_IsGimmickE1(u16 terrainId);
BOOL MAP_ATTR_IsGrassSingle(u16 terrainId);
BOOL MAP_ATTR_IsGrassDouble(u16 terrainId);
BOOL MAP_ATTR_IsTallGrassSingle(u16 terrainId);
BOOL MAP_ATTR_IsTallGrassDouble(u16 terrainId);
BOOL MAP_ATTR_IsAnySingleGrass(u16 terrainId);
BOOL MAP_ATTR_IsAnyDoubleGrass(u16 terrainId);
BOOL MAP_ATTR_IsAnyGrass(u16 terrainId);
BOOL MAP_ATTR_IsHole(u16 terrainId);
BOOL MAP_ATTR_IsLongHopEdge(int terrainId);
int MAP_ATTR_IsRippleWater(int terrainId);
BOOL MAP_ATTR_IsSplashWater(u16 terrainId);
BOOL MAP_ATTR_IsWaterfall(u16 terrainId);
BOOL MAP_ATTR_IsSnow(u16 terrainId);
BOOL MAP_ATTR_IsDeepSnow(int terrainId);
BOOL MAP_ATTR_IsSnowTile(u16 terrainId);
BOOL MAP_ATTR_IsForcedSlide(u32 terrainId);
int MAP_ATTR_IsIce(int terrainId);
BOOL MAP_ATTR_IsSplashWaterB(u16 terrainId);
BOOL MAP_ATTR_IsSandD(u16 terrainId);
BOOL MAP_ATTR_IsSandVariant(u32 terrainId);
BOOL MAP_ATTR_IsAnySand(u16 terrainId);
BOOL MAP_ATTR_IsFishableWater(u16 terrainId);
int MAP_ATTR_IsPuddle(int terrainId);
BOOL MAP_ATTR_IsMud(u16 terrainId);
BOOL MAP_ATTR_IsElectricFloor(u16 terrainId);
BOOL MAP_ATTR_IsElectricPanel(u16 terrainId);
int MAP_ATTR_IsDeepSand(int terrainId);
int MAP_ATTR_IsDeepSandB(int terrainId);
BOOL MAP_ATTR_IsSand(u16 terrainId);
BOOL MAP_ATTR_IsGrassSingleB(u16 terrainId);
BOOL MAP_ATTR_IsGrassDoubleB(u16 terrainId);
BOOL MAP_ATTR_IsMirrorFloor(u16 terrainId);
BOOL MAP_ATTR_IsNoDash(u16 terrainId);
int MAP_ATTR_IsSlopeYA(int terrainId);
int MAP_ATTR_IsSlopeYB(int terrainId);
int MAP_ATTR_IsSlopeXB(int terrainId);
int MAP_ATTR_IsSlopeXA(int terrainId);
int MAP_ATTR_IsRoughGround(int terrainId);
BOOL MAP_ATTR_IsGrassSingleC(u16 terrainId);
BOOL MAP_ATTR_IsGrassDoubleC(u16 terrainId);
int MAP_ATTR_GetEncounterEffectKind(u32 attr);
u8 MAP_ATTR_GetBattleBackground(u16 terrainId);
int MAP_ATTR_IsHopTransition(unsigned long fromAttr, unsigned long toAttr);
extern const u8 data_021D8EA0[];
extern const u8 data_021D8EA1[];

/*
 * Runs the lookup FIELD_G3D_MAPPER_QueryNearestHit into a four-word buffer and returns its third
 * word on success, -1 otherwise.
 *
 * Addresses are Black-image addresses.
 */
int MAP_ATTR_GetAt(void *g3dMapper, void *pos)
{
    u32 hit[4];

    if (FIELD_G3D_MAPPER_QueryNearestHit(g3dMapper, pos, hit) == 1)
        return hit[2];
    return -1;
}

/*
 * Terrain-attribute accessor: the low half of the 32-bit attribute word a
 * map tile's 8-byte grid record carries at byte offset 4 (see
 * FIELD_G3D_MAPPER_GetTilePlane, which hands that word to its caller verbatim with bit 31
 * cleared).  The low half is the terrain id; MAP_ATTR_GetFlags is the matching
 * accessor for the high half, which is the flag half.
 *
 * A leaf that saves nothing, so disasm.py labels it only because a branch
 * elsewhere in ov021 targets it.
 */
u16 MAP_ATTR_GetTerrainId(u32 attr)
{
    return (u16)attr;
}

/*
 * Terrain-attribute accessor: the high half of the tile attribute word,
 * the flag half.  bit 0 is the passable flag (MAP_ATTR_IsBlocked), bit 1 selects
 * the alternate encounter-effect set (enceff.c at 0x021CF6CE), bit 2 gates
 * the terrain-class switch in MAP_ATTR_GetEncounterEffectKind.
 */
u16 MAP_ATTR_GetFlags(u32 attr)
{
    return (u16)(attr >> 16);
}

/*
 * The tile attribute word is present at all: neither the all-ones no-tile
 * sentinel nor the 0xFF no-terrain id in its low half.
 */
BOOL MAP_ATTR_IsPresent(u32 attr)
{
    u16 terrainId;

    terrainId = MAP_ATTR_GetTerrainId(attr);

    if (attr == 0xFFFFFFFF || terrainId == MAP_ATTR_TERRAIN_NONE) {
        return 0;
    }

    return 1;
}

/*
 * The walk/collision test: a tile blocks movement when its attribute word
 * is absent (MAP_ATTR_IsPresent) or when bit 0 of the flag half is set.
 */
BOOL MAP_ATTR_IsBlocked(u32 attr)
{
    u16 flags;

    flags = MAP_ATTR_GetFlags(attr);

    if (!MAP_ATTR_IsPresent(attr) || (flags & MAP_ATTR_FLAG_BLOCKED)) {
        return 1;
    }

    return 0;
}

/*
 * Addresses are Black-image addresses.
 */
int MAP_ATTR_IsTallGrass(int terrainId)
{
    /* TALL_GRASS_SINGLE or TALL_GRASS_DOUBLE: the 16-bit wrap tests 8..9 */
    if ((u16)(terrainId + 0xFFF8) <= 1)
        return 1;
    return 0;
}

/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for MAP_ATTR_TERRAIN_LEDGE_NORTH.
 */
BOOL MAP_ATTR_IsLedgeNorth(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_LEDGE_NORTH) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for MAP_ATTR_TERRAIN_LEDGE_SOUTH.
 */
BOOL MAP_ATTR_IsLedgeSouth(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_LEDGE_SOUTH) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for MAP_ATTR_TERRAIN_LEDGE_WEST.
 */
BOOL MAP_ATTR_IsLedgeWest(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_LEDGE_WEST) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for MAP_ATTR_TERRAIN_LEDGE_EAST.
 */
BOOL MAP_ATTR_IsLedgeEast(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_LEDGE_EAST) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for MAP_ATTR_TERRAIN_NO_INTERACT.
 */
BOOL MAP_ATTR_IsNoInteract(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_NO_INTERACT) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for MAP_ATTR_TERRAIN_CAMERA_STEP.
 */
BOOL MAP_ATTR_IsCameraStep(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_CAMERA_STEP) {
        return 1;
    }

    return 0;
}

int MAP_ATTR_IsGimmickD6(int terrainId)
{
    return terrainId == MAP_ATTR_TERRAIN_GIMMICK_D6;
}

/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for MAP_ATTR_TERRAIN_GIMMICK_D7.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL MAP_ATTR_IsGimmickD7(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_GIMMICK_D7) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for MAP_ATTR_TERRAIN_GIMMICK_D8.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL MAP_ATTR_IsGimmickD8(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_GIMMICK_D8) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for MAP_ATTR_TERRAIN_GIMMICK_E2.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL MAP_ATTR_IsGimmickE2(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_GIMMICK_E2) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for MAP_ATTR_TERRAIN_GIMMICK_D9.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL MAP_ATTR_IsGimmickD9(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_GIMMICK_D9) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for MAP_ATTR_TERRAIN_GIMMICK_DA.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL MAP_ATTR_IsGimmickDA(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_GIMMICK_DA) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for MAP_ATTR_TERRAIN_GIMMICK_DB.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL MAP_ATTR_IsGimmickDB(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_GIMMICK_DB) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for MAP_ATTR_TERRAIN_GIMMICK_DC.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL MAP_ATTR_IsGimmickDC(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_GIMMICK_DC) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for MAP_ATTR_TERRAIN_GIMMICK_DD.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL MAP_ATTR_IsGimmickDD(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_GIMMICK_DD) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for MAP_ATTR_TERRAIN_GIMMICK_DE.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL MAP_ATTR_IsGimmickDE(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_GIMMICK_DE) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for MAP_ATTR_TERRAIN_GIMMICK_DF.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL MAP_ATTR_IsGimmickDF(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_GIMMICK_DF) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for MAP_ATTR_TERRAIN_GIMMICK_E0.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL MAP_ATTR_IsGimmickE0(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_GIMMICK_E0) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for MAP_ATTR_TERRAIN_GIMMICK_E1.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL MAP_ATTR_IsGimmickE1(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_GIMMICK_E1) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for MAP_ATTR_TERRAIN_GRASS_SINGLE, MAP_ATTR_TERRAIN_GRASS_SINGLE_C, MAP_ATTR_TERRAIN_GRASS_SINGLE_B.
 */
BOOL MAP_ATTR_IsGrassSingle(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_GRASS_SINGLE || terrainId == MAP_ATTR_TERRAIN_GRASS_SINGLE_C || terrainId == MAP_ATTR_TERRAIN_GRASS_SINGLE_B) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for MAP_ATTR_TERRAIN_GRASS_DOUBLE, MAP_ATTR_TERRAIN_GRASS_DOUBLE_C, MAP_ATTR_TERRAIN_GRASS_DOUBLE_B.
 */
BOOL MAP_ATTR_IsGrassDouble(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_GRASS_DOUBLE || terrainId == MAP_ATTR_TERRAIN_GRASS_DOUBLE_C || terrainId == MAP_ATTR_TERRAIN_GRASS_DOUBLE_B) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for MAP_ATTR_TERRAIN_TALL_GRASS_SINGLE.
 */
BOOL MAP_ATTR_IsTallGrassSingle(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_TALL_GRASS_SINGLE) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for MAP_ATTR_TERRAIN_TALL_GRASS_DOUBLE.
 */
BOOL MAP_ATTR_IsTallGrassDouble(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_TALL_GRASS_DOUBLE) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate: the union of the two families below.
 */
BOOL MAP_ATTR_IsAnySingleGrass(u16 terrainId)
{
    if (MAP_ATTR_IsGrassSingle(terrainId) == 1 || MAP_ATTR_IsTallGrassSingle(terrainId) == 1) {
        return 1;
    }

    return 0;
}

BOOL MAP_ATTR_IsAnyDoubleGrass(u16 terrainId)
{
    if (MAP_ATTR_IsGrassDouble(terrainId) == 1 || MAP_ATTR_IsTallGrassDouble(terrainId) == 1) {
        return 1;
    }

    return 0;
}

BOOL MAP_ATTR_IsAnyGrass(u16 terrainId)
{
    if (MAP_ATTR_IsAnySingleGrass(terrainId) == 1 || MAP_ATTR_IsAnyDoubleGrass(terrainId) == 1) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for MAP_ATTR_TERRAIN_HOLE.
 */
BOOL MAP_ATTR_IsHole(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_HOLE) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for MAP_ATTR_TERRAIN_LONG_HOP_EDGE, MAP_ATTR_TERRAIN_LONG_HOP_EDGE_B.
 */
BOOL MAP_ATTR_IsLongHopEdge(int terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_LONG_HOP_EDGE || terrainId == MAP_ATTR_TERRAIN_LONG_HOP_EDGE_B) {
        return 1;
    }

    return 0;
}

/*
 * Two equality predicates.
 */
int MAP_ATTR_IsRippleWater(int terrainId)
{
    return terrainId == MAP_ATTR_TERRAIN_RIPPLE_WATER;
}

/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for MAP_ATTR_TERRAIN_SPLASH_WATER.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL MAP_ATTR_IsSplashWater(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_SPLASH_WATER) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for MAP_ATTR_TERRAIN_WATERFALL.
 */
BOOL MAP_ATTR_IsWaterfall(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_WATERFALL) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for MAP_ATTR_TERRAIN_SNOW.
 */
BOOL MAP_ATTR_IsSnow(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_SNOW) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for MAP_ATTR_TERRAIN_DEEP_SNOW.
 */
BOOL MAP_ATTR_IsDeepSnow(int terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_DEEP_SNOW) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate forwarding to MAP_ATTR_IsSnow (id 0x0e).
 */
BOOL MAP_ATTR_IsSnowTile(u16 terrainId)
{
    if (MAP_ATTR_IsSnow(terrainId)) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for MAP_ATTR_TERRAIN_ICE_B, MAP_ATTR_TERRAIN_ICE.
 */
BOOL MAP_ATTR_IsForcedSlide(u32 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_ICE_B || terrainId == MAP_ATTR_TERRAIN_ICE) {
        return 1;
    }

    return 0;
}

int MAP_ATTR_IsIce(int terrainId)
{
    return terrainId == MAP_ATTR_TERRAIN_ICE;
}

/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for MAP_ATTR_TERRAIN_SPLASH_WATER_B.
 */
BOOL MAP_ATTR_IsSplashWaterB(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_SPLASH_WATER_B) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for MAP_ATTR_TERRAIN_SAND_D.
 */
BOOL MAP_ATTR_IsSandD(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_SAND_D) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for MAP_ATTR_TERRAIN_SAND, MAP_ATTR_TERRAIN_SAND_B, MAP_ATTR_TERRAIN_SAND_C.
 */
BOOL MAP_ATTR_IsSandVariant(u32 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_SAND || terrainId == MAP_ATTR_TERRAIN_SAND_B || terrainId == MAP_ATTR_TERRAIN_SAND_C) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate: MAP_ATTR_IsSandD (0x19) or MAP_ATTR_IsSandVariant (0x0b, 0x0c, 0x23).
 */
BOOL MAP_ATTR_IsAnySand(u16 terrainId)
{
    if (MAP_ATTR_IsSandD(terrainId) || MAP_ATTR_IsSandVariant(terrainId)) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate: true for MAP_ATTR_TERRAIN_WATER, WATER_B, WATER_DEEP, WATER_C and WATER_DEEP_B.  The
 * compiler folds the last two arms into one (u16)(id - 0x42) <= 1 range test.
 */
BOOL MAP_ATTR_IsFishableWater(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_WATER || terrainId == MAP_ATTR_TERRAIN_WATER_B || terrainId == MAP_ATTR_TERRAIN_WATER_DEEP || terrainId == MAP_ATTR_TERRAIN_WATER_C || terrainId == MAP_ATTR_TERRAIN_WATER_DEEP_B) {
        return 1;
    }

    return 0;
}

int MAP_ATTR_IsPuddle(int terrainId)
{
    return terrainId == MAP_ATTR_TERRAIN_PUDDLE;
}

/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for MAP_ATTR_TERRAIN_MUD.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL MAP_ATTR_IsMud(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_MUD) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for MAP_ATTR_TERRAIN_ELECTRIC_FLOOR.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL MAP_ATTR_IsElectricFloor(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_ELECTRIC_FLOOR) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for MAP_ATTR_TERRAIN_ELECTRIC_PANEL.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL MAP_ATTR_IsElectricPanel(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_ELECTRIC_PANEL) {
        return 1;
    }

    return 0;
}

/*
 * Seven one-line equality predicates, one per constant.
 */
int MAP_ATTR_IsDeepSand(int terrainId)
{
    return terrainId == MAP_ATTR_TERRAIN_DEEP_SAND;
}

int MAP_ATTR_IsDeepSandB(int terrainId)
{
    return terrainId == MAP_ATTR_TERRAIN_DEEP_SAND_B;
}

/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for MAP_ATTR_TERRAIN_SAND.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL MAP_ATTR_IsSand(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_SAND) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for MAP_ATTR_TERRAIN_GRASS_SINGLE_B.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL MAP_ATTR_IsGrassSingleB(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_GRASS_SINGLE_B) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for MAP_ATTR_TERRAIN_GRASS_DOUBLE_B.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL MAP_ATTR_IsGrassDoubleB(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_GRASS_DOUBLE_B) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for MAP_ATTR_TERRAIN_MIRROR_FLOOR.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL MAP_ATTR_IsMirrorFloor(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_MIRROR_FLOOR) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for MAP_ATTR_TERRAIN_NO_DASH.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL MAP_ATTR_IsNoDash(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_NO_DASH) {
        return 1;
    }

    return 0;
}

int MAP_ATTR_IsSlopeYA(int terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_SLOPE_AXIS_Y_A || (unsigned short)(terrainId + 0xFFAB) <= 1) /* 0x55..0x56 */
        return 1;
    return 0;
}

int MAP_ATTR_IsSlopeYB(int terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_SLOPE_AXIS_Y_B || (unsigned short)(terrainId + 0xFFA9) <= 1) /* 0x57..0x58 */
        return 1;
    return 0;
}

int MAP_ATTR_IsSlopeXB(int terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_SLOPE_AXIS_X_B || terrainId == MAP_ATTR_TERRAIN_SLOPE_XB_YA || terrainId == MAP_ATTR_TERRAIN_SLOPE_XB_YB)
        return 1;
    return 0;
}

int MAP_ATTR_IsSlopeXA(int terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_SLOPE_AXIS_X_A || terrainId == MAP_ATTR_TERRAIN_SLOPE_XA_YA || terrainId == MAP_ATTR_TERRAIN_SLOPE_XA_YB)
        return 1;
    return 0;
}

int MAP_ATTR_IsRoughGround(int terrainId)
{
    if (MAP_ATTR_IsTallGrass(terrainId) || MAP_ATTR_IsDeepSand(terrainId) || MAP_ATTR_IsDeepSandB(terrainId) || MAP_ATTR_IsDeepSnow(terrainId))
        return 1;
    return 0;
}

/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for MAP_ATTR_TERRAIN_GRASS_SINGLE_C.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL MAP_ATTR_IsGrassSingleC(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_GRASS_SINGLE_C) {
        return 1;
    }

    return 0;
}

/*
 * Terrain-id predicate over the low half of a tile's 32-bit attribute word
 * (byte offset 4 of the 8-byte a/0/0/8 grid record): true for MAP_ATTR_TERRAIN_GRASS_DOUBLE_C.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run this whole predicate family prints as.
 */
BOOL MAP_ATTR_IsGrassDoubleC(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_GRASS_DOUBLE_C) {
        return 1;
    }

    return 0;
}

/*
 * Terrain class of a tile attribute word, for the encounter-effect lane.
 * Its one caller, EFFECT_ENCOUNT_CollectCandidates in effect_encount.c, drops the tile when
 * the answer is 8 and otherwise stores the class byte in its per-tile
 * candidate list, so 8 is "no effect".  Note the flag-half gate: unless
 * bit 2 of the high half is set, every id falls through to 8, which is why
 * the overwhelmingly common 0x0081 flag half never produces a class.
 *
 * The two half accessors are MAP_ATTR_GetTerrainId/MAP_ATTR_GetFlags inlined.
 */
int MAP_ATTR_GetEncounterEffectKind(u32 attr)
{
    u16 terrainId = (u16)attr;
    u16 flags = (u16)(attr >> 16);

    if (terrainId == MAP_ATTR_TERRAIN_NO_ENCOUNTER) {
        return 7;
    }

    if (!(flags & MAP_ATTR_FLAG_ENCOUNTER_EFFECT)) {
        return 8;
    }

    switch (terrainId) {
    case MAP_ATTR_TERRAIN_GRASS_SINGLE:
        return 0;
    case MAP_ATTR_TERRAIN_GRASS_SINGLE_B:
        return 1;
    case MAP_ATTR_TERRAIN_GRASS_SINGLE_C:
        return 2;
    case MAP_ATTR_TERRAIN_TALL_GRASS_SINGLE:
        return 3;
    case MAP_ATTR_TERRAIN_CAVE_FLOOR:
        return 4;
    case MAP_ATTR_TERRAIN_WATER:
        return 5;
    case MAP_ATTR_TERRAIN_WATER_DEEP:
    case MAP_ATTR_TERRAIN_WATER_DEEP_B:
        return 6;
    }

    return 8;
}

/*
 * Addresses are Black-image addresses.
 */
u8 MAP_ATTR_GetBattleBackground(u16 terrainId)
{
    u32 i;

    for (i = 0; i < 0x25; i++) {
        if (terrainId == data_021D8EA0[i * 2])
            return data_021D8EA1[i * 2];
    }
    return 0;
}

int MAP_ATTR_IsHopTransition(unsigned long fromAttr, unsigned long toAttr)
{
    unsigned short flags = MAP_ATTR_GetFlags(toAttr);
    unsigned short terrainId = MAP_ATTR_GetTerrainId(toAttr);

    if (MAP_ATTR_IsBlocked(fromAttr))
        return 0;
    if (((flags & MAP_ATTR_FLAG_ENCOUNTER_ALT) && !MAP_ATTR_IsBlocked(toAttr)) || MAP_ATTR_IsLongHopEdge(terrainId))
        return 1;
    return 0;
}
