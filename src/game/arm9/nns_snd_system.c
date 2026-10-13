/*
 * file:     nns_snd_system.c
 * unit:     yes
 * function: func_02072374, func_02072440, func_020724E4, func_02072524, func_02072548, func_020726D0, func_02072758, func_02072788, func_02072794, func_020727B4, func_02072894, func_020728E8, func_02072920
 * address:  0x02072374
 * region:   arm9
 * compiler: dsi/../2.0/sp2
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
 *   func_0206DDA4  0x0206DDA4  arm
 *   data_020A8478  0x020A8478  data
 *   g_0214BAC0     0x0214BAC0  data
 *   SND_Init       0x02089848  arm
 *   PM_PrependPostSleepCallback  0x0208C808  arm
 *   PM_AppendPostSleepCallback   0x0208C828  arm
 *   NNS_SndWaveOutInit  0x02072A28  arm
 *   func_02073D5C  0x02073D5C  arm
 *   func_0207312C  0x0207312C  arm
 *   func_02089978  0x02089978  arm
 *   func_020731E0  0x020731E0  arm
 *   func_02073D7C  0x02073D7C  arm
 *   func_02075858  0x02075858  arm
 *   func_02089B38  0x02089B38  arm
 *   func_0208970C  0x0208970C  arm
 *   g_0214BB00     0x0214BB00  data
 *   SND_RecvCommandReply      0x02089978  arm
 *   SND_IsFinishedCommandTag  0x02089D6C  arm
 *   SND_ReadDriverInfo        0x02089794  arm
 *   SND_GetCurrentCommandTag  0x02089D40  arm
 *   DC_InvalidateRange        0x020862B8  arm
 *   SND_FlushCommand          0x02089B38  arm
 *   func_0208A0A4 0x0208A0A4  arm
 *   func_02073F3C  0x02073F3C  arm
 *   NNS_SndStartTimer  0x02073EE4  arm
 */
struct SNDCommand;
struct SNDDriverInfo;
struct SNDTrackInfo;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef short          s16_02072374;

typedef int            s32;

typedef long long      s64_02072374;

struct SRC_02072374 {
    u8  pad_00[0x18];
    s32 f18;
    s32 f1c;
    s16_02072374 f20;
    s16_02072374 f22;
    u8  pad_24[8];
    u16 f2c;
    volatile u16 f2e;
};

struct DST_02072374 {
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
    s16_02072374 f20;
    s16_02072374 f22;
    u8  pad_24[8];
    u16 f2c;
    u16 f2e;
};

typedef int           s32_02072524;

struct DST_02072524 {
    s32_02072524 f00;
    s32_02072524 f04;
    u8  pad_08[8];
    s32_02072524 f10;
    s32_02072524 f14;
    u8  pad_18[0x18];
    s32_02072524 f30;
    s32_02072524 f34;
};

typedef signed short s16_02072524;

typedef signed int   s32_02072548;

typedef signed long long s64_02072524;

typedef struct Obj {
    u32 f00;
    u8  pad04[0x18 - 4];
    s32_02072548 f18;
    s32_02072548 f1c;
    s16_02072524 h20;
    s16_02072524 h22;
    s32_02072548 f24;
    s32_02072548 f28;
    u8  pad2c[0x30 - 0x2c];
    volatile s32_02072548 f30;
    volatile s32_02072548 f34;
} Obj;

typedef struct Rec {
    u32 hdr;
    s32_02072548 f04;
    s32_02072548 f08;
    s32_02072548 f0c;
    s32_02072548 f10;
    s32_02072548 f14;
    s32_02072548 f18;
    s32_02072548 f1c;
    s32_02072548 f20;
    s32_02072548 f24;
    s32_02072548 f28;
    s32_02072548 f2c;
    s32_02072548 f30;
    s32_02072548 f34;
    s32_02072548 f38;
    s32_02072548 f3c;
    s32_02072548 f40;
    s32_02072548 f44;
    s32_02072548 f48;
} Rec;

typedef void (*Fill)(s32_02072548 *out, Obj *o);

struct SleepCb { void (*fn)(void *); void *arg; void *p08; void *p0c; };

struct Sys {
    signed char idx;
    u8  p01[3];
    u32 pending;
    u32 tag;
    u32 f0c;
    struct SleepCb cb10;
    struct SleepCb cb20;
};

typedef signed char s8;

