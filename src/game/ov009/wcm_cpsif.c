/*
 * file:     wcm_cpsif.c
 * unit:     yes
 * function: WCMi_InitCpsif, WCMi_CpsifRecvCallback, WCMi_GetCpsifWork, WCM_GetApMacAddress, WCM_GetApEssid, WCM_SetRecvDCFCallback, WCM_SendDCFDataEx, WCMi_CpsifUnlockMutexInIRQ, func_021665CC, WCM_GetMacAddress, WCMi_MergeToBuffer
 * address:  0x02166304
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * sdk:      WCMi_InitCpsif (libwcm.TWL.HYB.a cpsif.o)
 * One-time initialisation of the CPS interface work: clears the MAC address and the state words, then initialises the send mutex.
 * Returns the address of the CPS interface work block (initialised flag,
 * send mutex, receive and send callbacks, AP MAC address; see WCMCpsifWork
 * in twl/nwmif.c and wcm_cpsif_1.c).
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   OS_InitMutex  0x02086004  arm
 *   gWcmCpsifWork  0x021AA7DC  data ov009
 *   gWcmCpsifMac  0x021AA80C  data ov009
 *   WCMi_GetSystemWork  0x021657C8  arm  ov009
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   OS_LockMutex  0x02086028  arm
 *   OS_UnlockMutex 0x02086078  arm
 *   WCMi_WmifSetDCFData  0x02166D2C  arm  ov009
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   WCMi_NwmifSetDCFData  0x02731E50  arm  twl
 *   gWcmCpsifMutex     0x021AA7E8  data ov009
 *   OS_WakeupThread  0x02085800  arm
 *   OS_IrqHandler  0x01FF80F0  data
 *   MI_CpuCopy                   0x02082EA4  arm
 */
typedef struct WcmCpsifWork {
    unsigned char inited;
    unsigned char reserved1[0x3];
    long reserved4;
    long reserved8;
    unsigned char mutex[24];
    unsigned short reserved24;
    unsigned char reserved26[0x2];
    void (*recvCb)(unsigned char *, unsigned char *, unsigned char *, long);
} WcmCpsifWork;

typedef struct WCMWork_02166384 {
    unsigned char pad0[0x12DD];
    unsigned char resetting;
    unsigned char phase;
    unsigned char pad1[5];
    unsigned char bssid[6];
} WCMWork_02166384;

typedef struct WCMWork_021663C8 {
    unsigned char pad0[0x12DD];
    unsigned char resetting;
    unsigned char phase;
    unsigned char pad1[0x0B];
    unsigned short essidLen;
    unsigned char essid[32];
} WCMWork_021663C8;

typedef struct WCMWork_02166444 {
    unsigned short sendBuf[768];
    unsigned char pad0[0x12DD - 0x600];
    unsigned char resetting;
    unsigned char phase;
    unsigned char deviceId;
} WCMWork_02166444;

typedef struct OSMutex {
    unsigned long queue;
    unsigned long queue2;
    void *thread;
    long count;
} OSMutex;

extern void MI_CpuFill8(void *dst, unsigned char data, unsigned long size);
extern void OS_InitMutex(void *mutex);
extern int WCMi_GetSystemWork(void);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void OS_LockMutex(void *mutex);
extern void OS_UnlockMutex(void *mutex);
extern long WCMi_WmifSetDCFData(unsigned char *dstAddr, unsigned short *buf, unsigned short len, void (*callback)(long));
extern int OS_IsRunOnTwl(void);
extern void WCMi_NwmifSetDCFData();
extern void OS_WakeupThread(void *queue);
extern void MI_CpuCopy(void *src, void *dst, unsigned long size);
extern void func_02082EA4(char *p, int a, int n);
void WCMi_InitCpsif(void);
void WCMi_CpsifRecvCallback(unsigned char *s, unsigned char *d, unsigned char *dat, long len);
void *WCMi_GetCpsifWork(void);
unsigned char *WCM_GetApMacAddress(void);
unsigned char *WCM_GetApEssid(unsigned short *length);
void WCM_SetRecvDCFCallback(void (*callback)(unsigned char *, unsigned char *, unsigned char *, long));
long WCM_SendDCFDataEx(unsigned char *dstAddr, unsigned char *header, long headerLen, unsigned char *body, long bodyLen);
void WCMi_CpsifUnlockMutexInIRQ(OSMutex *mutex);
void WCMi_CpsifSetMacAddress(void *mac);
void WCM_GetMacAddress(int a);
unsigned long WCMi_MergeToBuffer(unsigned char deviceId, unsigned short *sendBuf, void *header, unsigned long headerLen, void *body, unsigned long bodyLen);
extern WcmCpsifWork gWcmCpsifWork;
extern char gWcmCpsifMac[];
extern unsigned char gWcmCpsifMutex[];
extern int OS_IrqHandler;


