/*
 * file:     gf_font_p04.c
 * unit:     yes
 * function: func_0201DC44, func_0201DC6C, func_0201DC80, func_0201DC88, func_0201DD58, func_0201DD60, func_0201DD68, func_0201DD78, func_0201DE00, func_0201DE18
 * address:  0x0201DC44
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
 */
#include "../../matched/include/Obj11722.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Font_0201DC44 {
    u32   pad00[2];
    void (*unk08)(const u8 *src, u16 w, void *dst);
    u32   pad0C[19];
    u8    pad58;
    u8    unk59;
};

struct Font_0201DC6C {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    void *unk0C;
    u8  pad10[0x40];
    void *unk50;
    void *unk54;
    u8  unk58[8];
    void *unk60;
    void *unk64;
    void *unk68;
    u32 unk6C;
    u16 unk70;
    u8  unk72;
    u8  pad73;
    u8  unk74;
    u8  unk75;
    u16 unk76;
    u8  pad78[4];
    u16 unk7C;
    u8  unk7E;
    u8  unk7F;
    void *unk80;
    void *unk84;
    void *unk88;
    void *unk8C;
    void *unk90;
};

typedef signed   char  s8;

struct Hdr0201DC88 {
    u8  dflt[3];
    u8  pad3;
    u32 bits;       /* +4 */
    u32 hash;       /* +8 */
    u32 chain;      /* +0xc */
};

typedef signed int     s32;

extern u32 func_0201DB20(struct Font_0201DC6C *p, u16 ch);
u32 func_0201DD58(struct Font_0201DC6C *p);
u32 func_0201DC6C(struct Font_0201DC6C *p, u16 ch);
void func_0201DD68(void);
void func_0201DD78(u32 r, u32 g, u32 b);
void func_0201DE00(u8 *r, u8 *g, u8 *b);
u32 func_0201DE18(u32 r, u32 g, u32 b);
extern u8  g_02146578[3];
extern u16 g_02146588[256];




/*
 * gf_font.c's glyph hand-off: the rendering hook installed at +8 of the font
 * object is called on the glyph bitmap, which starts three bytes into the
 * glyph record, and the record's own three metric bytes plus the byte at +0x59
 * of the font object are copied into the caller's four-byte descriptor.
 *
 * The width is a `u32` parameter and the hook takes it as `u16`, which is what
 * the single `lsls #16` / `lsrs #16` pair before the call is: a `u16`
 * parameter here would make the caller truncate instead and both callers in
 * this packet are two bytes short.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201DC44.c \
 *       --func func_0201DC44 --addr 0x0201DC44 --cc 1.1p1 --thumb
 */
void func_0201DC44(struct Font_0201DC44 *f, const u8 *g, u32 w, void *d, u8 *out)
{
    f->unk08(g + 3, (u16)w, d);
    out[0] = g[0];
    out[1] = g[1];
    out[2] = g[2];
    out[3] = f->unk59;
}



/*
 * The gf_font.c width query and the accessor for the byte at +0x59.
 *
 * func_0201DC6C returns whatever the function pointer at +0x6C returns, and the
 * tail call shape (`ldr r2, [r4, #0x6c]`, `blx r2`, `pop {r4, pc}`) is the same
 * bytes whether the C declares a return value or not, so the return type is
 * fixed by the caller instead: func_0201D528 adds the result to a running width.
 *
 * func_0201DC80 has no label in the listing; it is three halfwords between two
 * literal pools.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201DC6C.c \
 *       --addr 0x0201DC6C --thumb
 */
u32 func_0201DC6C(struct Font_0201DC6C *p, u16 ch)
{
    return ((u32 (*)(struct Font_0201DC6C *, u32))p->unk6C)(p, func_0201DB20(p, ch));
}

/*
 * The gf_font.c width query and the accessor for the byte at +0x59.
 *
 * func_0201DC6C returns whatever the function pointer at +0x6C returns, and the
 * tail call shape (`ldr r2, [r4, #0x6c]`, `blx r2`, `pop {r4, pc}`) is the same
 * bytes whether the C declares a return value or not, so the return type is
 * fixed by the caller instead: func_0201D528 adds the result to a running width.
 *
 * func_0201DC80 has no label in the listing; it is three halfwords between two
 * literal pools.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201DC6C.c \
 *       --addr 0x0201DC6C --thumb
 */
u32 func_0201DC80(struct Font_0201DC6C *p)
{
    return p->unk58[1];
}


