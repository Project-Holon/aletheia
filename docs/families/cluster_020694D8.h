/*
 * docs/families/cluster_020694D8.h -- shared declarations for the
 * pseudo-family at 0x020694D8..0x02069AC4 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled
 * shape instead of re-deriving it.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  Unlike docs/families/mcss.h this is NOT a
 * recovered translation unit -- the upper half of the ARM9 image carries no
 * __FILE__ anchors.  It was formed by address adjacency plus shared callees,
 * and here the adjacency is real: all six members are ONE SUBSYSTEM, the
 * NFTR FONT TEXT RENDERER, and they form a clean call chain.
 *
 *   func_020698F8   open the font resource, validate it, publish the FINF
 *                   payload                                  (OPEN, DIFF)
 *   func_02069AC4   relocate the resource's section table    (EXACT)
 *   func_020696F4   block-alignment pre-pass, 2-D            (EXACT)
 *   func_02069818   line-alignment pre-pass, 1-D             (EXACT)
 *   func_0206958C   the LINE loop: align, draw, step down    (EXACT)
 *   func_020694D8   the CHARACTER loop: draw one line        (EXACT)
 *
 * The two pre-passes both tail-call func_0206958C, which calls func_020694D8
 * once per line, which calls the per-glyph blitter func_02068EA0 once per
 * character.  The measuring siblings live just below the cluster
 * (func_02068030 measures one line, func_020680DC one string,
 * func_02068150 a whole block) and are the best writing aid in the range:
 * func_02068030 in particular is func_020694D8 with the drawing removed and
 * carries the identical cursor/newline tail.
 *
 * Derived from the five matched sources found with
 *   grep -l "address:  0x02069[4-9A]" src/matched/*.c
 * and from docs/notes/pkt_020694D8.c.txt.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains
 * a field; a name does not.  `ldrsb`/`ldrsh` prove signedness; a plain `ldr`
 * followed by a shift pair proves the FIELD is 32-bit and the narrowing
 * happens at the use.  Where two matched files disagree, the file whose code
 * actually constrains the field wins.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * FOUR of this cluster's five EXACT files are pinned to `../2.0/sp2`:
 *
 *   func_020694D8   func_0206958C   func_020696F4   func_02069AC4
 *
 * and func_02069818 is the single 1.1p1 file.  The tells are recorded per
 * file in docs/FRONTEND-PINS.md and are three different faces of the same
 * thing -- 1.1p1 -O4,p is more aggressive about collapsing control flow:
 *
 *   - func_020696F4: 1.1p1 PREDICATES a five-instruction guard arm the image
 *     branches over.
 *   - func_0206958C: 1.1p1 CROSS-JUMPS two identical arm tails the image
 *     writes out twice; 352 bytes against 360.
 *   - func_02069AC4: 1.1p1 FOLDS a dead compare whose arm shares the default
 *     exit; 216 bytes against 220.
 *   - func_020694D8: a NARROW pin -- same 180 bytes under both, 10 bytes out,
 *     a scheduling difference in the four-instruction head only.
 *
 * Symptom to recognise instantly: a compile whose instructions and
 * relocations are all correct but that is FOUR OR EIGHT BYTES SHORT, or whose
 * push/pop lists are one register wider than the image's.  If a function in
 * this range is nearly right and short, change the compiler, not the source.
 *
 * ISA: ARM throughout.  Unusual for game code (the ARM9 static module is
 * Thumb almost everywhere) and itself a cluster property: always pass `--arm`.
 * ============================================================================
 */

#ifndef CLUSTER_020694D8_H
#define CLUSTER_020694D8_H

typedef signed int         s32;
typedef unsigned int       u32;
typedef unsigned short     u16;
typedef unsigned char      u8;

/* ================================================================== *
 * 1.  struct Step -- the step vector, THE CLUSTER'S DEFINING TYPE
 *
 * The two trailing `signed char` parameters every function in this cluster
 * carries are ONE 2-BYTE STRUCT PASSED BY VALUE, not two char arguments.
 * This is the single most expensive thing to get wrong here and it is
 * evidenced by func_02069818's header: spelled as two arguments the ABI gives
 * each its own word slot and the image's `ldrsb r2, [sp, #0x39]` /
 * `strb ip, [sp, #0xd]` become +0x3C and +0x10.  The struct form packs them
 * adjacently and is what makes all four files byte-correct.
 *
 * It is a unit direction vector for the text baseline, and it is applied the
 * same way everywhere:
 *   ALONG the baseline    pen.x += n * st.dx;   pen.y += n * st.dy;
 *   ACROSS it (next line) pen.x += n * -st.dy;  pen.y += n * st.dx;
 * Each application is the `mla` pair the diffs in this range keep landing on.
 * ================================================================== */
