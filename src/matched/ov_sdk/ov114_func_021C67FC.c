/*
 * function: DWCi_Ndi_getDSdesc
 * address:  0x021C67FC
 * packet:   pkt_ov114_021C67FC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Ndi_getDSdesc (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * symbols:
 *   DWCi_Ndi_memclr  0x021C7A30  arm  ov114
 *   DWCi_BM_GetWiFiInfo  0x02058518  arm
 *   DWCi_Ndi_intToStrFigure  0x021C7A74  arm  ov114
 *   DWCi_Ndi_encodeBASE64  0x021C60C8  arm  ov114
 */

typedef struct {
	unsigned long long macid;
	int pad[3];
} WiFiInfo;

extern void DWCi_Ndi_memclr(int a, int b);
struct tagDWCWiFiInfo;
extern void DWCi_BM_GetWiFiInfo(struct tagDWCWiFiInfo *buf);
extern int DWCi_Ndi_intToStrFigure(char *p, unsigned long long n, int figure);
extern int DWCi_Ndi_encodeBASE64(char *encstr, char *srcbin, int length);

int DWCi_Ndi_getDSdesc(char *gamecode, char *userid)
{
	WiFiInfo wifiinfo;
	char strId[13];
	DWCi_Ndi_memclr((int)(&wifiinfo), 20);
	DWCi_BM_GetWiFiInfo((struct tagDWCWiFiInfo *)(&wifiinfo));
	if (wifiinfo.macid == 0)
		return 0;
	if (DWCi_Ndi_intToStrFigure(strId, wifiinfo.macid, 13) < 0)
		return 0;
	DWCi_Ndi_encodeBASE64(userid, strId, 13);
	DWCi_Ndi_encodeBASE64(gamecode, (char *)0x02fffe0c, 4);
	return 1;
}