/*
 * gf_font.c streamed-glyph lookup: classify glyph `id` through a
 * 2-bit-per-glyph table, fall back to a 9-bit hash, then walk a run of
 * variable-length records for a matching 2-byte code.  See
 * docs/notes/sub_0201DC88.c.txt for the full structural derivation.
 *
 * No relocations: every table is reached through offsets stored in the
 * resource header at obj+0x84.
 *
 * EXACT*, not EXACT: func_0201DD58 immediately after this one is an
 * unlabelled leaf, so the inferred extent runs long (240 vs 208).  Report
 * the unlabelled follower at 0x0201DD58 rather than editing
 * layout/function_starts.txt.
 *
 * The closing lever (2026-09-21): the record header must be read with a
 * fused post-increment, `cnt = *p++;`.  Spelling it as the two statements
 * `cnt = *p; p++;` swaps the cursor and the scan counter between r2 and r3
 * for the whole tail, which is the 17-byte residue the note records.
 */
u8 sub_0201DC88(u8 *obj, u32 id)
{
    struct Hdr0201DC88 *h = *(struct Hdr0201DC88 * *)&((struct Obj11722 *)obj)->f84;
    u32 i = id * 2;
    u8  b = ((u8 *)h + h->bits)[i >> 3];
    u8  k = (u8)((b >> (6 - (i & 7))) & 3);
    u16 slot;
    s8  e;
    u16 n;
    u8 *p;
    u8  cnt;
    u8  idx;

    if (k < 3)
        return ((u8 *)h)[k];

    slot = (u16)(((id & 0x1ff) ^ (u16)(((((id >> 12) ^ (id >> 11)) ^ (id >> 10)) ^ (id >> 9)) & 1) << 3) & 0x1ff);

    e = ((s8 *)((u8 *)h + h->hash))[slot];
    if (e >= 0)
        return (u8)e;

    n = (u16)((u16)(-e) - 1);
    p = (u8 *)h + h->chain;
    while (n != 0) {
        u8 m = *p;
        u16 d = (u16)(n - 1);
        p += m + m * 2 + 1;
        n = d;
    }

    cnt = *p++;
    idx = 0;
    while (idx < cnt) {
        u16 key = (u16)((p[0] << 8) | p[1]);
        if (id == key)
            return p[2];
        idx = (u8)(idx + 1);
        p += 3;
    }
    return obj[0x5e];
}



/*
 * Three unlabelled leaves of gf_font.c: the accessor for the byte at +0x5E and
 * a two-step thunk that resets the text colour to (1, 2, 0).
 *
 * func_0201DD60 and func_0201DD68 are both the pool-word-and-bx shape
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md describes, and neither carries
 * a label, because a tail call saves nothing and the prologue sweep never fires.
 * The chain is real: func_0201DD60 tail-calls func_0201DD68, which tail-calls
 * func_0201DD78 with three constants.  Writing it as one function that calls
 * func_0201DD78 directly loses eight bytes.
 *
 * func_0201DD78 itself, the 4x4x4x4 colour expansion at 0x0201DD78, is still
 * open: the original keeps its two outer loop counters in ip and lr and spills
 * only the third, and no declaration order tried reproduces that split.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201DD58.c \
 *       --addr 0x0201DD58 --thumb
 */
u32 func_0201DD58(struct Font_0201DC6C *p)
{
    return p->unk58[6];
}

/*
 * Three unlabelled leaves of gf_font.c: the accessor for the byte at +0x5E and
 * a two-step thunk that resets the text colour to (1, 2, 0).
 *
 * func_0201DD60 and func_0201DD68 are both the pool-word-and-bx shape
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md describes, and neither carries
 * a label, because a tail call saves nothing and the prologue sweep never fires.
 * The chain is real: func_0201DD60 tail-calls func_0201DD68, which tail-calls
 * func_0201DD78 with three constants.  Writing it as one function that calls
 * func_0201DD78 directly loses eight bytes.
 *
 * func_0201DD78 itself, the 4x4x4x4 colour expansion at 0x0201DD78, is still
 * open: the original keeps its two outer loop counters in ip and lr and spills
 * only the third, and no declaration order tried reproduces that split.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201DD58.c \
 *       --addr 0x0201DD58 --thumb
 */
void func_0201DD60(void)
{
    func_0201DD68();
}



