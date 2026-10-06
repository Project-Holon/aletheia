/*
 * file:     gf_font_p05.c
 * unit:     yes
 * function: func_0201DE40, func_0201E4C8, func_0201E4D4
 * address:  0x0201DE40
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
 *   g_02146578   0x02146578  data
 *   g_02146588   0x02146588  data
 *   g_0209E74C   0x0209E74C  data
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

struct BitReader_0201E4C8 {
    const u8 *src;
    u32       nbits;
    u8        cur;
};

struct BitReader_0201E4D4 {
    const u8 *src;
    u32       avail;
    u8        cur;
};

extern struct FontState g_02146578;
extern const u8         g_0209E74C[];
extern u16              g_02146588[256];


static inline u8 read_bits(struct BitReader *r, u8 n)
{
    u8  hi;
    u32 lo;
    u8  cur;
    u32 used;

    if (r->avail < n) {
        hi = r->cur;
        hi &= g_0209E74C[r->avail];
        used = r->avail;
        n = (u8)(n - (u8)used);
        r->src++;
        r->cur = *r->src;
        r->avail = 8;
    } else {
        hi = 0;
        used = 0;
    }

    cur = r->cur;
    lo = g_0209E74C[n] & cur;
    r->avail = r->avail - n;
    if (r->avail == 0) {
        r->src++;
        r->cur = *r->src;
        r->avail = 8;
    } else {
        r->cur = (u8)(cur << n);
    }
    return (u8)((lo >> used) | hi);
}

/*
 * gf_font.c's format-1 glyph decoder, one of the four hooks func_0201DAA4
 * installs at f->unk08 (src/pending/sub_0201DAA4.c): the one for format 1
 * with b == 1.
 *
 * Sixteen 4-pixel groups of a compressed 2bpp 8x8 glyph.  Every even group is
 * a whole literal byte (read_bits of 8 bits) and every odd one is `n` bits
 * wide; each group's byte then indexes the 256-entry 2bpp->4bpp expansion
 * table at 0x02146588 that func_0201DD78 rebuilds (src/matched/sub_0201DD78.c),
 * so the sixteen halfwords written to dst are the glyph in 4bpp.  `n` is the
 * caller's bit depth and is a runtime value, which is why the even and odd
 * reads are the same inlined reader with a constant and a variable count.
 *
 * The reader is the source of sub_0201E4D4 (src/matched/sub_0201E4D4.c), the
 * out-of-line copy of it that sits just past this function, inlined here
 * sixteen times; `static inline` is load-bearing, plain `static` compiles to
 * sixteen `bl`s and 260 bytes.  Its state is the second half of the global at
 * 0x02146578, whose first three bytes are the text colour func_0201DD78
 * stores and src/matched/unit_0201DE00.c reads back; that is why the inlined
 * field accesses sit at +4/+8/+12 rather than at +0/+4/+8 as they do in the
 * out-of-line call.
 *
 * What cost the last eight bytes: the outer parameter must be `u32 n`, not
 * `u8 n`.  With a u8 parameter mwcc treats the register as an already
 * zero-extended byte, so the inlined expansions compare `r->avail` against
 * the raw argument and keep `n` alive in two registers; the original
 * re-materialises `(u8)n` once per expansion, before the `avail < n`
 * comparison, which is what a conversion from a wider argument gives you.
 * Every block is the same length either way, so the whole difference is one
 * register choice and a pool 8 bytes further along.
 *
 * Extent note: the listing's 1672 bytes for this function run to 0x0201E4C8,
 * eight bytes past the last code byte (0x0201E4BE) - the two-word literal
 * pool at 0x0201E4C0 (g_0209E74C, g_02146588) is this function's own.  It is
 * inside this packet, not the neighbouring 0x0201E000..0x0202E000 lane; the
 * next function starts at 0x0201E4C8.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201DE40.c \
 *       --func func_0201DE40 --addr 0x0201DE40 --cc 1.1p1 --thumb
 *   EXACT, 1672 bytes, 5 relocation sites, all 5 resolved.
 */
