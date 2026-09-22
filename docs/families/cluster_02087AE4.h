/*
 * docs/families/cluster_02087AE4.h -- shared declarations for the
 * pseudo-family at 0x02087AE4..0x02091284 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry, written
 * down once so a new attempt on an open function starts from the settled shape
 * instead of re-deriving it.
 *
 * ============================================================================
 * WHAT THIS IS.  READ THIS FIRST -- IT IS NOT GAME CODE.
 * ============================================================================
 *
 * Unlike every other pseudo-family in the upper half, this cluster is not a
 * recovered game translation unit and it is not even mostly this project's C.
 * The range 0x02087AE4..0x02091284 is the TwlSDK STATIC LIBRARY TAIL of the
 * ARM9 module: the linked-in archive members of libos, libpxi, librtc, libsnd,
 * libspi, libscfg, libstd, libwm, libnwm and libctrdg, laid out in archive
 * order.  layout/symbols_sdk.txt names ~280 symbols inside this range, one per
 * library entry point, with the archive member each came from.
 *
 * Three consequences that matter before writing any C here:
 *
 *   1. THE SUBSYSTEM IS "the SDK", not one subsystem.  Reading a struct out of
 *      one function here tells you nothing about its neighbour, because the
 *      neighbour is a different library.  The address ranges, from
 *      layout/symbols_sdk.txt:
 *
 *        0x02087A04..0x020883D4   libos     os_system / os_systemwork /
 *                                           os_reset / os_ownerinfo{,ex} /
 *                                           os_argument / os_entropy /
 *                                           os_terminate / os_event
 *        0x020884A4..0x02088688   libpxi    pxi_fifo.o
 *        0x02088788..0x02089274   librtc    external / internal / convert
 *        0x02089330..0x0208A674   libsnd    snd_interface / snd_main /
 *                                           snd_command / snd_alarm /
 *                                           snd_work / snd_util / snd_bank
 *        0x0208A6B0..0x0208B7BC   libspi    tp.o, mic.o
 *        0x0208B7BC..0x0208C944   libspi    pm.o
 *        0x0208C960..0x0208C9C4   libscfg   scfg_proc.o
 *        0x0208CADC..0x0208D80C   libstd    std_string.o, std_sprintf.o
 *                                           + libos os_printf.o (interleaved)
 *        0x0208D834..0x0208E010   libstd    std_sprintf.o (STD_TVSNPrintf)
 *        0x0208E010..0x02090ED8   libwm     wm_system / wm_sync / wm_standard /
 *                                           wm_mp / wm_dcf / wm_ds / wm_ks /
 *                                           wm_etc / wm_common
 *        0x02090EF4..0x020911A0   libctrdg  ctrdg.o, ctrdg_proc.o
 *        0x020911D8..0x02091284   game glue + interworking veneers
 *
 *   2. EVERY OPEN FUNCTION HERE HAS A REAL NAME ALREADY.  Do not invent
 *      `func_0208XXXX`.  Look the address up in layout/symbols_sdk.txt first
 *      and use the SDK's own name for the C function; match.py resolves the
 *      name through layout/symbols_sdk.json, so the right name also buys the
 *      relocation its witness for free.
 *
 *   3. THE SEEDED ADDRESSES ARE NOT ALWAYS THE FUNCTION STARTS.  See the
 *      MIS-SEEDED LABELS section below.  Three of the ten open entries in this
 *      cluster were seeded four bytes into the body; all three became EXACT the
 *      moment they were written at the true entry.
 *
 * Derived from the 19 matched sources found with
 *   grep -l "address:  0x0208[7-9A-F]\|address:  0x02090\|address:  0x02091[0-2]" src/matched/*.c
 * from layout/symbols_sdk.txt, and from the notes docs/notes/pkt_02087FBC.c.txt,
 * docs/notes/pkt_0208B8B0.c.txt, docs/notes/pkt_020911D8.c.txt and
 * docs/notes/func_0209128C.c.txt.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  `ldrsb`/`ldrsh` prove signedness; a shift pair of
 * unequal amounts proves a bitfield's width and position.  Where a matched file
 * and the SDK's public header would disagree, the file whose code actually
 * constrains the field wins.
 *
 * ============================================================================
 * THE COMPILER PIN.  There is NO per-file pin in this cluster.
 * ============================================================================
 *
 * Every one of the 19 matched sources in the range carries
 * `compiler: 1.1p1`, and the three functions filed into this cluster in wave 7
 * (OS_SPrintf, STD_TSPrintf, OS_SNPrintf) are EXACT under the project default
 * too.  Unlike cluster_020737C0 there is no `../2.0/sp2` subset here: do not
 * spend a pass looking for one.  This is expected -- dsi/1.1p1 is the build the
 * SDK libraries were compiled with, and this range IS the SDK libraries, so it
 * is the one part of the image where the default compiler is not merely
 * calibrated but literally correct.
 *
 * ISA: ARM throughout, EXCEPT the game-glue tail at 0x020911D8..0x0209127x,
 * which is Thumb.  SDK library code is ARM by rule (docs/AGENT-BRIEF.md S2);
 * the tail is this project's own C calling into it, so it follows the ARM9
 * static module's Thumb convention and then interworks through veneers.
 * Pass `--arm` for anything at or below 0x020911D0 and `--thumb` above it.
 *
 * ============================================================================
 * MIS-SEEDED LABELS: THE VARARGS PROLOGUE.  This cost wave 7 its whole first
 * hour and closed three functions once seen.
 * ============================================================================
 *
 * A variadic SDK function opens with TWO pushes, not one:
 *
 *      0208D7E0  push {r0, r1, r2, r3}     <- the argument home area
 *      0208D7E4  push {r3, lr}             <- the ordinary frame
 *
 * The first is the `...` home area that makes `&fmt + 4` a real address (the
 * idiom docs/idioms/address-of-a-register-parameter-is-a-push-of-all-four.md).
 * `disasm.py` only auto-labels a prologue that saves `lr`, so it labels the
 * SECOND push and the worklist seeds the function four bytes late.  Three of
 * this cluster's ten open entries were exactly this:
 *
 *      seeded 0x0208CF38  ->  real entry 0x0208CF34  OS_SPrintf
 *      seeded 0x0208D7E4  ->  real entry 0x0208D7E0  STD_TSPrintf
 *      seeded 0x0208D810  ->  real entry 0x0208D80C  OS_SNPrintf
 *
 * All three are 40-44 byte forwarders and all three went EXACT first try once
 * written at the real entry.  The existing src/pending/func_0208CF38.c (status
 * corrected to DIFF, 9 bytes out) is not a hard function: it is the right C
 * compiled against the wrong four bytes.  If an entry in this range is small,
 * ARM, and its `show` opens with `push {r3, lr}` at the seeded address with a
 * `push {r0, r1, r2, r3}` in the word BEFORE it, subtract four and look the
 * address up in layout/symbols_sdk.txt.
 *
 * THE OTHER HALF OF THE SAME FINDING: the va_start alignment.  The image's
 * three instructions after the second push are
 *
 *      add r1, sp, #0xc          ; &fmt in the home area
 *      bic r1, r1, #3            ; round DOWN to a word boundary
 *      add r3, r1, #4            ; then step one word past it
 *
 * i.e. the SDK's va_start is `(char *)(((unsigned)&last & ~3u) + 4)`, mask
 * FIRST and add SECOND.  The naive `(char *)&last + sizeof(last)` (what
 * src/pending/func_0208CF38.c uses) drops the `bic` and is 4 bytes short; the
 * plausible `((unsigned)(&last + 1) & ~3u)` emits the add before the bic and
 * is byte-wrong in the same three instructions.  Only the mask-then-add order
 * reproduces.  Spell it exactly as in section 6 below.
 *
 * ============================================================================
 * THE TWO KNOWN WALLS IN THIS CLUSTER
 * ============================================================================
 *
 * func_02087FBC (176 B, ARM, OS_InitDeliverArgInfo's sibling).  Size wall:
 * every spelling compiles 188 bytes against 176.  The note
 * docs/notes/pkt_02087FBC.c.txt blamed the two 8-byte aggregate copies,
 * claiming mwcc will not emit a two-register `ldm`/`stm` below 12 bytes.
 * THAT PART OF THE NOTE IS WRONG and wave 7 corrected it: a bare `u64` copy
 * emits exactly `ldm r1,{r2,r3}` / `stm r0,{r2,r3}`.  What the note actually
 * tested was `struct { u64 v; }`, a STRUCT WRAPPING a u64, which goes back to
 * ldr/ldr/str/str.  Use the bare `u64`.  The residue that remains after that
 * fix is 12 bytes of reloaded `base[2]`, not the copies.
 *
 * func_0208B8B0 (160 B, ARM, MicCommonCallback's neighbour in pm.o).  Pure
 * allocation tie, 9 concrete bytes, size-exact: mwcc puts the address of
 * g_02153000 in r1 and the loaded halfword in r0, the image the other way
 * round.  The body in docs/notes/pkt_0208B8B0.c.txt is settled and correct.
 * One thing in that note IS now stale: it reports the pool word func_0208B950
 * as an unresolvable MATCH cap.  Since sole-ref/code widened (2026-09-21) that
 * site resolves `[sole-ref x1]`, and the only unresolved site left is the data
 * word g_02FFF684.
 *
 * ============================================================================
 * THE FOUR TAIL ENTRIES ARE VENEERS, NOT FUNCTIONS
 * ============================================================================
 *
 * 0x020911F0, 0x02091220, 0x0209124C (2 bytes each as seeded, 16 as laid out)
 * are Thumb-to-ARM long-branch interworking veneers:
 *
 *      78 47        bx pc                     ; enter ARM state
 *      c0 46        mov r8, r8                ; alignment nop
 *      00 c0 9f e5  ldr ip, [pc]              ; the ARM stub proper
 *      1c ff 2f e1  bx ip
 *      .word <target | 1>
 *
 * and 0x02091284 (4 bytes) is the bare ARM form `ldr pc, [pc, #-4]; .word
 * target`.  Their targets are 0x02731755, 0x02731761, 0x02731765 and
 * 0x02731920 -- ALL OUTSIDE the ARM9 static module, in overlay address space.
 * None of the four is compiled C, none can be written as C, and no `tu` range
 * may span one (docs/idioms/a-four-byte-arm-function-in-a-thumb-packet-is-a-
 * long-branch-veneer.md).  They are the linker's own output.  They are also
 * already covered as evidence: match.py's `veneer` class reads them from
 * outside any compared range, which is exactly how src/matched/func_02091200.c
 * and func_02091230.c resolve their calls to 0x02091220 and 0x0209124C.
 * Treat all four as CLOSED-not-matchable and do not spend budget on them.
 *
 * ============================================================================
 * SUMMARY OF THE TEN OPEN ENTRIES, adjudicated
 * ============================================================================
 *   0x02087FBC  160 B  real function, SIZE wall (12 B), see above
 *   0x02088498    8 B  VENEER to PXI_InitFifo (0x020884A4); src/pending has it
 *                      at MATCH*, blocked because the veneer's own target is
 *                      the next function and nothing else branches there
 *   0x0208B8B0  144 B  real function, DIFF wall (9 B allocation tie)
 *   0x0208CF38   36 B  MIS-SEEDED -> OS_SPrintf   @ 0x0208CF34  [EXACT wave 7]
 *   0x0208D7E4   40 B  MIS-SEEDED -> STD_TSPrintf @ 0x0208D7E0  [EXACT wave 7]
 *   0x0208D810   36 B  MIS-SEEDED -> OS_SNPrintf  @ 0x0208D80C  [EXACT wave 7]
 *   0x020911F0    2 B  VENEER, overlay target, not C
 *   0x02091220    2 B  VENEER, overlay target, not C
 *   0x0209124C    2 B  VENEER, overlay target, not C
 *   0x02091284    4 B  VENEER, overlay target, not C
 *
 * So of ten "open" entries: three were mis-seeded labels and are now EXACT,
 * five are linker veneers that are not compiled C at all, and exactly TWO are
 * real open functions, both of them documented walls.  The 434-byte figure in
 * the worklist overstates the available ground by about an order of magnitude.
 * ============================================================================
 */

