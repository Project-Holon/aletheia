/*
 * docs/families/net.h -- shared declarations for the net.c family
 * (0x0203CBAC..0x0203D8AC in the ARM9 image).  The __FILE__ anchor these
 * functions load is 0x020A7CA0 and reads "net.c" (layout/file_anchors.txt
 * lists 0x0203CD88, 0x0203CEA4, 0x0203D344, 0x0203D4C4, 0x0203D6B0 and
 * 0x0203D6F4 as the loading sites).  Edges are fuzzy by a function or two
 * at both ends: net_state.c sits ahead of it and the tail past 0x0203D8AC
 * runs on into the next unit.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration below
 * is derived from a file in src/matched that is EXACT, and the matched
 * function that evidences each field or parameter is named in the comment
 * beside it.  Where two matched sources spell the same field differently
 * (they were written by different lanes), the spelling recorded here is the
 * one the byte evidence actually constrains.
 *
 * Addresses are Black-image addresses throughout (docs/AGENT-BRIEF.md
 * section 8).  Nothing here encodes a guess about the White layout.
 */

#ifndef NET_H
#define NET_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * THE MODULE BLOCK at 0x021469E0.
 *
 * This is the family's one global and the most-referenced address in it
 * (eleven matched sources name it).  It is NOT a pointer variable: it is a
 * small block, and the session pointer lives at +8.  Two distinct uses
 * appear in the matched sources and they are the same object:
 *
 *   *(u16 *)0x021469E0   a flag/id halfword read at +0.  func_0203CBAC
 *                        reads it with `ldrh r0, [r3]` and substitutes the
 *                        request's +0x54 when it is zero.
 *   *(void **)0x021469E8 the live session record.  func_0203D788 returns
 *                        exactly this (`return *(void **)(g + 8)`), and
 *                        func_0203CBAC publishes the freshly allocated
 *                        record into it.
 *
 * TRAP, recorded in docs/notes/pkt_0203CBAC.c.txt and worth repeating: the
 * +0 halfword read and the +8 store use the SAME pool word.  Declaring
 * them as two separate externs leaves the ABS32 site unresolved.  Declare
 * one object and reach both fields through it.
 *
 * A second global, 0x021469DC, is read by func_0203CB34 and stores a u16
 * at 0x021469E0 -- adjacent, but spelled separately by that lane.
 * ------------------------------------------------------------------ */
struct NetModule {
    u16 flag;           /* 0x00  func_0203CBAC's `ldrh r0, [r3]` guard */
    u8  pad_02[6];
    struct NetSession *session;
                        /* 0x08  func_0203D788 returns this; func_0203D798
                         * returns it with an explicit NULL test first */
};

extern struct NetModule g_021469E0;     /* 0x021469E0 */

/* func_0203D788 is THE accessor: every function in the family that needs
 * the session calls it rather than reading the global directly. */
extern void *func_0203D788(void);       /* 0x0203D788, src/matched */
extern void *func_0203D798(void);       /* 0x0203D798, NULL-checking form */

/* ------------------------------------------------------------------ *
 * struct NetSession -- the 0x354-byte record.
 *
 * Allocated by func_0203CBAC: func_02030734(req->f56, 0x354, 1,
 * file_020A7CA0, 0x6a), i.e. on the heap the REQUEST names, zero-filled,
 * at net.c line 0x6a.  Only the fields the matched sources actually touch
 * are named; the gaps are padding of the size the byte evidence forces.
 * ------------------------------------------------------------------ */
#define NET_SESSION_SIZE    0x354       /* func_0203CBAC's allocation size */

