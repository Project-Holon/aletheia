/*
 * file:     gf_font_p06.c
 * unit:     yes
 * function: func_0201E538, func_0201E738, func_0201E928, func_0201EC64
 * address:  0x0201E538
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02146578     0x02146578  data
 *   g_02146588     0x02146588  data
 *   func_0201E4C8  0x0201E4C8  thumb
 *   sub_0201E4D4   0x0201E4D4  thumb
 */
struct WordSet;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct BitReader {
    const u8 *src;
    u32       avail;
    u8        cur;
};

struct FontState {
    u8               colour[3];
    u8               pad;
    struct BitReader br;
};

extern void func_0201E4C8(struct BitReader *b, const u8 *p);
extern u8   sub_0201E4D4(struct BitReader *r, u8 n);
extern struct WordSet *func_0201EC74(u32 count, u32 size, u32 heap);
void func_0201E538(const u8 *src, u32 n, u16 *dst);
void func_0201E738(const u8 *src, u32 n, u16 *dst);
void func_0201E928(const u8 *src, u32 n, u16 *dst);
struct WordSet *func_0201EC64(u32 heap);
extern struct FontState g_02146578;
extern u16 g_02146588[256];




/*
 * One of the four compressed-glyph decoders src/matched/func_0201DAA4.c and
 * src/matched/sub_0201DA24.c install at the font object's +8.  All four read
 * the same 2bpp bit stream through the shared reader (src/matched/sub_0201E4C8.c
 * opens it, src/matched/sub_0201E4D4.c pulls bits) and expand every byte
 * through the 256-entry table src/matched/sub_0201DD78.c rebuilds, so the
 * halfwords written to dst are the glyph in 4bpp.  They differ only in how
 * many halfwords they write and in what shape.
 *
 * `n` is the caller's bit depth and is a runtime value: every second (or third)
 * group is read at that variable width while the rest are whole literal bytes,
 * which is why the argument alternates between `movs r1, #8` and the
 * `lsls`/`lsrs #24` re-materialisation of `(u8)n`.  The parameter must stay
 * `u32`; a `u8` parameter lets mwcc treat the register as already narrowed,
 * drops the per-call re-materialisation and the function comes out short.
 *
 * Unlike src/matched/func_0201DE40.c, which is the same reader inlined sixteen
 * times against the state's inline fields, these three call it out of line, so
 * the state address is a plain pool word reloaded before every call and the
 * body is a flat run of calls with no loop.
 *
 * Thirty-two halfwords, one flat 8x8-at-4bpp glyph in address order, with the
 * widths alternating 8, n, 8, n, ...  The simplest of the four: one cursor,
 * dst[0] through dst[31] in order.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201E538.c \
 *       --func func_0201E538 --addr 0x0201E538 --cc 1.1p1 --thumb
 *   EXACT, 512 bytes, 35 relocation sites, all 35 resolved.
 */
void func_0201E538(const u8 *src, u32 n, u16 *dst)
{
    func_0201E4C8(&g_02146578.br, src);
    dst[0] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[1] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[2] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[3] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[4] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[5] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[6] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[7] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[8] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[9] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[10] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[11] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[12] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[13] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[14] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[15] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[16] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[17] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[18] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[19] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[20] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[21] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[22] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[23] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[24] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[25] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[26] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[27] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[28] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[29] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[30] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[31] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
}




/*
 * One of the four compressed-glyph decoders src/matched/func_0201DAA4.c and
 * src/matched/sub_0201DA24.c install at the font object's +8.  All four read
 * the same 2bpp bit stream through the shared reader (src/matched/sub_0201E4C8.c
 * opens it, src/matched/sub_0201E4D4.c pulls bits) and expand every byte
 * through the 256-entry table src/matched/sub_0201DD78.c rebuilds, so the
 * halfwords written to dst are the glyph in 4bpp.  They differ only in how
 * many halfwords they write and in what shape.
 *
 * `n` is the caller's bit depth and is a runtime value: every second (or third)
 * group is read at that variable width while the rest are whole literal bytes,
 * which is why the argument alternates between `movs r1, #8` and the
 * `lsls`/`lsrs #24` re-materialisation of `(u8)n`.  The parameter must stay
 * `u32`; a `u8` parameter lets mwcc treat the register as already narrowed,
 * drops the per-call re-materialisation and the function comes out short.
 *
 * Unlike src/matched/func_0201DE40.c, which is the same reader inlined sixteen
 * times against the state's inline fields, these three call it out of line, so
 * the state address is a plain pool word reloaded before every call and the
 * body is a flat run of calls with no loop.
 *
 * Thirty-two halfwords in TWO interleaved cursors, `dst` and `dst2 = dst + 16`,
 * written four at a time: dst[2i], dst[2i+1], dst2[2i], dst2[2i+1], with widths
 * 8, 8, 8, n.  The second cursor is what puts dst+0x20 in r7 for the whole
 * body; written as dst[16 + k] instead the compiler recomputes the base from
 * dst at every far store and the function is longer.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201E738.c \
 *       --func func_0201E738 --addr 0x0201E738 --cc 1.1p1 --thumb
 *   EXACT, 496 bytes, 35 relocation sites, all 35 resolved.
 */
