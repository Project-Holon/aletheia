/*
 * function: DWC_Auth_GetCalInfoFromNVRAM
 * address:  0x02178F4C
 * packet:   pkt_ov009_02178F4C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Auth_GetCalInfoFromNVRAM (dwc_cal.o)
 *
 * symbols:
 *   DWCi_BM_GetWiFiInfo  0x02058518  arm
 *   DWC_Auth_GetCalInfoFromWiFiInfo        0x02178F78  arm  ov009
 */

typedef struct {
    char bytes[0x14];
} WiFiInfo;
extern void DWCi_BM_GetWiFiInfo(WiFiInfo *buf);
struct DWCCalInfo;
struct DWCWiFiInfo;
extern int DWC_Auth_GetCalInfoFromWiFiInfo(struct DWCCalInfo *cal, struct DWCWiFiInfo *wifiinfo);

int DWC_Auth_GetCalInfoFromNVRAM(void *cal)
{
    WiFiInfo wifiinfo;
    DWCi_BM_GetWiFiInfo(&wifiinfo);
    return DWC_Auth_GetCalInfoFromWiFiInfo(cal, (struct DWCWiFiInfo *)(&wifiinfo));
}
