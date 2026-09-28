/*
 * function: WCM_CountApList
 * address:  0x02165BD0
 * packet:   pkt_ov009_02165BD0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCM_CountApList (aplist.o)
 *
 * symbols:
 *   OS_DisableInterrupts   0x02087988  arm
 *   WCMi_GetSystemWork     0x021657C8  arm
 *   OS_RestoreInterrupts   0x0208799C  arm
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

extern unsigned long OS_DisableInterrupts(void);
extern struct WCMWork *WCMi_GetSystemWork(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

long WCM_CountApList(void)
{
    struct WCMWork *w;
    unsigned long e;
    long count;

    e = OS_DisableInterrupts();
    w = WCMi_GetSystemWork();
    count = 0;
    if (w == 0) {
        OS_RestoreInterrupts(e);
        return count;
    }
    if (w->pHeader != 0 && w->apListSize > 12)
        count = w->pHeader->count;
    OS_RestoreInterrupts(e);
    return count;
}
