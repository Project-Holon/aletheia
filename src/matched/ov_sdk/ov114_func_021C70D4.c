/*
 * function: func_021C70D4
 * address:  0x021C70D4
 * packet:   pkt_ov114_021C70D4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      runHttp (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * symbols:
 *   func_021C78E0  0x021C78E0  arm  ov114
 *   func_021BF308  0x021BF308  arm  ov114
 *   func_021C659C  0x021C659C  arm  ov114
 *   func_021C78F4  0x021C78F4  arm  ov114
 *   g_021D3B9C  0x021D3B9C  data
 */

extern void func_021C78E0(void);
extern int func_021BF308(void *handle);
extern void func_021C659C(int err, int servererror);
extern void func_021C78F4(void);
extern int g_021D3B9C[];

int func_021C70D4(int unused, void *req)
{
	int err;
	func_021C78E0();
	err = func_021BF308(req);
	if (err) {
		req = 0;
		func_021C659C(3, (int)req);
		func_021C78F4();
		return (int)req;
	}
	g_021D3B9C[4] = (int)req;
	func_021C78F4();
	return 1;
}