extern void func_0207C930(s32 a, s32 b);
extern s32  func_0207C86C(void);
extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
extern void SND_Init(void);
extern void PM_PrependPostSleepCallback(struct SleepCb *cb);
extern void PM_AppendPostSleepCallback(struct SleepCb *cb);
extern void NNS_SndWaveOutInit(void);
extern void func_02073D5C(void);
extern void func_0207312C(void);
extern const struct SNDCommand *func_02089978(u32 flags);
extern void func_020731E0(void);
extern void func_02073D7C(void);
extern void func_02075858(void);
extern void func_02089B38(s32 a);
extern void func_0208970C(int volume);
extern void func_02089754(int pan);
extern void func_02089774(void);
extern u32  SND_RecvCommandReply(u32 mode);
extern u32  SND_IsFinishedCommandTag(u32 tag);
extern void SND_ReadDriverInfo(void *dst);
extern u32  SND_GetCurrentCommandTag(void);
extern void DC_InvalidateRange(void *p, u32 n);
extern void SND_FlushCommand(u32 flags);
extern int func_0208A0A4(struct SNDDriverInfo *, int playerNo, int trackNo, struct SNDTrackInfo *trackInfo);
extern void NNS_SndStartTimer(void);
extern void func_020894DC(u32 a, u32 b, u32 c, u32 d);
extern u32  func_02089D40(void);
extern void func_02089CD4(u32 a);
extern void func_02073F3C(void);
void func_02072374(struct DST_02072374 *d, struct SRC_02072374 *s);
void func_02072440(struct DST_02072374 *d, struct SRC_02072440 *s);
void func_020724E4(struct DST_02072374 *d, struct SRC_02072440 *s);
void func_02072524(struct DST_02072524 *d);
void func_02072548(Obj *o);
void func_020726D0(void);
void func_02072758(void);
void func_02072788(int volume);
void func_02072794(u32 flag);
u32 func_020727B4(void);
int func_02072894(int playerNo, int trackNo, struct SNDTrackInfo *trackInfo);
void func_020728E8(void);
void func_02072920(void *p);
extern Fill data_020A8478[];
extern struct Sys g_0214BAC0;
extern u8 g_0214BB00[];




/*
 * The s32 2x2 member of the (DST_02072374, SRC) matrix-constructor family
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
 *     d->f00 = (s32)(((s64_02072374)e * a) >> 12);
 *     q = ...; r = ...; d->f14 = r;
 * which is the image's STORE order but not its VALUE order.  Moving the f00
 * store down, so the three narrowings are computed as a run and only then
 * stored,
 *     q = (s32)(((s64_02072374)e * b) >> 12);
 *     r = (s32)(((s64_02072374)c * a) >> 12);
 *     d->f00 = (s32)(((s64_02072374)e * a) >> 12);
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
void func_02072374(struct DST_02072374 *d, struct SRC_02072374 *s)
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

    q = (s32)(((s64_02072374)e * b) >> 12);
    r = (s32)(((s64_02072374)c * a) >> 12);
    d->f00 = (s32)(((s64_02072374)e * a) >> 12);
    d->f14 = r;
    d->f04 = ((s32)(((s64_02072374)c * b) >> 12) * func_0207C86C()) >> 12;

    func_0207C930(f12, e12);

    d->f30 = ((s32)s->f2c * q) << 4;
    d->f34 = ((0 - (s32)s->f2e) * (r - 0x1000)) << 4;
    d->f10 = ((0 - q) * func_0207C86C()) >> 12;
}




/*
 * Two functions of the 0x02071CDC constructor family, 228 bytes: the
 * all-s16_02072374 variant at 0x02072440 (164 B, no smull anywhere - every term is
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
void func_02072440(struct DST_02072374 *d, struct SRC_02072440 *s)
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



void func_020724E4(struct DST_02072374 *d, struct SRC_02072440 *s)
{
    d->f00 = s->f18;
    d->f14 = s->f1c;
    d->f04 = 0;
    d->f30 = 0;
    d->f34 = ((0 - (s32)s->f2e) * (s->f1c - 0x1000)) << 4;
    d->f10 = 0;
}





/*
 * The identity member of the 0x02071CDC constructor family, an unlabelled
 * leaf (saves no lr). The same 36-byte body appears twice in this file, at
 * 0x02072524 and 0x02072524.
 *
 * PINNED ../2.0/sp2 on the "kept constants" tell (docs/FRONTEND-PINS.md),
 * the same measurement already taken for src/matched/func_020713A4.c: the
 * image materialises the unit scale FIRST, `mov r2, #0x1000`
 * (`01 2a a0 e3`) at 0x02072524 followed by `str r2, [r0]`, and only then
 * `mov r1, #0` (`00 10 a0 e3`) at 0x0207252C. dsi/1.1p1 -O4,p schedules the
 * zero first for the same 36 bytes, 9 concrete bytes out, under all ten
 * spellings measured in docs/notes/func_02072524.c.txt (store order,
 * constants bound to locals, zero derived from the live 0x1000, re-read of
 * a stored field). Under the pin the same C is 36 bytes, 0 mismatches.
 */
