/*
 * function: func_02061D0C
 * address:  0x02061D0C
 * packet:   pkt_02061D0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Node {
    u32 start;
    u32 size;
    struct Node *prev;
    struct Node *next;
};

struct Range {
    u32 start;
    u32 end;
};

u32 func_02061D0C(struct Node **head1, struct Node **head2, struct Range *range) {
    struct Node *curr = *head1;
    struct Node *next_node;
    u32 ret = 0;
    u32 zero1 = ret;
    u32 zero2 = ret;

    if (curr != 0) {
        while (curr != 0) {
            next_node = curr->next;

            if (curr->start == range->end) {
                struct Node *next;
                struct Node *prev;
                struct Node *head2_curr;

                range->end = curr->start + curr->size;
                ret |= 1;

                prev = curr->prev;
                next = curr->next;
                if (prev != 0) {
                    prev->next = next;
                } else {
                    *head1 = next;
                }
                if (next != 0) {
                    next->prev = prev;
                }

                head2_curr = *head2;
                if (head2_curr != 0) {
                    head2_curr->prev = curr;
                }
                curr->next = *head2;
                curr->prev = (struct Node *)zero1;
                *head2 = curr;
            }

            if (range->start == curr->start + curr->size) {
                struct Node *next;
                struct Node *prev;
                struct Node *head2_curr;

                range->start = curr->start;
                ret |= 1;

                prev = curr->prev;
                next = curr->next;
                if (prev != 0) {
                    prev->next = next;
                } else {
                    *head1 = next;
                }
                if (next != 0) {
                    next->prev = prev;
                }

                head2_curr = *head2;
                if (head2_curr != 0) {
                    head2_curr->prev = curr;
                }
                curr->next = *head2;
                curr->prev = (struct Node *)zero2;
                *head2 = curr;
            }

            curr = next_node;
        }
    }

    return ret;
}
