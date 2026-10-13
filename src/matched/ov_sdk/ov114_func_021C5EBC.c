/*
 * function: setAttr
 * address:  0x021C5EBC
 * packet:   pkt_ov114_021C5EBC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      setAttr (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * symbols:
 *   DWCi_Ndi_strlen  0x021C7A18  arm  ov114
 *   DWCi_NdSetError  0x021C659C  arm  ov114
 *   DWCi_Ndi_getEncodeLenBASE64  0x021C60AC  arm  ov114
 *   DWCi_Ndi_encodeBASE64  0x021C60C8  arm  ov114
 *   gDwciNdStatics  0x021D3B9C  data
 *   gDwciNdAttrEncoded  0x021D3BD8  data
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 DWCi_Ndi_strlen(const u8 *a0);
extern void DWCi_NdSetError(int err, int servererror);
extern int DWCi_Ndi_getEncodeLenBASE64(int len);
extern int DWCi_Ndi_encodeBASE64(char *encstr, char *srcbin, int length);
extern int gDwciNdStatics[];
extern char *gDwciNdAttrEncoded[];

int setAttr(int id, char *attr)
{
	int encLen;
	int n;
	if (*attr != 0) {
		if ((int)DWCi_Ndi_strlen((const u8 *)attr) > 10) {
			DWCi_NdSetError(5, 0);
			return 0;
		}
		n = DWCi_Ndi_strlen((const u8 *)attr);
		if (n > 10) {
			DWCi_NdSetError(5, 0);
			return 0;
		}
		gDwciNdAttrEncoded[id] = ((char *(*)(int, int))gDwciNdStatics[1])(DWCi_Ndi_getEncodeLenBASE64(n) + 1, 4);
		if (gDwciNdAttrEncoded[id] == 0) {
			DWCi_NdSetError(1, 0);
			return 0;
		}
		encLen = DWCi_Ndi_encodeBASE64(gDwciNdAttrEncoded[id], attr, n);
		gDwciNdAttrEncoded[id][encLen] = 0;
	}
	return 1;
}
