/*
 * function: func_021BABF4
 * address:  0x021BABF4
 * packet:   pkt_021BABF4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef struct Node
{
    struct Node *next;
    struct Node *prev;
} Node;

Node *func_021BABF4(Node **head)
{
    Node *n = *head;

    if (n != 0)
    {
        if (n == n->next)
        {
            *head = 0;
        }
        else
        {
            n->next->prev = n->prev;
            n->prev->next = n->next;
            *head = n->prev;
        }
    }
    return n;
}
