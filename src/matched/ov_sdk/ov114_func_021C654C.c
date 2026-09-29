/*
 * function: func_021C654C
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
 *   func_021C78E0  0x021C78E0  arm  ov114
 *   func_021BF3BC  0x021BF3BC  arm  ov114
 *   func_021BF184  0x021BF184  arm  ov114
 *   func_021C78F4  0x021C78F4  arm  ov114
 */

extern void func_021C78E0(void);
extern int func_021BF3BC(void *handle);
extern int func_021BF184(void *handle);
extern void func_021C78F4(void);

int func_021C654C(void *volatile handle)
{
	int result = 1;
	func_021C78E0();
	if (handle) {
		func_021BF3BC(handle);
		if (func_021BF184(handle) != 0)
			result = 0;
		else
			handle = 0;
	}
	func_021C78F4();
	return result;
}
