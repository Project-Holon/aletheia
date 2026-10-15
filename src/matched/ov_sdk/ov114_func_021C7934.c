/*
 * function: DWCi_Ndi_prepareHttpCallback
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
 *   OS_LockMutex  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   gDwciNdHttpMutex  0x021D3C20  data
 *   gDwciNdStatics  0x021D3B9C  data
 */

extern void OS_LockMutex(void *m);
extern void func_02086078(void *m);
extern char gDwciNdHttpMutex[];
extern int gDwciNdStatics[];

int DWCi_Ndi_prepareHttpCallback(void)
{
	int rc;
	OS_LockMutex(gDwciNdHttpMutex);
	rc = (gDwciNdStatics[8] == 0);
	if (rc)
		gDwciNdStatics[8] = 1;
	func_02086078(gDwciNdHttpMutex);
	return rc;
}
