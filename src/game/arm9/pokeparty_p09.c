/*
 * file:     pokeparty_p09.c
 * unit:     yes
 * function: func_0201C314, func_0201C328, func_0201C3C0, func_0201C41C, func_0201C440, func_0201C450, func_0201C4C0, func_0201C4C8, func_0201C4DC, func_0201C4E4
 * address:  0x0201C314
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
 *   gWazaTool          0x02146530  data
 *   sub_0201C328_File  0x020A7340  data
 *   g_02146558         0x02146558  data
 *   sub_0201C450_File   0x020A734C  data
 *   func_0201DE00  0x0201DE00  thumb
 *   func_0201DE18  0x0201DE18  thumb
 *   func_0201DD78  0x0201DD78  thumb
 *   func_020870D0  0x020870D0  arm
 *   func_0201C974  0x0201C974  thumb
 *   func_0201D7C4  0x0201D7C4  thumb
 */
struct Bmp;
struct PrintCtx;
typedef unsigned int u32;

typedef unsigned short u16;

typedef int            s32_0201C328;

struct WazaTool {
    void **recs;
    u16  *vals;
    s32_0201C328   count;
};

typedef unsigned char      u8;

typedef unsigned long long u64;

union Ticks {
    u64 v;
    struct {
        u32 lo;
        u32 hi;
    } w;
};

struct PrintSys_0201C450 {
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u8  unk06;
    u8  unk07;
    union Ticks unk08;
    void *unk10;
    void *unk14;
};

typedef signed int          s32_0201C4E4;

struct Rec {
    u32 unk00;
    u32 pad04a : 20;
    s32_0201C4E4 kind   : 4;
    u32 pad04b : 8;
    u32 pad08;
    u16 pad0C;
    u16 unk0E;
};

struct PrintSys_0201C4E4 {
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u8  unk06;
    u8  unk07lo : 4;
    u8  unk07hi : 4;
    u64 unk08;
    struct Rec *unk10;
    u16 *unk14;
    u8  buf[4];
};

extern u32 sub_0201BD28(void *p, u32 id);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_020457A0(u16 stamp);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u32 heap);
extern void  func_0201DE00(u8 *r, u8 *g, u8 *b);
extern u32   func_0201DE18(u32 r, u32 g, u32 b);
extern void  func_0201DD78(u32 r, u32 g, u32 b);
extern u64   func_020870D0(void);
extern u16 *func_0201C974(struct PrintCtx *c, u16 *p, u32 f);
extern void *func_0201D7C4(struct PrintSys_0201C4E4 *p, void *q);
u32 sub_0201C314(void *p);
void sub_0201C328(s32_0201C328 n, u32 heap);
void sub_0201C3C0(void);
u32 sub_0201C408(void);
void sub_0201C41C(void *arg);
u32 sub_0201C440(void *p);
void *sub_0201C450(u16 n, u32 heap);
extern struct WazaTool *gWazaTool;
extern const char sub_0201C328_File[];
extern void *g_02146558;
extern const char sub_0201C450_File[];


/*
 * A boolean wrapper around sub_0201BD28 (see src/matched/unit_0201C1C8.c),
 * id 3 again, this time reduced to 0/1 rather than truncated to a halfword.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C314.c \
 *       --addr 0x0201C314 --thumb
 */
u32 sub_0201C314(void *p)
{
    if (sub_0201BD28(p, 3) == 0) {
        return 0;
    }
    return 1;
}


