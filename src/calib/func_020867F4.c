/*
 * function: DLAddFront
 * address:  0x020867F4
 * packet:   pkt_02086788
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

struct Node {
    struct Node *prev;
    struct Node *next;
};

struct Node *DLAddFront(struct Node *r0, struct Node *r1)
{
    r1->next = r0;
    r1->prev = 0;
    if (r0 != 0) {
        r0->prev = r1;
    }
    return r1;
}
