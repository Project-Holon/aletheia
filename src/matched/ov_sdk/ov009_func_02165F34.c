/*
 * function: WcmSearchIndexedApList
 * address:  0x02165F34
 * packet:   pkt_ov009_02165F34
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WcmSearchIndexedApList (aplist.o)
 *
 * symbols:
 *   WCMi_GetSystemWork     0x021657C8  arm
 */

struct WCMApList {
    unsigned long       field0;
    unsigned long       index;
    unsigned long       field8;
    struct WCMApList   *next;
};

struct WCMApListHeader {
    unsigned long      count;
    struct WCMApList  *head;
    unsigned long      field8;
};

struct WCMWork {
    unsigned char pad0[0x12C4];
    struct WCMApListHeader *pHeader;
    unsigned long           apListSize;
    unsigned char           pad1[0x10];
    unsigned char           lockFlag;
};

extern struct WCMWork *WCMi_GetSystemWork(void);

static struct WCMApList *WcmSearchIndexedApList(unsigned long index)
{
    struct WCMWork *w;
    struct WCMApListHeader *pHeader;
    struct WCMApList *p;

    w = WCMi_GetSystemWork();
    p = 0;
    pHeader = w->pHeader;
    if (pHeader != 0 && w->apListSize > 12) {
        p = pHeader->head;
        while (p != 0) {
            if (p->index == index)
                break;
            p = p->next;
        }
    }
    return p;
}
