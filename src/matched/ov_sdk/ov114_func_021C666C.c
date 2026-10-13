/*
 * function: DWCi_NdCancelAsync
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
 *   DWC_NdGetProgress  0x021C5E14  arm  ov114
 *   DWCi_Ndi_prepareHttpCallback  0x021C7934  arm  ov114
 *   DWCi_Ndi_lockGlobal  0x021C78E0  arm  ov114
 *   DWCi_Ndi_unlockGlobal  0x021C78F4  arm  ov114
 *   NHTTP_CancelConnection  0x021BF374  arm  ov114
 *   DWCi_Ndi_unprepareHttpCallback  0x021C797C  arm  ov114
 *   gDwciNdStatics  0x021D3B9C  data
 */

extern int DWC_NdGetProgress(unsigned long *received, unsigned long *contentlen);
extern int DWCi_Ndi_prepareHttpCallback(void);
extern void DWCi_Ndi_lockGlobal(void);
extern void DWCi_Ndi_unlockGlobal(void);
extern int NHTTP_CancelConnection(void *handle);
extern void DWCi_Ndi_unprepareHttpCallback(void);
extern int gDwciNdStatics[];

int DWCi_NdCancelAsync(void)
{
	unsigned long received;
	unsigned long contentlen;
	void *id;
	int rc;
	if (gDwciNdStatics[2] == 0)
		return 0;
	rc = 0;
	received = 0;
	contentlen = 0;
	DWC_NdGetProgress(&received, &contentlen);
	if (received == contentlen)
		return rc;
	if (DWCi_Ndi_prepareHttpCallback() == 0) {
		DWCi_Ndi_lockGlobal();
		id = (void *)gDwciNdStatics[4];
		DWCi_Ndi_unlockGlobal();
		if (NHTTP_CancelConnection(id) == 0)
			rc = 1;
		return rc;
	}
	DWCi_Ndi_unprepareHttpCallback();
	return rc;
}
