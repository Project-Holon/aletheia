/*
 * function: DWCi_Ndi_getMacAddress
 * address:  0x021C79C0
 * packet:   pkt_ov114_021C79C0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Ndi_getMacAddress (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * symbols:
 *   OS_GetMacAddress  0x02087C6C  arm
 *   DWCi_Ndi_hexToStrFigure  0x021C7B48  arm  ov114
 *   DWCi_Ndi_encodeBASE64  0x021C60C8  arm  ov114
 */

extern void OS_GetMacAddress(unsigned char *macAddress);
extern int DWCi_Ndi_hexToStrFigure(char *p, unsigned long n, int figure);
extern int DWCi_Ndi_encodeBASE64(char *encstr, char *srcbin, int length);

void DWCi_Ndi_getMacAddress(char *macaddr)
{
	unsigned char madr[6];
	char strmadr[12];
	int i;
	OS_GetMacAddress(madr);
	for (i = 0; i < 6; i++)
		DWCi_Ndi_hexToStrFigure(strmadr + i * 2, madr[i], 2);
	DWCi_Ndi_encodeBASE64(macaddr, strmadr, 12);
}
