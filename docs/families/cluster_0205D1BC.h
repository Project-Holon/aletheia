/*
 * docs/families/cluster_0205D1BC.h -- shared declarations for the
 * pseudo-family at 0x0205D1BC..0x02060550 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  It is the adjudicated union
 * of the declarations the cluster's byte-exact sources already carry.
 *
 * WHAT THIS IS A PSEUDO-FAMILY OF.  The upper half of the ARM9 image has no
 * __FILE__ anchors, so this cluster is NOT a recovered translation unit.  It
 * was formed by address adjacency plus shared callees.  Its members are the
 * INSERTION HALF of a generic DOUBLY-LINKED LIST library -- the NitroSDK
 * `NNS_FndList` shape -- whose iteration half sits immediately after it at
 * 0x02060614 (src/matched/unit_02060614.c, a tu-verified three-function unit)
 * and whose remove/splice half is cluster_02060550 next door.
 *
 * The one outlier is 0x0205D1BC itself, a four-byte `return ~5;` that the
 * packet cut happens to start at and that shares nothing with the rest; the
 * cluster's real body is 0x02060468..0x02060550.
 *
 * Derived from the matched sources found with
 *   grep -l "address:  0x0205D1BC\|address:  0x020604\|address:  0x020605" \
 *        src/matched/*.c
 * and from the note docs/notes/dlist_ops.c.txt.
 *
 * ADJUDICATION RULE USED THROUGHOUT.  A load or store instruction constrains a
 * field; a name does not.  The DList header's `ldrh [r0, #8]` / `ldrh [r0,
 * #0xa]` pair is what makes +0x08 and +0x0a two halfwords rather than one
 * word, and `str rX, [r1, r3]` with r3 the halfword at +0x0a is what makes
 * +0x0a a BYTE OFFSET applied to the element pointer rather than an index.
 *
 * ============================================================================
 * THE COMPILER PIN.  READ THIS BEFORE WRITING ANY C FOR THIS CLUSTER.
 * ============================================================================
 *
 * dsi/1.1p1 (the project default) throughout.  Every byte-exact source in
 * 0x0205D1BC..0x02060550 carries `compiler: 1.1p1`, and `../2.0/sp2` was
 * measured on the cluster's residues (func_020604AC, func_02060500) and is
 * strictly worse.  The SIBLING cluster_02060764 next door does contain one
 * sp2-pinned function (func_02060814); do not carry that pin across.
 *
 * ISA: ARM throughout.  This is unusual for game code (the ARM9 static module
 * is Thumb almost everywhere) and is itself a cluster property worth knowing:
 * always pass `--arm`.
 *
 * ============================================================================
 * THE `volatile` SHAPE.  THE SECOND THING TO READ.
 * ============================================================================
 *
 * EVERY list-mutating function in this cluster and the next takes its list
 * pointer as `volatile struct DList *`.  This is not decoration and it is not
 * a guess about the original's types; it is the only spelling that reproduces
 * the image, and the reason is mechanical:
 *
 *   The list functions all end `list->count = list->count + 1;` (or `- 1`).
 *   Without `volatile`, mwcc proves the count field cannot alias the element's
 *   own link words, HOISTS the `ldrh r1, [r0, #8]` above the head/tail stores,
 *   and thereby frees the element-pointer register (r1, dead after those
 *   stores) to hold the counter.  Every later register shifts by one.  The
 *   image reads the count LAST, in source order, and reuses r1 for it.
 *
 * Symptom to recognise instantly: a compile that is SIZE-EXACT with all
 * relocations right, whose residue `tools/permuter.py --explain` prints as a
 * single register substitution (`r1 -> r2 x1`) around the count update.  Add
 * the `volatile` and the function closes; func_02060480 is the evidencing
 * function and the permuter names the mutation itself (`volatile-add(list)`).
 * Qualifying the COUNT FIELD alone instead of the pointer does not work.
 * ============================================================================
 */

