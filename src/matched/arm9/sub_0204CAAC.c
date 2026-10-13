/*
 * unit:     no
 * function: CLACT_FindActorAfter
 * address:  0x0204CAAC
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
 * The forward half of the pair that opens this packet: walk the circular
 * list through its `next` links and return the first node whose key does
 * not sort above `key`, falling back on the head's `prev` when the walk
 * comes all the way round.
 *
 * Where CLACT_FindActorBefore returns a payload, this one returns the node itself,
 * which is the whole difference between `ldrhi r0, [r4, #4]` there and
 * `movls r0, r4` here.  The polarity is the other way round too: `ls`, the
 * complement of the sibling's `hi`.
 *
 * The two are separate translation units in the image, not one: each gets
 * its own `bl 0x204b838` and its own copy of the loop.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_FindActorAfter.c \
 *       --func CLACT_FindActorAfter --addr 0x0204CAAC --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Node {
    struct Node *prev;
    struct Node *next;
};

extern int CLACT_GetActorDrawPriority(int a0);

struct Node *CLACT_FindActorAfter(struct Node *head, u32 key)
{
    struct Node *n = head;

    do {
        if (CLACT_GetActorDrawPriority((int)n) <= key) {
            return n;
        }
        n = n->next;
    } while (n != head);

    return head->prev;
}