/*
 * waza_tool.c: the module's constructor, its destructor, its "is it up"
 * predicate, and (folded back in this run) sub_0201C41C, which resets
 * something with 0xFFFF and hands func_02043678's result to the static at
 * 0x02146558.  sub_0201C41C used to be cut out into src/pending/sub_0201C41C.c
 * because its one call, to func_020457A0, had no witness anywhere in the
 * image; func_020457A0 is now EXACT in src/matched/sub_020457A0.c, giving the
 * `matched` class a witness, so the range folds back into one unit.  The file
 * name is the image's own, 0x020A7340 spelling "waza_tool.c" between
 * "shinka_check.c" and "printsys.c".
 *
 * The module object at 0x02146530 is three words: an array of `n` pointers to
 * 0x24 byte records, an array of `n` halfwords, and `n` itself.  Each of the
 * four allocations passes a different __LINE__, and the four values 577, 578,
 * 579 and 584 are visible in the bytes as one pool word holding 577 and three
 * `adds r0, r0, #k` off it, which is what fixes both the line numbers and the
 * order of the statements.  577 is too large for a `movs` immediate, so the
 * first one is a pool word rather than a relocation
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md is the
 * case where it is the other way round).
 *
 * sub_0201C408 is an unlabelled follower: eight halfwords with no prologue
 * sitting between two literal pools, which the listing prints as `.word` data
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  Its `!= 0`
 * arm is the fall-through, so the source returns 1 first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C328.c \
 *       --addr 0x0201C328 --thumb
 */
void sub_0201C328(s32_0201C328 n, u32 heap)
{
    s32_0201C328 i;

    if (gWazaTool != 0) {
        return;
    }
    gWazaTool = (struct WazaTool *)func_02030734(heap, sizeof(struct WazaTool), 0,
                                                sub_0201C328_File, 577);
    gWazaTool->recs = (void **)func_02030734(heap, n * sizeof(void *), 0,
                                             sub_0201C328_File, 578);
    gWazaTool->vals = (u16 *)func_02030734(heap, n * sizeof(u16), 0,
                                           sub_0201C328_File, 579);
    gWazaTool->count = n;
    for (i = 0; i < n; i++) {
        gWazaTool->recs[i] = func_02030734(heap, 0x24, 0, sub_0201C328_File, 584);
        gWazaTool->vals[i] = 0;
    }
}


/*
 * waza_tool.c: the module's constructor, its destructor, its "is it up"
 * predicate, and (folded back in this run) sub_0201C41C, which resets
 * something with 0xFFFF and hands func_02043678's result to the static at
 * 0x02146558.  sub_0201C41C used to be cut out into src/pending/sub_0201C41C.c
 * because its one call, to func_020457A0, had no witness anywhere in the
 * image; func_020457A0 is now EXACT in src/matched/sub_020457A0.c, giving the
 * `matched` class a witness, so the range folds back into one unit.  The file
 * name is the image's own, 0x020A7340 spelling "waza_tool.c" between
 * "shinka_check.c" and "printsys.c".
 *
 * The module object at 0x02146530 is three words: an array of `n` pointers to
 * 0x24 byte records, an array of `n` halfwords, and `n` itself.  Each of the
 * four allocations passes a different __LINE__, and the four values 577, 578,
 * 579 and 584 are visible in the bytes as one pool word holding 577 and three
 * `adds r0, r0, #k` off it, which is what fixes both the line numbers and the
 * order of the statements.  577 is too large for a `movs` immediate, so the
 * first one is a pool word rather than a relocation
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md is the
 * case where it is the other way round).
 *
 * sub_0201C408 is an unlabelled follower: eight halfwords with no prologue
 * sitting between two literal pools, which the listing prints as `.word` data
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  Its `!= 0`
 * arm is the fall-through, so the source returns 1 first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C328.c \
 *       --addr 0x0201C328 --thumb
 */
void sub_0201C3C0(void)
{
    s32_0201C328 i;

    if (gWazaTool != 0) {
        for (i = 0; i < gWazaTool->count; i++) {
            func_020307B0(gWazaTool->recs[i]);
        }
        func_020307B0(gWazaTool->vals);
        func_020307B0(gWazaTool->recs);
        func_020307B0(gWazaTool);
        gWazaTool = 0;
    }
}


