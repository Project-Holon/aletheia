/*
 * function: func_02030D28
 * address:  0x02030D28
 * packet:   pkt_02030D28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * time_icon.c tail (the task-list runtime).  One pass over the circular
 * callback list at +0x08: unless the +0x2c busy flag is set, walk from
 * head.next to the embedded sentinel through the +0x30 cursor, pre-reading
 * each successor into +0x34 so a callback may unlink its own node, and call
 * each node's callback unless its +0x18 "fired" flag is set (which is
 * cleared instead).  The loop ends with the cursor on the sentinel, whose
 * callback slot is cleared.
 *
 * The documented 13-byte "loop-carried register" residue
 * (docs/notes/sub_02030D28.c.txt) was a misread callback arity: the image
 * loads the node into r0 and node->arg into r1 before `blx r2`, so the
 * callback is fn(node, arg), not fn(arg).  With two arguments the body is
 * byte-exact under 1.1p1 -O4,p.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02030D28.c \
 *       --func func_02030D28 --addr 0x02030D28 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Ctx;
struct Node;

struct Node {
    struct Ctx  *owner;   /* +0x00 */
    struct Node *prev;    /* +0x04 */
    struct Node *next;    /* +0x08 */
    u32          key;     /* +0x0c */
    u32          arg;     /* +0x10 */
    void       (*fn)(struct Node *node, u32 arg); /* +0x14 */
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

void func_02030D28(struct Ctx *c)
{
    if (c->busy != 0) {
        return;
    }

    c->cursor = c->head.next;

    while (c->cursor != &c->head) {
        c->walk = c->cursor->next;

        if (c->cursor->fired == 0) {
            if (c->cursor->fn != 0) {
                c->cursor->fn(c->cursor, c->cursor->arg);
            }
        } else {
            c->cursor->fired = 0;
        }

        c->cursor = c->walk;
    }

    c->cursor->fn = 0;
}
