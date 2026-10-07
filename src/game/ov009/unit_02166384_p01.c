/*
 * file:     unit_02166384_p01.c
 * unit:     yes
 * function: func_02166384, func_021663C8, func_02166424, func_02166444
 * address:  0x02166384
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
 *   func_021657C8  0x021657C8  arm  ov009
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   g_021AA7DC  0x021AA7DC  data ov009
 *   func_02086028  0x02086028  arm
 *   OS_UnlockMutex 0x02086078  arm
 *   func_02166600  0x02166600  arm  ov009
 *   func_02166D2C  0x02166D2C  arm  ov009
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   func_02731E50  0x02731E50  arm  twl
 *   g_021AA7E8     0x021AA7E8  data ov009
 */
#include "../../matched/include/G_ov009_021AA7DC.h"

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

extern int func_021657C8(void);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void func_02086028(void *mutex);
extern void OS_UnlockMutex(void *mutex);
extern unsigned long func_02166600(unsigned char deviceId, unsigned short *sendBuf, void *header, unsigned long headerLen, void *body, unsigned long bodyLen);
extern long func_02166D2C(unsigned char *dstAddr, unsigned short *buf, unsigned short len, void (*callback)(long));
extern int OS_IsRunOnTwl(void);
extern void func_02731E50();
unsigned char *func_02166384(void);
unsigned char *func_021663C8(unsigned short *length);
void func_02166424(void (*callback)(unsigned char *, unsigned char *, unsigned char *, long));
long func_02166444(unsigned char *dstAddr, unsigned char *header, long headerLen, unsigned char *body, long bodyLen);
extern struct G_ov009_021AA7DC g_021AA7DC;
extern unsigned char g_021AA7E8[];


/*
 * sdk:      WCM_GetApMacAddress (libwcm.TWL.HYB.a cpsif.o)
 *
 * Returns the connected AP BSSID from the WCM work area, or 0 when not connected.
 */
unsigned char *func_02166384(void)
{
    unsigned char *mac;
    WCMWork_02166384 *w;
    unsigned long e;

    mac = 0;
    w = (WCMWork_02166384 *)func_021657C8();
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
unsigned char *func_021663C8(unsigned short *length)
{
    unsigned char *essid;
    unsigned short len;
    WCMWork_021663C8 *w;
    unsigned long e;

    essid = 0;
    len = 0;
    w = (WCMWork_021663C8 *)func_021657C8();
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
void func_02166424(void (*callback)(unsigned char *, unsigned char *, unsigned char *, long))
{
    unsigned long e;

    e = OS_DisableInterrupts();
    g_021AA7DC.recvCb = callback;
    OS_RestoreInterrupts(e);
}


/*
 * sdk:      WCM_SendDCFDataEx (libwcm.TWL.HYB.a cpsif.o)
 *
 * Sends a DCF frame: merges header and body into the send buffer under the CPS interface mutex, then dispatches to the WM or NWM sender by device id.
 */
long func_02166444(unsigned char *dstAddr, unsigned char *header, long headerLen, unsigned char *body, long bodyLen)
{
    unsigned long totalLen;
    WCMWork_02166444 *w;
    unsigned long e;

    e = OS_DisableInterrupts();
    w = (WCMWork_02166444 *)func_021657C8();
    if (w == 0) {
        OS_RestoreInterrupts(e);
        return -1;
    }
    func_02086028(g_021AA7E8);
    w = (WCMWork_02166444 *)func_021657C8();
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
        func_02166D2C(dstAddr, w->sendBuf, (unsigned short)totalLen, 0);
        break;
    case 2:
        if (OS_IsRunOnTwl()) {
            func_02731E50(dstAddr, w->sendBuf, (unsigned short)totalLen, 0);
        }
        break;
    }
    OS_UnlockMutex(g_021AA7E8);
    OS_RestoreInterrupts(e);
    return headerLen + bodyLen;
}