struct NetSession {
    u8  pad_000[0x340];
    u32 (**vtable)(void);   /* 0x340  seeded from func_0200F17C(req->f65);
                             * func_0203CBAC asserts it is non-NULL at line
                             * 0x6f.  func_0203CDD4 calls through it. */
    u8  pad_344[4];
    void (*cb348)(u32);     /* 0x348  optional callback, called with f34c as
                             * its argument by func_0203CDD4 when non-NULL.
                             * func_0203CEAC STORES its own caller's handle
                             * here (`str r5, [r4, #0x348]`), so the slot is
                             * written as a plain word in one function and
                             * called as a function pointer in the other. */
    u32 f34c;               /* 0x34c  the handle/context word; func_0203CBAC
                             * sets it from its third argument, func_0203CDD4
                             * passes it to both callbacks */
    u8  pad_350[2];
    u8  live;               /* 0x352  set to 1 by func_0203CBAC right after
                             * the allocation */
};

/* ------------------------------------------------------------------ *
 * struct NetRequest -- the caller-supplied request block.
 *
 * Confirmed field by field by func_0203CBAC, which copies 0x70 bytes of it
 * into the session with func_02082D44.  func_0203CDD4 reads the SAME
 * offsets (0x56/0x58/0x5a/0x65) out of the session record after that copy,
 * which is the evidence that the copy lands at offset 0 of the session.
 * ------------------------------------------------------------------ */
struct NetRequest {
    u32 f00;            /* 0x00  passed to func_0203A494; the `ldm sb,{r1,r2}`
                         * at 0x0203CD40 reads f00/f04 as one pair */
    u32 f04;            /* 0x04 */
    u8  pad_08[0x40];
    u32 f48;            /* 0x48  third argument of the vtable arm's
                         * func_0203064C */
    u8  pad_4c[8];
    u16 f54;            /* 0x54  the id used when the module flag is zero */
    u16 heap;           /* 0x56  THE HEAP ID: names the heap the session is
                         * allocated on (func_0203CBAC), and is passed on to
                         * func_0203AFCC, func_0203A494 and func_02037010 */
    u16 f58;            /* 0x58  or'd with 0x8000 in the vtable arm */
    u16 f5a;            /* 0x5a  the beacon arm's second argument */
    u16 f5c;            /* 0x5c  func_02037010's first argument */
    u16 f5e;            /* 0x5e  func_02037010's second argument */
    u8  pad_60[1];
    u8  beacon_len;     /* 0x61  asserted <= 0x80 at line 0x84 */
    u8  pad_62[3];
    u8  mode;           /* 0x65  THE MODE BYTE: drives the dense switch in
                         * both func_0203CBAC and func_0203CDD4, and selects
                         * the vtable via func_0200F17C */
    u8  pad_66[1];
    u8  f67;            /* 0x67  shifted left 8 into func_0203A494's first
                         * argument */
};

/* ------------------------------------------------------------------ *
 * THE MODE BYTE AND ITS DENSE SWITCH.
 *
 * Both big functions dispatch on the mode byte with the same construct,
 * `cmp rN, #6` + `addls pc, pc, rN, lsl #2`, and the two tables are laid
 * out the same way.  READ THE BASE CAREFULLY -- this cost two separate
 * lanes a pass each, and both notes in docs/notes/ were wrong about it
 * until 2026-09-22:
 *
 *     cmp   rN, #6
 *     addls pc, pc, rN, lsl #2
 *     b     <default>        <- the OUT-OF-RANGE fallthrough, NOT case 0
 *     b     <case 0>         <- the table actually starts HERE
 *
 * `addls pc, pc, ...` reads pc as the instruction address PLUS 8, so the
 * table base is (address of the addls) + 8 and entry k is at base + 4k.
 * Counting the first word as table[0] shifts every case by one and gives a
 * residue no source-level edit can reach: the arm blocks all land at the
 * right addresses and only the dispatch words differ.  A permuter run that
 * is completely flat over thousands of compiles is the tell.
 *
 * The error arm is reached by the fallthrough word, so it must be spelled
 * `default:` and never `case 0:`.
 * ------------------------------------------------------------------ */
#define NET_MODE_MAX        6       /* the `cmp rN, #6` bound in both */

