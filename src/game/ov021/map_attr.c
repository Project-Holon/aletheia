/*
 * file:     map_attr.c
 * unit:     yes
 * function: func_021AB0D4, func_021AB0F0, func_021AB0F8, func_021AB100, func_021AB11C, func_021AB140, func_021AB158, func_021AB164, func_021AB170, func_021AB17C, func_021AB188, func_021AB194, func_021AB1A0, sub_021AB1AC, sub_021AB1B8, sub_021AB1C4, sub_021AB1D0, sub_021AB1DC, sub_021AB1E8, sub_021AB1F4, sub_021AB200, sub_021AB20C, sub_021AB218, sub_021AB224, sub_021AB230, func_021AB23C, func_021AB250, func_021AB264, func_021AB270, func_021AB27C, func_021AB29C, func_021AB2BC, func_021AB2DC, func_021AB2E8, func_021AB2F8, sub_021AB304, func_021AB310, func_021AB31C, func_021AB328, func_021AB334, func_021AB348, func_021AB358, func_021AB364, func_021AB370, func_021AB37C, func_021AB390, func_021AB3B0, func_021AB3D4, sub_021AB3E0, sub_021AB3EC, sub_021AB3F8, func_021AB404, func_021AB410, sub_021AB41C, sub_021AB428, sub_021AB434, sub_021AB440, sub_021AB44C, func_021AB458, func_021AB474, func_021AB490, func_021AB4A4, func_021AB4B8, sub_021AB4EC, sub_021AB4F8, func_021AB504, func_021AB580, func_021AB5AC
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
 *   func_0218DAEC  0x0218DAEC  thumb
 *   data_021D8EA0  0x021D8EA0  data
 *   data_021D8EA1  0x021D8EA1  data
 */
typedef unsigned char u8;


typedef unsigned short u16;


typedef unsigned int u32;

typedef int BOOL;
#include "map_attr_types.h"
extern int func_0218DAEC(void *g3dMapper, void *pos, u32 *out);
int func_021AB0D4(void *g3dMapper, void *pos);
u16 func_021AB0F0(u32 attr);
u16 func_021AB0F8(u32 attr);
BOOL func_021AB100(u32 attr);
BOOL func_021AB11C(u32 attr);
int func_021AB140(int terrainId);
BOOL func_021AB158(u16 terrainId);
BOOL func_021AB164(u16 terrainId);
BOOL func_021AB170(u16 terrainId);
BOOL func_021AB17C(u16 terrainId);
BOOL func_021AB188(u16 terrainId);
BOOL func_021AB194(u16 terrainId);
int func_021AB1A0(int terrainId);
BOOL sub_021AB1AC(u16 terrainId);
BOOL sub_021AB1B8(u16 terrainId);
BOOL sub_021AB1C4(u16 terrainId);
BOOL sub_021AB1D0(u16 terrainId);
BOOL sub_021AB1DC(u16 terrainId);
BOOL sub_021AB1E8(u16 terrainId);
BOOL sub_021AB1F4(u16 terrainId);
BOOL sub_021AB200(u16 terrainId);
BOOL sub_021AB20C(u16 terrainId);
BOOL sub_021AB218(u16 terrainId);
BOOL sub_021AB224(u16 terrainId);
BOOL sub_021AB230(u16 terrainId);
BOOL func_021AB23C(u16 terrainId);
BOOL func_021AB250(u16 terrainId);
BOOL func_021AB264(u16 terrainId);
BOOL func_021AB270(u16 terrainId);
BOOL func_021AB27C(u16 terrainId);
BOOL func_021AB29C(u16 terrainId);
BOOL func_021AB2BC(u16 terrainId);
BOOL func_021AB2DC(u16 terrainId);
BOOL func_021AB2E8(int terrainId);
int func_021AB2F8(int terrainId);
BOOL sub_021AB304(u16 terrainId);
BOOL func_021AB310(u16 terrainId);
BOOL func_021AB31C(u16 terrainId);
BOOL func_021AB328(int terrainId);
BOOL func_021AB334(u16 terrainId);
BOOL func_021AB348(u32 terrainId);
int func_021AB358(int terrainId);
BOOL func_021AB364(u16 terrainId);
BOOL func_021AB370(u16 terrainId);
BOOL func_021AB37C(u32 terrainId);
BOOL func_021AB390(u16 terrainId);
BOOL func_021AB3B0(u16 terrainId);
int func_021AB3D4(int terrainId);
BOOL sub_021AB3E0(u16 terrainId);
BOOL sub_021AB3EC(u16 terrainId);
BOOL sub_021AB3F8(u16 terrainId);
int func_021AB404(int terrainId);
int func_021AB410(int terrainId);
BOOL sub_021AB41C(u16 terrainId);
BOOL sub_021AB428(u16 terrainId);
BOOL sub_021AB434(u16 terrainId);
BOOL sub_021AB440(u16 terrainId);
BOOL sub_021AB44C(u16 terrainId);
int func_021AB458(int terrainId);
int func_021AB474(int terrainId);
int func_021AB490(int terrainId);
int func_021AB4A4(int terrainId);
int func_021AB4B8(int terrainId);
BOOL sub_021AB4EC(u16 terrainId);
BOOL sub_021AB4F8(u16 terrainId);
int func_021AB504(u32 attr);
u8 func_021AB580(u16 terrainId);
int func_021AB5AC(unsigned long fromAttr, unsigned long toAttr);
extern const u8 data_021D8EA0[];
extern const u8 data_021D8EA1[];

