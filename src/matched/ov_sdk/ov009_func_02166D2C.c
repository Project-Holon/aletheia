/*
 * function: func_02166D2C
 * address:  0x02166D2C
 * packet:   pkt_ov009_02166D2C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCMi_WmifSetDCFData (libwcm.TWL.HYB.a wmif.o)
 *
 * symbols:
 *   func_02166378  0x02166378  arm  ov009
 *   func_0208FF0C  0x0208FF0C  arm
 *   OS_SleepThread  0x020857B0  arm
 *   func_02167DE0  0x02167DE0  arm  ov009
 *   func_02167E20  0x02167E20  arm  ov009
 *
 * Sends a DCF frame through WM; with a callback the send is asynchronous, otherwise the caller sleeps until the completion callback.
 */

typedef struct WCMCpsifWork {
    unsigned char pad0[4];
    unsigned char queue[8];
    unsigned char pad1[0x18];
    unsigned short result;
    unsigned char pad2[6];
    void (*callback)(long);
} WCMCpsifWork;

extern void *func_02166378(void);
extern long func_0208FF0C(void (*callback)(void *), unsigned char *destAdr, unsigned short *sendData, unsigned short sendDataSize);
extern void OS_SleepThread(void *queue);
extern void func_02167DE0(void *arg);
extern void func_02167E20(void *arg);

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
