/*
 * Function matched as standalone.
 *
 * address:  0x02060468
 * packet:   pkt_02060468
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DList initialization function.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02060468.c \
 *       --func func_02060468 --addr 0x02060468 --arm
 */

typedef unsigned short u16;

struct DList {
    void *head;
    void *tail;
    u16   count;
    u16   node_offset;
};

void func_02060468(struct DList *list, u16 node_offset)
{
    list->head = 0;
    list->tail = 0;
    list->count = 0;
    list->node_offset = node_offset;
}