#ifndef CLUSTER_02087AE4_H
#define CLUSTER_02087AE4_H

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;
typedef signed   char      s8;
typedef signed   short     s16;
typedef signed   int       s32;

/* ================================================================== *
 * 0.  Data objects
 * ================================================================== */

/* The delivery-argument / boot-parameter control block.  func_0208806C and
   func_02087FBC both reach it as a plain u32 array at the literal 0x02151384
   (NOT a relocation -- the address is materialised as a pool word and used as
   a constant), and both read the same three slots:
     [1]  a flag word; bit 0 is "armed" (`tst r0,#1` in func_02087FBC,
          `base[1] = 1` at the tail of func_0208806C)
     [2]  the pointer to the 0x300-byte scratch buffer everything else works on
   Declared as an array rather than a struct because that is how both matched
   files spell it and how they stay byte-exact. */
#define DELIVER_ARG_BASE  ((u32 *)0x02151384)

/* The 8-byte pair at 0x02151390 that func_02087FBC stores the buffer head
   into.  It is DELIVER_ARG_BASE + 0x0c, and naming it separately is what lets
   the copy stay an ldm/stm pair instead of folding to two str's off r4 -- see
   the second residue in docs/notes/pkt_02087FBC.c.txt.  No `literal` witness
   exists for it, so it is currently unresolvable on its own. */