/*
 * Runs the lookup func_0218DAEC into a four-word buffer and returns its third
 * word on success, -1 otherwise.
 *
 * Addresses are Black-image addresses.
 */
int func_021AB0D4(void *g3dMapper, void *pos)
{
    u32 hit[4];

    if (func_0218DAEC(g3dMapper, pos, hit) == 1)
        return hit[2];
    return -1;
}
















/*
 * Terrain-attribute accessor: the low half of the 32-bit attribute word a
 * map tile's 8-byte grid record carries at byte offset 4 (see
 * func_021D14C4, which hands that word to its caller verbatim with bit 31
 * cleared).  The low half is the terrain id; func_021AB0F8 is the matching
 * accessor for the high half, which is the flag half.
 *
 * A leaf that saves nothing, so disasm.py labels it only because a branch
 * elsewhere in ov021 targets it.
 */
u16 func_021AB0F0(u32 attr)
{
    return (u16)attr;
}


















/*
 * Terrain-attribute accessor: the high half of the tile attribute word,
 * the flag half.  bit 0 is the passable flag (func_021AB11C), bit 1 selects
 * the alternate encounter-effect set (enceff.c at 0x021CF6CE), bit 2 gates
 * the terrain-class switch in func_021AB504.
 */
u16 func_021AB0F8(u32 attr)
{
    return (u16)(attr >> 16);
}

















/*
 * The tile attribute word is present at all: neither the all-ones no-tile
 * sentinel nor the 0xFF no-terrain id in its low half.
 */
BOOL func_021AB100(u32 attr)
{
    u16 terrainId;

    terrainId = func_021AB0F0(attr);

    if (attr == 0xFFFFFFFF || terrainId == MAP_ATTR_TERRAIN_NONE) {
        return 0;
    }

    return 1;
}

















/*
 * The walk/collision test: a tile blocks movement when its attribute word
 * is absent (func_021AB100) or when bit 0 of the flag half is set.
 */
BOOL func_021AB11C(u32 attr)
{
    u16 flags;

    flags = func_021AB0F8(attr);

    if (!func_021AB100(attr) || (flags & MAP_ATTR_FLAG_BLOCKED)) {
        return 1;
    }

    return 0;
}
















/*
 * Addresses are Black-image addresses.
 */
int func_021AB140(int terrainId)
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
BOOL func_021AB158(u16 terrainId)
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
BOOL func_021AB164(u16 terrainId)
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
BOOL func_021AB170(u16 terrainId)
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
BOOL func_021AB17C(u16 terrainId)
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
BOOL func_021AB188(u16 terrainId)
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
BOOL func_021AB194(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_CAMERA_STEP) {
        return 1;
    }

    return 0;
}















