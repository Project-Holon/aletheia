/*
 * docs/families/cluster_02091588.h -- shared declarations for the
 * pseudo-family at 0x02091588..0x020917D4 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled shape
 * instead of re-deriving it.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  The upper half of the ARM9 image has no
 * __FILE__ anchors, so unlike docs/families/mcss.h this cluster is NOT a
 * recovered original translation unit.  It was formed by address adjacency
 * plus shared callees and data objects.
 *
 * WHAT THE SUBSYSTEM IS.  This is MSL's BUFFERED STDIO -- the FILE object and
 * the machinery that moves bytes between a caller's buffer and it.  The
 * evidence does not depend on any guess about names:
 *
 *   - every function here operates on ONE object whose field set is fixed by
 *     src/matched/func_0209159C.c (f18/f1c/f20/f24/f28/f2c/f34),
 *     src/matched/func_020915C4.c (adds f00, f04, f3c, f48) and
 *     src/matched/func_02091650.c (adds f40);
 *   - +0x3c and +0x40 are CALLBACK FIELDS invoked as a bare `blx ip` off a
 *     cast of the field, each with the same four arguments (f00, f1c, &f28,
 *     f48).  That is a FILE's read and write vectors;
 *   - func_020915C4 is the PREPARE half and func_02091650 the COMMIT half of
 *     one pair, and both end in func_0209159C, which is the three-statement
 *     "re-derive the working pointers" routine (f24 = f1c;
 *     f28 = f20 - (f18 & f2c); f34 = f18);
 *   - func_020917D4 is `fread`: it multiplies size by count, drains the
 *     pushback stack the +0x08 word's low three bits count, refills through
 *     func_020915C4, copies with func_02092344 (which
 *     src/matched/unit_02092344.c proves is byte-wise memcpy) and returns
 *     func_0209C2B0(bytes, size), i.e. the element count;
 *   - func_020916D4 is its refcounting wrapper (see THE WRAPPER FAMILY).
 *
 * Derived from the eight matched sources found with
 *   grep -l "address:  0x020915[89ABCDEF]\|address:  0x020916\|address:  0x020917" \
 *        src/matched/*.c
 * plus src/matched/func_02091CBC.c and src/matched/func_02091E44.c's family,
 * and from the notes docs/notes/pkt_020916D4.c.txt and
 * docs/notes/pkt_02091B5C.c.txt.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains
 * a field; a name does not.  `ldrsb`/`ldrsh` prove signedness; a shift pair of
 * unequal amounts proves a bitfield's width and position; a plain `ldr`
 * followed by a shift pair proves the FIELD is 32-bit and the narrowing
 * happens at the use.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * THERE IS NO PIN HERE.  Every byte-exact file in this cluster is EXACT under
 * the project default `dsi/1.1p1` with `-O4,p -proc arm946e`, and every
 * matched source in 0x02091xxx-0x02092xxx carries `compiler: 1.1p1` without
 * exception.  The alternative was probed on this cluster's hardest open row
 * (func_020917D4, 2026-09-22) and is decisively worse:
 *
 *     dsi/1.1p1     788 bytes (SIZE-EXACT), 456 concrete bytes out
 *     ../2.0/sp2    820 bytes,              686 concrete bytes out
 *
 * Do not spend a slot re-running that probe.  This is the OPPOSITE of
 * docs/families/cluster_020737C0.h, whose eight functions are exact only
 * under ../2.0/sp2: a push list one register wider than the image's means
 * a missing structural lever here, not a front end.
 *
 * ISA: ARM throughout, with ONE EXCEPTION worth knowing -- the four
 * 0x020911D8..0x02091260 rows immediately below this cluster
 * (func_020911D8, func_02091200, func_02091230, func_0209125C) are THUMB.
 * Inside 0x02091588..0x020917D4 itself, always pass `--arm`.
 * ============================================================================
 */

