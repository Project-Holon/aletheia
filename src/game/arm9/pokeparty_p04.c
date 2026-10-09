/*
 * file:     pokeparty_p04.c
 * unit:     yes
 * function: func_0201B7B4, func_0201B7EC, func_0201B818, func_0201B850, func_0201B920, func_0201B970, func_0201B9F0, func_0201BA34, func_0201BA68, func_0201BABC, func_0201BB5C, func_0201BBE8, func_0201BC3C, func_0201BC40, func_0201BC78, func_0201BCB4, func_0201BCEC, func_0201BD28, func_0201BDB4
 * address:  0x0201B7B4
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
 *   func_02020FE4  0x02020FE4  thumb
 *   func_0201B850  0x0201B850  thumb
 *   func_0203F0A8  0x0203F0A8  arm
 *   g_0209E465     0x0209E465  data  a1
 *   g_0209E462     0x0209E462  data
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02013E4C   0x02013E4C  thumb
 *   func_02017E1C   0x02017E1C  thumb
 *   func_02017E40   0x02017E40  thumb
 *   func_02011014   0x02011014  thumb
 *   _s32_div_f      0x0209C0A4  arm
 *   sub_0201C158   0x0201C158  thumb
 *   g_0209E474  0x0209E474  data
 *   gWazaTool   0x02146530  data
 *   g_02146534  0x02146534  data
 */
struct Sav;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed char    s8;

typedef unsigned int   u32;

typedef unsigned long long u64;

typedef int            s32;

struct Waza {
    u8  unk00;
    u8  unk01;
    u8  unk02;
    u8  unk03;
    u8  unk04;
    u8  unk05;
    s8  unk06;
    u8  lo : 4;
    u8  hi : 4;
    u16 unk08;
    u8  unk0A;
    u8  unk0B;
    u8  unk0C;
    u8  unk0D;
    u8  unk0E;
    u8  unk0F;
    u16 unk10;
    s8  unk12;
    s8  unk13;
    u8  unk14;
    u8  unk15[3];
    s8  unk18[3];
    u8  unk1B[3];
};

struct WazaTool {
    struct Waza **recs;
    u16 *vals;
    s32 count;
};

extern u32 func_02020FE4(void *a, u32 sel, u32 id);
extern void func_0201B850(void *mon, const s8 *tbl, int a2, u32 a3);
extern u32  func_0203F0A8(void);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02013E4C(u32 id);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02017E40(void *p, u32 id, u32 v);
extern int func_02011014(int a0);
extern u8  func_0201C158(u32 move, u32 ppUp);
extern u8   sub_0201C158(u32 move, u32 ppUp);
extern u32 sub_0201AA18(void *p);
extern void *sub_0201AB28(void *p, u32 idx);
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern u32  func_02017E88(void *mon, u32 id, u32 v);
extern u32 func_02019C90(u16 a, u16 b, u32 k);
extern u32  func_020490A8(u32 kind, u32 member);
extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
u32 sub_0201BDB4(const struct Waza *p, u32 id);
void func_0201B7B4(void *a0, int a1, u16 a2, u16 a3);
void func_0201B7EC(void *a0, int a1, int a2);
void func_0201B818(void *a0, int a1, int a2);
void sub_0201B850(void *mon, const s8 *tbl, int a2, u32 a3);
u8 sub_0201B920(void *mon, u32 slot);
u32 sub_0201B970(void *mon, u32 slot, u32 amount);
void sub_0201B9F0(void *mon);
void sub_0201BA34(void *party);
u32 sub_0201BA68(void *mon);
u32 sub_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
u32 sub_0201BB5C(u32 species, u32 form, u32 half, u32 isEgg);
u32 sub_0201BBE8(void *mon);
int func_0201BC3C(void);
int func_0201BC40(void);
int func_0201BC78(void);
int func_0201BCB4(void);
int func_0201BCEC(void);
u32 sub_0201BD28(u16 id, u32 field);
extern const s8 g_0209E465[];
extern const s8 g_0209E462[];
extern const u8 g_0209E474[];
extern struct WazaTool *gWazaTool;
extern struct Waza g_02146534;



