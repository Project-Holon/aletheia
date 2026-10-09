/*
 * file:     pokeparty_p01.c
 * unit:     yes
 * function: func_02019A50, func_02019A7C, func_02019A9C, func_02019ABC, func_02019B04, func_02019B44, func_02019B58, func_02019B64, func_02019B94, func_02019BA4, func_02019C38, func_02019C54, func_02019C7C, func_02019C90, func_02019CA0, func_02019CE0
 * address:  0x02019A50
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
 *   gMsgBank   0x020A7370  data
 *   gNameBuf   0x021462F0  data
 *   _s32_div_f           0x0209C0A4  arm
 *   func_02019B04_Table  0x0209E324  data
 *   func_02048F4C  0x02048F4C  arm
 *   gWordBuf       0x02146398  data
 *   gBlockOrder  0x0209E3A4  data
 *   g_02146270   0x02146270  data
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02018584  0x02018584  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 */
struct MsgData;
struct Personal;
typedef unsigned short u16;

typedef unsigned int   u32;

struct Mon_02019A50 {
    u32 unk00;
};

struct BlockA {
    u16 species;
};

typedef signed char    s8;

typedef unsigned char  u8;

struct Mon_02019C38 {
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

extern void func_02045F5C(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
extern u32 func_0201F448(const u16 *a, const u16 *b);
extern void *func_020185F0(void);
extern u32   func_02017E88(void *p, u32 id, u32 v);
extern void  func_02017E64(void *p, u32 id, u32 v);
extern void  func_02048F4C(void *a, u32 b, u32 c);
extern void sub_0201ADA4(u32 a, int b, void *dest);
extern u32  func_02017E1C(void *p, u32 id, u32 v);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32  func_02018584(u16 a, u16 b, u16 v);
extern void func_020185C4(void *p);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
void func_02019A50(u16 *p, u32 size, u32 seed);
u16 func_02019A7C(u32 *s);
u16 func_02019A9C(const u16 *p, u32 size);
u32 func_02019ABC(struct Mon_02019A50 *p);
u32 func_02019B04(u32 a, u32 b, u32 n);
s8 func_02019B44(u32 a, u32 n);
void func_02019B58(void *p);
void func_02019B64(void *p);
void func_02019B94(u32 a, void *b);
u32 func_02019BA4(u32 a, u32 i);
u32 func_02019BBC(u32 item);
void *func_02019C38(struct Mon_02019C38 *p, u32 pid, u32 n);
void *func_02019C54(u32 a, u32 b);
u32 func_02019C7C(void *h);
u32 func_02019C90(u16 a, u16 b, u32 k);
void func_02019CA0(void *p, u32 v);
void func_02019CE0(const struct RecDC *src, struct RecDC *dest);
extern void *gMsgBank;
extern u16   gNameBuf[];
extern const s8 func_02019B04_Table[][5];
extern u32   gWordBuf[];
extern const u8 gBlockOrder[32][4];
extern struct Memo g_02146270;



/*
 * The three primitives the whole save record in this region is protected
 * with.  func_02019A7C is one step of the linear congruential generator
 * `s = s * 0x41C64E6D + 0x6073` returning the middle halfword of the new
 * state, func_02019A50 XOR masks a byte range with that stream halfword by
 * halfword, and func_02019A9C is the plain halfword sum used as the checksum.
 *
 * func_02019A50 opens `push {r0, r1, r2, r3}` and closes `pop {r3}` /
 * `add sp, #0x10` / `bx r3`, which is what taking the address of a register
 * parameter costs on this front end; see
 * docs/idioms/address-of-a-register-parameter-is-a-push-of-all-four.md.  The
 * seed is passed by value and updated in place through that home slot, so a
 * caller's seed is never modified, which is what lets func_02018D34 mask the
 * same area twice with the same seed to undo itself.
 *
 * func_02019A7C carries no label in the generated listing.
 */
void func_02019A50(u16 *p, u32 size, u32 seed)
{
    u32 i = 0;
    u32 n = size >> 1;

    if (n != 0) {
        u32 *s = &seed;

        do {
            p[i] ^= func_02019A7C(s);
            i++;
        } while (i < n);
    }
}



u16 func_02019A7C(u32 *s)
{
    *s = *s * 0x41C64E6D + 0x6073;
    return (u16)(*s >> 16);
}



u16 func_02019A9C(const u16 *p, u32 size)
{
    u16 sum = 0;
    u32 i = 0;
    u32 n = size >> 1;

    if (n != 0) {
        do {
            sum = (u16)(sum + p[i]);
            i++;
        } while (i < n);
    }
    return sum;
}



/*
 * "Is the name in substruct C still the species' default name": it renders the
 * species name for substruct A's species id into the shared 0x20 halfword
 * buffer at 0x021462F0 and compares it with substruct C's own name, returning
 * 1 when they are equal.  func_02019388 (src/matched/sub_02019388.c) calls it
 * from ids 0x73 and 0x74 and stores the result in substruct B +0x10 bit 31,
 * which is the bit func_02018E34 reads back as id 0x75.  Those two calls are
 * the only references to this address in the image.
 *
 * The result local is declared before the two substruct fetches, which is what
 * puts `movs r5, #0` in front of the first call rather than after the second.
 *
 * The message bank at 0x020A7370 is a global pointer, so its address is a
 * build property and has to be re-derived for a White build rather than
 * copied; the 0x20 is a halfword count and the species id is data, so nothing
 * else here is version specific.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02019ABC.c \
 *       --addr 0x02019ABC --thumb
 */
u32 func_02019ABC(struct Mon_02019A50 *p)
{
    u32 r = 0;
    struct BlockA *a = (struct BlockA *)func_02019C38((struct Mon_02019C38 *)p, p->unk00, 0);
    void *c = func_02019C38((struct Mon_02019C38 *)p, p->unk00, 2);

    func_02045F5C(gMsgBank, a->species, gNameBuf, 0x20);
    if (func_0201F448(gNameBuf, c) == 0) {
        r = 1;
    }
    return r;
}



/*
 * Scales b by a per (a, n) table entry of -1, 0 or 1; the multipliers are
 * 0x5A and 0x6E, which are 90 and 110 percent. Both arms are written out in
 * full and the compiler cross jumps their common muls/truncate/divide tail
 * into one block that the missing default branches past, which is
 * docs/idioms/switch-arms-tail-merge.md; hoisting the multiplication out of
 * the switch puts the default branch to that block instead of past it and
 * costs eight bytes.
 *
 * The table at 0x0209E324 is witnessed by the pool word of the neighbouring
 * leaf sub_02019B44.c (seeded via layout/function_starts.txt), and this
 * file's own pool word witnesses it for that one: the unit_02005DF8 /
 * unit_02005E30 pairwise treatment.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02019B04.c \
 *       --addr 0x02019B04 --thumb
 */
u32 func_02019B04(u32 a, u32 b, u32 n)
{
    s8 v;

    if (n >= 6) {
        return b;
    }
    v = func_02019B04_Table[a][n - 1];
    switch (v) {
    case 1:
        b = (u16)((u16)(b * 0x6E) / 100);
        break;
    case -1:
        b = (u16)((u16)(b * 0x5A) / 100);
        break;
    }
    return b;
}



/*
 * The unlabelled leaf whose pool word is the second image-wide reference to
 * the table at 0x0209E324; traced via layout/function_starts.txt. Its pool
 * word witnesses the table for unit_02019B04.c and vice versa.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/sub_02019B44.c \
 *       --func func_02019B44 --addr 0x02019B44
 */
s8 func_02019B44(u32 a, u32 n)
{
    return func_02019B04_Table[a][n - 1];
}



/*
 *           func_02019BBC
 *
 * The first five of the seven functions between func_02019ABC and the cache
 * helper at 0x02019C54.  The range stops at 0x02019C38 on purpose: the two
 * functions after it, func_02019C38 and func_02019C54, each reach a data
 * object through a pool word that is the object's only reference in the whole
 * image (0x0209E3A4 at 0x02019C50 and 0x02146274 at 0x02019C78), so the
 * `literal` class has no outside witness for either and both cap at MATCH
 * however they are written.  Cutting in front of them leaves these five
 * clean.
 *
 * func_02019B58 reaches func_020185F0, which src/matched/unit_020185F0.c
 * proves is an empty `bx lr`, and then calls func_02019B64 with whatever r0
 * holds, with no register saved across the first call.  That only compiles
 * from a declaration in which func_020185F0 returns a value, so this unit
 * declares it `void *func_020185F0(void)` and passes the result straight on;
 * declaring it `void` the way unit_020185F0.c does forces a callee-saved
 * register and a four byte longer prologue.  The two declarations disagree,
 * and the image cannot say which one the original header carried, because an
 * empty function's return value is unobservable.
 *
 * func_02019B94 is docs/idioms/tail-call-is-a-pool-word-and-bx.md: it permutes
 * three arguments into an ARM callee at 0x02048F4C and has no prologue at all.
 *
 * func_02019BBC is the plate-to-type table of ids 0xAE and 0xAF of
 * func_02018E34: sixteen consecutive item ids from 0x12A map to sixteen type
 * ids and everything else to 0.  The switch value arrives as a pool word
 * rather than a `subs` immediate only because 0x12A does not fit the eight bit
 * form, so it is an ordinary constant and not the linker symbol of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * VERSION SENSITIVITY: func_02019BBC's sixteen case labels are item ids and
 * its sixteen results are type ids, and func_02019B64 passes id 5 (species)
 * and id 0x74 (the name) of the record.  None of them is a version flag and
 * there is no exclusive-species table here, but the item ids 0x12A..0x139 are
 * content numbering and are the values to re-read first for a White build.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02019B58.c \
 *       --addr 0x02019B58 --thumb
 */
void func_02019B58(void *p)
{
    func_02019B64(func_020185F0());
}



void func_02019B64(void *p)
{
    u32 s = func_02017E88(p, 5, 0);

    func_02045F5C(gMsgBank, s, gNameBuf, 0x20);
    func_02017E64(p, 0x74, (u32)gNameBuf);
}



void func_02019B94(u32 a, void *b)
{
    func_02048F4C(b, 0x11, a);
}



u32 func_02019BA4(u32 a, u32 i)
{
    func_02019B94(a, gWordBuf);
    return gWordBuf[i];
}



u32 func_02019BBC(u32 item)
{
    switch (item) {
    case 0x12A: return 9;
    case 0x12B: return 10;
    case 0x12C: return 12;
    case 0x12D: return 11;
    case 0x12E: return 14;
    case 0x12F: return 1;
    case 0x130: return 3;
    case 0x131: return 4;
    case 0x132: return 2;
    case 0x133: return 13;
    case 0x134: return 6;
    case 0x135: return 5;
    case 0x136: return 7;
    case 0x137: return 15;
    case 0x138: return 16;
    case 0x139: return 8;
    }
    return 0;
}




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
void *func_02019C38(struct Mon_02019C38 *p, u32 pid, u32 n)
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



u32 func_02019C90(u16 a, u16 b, u32 k)
{
    return func_0201AE1C(func_02019C54(a, b), k);
}



void func_02019CA0(void *p, u32 v)
{
    u32 a = func_02017E1C(p, 5, 0);
    u32 b = func_02017E1C(p, 0x6F, 0);

    func_02017E40(p, 8, func_02018584((u16)a, (u16)b, (u16)v));
    func_020185C4(p);
}



void func_02019CE0(const struct RecDC *src, struct RecDC *dest)
{
    *dest = *src;
}
