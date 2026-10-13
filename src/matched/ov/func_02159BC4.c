/*
 * function: MAP_MATRIX_GetZoneId
 * address:  0x02159BC4
 * packet:   pkt_02159B94
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Read one cell of the matrix object's zone grid: the u16 array at +0x14,
 * row-major over the object's own width at +0x08.  Leaf, no relocations.
 *
 * The companion grid is the u32 array at +0x71C holding a/0/0/8 sub-file
 * indices; MAP_MATRIX_GetMapGrid hands out its base.  Both are decoded by
 * MAP_MATRIX_SetupFromFile out of one a/0/0/9 sub-file.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MAP_MATRIX_GetZoneId.c \
 *       --func MAP_MATRIX_GetZoneId --addr 0x02159BC4 --region ov010 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct MapMatrix {
    u16 field00;
    u16 zone_id;
    u32 matrix_id;
    u16 width;
    u16 height;
    u16 mode;
    u16 pad0e;
    u32 count;
    u16 zone_grid[900];
    u32 map_grid[900];
};

u16 MAP_MATRIX_GetZoneId(const struct MapMatrix *m, u32 x, u32 y)
{
    return m->zone_grid[x + y * m->width];
}
