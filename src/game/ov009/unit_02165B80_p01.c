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
#include "wcm_types.h"

extern unsigned long OS_DisableInterrupts(void);
extern WCMWork *WCMi_GetSystemWork(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
void WCM_ClearApList(void);
long WCM_CountApList(void);
long WCM_LockApList(long lock);


void WCM_ClearApList(void)
{
    WCMWork *w;
    unsigned long e;

    e = OS_DisableInterrupts();
    w = WCMi_GetSystemWork();
    if (w == 0) {
        OS_RestoreInterrupts(e);
        return;
    }
    if (((WCMApListHeader *)w->config.pbdbuffer) != 0 && (long)w->config.nbdbuffer > 0)
        MI_CpuFill8(((WCMApListHeader *)w->config.pbdbuffer), 0, w->config.nbdbuffer);
    OS_RestoreInterrupts(e);
}


long WCM_CountApList(void)
{
    WCMWork *w;
    unsigned long e;
    long count;

    e = OS_DisableInterrupts();
    w = WCMi_GetSystemWork();
    count = 0;
    if (w == 0) {
        OS_RestoreInterrupts(e);
        return count;
    }
    if (((WCMApListHeader *)w->config.pbdbuffer) != 0 && w->config.nbdbuffer > 12)
        count = ((WCMApListHeader *)w->config.pbdbuffer)->count;
    OS_RestoreInterrupts(e);
    return count;
}


long WCM_LockApList(long lock)
{
    WCMWork *w;
    unsigned long e;
    long ret;

    e = OS_DisableInterrupts();
    w = WCMi_GetSystemWork();
    if (w == 0) {
        OS_RestoreInterrupts(e);
        return 0;
    }
    if (lock) {
        ret = (w->apListLock == 0) ? 0 : 1;
        w->apListLock = 1;
    } else {
        ret = (w->apListLock == 0) ? 0 : 1;
        w->apListLock = 0;
    }
    OS_RestoreInterrupts(e);
    return ret;
}


WMBssDesc *WCM_PointApListEx(long index);
