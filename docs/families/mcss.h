/*
 * docs/families/mcss.h -- shared declarations for the mcss.c family.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and `match.py` never sees it.  It is the adjudicated
 * union of the declarations the family's byte-exact sources already carry,
 * written down once so a new attempt on an open function starts from the
 * settled shape instead of re-deriving it.
 *
 * Family: original source file **mcss.c**, 0x02014B08..0x020173EC in the
 * ARM9 image (edges fuzzy by a function or two).  The file name is not a
 * guess: src/matched/sub_020159C8.c resolves the allocator's fourth
 * argument to 0x020A72CC and the bytes there spell "mcss.c"; the same word
 * is the __FILE__ argument of every allocation in the family
 * (func_02014B08 lines 0x78/0x7f/0x8e, func_020159C8 line 906,
 * func_0201624C lines 1942/1950, func_020163C4 line 0x840/0x858,
 * func_02016630 line 0x8AB/0x8C3, func_02016984 line 0x970).  The line
 * numbers are monotone in address, which is the second, independent check
 * that this really is one original translation unit.
 *
 * Derived from the 59 matched sources found with
 *   grep -l "address:  0x02014\|address:  0x02015\|address:  0x02016\|\
 *            address:  0x02017[0-3]" src/matched/*.c
 * plus the four ctor helpers at 0x02049FBC..0x0204A17C
 * (src/matched/unit_02049DB4.c, func_0204A03C.c, unit_0204A07C.c,
 * unit_0204A0FC.c), which are arc_util.c and not part of this family but
 * whose prototypes every mcss constructor depends on.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction
 * constrains a field; a name does not.  `ldrsb`/`ldrsh` prove signedness
 * (there is no immediate-offset form, see
 * docs/idioms/ldrsh-register-offset-is-signedness.md); a shift pair of
 * unequal amounts proves a bitfield's width and position; a plain `ldr`
 * followed by an `lsls/lsrs #0x10` pair proves the FIELD is 32-bit and the
 * narrowing happens at the use, NOT that the field is u16 (an `ldrh` is
 * what a u16 field produces, and it is four bytes cheaper -- this exact
 * tell is recorded in src/matched/func_02016984.c and again in
 * src/matched/unit_02014CB8.c).  Where two matched files disagree, the
 * file whose code actually constrains the field wins and the losing
 * spelling is recorded beside it as `WAS:`.
 */

#ifndef MCSS_H
#define MCSS_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;
typedef signed long long s64;

struct McssSys;
struct McssCell;
struct McssWork;
struct McssSrc;

/* ------------------------------------------------------------------ */
/* THE FILE NAME.  Declared as an extern array pinned by address, never  */
/* written `__FILE__`; see                                              */
/* docs/idioms/file-string-is-an-abs32-into-the-string-area.md.          */
/* Eight matched files in this family carry the same pool word, which is */
/* what attests the site through the `literal` class (the witness list   */
/* is in src/matched/func_02016984.c's header).                          */
/*   symbols:  sMcssFile  0x020A72CC  data                               */
/* Spelled `sFile_020A72CC` in func_02014B08, `data_020A72CC` in         */
/* func_0201624C / func_02016984, `func_020159C8_File` in sub_020159C8:  */
/* three names for one object.                                           */
/* ------------------------------------------------------------------ */
extern const char sMcssFile[];              /* 0x020A72CC -- "mcss.c"   */

/* A second data word, 0x020A72D4, is the 4-entry pointer table          */
/* func_020172D8 walks (docs/notes/pkt_020172D8.c.txt).  Four pointers   */
/* to lists of 2-byte records terminated by 0xFF in byte 0.              */
extern const u8 *sMcssTable[4];             /* 0x020A72D4               */
/* CONFIRMED 2026-09-22 by the func_020172D8 transcription
 * (docs/notes/pkt_020172D8.c.txt): four lists of 2-byte records
 * terminated by 0xFF in byte 0, and func_020172D8 consumes ONE BYTE of
 * its u32 second argument per list (`a1 >>= 8` once per outer pass), so
 * the four lists are indexed by the four bytes of one packed word.
 * Per record: byte 0 + ((a1 & 0xF) - 8) and byte 1 + (((a1 & 0xF0) >> 4)
 * - 8), both truncated to u8; the first's bit 0 selects which of two
 * nibble ranges is bumped, and its value >> 1 plus (second << 7) and
 * plus ((second + 0x28) << 7) are the two byte offsets written.        */

/* ================================================================== *
 * 1.  struct McssSys -- the module object (0x48+ bytes)
 *
 * The thing func_02014B08 allocates (0x4c bytes, line 0x78) and
 * func_02014BA8 tears down.  Every open function in the family takes it
 * as its first parameter.
 * ================================================================== */