typedef struct {
    signed char dx;
    signed char dy;
} Step;

/* ================================================================== *
 * 2.  struct Ctx -- the renderer context
 *
 * Every entry point takes this as its first argument.  Each matched file
 * declares only the fields it loads, so the union is below and the per-file
 * views are noted; declare per function, not once.
 *
 *   +0x00  the DESTINATION surface, func_02068EA0's first argument.
 *          func_020694D8 loads it fresh inside the loop (`ldr r0, [fp]`).
 *   +0x04  the FONT object.  Its +0x00 is a measure callback and its +0x04 is
 *          the CHARACTER ITERATOR (see NextFn).  func_020694D8 caches it,
 *          func_02068030 caches only the iterator out of it.
 *   +0x08  the INTER-CHARACTER GAP, added to every glyph advance
 *          (`add r0, r4, r0` in func_020694D8 after the blit).  Signed.
 *          NOTE func_020696F4 reads +0x08 as a POINTER instead, its third
 *          argument to func_02068150 -- the two readings coexist because the
 *          two functions are reading different objects through the same
 *          pointer type.  func_020694D8's is the constraining one for the
 *          draw path.
 *   +0x0C  the LEADING, added to the font header's own line-step byte to give
 *          the distance between baselines (`ctx->f0C + hdr->b01` in
 *          func_0206958C).  Signed.
 * ================================================================== */
typedef struct {
    void *f00_dst;          /* 0x00  destination surface                     */
    void *f04_font;         /* 0x04  font object; +0x04 is the iterator      */
    s32   f08_gap;          /* 0x08  inter-character gap (a pointer in 696F4)*/
    s32   f0C_leading;      /* 0x0c  extra line spacing                      */
} Ctx;

/* The character iterator, ctx->f04's SECOND word.  It advances the cursor in
   place and returns the character code, 0 at end of string and 0xa ('\n') at
   a line break -- the two stop conditions every walk in this cluster tests.
   Invoked with `blx` off a register, never called by name. */
typedef s32 (*NextFn)(const void **cursor);

/* The font header func_0206958C reaches through ctx->f04's FIRST word:
   `((Hdr *)((void **)ctx->f04)[0])->b01` is the line step, and it is SIGNED
   (`ldrsb`).  b00 is read by nothing in this cluster. */
typedef struct {
    u8          b00;
    signed char b01;        /* line step, added to Ctx.f0C_leading           */
} Hdr;

/* The two-word measured extent func_02068150 fills.  func_020696F4 keeps
   THREE distinct copies of it on the stack (sp+0x10, sp+0x18, sp+0x20) and
   two of them MUST be declared `volatile` or both front ends dead-store
   eliminate them and the frame comes out 0x18 instead of 0x28. */
typedef struct {
    s32 w;
    s32 h;
} Ext;

/* ================================================================== *
 * 3.  struct Res -- the NFTR font resource, subsystem entry
 *
 * func_020698F8's argument.  THE VERSION IS A u16 AT +0x06, NOT +0x08:
 * `ldrh r1, [r6, #6]` at 0x02069948 and 0x020699BC, `ldrh r0, [r6, #6]` at
 * 0x02069A30.  A `u32` between sig and ver puts the field at +0x08 and every
 * version compare reads the wrong halfword -- this cost a whole pass, see
 * docs/notes/pkt_020694D8.c.txt.
 *
 * The three accepted versions are 0x0102 and 0x0101 (pool words at
 * 0x02069AB8 and 0x02069ABC) and 0x0100 (an immediate, `cmp r0, #0x100` at
 * 0x02069A34).  Matching 0x0100 only is the "legacy" path, which additionally
 * clears one byte of the payload.
 * ================================================================== */
typedef struct {
    u32 sig;                /* 0x00  'NFTR', 0x4E465452                      */
    u16 unk04;
    u16 ver;                /* 0x06  0x0100 / 0x0101 / 0x0102                */
} Res;

/* The section header func_02069AC4 walks.  The u16 at +0x0C of the RESOURCE
   is the byte offset of the first one and the u16 at +0x0E the count; each
   header carries its own FourCC at +0 and its own size at +4, which is the
   stride to the next. */
