/*
 * docs/families/ica_anime.h -- shared declarations for the ica_anime.c
 * family.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and `match.py` never sees it.  It is the adjudicated
 * union of the declarations that the family's byte-exact sources already
 * carry, written down once so a new attempt on an open function starts from
 * the settled shape instead of re-deriving it.
 *
 * Family: original source file ica_anime.c, 0x02011428..0x020122B4 in the
 * ARM9 image.  Derived from the 41 matched sources found with
 *   grep -l "address:  0x02011[4-9A-F]\|address:  0x02012[0-2]" src/matched/*.c
 * restricted to that range.  Each field carries the matched function that
 * evidences it.  Where two matched files disagreed, the file whose code
 * actually constrains the field wins, and the losing spelling is recorded
 * beside it as `WAS:` so the adjudication is auditable.
 *
 * ADJUDICATION RULE USED THROUGHOUT (copied from docs/families/clact.h).  A
 * load instruction constrains a field and a name does not.  `ldrsh`/asr
 * proves a signed width; a plain scalar accessor that only moves a word
 * (never dereferences it) does not outrank a file that dereferences the
 * same offset as a pointer.  A shift pair with no matching integer width
 * (`lsls #0x1f` / `lsrs #0x1f`, 32-31) proves a 1-bit field, not a cast.
 *
 * NOTE ON THE OBJECT IDENTITY.  Two families of matched files describe the
 * SAME object under two different names: `struct IcaAnime` (used by the
 * constructors, teardown, clock and table-lookup helpers) and `struct Ctx`
 * (used by unit_020120F0.c / unit_02011F24.c / unit_02012204.c, the flat
 * accessor run at 0x020120F0..0x02012158).  func_02011F24 fixes the size at
 * 0x34 (`movs r0, #0x34; bx lr`, its own sizeof getter) and every offset the
 * two spellings share agrees once accessor pass-throughs are weighed against
 * dereferences.  They are merged below as one struct.
 *
 * UNSETTLED / NOTED EXPLICITLY:
 *   - +0x00: only func_020116E0 touches it (`*(u16*)p = a3`); no other file
 *     in the 41 reads it back, so the u16 spelling is unopposed but also
 *     uncorroborated.
 *   - +0x1a..+0x1b (Ctx unk10[8] straddles +0x10..+0x17 without an
 *     accessor): no matched file resolves what, if anything, lives in
 *     +0x10..+0x17 beyond `f10`/`f14`/`f18` themselves; Ctx's own
 *     unk00[0xC]/unk0C/unk10[8]/unk18 spelling only fixes the total offset
 *     to +0x18, not the internal shape of unk10[8] (nothing in the 41 files
 *     dereferences inside that span as anything other than f10/f14/f18).
 *   - +0x28/+0x2c/+0x30 (guard words): func_02012124/func_0201212C's u8
 *     accessor on +0x30 and func_0201213C/func_02012144's u8 accessor on
 *     +0x32 pass a single byte through and constrain nothing; they are
 *     listed as WAS: below because the guard/table triple's own definition
 *     sites (sub_02011770, func_020117D8, unit_02011610) store and test the
 *     full u32 at +0x28/+0x2c/+0x30.
 *   - the "handle" read back at +0x24 by func_02012138 (passed to
 *     func_0203CD98/func_02026454 as an opaque handle) is the SAME offset
 *     unit_02011610's third table copy dereferences as `struct Rec12 *`.
 *     Neither file's use contradicts the type (a handle can be a pointer
 *     value); the pointer spelling is used below because it is the only one
 *     of the two that dereferences.
 */

#ifndef ICA_ANIME_H
#define ICA_ANIME_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Rec12;