struct McssSys {
    void   *f00;        /* +0x00  func_020163C4 tests it non-zero before
                         *        delegating to func_02016630; the "already
                         *        bound" branch                          */
    void   *f04;        /* +0x04  func_020163C4 compares it with src->f00 */
    void   *f08;        /* +0x08  func_0201624C, func_020163C4: if set,
                         *        func_02030DA8(f08, cb, p, 0), else
                         *        func_020056A0(cb, p, 0).  A task queue   */
    void   *f0c;        /* +0x0c  func_02014B08 stores func_020056A0's
                         *        result; func_02014BA8 frees it through
                         *        func_02030EE8/func_02030EAC             */
    s32     count;      /* +0x10  func_02014BA8's loop bound; the loop
                         *        bound of sub_020159C8 and of
                         *        func_02014C08.  Signed: `i < obj->f10`
                         *        with i an int is what sub_020159C8 needs */
    struct McssWork **slots;
                        /* +0x14  func_02014B08 allocates id*4 here;
                         *        sub_020159C8 fills the first free slot;
                         *        sub_02015BA4 clears slots[obj->f148]    */
    u8      pad18[0x18];/* +0x18  func_02014B08 passes &f18 to
                         *        func_020637D4 and stores (u32)&f18 into
                         *        the sub-record's +0x0c                  */
    u32     f30;        /* +0x30  = 9 << 14 (func_02014B08).  Base of the
                         *        per-slot VRAM window: func_020163C4 and
                         *        func_02016630 compute f30 + (idx << 14) */
    u32     f34;        /* +0x34  = 0x1000 (func_02014B08).  Second base:
                         *        f34 + (idx << 5).  Also the member
                         *        sub_02015F2C / sub_02016374 hand to the
                         *        0x0206xxxx API as `obj + 0x34`          */
    u32   (*f38)(void *src, void *obj, u32 ctx);
                        /* +0x38  optional hook; func_020163C4 and
                         *        func_02016630 call it and clear the pair
                         *        (f38, f3c) when it returns 1.
                         *        sub_02014CF0 is its setter: two word
                         *        stores at +0x38 and +0x3c in source
                         *        order, and func_020172AC tail-calls it
                         *        with sub_02014CF8's address (pool word
                         *        0x020172BD) as the hook value           */
    u32     f3c;        /* +0x3c  the hook's context word (sub_02014CF0)  */
    void   *f40;        /* +0x40  the heap handle func_02014B08 was given;
                         *        sub_020159C8 reads it as the heap id and
                         *        narrows it with (u16) at the call, so it
                         *        is a 32-bit field.  unit_02014CB8.c
                         *        records the same +0x40 reach tell.      */
    u32     f44;        /* +0x44  = 0x1000 (func_02014B08)               */
};

/* ================================================================== *
 * 2.  struct McssWork -- the per-slot record, EXACTLY 0x188 bytes
 *
 * SIZE IS SELF-CHECKING.  src/matched/sub_020159C8.c passes
 * `sizeof(struct Rec)` to the allocator and the original materialises it
 * as `movs r7, #0x62 / lsls r7, r7, #2` = 0x188, then keeps r7 live and
 * addresses every far field as `adds r0, r7, #0 / subs r0, #k`.  A struct
 * one word longer or shorter changes that constant AND every derived
 * offset, so the layout below is constrained end to end, not merely named.
 * ================================================================== */
