/*
 * function: func_0201E538
 * address:  0x0201E538
 * packet:   pkt_0201E538
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
