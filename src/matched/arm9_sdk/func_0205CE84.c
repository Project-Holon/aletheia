/*
 * function: func_0205CE84
 * address:  0x0205CE84
 * packet:   pkt_0205CE84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      DWC_CheckWiFiStation (dwc_connectinet.o)
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   DWC_AC_CheckWiFiStation 0x0205BFD4 arm
 *   DWCi_AC_GetPostalCode 0x0205EA70 arm
 *   func_0205CCE4 0x0205CCE4 arm
 */

typedef struct {
    int aptype;
    int area;
    int security;
    char spotinfo[10];
    char essid[33];
    unsigned char bssid[6];
} DWCApInfo;

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int DWC_AC_CheckWiFiStation(void *ssid, unsigned short len);
extern int DWCi_AC_GetPostalCode(char *ssid, unsigned char *pos);
extern void func_0205CCE4(char *fullapinfo, DWCApInfo *apinfo);

int func_0205CE84(void *ssid, unsigned short len, DWCApInfo *apinfo)
{
    unsigned char apSpotInfo[10];

    MI_CpuFill8(apSpotInfo, 0, 10);
    if (ssid == 0) {
        return 0;
    }
    if (DWC_AC_CheckWiFiStation(ssid, len)) {
        if (apinfo == 0) {
            return 1;
        }
        if (DWCi_AC_GetPostalCode(ssid, apSpotInfo)) {
            apinfo->aptype = 4;
            func_0205CCE4((char *)apSpotInfo, apinfo);
            return 1;
        }
    }
    return 0;
}
