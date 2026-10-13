/*
 * function: WcmNwmcbSetDCFDataAsync
 * address:  0x02732CEC
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WcmNwmcbSetDCFDataAsync (libwcm.TWL.HYB.a nwmif.o)
 *
 * NWM completion callback for an asynchronous DCF send, the TWL twin of
 * ov009 WcmWmcbSetDCFDataAsync (0x02167E20): record the NWM error code,
 * re-arm the keep-alive alarm on success, map the result to the WCM cpsif
 * code (0 or -5), release the send mutex and call the user callback.  The
 * vendor member matches the image with 0 masked mismatches.  The result is
 * a switch on sendResult with a `case 1: default:` arm, as in the wmif.o
 * twin; that arm is reached by two edges, so it is not if-converted (the
 * image's `mov r5,#0 / cmp / beq / mvn r5,#4`).
 *
 * symbols:
 *   WCMi_GetCpsifWork  0x02166378  arm  ov009
 *   func_02165AF4  0x02165AF4  arm  ov009
 *   func_02166594  0x02166594  arm  ov009
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
typedef struct NWMCallback { unsigned short apiid; unsigned short retcode; } NWMCallback;

extern WCMCpsifWork *WCMi_GetCpsifWork(void);
extern void func_02165AF4(void);
extern void func_02166594(OSMutex *mutex);

void WcmNwmcbSetDCFDataAsync(void *arg)
{
    NWMCallback *cb = (NWMCallback *)arg;
    WCMCpsifWork *wcmiw = WCMi_GetCpsifWork();
    long wcmResult;
    void (*sendCallback)(long);

    switch (cb->apiid) {
    case 0xb:
        wcmiw->sendResult = cb->retcode;
        if (cb->retcode == 0) {
            func_02165AF4();
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
        func_02166594(&wcmiw->sendMutex);
        sendCallback(wcmResult);
        break;
    }
}
