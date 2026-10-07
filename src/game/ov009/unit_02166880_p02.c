/*
 * file:     unit_02166880_p02.c
 * unit:     yes
 * function: func_02166C44, func_02166D2C
 * address:  0x02166C44
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
 *   WMi_GetStatusAddress  0x0208E9C8  arm
 *   DC_InvalidateRange  0x020862B8  arm
 *   WM_Finish  0x0208E2B8  arm
 *   func_02165A4C  0x02165A4C  arm  ov009
 *   func_0208F2A0  0x0208F2A0  arm
 *   func_0208F328  0x0208F328  arm
 *   func_0208F400  0x0208F400  arm
 *   func_02166F24  0x02166F24  arm  ov009
 *   func_021679C0  0x021679C0  arm  ov009
 *   func_02166378  0x02166378  arm  ov009
 *   func_0208FF0C  0x0208FF0C  arm
 *   OS_SleepThread  0x020857B0  arm
 *   func_02167DE0  0x02167DE0  arm  ov009
 *   func_02167E20  0x02167E20  arm  ov009
 */
typedef struct WCMWork {
    unsigned char pad0[0x12DA];
    unsigned short notify;
    unsigned char pad1[1];
    unsigned char resetting;
} WCMWork;

typedef struct WMStatus {
    unsigned short state;
} WMStatus;

typedef struct WCMCpsifWork {
    unsigned char pad0[4];
    unsigned char queue[8];
    unsigned char pad1[0x18];
    unsigned short result;
    unsigned char pad2[6];
    void (*callback)(long);
} WCMCpsifWork;

extern int func_021657C8(void);
extern WMStatus *WMi_GetStatusAddress(void);
extern void DC_InvalidateRange(void *startAddr, unsigned long nBytes);
extern long WM_Finish(void);
extern void func_02165A4C(unsigned char phase);
extern long func_0208F2A0(void (*callback)(void *));
extern long func_0208F328(void (*callback)(void *));
extern long func_0208F400(void (*callback)(void *));
extern void func_02166F24(void *arg);
extern void func_021679C0(void *arg);
extern void *func_02166378(void);
extern long func_0208FF0C(void (*callback)(void *), unsigned char *destAdr, unsigned short *sendData, unsigned short sendDataSize);
extern void OS_SleepThread(void *queue);
extern void func_02167DE0(void *arg);
extern void func_02167E20(void *arg);
long func_02166C44(void);
long func_02166D2C(unsigned char *dstAddr, unsigned short *buf, unsigned short len, void (*callback)(long));


/*
 * sdk:      WCMi_WmifTerminateAsync (libwcm.TWL.HYB.a wmif.o)
 *
 * Terminates the WM link by walking the WM state down: finish, disable, power off or reset, then maps the result to a WCM result.
 */
long func_02166C44(void)
{
    WCMWork *wcmw;
    long wmResult;
    WMStatus *ws;

    wcmw = (WCMWork *)func_021657C8();
    ws = WMi_GetStatusAddress();
    DC_InvalidateRange(ws, 2);
    switch (ws->state) {
    case 0:
        wmResult = WM_Finish();
        if (wmResult == 0) {
            func_02165A4C(1);
            wcmw->notify = 0;
            return 0;
        }
        break;
    case 1:
        wmResult = func_0208F2A0(func_02166F24);
        break;
    case 2:
        wmResult = func_0208F328(func_02166F24);
        break;
    default:
        wcmw->resetting = 1;
        wmResult = func_0208F400(func_021679C0);
        break;
    }
    switch (wmResult) {
    case 2:
        func_02165A4C(13);
        wcmw->notify = 9;
        break;
    case 8:
        return 4;
    case 3:
    default:
        func_02165A4C(11);
        return 7;
    }
    return 3;
}


/*
 * sdk:      WCMi_WmifSetDCFData (libwcm.TWL.HYB.a wmif.o)
 *
 * Sends a DCF frame through WM; with a callback the send is asynchronous, otherwise the caller sleeps until the completion callback.
 */
long func_02166D2C(unsigned char *dstAddr, unsigned short *buf, unsigned short len, void (*callback)(long))
{
    WCMCpsifWork *wcmiw;
    long wmResult;

    wcmiw = func_02166378();
    if (callback == 0) {
        wmResult = func_0208FF0C(func_02167DE0, dstAddr, buf, len);
    } else {
        wcmiw->callback = callback;
        wmResult = func_0208FF0C(func_02167E20, dstAddr, buf, len);
    }
    switch (wmResult) {
    case 0:
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    default:
        return -5;
    case 2:
        if (callback == 0) {
            OS_SleepThread(wcmiw->queue);
            if (wcmiw->result != 0) {
                return -5;
            }
        }
        return len;
    }
}
