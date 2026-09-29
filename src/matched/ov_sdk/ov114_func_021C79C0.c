/*
 * function: func_021C79C0
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
 *   func_02087C6C  0x02087C6C  arm
 *   func_021C7B48  0x021C7B48  arm  ov114
 *   func_021C60C8  0x021C60C8  arm  ov114
 */

extern void func_02087C6C(unsigned char *macAddress);
extern int func_021C7B48(char *p, unsigned long n, int figure);
extern int func_021C60C8(char *encstr, char *srcbin, int length);

void func_021C79C0(char *macaddr)
{
	unsigned char madr[6];
	char strmadr[12];
	int i;
	func_02087C6C(madr);
	for (i = 0; i < 6; i++)
		func_021C7B48(strmadr + i * 2, madr[i], 2);
	func_021C60C8(macaddr, strmadr, 12);
}