#ifndef CLUSTER_02091588_H
#define CLUSTER_02091588_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed   char  s8;
typedef signed   short s16;
typedef signed   int   s32;

/* ================================================================== *
 * 1.  struct File -- the stdio object
 *
 * Field evidence, one function per line:
 *   +0x00   the handler's first argument (func_020915C4, func_02091650).
 *   +0x04   the FLAG WORD.  Three disjoint bitfields are read out of it and
 *           each is proved by its own unequal shift pair, so none of them may
 *           be spelled as a mask:
 *             bits 7..9   `lsl #0x16 / lsr #0x1d`  -- the OPEN MODE.
 *                         func_02091CBC guards on it == 1 and narrows the
 *                         result to u8 before the compare (`and r1, r1, #0xff`
 *                         at 0x02091E60); func_020917D4 guards on it != 0.
 *             bits 2..4   `lsl #0x1b / lsr #0x1d`  -- the DIRECTION.  Tested
 *                         `& 1` by func_020917D4 and `!= 3` by func_02091E44.
 *             bits 5..6   `lsl #0x19 / lsr #0x1e`  -- tested `& 1` by
 *                         func_020917D4 before its func_0209149C call.
 *             bit 12      `lsl #0x13 / lsr #0x1f`  -- func_020917D4's lock.
 *             bit 12      is ALSO read by func_020915C4 / func_02091650 as
 *                         `(f04 << 19) >> 31`; a `tst #0x1000` spelling folds
 *                         both shifts away and is 102 bytes out.
 *   +0x08   the STATE WORD.  Its low three bits are a small state, always read
 *           `lsl #0x1d / lsr #0x1d` and written `bic #7` then `orr`.  Values
 *           seen: 0 (fresh), 2 (buffer live), >= 3 (pushback pending, and the
 *           count is the value minus 2).  A `& 7` spelling folds to
 *           `and r0, r0, #7` and loses the pair.
 *   +0x0c   sticky end-of-input flag, `strb`.
 *   +0x0d   sticky error flag, `strb`.  Every failure path sets it to 1 and
 *           zeroes f28.
 *   +0x0e   the PUSHBACK BUFFER, indexed off the state word: func_020917D4
 *           reads a halfword at `p + 0xe + ((f08 << 29) >> 28)` and a byte at
 *           `p + 0xf + ((f08 << 29) >> 29)`.
 *   +0x18   the logical position.  func_0209159C copies it to f34; func_02091E44
 *           writes the caller's new position here.
 *   +0x1c   the buffer base.  func_020917D4 borrows it (saving and restoring
 *           the pair f1c/f20) to read straight into the caller's buffer.
 *   +0x20   the buffer capacity.  Borrowed with f1c.
 *   +0x24   the read cursor.  func_0209159C resets it to f1c.
 *   +0x28   the bytes remaining.  The out parameter of the +0x3c handler.
 *   +0x2c   the position mask, ANDed with f18 by func_0209159C.
 *   +0x30   the refill amount func_020917D4 latches when the state is 2.
 *   +0x34   the buffer's own start position (func_0209159C sets it from f18;
 *           func_02091E44 subtracts it to convert a position to an offset).
 *   +0x38   an OPTIONAL SEEK HANDLER, called only by func_02091E44 and only
 *           when non-null, with (f00, &pos, whence, f48).
 *   +0x3c   the READ/FILL handler.  Bare `blx ip` off a cast of the field; a
 *           guarded `p->f3c ? ... : 0` spelling is 102 bytes out.
 *   +0x40   the COMMIT handler (func_02091650), same four arguments.
 *   +0x48   the handler's fourth argument, visible only as the otherwise-dead
 *           `ldr r3, [r4, #0x48]` the call does not need.
 * ================================================================== */
