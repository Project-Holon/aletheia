/*
 * function: func_02159D04
 * address:  0x02159D04
 * packet:   pkt_ov010_02159D04
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082A48  0x02082A48  arm
 *   func_02082A90  0x02082A90  arm
 *
 * The map-matrix decoder: unpack one a/0/0/9 sub-file into the runtime matrix
 * object. File = { u16 mode; u16 pad; u16 width; u16 height; u32 cells[] },
 * plus a second block of the same length when mode == 1. Block one is copied
 * into the u32 grid at +0x71C. Block two is narrowed into the u16 grid at
 * +0x14; without it the u16 grid is filled with the caller's zone id.
 *
 * final push 2026-10-05 G4L1: closed by storing zone_id first (dst->zone_id =
 * zone_id before the matrix_id store). That gives the parameter the earliest
 * birth, so it takes r7 (the later-born cells and pool take r6 and r4). EXACT
 * in c99 and c.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct MatrixFile {
    u16 mode;
    u16 pad02;
    u16 width;
    u16 height;
    u32 cells[];
};

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

extern void func_02082A48(u32 value, void *dst, u32 size);
extern void func_02082A90(const void *src, void *dst, u32 size);

void func_02159D04(struct MapMatrix *dst, const struct MatrixFile *src,
                   u32 matrix_id, u16 zone_id)
{
    u32 n;
    const u32 *cells;
    const u32 *second;
    u32 i;
    u16 *zone_grid;

    dst->zone_id = zone_id;
    dst->matrix_id = matrix_id;
    n = src->width * src->height;
    dst->height = src->height;
    dst->count = n;
    dst->mode = src->mode;
    dst->width = src->width;
    cells = src->cells;
    func_02082A90(cells, dst->map_grid, n * 4);

    zone_grid = dst->zone_grid;
    if (dst->mode == 1) {
        second = cells + dst->count;
        for (i = 0; i < dst->count; i++)
            zone_grid[i] = (u16)second[i];
    } else {
        func_02082A48(zone_id, zone_grid, 0x708);
    }
}
