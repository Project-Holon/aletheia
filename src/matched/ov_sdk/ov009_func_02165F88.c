/*
 * function: WcmAppendApList
 * address:  0x02165F88
 * packet:   pkt_ov009_02165F88
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WcmAppendApList (aplist.o)
 *
 * symbols:
 *   WCMi_GetSystemWork  0x021657C8  arm  ov009
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
extern int WCMi_GetSystemWork(void);

void WcmAppendApList(struct WCMApList *aplist)
{
    struct WCMWork *w = (struct WCMWork *)WCMi_GetSystemWork();
    struct WCMApListHeader *pHeader = (struct WCMApListHeader *)w->config.pbdbuffer;
    struct WCMApList *p;

    if (aplist == 0 || pHeader == 0)
        return;
    if (w->config.nbdbuffer <= sizeof(struct WCMApListHeader))
        return;

    for (p = pHeader->head; p != 0; p = p->next) {
        if (p == aplist) {
            if (p->previous)
                p->previous->next = p->next;
            else
                pHeader->head = p->next;
            if (p->next)
                p->next->previous = p->previous;
            else
                pHeader->tail = p->previous;
            break;
        }
    }
    aplist->next = 0;
    aplist->previous = pHeader->tail;
    pHeader->tail = aplist;
    if (aplist->previous)
        aplist->previous->next = aplist;
    else
        pHeader->head = aplist;
    if (p == 0) {
        aplist->index = pHeader->count;
        pHeader->count++;
    }
}