extern u64 g_02151390;                  /* 0x02151390 -- a2 minimum, a4 in use */

/* The system shared-work area.  func_02087FBC reads a halfword at +0x000 and
   an 8-byte pair at +0x220.  The image reaches the pair with `add r1, r0,
   #0x220` off the SAME pool word as the halfword, so this is ONE object, not
   two: ARM's ldr immediate reach is +-4095 and 0x220 is well inside it, unlike
   the Thumb case in docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset
   -masked-by-the-load-reach.md.  Splitting it into two externs costs the file
   a second pool word and 4 bytes. */
struct SysWork {
    u16 f000;                   /* 0x000  copied to buffer + 0x0a             */
    u8  pad_002[0x220 - 2];
    u64 f220;                   /* 0x220  the ldm/stm source pair             */
};
extern struct SysWork g_02FFE010;       /* 0x02FFE010                         */

/* The mic/pm module object func_0208B8B0 initialises.  Only the five fields
   the function touches are constrained; f00 is read with `ldrh`, which is what
   makes it u16 and not u32. */
struct MicWork {
    u16 f00;                    /* 0x00  init-once latch, ldrh/strh           */
    u8  pad_02[0x0a];
    u32 f0c;                    /* 0x0c  \ both written from g_02FFFC3C       */
    u32 f10;                    /* 0x10  /                                    */
    u8  pad_14[0x1c];
    u32 f30;                    /* 0x30  zeroed at init                       */
    u32 f34;                    /* 0x34  zeroed at init                       */
};
extern struct MicWork g_02153000;       /* 0x02153000                         */
extern u32 g_02FFF684;                  /* 0x02FFF684 -- zeroed at init; the
                                           one site with no witness in B8B0   */