struct File {
    u32 f00;                /* 0x00  handler argument 1                      */
    u32 f04;                /* 0x04  flag word; read through the views below */
    u32 f08;                /* 0x08  state word; low 3 bits                  */
    u8  f0c;                /* 0x0c  end-of-input                            */
    u8  f0d;                /* 0x0d  error                                   */
    u8  f0e[2];             /* 0x0e  pushback buffer                         */
    u8  pad10[0x08];
    u32 f18;                /* 0x18  logical position                        */
    u32 f1c;                /* 0x1c  buffer base                             */
    u32 f20;                /* 0x20  buffer capacity                         */
    u32 f24;                /* 0x24  read cursor                             */
    u32 f28;                /* 0x28  bytes remaining                         */
    u32 f2c;                /* 0x2c  position mask                           */
    u32 f30;                /* 0x30  refill amount                           */
    u32 f34;                /* 0x34  buffer start position                   */
    u32 f38_seek;           /* 0x38  optional; null means "no seek"          */
    u32 f3c_read;           /* 0x3c  fill handler, cast and blx'd            */
    u32 f40_commit;         /* 0x40  commit handler, cast and blx'd          */
    u32 pad44;
    u32 f48;                /* 0x48  handler argument 4                      */
};

/* THE BITFIELD VIEWS.  Declare the view, cast &p->fNN to it, read the member.
   These are NOT interchangeable with masks or with hand-written shift pairs:
   each unequal pair below is what keeps both shifts alive in the output. */
struct F04hiP { u32 lo : 7;  u32 mode : 3; u32 hi : 22; };  /* f04 bits 7..9  */
struct F04loP { u32 lo : 2;  u32 mode : 3; u32 hi : 27; };  /* f04 bits 2..4  */
struct F04b56 { u32 lo : 5;  u32 mode : 2; u32 hi : 25; };  /* f04 bits 5..6  */
struct F04b12 { u32 lo : 12; u32 b : 1;    u32 hi : 19; };  /* f04 bit 12     */
struct F08P   { u32 mode : 3; u32 hi : 29; };               /* f08 bits 0..2  */

/* The handlers at +0x3c and +0x40.  The field is declared u32 and CAST at the
   call site; declaring the field itself as a function pointer also works and
   is what src/matched/func_020915C4.c does. */
typedef u32 (*FileHandler)(u32 a, u32 base, u32 *remaining, u32 d);

/* The seek handler at +0x38, which takes the position BY ADDRESS -- which is
   why func_02091E44 opens with the `push {r0, r1, r2, r3}` home area. */
typedef u32 (*FileSeek)(u32 a, u32 *pos, u32 whence, u32 d);

