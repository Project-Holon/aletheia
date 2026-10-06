/*
 * unit:     no
 * function: sub_0204CA74
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
 *   sub_0204B838  0x0204B838  arm
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
 * Its mirror image sub_0204CAAC walks the same list forwards, returns the
 * node instead of the payload and inverts the condition.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204CA74.c \
 *       --func sub_0204CA74 --addr 0x0204CA74 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Node {
    struct Node *prev;
    void        *payload;
};

extern int sub_0204B838(int a0);

void *sub_0204CA74(struct Node *head, u32 key)
{
    struct Node *n = head;

    do {
        if (sub_0204B838((int)n) > key) {
            return n->payload;
        }
        n = n->prev;
    } while (n != head);

    return head->payload;
}
