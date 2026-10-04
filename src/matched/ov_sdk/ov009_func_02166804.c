/*
 * function: func_02166804
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
 *   func_021657C8  0x021657C8  arm  ov009
 *   g_021AA814  0x021AA814  data ov009
 *   g_021AA815  0x021AA815  data ov009
 *
 * Stores an RSSI sample into the ring buffer, converting the raw value first for device 1.
 */

typedef struct WCMWork {
    unsigned char pad0[0x12DF];
    unsigned char deviceId;
} WCMWork;

extern unsigned char g_021AA814;
extern unsigned char g_021AA815[16];
extern int func_021657C8(void);

void func_02166804(unsigned char rssi)
{
    WCMWork *w;
    int raw;

    w = (WCMWork *)func_021657C8();
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
    g_021AA815[g_021AA814 % 16] = rssi;
    if (g_021AA814 < 16) {
        g_021AA814 = (unsigned char)(g_021AA814 + 1);
    } else {
        g_021AA814 = (unsigned char)((g_021AA814 + 1) % 16 + 16);
    }
}
