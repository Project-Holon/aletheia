/*
 * file:     unit_02072374_p01.c
 * unit:     yes
 * function: func_02072374, func_02072440, func_020724E4
 * address:  0x02072374
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0207C930  0x0207C930  arm
 *   func_0207C86C  0x0207C86C  arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef short          s16;

typedef int            s32;

typedef long long      s64;

struct SRC_02072374 {
    u8  pad_00[0x18];
    s32 f18;
    s32 f1c;
    s16 f20;
    s16 f22;
    u8  pad_24[8];
    u16 f2c;
    volatile u16 f2e;
};

struct DST {
    s32 f00;
    s32 f04;
    u8  pad_08[8];
    s32 f10;
    s32 f14;
    u8  pad_18[0x18];
    s32 f30;
    s32 f34;
};

typedef unsigned int   u32;

struct SRC_02072440 {
    u8  pad_00[0x18];
    s32 f18;
    s32 f1c;
    s16 f20;
    s16 f22;
    u8  pad_24[8];
    u16 f2c;
    u16 f2e;
};

extern void func_0207C930(s32 a, s32 b);
extern s32  func_0207C86C(void);


/*
 * The s32 2x2 member of the (DST, SRC) matrix-constructor family
 * (docs/families/cluster_02071EAC.h): f18/f1c x f20/f22 through four
 * `smull`s reduced by the family's `>> 12`, with both FX divisions and the
 * plain 32-bit f30/f34 pair.
 *
 * CLOSED AFTER THREE PREVIOUS PASSES.  docs/notes/pkt_02072374.c.txt records
 * this address at DIFF 17, then 7, then 8 across three lanes and some
 * thirty-odd measured spellings, and concludes that the residue -- a stable
 * r5/r6 exchange over seven instructions, all of them `smull` / `lsr` /
 * `orr` / `mul` / `rsb`, i.e. multiply-class instructions or direct consumers
 * of one -- "is chosen after linearisation and is not source-addressable".
 * It IS source-addressable, and the address is ONE STATEMENT REORDER.
 *
 * THE LEVER: THE `d->f00` STORE SITS AFTER BOTH `q` AND `r`, NOT BEFORE THEM.
 * The note's best source writes
 *     d->f00 = (s32)(((s64)e * a) >> 12);
 *     q = ...; r = ...; d->f14 = r;
 * which is the image's STORE order but not its VALUE order.  Moving the f00
 * store down, so the three narrowings are computed as a run and only then
 * stored,
 *     q = (s32)(((s64)e * b) >> 12);
 *     r = (s32)(((s64)c * a) >> 12);
 *     d->f00 = (s32)(((s64)e * a) >> 12);
 *     d->f14 = r;
 * takes it from 8 concrete bytes to 0.  The reason is the one the cluster
 * header's L8 names: a value's colour follows its first-definition order, and
 * an intervening store re-numbers everything after it.  With the store out of
 * the way, `c`'s product is numbered before `q`'s and the two take the
 * image's registers.  The note's own row "q hoisted above r with the f14
 * store last (7, the same as the filed shape)" was one step from this and
 * stopped at moving the f14 store rather than the f00 store.
 *
 * Found by tools/permuter.py in a single hill pass -- `reorder(+2)`, 269
 * compiles, 8 -> 0 -- after thirty-odd hand spellings had not reached it.
 *
 * The other three levers the note establishes are all still required and are
 * carried below unchanged:
 *   - the two `<< 12` shifted angle values are NAMED LOCALS live across the
 *     whole body (L4 of docs/families/cluster_02070B64.h), which is what
 *     forces the ten-register push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr};
 *   - `b` (f20) is bound BEFORE `c` (f1c), matching the image's load order
 *     f22 / f18 / f20 / f1c at 0x0207239C..0x020723A8;
 *   - `s->f2e` is `volatile`, so the second `ldrh` at 0x020723B0 survives.
 *
 * NO PIN.  With the reorder in place the DEFAULT dsi/1.1p1 produces the bytes
 * exactly as ../2.0/sp2 does (both 204 bytes, 0 mismatches), so the file takes
 * the project default.  This retires the note's standing question about which
 * front end is "the better of the two" here: at the correct source neither is
 * better, and the 8-vs-14 gap the note measured was an artefact of the
 * mis-ordered store, not a front-end tell.
 */
