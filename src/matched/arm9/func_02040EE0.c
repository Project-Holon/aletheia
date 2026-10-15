/*
 * unit:     no
 * function: BG_SYS_GetTileMapEntry
 * address:  0x02040EE0
 * packet:   pkt_020409E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The (x, y) to linear screen-entry index helper the whole BG layer uses
 * (src/matched/BG_SYS_SetupTileScreen.c and src/matched/BG_SYS_FillTileMap.c are two of
 * its callers).  The third argument is the slot's screen-size code at +0x1d
 * of the 0x2c-byte slot record, and the six arms spell the DS BG screen
 * layouts out exactly:
 *
 *   0  256x256 text, one 32x32 map:      x + y * 32 is wrong, it is
 *                                        x + y * 16, i.e. a 16-wide map
 *   1  and 2                             x + y * 32, a 32-wide map
 *   3  512x256: the second 32x32 map follows the first, so the high bits
 *      of x select the map and the low five index inside it
 *   4  512x512: four 32x32 maps in a 2x2 grid, map index (y>>5)*2 + (x>>5)
 *      times 0x400 entries, plus (x & 31) + (y & 31) * 32 inside
 *   5  no map
 *
 * Everything is u16 arithmetic: case 4 truncates the scaled map index to
 * sixteen bits before adding the in-map offset, which is what the
 * `lsl #26` / `lsr #16` pair is, so the two partial results have to be u16
 * locals rather than one expression.
 *
 * x and y are signed (the shifts are `asr`, not `lsr`), and the switch has
 * no default arm at all: an out-of-range code falls straight out of the
 * dispatch to `bx lr` with x still in r0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_GetTileMapEntry.c \
 *       --func BG_SYS_GetTileMapEntry --addr 0x02040EE0 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

u16 BG_SYS_GetTileMapEntry(int x, int y, u32 code)
{
    u16 map;
    u16 off;

    switch (code) {
    case 0:
        return x + y * 16;
    case 1:
    case 2:
        return x + y * 32;
    case 3:
        return (x & 0x1f) + (y + (x & ~0x1f)) * 32;
    case 4:
        map = (y >> 5) * 2 + (x >> 5);
        off = (x & 0x1f) + (y & 0x1f) * 32;
        map = map * 0x400;
        return off + map;
    case 5:
        return 0;
    }
}