struct McssWork {
    /* --- the eight resource handles sub_02016BA0 releases, +0x00..+0x2c -- */
    void   *f00;        /* +0x00  the task handle.  func_020163C4 /
                         *        func_02016630 / func_0201624C store
                         *        func_02030DA8's or func_020056A0's
                         *        result here; sub_02015BA4 passes its
                         *        VALUE (not the object) to func_02016C0C;
                         *        sub_02016BA0 recurses into func_02016C0C
                         *        and zeroes it                           */
    void   *f04;        /* +0x04  second handle; sub_02015BA4 ->
                         *        func_02016C38.  func_0201624C and
                         *        func_020169E8 write the new task here
                         *        after releasing the old one             */
    void   *f08;        /* +0x08  third handle; sub_02015BA4 ->
                         *        func_02016C38.  func_0201624C tests it
                         *        non-zero, releases, zeroes              */
    void   *f0c;        /* +0x0c  func_02049FBC/func_02049FFC result;
                         *        sub_02016BA0 releases and zeroes it     */
    void   *f10;        /* +0x10  the ctor's 4th argument is &f10, so the
                         *        helper writes THROUGH it (unit_02049DB4) */
    void   *f14;        /* +0x14  func_0204A0BC/func_0204A0FC result      */
    void   *f18;        /* +0x18  that ctor's out-parameter               */
    void   *f1c;        /* +0x1c  func_0204A03C/func_0204A07C result      */
    void   *f20;        /* +0x20  that ctor's out-parameter               */
    void   *f24;        /* +0x24  func_0204A13C/func_0204A17C result      */
    void   *f28;        /* +0x28  that ctor's out-parameter.  Also the
                         *        word sub_02016028 feeds to func_020627D8 */
    u32    *f2c;        /* +0x2c  func_02048F60 / func_02049250 result,
                         *        a counted table: f2c[0] is the record
                         *        count and f30 below points past it      */
    u32    *f30;        /* +0x30  = f2c + ((0x30 * f2c[0] + 0xC) & ~3),
                         *        the second half of the same block.  0x30
                         *        is the record stride                    */
    u32     f34_member[(0x98 - 0x34) / 4];
                        /* +0x34  a 0x64-byte embedded sub-object handed
                         *        whole to the 0x0206xxxx API: sub_02015F2C
                         *        (func_02063000), sub_02016374
                         *        (func_02064CBC), sub_02016028
                         *        (func_0206469C), func_02016984
                         *        (func_02064754).  Never indexed from
                         *        inside this family, so its own layout is
                         *        NOT evidenced here                      */
    int     f98;        /* +0x98  func_02016984 stores func_02030734's
                         *        result and immediately re-reads it as
                         *        func_02064754's 2nd argument, which is
                         *        what makes it a genuine `int` and not a
                         *        pointer.  sub_02016028 and sub_02016BA0
                         *        release it; sub_02016BA0 zeroes it      */
    u8      pad9c[0xc0 - 0x9c];
                        /* +0x9c  func_02063790 takes &f9c (func_020163C4,
                         *        func_02016630) -- a 0x24-byte nested
                         *        object.  func_02016880's ctx copies the
                         *        pointer, not the contents               */
    u32     fc0;        /* +0xc0  func_020637D4 takes &fc0 (func_02014B08
                         *        does the same on the SYS object's +0x18,
                         *        so the two share a type).  func_0201624C
                         *        copies *(u32*)(a1+0xc0) into the ctx     */
    u8      padc4[0xd4 - 0xc4];
    void   *fd4;        /* +0xd4  func_02030734(h, fdc, 0, file, L),
                         *        the first of a twin pair; MIi_CpuCopy16's
                         *        destination.  sub_02016BA0 zeroes it     */
    void   *fd8;        /* +0xd8  the twin, allocated at L+1              */
    u32     fdc;        /* +0xdc  the byte size shared by fd4 and fd8 and
                         *        passed to MIi_CpuCopy16.  func_0201624C
                         *        reads it back as the copy length        */
    u8      pade0[0x140 - 0xe0];
                        /* +0xe0..+0x134: the fixed-point block.
                         * sub_020159C8 initialises, in this order:
                         *   +0xe0,+0xe4,+0xe8   the three caller values
                         *   +0xec,+0xf0,+0xf4   = 0x1000 (scale, 1.0)
                         *   +0x11c,+0x120,+0x124 = 0
                         *   +0x128,+0x12c,+0x130 = 0x1000
                         *   +0x110,+0x114,+0x118 = 0x1000 (written LATE,
                         *     off the reused constant 0x1F parked in ip)
                         * All s32 fixed-point 1.0; nothing narrows them.  */

    /* --- +0x140: THE FLAG WORD.  One u32 container, partitioned by ---- *
     * sub_020159C8's bitfield writes and read back by four other files.
     * The partition below is sub_020159C8's, and it is the one that
     * constrains: written as plain masks the compiler pools every mask,
     * written as these bitfields it emits the original's bics/orrs
     * against small constants with only the two nine-bit masks reaching
     * the pool.                                                          */
    u32     b0  : 8;    /* bits 0..7    sub_020159C8 sets 0x1F            */
    u32     b1  : 3;    /* bits 8..10                                     */
    u32     b2  : 1;    /* bit  11      sub_020159C8 clears it            */
    u32     b3  : 2;    /* bits 12..13                                    */
    u32     b4  : 9;    /* bits 14..22  sub_020159C8 sets 0x20            */
    u32     b5  : 6;    /* bits 23..28                                    */
    u32     b6  : 1;    /* bit  29      sub_020159C8 sets it last, after
                         *              the +0x150 struct copy            */
    u32     b7  : 2;    /* bits 30..31                                    */
    /*
     * THE SAME WORD SEEN FROM THE OTHER FILES.  Each of these is a
     * different view of the identical container; they agree, and the
     * cross-check is what makes the partition above trustworthy:
     *   bit 13        func_020163C4 / func_02016630 clear it with
     *                 `&= 0xFFFFDFFF` on entry; func_02016880 sets it with
     *                 `|= 0x2000`.  That is b3's low bit.
     *   bits 28..31   func_02016880 and func_020163C4 both extract it as
     *                 `(w << 4) >> 0x1C`; b6 is bit 29, inside it.
     *   bit 28        func_0201624C clears it with `&= 0xEFFFFFFF`.
     *   bits 24..27   sub_02016078 reads and writes it as a 4-bit field
     *                 (its `struct { u32 low24:24; u32 mode:4; u32 hi4:4; }`
     *                 is the SAME word viewed from bit 24 up), clamped to
     *                 15.  That is inside b5/b6.
     *   bit 29        sub_02015C0C sets and sub_02015C1C clears it via
     *                 `|= 0x20000000` / `&= ~0x20000000`, which is b6 --
     *                 an independent confirmation of the 29 boundary.
     *   bits 9..10    func_02014C08 tests `(w << 0x15) >> 0x1e`, a 2-bit
     *                 field inside b1.
     *   bit 12        func_02014C08 tests `(w << 0x13) >> 0x1f`, which is
     *                 b3's high bit.
     * WAS: func_02014C08's note spells the whole word as hand-written
     * shift pairs.  That loses: mwcc folds a 1-bit `(x<<31)>>31` to
     * `movs r0,#1 / ands`, while a `: 1` bitfield keeps the original's
     * lsls/lsrs -- see that note.  The bitfield spelling wins.
     */

