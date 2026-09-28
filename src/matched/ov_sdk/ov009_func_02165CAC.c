/*
 * function: WCM_PointApListEx
 * address:  0x02165CAC
 * packet:   pkt_ov009_02165CAC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCM_PointApListEx (aplist.o)
 *
 * symbols:
 *   OS_DisableInterrupts      0x02087988  arm
 *   WCMi_GetSystemWork        0x021657C8  arm
 *   OS_RestoreInterrupts      0x0208799C  arm
 *   WcmSearchIndexedApList    0x02165F34  arm
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

extern unsigned long OS_DisableInterrupts(void);
extern struct WCMWork *WCMi_GetSystemWork(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern struct WCMApList *WcmSearchIndexedApList(unsigned long index);

struct WCMBssDesc *WCM_PointApListEx(long index)
{
    struct WCMWork *w;
    unsigned long e;
    struct WCMApList *p;

    e = OS_DisableInterrupts();
    w = WCMi_GetSystemWork();
    if (w == 0) {
        OS_RestoreInterrupts(e);
        return 0;
    }
    p = WcmSearchIndexedApList(index);
    if (p == 0) {
        OS_RestoreInterrupts(e);
        return 0;
    }
    OS_RestoreInterrupts(e);
    return &p->bssDesc;
}
