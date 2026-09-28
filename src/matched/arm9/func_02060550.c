/*
 * unit:     no
 * function: func_02060550
 * address:  0x02060550
 * packet:   pkt_02060550
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020604AC  0x020604AC  arm
 *   func_02060500  0x02060500  arm
 *
 * DList insert-before: splice `elem` into the list immediately ahead of
 * `before`.  A null `before` means "no successor", i.e. append at the tail
 * (func_020604AC); a `before` that is already the head is a prepend
 * (func_02060500).  Otherwise the four links are rewritten in place.
 *
 * The node-offset load is hoisted into a local because the splice reads it
 * once and the final `before->prev` write re-reads it: the image has two
 * `ldrh [r0, #0xa]`, not one and not three.
 *
 * Order is load-bearing twice over.  The `node` pointer is computed BEFORE
 * `prev` is read, even though `prev` is used first: mwcc numbers values in
 * the order the IR creates them and colours in that order, so computing
 * `prev` first gives it ip and `node` r3, exactly inverting the image's
 * `ldr r3, [r1, lr]` / `add ip, r2, lr` pair.  Writing the two statements in
 * the other order is a five-byte, pure register-substitution residue that no
 * single mutation moves; the permuter found the same lever independently
 * (`temp(tmp=(struct DListNode *)((char *)elem + off))` lifted above the
 * `prev` read) from that five-byte baseline.  The `volatile` on the list
 * pointer is the cluster-wide shape documented on func_02060480: it keeps
 * the count read after the link stores.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02060550.c \
 *       --func func_02060550 --addr 0x02060550 --cc 1.1p1 --arm
 */

typedef unsigned short u16;

struct DList {
    void *head;
    void *tail;
    u16   count;
    u16   node_offset;
};

struct DListNode {
    void *prev;
    void *next;
};

extern void func_020604AC(volatile struct DList *list, void *elem);
extern void func_02060500(volatile struct DList *list, void *elem);

void func_02060550(volatile struct DList *list, void *before, void *elem)
{
    u16               off;
    struct DListNode *node;
    void             *prev;

    if (before == 0) {
        func_020604AC(list, elem);
        return;
    }
    if (before == list->head) {
        func_02060500(list, elem);
        return;
    }
    off = list->node_offset;
    node = (struct DListNode *)((char *)elem + off);
    prev = ((struct DListNode *)((char *)before + off))->prev;
    node->prev = prev;
    node->next = before;
    ((struct DListNode *)((char *)prev + off))->next = elem;
    ((struct DListNode *)((char *)before + list->node_offset))->prev = elem;
    list->count = list->count + 1;
}