extern u32 g_02FFFC3C;                  /* 0x02FFFC3C -- the value both f0c
                                           and f10 are set from              */

/* The singleton pointer func_0208A054 reads twice across a call.  The re-read
   is load-bearing: caching the object pointer loses the second `ldr r0,[r4]`. */
struct SndInfoObj { u32 f00; u32 f04; };
extern struct SndInfoObj *g_02152FA0;   /* 0x02152FA0                         */

/* func_0208E4BC's target -- WM's status block pointer, at +0x04. */
struct WmStatusSlot { void *pad0; void *val; };
extern struct WmStatusSlot data_02153058;   /* 0x02153058                     */

/* func_0209128C's byte flag.  One pool word image-wide (the one inside that
   function), so it has no outside witness of any class. */
extern u8 addr_02153B88;                /* 0x02153B88                         */

/* ================================================================== *
 * 1.  The variadic forwarders -- the shape that closed three functions
 *
 * All four printf-family entry points in this cluster are the same 10-line
 * forwarder and differ only in which worker they call and what they pass for
 * the bound.  Spell va_list and va_start EXACTLY as below: the mask-then-add
 * order is what reproduces `bic` then `add`, and any other order or any use of
 * `sizeof(last)` is byte-wrong in the first three instructions of the body.
 * ================================================================== */

typedef char *va_list;
#define va_start(v, l) ((v) = (char *)(((unsigned int)&(l) & ~3u) + 4))
#define va_end(v)

/* The two workers.  Neither is open; both are large (1840 B and 2012 B). */
extern int STD_TVSScanf (char *dst, const char *fmt, va_list vlist);
                                        /* 0x0208CFD8.  layout/symbols_sdk.txt
                                           calls it STD_TVSScanf, but its one
                                           caller passes (dst, fmt, va_list)
                                           and is a *printf*: the SDK table's
                                           name for this address looks wrong.
                                           The address is what matters.       */
extern int STD_TVSNPrintf(char *dst, int n, const char *fmt, va_list vlist);
                                        /* 0x0208D834                         */

/* The bound STD_TSPrintf passes for "unbounded".  The image materialises it as
   `mvn r1, #0x80000000`, i.e. INT_MAX, not UINT_MAX -- so the worker's second
   parameter is signed int, not size_t. */
#define STD_PRINTF_UNBOUNDED  0x7FFFFFFF

extern int OS_SPrintf  (char *dst, const char *fmt, ...);   /* 0x0208CF34     */
extern int STD_TSPrintf(char *dst, const char *fmt, ...);   /* 0x0208D7E0     */
extern int OS_SNPrintf (char *dst, int n, const char *fmt, ...); /* 0x0208D80C */

/* ================================================================== *
 * 2.  Prototypes -- the SDK entry points this cluster's own code calls
 *
 * Parameter types are the ones the matched sources fixed, not the ones the
 * public TwlSDK headers declare; where they differ, the matched file wins.
 * ================================================================== */