/*
 * Three bytes are built one selector at a time - selectors 0x3C, 0x3D, 0x3E
 * - and the three-byte buffer is then handed to func_0201B850 along with
 * the caller's own second and fourth arguments.  No literal pool: the only
 * pointers are the two call targets.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201B7B4.c \
 *       --func func_0201B7B4 --addr 0x0201B7B4 --cc 1.1p1 --thumb
 */
void func_0201B7B4(void *a0, int a1, u16 a2, u16 a3)
{
    u8 buf[3];
    int i;

    for (i = 0; i < 3; i++) {
        buf[i] = (u8)func_02020FE4((void *)(u32)a1, (u16)(i + 0x3C), a3);
    }
    func_0201B850(a0, (const s8 *)buf, a2, a3);
}



/*
 * shinka_check.c.  The coin-flip sibling of func_0201B7A0 / func_0201B818:
 * on an even draw below 2, hand the fixed row g_0209E465 to func_0201B850.
 *
 * The `movs r1,#0 / lsls r1,r1,#1 / lsrs r0,r0,#31 / orrs` run that four
 * waves read as a scheduling tie of two u32 shifts is the high word of a
 * 64-bit product: the draw widened to u64, times 2, shifted right 32 (the
 * random-below-N idiom, docs/idioms/random-below-n-is-a-64-bit-multiply-high.md,
 * with N = 2).  The zero high half is shifted left by one and ORed with the
 * low half's carry-out bit; the compiler emits the two halves in that order,
 * which is the order no u32 spelling could reach.  `% 2 == 0` gives the
 * `tst` against 1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201B7EC.c \
 *       --func func_0201B7EC --addr 0x0201B7EC --cc 1.1p1 --thumb
 */
void func_0201B7EC(void *a0, int a1, int a2)
{
    if ((u32)((u64)func_0203F0A8() * 2 >> 32) % 2 == 0) {
        func_0201B850(a0, g_0209E465, a1, a2);
    }
}



/*
 * was-blocked: 0209E462.  The `literal` class still refuses it -- the only
 *           pool word in the image holding 0x0209E462 is this function's own,
 *           at 0x0201B84C, inside the compared range.  The site resolves as
 *           `sole-ref` instead, so the entry is EXACT and not MATCH.
 *
 * for (i = 0; i < count(a0); i++) func_0201B850(entry(a0, i), &g_0209E462,
 * a1, a2); - the entry pointer the loop computes is what feeds the second
 * call's first argument, which is why no `r0 = a0` copy appears in front of
 * it (the returned r0 is already the argument), and the bound is
 * re-evaluated at the bottom of the loop so it stays a call in the
 * condition.  The table pointer is this function's own pool word at
 * 0x0201B84C, behind the C0 46 alignment filler at 0x0201B84A.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201B818.c \
 *       --func func_0201B818 --addr 0x0201B818 --cc 1.1p1 --thumb
 */
void func_0201B818(void *a0, int a1, int a2)
{
    int i;

    for (i = 0; i < (int)func_0201AA18(a0); i++) {
        func_0201B850(func_0201AB28(a0, i), g_0209E462, a1, a2);
    }
}