/*
 * waza_tool.c: the module's constructor, its destructor, its "is it up"
 * predicate, and (folded back in this run) sub_0201C41C, which resets
 * something with 0xFFFF and hands func_02043678's result to the static at
 * 0x02146558.  sub_0201C41C used to be cut out into src/pending/sub_0201C41C.c
 * because its one call, to func_020457A0, had no witness anywhere in the
 * image; func_020457A0 is now EXACT in src/matched/sub_020457A0.c, giving the
 * `matched` class a witness, so the range folds back into one unit.  The file
 * name is the image's own, 0x020A7340 spelling "waza_tool.c" between
 * "shinka_check.c" and "printsys.c".
 *
 * The module object at 0x02146530 is three words: an array of `n` pointers to
 * 0x24 byte records, an array of `n` halfwords, and `n` itself.  Each of the
 * four allocations passes a different __LINE__, and the four values 577, 578,
 * 579 and 584 are visible in the bytes as one pool word holding 577 and three
 * `adds r0, r0, #k` off it, which is what fixes both the line numbers and the
 * order of the statements.  577 is too large for a `movs` immediate, so the
 * first one is a pool word rather than a relocation
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md is the
 * case where it is the other way round).
 *
 * sub_0201C408 is an unlabelled follower: eight halfwords with no prologue
 * sitting between two literal pools, which the listing prints as `.word` data
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  Its `!= 0`
 * arm is the fall-through, so the source returns 1 first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C328.c \
 *       --addr 0x0201C328 --thumb
 */
u32 sub_0201C408(void)
{
    if (gWazaTool != 0) {
        return 1;
    }
    return 0;
}


/*
 * waza_tool.c: the module's constructor, its destructor, its "is it up"
 * predicate, and (folded back in this run) sub_0201C41C, which resets
 * something with 0xFFFF and hands func_02043678's result to the static at
 * 0x02146558.  sub_0201C41C used to be cut out into src/pending/sub_0201C41C.c
 * because its one call, to func_020457A0, had no witness anywhere in the
 * image; func_020457A0 is now EXACT in src/matched/sub_020457A0.c, giving the
 * `matched` class a witness, so the range folds back into one unit.  The file
 * name is the image's own, 0x020A7340 spelling "waza_tool.c" between
 * "shinka_check.c" and "printsys.c".
 *
 * The module object at 0x02146530 is three words: an array of `n` pointers to
 * 0x24 byte records, an array of `n` halfwords, and `n` itself.  Each of the
 * four allocations passes a different __LINE__, and the four values 577, 578,
 * 579 and 584 are visible in the bytes as one pool word holding 577 and three
 * `adds r0, r0, #k` off it, which is what fixes both the line numbers and the
 * order of the statements.  577 is too large for a `movs` immediate, so the
 * first one is a pool word rather than a relocation
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md is the
 * case where it is the other way round).
 *
 * sub_0201C408 is an unlabelled follower: eight halfwords with no prologue
 * sitting between two literal pools, which the listing prints as `.word` data
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  Its `!= 0`
 * arm is the fall-through, so the source returns 1 first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C328.c \
 *       --addr 0x0201C328 --thumb
 */
void sub_0201C41C(void *arg)
{
    func_020457A0(0xFFFF);
    g_02146558 = func_02043678(2, 2, 0x20, (u32)arg);
}


/*
 * A 12-byte pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), swapping its own
 * parameter into the callee's second argument slot and passing the literal
 * 0x400 as the first: `sub_0201C450(0x400, p)`.  sub_0201C450 (0x0201C450)
 * is a bigger constructor with an inline division-by-multiplication trick
 * and is left as an unresolved extern; only its address is needed here.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C440.c \
 *       --addr 0x0201C440 --thumb
 */
u32 sub_0201C440(void *p)
{
    return (u32)sub_0201C450(0x400, (u32)p);
}