void func_02072374(struct DST *d, struct SRC_02072374 *s)
{
    s32 e, a, c, b;
    s32 q, r;
    s32 f12, e12;

    f12 = (s32)s->f2c << 12;
    e12 = (s32)s->f2e << 12;
    func_0207C930(e12, f12);

    e = s->f18;
    a = (s32)s->f22;
    b = (s32)s->f20;
    c = s->f1c;

    q = (s32)(((s64)e * b) >> 12);
    r = (s32)(((s64)c * a) >> 12);
    d->f00 = (s32)(((s64)e * a) >> 12);
    d->f14 = r;
    d->f04 = ((s32)(((s64)c * b) >> 12) * func_0207C86C()) >> 12;

    func_0207C930(f12, e12);

    d->f30 = ((s32)s->f2c * q) << 4;
    d->f34 = ((0 - (s32)s->f2e) * (r - 0x1000)) << 4;
    d->f10 = ((0 - q) * func_0207C86C()) >> 12;
}


/*
 * Two functions of the 0x02071CDC constructor family, 228 bytes: the
 * all-s16 variant at 0x02072440 (164 B, no smull anywhere - every term is
 * a plain `ldrsh` times an `ldrh`) and the UNLABELLED leaf at 0x020724E4
 * (64 B), which saves no lr and so never gets a func_ label. Folding the
 * follower in here is what turns the lead function's EXACT* into EXACT.
 *
 * The third leaf of the file, the pure-identity writer at 0x02072524
 * (36 B, byte-identical to the one at 0x02071EFC), is NOT in this unit:
 * 1.1p1 -O4,p hoists `mov r1, #0` ahead of `mov r2, #0x1000` where the
 * image materialises 0x1000 first. Nine store-order and constant-binding
 * spellings all give the same 3-instruction swap; see
 * docs/notes/func_02071EFC.c.txt.
 */
void func_02072440(struct DST *d, struct SRC_02072440 *s)
{
    s32 e12, f12, t;

    e12 = (s32)((u32)s->f2c << 12);
    f12 = (s32)((u32)s->f2e << 12);

    func_0207C930(f12, e12);

    d->f00 = s->f22;
    d->f14 = s->f22;

    t = func_0207C86C();
    d->f04 = (s->f20 * t) >> 12;

    func_0207C930(e12, f12);

    d->f30 = ((s32)s->f2c * s->f20) << 4;
    d->f34 = ((0 - (s32)s->f2e) * (s->f22 - 0x1000)) << 4;

    t = func_0207C86C();
    d->f10 = ((0 - (s32)s->f20) * t) >> 12;
}

/*
 * Two functions of the 0x02071CDC constructor family, 228 bytes: the
 * all-s16 variant at 0x02072440 (164 B, no smull anywhere - every term is
 * a plain `ldrsh` times an `ldrh`) and the UNLABELLED leaf at 0x020724E4
 * (64 B), which saves no lr and so never gets a func_ label. Folding the
 * follower in here is what turns the lead function's EXACT* into EXACT.
 *
 * The third leaf of the file, the pure-identity writer at 0x02072524
 * (36 B, byte-identical to the one at 0x02071EFC), is NOT in this unit:
 * 1.1p1 -O4,p hoists `mov r1, #0` ahead of `mov r2, #0x1000` where the
 * image materialises 0x1000 first. Nine store-order and constant-binding
 * spellings all give the same 3-instruction swap; see
 * docs/notes/func_02071EFC.c.txt.
 */
void func_020724E4(struct DST *d, struct SRC_02072440 *s)
{
    d->f00 = s->f18;
    d->f14 = s->f1c;
    d->f04 = 0;
    d->f30 = 0;
    d->f34 = ((0 - (s32)s->f2e) * (s->f1c - 0x1000)) << 4;
    d->f10 = 0;
}
