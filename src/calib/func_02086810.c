/*
 * function: DLExtract
 * address:  0x02086810
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

struct Node *DLExtract(struct Node *list, struct Node *node)
{
    if (node->next != 0) {
        node->next->prev = node->prev;
    }
    if (node->prev == 0) {
        list = node->next;
    } else {
        node->prev->next = node->next;
    }
    return list;
}
