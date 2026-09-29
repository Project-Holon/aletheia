/*
 * function: func_021C666C
 * address:  0x021C666C
 * packet:   pkt_ov114_021C666C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_NdCancelAsync (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * symbols:
 *   func_021C5E14  0x021C5E14  arm  ov114
 *   func_021C7934  0x021C7934  arm  ov114
 *   func_021C78E0  0x021C78E0  arm  ov114
 *   func_021C78F4  0x021C78F4  arm  ov114
 *   func_021BF374  0x021BF374  arm  ov114
 *   func_021C797C  0x021C797C  arm  ov114
 *   g_021D3B9C  0x021D3B9C  data
 */

extern int func_021C5E14(unsigned long *received, unsigned long *contentlen);
extern int func_021C7934(void);
extern void func_021C78E0(void);
extern void func_021C78F4(void);
extern int func_021BF374(void *handle);
extern void func_021C797C(void);
extern int g_021D3B9C[];

int func_021C666C(void)
{
	unsigned long received;
	unsigned long contentlen;
	void *id;
	int rc;
	if (g_021D3B9C[2] == 0)
		return 0;
	rc = 0;
	received = 0;
	contentlen = 0;
	func_021C5E14(&received, &contentlen);
	if (received == contentlen)
		return rc;
	if (func_021C7934() == 0) {
		func_021C78E0();
		id = (void *)g_021D3B9C[4];
		func_021C78F4();
		if (func_021BF374(id) == 0)
			rc = 1;
		return rc;
	}
	func_021C797C();
	return rc;
}
