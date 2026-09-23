/*
 * docs/families/cluster_02091AE8.h -- shared declarations for the
 * pseudo-family at 0x02091AE8..0x02092004 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  The upper half of the ARM9 image has no
 * __FILE__ anchors, so this cluster is NOT a recovered original translation
 * unit.  It was formed by address adjacency plus shared callees and data
 * objects, and it is the DIRECT CONTINUATION of the cluster documented in
 * docs/families/cluster_02091588.h: the same `struct File`, the same flag and
 * state words, the same g_02153FAC failure value.  READ THAT FILE FIRST; this
 * one records only what is specific to 0x02091AE8..0x02092004 and does not
 * repeat the struct or the bitfield views.
 *
 * WHAT THE SUBSYSTEM IS.  The POSITIONING half of MSL's buffered stdio, where
 * the previous cluster held the transfer half:
 *
 *   - func_02091CBC is the position query.  It rejects the object when the
 *     f04 bits 7..9 open mode is neither 0 nor 1 or when f0d is set (leaving
 *     0x28 in g_02153FAC and returning -1), returns the running f18 when the
 *     f08 three-bit state is 0, and otherwise f34 + (f24 - f1c) reduced by
 *     (state - 2) for states of 3 or more -- i.e. the buffered position with
 *     the pushback stack subtracted back off.  That is `ftell`.
 *   - func_02091E44 is the seek.  Its real entry is the `push {r0,r1,r2,r3}`
 *     home area at 0x02091E44 (see THE MIS-SEEDED LABEL below); it validates
 *     the object the same way, optionally commits through func_02091650,
 *     folds a relative request through func_02091CBC, decides whether the
 *     target is inside the live buffer window [f34, f18) and either retargets
 *     f24/f28 in place or invalidates the buffer, then calls the object's
 *     OPTIONAL +0x38 handler with the position BY ADDRESS.  That is `fseek`.
 *   - func_02091C40 is the bounded case-insensitive compare the mode-string
 *     parsing uses, the `strncmp` twin of src/matched/func_0209AB8C.c.
 *   - func_02091D38 and func_02092004 are two members of the refcounting
 *     wrapper family documented in docs/families/cluster_02091588.h section 2.
 *
 * Derived from the six matched sources found with
 *   grep -l "address:  0x02091[ABCDEF]\|address:  0x02092004" src/matched/*.c
 * and from the note docs/notes/pkt_02091D38.c.txt.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains
 * a field; a name does not.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * THERE IS NO PIN HERE.  Every byte-exact file in this cluster is EXACT under
 * the project default `dsi/1.1p1` with `-O4,p -proc arm946e`.  The alternative
 * has now been probed THREE times on this cluster's one stuck row
 * (func_02091E44) and refused every time; the two most recent, both at the
 * corrected entry 0x02091E44:
 *
 *     dsi/1.1p1     448 bytes,  12-28 concrete bytes out
 *     ../2.0/sp2    468 bytes, 107    concrete bytes out
 *
 * Both of func_02091E44's residues READ LIKE the "kept branches" and
 * "re-read versus forward" families docs/FRONTEND-PINS.md records for 2.0,
 * and the front end is nonetheless NOT 2.0 for this row.  DO NOT SPEND A
 * FOURTH PROBE.  This is the standing counter-example to the pin heuristic:
 * a 2.0-shaped tell in this neighbourhood is a codegen coincidence.
 *
 * ISA: ARM throughout.  Always pass `--arm`.
 *
 * ============================================================================
 * THE MIS-SEEDED LABEL AT 0x02091E44.  THE OTHER THING TO READ FIRST.
 * ============================================================================
 *
 * `match.py show --addr 0x02091E44` reports a FOUR-BYTE row decoding to one
 * instruction:
 *
 *     0x02091E44   0f 00 2d e9   push {r0, r1, r2, r3}
 *
 * It is NOT a stub and NOT a one-instruction function.  It is the argument
 * home area mwcc emits as the FIRST instruction of a function that takes the
 * address of a parameter -- here the +0x38 seek handler is handed `&pos` as
 * `add r1, sp, #0x14`.  `disasm.py` only auto-labels a prologue that saves
 * `lr`, and a home-area push saves none, so the label landed four bytes late
 * at 0x02091E48.  The real function entry is 0x02091E44.  This is the same
 * mis-seed docs/families/cluster_020929E8.h documents for 0x02092C38,
 * 0x02092F0C and 0x02093BDC, and it is confirmed here by compile: a source
 * compiled at 0x02091E44 reproduces the push and all three
 * `pop {r4,r5,r6,lr}; add sp, sp, #0x10; bx lr` epilogues exactly.
 *
 * CONSEQUENCES, all of them load-bearing:
 *
 *   1. Compile at the EARLIER address.  `--addr 0x02091E44`, never
 *      0x02091E48.  At the body label the home-area push shifts the whole
 *      function and the residue reads as 367 bytes out instead of 28, with a
 *      spurious register-substitution map that is pure misalignment artefact.
 *   2. TOOLS/PERMUTER.PY CANNOT SCORE THIS ROW, and its search is not merely
 *      unhelpful but INVERTED.  Its scorer takes the target size from
 *      `match.target_extent(addr)`, which is the mis-seeded 4.  `Score.key`
 *      then never takes its size-exact branch (that branch requires
 *      `size == tsize`) and ranks by `(asm, miss, abs(size - 4))`, so the
 *      size term rewards SHRINKING the function.  Measured 2026-09-22:
 *      `--mode hill --budget 800 --jobs 8 --types` reported a 400-byte /
 *      347-bytes-out variant as an improvement on the 448-byte /
 *      28-bytes-out baseline.  DO NOT RUN THE PERMUTER ON 0x02091E44 UNTIL
 *      THE SEED LANDS.
 *   3. FOR THE INTEGRATOR: 0x02091E44 is a SEED-FILE item.  It wants a seed
 *      at its own address in layout/function_starts.txt and the LATER label
 *      at 0x02091E48 removed.
 *   4. src/pending/func_02092004.c is capped at MATCH by this and nothing
 *      else: its sole wildcard is the PC24 to func_02091E44, whose only
 *      branch in the whole image is that one call, so no cut helps and only
 *      a `matched` entry at 0x02091E44 promotes it.
 * ============================================================================
 */

