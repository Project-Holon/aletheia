/*
 * function: DWC_ParseWMBssDesc
 * address:  0x0205D01C
 * packet:   pkt_0205D01C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_ParseWMBssDesc (dwc_connectinet.o)
 *
 * symbols:
 *   DWC_CheckWiFiStation 0x0205CE84 arm
 *   DWC_CheckNintendoZone 0x0205CF30 arm
 */

typedef struct {
    int aptype;
    int area;
    int security;
    char spotinfo[10];
    char essid[33];
    unsigned char bssid[6];
} DWCApInfo;

typedef struct {
    unsigned short length;
    unsigned short rssi;
    unsigned char bssid[6];
    unsigned short ssidLength;
    unsigned char ssid[32];
} WMBssDesc;

extern int DWC_CheckWiFiStation(void *ssid, unsigned short len, DWCApInfo *apinfo);
extern int DWC_CheckNintendoZone(void *work, WMBssDesc *bssdesc, DWCApInfo *apinfo);

int DWC_ParseWMBssDesc(void *work, WMBssDesc *bssdesc, DWCApInfo *apinfo)
{
    if (work == 0 || bssdesc == 0 || apinfo == 0) {
        return 0;
    }
    if (DWC_CheckWiFiStation(bssdesc->ssid, bssdesc->ssidLength, apinfo)) {
        return 1;
    }
    return DWC_CheckNintendoZone(work, bssdesc, apinfo) ? 1 : 0;
}