/* ================================================================== *
 * 2.  THE WRAPPER FAMILY.  Three functions, one shape, all EXACT.
 *
 * Wave 7 closed two of these three by transcribing the third.  IF A ROW IN
 * 0x02091600..0x02092120 IS SIZE-EXACT-ISH AND READS THESE POOL OBJECTS,
 * READ THIS SECTION BEFORE DIAGNOSING AN ALLOCATOR TIE.
 *
 *   func_020916D4(a0, a1, a2, a3)  -> forwards to func_020917D4, id is a3,
 *                                     TWO-way dispatch (g_020A8730 ? 2 : 5)
 *   func_02091D38(a0)              -> forwards to func_02091CBC, id is a0,
 *                                     THREE-way dispatch
 *   func_02092004(a0, a1, a2)      -> forwards to func_02091E44, id is a0,
 *                                     THREE-way dispatch
 *
 * The body is identical in all three and every line of it is load-bearing:
 *
 *   u32 idx = (id == (u32)g_020A8730) ? 2 : (id == (u32)g_020A877C) ? 3
 *           : (id == (u32)g_020A87C8) ? 4 : 5;
 *   u8 *blk = g_02153BD4 + idx * 0x18;
 *   if (func_020860D0(blk) == 0) {
 *       arr_02153B8C[idx] = g_02150FEC.unk04[0x1b];
 *       arr_02153BB0[idx] = 1;
 *   } else {
 *       u32 cur = arr_02153B8C[idx];          <-- BOTH sides named, ARRAY
 *       u32 ref = g_02150FEC.unk04[0x1b];         ELEMENT FIRST
 *       if (cur == ref) {                     <-- a NESTED if/else, never
 *           arr_02153BB0[idx]++;                  an `else if`
 *       } else {
 *           func_02086028(blk);
 *           arr_02153B8C[idx] = g_02150FEC.unk04[0x1b];   <-- written out in
 *           arr_02153BB0[idx] = 1;                            FULL, again
 *       }
 *   }
 *   r = <the wrapped call>;
 *   arr_02153BB0[idx]--;
 *   if (arr_02153BB0[idx] == 0) func_02086078(blk);
 *   return r;
 *
 * THREE SPELLINGS COST WHOLE PASSES BEFORE THEY WERE SETTLED:
 *  - the id constants are ADDRESSES compared against the argument, so they are
 *    declared as OBJECTS and their address taken.  Declaring them `u32` makes
 *    the compiler dereference them: 100 bytes of diff.
 *  - g_02150FEC is a TWO-WORD object whose SECOND word is the pointer.  The
 *    pool word is 0x02150FEC itself, so the field is reached through
 *    `g_02150FEC.unk04[0x1b]`, never through a symbol named for 0x02150FF0.
 *  - the `cur`/`ref` pair is the whole residue.  Written as
 *    `else if (arr_02153B8C[idx] == g_02150FEC.unk04[0x1b])` the compiler
 *    canonicalises EITHER operand order to the swapped temporaries and leaves
 *    a three-instruction diff no further spelling reaches.  Two live named
 *    locals on the compare is what lands arr in r1 and the field in r0.
 * ================================================================== */
struct Hdr02150FEC { u32 unk00; u32 *unk04; };

extern u8 g_020A8730[];                 /* 0x020A8730  id, dispatch -> 2      */
extern u8 g_020A877C[];                 /* 0x020A877C  id, dispatch -> 3      */
extern u8 g_020A87C8[];                 /* 0x020A87C8  id, dispatch -> 4      */
extern u8 g_02153BD4[];                 /* 0x02153BD4  block base, stride 0x18*/
extern struct Hdr02150FEC g_02150FEC;   /* 0x02150FEC  unk04[0x1b] is the tok */
extern u32 arr_02153B8C[];              /* 0x02153B8C  the latched token      */
extern u32 arr_02153BB0[];              /* 0x02153BB0  the refcount           */

/* ================================================================== *
 * 3.  Other data objects
 * ================================================================== */

/* The errno-like word every failure path sets to 0x28 before returning -1.
   Note the spelling the image uses: it materialises 0x28 into a register,
   stores it, and derives the -1 as `sub r0, r1, #0x29` off that same
   register rather than as a fresh `mvn`. */
extern u32 g_02153FAC;                  /* 0x02153FAC                         */

/* The 256-byte case-folding table shared with func_0209AB8C's strcmp.  Only
   bytes below 0x80 are mapped; the guard is a SIGNED `c >= 0 && c < 0x80` on
   an `int`, which is what emits the `cmp #0; blt` before the
   `cmp #0x80; ldrblt` even though the byte load itself is unsigned. */
extern const u8 g_020A60DC[];           /* 0x020A60DC                         */

/* ================================================================== *
 * 4.  Prototypes, with the parameter types the matched sources fixed
 * ================================================================== */

/* --- the cluster's own ---------------------------------------------------- */
extern void func_02091588(void);
extern void func_02091594(u32 a, u32 *b);
extern s32  func_02091598(u32 a, u32 *b);
extern void func_0209159C(struct File *p);              /* re-derive f24/f28/f34 */
extern s32  func_020915C4(struct File *p, u32 *out, s32 mode);  /* prepare  */
extern s32  func_02091650(struct File *p, u32 *out);            /* commit   */
extern u32  func_020916D4(u8 *buf, u32 sz, u32 cnt, u32 id);    /* wrapper  */
extern u32  func_020917D4(u8 *buf, u32 sz, u32 cnt, struct File *p);  /* fread */

