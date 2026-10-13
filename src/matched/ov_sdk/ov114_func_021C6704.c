/*
 * function: DWCi_Ndi_getApInfo
 * address:  0x021C6704
 * packet:   pkt_ov114_021C6704
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Ndi_getApInfo (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * symbols:
 *   func_0205CD24  0x0205CD24  arm
 *   DWCi_Ndi_intToStr  0x021C7A68  arm  ov114
 *   DWCi_Ndi_memcpy  0x021C7A44  arm  ov114
 *   DWCi_Ndi_encodeBASE64  0x021C60C8  arm  ov114
 *   sDwciNdEmptyMacAddress  0x021CE0E4  data
 *   gDwciNdApInfo  0x021D3C8C  data
 */

typedef struct {
	char b[13];
} B13;

typedef struct {
	int type;
	int idx;
	int pad;
	char bssid[9];
} ApInfo;

extern int func_0205CD24(ApInfo *apinfo);
typedef unsigned int   u32;
extern void DWCi_Ndi_intToStr(char *p, u32 n);
extern void DWCi_Ndi_memcpy(void *dst, void *src, int size);
extern int DWCi_Ndi_encodeBASE64(char *encstr, char *srcbin, int length);
extern B13 sDwciNdEmptyMacAddress;
extern ApInfo gDwciNdApInfo;

int DWCi_Ndi_getApInfo(char *apinfo)
{
	B13 strAp = sDwciNdEmptyMacAddress;
	if (func_0205CD24(&gDwciNdApInfo)) {
		if (gDwciNdApInfo.type >= 0 && gDwciNdApInfo.type < 10)
			strAp.b[1] = gDwciNdApInfo.type + '0';
		else if (gDwciNdApInfo.type >= 10 && gDwciNdApInfo.type < 100)
			DWCi_Ndi_intToStr(strAp.b, gDwciNdApInfo.type);
		if (gDwciNdApInfo.type == 4 || gDwciNdApInfo.type == 8) {
			if (gDwciNdApInfo.idx >= 0 && gDwciNdApInfo.idx < 10)
				strAp.b[3] = gDwciNdApInfo.idx + '0';
			DWCi_Ndi_memcpy(&strAp.b[4], gDwciNdApInfo.bssid, 9);
		}
		DWCi_Ndi_encodeBASE64(apinfo, strAp.b, 13);
		return 1;
	}
	return 0;
}
