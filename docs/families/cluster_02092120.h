/*
 * docs/families/cluster_02092120.h -- shared declarations for the
 * pseudo-family at 0x02092120..0x020924DC in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  The upper half of the ARM9 image has no
 * __FILE__ anchors, so this cluster is NOT a recovered original translation
 * unit.  It was formed by address adjacency plus shared callees and data
 * objects.
 *
 * WHAT THE SUBSYSTEM IS.  This is the MSL C STANDARD LIBRARY's primitive
 * layer: the memory and string routines, the floating-point classifiers, the
 * multibyte conversion, and at the top of the range the printf/scanf
 * conversion-spec scanner.  It sits between the buffered stdio it serves
 * (docs/families/cluster_02091588.h and docs/families/cluster_02091AE8.h,
 * immediately below) and the printf formatting family it feeds
 * (docs/families/cluster_020929E8.h, immediately above).  The three clusters
 * are ONE library and should be read as one.
 *
 * The identification does not depend on any guess about names -- every row is
 * a textbook implementation and each is byte-exact:
 *
 *   0x02092120  func_02092120   a two-line wrapper: clear the object's +0x0d
 *                               error byte, call func_02092004, clear it
 *                               again, return.  `clearerr`-and-retry.
 *   0x02092144  func_02092144   64-bit POPCOUNT: the four SWAR stages of the
 *                               standard bit-count idiom over an unsigned
 *                               long long, then the horizontal fold.
 *   0x020921D8  func_020921D8   SIGNBIT: `(hi & 0x80000000) ? 1 : 0` off a
 *                               u64 read as two words.
 *   0x020921F4  func_020921F4   FPCLASSIFY: the 0x7FF00000 exponent mask
 *                               ladder returning 1/2/3/4/5.  EXACT*, the
 *                               trailing star being the unlabelled leaf at
 *                               0x02092264 (a SEED-FILE item).
 *   0x020922B0  func_020922B0   one conversion step dispatched through a
 *                               function-pointer table at g_020A8878 + 4.
 *   0x020922CC  func_020922CC   wide-to-multibyte string conversion, driving
 *                               func_020922B0 per character and copying with
 *                               func_02094860.
 *   0x02092344  func_02092344   MEMCPY (byte-wise).  Filed as a `tu` pair.
 *   0x02092364  func_02092364   MEMMOVE (the overlap-aware twin).
 *   0x020923B0  func_020923B0   MEMSET wrapper: calls func_02092430 and
 *                               returns the pointer.
 *   0x020923C4  func_020923C4   MEMCHR.
 *   0x020923F0  func_020923F0   MEMCMP.
 *   0x02092430  func_02092430   the word-unrolled MEMSET core.
 *   0x020924DC  func_020924DC   MSL printf.c `parse_format`, the spec
 *                               scanner.  EXACT (wave 11); see section 3.
 *
 * Derived from the ten matched sources found with
 *   grep -l "address:  0x020921\|address:  0x020922\|address:  0x020923" \
 *        src/matched/*.c
 * plus src/matched/func_02092120.c, and from the note
 * docs/notes/pkt_020924DC.c.txt.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains
 * a field; a name does not.  A shift pair of unequal amounts proves a
 * bitfield's width and position; the 32-bit halves of a 64-bit shift
 * (`orr r3, r3, r1, lsl #31` after `lsr r3, r0, #1`) prove the operand is a
 * `long long` and not two words.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * THERE IS NO PIN HERE, and this is settled across the whole three-cluster
 * library.  Every byte-exact file in 0x02091150..0x02094534 carries
 * `compiler: 1.1p1` -- there is not one exception in thirty-five files -- and
 * the alternatives have now been measured on three separate stuck rows and
 * are worse every time:
 *
 *     func_020933B8   dsi/1.1p1 264 B /  65 out | ../2.0/sp2 272 B / 162 out
 *                                              | ../1.2/sp2 292 B / 253 out
 *     func_02091E44   dsi/1.1p1 448 B /  28 out | ../2.0/sp2 468 B / 107 out
 *     func_020917D4   dsi/1.1p1 788 B / 456 out | ../2.0/sp2 820 B / 686 out
 *
 * DO NOT SPEND A SLOT ON A FRONT-END SWEEP IN THIS RANGE.  If a function here
 * is size-exact but a push list wider than the image's, the cause is a
 * missing structural lever in the C (an unshared epilogue, a doubled call, a
 * missing home area), not the front end.  That is the OPPOSITE of
 * docs/families/cluster_020737C0.h, where eight functions are exact only
 * under ../2.0/sp2 and the wide push list IS the tell.
 *
 * ISA: ARM throughout, with no exceptions in this range.  This is unusual for
 * the ARM9 static module (Thumb almost everywhere) and follows from what the
 * cluster is -- MSL is compiled ARM, as layout/runtime_arm9.txt records for
 * the runtime helpers this code calls.  ALWAYS pass `--arm`.
 * ============================================================================
 */

