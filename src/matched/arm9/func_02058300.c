/*
 * function: SPL_EMITTER_FreeNode
 * address:  0x02058300
 * packet:   pkt_02057830
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p -proc arm7tdmi
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

struct Node {
    struct Node *next;
    struct Node *prev;
};

struct List {
    struct Node * volatile head;
    int count;
    struct Node *tail;
};

struct Node *SPL_EMITTER_FreeNode(struct List *list, struct Node *node)
{
    struct Node *next;

    next = node->next;
    if (next == 0) {
        if (list->head == node) {
            list->head = 0;
            list->tail = 0;
        } else {
            node->prev->next = 0;
            list->tail = list->tail->prev;
        }
    } else {
        if (list->head == node) {
            list->head = next;
            list->head->prev = 0;
        } else {
            next->prev = node->prev;
            node->prev->next = node->next;
        }
    }
    list->count--;
    return node;
}