#ifndef CLUSTER_0205D1BC_H
#define CLUSTER_0205D1BC_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* ================================================================== *
 * 1.  struct DList -- the list header, 12 bytes
 *
 * Field evidence, one instruction per line:
 *   +0x00  head.  `ldr r2, [r0]` is the emptiness test at the top of
 *          func_020604AC and func_02060500, and the `str r1, [r0]` at the
 *          end of func_02060500 is the prepend.
 *   +0x04  tail.  `ldr r3, [r0, #4]` in func_020604AC, `str r1, [r0, #4]`
 *          in func_02060480 and func_020604AC.
 *   +0x08  count, a HALFWORD: `ldrh r1, [r0, #8]` / `add r1, r1, #1` /
 *          `strh r1, [r0, #8]` in func_02060480, and the matching `sub` in
 *          func_020605B4.  Never read as a word anywhere in the cluster.
 *   +0x0a  node_offset, a HALFWORD used as a BYTE OFFSET on the ELEMENT:
 *          `ldrh r3, [r0, #0xa]` then `str r2, [r1, r3]` -- r1 is the
 *          element and r3 scales by one, so this is `(char *)elem + off`
 *          and not an index.  func_02060468 writes it from its second
 *          parameter; func_020606D0 and func_02060814 both pass 4.
 * ================================================================== */
struct DList {
    void *head;             /* 0x00 */
    void *tail;             /* 0x04 */
    u16   count;            /* 0x08 */
    u16   node_offset;      /* 0x0a  byte offset of DListNode inside an elem */
};

/* ================================================================== *
 * 2.  struct DListNode -- the link pair embedded in each element
 *
 * Evidence: func_02060614 (in src/matched/unit_02060614.c, the head walk)
 * returns `[elem + off + 4]` and func_0206062C (the tail walk) returns
 * `[elem + off + 0]`, which fixes prev at +0x00 and next at +0x04.  The
 * removal func_020605B4 agrees: its `prev == 0` arm writes list->head from
 * the +0x04 word.
 * ================================================================== */
struct DListNode {
    void *prev;             /* 0x00 */
    void *next;             /* 0x04 */
};

/* ================================================================== *
 * 3.  Prototypes, with the exact parameter types the matched sources use
 * ================================================================== */

/* 0x02060468  EXACT (src/matched/func_02060468.c).  Initialise an empty list.
   Its own source spells the object as raw stores through an int parameter;
   the typed form below is what every CALLER of it declares.  It takes four
   parameters in the matched source and uses only the first two. */
extern void func_02060468(struct DList *list, u16 node_offset);

/* 0x02060480  EXACT (src/matched/func_02060480.c).  Seed an EMPTY list with
   its first element: both links cleared, head and tail both the element.
   THE EVIDENCING FUNCTION FOR THE `volatile` SHAPE above. */
extern void func_02060480(volatile struct DList *list, void *elem);

/* 0x020604AC  open, residue at 4 bytes (docs/notes/dlist_ops.c.txt).
   Append at the tail; delegates to func_02060480 on an empty list. */
extern void func_020604AC(volatile struct DList *list, void *elem);

/* 0x02060500  open, residue at 4 bytes (docs/notes/dlist_ops.c.txt).
   Prepend at the head; delegates to func_02060480 on an empty list. */
extern void func_02060500(volatile struct DList *list, void *elem);

/* 0x02060550  EXACT (src/matched/func_02060550.c), cluster_02060550.
   Insert `elem` immediately BEFORE `before`; a null `before` appends. */
extern void func_02060550(volatile struct DList *list, void *before, void *elem);

/* 0x0205D1BC  EXACT (src/matched/func_0205D1BC.c).  `return ~5;`  Unrelated
   to the rest of the cluster; it is the address the packet cut started at. */
extern int func_0205D1BC(void);

#endif /* CLUSTER_0205D1BC_H */

/* CORRECTION 2026-09-23 (wave 13).  func_020604AC and func_02060500 are
 * EXACT under ../2.0/sp2, NOT 1.1p1, and WITHOUT the volatile: they are
 * NitroSystem fnd/list.c NNS_FndAppendListObject / NNS_FndPrependListObject,
 * written with the library's GetLink macro ((NNSFndLink *)((u32)(obj) +
 * (list)->offset)) and the non-empty case as an else arm.  The pointer-typed
 * add was the 4-byte register swap; the volatile was compensating for a
 * different compiler.  The pin paragraph above measured sp2 on the old,
 * pointer-typed source only.  See src/matched/func_020604AC.c. */