/*
 * Applies an EV/stat-like gain to party record id 9, scaled by a per-band
 * table the caller supplies.  The species read (id 0xAB) gates the whole
 * body: species 0 and species 650 both return early.
 *
 * The band index `idx` doubles as the literal zero argument of the three
 * func_02017E1C reads, which is why it is a named u8 initialised before the
 * species call rather than three separate `0` literals; and the two
 * increments must be spelled `idx++` (post-increment), not `idx = idx + 1`,
 * or the compiler proves idx is still 0 at the first band test and folds it
 * to `movs r5, #1`, costing the `adds/lsls/lsrs` triple.
 *
 * The function returns void: an `int` return adds a `movs r0, #0` before the
 * epilogue.
 *
 * VERSION SENSITIVITY: 650 is a species id and 0xAB / 6 / 9 / 0x96 / 0x98 are
 * party-record ids; both are content numbering and should be re-read for a
 * White build.  0x35 is the value func_02020FE4 returns for one particular
 * kind and is content numbering too.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/sub_0201B850.c \
 *       --func sub_0201B850 --addr 0x0201B850 --cc 1.1p1 --thumb
 *   python tools/match.py tu --src src/matched/sub_0201B850.c \
 *       --addr 0x0201B850 --thumb
 */
void sub_0201B850(void *mon, const s8 *tbl, int a2, u32 a3)
{
    int t;
    u32 species;
    u32 kind;
    int cur;
    int n;
    u8 idx;

    t = func_02013E4C(a2);
    idx = 0;
    species = (u16)func_02017E1C(mon, 0xAB, 0);
    if (species == 0 || species == 650) {
        return;
    }
    kind = (u8)func_02020FE4((void *)((u16)func_02017E1C(mon, 6, idx)), 1, a3);
    cur = func_02017E1C(mon, 9, idx);

    if (cur >= 100) {
        idx++;
    }
    if (cur >= 200) {
        idx++;
    }
    n = tbl[idx];
    if (n > 0) {
        if (func_02017E1C(mon, 0x98, 0) == 11) {
            n = n + 1;
        }
    }
    if (t != 0 && n > 0) {
        if (t == (int)func_02017E1C(mon, 0x96, 0)) {
            n = n + 1;
        }
    }
    if (n > 0 && kind == 0x35) {
        n = n * 150 / 100;
    }
    cur = cur + func_02011014(n);
    if (cur < 0) {
        cur = 0;
    }
    if (cur > 255) {
        cur = 255;
    }
    func_02017E40(mon, 9, cur);
    return;
}



/*
 * A single function, matched as a byte range because the function after it is
 * a near miss and a committed range has to be EXACT end to end.
 *
 * pokeparty.c's "is this move slot short of PP" predicate: 78 bytes, three
 * reads of the party record and one call into the PP table.
 *
 * The three ids it reads are three parallel runs of the record's id space,
 * one per move slot: 0x36 + slot is the move, 0x3A + slot its current PP and
 * 0x3E + slot its PP ups.  src/matched/unit_0201C158.c turns the last two of
 * those into the slot's maximum, and the answer is whether the current PP is
 * below it.
 *
 * It stands alone rather than inside a unit with its neighbours because
 * sub_0201B970, which sits immediately after it, is a documented near miss
 * (docs/notes/sub_0201B970.c.txt) and a range cannot be committed while any
 * part of it is short of EXACT.  Its own single caller, sub_0201B9F0 at
 * 0x0201BA18, is parked in src/pending/unit_0201B9F0.c and resolves this
 * address through the `matched` class off this entry.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * No species, item or move id appears here.  0x36, 0x3A and 0x3E are party
 * record ids in src/matched/sub_02018DB4.c's space, and the three are written
 * out as three separate literals rather than derived from one base, so a
 * version that inserted a field into that id space would move all three
 * independently.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * The function has two epilogues and only the second truncates the result.
 * That is what says the early exit returns the result *variable* while it is
 * still provably zero rather than the literal zero: `return 0;` would be a
 * `movs r0, #0` where the original copies r5, and a shared exit would need the
 * two tests to be one conjunction, which they cannot be because the second one
 * depends on the first's call
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 *
 * The result variable is therefore wider than the return type: declared `u8`
 * it needs no truncation at the tail and the function is two bytes short.
 *
 * The third id is built by advancing r7 in place (`adds r7, #0x3e` over the
 * register that held the slot), which is the last use of the slot number and
 * not a separate pointer.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/sub_0201B920.c \
 *       --func sub_0201B920 --addr 0x0201B920 --cc 1.1p1
 */
