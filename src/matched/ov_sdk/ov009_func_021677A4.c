/*
 * function: WcmWmcbStartDCF
 * address:  0x021677A4
 * packet:   pkt_ov009_021677A4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WcmWmcbStartDCF (libwcm.TWL.HYB.a wmif.o)
 *
 * symbols:
 *   WCMi_GetSystemWork    0x021657C8  arm  ov009
 *   WCMi_SetPhase    0x02165A4C  arm  ov009
 *   func_02166E5C    0x02166E5C  arm  ov009
 *   func_021659B4    0x021659B4  arm  ov009
 *   WCMi_ShelterRssi    0x02166804  arm  ov009
 *   DC_InvalidateRange 0x020862B8  arm
 *   WCMi_CpsifRecvCallback    0x02166358  arm  ov009
 */

typedef struct WMDcfRecvBuf {
    unsigned char pad0[6];
    unsigned short length;
    unsigned char pad1[6];
    unsigned short rateRssi;
    unsigned char pad2[8];
    unsigned char destAdrs[6];
    unsigned char srcAdrs[6];
    unsigned char pad3[8];
    unsigned char data[1];
} WMDcfRecvBuf;

typedef struct WMStartDCFCallback {
    unsigned short apiid;
    unsigned short errcode;
    unsigned short state;
    unsigned char pad[2];
    WMDcfRecvBuf *recv;
} WMStartDCFCallback;

typedef struct WCMWork {
    unsigned char pad0[0x12DE];
    unsigned char phase;
    unsigned char pad1[0x12E0 - 0x12DF];
    unsigned char notifyParam[1];
} WCMWork;

extern int WCMi_GetSystemWork(void);
extern void WCMi_SetPhase(unsigned char phase);
extern void func_02166E5C(void);
extern void func_021659B4(short result, void *para0, void *para1, long para2);
extern void WCMi_ShelterRssi(unsigned char rssi);
extern void DC_InvalidateRange(void *startAddr, unsigned long nBytes);
extern void WCMi_CpsifRecvCallback(unsigned char *srcAdrs, unsigned char *destAdrs, unsigned char *data, long length);

void WcmWmcbStartDCF(void *arg)
{
    WCMWork *wcmw;
    WMStartDCFCallback *cb;

    cb = arg;
    wcmw = (WCMWork *)WCMi_GetSystemWork();
    if (cb->errcode == 0) {
        switch (cb->state) {
        case 0xe:
            if (wcmw->phase == 0xc) {
                WCMi_SetPhase(8);
                func_02166E5C();
                return;
            }
            WCMi_SetPhase(9);
            func_021659B4(0, wcmw->notifyParam, 0, 0x4b7);
            return;
        case 0xf:
            WCMi_ShelterRssi((cb->recv->rateRssi >> 8) & 0xff);
            DC_InvalidateRange(cb->recv, 0x620);
            WCMi_CpsifRecvCallback(cb->recv->srcAdrs, cb->recv->destAdrs, cb->recv->data, cb->recv->length);
            return;
        default:
            WCMi_SetPhase(0xb);
            func_021659B4(7, wcmw->notifyParam, (void *)cb->state, 0x4c6);
            return;
        }
    } else {
        WCMi_SetPhase(0xb);
        func_021659B4(7, wcmw->notifyParam, 0, 0x4d1);
    }
}