#ifndef CLUSTER_02092120_H
#define CLUSTER_02092120_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;
typedef signed   char      s8;
typedef signed   short     s16;
typedef signed   int       s32;
typedef unsigned int       size_t;

/* ================================================================== *
 * 1.  Data objects
 * ================================================================== */

/* The conversion dispatch table func_020922B0 indexes.  The FUNCTION POINTER
   IS AT +0x04 of each record, not at +0x00: the four pad bytes before it are
   what the `ldr` offset proves, and declaring the table as bare function
   pointers loses them. */
typedef struct {
    u8  pad[4];
    u32 (*fn)(u32 *dst, u32 c);
} FuncTable;
extern FuncTable g_020A8878[];          /* 0x020A8878                         */

/* The 512-byte character-class map func_020924DC reads as HALFWORDS, one per
   character.  Bit 3 is "is a decimal digit"; the scanner tests
   `(g_020A61DC[c] & 8) != 0` guarded by `c < 0x80` (for c >= 0x80 the image
   branches to a zero class with `movhs r5, r0`, so the guard is in the
   source, not an artefact). */
extern u16 g_020A61DC[];                /* 0x020A61DC                         */

/* Distinct from g_020A60DC, the 256-BYTE case-folding table that
   func_02091C40 and func_0209AB8C read.  Do not conflate the two: one is
   halfword-indexed classes, the other byte-indexed case mapping. */
extern const u8 g_020A60DC[];           /* 0x020A60DC                         */

/* ================================================================== *
 * 2.  struct Spec -- the conversion specification
 *
 * SIXTEEN BYTES, copied out whole with ONE `ldm`/`stm` pair, which is why the
 * scanner's C must end in a STRUCT ASSIGNMENT `*out = spec;` and not in a
 * sequence of field stores (see docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * This layout is confirmed from BOTH ends and is the operand of the whole
 * printf family: func_020924DC writes it, and func_020929EC, func_02092C3C
 * and func_02092F10 (docs/families/cluster_020929E8.h) read exactly bytes
 * 0, 1, 3 and 5 of it.
 * ================================================================== */
struct Spec {
    u8  f0;                 /* +0x00  justify: 0 = '-', 1 = none, 2 = '0'     */
    u8  sign;               /* +0x01  0 = none, 1 = '+', 2 = ' '              */
    u8  prec_p;             /* +0x02  precision present                       */
    u8  hash;               /* +0x03  '#'                                     */
    u8  len;                /* +0x04  0 none, 1 hh, 2 h, 3 l, 4 ll,
                                       5 'c'->wint_t, 6 j, 7 z, 8 t, 9 L      */
    u8  conv;               /* +0x05  conversion char; 0xFF = invalid, or '%' */
    u8  pad[2];             /* +0x06                                          */
    u32 width;              /* +0x08  capped at SPEC_WIDTH_MAX                */
    u32 prec;               /* +0x0C                                          */
};