/* ------------------------------------------------------------------ */
/* The cell-animation object.  0x38 bytes: func_0201147C/func_02011428/  */
/* func_020114D0/func_02011510 all allocate it with                      */
/* func_02030734(heap, 0x38, 0, file, line), and func_02011F24 fixes the */
/* accessor-record view at exactly 0x34 (`sizeof(struct Ctx)`), which is */
/* the same object seen through a narrower window (0x00..0x34 of 0x38).  */
/*                                                                       */
/* THE TABLE/GUARD TRIPLE AT +0x1c/+0x20/+0x24 (pointers) and            */
/* +0x28/+0x2c/+0x30 (u32 guards).  sub_02011770 WINS: it allocates the   */
/* three table pointers conditionally on the three guard words and       */
/* stores through all three, which constrains both the pointer-ness of   */
/* +0x1c/+0x20/+0x24 and the u32-ness of the guards.  unit_02011610       */
/* agrees: it dereferences each table pointer as `struct Rec12 *` and     */
/* tests each guard against 0.  func_020117D8 agrees again for +0x1c/    */
/* +0x20/+0x24 and +0x28/+0x2c/+0x30 from the loader side.                */
/*   WAS: func_02012124/func_0201212C spell +0x30 a plain `u8` (getter/  */
/*        setter pair, unit_020120F0.c).  They never read or write the   */
/*        other three bytes of the word, so they constrain nothing beyond*/
/*        their own byte; the u32 spelling from the definition sites     */
/*        wins.                                                          */
/*   WAS: func_0201213C/func_02012144 spell +0x32 a plain `u8`.  +0x32 is */
/*        NOT part of the guard triple (that is +0x28/+0x2c/+0x30); it is */
/*        its own byte field and the u8 spelling stands unopposed.       */
/*                                                                       */
/* THE BIT FIELD AT +0x33.  unit_02012204 WINS with a 1-bit field: its    */
/* `lsls r0, #0x1f` / `lsrs r0, #0x1f` pair (func_02012204) and the       */
/* `movs r1,#1; bics` clearer (func_02012210) have no matching integer    */
/* width (32-31 is not a size) and can only come from a declared          */
/* bitfield.                                                             */
/*   WAS: func_02012220 spells the same byte `u8 f33` and updates bit 0   */
/*        with `(f & ~1) | 1`.  That is compatible (same bit, same byte)  */
/*        but weaker: a byte load/store cannot by itself prove the field  */
/*        is only one bit wide.                                          */
/*                                                                       */
/* THE HANDLE/TABLE-3 POINTER AT +0x24.  See the banner note above:       */
/* unit_020120F0's func_02012138 treats it as an opaque u32 "handle";      */
/* unit_02011610's third copy dereferences it as `struct Rec12 *`.  The   */
/* pointer spelling is used because it is the only one of the two that    */
/* dereferences; the handle use is noted as compatible, not overridden.   */
/* ------------------------------------------------------------------ */
struct IcaAnime {
    u16   f00;              /* +0x00  func_020116E0 (*(u16*)p = a3);
                             *        unopposed, no other file reads it  */
    u8    pad02[2];
    void *f04;              /* +0x04  func_020116E0 stores a2; unit_02011558
                             *        reads it as a handle into
                             *        func_02049238                      */
    u32   f08;               /* +0x08  func_0201147C, func_02011428,
                             *        func_020120A4 (via +0x31 sibling),
                             *        func_02012088 (func_0203133C(p->f08))*/
    u32   f0c;              /* +0x0C  func_020114D0 (re-read as init arg);
                             *        func_02011590 tests it unsigned
                             *        (bhi/bhs) against a signed frame,
                             *        which is what fixes it u32 not s32  */
    s32   f10;              /* +0x10  func_02011590/func_020115C0/
                             *        func_020115EC/func_0201160C: the
                             *        clock, `f10 >> 12` is an asrs (asr),
                             *        which proves signed                */
    s32   f14;              /* +0x14  func_02011590 (frame-window lower
                             *        bound), unit_02011610 (table index
                             *        base)                              */
    s32   f18;              /* +0x18  func_02011590 (frame-window width) */
    void *f1c;              /* +0x1C  sub_02011770 allocates it;
                             *        unit_02011610 dereferences it as
                             *        struct Rec12*; func_02011F90 reads
                             *        it as o[7] for teardown             */
    void *f20;              /* +0x20  sub_02011770; unit_02011610 as
                             *        struct Rec12*                      */
    void *f24;              /* +0x24  sub_02011770; unit_02011610 as
                             *        struct Rec12*; func_02012138 reads
                             *        it as an opaque handle (compatible,
                             *        does not dereference)              */
    u8    pad25[4];
    u32   f28;              /* +0x28  guard for f1c; sub_02011770,
                             *        func_020117D8, unit_02011610        */
    u32   f2c;              /* +0x2C  guard for f20; same trio; also
                             *        func_02011F90's o[0xb] (teardown)   */
    u32   f30;              /* +0x30  guard for f24; same trio
                             *        WAS: func_02012124/func_0201212C
                             *        spell it `u8` (pass-through only)   */
    u8    f31;              /* +0x31  func_020120A4/func_020120D8         */
    u8    f32;              /* +0x32  func_0201213C/func_02012144         */
    u8    f33_0 : 1;         /* +0x33  bit 0, unit_02012204 (shift pair)
                             *        WAS: func_02012220 spells it plain
                             *        `u8 f33` updated with (f & ~1) | 1  */
    u8    f33_1 : 7;
    u32   f34;               /* +0x34  sub_02011770 sets it to 1 after the
                             *        table allocations; unit_02011558
                             *        tests it != 0 to decide whether the
                             *        three tables were ever allocated    */
    /* +0x38 total -- func_0201147C/func_02011428/func_020114D0/
     *                func_02011510 all allocate func_02030734(heap,
     *                0x38, 0, file, line); func_02011F24 independently
     *                fixes the accessor-record view (0x00..0x34) to
     *                0x34 bytes via sizeof().                           */
};