void func_02072524(struct DST_02072524 *d)
{
    d->f00 = 0x1000;
    d->f04 = 0;
    d->f10 = 0;
    d->f14 = 0x1000;
    d->f30 = 0;
    d->f34 = 0;
}





/*
 * One of the two CALLERS of the 0x02071CDC constructor family
 * (docs/notes/pkt_02071DD4.c.txt).  It builds a 0x4c-byte command record
 * on the stack, fills the record's 2x3 matrix block by dispatching on the
 * low three bits of the object's flag word through a pointer table, then
 * applies the object's f30/f34 scales to the two rows -- each through the
 * family's `>> 12` on an s64_02072524 product, which folds to `lsr #0xc` +
 * `orr ..., lsl #20` -- and hands the record to func_0206DDA4.
 *
 * Each scale is skipped outright when it is already the unit 0x1000, so
 * both are guarded compares against 0x1000 rather than multiplies by one.
 *
 * Three levers, all measured, and all needed:
 *
 * L1  f30/f34 ARE `volatile`.  The image RE-READS the scale from the
 *     object before the second and third multiply of each block
 *     (`ldr r2,[r4,#0x30]` at 0x02071FC4, `ldr r1,[r4,#0x30]` at
 *     0x02071FDC); 1.1p1 otherwise forwards the register it still holds
 *     live and batches all three smulls, which is 8 bytes short.  But
 *     plain `volatile` also re-reads for the GUARD compare and comes out
 *     4 bytes LONG, so the guard's own load is bound to a local `s` and
 *     the FIRST multiply uses that local while the other two re-read.
 * L2  THE CALL'S BASE IS A POINTER LOCAL.  The image spends two
 *     instructions on the argument, `add r1, sp, #0` then
 *     `add r1, r1, #4` (0x02072040/0x02072048); `&r.f04` folds to a
 *     single `add r1, sp, #4` and loses 4 bytes.  `(s32 *)&r` bound
 *     first, then `base + 1`, reproduces the pair.
 * L3  THE FOUR HEADER CONSTANTS ARE ORDERED BY THE STORES, NOT THE
 *     DECLARATIONS.  mwcc emits the constant movs in order of the first
 *     store that uses each, and sinks any constant whose store sits
 *     after the zero run.  `f04, f48, f40, f44` is the only one of the
 *     orderings measured that gives the image's `mov r1,#0 / mov r3,#3 /
 *     mov r2,#2 / mov r0,#0x1000`; f44-first is 27 bytes out and
 *     f48-first 8, differing by a pure rotation of the three non-zero
 *     constants.  Declaration order and binding the constants to locals
 *     at all are both insensitive.
 *
 * Derived from src/matched/func_02071F20.c, its sibling and the other caller of
 * the 0x02071CDC constructor family (docs/notes/pkt_02071DD4.c.txt, "NOT
 * ATTEMPTED").  Same 0x4c-byte stack record, same two header constants
 * (0x00101610 / 0x00101810), same 2x3 fill dispatched through the low three
 * flag bits -- through data_020A8478 here rather than data_020A8458 -- and the
 * same two f30/f34 scale blocks.  L1, L2 and L3 above all transferred
 * unchanged, including the `volatile` f30/f34 with the guard's own load bound
 * to `s`, and were not re-derived.
 *
 * What this one adds over func_02071F20: three flag-guarded writes back into
 * the OBJECT, ahead of the dispatch -- bit 0 sets f1c and f18 to the unit
 * scale, bit 1 sets h22 to 0x1000 and h20 to 0, bit 2 clears f28 and f24.  The
 * store order inside each pair is high field first, and each guard re-reads
 * o->f00 (`ldr r0,[r4]` at 0x020725AC, 0x020725BC, 0x020725D8, 0x020725EC).
 * h20/h22 are s16_02072524: the pair is `strh`.
 *
 * PIN ../2.0/sp2, the "kept branches" tell (docs/FRONTEND-PINS.md), and exactly
 * the one docs/notes/pkt_02071DD4.c.txt flagged at this address in advance.
 * The image keeps `tst r0, #2` at 0x020725C0 (`02 00 10 e3`) and `beq 0x020725D8`
 * at 0x020725C4 (`03 00 00 0a`) over the FOUR-instruction bit-1 guard body at
 * 0x020725C8..0x020725D4 (`mov r0,#0x1000` / `strh r0,[r4,#0x22]` /
 * `mov r0,#0` / `strh r0,[r4,#0x20]`).  1.1p1 -O4,p predicates it to
 * `movne/strhne/movne/strhne` -- and, having done so, reverses the pair to
 * h20-then-h22 -- giving 388 bytes against the original's 392, 226 concrete
 * bytes out and the whole body shifted by four.  The bit-0 and bit-2 guards,
 * being two instructions each, are predicated under BOTH front ends and are
 * not evidence either way.  Under the pin the same C is 392 bytes,
 * 0 mismatches.
 */