u8 sub_0201B920(void *mon, u32 slot)
{
    u32 move;
    u8 pp;
    u8 ppUp;
    u32 r;

    r = 0;
    move = (u16)func_02017E1C(mon, slot + 0x36, 0);
    if (move == 0) {
        return r;
    }
    pp = (u8)func_02017E1C(mon, slot + 0x3A, 0);
    ppUp = (u8)func_02017E1C(mon, slot + 0x3E, 0);
    if (pp < func_0201C158(move, ppUp)) {
        r = 1;
    }
    return r;
}



/*
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`id = slot;` before `id = slot + 0x3A;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT* in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 *
 * pokeparty.c.  Restore PP to one move slot: read the move (0x36 + slot),
 * its current PP (0x3A + slot) and its PP ups (0x3E + slot), ask
 * sub_0201C158 for the slot's maximum, and if the slot is short either fill
 * it (amount 0x7F) or add `amount` and clamp at the maximum.
 *
 * The last register copy (`adds r2, r4, #0` ahead of func_02017E40, the new
 * PP kept in r4 where the old one lived) is the compound assignment
 * `pp += (u8)amount`: the spelled-out `pp = (u8)(pp + (u8)amount)` starts a
 * new value that coalesces straight into the argument register (wave 15;
 * docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-
 * the-cached-load.md is the same lever on a field).  sub_0201C158 returns a
 * u8, so `max` is u8 (wave 14).  The dead store `id = slot` is the image's
 * `str r0, [sp]` before the add.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201B970.c \
 *       --func sub_0201B970 --addr 0x0201B970 --thumb
 */
u32 sub_0201B970(void *mon, u32 slot, u32 amount)
{
    u32 move;
    u32 id;
    u8  pp;
    u32 ppUp;
    u8  max;

    move = (u16)func_02017E1C(mon, slot + 0x36, 0);
    if (move == 0) {
        return 0;
    }
    id = slot + 0x3A;
    pp = (u8)func_02017E1C(mon, id, 0);
    ppUp = func_02017E1C(mon, slot + 0x3E, 0);
    max = sub_0201C158(move, (u8)ppUp);
    if (pp < max) {
        if (amount == 0x7F) {
            pp = max;
        } else {
            pp += (u8)amount;
            if (pp > max) {
                pp = max;
            }
        }
        func_02017E40(mon, id, pp);
        return 1;
    }
    return 0;
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * pokeparty.c's healer: sub_0201B9F0 restores one Pokemon (current HP to its
 * maximum, status to zero, and every move slot that is short of PP back to
 * full), and sub_0201BA34 runs it over every occupied slot of a party.
 * sub_0201BA34 is the packet's only entry point, reached from 0x02011062.
 *
 * Both of its calls into the neighbouring functions resolve, and the second one
 * is the interesting one.  0x0201B920 is covered by src/matched/
 * unit_0201B920.c, so the `matched` class would carry it on its own;
 * 0x0201B970 is a near miss (docs/notes/sub_0201B970.c.txt) and has no matched
 * entry at all, and the only `bl` to it inside arm9_main is the one in this
 * file.  What attests it is an overlay: ov118 branches to 0x0201B970 at
 * 0x021BE4D0, and to 0x0201B920 at 0x021BDF2A, and those are real instructions
 * outside the compared range, which is exactly what the `label` class asks for
 * once it reads branches from the whole image rather than from arm9 alone.
 * The two functions here would otherwise have had to be split apart or parked.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * No species, item or move id.  0x7F is the "fill the slot" sentinel
 * sub_0201B970 tests for and has to stay in step with it; 4 is the move slot
 * count written out as the loop bound; 0xA9, 0xA0, 0xA1 and 0x9D are party
 * record ids in src/matched/sub_02018DB4.c's space.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * The id 0xA1 read is used directly as the id 0xA0 write's third argument with
 * nothing bound to a local, so the result reaches r2 straight out of r0; this
 * is the site where the inline spelling is the right one
 * (docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md).
 *
 * sub_0201B9F0's `for` runs 0 to 3 with no entry guard, because the compiler
 * can see the bound; the 0x7F is hoisted into r6 in front of the loop and the
 * index's zero is set before the two writes that precede it.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_0201B9F0.c \
 *       --addr 0x0201B9F0 --thumb
 */
