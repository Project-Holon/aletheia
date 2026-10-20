/*
 * file:     wcm_util.c
 * unit:     yes
 * function: WcmCompareMemory, WCM_CompareBssID, WCM_GetLinkLevel, WCM_CalcLinkLevel, WCMi_GetRssiAverage, WCMi_ShelterRssi
 * address:  0x02166680
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
 *   OS_DisableInterrupts  0x02087988  arm
 *   WCMi_GetSystemWork  0x021657C8  arm  ov009
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   _s32_div_f  0x0209C0A4  arm
 *   gWcmUtilLength  0x021AA814  data ov009
 *   gWcmUtilData  0x021AA815  data ov009
 */
#include "wcm_types.h"

#include "../sdk_wm.h"

typedef unsigned int OSIntrMode;
#include "../arm9/os_system.h"
#include "wcm_system.h"
int WcmCompareMemory(unsigned char *a, unsigned char *b, unsigned int n);
int WCM_CompareBssID(unsigned char *a, unsigned char *b);
WMLinkLevel WCM_GetLinkLevel(void);
WMLinkLevel WCM_CalcLinkLevel(unsigned char rssi);
unsigned char WCMi_GetRssiAverage(void);
void WCMi_ShelterRssi(unsigned char rssi);
extern unsigned char gWcmUtilLength;
extern unsigned char gWcmUtilData[16];

/*
 * Byte compare over n units: 0 at the first difference, 1 when all agree.
 */
int WcmCompareMemory(unsigned char *a, unsigned char *b, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        if (a[i] != b[i]) return 0;
    return 1;
}


int WCM_CompareBssID(unsigned char *a, unsigned char *b)
{
    return WcmCompareMemory(a, b, 6);
}


/*
 * sdk:      WCM_GetLinkLevel (libwcm.TWL.HYB.a util.o)
 *
 * Returns the current link level from the averaged RSSI while connected, else level 0.
 */
WMLinkLevel WCM_GetLinkLevel(void)
{
    unsigned long e;
    WCMWork *w;
    WMLinkLevel ret;

    e = OS_DisableInterrupts();
    w = WCMi_GetSystemWork();
    ret = WM_LINK_LEVEL_0;
    if (w != 0 && w->phase == 9) {
        ret = WCM_CalcLinkLevel(WCMi_GetRssiAverage());
    }
    OS_RestoreInterrupts(e);
    return ret;
}


/*
 * sdk:      WCM_CalcLinkLevel (libwcm.TWL.HYB.a util.o)
 *
 * Maps an RSSI value to a link level, with per-device thresholds.
 */
WMLinkLevel WCM_CalcLinkLevel(unsigned char rssi)
{
    WCMWork *w;

    w = WCMi_GetSystemWork();
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


/*
 * sdk:      WCMi_GetRssiAverage (libwcm.TWL.HYB.a util.o)
 *
 * Averages the sheltered RSSI ring buffer: 16 samples once the ring is full, otherwise the samples stored so far.
 */
unsigned char WCMi_GetRssiAverage(void)
{
    long sum;
    long i;

    sum = 0;
    if (gWcmUtilLength > 16) {
        for (i = 0; i < 16; i++) {
            sum += gWcmUtilData[i];
        }
        sum = sum / 16;
    } else if (gWcmUtilLength != 0) {
        for (i = 0; i < gWcmUtilLength; i++) {
            sum += gWcmUtilData[i];
        }
        sum = sum / gWcmUtilLength;
    }
    return (unsigned char)sum;
}


/*
 * sdk:      WCMi_ShelterRssi (libwcm.TWL.HYB.a util.o)
 *
 * Stores an RSSI sample into the ring buffer, converting the raw value first for device 1.
 */
void WCMi_ShelterRssi(unsigned char rssi)
{
    WCMWork *w;
    int raw;

    w = WCMi_GetSystemWork();
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
