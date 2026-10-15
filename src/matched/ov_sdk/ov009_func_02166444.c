/*
 * function: func_02166444
 * address:  0x02166444
 * packet:   pkt_ov009_02166444
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCM_SendDCFDataEx (libwcm.TWL.HYB.a cpsif.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   WCMi_GetSystemWork  0x021657C8  arm  ov009
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   OS_LockMutex  0x02086028  arm
 *   OS_UnlockMutex 0x02086078  arm
 *   func_02166600  0x02166600  arm  ov009
 *   WCMi_WmifSetDCFData  0x02166D2C  arm  ov009
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   WCMi_NwmifSetDCFData  0x02731E50  arm  twl
 *   g_021AA7E8     0x021AA7E8  data ov009
 *
 * Sends a DCF frame: merges header and body into the send buffer under the CPS interface mutex, then dispatches to the WM or NWM sender by device id.
 */

typedef struct WCMWork {
    unsigned short sendBuf[768];
    unsigned char pad0[0x12DD - 0x600];
    unsigned char resetting;
    unsigned char phase;
    unsigned char deviceId;
} WCMWork;

extern unsigned char g_021AA7E8[];
extern unsigned long OS_DisableInterrupts(void);
extern int WCMi_GetSystemWork(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void OS_LockMutex(void *mutex);
extern void OS_UnlockMutex(void *mutex);
extern unsigned long func_02166600(unsigned char deviceId, unsigned short *sendBuf, void *header, unsigned long headerLen, void *body, unsigned long bodyLen);
extern long WCMi_WmifSetDCFData(unsigned char *dstAddr, unsigned short *buf, unsigned short len, void (*callback)(long));
extern int OS_IsRunOnTwl(void);
extern void WCMi_NwmifSetDCFData();

long func_02166444(unsigned char *dstAddr, unsigned char *header, long headerLen, unsigned char *body, long bodyLen)
{
    unsigned long totalLen;
    WCMWork *w;
    unsigned long e;

    e = OS_DisableInterrupts();
    w = (WCMWork *)WCMi_GetSystemWork();
    if (w == 0) {
        OS_RestoreInterrupts(e);
        return -1;
    }
    OS_LockMutex(g_021AA7E8);
    w = (WCMWork *)WCMi_GetSystemWork();
    if (w == 0) {
        OS_UnlockMutex(g_021AA7E8);
        OS_RestoreInterrupts(e);
        return -1;
    }
    if (w->phase != 9 || w->resetting == 1) {
        OS_UnlockMutex(g_021AA7E8);
        OS_RestoreInterrupts(e);
        return -4;
    }
    totalLen = func_02166600(w->deviceId, w->sendBuf, header, headerLen, body, bodyLen);
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
    OS_UnlockMutex(g_021AA7E8);
    OS_RestoreInterrupts(e);
    return headerLen + bodyLen;
}
