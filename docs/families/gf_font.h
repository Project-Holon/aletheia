/*
 * docs/families/gf_font.h -- shared declarations for the gf_font.c family
 * (0x0201D7EC..0x0201EC64 in the ARM9 image; the __FILE__ anchor at
 * 0x020A7358 is loaded by func_0201D7EC line 0xC0 and by func_0201D854
 * lines 248/266/271 and func_0201DA24 line 363, which is what names the
 * span).  The edges are soft at both ends: 0x0201D6D8..0x0201D7C4 ahead of
 * it is printsys.c record-ring code that shares the packet, and the tail
 * from 0x0201EC64 onwards is wordset.c (src/matched/unit_0201EC64.c,
 * src/matched/unit_0201ED04.c), a different original file with its own
 * anchor at 0x020A7370.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration
 * below is derived from a file in src/matched that is EXACT, and the
 * matched function that evidences each field or parameter is named in the
 * comment beside it.  Where two matched sources spell the same field
 * differently (they were written by different lanes), the spelling
 * recorded here is the one the byte evidence actually constrains; a field
 * only ever loaded as a word and never dereferenced is left u32.
 *
 * Addresses are Black-image addresses throughout (docs/AGENT-BRIEF.md
 * section 8).  Nothing here encodes a guess about the White layout.
 */

#ifndef GF_FONT_H
#define GF_FONT_H

typedef unsigned char  u8;
typedef signed   char  s8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed   int   s32;

