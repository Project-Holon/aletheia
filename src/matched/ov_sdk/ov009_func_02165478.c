/*
 * function: func_02165478
 * address:  0x02165478
 * packet:   pkt_ov009_02165478
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCM_DisconnectAsync (libwcm.TWL.HYB.a system.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   func_02165A4C  0x02165A4C  arm  ov009
 *   func_02166BD8  0x02166BD8  arm  ov009
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   func_02731CFC  0x02731CFC  arm  twl
 *   g_021AA7D4  0x021AA7D4  data ov009
 *
 * Requests disconnection: valid only in the connected phase, either flagging the reset or dispatching to the WM or NWM disconnect.
 */

typedef struct WCMWork {
    unsigned char pad0[0x12DA];
    unsigned short notify;
    unsigned char pad1[1];
    unsigned char resetting;
    unsigned char phase;
    unsigned char deviceId;
} WCMWork;

typedef struct WCMState {
    long pad0;
    WCMWork *work;
} WCMState;

extern WCMState g_021AA7D4;
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void func_02165A4C(unsigned char phase);
extern long func_02166BD8(void);
extern int OS_IsRunOnTwl(void);
extern long func_02731CFC(void);

long func_02165478(void)
{
    unsigned long e;
    long wcmResult;

    e = OS_DisableInterrupts();
    wcmResult = 0;
    if (g_021AA7D4.work == 0) {
        OS_RestoreInterrupts(e);
        return 1;
    }
    switch (g_021AA7D4.work->phase) {
    case 10:
        OS_RestoreInterrupts(e);
        return 2;
    case 3:
        OS_RestoreInterrupts(e);
        return wcmResult;
    default:
        OS_RestoreInterrupts(e);
        return 1;
    case 9:
        break;
    }
    if (g_021AA7D4.work->resetting == 1) {
        func_02165A4C(10);
        g_021AA7D4.work->notify = 6;
    } else {
        switch (g_021AA7D4.work->deviceId) {
        case 1:
            wcmResult = func_02166BD8();
            break;
        case 2:
            if (OS_IsRunOnTwl()) {
                wcmResult = func_02731CFC();
                break;
            }
        default:
            wcmResult = 7;
            break;
        }
    }
    OS_RestoreInterrupts(e);
    return wcmResult;
}
