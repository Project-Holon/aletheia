/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: NNS_FndGetNextListObject, NNS_FndGetPrevListObject, NNSi_FndFindElem
 * address:  0x02060614
 * packet:   pkt_02060468
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DList iterators and recursive range query.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02060614.c \
 *       --addr 0x02060614 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

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

struct Elem {
    char pad00[0x0c];
    struct DList sublist;
    u32 min_val;
    u32 max_val;
};

void *NNS_FndGetNextListObject(struct DList *list, void *elem)
{
    if (elem == 0) {
        return list->head;
    }
    return ((struct DListNode *)((char *)elem + list->node_offset))->next;
}

void *NNS_FndGetPrevListObject(struct DList *list, void *elem)
{
    if (elem == 0) {
        return list->tail;
    }
    return ((struct DListNode *)((char *)elem + list->node_offset))->prev;
}

struct Elem *NNSi_FndFindElem(struct DList *list, u32 val)
{
    struct Elem *elem;
    for (elem = (struct Elem *)NNS_FndGetNextListObject(list, 0); elem != 0; elem = (struct Elem *)NNS_FndGetNextListObject(list, elem)) {
        if (elem->min_val <= val && val < elem->max_val) {
            struct Elem *res = NNSi_FndFindElem(&elem->sublist, val);
            if (res == 0) {
                res = elem;
            }
            return res;
        }
    }
    return 0;
}
