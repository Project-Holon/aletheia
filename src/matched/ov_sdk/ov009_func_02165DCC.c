/*
 * function: func_02165DCC
 * address:  0x02165DCC
 * packet:   pkt_ov009_02165DCC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WcmAllocApList (aplist.o)
 *
 * symbols:
 *   func_021657C8  0x021657C8  arm  ov009
 */

struct WCMApList {
    unsigned char state;
    unsigned char reserved;
    unsigned short linkLevel;
    unsigned long index;
    struct WCMApList *previous;
    struct WCMApList *next;
    unsigned long data[48];
};
struct WCMApListHeader {
    unsigned long count;
    struct WCMApList *head;
    struct WCMApList *tail;
};
struct WCMWork {
    char pad[0x12c0];
    struct {
        unsigned long dmano;
        void *pbdbuffer;
        unsigned long nbdbuffer;
        unsigned long nbdmode;
    } config;
};
extern struct WCMWork *func_021657C8(void);

struct WCMApList *func_02165DCC(void)
{
    unsigned long maxBlock;
    long i;
    struct WCMApList *pList;
    struct WCMApList *p;
    struct WCMApListHeader *pHeader;
    struct WCMWork *w;

    w = func_021657C8();
    pHeader = (struct WCMApListHeader *)w->config.pbdbuffer;
    p = 0;

    if (pHeader == 0)
        return 0;
    if (w->config.nbdbuffer <= sizeof(struct WCMApListHeader))
        return 0;
    maxBlock = (w->config.nbdbuffer - sizeof(struct WCMApListHeader)) / sizeof(struct WCMApList);
    if (maxBlock == 0)
        return 0;
    if (maxBlock <= pHeader->count)
        return 0;

    i = 0;
    if (i < maxBlock) {
        pList = (struct WCMApList *)(pHeader + 1);
        do {
            p = pList + i;
            if (p->state == 0)
                break;
            i++;
        } while (i < maxBlock);
    }
    if (i < maxBlock) {
        p->state = 1;
        p->index = pHeader->count;
        p->next = 0;
        p->previous = pHeader->tail;
        pHeader->tail = p;
        if (p->previous)
            p->previous->next = p;
        else
            pHeader->head = p;
        pHeader->count++;
    }
    return p;
}