/* ------------------------------------------------------------------ *
 * THE FONT OBJECT.  0x94 bytes, evidenced directly as the literal
 * passed to the allocator by the constructor func_0201D7EC
 * (src/matched/func_0201D7EC.c: `func_02030734(heapId, 0x94, ...)`).
 *
 * The layout below is the union of what four EXACT sources constrain:
 * src/matched/func_0201D7EC.c (the constructor), src/matched/sub_0201D854.c
 * (the metrics/buffer initialiser, which touches the most of it),
 * src/matched/unit_0201D9C8.c (the destructor) and
 * src/matched/unit_0201DC6C.c (the width query).
 *
 * Note that +0x60, +0x64 and +0x68 are declared `u32` here rather than the
 * `void *` unit_0201D9C8.c gives them, because sub_0201D854.c does
 * arithmetic on all three; the loads are identical either way.
 *
 * All of +0x50 and beyond is past the reach of a Thumb `ldr` immediate
 * (+124), so every access to those fields costs an `adds rN, #imm` that is
 * an encoding artefact and not a pointer in the source
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 * ------------------------------------------------------------------ */
struct Font {
    u32   format;    /* +0x00  the glyph format.  func_0201DA00 stores the
                      *        caller's request here and immediately uses it
                      *        as the index into the initialiser table; the
                      *        teardown func_0201DADC reads it back and
                      *        indexes the fini table with it
                      *        (src/matched/sub_0201DA00.c,
                      *        src/matched/sub_0201DADC.c). */
    u32   measure;   /* +0x04  the per-format measure/fetch hook.  Set to
                      *        func_0201DBBC by func_0201DA24 for the
                      *        preloaded format and to func_0201DBF4 by
                      *        func_0201DAA4 for the streamed one; called
                      *        through by func_0201DB04
                      *        (src/matched/unit_0201DAF0.c). */
    u32   decode;    /* +0x08  the per-format glyph decoder, one of the four
                      *        in this file.  Both installers pick it on the
                      *        same 2x2 cross of two flags: a==1 selects the
                      *        first pair, b==1 the first of each pair, so
                      *        the four are func_0201DE40, func_0201E538,
                      *        func_0201E738 and func_0201E928 in that order
                      *        (src/matched/func_0201DAA4.c,
                      *        src/matched/sub_0201DA24.c). */
    u8   *body;      /* +0x0C  the resident glyph body for a preloaded font:
                      *        func_0201DA24 allocates it and reads the whole
                      *        body in; func_0201DBBC copies one glyph out of
                      *        it.  Zero for a streamed font. */
    u8    pad10[0x40];
    void *handle;    /* +0x50  the open resource handle from func_020490F4.
                      *        Every archive read in the file goes through
                      *        it and the destructor closes it with
                      *        func_02049238 (src/matched/unit_0201D9C8.c).
                      *        A null handle makes func_0201D854 return at
                      *        once, so it is the object's validity flag. */
    u32   resid;     /* +0x54  the archive entry id the constructor was
                      *        given (src/matched/func_0201D7EC.c stores a1
                      *        here; func_0201DA24 reads it back as the id
                      *        for its own archive reads). */
    u8    hdr58[8];  /* +0x58  the first eight bytes of the 0x14-byte
                      *        resource header block func_0201D854 reads
                      *        from archive offset 0x18; the remaining
                      *        twelve are the three words below. */
    u32   metricsOff;/* +0x60  offset of the eight metric bytes inside the
                      *        resource.  func_0201D854 reads eight bytes
                      *        from here into &f->cellW, and derives
                      *        glyphDir (+0x8C) as this plus 8. */
    u32   bodyOff;   /* +0x64  offset of the glyph body. */
    u32   bodyEnd;   /* +0x68  one past the glyph body; bodyEnd - bodyOff is
                      *        the preloaded body's size, and bodyEnd is
                      *        also the file-side base the character map's
                      *        absolute next-block pointers are rebased off
                      *        (func_0201DB20). */
    u32   lookup;    /* +0x6C  the glyph-index lookup hook: func_0201DC88 for
                      *        a streamed font, func_0201DD58 for a
                      *        preloaded one.  func_0201DC6C tail-calls
                      *        through it (src/matched/unit_0201DC6C.c). */
    u16   fallback;  /* +0x70  the fallback glyph index, primed by
                      *        func_0201D854 from the glyph for '?' (0x3F)
                      *        and returned by func_0201DB20 whenever a
                      *        character's block has an unknown kind or the
                      *        binary search misses.  func_0201D854 stores
                      *        it TWICE, zero then the lookup result, and
                      *        the first store is not dead: func_0201DB20
                      *        reads the field on the no-block path. */
    u8    preloaded; /* +0x72  the storage-mode flag func_0201D854 records
                      *        from its `flag` parameter: nonzero means
                      *        streamed (no resident body). */
    u8    pad73;
    u8    cellW;     /* +0x74  glyph cell width in pixels, the first of the
                      *        eight metric bytes. */
    u8    cellH;     /* +0x75  glyph cell height in pixels. */
    u16   mapSize;   /* +0x76  the size in bytes of ONE glyph record; also
                      *        the allocation size of the scratch buffer at
                      *        +0x90 and the length of every archive read of
                      *        a single glyph (func_0201DBBC, func_0201DBF4). */
    u8    pad78[4];
    u16   lastCols;  /* +0x7C  (cellW * 2) % 8, with 0 normalised to 8: the
                      *        number of columns in the glyph's last partial
                      *        tile.  func_0201DBBC and func_0201DBF4 pass it
                      *        to func_0201DC44 as the width argument. */
    u8    tilesW;    /* +0x7E  cellW / 8 rounded up, the glyph's tile width.
                      *        func_0201DA00 passes it as the second argument
                      *        to the format initialiser. */
    u8    tilesH;    /* +0x7F  cellH / 8 rounded up; the third argument. */
    void *resHdr;    /* +0x80  the whole resource header, read in one call by
                      *        func_020494F4.  func_0201DBF4 seeks relative
                      *        to it. */
    void *bodyBuf;   /* +0x84  the preloaded glyph body buffer allocated by
                      *        func_0201D854 (null in the streamed case).
                      *        func_0201DC88 reads its own sub-tables through
                      *        the header stored here. */
    void *charMap;   /* +0x88  the character map: a linked list of blocks,
                      *        read by func_0201DB20. */
    void *glyphDir;  /* +0x8C  metricsOff + 8, the glyph directory offset.
                      *        func_0201DBF4 adds it to the record index. */
    void *scratch;   /* +0x90  the one-glyph scratch buffer, mapSize bytes.
                      *        Both fetchers decode into it and hand it to
                      *        func_0201DC44. */
};

/* ------------------------------------------------------------------ *
 * THE CHARACTER MAP BLOCK, read by func_0201DB20
 * (docs/notes/sub_0201DB20.c.txt; the function itself is still DIFF, so
 * this layout is evidenced by the loads, not by an EXACT compile).  Each
 * block covers the inclusive character range [lo, hi] and says in `kind`
 * how the indices inside it are stored:
 *
 *     kind 0   run:    index = data[0] + (c - lo)
 *     kind 1   array:  index = data[(u16)(c - lo)]
 *     kind 2   pairs:  binary search over data[1], data[3], ... with the
 *                      answer in the slot after the matching key
 *     otherwise        the font's `fallback` at +0x70
 *
 * `next` is stored as an absolute address in the ORIGINAL FILE and has to
 * be rebased onto the loaded copy as charMap + (next - bodyEnd); a null
 * next ends the walk and the lookup returns 0.
 * ------------------------------------------------------------------ */
struct MapBlock {
    u16 lo;                /* +0x00 */
    u16 hi;                /* +0x02 */
    u16 kind;              /* +0x04 */
    u16 pad06;
    struct MapBlock *next; /* +0x08  file-absolute, needs rebasing */
    u32 pad0C;
    u16 data[1];           /* +0x0C  the loads are `ldrh ..., #0xc` off the
                            *        block, so the payload starts here. */
};

