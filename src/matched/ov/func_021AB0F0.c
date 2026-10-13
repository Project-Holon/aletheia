/*
 * function: MAP_ATTR_GetTerrainId
 * address:  0x021AB0F0
 * packet:   pkt_021AB0F0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Terrain-attribute accessor: the low half of the 32-bit attribute word a
 * map tile's 8-byte grid record carries at byte offset 4 (see
 * FIELD_G3D_MAPPER_GetTilePlane, which hands that word to its caller verbatim with bit 31
 * cleared).  The low half is the terrain id; MAP_ATTR_GetFlags is the matching
 * accessor for the high half, which is the flag half.
 *
 * A leaf that saves nothing, so disasm.py labels it only because a branch
 * elsewhere in ov021 targets it.
 */

typedef unsigned short u16;
typedef unsigned long u32;

u16 MAP_ATTR_GetTerrainId(u32 attr)
{
    return (u16)attr;
}