    u32     f144;       /* +0x144  a SECOND, separate flag word, not part
                         *         of +0x140: sub_02016380 sets its bit 0
                         *         (read, &~1, |1, write back -- two
                         *         `movs r1,#1` because Thumb has no ORR
                         *         immediate), sub_02016028 clears it, and
                         *         func_02014C08 tests bit 0 as a one-bit
                         *         unsigned bitfield and clears it.       */
    s32     f148;       /* +0x148  the slot index.  sub_020159C8 writes i
                         *         here; sub_02015BA4 uses it to clear
                         *         sys->slots[f148]; func_02016078 and
                         *         sub_02014CF8 pass it as func_020163C4's
                         *         second argument, which is what pins
                         *         that parameter as the index and not a
                         *         pointer.  Note func_0201624C reads
                         *         `*((u32*)(a1+0x148) + 1)` -- i.e. f14c
                         *         -- for the heap, so the two are adjacent
                         *         words of one struct, confirmed twice.  */
    u32     f14c;       /* +0x14c  the heap id.  sub_020159C8 writes
                         *         sys->f40 here; func_02016984,
                         *         func_0201624C and func_020163C4 all
                         *         load it with a plain `ldr` and narrow
                         *         with lsls/lsrs #0x10 at the call, which
                         *         is the tell that the FIELD is u32 (an
                         *         `ldrh` would be four bytes cheaper).
                         *         Declaring it u16 loses four bytes --
                         *         measured in func_02016984's header.    */
    struct McssSrc f150;/* +0x150  the 0x24-byte descriptor, copied in by
                         *         one struct assignment.  sub_020159C8
                         *         and sub_02014CF8 both do it and both
                         *         get the inlined ldm/stm loop of four
                         *         iterations plus a trailing word, which
                         *         is docs/idioms/big-struct-assignment...
                         *         A byte array gives a 36-iteration
                         *         ldrb/strb loop instead, so the source
                         *         type has >= 4-byte alignment: `u32 w[9]`
                         *         is what reproduces it.                 */
    u32     f174;       /* +0x174  = 0x1000 (sub_020159C8).  func_02014C08
                         *         passes it as func_020649D4's 2nd arg   */
    u16     f178;       /* +0x178  = 0xC400, stored with strh off
                         *         `lsls r2, r7, #7` (r7 = sizeof) --
                         *         a halfword, not a word                 */
    u16     f17a;       /* +0x17a  = 0                                    */
    u32     f17c;       /* +0x17c  = 0                                    */
    u32     f180;       /* +0x180  = 0                                    */
    u32     f184;       /* +0x184  = 0xFFFFF000, i.e. -0x1000 fixed point */
};                      /* total 0x188 -- see the size note above         */

/* Two byte fields inside the 0x134 pad, evidenced only by func_020169E8's
 * `ldrsb` pairs (0x02016B26/0x02016B28) at 0x134 and 0x135, plus 0x138 and
 * 0x139.  `ldrsb` with a register offset is the signedness proof; the
 * offsets are built as `movs r0,#0x4d / lsls r0,r0,#2` = 0x134.
 *   +0x134  s8   current value      func_020169E8, strb'd back
 *   +0x135  s8   target value       func_020169E8, compared with +0x134
 *   +0x138  s32  step               func_020169E8: `lsls #0x18 / asrs #0x18`
 *                                   on it, so its LOW BYTE is the signed
 *                                   step added to +0x134
 * The three are a one-byte-per-frame interpolator; the guard at the top of
 * func_020169E8 is `ldrsb` on a further byte reached through a pool word.  */

/* ================================================================== *
 * 3.  struct McssSrc -- the 0x24-byte descriptor (9 words)
 *
 * Evidenced twice over: sub_02014CF8 copies it into McssWork+0x150 and
 * forwards the ORIGINAL pointer to func_020163C4; func_02017270 builds
 * one on its own stack as `u8 buf[0x24]` and hands it to func_020159C8.
 * The 0x24 size is therefore fixed by two independent files.
 * ================================================================== */
