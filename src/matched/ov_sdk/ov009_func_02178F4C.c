/*
 * function: func_02178F4C
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
 *   func_02178F78        0x02178F78  arm  ov009
 */

typedef struct {
    char bytes[0x14];
} WiFiInfo;
extern void DWCi_BM_GetWiFiInfo(WiFiInfo *buf);
struct DWCCalInfo;
struct DWCWiFiInfo;
extern int func_02178F78(struct DWCCalInfo *cal, struct DWCWiFiInfo *wifiinfo);

int func_02178F4C(void *cal)
{
    WiFiInfo wifiinfo;
    DWCi_BM_GetWiFiInfo(&wifiinfo);
    return func_02178F78(cal, (struct DWCWiFiInfo *)(&wifiinfo));
}