void func_02072548(Obj *o)
{
    Rec r;
    s32_02072548 z;
    s32_02072548 three = 3;
    s32_02072548 two = 2;
    s32_02072548 unit = 0x1000;

    z = 0;
    if (o->f00 & 8) {
        r.hdr = 0x00101610;
    } else {
        r.hdr = 0x00101810;
    }
    r.f04 = three;
    r.f48 = two;
    r.f40 = z;
    r.f44 = unit;
    r.f34 = z;
    r.f30 = z;
    r.f2c = z;
    r.f28 = z;
    r.f24 = z;
    r.f20 = z;
    r.f14 = z;
    r.f10 = z;

    if (o->f00 & 1) {
        o->f1c = unit;
        o->f18 = unit;
    }
    if (o->f00 & 2) {
        o->h22 = 0x1000;
        o->h20 = 0;
    }
    if (o->f00 & 4) {
        o->f28 = 0;
        o->f24 = 0;
    }

    data_020A8478[o->f00 & 7](&r.f08, o);

    {
        s32_02072548 s = o->f30;
        if (s != 0x1000) {
            r.f08 = (s32_02072548)(((s64_02072524)s * r.f08) >> 12);
            r.f0c = (s32_02072548)(((s64_02072524)o->f30 * r.f0c) >> 12);
            r.f38 = (s32_02072548)(((s64_02072524)o->f30 * r.f38) >> 12);
        }
    }
    {
        s32_02072548 s = o->f34;
        if (s != 0x1000) {
            r.f18 = (s32_02072548)(((s64_02072524)s * r.f18) >> 12);
            r.f1c = (s32_02072548)(((s64_02072524)o->f34 * r.f1c) >> 12);
            r.f3c = (s32_02072548)(((s64_02072524)o->f34 * r.f3c) >> 12);
        }
    }

    {
        s32_02072548 *base = (s32_02072548 *)&r;
        func_0206DDA4(r.hdr, base + 1, 0x12);
    }
}




/*
 * Sound-system one-shot init: take the f0c latch, SND_Init(), register the two
 * post-sleep callbacks whose PMSleepCallbackInfo blocks live at +0x10 and +0x20
 * of the same global, bring up the three subsystems, then seed b00 = -1 and
 * f04 = 1.
 *
 * BYTE-CORRECT under the pin: 136 bytes, 0 concrete mismatches.  PARKED, not
 * filed: three of the eight PC24 sites have no witness outside this function's
 * own 136 bytes --
 *   +0x1C  SND_Init (0x02089848): the `bl` here is the only branch to it
 *          anywhere in the image, arm9 and all overlays.
 *   +0x54  func_02073D5C: only src/pending/func_02073D5C.c names it, and a
 *          `pending` file is never a `matched` witness.
 *   +0x58  func_0207312C: same, src/pending/func_0207312C.c, which is itself
 *          parked for want of a `literal` witness on 0x0214E024 (see its
 *          header and docs/FRONTEND-PINS.md).
 * Promoting either of those two pending files promotes this one with it; there
 * is no split that helps, since all three witnesses would still be inside.
 *
 * Signedness lever: b00 is `signed char`, not `u8`.  The image emits
 * `mvn r1, #0` at 0x02072730; written as `(u8)-1` the compiler materialises
 * `mov r0, #0xff` instead, which is a concrete byte difference, not a
 * relocation one.
 *
 * PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md).  The image
 * RELOADS the base pool word 0x0214BAC0 three separate times -- `ldr r0,[pc,#0x68]`
 * at 0x020726D4, `ldr r1,[pc,#0x48]` at 0x020726F4 and `ldr r0,[pc,#0x10]` at
 * 0x0207272C, three distinct pool entries at 0x02072744, 0x02072750 and
 * 0x02072754 for one symbol -- and rematerialises the literal 1 twice
 * (`mov r1,#1` at 0x020726E4 and again at 0x02072738), which is why the frame
 * is a bare `push {r3, lr}`.  1.1p1 -O4,p hoists the base into callee-saved r4
 * and the 1 into r5 across all five calls, needing `push {r3, r4, r5, lr}` and
 * folding the pool to two words: 124 bytes against the original's 136, 75
 * concrete bytes out.  Under the pin the same C is 136 bytes, 0 mismatches.
 */
