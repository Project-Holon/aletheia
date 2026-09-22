/*
 * docs/families/cluster_02060550.h -- shared declarations for the
 * pseudo-family at 0x02060550..0x0206074C in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  Formed by address adjacency plus shared
 * callees, and it is in fact TWO things that sit next to each other:
 *
 *   A. 0x02060550..0x02060614 -- the SPLICE HALF of the doubly-linked list
 *      library whose insertion half is cluster_0205D1BC next door.  Insert
 *      before (func_02060550) and remove (func_020605B4), sharing the same
 *      `struct DList` / `struct DListNode` pair and the same `volatile`
 *      shape that header documents in full.  Do not re-derive it: READ
 *      docs/families/cluster_0205D1BC.h FIRST.
 *
 *   B. 0x02060614..0x0206074C -- the ARENA REGISTRY that uses that library.
 *      func_02060614 / func_0206062C are the head and tail walks and
 *      func_02060640 the recursive range query (all three byte-exact as one
 *      unit, src/matched/unit_02060614.c); func_020606A8 is the query's
 *      wrapper over the module-global root list; func_020606D0 is the arena
 *      constructor that registers a new arena under its enclosing one.
 *
 * Derived from the matched sources found with
 *   grep -l "address:  0x020605\|address:  0x020606\|address:  0x020607" \
 *        src/matched/*.c
 * and from the note docs/notes/dlist_ops.c.txt.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * dsi/1.1p1 (the project default) throughout.  Every byte-exact source here
 * carries `compiler: 1.1p1`, and `../2.0/sp2` was measured on this cluster's
 * one residue (func_020606D0) and is strictly worse -- 94 concrete bytes out
 * against 1.1p1's 90 on the same body, at the same size.  The SIBLING cluster
 * cluster_02060764 next door does contain one sp2-pinned function
 * (func_02060814); that pin belongs to the heap code, not to this list code,
 * and must not be carried across.
 *
 * ISA: ARM throughout.  Always pass `--arm`.
 * ============================================================================
 */

#ifndef CLUSTER_02060550_H
#define CLUSTER_02060550_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* struct DList and struct DListNode: see docs/families/cluster_0205D1BC.h.
   Repeated here only so this header stands alone. */
struct DList {
    void *head;             /* 0x00 */
    void *tail;             /* 0x04 */
    u16   count;            /* 0x08 */
    u16   node_offset;      /* 0x0a */
};

struct DListNode {
    void *prev;             /* 0x00 */
    void *next;             /* 0x04 */
};

/* ================================================================== *
 * 1.  struct Arena -- the registered memory arena, 0x24+ bytes
 *
 * Field evidence, one instruction per line, all from func_020606D0 unless
 * noted:
 *   +0x00  lo, the arena's low bound.  `str r1, [r4]`, the first parameter.
 *          func_02060640's range query reads the SAME word as its `min_val`
 *          (src/matched/unit_02060614.c calls the view `struct Elem`), which
 *          is what makes the registry an interval tree over the arenas.
 *   +0x0c  the embedded child DList, twelve bytes.  `add r0, r4, #0xc` is
 *          handed straight to func_02060468 with a node_offset of 4, so
 *          the LINK PAIR of a child arena lives at its own +0x04.  In
 *          unit_02060614's `struct Elem` view this same field is the
 *          `sublist` the recursive query descends into.
 *   +0x18  parent (or a second bound).  `str r2, [r4, #0x18]`, the second
 *          parameter.  func_02060814 reads it back as the heap's `lo`.
 *   +0x1c  hi, the arena's high bound.  `str r3, [r4, #0x1c]`, the third
 *          parameter, and func_02060814 reads it back as the heap's `hi`.
 *          unit_02060614's `max_val`.
 *   +0x20  attr.  Built as `mov ip, #0` / `bic r1, ip, #0xff` /
 *          `orr r2, r1, r0` from the stack parameter masked to `& 0xff`:
 *          a CLEAR-THEN-SET pair on a byte field of a word, not a plain
 *          assignment.  The stack parameter is loaded `ldrh [sp, #8]`, so
 *          the fifth argument is a u16 and not a u32.
 * ================================================================== */