/* --- reached from inside the cluster -------------------------------------- */
extern s32  func_0209149C(void);
extern s32  func_02096508(struct File *p, s32 v);       /* 0 asks, -1 sets    */
extern u32  func_02091CBC(struct File *p);              /* position query     */
extern s32  func_02091E44(struct File *p, u32 pos, u32 whence); /* seek       */
extern void func_02092344(u8 *dst, u32 src, u32 n);     /* memcpy             */
extern u32  func_0209C2B0(u32 total, u32 size);         /* unsigned divide    */
extern s32  func_020860D0(void *blk);
extern void func_02086028(void *blk);
extern void func_02086078(void *blk);

/* ================================================================== *
 * 5.  Constants
 * ================================================================== */
#define FILE_STATE_MASK     7       /* f08 low three bits                     */
#define FILE_STATE_LIVE     2       /* buffer holds data                      */
#define FILE_STATE_PUSHED   3       /* >= 3: pushback pending, count = v - 2  */
#define FILE_PUSHBACK_OFF   0x0e    /* func_020917D4's halfword/byte reads    */
#define WRAP_BLOCK_STRIDE   0x18    /* g_02153BD4, `mul rN, rIdx, #0x18`      */
#define WRAP_TOKEN_INDEX    0x1b    /* g_02150FEC.unk04[0x1b]                 */
#define ERR_VALUE           0x28    /* g_02153FAC on every failure path       */
#define CASEFOLD_LIMIT      0x80    /* g_020A60DC maps only below this        */


/* ================================================================== *
 * WAVE 10 ADDENDUM (2026-09-22) -- func_020917D4 EXACT (1.1p1)
 * ================================================================== *
 * func_020917D4 is MSL C's `__fread` and is EXACT under dsi/1.1p1 as
 * src/matched/func_020917D4.c.  Transcribed straight from the Metrowerks
 * MSL shape it compiled byte-exact once the FILE layout was right, which
 * retires the "456-byte colouring residue the permuter cannot reach" in
 * docs/notes/pkt_020916D4.c.txt: that residue was a wrong body, not a tie.
 * The struct is MSL's FILE, and the section 1 field list above maps onto it:
 *   f04 = __file_modes bitfield (open_mode:2, io_mode:3, buffer_mode:2,
 *         file_kind:3, file_orientation:2, binary_io:1)
 *   f08 = __file_state bitfield (io_state:3, free_buffer:1)
 *   f0c = eof (u8), f0d = error (u8)    <-- PLAIN FILE MEMBERS.  Putting them
 *         inside an 8-byte state struct shifts everything after +0x0c by 4
 *         and is 26 bytes out.
 *   f0e = char_buffer, f0f = char_buffer_overflow, +0x12 = ungetc_buffer[2],
 *   +0x14 = ungetwc_buffer[2] (u16), f18 = position, f1c = buffer,
 *   f20 = buffer_size, f24 = buffer_ptr, f28 = buffer_len,
 *   f2c = buffer_alignment, f30 = saved_buffer_len, f34 = buffer_pos,
 *   f38/f3c/f40 = position/read/write procs, f48 = ref_con.
 * Callees: func_02096508 = fwide, func_0209149C =
 * __flush_line_buffered_output_files, func_020915C4 = __load_buffer
 * (file, &count, align), func_0209159C = __prep_buffer, func_02092344 =
 * memcpy.  io_state values: 0 neutral, 1 writing, 2 reading, 3+ rereading.
 * LESSON: in this cluster, recognise the MSL routine and transcribe it; the
 * `zero` in r4 is 1.1p1's kept-constant habit and matches the image.
 */

#endif /* CLUSTER_02091588_H */