void func_0201E738(const u8 *src, u32 n, u16 *dst)
{
    u16 *dst2 = dst + 16;

    func_0201E4C8(&g_02146578.br, src);
    dst[0] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[1] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[0] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[1] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[2] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[3] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[2] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[3] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[4] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[5] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[4] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[5] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[6] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[7] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[6] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[7] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[8] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[9] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[8] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[9] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[10] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[11] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[10] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[11] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[12] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[13] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[12] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[13] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[14] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[15] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[14] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[15] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
}



/*
 * One of the four compressed-glyph decoders src/matched/func_0201DAA4.c and
 * src/matched/sub_0201DA24.c install at the font object's +8.  All four read
 * the same 2bpp bit stream through the shared reader (src/matched/sub_0201E4C8.c
 * opens it, src/matched/sub_0201E4D4.c pulls bits) and expand every byte
 * through the 256-entry table src/matched/sub_0201DD78.c rebuilds, so the
 * halfwords written to dst are the glyph in 4bpp.  They differ only in how
 * many halfwords they write and in what shape.
 *
 * `n` is the caller's bit depth and is a runtime value: every second (or third)
 * group is read at that variable width while the rest are whole literal bytes,
 * which is why the argument alternates between `movs r1, #8` and the
 * `lsls`/`lsrs #24` re-materialisation of `(u8)n`.  The parameter must stay
 * `u32`; a `u8` parameter lets mwcc treat the register as already narrowed,
 * drops the per-call re-materialisation and the function comes out short.
 *
 * Unlike src/matched/func_0201DE40.c, which is the same reader inlined sixteen
 * times against the state's inline fields, these three call it out of line, so
 * the state address is a plain pool word reloaded before every call and the
 * body is a flat run of calls with no loop.
 *
 * Forty-eight halfwords across FOUR 8x8 tiles, the widest of the four decoders.
 * The tiles are written three halfwords at a time, dst[k], dst[k+1], dst2[k],
 * with widths 8, 8, n, where `dst2 = dst + 16` is the tile below.
 *
 * WHICH INDEX GOES THROUGH WHICH CURSOR IS LOAD-BEARING, and it is what cost
 * the time here.  The second tile pair lives at halfword 32..63, and its low
 * tile (32..47) must be written as `dst[32..47]`, i.e. through the FIRST
 * cursor, while its high tile (48..63) goes through `dst2[32..47]`.  Routing
 * the whole second pair through `dst2` (dst2[16..47], which is the same
 * address arithmetic) lets mwcc keep one base live across both blocks: sixty
 * bytes short, 413 bytes out, and a clean r5/r6/r7 rotation in the permuter's
 * --explain map.  Splitting them back restores the original's recomputed
 * `adds r0, r5, #0 / adds r0, #0x40 / strh` at every far store, which is the
 * shape the image actually has.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201E928.c \
 *       --func func_0201E928 --addr 0x0201E928 --cc 1.1p1 --thumb
 *   EXACT, 828 bytes, 51 relocation sites, all 51 resolved.
 */
void func_0201E928(const u8 *src, u32 n, u16 *dst)
{
    u16 *dst2 = dst + 16;

    func_0201E4C8(&g_02146578.br, src);
    dst[0] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[1] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[0] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[2] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[3] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[2] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[4] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[5] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[4] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[6] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[7] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[6] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[8] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[9] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[8] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[10] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[11] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[10] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[12] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[13] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[12] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[14] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[15] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[14] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[32] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[33] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[32] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[34] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[35] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[34] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[36] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[37] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[36] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[38] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[39] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[38] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[40] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[41] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[40] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[42] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[43] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[42] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[44] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[45] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[44] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
    dst[46] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst[47] = g_02146588[sub_0201E4D4(&g_02146578.br, 8)];
    dst2[46] = g_02146588[sub_0201E4D4(&g_02146578.br, n)];
}


/*
 * The first function of wordset.c.  The file identity is in the image: the
 * constructor at 0x0201EC74, immediately after this, passes 0x020A7364 to the
 * debug allocator at 0x02030734, and the bytes there spell "wordset.c".  The
 * string before it is "gf_font.c", whose terminator at 0x020A7360 plus three
 * bytes of padding fixes 0x020A7364 by construction, so the `string` class
 * carries the address; see src/matched/unit_0201ED04.c for the rest of the
 * file and the near miss at 0x0201EC74 that keeps this function on its own.
 *
 * Sixteen bytes: a pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) that fills in the default
 * entry count 8 and the default per-entry string size 0x20.  It cannot be one
 * unit with 0x0201EC74 because that function is 14 bytes of prologue
 * scheduling away from EXACT and csrc.py refuses anything less.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201EC64.c \
 *       --addr 0x0201EC64 --thumb
 */
struct WordSet *func_0201EC64(u32 heap)
{
    return func_0201EC74(8, 0x20, heap);
}