/*
 * sdk:      WCMi_InitCpsif (libwcm.TWL.HYB.a cpsif.o)
 *
 * One-time initialisation of the CPS interface work: clears the MAC address and the state words, then initialises the send mutex.
 */
void WCMi_InitCpsif(void)
{
    if (gWcmCpsifWork.inited != 0) {
        return;
    }
    gWcmCpsifWork.inited = 1;
    gWcmCpsifWork.reserved24 = 0;
    MI_CpuFill8(gWcmCpsifMac, 0, 6);
    gWcmCpsifWork.reserved8 = 0;
    gWcmCpsifWork.reserved4 = 0;
    OS_InitMutex(gWcmCpsifWork.mutex);
}


/*
 * sdk: WCMi_CpsifRecvCallback (cpsif.o)
 *
 * Forwards its four arguments to the receive callback at +0x28 of the
 * cpsif work block, if one is set.
 */
void WCMi_CpsifRecvCallback(unsigned char *s, unsigned char *d, unsigned char *dat, long len)
{
    if (gWcmCpsifWork.recvCb != 0)
        gWcmCpsifWork.recvCb(s, d, dat, len);
}


void *WCMi_GetCpsifWork(void)
{
    return &gWcmCpsifWork;
}





/*
 * sdk:      WCM_GetApMacAddress (libwcm.TWL.HYB.a cpsif.o)
 *
 * Returns the connected AP BSSID from the WCM work area, or 0 when not connected.
 */
unsigned char *WCM_GetApMacAddress(void)
{
    unsigned char *mac;
    WCMWork_02166384 *w;
    unsigned long e;

    mac = 0;
    w = (WCMWork_02166384 *)WCMi_GetSystemWork();
    e = OS_DisableInterrupts();
    if (w != 0) {
        if (w->phase == 9 && w->resetting == 0) {
            mac = w->bssid;
        }
    }
    OS_RestoreInterrupts(e);
    return mac;
}





/*
 * sdk:      WCM_GetApEssid (libwcm.TWL.HYB.a cpsif.o)
 *
 * Returns the connected AP ESSID and stores its length through the optional out pointer.
 */
unsigned char *WCM_GetApEssid(unsigned short *length)
{
    unsigned char *essid;
    unsigned short len;
    WCMWork_021663C8 *w;
    unsigned long e;

    essid = 0;
    len = 0;
    w = (WCMWork_021663C8 *)WCMi_GetSystemWork();
    e = OS_DisableInterrupts();
    if (w != 0) {
        if (w->phase == 9 && w->resetting == 0) {
            essid = w->essid;
            len = w->essidLen;
        }
    }
    OS_RestoreInterrupts(e);
    if (length != 0) {
        *length = len;
    }
    return essid;
}





/*
 * sdk:      WCM_SetRecvDCFCallback (libwcm.TWL.HYB.a cpsif.o)
 *
 * Installs the DCF receive callback in the CPS interface work under a critical section.
 */
void WCM_SetRecvDCFCallback(void (*callback)(unsigned char *, unsigned char *, unsigned char *, long))
{
    unsigned long e;

    e = OS_DisableInterrupts();
    gWcmCpsifWork.recvCb = callback;
    OS_RestoreInterrupts(e);
}





/*
 * sdk:      WCM_SendDCFDataEx (libwcm.TWL.HYB.a cpsif.o)
 *
 * Sends a DCF frame: merges header and body into the send buffer under the CPS interface mutex, then dispatches to the WM or NWM sender by device id.
 */