#ifndef CLUSTER_02091AE8_H
#define CLUSTER_02091AE8_H

/* struct File, the four F04 bitfield views and struct F08P are defined in
   docs/families/cluster_02091588.h and are NOT repeated here.  So are
   g_02153FAC, g_020A60DC and the whole wrapper-family data set
   (g_020A8730 / g_020A877C / g_020A87C8 / g_02153BD4 / g_02150FEC /
   arr_02153B8C / arr_02153BB0). */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef signed   int   s32;

/* ================================================================== *
 * 1.  What this cluster adds to struct File
 *
 * Only two fields are read here that the transfer half never touches, and
 * both belong to the seek:
 *   +0x38   the OPTIONAL seek handler.  Null means "this object cannot seek"
 *           and the seek then succeeds without calling anything.  It is
 *           invoked as a bare `blx ip` with four arguments, the second of
 *           which is `&pos` -- THE ADDRESS OF THE LOCAL COPY OF THE SECOND
 *           PARAMETER.  That address-taking is what puts the home-area push
 *           at 0x02091E44; see docs/idioms/
 *           address-of-a-register-parameter-is-a-push-of-all-four.md.
 *   +0x48   its fourth argument, the same dead-looking load the transfer
 *           half's handlers take.
 * ================================================================== */
typedef u32 (*FileSeekFn)(u32 a, u32 *pos, u32 whence, u32 d);

