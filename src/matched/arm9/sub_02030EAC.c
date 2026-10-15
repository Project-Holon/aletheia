/*
 * function: TCB_DeleteTask
 * address:  0x02030EAC
 * packet:   pkt_02030CBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_02030C68   0x02030C68  arm
 *
 * Unlink one node from its owner's doubly-linked list and then tail-call
 * sub_02030C68 on the owner.  The node carries its owner at +0, its
 * predecessor at +4 and its successor at +8; the owner's list head is at
 * +0x34 and is advanced to the successor when the node being removed is
 * the head.
 *
 * `ldmib r1, {r0, r2}` is the paired load of the two link fields, not an
 * aggregate copy: the head fix-up above it is predicated, so there is no
 * branch anywhere in the function and the scheduler is free to fold the
 * two loads.  The links are then re-loaded for the second unlink store
 * because the first store may alias them.
 *
 * The `mov r1, r0` that opens the function is the arity tell: nothing in
 * the body reads r1, and r1 is not callee-saved, so the only reason to
 * spend an instruction parking the node there is that the tail call
 * needs it as a second argument.  Written as a one-argument call the
 * whole function comes out four bytes shorter with the node left in r0,
 * every concrete byte shifted by one instruction.  See
 * docs/idioms/a-parameter-moved-out-of-r0-at-entry-names-the-tail-calls-arity.md.
 *
 * 0x02030C68 has no branch witness of its own: this function is its only
 * reference image-wide.  The site resolves on class `matched` against
 * src/matched/unit_02030C68.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCB_DeleteTask.c \
 *       --func TCB_DeleteTask --addr 0x02030EAC --cc 1.1p1 --arm
 */

typedef unsigned char u8;

struct Node;

struct Owner {
    u8           pad_00[0x34];
    struct Node *head;
};

struct Node {
    struct Owner *owner;
    struct Node  *prev;
    struct Node  *next;
};

typedef unsigned int   u32;
struct Ctx02030C68;
struct Frame02030C68;
extern u32 sub_02030C68(struct Ctx02030C68 *ctx, struct Frame02030C68 *frame);

void TCB_DeleteTask(struct Node *n)
{
    struct Owner *o = n->owner;

    if (o->head == n) {
        o->head = n->next;
    }
    n->prev->next = n->next;
    n->next->prev = n->prev;
    sub_02030C68((struct Ctx02030C68 *)n->owner, (struct Frame02030C68 *)n);
}