/* ------------------------------------------------------------------ *
 * THE STREAMED GLYPH HEADER at bodyBuf, read by sub_0201DC88
 * (src/matched/sub_0201DC88.c, EXACT*).  The three offsets are relative
 * to the header itself, so no relocation is involved anywhere in that
 * function.
 * ------------------------------------------------------------------ */
struct GlyphHdr {
    u8  dflt[3];  /* +0x00  the three default indices, selected by the
                   *        2-bit class code when that code is < 3. */
    u8  pad3;
    u32 bitsOff;  /* +0x04  offset of the 2-bit-per-glyph class table. */
    u32 hashOff;  /* +0x08  offset of the 512-entry signed hash table: a
                   *        non-negative entry IS the index, a negative one
                   *        is -(chain position) - 1. */
    u32 chainOff; /* +0x0C  offset of the chain area: a run of
                   *        variable-length records, each a count byte
                   *        followed by that many 3-byte (key16, index8)
                   *        entries. */
};

/* ------------------------------------------------------------------ *
 * THE BIT READER.  Three fields, evidenced twice over: out of line by
 * src/matched/sub_0201E4C8.c (the open) and src/matched/sub_0201E4D4.c
 * (the pull), and inline sixteen times by src/matched/func_0201DE40.c.
 * Bits come out most significant first.
 * ------------------------------------------------------------------ */
struct BitReader {
    const u8 *src;  /* +0x00  the read cursor. */
    u32       avail;/* +0x04  bits still unconsumed in `cur`. */
    u8        cur;  /* +0x08  the byte being consumed. */
};

/* The one global of the file, at 0x02146578: the three text-colour
 * palette indices func_0201DD78 records, immediately followed by the
 * shared bit reader every decoder runs on.  func_0201DE40 accesses the
 * reader's fields at +4/+8/+12 for exactly this reason, where the
 * out-of-line sub_0201E4D4 sees them at +0/+4/+8
 * (src/matched/sub_0201DD78.c, src/matched/func_0201DE40.c). */
struct FontState {
    u8               colour[3];  /* +0x00 */
    u8               pad;
    struct BitReader br;         /* +0x04 */
};

extern struct FontState g_02146578;

/* The 256-entry 2bpp -> 4bpp expansion table func_0201DD78 rebuilds every
 * time the text colour changes: a byte of four 2-bit pixels indexes it and
 * the halfword it yields is the same four pixels widened to a nibble each.
 * Every decoder in the file runs its bytes through it
 * (src/matched/sub_0201DD78.c). */
extern u16 g_02146588[256];

/* The 0..8 table of top-bit masks the bit reader ANDs with
 * (src/matched/sub_0201E4D4.c). */
extern const u8 g_0209E74C[9];

/* The two four-entry dispatch tables, eight bytes apart.  NOTE that the
 * gap is NOT usable as evidence that they are one object: expressing one
 * as an offset from the other would be a claim the image does not make
 * (src/matched/sub_0201DA00.c says so explicitly). */
typedef void (*FontInit)(struct Font *f, u32 tilesW, u32 tilesH, u32 heap);
typedef void (*FontFini)(struct Font *f);
extern FontInit g_0209E73C[4];  /* src/matched/sub_0201DA00.c */
extern FontFini g_0209E744[4];  /* src/matched/sub_0201DADC.c */

/* The packed __FILE__ string for gf_font.c, passed as the fourth argument
 * to every allocation in the file. */
extern const char g_020A7358[];

/* ------------------------------------------------------------------ *
 * PROTOTYPES.  Parameter types are the ones the byte evidence pins, and
 * the evidencing file is named for each.  Where a type is load-bearing in
 * a way that is easy to get wrong, it is called out.
 * ------------------------------------------------------------------ */

/* Lifecycle. */
struct Font *func_0201D7EC(int resFileId, int resid, int fmt, int flag,
                           u32 heapId);
                        /* 0x0201D7EC  src/matched/func_0201D7EC.c */
void  func_0201D854(struct Font *f, u32 resid, u32 flag, u32 heap);
                        /* 0x0201D854  src/matched/sub_0201D854.c */
void  func_0201D83C(void *f);
                        /* 0x0201D83C  src/matched/func_0201D83C.c: the
                         * teardown trio, fini then buffer release then
                         * free. */
void  func_0201D9C8(struct Font *f);
                        /* 0x0201D9C8  src/matched/unit_0201D9C8.c */

/* Format dispatch. */
void  func_0201DA00(struct Font *f, u32 fmt, u32 heap);
                        /* 0x0201DA00  src/matched/sub_0201DA00.c */
