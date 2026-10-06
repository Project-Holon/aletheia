/*
 * file:     pokeparty_p02.c
 * unit:     yes
 * function: func_02019C38, func_02019C54, func_02019C7C, func_02019C90, func_02019CA0, func_02019CE0
 * address:  0x02019C38
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
 *   gBlockOrder  0x0209E3A4  data
 *   g_02146270   0x02146270  data
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02018584  0x02018584  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 */
struct Personal;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Mon {
    u32 unk00;
    u16 flags;
    u16 unk06;
    u8  block[0x80];
};

struct Memo {
    u16 b;
    u16 a;
    u8  obj[0x10];
};

struct RecDC {
    u32 unk00[0x37];
};

extern void sub_0201ADA4(u32 a, int b, void *dest);
extern u32  func_02017E1C(void *p, u32 id, u32 v);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32  func_02018584(u16 a, u16 b, u16 v);
extern void func_020185C4(void *p);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
void *func_02019C38(struct Mon *p, u32 pid, u32 n);
u32 func_02019C7C(void *h);
u32 func_02019C90(u16 a, u16 b, u32 k);
void func_02019CA0(void *p, u32 v);
extern const u8 gBlockOrder[32][4];
extern struct Memo g_02146270;



/*
 * note:     28 bytes including its pool word, one function
 * note:     re-verified 2026-09-21: EXACT.  The MATCH cap was lifted by the
 *           sole-ref widening of 2026-09-21, not by any edit to the C:
 *           the data address this file reaches now attests as
 *           sole-ref/data.  Promoted from src/pending/ unchanged.
 *
 * The substruct permuter the whole poke_tool.c field machinery reaches every
 * block through: bits 13 to 17 of the personality word select one of 32
 * orderings, and the ordering's n-th byte is the offset of the n-th 0x20 byte
 * substruct inside the 0x80 byte block area at +0x08, so the table at
 * 0x0209E3A4 is 32 rows of four offsets drawn from 0x00, 0x20, 0x40 and 0x60.
 * src/matched/sub_02019388.c, src/matched/unit_020188B4.c and
 * src/pending/sub_02018E34.c all index through it, and ov188 calls it eight
 * more times.
 *
 * Why it WAS capped (historical, resolved 2026-09-21): the one relocation is an ABS32 against the table at
 * 0x0209E3A4, and a scan of every word in all 242 regions finds exactly one
 * occurrence of that address, the pool word at 0x02019C50 inside this
 * function.  The `literal` class discards its only witness under the honesty
 * rule and no cut helps, because the range cannot be made smaller than the one
 * function that holds the pool word.  The `matched` class never applies to
 * data (docs/MATCHING.md, "The matched class"), so this is the same shape as
 * src/matched/sub_02013FA8.c's private table and not the same shape as
 * sub_02018E34's runtime helper.  It closes the day anything else in the image
 * names 0x0209E3A4, or the day the table itself is a matched data entry.
 *
 * The neighbour func_02019C54, which is the one-entry memo in front of this
 * function, has no such site and was cut off into
 * src/matched/unit_02019C54.c rather than left capped with it
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md is the same
 * remedy applied to a data reference).
 *
 * What pinned the source: the mask is written `(pid & 0x3E000) >> 13` and not
 * `(pid >> 13) & 0x1F`.  The first is the `movs #0x3E` / `lsls #0xC` / `ands`
 * / `lsrs #0xD` the original has; the second folds to a `lsrs` and an `ands`
 * against a pooled 0x1F.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/sub_02019C38.c \
 *       --addr 0x02019C38 --thumb
 */
void *func_02019C38(struct Mon *p, u32 pid, u32 n)
{
    return &p->block[gBlockOrder[(pid & 0x3E000) >> 13][n]];
}


/*
 * A one-entry memo: the (a, b) key pair at 0x02146270 and the 0x10 byte
 * object built for it at 0x02146274, rebuilt through sub_0201ADA4
 * (src/matched/unit_0201ADA4.c) only when the key changes.  func_02019C90 in
 * src/matched/unit_02019C7C.c is its only caller.
 *
 * Two things pin the source.
 *
 * The guard is one `||` expression rather than two ifs, which is what puts
 * both stores and the call in one block, per
 * docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md; and the
 * arm that falls through the first `bne` is the second half of the
 * disjunction, not the body.
 *
 * The two pool words 0x02146270 and 0x02146274 are one symbol and an addend,
 * per docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 * Declared as two symbols, 0x02146274 would need a witness of its own and the
 * only word in the image that holds it is the one under test.
 *
 * The neighbour func_02019C38 at the head of this packet is byte-correct but
 * MATCH-capped on its private table and is parked in
 * src/pending/sub_02019C38.c; this range is cut to exclude it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02019C54.c \
 *       --addr 0x02019C54 --thumb
 */
