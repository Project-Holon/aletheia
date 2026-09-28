/*
 * unit:     no
 * address:  0x02030F34
 * packet:   pkt_02030BBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_02030F34
 *
 * Doubly linked list push-front: clears the new node's prev, chains it in
 * front of the current head, fixes the old head's back pointer if there
 * was one, and stores the new node as the head. No relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030F34.c \
 *       --func sub_02030F34 --addr 0x02030F34 --cc 1.1p1
 */

typedef unsigned int u32;

struct Node02030F34 {
    u32 unk0;
    struct Node02030F34 *prev;
    struct Node02030F34 *next;
};

struct S02030F34 {
    char pad[0x34];
    struct Node02030F34 *head;
};

void sub_02030F34(struct S02030F34 *p, struct Node02030F34 *node)
{
    struct Node02030F34 *old = p->head;
    node->prev = 0;
    node->next = old;
    if (old != 0) {
        old->prev = node;
    }
    p->head = node;
}
