/*
 * function: func_0204CA30
 * address:  0x0204CA30
 * packet:   pkt_0204C944
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   none (no external calls, no data references)
 *
 * Unlink a node from a doubly linked list whose head pointer lives at +4 of
 * the manager.  A node whose own forward pointer is itself is the only
 * entry, so the manager's head is cleared instead of taking the link.  Both
 * arms of that inner if write the head, which is why the store is a
 * conditional pair rather than one unconditional store.
 */

typedef unsigned char u8;

struct Node {
    struct Node *f0;
    struct Node *f4;
};

struct Mgr {
    u8           pad_000[4];
    struct Node *head;
};

void func_0204CA30(struct Mgr *m, struct Node *l)
{
    if (m->head == l) {
        if (l->f0 == l) {
            m->head = 0;
        } else {
            m->head = l->f0;
        }
    }
    l->f0->f4 = l->f4;
    l->f4->f0 = l->f0;
    l->f0 = 0;
    l->f4 = 0;
}