/*
 * The head of printsys.c: the module constructor and three accessors on the
 * object it builds.  The file identity is in the image, the same way
 * src/matched/unit_0201D69C.c recovers gf_font.c: the constructor loads
 * 0x020A734C as the debug allocator's __FILE__ argument and the bytes there
 * spell "printsys.c", with "waza_tool.c" ending at 0x020A734B so the `string`
 * class carries the address.  The __LINE__ argument is 287.
 *
 * The constructor was a documented two-byte near miss and this is what closed
 * it: the field at +8 is one `u64`, not two `u32`.  Written as two words the
 * whole function is right except that the pool constant 0x1130 arrives in r1
 * instead of r2; assigning it to a 64 bit field makes the compiler take the
 * other scratch register, because the high half comes from the register that
 * already holds zero.  See
 * docs/idioms/a-u64-field-store-picks-a-different-scratch-register.md.
 *
 * sub_0201C4DC writes the two halves of that u64 separately, which is what
 * fixes the field as a union of the 64 bit value and a two-word struct rather
 * than a plain `u64` (docs/idioms/long-long-aligns-to-four.md is why +8 is a
 * legal offset for it at all).
 *
 * The size the constructor allocates is (u16)(n + 0x1C) rounded up to a
 * multiple of four and then + 0x18, and the rounding is a `while (v % 4)` loop
 * over a `u16` local: the signed `lsrs #31` / `lsls #30` / `subs` / `rors #30`
 * quartet is `% 4` on the promoted int, exactly as src/matched/sub_0200A6BC.c
 * records for `% 8`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C450.c \
 *       --addr 0x0201C450 --thumb
 */
void *sub_0201C450(u16 n, u32 heap)
{
    u16 v = n + 0x1C;
    struct PrintSys_0201C450 *p;

    while (v % 4 != 0) {
        v++;
    }
    p = func_02030734(heap, v + 0x18, 0, sub_0201C450_File, 287);
    p->unk04 = n;
    p->unk08.v = 0x1130;
    p->unk10 = 0;
    p->unk14 = 0;
    ((u8 *)p)[7] = ((u8 *)p)[7] & ~0xFu;
    ((u8 *)p)[7] = ((u8 *)p)[7] & ~0xF0u;
    p->unk06 = 0;
    p->unk00 = 0;
    p->unk02 = n;
    return p;
}


/*
 * The head of printsys.c: the module constructor and three accessors on the
 * object it builds.  The file identity is in the image, the same way
 * src/matched/unit_0201D69C.c recovers gf_font.c: the constructor loads
 * 0x020A734C as the debug allocator's __FILE__ argument and the bytes there
 * spell "printsys.c", with "waza_tool.c" ending at 0x020A734B so the `string`
 * class carries the address.  The __LINE__ argument is 287.
 *
 * The constructor was a documented two-byte near miss and this is what closed
 * it: the field at +8 is one `u64`, not two `u32`.  Written as two words the
 * whole function is right except that the pool constant 0x1130 arrives in r1
 * instead of r2; assigning it to a 64 bit field makes the compiler take the
 * other scratch register, because the high half comes from the register that
 * already holds zero.  See
 * docs/idioms/a-u64-field-store-picks-a-different-scratch-register.md.
 *
 * sub_0201C4DC writes the two halves of that u64 separately, which is what
 * fixes the field as a union of the 64 bit value and a two-word struct rather
 * than a plain `u64` (docs/idioms/long-long-aligns-to-four.md is why +8 is a
 * legal offset for it at all).
 *
 * The size the constructor allocates is (u16)(n + 0x1C) rounded up to a
 * multiple of four and then + 0x18, and the rounding is a `while (v % 4)` loop
 * over a `u16` local: the signed `lsrs #31` / `lsls #30` / `subs` / `rors #30`
 * quartet is `% 4` on the promoted int, exactly as src/matched/sub_0200A6BC.c
 * records for `% 8`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C450.c \
 *       --addr 0x0201C450 --thumb
 */
void sub_0201C4C0(struct PrintSys_0201C450 *p)
{
    func_020307B0(p);
}

