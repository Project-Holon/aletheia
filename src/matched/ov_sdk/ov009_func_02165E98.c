/*
 * function: WcmGetOldestApList
 * address:  0x02165E98
 * packet:   pkt_ov009_02165E98
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WcmGetOldestApList (aplist.o)
 *
 * symbols:
 *   WCMi_GetSystemWork     0x021657C8  arm
 */

struct WCMApList;
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

static struct WCMApList *WcmGetOldestApList(void)
{
    struct WCMWork *w;
    struct WCMApListHeader *pHeader;

    w = WCMi_GetSystemWork();
    pHeader = w->pHeader;
    if (pHeader != 0 && w->apListSize > 12)
        return pHeader->head;
    return 0;
}