struct McssSrc {
    void   *f00;        /* +0x00  the archive/handle every ctor takes as
                         *        its first argument; func_020163C4
                         *        compares it with sys->f04                */
    void   *f04;        /* +0x04  func_02049DB4/func_02049DF4's 2nd arg    */
    void   *f08;        /* +0x08  func_02049F34/func_02049F78's 2nd arg    */
    void   *f0c;        /* +0x0c  func_02049FBC/func_02049FFC's 2nd arg    */
    void   *f10;        /* +0x10  func_0204A03C/func_0204A07C's 2nd arg    */
    void   *f14;        /* +0x14  func_0204A0BC/func_0204A0FC's 2nd arg    */
    void   *f18;        /* +0x18  func_0204A13C/func_0204A17C's 2nd arg    */
    void   *f1c;        /* +0x1c  func_02048F60/func_02049250's 2nd arg    */
    u32     f20;        /* +0x20  the MODE tag.  func_020163C4 branches on
                         *        `f20 == 1` to decide whether the heap id
                         *        is masked to the sub-heap form; it is the
                         *        only field read as a value               */
};

/* ================================================================== *
 * 4.  The per-task context -- 0x2c bytes
 *
 * Allocated by func_02014B08 (line 0x8e), func_0201624C (line 1942),
 * func_020163C4 (line 0x840), func_02016630 (line 0x8AB) and
 * func_020169E8, always with size 0x2c and clear=1, and consumed by the
 * two task bodies func_02016880 and func_0201691C.  The two bodies are
 * where the layout is actually constrained.
 * ================================================================== */
struct McssTask {
    void   *f00;        /* +0x00  func_02016880: func_02063A54's 1st arg   */
    struct McssTaskInner *f04;
                        /* +0x04  the 0x10-byte inner block func_0201624C
                         *        and func_020169E8 allocate; also
                         *        func_02049F34's out-parameter (&p->f04)
                         *        in func_020163C4                         */
    void   *f08;        /* +0x08  = &work->f9c (func_020163C4)             */
    void   *f0c;        /* +0x0c  = &work->fc0 (func_0201624C, 163C4)      */
    void   *f10;        /* +0x10  func_02049DB4's result; func_02016880
                         *        releases it and may return early         */
    void   *f14;        /* +0x14  func_02049F34's result                   */
    u32     f18;        /* +0x18  = sys->f30 + (idx << 14)                 */
    u32     f1c;        /* +0x1c  = sys->f34 + (idx << 5)                  */
    struct McssSys *f20;/* +0x20  the owning module object                 */
    struct McssWork *f24;
                        /* +0x24  the slot record.  func_02016880 reaches
                         *        the +0x140 flag word through it as
                         *        f24[0x140/4]; func_0201691C clears the
                         *        f24->f04 / f24->f08 handles that name
                         *        this task                                */
    u32     f28;        /* +0x28  the "sync to VBlank" flag: when 0, both
                         *        task bodies read the VCOUNT register
                         *        *(volatile u16 *)0x04000006 and return
                         *        unless it is in [0xc0, 0xc8].  Set from
                         *        `sys->f08 != 0` at construction          */
};

struct McssTaskInner {  /* 0x10 bytes, func_0201624C line 1950            */
    u32     f00;        /* = work->fc0                                    */
    u32     f04;        /* = 0                                            */
    u32     f08;        /* = work->fdc, the byte size                     */
    void   *f0c;        /* = func_02030734(heap, work->fdc, 0, file, L+5) */
};

/* ================================================================== *
 * 5.  Prototypes.  EXACT PARAMETER TYPES, from the matched callees.
 * ================================================================== */

/* -- the heap / task runtime (outside the family, all ARM, reached by blx) */
extern void *func_02030734(u32 heap, u32 size, u32 clear,
                           const char *file, u32 line);   /* 0x02030734 arm */
extern void  func_020307B0(void *p);                      /* 0x020307B0 arm */
extern void  func_02030EAC(void *id);                     /* 0x02030EAC arm */
extern void *func_02030EE8(void *id);                     /* 0x02030EE8 arm */
extern void *func_02030DA8(void *queue, void *cb, void *ctx, int prio);
extern void *func_020056A0(void *cb, void *ctx, int prio);
extern void  MIi_CpuCopy16(const void *src, void *dst, u32 size);

/*
 * -- THE FOUR CTOR HELPERS, 0x02049FBC..0x0204A17C (arc_util.c, ARM).
 *
 * THIS IS THE DECLARATION docs/notes/func_020163C4.c.txt and
 * docs/notes/func_02016630.c.txt were waiting on, and it is now settled by
 * the matched sources, not inferred:
 *
 *   src/matched/unit_02049DB4.c   0x02049FBC, 0x02049FFC
 *   src/matched/func_0204A03C.c   0x0204A03C
 *   src/matched/unit_0204A07C.c   0x0204A07C, 0x0204A0BC
 *   src/matched/unit_0204A0FC.c   0x0204A0FC, 0x0204A13C, 0x0204A17C
 *
 * All eight share ONE shape, and the ARM disassembly at 0x02049FBC confirms
 * it directly: `push {r3,r4,r5,lr}` then `ldrh r3, [sp, #0x10]` -- the fifth
 * argument is fetched from the stack with LDRH, which is the byte-level
 * proof that the fifth parameter is 16-bit.
 *
 *   void *f(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
 *
 * CAUTION, AND THIS IS THE POINT THE TWO NOTES NOW RECORD: declaring the
 * fifth parameter u16 AT THE CALL SITE is correct for the callee but is NOT
 * the lever the notes predicted.  In func_020163C4 it makes the compiler
 * narrow at all four call sites (four surplus lsls/lsrs pairs, 636 bytes vs
 * the original's 620) because the caller's value is ALREADY narrowed; in
 * func_02016630 it changes nothing (592 bytes, 36 mismatches either way).
 * Both notes retract the prediction in their 2026-09-21 appendices.  The
 * declaration is right; it is not what those two functions are stuck on.
 */
