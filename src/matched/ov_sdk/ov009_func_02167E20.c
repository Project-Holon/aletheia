/*
 * function: func_02167E20
 * address:  0x02167E20
 * packet:   pkt_ov009_02167E20
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WcmWmcbSetDCFDataAsync (libwcm.TWL.HYB.a wmif.o)
 *
 * WM completion callback for an asynchronous DCF send: record the WM error
 * code, re-arm the keep-alive alarm on success, map the result to the WCM
 * cpsif code (0 or -5), release the send mutex and call the user callback.
 *
 * 2026-10-01 (w3 lane28): closed. The earlier "front-end predication wall"
 * was source shape. The vendor .debug_line puts `mov r5,#0` on line 1574 and
 * `mvn r5,#4` on line 1580, both after the line-1570 test, so the result is
 * set in two arms of a switch on sendResult. A dead case label sharing the
 * default arm (`case 1: default:`, WM_ERRCODE_FAILED) keeps the -5 arm a
 * real block reached by two edges, so 1.1p1 does not if-convert it: the
 * image's `mov r5,#0 / cmp / beq / mvn r5,#4`. Plain `case 0 / default`,
 * if/else and the guard-after-default spellings all give `mvnne` (100 B).
 * Outer `switch (cb->apiid)` and the DWARF `cb` local as in the vendor.
 *
 * symbols:
 *   WCMi_GetCpsifWork                0x02166378 arm
 *   WCMi_ResetKeepAliveAlarm         0x02165af4 arm
 *   WCMi_CpsifUnlockMutexInIRQ       0x02166594 arm
 */

typedef struct OSThreadQueue { void *head; void *tail; } OSThreadQueue;
typedef struct OSMutex { OSThreadQueue queue; void *thread; long count; void *prev; void *next; } OSMutex;
typedef struct WCMCpsifWork {
    unsigned char initialized;
    unsigned char reserved[3];
    OSThreadQueue sendQ;
    OSMutex sendMutex;
    unsigned short sendResult;
    unsigned short padding1;
    void (*recvCallback)(unsigned char *, unsigned char *, unsigned char *, long);
    void (*sendCallback)(long);
    unsigned char macAddress[6];
    unsigned short padding2;
} WCMCpsifWork;
typedef struct WMCallback { unsigned short apiid; unsigned short errcode; unsigned short wlCmdID; unsigned short wlResult; } WMCallback;

extern WCMCpsifWork *WCMi_GetCpsifWork(void);
extern void WCMi_ResetKeepAliveAlarm(void);
extern void WCMi_CpsifUnlockMutexInIRQ(OSMutex *mutex);

static void func_02167E20(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    WCMCpsifWork *wcmiw = WCMi_GetCpsifWork();
    long wcmResult;
    void (*sendCallback)(long);

    switch (cb->apiid) {
    case 0x12:
        wcmiw->sendResult = cb->errcode;
        if (cb->errcode == 0) {
            WCMi_ResetKeepAliveAlarm();
        }
        switch (wcmiw->sendResult) {
        case 0:
            wcmResult = 0;
            break;
        case 1:
        default:
            wcmResult = -5;
            break;
        }
        sendCallback = wcmiw->sendCallback;
        wcmiw->sendCallback = 0;
        WCMi_CpsifUnlockMutexInIRQ(&wcmiw->sendMutex);
        sendCallback(wcmResult);
        break;
    }
}
