/*
 * function: sub_02030BD4
 * address:  0x02030BD4
 * packet:   pkt_02030BD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Refill the free stack: every node in the pool is blanked, pointed back at
 * its owner and at the sentinel, and pushed onto the stack in index order, so
 * afterwards the stack holds all `capacity` nodes and the top index is zero.
 * The allocator in src/matched/unit_02030C44.c reads that stack from the top.
 *
 * The node stride is 0x1c, so the pool index is a real `mul` against a hoisted
 * 0x1c, not a shift.  `&c->pool[i]` is recomputed from the field for the
 * free-stack store, and the loop bound re-reads c->capacity, because the
 * writes through the cursor may alias either pointer.
 *
 * This function is kept in its own file rather than folded into
 * unit_02030C44.c beside it: a unit spanning both records its manifest entry
 * at the unit's own start address, and 0x02030C44 then stops being an
 * attestable address, which costs unit_02030DA8.c its only witness.  See
 * docs/idioms/a-unit-attests-only-its-own-start-address.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030BD4.c  *       --func sub_02030BD4 --addr 0x02030BD4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Ctx;

struct Node {
    struct Ctx  *owner;   /* +0x00 */
    struct Node *prev;    /* +0x04 */
    struct Node *next;    /* +0x08 */
    u32          key;     /* +0x0c */
    u32          arg;     /* +0x10 */
    void       (*fn)(u32);/* +0x14 */
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

void sub_02030BD4(struct Ctx *c)
{
    struct Node *n;
    u32 i;

    for (i = 0; i < c->capacity; i++) {
        n = &c->pool[i];
        n->owner = c;
        n->next = &c->head;
        n->prev = &c->head;
        n->key = 0;
        n->arg = 0;
        n->fn = 0;
        c->freeList[i] = &c->pool[i];
    }
    c->top = 0;
}
