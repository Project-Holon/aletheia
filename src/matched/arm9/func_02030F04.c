/*
 * function: TCBL_PopFreeTask
 * address:  0x02030F04
 * packet:   pkt_02030F04
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

struct Node {
    char pad[4];
    struct Node *prev;
    struct Node *next;
};

struct List {
    char pad[0x34];
    struct Node *head;
};

struct Node *TCBL_PopFreeTask(struct List *list)
{
    struct Node *head = list->head;
    if (head == 0) {
        return 0;
    }
    list->head = head->next;
    if (head->next != 0) {
        head->next->prev = 0;
    }
    return head;
}
