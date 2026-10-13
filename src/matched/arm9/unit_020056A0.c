/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x020056A0
 * packet:   pkt_020051D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GFL_USE_AddMainTask, GFL_USE_GetMainTaskList, GFL_USE_InitRandomState, GFL_USE_InitRandom, GFL_USE_GetRandom, GFL_USE_GetRandomBelow
 *
 * symbols:
 *   sub_020056A0_Sys  0x020AA194  data
 *   func_02030DA8     0x02030DA8  arm
 *   func_0203F034     0x0203F034  arm
 *   func_0203F258     0x0203F258  arm
 *   _ull_mul          0x0209C054  arm
 *
 * The tail of the packet: the second heap's allocator wrapper, the shutdown
 * pair, and the two random number draws.  0x020AA194 is the same system
 * record src/matched/unit_0200560C.c reaches, and the pointer at its +0x10 is
 * the same object; the two files name it separately because each pins its own
 * address block.
 *
 * The two draws are a 64 bit linear congruential generator.  0x0209C054 is
 * mwccarm's own `_ull_mul` runtime helper (`umull` plus two `mla`, ARM, at the
 * near end of the helper block that also holds `_u32_div_f`), so the pair of
 * calls in each function is one 64 bit multiply each and not an SDK call:
 *
 *   seed = mul * seed + add;
 *   return (u32)(((seed >> 32) * range) >> 32);
 *
 * The second multiply is what makes the shape readable.  `range` is a u32 and
 * so is the high half of the seed, but the helper is called with r1 and r3
 * both zeroed, which is two operands already widened to 64 bits; that is
 * `(seed >> 32) * range` on a `u64` seed and not a `umull` of two words, and
 * taking the returned r1 is the `>> 32`.  GFL_USE_GetRandom is the same draw with
 * a range of zero meaning "the whole word", and its two arms merge on r1,
 * which is why the zero arm loads the high half into r1 and moves rather than
 * loading it into r0.
 *
 * GFL_USE_GetRandom reloads the high half from memory after the step and
 * GFL_USE_GetRandomBelow keeps it in the register the `adcs` left it in.  That is not a
 * difference in the source: it falls out of the branch in the first one, and
 * both come from the same expression.
 *
 * Three of the six carry no label, all because they save nothing.
 * GFL_USE_GetMainTaskList is a two load getter and GFL_USE_InitRandomState is a tail call through a
 * pool word.  GFL_USE_InitRandomState is in this range rather than a range of its own
 * because GFL_USE_InitRandom is its only caller anywhere in the image, so the call
 * has to be the `local` class; splitting them leaves it with no witness at
 * all.
 *
 * ------------------------------------------------------------------------
 * The near miss register for pkt_020051D8
 *
 * This packet is the system boot path, and that is exactly the shape of code
 * the honesty rule is hardest on: it calls each subsystem's initialiser once
 * and nothing else in the 3.9 MB image calls it again, so the only witness
 * for the target address is the call under test.  Of the packet's 1160 code
 * bytes, 334 are matched in four files (0x0200530C, 0x02005430, 0x0200560C,
 * 0x020056A0) and the rest is listed here with the class and the census that
 * blocks it.  None of it is a codegen failure; nothing below was written and
 * then rejected for wrong bytes.
 *
 *   0x020051D8..0x02005202, 42 bytes.  `label`, 0x0203D26C has one witness
 *       image wide and it is the `blx` at 0x020051E6 inside the function.
 *   0x02005204..0x0200520C, 8 bytes.  A tail call whose pool word holds
 *       0x02005611.  0x02005610 has no `func_` label, because it saves
 *       nothing, and the word appears in exactly one literal pool in the
 *       image, its own at 0x02005208, so `label` has no label and `literal`
 *       discards its only witness.  Seeding the label would not help: nothing
 *       in the image branches to 0x02005610 either.
 *   0x0200520C..0x02005230, 36 bytes.  `label`, the only caller of
 *       GFL_USE_CallVBlankHook is the `bl` at 0x0200520E.  GFL_USE_CallVBlankHook is matched, in
 *       src/matched/unit_0200560C.c, but it is 0x434 bytes away with two
 *       blocked functions and three linker veneers in between, so no
 *       contiguous range makes the site `local`.
 *   0x02005230..0x0200523C, 12 bytes.  `label` twice: the only caller of
 *       GFL_USE_PollTwlService is the `bl` at 0x02005232 and the only caller of
 *       sub_0200567C is the `bl` at 0x02005236.  Same obstruction as above in
 *       both directions at once.
 *   0x0200523C..0x020052EC, 176 bytes.  19 unresolved sites, 18 of them
 *       `label` with a census of one, plus 0x020A0480 whose only literal
 *       witness is the pool word at 0x020052DC.  This is the once-per-boot
 *       call sequence itself.
 *   0x020052EC..0x0200530C, 32 bytes.  5 unresolved sites, all `label` with a
 *       census of one.
 *   0x02005328..0x020053E4, 188 bytes.  11 unresolved sites.  Two are
 *       structural rather than merely rare: the veneer at 0x020053E4, whose
 *       only witness is the `blx` at 0x020053AA, and the pool word at
 *       0x020053DC naming sub_02005440, an address no other word or branch in
 *       the image mentions.
 *   0x020053EC..0x02005420, 52 bytes.  The veneers at 0x02005420 and
 *       0x02005428, each witnessed only by its own call site at 0x02005400
 *       and 0x02005412, plus EL_Export at 0x020351D0 with a census of one.
 *   0x02005438..0x02005440, 8 bytes.  `literal`, CTRDG_DummyInit at
 *       0x020911A0 is named by exactly one word in the image and it is this
 *       function's own pool word at 0x0200543C.  It is a labelled SDK symbol,
 *       but no branch anywhere reaches it, so the `label` class has nothing.
 *   0x02005440..0x02005454, 20 bytes.  The veneer at 0x02005454, witnessed
 *       only by the `blx` at 0x02005444.
 *   0x0200545C..0x020055F8, 412 bytes.  19 unresolved sites; the packet's
 *       largest function and its arena, heap and DWC set up.
 *   0x020055F8..0x0200560C, 20 bytes.  3 unresolved sites, all with a census
 *       of one.
 *   0x0200567C..0x020056A0, 36 bytes.  One unresolved site: 0x02050A70,
 *       `label`, one witness image wide and it is the `blx` at 0x0200568C
 *       inside the function.  This is the single function that keeps
 *       src/matched/unit_0200560C.c and this file apart; the day anything
 *       else in the image calls 0x02050A70, the two files and it become one
 *       336 byte range.
 *
 * The four ARM stubs at 0x020053E4, 0x02005420, 0x02005428 and 0x02005454 are
 * not functions and are in no file here.  Each is `ldr pc, [pc, #-4]` and a
 * pointer word, and each pointer (0x0273154C, 0x027315D0, 0x027314F0,
 * 0x027315C0) lies outside every region of layout/layout.json, which is why
 * the `veneer` attestation class cannot carry them: its fourth condition
 * wants the pointer to name code in a known region.  See
 * docs/idioms/a-four-byte-arm-function-in-a-thumb-packet-is-a-long-branch-veneer.md
 * for what they are and why they force the unit boundaries in this packet.
 * ------------------------------------------------------------------------
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020056A0.c \
 *       --addr 0x020056A0 --thumb
 */

