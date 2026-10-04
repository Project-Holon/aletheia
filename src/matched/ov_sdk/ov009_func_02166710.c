/*
 * function: func_02166710
 * address:  0x02166710
 * packet:   pkt_ov009_02166710
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCM_CalcLinkLevel (libwcm.TWL.HYB.a util.o)
 *
 * symbols:
 *   func_021657C8  0x021657C8  arm  ov009
 *
 * Maps an RSSI value to a link level, with per-device thresholds.
 */

typedef enum WMLinkLevel {
    WM_LINK_LEVEL_0 = 0,
    WM_LINK_LEVEL_1 = 1,
    WM_LINK_LEVEL_2 = 2,
    WM_LINK_LEVEL_3 = 3
} WMLinkLevel;

typedef struct WCMWork {
    unsigned char pad0[0x12DF];
    unsigned char deviceId;
} WCMWork;

extern int func_021657C8(void);

WMLinkLevel func_02166710(unsigned char rssi)
{
    WCMWork *w;

    w = (WCMWork *)func_021657C8();
    switch (w->deviceId) {
    case 1:
    default:
        if (rssi >= 0x1C) {
            return WM_LINK_LEVEL_3;
        }
        if (rssi >= 0x16) {
            return WM_LINK_LEVEL_2;
        }
        if (rssi >= 0x10) {
            return WM_LINK_LEVEL_1;
        }
        return WM_LINK_LEVEL_0;
    case 2:
        if (rssi >= 0x16) {
            return WM_LINK_LEVEL_3;
        }
        if (rssi >= 0x11) {
            return WM_LINK_LEVEL_2;
        }
        if (rssi >= 0xC) {
            return WM_LINK_LEVEL_1;
        }
        return WM_LINK_LEVEL_0;
    }
}
