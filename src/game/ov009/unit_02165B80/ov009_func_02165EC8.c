/*
 * function: WcmSearchApList
 * address:  0x02165EC8
 * packet:   pkt_ov009_02165EC8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WcmSearchApList (aplist.o)
 *
 * symbols:
 *   WCMi_GetSystemWork     0x021657C8  arm
 *   WCM_CompareBssID       0x021666B8  arm
 */

struct WCMBssDesc {
    unsigned short length;
    unsigned short rssi;
    unsigned char  bssid[6];
};

struct WCMApList {
    unsigned long       field0;
    unsigned long       index;
    unsigned long       field8;
    struct WCMApList   *next;
    struct WCMBssDesc   bssDesc;
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
extern int WCM_CompareBssID(unsigned char *a, unsigned char *b);

static struct WCMApList *WcmSearchApList(unsigned char *bssid)
{
    struct WCMWork *w;
    struct WCMApListHeader *pHeader;
    struct WCMApList *p;

    w = WCMi_GetSystemWork();
    p = 0;
    pHeader = w->pHeader;
    if (bssid == 0)
        return p;
    if (pHeader != 0 && w->apListSize > 12) {
        p = pHeader->head;
        while (p != 0) {
            if (WCM_CompareBssID(p->bssDesc.bssid, bssid))
                break;
            p = p->next;
        }
    }
    return p;
}
