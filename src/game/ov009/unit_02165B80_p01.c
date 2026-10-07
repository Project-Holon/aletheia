/*
 * file:     unit_02165B80_p01.c
 * unit:     yes
 * function: func_02165B80, func_02165BD0, func_02165C28
 * address:  0x02165B80
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
void WCM_ClearApList(void);
long WCM_CountApList(void);
long WCM_LockApList(long lock);


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