void func_020726D0(void)
{
    if (g_0214BAC0.f0c != 0) {
        return;
    }
    g_0214BAC0.f0c = 1;
    SND_Init();
    g_0214BAC0.cb10.fn = (void (*)(void *))func_020728E8;
    g_0214BAC0.cb10.arg = 0;
    g_0214BAC0.cb20.fn = func_02072920;
    g_0214BAC0.cb20.arg = 0;
    PM_PrependPostSleepCallback(&g_0214BAC0.cb10);
    PM_AppendPostSleepCallback(&g_0214BAC0.cb20);
    NNS_SndWaveOutInit();
    func_02073D5C();
    func_0207312C();
    g_0214BAC0.idx = -1;
    g_0214BAC0.pending = 1;
}





/*
 * Not a member of the 0x02071CDC constructor family: the subsystem's boot
 * sequence. Spins until func_02089978(0) reports ready, runs the three
 * initialisers, then hands 0 to func_02089B38.
 *
 * PINNED ../2.0/sp2 on the "kept constants" tell (docs/FRONTEND-PINS.md).
 * The image rematerialises the last call's zero argument, `mov r0, #0`
 * (`00 00 a0 e3`) at 0x0207277C, although the spin loop is still holding a
 * zero live in the callee-saved r4 it set up at 0x0207275C; dsi/1.1p1 -O4,p
 * reuses it and emits `mov r0, r4` (`04 00 a0 e1`) instead, the same 48
 * bytes with exactly those 2 concrete bytes out. Five spellings measured in
 * docs/notes/pkt_02071DD4.c.txt (a `z` local, a bare literal 0, a
 * `for (z = 0; ...)` head, passing the same `z` to the last call, and the
 * truthiness form `while (f(0))`) all share the constant. Under the pin the
 * same C is 48 bytes, 0 mismatches: BYTE-CORRECT, and the 2-byte codegen
 * difference is gone.
 *
 * CAPPED AT MATCH for lack of an outside witness, not for codegen. Three of
 * the five PC24 sites (func_020731E0, func_02073D7C, func_02075858) have no
 * branch anywhere in the image outside this function's own 48 bytes, and
 * nothing under src/matched/ reproduces the ranges that define them, so the
 * `label` and `matched` classes both refuse. There is nothing to split: this
 * is one function, and it is the sole caller of all three. It promotes to
 * EXACT unchanged the moment any one of 0x020731E0, 0x02073D7C, 0x02075858
 * is filed EXACT elsewhere, or a second caller of one is decompiled.
 *
 * 2026-09-21, unblock lane: ONE OF THE THREE BLOCKING SITES IS NOW CLEARED.
 * func_020731E0 (the +0x18 site) was promoted to src/matched/ this pass and
 * resolves `matched x1`; the file is now MATCH* with 3 of 5 relocations
 * resolved.  The two that remain are +0x1C (func_02073D7C, 128 bytes at
 * 0x02073D7C) and +0x20 (func_02075858, 272 bytes at 0x02075858), neither of
 * which has any branch outside this function's own bytes.  Both must be
 * written and filed EXACT in their own right -- there is no second caller to
 * find for either -- and then this file promotes with no change to the C.
 * Verify it with `--cc ../2.0/sp2 --arm`, not the default 1.1p1.
 */
void func_02072758(void)
{
    while (func_02089978(0) != 0)
        ;

    func_020731E0();
    func_02073D7C();
    func_02075858();
    func_02089B38(0);
}


void func_02072788(int volume)
{
    func_0208970C(volume);
}




