/*
 * function: func_021C5F90
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
 *   func_021C78E0  0x021C78E0  arm  ov114
 *   func_021C5E78  0x021C5E78  arm  ov114
 *   func_021C5EBC  0x021C5EBC  arm  ov114
 *   func_021C78F4  0x021C78F4  arm  ov114
 */

extern void func_021C78E0(void);
extern void func_021C5E78(void);
extern int func_021C5EBC(int id, char *attr);
extern void func_021C78F4(void);

int func_021C5F90(char *attr1, char *attr2, char *attr3)
{
	func_021C78E0();
	func_021C5E78();
	if (func_021C5EBC(0, attr1) && func_021C5EBC(1, attr2) && func_021C5EBC(2, attr3)) {
		func_021C78F4();
		return 1;
	}
	func_021C5E78();
	func_021C78F4();
	return 0;
}