void sub_0201B9F0(void *mon)
{
    s32 i;

    func_02017E40(mon, 0xA0, func_02017E1C(mon, 0xA1, 0));
    func_02017E40(mon, 0x9D, 0);
    for (i = 0; i < 4; i++) {
        if (sub_0201B920(mon, i) == 1) {
            sub_0201B970(mon, i, 0x7F);
        }
    }
}



void sub_0201BA34(void *party)
{
    s32 n;
    s32 i;
    void *mon;

    n = sub_0201AA18(party);
    for (i = 0; i < n; i++) {
        mon = sub_0201AB28(party, i);
        if (func_02017E1C(mon, 0xA9, 0) != 0) {
            sub_0201B9F0(mon);
        }
    }
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * The graphics index of a Pokemon: sub_0201BA68 unpacks the four values that
 * decide it out of the record and sub_0201BABC turns them into a member number
 * of archive 7.  The pair that follows them, sub_0201BB5C and sub_0201BBE8, is
 * the same index arithmetic over a different table and is parked in
 * src/pending/unit_0201BB5C.c because that table has no witness; the cut
 * between the two pairs is what lets this half land
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 *
 * sub_0201BA68 brackets its four reads with func_02017DBC and func_02017DE4,
 * which is the pair the region uses around a run of raw field reads; that is
 * why the reads here are func_02017E88 and not the func_02017E1C of
 * src/matched/sub_02018A7C.c.  The fourth read is written inline as the call's
 * fourth argument rather than bound to a local, which is what puts it in r3
 * with the other three already in place.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 * Four content constants, and the index arithmetic that ties them together is
 * itself a statement about how the sprite archive is packed:
 *
 *   490    the species whose egg has a graphic of its own.  Every other
 *          species shares one egg graphic.
 *   650    the index the ordinary egg occupies, so 651 is that species' egg;
 *          the same 650/651 pair src/matched/unit_0201AFD4.c rejects as
 *          species ids.
 *   7      the first member of archive 7 that belongs to a species, and the
 *          stride is two members per index.
 *   1311   the member the alternate forms start at, which is 652 * 2 + 7, i.e.
 *          immediately after the two egg indices.  A White build with a
 *          different species count would move this number and only this one.
 *   0x1F, 0x20, 0x23   the three personal-record attributes func_02019C90
 *          answers: the form block's first index, the form count, and the flag
 *          that says the forms are not drawn separately.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * The `case 1` arm binds the archive query to a local before assigning the
 * gender.  Written inline, `gender = 1;` is hoisted in front of the `blx` and
 * six bytes come out in the wrong order; the named local is what pins the
 * order, the same way
 * docs/idioms/cmp-operand-order-names-the-temporary.md pins a comparison.
 *
 * `case 2`'s `gender = 0;` and `case 1`'s failure arm are one block, reached
 * by a `b` whose displacement is zero: the source writes the statement out in
 * both arms and the compiler cross-jumps the two copies
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).  The switch
 * is a `cmp`/`beq` chain rather than a table, because three labels are too few
 * for mwccarm to build one
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md, the other side of
 * the density rule).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201BA68.c \
 *       --addr 0x0201BA68 --thumb
 */
u32 sub_0201BA68(void *mon)
{
    u32 save;
    u32 species;
    u32 form;
    u32 gender;
    u32 r;

    save = func_02017DBC(mon);
    species = func_02017E88(mon, 5, 0);
    form = func_02017E88(mon, 0x6F, 0);
    gender = func_02017E88(mon, 0x6E, 0);
    r = sub_0201BABC(species, form, gender, func_02017E88(mon, 0x4C, 0));
    func_02017DE4(mon, save);
    return r;
}