int func_021AB1A0(int terrainId)
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
BOOL sub_021AB1AC(u16 terrainId)
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
BOOL sub_021AB1B8(u16 terrainId)
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
BOOL sub_021AB1C4(u16 terrainId)
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
BOOL sub_021AB1D0(u16 terrainId)
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
BOOL sub_021AB1DC(u16 terrainId)
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
BOOL sub_021AB1E8(u16 terrainId)
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
BOOL sub_021AB1F4(u16 terrainId)
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
BOOL sub_021AB200(u16 terrainId)
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
BOOL sub_021AB20C(u16 terrainId)
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
BOOL sub_021AB218(u16 terrainId)
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
BOOL sub_021AB224(u16 terrainId)
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
BOOL sub_021AB230(u16 terrainId)
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
BOOL func_021AB23C(u16 terrainId)
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
BOOL func_021AB250(u16 terrainId)
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
BOOL func_021AB264(u16 terrainId)
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
BOOL func_021AB270(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_TALL_GRASS_DOUBLE) {
        return 1;
    }

    return 0;
}

















/*
 * Terrain-id predicate: the union of the two families below.
 */
BOOL func_021AB27C(u16 terrainId)
{
    if (func_021AB23C(terrainId) == 1 || func_021AB264(terrainId) == 1) {
        return 1;
    }

    return 0;
}
















BOOL func_021AB29C(u16 terrainId)
{
    if (func_021AB250(terrainId) == 1 || func_021AB270(terrainId) == 1) {
        return 1;
    }

    return 0;
}
















BOOL func_021AB2BC(u16 terrainId)
{
    if (func_021AB27C(terrainId) == 1 || func_021AB29C(terrainId) == 1) {
        return 1;
    }

    return 0;
}















/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for MAP_ATTR_TERRAIN_HOLE.
 */
BOOL func_021AB2DC(u16 terrainId)
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
BOOL func_021AB2E8(int terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_LONG_HOP_EDGE || terrainId == MAP_ATTR_TERRAIN_LONG_HOP_EDGE_B) {
        return 1;
    }

    return 0;
}













/*
 * Two equality predicates.
 */
int func_021AB2F8(int terrainId)
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
BOOL sub_021AB304(u16 terrainId)
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
BOOL func_021AB310(u16 terrainId)
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
BOOL func_021AB31C(u16 terrainId)
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
BOOL func_021AB328(int terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_DEEP_SNOW) {
        return 1;
    }

    return 0;
}

















/*
 * Terrain-id predicate forwarding to func_021AB31C (id 0x0e).
 */
BOOL func_021AB334(u16 terrainId)
{
    if (func_021AB31C(terrainId)) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for MAP_ATTR_TERRAIN_ICE_B, MAP_ATTR_TERRAIN_ICE.
 */
BOOL func_021AB348(u32 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_ICE_B || terrainId == MAP_ATTR_TERRAIN_ICE) {
        return 1;
    }

    return 0;
}















int func_021AB358(int terrainId)
{
    return terrainId == MAP_ATTR_TERRAIN_ICE;
}
















/*
 * Terrain-id predicate over the low half of the tile attribute word:
 * true for MAP_ATTR_TERRAIN_SPLASH_WATER_B.
 */
BOOL func_021AB364(u16 terrainId)
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
BOOL func_021AB370(u16 terrainId)
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
BOOL func_021AB37C(u32 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_SAND || terrainId == MAP_ATTR_TERRAIN_SAND_B || terrainId == MAP_ATTR_TERRAIN_SAND_C) {
        return 1;
    }

    return 0;
}
















/*
 * Terrain-id predicate: func_021AB370 (0x19) or func_021AB37C (0x0b, 0x0c, 0x23).
 */
BOOL func_021AB390(u16 terrainId)
{
    if (func_021AB370(terrainId) || func_021AB37C(terrainId)) {
        return 1;
    }

    return 0;
}

















/*
 * Terrain-id predicate: true for MAP_ATTR_TERRAIN_WATER, WATER_B, WATER_DEEP, WATER_C and WATER_DEEP_B.  The
 * compiler folds the last two arms into one (u16)(id - 0x42) <= 1 range test.
 */