struct Arena {
    void        *lo;            /* 0x00  low bound / interval min            */
    u8           pad_04[0x08];  /* 0x04  includes the element's own link pair
                                          at +0x04 (node_offset 4)           */
    struct DList children;      /* 0x0c  child arenas                        */
    void        *parent;        /* 0x18                                      */
    void        *hi;            /* 0x1c  high bound / interval max           */
    u32          attr;          /* 0x20  low byte set, rest cleared          */
};

/* ================================================================== *
 * 2.  Data objects
 * ================================================================== */

/* The registry's init-once latch and its root list, the two pool words at
   0x02060744 and 0x02060748.  func_020606D0: `if (g_02146B60 == 0) {
   func_02060468(&g_02146B64, 4); g_02146B60 = 1; }`.  func_020606A8 (EXACT,
   src/matched/func_020606A8.c) takes &g_02146B64 as the root of the range
   query and returns either that root's list or the found arena's child list
   at +0x0c, which is the `v + 0xc` in its own source. */
extern u32          g_02146B60;     /* 0x02146B60 -- registry init latch     */
extern struct DList g_02146B64;     /* 0x02146B64 -- root arena list         */

/* ================================================================== *
 * 3.  Prototypes, with the exact parameter types the matched sources use
 * ================================================================== */

/* 0x02060550  EXACT (src/matched/func_02060550.c).  Insert `elem` immediately
   BEFORE `before`.  A null `before` means "no successor", i.e. append at the
   tail; a `before` that is already the head is a prepend. */
extern void func_02060550(volatile struct DList *list, void *before, void *elem);

/* 0x020605B4  EXACT (src/matched/func_020605B4.c).  Unlink `elem` and clear
   its own link pair.  The image if-converts BOTH end cases
   (`ldreq`/`streq` against `ldrne`/`strne`); plain if/else gets that for
   free, no goto or ternary is needed. */
extern void func_020605B4(volatile struct DList *list, void *elem);

/* 0x02060614, 0x0206062C, 0x02060640  EXACT as one unit
   (src/matched/unit_02060614.c).  Head walk, tail walk, recursive range
   query.  func_02060640 returns the INNERMOST arena containing `val`. */
extern void *func_02060614(struct DList *list, void *elem);
extern void *func_0206062C(struct DList *list, void *elem);
extern struct Arena *func_02060640(struct DList *list, u32 val);

/* 0x020606A8  EXACT (src/matched/func_020606A8.c).  The range query over the
   module-global root: returns the found arena's CHILD LIST, or the root list
   itself when nothing contains the address.  This is the list a new arena is
   registered into, which is how the registry nests. */
extern void *func_020606A8(u32 addr);

/* 0x020606D0  open, residue at 90 concrete bytes / 8 short under 1.1p1.
   The arena constructor: fill the header, initialise the child list, create
   the root list once, then register this arena in the list func_020606A8
   picks for its own low bound.  ARGUMENT ORDER IS EVIDENCED, not guessed --
   func_02060814's `mov r3, r1` / `ldr r1, [pc]` pair puts ITS second
   parameter in the FOURTH slot here and a pooled signature word in the
   SECOND, so the call is (arena, signature, self + 0x38, lo, attr) and the
   fifth argument is the u16 the `ldrh [sp, #8]` reads. */
extern void func_020606D0(struct Arena *a, void *sig, void *self, void *lo,
                          u16 attr);

/* 0x02060468, 0x02060480  see docs/families/cluster_0205D1BC.h. */
extern void func_02060468(struct DList *list, u16 node_offset);
extern void func_020604AC(volatile struct DList *list, void *elem);

#endif /* CLUSTER_02060550_H */
