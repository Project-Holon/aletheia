/*
 * function: sub_02159C00
 * address:  0x02159C00
 * packet:   pkt_02159B94
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Set the matrix object's dimensions, refusing anything that would not fit
 * the two fixed 900-entry grids: width and height are each capped at 30 and
 * their product at 900.  That is what pins the object's layout, since
 * 0x14 + 900 * 2 is exactly the 0x71C where the u32 map-model grid starts.
 *
 * The product is computed before the guards rather than after, so all three
 * checks share one exit and the whole body is a single conjunction
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 * 900 is spelled 0xe1 << 2 because it is not an 8-bit Thumb immediate.
 *
 * Another leaf with no lr save, so disasm.py left it unlabelled.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02159C00.c \
 *       --func sub_02159C00 --addr 0x02159C00 --region ov010 --cc 1.1p1 --thumb
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

void sub_02159C00(struct MapMatrix *m, u32 width, u32 height)
{
    u32 n = width * height;

    if (width <= 30 && height <= 30 && n <= 900) {
        m->width = (u16)width;
        m->height = (u16)height;
        m->count = n;
    }
}
