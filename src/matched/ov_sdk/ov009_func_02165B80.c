/*
 * function: WCM_ClearApList
 * address:  0x02165B80
 * packet:   pkt_ov009_02165B80
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCM_ClearApList (aplist.o)
 *
 * symbols:
 *   OS_DisableInterrupts   0x02087988  arm
 *   WCMi_GetSystemWork     0x021657C8  arm
 *   OS_RestoreInterrupts   0x0208799C  arm
 *   MI_CpuFill8            0x02082BCC  arm
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
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);

void WCM_ClearApList(void)
{
    struct WCMWork *w;
    unsigned long e;

    e = OS_DisableInterrupts();
    w = WCMi_GetSystemWork();
    if (w == 0) {
        OS_RestoreInterrupts(e);
        return;
    }
    if (w->pHeader != 0 && (long)w->apListSize > 0)
        MI_CpuFill8(w->pHeader, 0, w->apListSize);
    OS_RestoreInterrupts(e);
}
