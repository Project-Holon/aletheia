/*
 * unit:     no
 * function: CLACT_FindActorBefore
 * address:  0x0204CA74
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CLACT_GetActorDrawPriority  0x0204B838  arm
 *
 * Walk the circular list backwards from `head` and return the payload of
 * the first node whose key sorts strictly above `key`; if the walk comes
 * all the way round, the head's own payload is the answer.
 *
 * The list is circular, so the test is at the bottom and the loop is a
 * `do`/`while`: a `while` would have added an entry test the original does
 * not have.  `hi` rather than `gt` fixes the comparison as unsigned.  The
 * hit arm is two predicated instructions, `ldrhi` and `pophi`, so it never
 * reaches the shared tail.
 *
 * Its mirror image CLACT_FindActorAfter walks the same list forwards, returns the
 * node instead of the payload and inverts the condition.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_FindActorBefore.c \
 *       --func CLACT_FindActorBefore --addr 0x0204CA74 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Node {
    struct Node *prev;
    void        *payload;
};

extern int CLACT_GetActorDrawPriority(int a0);

void *CLACT_FindActorBefore(struct Node *head, u32 key)
{
    struct Node *n = head;

    do {
        if (CLACT_GetActorDrawPriority((int)n) > key) {
            return n->payload;
        }
        n = n->prev;
    } while (n != head);

    return head->payload;
}