/* ================================================================== *
 * 2.  func_02091E44 -- the settled body, and every lever in it
 *
 * Four independent lanes have now transcribed this function and all four land
 * on the same 448 bytes.  The shape below is not a guess; it is what those
 * lanes converged on, and each bullet after it is worth four bytes or more.
 *
 *   s32 func_02091E44(struct File *p, u32 pos, u32 whence)
 *   {
 *       struct F08P *m08 = (struct F08P *)&p->f08;
 *       u8 mode;  u32 v;
 *
 *       mode = ((struct F04hiP *)&p->f04)->mode;
 *       if (mode != 1 || p->f0d != 0) { g_02153FAC = 0x28; return -1; }
 *       if (m08->mode == 1 && func_02091650(p, 0) != 0) {
 *           p->f0d = 1; p->f28 = 0; g_02153FAC = 0x28; return -1;
 *       }
 *       if (whence == 1) { whence = 0; pos += func_02091CBC(p); }
 *       if (whence != 2 && ((struct F04loP *)&p->f04)->mode != 3) {
 *           if (m08->mode - 2 <= 1) {
 *               if (pos < p->f18 && pos >= p->f34) {
 *                   u32 f08 = p->f08;
 *                   p->f24 = p->f1c + (pos - p->f34);
 *                   p->f28 = p->f18 - pos;
 *                   v = (f08 & ~7u) | 2;
 *                   goto stored;
 *               }
 *           }
 *       }
 *       v = p->f08 & ~7u;
 *   stored:
 *       p->f08 = v;
 *       if (((volatile struct F08P *)&p->f08)->mode != 0) goto done;
 *       if (p->f38 != 0 && p->f38(p->f00, &pos, whence, p->f48) != 0) {
 *           p->f0d = 1; p->f28 = 0; g_02153FAC = 0x28; return -1;
 *       }
 *       p->f0c = 0; p->f18 = pos; p->f28 = 0;
 *   done:
 *       return 0;
 *   }
 *
 * SEVEN LEVERS, each measured:
 *  1. THE f04 MODE IS NARROWED TO u8 BEFORE THE COMPARE.  The image is
 *     `lsl #0x16 / lsr #0x1d / and #0xff / cmp #1`.  Testing the bitfield
 *     inline without the u8 local drops the `and` and costs 4 bytes and 329
 *     mismatches -- the single most expensive line in the function.
 *  2. `whence = 0;` BEFORE `pos += func_02091CBC(p);`.  The reverse order
 *     puts the `mov r5, #0` after the `bl`.
 *  3. The f08 state is read through the `struct F08P` view.  `v8 & 7` and
 *     `(v8 << 29) >> 29` both fold to `and r0, ip, #7` where the image keeps
 *     the `lsl #0x1d` / `lsr #0x1d` pair.
 *  4. The final `return 0` is SHARED between the early-out and the
 *     fall-through: it must be `goto done;`, not a second `return 0`, or the
 *     `mov r0, #0` is written out twice.
 *  5. The f08 WRITE is ONE statement `p->f08 = v;` reached by `goto stored;`
 *     from both arms; the arms compute `v` and do not store.  Storing per arm
 *     loses the join at 0x02091F7C.
 *  6. The post-store test is a genuine RE-READ of the word just written and
 *     only `((volatile struct F08P *)&p->f08)->mode` reproduces it.  A plain
 *     `m08->mode` forwards `v`; `*(volatile u32 *)&p->f08 & 7u` gives
 *     `tst r0, #7`; binding the volatile read to a local spills `pos`.
 *  7. The in-window arm's statement order is `f24 store, f28 store, then v`.
 *     Every reordering measured is 32 bytes out or worse.
 *
 * THE 28-BYTE RESIDUE IS TWO COUPLED DECISIONS THAT TRADE AGAINST EACH OTHER
 * AND NO C SPELLING REACHES BOTH:
 *  (a) the image keeps the f08 word live in ip from `ldr ip, [r6, #8]` at
 *      0x02091F14 through `bic r0, ip, #7` at 0x02091F60, ACROSS the
 *      intervening `str r0, [r6, #0x24]`.  1.1p1 re-reads it.
 *  (b) the image writes the in-window failure out twice (`bhs 0x2091f48`
 *      reaching an unconditional `b 0x2091f74`, plus `bhs 0x2091f4c`);
 *      1.1p1 cross-jumps the pair to `bhs`/`blo` and drops the `b`.
 * Fixing (a) needs a const view that defeats the intervening store; ANY const
 * view that reaches the word enables the CSE that deletes (6)'s volatile
 * re-read, which costs exactly the 4 bytes (b) has already lost.  FIVE
 * const/volatile splits and NINE branch spellings have been measured across
 * four lanes and all collapse.  Do not re-measure them; the list is in
 * docs/notes/pkt_02091D38.c.txt.
 * ================================================================== */

/* ================================================================== *
 * 3.  Prototypes
 * ================================================================== */
struct File;
struct F08P;

extern u32 g_02153FAC;
extern const u8 g_020A60DC[];

extern u32  func_02091AE8(void);
extern u32  func_02091B5C(void);
extern int  func_02091C40(const u8 *s1, const u8 *s2, int n);  /* strncmp-ish */
extern u32  func_02091CBC(struct File *p);                     /* ftell       */
extern s32  func_02091D38(u32 id);                             /* wrapper     */
extern s32  func_02091E44(struct File *p, u32 pos, u32 whence);/* fseek       */
extern s32  func_02092004(u32 id, u32 a1, u32 a2);             /* wrapper     */

extern s32  func_02091650(struct File *p, u32 *out);
extern s32  func_020860D0(void *blk);
extern void func_02086028(void *blk);
extern void func_02086078(void *blk);

/* ================================================================== *
 * 4.  Constants
 * ================================================================== */
#define SEEK_SET_LIKE       0       /* whence 0: absolute                     */
#define SEEK_CUR_LIKE       1       /* whence 1: folded through func_02091CBC */
#define SEEK_END_LIKE       2       /* whence 2: skips the in-window path     */
#define ERR_VALUE           0x28    /* g_02153FAC on every failure path       */
#define HOME_AREA_ENTRY     0x02091E44  /* the REAL entry; 0x02091E48 is body */

/* ================================================================== *
 * 5.  WAVE 12 (2026-09-23): func_02091E44 CLOSED, EXACT*, dsi/1.1p1.
 *     src/matched/func_02091E44.c.  Section 2's settled body was wrong in
 *     two declarations, and they were the whole 28-byte residue:
 *       (a) f08 is a BITFIELD MEMBER of the struct and is ASSIGNED:
 *           `p->f08.mode = 2;` / `p->f08.mode = 0;`.  That is the
 *           `bic ip, #7 / orr #2` off the word the state test loaded, and the
 *           plain re-read after the store -- no volatile, no `v`/`goto stored`.
 *       (b) the window test is `if (pos >= f18 || pos < f34) mode = 0; else
 *           {...}`: the disjunction's THEN arm is the kept `b`.
 *     Section 2's SEVEN LEVERS 3, 5 and 6 are superseded by (a).  The
 *     permuter warning (the 4-byte listing extent) still stands until the
 *     seed lands; `match.py one` reports EXACT* against it.
 * ================================================================== */

#endif /* CLUSTER_02091AE8_H */
