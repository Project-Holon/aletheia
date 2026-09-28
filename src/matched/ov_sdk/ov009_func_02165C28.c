/*
 * function: WCM_LockApList
 * address:  0x02165C28
 * packet:   pkt_ov009_02165C28
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCM_LockApList (aplist.o)
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

long WCM_LockApList(long lock)
{
    struct WCMWork *w;
    unsigned long e;
    long ret;

    e = OS_DisableInterrupts();
    w = WCMi_GetSystemWork();
    if (w == 0) {
        OS_RestoreInterrupts(e);
        return 0;
    }
    if (lock) {
        ret = (w->lockFlag == 0) ? 0 : 1;
        w->lockFlag = 1;
    } else {
        ret = (w->lockFlag == 0) ? 0 : 1;
        w->lockFlag = 0;
    }
    OS_RestoreInterrupts(e);
    return ret;
}
