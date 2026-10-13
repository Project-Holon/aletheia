/*
 * function: DWCi_NdCleanupConnectionHandle
 * address:  0x021C654C
 * packet:   pkt_ov114_021C654C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_NdCleanupConnectionHandle (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * symbols:
 *   DWCi_Ndi_lockGlobal  0x021C78E0  arm  ov114
 *   NHTTP_GetConnectionStatus  0x021BF3BC  arm  ov114
 *   NHTTP_DeleteConnection  0x021BF184  arm  ov114
 *   DWCi_Ndi_unlockGlobal  0x021C78F4  arm  ov114
 */

extern void DWCi_Ndi_lockGlobal(void);
extern int NHTTP_GetConnectionStatus(int a);
extern int NHTTP_DeleteConnection(int a);
extern void DWCi_Ndi_unlockGlobal(void);

int DWCi_NdCleanupConnectionHandle(void *volatile handle)
{
	int result = 1;
	DWCi_Ndi_lockGlobal();
	if (handle) {
		NHTTP_GetConnectionStatus((int)handle);
		if (NHTTP_DeleteConnection((int)handle) != 0)
			result = 0;
		else
			handle = 0;
	}
	DWCi_Ndi_unlockGlobal();
	return result;
}