/*
 * The head of printsys.c: the module constructor and three accessors on the
 * object it builds.  The file identity is in the image, the same way
 * src/matched/unit_0201D69C.c recovers gf_font.c: the constructor loads
 * 0x020A734C as the debug allocator's __FILE__ argument and the bytes there
 * spell "printsys.c", with "waza_tool.c" ending at 0x020A734B so the `string`
 * class carries the address.  The __LINE__ argument is 287.
 *
 * The constructor was a documented two-byte near miss and this is what closed
 * it: the field at +8 is one `u64`, not two `u32`.  Written as two words the
 * whole function is right except that the pool constant 0x1130 arrives in r1
 * instead of r2; assigning it to a 64 bit field makes the compiler take the
 * other scratch register, because the high half comes from the register that
 * already holds zero.  See
 * docs/idioms/a-u64-field-store-picks-a-different-scratch-register.md.
 *
 * sub_0201C4DC writes the two halves of that u64 separately, which is what
 * fixes the field as a union of the 64 bit value and a two-word struct rather
 * than a plain `u64` (docs/idioms/long-long-aligns-to-four.md is why +8 is a
 * legal offset for it at all).
 *
 * The size the constructor allocates is (u16)(n + 0x1C) rounded up to a
 * multiple of four and then + 0x18, and the rounding is a `while (v % 4)` loop
 * over a `u16` local: the signed `lsrs #31` / `lsls #30` / `subs` / `rors #30`
 * quartet is `% 4` on the promoted int, exactly as src/matched/sub_0200A6BC.c
 * records for `% 8`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C450.c \
 *       --addr 0x0201C450 --thumb
 */
void sub_0201C4C8(struct PrintSys_0201C450 *p, u32 v)
{
    ((u8 *)p)[7] = (((u8 *)p)[7] & ~0xF0u) | (u8)((u8)v << 4);
}

/*
 * The head of printsys.c: the module constructor and three accessors on the
 * object it builds.  The file identity is in the image, the same way
 * src/matched/unit_0201D69C.c recovers gf_font.c: the constructor loads
 * 0x020A734C as the debug allocator's __FILE__ argument and the bytes there
 * spell "printsys.c", with "waza_tool.c" ending at 0x020A734B so the `string`
 * class carries the address.  The __LINE__ argument is 287.
 *
 * The constructor was a documented two-byte near miss and this is what closed
 * it: the field at +8 is one `u64`, not two `u32`.  Written as two words the
 * whole function is right except that the pool constant 0x1130 arrives in r1
 * instead of r2; assigning it to a 64 bit field makes the compiler take the
 * other scratch register, because the high half comes from the register that
 * already holds zero.  See
 * docs/idioms/a-u64-field-store-picks-a-different-scratch-register.md.
 *
 * sub_0201C4DC writes the two halves of that u64 separately, which is what
 * fixes the field as a union of the 64 bit value and a two-word struct rather
 * than a plain `u64` (docs/idioms/long-long-aligns-to-four.md is why +8 is a
 * legal offset for it at all).
 *
 * The size the constructor allocates is (u16)(n + 0x1C) rounded up to a
 * multiple of four and then + 0x18, and the rounding is a `while (v % 4)` loop
 * over a `u16` local: the signed `lsrs #31` / `lsls #30` / `subs` / `rors #30`
 * quartet is `% 4` on the promoted int, exactly as src/matched/sub_0200A6BC.c
 * records for `% 8`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201C450.c \
 *       --addr 0x0201C450 --thumb
 */
void sub_0201C4DC(struct PrintSys_0201C450 *p, u32 lo, u32 hi)
{
    p->unk08.w.lo = lo;
    p->unk08.w.hi = hi;
}


static inline u16 Wrap(struct PrintSys_0201C4E4 *ps, u16 o)
{
    u16 r = o;

    if (r >= ps->unk04)
        r = 0;
    return r;
}