void func_02072794(u32 flag)
{
    if (flag != 0) {
        func_02089754(0x40);
    } else {
        func_02089774();
    }
}




/*
 * Double-buffered SND_ReadDriverInfo pump over the 0x0214BAC0 control block
 * (the same base src/pending/func_020726D0.c initialises) and the pair of
 * 0x11E0-byte info buffers at 0x0214BB00.
 *
 * BYTE-CORRECT at 212 bytes, 0 concrete mismatches.  PARKED, NOT FILED: the two
 * PC24 sites at +0x68 and +0xB8 both name SND_ReadDriverInfo (0x02089794),
 * whose ONLY branches anywhere in the image are those two `bl`s, both inside
 * this one function.  `label` refuses a witness that lives inside the compared
 * range, and the two calls sit in mutually exclusive arms of the same function,
 * so no --suggest-split cut can separate them.  Capped at MATCH until some
 * other caller of SND_ReadDriverInfo is filed.
 *
 * PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md).  The image
 * RELOADS the 0x0214BAC0 base pool word FOUR separate times -- `ldr r0,[pc,#0xc8]`
 * at 0x020727B8, `ldr r0,[pc,#0xa4]` at 0x020727DC, `ldr r0,[pc,#0x8c]` at
 * 0x020727F4 and `ldr r1,[pc,#0x5c]` at 0x02072824, plus a fifth at 0x02072844
 * and a sixth at 0x02072874 -- all resolving to the single pool word at
 * 0x02072888, which is why the frame is a bare `push {r4, lr}` (`10 40 2d e9`).
 * 1.1p1 -O4,p hoists the base into callee-saved r4 and CSEs the `mov r0, #0`
 * arguments into r5, needing `push {r3, r4, r5, lr}`: the same 212 bytes with
 * 45 concrete bytes out.  Under the pin the same C is 212 bytes, 0 mismatches.
 *
 * One lever needed only under the pin: the index toggle must be written as an
 * explicit if/else pair of stores (`if (idx == 0) idx = 1; else idx = 0;`).
 * The boolean form `idx = (s8)(idx == 0);` schedules the third base reload one
 * instruction late and is 6 bytes out; `volatile` on the struct and on the
 * field alone are both 6 out as well.
 */
u32 func_020727B4(void)
{
    if (g_0214BAC0.pending == 0) {
        while (SND_RecvCommandReply(0) != 0)
            ;

        if (SND_IsFinishedCommandTag(g_0214BAC0.tag) == 0)
            return 0;

        if (g_0214BAC0.idx < 0)
            g_0214BAC0.idx = 1;

        SND_ReadDriverInfo(&g_0214BB00[g_0214BAC0.idx * 0x11E0]);
        g_0214BAC0.tag = SND_GetCurrentCommandTag();
        if (g_0214BAC0.idx == 0)
            g_0214BAC0.idx = 1;
        else
            g_0214BAC0.idx = 0;
        DC_InvalidateRange(&g_0214BB00[g_0214BAC0.idx * 0x11E0], 0x11E0);
        SND_FlushCommand(0);
        return 1;
    }

    SND_ReadDriverInfo(&g_0214BB00[0]);
    g_0214BAC0.tag = SND_GetCurrentCommandTag();
    g_0214BAC0.pending = 0;
    return 0;
}




/*
 *           and it is this function, so no branch outside 0x02072894..0x020728E8
 *           witnesses it.  Every concrete byte reproduces.
 *
 * r1 (b) is parked in lr as soon as it is read, because the predicated
 * `ldrge r1, [pc]` that materialises the table base clobbers r1 before the
 * call; the fourth argument (c) is copied into r3 first for the same reason,
 * r2 being needed for b again at the call.
 */
int func_02072894(int playerNo, int trackNo, struct SNDTrackInfo *trackInfo)
{
    s8 idx = g_0214BAC0.idx;
    u8 *p;

    if (idx < 0) p = 0;
    else         p = g_0214BB00 + idx * 0x11E0;
    if (p == 0) return 0;
    return func_0208A0A4((struct SNDDriverInfo *)p, playerNo, trackNo, trackInfo);
}




void func_020728E8(void)
{
    u32 res;

    NNS_SndStartTimer();
    func_020894DC(0, 0, 0, 0);
    res = func_02089D40();
    func_02089B38(1);
    func_02089CD4(res);
}


void func_02072920(void *p)
{
    func_02073F3C();
}
