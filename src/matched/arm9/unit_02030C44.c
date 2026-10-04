/*
 * unit:     yes
 * function: sub_02030C44
 * address:  0x02030C44
 * packet:   pkt_02030BD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_02030C44  0x02030C44  arm
 *
 * Allocate a timer node.  Free nodes live in a stack of pointers at
 * c->freeList with c->top the live index: this function hands back the entry
 * at the top and steps up, and 0x02030C68 (src/matched/unit_02030C68.c) steps
 * back down and stores the node there.  It calls nothing, so the unit holds
 * no relocations at all and needs no outside evidence; that is what unblocks
 * src/matched/unit_02030DA8.c, whose only unresolved site was the call to
 * 0x02030C44.
 *
 * 0x02030C68 used to be written out again at the bottom of this file, from
 * when it was still an unlabelled follower and this unit's inferred extent
 * ran to 0x02030CB0.  It is seeded in layout/function_starts.txt now and
 * src/matched/unit_02030C68.c is the manifest entry for it, so the extent
 * here stops at 0x02030C68 and the second body was redundant: two files laid
 * out the same 72 bytes and only one of them could own the address
 * (docs/idioms/a-unit-attests-only-its-own-start-address.md).
 *
 * In 0x02030C44 the popped entry is bound to a local before c->top is stepped:
 * that is the `movne r0, r2` at the end, four bytes that disappear if the
 * subscript is returned directly.  `cmp r3, r1` puts the live top on the
 * left, so the guard is written with c->top first
 * (docs/idioms/cmp-operand-order-names-the-temporary.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02030C44.c \
 *       --addr 0x02030C44 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Ctx;

struct Node {
    struct Ctx  *owner;   /* +0x00 */
    struct Node *prev;    /* +0x04 */
    struct Node *next;    /* +0x08 */
    u32          key;     /* +0x0c */
    void        *arg;     /* +0x10 */
    void       (*fn)(struct Node *, void *); /* +0x14 */
    u32          fired;   /* +0x18 */
};

struct Ctx {
    u32           capacity;   /* +0x00 */
    u32           top;        /* +0x04 */
    struct Node   head;       /* +0x08 */
    struct Node **freeList;   /* +0x24 */
    struct Node  *pool;       /* +0x28 */
    u32           busy;       /* +0x2c */
    struct Node  *cursor;     /* +0x30 */
    struct Node  *walk;       /* +0x34 */
    struct Node  *slots[1];   /* +0x38 */
};

struct Node *sub_02030C44(struct Ctx *c)
{
    struct Node *n;
    u32 top;

    top = c->top;
    if (top == c->capacity) {
        return 0;
    }
    n = c->freeList[top];
    c->top = top + 1;
    return n;
}
