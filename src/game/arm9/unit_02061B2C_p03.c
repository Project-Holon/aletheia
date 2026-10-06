/*
 * file:     unit_02061B2C_p03.c
 * unit:     yes
 * function: func_02061D0C, func_02061DF0, func_02061DFC, func_02061E48
 * address:  0x02061D0C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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

typedef unsigned short u16;

struct Node02061DFC {
    u32 data0;                 /* 0x0 */
    u32 data1;                 /* 0x4 */
    struct Node02061DFC *prev; /* 0x8 */
    struct Node02061DFC *next; /* 0xc */
};

struct Node02061E48 {
    u32 data0;                 /* 0x0 */
    u32 data1;                 /* 0x4 */
    struct Node02061E48 *prev; /* 0x8 */
    struct Node02061E48 *next; /* 0xc */
};

struct Pool02061E48 {
    struct Node02061E48 *free_list;
};

struct List02061E48 {
    struct Node02061E48 *head;
};

void NHTTPi_InitRequestInfo(u32 *reqInfo_p);


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


void NHTTPi_InitRequestInfo(u32 *reqInfo_p)
{
    *reqInfo_p = 0;
}


/*
 * note:     closed 2026-09-21 by tools/permuter.py (hill, --types, ret-var): the function
 *           returns the array pointer it was given; the void version freed r0 too early (2 bytes)
 */
struct Node02061DFC *func_02061DFC(struct Node02061DFC *arr, u32 count)
{
    u32 last = count - 1;
    u32 i = 0;
    u32 *end;

    if (last != 0) {
        struct Node02061DFC *p = arr;
        do {
            struct Node02061DFC *next_node = &arr[i + 1];
            arr[i].next = next_node;
            (&arr[i])[1].prev = p;
            i++;
            p++;
        } while (i < last);
    }

    arr[0].prev = 0;
    end = (u32 *)&arr[count];
    end[-1] = 0;
    return arr;
}


u32 func_02061E48(struct List02061E48 *list, struct Pool02061E48 *pool, u32 d0, u32 d1)
{
    struct Node02061E48 *node = pool->free_list;

    if (node != 0) {
        pool->free_list = node->next;
    }

    if (node == 0) {
        goto err;
    }

    node->data0 = d0;
    node->data1 = d1;
    node->prev = 0;
    node->next = 0;

    if (list->head != 0) {
        list->head->prev = node;
    }

    node->next = list->head;
    node->prev = 0;
    list->head = node;

    return 1;

err:
    return 0;
}