/* ------------------------------------------------------------------ *
 * The __FILE__ anchor and the assert strings.
 *
 * func_02034714(file, line, msg) is the assert helper (its signature is
 * fixed by src/matched/func_02007374.c and two siblings).  Declare each
 * string as an extern pinned by address in symbols:, never as a literal
 * __FILE__; see docs/idioms/file-string-is-an-abs32-into-the-string-area.md.
 * ------------------------------------------------------------------ */
extern const char file_020A7CA0[];  /* 0x020A7CA0  "net.c" */
extern const char str_020A7CA8[];   /* 0x020A7CA8  line 0x6f, null vtable */
extern const char str_020A7CB8[];   /* 0x020A7CB8  line 0x84, beacon length */
extern const char str_020A7CE8[];   /* 0x020A7CE8  line 0x8e (func_0203CBAC)
                                     * and line 0xEE (func_0203CDD4) */

/* net.c line numbers seen in the matched sources */
#define NET_LINE_ALLOC      0x6A    /* func_0203CBAC's allocation */
#define NET_LINE_VTABLE     0x6F    /* func_0203CBAC, null vtable */
#define NET_LINE_BEACON     0x84    /* func_0203CBAC, beacon length > 0x80 */
#define NET_LINE_MODE       0x8E    /* func_0203CBAC, bad mode */
#define NET_LINE_MODE2      0xEE    /* func_0203CDD4, bad mode */

/* ------------------------------------------------------------------ *
 * CROSS-FAMILY CALLEES, with the ISA each one needs in symbols:.
 *
 * ISA IS NOT COSMETIC HERE.  func_0200F17C and func_0200F234 are THUMB and
 * are reached with `blx`; declaring either `arm` makes match.py refuse the
 * site outright with an ISA conflict rather than reporting a diff.
 * ------------------------------------------------------------------ */
extern void  func_0203064C(u32 a, u32 b, u32 c);        /* arm */
extern void *func_02030734(u32 heap, u32 size, u32 clear,
                           const char *file, u32 line); /* arm, the allocator */
extern void  func_020306F0(u32 a);                      /* arm */
extern void  func_020307B0(void *s);                    /* arm */
extern void  func_02034714(const char *file, u32 line,
                           const char *msg);            /* arm, assert */
extern void  func_02034FB8(u32 a);                      /* arm */
extern void  func_02037010(u32 a, u32 b, u32 c, u32 d); /* arm */
extern void  func_020370C8(void);                       /* arm */
extern void  func_02039834(struct NetSession *s);       /* arm */
extern void  func_020398B4(void *s);                    /* arm */
extern void  func_0203A494(u32 a, u32 b, u32 c, u32 d, u32 e);   /* arm */
extern void  func_0203AFCC(u32 heap, u32 a);            /* arm */
extern void  func_02082D44(void *dst, void *src, u32 n);/* arm, memcpy-like */
extern void *func_0200F17C(u32 mode);                   /* THUMB */
extern void  func_0200F234(u32 a);                      /* THUMB */

/* ------------------------------------------------------------------ *
 * THE 12-BYTE VENEERS, and why two identical-looking files disagree.
 *
 * The family's tail holds several `ldr ip,[pc]; bx ip; .word target` stubs.
 * They are compilable as a one-line tail call, but whether one can be filed
 * EXACT depends on whether disasm.py labelled the TARGET, which in turn
 * depends on whether the target's prologue saves lr
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md):
 *
 *   0x0203D7BC -> 0x0203C900  target pushes lr -> labelled -> EXACT
 *   0x0203D7B0 -> 0x0203C8E8  target saves none -> unlabelled -> MATCH
 *   0x0203CF04 -> 0x0203BFF0  target saves none -> unlabelled -> MATCH
 *   0x0203D56C -> 0x020394C0  target saves none -> unlabelled -> MATCH
 *
 * sole-ref/code accepts only an exact traced label start (or a recognised
 * veneer), checked against evidence().labels.  The three MATCH files are
 * byte-correct and capped for lack of a witness, not for lack of C; they
 * lift the moment their target is seeded into layout/function_starts.txt
 * (the integrator's file) or a second referrer is decompiled.
 * ------------------------------------------------------------------ */

#endif /* NET_H */
