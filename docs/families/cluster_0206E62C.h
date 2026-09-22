/*
 * docs/families/cluster_0206E62C.h -- shared declarations for the
 * pseudo-family at 0x0206E62C..0x0206E954 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  A KEYED-RECORD CONTAINER: a lookup table
 * of fixed-size records addressed by a 16-BYTE (128-bit) key.  Three members,
 * and the two open ones are THE SAME FUNCTION differing only in what they
 * return:
 *
 *   func_0206E62C  448 B  look a key up, return the VALUE POINTER  (OPEN)
 *   func_0206E7EC  360 B  look a key up, return the INDEX          (OPEN)
 *   func_0206E954    ~20 B  reach the sub-header                   (EXACT)
 *
 * The cluster is small and evidence-thin: only func_0206E954 is matched, and
 * it is a one-liner.  Write the two open ones against the IMAGE, not against
 * sibling C; there is almost none.  See docs/notes/pkt_0206E62C.c.txt for the
 * measured ladder and the standing residue.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains
 * a field; a name does not.
 *
 * ============================================================================
 * THE COMPILER.  This cluster is NOT pinned: `1.1p1`, the project default.
 * ============================================================================
 *
 * func_0206E954 is EXACT under dsi/1.1p1 with plain `-O4,p`, and both open
 * functions were measured under 1.1p1 this pass (size-exact at 448/448 and
 * DIFF).  There is no "kept branches" or "kept constants" tell anywhere in
 * the range and no reason to reach for `../2.0/sp2` here.  Do not sweep it.
 *
 * ISA: ARM throughout.  Always pass `--arm`.
 * ============================================================================
 */

#ifndef CLUSTER_0206E62C_H
#define CLUSTER_0206E62C_H

typedef signed int         s32;
typedef unsigned int       u32;
typedef unsigned short     u16;
typedef unsigned char      u8;

/* ================================================================== *
 * 1.  struct Tbl -- the container header
 *
 * Field evidence, one instruction per line:
 *   +0x01  the RECORD COUNT, a u8 (`ldrb r5, [r0, #1]` at 0x0206E63C).  It is
 *          both the strategy selector (`cmp r5, #0x10`) and the linear scan's
 *          bound.  It is RE-READ from memory inside the loop
 *          (`ldrb r6, [r0, #1]` at 0x0206E6E4) even though r5 still holds it:
 *          each inlined accessor carries its own guard and each guard loads
 *          the field fresh.  Hoisting it into one local loses those loads.
 *   +0x06  the SUB-HEADER OFFSET, a u16 (`ldrh r6, [r0, #6]`), added to the
 *          container base to reach the sub-header.  func_0206E954 reads the
 *          same shape at +0x0c of ITS argument, so the +0x06 spelling is
 *          specific to this container, not universal.
 *   +0x08  where the TRIE starts, when there is one (`add r4, r0, #8`).
 *          It overlaps pad02[]; the trie and the scan path are alternative
 *          readings of the same bytes, selected by the count.
 * ================================================================== */
typedef struct {
    u8  pad00;
    u8  count;              /* 0x01  record count; >= 0x10 selects the trie  */
    u8  pad02[4];           /* 0x02  the trie lives at +0x08, inside this    */
    u16 sub_off;            /* 0x06  offset to the sub-header                */
} Tbl;

/* The sub-header, at (u8 *)t + t->sub_off.  Two u16s then the records.
 *   +0x00  the RECORD STRIDE (`ldrh r2, [r0, r3]` then `mla r0, r2, r1, r0`)
 *   +0x02  the offset from the SUB-HEADER to the key array
 *          (`ldrh r6, [r8, #2]` / `add r6, r8, r6`)
 *   +0x04  the first record
 * The value pointer is therefore  sub + 4 + stride * index,  and the key
 * pointer is  sub + keys_off + (index << 4).
 */
typedef struct {
    u16 stride;             /* 0x00  bytes per record                        */
    u16 keys_off;           /* 0x02  sub-header -> key array                 */
    u8  records[4];         /* 0x04  first record                            */
} Sub;

/* ================================================================== *
 * 2.  The key, and why it is four locals and not a struct
 *
 * The key is 16 bytes, four words, and the image loads all four in ONE
 * instruction at 0x0206E648:
 *
 *     0c 50 91 e8   ldm r1, {r2, r3, ip, lr}
 *
 * and compares them with a `cmp` / `ldreq` / `cmpeq` chain, so a mismatch in
 * the first word costs one compare and the rest are never loaded.
 *
 * DO NOT DECLARE IT AS A STRUCT AND COPY IT BY VALUE.  That does produce the
 * four-word `ldm`, but the aggregate assignment then gives the function a
 * stack frame and an `ldm`/`stm` pair into it (measured at 524 bytes against
 * 448; docs/idioms/aggregate-assignment-is-ldm-stm.md).  The image has NO
 * frame -- its prologue is `push {r4, r5, r6, r7, r8, lr}` and nothing else.
 * The four words are four separate `u32` LOCALS that the allocator coalesces
 * into consecutive registers; getting r2/r3/ip/lr assigned is the cluster's
 * standing residue and is a DECLARATION-ORDER problem.
 * ================================================================== */
