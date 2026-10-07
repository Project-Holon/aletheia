/*
 * file:     mcss_p13.c
 * unit:     yes
 * function: func_020189D8, func_020189F0, func_02018A00, func_02018A08, func_02018A7C, func_02018D10, func_02018D34, func_02018D6C, func_02018D8C, func_02018DB4
 * address:  0x020189D8
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
 *   tbl_0209E2A4   0x0209E2A4  data  a1
 *   func_02017E64  0x02017E64  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_02019C54  0x02019C54  thumb
 *   func_02019C7C  0x02019C7C  thumb
 *   func_02019C90  0x02019C90  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   _s32_div_f  0x0209C0A4  arm
 *   func_02019A50  0x02019A50  thumb
 *   func_02019A9C  0x02019A9C  thumb
 *   sub_02008F3C   0x02008F3C  thumb
 *   func_02018E34  0x02018E34  thumb
 */
struct Personal;
struct Sub02008F80Obj;
typedef unsigned char u8;

typedef unsigned int u32;

typedef signed char    s8;

typedef unsigned short u16;

typedef signed int     s32;

struct Sav {
    u32 unk00;
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 13;
    u16 unk06;
    u8  unk08[0x80];
    u8  unk88[0x54];
};

struct Mail {
    u8 unk00[0x38];
};

struct Mon {
    u32 unk00;
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 13;
    u16 unk06;
    u8  unk08[0x80];
    u32 unk88;
    u8  unk8C;
    u8  unk8D;
    u16 unk8E;
    u16 unk90;
    u16 unk92;
    u16 unk94;
    u16 unk96;
    u16 unk98;
    u16 unk9A;
    struct Mail unk9C;
};

extern u32 func_02017E88(void *p, u32 id, u32 v);
extern void func_02017E64(void *p, u32 id, u32 v);
extern void *func_02019C54(u32 a, u32 b);
extern u32  func_02019C7C(void *h);
extern u32  func_02019C90(u16 a, u16 b, u32 i);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern u32  func_02017E1C(void *p, u32 id, u32 v);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u8 func_02018598(void *p);
extern u32  func_02019B04(u32 a, u32 b, u32 n);
extern void func_02019A50(u16 *p, u32 size, u32 seed);
extern u16 func_02019A9C(const u16 *p, u32 size);
u32 func_02018D34(struct Sav *p);
void func_02018D8C(struct Sav *p);
extern void sub_02008F3C(const struct Sub02008F80Obj *src, struct Sub02008F80Obj *dest);
extern u32  func_02018E34(struct Mon *p, u32 id, u32 v);
s8 func_020189D8(void *m, u32 a1);
s8 func_020189F0(u8 nature, u32 stat);
void func_02018A00(void *p, u32 a, u32 b);
void func_02018A08(void *p, u32 a, u32 b);
void func_02018A7C(void *p);
extern const s8 tbl_0209E2A4[][5];



s8 func_020189D8(void *m, u32 a1)
{
    return func_020189F0((u8)func_02017E88(m, 0x70, 0), a1);
}




/*
 * The nature table lookup: a signed byte out of the s8[25][5] table at
 * 0x0209E2A4 (row = nature, column = stat).  func_020189D8 is the one
 * caller, and it truncates the nature to u8 at the call.  Wave 11,
 * 2026-09-23.
 *
 * Closes the "one byte the language cannot express" of
 * docs/notes/func_020189F0.c.txt: earlier lanes read the SECOND argument as
 * a base pointer (`b[o + (u32)tbl]`), which makes the scaled index the
 * running operand of the final add.  It is an integer column index and the
 * natural two-dimensional subscript gives the image's `adds r0, r0, r2`
 * (table as accumulator) directly.
 */
s8 func_020189F0(u8 nature, u32 stat)
{
    return tbl_0209E2A4[nature][stat];
}




/*
 * The two functions after src/matched/unit_020188B4.c and the three that its
 * header records as a near miss.  func_02018A00 is the eight byte
 * `ldr r3, [pc, #0]; bx r3` tail call that
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md describes; its callee is the
 * next function in this same range, so the site is the `local` class.
 */
void func_02018A00(void *p, u32 a, u32 b)
{
    func_02018A08(p, a, b);
}




