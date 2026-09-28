/*
 * function: WcmWmcbSetDCFData
 * address:  0x02167DE0
 * packet:   pkt_ov009_02167DE0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WcmWmcbSetDCFData (wmif.o)
 *
 * symbols:
 *   WCMi_GetCpsifWork                0x02166378 arm
 *   WCMi_ResetKeepAliveAlarm         0x02165af4 arm
 *   OS_WakeupThread                  0x02085800 arm
 */

struct WCMCpsifWork;

extern struct WCMCpsifWork *WCMi_GetCpsifWork(void);
extern void WCMi_ResetKeepAliveAlarm(void);
extern void OS_WakeupThread(void *queue);

static void WcmWmcbSetDCFData(void *arg)
{
    struct WCMCpsifWork *wcmiw = WCMi_GetCpsifWork();

    if (*(unsigned short *)arg != 0x12)
        return;
    *(unsigned short *)((char *)wcmiw + 0x24) = *(unsigned short *)((char *)arg + 2);
    if (*(unsigned short *)((char *)arg + 2) == 0)
        WCMi_ResetKeepAliveAlarm();
    OS_WakeupThread((char *)wcmiw + 4);
}
