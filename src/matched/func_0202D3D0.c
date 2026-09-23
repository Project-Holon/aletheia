/*
 * function: func_0202D3D0
 * address:  0x0202D3D0
 * packet:   pkt_0202D2EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   tile_tables  0x020A779C  data
 *
 * pokegra.c (wave 13): stamp four shape tables into a 4bpp tile image.  For
 * each of the four 0xff-terminated (x, y) pair tables at 0x020A779C, offset
 * by the low nibble pair of a1 (minus 8 each, a1 then shifted down a byte per
 * table), locate the pixel's byte in a 12-tile-wide 8x8 tile layout and, when
 * its nibble is colour 1..3, move it to 6..8 (+5 low, +0x50 high).
 *
 * WHAT CLOSED IT (docs/notes/func_0202D3D0.c.txt: 216 against 216, 29 to 39
 * bytes out, "idx in r0 / v in r2" allocation never reached by sixteen
 * spellings, permuter flat): there is NO hoisted byte local.  Each arm reads
 * the pixel byte itself and updates it with a compound assignment,
 * `n = blob[idx] & 0xf0; if (...) blob[idx] += 0x50;`.  The compiler hoists
 * the common load itself, after the `x & 1` test, and that is the register
 * assignment the image has.  The note's "v read inside each arm" attempt
 * (212 bytes) wrote `v = blob[idx]` per arm; the compound `+=` is what makes
 * the two arms' loads identical expressions the compiler can merge.  The
 * quotient locals cx/cy (second pass) and `j = 0` above the terminator test
 * (first pass) stand.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern const u8 *const tile_tables[4];

struct Obj {
    u8  pad[0x14];
    u8 *blob;
};

void func_0202D3D0(struct Obj *obj, u32 a1)
{
    u8 *blob = obj->blob;
    int i;
    int j;
    const u8 *tab;
    s32 x, y, cx, cy, idx, n;

    for (i = 0; i < 4; i++) {
        tab = tile_tables[i];
        j = 0;
        if (tab[0] != 0xff) {
            s32 bx = (s32)(a1 & 0xf) - 8;
            s32 by = (s32)((a1 & 0xf0) >> 4) - 8;
            do {
                x = bx + (tab[j * 2] + 0x16);
                y = by + (tab[j * 2 + 1] + 0x10);
                cx = x / 8;
                cy = y / 8;
                idx = ((x % 8) + (y % 8) * 8 + (cx + cy * 12) * 64) / 2;
                if (x & 1) {
                    n = blob[idx] & 0xf0;
                    if (n >= 0x10 && n <= 0x30)
                        blob[idx] += 0x50;
                } else {
                    n = blob[idx] & 0xf;
                    if (n >= 1 && n <= 3)
                        blob[idx] += 5;
                }
                j++;
            } while (tab[j * 2] != 0xff);
        }
        a1 >>= 8;
    }
}
