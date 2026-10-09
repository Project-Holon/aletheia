/*
 * file:     button_man_p14.c
 * function: func_02058380
 * address:  0x02058380
 * packet:   pkt_02057830
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

struct Node {
    struct Node * volatile next;
    struct Node *prev;
};

struct List {
    struct Node * volatile head;
    volatile int count;
    struct Node * volatile tail;
};

struct Node *func_02058380(struct List *list)
{
    struct Node *ret;
    struct Node *head;

    ret = 0;
    head = list->head;
    if (head != 0) {
        ret = head;
        list->head = head->next;
        if (list->head != 0) {
            head->next->prev = 0;
        } else {
            list->head = 0;
            list->tail = 0;
        }
        list->count--;
    }
    return ret;
}
