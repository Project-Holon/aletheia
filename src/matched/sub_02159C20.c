/*
 * function: sub_02159C20
 * address:  0x02159C20
 * packet:   pkt_02159B94
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The map-model grid getter: hand out the base of the matrix object's u32
 * cell array at +0x71C.  Each cell is an a/0/0/8 sub-file index, or
 * 0xFFFFFFFF for an empty square; func_02159D04 copies them there verbatim
 * out of the a/0/0/9 sub-file.  Its two callers are ov021's func_0218CD20
 * and func_02189B28's neighbour, both of which splice grids rather than
 * index them singly.
 *
 * A leaf that saves nothing, so disasm.py never labelled it: it hides in the
 * word run between func_02159C0C and func_02159C2C
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  The 0x71C
 * offset is out of reach of an `adds rd, rn, #imm`, hence the pool word.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02159C20.c \
 *       --func sub_02159C20 --addr 0x02159C20 --region ov010 --cc 1.1p1 --thumb
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

u32 *sub_02159C20(struct MapMatrix *m)
{
    return m->map_grid;
}
