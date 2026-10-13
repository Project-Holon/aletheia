/*
 * function: WcmNwmcbConnect
 * address:  0x02732648
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   WCMi_GetSystemWork  0x021657C8  arm  ov009
 *   NWM_GetState  0x027028B0  arm  twl
 *   WCMi_SetPhase  0x02165A4C  arm  ov009
 *   WcmNwmReset  0x02731F14  arm  twl
 *   func_021659B4  0x021659B4  arm  ov009
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct NetWork {
    u8 pad00[0x600];
    u8 recvBuf[0xc40];
    u8 peer[0x20];
    u8 pad0a[0x1290 - 0x1260];
    u8 mode;
    u8 submode;
    u8 pad0b[0x12c0 - 0x1292];
    u32 cmdArg;
    u8 pad0c[0x12d4 - 0x12c4];
    u32 linkFlags;
    u16 sync;
    short phase;
    u8 pad2a;
    u8 stopFlag;
    u8 state;
    u8 pad3;
    u8 buf[0x130c - 0x12e0];
    u16 optFlags;
    u8 pad4[0x13a0 - 0x130e];
    u8 rxBuf[0x3000];
    u32 sendBuf;
    u16 sendLen;
    u16 sendMask;
    u16 sendId;
    u16 sendFlag;
    u8 sendMac[6];
    u16 nameLen;
    u8 sendName[0x20];
    u16 nameLen2;
    u8 pad5[0x43e0 - 0x43d6];
    u32 sendCount;
    u16 rxFlag;
    u16 txFlag;
} NetWork;

extern NetWork *WCMi_GetSystemWork(void);
extern u32 NWM_GetState(void);
extern void WCMi_SetPhase(unsigned char phase);
extern void WcmNwmReset(void);
extern void func_021659B4(u32 a, void *b, u32 c, u32 d);

void WcmNwmcbConnect(u16 *arg)
{
    NetWork *w = WCMi_GetSystemWork();
    u32 cur = NWM_GetState();

    switch (arg[1]) {
    case 0:
        if (cur == 4) {
            if (w->state == 12) {
                WCMi_SetPhase(8);
                WcmNwmReset();
                return;
            }
            w->rxFlag = arg[7];
            WCMi_SetPhase(9);
            func_021659B4(0, w->buf, 0, 1078);
            return;
        }
        WCMi_SetPhase(11);
        func_021659B4(7, w->buf, 0, 1084);
        return;
    case 1:
        switch (arg[8]) {
        case 1:
        case 2:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
            switch (w->state) {
            case 9:
            case 10:
                w->phase = 6;
            case 8:
                w->rxFlag = 0;
                switch (arg[8]) {
                case 5:
                    w->txFlag = 13;
                    break;
                case 10:
                case 11:
                    w->txFlag = 15;
                    break;
                case 7:
                    w->txFlag = 17;
                    break;
                }
            case 12:
                WcmNwmReset();
                break;
            case 11:
                goto exit11;
            default:
                goto exit_default;
            }
            return;
        case 3:
            if (w->state == 8) {
                w->rxFlag = 0;
                WcmNwmReset();
            }
            return;
        default:
            WCMi_SetPhase(11);
            func_021659B4(7, w->buf, arg[8], 1153);
            return;
        }
    case 5:
        WCMi_SetPhase(8);
        WcmNwmReset();
        return;
    case 2:
    case 3:
    case 4:
    default:
        WCMi_SetPhase(11);
        func_021659B4(7, w->buf, 0, 1173);
        return;
    }
exit11:
    return;
exit_default:
    return;
}