extern void *func_02049FBC(u32 a0, u32 a1, u32 a2, u32 a3, u16 heap);
extern void *func_02049FFC(u32 a0, u32 a1, u32 a2, u32 a3, u16 heap);
extern void *func_0204A03C(u32 a0, u32 a1, u32 a2, u32 a3, u16 heap);
extern void *func_0204A07C(u32 a0, u32 a1, u32 a2, u32 a3, u16 heap);
extern void *func_0204A0BC(u32 a0, u32 a1, u32 a2, u32 a3, u16 heap);
extern void *func_0204A0FC(u32 a0, u32 a1, u32 a2, u32 a3, u16 heap);
extern void *func_0204A13C(u32 a0, u32 a1, u32 a2, u32 a3, u16 heap);
extern void *func_0204A17C(u32 a0, u32 a1, u32 a2, u32 a3, u16 heap);

/* The 4-argument forms pass 0 for the third argument internally.        */
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, void *out, u32 heap);
extern void *func_02049DF4(u32 a0, u32 a1, u32 a2, void *out, u32 heap);
extern void *func_02049F34(u32 a0, u32 a1, void *out, u32 heap);
extern void *func_02049F78(u32 a0, u32 a1, void *out, u32 heap);
extern u32  *func_02048F60(u32 arc, u32 id, u32 heap);
extern u32  *func_02049250(u32 arc, u32 id, u32 heap);

/* -- the 0x0206xxxx renderer API the +0x34 member is handed to -------- */
extern void  func_02063000(void *member, u32 one, u32 a, u32 b);  /* 15F2C */
extern void  func_02063790(void *p);                              /* +0x9c */
extern void  func_020637D4(void *p);                              /* +0xc0 */
extern void  func_02063A54(void *a, u32 b, int c, u32 d);
extern void  func_02063E54(void *a, u32 b, int c, void *d);
extern void  func_0206469C(void *member, u32 value);
extern void  func_02064754(int member, int a1, int a2, int a3, int a4, int a5);
extern int   func_020648B4(int v);
extern void  func_02064CBC(void *member);
extern void  func_020649D4(void *member, u32 value);
extern u32   func_020627D8(u32 a, u32 flag);

/* -- inside the family ------------------------------------------------ */
extern void *func_02014B08(u32 count, void *heap);      /* ctor           */
extern void  func_02014BA8(struct McssSys *sys);        /* dtor           */
extern void  func_02014C08(struct McssSys *sys);        /* per-frame walk */
extern void  sub_02014CB8(void *o, u32 x);
extern void  sub_02014CD4(void *o);
extern void  sub_02014CF0(struct McssSys *sys, u32 hook, u32 ctx);
extern void  sub_02014CF8(void *sys, struct McssWork *w,
                          const struct McssSrc *src);
extern struct McssWork *func_020159C8(struct McssSys *sys, u32 a1, u32 a2,
                                      u32 a3, const struct McssSrc *src);
extern void  sub_02015BA4(struct McssSys *sys, struct McssWork *w);
extern void  sub_02015BF0(struct McssWork *w);
extern void  sub_02015C00(struct McssWork *w);
extern void  sub_02015C0C(struct McssWork *w);
extern void  sub_02015C1C(struct McssWork *w);
extern void  sub_02015F2C(struct McssWork *w, u32 a, u32 b);
extern void  sub_02016028(struct McssWork *w, u32 flag);
extern void  sub_02016078(struct McssSys *sys, struct McssWork *w, int mode);
extern void  func_0201624C(struct McssSys *sys, struct McssWork *w);
extern void  func_02016374(struct McssWork *w);
/* PROVED 2026-09-22 (src/matched/func_02014C08.c, EXACT).  The single
 * argument is not a guess any more: declared `void func_02016374(void)`,
 * func_02014C08 is 7 concrete bytes out and NOTHING reaches it -- 171
 * single permuter mutations and 2000 anneal compiles move it by zero.
 * Declared with the slot pointer and CALLED with it, every byte closes,
 * because the image deliberately leaves the slot live in r0 across the
 * bit test that precedes the call (0x02014C80).  Caller-side evidence
 * for a callee's arity, of the shape
 * docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-
 * leftovers.md describes from the other direction.                     */
extern void  sub_02016380(struct McssWork *w);
extern void  func_020163C4(struct McssSys *sys, u32 idx,
                           struct McssSrc *src);
extern void  func_02016630(struct McssSys *sys, u32 idx,
                           struct McssSrc *src);