long WCM_SendDCFDataEx(unsigned char *dstAddr, unsigned char *header, long headerLen, unsigned char *body, long bodyLen)
{
    unsigned long totalLen;
    WCMWork_02166444 *w;
    unsigned long e;

    e = OS_DisableInterrupts();
    w = (WCMWork_02166444 *)WCMi_GetSystemWork();
    if (w == 0) {
        OS_RestoreInterrupts(e);
        return -1;
    }
    OS_LockMutex(gWcmCpsifMutex);
    w = (WCMWork_02166444 *)WCMi_GetSystemWork();
    if (w == 0) {
        OS_UnlockMutex(gWcmCpsifMutex);
        OS_RestoreInterrupts(e);
        return -1;
    }
    if (w->phase != 9 || w->resetting == 1) {
        OS_UnlockMutex(gWcmCpsifMutex);
        OS_RestoreInterrupts(e);
        return -4;
    }
    totalLen = WCMi_MergeToBuffer(w->deviceId, w->sendBuf, header, headerLen, body, bodyLen);
    switch (w->deviceId) {
    case 1:
        WCMi_WmifSetDCFData(dstAddr, w->sendBuf, (unsigned short)totalLen, 0);
        break;
    case 2:
        if (OS_IsRunOnTwl()) {
            WCMi_NwmifSetDCFData(dstAddr, w->sendBuf, (unsigned short)totalLen, 0);
        }
        break;
    }
    OS_UnlockMutex(gWcmCpsifMutex);
    OS_RestoreInterrupts(e);
    return headerLen + bodyLen;
}





/*
 * sdk:      WCMi_CpsifUnlockMutexInIRQ (libwcm.TWL.HYB.a cpsif.o)
 *
 * Releases a mutex from IRQ context: drops one lock level owned by the IRQ handler and wakes waiters.
 */
void WCMi_CpsifUnlockMutexInIRQ(OSMutex *mutex)
{
    if (mutex->thread == (void *)&OS_IrqHandler) {
        if (--mutex->count == 0) {
            mutex->thread = 0;
            OS_WakeupThread(mutex);
        }
    }
}





void WCMi_CpsifSetMacAddress(void *mac)
{
	MI_CpuCopy(mac, gWcmCpsifMac, 6);
}




/*
 * Copies six bytes to the object at 0x021AA80C.
 */
void WCM_GetMacAddress(int a)
{
    func_02082EA4(gWcmCpsifMac, a, 6);
}




/*
 * sdk:      WCMi_MergeToBuffer (libwcm.TWL.HYB.a cpsif.o)
 *
 * Merges a frame header and body into the send buffer; device 2 prefixes a byte-swapped length word.
 * Earlier waves parked this as a store-motion wall (shared case-1/default `copyDest = sendBuf`
 * hoisted above the compares). It was register coalescing: with no interference the copy merged
 * sendBuf and copyDest into r6 at entry. 2026-10-01 lane22 closed it: case 2 assigns copyDest
 * before the length store through sendBuf, so both are live together and stay apart; the swap is
 * high-byte-first with an unsigned 0xff00U mask (lsr, operand order).
 */
unsigned long WCMi_MergeToBuffer(unsigned char deviceId, unsigned short *sendBuf, void *header, unsigned long headerLen, void *body, unsigned long bodyLen)
{
    void *copyDest;
    unsigned long totalLen;
    totalLen = headerLen + bodyLen;
    switch (deviceId) {
    case 1:
    default:
        copyDest = sendBuf;
        break;
    case 2:
        copyDest = sendBuf + 7;
        sendBuf[6] = (unsigned short)((((unsigned short)totalLen & 0xff00U) >> 8) | (((unsigned short)totalLen & 0xff) << 8));
        totalLen += 0xE;
        break;
    }
    MI_CpuCopy(header, copyDest, headerLen);
    if (body != 0 && bodyLen != 0) {
        MI_CpuCopy(body, (unsigned char *)copyDest + headerLen, bodyLen);
    }
    return totalLen;
}
