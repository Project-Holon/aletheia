/*
 * file:     tcbl_p03.c
 * unit:     yes
 * function: func_02030CB0, func_02030CBC, sub_02030CF4
 * address:  0x02030CB0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_02030CF4  0x02030CF4  arm
 *   sub_02030BD4  0x02030BD4  arm
 */
struct Ctx;
typedef unsigned int u32;

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

extern void sub_02030CF4(struct Ctx *c);
extern void sub_02030BD4(struct Ctx *c);
u32 sub_02030CB0(u32 idx);



/*
 * Index-to-offset arithmetic: a fixed 0x38-byte header plus 0x20 bytes per
 * element. No relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030CB0.c \
 *       --func sub_02030CB0 --addr 0x02030CB0 --cc 1.1p1
 */
u32 sub_02030CB0(u32 idx)
{
    return (idx << 5) + 0x38;
}



/*
 * Lay a timer context out over caller-supplied storage and return it.  The
 * two arrays live in the tail of the block: the free stack of `capacity`
 * node pointers starts at +0x38 and the node pool starts immediately after
 * it, which is what `add r3, r4, #0x38` and `add r2, r3, r0, lsl #2` are.
 * Nothing is allocated here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030CBC.c \
 *       --func sub_02030CBC --addr 0x02030CBC --cc 1.1p1 --arm
 */
struct Ctx *sub_02030CBC(u32 capacity, struct Ctx *c)
{
    c->capacity = capacity;
    c->freeList = c->slots;
    c->pool = (struct Node *)(c->freeList + capacity);
    c->top = 0;
    c->busy = 0;
    sub_02030CF4(c);
    return c;
}


/*
 * Reset the context: rebuild the free stack over the whole pool (0x02030BD4)
 * and then re-arm the embedded sentinel so the circular list is empty, both
 * links pointing back at the sentinel itself.  The walk cursor at +0x30 is
 * parked on the sentinel, which is the "nothing pending" state the stepper at
 * 0x02030D28 tests for.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030CF4.c \
 *       --func sub_02030CF4 --addr 0x02030CF4 --cc 1.1p1 --arm
 */
void sub_02030CF4(struct Ctx *c)
{
    sub_02030BD4(c);

    c->head.owner = c;
    c->head.next = &c->head;
    c->head.prev = &c->head;
    c->head.key = 0;
    c->head.arg = 0;
    c->head.fn = 0;
    c->cursor = &c->head;
}