extern void  func_02016880(void *task, struct McssTask *ctx);
extern void  func_0201691C(void *task, struct McssTask *ctx);
extern void  func_02016984(struct McssWork *w, int a1);
extern void  sub_020169D4(void);
/* PROVED 2026-09-22 (src/matched/func_020160D4.c, EXACT).  The THIRD
 * parameter is 16-bit AT THE PARAMETER, not merely truncated at the
 * call.  `int a2` leaves 12 concrete bytes wrong in the prologue spill
 * order and no body spelling reaches them; `u16 a2` closes the function
 * in one change (found by tools/permuter.py --types as
 * `type:p(a2:int->u16)`).  A 16-bit parameter arrives already narrowed,
 * so mwcc spills it BEFORE it touches the literal pool.  Note the
 * asymmetry: the FOURTH parameter must stay `int` -- declaring it u16
 * frees its frame slot entirely and costs 168 bytes.                   */
extern void  func_020160D4(struct McssWork *w, struct McssWork *w2,
                           u16 a2, int a3);
extern void  func_020169E8(struct McssSys *sys, struct McssWork *w);
extern void  sub_02016BA0(struct McssWork *w);
extern void  sub_02016C0C(void *id);
extern void  func_02016C38(void *id);
extern void  func_02016C60(struct McssWork *w, struct McssTask *task);
/* TRANSCRIBED 2026-09-22, docs/notes/pkt_02016C60.c.txt (size-exact at
 * 870, 109 out).  A 4-bit-per-pixel block stamper over the cell bitmap.
 * Three NEW McssWork fields it is the sole evidence for:
 *   +0xa8  s32  the log2 of the row stride minus 2; the function
 *              computes `scale = (s32)pow(2.0, (double)(fa8 + 2))` with
 *              the soft-float triple _s32_to_double / the 0x0209AB80
 *              veneer / _d2s, and uses `scale` as the bytes-per-row of
 *              a 2-pixels-per-byte bitmap.
 *   +0xb0  s32  a mode word; the whole function is guarded on == 3.
 * Both lie inside the pad9c[0x9c..0xc0] hole this header declares, which
 * is therefore NOT opaque: 0xa8 and 0xb0 are real members.
 *
 * The McssWork.f2c table is walked here as records of STRIDE 0x30 with
 * live fields at +0x14 (w), +0x18 (h), +0x1c (sx), +0x20 (sy) and, for
 * the second pass, +0x2c (w2), +0x30 (h2, doubled), +0x34 (sx2),
 * +0x38 (sy2) -- all 12-bit fixed point, all >>12 on use.  The count at
 * f2c[0] is read UNSIGNED (`bhi` / `bhs`).
 *
 * McssTask.f00 is dereferenced and indexed: `base = ((u8 **)t->f00)[5]`.
 * So f00 points at a structure whose +0x14 is the pixel buffer.        */

/* ================================================================== *
 * 6.  Inline helpers -- the two recurring idioms, spelled once.
 * ================================================================== */

/*
 * THE SUB-HEAP MASK.  Appears at least eleven times across the family and
 * is ALWAYS spelled out at the call, never hoisted into a helper by the
 * compiler, so write it inline:
 *
 *     (u16)(((u16)heap_word & 0x7FFF) | 0x8000)
 *
 * The ORDER matters: `(u16)x` first, then the mask, then the or, then a
 * final narrowing.  func_0201624C and func_02016984 both show the
 * `lsls #0x10 / lsrs #0x10 / ands / adds #1 / orrs / lsls / lsrs` sequence
 * that this exact nesting produces.  `0x8000` is written by the original as
 * `adds r0, r0, #1` off the 0x7FFF already in a register -- do NOT try to
 * spell it as a second constant; write the mask as `0x7FFF` and let the
 * compiler find the +1, which it does.
 *
 * In func_020163C4 and func_02016630 the mask is guarded by src->f20 == 1
 * and joined with a CROSS-JUMP, not a shared store.  The only spelling that
 * reproduces it (620 bytes, measured) is a u32 temporary with its own cast
 * in the then-arm and ONE cast on the join:
 *
 *     u32 t;
 *     if (src->f20 == 1) t = (u16)(((u16)w->f14c & 0x7FFF) | 0x8000);
 *     else               t = w->f14c;
 *     h = (u16)t;
 *
 * and `h` must be declared BEFORE the `flag` local so it lands at sp+0xc.
 */

/*
 * THE VBLANK GUARD.  Opens both task bodies (func_02016880, func_0201691C)
 * verbatim.  The register is VCOUNT; it is a cast constant and raises no
 * relocation (docs/idioms/volatile-reread-needs-two-locals.md):
 *
 *     if (ctx->f28 == 0) {
 *         u32 v = *(volatile u16 *)0x04000006;
 *         if (v < 0xc0 || v > 0xc8) return;
 *     }
 *
 * The single named local is required: reading the register twice in one
 * expression interleaves the two loads.
 */