typedef unsigned int       u32;
typedef unsigned long long u64;

struct Sub020056A0Heaps {
    u64   seed;
    u64   mul;
    u64   add;
    void *unk18;
    void *unk1C;
    void *unk20;
    void *unk24;
};

struct Sub020056A0Sys {
    void *unk00;
    u32   unk04;
    void (*unk08)(void *);
    u32   unk0C;
    struct Sub020056A0Heaps *unk10;
    void *unk14;
};

extern struct Sub020056A0Sys sub_020056A0_Sys;

struct Ctx;
struct Lcg64;
struct Node;
extern struct Node *func_02030DA8(struct Ctx *c, void (*callback)(struct Node *, void *), void *work, u32 key);
extern void  func_0203F034(u32 seed);
extern void func_0203F258(struct Lcg64 *out);

void GFL_USE_InitRandomState(void *heap);
u32  GFL_USE_GetRandom(u32 range);

void *GFL_USE_AddMainTask(void (*callback)(struct Node *, void *), void *work, u32 key)
{
    return func_02030DA8(sub_020056A0_Sys.unk10->unk20, callback, work, key);
}

void *GFL_USE_GetMainTaskList(void)
{
    return sub_020056A0_Sys.unk10->unk20;
}

void GFL_USE_InitRandomState(void *heap)
{
    func_0203F258(heap);
}

void GFL_USE_InitRandom(void)
{
    GFL_USE_InitRandomState(sub_020056A0_Sys.unk10);
    func_0203F034(GFL_USE_GetRandom(0));
}

u32 GFL_USE_GetRandom(u32 range)
{
    struct Sub020056A0Heaps *p = sub_020056A0_Sys.unk10;
    u32 v;

    p->seed = p->mul * p->seed + p->add;
    if (range == 0) {
        v = (u32)(p->seed >> 32);
    } else {
        v = (u32)(((p->seed >> 32) * range) >> 32);
    }
    return v;
}

u32 GFL_USE_GetRandomBelow(u32 range)
{
    struct Sub020056A0Heaps *p = sub_020056A0_Sys.unk10;

    p->seed = p->mul * p->seed + p->add;
    return (u32)(((p->seed >> 32) * range) >> 32);
}