typedef const u32 *Key;     /* a pointer to four words, never dereferenced
                               as an aggregate                              */

/* ================================================================== *
 * 3.  The Patricia trie, taken when count >= 0x10
 *
 * Four bytes per node, based at (u8 *)t + 8, indexed by node number:
 *   +0x00  this node's BIT INDEX
 *   +0x01  the child taken when the key bit is 0
 *   +0x02  the child taken when the key bit is 1
 *   +0x03  the RECORD INDEX this node stands for
 *
 * The descent loop is `while (parent_bit > child_bit)`, i.e. it runs while
 * the bit index keeps increasing and stops on the first back-pointer -- the
 * standard Patricia termination test, `cmp r2, r7` / `bhi` at
 * 0x0206E718/0x0206E74C.  The key bit is extracted as
 *
 *     (key[b >> 5] >> (b & 0x1f)) & 1
 *
 * which is the `asr #5` / `ldr [r1, r2, lsl #2]` / `and #0x1f` / `lsr` /
 * `and #1` quintet at 0x0206E720..0x0206E730.  Note the SHIFT IS RIGHT BY
 * `b & 0x1f`, not left: the bit numbering is little-endian within the word.
 *
 * The descent narrows to exactly one candidate and then the FULL key is
 * compared, because a Patricia trie only narrows and never proves.  Both the
 * scan path and the trie path therefore end in the same four-word compare
 * chain, written out twice in the image.
 * ================================================================== */
typedef struct {
    u8 bit;                 /* 0x00                                          */
    u8 child0;              /* 0x01                                          */
    u8 child1;              /* 0x02                                          */
    u8 index;               /* 0x03                                          */
} TrieNode;

/* ================================================================== *
 * 4.  Constants
 * ================================================================== */
#define TBL_TRIE_MIN    0x10    /* count >= this selects the trie            */
#define TBL_TRIE_OFF    8       /* (u8 *)t + 8 is the trie base              */
#define TBL_KEY_BYTES   0x10    /* the key is four words                     */
#define TBL_NODE_SIZE   4       /* one TrieNode                              */
#define TBL_REC_OFF     4       /* sub + 4 is the first record               */

/* ================================================================== *
 * 5.  Prototypes
 * ================================================================== */

/* Look `key` up.  Returns the record's ADDRESS, or 0 when the key is absent,
   when `key` is null, or when the container is empty.  OPEN, DIFF: size-exact
   at 448/448, 289 concrete bytes out.  See docs/notes/pkt_0206E62C.c.txt. */
extern void *func_0206E62C(const Tbl *t, Key key);

/* The same lookup returning the record's INDEX instead.  Every failure path
   returns -1 (`mvn r0, #0`), NOT 0 -- that is the only difference in the
   tail, and it is what makes this function 360 bytes to 62C's 448 (the
   value-pointer arithmetic, `ldrh`/`add`/`add`/`mla`, is absent).  OPEN. */
extern s32  func_0206E7EC(const Tbl *t, Key key);

/* Reach the sub-header of a container of the same family, whose sub-header
   offset is a u16 at +0x0C rather than +0x06.  EXACT; see
   src/matched/func_0206E954.c, which is a single return expression. */
extern int  func_0206E954(int p0, int p1, int p2, int p3);


/* ================================================================== *
 * WAVE 10 ADDENDUM (2026-09-22) -- BOTH OPEN ROWS NOW EXACT
 * ================================================================== *
 * func_0206E62C and func_0206E7EC are EXACT under ../2.0/sp2, NOT 1.1p1:
 * src/matched/func_0206E62C.c and src/matched/func_0206E7EC.c.  The section
 * "THE COMPILER" above is superseded.  The tell was not a push list: the
 * image keeps a SEPARATE +0x10 induction register for the scan's key pointer
 * (`add r4, r4, #0x10` beside `add r1, r1, #1`), i.e. `name_array + i` is
 * strength-reduced.  dsi/1.1p1 never does that (it emits
 * `add rN, base, i, lsl #4` and one fewer callee-saved register); 2.0 does.
 *
 * The code is NitroSystem g3d's resource dictionary (NNSG3dResDict):
 *   Tbl     = { u8 revision; u8 numEntry; u16 sizeDictBlk; u16 dummy_;
 *               u16 ofsEntry; TreeNode node[]; }
 *   Sub     = { u16 sizeUnit; u16 ofsName; u8 data[]; }  (entry header)
 *   Key     = struct { u32 val[4]; }  (NNSG3dResName)
 *   62C     = GetResDataByName, 7EC = GetResDictIdxByName.
 * The two accessors are `static inline` helpers (dict && idx < numEntry ?
 * ... : 0) and inline fine.  Levers that mattered: `u32 i` declared BEFORE
 * the four key words (else the four-word ldm splits); guard polarity
 * `dict != 0 && idx < numEntry` so the compute arm falls through; the trie
 * bit index SIGNED (asr #5).  The last 5 bytes (child index r3/r4 tie) were
 * closed by the permuter: re-spell the child expression in the `bit`
 * update instead of reading it back from `n`.
 */

#endif /* CLUSTER_0206E62C_H */