void *func_02019C54(u32 a, u32 b)
{
    if (a != g_02146270.a || b != g_02146270.b) {
        g_02146270.b = (u16)b;
        g_02146270.a = (u16)a;
        sub_0201ADA4(a, b, g_02146270.obj);
    }
    return g_02146270.obj;
}


/*
 * func_02019CE0 carries no label in the generated listing: it saves r3 and r4
 * but not lr, so disasm.py's prologue sweep never fires on it and its 24 bytes
 * arrive as a run of .word between two literal pools.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.  It is one
 * struct assignment: 27 ldm/stm pairs of eight bytes plus a trailing word is
 * 0xDC bytes, and the eight byte step is what says the record is at least four
 * aligned, which is docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md.
 *
 * The range stops at 0x02019CF8, which is an eight byte tail call whose pool
 * word names 0x02019BBC.  That address carries no func_ label and no other
 * pool word in the image holds it, so neither the label nor the literal class
 * can attest it and the stub cannot be matched from either side.
 */
u32 func_02019C7C(void *h)
{
    if (func_0201AE1C(h, 0x1B) != 0) {
        return 2;
    }
    return 1;
}


/*
 * func_02019CE0 carries no label in the generated listing: it saves r3 and r4
 * but not lr, so disasm.py's prologue sweep never fires on it and its 24 bytes
 * arrive as a run of .word between two literal pools.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.  It is one
 * struct assignment: 27 ldm/stm pairs of eight bytes plus a trailing word is
 * 0xDC bytes, and the eight byte step is what says the record is at least four
 * aligned, which is docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md.
 *
 * The range stops at 0x02019CF8, which is an eight byte tail call whose pool
 * word names 0x02019BBC.  That address carries no func_ label and no other
 * pool word in the image holds it, so neither the label nor the literal class
 * can attest it and the stub cannot be matched from either side.
 */
u32 func_02019C90(u16 a, u16 b, u32 k)
{
    return func_0201AE1C(func_02019C54(a, b), k);
}


/*
 * func_02019CE0 carries no label in the generated listing: it saves r3 and r4
 * but not lr, so disasm.py's prologue sweep never fires on it and its 24 bytes
 * arrive as a run of .word between two literal pools.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.  It is one
 * struct assignment: 27 ldm/stm pairs of eight bytes plus a trailing word is
 * 0xDC bytes, and the eight byte step is what says the record is at least four
 * aligned, which is docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md.
 *
 * The range stops at 0x02019CF8, which is an eight byte tail call whose pool
 * word names 0x02019BBC.  That address carries no func_ label and no other
 * pool word in the image holds it, so neither the label nor the literal class
 * can attest it and the stub cannot be matched from either side.
 */
void func_02019CA0(void *p, u32 v)
{
    u32 a = func_02017E1C(p, 5, 0);
    u32 b = func_02017E1C(p, 0x6F, 0);

    func_02017E40(p, 8, func_02018584((u16)a, (u16)b, (u16)v));
    func_020185C4(p);
}


/*
 * func_02019CE0 carries no label in the generated listing: it saves r3 and r4
 * but not lr, so disasm.py's prologue sweep never fires on it and its 24 bytes
 * arrive as a run of .word between two literal pools.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.  It is one
 * struct assignment: 27 ldm/stm pairs of eight bytes plus a trailing word is
 * 0xDC bytes, and the eight byte step is what says the record is at least four
 * aligned, which is docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md.
 *
 * The range stops at 0x02019CF8, which is an eight byte tail call whose pool
 * word names 0x02019BBC.  That address carries no func_ label and no other
 * pool word in the image holds it, so neither the label nor the literal class
 * can attest it and the stub cannot be matched from either side.
 */
void func_02019CE0(const struct RecDC *src, struct RecDC *dest)
{
    *dest = *src;
}