void func_02018A08(void *p, u32 a, u32 b)
{
    void *h;
    u32 t;
    u32 k;
    u32 v;

    v = func_02019C90((u16)a, (u16)b, 0x1C);
    if (v != 0) {
        func_02017E64(p, 0xA, v);
        func_02017E64(p, 0x71, 1);
        return;
    }
    h = func_02019C54((u16)a, (u16)b);
    t = func_02017E88(p, 0, 0);
    k = 0x1A;
    if (func_02019C7C(h) == 2 && (t & (1 << 16))) {
        k = 0x1B;
    }
    func_02017E64(p, 0xA, func_0201AE1C(h, k));
}




/*
 * 660 bytes, one function, no jump table.
 *
 * The six-stat recalculation of poke_tool.c, and the only thing in the region
 * that reads and writes the record through both halves of the dispatcher
 * quartet at once.  It takes no arguments but the record pointer: everything
 * it needs is read back through func_02017E1C (src/matched/unit_02017E1C.c)
 * and everything it produces is written through func_02017E40
 * (src/matched/unit_02017E40.c), so the whole function is seventeen reads, a
 * base-stat table lookup, six formulas and six writes.
 *
 * Its single caller is func_020185C4 (src/pending/unit_020185C4.c), which was
 * MATCH-capped on exactly this address; with this entry EXACT the `matched`
 * class carries that site and the parked file graduates.
 *
 * ---------------------------------------------------------------------------
 * THE IDS, AND WHERE THE FIELD MAP FOR THEM IS
 * ---------------------------------------------------------------------------
 * The party-area ids are func_02018DB4's (src/matched/sub_02018DB4.c) and the
 * block-area ids are func_02018E34's (src/pending/sub_02018E34.c, whose header
 * carries the full map).  What this function uses:
 *
 *   read  0x9E  level          0xA1  current max HP   0xA0  current HP
 *   read  0x46..0x4B           the six 5 bit IVs, in stat order
 *   read  0x0D..0x12           the six effort values, capped at 510 together
 *   read  0x6F  form           0x05  species
 *   write 0xA1  max HP
 *   write 0xA2..0xA6           attack, defence, speed, sp. attack, sp. defence
 *   write 0xA0  current HP, and only when the result is non zero
 *
 * func_02019C54(species, form) returns the species' base-stat record and the
 * first six bytes of it are the six base stats, indexed here in the same order
 * the ids are: HP, attack, defence, speed, sp. attack, sp. defence.  The
 * nature multiplier func_02019B04 (src/matched/unit_02019B04.c) is indexed
 * differently, 1, 2, 5, 3, 4 for that same sequence, so its table is in
 * attack, defence, sp. attack, sp. defence, speed order.  That permutation is
 * in the game and not in this reconstruction; the two orderings are visible
 * side by side in the five `movs r2, #k` immediates.
 *
 * The formulas are the ordinary third-generation-onwards ones, in signed
 * arithmetic throughout (the divides are `_s32_div_f`, and `ev / 4` carries
 * the rounding correction a signed shift needs):
 *
 *   max HP = (base * 2 + iv + ev / 4) * level / 100 + level + 10
 *   stat   = ((base * 2 + iv + ev / 4) * level / 100 + 5) scaled by nature
 *
 * Species 292 is the exception: its max HP is 1 and its current HP is 1,
 * whatever its level, IVs or EVs are.  The constant appears twice and the
 * compiler materialises it two different ways, `0x6F + 0xB5` off the id
 * constant that is still live from the id 0x6F read, and `0x49 << 2` in the
 * tail where nothing is live; both are written `292` in the source.
 *
 * ---------------------------------------------------------------------------
 * THE THREE THINGS THAT COST THE MOST TIME
 * ---------------------------------------------------------------------------
 * **The nature multiplier's first argument is a named local.**  Written
 * inline, `func_02019B04(func_02018598(p), (u16)stat, k)`, the first three
 * stats are byte for byte right and the last two are not: the compiler hoists
 * the `bl func_02018598` in front of the arithmetic, which costs the `adds r5,
 * r0, #5` its fold and adds three instructions per stat, twelve bytes and 203
 * concrete bytes in total.  Binding the call result to a local before the
 * outer call, `nature = func_02018598(p);`, pins the evaluation order for all
 * five and is EXACT.  This is the store form of
 * docs/idioms/a-store-that-lands-after-the-next-call-names-a-local-temporary.md
 * seen at an argument rather than at a field, and the new file
 * docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md
 * records it, because the asymmetry (three sites right, two wrong, from one
 * source shape) is what makes it expensive to read back.
 *
 * **The named local also decides the two callee-saved registers.**  With the
 * call inline, level lands in r7 and the current HP in r6; with `nature`
 * bound, they are the original's r6 and r7.  Nothing about the register
 * numbering points at the argument that caused it.
 *
 * **Max HP is two statements, not one.**  The original stores the running
 * value into the max-HP slot, adds ten, and stores it again; the dead first
 * store is what says the source wrote `newMax = ... + level;` and then
 * `newMax = newMax + 10;`.  Written as one expression the `+ 10` folds into
 * the same instruction stream, the first `str` disappears, and the species 292
 * arm's `b` then cross-jumps onto a different store.
 *
 * The five IVs and five EVs that reach the stack are grouped, all five IVs at
 * sp+0x30 down to sp+0x20 and then all five EVs at sp+0x1C down to sp+0x0C,
 * which is what says they were declared in two runs rather than interleaved in
 * the order they are read; declared read-interleaved every slot is right by
 * four bytes and nothing else moves.  See
 * docs/idioms/local-declaration-order-is-stack-order.md.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * One content id: 292, the species whose max HP is forced to 1.  It appears
 * twice, at the max-HP branch and in the current-HP tail.  Black and White
 * share their species numbering, so it is expected to be identical in IRAO,
 * but it is the one number to re-read.  Everything else here is a structure
 * offset, a stat index or a formula constant (2, 4, 100, 5, 10), and the stat
 * formulas themselves are content in the sense that they decide the game's
 * numbers: if a White build ever diverges here, it diverges on 292 or on the
 * base-stat table func_02019C54 hands back, not on this code.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/sub_02018A7C.c \
 *       --func func_02018A7C --addr 0x02018A7C --cc 1.1p1
 */