BOOL func_021AB3B0(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_WATER || terrainId == MAP_ATTR_TERRAIN_WATER_B || terrainId == MAP_ATTR_TERRAIN_WATER_DEEP || terrainId == MAP_ATTR_TERRAIN_WATER_C || terrainId == MAP_ATTR_TERRAIN_WATER_DEEP_B) {
        return 1;
    }

    return 0;
}














int func_021AB3D4(int terrainId)
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
BOOL sub_021AB3E0(u16 terrainId)
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
BOOL sub_021AB3EC(u16 terrainId)
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
BOOL sub_021AB3F8(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_ELECTRIC_PANEL) {
        return 1;
    }

    return 0;
}











/*
 * Seven one-line equality predicates, one per constant.
 */
int func_021AB404(int terrainId)
{
    return terrainId == MAP_ATTR_TERRAIN_DEEP_SAND;
}












int func_021AB410(int terrainId)
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
BOOL sub_021AB41C(u16 terrainId)
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
BOOL sub_021AB428(u16 terrainId)
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
BOOL sub_021AB434(u16 terrainId)
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
BOOL sub_021AB440(u16 terrainId)
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
BOOL sub_021AB44C(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_NO_DASH) {
        return 1;
    }

    return 0;
}











int func_021AB458(int terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_SLOPE_AXIS_Y_A || (unsigned short)(terrainId + 0xFFAB) <= 1) /* 0x55..0x56 */
        return 1;
    return 0;
}










int func_021AB474(int terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_SLOPE_AXIS_Y_B || (unsigned short)(terrainId + 0xFFA9) <= 1) /* 0x57..0x58 */
        return 1;
    return 0;
}










int func_021AB490(int terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_SLOPE_AXIS_X_B || terrainId == MAP_ATTR_TERRAIN_SLOPE_XB_YA || terrainId == MAP_ATTR_TERRAIN_SLOPE_XB_YB)
        return 1;
    return 0;
}










int func_021AB4A4(int terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_SLOPE_AXIS_X_A || terrainId == MAP_ATTR_TERRAIN_SLOPE_XA_YA || terrainId == MAP_ATTR_TERRAIN_SLOPE_XA_YB)
        return 1;
    return 0;
}














int func_021AB4B8(int terrainId)
{
    if (func_021AB140(terrainId) || func_021AB404(terrainId) || func_021AB410(terrainId) || func_021AB328(terrainId))
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
BOOL sub_021AB4EC(u16 terrainId)
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
BOOL sub_021AB4F8(u16 terrainId)
{
    if (terrainId == MAP_ATTR_TERRAIN_GRASS_DOUBLE_C) {
        return 1;
    }

    return 0;
}














/*
 * Terrain class of a tile attribute word, for the encounter-effect lane.
 * Its one caller, func_021AACD4 in effect_encount.c, drops the tile when
 * the answer is 8 and otherwise stores the class byte in its per-tile
 * candidate list, so 8 is "no effect".  Note the flag-half gate: unless
 * bit 2 of the high half is set, every id falls through to 8, which is why
 * the overwhelmingly common 0x0081 flag half never produces a class.
 *
 * The two half accessors are func_021AB0F0/func_021AB0F8 inlined.
 */
int func_021AB504(u32 attr)
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
u8 func_021AB580(u16 terrainId)
{
    u32 i;

    for (i = 0; i < 0x25; i++) {
        if (terrainId == data_021D8EA0[i * 2])
            return data_021D8EA1[i * 2];
    }
    return 0;
}














int func_021AB5AC(unsigned long fromAttr, unsigned long toAttr)
{
    unsigned short flags = func_021AB0F8(toAttr);
    unsigned short terrainId = func_021AB0F0(toAttr);

    if (func_021AB11C(fromAttr))
        return 0;
    if (((flags & MAP_ATTR_FLAG_ENCOUNTER_ALT) && !func_021AB11C(toAttr)) || func_021AB2E8(terrainId))
        return 1;
    return 0;
}
