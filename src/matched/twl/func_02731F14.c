/*
 * function: WcmNwmReset
 * address:  0x02731F14
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021657C8  0x021657C8  arm  ov009
 *   func_02165A4C  0x02165A4C  arm  ov009
 *   func_021659B4  0x021659B4  arm  ov009
 *   NWM_Close  0x02702FE8  arm  twl
 *   WcmNwmcbCommon  0x027320D0  arm  twl
 */

typedef unsigned int u32;
typedef unsigned short u16; typedef unsigned char u8;
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
extern NetWork *func_021657C8(void);
extern void func_02165A4C(unsigned char phase);
extern void func_021659B4(u32 a, void *b, u32 c, u32 d);
extern u32 NWM_Close(void *arg);
void WcmNwmcbCommon(u16 *arg);
void WcmNwmReset(void)
{
    NetWork *w = func_021657C8();
    u16 tx;

    if (w->stopFlag != 0) {
        return;
    }
    /* WcmNwmReset (libwcm nwmif.o): its line table puts a constant 1 on a
       line of its own before the store of 0, so the source sets the flag
       and then clears it; the dead first store leaves the 1 in a register. */
    w->stopFlag = 1;
    w->stopFlag = 0;
    w->rxFlag = 0;
    switch (w->state) {
    case 5:
    case 6:
        func_02165A4C(3);
        func_021659B4(1, 0, 0, 667);
        return;
    case 7:
        func_02165A4C(3);
        func_021659B4(0, 0, 0, 673);
        return;
    case 8:
        tx = w->txFlag;
        w->txFlag = 0;
        func_02165A4C(3);
        func_021659B4(1, w->buf, tx, 683);
        return;
    case 9:
    case 12:
        func_02165A4C(3);
        func_021659B4(0, w->buf, 1, 691);
        return;
    case 10:
        func_02165A4C(3);
        func_021659B4(0, w->buf, 0, 698);
        return;
    case 13:
        switch (NWM_Close(WcmNwmcbCommon)) {
        case 2:
            return;
        case 6:
            func_02165A4C(12);
            func_021659B4(1, 0, 0, 712);
            return;
        case 3:
        default:
            func_02165A4C(11);
            func_021659B4(7, 0, 0, 721);
            return;
        }
    default:
        func_02165A4C(11);
        func_021659B4(7, 0, w->state, 727);
        return;
    }
}
