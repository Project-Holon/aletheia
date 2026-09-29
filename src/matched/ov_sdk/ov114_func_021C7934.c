/*
 * function: func_021C7934
 * address:  0x021C7934
 * packet:   pkt_ov114_021C7934
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Ndi_prepareHttpCallback (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * symbols:
 *   func_02086028  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   g_021D3C20  0x021D3C20  data
 *   g_021D3B9C  0x021D3B9C  data
 */

extern void func_02086028(void *m);
extern void func_02086078(void *m);
extern char g_021D3C20[];
extern int g_021D3B9C[];

int func_021C7934(void)
{
	int rc;
	func_02086028(g_021D3C20);
	rc = (g_021D3B9C[8] == 0);
	if (rc)
		g_021D3B9C[8] = 1;
	func_02086078(g_021D3C20);
	return rc;
}