u32 sub_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg)
{
    u32 first;
    u32 hidden;
    u32 count;
    u32 idx;
    u32 ok;

    idx = species * 2 + 7;
    if (isEgg != 0) {
        idx = (u32)((species == 490 ? 1 : 0) + 650) * 2 + 7;
    } else if (form != 0) {
        first = func_02019C90((u16)species, 0, 0x1F);
        hidden = func_02019C90((u16)species, 0, 0x23);
        count = func_02019C90((u16)species, 0, 0x20);
        if (form >= count) {
            form = 0;
        }
        if (hidden == 0 && form != 0) {
            idx = (first + form - 1) * 2 + 1311;
        }
    }
    switch (gender) {
    case 0:
        break;
    case 1:
        ok = func_020490A8(7, idx + 1);
        gender = 1;
        if (ok == 0) {
            gender = 0;
        }
        break;
    case 2:
        gender = 0;
        break;
    }
    return idx + gender;
}



/*
 * note:     224 bytes, two functions
 *
 * The nibble-table twin of src/matched/unit_0201BA68.c: the same egg and
 * alternate-form index arithmetic, indexing a packed table of two four bit
 * values per entry instead of an archive.  sub_0201BBE8 unpacks the four
 * inputs out of a Pokemon record, bracketed by the func_02017DBC /
 * func_02017DE4 pair, and hands them over.
 *
 * The index is the same logical number unit_0201BA68.c computes, one step
 * short of it: there the answer is `n * 2 + 7`, a member of archive 7, here it
 * is `n` itself, and the alternate-form case reaches it as `first + form +
 * 651` where the other reaches `(first + form - 1) * 2 + 1311`.  1311 is
 * 652 * 2 + 7, so the two agree.
 *
 * ---------------------------------------------------------------------------
 * WHY IT WAS CAPPED (HISTORY)
 * ---------------------------------------------------------------------------
 * NO LONGER CAPPED (re-verified 2026-09-22).  The pool word at 0x0201BBE4 is
 * still the only word in the image that holds 0x0209E474, so the `literal`
 * class does discard its only witness.  What closed it is the sole-ref
 * widening of 2026-09-21: 0x0209E474 is 4-aligned and starts a recognised
 * data object, so the site now resolves as `sole-ref` and the unit is EXACT.
 * The old "WHY IT IS CAPPED" reading below is kept only as history.
 *
 * The cut between this pair and sub_0201BA68/sub_0201BABC is what let those
 * two land EXACT.  sub_0201BB5C is reached only from 0x0201BC34, inside this
 * range, so that call is the `local` class and needs no evidence.
 *
 * ---------------------------------------------------------------------------
 * VERSION SENSITIVITY, read this before porting to Pokemon White
 * ---------------------------------------------------------------------------
 *   490    the species whose egg has an entry of its own.
 *   650    the ordinary egg's index, so 651 is that species' egg; 651 again is
 *          the base the alternate-form block is counted from.
 *   0x1F, 0x20, 0x23   the three personal-record attributes func_02019C90
 *          answers: the form block's first index, the form count, and the
 *          "not drawn separately" flag.
 *   0x0209E474  the table itself, one packed byte per index.  Its contents are
 *          content and are not reproduced here.
 *
 * ---------------------------------------------------------------------------
 * NOTES
 * ---------------------------------------------------------------------------
 * The two returns are unequal shift pairs, not bitfields: `lsls #0x14` /
 * `lsrs #0x18` is `(u8)(x >> 4)`, because 32 - 24 is the width and 20 - 24 is
 * the shift, and the low half's equal pair is a plain `(u8)`
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 * The mask has to be written out as well as the cast; `x >> 4` on its own
 * loses the `ands`.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/unit_0201BB5C.c \
 *       --addr 0x0201BB5C --thumb
 */
