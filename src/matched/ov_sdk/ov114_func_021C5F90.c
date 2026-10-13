/*
 * function: DWCi_NdSetAttr
 * address:  0x021C5F90
 * packet:   pkt_ov114_021C5F90
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_NdSetAttr (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * symbols:
 *   DWCi_Ndi_lockGlobal  0x021C78E0  arm  ov114
 *   DWCi_Ndi_freeAttr  0x021C5E78  arm  ov114
 *   setAttr  0x021C5EBC  arm  ov114
 *   DWCi_Ndi_unlockGlobal  0x021C78F4  arm  ov114
 */

extern void DWCi_Ndi_lockGlobal(void);
extern void DWCi_Ndi_freeAttr(void);
extern int setAttr(int id, char *attr);
extern void DWCi_Ndi_unlockGlobal(void);

int DWCi_NdSetAttr(char *attr1, char *attr2, char *attr3)
{
	DWCi_Ndi_lockGlobal();
	DWCi_Ndi_freeAttr();
	if (setAttr(0, attr1) && setAttr(1, attr2) && setAttr(2, attr3)) {
		DWCi_Ndi_unlockGlobal();
		return 1;
	}
	DWCi_Ndi_freeAttr();
	DWCi_Ndi_unlockGlobal();
	return 0;
}
