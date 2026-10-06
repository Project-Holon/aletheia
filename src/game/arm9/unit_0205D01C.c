/*
 * file:     unit_0205D01C.c
 * unit:     yes
 * function: func_0205D01C, func_0205D074
 * address:  0x0205D01C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWC_CheckWiFiStation 0x0205CE84 arm
 *   DWC_CheckNintendoZone 0x0205CF30 arm
 *   DWC_ProcessInet 0x0205C8E0 arm
 *   func_0205CCAC 0x0205CCAC arm
 *   DWC_AC_GetApType 0x0205BDD0 arm
 *   WCM_GetPhase 0x021656A0 arm
 *   DWCi_SetError 0x02059F54 arm
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
extern void DWC_ProcessInet(void);
extern int func_0205CCAC(void);
extern unsigned char DWC_AC_GetApType(void);
extern long WCM_GetPhase(void);
extern void DWCi_SetError(int error, int errorCode);
int func_0205D01C(void *work, WMBssDesc *bssdesc, DWCApInfo *apinfo);
int func_0205D074(void);


/*
 * sdk:      DWC_ParseWMBssDesc (dwc_connectinet.o)
 */
int func_0205D01C(void *work, WMBssDesc *bssdesc, DWCApInfo *apinfo)
{
    if (work == 0 || bssdesc == 0 || apinfo == 0) {
        return 0;
    }
    if (DWC_CheckWiFiStation(bssdesc->ssid, bssdesc->ssidLength, apinfo)) {
        return 1;
    }
    return DWC_CheckNintendoZone(work, bssdesc, apinfo) ? 1 : 0;
}


/*
 * sdk:      DWC_UpdateConnection (dwc_connectinet.o)
 */
int func_0205D074(void)
{
    unsigned char aptype;

    DWC_ProcessInet();
    if (func_0205CCAC()) {
        aptype = DWC_AC_GetApType();
        if (aptype == 0xff || aptype > 99) {
            aptype = 99;
        }
        if (WCM_GetPhase() == 11) {
            DWCi_SetError(9, -54900 - aptype);
        } else {
            DWCi_SetError(8, -54000 - aptype);
        }
        return 1;
    }
    return 0;
}