/* --- libos -------------------------------------------------------------- */
extern void func_02087988(void);                    /* 0x02087988  OS_DisableIrq-ish:
                                                       returns a token in the
                                                       image's other callers   */
extern void func_0208799C(u32 token);               /* 0x0208799C              */
extern int  func_02088150(void);                    /* 0x02088150  OS_IsValidDeliverArg */
extern void func_02088234(void);                    /* 0x02088234  OS_Terminate */
extern void func_020882D0(void);                    /* 0x020882D0  OS_Halt      */

/* --- libpxi ------------------------------------------------------------- */
extern void func_02088498(void);                    /* 0x02088498  the VENEER  */
extern void func_020884A4(void);                    /* 0x020884A4  PXI_InitFifo */
extern void func_020885A0(int chan, void *handler); /* 0x020885A0  PXI_SetFifoRecvCallback */
extern int  func_020885EC(int chan, int b);         /* 0x020885EC  PXI_IsCallbackReady */

/* --- libsnd ------------------------------------------------------------- */
extern int  func_02089804(int code, u32 a, u32 b, u32 c, u32 d);
                                                    /* 0x02089804  PushCommand_impl;
                                                       FIVE args, the fifth via
                                                       the stack, which is what
                                                       makes the frame push
                                                       {r3, lr}                */

/* --- the DMA / memory layer these call into ----------------------------- */
extern void func_02082D44(u32 bus, u32 p, u32 n);   /* 0x02082D44  cache op    */
extern void func_02082BCC(u32 p, u32 c, u32 n);     /* 0x02082BCC  fill        */
extern u32  func_02004632(u32 seed, u32 p, u32 n);  /* 0x02004632  CRC16; THUMB,
                                                       reached by BLX.  Declare
                                                       it at 0x02004632, not
                                                       0x02004630: match.py
                                                       rewrites BL against BLX
                                                       from the declared ISA and
                                                       the even address leaves
                                                       the H bit wrong.        */
extern void func_02004490(int n);                   /* 0x02004490  spin/delay;
                                                       THUMB, reached by BLX   */
extern void func_020862B8(void *p, u32 n);          /* 0x020862B8              */

/* --- this cluster's own ------------------------------------------------- */
extern void func_02087AE4(void);                    /* 0x02087AE4              */
extern int  func_02087EA0(u32 x);                   /* 0x02087EA0  clz, written
                                                       as inline asm -- a
                                                       pycparser-unparseable
                                                       body, so permuter.py
                                                       cannot be run on it     */
extern int  func_02087FBC(void);                    /* 0x02087FBC  OPEN, SIZE  */
extern int  func_0208806C(void);                    /* 0x0208806C              */
extern void func_020882C0(void);                    /* 0x020882C0              */
extern void func_0208B8B0(void);                    /* 0x0208B8B0  OPEN, DIFF  */
extern u32  func_0208A054(void);                    /* 0x0208A054              */
extern void *func_0208E4BC(void);                   /* 0x0208E4BC              */
extern void func_0208B950(void);                    /* 0x0208B950  PMi_CommonCallback;
                                                       the handler B8B0 installs */

/* --- the Thumb game-glue tail ------------------------------------------- */
extern u32  func_02085D88(void);                    /* 0x02085D88  ARM         */
extern void func_020911D8(u32 a, u32 b, u32 c, u32 d);  /* 0x020911D8  thumb   */
extern void func_02091200(u32 a, u32 b, u32 c);     /* 0x02091200  thumb       */
extern void func_02091230(u32 a, u32 b);            /* 0x02091230  thumb       */
extern void func_0209128C(int x);                   /* 0x0209128C  ARM, DIFF   */

/* The veneers.  Declared so a caller can name them, never defined in C. */
extern void veneer_020911F0(void);      /* -> 0x02731754 thumb (overlay)      */
extern void veneer_02091220(void);      /* -> 0x02731760 thumb (overlay)      */
extern void veneer_0209124C(void);      /* -> 0x02731764 thumb (overlay)      */
extern void veneer_02091284(void);      /* -> 0x02731920 arm   (overlay)      */

/* ================================================================== *
 * 3.  Constants
 * ================================================================== */
#define DELIVER_BUF_SIZE    0x300   /* func_02087FBC, func_0208806C           */
#define DELIVER_CRC_SEED    0xffff  /* func_02004632's first argument         */
#define MAIN_MEM_BASE       0x02000000  /* func_02082D44's bus argument       */
#define PXI_CHAN_MIC        8       /* func_0208B8B0's channel                */
#define SYSWORK_PAIR_OFF    0x220   /* g_02FFE010.f220                        */

#endif /* CLUSTER_02087AE4_H */
