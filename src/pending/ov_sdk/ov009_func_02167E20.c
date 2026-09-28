/*
 * function: WcmWmcbSetDCFDataAsync
 * address:  0x02167E20
 * packet:   pkt_ov009_02167E20
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      WcmWmcbSetDCFDataAsync (wmif.o)
 *
 * blocker:  1.1p1 if-converts the one-instruction then-arm `wcmResult = -5;`
 *           to `subne r5,r5,#5` (100 B); the image keeps a real branch
 *           `mov r5,#0 / cmp / beq / mvn r5,#4` (104 B). Allocating the
 *           trailing callback tail does not stop the if-conversion; 2.0/sp2
 *           and every dsi front end give the same 100 B. Codegen wall.
 *
 * symbols:
 *   WCMi_GetCpsifWork                0x02166378 arm
 *   WCMi_ResetKeepAliveAlarm         0x02165af4 arm
 *   WCMi_CpsifUnlockMutexInIRQ       0x02166594 arm
 */

struct WCMCpsifWork;

extern struct WCMCpsifWork *WCMi_GetCpsifWork(void);
extern void WCMi_ResetKeepAliveAlarm(void);
extern void WCMi_CpsifUnlockMutexInIRQ(void *mutex);

static void WcmWmcbSetDCFDataAsync(void *arg)
{
    struct WCMCpsifWork *wcmiw = WCMi_GetCpsifWork();
    long wcmResult;
    void (*sendCallback)(long);

    if (*(unsigned short *)arg != 0x12)
        return;
    *(unsigned short *)((char *)wcmiw + 0x24) = *(unsigned short *)((char *)arg + 2);
    if (*(unsigned short *)((char *)arg + 2) == 0)
        WCMi_ResetKeepAliveAlarm();
    wcmResult = 0;
    if (*(unsigned short *)((char *)wcmiw + 0x24) != 0)
        wcmResult = -5;
    sendCallback = *(void (**)(long))((char *)wcmiw + 0x2c);
    *(void (**)(long))((char *)wcmiw + 0x2c) = 0;
    WCMi_CpsifUnlockMutexInIRQ((char *)wcmiw + 0xc);
    sendCallback(wcmResult);
}