/* Three-word animation-frame record copied out of the f1c/f20/f24 tables. */
struct Rec12 {
    s32 a;
    s32 b;
    s32 c;
};

/* ------------------------------------------------------------------ */
/* Constructors.  All four allocate 0x38 bytes off `heap`, zero it via   */
/* func_020116C0, run func_020116E0(p, a1, a2, heap), then diverge in    */
/* their class-specific initialiser and debug-tag line number.          */
/* ------------------------------------------------------------------ */
extern void *func_0201147C(u32 heap, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern void *func_02011510(u32 heap, u32 a1, u32 a2, u32 a3);
extern void *func_020114D0(u32 heap, u32 a1, u32 a2);
extern void *func_02011428(u32 heap, u32 a1, u32 a2, u32 a3, u32 a4);

/*
 * func_020116C0's own definition zero-fills 14 words (0x00..0x37) through
 * four scalar parameters that are never actually distinct callers' values
 * -- every call site in the family passes only `p` and leaves the other
 * three int parameters as whatever garbage is in r1..r3, which the callee
 * ignores.  func_020114D0 calls it with zero arguments of its own, which
 * is compatible: the parameters are dead.
 */
extern void func_020116C0(struct IcaAnime *p);

/*
 * func_020116E0's own definition takes (u8 *p, u32 a1, u32 a2, u32 a3);
 * every call site in the family passes `struct IcaAnime *` for p, so the
 * struct-typed prototype is used here without contradiction.
 */
extern void func_020116E0(struct IcaAnime *p, u32 a1, u32 a2, u32 heap);

/* Class initialisers: func_02011770 fills the table/guard triple from a
 * caller-supplied count; func_020117D8 lays out caller-supplied rows into
 * the same triple and returns 0 on insufficient budget. */
extern u32  func_02011770(struct IcaAnime *p, u32 n);
extern int  func_020117D8(u8 *p, int rows, u8 *buf, int budget);

/* Frame loader (src/matched/func_0201183C.c, wave 10): reads frame
 * (q >> 12) % f0c of the three channels from the archive into a scratch
 * buffer and converts it into f24/f20/f1c; stores q >> 12 to f14.
 *   WAS: "shared teardown initialiser, called with v=0" -- a guess. */
extern void func_0201183C(struct IcaAnime *p, s32 q);

/* Destructor: releases the f04 handle, the three f1c/f20/f24 buffers when
 * f34 says they were allocated, then the object itself. */
extern void func_02011558(struct IcaAnime *p);

/* ------------------------------------------------------------------ */
/* Clock / frame-window helpers (unit_02011590.c).                      */
/* ------------------------------------------------------------------ */
extern u32  func_02011590(struct IcaAnime *p, s32 v);   /* advance + wrap */
extern u32  func_020115C0(struct IcaAnime *p, s32 v);   /* advance, "finished" guard */
extern void func_020115EC(struct IcaAnime *p, s32 v);   /* set clock outright */
extern u32  func_02011608(struct IcaAnime *p);          /* getter: f0c */
extern s32  func_0201160C(struct IcaAnime *p);          /* getter: f10 */

/* Table-lookup accessors (unit_02011610.c). */
extern u32  func_02011610(struct IcaAnime *p, struct Rec12 *dst);
extern u32  func_02011638(struct IcaAnime *p, struct Rec12 *dst);
extern u32  func_02011660(struct IcaAnime *p, struct Rec12 *dst);

/* "Is animation finished" (unit_02011410.c). */
extern u32  func_02011410(void);

/* Flat accessor record run, 0x020120F0..0x02012158 (unit_020120F0.c,
 * unit_02011F24.c, unit_02012204.c). */
extern u32   func_02011F24(void);                       /* sizeof(IcaAnime accessor view) == 0x34 */
extern u32   func_020120F0(const struct IcaAnime *p);    /* getter: f0c */
extern void *func_020120F4(const struct IcaAnime *p);    /* getter: f1c */
extern u8   *func_020120F8(const struct IcaAnime *p);    /* func_020127A4(p->f1c) */
extern u32   func_02012104(const struct IcaAnime *p);    /* getter: f18 */
extern void  func_02012108(struct IcaAnime *p, u32 v);   /* setter: f18 */
extern u32   func_0201210C(const struct IcaAnime *p);    /* getter: f20 (pass-through) */
extern void  func_02012110(struct IcaAnime *p, u32 v);   /* setter: f20 */
extern u32   func_02012114(const struct IcaAnime *p);    /* f20 != 0 */
extern void  func_02012124(struct IcaAnime *p, u8 v);    /* setter: low byte of f30 */
extern u8    func_0201212C(const struct IcaAnime *p);    /* getter: low byte of f30 */
extern u32   func_02012134(const struct IcaAnime *p);    /* getter: f2c */
extern u32   func_02012138(const struct IcaAnime *p);    /* getter: f24 (handle/pointer) */
extern void  func_0201213C(struct IcaAnime *p, u8 v);    /* setter: f32 */
extern u8    func_02012144(const struct IcaAnime *p);    /* getter: f32 */
extern u32   func_0201214C(const struct IcaAnime *p);    /* func_02012BB0(p->f1c) */
extern void  func_02012158(const struct IcaAnime *p, u32 v); /* func_02012BC8(p->f1c, v) */
extern u32   func_02012204(const struct IcaAnime *p);    /* getter: bit f33_0 */
extern void  func_02012210(struct IcaAnime *p);          /* clear bit f33_0 */

/* Teardown chain (func_02011FB8.c / func_02011F90.c / func_02012088.c). */
extern void func_02011FB8(struct IcaAnime *p);
extern void func_02011F90(u32 *o);                       /* o[0xb]=f2c, o[7]=f1c, o[9]=f24 */
extern void func_02012088(struct IcaAnime *p);
extern void func_020122B4(void);
extern void func_020122A4(u32 arg);
/* func_02012258 is declared twice across the 41 files: func_02011F90.c
 * spells it `void func_02012258(void *o)` (called as a teardown step with
 * the object pointer); func_02012258.c's own definition takes no
 * arguments and calls func_02035138(0, 0).  Neither dereferences the
 * pointer, so the caller's typed spelling constrains nothing; the
 * definition's own (void) signature wins.
 *   WAS: func_02011F90 spells it `void func_02012258(void *o)`.        */
extern void func_02012258(void);

/* Playback / bit-0 control (func_02012220.c / func_02012248.c). */
extern void func_02012220(struct IcaAnime *p);
extern void func_02012248(struct IcaAnime *p);

/* Byte-0x31 accessors (func_020120A4.c / func_020120D8.c). */
extern int  func_020123C4(void *p);
extern void func_020120A4(struct IcaAnime *p);
extern int  func_020120D8(struct IcaAnime *p);

/* State-machine driver (func_02011FCC.c / func_0201205C.c / func_020121CC.c). */
extern int  func_02011FCC(struct IcaAnime *p);
extern void func_0201205C(struct IcaAnime *p);
extern u32  func_020121CC(struct IcaAnime *p);

/* HSV tint helper (func_02011B8C.c). PARKED AT MATCH, not EXACT, in its
 * own file -- included here because it is inside the family's address
 * range and its struct usage does not touch struct IcaAnime at all (it
 * operates on an opaque `ctx` handle through func_02011610/func_02011638,
 * the SAME-NAMED but unrelated basis-accessor pair at a different address
 * range; do not confuse with struct IcaAnime's own func_02011610). */
struct Vec3 { s32 x; s32 y; s32 z; };
extern void func_02011B8C(void *dst, void *ctx);

/* Misc small leaves reached only from inside the family's own callers. */
extern void func_02011D40(void);   /* debug-tag alloc + g_02146248.unk04++ */
extern void func_02011D7C(void);   /* same, sibling debug marker */
extern void func_02011D28(u32 (*fn)(void));
extern void func_02011D34(void);
extern void func_02011D60(void);
extern void func_02011CF0(void *a0, void *a1);   /* func_02011610(a1,buf) + func_02048AFC(a0,buf) */
extern void func_02011D0C(void *a0, void *a1);   /* func_02011610(a1,buf) + func_02048B44(a0,buf) */
extern u32  func_02011EAC(u32 a0, u32 a1, u32 a2, u32 a3);  /* wrapper: func_02011FCC(a3) != 0 */
extern u32  func_02011EC0(u32 a0, u32 a1, u32 a2, u32 a3);
extern u32  func_02011EEC(u32 a0, u16 a1, struct Rec12 *a2, u16 a3);  /* writes g_02146248, NOT IcaAnime */
extern int  func_02012264(int a0, int a1, int a2, int a3);

/* sub_020122C0's own object: unrelated 5-word descriptor, NOT IcaAnime.
 * Listed for completeness since it is inside the family's address range. */
struct Desc {
    void *unk_00;
    void *unk_04;
    u32   unk_08;
    void *unk_0c;
    void *unk_10;
};
extern struct Desc *sub_020122C0(void *owner, void *a, void *b, u32 size);

/* ------------------------------------------------------------------ */
/* Globals. */
/* ------------------------------------------------------------------ */
extern u8 sIcaAnimeFile;                /* 0x020A7270  data; __FILE__-style
                                         * debug tag string every ica_anime.c
                                         * allocation site passes to
                                         * func_02030734                 */

/* func_02011EEC's own object -- 0x02146248, NOT struct IcaAnime.  Kept
 * out of this header's main struct on purpose; listed only so a reader
 * chasing g_02146248 through func_02011D40/func_02011D7C does not
 * conflate it with the family's own object. */
struct G02146248 { u32 unk00; u32 unk04; };
extern struct G02146248 g_02146248;

/* ------------------------------------------------------------------ */
/* Recurring constants. */
/* ------------------------------------------------------------------ */
#define ICA_ANIME_SIZE      0x38     /* func_0201147C/func_02011428/
                                     * func_020114D0/func_02011510        */
#define ICA_ANIME_CTX_SIZE  0x34     /* func_02011F24 sizeof() view       */
#define ICA_ANIME_CLOCK_SHIFT 12     /* f10 >> 12 == current frame        */


/* ------------------------------------------------------------------ */
/* WAVE 10 (2026-09-22) additions, each proved by an EXACT file.       */
/* ------------------------------------------------------------------ */

/*
 * SOFT-FLOAT NAMES.  layout/runtime_arm9.txt calls 0x0209C95C "__fsub" and
 * 0x0209CB8C "__fadd"; the calls mwcc 1.1p1 emits say the reverse.  Declared
 * `_fadd 0x0209C95C` / `_fsub 0x0209CB8C`, the TwlSDK FX_F32_TO_FX32 macro
 *   ((x) > 0 ? (x) * 4096.0f + .5f : (x) * 4096.0f - .5f)
 * reproduces func_0201183C's nine conversion sites exactly.  Consequence for
 * a reader: src/matched/func_02011B8C.c spells its wrap loops `h - 360.0f`
 * against `_fsub 0x0209C95C`; the bytes are an ADD, `h += 360.0f`, which is
 * also the only reading under which `while (h < 0.0f)` terminates.  The
 * compare helper is `_fgr` (0x0209BBB0, x > y), the conversion `_ffix`
 * (0x0209C494), the modulo `_u32_div_f` (0x0209C2B0, remainder in r1).
 */

/* The archive read used by func_0201183C: five arguments, the fifth (on the
 * stack) is the destination buffer.  func_02030734 likewise takes five:
 * (heap, size, 0, __FILE__ at 0x020A7270, __LINE__). */
extern void func_0204944C(u32 arc, u32 file, u32 ofs, u32 size, void *dst);

/* The record initialiser func_02011F28 (src/matched/func_02011F28.c, EXACT*):
 * f00 = id, f04 = a2, f08 = func_02031324(id), f0c..f18 = 0,
 * f1c = func_020124F4(id), f20 = 0, f24 = func_020261E4(id, f1c),
 * f28 = 0, f2c = func_0202B4BC(f1c, id), f32 = 0, f33_0 = 0, then
 * func_02012248(p), func_020122A4(p), func_020139B0(id).
 * func_020261E4 takes TWO arguments; reading it as one costs a phantom
 * r0/r1 swap. */
extern void func_02011F28(struct IcaAnime *p, u16 id, u32 a2);
extern void *func_020261E4(u32 heap, void *tbl);

/* func_02012AC8 is `ldrh r0, [r0]; bx lr`: a u16 getter on the pointer
 * func_020120F8 returns; func_02012164 feeds its result to func_02013D34.
 * func_02012164 is byte-correct (src/pending, MATCH*) and capped only by
 * func_02158318 (ov010, no caller outside it). */
extern u16  func_02012AC8(const u8 *h);

/* func_02011688: the remainder is assigned back into the index PARAMETER
 * (`idx %= n;`) -- measured, it is what homes it in r2.  Still DIFF,
 * docs/notes/pkt_02011688.c.txt. */

#endif /* ICA_ANIME_H */
