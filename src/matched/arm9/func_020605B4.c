/*
 * unit:     no
 * function: NNS_FndRemoveListObject
 * address:  0x020605B4
 * packet:   pkt_02060550
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DList remove: unlink `elem` from the list and clear its own link pair.
 * Both ends are handled by the same shape -- a null neighbour means the
 * element was at that end, so the list header's own head/tail takes the
 * element's other link.  The image's conditional execution (`ldreq`/`streq`
 * paired with `ldrne`/`strne`) is mwcc if-converting both arms; no goto or
 * ternary is needed to get it.
 *
 * The node offset is read into a local for the first arm pair and re-read
 * from the list for the second `->prev` write: the image has exactly two
 * `ldrh [r0, #0xa]`, the second inside the `ne` arm (`ldrhne r1, [r0, #0xa]`),
 * which is what pins that one access to the field rather than the local.
 * The `volatile` on the list pointer is the cluster-wide shape documented on
 * NNSi_FndSetFirstObject: it keeps the count read after the link stores.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_FndRemoveListObject.c \
 *       --func NNS_FndRemoveListObject --addr 0x020605B4 --cc 1.1p1 --arm
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

void NNS_FndRemoveListObject(volatile struct DList *list, void *elem)
{
    u16               off  = list->node_offset;
    struct DListNode *node = (struct DListNode *)((char *)elem + off);

    if (node->prev == 0) {
        list->head = node->next;
    } else {
        ((struct DListNode *)((char *)node->prev + off))->next = node->next;
    }
    if (node->next == 0) {
        list->tail = node->prev;
    } else {
        ((struct DListNode *)((char *)node->next + list->node_offset))->prev = node->prev;
    }
    node->prev = 0;
    node->next = 0;
    list->count = list->count - 1;
}
