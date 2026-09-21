/*
 * function: func_0201E928
 * address:  0x0201E928
 * packet:   pkt_0201E928
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *

 * symbols:
 *   g_02146578     0x02146578  data
 *   g_02146588     0x02146588  data
 *   func_0201E4C8  0x0201E4C8  thumb
 *   sub_0201E4D4   0x0201E4D4  thumb
 *
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

extern struct FontState g_02146578;
extern u16 g_02146588[256];

extern void func_0201E4C8(struct BitReader *b, const u8 *p);
extern u8   sub_0201E4D4(struct BitReader *r, u8 n);

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
