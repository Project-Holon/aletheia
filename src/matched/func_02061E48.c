/*
 * function: func_02061E48
 * address:  0x02061E48
 * packet:   pkt_02061DFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

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
