/*
 * function: WCMi_ShelterRssi
 * address:  0x02166804
 * packet:   pkt_ov009_02166804
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCMi_ShelterRssi (libwcm.TWL.HYB.a util.o)
 *
 * symbols:
 *   WCMi_GetSystemWork  0x021657C8  arm  ov009
 *   gWcmUtilLength  0x021AA814  data ov009
 *   gWcmUtilData  0x021AA815  data ov009
 *
 * Stores an RSSI sample into the ring buffer, converting the raw value first for device 1.
 */

typedef struct WCMWork {
    unsigned char pad0[0x12DF];
    unsigned char deviceId;
} WCMWork;

extern unsigned char gWcmUtilLength;
extern unsigned char gWcmUtilData[16];
extern int WCMi_GetSystemWork(void);

void WCMi_ShelterRssi(unsigned char rssi)
{
    WCMWork *w;
    int raw;

    w = (WCMWork *)WCMi_GetSystemWork();
    switch (w->deviceId) {
    case 1:
    default:
        raw = rssi >> 2;
        if ((rssi & 2) != 0) {
            rssi = (unsigned char)raw;
        } else {
            rssi = (unsigned char)(raw + 0x19);
        }
        break;
    case 2:
        break;
    }
    gWcmUtilData[gWcmUtilLength % 16] = rssi;
    if (gWcmUtilLength < 16) {
        gWcmUtilLength = (unsigned char)(gWcmUtilLength + 1);
    } else {
        gWcmUtilLength = (unsigned char)((gWcmUtilLength + 1) % 16 + 16);
    }
}