void func_0201DE40(const u8 *src, u32 n, u16 *dst)
{
    g_02146578.br.src = src;
    g_02146578.br.cur = *src;
    g_02146578.br.avail = 8;

    dst[0] = g_02146588[read_bits(&g_02146578.br, 8)];
    dst[1] = g_02146588[read_bits(&g_02146578.br, n)];
    dst[2] = g_02146588[read_bits(&g_02146578.br, 8)];
    dst[3] = g_02146588[read_bits(&g_02146578.br, n)];
    dst[4] = g_02146588[read_bits(&g_02146578.br, 8)];
    dst[5] = g_02146588[read_bits(&g_02146578.br, n)];
    dst[6] = g_02146588[read_bits(&g_02146578.br, 8)];
    dst[7] = g_02146588[read_bits(&g_02146578.br, n)];
    dst[8] = g_02146588[read_bits(&g_02146578.br, 8)];
    dst[9] = g_02146588[read_bits(&g_02146578.br, n)];
    dst[10] = g_02146588[read_bits(&g_02146578.br, 8)];
    dst[11] = g_02146588[read_bits(&g_02146578.br, n)];
    dst[12] = g_02146588[read_bits(&g_02146578.br, 8)];
    dst[13] = g_02146588[read_bits(&g_02146578.br, n)];
    dst[14] = g_02146588[read_bits(&g_02146578.br, 8)];
    dst[15] = g_02146588[read_bits(&g_02146578.br, n)];
}



/*
 * Opens the bit reader the glyph decompressor in this packet runs on: the
 * cursor at +0 is the byte pointer, +4 is the number of bits still unread out
 * of the byte cached at +8, and the first byte is latched on the spot.
 *
 * Twelve bytes, no prologue: the function saves nothing, so disasm.py's
 * prologue sweep never labels it and it prints as part of the `.word` run in
 * front of func_0201E4D4
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * The bit count is assigned last.  Written before the cached byte the two
 * stores swap and the constant 8 is materialised earlier, four bytes wrong.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201E4C8.c \
 *       --func func_0201E4C8 --addr 0x0201E4C8 --cc 1.1p1 --thumb
 */
void func_0201E4C8(struct BitReader_0201E4C8 *b, const u8 *p)
{
    b->src = p;
    b->cur = p[0];
    b->nbits = 8;
}


/*
 * The bit reader behind the compressed glyph stream: pulls `n` bits out of a
 * byte stream, most significant bit first.  The state is three fields, the
 * read pointer at +0, the number of bits still unconsumed in the byte at +4,
 * and that byte itself at +8; g_0209E74C is the 0..8 entry table of top-bit
 * masks.  When the request straddles a byte boundary the leading bits are
 * taken first, the next byte is fetched, and the two halves are OR'd back
 * together.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201E4D4.c
 *       --func sub_0201E4D4 --addr 0x0201E4D4 --cc 1.1p1 --thumb
 */
u8 sub_0201E4D4(struct BitReader_0201E4D4 *r, u8 n)
{
    u8  hi;
    u32 lo;
    u8  cur;
    u32 used;

    if (r->avail < n) {
        hi = r->cur;
        hi &= g_0209E74C[r->avail];
        used = r->avail;
        n = (u8)(n - (u8)used);
        r->src++;
        r->cur = *r->src;
        r->avail = 8;
    } else {
        hi = 0;
        used = 0;
    }

    cur = r->cur;
    lo = g_0209E74C[n] & cur;
    r->avail = r->avail - n;
    if (r->avail == 0) {
        r->src++;
        r->cur = *r->src;
        r->avail = 8;
    } else {
        r->cur = (u8)(cur << n);
    }
    return (u8)((lo >> used) | hi);
}