void func_02018A7C(void *p)
{
    s32 cur;
    s32 level;
    s32 form;
    s32 iv0;
    s32 oldMax;
    s32 iv1;
    s32 iv2;
    s32 iv3;
    s32 iv4;
    s32 iv5;
    s32 ev1;
    s32 ev2;
    s32 ev3;
    s32 ev4;
    s32 ev5;
    s32 species;
    const u8 *base;
    s32 newMax;
    s32 ev0;
    s32 stat;
    u32 nature;
    s32 delta;

    level = func_02017E1C(p, 0x9E, 0);
    oldMax = func_02017E1C(p, 0xA1, 0);
    cur = func_02017E1C(p, 0xA0, 0);
    iv0 = func_02017E1C(p, 0x46, 0);
    ev0 = func_02017E1C(p, 0x0D, 0);
    iv1 = func_02017E1C(p, 0x47, 0);
    ev1 = func_02017E1C(p, 0x0E, 0);
    iv2 = func_02017E1C(p, 0x48, 0);
    ev2 = func_02017E1C(p, 0x0F, 0);
    iv3 = func_02017E1C(p, 0x49, 0);
    ev3 = func_02017E1C(p, 0x10, 0);
    iv4 = func_02017E1C(p, 0x4A, 0);
    ev4 = func_02017E1C(p, 0x11, 0);
    iv5 = func_02017E1C(p, 0x4B, 0);
    ev5 = func_02017E1C(p, 0x12, 0);
    form = func_02017E1C(p, 0x6F, 0);
    species = func_02017E1C(p, 0x05, 0);
    base = func_02019C54((u16)species, (u16)form);

    if (species == 292) {
        newMax = 1;
    } else {
        newMax = (base[0] * 2 + iv0 + ev0 / 4) * level / 100 + level;
        newMax = newMax + 10;
    }
    func_02017E40(p, 0xA1, newMax);

    stat = (base[1] * 2 + iv1 + ev1 / 4) * level / 100 + 5;
    nature = func_02018598(p);
    func_02017E40(p, 0xA2, func_02019B04(nature, (u16)stat, 1));

    stat = (base[2] * 2 + iv2 + ev2 / 4) * level / 100 + 5;
    nature = func_02018598(p);
    func_02017E40(p, 0xA3, func_02019B04(nature, (u16)stat, 2));

    stat = (base[3] * 2 + iv3 + ev3 / 4) * level / 100 + 5;
    nature = func_02018598(p);
    func_02017E40(p, 0xA4, func_02019B04(nature, (u16)stat, 5));

    stat = (base[4] * 2 + iv4 + ev4 / 4) * level / 100 + 5;
    nature = func_02018598(p);
    func_02017E40(p, 0xA5, func_02019B04(nature, (u16)stat, 3));

    stat = (base[5] * 2 + iv5 + ev5 / 4) * level / 100 + 5;
    nature = func_02018598(p);
    func_02017E40(p, 0xA6, func_02019B04(nature, (u16)stat, 4));

    if (cur != 0 || oldMax == 0) {
        if (species == 292) {
            cur = 1;
        } else if (cur == 0) {
            cur = newMax;
        } else {
            delta = newMax - oldMax;
            if (delta < 0) {
                if (cur > newMax) {
                    cur = newMax;
                }
            } else {
                cur = cur + delta;
            }
        }
    }
    if (cur != 0) {
        func_02017E40(p, 0xA0, cur);
    }
}