/* ================================================================== *
 * 3.  func_020924DC -- MSL printf.c `parse_format`.  EXACT (wave 11).
 *
 * src/matched/func_020924DC.c, 1292 bytes, 1.1p1, ARM.  Closed by writing
 * the Metrowerks source shape instead of transcribing the bytes, the lesson
 * of the whole wave: the earlier transcription (docs/notes/pkt_020924DC.c.txt,
 * 1288 B / 941 out, permuter floor 1292 / 763) was a "whole-function
 * colouring class away" only because its SHAPE was wrong.  What the image
 * actually is:
 *
 *   const uchar *parse_format(const uchar *s, va_list *arg, print_format *f)
 *   with `print_format f; int c; int flag_found;` (the image's lr is `c`,
 *   ip is `s`, r7 is flag_found),
 *   - the flag loop as `for (;;) { flag_found = 1; switch (c) {...
 *     default: flag_found = 0; } if (flag_found) c = *++s; else break; }`,
 *   - `*` width / precision through va_arg(*arg, int) (MSL's
 *     `(*(int *)((ap += 4) - 4))`), assigned inside the `< 0` test,
 *   - isdigit as `((unsigned int)(c) < 0x80 ? (__ctype_map[c] & 8) : 0)` --
 *     the UNSIGNED range test is load-bearing (a signed `c < 0x80` gives
 *     movge/lsllt, the image has movhs/lsllo),
 *   - the length modifiers as a second switch with flag_found, cases in
 *     the order h, l, L, j, t, z (the arm bodies store 6, 8, 7 in that
 *     order; j, z, t swaps two branch targets),
 *   - the conversion switch in MSL's own order with `g`/`G` FALLING THROUGH
 *     into `e`/`E` and `a`/`A`'s six-way bad-length test as one `||` chain.
 * Measured: the plain MSL shape with signed isdigit and j,z,t order was
 * 12 bytes out; the two fixes closed it.  ../2.0/sp2 on the exact source is
 * 1392 bytes, so the no-pin statement above stands.
 *
 * print_format is the caller's struct (src/matched/func_02093BDC.c, the
 * __pformatter core): six unsigned char fields then `int field_width`,
 * `int precision`.  struct Spec in section 2 is the same 16 bytes; the
 * width compare is SIGNED (`ble` against 0x1FD), so field_width is int, not
 * u32.
 * ================================================================== */

/* ================================================================== *
 * 4.  Prototypes, with the parameter types the matched sources fixed
 * ================================================================== */

/* --- the cluster's own ---------------------------------------------------- */
extern s32   func_02092120(void *obj, s32 a1, s32 a2, s32 a3);
extern u32   func_02092144(u64 v);                  /* popcount               */
extern s32   func_020921D8(u64 v);                  /* signbit                */
extern s32   func_020921F4(u64 v);                  /* fpclassify, 1..5       */
extern u32   func_020922B0(u32 *dst, u32 c);        /* one conversion step    */
extern u32   func_020922CC(u8 *dst, const u16 *src, u32 max);
extern void *func_02092344(void *dst, const void *src, size_t n);  /* memcpy  */
extern void *func_02092364(void *dst, const void *src, size_t n);  /* memmove */
extern void *func_020923B0(void *dst, s32 c, size_t n);            /* memset  */
extern void *func_020923C4(const void *s, s32 c, size_t n);        /* memchr  */
extern s32   func_020923F0(const void *a, const void *b, size_t n);/* memcmp  */
extern void  func_02092430(u8 *dst, u32 val, u32 count);  /* memset core      */
extern const u8 *func_020924DC(const u8 *s, u8 **arg, struct Spec *out); /* parse_format, EXACT */

/* --- reached from inside the cluster -------------------------------------- */
extern s32   func_02092004(u32 id, u32 a1, u32 a2);
extern void  func_02094860(u8 *dst, const u8 *src, u32 n);

/* ================================================================== *
 * 5.  Constants
 * ================================================================== */
#define SPEC_SIZE           0x10    /* one ldm/stm pair copies it out         */
#define SPEC_WIDTH_MAX      0x1FD   /* over it the spec returns conv = 0xFF   */
#define SPEC_CONV_INVALID   0xFF
#define CLASS_DIGIT_BIT     8       /* g_020A61DC[c] & 8                      */
#define CLASS_TABLE_LIMIT   0x80    /* above it the class is taken as 0       */
#define FUNCTABLE_FN_OFF    4       /* g_020A8878 record: fn at +4, not +0    */

#endif /* CLUSTER_02092120_H */