/*
 * Three unlabelled leaves of gf_font.c: the accessor for the byte at +0x5E and
 * a two-step thunk that resets the text colour to (1, 2, 0).
 *
 * func_0201DD60 and func_0201DD68 are both the pool-word-and-bx shape
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md describes, and neither carries
 * a label, because a tail call saves nothing and the prologue sweep never fires.
 * The chain is real: func_0201DD60 tail-calls func_0201DD68, which tail-calls
 * func_0201DD78 with three constants.  Writing it as one function that calls
 * func_0201DD78 directly loses eight bytes.
 *
 * func_0201DD78 itself, the 4x4x4x4 colour expansion at 0x0201DD78, is still
 * open: the original keeps its two outer loop counters in ip and lr and spills
 * only the third, and no declaration order tried reproduces that split.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201DD58.c \
 *       --addr 0x0201DD58 --thumb
 */
void func_0201DD68(void)
{
    func_0201DD78(1, 2, 0);
}


/*
 * gf_font.c's text-colour setter, 136 bytes.  It records the three requested
 * palette indices in g_02146578 (the three bytes src/matched/unit_0201DE00.c
 * reads back) and then rebuilds the 256-entry expansion table at 0x02146588: a
 * byte of four 2-bit pixels indexes it and the halfword it yields is the same
 * four pixels widened to a nibble each.  The four nested loops enumerate the
 * four pixels; the local array is { 0, r, g, b }, so pixel value 0 stays 0 and
 * 1..3 map to the three requested indices.
 *
 * Two details cost time:
 *
 *   - **The disjunction is written innermost-term-first.**  Spelled
 *     `c[i] | c[j] << 4 | c[k] << 8 | c[l] << 12` the left-associated prefix
 *     `c[i] | c[j] << 4` is invariant in the two inner loops, mwcc hoists it,
 *     and the function is four bytes short with the partial results living in
 *     `ip` and `lr`.  Written the other way round, `c[l] << 12` leads and no
 *     prefix of the chain is loop-invariant, so only the three shifted terms
 *     are hoisted, one per loop level, which is what the original does.
 *   - **The four loop counters are signed.**  The back edges are `blt`, not
 *     `blo`; `u32` counters cost four wrong bytes and nothing else.
 *
 * The store order in the prologue is also load-bearing: the four array slots
 * are written first, the three global bytes after them, and the flat output
 * index last.  Any other order leaves the `strb`s and the `str`s interleaved
 * differently and up to eighteen bytes differ, with the instruction multiset
 * unchanged.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201DD78.c \
 *       --func func_0201DD78 --addr 0x0201DD78 --cc 1.1p1 --thumb
 */
void func_0201DD78(u32 r, u32 g, u32 b)
{
    u32 c[4];
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    u32 n;

    c[0] = 0;
    c[1] = r;
    c[2] = g;
    c[3] = b;
    g_02146578[0] = (u8)r;
    g_02146578[1] = (u8)g;
    g_02146578[2] = (u8)b;
    n = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                for (l = 0; l < 4; l++) {
                    g_02146588[n] = (u16)((c[l] << 12) | (c[k] << 8) |
                                          (c[j] << 4) | c[i]);
                    n++;
                }
            }
        }
    }
}


/*
 * The current text colour, read back and compared.  g_02146578 is the three
 * bytes func_0201DD78 stores the last requested colour into.
 *
 * func_0201DE18 returns 1 when the colour differs, and its shape is the
 * disjunction form rather than the conjunction: the first two comparisons branch
 * to one shared `movs r0, #1` block and only the last one branches past it,
 * which is what `if (r != c[0] || g != c[1] || b != c[2]) return 1;` gives.
 * Written as `if (all equal) return 0; return 1;` the arms swap and ten of the
 * forty bytes are wrong
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201DE00.c \
 *       --addr 0x0201DE00 --thumb
 */
void func_0201DE00(u8 *r, u8 *g, u8 *b)
{
    *r = g_02146578[0];
    *g = g_02146578[1];
    *b = g_02146578[2];
}


/*
 * The current text colour, read back and compared.  g_02146578 is the three
 * bytes func_0201DD78 stores the last requested colour into.
 *
 * func_0201DE18 returns 1 when the colour differs, and its shape is the
 * disjunction form rather than the conjunction: the first two comparisons branch
 * to one shared `movs r0, #1` block and only the last one branches past it,
 * which is what `if (r != c[0] || g != c[1] || b != c[2]) return 1;` gives.
 * Written as `if (all equal) return 0; return 1;` the arms swap and ten of the
 * forty bytes are wrong
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201DE00.c \
 *       --addr 0x0201DE00 --thumb
 */
u32 func_0201DE18(u32 r, u32 g, u32 b)
{
    if (r != g_02146578[0] || g != g_02146578[1] || b != g_02146578[2]) {
        return 1;
    }
    return 0;
}