/*
 * THE FLAG-WORD EXTRACTION.  `(w->f140 << 4) >> 0x1C` (bits 28..31) is a
 * 4-bit field and folds identically whether written as a shift pair or a
 * bitfield.  A ONE-BIT test does NOT: mwcc folds `(x << 0x1f) >> 0x1f` to
 * `movs r0,#1 / ands r0,r1` but keeps the original's `lsls/lsrs #0x1f` for
 * a `: 1` bitfield member.  func_02014C08 is 12 bytes wrong on exactly this
 * and nothing else -- always spell a single-bit test as a bitfield.
 */

/* ================================================================== *
 * 7.  Constants.
 * ================================================================== */
#define MCSS_FX_ONE        0x1000      /* fixed point 1.0, 12 fractional
                                        * bits.  func_02014B08 (+0x44),
                                        * sub_020159C8 (nine fields),
                                        * unit_02016FC8's >> 12           */
#define MCSS_FX_MINUS_ONE  0xFFFFF000  /* -1.0; sub_020159C8 +0x184       */
#define MCSS_VRAM_BASE     (9 << 14)   /* sys->f30, func_02014B08         */
#define MCSS_WORK_SIZE     0x188       /* sizeof(struct McssWork)         */
#define MCSS_TASK_SIZE     0x2c        /* sizeof(struct McssTask)         */
#define MCSS_SRC_SIZE      0x24        /* sizeof(struct McssSrc)          */
#define MCSS_INNER_SIZE    0x10        /* sizeof(struct McssTaskInner)    */
#define MCSS_SUBHEAP(h)    ((u16)(((u16)(h) & 0x7FFF) | 0x8000))
#define MCSS_VCOUNT        (*(volatile u16 *)0x04000006)


/* ================================================================== *
 * 8.  Wave 11 (2026-09-23), third lane: what func_020155A0 PROVED.
 *     src/matched/func_020155A0.c is EXACT (1064/1064 with pools).
 * ================================================================== */

/* THE QUAD DRAWER.  Called three times by the 0x02014D2C frame walker
 * (0x020154D0, 0x02015506, 0x02015562) with a cell record's six words as
 * x, y, width, height, s, t.  Four register and eleven stack parameters;
 * the last is a u8 read with `ldrb` from sp+0x90.                      */
extern void  func_020155A0(struct McssSys *sys, struct McssWork *w,
                           s32 x, s32 y, s32 width, s32 height,
                           s32 s, s32 t, void *pose, u16 *frame,
                           void *tex, int polyId, int proj, u32 *z,
                           u8 flip);
/*
 * New field facts (each from a load in func_020155A0):
 *   McssSys +0x2c bit 1   far plane (512 vs 1024 << 12) and depth step
 *                         (0x100 vs 0x400); tested as `(w << 30) >> 31`,
 *                         so a 1-bit bitfield at bit 1 of the +0x2c word
 *                         (the pad18 block above is NOT all opaque).
 *   McssSys +0x48  s32    depth step override when non-zero.  The struct
 *                         is allocated 0x4c bytes, so this is its last word.
 *   McssWork +0x78        pointer to an animation record whose +0x04 is an
 *                         array of 8-byte frames; a frame's +0x04 is an
 *                         array of 8-byte cells; a cell's +0x02/+0x04 are
 *                         s16 pixel offsets (`ldrsh`), << 8 into fx32.
 *   McssWork +0xc0  s32   texture format; compared with 2 (PLTT4) for
 *                         G3_TexPlttBase.  +0xc8 is the palette base.
 *   McssWork +0x140       bits 14..22 (b4, 9 bits) are the ALPHA with 0x20
 *                         as a sentinel meaning `b0 >> 1`; bit 23 hides the
 *                         second (polygon id 1) quad; bits 30 and 31 are
 *                         two separate 1-bit flags (b7 above is two
 *                         fields): bit 31 forces polygon id 0, bit 30
 *                         flips the depth step's sign.
 *
 * Declarations that turned out to be byte-visible (all measured):
 *   - FX_SinCosTable_ (0x020A1B38) declared WITHOUT const.  With const, mwcc
 *     keeps sin/cos across the G3_RotZ call in two extra frame slots.
 *   - G3_Translate / G3_Scale as the SDK inline functions: the original
 *     evaluates all three arguments before the first register store.
 *   - `u32 *z`: a signed pointee flips the register choice in the two
 *     +-0x100 tails (22 bytes; nothing in the body reaches it).
 *   - Frame slot order follows value CREATION order more than declaration
 *     order: the G3_TexPlttBase 0/1 is a compiler temporary homed at the
 *     lowest slot, and routing alpha through a block-local moved its slot.
 *
 * Two open rows' measured facts, same date (details in their notes):
 *   func_020163C4 / func_02016630: `flag = 1` belongs AFTER the second
 *     constructor call (26 -> 16 and 36 -> 21).
 *   func_020172D8: the list guard is an `if`, the nibble tests are signed,
 *     the target byte is read once into a local, and both nibble offsets
 *     recompute from a1 on their second assignment (183 -> 82).
 */

#endif /* MCSS_H */
