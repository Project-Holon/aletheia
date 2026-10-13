/*
 * function: runHttp
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
 *   DWCi_Ndi_lockGlobal  0x021C78E0  arm  ov114
 *   NHTTP_StartConnection  0x021BF308  arm  ov114
 *   DWCi_NdSetError  0x021C659C  arm  ov114
 *   DWCi_Ndi_unlockGlobal  0x021C78F4  arm  ov114
 *   gDwciNdStatics  0x021D3B9C  data
 */

extern void DWCi_Ndi_lockGlobal(void);
extern int NHTTP_StartConnection(void *handle);
extern void DWCi_NdSetError(int err, int servererror);
extern void DWCi_Ndi_unlockGlobal(void);
extern int gDwciNdStatics[];

int runHttp(int unused, void *req)
{
	int err;
	DWCi_Ndi_lockGlobal();
	err = NHTTP_StartConnection(req);
	if (err) {
		req = 0;
		DWCi_NdSetError(3, (int)req);
		DWCi_Ndi_unlockGlobal();
		return (int)req;
	}
	gDwciNdStatics[4] = (int)req;
	DWCi_Ndi_unlockGlobal();
	return 1;
}