typedef struct {
    u32 sig;
    u32 size;               /* stride to the next header                     */
    u32 unk08;
    u32 unk0C;              /* 'CWDH' relocates this if non-zero             */
    u32 unk10;              /* 'FINF' always, 'CMAP' if non-zero             */
    u32 unk14;              /* 'FINF' if non-zero                            */
    u32 unk18;              /* 'FINF' if non-zero                            */
} Section;

typedef struct {
    u8  unk00[0xc];
    u16 off0C;              /* 0x0c  offset of the first Section             */
    u16 cnt0E;              /* 0x0e  Section count                           */
} Font;

/* ================================================================== *
 * 4.  Constants
 * ================================================================== */
#define SIG_NFTR    0x4e465452u     /* pool 0x02069AB4                       */
#define SIG_FINF    0x46494e46u     /* pool 0x02069AC0, and func_02062B64's  */
#define SIG_CWDH    0x43574448u
#define SIG_CMAP    0x434d4150u
#define SIG_CGLP    0x43474c50u     /* the EMPTY arm -- see func_02069AC4    */
#define NFTR_V102   0x0102          /* pool 0x02069AB8                       */
#define NFTR_V101   0x0101          /* pool 0x02069ABC                       */
#define NFTR_V100   0x0100          /* immediate at 0x02069A34               */
#define CH_EOS      0               /* iterator's end-of-string return       */
#define CH_NEWLINE  0xa             /* iterator's line-break return          */

/* ================================================================== *
 * 5.  Prototypes, with the parameter types the matched sources fixed
 * ================================================================== */

/* --- the measuring siblings, just below the cluster (0x02068xxx) --------- */
/* Measure ONE line; `last` takes the cursor at a newline and 0 at end of
   string, the identical tail func_020694D8 carries.  The best writing aid in
   the range. */
extern s32  func_02068030(void *font, void *b, const void *cur, void *last);
/* Measure one whole string, no line handling. */
extern s32  func_020680DC(void *font, void *b, u32 s);
/* Measure a whole multi-line block into a two-word out buffer. */
extern void func_02068150(Ext *out, void *a, void *b, void *c, u32 s);
/* Blit ONE glyph and return its advance.  Six arguments, the last two on the
   stack; the advance has Ctx.f08_gap added to it by the caller. */
extern s32  func_02068EA0(void *dst, void *font, s32 x, s32 y, s32 w2, s32 c);

/* --- the resource layer ------------------------------------------------- */
extern void *func_02062B64(void *base, u32 sig);   /* find a Section by sig  */
extern void  func_02088234(void);                  /* the assert reporter    */

/* --- this cluster's own ------------------------------------------------- */
/* Open and validate the resource; *out receives the FINF payload + 8.
   Returns 1 on success, 0 when the FINF section is missing.  OPEN, DIFF. */
extern u32  func_020698F8(Res *res, void **out);
/* Relocate every Section's stored file offsets against `base`.  EXACT. */
extern void func_02069AC4(Font *base);
/* Block-alignment pre-pass: measure the whole extent, back the pen off by
   flag bits 0x10/0x20 (horizontal) and 0x02/0x04 (vertical), forward.  EXACT */
extern void func_020696F4(Ctx *ctx, s32 x, s32 y, s32 w,
                          u32 flags, u32 s, Step st);
/* Line-alignment pre-pass: flag bit 0x100 right-aligns by the full measured
   extent, bit 0x80 centres by half, then forward.  EXACT (1.1p1). */
extern void func_02069818(Ctx *ctx, s32 x, s32 y, s32 w,
                          u32 a4, u32 a5, u32 flags, u32 s, Step st);
/* The LINE loop.  Per line, flag bit 0x800 right-aligns within the measured
   line box and bit 0x400 centres; then draw the line and step the pen down
   one line height along the step NORMAL.  EXACT. */
extern void func_0206958C(Ctx *ctx, s32 x, s32 y, s32 w,
                          s32 w2, u32 flags, const void *s, Step st);
/* The CHARACTER loop: walk one line, blitting each glyph and stepping the pen
   ALONG the baseline.  `last` receives the cursor when the stop was a newline
   and 0 when it was end of string.  EXACT. */
extern void func_020694D8(Ctx *ctx, s32 x, s32 y, s32 w2,
                          const void *s, const void **last, Step st);

#endif /* CLUSTER_020694D8_H */