u32 sub_0201BB5C(u32 species, u32 form, u32 half, u32 isEgg)
{
    u32 first;
    u32 hidden;
    u32 count;
    u32 idx;

    idx = species;
    if (isEgg != 0) {
        idx = (species == 490 ? 1 : 0) + 650;
    } else if (form != 0) {
        first = func_02019C90((u16)species, 0, 0x1F);
        hidden = func_02019C90((u16)species, 0, 0x23);
        count = func_02019C90((u16)species, 0, 0x20);
        if (form >= count) {
            form = 0;
        }
        if (hidden == 0 && form != 0) {
            idx = first + form + 651;
        }
    }
    if (half != 0) {
        return (u8)((g_0209E474[idx] & 0xF0) >> 4);
    }
    return (u8)(g_0209E474[idx] & 0xF);
}



u32 sub_0201BBE8(void *mon)
{
    u32 save;
    u32 species;
    u32 form;
    u32 gender;
    u32 isEgg;

    save = func_02017DBC(mon);
    species = func_02017E88(mon, 5, 0);
    form = func_02017E88(mon, 0x6F, 0);
    gender = func_02017E88(mon, 0x6E, 0);
    isEgg = func_02017E88(mon, 0x4C, 0);
    func_02017DE4(mon, save);
    return sub_0201BB5C(species, form, gender, isEgg);
}



#define REG_DISPCNT      (*(volatile u32 *)0x04000000)


#define REG_DB_DISPCNT   (*(volatile u32 *)0x04001000)


#define OBJ_MAPPING_MASK 0x300010



/*
 *           func_0201BCEC
 *
 * Five leaves after func_0201BBE8.  The first returns 0.  The other four read
 * the OBJ character mapping bits of DISPCNT (bit 4, 1D mapping, and bits
 * 20..21, the 1D boundary) for the main engine (0x04000000) or the sub engine
 * (0x04001000) and turn the 32/64/128 KB boundary into a shift: 2/4/6 and
 * 1/3/5, with the unlisted 256 KB case falling into a separate default that
 * repeats the last value.  Seeded from ov208 0x021C5304, 0x021C531E,
 * 0x021C5324 (func_021C52F0) and ov021 0x021CC8EA, 0x021CC906, 0x021CC90C.
 *
 * Addresses are Black-image addresses.
 */
int func_0201BC3C(void)
{
    return 0;
}



int func_0201BC40(void)
{
    switch (REG_DISPCNT & OBJ_MAPPING_MASK) {
    case 0x10:     return 2;
    case 0x100010: return 4;
    case 0x200010: return 6;
    default:       return 6;
    }
}



int func_0201BC78(void)
{
    switch (REG_DB_DISPCNT & OBJ_MAPPING_MASK) {
    case 0x10:     return 2;
    case 0x100010: return 4;
    case 0x200010: return 6;
    default:       return 6;
    }
}



int func_0201BCB4(void)
{
    switch (REG_DISPCNT & OBJ_MAPPING_MASK) {
    case 0x10:     return 1;
    case 0x100010: return 3;
    case 0x200010: return 5;
    default:       return 5;
    }
}



int func_0201BCEC(void)
{
    switch (REG_DB_DISPCNT & OBJ_MAPPING_MASK) {
    case 0x10:     return 1;
    case 0x100010: return 3;
    case 0x200010: return 5;
    default:       return 5;
    }
}