/*
 * The four lock/unlock helpers every accessor wrapper in this region opens and
 * closes with.  The object is the same record as src/matched/unit_02017D30.c:
 * a seed word at +0x00, three flag bits at +0x04, a halfword checksum at
 * +0x06, an 0x80 byte area at +0x08 and a 0x54 byte area at +0x88, each
 * area XOR masked in place by func_02019A50.  Bit 2 of +0x04 is the sticky
 * "checksum did not match" flag func_02018D34 sets.
 *
 * The three flag tests are `lsls`/`lsrs` pairs of width one, which is the
 * bitfield shape of docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md;
 * spelling them as masks gives movs/ands instead.
 */
u32 func_02018D10(struct Sav *p)
{
    u32 r = 1;

    if (p->b0 == 0) {
        func_02019A50((u16 *)p->unk88, 0x54, p->unk00);
        r = func_02018D34(p);
    }
    return r;
}

u32 func_02018D34(struct Sav *p)
{
    u32 r = 1;
    u16 sum;

    if (p->b1 == 0) {
        func_02019A50((u16 *)p->unk08, 0x80, p->unk06);
        sum = func_02019A9C((const u16 *)p->unk08, 0x80);
        if (sum != p->unk06) {
            r = 0;
            p->b2 = 1;
        }
    }
    return r;
}

void func_02018D6C(struct Sav *p)
{
    if (p->b0 == 0) {
        func_02019A50((u16 *)p->unk88, 0x54, p->unk00);
        func_02018D8C(p);
    }
}

void func_02018D8C(struct Sav *p)
{
    if (p->b1 == 0) {
        p->unk06 = func_02019A9C((const u16 *)p->unk08, 0x80);
        func_02019A50((u16 *)p->unk08, 0x80, p->unk06);
    }
}


/*
 * The party-data half of the record's read accessor, and the outer half of the
 * get/set dispatcher quartet of poke_tool.c.  The record is the 0xDC byte
 * structure src/matched/unit_02017D30.c and src/matched/unit_02018D10.c
 * describe: a seed word at +0x00, three flag bits and a checksum at +0x04, an
 * 0x80 byte XOR masked block area at +0x08 and an 0x54 byte XOR masked party
 * area at +0x88.  This function owns the twelve ids that live in the party
 * area, 0x9D to 0xA8, and tail calls func_02018E34 for everything else, which
 * is the 176 case accessor over the block area (src/pending/sub_02018E34.c).
 *
 * The twelve ids are a dense switch from 0x9D, so the `cmp r3, #0xb` / `bhi` /
 * `add pc, r3` preamble and the twelve halfword table come out of a plain C
 * switch; see docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 * Only 0xA7 and 0xA8 have bodies that are not a field load: 0xA7 copies the
 * 0x38 byte object at +0x9C out through the third argument with
 * sub_02008F3C (the same whole-object copy src/matched/unit_02008F80.c
 * describes), and 0xA8 returns 1 with no field at all.  Both return 1 out of
 * their own `movs r0, #1` / `pop`, not a shared one.
 *
 * The setter half is func_02019308, src/matched/sub_02019308.c, which has the
 * same twelve ids in the same order over the same offsets.
 *
 * Nothing here is version specific: the ids are structure offsets, not species
 * or version tables.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/sub_02018DB4.c \
 *       --func func_02018DB4 --addr 0x02018DB4 --cc 1.1p1
 */
u32 func_02018DB4(struct Mon *p, u32 id, u32 v)
{
    switch (id) {
    case 0x9D: return p->unk88;
    case 0x9E: return p->unk8C;
    case 0x9F: return p->unk8D;
    case 0xA0: return p->unk8E;
    case 0xA1: return p->unk90;
    case 0xA2: return p->unk92;
    case 0xA3: return p->unk94;
    case 0xA4: return p->unk96;
    case 0xA5: return p->unk98;
    case 0xA6: return p->unk9A;
    case 0xA7:
        sub_02008F3C((const struct Sub02008F80Obj *)(&p->unk9C), (struct Sub02008F80Obj *)v);
        return 1;
    case 0xA8:
        return 1;
    }
    return func_02018E34(p, id, v);
}