void  func_0201DADC(struct Font *f);
                        /* 0x0201DADC  src/matched/sub_0201DADC.c */

/* The two format initialisers.  NOTE the heap-id parameter types: they
 * are NOT the same, and each is fixed by its own byte evidence. */
void  func_0201DA24(struct Font *f, u32 a, u32 b, u8 heap);
                        /* 0x0201DA24  src/matched/sub_0201DA24.c.  `u8`,
                         * not `u32`: the narrow parameter is what forces
                         * the parameter-home store to the FRONT of the
                         * register shuffle, which is nine bytes.  See that
                         * file's header for the full comparison. */
void  func_0201DAA4(char *f, int a, int b);
                        /* 0x0201DAA4  src/matched/func_0201DAA4.c */

/* Glyph fetch and hand-off. */
void  func_0201DBBC(struct Font *f, u32 i, void *d, u8 *out);
                        /* 0x0201DBBC  DIFF, docs/notes/sub_0201DBBC.c.txt */
void  func_0201DBF4(struct Font *f, u32 i, void *d, u8 *out);
                        /* 0x0201DBF4  DIFF, same note */
void  func_0201DC44(struct Font *f, const u8 *g, u32 w, void *d, u8 *out);
                        /* 0x0201DC44  src/matched/sub_0201DC44.c.  `w` is
                         * `u32` here and `u16` in the hook it calls: the
                         * single lsls/lsrs #16 pair before the indirect
                         * call is that conversion, and a `u16` parameter
                         * makes both callers truncate instead and come out
                         * two bytes short. */

/* Index lookup. */
u32   func_0201DB20(struct Font *f, u16 c);
                        /* 0x0201DB20  DIFF, docs/notes/sub_0201DB20.c.txt.
                         * The return type is `u32`, not `u16`: case 0's sum
                         * is returned unnarrowed. */
u8    sub_0201DC88(u8 *f, u32 id);
                        /* 0x0201DC88  src/matched/sub_0201DC88.c */
void  func_0201DD58(void);
                        /* 0x0201DD58  src/matched/unit_0201DD58.c */

/* Colour and the expansion table. */
void  func_0201DD78(u32 r, u32 g, u32 b);
                        /* 0x0201DD78  src/matched/sub_0201DD78.c.  The four
                         * loop counters are SIGNED (the back edges are
                         * `blt`, not `blo`) and the disjunction is written
                         * innermost-term-first; see that file's header. */

/* The bit reader. */
void  func_0201E4C8(struct BitReader *b, const u8 *p);
                        /* 0x0201E4C8  src/matched/sub_0201E4C8.c */
u8    sub_0201E4D4(struct BitReader *r, u8 n);
                        /* 0x0201E4D4  src/matched/sub_0201E4D4.c */

/* The four glyph decoders.  They share one signature, and `n`, the
 * caller's bit depth, must be `u32` in ALL FOUR.  A `u8` parameter lets
 * mwcc treat the register as already zero-extended, drops the per-group
 * re-materialisation of `(u8)n`, and every one of them comes out short. */
void  func_0201DE40(const u8 *src, u32 n, u16 *dst);
                        /* 0x0201DE40  src/matched/func_0201DE40.c: 16
                         * halfwords, the reader INLINED sixteen times
                         * (`static inline` is load-bearing; plain `static`
                         * compiles to sixteen `bl`s). */
void  func_0201E538(const u8 *src, u32 n, u16 *dst);
                        /* 0x0201E538  src/matched/func_0201E538.c: 32
                         * halfwords, flat, widths alternating 8/n. */
void  func_0201E738(const u8 *src, u32 n, u16 *dst);
                        /* 0x0201E738  src/matched/func_0201E738.c: 32
                         * halfwords through two cursors, dst and dst+16,
                         * four at a time, widths 8/8/8/n. */
void  func_0201E928(const u8 *src, u32 n, u16 *dst);
                        /* 0x0201E928  src/matched/func_0201E928.c: 48
                         * halfwords across four tiles, three at a time,
                         * widths 8/8/n. */

/* WAVE 15 (2026-09-23): the object at font+0x88 is a NitroSystem
 * NNSG2dFontCodeMap chain: { u16 ccodeBegin; u16 ccodeEnd; u16 mappingMethod;
 * u16 reserved; struct CMap *pNext; u16 mapInfo[]; } with mapInfo a member
 * array at +0xC (0 direct, 1 table, 2 binary scan over {code, index} pairs
 * after the count).  pNext is rebased as font->unk88 + (pNext - font->unk68).
 * func_0201DB20 is size-exact at 15 out on that shape
 * (docs/notes/sub_0201DB20.c.txt). */

#endif /* GF_FONT_H */