/*
 * waza_tool.c: the cached single-field read of a move record, and the 32 case
 * getter it ends in.
 *
 * sub_0201BD28 finds the move's record in the cache the constructor in
 * src/matched/unit_0201C328.c builds, loading it through func_02048F4C if the
 * slot it picks is empty or is holding a different move, and falls back to
 * the single record buffer at 0x02146534 when the cache has not been built.
 * The slot search, the "cache full, reuse the last slot" fixup and the load
 * are the same three blocks sub_0201C1F4 and sub_0201C020 repeat for their
 * own records.
 *
 * sub_0201BDB4 has to stay in this file.  The `bl` at 0x0201BDA6 is the only
 * branch to it anywhere in the image, so split off it would have no witness
 * at all; kept here the site is the `local` class and needs none
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md, read the
 * other way round).
 *
 * The getter is an ordinary dense switch: `cmp #0x1F` / `bhi` and a table of
 * 32 signed halfword displacements
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md).  Two things
 * the table says that the C has to repeat exactly:
 *
 *   * entry 29 points at the default body, so id 29 has no case label at all.
 *     It is a gap in the middle of the range and not an empty arm, which is
 *     the distinction docs/idioms/empty-switch-arms-are-what-make-the-table.md
 *     draws;
 *   * the arms are emitted in source order, and that order is not the numeric
 *     order: id 28 is written between 15 and 16, and the three three-way
 *     groups (16, 19, 22), (17, 20, 23) and (18, 21, 24) share one body each.
 *
 * The three grouped bodies index byte arrays at +0x15, +0x18 and +0x1B with a
 * run-time index, so the middle one costs a `movs`/`ldrsb` register-offset
 * pair rather than an immediate load, which is the only thing that says that
 * field is signed (docs/idioms/ldrsh-register-offset-is-signedness.md).
 *
 * Ids 4 and 7 answer a substitute value for one particular stored value,
 * 0x64 for 0x65 and 0 for 6; both reach the function's shared `bx lr` with
 * the loaded value still in r0, which is what says the source returns the
 * value in the ordinary path rather than assigning a result variable.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201BD28.c \
 *       --addr 0x0201BD28 --thumb
 */
u32 sub_0201BD28(u16 id, u32 field)
{
    struct Waza *rec;
    s32 i;

    if (gWazaTool != 0) {
        for (i = 0; i < gWazaTool->count; i++) {
            if (gWazaTool->vals[i] == 0) {
                gWazaTool->vals[i] = id;
                func_02048F4C(gWazaTool->recs[i], 0x15, id);
                break;
            }
            if (id == gWazaTool->vals[i]) {
                break;
            }
        }
        if (i == gWazaTool->count) {
            i--;
            gWazaTool->vals[i] = id;
            func_02048F4C(gWazaTool->recs[i], 0x15, id);
        }
        rec = gWazaTool->recs[i];
    } else {
        rec = &g_02146534;
        func_02048F4C(rec, 0x15, id);
    }
    return sub_0201BDB4(rec, field);
}



u32 sub_0201BDB4(const struct Waza *p, u32 id)
{
    u32 v;

    switch (id) {
    case 0:  return p->unk00;
    case 1:  return p->unk01;
    case 2:  return p->unk02;
    case 3:  return p->unk03;
    case 4:
        v = p->unk04;
        if (v == 0x65) {
            return 0x64;
        }
        return v;
    case 5:  return p->unk05;
    case 6:  return p->unk06;
    case 7:
        v = p->unk0E;
        if (v == 6) {
            return 0;
        }
        return v;
    case 8:  return p->hi;
    case 9:  return p->lo;
    case 10: return p->unk0F;
    case 11: return p->unk08;
    case 12: return p->unk0A;
    case 13: return p->unk0B;
    case 14: return p->unk0C;
    case 15: return p->unk0D;
    case 28: return p->unk10;
    case 16: case 19: case 22:
        return p->unk15[id - 16];
    case 17: case 20: case 23:
        return p->unk18[id - 17];
    case 18: case 21: case 24:
        return p->unk1B[id - 18];
    case 25:
        if (p->unk12 > 0) {
            return p->unk12;
        }
        return 0;
    case 30:
        if (p->unk12 < 0) {
            return -p->unk12;
        }
        return 0;
    case 26:
        if (p->unk13 > 0) {
            return p->unk13;
        }
        return 0;
    case 31:
        if (p->unk13 < 0) {
            return -p->unk13;
        }
        return 0;
    case 27: return p->unk14;
    }
    return 0;
}
