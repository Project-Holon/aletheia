/*
 * function: TCB_Reset
 * address:  0x02030CF4
 * packet:   pkt_02030CBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   TCB_BuildFreeStack  0x02030BD4  arm
 *
 * Reset the context: rebuild the free stack over the whole pool (0x02030BD4)
 * and then re-arm the embedded sentinel so the circular list is empty, both
 * links pointing back at the sentinel itself.  The walk cursor at +0x30 is
 * parked on the sentinel, which is the "nothing pending" state the stepper at
 * 0x02030D28 tests for.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCB_Reset.c \
 *       --func TCB_Reset --addr 0x02030CF4 --cc 1.1p1 --arm
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

extern void TCB_BuildFreeStack(struct Ctx *c);

void TCB_Reset(struct Ctx *c)
{
    TCB_BuildFreeStack(c);

    c->head.owner = c;
    c->head.next = &c->head;
    c->head.prev = &c->head;
    c->head.key = 0;
    c->head.arg = 0;
    c->head.fn = 0;
    c->cursor = &c->head;
}