/*
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`base = (u8 *)ps;` before `base = (u8 *)ps + 0x18;`). Game code has no
 * line table, so these were stand-ins. The plain single assignment gives
 * EXACT in --lang c99 and --lang c: the output bytes do not change. Older
 * text in this header that asks for the double assignment is superseded.
 *
 * printsys.c: the per-frame print pump.  Bumps the frame counter at +6,
 * saves the current text colour, applies the head request's colour when its
 * 4-bit kind is 0 or 2, then runs glyphs through func_0201C974 until the
 * string ends or the tick budget at +8 (func_020870D0 is OS_GetTick) runs
 * out.  On string end it pops the request (func_0201D7C4) and moves the
 * glyph cursor to the next record's text in the byte ring at +0x18,
 * wrapping twice at the ring size.  Restores the colour and reports idle.
 *
 * The last five bytes closed on the SHAPE OF THE INLINE WRAP HELPER: it
 * copies its parameter into a named local, conditionally zeroes the local
 * and returns it (`u16 r = o; if (r >= size) r = 0; return r;`).  The
 * early-return spelling (`if (o >= size) return 0; return o;`) truncates
 * `off + 0x1C` in place and hoists the ring-size load between the two
 * shifts; the named-local spelling keeps the image's
 * `lsls r0, r7 / lsrs r1, r0 / ldrh r0, [r5, #4]` order.  History in
 * docs/notes/sub_0201C4E4.c.txt.
 */
u32 func_0201C4E4(struct PrintSys_0201C4E4 *ps)
{
    u16 cap;
    u8  col[3];
    u32 stop;
    u16 saved;
    u32 rr;
    u32 bb;
    u8 *base;
    u32 r;
    u32 g;
    u32 b;
    u32 go;
    u32 gg;
    u32 off;
    u16 o;
    u64 t0;

    stop = 0;
    ps->unk06 = (u8)(ps->unk06 + 1);
    if (ps->unk10 == 0) {
        return 1;
    }
    func_0201DE00(&col[2], &col[1], &col[0]);
    saved = (u16)(((col[2] & 0x1F) << 10) | ((col[1] & 0x1F) << 5) |
                  (col[0] & 0x1F));
    go = 0;
    if (ps->unk10->kind == 0 || ps->unk10->kind == 2) {
        r = (u8)((ps->unk10->unk0E >> 10) & 0x1F);
        g = (u8)((ps->unk10->unk0E >> 5) & 0x1F);
        b = (u8)(ps->unk10->unk0E & 0x1F);
        go = 1;
    }
    if (go != 0) {
        if (func_0201DE18(r, g, b) != 0) {
            func_0201DD78(r, g, b);
        }
    }
    t0 = func_020870D0();
    if (ps->unk10 != 0) {
        base = (u8 *)ps + 0x18;
        do {
            if (ps->unk10->kind == 1) {
                rr = (u8)((ps->unk10->unk0E >> 10) & 0x1F);
                gg = (u8)((ps->unk10->unk0E >> 5) & 0x1F);
                bb = (u8)(ps->unk10->unk0E & 0x1F);
                if (func_0201DE18(rr, gg, bb) != 0) {
                    func_0201DD78(rr, gg, bb);
                }
                ps->unk10->kind = 2;
            }
            while (ps->unk14[0] != 0xFFFF) {
                ps->unk14 = func_0201C974((struct PrintCtx *)ps->unk10, ps->unk14, 1);
                if (func_020870D0() - t0 > ps->unk08) {
                    stop = 1;
                    break;
                }
            }
            if (ps->unk14[0] == 0xFFFF) {
                off = (u16)((u8 *)ps->unk10 - base);
                ps->unk10 = func_0201D7C4(ps, ps->unk10);
                if (ps->unk10 != 0) {
                    o = Wrap(ps, off + 0x1C);
                    o = Wrap(ps, o + 4);
                    ps->unk14 = (u16 *)((u8 *)ps + 0x18 + o);
                }
            }
        } while (stop == 0 && ps->unk10 != 0);
    }
    func_0201DD78((u8)((saved >> 10) & 0x1F), (u8)((saved >> 5) & 0x1F),
                  (u8)(saved & 0x1F));
    if (ps->unk10 != 0) {
        ps->unk02 = (u16)((u8 *)ps->unk14 - ((u8 *)ps + 0x18));
        return 0;
    }
    ps->unk00 = 0;
    ps->unk02 = ps->unk04;
    ps->unk07lo = 0;
    return 1;
}
