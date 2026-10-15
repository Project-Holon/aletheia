/*
 * function: TCB_Init
 * address:  0x02030CBC
 * packet:   pkt_02030CBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   TCB_Reset  0x02030CF4  arm
 *
 * Lay a timer context out over caller-supplied storage and return it.  The
 * two arrays live in the tail of the block: the free stack of `capacity`
 * node pointers starts at +0x38 and the node pool starts immediately after
 * it, which is what `add r3, r4, #0x38` and `add r2, r3, r0, lsl #2` are.
 * Nothing is allocated here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCB_Init.c \
 *       --func TCB_Init --addr 0x02030CBC --cc 1.1p1 --arm
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

extern void TCB_Reset(struct Ctx *c);

struct Ctx *TCB_Init(u32 capacity, struct Ctx *c)
{
    c->capacity = capacity;
    c->freeList = c->slots;
    c->pool = (struct Node *)(c->freeList + capacity);
    c->top = 0;
    c->busy = 0;
    TCB_Reset(c);
    return c;
}
